require "socket"

local lastcode = string.byte("C")
local function nextstr(text)
        for i = #text, 1, -1 do
                local code = text:byte(i)
                if code < lastcode then
                        return text:sub(1,i-1)..string.char(code+1)..string.rep("A", #text-i)
                end
        end
        return string.rep("A", #text+1)
end



local tags = {}
for i = 1, 50 do
        tags[#tags+1] = "test.EQ_FULL_"..i.."_EN"     -- bool
        tags[#tags+1] = "test.EQ_FULL_"..i.."_IT"     -- int
        tags[#tags+1] = "test.EQ_FULL_"..i.."_TOTAL"  -- real
        tags[#tags+1] = "test.EQ_FULL_"..i.."_GENTXT" -- text
end
for i = 1, 200 do
        tags[#tags+1] = "test.EQ_SIMPLE_"..i.."_BOOL" -- bool
        tags[#tags+1] = "test.EQ_SIMPLE_"..i.."_INT"  -- int
        tags[#tags+1] = "test.EQ_SIMPLE_"..i.."_REAL" -- real
        tags[#tags+1] = "test.EQ_SIMPLE_"..i.."_TXT"  -- text
end
tags[#tags+1] = "fake.MISSING_POINT"

local vals = {}
for i = 1, #tags/4 do
        vals[4*i-3] = false
        vals[4*i-2] = 0
        vals[4*i-1] = 2^50-1
        vals[4*i  ] = ""
end
--vals[#vals+1] = "The item definition does not conform to the server's syntax."
vals[#vals+1] = "The item definition does not exist in the server's address space."



local opc = require "mpa.bridge.opc"
local bridge = assert(opc.open{ server = "Matrikon.OPC.Simulation", stats = true, use_v2 = false, async = false})

print("SOCKET", socket.gettime())
print(bridge:get(tags[1]))

for i = 1, 100 do

        local write = assert(bridge:setblock(tags, vals))
        assert(#write == 1)
        assert(write[1].tag == tags[#tags])
        assert(write[1].value == vals[#vals])

        local read = assert(bridge:getblock(tags))
        assert(not read[#read].success)
        assert(read[#read].value == vals[#vals])
        -- matrikon simulation does not allow this
        bridge:setblock({tags[1]}, {true}, {100}, {socket.gettime() + 2000})
        for k, v in pairs(read[1]) do print(k, v) end
        for i, tag in ipairs(tags) do
                if i == #tags then break end
                local expected = vals[i]
                local actual = read[i].value
                if not read[i].success then
                        io.stderr:write(tag," raised error '",tostring(actual),"'\n")
                elseif expected ~= actual then
                        io.stderr:write(tag," should be '",tostring(expected),"', but got '",tostring(actual),"'\n")
                end
                local case = i%4
                if     case == 1 then vals[i] = not expected
                elseif case == 2 then vals[i] = expected+1
                elseif case == 3 then vals[i] = -expected/2
                elseif case == 0 then vals[i] = nextstr(expected)
                end
        end
end

for i = 1, 4 do
        print(vals[i])
end

bridge:close()

os.exit()
