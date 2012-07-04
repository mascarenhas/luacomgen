local comgen = require "comgen"
local opc = require "mpa.bridge.opc"
local socket = require "socket.core"

local srv = assert(opc.open{ server = "Matrikon.OPC.Simulation.1", stats = false, use_v2 = true, async = false, log = "all"})
local tags = { "Random.Int4", "Bucket Brigade.Int4" }

print("GETBLOCK")
local tab = srv:getblock(tags)
for _, tag in ipairs(tab) do
  for k, v in pairs(tag) do
    print(k, v)
  end
end

--while true do
print("GET")
for _, tag in ipairs(tags) do
  print(srv:get(tag))
end
--socket.sleep(2)
--end

print("SET")
srv:set(tags[2], 500)

socket.sleep(5)

print("GET")
for _, tag in ipairs(tags) do
  print(srv:get(tag))
end

print("GETBLOCK")
local tab = srv:getblock(tags)
for _, tag in ipairs(tab) do
  for k, v in pairs(tag) do
    print(k, v)
  end
end

print("SETBLOCK")
srv:setblock(tags, { 100, 200 })

socket.sleep(2)

print("GETBLOCK")
local tab = srv:getblock(tags)
for _, tag in ipairs(tab) do
  for k, v in pairs(tag) do
    print(k, v)
  end
end

