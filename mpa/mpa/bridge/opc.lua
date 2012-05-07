local math = require "math"
local min = math.min
local max = math.max
local huge = math.huge

local socket = require "socket.core"
local gettime = socket.gettime

local comgen = require "comgen"
local CreateInstance = comgen.CreateInstance
local MessageStep = comgen.MessageStep

local opclib = require "opclib"
local IOPCItemMgt = opclib.IOPCItemMgt
local IOPCSyncIO = opclib.IOPCSyncIO
local IOPCServer = opclib.IOPCServer
local IOPCItemIO = opclib.IOPCItemIO

local ok, opcsec = pcall(require, "opcsec")
local IOPCSecurityPrivate = ok and opcsec.IOPCSecurityPrivate

local connpoint = require "connpoint"

local oo = require "mpa.oo"
local class = oo.class
local classof = oo.classof

module("mpa.bridge.opc", package.seeall)

--------------------------------------------------------------------------------
-- Functions to convert from Windows FILETIME to LuaSocket time ----------------
-- Thanks Diego Nehab! ---------------------------------------------------------

local function stime2filetime(t)
  local ft = {}
  -- convert to Windows Epoch (time since January 1, 1601)
  t = t + 11644473600.0
  -- High part (t in 0.1 usec DIV 2^32)
  ft.dwHighDateTime = math.floor(t * (1.0e7 / 4294967296))
  -- Low part (t in 0.1 usec MOD 2^32)
  ft.dwLowDateTime = math.floor(t*1.0e7) % 4294967296
  return ft
end

local function filetime2stime(ft)
  local t  = ft.dwLowDateTime/1.0e7 + ft.dwHighDateTime*(4294967296/1.0e7)
  -- convert to Unix Epoch time (time since January 1, 1970 (UTC))
  t = t - 11644473600.0
  return t
end

local function check_value(val, qual, ts)
  if val then
    return val, qual, ts
  else
    return nil, "OPC server did not provide a value"
  end
end

local function check_value_block(val, qual, ts)
  if val then
    return { success = true, value = val, quality = qual, timestamp = ts }
  else
    return { success = false, value = "OPC server did not provide a value" }
  end
end

--------------------------------------------------------------------------------
-- Support for OPC Data Access version 3 ---------------------------------------

DataAccess_v3 = class()

function DataAccess_v3:init()
        self.last_checked = gettime()
        self.timeout = self.params.timeout or 5
end

function DataAccess_v3:check(force)
        local now = gettime()
        if force or ((now - self.last_checked) > self.timeout) then
                local ok, status = pcall(self.server.GetStatus, self.server)
                if (not ok) or status[1].dwServerState ~= 1 then
                        self:restart()
                end
                self.last_checked = now
        end
end

function DataAccess_v3:restart()
        if self.close then pcall(self.close, self) end
        local params = self.params
        local ok, server = pcall(CreateInstance, params.server, IOPCServer, self.params.host)
        if not ok then error("server not found, COM error: " .. server) end
        if params.user then
          local ok, sec = pcall(server.QueryInterface, server, IOPCSecurityPrivate)
          if not ok then error("OPC Security interface not available: " .. server) end
          if not sec:IsAvailablePriv() then
            error("OPC Security interface not available, COM error: " .. sec)
          end
          comgen.RaisePrivacy(sec)
          local ok, err = pcall(sec.Logon, sec, params.user, params.pass)
          if not ok then error("login to server failed, COM error: " .. err) end
        end
        self.server = server
        local ok, itemio = pcall(server.QueryInterface, server, IOPCItemIO)
        if ok and (not params.use_v2) then
          self.itemio = itemio
        end
        if self.init then self:init() end
end

function DataAccess_v3:errmsg(err)
        if type(err) == "number" then
                return self.server:GetErrorString(err, 1033)
        else
                return err
        end
end

function DataAccess_v3:get(tag)
        self:check()
        local values, quals, ts, err = self.itemio:Read(1, { tag }, { 0 })
        if err[1] == "OK" then
                return check_value(values[1], quals[1], filetime2stime(ts[1]))
        else
                return nil, self:errmsg(err[1])
        end
end

function DataAccess_v3:set(tag, val, qual, ts)
        self:check()
        local vqt = { vDataValue = val, ftTimeStamp = {} }
        if qual then
                vqt.bQualitySpecified = true
                vqt.wQuality = qual
        end
        if ts then
                vqt.bTimeStampSpecified = true
                vqt.ftTimeStamp = stime2filetime(ts)
        end
        local err = self.itemio:WriteVQT(1, { tag }, { vqt })
        if err[1] == "OK" then
                return true
        else
                return nil, self:errmsg(err[1])
        end
end

function DataAccess_v3:getblock(tags)
        self:check()
        local ages = {}
        for i = 1, #tags do ages[i] = 0 end
        local values, quals, ts, err
        if #tags > 0 then
          values, quals, ts, err = self.itemio:Read(#tags, tags, ages)
        end
        local res = {}
        for i = 1, #tags do
                if err[i] == "OK" then
                        res[i] = check_value_block(values[i], quals[i],  filetime2stime(ts[i]))
                else
                        res[i] = { success = false, value = self:errmsg(err[i]) }
                end
        end
        return res
end

function DataAccess_v3:setblock(tags, vals, quals, ts)
        self:check()
        quals = quals or {}
        ts = ts or {}
        local vqts = {}
        for i = 1, #tags do
                vqts[i] = { vDataValue = vals[i], ftTimeStamp = {} }
                if quals[i] then
                        vqts[i].bQualitySpecified = true
                        vqts[i].wQuality = quals[i]
                end
                if ts[i] then
                        vqts[i].bTimeStampSpecified = true
                        vqts[i].ftTimeStamp = stime2filetime(ts[i])
                end
        end
        local err = {}
        if #tags > 0 then
          err = self.itemio:WriteVQT(#tags, tags, vqts)
        end
        local errors = {}
        for i = 1, #err do
                if err[i] ~= "OK" then
                        errors[#errors+1] = { tag = tags[i], value = self:errmsg(err[i]) }
                end
        end
        return errors
end

function DataAccess_v3:close()
        self.server = nil
        self.itemio = nil
end

--------------------------------------------------------------------------------
-- Support for OPC Data Access version 2 ---------------------------------------

DataAccess_v2 = class({}, DataAccess_v3)

function DataAccess_v2:init()
        local hgrp, _, mgt = self.server:AddGroup("LuaGroup", true, 0, 0, 0, IOPCItemMgt)
        self.hgrp = hgrp
        self.mgt = mgt
        self.syncio = mgt:QueryInterface(IOPCSyncIO)
        self.items = {}
end

function DataAccess_v2:get(tag)
        self:check()
        if self.items[tag] then
                local result, err = self.syncio:Read("OPC_DS_DEVICE", 1, { self.items[tag] })
                if err[1] == "OK" then
                        return check_value(result[1].vDataValue, result[1].wQuality, filetime2stime(result[1].ftTimeStamp))
                else
                        return nil, self:errmsg(err[1])
                end
        else
                local result, err = self.mgt:AddItems(1, { {
                        szAccessPath = "",
                        szItemID = tag,
                        bActive = false,
                        hClient = 1,
                        dwBlobSize = 0,
                        pBlob = {},
                        vtRequestedDataType = "VT_EMPTY",
                        wReserved = 0,
                } })
                if err[1] == "OK" then
                        self.items[tag] = result[1].hServer
                        result, err = self.syncio:Read("OPC_DS_DEVICE", 1, { result[1].hServer })
                        if err[1] == "OK" then
                               return check_value(result[1].vDataValue, result[1].wQuality, filetime2stime(result[1].ftTimeStamp))
                        end
                end
                return nil, self:errmsg(err[1])
        end
end

function DataAccess_v2:set(tag, val)
        self:check()
        if self.items[tag] then
                local err = self.syncio:Write(1, { self.items[tag] }, { val })
                if err[1] == "OK" then
                        return true
                else
                        return nil, self:errmsg(err[1])
                end
        else
                local result, err = self.mgt:AddItems(1, { { szAccessPath = "",
                                                 szItemID = tag,
                                                 bActive = false,
                                                 hClient = 1,
                                                 dwBlobSize = 0,
                                                 pBlob = {},
                                                 vtRequestedDataType = "VT_EMPTY",
                                                 wReserved = 0 } })
                if err[1] == "OK" then
                        self.items[tag] = result[1].hServer
                        err = self.syncio:Write(1, { result[1].hServer }, { val })
                        if err[1] == "OK" then
                                return true
                        end
                end
                return nil, self:errmsg(err[1])
        end
end

function DataAccess_v2:getblock(tags)
        self:check()
        local new, err_add = {}, {}
        for _, tag in ipairs(tags) do
                if not self.items[tag] then
                        new[#new + 1] = { szAccessPath = "",
                        szItemID = tag,
                        bActive = false,
                        hClient = 1,
                        dwBlobSize = 0,
                        pBlob = {},
                        vtRequestedDataType = "VT_EMPTY",
                        wReserved = 0 }
                end
        end
        if #new > 0 then
                local result, err = self.mgt:AddItems(#new, new)
                for i, item in ipairs(new) do
                        if err[i] == "OK" then
                                self.items[item.szItemID] = result[i].hServer
                        else
                                err_add[item.szItemID] = err[i]
                        end
                end
        end
        local ids = {}
        for _, tag in ipairs(tags) do
                ids[#ids + 1] = self.items[tag]
        end
        local result, err
        if #ids > 0 then
          result, err = self.syncio:Read("OPC_DS_DEVICE", #ids, ids)
        end
        local i, res = 1, {}
        for _, tag in ipairs(tags) do
                if self.items[tag] then
                        if err[i] == "OK" then
                                res[#res + 1] = check_value_block(result[i].vDataValue,
                                                  result[i].wQuality,
                                                  filetime2stime(result[i].ftTimeStamp))
                        else
                                res[#res + 1] = { success = false, value = self:errmsg(err[i]) }
                        end
                        i = i + 1
                else
                        res[#res + 1] = { success = false, value = self:errmsg(err_add[tag]) }
                end
        end
        return res
end

function DataAccess_v2:setblock(tags, vals)
        self:check()
        local new, err_add = {}, {}
        for _, tag in ipairs(tags) do
                if not self.items[tag] then
                        new[#new + 1] = { szAccessPath = "",
                        szItemID = tag,
                        bActive = false,
                        hClient = 1,
                        dwBlobSize = 0,
                        pBlob = {},
                        vtRequestedDataType = "VT_EMPTY",
                        wReserved = 0 }
                end
        end
        if #new > 0 then
                local result, err = self.mgt:AddItems(#new, new)
                for i, item in ipairs(new) do
                        if err[i] == "OK" then
                                self.items[item.szItemID] = result[i].hServer
                        else
                                err_add[item.szItemID] = err[i]
                        end
                end
        end
        local ids, values = {}, {}
        for i, tag in ipairs(tags) do
                if self.items[tag] then
                        ids[#ids + 1] = self.items[tag]
                        if type(vals[i]) == "nil" then
                          values[#values + 1] = { type = "EMPTY" }
                        else
                          values[#values + 1] = vals[i]
                        end
                end
        end
        local err
        if #ids > 0 then
          err = self.syncio:Write(#ids, ids, values)
        end
        local i, errors = 1, {}
        for _, tag in ipairs(tags) do
                if self.items[tag] then
                        if err[i] ~= "OK" then
                                errors[#errors + 1] = { tag = tag, value = self:errmsg(err[i]) }
                        end
                        i = i + 1
                else
                        errors[#errors + 1] = { tag = tag, value = self:errmsg(err_add[tag]) }
                end
        end
        return errors
end

function DataAccess_v2:close()
        local ids = {}
        for tag, id in pairs(self.items) do
                ids[#ids + 1] = id
        end
        self.mgt:RemoveItems(#ids, ids)
        self.server:RemoveGroup(self.hgrp, true)
        self.items = nil
        self.server = nil
        self.mgt = nil
        self.syncio = nil
end

--------------------------------------------------------------------------------
-- Support for OPC Data Access version 2 using Asynchronous Comm. via Callbacks

DataAccess_v2_Callback = class()

function DataAccess_v2_Callback:OnDataChange(dwTransid, hGroup, hrMasterquality, hrMastererror, dwCount, phClientItems, pvValues, pwQualities, pftTimeStamps, pErrors)
        for i, handle in ipairs(phClientItems) do
                if pErrors[i] == "OK" then
                        local item = self.cache[handle]
                        if item then
                                item.result = pvValues[i]
                                item.quality = pwQualities[i]
                                item.timestamp = filetime2stime(pftTimeStamps[i])
                                item.err = "OK"
                        end
                else
                        local item = self.cache[handle]
                        if item then
                                item.result = nil
                                item.quality = nil
                                item.timestamp = nil
                                item.err = pErrors[i]
                        end
                end
        end
end

function DataAccess_v2_Callback:OnReadComplete(dwTransid, hGroup, hrMasterquality, hrMastererror, dwCount, phClientItems, pvValues, pwQualities, pftTimeStamps, pErrors)
        error("not necessary")
end

function DataAccess_v2_Callback:OnWriteComplete(dwTransid, hGroup, hrMasterquality, hrMastererror, dwCount, phClientItems, pvValues, pwQualities, pftTimeStamps, pErrors)
        error("not necessary")
end

function DataAccess_v2_Callback:OnCancelComplete(dwTransid, hGroup)
        error("not necessary")
end



DataAccess_v2_Async = class({ handle = 1000 }, DataAccess_v2)

function DataAccess_v2_Async:init()
        self.cpc = self.mgt:QueryInterface(connpoint.IConnectionPointContainer)
        self.cp = self.cpc:FindConnectionPoint(opclib.IOPCDataCallback)
        self.cache = {}
        self.cb = DataAccess_v2_Callback{ cache = self.cache }
        self.wrap = opclib.DataCallback(self.cb)
        self.cookie = self.cp:Advise(self.wrap.__interfaces.IOPCDataCallback)
        self.handles = {}
end

function DataAccess_v2_Async:newhandle()
        self.handle = self.handle + 1
        return self.handle
end

function DataAccess_v2_Async:get(tag)
        self:check()
        if self.items[tag] then
                MessageStep()
                local item = self.cache[self.items[tag]]
                if item.err == "OK" then
                        return check_value(item.result, item.quality, item.timestamp)
                else
                        return nil, self:errmsg(item.err)
                end
        else
                local handle = self:newhandle()
                local result, err = self.mgt:AddItems(1, { {
                        szAccessPath = "",
                        szItemID = tag,
                        bActive = true,
                        hClient = handle,
                        dwBlobSize = 0,
                        pBlob = {},
                        vtRequestedDataType = "VT_EMPTY",
                        wReserved = 0,
                } })
                if err[1] == "OK" then
                        self.items[tag] = handle
                        self.handles[tag] = result[1].hServer
                        result, err = self.syncio:Read("OPC_DS_DEVICE", 1, { result[1].hServer })
                        if err[1] == "OK" then
                                local item = {
                                        result = result[1].vDataValue,
                                        quality = result[1].wQuality,
                                        timestamp = filetime2stime(result[1].ftTimeStamp),
                                        err = "OK",
                                }
                                self.cache[handle] = item
                                return check_value(item.result, item.quality, item.timestamp)
                        else
                                local item = { err = err[1] }
                                self.cache[handle] = item
                                return nil, self:errmsg(item.err)
                        end
                end
                return nil, self:errmsg(err[1])
        end
end

function DataAccess_v2_Async:set(tag, val)
        self:check()
        if self.handles[tag] then
                local err = self.syncio:Write(1, { self.handles[tag] }, { val })
                if err[1] == "OK" then
                        self.cache[self.items[tag]] = { result = val, err = "OK",
                                                        timestamp = gettime(), quality = 192 }
                        return true
                else
                        self.cache[self.items[tag]] = { err = err[i] }
                        return nil, self:errmsg(err[1])
                end
        else
                local handle = self:newhandle()
                local result, err = self.mgt:AddItems(1, { {
                        szAccessPath = "",
                        szItemID = tag,
                        bActive = true,
                        hClient = handle,
                        dwBlobSize = 0,
                        pBlob = {},
                        vtRequestedDataType = "VT_EMPTY",
                        wReserved = 0,
                } })
                if err[1] == "OK" then
                        self.items[tag] = handle
                        self.handles[tag] = result[1].hServer
                        err = self.syncio:Write(1, { result[1].hServer }, { val })
                        if err[1] == "OK" then
                                self.cache[handle] = { result = val, err = "OK",
                                                       timestamp = gettime(), quality = 192 }
                                return true
                        else
                                self.cache[handle] = { err = err[i] }
                        end
                end
                return nil, self:errmsg(err[1])
        end
end

function DataAccess_v2_Async:getblock(tags)
        self:check()
        local new, err_add = {}, {}
        for _, tag in ipairs(tags) do
                if not self.items[tag] then
                        new[#new + 1] = {
                                szAccessPath = "",
                                szItemID = tag,
                                bActive = true,
                                hClient = self:newhandle(),
                                dwBlobSize = 0,
                                pBlob = {},
                                vtRequestedDataType = "VT_EMPTY",
                                wReserved = 0,
                        }
                end
        end
        local ids, handles = {}, {}
        if #new > 0 then
                local result, err = self.mgt:AddItems(#new, new)
                for i, item in ipairs(new) do
                        if err[i] == "OK" then
                                self.items[item.szItemID] = item.hClient
                                self.handles[item.szItemID] = result[i].hServer
                                ids[#ids + 1] = result[i].hServer
                                handles[#handles + 1] = item.hClient
                        else
                                err_add[item.szItemID] = err[i]
                        end
                end
        end
        if #ids > 0 then
                local result, err = self.syncio:Read("OPC_DS_DEVICE", #ids, ids)
                for i, id in ipairs(ids) do
                        if err[i] == "OK" then
                                self.cache[handles[i]] = { result = result[i].vDataValue, quality = result[i].wQuality,
                                                           err = "OK", timestamp = filetime2stime(result[i].ftTimeStamp) }
                        else
                                self.cache[handles[i]] = { err = err[i] }
                        end
                end
        end
        local res = {}
        MessageStep()
        for _, tag in ipairs(tags) do
                if self.items[tag] then
                        local item = self.cache[self.items[tag]]
                        if item.err == "OK" then
                                res[#res + 1] = check_value_block(item.result, item.quality, item.timestamp)
                        else
                                res[#res + 1] = { success = false, value = self:errmsg(item.err) }
                        end
                else
                        res[#res + 1] = { success = false, value = self:errmsg(err_add[tag]) }
                end
        end
        return res
end

function DataAccess_v2_Async:setblock(tags, vals)
        self:check()
        local new, err_add = {}, {}
        for _, tag in ipairs(tags) do
                if not self.items[tag] then
                        new[#new + 1] = {
                                szAccessPath = "",
                                szItemID = tag,
                                bActive = true,
                                hClient = self:newhandle(),
                                dwBlobSize = 0,
                                pBlob = {},
                                vtRequestedDataType = "VT_EMPTY",
                                wReserved = 0,
                        }
                end
        end
        if #new > 0 then
                local result, err = self.mgt:AddItems(#new, new)
                for i, item in ipairs(new) do
                        if err[i] == "OK" then
                                self.items[item.szItemID] = new[i].hClient
                                self.handles[item.szItemID] = result[i].hServer
                        else
                                err_add[item.szItemID] = err[i]
                        end
                end
        end
        local ids, values = {}, {}
        for i, tag in ipairs(tags) do
                if self.items[tag] then
                        ids[#ids + 1] = self.handles[tag]
                        if type(vals[i]) == "nil" then
                          values[#values + 1] = { type = "EMPTY" }
                        else
                          values[#values + 1] = vals[i]
                        end
                end
        end
        local err
        if #ids > 0 then
          err = self.syncio:Write(#ids, ids, values)
        end
        local i, errors = 1, {}
        local now = gettime()
        for j, tag in ipairs(tags) do
                if self.items[tag] then
                        if err[i] ~= "OK" then
                                errors[#errors + 1] = { tag = tag, value = self:errmsg(err[i]) }
                                self.cache[self.items[tag]] = { err = err[i] }
                        else
                                self.cache[self.items[tag]] = { result = vals[j], err = "OK",
                                                                timestamp = now, quality = 192 }
                        end
                        i = i + 1
                else
                        errors[#errors + 1] = { tag = tag, value = self:errmsg(err_add[tag]) }
                end
        end
        return errors
end

function DataAccess_v2_Async:close()
        DataAccess_v2.close(self)
        self.cp:Unadvise(self.cookie)
        self.cp = nil
        self.cb = nil
end

DataAccess_v3_Async = class({ handle = 1000 }, DataAccess_v2_Async)

function DataAccess_v3_Async:set(tag, val, qual, ts)
        self:check()
        local vqt = { vDataValue = val, ftTimeStamp = {} }
        if qual then
                vqt.bQualitySpecified = true
                vqt.wQuality = qual
        end
        if ts then
                vqt.bTimeStampSpecified = true
                vqt.ftTimeStamp = stime2filetime(ts)
        end
        if self.handles[tag] then
                local err = self.itemio:WriteVQT(1, { tag }, { vqt })
                if err[1] == "OK" then
                        self.cache[self.items[tag]] = { result = val, err = "OK",
                                                        timestamp = ts or gettime(), quality = qual or 192 }
                        return true
                else
                        self.cache[self.items[tag]] = { err = err[i] }
                        return nil, self:errmsg(err[1])
                end
        else
                local handle = self:newhandle()
                local result, err = self.mgt:AddItems(1, { {
                        szAccessPath = "",
                        szItemID = tag,
                        bActive = true,
                        hClient = handle,
                        dwBlobSize = 0,
                        pBlob = {},
                        vtRequestedDataType = "VT_EMPTY",
                        wReserved = 0,
                } })
                if err[1] == "OK" then
                        self.items[tag] = handle
                        self.handles[tag] = result[1].hServer
                        err = self.itemio:WriteVQT(1, { tag }, { vqt })
                        if err[1] == "OK" then
                                self.cache[handle] = { result = val, err = "OK",
                                                       timestamp = ts or gettime(), quality = qual or 192 }
                                return true
                        else
                                self.cache[handle] = { err = err[i] }
                        end
                end
                return nil, self:errmsg(err[1])
        end
end

function DataAccess_v3_Async:setblock(tags, vals, quals, ts)
        self:check()
        quals = quals or {}
        ts = ts or {}
        local vqts = {}
        for i = 1, #tags do
                vqts[i] = { vDataValue = vals[i], ftTimeStamp = {} }
                if quals[i] then
                        vqts[i].bQualitySpecified = true
                        vqts[i].wQuality = quals[i]
                end
                if ts[i] then
                        vqts[i].bTimeStampSpecified = true
                        vqts[i].ftTimeStamp = stime2filetime(ts[i])
                end
        end
        local new, err_add = {}, {}
        for _, tag in ipairs(tags) do
                if not self.items[tag] then
                        new[#new + 1] = {
                                szAccessPath = "",
                                szItemID = tag,
                                bActive = true,
                                hClient = self:newhandle(),
                                dwBlobSize = 0,
                                pBlob = {},
                                vtRequestedDataType = "VT_EMPTY",
                                wReserved = 0,
                        }
                end
        end
        if #new > 0 then
                local result, err = self.mgt:AddItems(#new, new)
                for i, item in ipairs(new) do
                        if err[i] == "OK" then
                                self.items[item.szItemID] = new[i].hClient
                                self.handles[item.szItemID] = result[i].hServer
                        else
                                err_add[item.szItemID] = err[i]
                        end
                end
        end
        local ids, values = {}, {}, {}
        for i, tag in ipairs(tags) do
                if self.items[tag] then
                        ids[#ids + 1] = tag
                        values[#values + 1] = vqts[i]
                end
        end
        local err
        if #ids > 0 then
          err = self.itemio:WriteVQT(#ids, ids, values)
        end
        local i, errors = 1, {}
        local now = gettime()
        for j, tag in ipairs(tags) do
                if self.items[tag] then
                        if err[i] ~= "OK" then
                                errors[#errors + 1] = { tag = tag, value = self:errmsg(err[i]) }
                                self.cache[self.items[tag]] = { err = err[i] }
                        else
                                self.cache[self.items[tag]] = { result = vals[j], err = "OK",
                                                                timestamp = ts[j] or now, quality = quals[j] or 192 }
                        end
                        i = i + 1
                else
                        errors[#errors + 1] = { tag = tag, value = self:errmsg(err_add[tag]) }
                end
        end
        return errors
end

--------------------------------------------------------------------------------
-- Support for performance statics collection ----------------------------------

local StatsTags = {
        readtime   = true,
        writetime  = true,
        mreadtime  = true,
        mwritetime = true,
        mreadsize  = true,
        mwritesize = true,
}
local function regBlockStats(info, tags)
        local size = #tags
        info.min = min(info.min, size)
        info.max = max(info.max, size)
        info.sum = info.sum + size
        info.cnt = info.cnt + 1
end
local function regTimeStats(info, time, ...)
        time = gettime() - time
        info.min = min(info.min, time)
        info.max = max(info.max, time)
        info.sum = info.sum + time
        info.cnt = info.cnt + 1
        return ...
end

function wrapped_get(self, ...)
        local class = classof(self)
        return regTimeStats(self.readtime, gettime(), class.get(self, ...))
end
function wrapped_set(self, ...)
        local class = classof(self)
        return regTimeStats(self.writetime, gettime(), class.set(self, ...))
end
function wrapped_getblock(self, tags, ...)
        local class = classof(self)
        regBlockStats(self.mreadsize, tags)
        return regTimeStats(self.mreadtime, gettime(), class.getblock(self,tags,...))
end
function wrapped_setblock(self, tags, ...)
        local class = classof(self)
        regBlockStats(self.mwritesize, tags)
        return regTimeStats(self.mwritetime, gettime(), class.setblock(self,tags,...))
end

function DataAccess_v3:resetstats()
        for tag in pairs(StatsTags) do
                local table = self[tag]
                if table == nil then
                        table = {}
                        self[tag] = table
                end
                table.min = huge
                table.max = 0
                table.sum = 0
                table.cnt = 0
        end
end
function DataAccess_v3:getstats()
        local stats = {}
        for tag in pairs(StatsTags) do
                stats[tag] = self[tag]
        end
        return stats
end

--------------------------------------------------------------------------------
-- Creation of OPC bridge ------------------------------------------------------

function open(params, host, stats, use_v2, async, user, pass)
        if type(params) ~= "table" then
          params = { server = params, host = host, stats = stats,
                     use_v2 = use_v2, async = async, user = user,
                     pass = pass }
        end
        local ok, server = pcall(CreateInstance, params.server, IOPCServer, params.host)
        if not ok then return nil, "server not found, COM error: " .. server end
        if params.user then
          local ok, sec = pcall(server.QueryInterface, server, IOPCSecurityPrivate)
          if not ok then return nil, "OPC Security interface not available: " .. server end
          if not sec:IsAvailablePriv() then
            return nil, "OPC Security interface not available, COM error: " .. sec
          end
          comgen.RaisePrivacy(sec)
          local ok, err = pcall(sec.Logon, sec, params.user, params.pass)
          if not ok then return nil, "login to server failed, COM error: " .. err end
        end
        local ok, itemio = pcall(server.QueryInterface, server, IOPCItemIO)
        if ok and (not params.use_v2) then
          if params.async then
                server = DataAccess_v3_Async{ params = params, server = server, itemio = itemio }
          else
                server = DataAccess_v3{ params = params, server = server, itemio = itemio }
          end
        else
          if params.async then
                server = DataAccess_v2_Async{ params = params, server = server }
          else
                server = DataAccess_v2{ params = params, server = server }
          end
        end
        if params.stats then
                server.get = wrapped_get
                server.set = wrapped_set
                server.getblock = wrapped_getblock
                server.setblock = wrapped_setblock
                server:resetstats()
        end
        return server
end
