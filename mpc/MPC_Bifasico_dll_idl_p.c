

/* this ALWAYS GENERATED file contains the proxy stub code */


 /* File created by MIDL compiler version 7.00.0500 */
/* at Wed Aug 01 09:46:27 2012
 */
/* Compiler settings for D:\Documents and Settings\phtf\Desktop\Grupo de Controle\Projetos Especificos\Controle por bandas e MPC\MPC_Bifasico_dll\src\MPC_Bifasico_dll_idl.idl:
    Oicf, W1, Zp8, env=Win32 (32b run)
    protocol : dce , ms_ext, c_ext, robust
    error checks: allocation ref bounds_check enum stub_data 
    VC __declspec() decoration level: 
         __declspec(uuid()), __declspec(selectany), __declspec(novtable)
         DECLSPEC_UUID(), MIDL_INTERFACE()
*/
//@@MIDL_FILE_HEADING(  )

#if !defined(_M_IA64) && !defined(_M_AMD64)


#pragma warning( disable: 4049 )  /* more than 64k source lines */
#if _MSC_VER >= 1200
#pragma warning(push)
#endif

#pragma warning( disable: 4211 )  /* redefine extern to static */
#pragma warning( disable: 4232 )  /* dllimport identity*/
#pragma warning( disable: 4024 )  /* array to pointer mapping*/
#pragma warning( disable: 4152 )  /* function/data pointer conversion in expression */
#pragma warning( disable: 4100 ) /* unreferenced arguments in x86 call */

#pragma optimize("", off ) 

#define USE_STUBLESS_PROXY


/* verify that the <rpcproxy.h> version is high enough to compile this file*/
#ifndef __REDQ_RPCPROXY_H_VERSION__
#define __REQUIRED_RPCPROXY_H_VERSION__ 475
#endif


#include "rpcproxy.h"
#ifndef __RPCPROXY_H_VERSION__
#error this stub requires an updated version of <rpcproxy.h>
#endif // __RPCPROXY_H_VERSION__


#include "MPC_Bifasico_dll_idl.h"

#define TYPE_FORMAT_STRING_SIZE   1079                              
#define PROC_FORMAT_STRING_SIZE   3337                              
#define EXPR_FORMAT_STRING_SIZE   1                                 
#define TRANSMIT_AS_TABLE_SIZE    0            
#define WIRE_MARSHAL_TABLE_SIZE   1            

typedef struct _MPC_Bifasico_dll_idl_MIDL_TYPE_FORMAT_STRING
    {
    short          Pad;
    unsigned char  Format[ TYPE_FORMAT_STRING_SIZE ];
    } MPC_Bifasico_dll_idl_MIDL_TYPE_FORMAT_STRING;

typedef struct _MPC_Bifasico_dll_idl_MIDL_PROC_FORMAT_STRING
    {
    short          Pad;
    unsigned char  Format[ PROC_FORMAT_STRING_SIZE ];
    } MPC_Bifasico_dll_idl_MIDL_PROC_FORMAT_STRING;

typedef struct _MPC_Bifasico_dll_idl_MIDL_EXPR_FORMAT_STRING
    {
    long          Pad;
    unsigned char  Format[ EXPR_FORMAT_STRING_SIZE ];
    } MPC_Bifasico_dll_idl_MIDL_EXPR_FORMAT_STRING;


static RPC_SYNTAX_IDENTIFIER  _RpcTransferSyntax = 
{{0x8A885D04,0x1CEB,0x11C9,{0x9F,0xE8,0x08,0x00,0x2B,0x10,0x48,0x60}},{2,0}};


extern const MPC_Bifasico_dll_idl_MIDL_TYPE_FORMAT_STRING MPC_Bifasico_dll_idl__MIDL_TypeFormatString;
extern const MPC_Bifasico_dll_idl_MIDL_PROC_FORMAT_STRING MPC_Bifasico_dll_idl__MIDL_ProcFormatString;
extern const MPC_Bifasico_dll_idl_MIDL_EXPR_FORMAT_STRING MPC_Bifasico_dll_idl__MIDL_ExprFormatString;


extern const MIDL_STUB_DESC Object_StubDesc;


extern const MIDL_SERVER_INFO IClass1_ServerInfo;
extern const MIDL_STUBLESS_PROXY_INFO IClass1_ProxyInfo;


extern const USER_MARSHAL_ROUTINE_QUADRUPLE UserMarshalRoutines[ WIRE_MARSHAL_TABLE_SIZE ];

#if !defined(__RPC_WIN32__)
#error  Invalid build platform for this stub.
#endif

#if !(TARGET_IS_NT50_OR_LATER)
#error You need a Windows 2000 or later to run this stub because it uses these features:
#error   /robust command line switch.
#error However, your C/C++ compilation flags indicate you intend to run this app on earlier systems.
#error This app will fail with the RPC_X_WRONG_STUB_VERSION error.
#endif


static const MPC_Bifasico_dll_idl_MIDL_PROC_FORMAT_STRING MPC_Bifasico_dll_idl__MIDL_ProcFormatString =
    {
        0,
        {

	/* Procedure get_MWFlags */

			0x33,		/* FC_AUTO_HANDLE */
			0x6c,		/* Old Flags:  object, Oi2 */
/*  2 */	NdrFcLong( 0x0 ),	/* 0 */
/*  6 */	NdrFcShort( 0x7 ),	/* 7 */
/*  8 */	NdrFcShort( 0xc ),	/* x86 Stack size/offset = 12 */
/* 10 */	NdrFcShort( 0x0 ),	/* 0 */
/* 12 */	NdrFcShort( 0x8 ),	/* 8 */
/* 14 */	0x45,		/* Oi2 Flags:  srv must size, has return, has ext, */
			0x2,		/* 2 */
/* 16 */	0x8,		/* 8 */
			0x1,		/* Ext Flags:  new corr desc, */
/* 18 */	NdrFcShort( 0x0 ),	/* 0 */
/* 20 */	NdrFcShort( 0x0 ),	/* 0 */
/* 22 */	NdrFcShort( 0x0 ),	/* 0 */

	/* Parameter ppvFlags */

/* 24 */	NdrFcShort( 0x13 ),	/* Flags:  must size, must free, out, */
/* 26 */	NdrFcShort( 0x4 ),	/* x86 Stack size/offset = 4 */
/* 28 */	NdrFcShort( 0x2 ),	/* Type Offset=2 */

	/* Return value */

/* 30 */	NdrFcShort( 0x70 ),	/* Flags:  out, return, base type, */
/* 32 */	NdrFcShort( 0x8 ),	/* x86 Stack size/offset = 8 */
/* 34 */	0x8,		/* FC_LONG */
			0x0,		/* 0 */

	/* Procedure put_MWFlags */

/* 36 */	0x33,		/* FC_AUTO_HANDLE */
			0x6c,		/* Old Flags:  object, Oi2 */
/* 38 */	NdrFcLong( 0x0 ),	/* 0 */
/* 42 */	NdrFcShort( 0x8 ),	/* 8 */
/* 44 */	NdrFcShort( 0xc ),	/* x86 Stack size/offset = 12 */
/* 46 */	NdrFcShort( 0x0 ),	/* 0 */
/* 48 */	NdrFcShort( 0x8 ),	/* 8 */
/* 50 */	0x46,		/* Oi2 Flags:  clt must size, has return, has ext, */
			0x2,		/* 2 */
/* 52 */	0x8,		/* 8 */
			0x1,		/* Ext Flags:  new corr desc, */
/* 54 */	NdrFcShort( 0x0 ),	/* 0 */
/* 56 */	NdrFcShort( 0x0 ),	/* 0 */
/* 58 */	NdrFcShort( 0x0 ),	/* 0 */

	/* Parameter pvFlags */

/* 60 */	NdrFcShort( 0xb ),	/* Flags:  must size, must free, in, */
/* 62 */	NdrFcShort( 0x4 ),	/* x86 Stack size/offset = 4 */
/* 64 */	NdrFcShort( 0x6 ),	/* Type Offset=6 */

	/* Return value */

/* 66 */	NdrFcShort( 0x70 ),	/* Flags:  out, return, base type, */
/* 68 */	NdrFcShort( 0x8 ),	/* x86 Stack size/offset = 8 */
/* 70 */	0x8,		/* FC_LONG */
			0x0,		/* 0 */

	/* Procedure MPC_Bifasico_dll */

/* 72 */	0x33,		/* FC_AUTO_HANDLE */
			0x6c,		/* Old Flags:  object, Oi2 */
/* 74 */	NdrFcLong( 0x0 ),	/* 0 */
/* 78 */	NdrFcShort( 0x9 ),	/* 9 */
/* 80 */	NdrFcShort( 0x230 ),	/* x86 Stack size/offset = 560 */
/* 82 */	NdrFcShort( 0x8 ),	/* 8 */
/* 84 */	NdrFcShort( 0x8 ),	/* 8 */
/* 86 */	0x47,		/* Oi2 Flags:  srv must size, clt must size, has return, has ext, */
			0x2b,		/* 43 */
/* 88 */	0x8,		/* 8 */
			0x7,		/* Ext Flags:  new corr desc, clt corr check, srv corr check, */
/* 90 */	NdrFcShort( 0xbd7 ),	/* 3031 */
/* 92 */	NdrFcShort( 0x4dd0 ),	/* 19920 */
/* 94 */	NdrFcShort( 0x0 ),	/* 0 */

	/* Parameter nargout */

/* 96 */	NdrFcShort( 0x48 ),	/* Flags:  in, base type, */
/* 98 */	NdrFcShort( 0x4 ),	/* x86 Stack size/offset = 4 */
/* 100 */	0x8,		/* FC_LONG */
			0x0,		/* 0 */

	/* Parameter Kph */

/* 102 */	NdrFcShort( 0x11b ),	/* Flags:  must size, must free, in, out, simple ref, */
/* 104 */	NdrFcShort( 0x8 ),	/* x86 Stack size/offset = 8 */
/* 106 */	NdrFcShort( 0x41a ),	/* Type Offset=1050 */

	/* Parameter SPh */

/* 108 */	NdrFcShort( 0x11b ),	/* Flags:  must size, must free, in, out, simple ref, */
/* 110 */	NdrFcShort( 0xc ),	/* x86 Stack size/offset = 12 */
/* 112 */	NdrFcShort( 0x41a ),	/* Type Offset=1050 */

	/* Parameter exitFlag */

/* 114 */	NdrFcShort( 0x11b ),	/* Flags:  must size, must free, in, out, simple ref, */
/* 116 */	NdrFcShort( 0x10 ),	/* x86 Stack size/offset = 16 */
/* 118 */	NdrFcShort( 0x41a ),	/* Type Offset=1050 */

	/* Parameter u0 */

/* 120 */	NdrFcShort( 0x11b ),	/* Flags:  must size, must free, in, out, simple ref, */
/* 122 */	NdrFcShort( 0x14 ),	/* x86 Stack size/offset = 20 */
/* 124 */	NdrFcShort( 0x41a ),	/* Type Offset=1050 */

	/* Parameter xk_1 */

/* 126 */	NdrFcShort( 0x11b ),	/* Flags:  must size, must free, in, out, simple ref, */
/* 128 */	NdrFcShort( 0x18 ),	/* x86 Stack size/offset = 24 */
/* 130 */	NdrFcShort( 0x41a ),	/* Type Offset=1050 */

	/* Parameter Fo */

/* 132 */	NdrFcShort( 0x11b ),	/* Flags:  must size, must free, in, out, simple ref, */
/* 134 */	NdrFcShort( 0x1c ),	/* x86 Stack size/offset = 28 */
/* 136 */	NdrFcShort( 0x41a ),	/* Type Offset=1050 */

	/* Parameter x0 */

/* 138 */	NdrFcShort( 0x11b ),	/* Flags:  must size, must free, in, out, simple ref, */
/* 140 */	NdrFcShort( 0x20 ),	/* x86 Stack size/offset = 32 */
/* 142 */	NdrFcShort( 0x41a ),	/* Type Offset=1050 */

	/* Parameter ParametrosForaDaFaixa */

/* 144 */	NdrFcShort( 0x11b ),	/* Flags:  must size, must free, in, out, simple ref, */
/* 146 */	NdrFcShort( 0x24 ),	/* x86 Stack size/offset = 36 */
/* 148 */	NdrFcShort( 0x41a ),	/* Type Offset=1050 */

	/* Parameter h_passado */

/* 150 */	NdrFcShort( 0x11b ),	/* Flags:  must size, must free, in, out, simple ref, */
/* 152 */	NdrFcShort( 0x28 ),	/* x86 Stack size/offset = 40 */
/* 154 */	NdrFcShort( 0x41a ),	/* Type Offset=1050 */

	/* Parameter TAmost */

/* 156 */	NdrFcShort( 0x8b ),	/* Flags:  must size, must free, in, by val, */
/* 158 */	NdrFcShort( 0x2c ),	/* x86 Stack size/offset = 44 */
/* 160 */	NdrFcShort( 0x428 ),	/* Type Offset=1064 */

	/* Parameter Pfwd */

/* 162 */	NdrFcShort( 0x8b ),	/* Flags:  must size, must free, in, by val, */
/* 164 */	NdrFcShort( 0x3c ),	/* x86 Stack size/offset = 60 */
/* 166 */	NdrFcShort( 0x428 ),	/* Type Offset=1064 */

	/* Parameter PCfwd */

/* 168 */	NdrFcShort( 0x8b ),	/* Flags:  must size, must free, in, by val, */
/* 170 */	NdrFcShort( 0x4c ),	/* x86 Stack size/offset = 76 */
/* 172 */	NdrFcShort( 0x428 ),	/* Type Offset=1064 */

	/* Parameter nu */

/* 174 */	NdrFcShort( 0x8b ),	/* Flags:  must size, must free, in, by val, */
/* 176 */	NdrFcShort( 0x5c ),	/* x86 Stack size/offset = 92 */
/* 178 */	NdrFcShort( 0x428 ),	/* Type Offset=1064 */

	/* Parameter np */

/* 180 */	NdrFcShort( 0x8b ),	/* Flags:  must size, must free, in, by val, */
/* 182 */	NdrFcShort( 0x6c ),	/* x86 Stack size/offset = 108 */
/* 184 */	NdrFcShort( 0x428 ),	/* Type Offset=1064 */

	/* Parameter ny */

/* 186 */	NdrFcShort( 0x8b ),	/* Flags:  must size, must free, in, by val, */
/* 188 */	NdrFcShort( 0x7c ),	/* x86 Stack size/offset = 124 */
/* 190 */	NdrFcShort( 0x428 ),	/* Type Offset=1064 */

	/* Parameter q */

/* 192 */	NdrFcShort( 0x8b ),	/* Flags:  must size, must free, in, by val, */
/* 194 */	NdrFcShort( 0x8c ),	/* x86 Stack size/offset = 140 */
/* 196 */	NdrFcShort( 0x428 ),	/* Type Offset=1064 */

	/* Parameter r */

/* 198 */	NdrFcShort( 0x8b ),	/* Flags:  must size, must free, in, by val, */
/* 200 */	NdrFcShort( 0x9c ),	/* x86 Stack size/offset = 156 */
/* 202 */	NdrFcShort( 0x428 ),	/* Type Offset=1064 */

	/* Parameter ys */

/* 204 */	NdrFcShort( 0x8b ),	/* Flags:  must size, must free, in, by val, */
/* 206 */	NdrFcShort( 0xac ),	/* x86 Stack size/offset = 172 */
/* 208 */	NdrFcShort( 0x428 ),	/* Type Offset=1064 */

	/* Parameter yspmax */

/* 210 */	NdrFcShort( 0x8b ),	/* Flags:  must size, must free, in, by val, */
/* 212 */	NdrFcShort( 0xbc ),	/* x86 Stack size/offset = 188 */
/* 214 */	NdrFcShort( 0x428 ),	/* Type Offset=1064 */

	/* Parameter yspmin */

/* 216 */	NdrFcShort( 0x8b ),	/* Flags:  must size, must free, in, by val, */
/* 218 */	NdrFcShort( 0xcc ),	/* x86 Stack size/offset = 204 */
/* 220 */	NdrFcShort( 0x428 ),	/* Type Offset=1064 */

	/* Parameter umax */

/* 222 */	NdrFcShort( 0x8b ),	/* Flags:  must size, must free, in, by val, */
/* 224 */	NdrFcShort( 0xdc ),	/* x86 Stack size/offset = 220 */
/* 226 */	NdrFcShort( 0x428 ),	/* Type Offset=1064 */

	/* Parameter umin */

/* 228 */	NdrFcShort( 0x8b ),	/* Flags:  must size, must free, in, by val, */
/* 230 */	NdrFcShort( 0xec ),	/* x86 Stack size/offset = 236 */
/* 232 */	NdrFcShort( 0x428 ),	/* Type Offset=1064 */

	/* Parameter dumax */

/* 234 */	NdrFcShort( 0x8b ),	/* Flags:  must size, must free, in, by val, */
/* 236 */	NdrFcShort( 0xfc ),	/* x86 Stack size/offset = 252 */
/* 238 */	NdrFcShort( 0x428 ),	/* Type Offset=1064 */

	/* Parameter LTRange_h */

/* 240 */	NdrFcShort( 0x8b ),	/* Flags:  must size, must free, in, by val, */
/* 242 */	NdrFcShort( 0x10c ),	/* x86 Stack size/offset = 268 */
/* 244 */	NdrFcShort( 0x428 ),	/* Type Offset=1064 */

	/* Parameter Bias_h */

/* 246 */	NdrFcShort( 0x8b ),	/* Flags:  must size, must free, in, by val, */
/* 248 */	NdrFcShort( 0x11c ),	/* x86 Stack size/offset = 284 */
/* 250 */	NdrFcShort( 0x428 ),	/* Type Offset=1064 */

	/* Parameter CV */

/* 252 */	NdrFcShort( 0x8b ),	/* Flags:  must size, must free, in, by val, */
/* 254 */	NdrFcShort( 0x12c ),	/* x86 Stack size/offset = 300 */
/* 256 */	NdrFcShort( 0x428 ),	/* Type Offset=1064 */

	/* Parameter gamaw */

/* 258 */	NdrFcShort( 0x8b ),	/* Flags:  must size, must free, in, by val, */
/* 260 */	NdrFcShort( 0x13c ),	/* x86 Stack size/offset = 316 */
/* 262 */	NdrFcShort( 0x428 ),	/* Type Offset=1064 */

	/* Parameter gamal */

/* 264 */	NdrFcShort( 0x8b ),	/* Flags:  must size, must free, in, by val, */
/* 266 */	NdrFcShort( 0x14c ),	/* x86 Stack size/offset = 332 */
/* 268 */	NdrFcShort( 0x428 ),	/* Type Offset=1064 */

	/* Parameter Gw */

/* 270 */	NdrFcShort( 0x8b ),	/* Flags:  must size, must free, in, by val, */
/* 272 */	NdrFcShort( 0x15c ),	/* x86 Stack size/offset = 348 */
/* 274 */	NdrFcShort( 0x428 ),	/* Type Offset=1064 */

	/* Parameter Gl */

/* 276 */	NdrFcShort( 0x8b ),	/* Flags:  must size, must free, in, by val, */
/* 278 */	NdrFcShort( 0x16c ),	/* x86 Stack size/offset = 364 */
/* 280 */	NdrFcShort( 0x428 ),	/* Type Offset=1064 */

	/* Parameter Gg */

/* 282 */	NdrFcShort( 0x8b ),	/* Flags:  must size, must free, in, by val, */
/* 284 */	NdrFcShort( 0x17c ),	/* x86 Stack size/offset = 380 */
/* 286 */	NdrFcShort( 0x428 ),	/* Type Offset=1064 */

	/* Parameter C */

/* 288 */	NdrFcShort( 0x8b ),	/* Flags:  must size, must free, in, by val, */
/* 290 */	NdrFcShort( 0x18c ),	/* x86 Stack size/offset = 396 */
/* 292 */	NdrFcShort( 0x428 ),	/* Type Offset=1064 */

	/* Parameter D */

/* 294 */	NdrFcShort( 0x8b ),	/* Flags:  must size, must free, in, by val, */
/* 296 */	NdrFcShort( 0x19c ),	/* x86 Stack size/offset = 412 */
/* 298 */	NdrFcShort( 0x428 ),	/* Type Offset=1064 */

	/* Parameter u0_in1 */

/* 300 */	NdrFcShort( 0x8b ),	/* Flags:  must size, must free, in, by val, */
/* 302 */	NdrFcShort( 0x1ac ),	/* x86 Stack size/offset = 428 */
/* 304 */	NdrFcShort( 0x428 ),	/* Type Offset=1064 */

	/* Parameter xk_1_in1 */

/* 306 */	NdrFcShort( 0x8b ),	/* Flags:  must size, must free, in, by val, */
/* 308 */	NdrFcShort( 0x1bc ),	/* x86 Stack size/offset = 444 */
/* 310 */	NdrFcShort( 0x428 ),	/* Type Offset=1064 */

	/* Parameter Fo_in1 */

/* 312 */	NdrFcShort( 0x8b ),	/* Flags:  must size, must free, in, by val, */
/* 314 */	NdrFcShort( 0x1cc ),	/* x86 Stack size/offset = 460 */
/* 316 */	NdrFcShort( 0x428 ),	/* Type Offset=1064 */

	/* Parameter ParametrosForaDaFaixa_in1 */

/* 318 */	NdrFcShort( 0x8b ),	/* Flags:  must size, must free, in, by val, */
/* 320 */	NdrFcShort( 0x1dc ),	/* x86 Stack size/offset = 476 */
/* 322 */	NdrFcShort( 0x428 ),	/* Type Offset=1064 */

	/* Parameter h_atual */

/* 324 */	NdrFcShort( 0x8b ),	/* Flags:  must size, must free, in, by val, */
/* 326 */	NdrFcShort( 0x1ec ),	/* x86 Stack size/offset = 492 */
/* 328 */	NdrFcShort( 0x428 ),	/* Type Offset=1064 */

	/* Parameter h_passado_in1 */

/* 330 */	NdrFcShort( 0x8b ),	/* Flags:  must size, must free, in, by val, */
/* 332 */	NdrFcShort( 0x1fc ),	/* x86 Stack size/offset = 508 */
/* 334 */	NdrFcShort( 0x428 ),	/* Type Offset=1064 */

	/* Parameter Pvaso */

/* 336 */	NdrFcShort( 0x8b ),	/* Flags:  must size, must free, in, by val, */
/* 338 */	NdrFcShort( 0x20c ),	/* x86 Stack size/offset = 524 */
/* 340 */	NdrFcShort( 0x428 ),	/* Type Offset=1064 */

	/* Parameter Pjus */

/* 342 */	NdrFcShort( 0x8b ),	/* Flags:  must size, must free, in, by val, */
/* 344 */	NdrFcShort( 0x21c ),	/* x86 Stack size/offset = 540 */
/* 346 */	NdrFcShort( 0x428 ),	/* Type Offset=1064 */

	/* Return value */

/* 348 */	NdrFcShort( 0x70 ),	/* Flags:  out, return, base type, */
/* 350 */	NdrFcShort( 0x22c ),	/* x86 Stack size/offset = 556 */
/* 352 */	0x8,		/* FC_LONG */
			0x0,		/* 0 */

	/* Procedure MCRWaitForFigures */

/* 354 */	0x33,		/* FC_AUTO_HANDLE */
			0x6c,		/* Old Flags:  object, Oi2 */
/* 356 */	NdrFcLong( 0x0 ),	/* 0 */
/* 360 */	NdrFcShort( 0xa ),	/* 10 */
/* 362 */	NdrFcShort( 0x8 ),	/* x86 Stack size/offset = 8 */
/* 364 */	NdrFcShort( 0x0 ),	/* 0 */
/* 366 */	NdrFcShort( 0x8 ),	/* 8 */
/* 368 */	0x44,		/* Oi2 Flags:  has return, has ext, */
			0x1,		/* 1 */
/* 370 */	0x8,		/* 8 */
			0x1,		/* Ext Flags:  new corr desc, */
/* 372 */	NdrFcShort( 0x0 ),	/* 0 */
/* 374 */	NdrFcShort( 0x0 ),	/* 0 */
/* 376 */	NdrFcShort( 0x0 ),	/* 0 */

	/* Return value */

/* 378 */	NdrFcShort( 0x70 ),	/* Flags:  out, return, base type, */
/* 380 */	NdrFcShort( 0x4 ),	/* x86 Stack size/offset = 4 */
/* 382 */	0x8,		/* FC_LONG */
			0x0,		/* 0 */

	/* Procedure get_Kph */

/* 384 */	0x33,		/* FC_AUTO_HANDLE */
			0x6c,		/* Old Flags:  object, Oi2 */
/* 386 */	NdrFcLong( 0x0 ),	/* 0 */
/* 390 */	NdrFcShort( 0xb ),	/* 11 */
/* 392 */	NdrFcShort( 0xc ),	/* x86 Stack size/offset = 12 */
/* 394 */	NdrFcShort( 0x0 ),	/* 0 */
/* 396 */	NdrFcShort( 0x8 ),	/* 8 */
/* 398 */	0x45,		/* Oi2 Flags:  srv must size, has return, has ext, */
			0x2,		/* 2 */
/* 400 */	0x8,		/* 8 */
			0x3,		/* Ext Flags:  new corr desc, clt corr check, */
/* 402 */	NdrFcShort( 0xca ),	/* 202 */
/* 404 */	NdrFcShort( 0x0 ),	/* 0 */
/* 406 */	NdrFcShort( 0x0 ),	/* 0 */

	/* Parameter Kph */

/* 408 */	NdrFcShort( 0x4113 ),	/* Flags:  must size, must free, out, simple ref, srv alloc size=16 */
/* 410 */	NdrFcShort( 0x4 ),	/* x86 Stack size/offset = 4 */
/* 412 */	NdrFcShort( 0x41a ),	/* Type Offset=1050 */

	/* Return value */

/* 414 */	NdrFcShort( 0x70 ),	/* Flags:  out, return, base type, */
/* 416 */	NdrFcShort( 0x8 ),	/* x86 Stack size/offset = 8 */
/* 418 */	0x8,		/* FC_LONG */
			0x0,		/* 0 */

	/* Procedure put_Kph */

/* 420 */	0x33,		/* FC_AUTO_HANDLE */
			0x6c,		/* Old Flags:  object, Oi2 */
/* 422 */	NdrFcLong( 0x0 ),	/* 0 */
/* 426 */	NdrFcShort( 0xc ),	/* 12 */
/* 428 */	NdrFcShort( 0x18 ),	/* x86 Stack size/offset = 24 */
/* 430 */	NdrFcShort( 0x0 ),	/* 0 */
/* 432 */	NdrFcShort( 0x8 ),	/* 8 */
/* 434 */	0x46,		/* Oi2 Flags:  clt must size, has return, has ext, */
			0x2,		/* 2 */
/* 436 */	0x8,		/* 8 */
			0x5,		/* Ext Flags:  new corr desc, srv corr check, */
/* 438 */	NdrFcShort( 0x0 ),	/* 0 */
/* 440 */	NdrFcShort( 0xe1 ),	/* 225 */
/* 442 */	NdrFcShort( 0x0 ),	/* 0 */

	/* Parameter Kph */

/* 444 */	NdrFcShort( 0x8b ),	/* Flags:  must size, must free, in, by val, */
/* 446 */	NdrFcShort( 0x4 ),	/* x86 Stack size/offset = 4 */
/* 448 */	NdrFcShort( 0x428 ),	/* Type Offset=1064 */

	/* Return value */

/* 450 */	NdrFcShort( 0x70 ),	/* Flags:  out, return, base type, */
/* 452 */	NdrFcShort( 0x14 ),	/* x86 Stack size/offset = 20 */
/* 454 */	0x8,		/* FC_LONG */
			0x0,		/* 0 */

	/* Procedure get_SPh */

/* 456 */	0x33,		/* FC_AUTO_HANDLE */
			0x6c,		/* Old Flags:  object, Oi2 */
/* 458 */	NdrFcLong( 0x0 ),	/* 0 */
/* 462 */	NdrFcShort( 0xd ),	/* 13 */
/* 464 */	NdrFcShort( 0xc ),	/* x86 Stack size/offset = 12 */
/* 466 */	NdrFcShort( 0x0 ),	/* 0 */
/* 468 */	NdrFcShort( 0x8 ),	/* 8 */
/* 470 */	0x45,		/* Oi2 Flags:  srv must size, has return, has ext, */
			0x2,		/* 2 */
/* 472 */	0x8,		/* 8 */
			0x3,		/* Ext Flags:  new corr desc, clt corr check, */
/* 474 */	NdrFcShort( 0xf9 ),	/* 249 */
/* 476 */	NdrFcShort( 0x0 ),	/* 0 */
/* 478 */	NdrFcShort( 0x0 ),	/* 0 */

	/* Parameter SPh */

/* 480 */	NdrFcShort( 0x4113 ),	/* Flags:  must size, must free, out, simple ref, srv alloc size=16 */
/* 482 */	NdrFcShort( 0x4 ),	/* x86 Stack size/offset = 4 */
/* 484 */	NdrFcShort( 0x41a ),	/* Type Offset=1050 */

	/* Return value */

/* 486 */	NdrFcShort( 0x70 ),	/* Flags:  out, return, base type, */
/* 488 */	NdrFcShort( 0x8 ),	/* x86 Stack size/offset = 8 */
/* 490 */	0x8,		/* FC_LONG */
			0x0,		/* 0 */

	/* Procedure put_SPh */

/* 492 */	0x33,		/* FC_AUTO_HANDLE */
			0x6c,		/* Old Flags:  object, Oi2 */
/* 494 */	NdrFcLong( 0x0 ),	/* 0 */
/* 498 */	NdrFcShort( 0xe ),	/* 14 */
/* 500 */	NdrFcShort( 0x18 ),	/* x86 Stack size/offset = 24 */
/* 502 */	NdrFcShort( 0x0 ),	/* 0 */
/* 504 */	NdrFcShort( 0x8 ),	/* 8 */
/* 506 */	0x46,		/* Oi2 Flags:  clt must size, has return, has ext, */
			0x2,		/* 2 */
/* 508 */	0x8,		/* 8 */
			0x5,		/* Ext Flags:  new corr desc, srv corr check, */
/* 510 */	NdrFcShort( 0x0 ),	/* 0 */
/* 512 */	NdrFcShort( 0x112 ),	/* 274 */
/* 514 */	NdrFcShort( 0x0 ),	/* 0 */

	/* Parameter SPh */

/* 516 */	NdrFcShort( 0x8b ),	/* Flags:  must size, must free, in, by val, */
/* 518 */	NdrFcShort( 0x4 ),	/* x86 Stack size/offset = 4 */
/* 520 */	NdrFcShort( 0x428 ),	/* Type Offset=1064 */

	/* Return value */

/* 522 */	NdrFcShort( 0x70 ),	/* Flags:  out, return, base type, */
/* 524 */	NdrFcShort( 0x14 ),	/* x86 Stack size/offset = 20 */
/* 526 */	0x8,		/* FC_LONG */
			0x0,		/* 0 */

	/* Procedure get_exitFlag */

/* 528 */	0x33,		/* FC_AUTO_HANDLE */
			0x6c,		/* Old Flags:  object, Oi2 */
/* 530 */	NdrFcLong( 0x0 ),	/* 0 */
/* 534 */	NdrFcShort( 0xf ),	/* 15 */
/* 536 */	NdrFcShort( 0xc ),	/* x86 Stack size/offset = 12 */
/* 538 */	NdrFcShort( 0x0 ),	/* 0 */
/* 540 */	NdrFcShort( 0x8 ),	/* 8 */
/* 542 */	0x45,		/* Oi2 Flags:  srv must size, has return, has ext, */
			0x2,		/* 2 */
/* 544 */	0x8,		/* 8 */
			0x3,		/* Ext Flags:  new corr desc, clt corr check, */
/* 546 */	NdrFcShort( 0x12c ),	/* 300 */
/* 548 */	NdrFcShort( 0x0 ),	/* 0 */
/* 550 */	NdrFcShort( 0x0 ),	/* 0 */

	/* Parameter exitFlag */

/* 552 */	NdrFcShort( 0x4113 ),	/* Flags:  must size, must free, out, simple ref, srv alloc size=16 */
/* 554 */	NdrFcShort( 0x4 ),	/* x86 Stack size/offset = 4 */
/* 556 */	NdrFcShort( 0x41a ),	/* Type Offset=1050 */

	/* Return value */

/* 558 */	NdrFcShort( 0x70 ),	/* Flags:  out, return, base type, */
/* 560 */	NdrFcShort( 0x8 ),	/* x86 Stack size/offset = 8 */
/* 562 */	0x8,		/* FC_LONG */
			0x0,		/* 0 */

	/* Procedure put_exitFlag */

/* 564 */	0x33,		/* FC_AUTO_HANDLE */
			0x6c,		/* Old Flags:  object, Oi2 */
/* 566 */	NdrFcLong( 0x0 ),	/* 0 */
/* 570 */	NdrFcShort( 0x10 ),	/* 16 */
/* 572 */	NdrFcShort( 0x18 ),	/* x86 Stack size/offset = 24 */
/* 574 */	NdrFcShort( 0x0 ),	/* 0 */
/* 576 */	NdrFcShort( 0x8 ),	/* 8 */
/* 578 */	0x46,		/* Oi2 Flags:  clt must size, has return, has ext, */
			0x2,		/* 2 */
/* 580 */	0x8,		/* 8 */
			0x5,		/* Ext Flags:  new corr desc, srv corr check, */
/* 582 */	NdrFcShort( 0x0 ),	/* 0 */
/* 584 */	NdrFcShort( 0x147 ),	/* 327 */
/* 586 */	NdrFcShort( 0x0 ),	/* 0 */

	/* Parameter exitFlag */

/* 588 */	NdrFcShort( 0x8b ),	/* Flags:  must size, must free, in, by val, */
/* 590 */	NdrFcShort( 0x4 ),	/* x86 Stack size/offset = 4 */
/* 592 */	NdrFcShort( 0x428 ),	/* Type Offset=1064 */

	/* Return value */

/* 594 */	NdrFcShort( 0x70 ),	/* Flags:  out, return, base type, */
/* 596 */	NdrFcShort( 0x14 ),	/* x86 Stack size/offset = 20 */
/* 598 */	0x8,		/* FC_LONG */
			0x0,		/* 0 */

	/* Procedure get_u0 */

/* 600 */	0x33,		/* FC_AUTO_HANDLE */
			0x6c,		/* Old Flags:  object, Oi2 */
/* 602 */	NdrFcLong( 0x0 ),	/* 0 */
/* 606 */	NdrFcShort( 0x11 ),	/* 17 */
/* 608 */	NdrFcShort( 0xc ),	/* x86 Stack size/offset = 12 */
/* 610 */	NdrFcShort( 0x0 ),	/* 0 */
/* 612 */	NdrFcShort( 0x8 ),	/* 8 */
/* 614 */	0x45,		/* Oi2 Flags:  srv must size, has return, has ext, */
			0x2,		/* 2 */
/* 616 */	0x8,		/* 8 */
			0x3,		/* Ext Flags:  new corr desc, clt corr check, */
/* 618 */	NdrFcShort( 0x163 ),	/* 355 */
/* 620 */	NdrFcShort( 0x0 ),	/* 0 */
/* 622 */	NdrFcShort( 0x0 ),	/* 0 */

	/* Parameter u0 */

/* 624 */	NdrFcShort( 0x4113 ),	/* Flags:  must size, must free, out, simple ref, srv alloc size=16 */
/* 626 */	NdrFcShort( 0x4 ),	/* x86 Stack size/offset = 4 */
/* 628 */	NdrFcShort( 0x41a ),	/* Type Offset=1050 */

	/* Return value */

/* 630 */	NdrFcShort( 0x70 ),	/* Flags:  out, return, base type, */
/* 632 */	NdrFcShort( 0x8 ),	/* x86 Stack size/offset = 8 */
/* 634 */	0x8,		/* FC_LONG */
			0x0,		/* 0 */

	/* Procedure put_u0 */

/* 636 */	0x33,		/* FC_AUTO_HANDLE */
			0x6c,		/* Old Flags:  object, Oi2 */
/* 638 */	NdrFcLong( 0x0 ),	/* 0 */
/* 642 */	NdrFcShort( 0x12 ),	/* 18 */
/* 644 */	NdrFcShort( 0x18 ),	/* x86 Stack size/offset = 24 */
/* 646 */	NdrFcShort( 0x0 ),	/* 0 */
/* 648 */	NdrFcShort( 0x8 ),	/* 8 */
/* 650 */	0x46,		/* Oi2 Flags:  clt must size, has return, has ext, */
			0x2,		/* 2 */
/* 652 */	0x8,		/* 8 */
			0x5,		/* Ext Flags:  new corr desc, srv corr check, */
/* 654 */	NdrFcShort( 0x0 ),	/* 0 */
/* 656 */	NdrFcShort( 0x180 ),	/* 384 */
/* 658 */	NdrFcShort( 0x0 ),	/* 0 */

	/* Parameter u0 */

/* 660 */	NdrFcShort( 0x8b ),	/* Flags:  must size, must free, in, by val, */
/* 662 */	NdrFcShort( 0x4 ),	/* x86 Stack size/offset = 4 */
/* 664 */	NdrFcShort( 0x428 ),	/* Type Offset=1064 */

	/* Return value */

/* 666 */	NdrFcShort( 0x70 ),	/* Flags:  out, return, base type, */
/* 668 */	NdrFcShort( 0x14 ),	/* x86 Stack size/offset = 20 */
/* 670 */	0x8,		/* FC_LONG */
			0x0,		/* 0 */

	/* Procedure get_xk_1 */

/* 672 */	0x33,		/* FC_AUTO_HANDLE */
			0x6c,		/* Old Flags:  object, Oi2 */
/* 674 */	NdrFcLong( 0x0 ),	/* 0 */
/* 678 */	NdrFcShort( 0x13 ),	/* 19 */
/* 680 */	NdrFcShort( 0xc ),	/* x86 Stack size/offset = 12 */
/* 682 */	NdrFcShort( 0x0 ),	/* 0 */
/* 684 */	NdrFcShort( 0x8 ),	/* 8 */
/* 686 */	0x45,		/* Oi2 Flags:  srv must size, has return, has ext, */
			0x2,		/* 2 */
/* 688 */	0x8,		/* 8 */
			0x3,		/* Ext Flags:  new corr desc, clt corr check, */
/* 690 */	NdrFcShort( 0x19e ),	/* 414 */
/* 692 */	NdrFcShort( 0x0 ),	/* 0 */
/* 694 */	NdrFcShort( 0x0 ),	/* 0 */

	/* Parameter xk_1 */

/* 696 */	NdrFcShort( 0x4113 ),	/* Flags:  must size, must free, out, simple ref, srv alloc size=16 */
/* 698 */	NdrFcShort( 0x4 ),	/* x86 Stack size/offset = 4 */
/* 700 */	NdrFcShort( 0x41a ),	/* Type Offset=1050 */

	/* Return value */

/* 702 */	NdrFcShort( 0x70 ),	/* Flags:  out, return, base type, */
/* 704 */	NdrFcShort( 0x8 ),	/* x86 Stack size/offset = 8 */
/* 706 */	0x8,		/* FC_LONG */
			0x0,		/* 0 */

	/* Procedure put_xk_1 */

/* 708 */	0x33,		/* FC_AUTO_HANDLE */
			0x6c,		/* Old Flags:  object, Oi2 */
/* 710 */	NdrFcLong( 0x0 ),	/* 0 */
/* 714 */	NdrFcShort( 0x14 ),	/* 20 */
/* 716 */	NdrFcShort( 0x18 ),	/* x86 Stack size/offset = 24 */
/* 718 */	NdrFcShort( 0x0 ),	/* 0 */
/* 720 */	NdrFcShort( 0x8 ),	/* 8 */
/* 722 */	0x46,		/* Oi2 Flags:  clt must size, has return, has ext, */
			0x2,		/* 2 */
/* 724 */	0x8,		/* 8 */
			0x5,		/* Ext Flags:  new corr desc, srv corr check, */
/* 726 */	NdrFcShort( 0x0 ),	/* 0 */
/* 728 */	NdrFcShort( 0x1bd ),	/* 445 */
/* 730 */	NdrFcShort( 0x0 ),	/* 0 */

	/* Parameter xk_1 */

/* 732 */	NdrFcShort( 0x8b ),	/* Flags:  must size, must free, in, by val, */
/* 734 */	NdrFcShort( 0x4 ),	/* x86 Stack size/offset = 4 */
/* 736 */	NdrFcShort( 0x428 ),	/* Type Offset=1064 */

	/* Return value */

/* 738 */	NdrFcShort( 0x70 ),	/* Flags:  out, return, base type, */
/* 740 */	NdrFcShort( 0x14 ),	/* x86 Stack size/offset = 20 */
/* 742 */	0x8,		/* FC_LONG */
			0x0,		/* 0 */

	/* Procedure get_Fo */

/* 744 */	0x33,		/* FC_AUTO_HANDLE */
			0x6c,		/* Old Flags:  object, Oi2 */
/* 746 */	NdrFcLong( 0x0 ),	/* 0 */
/* 750 */	NdrFcShort( 0x15 ),	/* 21 */
/* 752 */	NdrFcShort( 0xc ),	/* x86 Stack size/offset = 12 */
/* 754 */	NdrFcShort( 0x0 ),	/* 0 */
/* 756 */	NdrFcShort( 0x8 ),	/* 8 */
/* 758 */	0x45,		/* Oi2 Flags:  srv must size, has return, has ext, */
			0x2,		/* 2 */
/* 760 */	0x8,		/* 8 */
			0x3,		/* Ext Flags:  new corr desc, clt corr check, */
/* 762 */	NdrFcShort( 0x1dd ),	/* 477 */
/* 764 */	NdrFcShort( 0x0 ),	/* 0 */
/* 766 */	NdrFcShort( 0x0 ),	/* 0 */

	/* Parameter Fo */

/* 768 */	NdrFcShort( 0x4113 ),	/* Flags:  must size, must free, out, simple ref, srv alloc size=16 */
/* 770 */	NdrFcShort( 0x4 ),	/* x86 Stack size/offset = 4 */
/* 772 */	NdrFcShort( 0x41a ),	/* Type Offset=1050 */

	/* Return value */

/* 774 */	NdrFcShort( 0x70 ),	/* Flags:  out, return, base type, */
/* 776 */	NdrFcShort( 0x8 ),	/* x86 Stack size/offset = 8 */
/* 778 */	0x8,		/* FC_LONG */
			0x0,		/* 0 */

	/* Procedure put_Fo */

/* 780 */	0x33,		/* FC_AUTO_HANDLE */
			0x6c,		/* Old Flags:  object, Oi2 */
/* 782 */	NdrFcLong( 0x0 ),	/* 0 */
/* 786 */	NdrFcShort( 0x16 ),	/* 22 */
/* 788 */	NdrFcShort( 0x18 ),	/* x86 Stack size/offset = 24 */
/* 790 */	NdrFcShort( 0x0 ),	/* 0 */
/* 792 */	NdrFcShort( 0x8 ),	/* 8 */
/* 794 */	0x46,		/* Oi2 Flags:  clt must size, has return, has ext, */
			0x2,		/* 2 */
/* 796 */	0x8,		/* 8 */
			0x5,		/* Ext Flags:  new corr desc, srv corr check, */
/* 798 */	NdrFcShort( 0x0 ),	/* 0 */
/* 800 */	NdrFcShort( 0x1fe ),	/* 510 */
/* 802 */	NdrFcShort( 0x0 ),	/* 0 */

	/* Parameter Fo */

/* 804 */	NdrFcShort( 0x8b ),	/* Flags:  must size, must free, in, by val, */
/* 806 */	NdrFcShort( 0x4 ),	/* x86 Stack size/offset = 4 */
/* 808 */	NdrFcShort( 0x428 ),	/* Type Offset=1064 */

	/* Return value */

/* 810 */	NdrFcShort( 0x70 ),	/* Flags:  out, return, base type, */
/* 812 */	NdrFcShort( 0x14 ),	/* x86 Stack size/offset = 20 */
/* 814 */	0x8,		/* FC_LONG */
			0x0,		/* 0 */

	/* Procedure get_x0 */

/* 816 */	0x33,		/* FC_AUTO_HANDLE */
			0x6c,		/* Old Flags:  object, Oi2 */
/* 818 */	NdrFcLong( 0x0 ),	/* 0 */
/* 822 */	NdrFcShort( 0x17 ),	/* 23 */
/* 824 */	NdrFcShort( 0xc ),	/* x86 Stack size/offset = 12 */
/* 826 */	NdrFcShort( 0x0 ),	/* 0 */
/* 828 */	NdrFcShort( 0x8 ),	/* 8 */
/* 830 */	0x45,		/* Oi2 Flags:  srv must size, has return, has ext, */
			0x2,		/* 2 */
/* 832 */	0x8,		/* 8 */
			0x3,		/* Ext Flags:  new corr desc, clt corr check, */
/* 834 */	NdrFcShort( 0x220 ),	/* 544 */
/* 836 */	NdrFcShort( 0x0 ),	/* 0 */
/* 838 */	NdrFcShort( 0x0 ),	/* 0 */

	/* Parameter x0 */

/* 840 */	NdrFcShort( 0x4113 ),	/* Flags:  must size, must free, out, simple ref, srv alloc size=16 */
/* 842 */	NdrFcShort( 0x4 ),	/* x86 Stack size/offset = 4 */
/* 844 */	NdrFcShort( 0x41a ),	/* Type Offset=1050 */

	/* Return value */

/* 846 */	NdrFcShort( 0x70 ),	/* Flags:  out, return, base type, */
/* 848 */	NdrFcShort( 0x8 ),	/* x86 Stack size/offset = 8 */
/* 850 */	0x8,		/* FC_LONG */
			0x0,		/* 0 */

	/* Procedure put_x0 */

/* 852 */	0x33,		/* FC_AUTO_HANDLE */
			0x6c,		/* Old Flags:  object, Oi2 */
/* 854 */	NdrFcLong( 0x0 ),	/* 0 */
/* 858 */	NdrFcShort( 0x18 ),	/* 24 */
/* 860 */	NdrFcShort( 0x18 ),	/* x86 Stack size/offset = 24 */
/* 862 */	NdrFcShort( 0x0 ),	/* 0 */
/* 864 */	NdrFcShort( 0x8 ),	/* 8 */
/* 866 */	0x46,		/* Oi2 Flags:  clt must size, has return, has ext, */
			0x2,		/* 2 */
/* 868 */	0x8,		/* 8 */
			0x5,		/* Ext Flags:  new corr desc, srv corr check, */
/* 870 */	NdrFcShort( 0x0 ),	/* 0 */
/* 872 */	NdrFcShort( 0x243 ),	/* 579 */
/* 874 */	NdrFcShort( 0x0 ),	/* 0 */

	/* Parameter x0 */

/* 876 */	NdrFcShort( 0x8b ),	/* Flags:  must size, must free, in, by val, */
/* 878 */	NdrFcShort( 0x4 ),	/* x86 Stack size/offset = 4 */
/* 880 */	NdrFcShort( 0x428 ),	/* Type Offset=1064 */

	/* Return value */

/* 882 */	NdrFcShort( 0x70 ),	/* Flags:  out, return, base type, */
/* 884 */	NdrFcShort( 0x14 ),	/* x86 Stack size/offset = 20 */
/* 886 */	0x8,		/* FC_LONG */
			0x0,		/* 0 */

	/* Procedure get_ParametrosForaDaFaixa */

/* 888 */	0x33,		/* FC_AUTO_HANDLE */
			0x6c,		/* Old Flags:  object, Oi2 */
/* 890 */	NdrFcLong( 0x0 ),	/* 0 */
/* 894 */	NdrFcShort( 0x19 ),	/* 25 */
/* 896 */	NdrFcShort( 0xc ),	/* x86 Stack size/offset = 12 */
/* 898 */	NdrFcShort( 0x0 ),	/* 0 */
/* 900 */	NdrFcShort( 0x8 ),	/* 8 */
/* 902 */	0x45,		/* Oi2 Flags:  srv must size, has return, has ext, */
			0x2,		/* 2 */
/* 904 */	0x8,		/* 8 */
			0x3,		/* Ext Flags:  new corr desc, clt corr check, */
/* 906 */	NdrFcShort( 0x267 ),	/* 615 */
/* 908 */	NdrFcShort( 0x0 ),	/* 0 */
/* 910 */	NdrFcShort( 0x0 ),	/* 0 */

	/* Parameter ParametrosForaDaFaixa */

/* 912 */	NdrFcShort( 0x4113 ),	/* Flags:  must size, must free, out, simple ref, srv alloc size=16 */
/* 914 */	NdrFcShort( 0x4 ),	/* x86 Stack size/offset = 4 */
/* 916 */	NdrFcShort( 0x41a ),	/* Type Offset=1050 */

	/* Return value */

/* 918 */	NdrFcShort( 0x70 ),	/* Flags:  out, return, base type, */
/* 920 */	NdrFcShort( 0x8 ),	/* x86 Stack size/offset = 8 */
/* 922 */	0x8,		/* FC_LONG */
			0x0,		/* 0 */

	/* Procedure put_ParametrosForaDaFaixa */

/* 924 */	0x33,		/* FC_AUTO_HANDLE */
			0x6c,		/* Old Flags:  object, Oi2 */
/* 926 */	NdrFcLong( 0x0 ),	/* 0 */
/* 930 */	NdrFcShort( 0x1a ),	/* 26 */
/* 932 */	NdrFcShort( 0x18 ),	/* x86 Stack size/offset = 24 */
/* 934 */	NdrFcShort( 0x0 ),	/* 0 */
/* 936 */	NdrFcShort( 0x8 ),	/* 8 */
/* 938 */	0x46,		/* Oi2 Flags:  clt must size, has return, has ext, */
			0x2,		/* 2 */
/* 940 */	0x8,		/* 8 */
			0x5,		/* Ext Flags:  new corr desc, srv corr check, */
/* 942 */	NdrFcShort( 0x0 ),	/* 0 */
/* 944 */	NdrFcShort( 0x28c ),	/* 652 */
/* 946 */	NdrFcShort( 0x0 ),	/* 0 */

	/* Parameter ParametrosForaDaFaixa */

/* 948 */	NdrFcShort( 0x8b ),	/* Flags:  must size, must free, in, by val, */
/* 950 */	NdrFcShort( 0x4 ),	/* x86 Stack size/offset = 4 */
/* 952 */	NdrFcShort( 0x428 ),	/* Type Offset=1064 */

	/* Return value */

/* 954 */	NdrFcShort( 0x70 ),	/* Flags:  out, return, base type, */
/* 956 */	NdrFcShort( 0x14 ),	/* x86 Stack size/offset = 20 */
/* 958 */	0x8,		/* FC_LONG */
			0x0,		/* 0 */

	/* Procedure get_h_passado */

/* 960 */	0x33,		/* FC_AUTO_HANDLE */
			0x6c,		/* Old Flags:  object, Oi2 */
/* 962 */	NdrFcLong( 0x0 ),	/* 0 */
/* 966 */	NdrFcShort( 0x1b ),	/* 27 */
/* 968 */	NdrFcShort( 0xc ),	/* x86 Stack size/offset = 12 */
/* 970 */	NdrFcShort( 0x0 ),	/* 0 */
/* 972 */	NdrFcShort( 0x8 ),	/* 8 */
/* 974 */	0x45,		/* Oi2 Flags:  srv must size, has return, has ext, */
			0x2,		/* 2 */
/* 976 */	0x8,		/* 8 */
			0x3,		/* Ext Flags:  new corr desc, clt corr check, */
/* 978 */	NdrFcShort( 0x2b2 ),	/* 690 */
/* 980 */	NdrFcShort( 0x0 ),	/* 0 */
/* 982 */	NdrFcShort( 0x0 ),	/* 0 */

	/* Parameter h_passado */

/* 984 */	NdrFcShort( 0x4113 ),	/* Flags:  must size, must free, out, simple ref, srv alloc size=16 */
/* 986 */	NdrFcShort( 0x4 ),	/* x86 Stack size/offset = 4 */
/* 988 */	NdrFcShort( 0x41a ),	/* Type Offset=1050 */

	/* Return value */

/* 990 */	NdrFcShort( 0x70 ),	/* Flags:  out, return, base type, */
/* 992 */	NdrFcShort( 0x8 ),	/* x86 Stack size/offset = 8 */
/* 994 */	0x8,		/* FC_LONG */
			0x0,		/* 0 */

	/* Procedure put_h_passado */

/* 996 */	0x33,		/* FC_AUTO_HANDLE */
			0x6c,		/* Old Flags:  object, Oi2 */
/* 998 */	NdrFcLong( 0x0 ),	/* 0 */
/* 1002 */	NdrFcShort( 0x1c ),	/* 28 */
/* 1004 */	NdrFcShort( 0x18 ),	/* x86 Stack size/offset = 24 */
/* 1006 */	NdrFcShort( 0x0 ),	/* 0 */
/* 1008 */	NdrFcShort( 0x8 ),	/* 8 */
/* 1010 */	0x46,		/* Oi2 Flags:  clt must size, has return, has ext, */
			0x2,		/* 2 */
/* 1012 */	0x8,		/* 8 */
			0x5,		/* Ext Flags:  new corr desc, srv corr check, */
/* 1014 */	NdrFcShort( 0x0 ),	/* 0 */
/* 1016 */	NdrFcShort( 0x2d9 ),	/* 729 */
/* 1018 */	NdrFcShort( 0x0 ),	/* 0 */

	/* Parameter h_passado */

/* 1020 */	NdrFcShort( 0x8b ),	/* Flags:  must size, must free, in, by val, */
/* 1022 */	NdrFcShort( 0x4 ),	/* x86 Stack size/offset = 4 */
/* 1024 */	NdrFcShort( 0x428 ),	/* Type Offset=1064 */

	/* Return value */

/* 1026 */	NdrFcShort( 0x70 ),	/* Flags:  out, return, base type, */
/* 1028 */	NdrFcShort( 0x14 ),	/* x86 Stack size/offset = 20 */
/* 1030 */	0x8,		/* FC_LONG */
			0x0,		/* 0 */

	/* Procedure get_TAmost */

/* 1032 */	0x33,		/* FC_AUTO_HANDLE */
			0x6c,		/* Old Flags:  object, Oi2 */
/* 1034 */	NdrFcLong( 0x0 ),	/* 0 */
/* 1038 */	NdrFcShort( 0x1d ),	/* 29 */
/* 1040 */	NdrFcShort( 0xc ),	/* x86 Stack size/offset = 12 */
/* 1042 */	NdrFcShort( 0x0 ),	/* 0 */
/* 1044 */	NdrFcShort( 0x8 ),	/* 8 */
/* 1046 */	0x45,		/* Oi2 Flags:  srv must size, has return, has ext, */
			0x2,		/* 2 */
/* 1048 */	0x8,		/* 8 */
			0x3,		/* Ext Flags:  new corr desc, clt corr check, */
/* 1050 */	NdrFcShort( 0x301 ),	/* 769 */
/* 1052 */	NdrFcShort( 0x0 ),	/* 0 */
/* 1054 */	NdrFcShort( 0x0 ),	/* 0 */

	/* Parameter TAmost */

/* 1056 */	NdrFcShort( 0x4113 ),	/* Flags:  must size, must free, out, simple ref, srv alloc size=16 */
/* 1058 */	NdrFcShort( 0x4 ),	/* x86 Stack size/offset = 4 */
/* 1060 */	NdrFcShort( 0x41a ),	/* Type Offset=1050 */

	/* Return value */

/* 1062 */	NdrFcShort( 0x70 ),	/* Flags:  out, return, base type, */
/* 1064 */	NdrFcShort( 0x8 ),	/* x86 Stack size/offset = 8 */
/* 1066 */	0x8,		/* FC_LONG */
			0x0,		/* 0 */

	/* Procedure put_TAmost */

/* 1068 */	0x33,		/* FC_AUTO_HANDLE */
			0x6c,		/* Old Flags:  object, Oi2 */
/* 1070 */	NdrFcLong( 0x0 ),	/* 0 */
/* 1074 */	NdrFcShort( 0x1e ),	/* 30 */
/* 1076 */	NdrFcShort( 0x18 ),	/* x86 Stack size/offset = 24 */
/* 1078 */	NdrFcShort( 0x0 ),	/* 0 */
/* 1080 */	NdrFcShort( 0x8 ),	/* 8 */
/* 1082 */	0x46,		/* Oi2 Flags:  clt must size, has return, has ext, */
			0x2,		/* 2 */
/* 1084 */	0x8,		/* 8 */
			0x5,		/* Ext Flags:  new corr desc, srv corr check, */
/* 1086 */	NdrFcShort( 0x0 ),	/* 0 */
/* 1088 */	NdrFcShort( 0x32a ),	/* 810 */
/* 1090 */	NdrFcShort( 0x0 ),	/* 0 */

	/* Parameter TAmost */

/* 1092 */	NdrFcShort( 0x8b ),	/* Flags:  must size, must free, in, by val, */
/* 1094 */	NdrFcShort( 0x4 ),	/* x86 Stack size/offset = 4 */
/* 1096 */	NdrFcShort( 0x428 ),	/* Type Offset=1064 */

	/* Return value */

/* 1098 */	NdrFcShort( 0x70 ),	/* Flags:  out, return, base type, */
/* 1100 */	NdrFcShort( 0x14 ),	/* x86 Stack size/offset = 20 */
/* 1102 */	0x8,		/* FC_LONG */
			0x0,		/* 0 */

	/* Procedure get_Pfwd */

/* 1104 */	0x33,		/* FC_AUTO_HANDLE */
			0x6c,		/* Old Flags:  object, Oi2 */
/* 1106 */	NdrFcLong( 0x0 ),	/* 0 */
/* 1110 */	NdrFcShort( 0x1f ),	/* 31 */
/* 1112 */	NdrFcShort( 0xc ),	/* x86 Stack size/offset = 12 */
/* 1114 */	NdrFcShort( 0x0 ),	/* 0 */
/* 1116 */	NdrFcShort( 0x8 ),	/* 8 */
/* 1118 */	0x45,		/* Oi2 Flags:  srv must size, has return, has ext, */
			0x2,		/* 2 */
/* 1120 */	0x8,		/* 8 */
			0x3,		/* Ext Flags:  new corr desc, clt corr check, */
/* 1122 */	NdrFcShort( 0x354 ),	/* 852 */
/* 1124 */	NdrFcShort( 0x0 ),	/* 0 */
/* 1126 */	NdrFcShort( 0x0 ),	/* 0 */

	/* Parameter Pfwd */

/* 1128 */	NdrFcShort( 0x4113 ),	/* Flags:  must size, must free, out, simple ref, srv alloc size=16 */
/* 1130 */	NdrFcShort( 0x4 ),	/* x86 Stack size/offset = 4 */
/* 1132 */	NdrFcShort( 0x41a ),	/* Type Offset=1050 */

	/* Return value */

/* 1134 */	NdrFcShort( 0x70 ),	/* Flags:  out, return, base type, */
/* 1136 */	NdrFcShort( 0x8 ),	/* x86 Stack size/offset = 8 */
/* 1138 */	0x8,		/* FC_LONG */
			0x0,		/* 0 */

	/* Procedure put_Pfwd */

/* 1140 */	0x33,		/* FC_AUTO_HANDLE */
			0x6c,		/* Old Flags:  object, Oi2 */
/* 1142 */	NdrFcLong( 0x0 ),	/* 0 */
/* 1146 */	NdrFcShort( 0x20 ),	/* 32 */
/* 1148 */	NdrFcShort( 0x18 ),	/* x86 Stack size/offset = 24 */
/* 1150 */	NdrFcShort( 0x0 ),	/* 0 */
/* 1152 */	NdrFcShort( 0x8 ),	/* 8 */
/* 1154 */	0x46,		/* Oi2 Flags:  clt must size, has return, has ext, */
			0x2,		/* 2 */
/* 1156 */	0x8,		/* 8 */
			0x5,		/* Ext Flags:  new corr desc, srv corr check, */
/* 1158 */	NdrFcShort( 0x0 ),	/* 0 */
/* 1160 */	NdrFcShort( 0x37f ),	/* 895 */
/* 1162 */	NdrFcShort( 0x0 ),	/* 0 */

	/* Parameter Pfwd */

/* 1164 */	NdrFcShort( 0x8b ),	/* Flags:  must size, must free, in, by val, */
/* 1166 */	NdrFcShort( 0x4 ),	/* x86 Stack size/offset = 4 */
/* 1168 */	NdrFcShort( 0x428 ),	/* Type Offset=1064 */

	/* Return value */

/* 1170 */	NdrFcShort( 0x70 ),	/* Flags:  out, return, base type, */
/* 1172 */	NdrFcShort( 0x14 ),	/* x86 Stack size/offset = 20 */
/* 1174 */	0x8,		/* FC_LONG */
			0x0,		/* 0 */

	/* Procedure get_PCfwd */

/* 1176 */	0x33,		/* FC_AUTO_HANDLE */
			0x6c,		/* Old Flags:  object, Oi2 */
/* 1178 */	NdrFcLong( 0x0 ),	/* 0 */
/* 1182 */	NdrFcShort( 0x21 ),	/* 33 */
/* 1184 */	NdrFcShort( 0xc ),	/* x86 Stack size/offset = 12 */
/* 1186 */	NdrFcShort( 0x0 ),	/* 0 */
/* 1188 */	NdrFcShort( 0x8 ),	/* 8 */
/* 1190 */	0x45,		/* Oi2 Flags:  srv must size, has return, has ext, */
			0x2,		/* 2 */
/* 1192 */	0x8,		/* 8 */
			0x3,		/* Ext Flags:  new corr desc, clt corr check, */
/* 1194 */	NdrFcShort( 0x3ab ),	/* 939 */
/* 1196 */	NdrFcShort( 0x0 ),	/* 0 */
/* 1198 */	NdrFcShort( 0x0 ),	/* 0 */

	/* Parameter PCfwd */

/* 1200 */	NdrFcShort( 0x4113 ),	/* Flags:  must size, must free, out, simple ref, srv alloc size=16 */
/* 1202 */	NdrFcShort( 0x4 ),	/* x86 Stack size/offset = 4 */
/* 1204 */	NdrFcShort( 0x41a ),	/* Type Offset=1050 */

	/* Return value */

/* 1206 */	NdrFcShort( 0x70 ),	/* Flags:  out, return, base type, */
/* 1208 */	NdrFcShort( 0x8 ),	/* x86 Stack size/offset = 8 */
/* 1210 */	0x8,		/* FC_LONG */
			0x0,		/* 0 */

	/* Procedure put_PCfwd */

/* 1212 */	0x33,		/* FC_AUTO_HANDLE */
			0x6c,		/* Old Flags:  object, Oi2 */
/* 1214 */	NdrFcLong( 0x0 ),	/* 0 */
/* 1218 */	NdrFcShort( 0x22 ),	/* 34 */
/* 1220 */	NdrFcShort( 0x18 ),	/* x86 Stack size/offset = 24 */
/* 1222 */	NdrFcShort( 0x0 ),	/* 0 */
/* 1224 */	NdrFcShort( 0x8 ),	/* 8 */
/* 1226 */	0x46,		/* Oi2 Flags:  clt must size, has return, has ext, */
			0x2,		/* 2 */
/* 1228 */	0x8,		/* 8 */
			0x5,		/* Ext Flags:  new corr desc, srv corr check, */
/* 1230 */	NdrFcShort( 0x0 ),	/* 0 */
/* 1232 */	NdrFcShort( 0x3d8 ),	/* 984 */
/* 1234 */	NdrFcShort( 0x0 ),	/* 0 */

	/* Parameter PCfwd */

/* 1236 */	NdrFcShort( 0x8b ),	/* Flags:  must size, must free, in, by val, */
/* 1238 */	NdrFcShort( 0x4 ),	/* x86 Stack size/offset = 4 */
/* 1240 */	NdrFcShort( 0x428 ),	/* Type Offset=1064 */

	/* Return value */

/* 1242 */	NdrFcShort( 0x70 ),	/* Flags:  out, return, base type, */
/* 1244 */	NdrFcShort( 0x14 ),	/* x86 Stack size/offset = 20 */
/* 1246 */	0x8,		/* FC_LONG */
			0x0,		/* 0 */

	/* Procedure get_nu */

/* 1248 */	0x33,		/* FC_AUTO_HANDLE */
			0x6c,		/* Old Flags:  object, Oi2 */
/* 1250 */	NdrFcLong( 0x0 ),	/* 0 */
/* 1254 */	NdrFcShort( 0x23 ),	/* 35 */
/* 1256 */	NdrFcShort( 0xc ),	/* x86 Stack size/offset = 12 */
/* 1258 */	NdrFcShort( 0x0 ),	/* 0 */
/* 1260 */	NdrFcShort( 0x8 ),	/* 8 */
/* 1262 */	0x45,		/* Oi2 Flags:  srv must size, has return, has ext, */
			0x2,		/* 2 */
/* 1264 */	0x8,		/* 8 */
			0x3,		/* Ext Flags:  new corr desc, clt corr check, */
/* 1266 */	NdrFcShort( 0x406 ),	/* 1030 */
/* 1268 */	NdrFcShort( 0x0 ),	/* 0 */
/* 1270 */	NdrFcShort( 0x0 ),	/* 0 */

	/* Parameter nu */

/* 1272 */	NdrFcShort( 0x4113 ),	/* Flags:  must size, must free, out, simple ref, srv alloc size=16 */
/* 1274 */	NdrFcShort( 0x4 ),	/* x86 Stack size/offset = 4 */
/* 1276 */	NdrFcShort( 0x41a ),	/* Type Offset=1050 */

	/* Return value */

/* 1278 */	NdrFcShort( 0x70 ),	/* Flags:  out, return, base type, */
/* 1280 */	NdrFcShort( 0x8 ),	/* x86 Stack size/offset = 8 */
/* 1282 */	0x8,		/* FC_LONG */
			0x0,		/* 0 */

	/* Procedure put_nu */

/* 1284 */	0x33,		/* FC_AUTO_HANDLE */
			0x6c,		/* Old Flags:  object, Oi2 */
/* 1286 */	NdrFcLong( 0x0 ),	/* 0 */
/* 1290 */	NdrFcShort( 0x24 ),	/* 36 */
/* 1292 */	NdrFcShort( 0x18 ),	/* x86 Stack size/offset = 24 */
/* 1294 */	NdrFcShort( 0x0 ),	/* 0 */
/* 1296 */	NdrFcShort( 0x8 ),	/* 8 */
/* 1298 */	0x46,		/* Oi2 Flags:  clt must size, has return, has ext, */
			0x2,		/* 2 */
/* 1300 */	0x8,		/* 8 */
			0x5,		/* Ext Flags:  new corr desc, srv corr check, */
/* 1302 */	NdrFcShort( 0x0 ),	/* 0 */
/* 1304 */	NdrFcShort( 0x435 ),	/* 1077 */
/* 1306 */	NdrFcShort( 0x0 ),	/* 0 */

	/* Parameter nu */

/* 1308 */	NdrFcShort( 0x8b ),	/* Flags:  must size, must free, in, by val, */
/* 1310 */	NdrFcShort( 0x4 ),	/* x86 Stack size/offset = 4 */
/* 1312 */	NdrFcShort( 0x428 ),	/* Type Offset=1064 */

	/* Return value */

/* 1314 */	NdrFcShort( 0x70 ),	/* Flags:  out, return, base type, */
/* 1316 */	NdrFcShort( 0x14 ),	/* x86 Stack size/offset = 20 */
/* 1318 */	0x8,		/* FC_LONG */
			0x0,		/* 0 */

	/* Procedure get_np */

/* 1320 */	0x33,		/* FC_AUTO_HANDLE */
			0x6c,		/* Old Flags:  object, Oi2 */
/* 1322 */	NdrFcLong( 0x0 ),	/* 0 */
/* 1326 */	NdrFcShort( 0x25 ),	/* 37 */
/* 1328 */	NdrFcShort( 0xc ),	/* x86 Stack size/offset = 12 */
/* 1330 */	NdrFcShort( 0x0 ),	/* 0 */
/* 1332 */	NdrFcShort( 0x8 ),	/* 8 */
/* 1334 */	0x45,		/* Oi2 Flags:  srv must size, has return, has ext, */
			0x2,		/* 2 */
/* 1336 */	0x8,		/* 8 */
			0x3,		/* Ext Flags:  new corr desc, clt corr check, */
/* 1338 */	NdrFcShort( 0x465 ),	/* 1125 */
/* 1340 */	NdrFcShort( 0x0 ),	/* 0 */
/* 1342 */	NdrFcShort( 0x0 ),	/* 0 */

	/* Parameter np */

/* 1344 */	NdrFcShort( 0x4113 ),	/* Flags:  must size, must free, out, simple ref, srv alloc size=16 */
/* 1346 */	NdrFcShort( 0x4 ),	/* x86 Stack size/offset = 4 */
/* 1348 */	NdrFcShort( 0x41a ),	/* Type Offset=1050 */

	/* Return value */

/* 1350 */	NdrFcShort( 0x70 ),	/* Flags:  out, return, base type, */
/* 1352 */	NdrFcShort( 0x8 ),	/* x86 Stack size/offset = 8 */
/* 1354 */	0x8,		/* FC_LONG */
			0x0,		/* 0 */

	/* Procedure put_np */

/* 1356 */	0x33,		/* FC_AUTO_HANDLE */
			0x6c,		/* Old Flags:  object, Oi2 */
/* 1358 */	NdrFcLong( 0x0 ),	/* 0 */
/* 1362 */	NdrFcShort( 0x26 ),	/* 38 */
/* 1364 */	NdrFcShort( 0x18 ),	/* x86 Stack size/offset = 24 */
/* 1366 */	NdrFcShort( 0x0 ),	/* 0 */
/* 1368 */	NdrFcShort( 0x8 ),	/* 8 */
/* 1370 */	0x46,		/* Oi2 Flags:  clt must size, has return, has ext, */
			0x2,		/* 2 */
/* 1372 */	0x8,		/* 8 */
			0x5,		/* Ext Flags:  new corr desc, srv corr check, */
/* 1374 */	NdrFcShort( 0x0 ),	/* 0 */
/* 1376 */	NdrFcShort( 0x496 ),	/* 1174 */
/* 1378 */	NdrFcShort( 0x0 ),	/* 0 */

	/* Parameter np */

/* 1380 */	NdrFcShort( 0x8b ),	/* Flags:  must size, must free, in, by val, */
/* 1382 */	NdrFcShort( 0x4 ),	/* x86 Stack size/offset = 4 */
/* 1384 */	NdrFcShort( 0x428 ),	/* Type Offset=1064 */

	/* Return value */

/* 1386 */	NdrFcShort( 0x70 ),	/* Flags:  out, return, base type, */
/* 1388 */	NdrFcShort( 0x14 ),	/* x86 Stack size/offset = 20 */
/* 1390 */	0x8,		/* FC_LONG */
			0x0,		/* 0 */

	/* Procedure get_ny */

/* 1392 */	0x33,		/* FC_AUTO_HANDLE */
			0x6c,		/* Old Flags:  object, Oi2 */
/* 1394 */	NdrFcLong( 0x0 ),	/* 0 */
/* 1398 */	NdrFcShort( 0x27 ),	/* 39 */
/* 1400 */	NdrFcShort( 0xc ),	/* x86 Stack size/offset = 12 */
/* 1402 */	NdrFcShort( 0x0 ),	/* 0 */
/* 1404 */	NdrFcShort( 0x8 ),	/* 8 */
/* 1406 */	0x45,		/* Oi2 Flags:  srv must size, has return, has ext, */
			0x2,		/* 2 */
/* 1408 */	0x8,		/* 8 */
			0x3,		/* Ext Flags:  new corr desc, clt corr check, */
/* 1410 */	NdrFcShort( 0x4c8 ),	/* 1224 */
/* 1412 */	NdrFcShort( 0x0 ),	/* 0 */
/* 1414 */	NdrFcShort( 0x0 ),	/* 0 */

	/* Parameter ny */

/* 1416 */	NdrFcShort( 0x4113 ),	/* Flags:  must size, must free, out, simple ref, srv alloc size=16 */
/* 1418 */	NdrFcShort( 0x4 ),	/* x86 Stack size/offset = 4 */
/* 1420 */	NdrFcShort( 0x41a ),	/* Type Offset=1050 */

	/* Return value */

/* 1422 */	NdrFcShort( 0x70 ),	/* Flags:  out, return, base type, */
/* 1424 */	NdrFcShort( 0x8 ),	/* x86 Stack size/offset = 8 */
/* 1426 */	0x8,		/* FC_LONG */
			0x0,		/* 0 */

	/* Procedure put_ny */

/* 1428 */	0x33,		/* FC_AUTO_HANDLE */
			0x6c,		/* Old Flags:  object, Oi2 */
/* 1430 */	NdrFcLong( 0x0 ),	/* 0 */
/* 1434 */	NdrFcShort( 0x28 ),	/* 40 */
/* 1436 */	NdrFcShort( 0x18 ),	/* x86 Stack size/offset = 24 */
/* 1438 */	NdrFcShort( 0x0 ),	/* 0 */
/* 1440 */	NdrFcShort( 0x8 ),	/* 8 */
/* 1442 */	0x46,		/* Oi2 Flags:  clt must size, has return, has ext, */
			0x2,		/* 2 */
/* 1444 */	0x8,		/* 8 */
			0x5,		/* Ext Flags:  new corr desc, srv corr check, */
/* 1446 */	NdrFcShort( 0x0 ),	/* 0 */
/* 1448 */	NdrFcShort( 0x4fb ),	/* 1275 */
/* 1450 */	NdrFcShort( 0x0 ),	/* 0 */

	/* Parameter ny */

/* 1452 */	NdrFcShort( 0x8b ),	/* Flags:  must size, must free, in, by val, */
/* 1454 */	NdrFcShort( 0x4 ),	/* x86 Stack size/offset = 4 */
/* 1456 */	NdrFcShort( 0x428 ),	/* Type Offset=1064 */

	/* Return value */

/* 1458 */	NdrFcShort( 0x70 ),	/* Flags:  out, return, base type, */
/* 1460 */	NdrFcShort( 0x14 ),	/* x86 Stack size/offset = 20 */
/* 1462 */	0x8,		/* FC_LONG */
			0x0,		/* 0 */

	/* Procedure get_q */

/* 1464 */	0x33,		/* FC_AUTO_HANDLE */
			0x6c,		/* Old Flags:  object, Oi2 */
/* 1466 */	NdrFcLong( 0x0 ),	/* 0 */
/* 1470 */	NdrFcShort( 0x29 ),	/* 41 */
/* 1472 */	NdrFcShort( 0xc ),	/* x86 Stack size/offset = 12 */
/* 1474 */	NdrFcShort( 0x0 ),	/* 0 */
/* 1476 */	NdrFcShort( 0x8 ),	/* 8 */
/* 1478 */	0x45,		/* Oi2 Flags:  srv must size, has return, has ext, */
			0x2,		/* 2 */
/* 1480 */	0x8,		/* 8 */
			0x3,		/* Ext Flags:  new corr desc, clt corr check, */
/* 1482 */	NdrFcShort( 0x52f ),	/* 1327 */
/* 1484 */	NdrFcShort( 0x0 ),	/* 0 */
/* 1486 */	NdrFcShort( 0x0 ),	/* 0 */

	/* Parameter q */

/* 1488 */	NdrFcShort( 0x4113 ),	/* Flags:  must size, must free, out, simple ref, srv alloc size=16 */
/* 1490 */	NdrFcShort( 0x4 ),	/* x86 Stack size/offset = 4 */
/* 1492 */	NdrFcShort( 0x41a ),	/* Type Offset=1050 */

	/* Return value */

/* 1494 */	NdrFcShort( 0x70 ),	/* Flags:  out, return, base type, */
/* 1496 */	NdrFcShort( 0x8 ),	/* x86 Stack size/offset = 8 */
/* 1498 */	0x8,		/* FC_LONG */
			0x0,		/* 0 */

	/* Procedure put_q */

/* 1500 */	0x33,		/* FC_AUTO_HANDLE */
			0x6c,		/* Old Flags:  object, Oi2 */
/* 1502 */	NdrFcLong( 0x0 ),	/* 0 */
/* 1506 */	NdrFcShort( 0x2a ),	/* 42 */
/* 1508 */	NdrFcShort( 0x18 ),	/* x86 Stack size/offset = 24 */
/* 1510 */	NdrFcShort( 0x0 ),	/* 0 */
/* 1512 */	NdrFcShort( 0x8 ),	/* 8 */
/* 1514 */	0x46,		/* Oi2 Flags:  clt must size, has return, has ext, */
			0x2,		/* 2 */
/* 1516 */	0x8,		/* 8 */
			0x5,		/* Ext Flags:  new corr desc, srv corr check, */
/* 1518 */	NdrFcShort( 0x0 ),	/* 0 */
/* 1520 */	NdrFcShort( 0x564 ),	/* 1380 */
/* 1522 */	NdrFcShort( 0x0 ),	/* 0 */

	/* Parameter q */

/* 1524 */	NdrFcShort( 0x8b ),	/* Flags:  must size, must free, in, by val, */
/* 1526 */	NdrFcShort( 0x4 ),	/* x86 Stack size/offset = 4 */
/* 1528 */	NdrFcShort( 0x428 ),	/* Type Offset=1064 */

	/* Return value */

/* 1530 */	NdrFcShort( 0x70 ),	/* Flags:  out, return, base type, */
/* 1532 */	NdrFcShort( 0x14 ),	/* x86 Stack size/offset = 20 */
/* 1534 */	0x8,		/* FC_LONG */
			0x0,		/* 0 */

	/* Procedure get_r */

/* 1536 */	0x33,		/* FC_AUTO_HANDLE */
			0x6c,		/* Old Flags:  object, Oi2 */
/* 1538 */	NdrFcLong( 0x0 ),	/* 0 */
/* 1542 */	NdrFcShort( 0x2b ),	/* 43 */
/* 1544 */	NdrFcShort( 0xc ),	/* x86 Stack size/offset = 12 */
/* 1546 */	NdrFcShort( 0x0 ),	/* 0 */
/* 1548 */	NdrFcShort( 0x8 ),	/* 8 */
/* 1550 */	0x45,		/* Oi2 Flags:  srv must size, has return, has ext, */
			0x2,		/* 2 */
/* 1552 */	0x8,		/* 8 */
			0x3,		/* Ext Flags:  new corr desc, clt corr check, */
/* 1554 */	NdrFcShort( 0x59a ),	/* 1434 */
/* 1556 */	NdrFcShort( 0x0 ),	/* 0 */
/* 1558 */	NdrFcShort( 0x0 ),	/* 0 */

	/* Parameter r */

/* 1560 */	NdrFcShort( 0x4113 ),	/* Flags:  must size, must free, out, simple ref, srv alloc size=16 */
/* 1562 */	NdrFcShort( 0x4 ),	/* x86 Stack size/offset = 4 */
/* 1564 */	NdrFcShort( 0x41a ),	/* Type Offset=1050 */

	/* Return value */

/* 1566 */	NdrFcShort( 0x70 ),	/* Flags:  out, return, base type, */
/* 1568 */	NdrFcShort( 0x8 ),	/* x86 Stack size/offset = 8 */
/* 1570 */	0x8,		/* FC_LONG */
			0x0,		/* 0 */

	/* Procedure put_r */

/* 1572 */	0x33,		/* FC_AUTO_HANDLE */
			0x6c,		/* Old Flags:  object, Oi2 */
/* 1574 */	NdrFcLong( 0x0 ),	/* 0 */
/* 1578 */	NdrFcShort( 0x2c ),	/* 44 */
/* 1580 */	NdrFcShort( 0x18 ),	/* x86 Stack size/offset = 24 */
/* 1582 */	NdrFcShort( 0x0 ),	/* 0 */
/* 1584 */	NdrFcShort( 0x8 ),	/* 8 */
/* 1586 */	0x46,		/* Oi2 Flags:  clt must size, has return, has ext, */
			0x2,		/* 2 */
/* 1588 */	0x8,		/* 8 */
			0x5,		/* Ext Flags:  new corr desc, srv corr check, */
/* 1590 */	NdrFcShort( 0x0 ),	/* 0 */
/* 1592 */	NdrFcShort( 0x5d1 ),	/* 1489 */
/* 1594 */	NdrFcShort( 0x0 ),	/* 0 */

	/* Parameter r */

/* 1596 */	NdrFcShort( 0x8b ),	/* Flags:  must size, must free, in, by val, */
/* 1598 */	NdrFcShort( 0x4 ),	/* x86 Stack size/offset = 4 */
/* 1600 */	NdrFcShort( 0x428 ),	/* Type Offset=1064 */

	/* Return value */

/* 1602 */	NdrFcShort( 0x70 ),	/* Flags:  out, return, base type, */
/* 1604 */	NdrFcShort( 0x14 ),	/* x86 Stack size/offset = 20 */
/* 1606 */	0x8,		/* FC_LONG */
			0x0,		/* 0 */

	/* Procedure get_ys */

/* 1608 */	0x33,		/* FC_AUTO_HANDLE */
			0x6c,		/* Old Flags:  object, Oi2 */
/* 1610 */	NdrFcLong( 0x0 ),	/* 0 */
/* 1614 */	NdrFcShort( 0x2d ),	/* 45 */
/* 1616 */	NdrFcShort( 0xc ),	/* x86 Stack size/offset = 12 */
/* 1618 */	NdrFcShort( 0x0 ),	/* 0 */
/* 1620 */	NdrFcShort( 0x8 ),	/* 8 */
/* 1622 */	0x45,		/* Oi2 Flags:  srv must size, has return, has ext, */
			0x2,		/* 2 */
/* 1624 */	0x8,		/* 8 */
			0x3,		/* Ext Flags:  new corr desc, clt corr check, */
/* 1626 */	NdrFcShort( 0x609 ),	/* 1545 */
/* 1628 */	NdrFcShort( 0x0 ),	/* 0 */
/* 1630 */	NdrFcShort( 0x0 ),	/* 0 */

	/* Parameter ys */

/* 1632 */	NdrFcShort( 0x4113 ),	/* Flags:  must size, must free, out, simple ref, srv alloc size=16 */
/* 1634 */	NdrFcShort( 0x4 ),	/* x86 Stack size/offset = 4 */
/* 1636 */	NdrFcShort( 0x41a ),	/* Type Offset=1050 */

	/* Return value */

/* 1638 */	NdrFcShort( 0x70 ),	/* Flags:  out, return, base type, */
/* 1640 */	NdrFcShort( 0x8 ),	/* x86 Stack size/offset = 8 */
/* 1642 */	0x8,		/* FC_LONG */
			0x0,		/* 0 */

	/* Procedure put_ys */

/* 1644 */	0x33,		/* FC_AUTO_HANDLE */
			0x6c,		/* Old Flags:  object, Oi2 */
/* 1646 */	NdrFcLong( 0x0 ),	/* 0 */
/* 1650 */	NdrFcShort( 0x2e ),	/* 46 */
/* 1652 */	NdrFcShort( 0x18 ),	/* x86 Stack size/offset = 24 */
/* 1654 */	NdrFcShort( 0x0 ),	/* 0 */
/* 1656 */	NdrFcShort( 0x8 ),	/* 8 */
/* 1658 */	0x46,		/* Oi2 Flags:  clt must size, has return, has ext, */
			0x2,		/* 2 */
/* 1660 */	0x8,		/* 8 */
			0x5,		/* Ext Flags:  new corr desc, srv corr check, */
/* 1662 */	NdrFcShort( 0x0 ),	/* 0 */
/* 1664 */	NdrFcShort( 0x642 ),	/* 1602 */
/* 1666 */	NdrFcShort( 0x0 ),	/* 0 */

	/* Parameter ys */

/* 1668 */	NdrFcShort( 0x8b ),	/* Flags:  must size, must free, in, by val, */
/* 1670 */	NdrFcShort( 0x4 ),	/* x86 Stack size/offset = 4 */
/* 1672 */	NdrFcShort( 0x428 ),	/* Type Offset=1064 */

	/* Return value */

/* 1674 */	NdrFcShort( 0x70 ),	/* Flags:  out, return, base type, */
/* 1676 */	NdrFcShort( 0x14 ),	/* x86 Stack size/offset = 20 */
/* 1678 */	0x8,		/* FC_LONG */
			0x0,		/* 0 */

	/* Procedure get_yspmax */

/* 1680 */	0x33,		/* FC_AUTO_HANDLE */
			0x6c,		/* Old Flags:  object, Oi2 */
/* 1682 */	NdrFcLong( 0x0 ),	/* 0 */
/* 1686 */	NdrFcShort( 0x2f ),	/* 47 */
/* 1688 */	NdrFcShort( 0xc ),	/* x86 Stack size/offset = 12 */
/* 1690 */	NdrFcShort( 0x0 ),	/* 0 */
/* 1692 */	NdrFcShort( 0x8 ),	/* 8 */
/* 1694 */	0x45,		/* Oi2 Flags:  srv must size, has return, has ext, */
			0x2,		/* 2 */
/* 1696 */	0x8,		/* 8 */
			0x3,		/* Ext Flags:  new corr desc, clt corr check, */
/* 1698 */	NdrFcShort( 0x67c ),	/* 1660 */
/* 1700 */	NdrFcShort( 0x0 ),	/* 0 */
/* 1702 */	NdrFcShort( 0x0 ),	/* 0 */

	/* Parameter yspmax */

/* 1704 */	NdrFcShort( 0x4113 ),	/* Flags:  must size, must free, out, simple ref, srv alloc size=16 */
/* 1706 */	NdrFcShort( 0x4 ),	/* x86 Stack size/offset = 4 */
/* 1708 */	NdrFcShort( 0x41a ),	/* Type Offset=1050 */

	/* Return value */

/* 1710 */	NdrFcShort( 0x70 ),	/* Flags:  out, return, base type, */
/* 1712 */	NdrFcShort( 0x8 ),	/* x86 Stack size/offset = 8 */
/* 1714 */	0x8,		/* FC_LONG */
			0x0,		/* 0 */

	/* Procedure put_yspmax */

/* 1716 */	0x33,		/* FC_AUTO_HANDLE */
			0x6c,		/* Old Flags:  object, Oi2 */
/* 1718 */	NdrFcLong( 0x0 ),	/* 0 */
/* 1722 */	NdrFcShort( 0x30 ),	/* 48 */
/* 1724 */	NdrFcShort( 0x18 ),	/* x86 Stack size/offset = 24 */
/* 1726 */	NdrFcShort( 0x0 ),	/* 0 */
/* 1728 */	NdrFcShort( 0x8 ),	/* 8 */
/* 1730 */	0x46,		/* Oi2 Flags:  clt must size, has return, has ext, */
			0x2,		/* 2 */
/* 1732 */	0x8,		/* 8 */
			0x5,		/* Ext Flags:  new corr desc, srv corr check, */
/* 1734 */	NdrFcShort( 0x0 ),	/* 0 */
/* 1736 */	NdrFcShort( 0x6b7 ),	/* 1719 */
/* 1738 */	NdrFcShort( 0x0 ),	/* 0 */

	/* Parameter yspmax */

/* 1740 */	NdrFcShort( 0x8b ),	/* Flags:  must size, must free, in, by val, */
/* 1742 */	NdrFcShort( 0x4 ),	/* x86 Stack size/offset = 4 */
/* 1744 */	NdrFcShort( 0x428 ),	/* Type Offset=1064 */

	/* Return value */

/* 1746 */	NdrFcShort( 0x70 ),	/* Flags:  out, return, base type, */
/* 1748 */	NdrFcShort( 0x14 ),	/* x86 Stack size/offset = 20 */
/* 1750 */	0x8,		/* FC_LONG */
			0x0,		/* 0 */

	/* Procedure get_yspmin */

/* 1752 */	0x33,		/* FC_AUTO_HANDLE */
			0x6c,		/* Old Flags:  object, Oi2 */
/* 1754 */	NdrFcLong( 0x0 ),	/* 0 */
/* 1758 */	NdrFcShort( 0x31 ),	/* 49 */
/* 1760 */	NdrFcShort( 0xc ),	/* x86 Stack size/offset = 12 */
/* 1762 */	NdrFcShort( 0x0 ),	/* 0 */
/* 1764 */	NdrFcShort( 0x8 ),	/* 8 */
/* 1766 */	0x45,		/* Oi2 Flags:  srv must size, has return, has ext, */
			0x2,		/* 2 */
/* 1768 */	0x8,		/* 8 */
			0x3,		/* Ext Flags:  new corr desc, clt corr check, */
/* 1770 */	NdrFcShort( 0x6f3 ),	/* 1779 */
/* 1772 */	NdrFcShort( 0x0 ),	/* 0 */
/* 1774 */	NdrFcShort( 0x0 ),	/* 0 */

	/* Parameter yspmin */

/* 1776 */	NdrFcShort( 0x4113 ),	/* Flags:  must size, must free, out, simple ref, srv alloc size=16 */
/* 1778 */	NdrFcShort( 0x4 ),	/* x86 Stack size/offset = 4 */
/* 1780 */	NdrFcShort( 0x41a ),	/* Type Offset=1050 */

	/* Return value */

/* 1782 */	NdrFcShort( 0x70 ),	/* Flags:  out, return, base type, */
/* 1784 */	NdrFcShort( 0x8 ),	/* x86 Stack size/offset = 8 */
/* 1786 */	0x8,		/* FC_LONG */
			0x0,		/* 0 */

	/* Procedure put_yspmin */

/* 1788 */	0x33,		/* FC_AUTO_HANDLE */
			0x6c,		/* Old Flags:  object, Oi2 */
/* 1790 */	NdrFcLong( 0x0 ),	/* 0 */
/* 1794 */	NdrFcShort( 0x32 ),	/* 50 */
/* 1796 */	NdrFcShort( 0x18 ),	/* x86 Stack size/offset = 24 */
/* 1798 */	NdrFcShort( 0x0 ),	/* 0 */
/* 1800 */	NdrFcShort( 0x8 ),	/* 8 */
/* 1802 */	0x46,		/* Oi2 Flags:  clt must size, has return, has ext, */
			0x2,		/* 2 */
/* 1804 */	0x8,		/* 8 */
			0x5,		/* Ext Flags:  new corr desc, srv corr check, */
/* 1806 */	NdrFcShort( 0x0 ),	/* 0 */
/* 1808 */	NdrFcShort( 0x730 ),	/* 1840 */
/* 1810 */	NdrFcShort( 0x0 ),	/* 0 */

	/* Parameter yspmin */

/* 1812 */	NdrFcShort( 0x8b ),	/* Flags:  must size, must free, in, by val, */
/* 1814 */	NdrFcShort( 0x4 ),	/* x86 Stack size/offset = 4 */
/* 1816 */	NdrFcShort( 0x428 ),	/* Type Offset=1064 */

	/* Return value */

/* 1818 */	NdrFcShort( 0x70 ),	/* Flags:  out, return, base type, */
/* 1820 */	NdrFcShort( 0x14 ),	/* x86 Stack size/offset = 20 */
/* 1822 */	0x8,		/* FC_LONG */
			0x0,		/* 0 */

	/* Procedure get_umax */

/* 1824 */	0x33,		/* FC_AUTO_HANDLE */
			0x6c,		/* Old Flags:  object, Oi2 */
/* 1826 */	NdrFcLong( 0x0 ),	/* 0 */
/* 1830 */	NdrFcShort( 0x33 ),	/* 51 */
/* 1832 */	NdrFcShort( 0xc ),	/* x86 Stack size/offset = 12 */
/* 1834 */	NdrFcShort( 0x0 ),	/* 0 */
/* 1836 */	NdrFcShort( 0x8 ),	/* 8 */
/* 1838 */	0x45,		/* Oi2 Flags:  srv must size, has return, has ext, */
			0x2,		/* 2 */
/* 1840 */	0x8,		/* 8 */
			0x3,		/* Ext Flags:  new corr desc, clt corr check, */
/* 1842 */	NdrFcShort( 0x76e ),	/* 1902 */
/* 1844 */	NdrFcShort( 0x0 ),	/* 0 */
/* 1846 */	NdrFcShort( 0x0 ),	/* 0 */

	/* Parameter umax */

/* 1848 */	NdrFcShort( 0x4113 ),	/* Flags:  must size, must free, out, simple ref, srv alloc size=16 */
/* 1850 */	NdrFcShort( 0x4 ),	/* x86 Stack size/offset = 4 */
/* 1852 */	NdrFcShort( 0x41a ),	/* Type Offset=1050 */

	/* Return value */

/* 1854 */	NdrFcShort( 0x70 ),	/* Flags:  out, return, base type, */
/* 1856 */	NdrFcShort( 0x8 ),	/* x86 Stack size/offset = 8 */
/* 1858 */	0x8,		/* FC_LONG */
			0x0,		/* 0 */

	/* Procedure put_umax */

/* 1860 */	0x33,		/* FC_AUTO_HANDLE */
			0x6c,		/* Old Flags:  object, Oi2 */
/* 1862 */	NdrFcLong( 0x0 ),	/* 0 */
/* 1866 */	NdrFcShort( 0x34 ),	/* 52 */
/* 1868 */	NdrFcShort( 0x18 ),	/* x86 Stack size/offset = 24 */
/* 1870 */	NdrFcShort( 0x0 ),	/* 0 */
/* 1872 */	NdrFcShort( 0x8 ),	/* 8 */
/* 1874 */	0x46,		/* Oi2 Flags:  clt must size, has return, has ext, */
			0x2,		/* 2 */
/* 1876 */	0x8,		/* 8 */
			0x5,		/* Ext Flags:  new corr desc, srv corr check, */
/* 1878 */	NdrFcShort( 0x0 ),	/* 0 */
/* 1880 */	NdrFcShort( 0x7ad ),	/* 1965 */
/* 1882 */	NdrFcShort( 0x0 ),	/* 0 */

	/* Parameter umax */

/* 1884 */	NdrFcShort( 0x8b ),	/* Flags:  must size, must free, in, by val, */
/* 1886 */	NdrFcShort( 0x4 ),	/* x86 Stack size/offset = 4 */
/* 1888 */	NdrFcShort( 0x428 ),	/* Type Offset=1064 */

	/* Return value */

/* 1890 */	NdrFcShort( 0x70 ),	/* Flags:  out, return, base type, */
/* 1892 */	NdrFcShort( 0x14 ),	/* x86 Stack size/offset = 20 */
/* 1894 */	0x8,		/* FC_LONG */
			0x0,		/* 0 */

	/* Procedure get_umin */

/* 1896 */	0x33,		/* FC_AUTO_HANDLE */
			0x6c,		/* Old Flags:  object, Oi2 */
/* 1898 */	NdrFcLong( 0x0 ),	/* 0 */
/* 1902 */	NdrFcShort( 0x35 ),	/* 53 */
/* 1904 */	NdrFcShort( 0xc ),	/* x86 Stack size/offset = 12 */
/* 1906 */	NdrFcShort( 0x0 ),	/* 0 */
/* 1908 */	NdrFcShort( 0x8 ),	/* 8 */
/* 1910 */	0x45,		/* Oi2 Flags:  srv must size, has return, has ext, */
			0x2,		/* 2 */
/* 1912 */	0x8,		/* 8 */
			0x3,		/* Ext Flags:  new corr desc, clt corr check, */
/* 1914 */	NdrFcShort( 0x7ed ),	/* 2029 */
/* 1916 */	NdrFcShort( 0x0 ),	/* 0 */
/* 1918 */	NdrFcShort( 0x0 ),	/* 0 */

	/* Parameter umin */

/* 1920 */	NdrFcShort( 0x4113 ),	/* Flags:  must size, must free, out, simple ref, srv alloc size=16 */
/* 1922 */	NdrFcShort( 0x4 ),	/* x86 Stack size/offset = 4 */
/* 1924 */	NdrFcShort( 0x41a ),	/* Type Offset=1050 */

	/* Return value */

/* 1926 */	NdrFcShort( 0x70 ),	/* Flags:  out, return, base type, */
/* 1928 */	NdrFcShort( 0x8 ),	/* x86 Stack size/offset = 8 */
/* 1930 */	0x8,		/* FC_LONG */
			0x0,		/* 0 */

	/* Procedure put_umin */

/* 1932 */	0x33,		/* FC_AUTO_HANDLE */
			0x6c,		/* Old Flags:  object, Oi2 */
/* 1934 */	NdrFcLong( 0x0 ),	/* 0 */
/* 1938 */	NdrFcShort( 0x36 ),	/* 54 */
/* 1940 */	NdrFcShort( 0x18 ),	/* x86 Stack size/offset = 24 */
/* 1942 */	NdrFcShort( 0x0 ),	/* 0 */
/* 1944 */	NdrFcShort( 0x8 ),	/* 8 */
/* 1946 */	0x46,		/* Oi2 Flags:  clt must size, has return, has ext, */
			0x2,		/* 2 */
/* 1948 */	0x8,		/* 8 */
			0x5,		/* Ext Flags:  new corr desc, srv corr check, */
/* 1950 */	NdrFcShort( 0x0 ),	/* 0 */
/* 1952 */	NdrFcShort( 0x82e ),	/* 2094 */
/* 1954 */	NdrFcShort( 0x0 ),	/* 0 */

	/* Parameter umin */

/* 1956 */	NdrFcShort( 0x8b ),	/* Flags:  must size, must free, in, by val, */
/* 1958 */	NdrFcShort( 0x4 ),	/* x86 Stack size/offset = 4 */
/* 1960 */	NdrFcShort( 0x428 ),	/* Type Offset=1064 */

	/* Return value */

/* 1962 */	NdrFcShort( 0x70 ),	/* Flags:  out, return, base type, */
/* 1964 */	NdrFcShort( 0x14 ),	/* x86 Stack size/offset = 20 */
/* 1966 */	0x8,		/* FC_LONG */
			0x0,		/* 0 */

	/* Procedure get_dumax */

/* 1968 */	0x33,		/* FC_AUTO_HANDLE */
			0x6c,		/* Old Flags:  object, Oi2 */
/* 1970 */	NdrFcLong( 0x0 ),	/* 0 */
/* 1974 */	NdrFcShort( 0x37 ),	/* 55 */
/* 1976 */	NdrFcShort( 0xc ),	/* x86 Stack size/offset = 12 */
/* 1978 */	NdrFcShort( 0x0 ),	/* 0 */
/* 1980 */	NdrFcShort( 0x8 ),	/* 8 */
/* 1982 */	0x45,		/* Oi2 Flags:  srv must size, has return, has ext, */
			0x2,		/* 2 */
/* 1984 */	0x8,		/* 8 */
			0x3,		/* Ext Flags:  new corr desc, clt corr check, */
/* 1986 */	NdrFcShort( 0x870 ),	/* 2160 */
/* 1988 */	NdrFcShort( 0x0 ),	/* 0 */
/* 1990 */	NdrFcShort( 0x0 ),	/* 0 */

	/* Parameter dumax */

/* 1992 */	NdrFcShort( 0x4113 ),	/* Flags:  must size, must free, out, simple ref, srv alloc size=16 */
/* 1994 */	NdrFcShort( 0x4 ),	/* x86 Stack size/offset = 4 */
/* 1996 */	NdrFcShort( 0x41a ),	/* Type Offset=1050 */

	/* Return value */

/* 1998 */	NdrFcShort( 0x70 ),	/* Flags:  out, return, base type, */
/* 2000 */	NdrFcShort( 0x8 ),	/* x86 Stack size/offset = 8 */
/* 2002 */	0x8,		/* FC_LONG */
			0x0,		/* 0 */

	/* Procedure put_dumax */

/* 2004 */	0x33,		/* FC_AUTO_HANDLE */
			0x6c,		/* Old Flags:  object, Oi2 */
/* 2006 */	NdrFcLong( 0x0 ),	/* 0 */
/* 2010 */	NdrFcShort( 0x38 ),	/* 56 */
/* 2012 */	NdrFcShort( 0x18 ),	/* x86 Stack size/offset = 24 */
/* 2014 */	NdrFcShort( 0x0 ),	/* 0 */
/* 2016 */	NdrFcShort( 0x8 ),	/* 8 */
/* 2018 */	0x46,		/* Oi2 Flags:  clt must size, has return, has ext, */
			0x2,		/* 2 */
/* 2020 */	0x8,		/* 8 */
			0x5,		/* Ext Flags:  new corr desc, srv corr check, */
/* 2022 */	NdrFcShort( 0x0 ),	/* 0 */
/* 2024 */	NdrFcShort( 0x8b3 ),	/* 2227 */
/* 2026 */	NdrFcShort( 0x0 ),	/* 0 */

	/* Parameter dumax */

/* 2028 */	NdrFcShort( 0x8b ),	/* Flags:  must size, must free, in, by val, */
/* 2030 */	NdrFcShort( 0x4 ),	/* x86 Stack size/offset = 4 */
/* 2032 */	NdrFcShort( 0x428 ),	/* Type Offset=1064 */

	/* Return value */

/* 2034 */	NdrFcShort( 0x70 ),	/* Flags:  out, return, base type, */
/* 2036 */	NdrFcShort( 0x14 ),	/* x86 Stack size/offset = 20 */
/* 2038 */	0x8,		/* FC_LONG */
			0x0,		/* 0 */

	/* Procedure get_LTRange_h */

/* 2040 */	0x33,		/* FC_AUTO_HANDLE */
			0x6c,		/* Old Flags:  object, Oi2 */
/* 2042 */	NdrFcLong( 0x0 ),	/* 0 */
/* 2046 */	NdrFcShort( 0x39 ),	/* 57 */
/* 2048 */	NdrFcShort( 0xc ),	/* x86 Stack size/offset = 12 */
/* 2050 */	NdrFcShort( 0x0 ),	/* 0 */
/* 2052 */	NdrFcShort( 0x8 ),	/* 8 */
/* 2054 */	0x45,		/* Oi2 Flags:  srv must size, has return, has ext, */
			0x2,		/* 2 */
/* 2056 */	0x8,		/* 8 */
			0x3,		/* Ext Flags:  new corr desc, clt corr check, */
/* 2058 */	NdrFcShort( 0x8f7 ),	/* 2295 */
/* 2060 */	NdrFcShort( 0x0 ),	/* 0 */
/* 2062 */	NdrFcShort( 0x0 ),	/* 0 */

	/* Parameter LTRange_h */

/* 2064 */	NdrFcShort( 0x4113 ),	/* Flags:  must size, must free, out, simple ref, srv alloc size=16 */
/* 2066 */	NdrFcShort( 0x4 ),	/* x86 Stack size/offset = 4 */
/* 2068 */	NdrFcShort( 0x41a ),	/* Type Offset=1050 */

	/* Return value */

/* 2070 */	NdrFcShort( 0x70 ),	/* Flags:  out, return, base type, */
/* 2072 */	NdrFcShort( 0x8 ),	/* x86 Stack size/offset = 8 */
/* 2074 */	0x8,		/* FC_LONG */
			0x0,		/* 0 */

	/* Procedure put_LTRange_h */

/* 2076 */	0x33,		/* FC_AUTO_HANDLE */
			0x6c,		/* Old Flags:  object, Oi2 */
/* 2078 */	NdrFcLong( 0x0 ),	/* 0 */
/* 2082 */	NdrFcShort( 0x3a ),	/* 58 */
/* 2084 */	NdrFcShort( 0x18 ),	/* x86 Stack size/offset = 24 */
/* 2086 */	NdrFcShort( 0x0 ),	/* 0 */
/* 2088 */	NdrFcShort( 0x8 ),	/* 8 */
/* 2090 */	0x46,		/* Oi2 Flags:  clt must size, has return, has ext, */
			0x2,		/* 2 */
/* 2092 */	0x8,		/* 8 */
			0x5,		/* Ext Flags:  new corr desc, srv corr check, */
/* 2094 */	NdrFcShort( 0x0 ),	/* 0 */
/* 2096 */	NdrFcShort( 0x93c ),	/* 2364 */
/* 2098 */	NdrFcShort( 0x0 ),	/* 0 */

	/* Parameter LTRange_h */

/* 2100 */	NdrFcShort( 0x8b ),	/* Flags:  must size, must free, in, by val, */
/* 2102 */	NdrFcShort( 0x4 ),	/* x86 Stack size/offset = 4 */
/* 2104 */	NdrFcShort( 0x428 ),	/* Type Offset=1064 */

	/* Return value */

/* 2106 */	NdrFcShort( 0x70 ),	/* Flags:  out, return, base type, */
/* 2108 */	NdrFcShort( 0x14 ),	/* x86 Stack size/offset = 20 */
/* 2110 */	0x8,		/* FC_LONG */
			0x0,		/* 0 */

	/* Procedure get_Bias_h */

/* 2112 */	0x33,		/* FC_AUTO_HANDLE */
			0x6c,		/* Old Flags:  object, Oi2 */
/* 2114 */	NdrFcLong( 0x0 ),	/* 0 */
/* 2118 */	NdrFcShort( 0x3b ),	/* 59 */
/* 2120 */	NdrFcShort( 0xc ),	/* x86 Stack size/offset = 12 */
/* 2122 */	NdrFcShort( 0x0 ),	/* 0 */
/* 2124 */	NdrFcShort( 0x8 ),	/* 8 */
/* 2126 */	0x45,		/* Oi2 Flags:  srv must size, has return, has ext, */
			0x2,		/* 2 */
/* 2128 */	0x8,		/* 8 */
			0x3,		/* Ext Flags:  new corr desc, clt corr check, */
/* 2130 */	NdrFcShort( 0x982 ),	/* 2434 */
/* 2132 */	NdrFcShort( 0x0 ),	/* 0 */
/* 2134 */	NdrFcShort( 0x0 ),	/* 0 */

	/* Parameter Bias_h */

/* 2136 */	NdrFcShort( 0x4113 ),	/* Flags:  must size, must free, out, simple ref, srv alloc size=16 */
/* 2138 */	NdrFcShort( 0x4 ),	/* x86 Stack size/offset = 4 */
/* 2140 */	NdrFcShort( 0x41a ),	/* Type Offset=1050 */

	/* Return value */

/* 2142 */	NdrFcShort( 0x70 ),	/* Flags:  out, return, base type, */
/* 2144 */	NdrFcShort( 0x8 ),	/* x86 Stack size/offset = 8 */
/* 2146 */	0x8,		/* FC_LONG */
			0x0,		/* 0 */

	/* Procedure put_Bias_h */

/* 2148 */	0x33,		/* FC_AUTO_HANDLE */
			0x6c,		/* Old Flags:  object, Oi2 */
/* 2150 */	NdrFcLong( 0x0 ),	/* 0 */
/* 2154 */	NdrFcShort( 0x3c ),	/* 60 */
/* 2156 */	NdrFcShort( 0x18 ),	/* x86 Stack size/offset = 24 */
/* 2158 */	NdrFcShort( 0x0 ),	/* 0 */
/* 2160 */	NdrFcShort( 0x8 ),	/* 8 */
/* 2162 */	0x46,		/* Oi2 Flags:  clt must size, has return, has ext, */
			0x2,		/* 2 */
/* 2164 */	0x8,		/* 8 */
			0x5,		/* Ext Flags:  new corr desc, srv corr check, */
/* 2166 */	NdrFcShort( 0x0 ),	/* 0 */
/* 2168 */	NdrFcShort( 0x9c9 ),	/* 2505 */
/* 2170 */	NdrFcShort( 0x0 ),	/* 0 */

	/* Parameter Bias_h */

/* 2172 */	NdrFcShort( 0x8b ),	/* Flags:  must size, must free, in, by val, */
/* 2174 */	NdrFcShort( 0x4 ),	/* x86 Stack size/offset = 4 */
/* 2176 */	NdrFcShort( 0x428 ),	/* Type Offset=1064 */

	/* Return value */

/* 2178 */	NdrFcShort( 0x70 ),	/* Flags:  out, return, base type, */
/* 2180 */	NdrFcShort( 0x14 ),	/* x86 Stack size/offset = 20 */
/* 2182 */	0x8,		/* FC_LONG */
			0x0,		/* 0 */

	/* Procedure get_CV */

/* 2184 */	0x33,		/* FC_AUTO_HANDLE */
			0x6c,		/* Old Flags:  object, Oi2 */
/* 2186 */	NdrFcLong( 0x0 ),	/* 0 */
/* 2190 */	NdrFcShort( 0x3d ),	/* 61 */
/* 2192 */	NdrFcShort( 0xc ),	/* x86 Stack size/offset = 12 */
/* 2194 */	NdrFcShort( 0x0 ),	/* 0 */
/* 2196 */	NdrFcShort( 0x8 ),	/* 8 */
/* 2198 */	0x45,		/* Oi2 Flags:  srv must size, has return, has ext, */
			0x2,		/* 2 */
/* 2200 */	0x8,		/* 8 */
			0x3,		/* Ext Flags:  new corr desc, clt corr check, */
/* 2202 */	NdrFcShort( 0xa11 ),	/* 2577 */
/* 2204 */	NdrFcShort( 0x0 ),	/* 0 */
/* 2206 */	NdrFcShort( 0x0 ),	/* 0 */

	/* Parameter CV */

/* 2208 */	NdrFcShort( 0x4113 ),	/* Flags:  must size, must free, out, simple ref, srv alloc size=16 */
/* 2210 */	NdrFcShort( 0x4 ),	/* x86 Stack size/offset = 4 */
/* 2212 */	NdrFcShort( 0x41a ),	/* Type Offset=1050 */

	/* Return value */

/* 2214 */	NdrFcShort( 0x70 ),	/* Flags:  out, return, base type, */
/* 2216 */	NdrFcShort( 0x8 ),	/* x86 Stack size/offset = 8 */
/* 2218 */	0x8,		/* FC_LONG */
			0x0,		/* 0 */

	/* Procedure put_CV */

/* 2220 */	0x33,		/* FC_AUTO_HANDLE */
			0x6c,		/* Old Flags:  object, Oi2 */
/* 2222 */	NdrFcLong( 0x0 ),	/* 0 */
/* 2226 */	NdrFcShort( 0x3e ),	/* 62 */
/* 2228 */	NdrFcShort( 0x18 ),	/* x86 Stack size/offset = 24 */
/* 2230 */	NdrFcShort( 0x0 ),	/* 0 */
/* 2232 */	NdrFcShort( 0x8 ),	/* 8 */
/* 2234 */	0x46,		/* Oi2 Flags:  clt must size, has return, has ext, */
			0x2,		/* 2 */
/* 2236 */	0x8,		/* 8 */
			0x5,		/* Ext Flags:  new corr desc, srv corr check, */
/* 2238 */	NdrFcShort( 0x0 ),	/* 0 */
/* 2240 */	NdrFcShort( 0xa5a ),	/* 2650 */
/* 2242 */	NdrFcShort( 0x0 ),	/* 0 */

	/* Parameter CV */

/* 2244 */	NdrFcShort( 0x8b ),	/* Flags:  must size, must free, in, by val, */
/* 2246 */	NdrFcShort( 0x4 ),	/* x86 Stack size/offset = 4 */
/* 2248 */	NdrFcShort( 0x428 ),	/* Type Offset=1064 */

	/* Return value */

/* 2250 */	NdrFcShort( 0x70 ),	/* Flags:  out, return, base type, */
/* 2252 */	NdrFcShort( 0x14 ),	/* x86 Stack size/offset = 20 */
/* 2254 */	0x8,		/* FC_LONG */
			0x0,		/* 0 */

	/* Procedure get_gamaw */

/* 2256 */	0x33,		/* FC_AUTO_HANDLE */
			0x6c,		/* Old Flags:  object, Oi2 */
/* 2258 */	NdrFcLong( 0x0 ),	/* 0 */
/* 2262 */	NdrFcShort( 0x3f ),	/* 63 */
/* 2264 */	NdrFcShort( 0xc ),	/* x86 Stack size/offset = 12 */
/* 2266 */	NdrFcShort( 0x0 ),	/* 0 */
/* 2268 */	NdrFcShort( 0x8 ),	/* 8 */
/* 2270 */	0x45,		/* Oi2 Flags:  srv must size, has return, has ext, */
			0x2,		/* 2 */
/* 2272 */	0x8,		/* 8 */
			0x3,		/* Ext Flags:  new corr desc, clt corr check, */
/* 2274 */	NdrFcShort( 0xaa4 ),	/* 2724 */
/* 2276 */	NdrFcShort( 0x0 ),	/* 0 */
/* 2278 */	NdrFcShort( 0x0 ),	/* 0 */

	/* Parameter gamaw */

/* 2280 */	NdrFcShort( 0x4113 ),	/* Flags:  must size, must free, out, simple ref, srv alloc size=16 */
/* 2282 */	NdrFcShort( 0x4 ),	/* x86 Stack size/offset = 4 */
/* 2284 */	NdrFcShort( 0x41a ),	/* Type Offset=1050 */

	/* Return value */

/* 2286 */	NdrFcShort( 0x70 ),	/* Flags:  out, return, base type, */
/* 2288 */	NdrFcShort( 0x8 ),	/* x86 Stack size/offset = 8 */
/* 2290 */	0x8,		/* FC_LONG */
			0x0,		/* 0 */

	/* Procedure put_gamaw */

/* 2292 */	0x33,		/* FC_AUTO_HANDLE */
			0x6c,		/* Old Flags:  object, Oi2 */
/* 2294 */	NdrFcLong( 0x0 ),	/* 0 */
/* 2298 */	NdrFcShort( 0x40 ),	/* 64 */
/* 2300 */	NdrFcShort( 0x18 ),	/* x86 Stack size/offset = 24 */
/* 2302 */	NdrFcShort( 0x0 ),	/* 0 */
/* 2304 */	NdrFcShort( 0x8 ),	/* 8 */
/* 2306 */	0x46,		/* Oi2 Flags:  clt must size, has return, has ext, */
			0x2,		/* 2 */
/* 2308 */	0x8,		/* 8 */
			0x5,		/* Ext Flags:  new corr desc, srv corr check, */
/* 2310 */	NdrFcShort( 0x0 ),	/* 0 */
/* 2312 */	NdrFcShort( 0xaef ),	/* 2799 */
/* 2314 */	NdrFcShort( 0x0 ),	/* 0 */

	/* Parameter gamaw */

/* 2316 */	NdrFcShort( 0x8b ),	/* Flags:  must size, must free, in, by val, */
/* 2318 */	NdrFcShort( 0x4 ),	/* x86 Stack size/offset = 4 */
/* 2320 */	NdrFcShort( 0x428 ),	/* Type Offset=1064 */

	/* Return value */

/* 2322 */	NdrFcShort( 0x70 ),	/* Flags:  out, return, base type, */
/* 2324 */	NdrFcShort( 0x14 ),	/* x86 Stack size/offset = 20 */
/* 2326 */	0x8,		/* FC_LONG */
			0x0,		/* 0 */

	/* Procedure get_gamal */

/* 2328 */	0x33,		/* FC_AUTO_HANDLE */
			0x6c,		/* Old Flags:  object, Oi2 */
/* 2330 */	NdrFcLong( 0x0 ),	/* 0 */
/* 2334 */	NdrFcShort( 0x41 ),	/* 65 */
/* 2336 */	NdrFcShort( 0xc ),	/* x86 Stack size/offset = 12 */
/* 2338 */	NdrFcShort( 0x0 ),	/* 0 */
/* 2340 */	NdrFcShort( 0x8 ),	/* 8 */
/* 2342 */	0x45,		/* Oi2 Flags:  srv must size, has return, has ext, */
			0x2,		/* 2 */
/* 2344 */	0x8,		/* 8 */
			0x3,		/* Ext Flags:  new corr desc, clt corr check, */
/* 2346 */	NdrFcShort( 0xb3b ),	/* 2875 */
/* 2348 */	NdrFcShort( 0x0 ),	/* 0 */
/* 2350 */	NdrFcShort( 0x0 ),	/* 0 */

	/* Parameter gamal */

/* 2352 */	NdrFcShort( 0x4113 ),	/* Flags:  must size, must free, out, simple ref, srv alloc size=16 */
/* 2354 */	NdrFcShort( 0x4 ),	/* x86 Stack size/offset = 4 */
/* 2356 */	NdrFcShort( 0x41a ),	/* Type Offset=1050 */

	/* Return value */

/* 2358 */	NdrFcShort( 0x70 ),	/* Flags:  out, return, base type, */
/* 2360 */	NdrFcShort( 0x8 ),	/* x86 Stack size/offset = 8 */
/* 2362 */	0x8,		/* FC_LONG */
			0x0,		/* 0 */

	/* Procedure put_gamal */

/* 2364 */	0x33,		/* FC_AUTO_HANDLE */
			0x6c,		/* Old Flags:  object, Oi2 */
/* 2366 */	NdrFcLong( 0x0 ),	/* 0 */
/* 2370 */	NdrFcShort( 0x42 ),	/* 66 */
/* 2372 */	NdrFcShort( 0x18 ),	/* x86 Stack size/offset = 24 */
/* 2374 */	NdrFcShort( 0x0 ),	/* 0 */
/* 2376 */	NdrFcShort( 0x8 ),	/* 8 */
/* 2378 */	0x46,		/* Oi2 Flags:  clt must size, has return, has ext, */
			0x2,		/* 2 */
/* 2380 */	0x8,		/* 8 */
			0x5,		/* Ext Flags:  new corr desc, srv corr check, */
/* 2382 */	NdrFcShort( 0x0 ),	/* 0 */
/* 2384 */	NdrFcShort( 0xb88 ),	/* 2952 */
/* 2386 */	NdrFcShort( 0x0 ),	/* 0 */

	/* Parameter gamal */

/* 2388 */	NdrFcShort( 0x8b ),	/* Flags:  must size, must free, in, by val, */
/* 2390 */	NdrFcShort( 0x4 ),	/* x86 Stack size/offset = 4 */
/* 2392 */	NdrFcShort( 0x428 ),	/* Type Offset=1064 */

	/* Return value */

/* 2394 */	NdrFcShort( 0x70 ),	/* Flags:  out, return, base type, */
/* 2396 */	NdrFcShort( 0x14 ),	/* x86 Stack size/offset = 20 */
/* 2398 */	0x8,		/* FC_LONG */
			0x0,		/* 0 */

	/* Procedure get_Gw */

/* 2400 */	0x33,		/* FC_AUTO_HANDLE */
			0x6c,		/* Old Flags:  object, Oi2 */
/* 2402 */	NdrFcLong( 0x0 ),	/* 0 */
/* 2406 */	NdrFcShort( 0x43 ),	/* 67 */
/* 2408 */	NdrFcShort( 0xc ),	/* x86 Stack size/offset = 12 */
/* 2410 */	NdrFcShort( 0x0 ),	/* 0 */
/* 2412 */	NdrFcShort( 0x8 ),	/* 8 */
/* 2414 */	0x45,		/* Oi2 Flags:  srv must size, has return, has ext, */
			0x2,		/* 2 */
/* 2416 */	0x8,		/* 8 */
			0x3,		/* Ext Flags:  new corr desc, clt corr check, */
/* 2418 */	NdrFcShort( 0xbd6 ),	/* 3030 */
/* 2420 */	NdrFcShort( 0x0 ),	/* 0 */
/* 2422 */	NdrFcShort( 0x0 ),	/* 0 */

	/* Parameter Gw */

/* 2424 */	NdrFcShort( 0x4113 ),	/* Flags:  must size, must free, out, simple ref, srv alloc size=16 */
/* 2426 */	NdrFcShort( 0x4 ),	/* x86 Stack size/offset = 4 */
/* 2428 */	NdrFcShort( 0x41a ),	/* Type Offset=1050 */

	/* Return value */

/* 2430 */	NdrFcShort( 0x70 ),	/* Flags:  out, return, base type, */
/* 2432 */	NdrFcShort( 0x8 ),	/* x86 Stack size/offset = 8 */
/* 2434 */	0x8,		/* FC_LONG */
			0x0,		/* 0 */

	/* Procedure put_Gw */

/* 2436 */	0x33,		/* FC_AUTO_HANDLE */
			0x6c,		/* Old Flags:  object, Oi2 */
/* 2438 */	NdrFcLong( 0x0 ),	/* 0 */
/* 2442 */	NdrFcShort( 0x44 ),	/* 68 */
/* 2444 */	NdrFcShort( 0x18 ),	/* x86 Stack size/offset = 24 */
/* 2446 */	NdrFcShort( 0x0 ),	/* 0 */
/* 2448 */	NdrFcShort( 0x8 ),	/* 8 */
/* 2450 */	0x46,		/* Oi2 Flags:  clt must size, has return, has ext, */
			0x2,		/* 2 */
/* 2452 */	0x8,		/* 8 */
			0x5,		/* Ext Flags:  new corr desc, srv corr check, */
/* 2454 */	NdrFcShort( 0x0 ),	/* 0 */
/* 2456 */	NdrFcShort( 0xc25 ),	/* 3109 */
/* 2458 */	NdrFcShort( 0x0 ),	/* 0 */

	/* Parameter Gw */

/* 2460 */	NdrFcShort( 0x8b ),	/* Flags:  must size, must free, in, by val, */
/* 2462 */	NdrFcShort( 0x4 ),	/* x86 Stack size/offset = 4 */
/* 2464 */	NdrFcShort( 0x428 ),	/* Type Offset=1064 */

	/* Return value */

/* 2466 */	NdrFcShort( 0x70 ),	/* Flags:  out, return, base type, */
/* 2468 */	NdrFcShort( 0x14 ),	/* x86 Stack size/offset = 20 */
/* 2470 */	0x8,		/* FC_LONG */
			0x0,		/* 0 */

	/* Procedure get_Gl */

/* 2472 */	0x33,		/* FC_AUTO_HANDLE */
			0x6c,		/* Old Flags:  object, Oi2 */
/* 2474 */	NdrFcLong( 0x0 ),	/* 0 */
/* 2478 */	NdrFcShort( 0x45 ),	/* 69 */
/* 2480 */	NdrFcShort( 0xc ),	/* x86 Stack size/offset = 12 */
/* 2482 */	NdrFcShort( 0x0 ),	/* 0 */
/* 2484 */	NdrFcShort( 0x8 ),	/* 8 */
/* 2486 */	0x45,		/* Oi2 Flags:  srv must size, has return, has ext, */
			0x2,		/* 2 */
/* 2488 */	0x8,		/* 8 */
			0x3,		/* Ext Flags:  new corr desc, clt corr check, */
/* 2490 */	NdrFcShort( 0xc75 ),	/* 3189 */
/* 2492 */	NdrFcShort( 0x0 ),	/* 0 */
/* 2494 */	NdrFcShort( 0x0 ),	/* 0 */

	/* Parameter Gl */

/* 2496 */	NdrFcShort( 0x4113 ),	/* Flags:  must size, must free, out, simple ref, srv alloc size=16 */
/* 2498 */	NdrFcShort( 0x4 ),	/* x86 Stack size/offset = 4 */
/* 2500 */	NdrFcShort( 0x41a ),	/* Type Offset=1050 */

	/* Return value */

/* 2502 */	NdrFcShort( 0x70 ),	/* Flags:  out, return, base type, */
/* 2504 */	NdrFcShort( 0x8 ),	/* x86 Stack size/offset = 8 */
/* 2506 */	0x8,		/* FC_LONG */
			0x0,		/* 0 */

	/* Procedure put_Gl */

/* 2508 */	0x33,		/* FC_AUTO_HANDLE */
			0x6c,		/* Old Flags:  object, Oi2 */
/* 2510 */	NdrFcLong( 0x0 ),	/* 0 */
/* 2514 */	NdrFcShort( 0x46 ),	/* 70 */
/* 2516 */	NdrFcShort( 0x18 ),	/* x86 Stack size/offset = 24 */
/* 2518 */	NdrFcShort( 0x0 ),	/* 0 */
/* 2520 */	NdrFcShort( 0x8 ),	/* 8 */
/* 2522 */	0x46,		/* Oi2 Flags:  clt must size, has return, has ext, */
			0x2,		/* 2 */
/* 2524 */	0x8,		/* 8 */
			0x5,		/* Ext Flags:  new corr desc, srv corr check, */
/* 2526 */	NdrFcShort( 0x0 ),	/* 0 */
/* 2528 */	NdrFcShort( 0xcc6 ),	/* 3270 */
/* 2530 */	NdrFcShort( 0x0 ),	/* 0 */

	/* Parameter Gl */

/* 2532 */	NdrFcShort( 0x8b ),	/* Flags:  must size, must free, in, by val, */
/* 2534 */	NdrFcShort( 0x4 ),	/* x86 Stack size/offset = 4 */
/* 2536 */	NdrFcShort( 0x428 ),	/* Type Offset=1064 */

	/* Return value */

/* 2538 */	NdrFcShort( 0x70 ),	/* Flags:  out, return, base type, */
/* 2540 */	NdrFcShort( 0x14 ),	/* x86 Stack size/offset = 20 */
/* 2542 */	0x8,		/* FC_LONG */
			0x0,		/* 0 */

	/* Procedure get_Gg */

/* 2544 */	0x33,		/* FC_AUTO_HANDLE */
			0x6c,		/* Old Flags:  object, Oi2 */
/* 2546 */	NdrFcLong( 0x0 ),	/* 0 */
/* 2550 */	NdrFcShort( 0x47 ),	/* 71 */
/* 2552 */	NdrFcShort( 0xc ),	/* x86 Stack size/offset = 12 */
/* 2554 */	NdrFcShort( 0x0 ),	/* 0 */
/* 2556 */	NdrFcShort( 0x8 ),	/* 8 */
/* 2558 */	0x45,		/* Oi2 Flags:  srv must size, has return, has ext, */
			0x2,		/* 2 */
/* 2560 */	0x8,		/* 8 */
			0x3,		/* Ext Flags:  new corr desc, clt corr check, */
/* 2562 */	NdrFcShort( 0xd18 ),	/* 3352 */
/* 2564 */	NdrFcShort( 0x0 ),	/* 0 */
/* 2566 */	NdrFcShort( 0x0 ),	/* 0 */

	/* Parameter Gg */

/* 2568 */	NdrFcShort( 0x4113 ),	/* Flags:  must size, must free, out, simple ref, srv alloc size=16 */
/* 2570 */	NdrFcShort( 0x4 ),	/* x86 Stack size/offset = 4 */
/* 2572 */	NdrFcShort( 0x41a ),	/* Type Offset=1050 */

	/* Return value */

/* 2574 */	NdrFcShort( 0x70 ),	/* Flags:  out, return, base type, */
/* 2576 */	NdrFcShort( 0x8 ),	/* x86 Stack size/offset = 8 */
/* 2578 */	0x8,		/* FC_LONG */
			0x0,		/* 0 */

	/* Procedure put_Gg */

/* 2580 */	0x33,		/* FC_AUTO_HANDLE */
			0x6c,		/* Old Flags:  object, Oi2 */
/* 2582 */	NdrFcLong( 0x0 ),	/* 0 */
/* 2586 */	NdrFcShort( 0x48 ),	/* 72 */
/* 2588 */	NdrFcShort( 0x18 ),	/* x86 Stack size/offset = 24 */
/* 2590 */	NdrFcShort( 0x0 ),	/* 0 */
/* 2592 */	NdrFcShort( 0x8 ),	/* 8 */
/* 2594 */	0x46,		/* Oi2 Flags:  clt must size, has return, has ext, */
			0x2,		/* 2 */
/* 2596 */	0x8,		/* 8 */
			0x5,		/* Ext Flags:  new corr desc, srv corr check, */
/* 2598 */	NdrFcShort( 0x0 ),	/* 0 */
/* 2600 */	NdrFcShort( 0xd6b ),	/* 3435 */
/* 2602 */	NdrFcShort( 0x0 ),	/* 0 */

	/* Parameter Gg */

/* 2604 */	NdrFcShort( 0x8b ),	/* Flags:  must size, must free, in, by val, */
/* 2606 */	NdrFcShort( 0x4 ),	/* x86 Stack size/offset = 4 */
/* 2608 */	NdrFcShort( 0x428 ),	/* Type Offset=1064 */

	/* Return value */

/* 2610 */	NdrFcShort( 0x70 ),	/* Flags:  out, return, base type, */
/* 2612 */	NdrFcShort( 0x14 ),	/* x86 Stack size/offset = 20 */
/* 2614 */	0x8,		/* FC_LONG */
			0x0,		/* 0 */

	/* Procedure get_C */

/* 2616 */	0x33,		/* FC_AUTO_HANDLE */
			0x6c,		/* Old Flags:  object, Oi2 */
/* 2618 */	NdrFcLong( 0x0 ),	/* 0 */
/* 2622 */	NdrFcShort( 0x49 ),	/* 73 */
/* 2624 */	NdrFcShort( 0xc ),	/* x86 Stack size/offset = 12 */
/* 2626 */	NdrFcShort( 0x0 ),	/* 0 */
/* 2628 */	NdrFcShort( 0x8 ),	/* 8 */
/* 2630 */	0x45,		/* Oi2 Flags:  srv must size, has return, has ext, */
			0x2,		/* 2 */
/* 2632 */	0x8,		/* 8 */
			0x3,		/* Ext Flags:  new corr desc, clt corr check, */
/* 2634 */	NdrFcShort( 0xdbf ),	/* 3519 */
/* 2636 */	NdrFcShort( 0x0 ),	/* 0 */
/* 2638 */	NdrFcShort( 0x0 ),	/* 0 */

	/* Parameter C */

/* 2640 */	NdrFcShort( 0x4113 ),	/* Flags:  must size, must free, out, simple ref, srv alloc size=16 */
/* 2642 */	NdrFcShort( 0x4 ),	/* x86 Stack size/offset = 4 */
/* 2644 */	NdrFcShort( 0x41a ),	/* Type Offset=1050 */

	/* Return value */

/* 2646 */	NdrFcShort( 0x70 ),	/* Flags:  out, return, base type, */
/* 2648 */	NdrFcShort( 0x8 ),	/* x86 Stack size/offset = 8 */
/* 2650 */	0x8,		/* FC_LONG */
			0x0,		/* 0 */

	/* Procedure put_C */

/* 2652 */	0x33,		/* FC_AUTO_HANDLE */
			0x6c,		/* Old Flags:  object, Oi2 */
/* 2654 */	NdrFcLong( 0x0 ),	/* 0 */
/* 2658 */	NdrFcShort( 0x4a ),	/* 74 */
/* 2660 */	NdrFcShort( 0x18 ),	/* x86 Stack size/offset = 24 */
/* 2662 */	NdrFcShort( 0x0 ),	/* 0 */
/* 2664 */	NdrFcShort( 0x8 ),	/* 8 */
/* 2666 */	0x46,		/* Oi2 Flags:  clt must size, has return, has ext, */
			0x2,		/* 2 */
/* 2668 */	0x8,		/* 8 */
			0x5,		/* Ext Flags:  new corr desc, srv corr check, */
/* 2670 */	NdrFcShort( 0x0 ),	/* 0 */
/* 2672 */	NdrFcShort( 0xe14 ),	/* 3604 */
/* 2674 */	NdrFcShort( 0x0 ),	/* 0 */

	/* Parameter C */

/* 2676 */	NdrFcShort( 0x8b ),	/* Flags:  must size, must free, in, by val, */
/* 2678 */	NdrFcShort( 0x4 ),	/* x86 Stack size/offset = 4 */
/* 2680 */	NdrFcShort( 0x428 ),	/* Type Offset=1064 */

	/* Return value */

/* 2682 */	NdrFcShort( 0x70 ),	/* Flags:  out, return, base type, */
/* 2684 */	NdrFcShort( 0x14 ),	/* x86 Stack size/offset = 20 */
/* 2686 */	0x8,		/* FC_LONG */
			0x0,		/* 0 */

	/* Procedure get_D */

/* 2688 */	0x33,		/* FC_AUTO_HANDLE */
			0x6c,		/* Old Flags:  object, Oi2 */
/* 2690 */	NdrFcLong( 0x0 ),	/* 0 */
/* 2694 */	NdrFcShort( 0x4b ),	/* 75 */
/* 2696 */	NdrFcShort( 0xc ),	/* x86 Stack size/offset = 12 */
/* 2698 */	NdrFcShort( 0x0 ),	/* 0 */
/* 2700 */	NdrFcShort( 0x8 ),	/* 8 */
/* 2702 */	0x45,		/* Oi2 Flags:  srv must size, has return, has ext, */
			0x2,		/* 2 */
/* 2704 */	0x8,		/* 8 */
			0x3,		/* Ext Flags:  new corr desc, clt corr check, */
/* 2706 */	NdrFcShort( 0xe6a ),	/* 3690 */
/* 2708 */	NdrFcShort( 0x0 ),	/* 0 */
/* 2710 */	NdrFcShort( 0x0 ),	/* 0 */

	/* Parameter D */

/* 2712 */	NdrFcShort( 0x4113 ),	/* Flags:  must size, must free, out, simple ref, srv alloc size=16 */
/* 2714 */	NdrFcShort( 0x4 ),	/* x86 Stack size/offset = 4 */
/* 2716 */	NdrFcShort( 0x41a ),	/* Type Offset=1050 */

	/* Return value */

/* 2718 */	NdrFcShort( 0x70 ),	/* Flags:  out, return, base type, */
/* 2720 */	NdrFcShort( 0x8 ),	/* x86 Stack size/offset = 8 */
/* 2722 */	0x8,		/* FC_LONG */
			0x0,		/* 0 */

	/* Procedure put_D */

/* 2724 */	0x33,		/* FC_AUTO_HANDLE */
			0x6c,		/* Old Flags:  object, Oi2 */
/* 2726 */	NdrFcLong( 0x0 ),	/* 0 */
/* 2730 */	NdrFcShort( 0x4c ),	/* 76 */
/* 2732 */	NdrFcShort( 0x18 ),	/* x86 Stack size/offset = 24 */
/* 2734 */	NdrFcShort( 0x0 ),	/* 0 */
/* 2736 */	NdrFcShort( 0x8 ),	/* 8 */
/* 2738 */	0x46,		/* Oi2 Flags:  clt must size, has return, has ext, */
			0x2,		/* 2 */
/* 2740 */	0x8,		/* 8 */
			0x5,		/* Ext Flags:  new corr desc, srv corr check, */
/* 2742 */	NdrFcShort( 0x0 ),	/* 0 */
/* 2744 */	NdrFcShort( 0xec1 ),	/* 3777 */
/* 2746 */	NdrFcShort( 0x0 ),	/* 0 */

	/* Parameter D */

/* 2748 */	NdrFcShort( 0x8b ),	/* Flags:  must size, must free, in, by val, */
/* 2750 */	NdrFcShort( 0x4 ),	/* x86 Stack size/offset = 4 */
/* 2752 */	NdrFcShort( 0x428 ),	/* Type Offset=1064 */

	/* Return value */

/* 2754 */	NdrFcShort( 0x70 ),	/* Flags:  out, return, base type, */
/* 2756 */	NdrFcShort( 0x14 ),	/* x86 Stack size/offset = 20 */
/* 2758 */	0x8,		/* FC_LONG */
			0x0,		/* 0 */

	/* Procedure get_u0_in1 */

/* 2760 */	0x33,		/* FC_AUTO_HANDLE */
			0x6c,		/* Old Flags:  object, Oi2 */
/* 2762 */	NdrFcLong( 0x0 ),	/* 0 */
/* 2766 */	NdrFcShort( 0x4d ),	/* 77 */
/* 2768 */	NdrFcShort( 0xc ),	/* x86 Stack size/offset = 12 */
/* 2770 */	NdrFcShort( 0x0 ),	/* 0 */
/* 2772 */	NdrFcShort( 0x8 ),	/* 8 */
/* 2774 */	0x45,		/* Oi2 Flags:  srv must size, has return, has ext, */
			0x2,		/* 2 */
/* 2776 */	0x8,		/* 8 */
			0x3,		/* Ext Flags:  new corr desc, clt corr check, */
/* 2778 */	NdrFcShort( 0xf19 ),	/* 3865 */
/* 2780 */	NdrFcShort( 0x0 ),	/* 0 */
/* 2782 */	NdrFcShort( 0x0 ),	/* 0 */

	/* Parameter u0_in1 */

/* 2784 */	NdrFcShort( 0x4113 ),	/* Flags:  must size, must free, out, simple ref, srv alloc size=16 */
/* 2786 */	NdrFcShort( 0x4 ),	/* x86 Stack size/offset = 4 */
/* 2788 */	NdrFcShort( 0x41a ),	/* Type Offset=1050 */

	/* Return value */

/* 2790 */	NdrFcShort( 0x70 ),	/* Flags:  out, return, base type, */
/* 2792 */	NdrFcShort( 0x8 ),	/* x86 Stack size/offset = 8 */
/* 2794 */	0x8,		/* FC_LONG */
			0x0,		/* 0 */

	/* Procedure put_u0_in1 */

/* 2796 */	0x33,		/* FC_AUTO_HANDLE */
			0x6c,		/* Old Flags:  object, Oi2 */
/* 2798 */	NdrFcLong( 0x0 ),	/* 0 */
/* 2802 */	NdrFcShort( 0x4e ),	/* 78 */
/* 2804 */	NdrFcShort( 0x18 ),	/* x86 Stack size/offset = 24 */
/* 2806 */	NdrFcShort( 0x0 ),	/* 0 */
/* 2808 */	NdrFcShort( 0x8 ),	/* 8 */
/* 2810 */	0x46,		/* Oi2 Flags:  clt must size, has return, has ext, */
			0x2,		/* 2 */
/* 2812 */	0x8,		/* 8 */
			0x5,		/* Ext Flags:  new corr desc, srv corr check, */
/* 2814 */	NdrFcShort( 0x0 ),	/* 0 */
/* 2816 */	NdrFcShort( 0xf72 ),	/* 3954 */
/* 2818 */	NdrFcShort( 0x0 ),	/* 0 */

	/* Parameter u0_in1 */

/* 2820 */	NdrFcShort( 0x8b ),	/* Flags:  must size, must free, in, by val, */
/* 2822 */	NdrFcShort( 0x4 ),	/* x86 Stack size/offset = 4 */
/* 2824 */	NdrFcShort( 0x428 ),	/* Type Offset=1064 */

	/* Return value */

/* 2826 */	NdrFcShort( 0x70 ),	/* Flags:  out, return, base type, */
/* 2828 */	NdrFcShort( 0x14 ),	/* x86 Stack size/offset = 20 */
/* 2830 */	0x8,		/* FC_LONG */
			0x0,		/* 0 */

	/* Procedure get_xk_1_in1 */

/* 2832 */	0x33,		/* FC_AUTO_HANDLE */
			0x6c,		/* Old Flags:  object, Oi2 */
/* 2834 */	NdrFcLong( 0x0 ),	/* 0 */
/* 2838 */	NdrFcShort( 0x4f ),	/* 79 */
/* 2840 */	NdrFcShort( 0xc ),	/* x86 Stack size/offset = 12 */
/* 2842 */	NdrFcShort( 0x0 ),	/* 0 */
/* 2844 */	NdrFcShort( 0x8 ),	/* 8 */
/* 2846 */	0x45,		/* Oi2 Flags:  srv must size, has return, has ext, */
			0x2,		/* 2 */
/* 2848 */	0x8,		/* 8 */
			0x3,		/* Ext Flags:  new corr desc, clt corr check, */
/* 2850 */	NdrFcShort( 0xfcc ),	/* 4044 */
/* 2852 */	NdrFcShort( 0x0 ),	/* 0 */
/* 2854 */	NdrFcShort( 0x0 ),	/* 0 */

	/* Parameter xk_1_in1 */

/* 2856 */	NdrFcShort( 0x4113 ),	/* Flags:  must size, must free, out, simple ref, srv alloc size=16 */
/* 2858 */	NdrFcShort( 0x4 ),	/* x86 Stack size/offset = 4 */
/* 2860 */	NdrFcShort( 0x41a ),	/* Type Offset=1050 */

	/* Return value */

/* 2862 */	NdrFcShort( 0x70 ),	/* Flags:  out, return, base type, */
/* 2864 */	NdrFcShort( 0x8 ),	/* x86 Stack size/offset = 8 */
/* 2866 */	0x8,		/* FC_LONG */
			0x0,		/* 0 */

	/* Procedure put_xk_1_in1 */

/* 2868 */	0x33,		/* FC_AUTO_HANDLE */
			0x6c,		/* Old Flags:  object, Oi2 */
/* 2870 */	NdrFcLong( 0x0 ),	/* 0 */
/* 2874 */	NdrFcShort( 0x50 ),	/* 80 */
/* 2876 */	NdrFcShort( 0x18 ),	/* x86 Stack size/offset = 24 */
/* 2878 */	NdrFcShort( 0x0 ),	/* 0 */
/* 2880 */	NdrFcShort( 0x8 ),	/* 8 */
/* 2882 */	0x46,		/* Oi2 Flags:  clt must size, has return, has ext, */
			0x2,		/* 2 */
/* 2884 */	0x8,		/* 8 */
			0x5,		/* Ext Flags:  new corr desc, srv corr check, */
/* 2886 */	NdrFcShort( 0x0 ),	/* 0 */
/* 2888 */	NdrFcShort( 0x1027 ),	/* 4135 */
/* 2890 */	NdrFcShort( 0x0 ),	/* 0 */

	/* Parameter xk_1_in1 */

/* 2892 */	NdrFcShort( 0x8b ),	/* Flags:  must size, must free, in, by val, */
/* 2894 */	NdrFcShort( 0x4 ),	/* x86 Stack size/offset = 4 */
/* 2896 */	NdrFcShort( 0x428 ),	/* Type Offset=1064 */

	/* Return value */

/* 2898 */	NdrFcShort( 0x70 ),	/* Flags:  out, return, base type, */
/* 2900 */	NdrFcShort( 0x14 ),	/* x86 Stack size/offset = 20 */
/* 2902 */	0x8,		/* FC_LONG */
			0x0,		/* 0 */

	/* Procedure get_Fo_in1 */

/* 2904 */	0x33,		/* FC_AUTO_HANDLE */
			0x6c,		/* Old Flags:  object, Oi2 */
/* 2906 */	NdrFcLong( 0x0 ),	/* 0 */
/* 2910 */	NdrFcShort( 0x51 ),	/* 81 */
/* 2912 */	NdrFcShort( 0xc ),	/* x86 Stack size/offset = 12 */
/* 2914 */	NdrFcShort( 0x0 ),	/* 0 */
/* 2916 */	NdrFcShort( 0x8 ),	/* 8 */
/* 2918 */	0x45,		/* Oi2 Flags:  srv must size, has return, has ext, */
			0x2,		/* 2 */
/* 2920 */	0x8,		/* 8 */
			0x3,		/* Ext Flags:  new corr desc, clt corr check, */
/* 2922 */	NdrFcShort( 0x1083 ),	/* 4227 */
/* 2924 */	NdrFcShort( 0x0 ),	/* 0 */
/* 2926 */	NdrFcShort( 0x0 ),	/* 0 */

	/* Parameter Fo_in1 */

/* 2928 */	NdrFcShort( 0x4113 ),	/* Flags:  must size, must free, out, simple ref, srv alloc size=16 */
/* 2930 */	NdrFcShort( 0x4 ),	/* x86 Stack size/offset = 4 */
/* 2932 */	NdrFcShort( 0x41a ),	/* Type Offset=1050 */

	/* Return value */

/* 2934 */	NdrFcShort( 0x70 ),	/* Flags:  out, return, base type, */
/* 2936 */	NdrFcShort( 0x8 ),	/* x86 Stack size/offset = 8 */
/* 2938 */	0x8,		/* FC_LONG */
			0x0,		/* 0 */

	/* Procedure put_Fo_in1 */

/* 2940 */	0x33,		/* FC_AUTO_HANDLE */
			0x6c,		/* Old Flags:  object, Oi2 */
/* 2942 */	NdrFcLong( 0x0 ),	/* 0 */
/* 2946 */	NdrFcShort( 0x52 ),	/* 82 */
/* 2948 */	NdrFcShort( 0x18 ),	/* x86 Stack size/offset = 24 */
/* 2950 */	NdrFcShort( 0x0 ),	/* 0 */
/* 2952 */	NdrFcShort( 0x8 ),	/* 8 */
/* 2954 */	0x46,		/* Oi2 Flags:  clt must size, has return, has ext, */
			0x2,		/* 2 */
/* 2956 */	0x8,		/* 8 */
			0x5,		/* Ext Flags:  new corr desc, srv corr check, */
/* 2958 */	NdrFcShort( 0x0 ),	/* 0 */
/* 2960 */	NdrFcShort( 0x10e0 ),	/* 4320 */
/* 2962 */	NdrFcShort( 0x0 ),	/* 0 */

	/* Parameter Fo_in1 */

/* 2964 */	NdrFcShort( 0x8b ),	/* Flags:  must size, must free, in, by val, */
/* 2966 */	NdrFcShort( 0x4 ),	/* x86 Stack size/offset = 4 */
/* 2968 */	NdrFcShort( 0x428 ),	/* Type Offset=1064 */

	/* Return value */

/* 2970 */	NdrFcShort( 0x70 ),	/* Flags:  out, return, base type, */
/* 2972 */	NdrFcShort( 0x14 ),	/* x86 Stack size/offset = 20 */
/* 2974 */	0x8,		/* FC_LONG */
			0x0,		/* 0 */

	/* Procedure get_ParametrosForaDaFaixa_in1 */

/* 2976 */	0x33,		/* FC_AUTO_HANDLE */
			0x6c,		/* Old Flags:  object, Oi2 */
/* 2978 */	NdrFcLong( 0x0 ),	/* 0 */
/* 2982 */	NdrFcShort( 0x53 ),	/* 83 */
/* 2984 */	NdrFcShort( 0xc ),	/* x86 Stack size/offset = 12 */
/* 2986 */	NdrFcShort( 0x0 ),	/* 0 */
/* 2988 */	NdrFcShort( 0x8 ),	/* 8 */
/* 2990 */	0x45,		/* Oi2 Flags:  srv must size, has return, has ext, */
			0x2,		/* 2 */
/* 2992 */	0x8,		/* 8 */
			0x3,		/* Ext Flags:  new corr desc, clt corr check, */
/* 2994 */	NdrFcShort( 0x113e ),	/* 4414 */
/* 2996 */	NdrFcShort( 0x0 ),	/* 0 */
/* 2998 */	NdrFcShort( 0x0 ),	/* 0 */

	/* Parameter ParametrosForaDaFaixa_in1 */

/* 3000 */	NdrFcShort( 0x4113 ),	/* Flags:  must size, must free, out, simple ref, srv alloc size=16 */
/* 3002 */	NdrFcShort( 0x4 ),	/* x86 Stack size/offset = 4 */
/* 3004 */	NdrFcShort( 0x41a ),	/* Type Offset=1050 */

	/* Return value */

/* 3006 */	NdrFcShort( 0x70 ),	/* Flags:  out, return, base type, */
/* 3008 */	NdrFcShort( 0x8 ),	/* x86 Stack size/offset = 8 */
/* 3010 */	0x8,		/* FC_LONG */
			0x0,		/* 0 */

	/* Procedure put_ParametrosForaDaFaixa_in1 */

/* 3012 */	0x33,		/* FC_AUTO_HANDLE */
			0x6c,		/* Old Flags:  object, Oi2 */
/* 3014 */	NdrFcLong( 0x0 ),	/* 0 */
/* 3018 */	NdrFcShort( 0x54 ),	/* 84 */
/* 3020 */	NdrFcShort( 0x18 ),	/* x86 Stack size/offset = 24 */
/* 3022 */	NdrFcShort( 0x0 ),	/* 0 */
/* 3024 */	NdrFcShort( 0x8 ),	/* 8 */
/* 3026 */	0x46,		/* Oi2 Flags:  clt must size, has return, has ext, */
			0x2,		/* 2 */
/* 3028 */	0x8,		/* 8 */
			0x5,		/* Ext Flags:  new corr desc, srv corr check, */
/* 3030 */	NdrFcShort( 0x0 ),	/* 0 */
/* 3032 */	NdrFcShort( 0x119d ),	/* 4509 */
/* 3034 */	NdrFcShort( 0x0 ),	/* 0 */

	/* Parameter ParametrosForaDaFaixa_in1 */

/* 3036 */	NdrFcShort( 0x8b ),	/* Flags:  must size, must free, in, by val, */
/* 3038 */	NdrFcShort( 0x4 ),	/* x86 Stack size/offset = 4 */
/* 3040 */	NdrFcShort( 0x428 ),	/* Type Offset=1064 */

	/* Return value */

/* 3042 */	NdrFcShort( 0x70 ),	/* Flags:  out, return, base type, */
/* 3044 */	NdrFcShort( 0x14 ),	/* x86 Stack size/offset = 20 */
/* 3046 */	0x8,		/* FC_LONG */
			0x0,		/* 0 */

	/* Procedure get_h_atual */

/* 3048 */	0x33,		/* FC_AUTO_HANDLE */
			0x6c,		/* Old Flags:  object, Oi2 */
/* 3050 */	NdrFcLong( 0x0 ),	/* 0 */
/* 3054 */	NdrFcShort( 0x55 ),	/* 85 */
/* 3056 */	NdrFcShort( 0xc ),	/* x86 Stack size/offset = 12 */
/* 3058 */	NdrFcShort( 0x0 ),	/* 0 */
/* 3060 */	NdrFcShort( 0x8 ),	/* 8 */
/* 3062 */	0x45,		/* Oi2 Flags:  srv must size, has return, has ext, */
			0x2,		/* 2 */
/* 3064 */	0x8,		/* 8 */
			0x3,		/* Ext Flags:  new corr desc, clt corr check, */
/* 3066 */	NdrFcShort( 0x11fd ),	/* 4605 */
/* 3068 */	NdrFcShort( 0x0 ),	/* 0 */
/* 3070 */	NdrFcShort( 0x0 ),	/* 0 */

	/* Parameter h_atual */

/* 3072 */	NdrFcShort( 0x4113 ),	/* Flags:  must size, must free, out, simple ref, srv alloc size=16 */
/* 3074 */	NdrFcShort( 0x4 ),	/* x86 Stack size/offset = 4 */
/* 3076 */	NdrFcShort( 0x41a ),	/* Type Offset=1050 */

	/* Return value */

/* 3078 */	NdrFcShort( 0x70 ),	/* Flags:  out, return, base type, */
/* 3080 */	NdrFcShort( 0x8 ),	/* x86 Stack size/offset = 8 */
/* 3082 */	0x8,		/* FC_LONG */
			0x0,		/* 0 */

	/* Procedure put_h_atual */

/* 3084 */	0x33,		/* FC_AUTO_HANDLE */
			0x6c,		/* Old Flags:  object, Oi2 */
/* 3086 */	NdrFcLong( 0x0 ),	/* 0 */
/* 3090 */	NdrFcShort( 0x56 ),	/* 86 */
/* 3092 */	NdrFcShort( 0x18 ),	/* x86 Stack size/offset = 24 */
/* 3094 */	NdrFcShort( 0x0 ),	/* 0 */
/* 3096 */	NdrFcShort( 0x8 ),	/* 8 */
/* 3098 */	0x46,		/* Oi2 Flags:  clt must size, has return, has ext, */
			0x2,		/* 2 */
/* 3100 */	0x8,		/* 8 */
			0x5,		/* Ext Flags:  new corr desc, srv corr check, */
/* 3102 */	NdrFcShort( 0x0 ),	/* 0 */
/* 3104 */	NdrFcShort( 0x125e ),	/* 4702 */
/* 3106 */	NdrFcShort( 0x0 ),	/* 0 */

	/* Parameter h_atual */

/* 3108 */	NdrFcShort( 0x8b ),	/* Flags:  must size, must free, in, by val, */
/* 3110 */	NdrFcShort( 0x4 ),	/* x86 Stack size/offset = 4 */
/* 3112 */	NdrFcShort( 0x428 ),	/* Type Offset=1064 */

	/* Return value */

/* 3114 */	NdrFcShort( 0x70 ),	/* Flags:  out, return, base type, */
/* 3116 */	NdrFcShort( 0x14 ),	/* x86 Stack size/offset = 20 */
/* 3118 */	0x8,		/* FC_LONG */
			0x0,		/* 0 */

	/* Procedure get_h_passado_in1 */

/* 3120 */	0x33,		/* FC_AUTO_HANDLE */
			0x6c,		/* Old Flags:  object, Oi2 */
/* 3122 */	NdrFcLong( 0x0 ),	/* 0 */
/* 3126 */	NdrFcShort( 0x57 ),	/* 87 */
/* 3128 */	NdrFcShort( 0xc ),	/* x86 Stack size/offset = 12 */
/* 3130 */	NdrFcShort( 0x0 ),	/* 0 */
/* 3132 */	NdrFcShort( 0x8 ),	/* 8 */
/* 3134 */	0x45,		/* Oi2 Flags:  srv must size, has return, has ext, */
			0x2,		/* 2 */
/* 3136 */	0x8,		/* 8 */
			0x3,		/* Ext Flags:  new corr desc, clt corr check, */
/* 3138 */	NdrFcShort( 0x12c0 ),	/* 4800 */
/* 3140 */	NdrFcShort( 0x0 ),	/* 0 */
/* 3142 */	NdrFcShort( 0x0 ),	/* 0 */

	/* Parameter h_passado_in1 */

/* 3144 */	NdrFcShort( 0x4113 ),	/* Flags:  must size, must free, out, simple ref, srv alloc size=16 */
/* 3146 */	NdrFcShort( 0x4 ),	/* x86 Stack size/offset = 4 */
/* 3148 */	NdrFcShort( 0x41a ),	/* Type Offset=1050 */

	/* Return value */

/* 3150 */	NdrFcShort( 0x70 ),	/* Flags:  out, return, base type, */
/* 3152 */	NdrFcShort( 0x8 ),	/* x86 Stack size/offset = 8 */
/* 3154 */	0x8,		/* FC_LONG */
			0x0,		/* 0 */

	/* Procedure put_h_passado_in1 */

/* 3156 */	0x33,		/* FC_AUTO_HANDLE */
			0x6c,		/* Old Flags:  object, Oi2 */
/* 3158 */	NdrFcLong( 0x0 ),	/* 0 */
/* 3162 */	NdrFcShort( 0x58 ),	/* 88 */
/* 3164 */	NdrFcShort( 0x18 ),	/* x86 Stack size/offset = 24 */
/* 3166 */	NdrFcShort( 0x0 ),	/* 0 */
/* 3168 */	NdrFcShort( 0x8 ),	/* 8 */
/* 3170 */	0x46,		/* Oi2 Flags:  clt must size, has return, has ext, */
			0x2,		/* 2 */
/* 3172 */	0x8,		/* 8 */
			0x5,		/* Ext Flags:  new corr desc, srv corr check, */
/* 3174 */	NdrFcShort( 0x0 ),	/* 0 */
/* 3176 */	NdrFcShort( 0x1323 ),	/* 4899 */
/* 3178 */	NdrFcShort( 0x0 ),	/* 0 */

	/* Parameter h_passado_in1 */

/* 3180 */	NdrFcShort( 0x8b ),	/* Flags:  must size, must free, in, by val, */
/* 3182 */	NdrFcShort( 0x4 ),	/* x86 Stack size/offset = 4 */
/* 3184 */	NdrFcShort( 0x428 ),	/* Type Offset=1064 */

	/* Return value */

/* 3186 */	NdrFcShort( 0x70 ),	/* Flags:  out, return, base type, */
/* 3188 */	NdrFcShort( 0x14 ),	/* x86 Stack size/offset = 20 */
/* 3190 */	0x8,		/* FC_LONG */
			0x0,		/* 0 */

	/* Procedure get_Pvaso */

/* 3192 */	0x33,		/* FC_AUTO_HANDLE */
			0x6c,		/* Old Flags:  object, Oi2 */
/* 3194 */	NdrFcLong( 0x0 ),	/* 0 */
/* 3198 */	NdrFcShort( 0x59 ),	/* 89 */
/* 3200 */	NdrFcShort( 0xc ),	/* x86 Stack size/offset = 12 */
/* 3202 */	NdrFcShort( 0x0 ),	/* 0 */
/* 3204 */	NdrFcShort( 0x8 ),	/* 8 */
/* 3206 */	0x45,		/* Oi2 Flags:  srv must size, has return, has ext, */
			0x2,		/* 2 */
/* 3208 */	0x8,		/* 8 */
			0x3,		/* Ext Flags:  new corr desc, clt corr check, */
/* 3210 */	NdrFcShort( 0x1387 ),	/* 4999 */
/* 3212 */	NdrFcShort( 0x0 ),	/* 0 */
/* 3214 */	NdrFcShort( 0x0 ),	/* 0 */

	/* Parameter Pvaso */

/* 3216 */	NdrFcShort( 0x4113 ),	/* Flags:  must size, must free, out, simple ref, srv alloc size=16 */
/* 3218 */	NdrFcShort( 0x4 ),	/* x86 Stack size/offset = 4 */
/* 3220 */	NdrFcShort( 0x41a ),	/* Type Offset=1050 */

	/* Return value */

/* 3222 */	NdrFcShort( 0x70 ),	/* Flags:  out, return, base type, */
/* 3224 */	NdrFcShort( 0x8 ),	/* x86 Stack size/offset = 8 */
/* 3226 */	0x8,		/* FC_LONG */
			0x0,		/* 0 */

	/* Procedure put_Pvaso */

/* 3228 */	0x33,		/* FC_AUTO_HANDLE */
			0x6c,		/* Old Flags:  object, Oi2 */
/* 3230 */	NdrFcLong( 0x0 ),	/* 0 */
/* 3234 */	NdrFcShort( 0x5a ),	/* 90 */
/* 3236 */	NdrFcShort( 0x18 ),	/* x86 Stack size/offset = 24 */
/* 3238 */	NdrFcShort( 0x0 ),	/* 0 */
/* 3240 */	NdrFcShort( 0x8 ),	/* 8 */
/* 3242 */	0x46,		/* Oi2 Flags:  clt must size, has return, has ext, */
			0x2,		/* 2 */
/* 3244 */	0x8,		/* 8 */
			0x5,		/* Ext Flags:  new corr desc, srv corr check, */
/* 3246 */	NdrFcShort( 0x0 ),	/* 0 */
/* 3248 */	NdrFcShort( 0x13ec ),	/* 5100 */
/* 3250 */	NdrFcShort( 0x0 ),	/* 0 */

	/* Parameter Pvaso */

/* 3252 */	NdrFcShort( 0x8b ),	/* Flags:  must size, must free, in, by val, */
/* 3254 */	NdrFcShort( 0x4 ),	/* x86 Stack size/offset = 4 */
/* 3256 */	NdrFcShort( 0x428 ),	/* Type Offset=1064 */

	/* Return value */

/* 3258 */	NdrFcShort( 0x70 ),	/* Flags:  out, return, base type, */
/* 3260 */	NdrFcShort( 0x14 ),	/* x86 Stack size/offset = 20 */
/* 3262 */	0x8,		/* FC_LONG */
			0x0,		/* 0 */

	/* Procedure get_Pjus */

/* 3264 */	0x33,		/* FC_AUTO_HANDLE */
			0x6c,		/* Old Flags:  object, Oi2 */
/* 3266 */	NdrFcLong( 0x0 ),	/* 0 */
/* 3270 */	NdrFcShort( 0x5b ),	/* 91 */
/* 3272 */	NdrFcShort( 0xc ),	/* x86 Stack size/offset = 12 */
/* 3274 */	NdrFcShort( 0x0 ),	/* 0 */
/* 3276 */	NdrFcShort( 0x8 ),	/* 8 */
/* 3278 */	0x45,		/* Oi2 Flags:  srv must size, has return, has ext, */
			0x2,		/* 2 */
/* 3280 */	0x8,		/* 8 */
			0x3,		/* Ext Flags:  new corr desc, clt corr check, */
/* 3282 */	NdrFcShort( 0x1452 ),	/* 5202 */
/* 3284 */	NdrFcShort( 0x0 ),	/* 0 */
/* 3286 */	NdrFcShort( 0x0 ),	/* 0 */

	/* Parameter Pjus */

/* 3288 */	NdrFcShort( 0x4113 ),	/* Flags:  must size, must free, out, simple ref, srv alloc size=16 */
/* 3290 */	NdrFcShort( 0x4 ),	/* x86 Stack size/offset = 4 */
/* 3292 */	NdrFcShort( 0x41a ),	/* Type Offset=1050 */

	/* Return value */

/* 3294 */	NdrFcShort( 0x70 ),	/* Flags:  out, return, base type, */
/* 3296 */	NdrFcShort( 0x8 ),	/* x86 Stack size/offset = 8 */
/* 3298 */	0x8,		/* FC_LONG */
			0x0,		/* 0 */

	/* Procedure put_Pjus */

/* 3300 */	0x33,		/* FC_AUTO_HANDLE */
			0x6c,		/* Old Flags:  object, Oi2 */
/* 3302 */	NdrFcLong( 0x0 ),	/* 0 */
/* 3306 */	NdrFcShort( 0x5c ),	/* 92 */
/* 3308 */	NdrFcShort( 0x18 ),	/* x86 Stack size/offset = 24 */
/* 3310 */	NdrFcShort( 0x0 ),	/* 0 */
/* 3312 */	NdrFcShort( 0x8 ),	/* 8 */
/* 3314 */	0x46,		/* Oi2 Flags:  clt must size, has return, has ext, */
			0x2,		/* 2 */
/* 3316 */	0x8,		/* 8 */
			0x5,		/* Ext Flags:  new corr desc, srv corr check, */
/* 3318 */	NdrFcShort( 0x0 ),	/* 0 */
/* 3320 */	NdrFcShort( 0x14b9 ),	/* 5305 */
/* 3322 */	NdrFcShort( 0x0 ),	/* 0 */

	/* Parameter Pjus */

/* 3324 */	NdrFcShort( 0x8b ),	/* Flags:  must size, must free, in, by val, */
/* 3326 */	NdrFcShort( 0x4 ),	/* x86 Stack size/offset = 4 */
/* 3328 */	NdrFcShort( 0x428 ),	/* Type Offset=1064 */

	/* Return value */

/* 3330 */	NdrFcShort( 0x70 ),	/* Flags:  out, return, base type, */
/* 3332 */	NdrFcShort( 0x14 ),	/* x86 Stack size/offset = 20 */
/* 3334 */	0x8,		/* FC_LONG */
			0x0,		/* 0 */

			0x0
        }
    };

static const MPC_Bifasico_dll_idl_MIDL_TYPE_FORMAT_STRING MPC_Bifasico_dll_idl__MIDL_TypeFormatString =
    {
        0,
        {
			NdrFcShort( 0x0 ),	/* 0 */
/*  2 */	
			0x11, 0x10,	/* FC_RP [pointer_deref] */
/*  4 */	NdrFcShort( 0x2 ),	/* Offset= 2 (6) */
/*  6 */	
			0x2f,		/* FC_IP */
			0x5a,		/* FC_CONSTANT_IID */
/*  8 */	NdrFcLong( 0xa295776 ),	/* 170481526 */
/* 12 */	NdrFcShort( 0x23a1 ),	/* 9121 */
/* 14 */	NdrFcShort( 0x410a ),	/* 16650 */
/* 16 */	0x94,		/* 148 */
			0xbd,		/* 189 */
/* 18 */	0xc,		/* 12 */
			0x6c,		/* 108 */
/* 20 */	0x61,		/* 97 */
			0xb8,		/* 184 */
/* 22 */	0x91,		/* 145 */
			0xb7,		/* 183 */
/* 24 */	
			0x11, 0x0,	/* FC_RP */
/* 26 */	NdrFcShort( 0x400 ),	/* Offset= 1024 (1050) */
/* 28 */	
			0x13, 0x0,	/* FC_OP */
/* 30 */	NdrFcShort( 0x3e8 ),	/* Offset= 1000 (1030) */
/* 32 */	
			0x2b,		/* FC_NON_ENCAPSULATED_UNION */
			0x9,		/* FC_ULONG */
/* 34 */	0x7,		/* Corr desc: FC_USHORT */
			0x0,		/*  */
/* 36 */	NdrFcShort( 0xfff8 ),	/* -8 */
/* 38 */	NdrFcShort( 0x1 ),	/* Corr flags:  early, */
/* 40 */	NdrFcShort( 0x2 ),	/* Offset= 2 (42) */
/* 42 */	NdrFcShort( 0x10 ),	/* 16 */
/* 44 */	NdrFcShort( 0x2f ),	/* 47 */
/* 46 */	NdrFcLong( 0x14 ),	/* 20 */
/* 50 */	NdrFcShort( 0x800b ),	/* Simple arm type: FC_HYPER */
/* 52 */	NdrFcLong( 0x3 ),	/* 3 */
/* 56 */	NdrFcShort( 0x8008 ),	/* Simple arm type: FC_LONG */
/* 58 */	NdrFcLong( 0x11 ),	/* 17 */
/* 62 */	NdrFcShort( 0x8001 ),	/* Simple arm type: FC_BYTE */
/* 64 */	NdrFcLong( 0x2 ),	/* 2 */
/* 68 */	NdrFcShort( 0x8006 ),	/* Simple arm type: FC_SHORT */
/* 70 */	NdrFcLong( 0x4 ),	/* 4 */
/* 74 */	NdrFcShort( 0x800a ),	/* Simple arm type: FC_FLOAT */
/* 76 */	NdrFcLong( 0x5 ),	/* 5 */
/* 80 */	NdrFcShort( 0x800c ),	/* Simple arm type: FC_DOUBLE */
/* 82 */	NdrFcLong( 0xb ),	/* 11 */
/* 86 */	NdrFcShort( 0x8006 ),	/* Simple arm type: FC_SHORT */
/* 88 */	NdrFcLong( 0xa ),	/* 10 */
/* 92 */	NdrFcShort( 0x8008 ),	/* Simple arm type: FC_LONG */
/* 94 */	NdrFcLong( 0x6 ),	/* 6 */
/* 98 */	NdrFcShort( 0xe8 ),	/* Offset= 232 (330) */
/* 100 */	NdrFcLong( 0x7 ),	/* 7 */
/* 104 */	NdrFcShort( 0x800c ),	/* Simple arm type: FC_DOUBLE */
/* 106 */	NdrFcLong( 0x8 ),	/* 8 */
/* 110 */	NdrFcShort( 0xe2 ),	/* Offset= 226 (336) */
/* 112 */	NdrFcLong( 0xd ),	/* 13 */
/* 116 */	NdrFcShort( 0xf6 ),	/* Offset= 246 (362) */
/* 118 */	NdrFcLong( 0x9 ),	/* 9 */
/* 122 */	NdrFcShort( 0x102 ),	/* Offset= 258 (380) */
/* 124 */	NdrFcLong( 0x2000 ),	/* 8192 */
/* 128 */	NdrFcShort( 0x10e ),	/* Offset= 270 (398) */
/* 130 */	NdrFcLong( 0x24 ),	/* 36 */
/* 134 */	NdrFcShort( 0x336 ),	/* Offset= 822 (956) */
/* 136 */	NdrFcLong( 0x4024 ),	/* 16420 */
/* 140 */	NdrFcShort( 0x330 ),	/* Offset= 816 (956) */
/* 142 */	NdrFcLong( 0x4011 ),	/* 16401 */
/* 146 */	NdrFcShort( 0x32e ),	/* Offset= 814 (960) */
/* 148 */	NdrFcLong( 0x4002 ),	/* 16386 */
/* 152 */	NdrFcShort( 0x32c ),	/* Offset= 812 (964) */
/* 154 */	NdrFcLong( 0x4003 ),	/* 16387 */
/* 158 */	NdrFcShort( 0x32a ),	/* Offset= 810 (968) */
/* 160 */	NdrFcLong( 0x4014 ),	/* 16404 */
/* 164 */	NdrFcShort( 0x328 ),	/* Offset= 808 (972) */
/* 166 */	NdrFcLong( 0x4004 ),	/* 16388 */
/* 170 */	NdrFcShort( 0x326 ),	/* Offset= 806 (976) */
/* 172 */	NdrFcLong( 0x4005 ),	/* 16389 */
/* 176 */	NdrFcShort( 0x324 ),	/* Offset= 804 (980) */
/* 178 */	NdrFcLong( 0x400b ),	/* 16395 */
/* 182 */	NdrFcShort( 0x30e ),	/* Offset= 782 (964) */
/* 184 */	NdrFcLong( 0x400a ),	/* 16394 */
/* 188 */	NdrFcShort( 0x30c ),	/* Offset= 780 (968) */
/* 190 */	NdrFcLong( 0x4006 ),	/* 16390 */
/* 194 */	NdrFcShort( 0x316 ),	/* Offset= 790 (984) */
/* 196 */	NdrFcLong( 0x4007 ),	/* 16391 */
/* 200 */	NdrFcShort( 0x30c ),	/* Offset= 780 (980) */
/* 202 */	NdrFcLong( 0x4008 ),	/* 16392 */
/* 206 */	NdrFcShort( 0x30e ),	/* Offset= 782 (988) */
/* 208 */	NdrFcLong( 0x400d ),	/* 16397 */
/* 212 */	NdrFcShort( 0x30c ),	/* Offset= 780 (992) */
/* 214 */	NdrFcLong( 0x4009 ),	/* 16393 */
/* 218 */	NdrFcShort( 0x30a ),	/* Offset= 778 (996) */
/* 220 */	NdrFcLong( 0x6000 ),	/* 24576 */
/* 224 */	NdrFcShort( 0x308 ),	/* Offset= 776 (1000) */
/* 226 */	NdrFcLong( 0x400c ),	/* 16396 */
/* 230 */	NdrFcShort( 0x306 ),	/* Offset= 774 (1004) */
/* 232 */	NdrFcLong( 0x10 ),	/* 16 */
/* 236 */	NdrFcShort( 0x8002 ),	/* Simple arm type: FC_CHAR */
/* 238 */	NdrFcLong( 0x12 ),	/* 18 */
/* 242 */	NdrFcShort( 0x8006 ),	/* Simple arm type: FC_SHORT */
/* 244 */	NdrFcLong( 0x13 ),	/* 19 */
/* 248 */	NdrFcShort( 0x8008 ),	/* Simple arm type: FC_LONG */
/* 250 */	NdrFcLong( 0x15 ),	/* 21 */
/* 254 */	NdrFcShort( 0x800b ),	/* Simple arm type: FC_HYPER */
/* 256 */	NdrFcLong( 0x16 ),	/* 22 */
/* 260 */	NdrFcShort( 0x8008 ),	/* Simple arm type: FC_LONG */
/* 262 */	NdrFcLong( 0x17 ),	/* 23 */
/* 266 */	NdrFcShort( 0x8008 ),	/* Simple arm type: FC_LONG */
/* 268 */	NdrFcLong( 0xe ),	/* 14 */
/* 272 */	NdrFcShort( 0x2e4 ),	/* Offset= 740 (1012) */
/* 274 */	NdrFcLong( 0x400e ),	/* 16398 */
/* 278 */	NdrFcShort( 0x2e8 ),	/* Offset= 744 (1022) */
/* 280 */	NdrFcLong( 0x4010 ),	/* 16400 */
/* 284 */	NdrFcShort( 0x2e6 ),	/* Offset= 742 (1026) */
/* 286 */	NdrFcLong( 0x4012 ),	/* 16402 */
/* 290 */	NdrFcShort( 0x2a2 ),	/* Offset= 674 (964) */
/* 292 */	NdrFcLong( 0x4013 ),	/* 16403 */
/* 296 */	NdrFcShort( 0x2a0 ),	/* Offset= 672 (968) */
/* 298 */	NdrFcLong( 0x4015 ),	/* 16405 */
/* 302 */	NdrFcShort( 0x29e ),	/* Offset= 670 (972) */
/* 304 */	NdrFcLong( 0x4016 ),	/* 16406 */
/* 308 */	NdrFcShort( 0x294 ),	/* Offset= 660 (968) */
/* 310 */	NdrFcLong( 0x4017 ),	/* 16407 */
/* 314 */	NdrFcShort( 0x28e ),	/* Offset= 654 (968) */
/* 316 */	NdrFcLong( 0x0 ),	/* 0 */
/* 320 */	NdrFcShort( 0x0 ),	/* Offset= 0 (320) */
/* 322 */	NdrFcLong( 0x1 ),	/* 1 */
/* 326 */	NdrFcShort( 0x0 ),	/* Offset= 0 (326) */
/* 328 */	NdrFcShort( 0xffff ),	/* Offset= -1 (327) */
/* 330 */	
			0x15,		/* FC_STRUCT */
			0x7,		/* 7 */
/* 332 */	NdrFcShort( 0x8 ),	/* 8 */
/* 334 */	0xb,		/* FC_HYPER */
			0x5b,		/* FC_END */
/* 336 */	
			0x13, 0x0,	/* FC_OP */
/* 338 */	NdrFcShort( 0xe ),	/* Offset= 14 (352) */
/* 340 */	
			0x1b,		/* FC_CARRAY */
			0x1,		/* 1 */
/* 342 */	NdrFcShort( 0x2 ),	/* 2 */
/* 344 */	0x9,		/* Corr desc: FC_ULONG */
			0x0,		/*  */
/* 346 */	NdrFcShort( 0xfffc ),	/* -4 */
/* 348 */	NdrFcShort( 0x1 ),	/* Corr flags:  early, */
/* 350 */	0x6,		/* FC_SHORT */
			0x5b,		/* FC_END */
/* 352 */	
			0x17,		/* FC_CSTRUCT */
			0x3,		/* 3 */
/* 354 */	NdrFcShort( 0x8 ),	/* 8 */
/* 356 */	NdrFcShort( 0xfff0 ),	/* Offset= -16 (340) */
/* 358 */	0x8,		/* FC_LONG */
			0x8,		/* FC_LONG */
/* 360 */	0x5c,		/* FC_PAD */
			0x5b,		/* FC_END */
/* 362 */	
			0x2f,		/* FC_IP */
			0x5a,		/* FC_CONSTANT_IID */
/* 364 */	NdrFcLong( 0x0 ),	/* 0 */
/* 368 */	NdrFcShort( 0x0 ),	/* 0 */
/* 370 */	NdrFcShort( 0x0 ),	/* 0 */
/* 372 */	0xc0,		/* 192 */
			0x0,		/* 0 */
/* 374 */	0x0,		/* 0 */
			0x0,		/* 0 */
/* 376 */	0x0,		/* 0 */
			0x0,		/* 0 */
/* 378 */	0x0,		/* 0 */
			0x46,		/* 70 */
/* 380 */	
			0x2f,		/* FC_IP */
			0x5a,		/* FC_CONSTANT_IID */
/* 382 */	NdrFcLong( 0x20400 ),	/* 132096 */
/* 386 */	NdrFcShort( 0x0 ),	/* 0 */
/* 388 */	NdrFcShort( 0x0 ),	/* 0 */
/* 390 */	0xc0,		/* 192 */
			0x0,		/* 0 */
/* 392 */	0x0,		/* 0 */
			0x0,		/* 0 */
/* 394 */	0x0,		/* 0 */
			0x0,		/* 0 */
/* 396 */	0x0,		/* 0 */
			0x46,		/* 70 */
/* 398 */	
			0x13, 0x10,	/* FC_OP [pointer_deref] */
/* 400 */	NdrFcShort( 0x2 ),	/* Offset= 2 (402) */
/* 402 */	
			0x13, 0x0,	/* FC_OP */
/* 404 */	NdrFcShort( 0x216 ),	/* Offset= 534 (938) */
/* 406 */	
			0x2a,		/* FC_ENCAPSULATED_UNION */
			0x49,		/* 73 */
/* 408 */	NdrFcShort( 0x18 ),	/* 24 */
/* 410 */	NdrFcShort( 0xa ),	/* 10 */
/* 412 */	NdrFcLong( 0x8 ),	/* 8 */
/* 416 */	NdrFcShort( 0x5a ),	/* Offset= 90 (506) */
/* 418 */	NdrFcLong( 0xd ),	/* 13 */
/* 422 */	NdrFcShort( 0x7e ),	/* Offset= 126 (548) */
/* 424 */	NdrFcLong( 0x9 ),	/* 9 */
/* 428 */	NdrFcShort( 0x9e ),	/* Offset= 158 (586) */
/* 430 */	NdrFcLong( 0xc ),	/* 12 */
/* 434 */	NdrFcShort( 0xc8 ),	/* Offset= 200 (634) */
/* 436 */	NdrFcLong( 0x24 ),	/* 36 */
/* 440 */	NdrFcShort( 0x124 ),	/* Offset= 292 (732) */
/* 442 */	NdrFcLong( 0x800d ),	/* 32781 */
/* 446 */	NdrFcShort( 0x140 ),	/* Offset= 320 (766) */
/* 448 */	NdrFcLong( 0x10 ),	/* 16 */
/* 452 */	NdrFcShort( 0x15a ),	/* Offset= 346 (798) */
/* 454 */	NdrFcLong( 0x2 ),	/* 2 */
/* 458 */	NdrFcShort( 0x174 ),	/* Offset= 372 (830) */
/* 460 */	NdrFcLong( 0x3 ),	/* 3 */
/* 464 */	NdrFcShort( 0x18e ),	/* Offset= 398 (862) */
/* 466 */	NdrFcLong( 0x14 ),	/* 20 */
/* 470 */	NdrFcShort( 0x1a8 ),	/* Offset= 424 (894) */
/* 472 */	NdrFcShort( 0xffff ),	/* Offset= -1 (471) */
/* 474 */	
			0x1b,		/* FC_CARRAY */
			0x3,		/* 3 */
/* 476 */	NdrFcShort( 0x4 ),	/* 4 */
/* 478 */	0x19,		/* Corr desc:  field pointer, FC_ULONG */
			0x0,		/*  */
/* 480 */	NdrFcShort( 0x0 ),	/* 0 */
/* 482 */	NdrFcShort( 0x1 ),	/* Corr flags:  early, */
/* 484 */	
			0x4b,		/* FC_PP */
			0x5c,		/* FC_PAD */
/* 486 */	
			0x48,		/* FC_VARIABLE_REPEAT */
			0x49,		/* FC_FIXED_OFFSET */
/* 488 */	NdrFcShort( 0x4 ),	/* 4 */
/* 490 */	NdrFcShort( 0x0 ),	/* 0 */
/* 492 */	NdrFcShort( 0x1 ),	/* 1 */
/* 494 */	NdrFcShort( 0x0 ),	/* 0 */
/* 496 */	NdrFcShort( 0x0 ),	/* 0 */
/* 498 */	0x13, 0x0,	/* FC_OP */
/* 500 */	NdrFcShort( 0xff6c ),	/* Offset= -148 (352) */
/* 502 */	
			0x5b,		/* FC_END */

			0x8,		/* FC_LONG */
/* 504 */	0x5c,		/* FC_PAD */
			0x5b,		/* FC_END */
/* 506 */	
			0x16,		/* FC_PSTRUCT */
			0x3,		/* 3 */
/* 508 */	NdrFcShort( 0x8 ),	/* 8 */
/* 510 */	
			0x4b,		/* FC_PP */
			0x5c,		/* FC_PAD */
/* 512 */	
			0x46,		/* FC_NO_REPEAT */
			0x5c,		/* FC_PAD */
/* 514 */	NdrFcShort( 0x4 ),	/* 4 */
/* 516 */	NdrFcShort( 0x4 ),	/* 4 */
/* 518 */	0x11, 0x0,	/* FC_RP */
/* 520 */	NdrFcShort( 0xffd2 ),	/* Offset= -46 (474) */
/* 522 */	
			0x5b,		/* FC_END */

			0x8,		/* FC_LONG */
/* 524 */	0x8,		/* FC_LONG */
			0x5b,		/* FC_END */
/* 526 */	
			0x21,		/* FC_BOGUS_ARRAY */
			0x3,		/* 3 */
/* 528 */	NdrFcShort( 0x0 ),	/* 0 */
/* 530 */	0x19,		/* Corr desc:  field pointer, FC_ULONG */
			0x0,		/*  */
/* 532 */	NdrFcShort( 0x0 ),	/* 0 */
/* 534 */	NdrFcShort( 0x1 ),	/* Corr flags:  early, */
/* 536 */	NdrFcLong( 0xffffffff ),	/* -1 */
/* 540 */	NdrFcShort( 0x0 ),	/* Corr flags:  */
/* 542 */	0x4c,		/* FC_EMBEDDED_COMPLEX */
			0x0,		/* 0 */
/* 544 */	NdrFcShort( 0xff4a ),	/* Offset= -182 (362) */
/* 546 */	0x5c,		/* FC_PAD */
			0x5b,		/* FC_END */
/* 548 */	
			0x1a,		/* FC_BOGUS_STRUCT */
			0x3,		/* 3 */
/* 550 */	NdrFcShort( 0x8 ),	/* 8 */
/* 552 */	NdrFcShort( 0x0 ),	/* 0 */
/* 554 */	NdrFcShort( 0x6 ),	/* Offset= 6 (560) */
/* 556 */	0x8,		/* FC_LONG */
			0x36,		/* FC_POINTER */
/* 558 */	0x5c,		/* FC_PAD */
			0x5b,		/* FC_END */
/* 560 */	
			0x11, 0x0,	/* FC_RP */
/* 562 */	NdrFcShort( 0xffdc ),	/* Offset= -36 (526) */
/* 564 */	
			0x21,		/* FC_BOGUS_ARRAY */
			0x3,		/* 3 */
/* 566 */	NdrFcShort( 0x0 ),	/* 0 */
/* 568 */	0x19,		/* Corr desc:  field pointer, FC_ULONG */
			0x0,		/*  */
/* 570 */	NdrFcShort( 0x0 ),	/* 0 */
/* 572 */	NdrFcShort( 0x1 ),	/* Corr flags:  early, */
/* 574 */	NdrFcLong( 0xffffffff ),	/* -1 */
/* 578 */	NdrFcShort( 0x0 ),	/* Corr flags:  */
/* 580 */	0x4c,		/* FC_EMBEDDED_COMPLEX */
			0x0,		/* 0 */
/* 582 */	NdrFcShort( 0xff36 ),	/* Offset= -202 (380) */
/* 584 */	0x5c,		/* FC_PAD */
			0x5b,		/* FC_END */
/* 586 */	
			0x1a,		/* FC_BOGUS_STRUCT */
			0x3,		/* 3 */
/* 588 */	NdrFcShort( 0x8 ),	/* 8 */
/* 590 */	NdrFcShort( 0x0 ),	/* 0 */
/* 592 */	NdrFcShort( 0x6 ),	/* Offset= 6 (598) */
/* 594 */	0x8,		/* FC_LONG */
			0x36,		/* FC_POINTER */
/* 596 */	0x5c,		/* FC_PAD */
			0x5b,		/* FC_END */
/* 598 */	
			0x11, 0x0,	/* FC_RP */
/* 600 */	NdrFcShort( 0xffdc ),	/* Offset= -36 (564) */
/* 602 */	
			0x1b,		/* FC_CARRAY */
			0x3,		/* 3 */
/* 604 */	NdrFcShort( 0x4 ),	/* 4 */
/* 606 */	0x19,		/* Corr desc:  field pointer, FC_ULONG */
			0x0,		/*  */
/* 608 */	NdrFcShort( 0x0 ),	/* 0 */
/* 610 */	NdrFcShort( 0x1 ),	/* Corr flags:  early, */
/* 612 */	
			0x4b,		/* FC_PP */
			0x5c,		/* FC_PAD */
/* 614 */	
			0x48,		/* FC_VARIABLE_REPEAT */
			0x49,		/* FC_FIXED_OFFSET */
/* 616 */	NdrFcShort( 0x4 ),	/* 4 */
/* 618 */	NdrFcShort( 0x0 ),	/* 0 */
/* 620 */	NdrFcShort( 0x1 ),	/* 1 */
/* 622 */	NdrFcShort( 0x0 ),	/* 0 */
/* 624 */	NdrFcShort( 0x0 ),	/* 0 */
/* 626 */	0x13, 0x0,	/* FC_OP */
/* 628 */	NdrFcShort( 0x192 ),	/* Offset= 402 (1030) */
/* 630 */	
			0x5b,		/* FC_END */

			0x8,		/* FC_LONG */
/* 632 */	0x5c,		/* FC_PAD */
			0x5b,		/* FC_END */
/* 634 */	
			0x1a,		/* FC_BOGUS_STRUCT */
			0x3,		/* 3 */
/* 636 */	NdrFcShort( 0x8 ),	/* 8 */
/* 638 */	NdrFcShort( 0x0 ),	/* 0 */
/* 640 */	NdrFcShort( 0x6 ),	/* Offset= 6 (646) */
/* 642 */	0x8,		/* FC_LONG */
			0x36,		/* FC_POINTER */
/* 644 */	0x5c,		/* FC_PAD */
			0x5b,		/* FC_END */
/* 646 */	
			0x11, 0x0,	/* FC_RP */
/* 648 */	NdrFcShort( 0xffd2 ),	/* Offset= -46 (602) */
/* 650 */	
			0x2f,		/* FC_IP */
			0x5a,		/* FC_CONSTANT_IID */
/* 652 */	NdrFcLong( 0x2f ),	/* 47 */
/* 656 */	NdrFcShort( 0x0 ),	/* 0 */
/* 658 */	NdrFcShort( 0x0 ),	/* 0 */
/* 660 */	0xc0,		/* 192 */
			0x0,		/* 0 */
/* 662 */	0x0,		/* 0 */
			0x0,		/* 0 */
/* 664 */	0x0,		/* 0 */
			0x0,		/* 0 */
/* 666 */	0x0,		/* 0 */
			0x46,		/* 70 */
/* 668 */	
			0x1b,		/* FC_CARRAY */
			0x0,		/* 0 */
/* 670 */	NdrFcShort( 0x1 ),	/* 1 */
/* 672 */	0x19,		/* Corr desc:  field pointer, FC_ULONG */
			0x0,		/*  */
/* 674 */	NdrFcShort( 0x4 ),	/* 4 */
/* 676 */	NdrFcShort( 0x1 ),	/* Corr flags:  early, */
/* 678 */	0x1,		/* FC_BYTE */
			0x5b,		/* FC_END */
/* 680 */	
			0x1a,		/* FC_BOGUS_STRUCT */
			0x3,		/* 3 */
/* 682 */	NdrFcShort( 0x10 ),	/* 16 */
/* 684 */	NdrFcShort( 0x0 ),	/* 0 */
/* 686 */	NdrFcShort( 0xa ),	/* Offset= 10 (696) */
/* 688 */	0x8,		/* FC_LONG */
			0x8,		/* FC_LONG */
/* 690 */	0x4c,		/* FC_EMBEDDED_COMPLEX */
			0x0,		/* 0 */
/* 692 */	NdrFcShort( 0xffd6 ),	/* Offset= -42 (650) */
/* 694 */	0x36,		/* FC_POINTER */
			0x5b,		/* FC_END */
/* 696 */	
			0x13, 0x0,	/* FC_OP */
/* 698 */	NdrFcShort( 0xffe2 ),	/* Offset= -30 (668) */
/* 700 */	
			0x1b,		/* FC_CARRAY */
			0x3,		/* 3 */
/* 702 */	NdrFcShort( 0x4 ),	/* 4 */
/* 704 */	0x19,		/* Corr desc:  field pointer, FC_ULONG */
			0x0,		/*  */
/* 706 */	NdrFcShort( 0x0 ),	/* 0 */
/* 708 */	NdrFcShort( 0x1 ),	/* Corr flags:  early, */
/* 710 */	
			0x4b,		/* FC_PP */
			0x5c,		/* FC_PAD */
/* 712 */	
			0x48,		/* FC_VARIABLE_REPEAT */
			0x49,		/* FC_FIXED_OFFSET */
/* 714 */	NdrFcShort( 0x4 ),	/* 4 */
/* 716 */	NdrFcShort( 0x0 ),	/* 0 */
/* 718 */	NdrFcShort( 0x1 ),	/* 1 */
/* 720 */	NdrFcShort( 0x0 ),	/* 0 */
/* 722 */	NdrFcShort( 0x0 ),	/* 0 */
/* 724 */	0x13, 0x0,	/* FC_OP */
/* 726 */	NdrFcShort( 0xffd2 ),	/* Offset= -46 (680) */
/* 728 */	
			0x5b,		/* FC_END */

			0x8,		/* FC_LONG */
/* 730 */	0x5c,		/* FC_PAD */
			0x5b,		/* FC_END */
/* 732 */	
			0x1a,		/* FC_BOGUS_STRUCT */
			0x3,		/* 3 */
/* 734 */	NdrFcShort( 0x8 ),	/* 8 */
/* 736 */	NdrFcShort( 0x0 ),	/* 0 */
/* 738 */	NdrFcShort( 0x6 ),	/* Offset= 6 (744) */
/* 740 */	0x8,		/* FC_LONG */
			0x36,		/* FC_POINTER */
/* 742 */	0x5c,		/* FC_PAD */
			0x5b,		/* FC_END */
/* 744 */	
			0x11, 0x0,	/* FC_RP */
/* 746 */	NdrFcShort( 0xffd2 ),	/* Offset= -46 (700) */
/* 748 */	
			0x1d,		/* FC_SMFARRAY */
			0x0,		/* 0 */
/* 750 */	NdrFcShort( 0x8 ),	/* 8 */
/* 752 */	0x1,		/* FC_BYTE */
			0x5b,		/* FC_END */
/* 754 */	
			0x15,		/* FC_STRUCT */
			0x3,		/* 3 */
/* 756 */	NdrFcShort( 0x10 ),	/* 16 */
/* 758 */	0x8,		/* FC_LONG */
			0x6,		/* FC_SHORT */
/* 760 */	0x6,		/* FC_SHORT */
			0x4c,		/* FC_EMBEDDED_COMPLEX */
/* 762 */	0x0,		/* 0 */
			NdrFcShort( 0xfff1 ),	/* Offset= -15 (748) */
			0x5b,		/* FC_END */
/* 766 */	
			0x1a,		/* FC_BOGUS_STRUCT */
			0x3,		/* 3 */
/* 768 */	NdrFcShort( 0x18 ),	/* 24 */
/* 770 */	NdrFcShort( 0x0 ),	/* 0 */
/* 772 */	NdrFcShort( 0xa ),	/* Offset= 10 (782) */
/* 774 */	0x8,		/* FC_LONG */
			0x36,		/* FC_POINTER */
/* 776 */	0x4c,		/* FC_EMBEDDED_COMPLEX */
			0x0,		/* 0 */
/* 778 */	NdrFcShort( 0xffe8 ),	/* Offset= -24 (754) */
/* 780 */	0x5c,		/* FC_PAD */
			0x5b,		/* FC_END */
/* 782 */	
			0x11, 0x0,	/* FC_RP */
/* 784 */	NdrFcShort( 0xfefe ),	/* Offset= -258 (526) */
/* 786 */	
			0x1b,		/* FC_CARRAY */
			0x0,		/* 0 */
/* 788 */	NdrFcShort( 0x1 ),	/* 1 */
/* 790 */	0x19,		/* Corr desc:  field pointer, FC_ULONG */
			0x0,		/*  */
/* 792 */	NdrFcShort( 0x0 ),	/* 0 */
/* 794 */	NdrFcShort( 0x1 ),	/* Corr flags:  early, */
/* 796 */	0x1,		/* FC_BYTE */
			0x5b,		/* FC_END */
/* 798 */	
			0x16,		/* FC_PSTRUCT */
			0x3,		/* 3 */
/* 800 */	NdrFcShort( 0x8 ),	/* 8 */
/* 802 */	
			0x4b,		/* FC_PP */
			0x5c,		/* FC_PAD */
/* 804 */	
			0x46,		/* FC_NO_REPEAT */
			0x5c,		/* FC_PAD */
/* 806 */	NdrFcShort( 0x4 ),	/* 4 */
/* 808 */	NdrFcShort( 0x4 ),	/* 4 */
/* 810 */	0x13, 0x0,	/* FC_OP */
/* 812 */	NdrFcShort( 0xffe6 ),	/* Offset= -26 (786) */
/* 814 */	
			0x5b,		/* FC_END */

			0x8,		/* FC_LONG */
/* 816 */	0x8,		/* FC_LONG */
			0x5b,		/* FC_END */
/* 818 */	
			0x1b,		/* FC_CARRAY */
			0x1,		/* 1 */
/* 820 */	NdrFcShort( 0x2 ),	/* 2 */
/* 822 */	0x19,		/* Corr desc:  field pointer, FC_ULONG */
			0x0,		/*  */
/* 824 */	NdrFcShort( 0x0 ),	/* 0 */
/* 826 */	NdrFcShort( 0x1 ),	/* Corr flags:  early, */
/* 828 */	0x6,		/* FC_SHORT */
			0x5b,		/* FC_END */
/* 830 */	
			0x16,		/* FC_PSTRUCT */
			0x3,		/* 3 */
/* 832 */	NdrFcShort( 0x8 ),	/* 8 */
/* 834 */	
			0x4b,		/* FC_PP */
			0x5c,		/* FC_PAD */
/* 836 */	
			0x46,		/* FC_NO_REPEAT */
			0x5c,		/* FC_PAD */
/* 838 */	NdrFcShort( 0x4 ),	/* 4 */
/* 840 */	NdrFcShort( 0x4 ),	/* 4 */
/* 842 */	0x13, 0x0,	/* FC_OP */
/* 844 */	NdrFcShort( 0xffe6 ),	/* Offset= -26 (818) */
/* 846 */	
			0x5b,		/* FC_END */

			0x8,		/* FC_LONG */
/* 848 */	0x8,		/* FC_LONG */
			0x5b,		/* FC_END */
/* 850 */	
			0x1b,		/* FC_CARRAY */
			0x3,		/* 3 */
/* 852 */	NdrFcShort( 0x4 ),	/* 4 */
/* 854 */	0x19,		/* Corr desc:  field pointer, FC_ULONG */
			0x0,		/*  */
/* 856 */	NdrFcShort( 0x0 ),	/* 0 */
/* 858 */	NdrFcShort( 0x1 ),	/* Corr flags:  early, */
/* 860 */	0x8,		/* FC_LONG */
			0x5b,		/* FC_END */
/* 862 */	
			0x16,		/* FC_PSTRUCT */
			0x3,		/* 3 */
/* 864 */	NdrFcShort( 0x8 ),	/* 8 */
/* 866 */	
			0x4b,		/* FC_PP */
			0x5c,		/* FC_PAD */
/* 868 */	
			0x46,		/* FC_NO_REPEAT */
			0x5c,		/* FC_PAD */
/* 870 */	NdrFcShort( 0x4 ),	/* 4 */
/* 872 */	NdrFcShort( 0x4 ),	/* 4 */
/* 874 */	0x13, 0x0,	/* FC_OP */
/* 876 */	NdrFcShort( 0xffe6 ),	/* Offset= -26 (850) */
/* 878 */	
			0x5b,		/* FC_END */

			0x8,		/* FC_LONG */
/* 880 */	0x8,		/* FC_LONG */
			0x5b,		/* FC_END */
/* 882 */	
			0x1b,		/* FC_CARRAY */
			0x7,		/* 7 */
/* 884 */	NdrFcShort( 0x8 ),	/* 8 */
/* 886 */	0x19,		/* Corr desc:  field pointer, FC_ULONG */
			0x0,		/*  */
/* 888 */	NdrFcShort( 0x0 ),	/* 0 */
/* 890 */	NdrFcShort( 0x1 ),	/* Corr flags:  early, */
/* 892 */	0xb,		/* FC_HYPER */
			0x5b,		/* FC_END */
/* 894 */	
			0x16,		/* FC_PSTRUCT */
			0x3,		/* 3 */
/* 896 */	NdrFcShort( 0x8 ),	/* 8 */
/* 898 */	
			0x4b,		/* FC_PP */
			0x5c,		/* FC_PAD */
/* 900 */	
			0x46,		/* FC_NO_REPEAT */
			0x5c,		/* FC_PAD */
/* 902 */	NdrFcShort( 0x4 ),	/* 4 */
/* 904 */	NdrFcShort( 0x4 ),	/* 4 */
/* 906 */	0x13, 0x0,	/* FC_OP */
/* 908 */	NdrFcShort( 0xffe6 ),	/* Offset= -26 (882) */
/* 910 */	
			0x5b,		/* FC_END */

			0x8,		/* FC_LONG */
/* 912 */	0x8,		/* FC_LONG */
			0x5b,		/* FC_END */
/* 914 */	
			0x15,		/* FC_STRUCT */
			0x3,		/* 3 */
/* 916 */	NdrFcShort( 0x8 ),	/* 8 */
/* 918 */	0x8,		/* FC_LONG */
			0x8,		/* FC_LONG */
/* 920 */	0x5c,		/* FC_PAD */
			0x5b,		/* FC_END */
/* 922 */	
			0x1b,		/* FC_CARRAY */
			0x3,		/* 3 */
/* 924 */	NdrFcShort( 0x8 ),	/* 8 */
/* 926 */	0x7,		/* Corr desc: FC_USHORT */
			0x0,		/*  */
/* 928 */	NdrFcShort( 0xffd8 ),	/* -40 */
/* 930 */	NdrFcShort( 0x1 ),	/* Corr flags:  early, */
/* 932 */	0x4c,		/* FC_EMBEDDED_COMPLEX */
			0x0,		/* 0 */
/* 934 */	NdrFcShort( 0xffec ),	/* Offset= -20 (914) */
/* 936 */	0x5c,		/* FC_PAD */
			0x5b,		/* FC_END */
/* 938 */	
			0x1a,		/* FC_BOGUS_STRUCT */
			0x3,		/* 3 */
/* 940 */	NdrFcShort( 0x28 ),	/* 40 */
/* 942 */	NdrFcShort( 0xffec ),	/* Offset= -20 (922) */
/* 944 */	NdrFcShort( 0x0 ),	/* Offset= 0 (944) */
/* 946 */	0x6,		/* FC_SHORT */
			0x6,		/* FC_SHORT */
/* 948 */	0x8,		/* FC_LONG */
			0x8,		/* FC_LONG */
/* 950 */	0x4c,		/* FC_EMBEDDED_COMPLEX */
			0x0,		/* 0 */
/* 952 */	NdrFcShort( 0xfdde ),	/* Offset= -546 (406) */
/* 954 */	0x5c,		/* FC_PAD */
			0x5b,		/* FC_END */
/* 956 */	
			0x13, 0x0,	/* FC_OP */
/* 958 */	NdrFcShort( 0xfeea ),	/* Offset= -278 (680) */
/* 960 */	
			0x13, 0x8,	/* FC_OP [simple_pointer] */
/* 962 */	0x1,		/* FC_BYTE */
			0x5c,		/* FC_PAD */
/* 964 */	
			0x13, 0x8,	/* FC_OP [simple_pointer] */
/* 966 */	0x6,		/* FC_SHORT */
			0x5c,		/* FC_PAD */
/* 968 */	
			0x13, 0x8,	/* FC_OP [simple_pointer] */
/* 970 */	0x8,		/* FC_LONG */
			0x5c,		/* FC_PAD */
/* 972 */	
			0x13, 0x8,	/* FC_OP [simple_pointer] */
/* 974 */	0xb,		/* FC_HYPER */
			0x5c,		/* FC_PAD */
/* 976 */	
			0x13, 0x8,	/* FC_OP [simple_pointer] */
/* 978 */	0xa,		/* FC_FLOAT */
			0x5c,		/* FC_PAD */
/* 980 */	
			0x13, 0x8,	/* FC_OP [simple_pointer] */
/* 982 */	0xc,		/* FC_DOUBLE */
			0x5c,		/* FC_PAD */
/* 984 */	
			0x13, 0x0,	/* FC_OP */
/* 986 */	NdrFcShort( 0xfd70 ),	/* Offset= -656 (330) */
/* 988 */	
			0x13, 0x10,	/* FC_OP [pointer_deref] */
/* 990 */	NdrFcShort( 0xfd72 ),	/* Offset= -654 (336) */
/* 992 */	
			0x13, 0x10,	/* FC_OP [pointer_deref] */
/* 994 */	NdrFcShort( 0xfd88 ),	/* Offset= -632 (362) */
/* 996 */	
			0x13, 0x10,	/* FC_OP [pointer_deref] */
/* 998 */	NdrFcShort( 0xfd96 ),	/* Offset= -618 (380) */
/* 1000 */	
			0x13, 0x10,	/* FC_OP [pointer_deref] */
/* 1002 */	NdrFcShort( 0xfda4 ),	/* Offset= -604 (398) */
/* 1004 */	
			0x13, 0x10,	/* FC_OP [pointer_deref] */
/* 1006 */	NdrFcShort( 0x2 ),	/* Offset= 2 (1008) */
/* 1008 */	
			0x13, 0x0,	/* FC_OP */
/* 1010 */	NdrFcShort( 0x14 ),	/* Offset= 20 (1030) */
/* 1012 */	
			0x15,		/* FC_STRUCT */
			0x7,		/* 7 */
/* 1014 */	NdrFcShort( 0x10 ),	/* 16 */
/* 1016 */	0x6,		/* FC_SHORT */
			0x1,		/* FC_BYTE */
/* 1018 */	0x1,		/* FC_BYTE */
			0x8,		/* FC_LONG */
/* 1020 */	0xb,		/* FC_HYPER */
			0x5b,		/* FC_END */
/* 1022 */	
			0x13, 0x0,	/* FC_OP */
/* 1024 */	NdrFcShort( 0xfff4 ),	/* Offset= -12 (1012) */
/* 1026 */	
			0x13, 0x8,	/* FC_OP [simple_pointer] */
/* 1028 */	0x2,		/* FC_CHAR */
			0x5c,		/* FC_PAD */
/* 1030 */	
			0x1a,		/* FC_BOGUS_STRUCT */
			0x7,		/* 7 */
/* 1032 */	NdrFcShort( 0x20 ),	/* 32 */
/* 1034 */	NdrFcShort( 0x0 ),	/* 0 */
/* 1036 */	NdrFcShort( 0x0 ),	/* Offset= 0 (1036) */
/* 1038 */	0x8,		/* FC_LONG */
			0x8,		/* FC_LONG */
/* 1040 */	0x6,		/* FC_SHORT */
			0x6,		/* FC_SHORT */
/* 1042 */	0x6,		/* FC_SHORT */
			0x6,		/* FC_SHORT */
/* 1044 */	0x4c,		/* FC_EMBEDDED_COMPLEX */
			0x0,		/* 0 */
/* 1046 */	NdrFcShort( 0xfc0a ),	/* Offset= -1014 (32) */
/* 1048 */	0x5c,		/* FC_PAD */
			0x5b,		/* FC_END */
/* 1050 */	0xb4,		/* FC_USER_MARSHAL */
			0x83,		/* 131 */
/* 1052 */	NdrFcShort( 0x0 ),	/* 0 */
/* 1054 */	NdrFcShort( 0x10 ),	/* 16 */
/* 1056 */	NdrFcShort( 0x0 ),	/* 0 */
/* 1058 */	NdrFcShort( 0xfbfa ),	/* Offset= -1030 (28) */
/* 1060 */	
			0x12, 0x0,	/* FC_UP */
/* 1062 */	NdrFcShort( 0xffe0 ),	/* Offset= -32 (1030) */
/* 1064 */	0xb4,		/* FC_USER_MARSHAL */
			0x83,		/* 131 */
/* 1066 */	NdrFcShort( 0x0 ),	/* 0 */
/* 1068 */	NdrFcShort( 0x10 ),	/* 16 */
/* 1070 */	NdrFcShort( 0x0 ),	/* 0 */
/* 1072 */	NdrFcShort( 0xfff4 ),	/* Offset= -12 (1060) */
/* 1074 */	
			0x11, 0x4,	/* FC_RP [alloced_on_stack] */
/* 1076 */	NdrFcShort( 0xffe6 ),	/* Offset= -26 (1050) */

			0x0
        }
    };

static const USER_MARSHAL_ROUTINE_QUADRUPLE UserMarshalRoutines[ WIRE_MARSHAL_TABLE_SIZE ] = 
        {
            
            {
            VARIANT_UserSize
            ,VARIANT_UserMarshal
            ,VARIANT_UserUnmarshal
            ,VARIANT_UserFree
            }

        };



/* Object interface: IUnknown, ver. 0.0,
   GUID={0x00000000,0x0000,0x0000,{0xC0,0x00,0x00,0x00,0x00,0x00,0x00,0x46}} */


/* Object interface: IDispatch, ver. 0.0,
   GUID={0x00020400,0x0000,0x0000,{0xC0,0x00,0x00,0x00,0x00,0x00,0x00,0x46}} */


/* Object interface: IClass1, ver. 0.0,
   GUID={0x3723DFA6,0x9143,0x462D,{0x94,0xB8,0x94,0xB7,0x9E,0x73,0x89,0x7D}} */

#pragma code_seg(".orpc")
static const unsigned short IClass1_FormatStringOffsetTable[] =
    {
    (unsigned short) -1,
    (unsigned short) -1,
    (unsigned short) -1,
    (unsigned short) -1,
    0,
    36,
    72,
    354,
    384,
    420,
    456,
    492,
    528,
    564,
    600,
    636,
    672,
    708,
    744,
    780,
    816,
    852,
    888,
    924,
    960,
    996,
    1032,
    1068,
    1104,
    1140,
    1176,
    1212,
    1248,
    1284,
    1320,
    1356,
    1392,
    1428,
    1464,
    1500,
    1536,
    1572,
    1608,
    1644,
    1680,
    1716,
    1752,
    1788,
    1824,
    1860,
    1896,
    1932,
    1968,
    2004,
    2040,
    2076,
    2112,
    2148,
    2184,
    2220,
    2256,
    2292,
    2328,
    2364,
    2400,
    2436,
    2472,
    2508,
    2544,
    2580,
    2616,
    2652,
    2688,
    2724,
    2760,
    2796,
    2832,
    2868,
    2904,
    2940,
    2976,
    3012,
    3048,
    3084,
    3120,
    3156,
    3192,
    3228,
    3264,
    3300
    };

static const MIDL_STUBLESS_PROXY_INFO IClass1_ProxyInfo =
    {
    &Object_StubDesc,
    MPC_Bifasico_dll_idl__MIDL_ProcFormatString.Format,
    &IClass1_FormatStringOffsetTable[-3],
    0,
    0,
    0
    };


static const MIDL_SERVER_INFO IClass1_ServerInfo = 
    {
    &Object_StubDesc,
    0,
    MPC_Bifasico_dll_idl__MIDL_ProcFormatString.Format,
    &IClass1_FormatStringOffsetTable[-3],
    0,
    0,
    0,
    0};
CINTERFACE_PROXY_VTABLE(93) _IClass1ProxyVtbl = 
{
    &IClass1_ProxyInfo,
    &IID_IClass1,
    IUnknown_QueryInterface_Proxy,
    IUnknown_AddRef_Proxy,
    IUnknown_Release_Proxy ,
    0 /* (void *) (INT_PTR) -1 /* IDispatch::GetTypeInfoCount */ ,
    0 /* (void *) (INT_PTR) -1 /* IDispatch::GetTypeInfo */ ,
    0 /* (void *) (INT_PTR) -1 /* IDispatch::GetIDsOfNames */ ,
    0 /* IDispatch_Invoke_Proxy */ ,
    (void *) (INT_PTR) -1 /* IClass1::get_MWFlags */ ,
    (void *) (INT_PTR) -1 /* IClass1::put_MWFlags */ ,
    (void *) (INT_PTR) -1 /* IClass1::MPC_Bifasico_dll */ ,
    (void *) (INT_PTR) -1 /* IClass1::MCRWaitForFigures */ ,
    (void *) (INT_PTR) -1 /* IClass1::get_Kph */ ,
    (void *) (INT_PTR) -1 /* IClass1::put_Kph */ ,
    (void *) (INT_PTR) -1 /* IClass1::get_SPh */ ,
    (void *) (INT_PTR) -1 /* IClass1::put_SPh */ ,
    (void *) (INT_PTR) -1 /* IClass1::get_exitFlag */ ,
    (void *) (INT_PTR) -1 /* IClass1::put_exitFlag */ ,
    (void *) (INT_PTR) -1 /* IClass1::get_u0 */ ,
    (void *) (INT_PTR) -1 /* IClass1::put_u0 */ ,
    (void *) (INT_PTR) -1 /* IClass1::get_xk_1 */ ,
    (void *) (INT_PTR) -1 /* IClass1::put_xk_1 */ ,
    (void *) (INT_PTR) -1 /* IClass1::get_Fo */ ,
    (void *) (INT_PTR) -1 /* IClass1::put_Fo */ ,
    (void *) (INT_PTR) -1 /* IClass1::get_x0 */ ,
    (void *) (INT_PTR) -1 /* IClass1::put_x0 */ ,
    (void *) (INT_PTR) -1 /* IClass1::get_ParametrosForaDaFaixa */ ,
    (void *) (INT_PTR) -1 /* IClass1::put_ParametrosForaDaFaixa */ ,
    (void *) (INT_PTR) -1 /* IClass1::get_h_passado */ ,
    (void *) (INT_PTR) -1 /* IClass1::put_h_passado */ ,
    (void *) (INT_PTR) -1 /* IClass1::get_TAmost */ ,
    (void *) (INT_PTR) -1 /* IClass1::put_TAmost */ ,
    (void *) (INT_PTR) -1 /* IClass1::get_Pfwd */ ,
    (void *) (INT_PTR) -1 /* IClass1::put_Pfwd */ ,
    (void *) (INT_PTR) -1 /* IClass1::get_PCfwd */ ,
    (void *) (INT_PTR) -1 /* IClass1::put_PCfwd */ ,
    (void *) (INT_PTR) -1 /* IClass1::get_nu */ ,
    (void *) (INT_PTR) -1 /* IClass1::put_nu */ ,
    (void *) (INT_PTR) -1 /* IClass1::get_np */ ,
    (void *) (INT_PTR) -1 /* IClass1::put_np */ ,
    (void *) (INT_PTR) -1 /* IClass1::get_ny */ ,
    (void *) (INT_PTR) -1 /* IClass1::put_ny */ ,
    (void *) (INT_PTR) -1 /* IClass1::get_q */ ,
    (void *) (INT_PTR) -1 /* IClass1::put_q */ ,
    (void *) (INT_PTR) -1 /* IClass1::get_r */ ,
    (void *) (INT_PTR) -1 /* IClass1::put_r */ ,
    (void *) (INT_PTR) -1 /* IClass1::get_ys */ ,
    (void *) (INT_PTR) -1 /* IClass1::put_ys */ ,
    (void *) (INT_PTR) -1 /* IClass1::get_yspmax */ ,
    (void *) (INT_PTR) -1 /* IClass1::put_yspmax */ ,
    (void *) (INT_PTR) -1 /* IClass1::get_yspmin */ ,
    (void *) (INT_PTR) -1 /* IClass1::put_yspmin */ ,
    (void *) (INT_PTR) -1 /* IClass1::get_umax */ ,
    (void *) (INT_PTR) -1 /* IClass1::put_umax */ ,
    (void *) (INT_PTR) -1 /* IClass1::get_umin */ ,
    (void *) (INT_PTR) -1 /* IClass1::put_umin */ ,
    (void *) (INT_PTR) -1 /* IClass1::get_dumax */ ,
    (void *) (INT_PTR) -1 /* IClass1::put_dumax */ ,
    (void *) (INT_PTR) -1 /* IClass1::get_LTRange_h */ ,
    (void *) (INT_PTR) -1 /* IClass1::put_LTRange_h */ ,
    (void *) (INT_PTR) -1 /* IClass1::get_Bias_h */ ,
    (void *) (INT_PTR) -1 /* IClass1::put_Bias_h */ ,
    (void *) (INT_PTR) -1 /* IClass1::get_CV */ ,
    (void *) (INT_PTR) -1 /* IClass1::put_CV */ ,
    (void *) (INT_PTR) -1 /* IClass1::get_gamaw */ ,
    (void *) (INT_PTR) -1 /* IClass1::put_gamaw */ ,
    (void *) (INT_PTR) -1 /* IClass1::get_gamal */ ,
    (void *) (INT_PTR) -1 /* IClass1::put_gamal */ ,
    (void *) (INT_PTR) -1 /* IClass1::get_Gw */ ,
    (void *) (INT_PTR) -1 /* IClass1::put_Gw */ ,
    (void *) (INT_PTR) -1 /* IClass1::get_Gl */ ,
    (void *) (INT_PTR) -1 /* IClass1::put_Gl */ ,
    (void *) (INT_PTR) -1 /* IClass1::get_Gg */ ,
    (void *) (INT_PTR) -1 /* IClass1::put_Gg */ ,
    (void *) (INT_PTR) -1 /* IClass1::get_C */ ,
    (void *) (INT_PTR) -1 /* IClass1::put_C */ ,
    (void *) (INT_PTR) -1 /* IClass1::get_D */ ,
    (void *) (INT_PTR) -1 /* IClass1::put_D */ ,
    (void *) (INT_PTR) -1 /* IClass1::get_u0_in1 */ ,
    (void *) (INT_PTR) -1 /* IClass1::put_u0_in1 */ ,
    (void *) (INT_PTR) -1 /* IClass1::get_xk_1_in1 */ ,
    (void *) (INT_PTR) -1 /* IClass1::put_xk_1_in1 */ ,
    (void *) (INT_PTR) -1 /* IClass1::get_Fo_in1 */ ,
    (void *) (INT_PTR) -1 /* IClass1::put_Fo_in1 */ ,
    (void *) (INT_PTR) -1 /* IClass1::get_ParametrosForaDaFaixa_in1 */ ,
    (void *) (INT_PTR) -1 /* IClass1::put_ParametrosForaDaFaixa_in1 */ ,
    (void *) (INT_PTR) -1 /* IClass1::get_h_atual */ ,
    (void *) (INT_PTR) -1 /* IClass1::put_h_atual */ ,
    (void *) (INT_PTR) -1 /* IClass1::get_h_passado_in1 */ ,
    (void *) (INT_PTR) -1 /* IClass1::put_h_passado_in1 */ ,
    (void *) (INT_PTR) -1 /* IClass1::get_Pvaso */ ,
    (void *) (INT_PTR) -1 /* IClass1::put_Pvaso */ ,
    (void *) (INT_PTR) -1 /* IClass1::get_Pjus */ ,
    (void *) (INT_PTR) -1 /* IClass1::put_Pjus */
};


static const PRPC_STUB_FUNCTION IClass1_table[] =
{
    STUB_FORWARDING_FUNCTION,
    STUB_FORWARDING_FUNCTION,
    STUB_FORWARDING_FUNCTION,
    STUB_FORWARDING_FUNCTION,
    NdrStubCall2,
    NdrStubCall2,
    NdrStubCall2,
    NdrStubCall2,
    NdrStubCall2,
    NdrStubCall2,
    NdrStubCall2,
    NdrStubCall2,
    NdrStubCall2,
    NdrStubCall2,
    NdrStubCall2,
    NdrStubCall2,
    NdrStubCall2,
    NdrStubCall2,
    NdrStubCall2,
    NdrStubCall2,
    NdrStubCall2,
    NdrStubCall2,
    NdrStubCall2,
    NdrStubCall2,
    NdrStubCall2,
    NdrStubCall2,
    NdrStubCall2,
    NdrStubCall2,
    NdrStubCall2,
    NdrStubCall2,
    NdrStubCall2,
    NdrStubCall2,
    NdrStubCall2,
    NdrStubCall2,
    NdrStubCall2,
    NdrStubCall2,
    NdrStubCall2,
    NdrStubCall2,
    NdrStubCall2,
    NdrStubCall2,
    NdrStubCall2,
    NdrStubCall2,
    NdrStubCall2,
    NdrStubCall2,
    NdrStubCall2,
    NdrStubCall2,
    NdrStubCall2,
    NdrStubCall2,
    NdrStubCall2,
    NdrStubCall2,
    NdrStubCall2,
    NdrStubCall2,
    NdrStubCall2,
    NdrStubCall2,
    NdrStubCall2,
    NdrStubCall2,
    NdrStubCall2,
    NdrStubCall2,
    NdrStubCall2,
    NdrStubCall2,
    NdrStubCall2,
    NdrStubCall2,
    NdrStubCall2,
    NdrStubCall2,
    NdrStubCall2,
    NdrStubCall2,
    NdrStubCall2,
    NdrStubCall2,
    NdrStubCall2,
    NdrStubCall2,
    NdrStubCall2,
    NdrStubCall2,
    NdrStubCall2,
    NdrStubCall2,
    NdrStubCall2,
    NdrStubCall2,
    NdrStubCall2,
    NdrStubCall2,
    NdrStubCall2,
    NdrStubCall2,
    NdrStubCall2,
    NdrStubCall2,
    NdrStubCall2,
    NdrStubCall2,
    NdrStubCall2,
    NdrStubCall2,
    NdrStubCall2,
    NdrStubCall2,
    NdrStubCall2,
    NdrStubCall2
};

CInterfaceStubVtbl _IClass1StubVtbl =
{
    &IID_IClass1,
    &IClass1_ServerInfo,
    93,
    &IClass1_table[-3],
    CStdStubBuffer_DELEGATING_METHODS
};

static const MIDL_STUB_DESC Object_StubDesc = 
    {
    0,
    NdrOleAllocate,
    NdrOleFree,
    0,
    0,
    0,
    0,
    0,
    MPC_Bifasico_dll_idl__MIDL_TypeFormatString.Format,
    1, /* -error bounds_check flag */
    0x50002, /* Ndr library version */
    0,
    0x70001f4, /* MIDL Version 7.0.500 */
    0,
    UserMarshalRoutines,
    0,  /* notify & notify_flag routine table */
    0x1, /* MIDL flag */
    0, /* cs routines */
    0,   /* proxy/server info */
    0
    };

const CInterfaceProxyVtbl * _MPC_Bifasico_dll_idl_ProxyVtblList[] = 
{
    ( CInterfaceProxyVtbl *) &_IClass1ProxyVtbl,
    0
};

const CInterfaceStubVtbl * _MPC_Bifasico_dll_idl_StubVtblList[] = 
{
    ( CInterfaceStubVtbl *) &_IClass1StubVtbl,
    0
};

PCInterfaceName const _MPC_Bifasico_dll_idl_InterfaceNamesList[] = 
{
    "IClass1",
    0
};

const IID *  _MPC_Bifasico_dll_idl_BaseIIDList[] = 
{
    &IID_IDispatch,
    0
};


#define _MPC_Bifasico_dll_idl_CHECK_IID(n)	IID_GENERIC_CHECK_IID( _MPC_Bifasico_dll_idl, pIID, n)

int __stdcall _MPC_Bifasico_dll_idl_IID_Lookup( const IID * pIID, int * pIndex )
{
    
    if(!_MPC_Bifasico_dll_idl_CHECK_IID(0))
        {
        *pIndex = 0;
        return 1;
        }

    return 0;
}

const ExtendedProxyFileInfo MPC_Bifasico_dll_idl_ProxyFileInfo = 
{
    (PCInterfaceProxyVtblList *) & _MPC_Bifasico_dll_idl_ProxyVtblList,
    (PCInterfaceStubVtblList *) & _MPC_Bifasico_dll_idl_StubVtblList,
    (const PCInterfaceName * ) & _MPC_Bifasico_dll_idl_InterfaceNamesList,
    (const IID ** ) & _MPC_Bifasico_dll_idl_BaseIIDList,
    & _MPC_Bifasico_dll_idl_IID_Lookup, 
    1,
    2,
    0, /* table of [async_uuid] interfaces */
    0, /* Filler1 */
    0, /* Filler2 */
    0  /* Filler3 */
};
#pragma optimize("", on )
#if _MSC_VER >= 1200
#pragma warning(pop)
#endif


#endif /* !defined(_M_IA64) && !defined(_M_AMD64)*/

