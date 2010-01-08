
local generator = require "comgen.generator"

local types = generator.types

local IPoint = {
  name = "IPoint",
  iid = "{CCA7F35D-DAF3-11D0-8C53-0080C73925BA}",
  parent = { name = "IUnknown", iid = "{00000000-0000-0000-C000-000000000046}" },
  methods = {
    { 
      name = "SetCoords", 
      parameters = {
	{ type = types.long, attributes = { ["in"] = true }, name = "x" },
	{ type = types.long, attributes = { ["in"] = true }, name = "y" },
      }
    },
    {
      name = "GetCoords",
      parameters = {
	{ type = types.long, attributes = { out = true }, name = "px" },
	{ type = types.long, attributes = { out = true }, name = "py" }
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
	{ type = types.long, attributes = { ["in"] = true }, name = "left" },
	{ type = types.long, attributes = { ["in"] = true }, name = "top" },
	{ type = types.long, attributes = { ["in"] = true }, name = "right" },
	{ type = types.long, attributes = { ["in"] = true }, name = "bottom" }
      }
    },
    {
      name = "Volume",
      attributes = { propget = true },
      parameters = {
	{ type = types.long, attributes = { out = true, retval = true }, name = "pVal" }
      }
    },
    {
      name = "DrawRect",
      parameters = {
	{ type = types.enum("RECTTYPE"), attributes = { ["in"] = true }, name = "type" },
	{ type = types.long, attributes = { out = true, retval = true }, name = "res" }
      }
    }
  }
}

local RECTTYPE = {
  name = "RECTTYPE",
  fields = {
    { name = "FILLED", value = 1 },
    { name = "DOTTED", value = 2 }
  }
}

local rectpoint = {
  modname = "rectpointlib",
  header = "rectpoint",
  interfaces = { IRect, IPoint },
  enums = { RECTTYPE }
}

local source, def = generator.compile(rectpoint)

generator.writefile("rectpointlib.cpp", source)
generator.writefile("rectpointlib.def", def)
