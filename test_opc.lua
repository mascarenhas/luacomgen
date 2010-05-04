
require "comgen"
require "opclib"

local clsid_matrikon = "{F8582CF2-88FB-11D0-B850-00C0F0104305}"
local iid_iopcserver = "{39C13A4D-011E-11D0-9675-0020AFD8ADB3}"
local iid_iopcitemmgt = "{39C13A54-011E-11D0-9675-0020AFD8ADB3}"
local iid_iopcsyncio = "{39C13A52-011E-11D0-9675-0020AFD8ADB3}"

local srv = comgen.CreateInstance(clsid_matrikon, iid_iopcserver)
local hgrp, rate, mgt = srv:AddGroup("Group1", false, 0, 0, 0, iid_iopcitemmgt)
print("Rate: ", rate)
local result, err = mgt:AddItems(3, { { szAccessPath = "",
					szItemID = "Random.Real4",
					bActive = false,
					hClient = 1,
					dwBlobSize = 0,
					pBlob = {},
					vtRequestedDataType = "VT_R4",
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
					szItemID = "Bucket Brigade.Int4",
					bActive = false,
					hClient = 1,
					dwBlobSize = 0,
					pBlob = {},
					vtRequestedDataType = "VT_I4",
					wReserved = 0 } })
local syncio = mgt:QueryInterface(iid_iopcsyncio)
local res, err = syncio:Read("OPC_DS_DEVICE", 3, { result[1].hServer, result[2].hServer, result[3].hServer })
print(res[1].vDataValue, res[2].vDataValue, res[3].vDataValue)
print(syncio:Write(1, { result[3].hServer }, { 5 })[1])
local res, err = syncio:Read("OPC_DS_DEVICE", 3, { result[1].hServer, result[2].hServer, result[3].hServer })
print(res[1].vDataValue, res[2].vDataValue, res[3].vDataValue)
