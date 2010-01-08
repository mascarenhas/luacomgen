
local generator = require "comgen.generator"

local IRect = {
  name = "IRect",
  iid = "{CCA7F35F-DAF3-11D0-8C53-0080C73925BA}",
  parent = { name = "IUnknown", iid = "{00000000-0000-0000-C000-000000000046}" },
  methods = {
    { 
      name = "SetCoords", 
      parameters = {
	{ type = "long", attributes = { ["in"] = true }, name = "left" },
	{ type = "long", attributes = { ["in"] = true }, name = "top" },
	{ type = "long", attributes = { ["in"] = true }, name = "right" },
	{ type = "long", attributes = { ["in"] = true }, name = "bottom" }
      }
    },
    {
      name = "Volume",
      attributes = { propget = true },
      parameters = {
	{ type = "long", attributes = { out = true, retval = true }, name = "pVal" }
      }
    }
  }
}

local source, def = generator.compile(IRect)

generator.writefile("irect.cpp", source)
generator.writefile("irect.def", def)
