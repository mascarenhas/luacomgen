package = "luacomgen"
version = "scm-1"
source = {
		url = "https://github.com/renatomaia/luacomgen/archive/master.zip",
		dir = "luacomgen-master",
}
description = {
	summary = "Lua binding generator for COM interfaces.",
	homepage = "https://github.com/mascarenhas/luacomgen/",
	license = "MIT",
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
