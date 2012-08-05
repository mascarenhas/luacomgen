
local generator = require "comgen.generator"

local types = generator.types

local IUnknown =  { name = "IUnknown", iid = "{00000000-0000-0000-C000-000000000046}" }

local IDispatch =  { name = "IDispatch", iid = "{00020400-0000-0000-C000-000000000046}", parent = IUnknown, methods = {} }

local IClass1 = {
  name = "IClass1",
  iid = "{3723DFA6-9143-462D-94B8-94B79E73897D}",
  parent = IDispatch,
  methods = {
    {
      name = "MPC_Bifasico_dll",
      parameters = {
        { type = types.long, attributes = { ["in"] = true }, name = "nargout" },
        { type = types.variant, attributes = { ["in"] = true, out = true }, name = "Kph" },
        { type = types.variant, attributes = { ["in"] = true, out = true }, name = "SPh" },
        { type = types.variant, attributes = { ["in"] = true, out = true }, name = "exitFlag" },
        { type = types.variant, attributes = { ["in"] = true, out = true }, name = "u0" },
        { type = types.variant, attributes = { ["in"] = true,  out = true }, name = "xk_1" },
        { type = types.variant, attributes = { ["in"] = true,  out = true }, name = "Fo" },
        { type = types.variant, attributes = { ["in"] = true,  out = true }, name = "x0" },
        { type = types.variant, attributes = { ["in"] = true,  out = true }, name = "ParametrosForaDaFaixa" },
        { type = types.variant, attributes = { ["in"] = true, out = true }, name = "h_passado" },
        { type = types.variant, attributes = { ["in"] = true }, name = "TAmost" },
        { type = types.variant, attributes = { ["in"] = true }, name = "Pfwd" },
        { type = types.variant, attributes = { ["in"] = true }, name = "PCfwd" },
        { type = types.variant, attributes = { ["in"] = true }, name = "nu" },
        { type = types.variant, attributes = { ["in"] = true }, name = "np" },
        { type = types.variant, attributes = { ["in"] = true }, name = "ny" },
        { type = types.variant, attributes = { ["in"] = true }, name = "q" },
        { type = types.variant, attributes = { ["in"] = true }, name = "r" },
        { type = types.variant, attributes = { ["in"] = true }, name = "ys" },
        { type = types.variant, attributes = { ["in"] = true }, name = "yspmax" },
        { type = types.variant, attributes = { ["in"] = true }, name = "yspmin" },
        { type = types.variant, attributes = { ["in"] = true }, name = "umax" },
        { type = types.variant, attributes = { ["in"] = true }, name = "umin" },
        { type = types.variant, attributes = { ["in"] = true }, name = "dumax" },
        { type = types.variant, attributes = { ["in"] = true }, name = "LTRange_h" },
        { type = types.variant, attributes = { ["in"] = true }, name = "Bias_h" },
        { type = types.variant, attributes = { ["in"] = true }, name = "CV" },
        { type = types.variant, attributes = { ["in"] = true }, name = "gamaw" },
        { type = types.variant, attributes = { ["in"] = true }, name = "gamal" },
        { type = types.variant, attributes = { ["in"] = true }, name = "Gw" },
        { type = types.variant, attributes = { ["in"] = true }, name = "Gl" },
        { type = types.variant, attributes = { ["in"] = true }, name = "Gg" },
        { type = types.variant, attributes = { ["in"] = true }, name = "C" },
        { type = types.variant, attributes = { ["in"] = true }, name = "D" },
        { type = types.variant, attributes = { ["in"] = true }, name = "u0_in1" },
        { type = types.variant, attributes = { ["in"] = true }, name = "xk_1_in1" },
        { type = types.variant, attributes = { ["in"] = true }, name = "Fo_in1" },
        { type = types.variant, attributes = { ["in"] = true }, name = "ParametrosForaDaFaixa_in1" },
        { type = types.variant, attributes = { ["in"] = true }, name = "h_atual" },
        { type = types.variant, attributes = { ["in"] = true }, name = "h_passado_in1" },
        { type = types.variant, attributes = { ["in"] = true }, name = "Pvaso" },
        { type = types.variant, attributes = { ["in"] = true }, name = "Pjus" },
      }
    },
    {
      name = "put_Kph",
      parameters = {
        { type = types.variant, attributes = { ["in"] = true }, name = "param" },
      }
    },
    {
      name = "get_Kph",
      parameters = {
        { type = types.variant, attributes = { out = true, retval = true }, name = "param" },
      }
    },
    {
      name = "put_SPh",
      parameters = {
        { type = types.variant, attributes = { ["in"] = true }, name = "param" },
      }
    },
    {
      name = "get_SPh",
      parameters = {
        { type = types.variant, attributes = { out = true, retval = true }, name = "param" },
      }
    },
    {
      name = "put_exitFlag",
      parameters = {
        { type = types.variant, attributes = { ["in"] = true }, name = "param" },
      }
    },
    {
      name = "get_exitFlag",
      parameters = {
        { type = types.variant, attributes = { out = true, retval = true }, name = "param" },
      }
    },
    {
      name = "put_u0",
      parameters = {
        { type = types.variant, attributes = { ["in"] = true }, name = "param" },
      }
    },
    {
      name = "get_u0",
      parameters = {
        { type = types.variant, attributes = { out = true, retval = true }, name = "param" },
      }
    },
    {
      name = "put_xk_1",
      parameters = {
        { type = types.variant, attributes = { ["in"] = true }, name = "param" },
      }
    },
    {
      name = "get_xk_1",
      parameters = {
        { type = types.variant, attributes = { out = true, retval = true }, name = "param" },
      }
    },
    {
      name = "put_Fo",
      parameters = {
        { type = types.variant, attributes = { ["in"] = true }, name = "param" },
      }
    },
    {
      name = "get_Fo",
      parameters = {
        { type = types.variant, attributes = { out = true, retval = true }, name = "param" },
      }
    },
    {
      name = "put_x0",
      parameters = {
        { type = types.variant, attributes = { ["in"] = true }, name = "param" },
      }
    },
    {
      name = "get_x0",
      parameters = {
        { type = types.variant, attributes = { out = true, retval = true }, name = "param" },
      }
    },
    {
      name = "put_ParametrosForaDaFaixa",
      parameters = {
        { type = types.variant, attributes = { ["in"] = true }, name = "param" },
      }
    },
    {
      name = "get_ParametrosForaDaFaixa",
      parameters = {
        { type = types.variant, attributes = { out = true, retval = true }, name = "param" },
      }
    },
    {
      name = "put_h_passado",
      parameters = {
        { type = types.variant, attributes = { ["in"] = true }, name = "param" },
      }
    },
    {
      name = "get_h_passado",
      parameters = {
        { type = types.variant, attributes = { out = true, retval = true }, name = "param" },
      }
    },
    {
      name = "put_TAmost",
      parameters = {
        { type = types.variant, attributes = { ["in"] = true }, name = "param" },
      }
    },
    {
      name = "get_TAmost",
      parameters = {
        { type = types.variant, attributes = { out = true, retval = true }, name = "param" },
      }
    },
    {
      name = "put_Pfwd",
      parameters = {
        { type = types.variant, attributes = { ["in"] = true }, name = "param" },
      }
    },
    {
      name = "get_Pfwd",
      parameters = {
        { type = types.variant, attributes = { out = true, retval = true }, name = "param" },
      }
    },
    {
      name = "put_PCfwd",
      parameters = {
        { type = types.variant, attributes = { ["in"] = true }, name = "param" },
      }
    },
    {
      name = "get_PCfwd",
      parameters = {
        { type = types.variant, attributes = { out = true, retval = true }, name = "param" },
      }
    },
    {
      name = "put_nu",
      parameters = {
        { type = types.variant, attributes = { ["in"] = true }, name = "param" },
      }
    },
    {
      name = "get_nu",
      parameters = {
        { type = types.variant, attributes = { out = true, retval = true }, name = "param" },
      }
    },
    {
      name = "put_np",
      parameters = {
        { type = types.variant, attributes = { ["in"] = true }, name = "param" },
      }
    },
    {
      name = "get_np",
      parameters = {
        { type = types.variant, attributes = { out = true, retval = true }, name = "param" },
      }
    },
    {
      name = "put_ny",
      parameters = {
        { type = types.variant, attributes = { ["in"] = true }, name = "param" },
      }
    },
    {
      name = "get_ny",
      parameters = {
        { type = types.variant, attributes = { out = true, retval = true }, name = "param" },
      }
    },
    {
      name = "put_q",
      parameters = {
        { type = types.variant, attributes = { ["in"] = true }, name = "param" },
      }
    },
    {
      name = "get_q",
      parameters = {
        { type = types.variant, attributes = { out = true, retval = true }, name = "param" },
      }
    },
    {
      name = "put_r",
      parameters = {
        { type = types.variant, attributes = { ["in"] = true }, name = "param" },
      }
    },
    {
      name = "get_r",
      parameters = {
        { type = types.variant, attributes = { out = true, retval = true }, name = "param" },
      }
    },
    {
      name = "put_ys",
      parameters = {
        { type = types.variant, attributes = { ["in"] = true }, name = "param" },
      }
    },
    {
      name = "get_ys",
      parameters = {
        { type = types.variant, attributes = { out = true, retval = true }, name = "param" },
      }
    },
    {
      name = "put_yspmin",
      parameters = {
        { type = types.variant, attributes = { ["in"] = true }, name = "param" },
      }
    },
    {
      name = "get_yspmin",
      parameters = {
        { type = types.variant, attributes = { out = true, retval = true }, name = "param" },
      }
    },
    {
      name = "put_yspmax",
      parameters = {
        { type = types.variant, attributes = { ["in"] = true }, name = "param" },
      }
    },
    {
      name = "get_yspmax",
      parameters = {
        { type = types.variant, attributes = { out = true, retval = true }, name = "param" },
      }
    },
    {
      name = "put_umax",
      parameters = {
        { type = types.variant, attributes = { ["in"] = true }, name = "param" },
      }
    },
    {
      name = "get_umax",
      parameters = {
        { type = types.variant, attributes = { out = true, retval = true }, name = "param" },
      }
    },
    {
      name = "put_umin",
      parameters = {
        { type = types.variant, attributes = { ["in"] = true }, name = "param" },
      }
    },
    {
      name = "get_umin",
      parameters = {
        { type = types.variant, attributes = { out = true, retval = true }, name = "param" },
      }
    },
    {
      name = "put_dumax",
      parameters = {
        { type = types.variant, attributes = { ["in"] = true }, name = "param" },
      }
    },
    {
      name = "get_dumax",
      parameters = {
        { type = types.variant, attributes = { out = true, retval = true }, name = "param" },
      }
    },
    {
      name = "put_LTRange_h",
      parameters = {
        { type = types.variant, attributes = { ["in"] = true }, name = "param" },
      }
    },
    {
      name = "get_LTRange_h",
      parameters = {
        { type = types.variant, attributes = { out = true, retval = true }, name = "param" },
      }
    },
    {
      name = "put_Bias_h",
      parameters = {
        { type = types.variant, attributes = { ["in"] = true }, name = "param" },
      }
    },
    {
      name = "get_Bias_h",
      parameters = {
        { type = types.variant, attributes = { out = true, retval = true }, name = "param" },
      }
    },
    {
      name = "put_CV",
      parameters = {
        { type = types.variant, attributes = { ["in"] = true }, name = "param" },
      }
    },
    {
      name = "get_CV",
      parameters = {
        { type = types.variant, attributes = { out = true, retval = true }, name = "param" },
      }
    },
    {
      name = "put_gamaw",
      parameters = {
        { type = types.variant, attributes = { ["in"] = true }, name = "param" },
      }
    },
    {
      name = "get_gamaw",
      parameters = {
        { type = types.variant, attributes = { out = true, retval = true }, name = "param" },
      }
    },
    {
      name = "put_gamal",
      parameters = {
        { type = types.variant, attributes = { ["in"] = true }, name = "param" },
      }
    },
    {
      name = "get_gamal",
      parameters = {
        { type = types.variant, attributes = { out = true, retval = true }, name = "param" },
      }
    },
    {
      name = "put_Gw",
      parameters = {
        { type = types.variant, attributes = { ["in"] = true }, name = "param" },
      }
    },
    {
      name = "get_Gw",
      parameters = {
        { type = types.variant, attributes = { out = true, retval = true }, name = "param" },
      }
    },
    {
      name = "put_Gl",
      parameters = {
        { type = types.variant, attributes = { ["in"] = true }, name = "param" },
      }
    },
    {
      name = "get_Gl",
      parameters = {
        { type = types.variant, attributes = { out = true, retval = true }, name = "param" },
      }
    },
    {
      name = "put_Gg",
      parameters = {
        { type = types.variant, attributes = { ["in"] = true }, name = "param" },
      }
    },
    {
      name = "get_Gg",
      parameters = {
        { type = types.variant, attributes = { out = true, retval = true }, name = "param" },
      }
    },
    {
      name = "put_C",
      parameters = {
        { type = types.variant, attributes = { ["in"] = true }, name = "param" },
      }
    },
    {
      name = "get_C",
      parameters = {
        { type = types.variant, attributes = { out = true, retval = true }, name = "param" },
      }
    },
    {
      name = "put_D",
      parameters = {
        { type = types.variant, attributes = { ["in"] = true }, name = "param" },
      }
    },
    {
      name = "get_D",
      parameters = {
        { type = types.variant, attributes = { out = true, retval = true }, name = "param" },
      }
    },
    {
      name = "put_u0_in1",
      parameters = {
        { type = types.variant, attributes = { ["in"] = true }, name = "param" },
      }
    },
    {
      name = "get_u0_in1",
      parameters = {
        { type = types.variant, attributes = { out = true, retval = true }, name = "param" },
      }
    },
    {
      name = "put_xk_1_in1",
      parameters = {
        { type = types.variant, attributes = { ["in"] = true }, name = "param" },
      }
    },
    {
      name = "get_xk_1_in1",
      parameters = {
        { type = types.variant, attributes = { out = true, retval = true }, name = "param" },
      }
    },
    {
      name = "put_Fo_in1",
      parameters = {
        { type = types.variant, attributes = { ["in"] = true }, name = "param" },
      }
    },
    {
      name = "get_Fo_in1",
      parameters = {
        { type = types.variant, attributes = { out = true, retval = true }, name = "param" },
      }
    },
    {
      name = "put_ParametrosForaDaFaixa_in1",
      parameters = {
        { type = types.variant, attributes = { ["in"] = true }, name = "param" },
      }
    },
    {
      name = "get_ParametrosForaDaFaixa_in1",
      parameters = {
        { type = types.variant, attributes = { out = true, retval = true }, name = "param" },
      }
    },
    {
      name = "put_h_atual",
      parameters = {
        { type = types.variant, attributes = { ["in"] = true }, name = "param" },
      }
    },
    {
      name = "get_h_atual",
      parameters = {
        { type = types.variant, attributes = { out = true, retval = true }, name = "param" },
      }
    },
    {
      name = "put_h_passado_in1",
      parameters = {
        { type = types.variant, attributes = { ["in"] = true }, name = "param" },
      }
    },
    {
      name = "get_h_passado_in1",
      parameters = {
        { type = types.variant, attributes = { out = true, retval = true }, name = "param" },
      }
    },
    {
      name = "put_Pvaso",
      parameters = {
        { type = types.variant, attributes = { ["in"] = true }, name = "param" },
      }
    },
    {
      name = "get_Pvaso",
      parameters = {
        { type = types.variant, attributes = { out = true, retval = true }, name = "param" },
      }
    },
    {
      name = "put_Pjus",
      parameters = {
        { type = types.variant, attributes = { ["in"] = true }, name = "param" },
      }
    },
    {
      name = "get_Pjus",
      parameters = {
        { type = types.variant, attributes = { out = true, retval = true }, name = "param" },
      }
    },
  }
}


local mpc = {
  modname = "mpclib",
  header = "MPC_Bifasico_dll_idl",
  interfaces = { IDispatch, IClass1 },
  wrappers = {},
  enums = {}
}

local source, def, wrap = generator.compile(mpc)

generator.writefile("mpclib.cpp", source)
generator.writefile("mpclib.def", def)
