require "comgen"
require "mpclib"

local mpc = comgen.CreateInstance("MPC_Bifasico_dll.Class1", mpclib.IClass1)

print(mpc:get_TAmost())

mpc:put_TAmost(5)
