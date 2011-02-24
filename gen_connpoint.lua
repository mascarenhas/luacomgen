local generator = require "comgen.generator"

local types = generator.types

local IUnknown = { name = "IUnknown", iid = "{00000000-0000-0000-C000-000000000046}" }

local IConnectionPoint = {
  name = "IConnectionPoint",
  iid = "{B196B286-BAB4-101A-B69C-00AA00341D07}",
  parent = IUnknown,
  methods = {
    {
      name = "GetConnectionInterface",
      parameters = {
        { type = types.refiid, attributes = { out = true, retval = true }, name = "pIID" }
      }
    },
    {
      name = "Advise",
      parameters = {
        { type = types.interface(IUnknown), attributes = { ["in"] = true }, name = "pUnkSink" },
        { type = types.dword, attributes = { out = true, retval = true }, name = "pdwCookie" }
      }
    },
    {
      name = "Unadvise",
	  parameters = {
	    { type = types.dword, attributes = { ["in"] = true }, name = "cookie" }
      }
    }
  }
}

local IConnectionPointContainer = {
  name = "IConnectionPointContainer",
  iid = "{B196B284-BAB4-101A-B69C-00AA00341D07}",
  parent = IUnknown,
  methods = {
	{
	  name = "FindConnectionPoint",
	  parameters = {
	    { type = types.refiid, attributes = { ["in"] = true }, name = "riid" },
	    { type = types.interface(IConnectionPoint),
	      attributes = { out = true, retval = true },
	      name = "ppCP" }
	  }
	}
  }
}

local connpoint = {
  modname = "connpoint",
  header = "ocidl",
  interfaces = { IConnectionPointContainer, IConnectionPoint },
  builtin = true
}

local source, def = generator.compile(connpoint)

generator.writefile("connpoint.cpp", source)
generator.writefile("connpoint.def", def)
