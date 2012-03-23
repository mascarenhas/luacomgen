local math = require "math"
local min = math.min
local max = math.max
local huge = math.huge

local socket = require "socket.core"
local gettime = socket.gettime

local comgen = require "comgen"
local CreateInstance = comgen.CreateInstance

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
-- Support for OPC Data Access version 3 ---------------------------------------

DataAccess_v3 = class()

function DataAccess_v3:errmsg(err)
        if type(err) == "number" then
                return self.server:GetErrorString(err, 1033)
        else
                return err
        end
end

function DataAccess_v3:get(tag)
        local values, quals, ts, err = self.itemio:Read(1, { tag }, { 0 })
        if err[1] == "OK" then
                return values[1], quals[1]
        else
                return nil, self:errmsg(err[1])
        end
end
function DataAccess_v3:set(tag, val, qual)
        local vqt = { vDataValue = val, ftTimeStamp = {} }
        if qual then
                vqt.bQualitySpecified = true
                vqt.wQuality = qual
        end
        local err = self.itemio:WriteVQT(1, { tag }, { vqt })
        if err[1] == "OK" then
                return true
        else
                return nil, self:errmsg(err[1])
        end
end

function DataAccess_v3:getblock(tags)
        local ages = {}
        for i = 1, #tags do ages[i] = 0 end
        local values, quals, ts, err = self.itemio:Read(#tags, tags, ages)
        local res = {}
        for i = 1, #tags do
                if err[i] == "OK" then
                        res[i] = { success = true, value = values[i], quality = quals[i] }
                else
                        res[i] = { success = false, value = self:errmsg(err[i]) }
                end
        end
        return res
end

function DataAccess_v3:setblock(tags, vals, quals)
        quals = quals or {}
        local vqts = {}
        for i = 1, #tags do
                vqts[i] = { vDataValue = vals[i], ftTimeStamp = {} }
                if quals[i] then
                        vqts[i].bQualitySpecified = true
                        vqts[i].wQuality = quals[i]
                end
        end
        local err = self.itemio:WriteVQT(#tags, tags, vqts)
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
        local hgrp, _, mgt = self.server:AddGroup("LuaGroup", false, 0, 0, 0, IOPCItemMgt)
        self.hgrp = hgrp
        self.mgt = mgt
        self.syncio = mgt:QueryInterface(IOPCSyncIO)
        self.items = {}
end

function DataAccess_v2:get(tag)
        if self.items[tag] then
                local result, err = self.syncio:Read("OPC_DS_DEVICE", 1, { self.items[tag] })
                if err[1] == "OK" then
                        return result[1].vDataValue, result[1].wQuality
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
                                return result[1].vDataValue, result[1].wQuality
                        end
                end
                return nil, self:errmsg(err[1])
        end
end

function DataAccess_v2:set(tag, val)
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
        local result, err = self.syncio:Read("OPC_DS_DEVICE", #ids, ids)
        local i, res = 1, {}
        for _, tag in ipairs(tags) do
                if self.items[tag] then
                        if err[i] == "OK" then
                                res[#res + 1] = { success = true, value = result[i].vDataValue, quality = result[i].wQuality }
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
                        values[#values + 1] = vals[i]
                end
        end
        local err = self.syncio:Write(#ids, ids, values)
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
                                item.err = "OK"
                        end
                else
                        local item = self.cache[handle]
                        if item then
                                item.result = nil
                                item.quality = pwQualities[i]
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
        if self.items[tag] then
                local item = self.cache[self.items[tag]]
                if item.err == "OK" then
                        return item.result, item.quality
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
                                        err = "OK",
                                }
                                self.cache[handle] = item
                                return item.result, item.quality
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
        if self.handles[tag] then
                local err = self.syncio:Write(1, { self.handles[tag] }, { val })
                if err[1] == "OK" then
                        self.cache[self.items[tag]] = { result = val, err = "OK" }
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
                                self.cache[handle] = { result = val, err = "OK" }
                                return true
                        else
                                self.cache[handle] = { err = err[i] }
                        end
                end
                return nil, self:errmsg(err[1])
        end
end

function DataAccess_v2_Async:getblock(tags)
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
                                self.cache[handles[i]] = { result = result[i].vDataValue, quality = result[i].wQuality, err = "OK" }
                        else
                                self.cache[handles[i]] = { err = err[i] }
                        end
                end
        end
        local res = {}
        for _, tag in ipairs(tags) do
                if self.items[tag] then
                        local item = self.cache[self.items[tag]]
                        if item.err == "OK" then
                                res[#res + 1] = { success = true, value = item.result, quality = item.quality }
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
                        values[#values + 1] = vals[i]
                end
        end
        local err = self.syncio:Write(#ids, ids, values)
        local i, errors = 1, {}
        for j, tag in ipairs(tags) do
                if self.items[tag] then
                        if err[i] ~= "OK" then
                                errors[#errors + 1] = { tag = tag, value = self:errmsg(err[i]) }
                                self.cache[self.items[tag]] = { err = err[i] }
                        else
                                self.cache[self.items[tag]] = { result = vals[j], err = "OK" }
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

function open(server, host, stats, use_v2, async, user, pass)
        if type(server) == "table" then
          host = server.host
          stats = server.stats
          use_v2 = server.use_v2
          async = server.async
          user = server.user
          pass = server.pass
          server = server.server
        end
        if host == "" then host = nil end
        if stats == "" then stats = nil end
        if use_v2 == "" then use_v2 = nil end
        if async == "" then async = nil end
        if user == "" then user = nil end
        if pass == "" then pass = nil end
        local ok, server = pcall(CreateInstance, server, IOPCServer, host)
        if not ok then return nil, "server not found, COM error: " .. server end
        if user then
          local ok, sec = pcall(server.QueryInterface, server, IOPCSecurityPrivate)
          if not ok then return nil, "OPC Security interface not available: " .. server end
          if not sec:IsAvailablePriv() then
            return nil, "OPC Security interface not available: " .. server
          end
          comgen.RaisePrivacy(sec)
          local ok = pcall(sec.Logon, sec, user, pass)
          if not ok then return nil, "login to server failed: " .. server end
        end
        local ok, itemio = pcall(server.QueryInterface, server, IOPCItemIO)
        if ok and (not use_v2) and (not async) then
                server = DataAccess_v3{ server = server, itemio = itemio }
        elseif not async then
                server = DataAccess_v2{ server = server }
        else
                server = DataAccess_v2_Async{ server = server }
        end
        if stats then
                server.get = wrapped_get
                server.set = wrapped_set
                server.getblock = wrapped_getblock
                server.setblock = wrapped_setblock
                server:resetstats()
        end
        return server
end
