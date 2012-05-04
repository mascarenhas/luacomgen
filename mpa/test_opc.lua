local comgen = require "comgen"
local opc = require "mpa.bridge.opc"
local socket = require "socket.core"

local srv = assert(opc.open{ server = "Matrikon.OPC.Simulation.1", stats = false, use_v2 = true, async = true})
local tags = { "Random.Real4", "test.FOO_1", "Bucket Brigade.Real4" }

comgen.MessageStep()
comgen.MessageStep()

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

comgen.MessageStep()
comgen.MessageStep()

for _, tag in ipairs(tags) do
  print(srv:get(tag))
end

srv:setblock({ "Bucket Brigade.Real4" }, { 0 })

socket.sleep(2)

comgen.MessageStep()
comgen.MessageStep()

local tab = srv:getblock(tags)
for _, tag in ipairs(tab) do
  for k, v in pairs(tag) do
    print(k, v)
  end
end

while true do
  comgen.MessageStep()
  --print(srv:get("Random.Real"))
end