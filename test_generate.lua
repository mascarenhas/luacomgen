
local generator = require "comgen.generator"

local IPoint = {
  name = "IPoint",
  iid = "{CCA7F35D-DAF3-11D0-8C53-0080C73925BA}",
  parent = { name = "IUnknown", iid = "{00000000-0000-0000-C000-000000000046}" },
  methods = {
    { 
      name = "SetCoords", 
      parameters = {
	{ type = "long", attributes = { ["in"] = true }, name = "x" },
	{ type = "long", attributes = { ["in"] = true }, name = "y" },
      }
    },
    {
      name = "GetCoords",
      parameters = {
	{ type = "long", attributes = { out = true }, name = "px" },
	{ type = "long", attributes = { out = true }, name = "py" }
      }
    }
  }
}

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

local rectpoint = {
  modname = "rectpointlib",
  header = "rectpoint",
  interfaces = { IRect, IPoint }
}

local source, def = generator.compile(rectpoint)

generator.writefile("rectpointlib.cpp", source)
generator.writefile("rectpointlib.def", def)
