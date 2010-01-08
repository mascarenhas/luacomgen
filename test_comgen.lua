
require "comgen"
require "ipoint"
require "irect"

local clsid_point = "{CCA7F35E-DAF3-11D0-8C53-0080C73925BA}"
local iid_iunknown = "{00000000-0000-0000-C000-000000000046}"
local iid_ipoint = "{CCA7F35D-DAF3-11D0-8C53-0080C73925BA}"
local clsid_rect = "{CCA7F360-DAF3-11D0-8C53-0080C73925BA}"
local iid_irect = "{CCA7F35F-DAF3-11D0-8C53-0080C73925BA}"

local o = comgen.CreateInstance(clsid_point, iid_iunknown)
assert(o)
assert(o:AddRef() > 0)
assert(o:Release() > 0)

local p = o:QueryInterface(iid_ipoint)
assert(p)
assert(p:AddRef() > 0)
assert(p:Release() > 0)
p:SetCoords(2, 3)
local x, y = p:GetCoords()
assert(x == 2 and y == 3)

local r = comgen.CreateInstance(clsid_rect, iid_irect)
assert(r)
r:SetCoords(2, 3, 4, 5)
assert(r:Volume() == 4)
