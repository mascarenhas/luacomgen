
require "comgen"
require "opclib"
require "connpoint"

module("opc", package.seeall)

local methods_async = {}
methods_async.__index = methods_async
local methods_v3 = {}
methods_v3.__index = methods_v3
local methods_v2 = {}
methods_v2.__index = methods_v2
local methods_cb = {}
methods_cb.__index = methods_cb

function open(server, host, use_v2, async)
  local ok, server = pcall(comgen.CreateInstance, server, opclib.IOPCServer, host)
  if not ok then return nil, "server not found, com error: " .. server end
  local ok, itemio = pcall(server.QueryInterface, server, opclib.IOPCItemIO)
  if ok and (not use_v2) and (not async) then
    return setmetatable({ server = server, itemio = itemio },
                        methods_v3)
  else
    local hgrp, rate, mgt = server:AddGroup("LuaGroup", true, 0, 0, 0, opclib.IOPCItemMgt)
    if async then
      local cpc = mgt:QueryInterface(connpoint.IConnectionPointContainer)
      local syncio = mgt:QueryInterface(opclib.IOPCSyncIO)
      local cp = cpc:FindConnectionPoint(opclib.IOPCDataCallback)
      local cache = {}
      local cb = setmetatable({ cache = cache }, methods_cb)
      local wrap = opclib.DataCallback(cb)
      local cookie = cp:Advise(wrap.__interfaces.IOPCDataCallback)
      return setmetatable({ server = server, hgrp = hgrp, cp = cp, cache = cache, handle = 1000,
                            mgt = mgt, syncio = syncio, cookie = cookie, cb = cb, items = {}, handles = {} },
                          methods_async)
    else
      local syncio = mgt:QueryInterface(opclib.IOPCSyncIO)
      return setmetatable({ server = server, hgrp = hgrp,
                            mgt = mgt, syncio = syncio, items = {} },
                          methods_v2)
    end
  end
end

function methods_cb:OnDataChange(dwTransid, hGroup, hrMasterquality, hrMastererror, dwCount, phClientItems,
                         pvValues, pwQualities, pftTimeStamps, pErrors)
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

function methods_cb:OnReadComplete(dwTransid, hGroup, hrMasterquality, hrMastererror, dwCount, phClientItems,
                           pvValues, pwQualities, pftTimeStamps, pErrors)
  error("not necessary")
end

function methods_cb:OnWriteComplete(dwTransid, hGroup, hrMasterquality, hrMastererror, dwCount, phClientItems,
                                    pvValues, pwQualities, pftTimeStamps, pErrors)
  error("not necessary")
end

function methods_cb:OnCancelComplete(dwTransid, hGroup)
  error("not necessary")
end

function methods_v3:errmsg(err)
  if type(err) == "number" then
    return self.server:GetErrorString(err, 1033)
  else
    return err
  end
end

methods_v2.errmsg = methods_v3.errmsg
methods_async.errmsg = methods_v3.errmsg

function methods_v3:get(tag)
  local values, quals, ts, err = self.itemio:Read(1, { tag }, { 0 })
  if err[1] == "OK" then
    return values[1], quals[1]
  else
    return nil, self:errmsg(err[1])
  end
end

function methods_async:newhandle()
  self.handle = self.handle + 1
  return self.handle
end

function methods_async:get(tag)
  if self.items[tag] then
    local item = self.cache[self.items[tag]]
    if item.err == "OK" then
      return item.result, item.quality
    else
      return nil, self:errmsg(item.err)
    end
  else
    local handle = self:newhandle()
    local result, err = self.mgt:AddItems(1, { { szAccessPath = "",
                                                 szItemID = tag,
                                                 bActive = true,
                                                 hClient = handle,
                                                 dwBlobSize = 0,
                                                 pBlob = {},
                                                 vtRequestedDataType = "VT_EMPTY",
                                                 wReserved = 0 } })
    if err[1] == "OK" then
      self.items[tag] = handle
      self.handles[tag] = result[1].hServer
      result, err = self.syncio:Read("OPC_DS_DEVICE", 1, { result[1].hServer })
      if err[1] == "OK" then
        local item = { result = result[1].vDataValue,
                       quality = result[1].wQuality,
                       err = "OK" }
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

function methods_v2:get(tag)
  if self.items[tag] then
    local result, err = self.syncio:Read("OPC_DS_DEVICE", 1, { self.items[tag] })
    if err[1] == "OK" then
      return result[1].vDataValue, result[1].wQuality
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
      result, err = self.syncio:Read("OPC_DS_DEVICE", 1, { result[1].hServer })
      if err[1] == "OK" then
        return result[1].vDataValue, result[1].wQuality
      end
    end
    return nil, self:errmsg(err[1])
  end
end

function methods_v3:set(tag, val, qual)
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

function methods_v2:set(tag, val)
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

function methods_async:set(tag, val)
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
    local result, err = self.mgt:AddItems(1, { { szAccessPath = "",
                                                 szItemID = tag,
                                                 bActive = true,
                                                 hClient = handle,
                                                 dwBlobSize = 0,
                                                 pBlob = {},
                                                 vtRequestedDataType = "VT_EMPTY",
                                                 wReserved = 0 } })
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

function methods_v3:getblock(tags)
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

function methods_v2:getblock(tags)
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

function methods_async:getblock(tags)
  local new, err_add = {}, {}
  for _, tag in ipairs(tags) do
    if not self.items[tag] then
      new[#new + 1] = { szAccessPath = "",
                        szItemID = tag,
                        bActive = true,
                        hClient = self:newhandle(),
                        dwBlobSize = 0,
                        pBlob = {},
                        vtRequestedDataType = "VT_EMPTY",
                        wReserved = 0 }
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

function methods_v3:setblock(tags, vals, quals)
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

function methods_v2:setblock(tags, vals)
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

function methods_async:setblock(tags, vals)
  local new, err_add = {}, {}
  for _, tag in ipairs(tags) do
    if not self.items[tag] then
      new[#new + 1] = { szAccessPath = "",
                        szItemID = tag,
                        bActive = true,
                        hClient = self:newhandle(),
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

function methods_v3:close()
  self.server = nil
  self.itemio = nil
end

function methods_v2:close()
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

function methods_async:close()
  local ids = {}
  for tag, id in pairs(self.items) do
    ids[#ids + 1] = id
  end
  self.cp:Unadvise(self.cookie)
  self.mgt:RemoveItems(#ids, ids)
  self.server:RemoveGroup(self.hgrp, true)
  self.cp = nil
  self.cb = nil
  self.items = nil
  self.server = nil
  self.mgt = nil
  self.syncio = nil
end
