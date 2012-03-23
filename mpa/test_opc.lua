local comgen = require "comgen"
local opc = require "mpa.bridge.opc"
local socket = require "socket.core"

local srv = opc.open("Matrikon.OPC.Simulation.1", nil, "statistics", "OPC 2.0", "async")
local tags = { "Random.Real4", "Random.Real8", "Bucket Brigade.Real4" }

--comgen.MessageStep()

local tab = srv:getblock(tags)
for _, tag in ipairs(tab) do
  for k, v in pairs(tag) do
    print(k, v)
  end
end

for _, tag in ipairs(tags) do
  print(srv:get(tag))
end

srv:set("Bucket Brigade.Real4", 1)

socket.sleep(2)

for _, tag in ipairs(tags) do
  print(srv:get(tag))
end

--comgen.MessageStep()

for _, tag in ipairs(tags) do
  print(srv:get(tag))
end

srv:setblock({ "Bucket Brigade.Real4" }, { 0 })

socket.sleep(2)

--comgen.MessageStep()

local tab = srv:getblock(tags)
for _, tag in ipairs(tab) do
  for k, v in pairs(tag) do
    print(k, v)
  end
end
