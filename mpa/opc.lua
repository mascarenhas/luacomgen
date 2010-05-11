
require "comgen"
require "opclib"

module("opc", package.seeall)

local methods = {}
methods.__index = methods

function open(server)
  local server = comgen.CreateInstance(server, opclib.IOPCServer)
  local itemio = server:QueryInterface(opclib.IOPCItemIO)
  return setmetatable({ server = server, itemio = itemio },
		    methods)
end

function methods:errmsg(err)
  if type(err) == "number" then
    return self.server:GetErrorString(err, 1033)
  else
    return err
  end
end

function methods:get(tag)
  local values, quals, ts, err = self.itemio:Read(1, { tag }, { 0 })
  if err[1] == "OK" then
    return values[1], quals[1]
  else
    return nil, self:errmsg(err[1])
  end
end

function methods:set(tag, val, qual)
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

function methods:getblock(tags)
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

function methods:setblock(tags, vals, quals)
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

function methods:close()
  self.server = nil
  self.itemio = nil
end
