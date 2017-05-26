package = "luaopc"
version = "scm-1"
source = {
	url = "https://github.com/renatomaia/luacomgen/archive/master.zip",
	dir = "luacomgen-master",
}
description = {
	summary = "Lua binding of interfaces defined by the OPC foundation",
	detailed = [[
		The OPC Foundation provides standard interfaces to facilitate the
		development servers and clients of process control system by multiple
		vendors that shall inter-operate seamlessly together.
	]],
	homepage = "https://github.com/mascarenhas/luacomgen/tree/master/opc",
	license = "MIT/X11",
}
dependencies = {
	"lua >= 5.2, < 5.4",
}

local libs = { "ole32", "oleaut32" }
--local libs = { "ole32", "oleaut32", "shlwapi", "htmlhelp", "atls" }
local vars-- = { CFLAGS = "-EHsc" }
build = {
	type = "builtin",
	modules = {
		["opc.connpoint"] = {
			sources = { "connpoint.cpp" },
			libraries = libs,
			variables = vars,
		},
		["opc.security"] = {
			incdirs = {"opc"},
			sources = { "opcsec.cpp" },
			libraries = libs,
			variables = vars,
		},
		["opc.da"] = {
			incdirs = {"opc"},
			sources = { "opclib.cpp", "opclib_w.cpp" },
			libraries = libs,
			variables = vars,
		},
		["opc.ae"] = {
			incdirs = {"opc"},
			sources = { "opcae.cpp", "opcae_w.cpp" },
			libraries = libs,
			variables = vars,
		},
	}
}
