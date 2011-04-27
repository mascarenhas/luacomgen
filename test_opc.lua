
require "comgen"
require "opclib"
require "connpoint"
require "opcae"

local srv = comgen.CreateInstance("Matrikon.OPC.Simulation.1", opclib.IOPCServer)
local hgrp, rate, mgt = srv:AddGroup("Group1", true, 0, 0, 0, opclib.IOPCItemMgt)
print("Rate: ", rate)
local result, err = mgt:AddItems(3, { { szAccessPath = "",
                                        szItemID = "Random.Real4",
                                        bActive = true,
                                        hClient = 1,
                                        dwBlobSize = 0,
                                        pBlob = {},
                                        vtRequestedDataType = "VT_BSTR",
                                        wReserved = 0 },
                                    { szAccessPath = "",
                                        szItemID = "Random.Real8",
                                        bActive = true,
                                        hClient = 1,
                                        dwBlobSize = 0,
                                        pBlob = {},
                                        vtRequestedDataType = "VT_R8",
                                        wReserved = 0 },
                                    { szAccessPath = "",
                                        szItemID = "Write Only.Real4",
                                        bActive = false,
                                        hClient = 1,
                                        dwBlobSize = 0,
                                        pBlob = {},
                                        vtRequestedDataType = "VT_EMPTY",
                                        wReserved = 0 } })
for k, v in pairs(result[3]) do print(k, v) end
local syncio = mgt:QueryInterface(opclib.IOPCSyncIO)
local res, err = syncio:Read("OPC_DS_DEVICE", 3, { result[1].hServer, result[2].hServer, result[3].hServer })
print(res[1].vDataValue, res[2].vDataValue, res[3].vDataValue)
print(syncio:Write(1, { result[3].hServer }, { 1 })[1])
local res, err = syncio:Read("OPC_DS_DEVICE", 3, { result[1].hServer, result[2].hServer, result[3].hServer })
print(res[1].vDataValue, res[2].vDataValue, res[3].vDataValue)

local itemio = srv:QueryInterface(opclib.IOPCItemIO)
local values, quals, ts, err = itemio:Read(3, { "Random.Real4", "Random.Real8", "Bucket Brigade.Real4" }, { 0, 0, 0 })
print(values[1], values[2], values[3])
print(quals[1], quals[2], quals[3])
local err = itemio:WriteVQT(1, { "Bucket Brigade.Real4" }, { { vDataValue = 1, ftTimeStamp = {} } })
print(err[1])
local values, quals, ts, err = itemio:Read(3, { "Random.Real4", "Random.Real8", "Bucket Brigade.Real4" }, { 0, 0, 0 })
print(values[1], values[2], values[3])
print(quals[1], quals[2], quals[3])

local prop = srv:QueryInterface(opclib.IOPCItemProperties)
assert(prop)
local count, ids, descs, types = prop:QueryAvailableProperties("Random.Real8")
print("===== Random.Real8 properties")
for i = 1, count do
  print(ids[i], descs[i], types[i])
end
print("===== Random.Real8 properties")
local data, err = prop:GetItemProperties("Random.Real8", 1, { 2 })
print(data[1], err[1])

local cpc = mgt:QueryInterface(connpoint.IConnectionPointContainer)
local cp = cpc:FindConnectionPoint(opclib.IOPCDataCallback)

local cb = {}

function cb:OnDataChange(dwTransid, hGroup, hrMasterquality, hrMastererror, dwCount, phClientItems,
                         pvValues, pwQualities, pftTimeStamps, pErrors)
  print("data change")
  for _, item in ipairs(pvValues) do
    print(item)
  end
end

function cb:OnReadComplete(dwTransid, hGroup, hrMasterquality, hrMastererror, dwCount, phClientItems,
                           pvValues, pwQualities, pftTimeStamps, pErrors)
  print("read complete")
  for _, item in ipairs(phClientItems) do
    print(item)
  end
end

function cb:OnWriteComplete(dwTransid, hGroup, hrMasterquality, hrMastererror, dwCount, phClientItems, pvValues, pwQualities, pftTimeStamps, pErrors)
  print("write complete")
end

function cb:OnCancelComplete(dwTransid, hGroup)
  print("cancel complete")
end

local wrap1 = opclib.DataCallback(cb)
--local cookie = cp:Advise(wrap1.__interfaces.IOPCDataCallback)

local aesrv = srv:QueryInterface(opcae.IOPCEventServer)
local cpc, time, max = aesrv:CreateEventSubscription(true, 0, 0, 100, connpoint.IConnectionPointContainer)
print("time, max:", time, max)
print(cpc.FindConnectionPoint, opcae.IOPCEventSink)
local cp = cpc:FindConnectionPoint(opcae.IOPCEventSink)
print(cp)

local es = {}

function es:OnEvent(handle, refresh, lastrefresh, count, events)
  print("handle", handle, "refresh", refresh, "lastrefresh", lastrefresh)
  print(count, events)
  assert(count == #events)
  for i, ev in ipairs(events) do
    print("EVENT", i)
    for k, v in pairs(ev) do
      print(k, v)
    end
  end
end

local wrap2 = opcae.EventSink(es)
local cookie = cp:Advise(wrap2.__interfaces.IOPCEventSink)

while comgen.MessageStep() do
  print("step")
end
