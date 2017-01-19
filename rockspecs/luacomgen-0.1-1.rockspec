package = "luacomgen"
version = "0.1-1"
source = {
	url = "..." -- We don't have one yet
}
description = {
	summary = "Lua binding generator for COM interfaces.",
	homepage = "https://github.com/mascarenhas/luacomgen/",
	license = "MIT/X11",
}
dependencies = {
	"lua >= 5.1, < 5.4"
}
build = {
	type = "builtin",
	modules = {
		["comgen.generator"] = "comgen/generator.lua",
		["comgen.template"] = "comgen/template.lua",
		["comgen.template_wrapper"] = "comgen/template_wrapper.lua",
	},
}
