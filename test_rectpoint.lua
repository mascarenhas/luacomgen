
require "comgen"
require "rectpointlib"

local clsid_point = "{CCA7F35E-DAF3-11D0-8C53-0080C73925BA}"
local clsid_rect = "{CCA7F360-DAF3-11D0-8C53-0080C73925BA}"

local o = comgen.CreateInstance(clsid_point, comgen.IUnknown)
assert(o)
assert(o:AddRef() > 0)
assert(o:Release() > 0)

local p = o:QueryInterface(rectpointlib.IPoint)
assert(p)
assert(p:AddRef() > 0)
assert(p:Release() > 0)
p:SetCoords(2, 3)
local x, y = p:GetCoords()
assert(x == 2 and y == 3)

local r = comgen.CreateInstance(clsid_rect, rectpointlib.IRect)
assert(r)
r:SetCoords(2, 3, 4, 5)
assert(r:get_Volume() == 4)
assert(r:get_Volume() == 4)
assert(r:DrawRect("FILLED") == 1)
assert(r:DrawRect("DOTTED") == 2)
r:SetCoords2({ x = 3, y = 4 }, { x = 1, y = 7 })
assert(r:get_Volume() == -6)
local tl, br = r:GetCoords()
assert(tl.x == 3 and tl.y == 4)
assert(br.x == 1 and br.y == 7)
r:SetCoords2({ x = 4, y = 3 }, { x = 2, y = 5 })
assert(r:get_Volume() == -4)

p:SetCoords2(3, 4)
local x, y = p:GetCoords()
assert(x == 3 and y == 4)

local x, y = p:GetCoords2()
assert(x == 3 and y == 4)

local x, y = p:SetGetCoords(4, 5)
assert(x == 3 and y == 4)

local x, y = p:GetCoords()
assert(x == 4 and y == 5)

p:SetCoords2({ type = "I4", value = 2 }, { type = "INT", value = 3 })
local x, y = p:GetCoords()
assert(x == 2 and y == 3)

p:SetCoords2("5", { type = "INT", value = 3 })
local x, y = p:GetCoords()
assert(x == 5 and y == 3)

p:SetCoords2("5", "2")
local x, y = p:GetCoords()
assert(x == 5 and y == 2)

p:SetCoords2("5", { type = "BSTR", value = "2" })
local x, y = p:GetCoords()
assert(x == 5 and y == 2)

local t = p:GetType()
assert(t == "Point")

local s = p:RoundTrip("Foo Bar")
assert(s == "Foo Bar")

-- this test only works if file is encoded as UTF-8!
local s = p:RoundTrip("Constituição")
assert(s == "Constituição")

local t = p:GetType2()
assert(t == "Point")

local s = p:RoundTrip2("Foo Bar")
assert(s == "Foo Bar")

-- this test only works if file is encoded as UTF-8!
local s = p:RoundTrip2("Constituição")
assert(s == "Constituição")

local t = p:GetType3()
assert(t == "Point")

local s = p:RoundTrip3("Foo Bar")
assert(s == "Foo Bar")

-- this test only works if file is encoded as UTF-8!
local s = p:RoundTrip3("Constituição")
assert(s == "Constituição")

local t = p:GetType4()
assert(t == "Point")

local s = p:RoundTrip4("Foo Bar")
assert(s == "Foo Bar")

-- this test only works if file is encoded as UTF-8!
local s = p:RoundTrip4("Constituição")
assert(s == "Constituição")

local t = p:GetType5()
assert(t == "Point")

local s = p:RoundTrip5("Foo Bar")
assert(s == "Foo Bar")

-- this test only works if file is encoded as UTF-8!
local s = p:RoundTrip5("Constituição")
assert(s == "Constituição")

local p1 = comgen.CreateInstance(clsid_point, rectpointlib.IPoint)
p1:SetCoords(2, 5)
local p2 = comgen.CreateInstance(clsid_point, rectpointlib.IPoint)
p2:SetCoords(5, 3)
local r = comgen.CreateInstance(clsid_rect, rectpointlib.IRect)
r:SetCoords4(p1, p2)
assert(r:get_Volume() == -6)
local p1, p2 = r:GetCoords2()
local x, y = p1:GetCoords()
assert(x == 2 and y == 5)
local x, y = p2:GetCoords()
assert(x == 5 and y == 3)
p1:SetCoords(1, 5)
assert(r:get_Volume() == -8)

assert(p1:Sum({ 1, 2, 3, 4, 5 }) == 15)
assert(p1:Sum{ 1, 2, "foo", 3, 4, 5 } == 15)
assert(p1:Sum({ 1.1, 2.2, 3.3, 4.4, 5.4 }) == 15)

local arr = p1:GetCoordsArr()
assert(#arr == 2)
assert(arr[1] == 1)
assert(arr[2] == 5)

assert(p1:Sum2({ type = "I4", value = { 1, 2, 3, 4, 5 } }) == 15)
assert(p1:Sum2({ type = "I4", value = { 1.1, 2.2, 3.3, 4.4, 5.4 } }) == 15)

local arr = p1:GetCoordsArr2()
assert(#arr == 2)
assert(arr[1] == 1)
assert(arr[2] == 5)

p1:SetCoords(2,3)
p2:SetCoords(5, 7)
p3 = comgen.CreateInstance(clsid_point, rectpointlib.IPoint)
p3:SetCoords(8, 11)
assert(p1:Length({ type = "UNKNOWN", value = { p1, p2, p3 } }) == 10)

local point = { x = 2, y = 3 }

function point:GetCoords()
  return self.x, self.y
end

function point:GetCoords2()
  return self.x, self.y
end

function point:SetCoords(x, y)
  self.x, self.y = x, y
end

function point:SetCoords2(x, y)
  self.x, self.y = x, y
end

function point:SetGetCoords(x, y)
  local xold, yold = self.x, self.y
  self.x, self.y = x, y
  return xold, yold
end

function point:GetType()
  return "Point"
end

function point:RoundTrip(s)
  return s
end

for i = 2, 5 do
  point["GetType" .. i] = point.GetType
  point["RoundTrip" .. i] = point.RoundTrip
end

local pc = rectpointlib.LuaPoint(point)
local p = pc.__interfaces.IPoint

assert(p)
assert(p:AddRef() > 0)
assert(p:Release() > 0)

local x, y = p:GetCoords()
assert(x == 2 and y == 3)

p:SetCoords(3, 4)
local x, y = p:GetCoords()
assert(x == 3 and y == 4)

p:SetCoords2(5, 6)
local x, y = p:GetCoords()
assert(x == 5 and y == 6)

local x, y = p:GetCoords2()
assert(x == 5 and y == 6)

local x, y = p:SetGetCoords(2, 3)
assert(x == 5 and y == 6)

local x, y = p:GetCoords()
assert(x == 2 and y == 3)

p:SetCoords2({ type = "I4", value = 2 }, { type = "INT", value = 3 })
local x, y = p:GetCoords()
assert(x == 2 and y == 3)

p:SetCoords2("5", { type = "INT", value = 3 })
local x, y = p:GetCoords()
assert(x == 5 and y == 3)

p:SetCoords2("5", "2")
local x, y = p:GetCoords()
assert(x == 5 and y == 2)

p:SetCoords2("5", { type = "BSTR", value = "2" })
local x, y = p:GetCoords()
assert(x == 5 and y == 2)

local t = p:GetType()
assert(t == "Point")

local s = p:RoundTrip("Foo Bar")
assert(s == "Foo Bar")

local t = p:GetType2()
assert(t == "Point")

local s = p:RoundTrip2("Foo Bar")
assert(s == "Foo Bar")

-- this test only works if file is encoded as UTF-8!
local s = p:RoundTrip2("Constituição")
assert(s == "Constituição")

local t = p:GetType3()
assert(t == "Point")

local s = p:RoundTrip3("Foo Bar")
assert(s == "Foo Bar")

-- this test only works if file is encoded as UTF-8!
local s = p:RoundTrip3("Constituição")
assert(s == "Constituição")

local t = p:GetType4()
assert(t == "Point")

local s = p:RoundTrip4("Foo Bar")
assert(s == "Foo Bar")

-- this test only works if file is encoded as UTF-8!
local s = p:RoundTrip4("Constituição")
assert(s == "Constituição")

local t = p:GetType5()
assert(t == "Point")

local s = p:RoundTrip5("Foo Bar")
assert(s == "Foo Bar")

-- this test only works if file is encoded as UTF-8!
local s = p:RoundTrip5("Constituição")
assert(s == "Constituição")

function point:Sum(t)
  local s = 0
  for _, x in ipairs(t) do s = s + x end
  return s
end

assert(p:Sum({ 1, 2, 3, 4, 5 }) == 15)
assert(p:Sum{ 1, 2, "foo", 3, 4, 5 } == 15)
assert(p:Sum({ 1.1, 2.2, 3.3, 4.4, 5.4 }) == 15)

function point:GetCoordsArr()
  return { self.x, self.y }
end

local arr = p:GetCoordsArr()
assert(#arr == 2)
assert(arr[1] == 5)
assert(arr[2] == 2)

point.Sum2 = point.Sum

assert(p:Sum2({ type = "I4", value = { 1, 2, 3, 4, 5 } }) == 15)
assert(p:Sum2({ type = "I4", value = { 1.1, 2.2, 3.3, 4.4, 5.4 } }) == 15)

function point:GetCoordsArr2()
  return { type = "I4", value = { self.x, self.y } }
end

local arr = p:GetCoordsArr2()
assert(#arr == 2)
assert(arr[1] == 5)
assert(arr[2] == 2)

local rect = { tl = p1, br = p2 }
local rc = rectpointlib.LuaRect(rect)
local r = rc.__interfaces.IRect
assert(r)

function rect:SetCoords(l, t, r, b)
  self.tl:SetCoords(l, t)
  self.br:SetCoords(r, b)
end

function rect:get_Volume()
  local l, t = self.tl:GetCoords()
  local r, b = self.br:GetCoords()
  return (r - l) * (b - t)
end

function rect:DrawRect(style)
  if style == "FILLED" then return 1 else return 2 end
end

r:SetCoords(2, 3, 4, 5)
assert(r:get_Volume() == 4)
assert(r:get_Volume() == 4)
assert(r:DrawRect("FILLED") == 1)
assert(r:DrawRect("DOTTED") == 2)

function rect:SetCoords2(tl, br)
  self.tl:SetCoords(tl.x, tl.y)
  self.br:SetCoords(br.x, br.y)
end

r:SetCoords2({ x = 3, y = 4 }, { x = 1, y = 7 })
assert(r:get_Volume() == -6)

function rect:GetCoords()
  local l, t = self.tl:GetCoords()
  local r, b = self.br:GetCoords()
  return { x = l, y = t }, { x = r, y = b }
end

local tl, br = r:GetCoords()
assert(tl.x == 3 and tl.y == 4)
assert(br.x == 1 and br.y == 7)
r:SetCoords2({ x = 4, y = 3 }, { x = 2, y = 5 })
assert(r:get_Volume() == -4)

local p1 = comgen.CreateInstance(clsid_point, rectpointlib.IPoint)
p1:SetCoords(2, 5)
local p2 = comgen.CreateInstance(clsid_point, rectpointlib.IPoint)
p2:SetCoords(5, 3)

function rect:SetCoords4(tl, br)
  self.tl, self.br = tl, br
end

function rect:GetCoords2()
  return self.tl, self.br
end

r:SetCoords4(p1, p2)
assert(r:get_Volume() == -6)
local p1, p2 = r:GetCoords2()
local x, y = p1:GetCoords()
assert(x == 2 and y == 5)
local x, y = p2:GetCoords()
assert(x == 5 and y == 3)
p1:SetCoords(1, 5)
assert(r:get_Volume() == -8)

