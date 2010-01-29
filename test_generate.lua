
local generator = require "comgen.generator"

local types = generator.types

local SPoint = types.struct("SPoint", {
  { type = types.long, name = "x" },
  { type = types.long, name = "y" }
})

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
      name = "SetCoords2", 
      parameters = {
	{ type = types.variant, attributes = { ["in"] = true }, name = "x" },
	{ type = types.variant, attributes = { ["in"] = true }, name = "y" },
      }
    },
    {
      name = "GetCoords",
      parameters = {
	{ type = types.long, attributes = { out = true }, name = "px" },
	{ type = types.long, attributes = { out = true }, name = "py" }
      }
    },
    {
      name = "GetCoords2",
      parameters = {
	{ type = types.variant, attributes = { out = true }, name = "px" },
	{ type = types.variant, attributes = { out = true }, name = "py" }
      }
    },
    {
      name = "SetGetCoords",
      parameters = {
	{ type = types.variant, attributes = { ["in"] = true, out = true }, name = "px" },
	{ type = types.variant, attributes = { ["in"] = true, out = true }, name = "py" }
      }
    },
    {
      name = "GetType",
      parameters = {
	{ type = types.variant, attributes = { retval = true, out = true }, name = "t" },
      }
    },
    {
      name = "RoundTrip",
      parameters = {
	{ type = types.variant, attributes = { ["in"] = true }, name = "s1" },
	{ type = types.variant, attributes = { retval = true, out = true }, name = "s2" },
      }
    },
    {
      name = "GetType2",
      parameters = {
	{ type = types.bstring, attributes = { retval = true, out = true }, name = "t" },
      }
    },
    {
      name = "RoundTrip2",
      parameters = {
	{ type = types.bstring, attributes = { ["in"] = true }, name = "s1" },
	{ type = types.bstring, attributes = { retval = true, out = true }, name = "s2" },
      }
    },
    {
      name = "GetType3",
      parameters = {
	{ type = types.tstring, attributes = { retval = true, out = true }, name = "t" },
      }
    },
    {
      name = "RoundTrip3",
      parameters = {
	{ type = types.tstring, attributes = { ["in"] = true }, name = "s1" },
	{ type = types.tstring, attributes = { retval = true, out = true }, name = "s2" },
      }
    },
    {
      name = "GetType4",
      parameters = {
	{ type = types.wstring, attributes = { retval = true, out = true }, name = "t" },
      }
    },
    {
      name = "RoundTrip4",
      parameters = {
	{ type = types.wstring, attributes = { ["in"] = true }, name = "s1" },
	{ type = types.wstring, attributes = { retval = true, out = true }, name = "s2" },
      }
    },
    {
      name = "GetType5",
      parameters = {
	{ type = types.string, attributes = { retval = true, out = true }, name = "t" },
      }
    },
    {
      name = "RoundTrip5",
      parameters = {
	{ type = types.string, attributes = { ["in"] = true }, name = "s1" },
	{ type = types.string, attributes = { retval = true, out = true }, name = "s2" },
      }
    },
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
      name = "SetCoords2", 
      parameters = {
	{ type = SPoint, attributes = { ["in"] = true }, name = "topLeft" },
	{ type = SPoint, attributes = { ["in"] = true }, name = "botRight" }
      }
    },
    { 
      name = "SetCoords3", 
      parameters = {
	{ type = SPoint, attributes = { ["in"] = true, ref = true }, name = "topLeft" },
	{ type = SPoint, attributes = { ["in"] = true, ref = true }, name = "botRight" }
      }
    },
    { 
      name = "SetCoords4", 
      parameters = {
	{ type = types.interface(IPoint), attributes = { ["in"] = true }, name = "topLeft" },
	{ type = types.interface(IPoint), attributes = { ["in"] = true }, name = "botRight" }
      }
    },
    { 
      name = "GetCoords", 
      parameters = {
	{ type = SPoint, attributes = { out = true }, name = "topLeft" },
	{ type = SPoint, attributes = { out = true }, name = "botRight" }
      }
    },
    { 
      name = "GetCoords2", 
      parameters = {
	{ type = types.interface(IPoint), attributes = { out = true }, name = "topLeft" },
	{ type = types.interface(IPoint), attributes = { out = true }, name = "botRight" }
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
