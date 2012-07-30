require "comgen"
require "mpclib"

local mpc = comgen.CreateInstance("MPC_Bifasico_dll.Class1", mpclib.IClass1)

TAmost = 5
Pfwd = 240
PCfwd = 120
nu = 1
np = 1
ny = 1
q = 1
r = 20000
ys = 50
yspmax = 70
yspmin = 30
umax = 0.02
umin = 0
dumax = 0.003
LTRange_h = 1
Bias_h = 0.05
CV = 0.2
gamaw = 1000
gamal = 905
C = 5
D = 1.03
u0_in1 = 0.004
xk_1_in1 = 0.56
Fo_in1 = 0
ParametrosForaDaFaixa_in1 = { type = "R8", value = { 0.0, 0.0, 1.0 } }
h_atual = 50
h_passado_in1 = 50
Pvaso = 8
Pjus = 5

print(mpc:MPC_Bifasico_dll(9, TAmost, Pfwd, PCfwd, nu, np, ny, q, r, ys, yspmax, yspmin, umax, umin, dumax, LTRange_h, Bias_h, CV, gamaw, gamal, Gw, Gl, Gg, C, D, u0_in1, xk_1_in1, Fo_in1, ParametrosForaDaFaixa_in1, h_atual, h_passado_in1, Pvaso, Pjus))
