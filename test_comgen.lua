
require "comgen"

local clsid_point = "{CCA7F35E-DAF3-11D0-8C53-0080C73925BA}"
local iid_iunknown = "{00000000-0000-0000-C000-000000000046}"
local iid_ipoint = "{CCA7F35D-DAF3-11D0-8C53-0080C73925BA}"

o = comgen.CreateInstance(clsid_point, iid_iunknown)
assert(o)
assert(o:AddRef() > 0)
assert(o:Release() > 0)


