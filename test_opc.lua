
require "comgen"
require "opclib"

local srv = comgen.CreateInstance("Matrikon.OPC.Simulation.1", opclib.IOPCServer)
local hgrp, rate, mgt = srv:AddGroup("Group1", false, 0, 0, 0, opclib.IOPCItemMgt)
print("Rate: ", rate)
local result, err = mgt:AddItems(3, { { szAccessPath = "",
                                        szItemID = "Random.Real4",
                                        bActive = false,
                                        hClient = 1,
                                        dwBlobSize = 0,
                                        pBlob = {},
                                        vtRequestedDataType = "VT_BSTR",
                                        wReserved = 0 },
                                    { szAccessPath = "",
                                        szItemID = "Random.Real8",
                                        bActive = false,
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
