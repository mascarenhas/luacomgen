local _G = require "_G"
local newproxy = _G.newproxy
local pairs = _G.pairs
local unpack = _G.unpack
local rawget = _G.rawget
local setmetatable = _G.setmetatable
local getmetatable = _G.getmetatable

module "mpa.oo"

--------------------------------------------------------------------------------
function rawnew(class, object)
	return setmetatable(object or {}, class)
end
--------------------------------------------------------------------------------
local FIRST = newproxy()
local LAST = newproxy()
local function contains(self, element)
	return element ~= nil and (self[element] ~= nil or element == self[LAST])
end
local function insert(self, element, previous)
	if element ~= nil and not contains(self, element) then
		if previous == nil then
			previous = self[LAST]
			if previous == nil then
				previous = FIRST
			end
		elseif not contains(self, previous) and previous ~= FIRST then
			return
		end
		if self[previous] == nil
			then self[LAST] = element
			else self[element] = self[previous]
		end
		self[previous] = element
		return element
	end
end
local function push(self, element)
	if element ~= nil and not contains(self, element) then
		if self[FIRST] ~= nil
			then self[element] = self[FIRST]
			else self[LAST] = element
		end
		self[FIRST] = element
		return element
	end
end
local function topdown(stack, class)
	while stack[class] do
		local ready = true
		if not insert(stack, superclass(stack[class]), class) then
			return stack[class]
		end
	end
end
local function iconstruct(class)
	local stack = {}
	push(stack, class)
	return topdown, stack, FIRST
end
function new(class, ...)
	local object = rawnew(class, ...)
	for class in iconstruct(class) do
		local init = memberof(class, "init")
		if init then init(object, ...) end
	end
	return object
end
--------------------------------------------------------------------------------
function initclass(class)
	if class == nil then class = {} end
	if class.__index == nil then class.__index = class end
	return class
end
--------------------------------------------------------------------------------
classof = getmetatable
--------------------------------------------------------------------------------
function instanceof(object, class)
	return classof(object) == class
end
--------------------------------------------------------------------------------
memberof = rawget
--------------------------------------------------------------------------------
members = pairs
--------------------------------------------------------------------------------
function class(class, super)
	if super
		then return setmetatable(initclass(class), { __index = super, __call = new })
		else return setmetatable(initclass(class), { __call = new })
	end
end
--------------------------------------------------------------------------------
function isclass(class)
	local metaclass = classof(class)
	if metaclass then
		return metaclass == rawget(DerivedClass, metaclass.__index) or
		       classof(class) == MetaClass
	end
end
--------------------------------------------------------------------------------
function superclass(class)
	local metaclass = classof(class)
	if metaclass then return metaclass.__index end
end
--------------------------------------------------------------------------------
function subclassof(class, super)
	while class do
		if class == super then return true end
		class = superclass(class)
	end
	return false
end
--------------------------------------------------------------------------------
function instanceof(object, class)
	return subclassof(classof(object), class)
end
