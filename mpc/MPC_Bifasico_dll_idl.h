

/* this ALWAYS GENERATED file contains the definitions for the interfaces */


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

#pragma warning( disable: 4049 )  /* more than 64k source lines */


/* verify that the <rpcndr.h> version is high enough to compile this file*/
#ifndef __REQUIRED_RPCNDR_H_VERSION__
#define __REQUIRED_RPCNDR_H_VERSION__ 475
#endif

#include "rpc.h"
#include "rpcndr.h"

#ifndef __RPCNDR_H_VERSION__
#error this stub requires an updated version of <rpcndr.h>
#endif // __RPCNDR_H_VERSION__

#ifndef COM_NO_WINDOWS_H
#include "windows.h"
#include "ole2.h"
#endif /*COM_NO_WINDOWS_H*/

#ifndef __MPC_Bifasico_dll_idl_h__
#define __MPC_Bifasico_dll_idl_h__

#if defined(_MSC_VER) && (_MSC_VER >= 1020)
#pragma once
#endif

/* Forward Declarations */ 

#ifndef __IClass1_FWD_DEFINED__
#define __IClass1_FWD_DEFINED__
typedef interface IClass1 IClass1;
#endif 	/* __IClass1_FWD_DEFINED__ */


#ifndef __Class1_FWD_DEFINED__
#define __Class1_FWD_DEFINED__

#ifdef __cplusplus
typedef class Class1 Class1;
#else
typedef struct Class1 Class1;
#endif /* __cplusplus */

#endif 	/* __Class1_FWD_DEFINED__ */


/* header files for imported files */
#include "oaidl.h"
#include "ocidl.h"
#include "mwcomtypes.h"

#ifdef __cplusplus
extern "C"{
#endif 


#ifndef __IClass1_INTERFACE_DEFINED__
#define __IClass1_INTERFACE_DEFINED__

/* interface IClass1 */
/* [unique][helpstring][dual][uuid][object] */ 


EXTERN_C const IID IID_IClass1;

#if defined(__cplusplus) && !defined(CINTERFACE)
    
    MIDL_INTERFACE("3723DFA6-9143-462D-94B8-94B79E73897D")
    IClass1 : public IDispatch
    {
    public:
        virtual /* [helpstring][id][propget] */ HRESULT STDMETHODCALLTYPE get_MWFlags( 
            /* [retval][out] */ IMWFlags **ppvFlags) = 0;
        
        virtual /* [helpstring][id][propput] */ HRESULT STDMETHODCALLTYPE put_MWFlags( 
            /* [in] */ IMWFlags *pvFlags) = 0;
        
        virtual /* [helpstring][id] */ HRESULT STDMETHODCALLTYPE MPC_Bifasico_dll( 
            /* [in] */ long nargout,
            /* [out][in] */ VARIANT *Kph,
            /* [out][in] */ VARIANT *SPh,
            /* [out][in] */ VARIANT *exitFlag,
            /* [out][in] */ VARIANT *u0,
            /* [out][in] */ VARIANT *xk_1,
            /* [out][in] */ VARIANT *Fo,
            /* [out][in] */ VARIANT *x0,
            /* [out][in] */ VARIANT *ParametrosForaDaFaixa,
            /* [out][in] */ VARIANT *h_passado,
            /* [in] */ VARIANT TAmost,
            /* [in] */ VARIANT Pfwd,
            /* [in] */ VARIANT PCfwd,
            /* [in] */ VARIANT nu,
            /* [in] */ VARIANT np,
            /* [in] */ VARIANT ny,
            /* [in] */ VARIANT q,
            /* [in] */ VARIANT r,
            /* [in] */ VARIANT ys,
            /* [in] */ VARIANT yspmax,
            /* [in] */ VARIANT yspmin,
            /* [in] */ VARIANT umax,
            /* [in] */ VARIANT umin,
            /* [in] */ VARIANT dumax,
            /* [in] */ VARIANT LTRange_h,
            /* [in] */ VARIANT Bias_h,
            /* [in] */ VARIANT CV,
            /* [in] */ VARIANT gamaw,
            /* [in] */ VARIANT gamal,
            /* [in] */ VARIANT Gw,
            /* [in] */ VARIANT Gl,
            /* [in] */ VARIANT Gg,
            /* [in] */ VARIANT C,
            /* [in] */ VARIANT D,
            /* [in] */ VARIANT u0_in1,
            /* [in] */ VARIANT xk_1_in1,
            /* [in] */ VARIANT Fo_in1,
            /* [in] */ VARIANT ParametrosForaDaFaixa_in1,
            /* [in] */ VARIANT h_atual,
            /* [in] */ VARIANT h_passado_in1,
            /* [in] */ VARIANT Pvaso,
            /* [in] */ VARIANT Pjus) = 0;
        
        virtual /* [helpstring][id] */ HRESULT STDMETHODCALLTYPE MCRWaitForFigures( void) = 0;
        
        virtual /* [helpstring][id][propget] */ HRESULT STDMETHODCALLTYPE get_Kph( 
            /* [retval][out] */ VARIANT *Kph) = 0;
        
        virtual /* [helpstring][id][propput] */ HRESULT STDMETHODCALLTYPE put_Kph( 
            /* [in] */ VARIANT Kph) = 0;
        
        virtual /* [helpstring][id][propget] */ HRESULT STDMETHODCALLTYPE get_SPh( 
            /* [retval][out] */ VARIANT *SPh) = 0;
        
        virtual /* [helpstring][id][propput] */ HRESULT STDMETHODCALLTYPE put_SPh( 
            /* [in] */ VARIANT SPh) = 0;
        
        virtual /* [helpstring][id][propget] */ HRESULT STDMETHODCALLTYPE get_exitFlag( 
            /* [retval][out] */ VARIANT *exitFlag) = 0;
        
        virtual /* [helpstring][id][propput] */ HRESULT STDMETHODCALLTYPE put_exitFlag( 
            /* [in] */ VARIANT exitFlag) = 0;
        
        virtual /* [helpstring][id][propget] */ HRESULT STDMETHODCALLTYPE get_u0( 
            /* [retval][out] */ VARIANT *u0) = 0;
        
        virtual /* [helpstring][id][propput] */ HRESULT STDMETHODCALLTYPE put_u0( 
            /* [in] */ VARIANT u0) = 0;
        
        virtual /* [helpstring][id][propget] */ HRESULT STDMETHODCALLTYPE get_xk_1( 
            /* [retval][out] */ VARIANT *xk_1) = 0;
        
        virtual /* [helpstring][id][propput] */ HRESULT STDMETHODCALLTYPE put_xk_1( 
            /* [in] */ VARIANT xk_1) = 0;
        
        virtual /* [helpstring][id][propget] */ HRESULT STDMETHODCALLTYPE get_Fo( 
            /* [retval][out] */ VARIANT *Fo) = 0;
        
        virtual /* [helpstring][id][propput] */ HRESULT STDMETHODCALLTYPE put_Fo( 
            /* [in] */ VARIANT Fo) = 0;
        
        virtual /* [helpstring][id][propget] */ HRESULT STDMETHODCALLTYPE get_x0( 
            /* [retval][out] */ VARIANT *x0) = 0;
        
        virtual /* [helpstring][id][propput] */ HRESULT STDMETHODCALLTYPE put_x0( 
            /* [in] */ VARIANT x0) = 0;
        
        virtual /* [helpstring][id][propget] */ HRESULT STDMETHODCALLTYPE get_ParametrosForaDaFaixa( 
            /* [retval][out] */ VARIANT *ParametrosForaDaFaixa) = 0;
        
        virtual /* [helpstring][id][propput] */ HRESULT STDMETHODCALLTYPE put_ParametrosForaDaFaixa( 
            /* [in] */ VARIANT ParametrosForaDaFaixa) = 0;
        
        virtual /* [helpstring][id][propget] */ HRESULT STDMETHODCALLTYPE get_h_passado( 
            /* [retval][out] */ VARIANT *h_passado) = 0;
        
        virtual /* [helpstring][id][propput] */ HRESULT STDMETHODCALLTYPE put_h_passado( 
            /* [in] */ VARIANT h_passado) = 0;
        
        virtual /* [helpstring][id][propget] */ HRESULT STDMETHODCALLTYPE get_TAmost( 
            /* [retval][out] */ VARIANT *TAmost) = 0;
        
        virtual /* [helpstring][id][propput] */ HRESULT STDMETHODCALLTYPE put_TAmost( 
            /* [in] */ VARIANT TAmost) = 0;
        
        virtual /* [helpstring][id][propget] */ HRESULT STDMETHODCALLTYPE get_Pfwd( 
            /* [retval][out] */ VARIANT *Pfwd) = 0;
        
        virtual /* [helpstring][id][propput] */ HRESULT STDMETHODCALLTYPE put_Pfwd( 
            /* [in] */ VARIANT Pfwd) = 0;
        
        virtual /* [helpstring][id][propget] */ HRESULT STDMETHODCALLTYPE get_PCfwd( 
            /* [retval][out] */ VARIANT *PCfwd) = 0;
        
        virtual /* [helpstring][id][propput] */ HRESULT STDMETHODCALLTYPE put_PCfwd( 
            /* [in] */ VARIANT PCfwd) = 0;
        
        virtual /* [helpstring][id][propget] */ HRESULT STDMETHODCALLTYPE get_nu( 
            /* [retval][out] */ VARIANT *nu) = 0;
        
        virtual /* [helpstring][id][propput] */ HRESULT STDMETHODCALLTYPE put_nu( 
            /* [in] */ VARIANT nu) = 0;
        
        virtual /* [helpstring][id][propget] */ HRESULT STDMETHODCALLTYPE get_np( 
            /* [retval][out] */ VARIANT *np) = 0;
        
        virtual /* [helpstring][id][propput] */ HRESULT STDMETHODCALLTYPE put_np( 
            /* [in] */ VARIANT np) = 0;
        
        virtual /* [helpstring][id][propget] */ HRESULT STDMETHODCALLTYPE get_ny( 
            /* [retval][out] */ VARIANT *ny) = 0;
        
        virtual /* [helpstring][id][propput] */ HRESULT STDMETHODCALLTYPE put_ny( 
            /* [in] */ VARIANT ny) = 0;
        
        virtual /* [helpstring][id][propget] */ HRESULT STDMETHODCALLTYPE get_q( 
            /* [retval][out] */ VARIANT *q) = 0;
        
        virtual /* [helpstring][id][propput] */ HRESULT STDMETHODCALLTYPE put_q( 
            /* [in] */ VARIANT q) = 0;
        
        virtual /* [helpstring][id][propget] */ HRESULT STDMETHODCALLTYPE get_r( 
            /* [retval][out] */ VARIANT *r) = 0;
        
        virtual /* [helpstring][id][propput] */ HRESULT STDMETHODCALLTYPE put_r( 
            /* [in] */ VARIANT r) = 0;
        
        virtual /* [helpstring][id][propget] */ HRESULT STDMETHODCALLTYPE get_ys( 
            /* [retval][out] */ VARIANT *ys) = 0;
        
        virtual /* [helpstring][id][propput] */ HRESULT STDMETHODCALLTYPE put_ys( 
            /* [in] */ VARIANT ys) = 0;
        
        virtual /* [helpstring][id][propget] */ HRESULT STDMETHODCALLTYPE get_yspmax( 
            /* [retval][out] */ VARIANT *yspmax) = 0;
        
        virtual /* [helpstring][id][propput] */ HRESULT STDMETHODCALLTYPE put_yspmax( 
            /* [in] */ VARIANT yspmax) = 0;
        
        virtual /* [helpstring][id][propget] */ HRESULT STDMETHODCALLTYPE get_yspmin( 
            /* [retval][out] */ VARIANT *yspmin) = 0;
        
        virtual /* [helpstring][id][propput] */ HRESULT STDMETHODCALLTYPE put_yspmin( 
            /* [in] */ VARIANT yspmin) = 0;
        
        virtual /* [helpstring][id][propget] */ HRESULT STDMETHODCALLTYPE get_umax( 
            /* [retval][out] */ VARIANT *umax) = 0;
        
        virtual /* [helpstring][id][propput] */ HRESULT STDMETHODCALLTYPE put_umax( 
            /* [in] */ VARIANT umax) = 0;
        
        virtual /* [helpstring][id][propget] */ HRESULT STDMETHODCALLTYPE get_umin( 
            /* [retval][out] */ VARIANT *umin) = 0;
        
        virtual /* [helpstring][id][propput] */ HRESULT STDMETHODCALLTYPE put_umin( 
            /* [in] */ VARIANT umin) = 0;
        
        virtual /* [helpstring][id][propget] */ HRESULT STDMETHODCALLTYPE get_dumax( 
            /* [retval][out] */ VARIANT *dumax) = 0;
        
        virtual /* [helpstring][id][propput] */ HRESULT STDMETHODCALLTYPE put_dumax( 
            /* [in] */ VARIANT dumax) = 0;
        
        virtual /* [helpstring][id][propget] */ HRESULT STDMETHODCALLTYPE get_LTRange_h( 
            /* [retval][out] */ VARIANT *LTRange_h) = 0;
        
        virtual /* [helpstring][id][propput] */ HRESULT STDMETHODCALLTYPE put_LTRange_h( 
            /* [in] */ VARIANT LTRange_h) = 0;
        
        virtual /* [helpstring][id][propget] */ HRESULT STDMETHODCALLTYPE get_Bias_h( 
            /* [retval][out] */ VARIANT *Bias_h) = 0;
        
        virtual /* [helpstring][id][propput] */ HRESULT STDMETHODCALLTYPE put_Bias_h( 
            /* [in] */ VARIANT Bias_h) = 0;
        
        virtual /* [helpstring][id][propget] */ HRESULT STDMETHODCALLTYPE get_CV( 
            /* [retval][out] */ VARIANT *CV) = 0;
        
        virtual /* [helpstring][id][propput] */ HRESULT STDMETHODCALLTYPE put_CV( 
            /* [in] */ VARIANT CV) = 0;
        
        virtual /* [helpstring][id][propget] */ HRESULT STDMETHODCALLTYPE get_gamaw( 
            /* [retval][out] */ VARIANT *gamaw) = 0;
        
        virtual /* [helpstring][id][propput] */ HRESULT STDMETHODCALLTYPE put_gamaw( 
            /* [in] */ VARIANT gamaw) = 0;
        
        virtual /* [helpstring][id][propget] */ HRESULT STDMETHODCALLTYPE get_gamal( 
            /* [retval][out] */ VARIANT *gamal) = 0;
        
        virtual /* [helpstring][id][propput] */ HRESULT STDMETHODCALLTYPE put_gamal( 
            /* [in] */ VARIANT gamal) = 0;
        
        virtual /* [helpstring][id][propget] */ HRESULT STDMETHODCALLTYPE get_Gw( 
            /* [retval][out] */ VARIANT *Gw) = 0;
        
        virtual /* [helpstring][id][propput] */ HRESULT STDMETHODCALLTYPE put_Gw( 
            /* [in] */ VARIANT Gw) = 0;
        
        virtual /* [helpstring][id][propget] */ HRESULT STDMETHODCALLTYPE get_Gl( 
            /* [retval][out] */ VARIANT *Gl) = 0;
        
        virtual /* [helpstring][id][propput] */ HRESULT STDMETHODCALLTYPE put_Gl( 
            /* [in] */ VARIANT Gl) = 0;
        
        virtual /* [helpstring][id][propget] */ HRESULT STDMETHODCALLTYPE get_Gg( 
            /* [retval][out] */ VARIANT *Gg) = 0;
        
        virtual /* [helpstring][id][propput] */ HRESULT STDMETHODCALLTYPE put_Gg( 
            /* [in] */ VARIANT Gg) = 0;
        
        virtual /* [helpstring][id][propget] */ HRESULT STDMETHODCALLTYPE get_C( 
            /* [retval][out] */ VARIANT *C) = 0;
        
        virtual /* [helpstring][id][propput] */ HRESULT STDMETHODCALLTYPE put_C( 
            /* [in] */ VARIANT C) = 0;
        
        virtual /* [helpstring][id][propget] */ HRESULT STDMETHODCALLTYPE get_D( 
            /* [retval][out] */ VARIANT *D) = 0;
        
        virtual /* [helpstring][id][propput] */ HRESULT STDMETHODCALLTYPE put_D( 
            /* [in] */ VARIANT D) = 0;
        
        virtual /* [helpstring][id][propget] */ HRESULT STDMETHODCALLTYPE get_u0_in1( 
            /* [retval][out] */ VARIANT *u0_in1) = 0;
        
        virtual /* [helpstring][id][propput] */ HRESULT STDMETHODCALLTYPE put_u0_in1( 
            /* [in] */ VARIANT u0_in1) = 0;
        
        virtual /* [helpstring][id][propget] */ HRESULT STDMETHODCALLTYPE get_xk_1_in1( 
            /* [retval][out] */ VARIANT *xk_1_in1) = 0;
        
        virtual /* [helpstring][id][propput] */ HRESULT STDMETHODCALLTYPE put_xk_1_in1( 
            /* [in] */ VARIANT xk_1_in1) = 0;
        
        virtual /* [helpstring][id][propget] */ HRESULT STDMETHODCALLTYPE get_Fo_in1( 
            /* [retval][out] */ VARIANT *Fo_in1) = 0;
        
        virtual /* [helpstring][id][propput] */ HRESULT STDMETHODCALLTYPE put_Fo_in1( 
            /* [in] */ VARIANT Fo_in1) = 0;
        
        virtual /* [helpstring][id][propget] */ HRESULT STDMETHODCALLTYPE get_ParametrosForaDaFaixa_in1( 
            /* [retval][out] */ VARIANT *ParametrosForaDaFaixa_in1) = 0;
        
        virtual /* [helpstring][id][propput] */ HRESULT STDMETHODCALLTYPE put_ParametrosForaDaFaixa_in1( 
            /* [in] */ VARIANT ParametrosForaDaFaixa_in1) = 0;
        
        virtual /* [helpstring][id][propget] */ HRESULT STDMETHODCALLTYPE get_h_atual( 
            /* [retval][out] */ VARIANT *h_atual) = 0;
        
        virtual /* [helpstring][id][propput] */ HRESULT STDMETHODCALLTYPE put_h_atual( 
            /* [in] */ VARIANT h_atual) = 0;
        
        virtual /* [helpstring][id][propget] */ HRESULT STDMETHODCALLTYPE get_h_passado_in1( 
            /* [retval][out] */ VARIANT *h_passado_in1) = 0;
        
        virtual /* [helpstring][id][propput] */ HRESULT STDMETHODCALLTYPE put_h_passado_in1( 
            /* [in] */ VARIANT h_passado_in1) = 0;
        
        virtual /* [helpstring][id][propget] */ HRESULT STDMETHODCALLTYPE get_Pvaso( 
            /* [retval][out] */ VARIANT *Pvaso) = 0;
        
        virtual /* [helpstring][id][propput] */ HRESULT STDMETHODCALLTYPE put_Pvaso( 
            /* [in] */ VARIANT Pvaso) = 0;
        
        virtual /* [helpstring][id][propget] */ HRESULT STDMETHODCALLTYPE get_Pjus( 
            /* [retval][out] */ VARIANT *Pjus) = 0;
        
        virtual /* [helpstring][id][propput] */ HRESULT STDMETHODCALLTYPE put_Pjus( 
            /* [in] */ VARIANT Pjus) = 0;
        
    };
    
#else 	/* C style interface */

    typedef struct IClass1Vtbl
    {
        BEGIN_INTERFACE
        
        HRESULT ( STDMETHODCALLTYPE *QueryInterface )( 
            IClass1 * This,
            /* [in] */ REFIID riid,
            /* [iid_is][out] */ 
            __RPC__deref_out  void **ppvObject);
        
        ULONG ( STDMETHODCALLTYPE *AddRef )( 
            IClass1 * This);
        
        ULONG ( STDMETHODCALLTYPE *Release )( 
            IClass1 * This);
        
        HRESULT ( STDMETHODCALLTYPE *GetTypeInfoCount )( 
            IClass1 * This,
            /* [out] */ UINT *pctinfo);
        
        HRESULT ( STDMETHODCALLTYPE *GetTypeInfo )( 
            IClass1 * This,
            /* [in] */ UINT iTInfo,
            /* [in] */ LCID lcid,
            /* [out] */ ITypeInfo **ppTInfo);
        
        HRESULT ( STDMETHODCALLTYPE *GetIDsOfNames )( 
            IClass1 * This,
            /* [in] */ REFIID riid,
            /* [size_is][in] */ LPOLESTR *rgszNames,
            /* [range][in] */ UINT cNames,
            /* [in] */ LCID lcid,
            /* [size_is][out] */ DISPID *rgDispId);
        
        /* [local] */ HRESULT ( STDMETHODCALLTYPE *Invoke )( 
            IClass1 * This,
            /* [in] */ DISPID dispIdMember,
            /* [in] */ REFIID riid,
            /* [in] */ LCID lcid,
            /* [in] */ WORD wFlags,
            /* [out][in] */ DISPPARAMS *pDispParams,
            /* [out] */ VARIANT *pVarResult,
            /* [out] */ EXCEPINFO *pExcepInfo,
            /* [out] */ UINT *puArgErr);
        
        /* [helpstring][id][propget] */ HRESULT ( STDMETHODCALLTYPE *get_MWFlags )( 
            IClass1 * This,
            /* [retval][out] */ IMWFlags **ppvFlags);
        
        /* [helpstring][id][propput] */ HRESULT ( STDMETHODCALLTYPE *put_MWFlags )( 
            IClass1 * This,
            /* [in] */ IMWFlags *pvFlags);
        
        /* [helpstring][id] */ HRESULT ( STDMETHODCALLTYPE *MPC_Bifasico_dll )( 
            IClass1 * This,
            /* [in] */ long nargout,
            /* [out][in] */ VARIANT *Kph,
            /* [out][in] */ VARIANT *SPh,
            /* [out][in] */ VARIANT *exitFlag,
            /* [out][in] */ VARIANT *u0,
            /* [out][in] */ VARIANT *xk_1,
            /* [out][in] */ VARIANT *Fo,
            /* [out][in] */ VARIANT *x0,
            /* [out][in] */ VARIANT *ParametrosForaDaFaixa,
            /* [out][in] */ VARIANT *h_passado,
            /* [in] */ VARIANT TAmost,
            /* [in] */ VARIANT Pfwd,
            /* [in] */ VARIANT PCfwd,
            /* [in] */ VARIANT nu,
            /* [in] */ VARIANT np,
            /* [in] */ VARIANT ny,
            /* [in] */ VARIANT q,
            /* [in] */ VARIANT r,
            /* [in] */ VARIANT ys,
            /* [in] */ VARIANT yspmax,
            /* [in] */ VARIANT yspmin,
            /* [in] */ VARIANT umax,
            /* [in] */ VARIANT umin,
            /* [in] */ VARIANT dumax,
            /* [in] */ VARIANT LTRange_h,
            /* [in] */ VARIANT Bias_h,
            /* [in] */ VARIANT CV,
            /* [in] */ VARIANT gamaw,
            /* [in] */ VARIANT gamal,
            /* [in] */ VARIANT Gw,
            /* [in] */ VARIANT Gl,
            /* [in] */ VARIANT Gg,
            /* [in] */ VARIANT C,
            /* [in] */ VARIANT D,
            /* [in] */ VARIANT u0_in1,
            /* [in] */ VARIANT xk_1_in1,
            /* [in] */ VARIANT Fo_in1,
            /* [in] */ VARIANT ParametrosForaDaFaixa_in1,
            /* [in] */ VARIANT h_atual,
            /* [in] */ VARIANT h_passado_in1,
            /* [in] */ VARIANT Pvaso,
            /* [in] */ VARIANT Pjus);
        
        /* [helpstring][id] */ HRESULT ( STDMETHODCALLTYPE *MCRWaitForFigures )( 
            IClass1 * This);
        
        /* [helpstring][id][propget] */ HRESULT ( STDMETHODCALLTYPE *get_Kph )( 
            IClass1 * This,
            /* [retval][out] */ VARIANT *Kph);
        
        /* [helpstring][id][propput] */ HRESULT ( STDMETHODCALLTYPE *put_Kph )( 
            IClass1 * This,
            /* [in] */ VARIANT Kph);
        
        /* [helpstring][id][propget] */ HRESULT ( STDMETHODCALLTYPE *get_SPh )( 
            IClass1 * This,
            /* [retval][out] */ VARIANT *SPh);
        
        /* [helpstring][id][propput] */ HRESULT ( STDMETHODCALLTYPE *put_SPh )( 
            IClass1 * This,
            /* [in] */ VARIANT SPh);
        
        /* [helpstring][id][propget] */ HRESULT ( STDMETHODCALLTYPE *get_exitFlag )( 
            IClass1 * This,
            /* [retval][out] */ VARIANT *exitFlag);
        
        /* [helpstring][id][propput] */ HRESULT ( STDMETHODCALLTYPE *put_exitFlag )( 
            IClass1 * This,
            /* [in] */ VARIANT exitFlag);
        
        /* [helpstring][id][propget] */ HRESULT ( STDMETHODCALLTYPE *get_u0 )( 
            IClass1 * This,
            /* [retval][out] */ VARIANT *u0);
        
        /* [helpstring][id][propput] */ HRESULT ( STDMETHODCALLTYPE *put_u0 )( 
            IClass1 * This,
            /* [in] */ VARIANT u0);
        
        /* [helpstring][id][propget] */ HRESULT ( STDMETHODCALLTYPE *get_xk_1 )( 
            IClass1 * This,
            /* [retval][out] */ VARIANT *xk_1);
        
        /* [helpstring][id][propput] */ HRESULT ( STDMETHODCALLTYPE *put_xk_1 )( 
            IClass1 * This,
            /* [in] */ VARIANT xk_1);
        
        /* [helpstring][id][propget] */ HRESULT ( STDMETHODCALLTYPE *get_Fo )( 
            IClass1 * This,
            /* [retval][out] */ VARIANT *Fo);
        
        /* [helpstring][id][propput] */ HRESULT ( STDMETHODCALLTYPE *put_Fo )( 
            IClass1 * This,
            /* [in] */ VARIANT Fo);
        
        /* [helpstring][id][propget] */ HRESULT ( STDMETHODCALLTYPE *get_x0 )( 
            IClass1 * This,
            /* [retval][out] */ VARIANT *x0);
        
        /* [helpstring][id][propput] */ HRESULT ( STDMETHODCALLTYPE *put_x0 )( 
            IClass1 * This,
            /* [in] */ VARIANT x0);
        
        /* [helpstring][id][propget] */ HRESULT ( STDMETHODCALLTYPE *get_ParametrosForaDaFaixa )( 
            IClass1 * This,
            /* [retval][out] */ VARIANT *ParametrosForaDaFaixa);
        
        /* [helpstring][id][propput] */ HRESULT ( STDMETHODCALLTYPE *put_ParametrosForaDaFaixa )( 
            IClass1 * This,
            /* [in] */ VARIANT ParametrosForaDaFaixa);
        
        /* [helpstring][id][propget] */ HRESULT ( STDMETHODCALLTYPE *get_h_passado )( 
            IClass1 * This,
            /* [retval][out] */ VARIANT *h_passado);
        
        /* [helpstring][id][propput] */ HRESULT ( STDMETHODCALLTYPE *put_h_passado )( 
            IClass1 * This,
            /* [in] */ VARIANT h_passado);
        
        /* [helpstring][id][propget] */ HRESULT ( STDMETHODCALLTYPE *get_TAmost )( 
            IClass1 * This,
            /* [retval][out] */ VARIANT *TAmost);
        
        /* [helpstring][id][propput] */ HRESULT ( STDMETHODCALLTYPE *put_TAmost )( 
            IClass1 * This,
            /* [in] */ VARIANT TAmost);
        
        /* [helpstring][id][propget] */ HRESULT ( STDMETHODCALLTYPE *get_Pfwd )( 
            IClass1 * This,
            /* [retval][out] */ VARIANT *Pfwd);
        
        /* [helpstring][id][propput] */ HRESULT ( STDMETHODCALLTYPE *put_Pfwd )( 
            IClass1 * This,
            /* [in] */ VARIANT Pfwd);
        
        /* [helpstring][id][propget] */ HRESULT ( STDMETHODCALLTYPE *get_PCfwd )( 
            IClass1 * This,
            /* [retval][out] */ VARIANT *PCfwd);
        
        /* [helpstring][id][propput] */ HRESULT ( STDMETHODCALLTYPE *put_PCfwd )( 
            IClass1 * This,
            /* [in] */ VARIANT PCfwd);
        
        /* [helpstring][id][propget] */ HRESULT ( STDMETHODCALLTYPE *get_nu )( 
            IClass1 * This,
            /* [retval][out] */ VARIANT *nu);
        
        /* [helpstring][id][propput] */ HRESULT ( STDMETHODCALLTYPE *put_nu )( 
            IClass1 * This,
            /* [in] */ VARIANT nu);
        
        /* [helpstring][id][propget] */ HRESULT ( STDMETHODCALLTYPE *get_np )( 
            IClass1 * This,
            /* [retval][out] */ VARIANT *np);
        
        /* [helpstring][id][propput] */ HRESULT ( STDMETHODCALLTYPE *put_np )( 
            IClass1 * This,
            /* [in] */ VARIANT np);
        
        /* [helpstring][id][propget] */ HRESULT ( STDMETHODCALLTYPE *get_ny )( 
            IClass1 * This,
            /* [retval][out] */ VARIANT *ny);
        
        /* [helpstring][id][propput] */ HRESULT ( STDMETHODCALLTYPE *put_ny )( 
            IClass1 * This,
            /* [in] */ VARIANT ny);
        
        /* [helpstring][id][propget] */ HRESULT ( STDMETHODCALLTYPE *get_q )( 
            IClass1 * This,
            /* [retval][out] */ VARIANT *q);
        
        /* [helpstring][id][propput] */ HRESULT ( STDMETHODCALLTYPE *put_q )( 
            IClass1 * This,
            /* [in] */ VARIANT q);
        
        /* [helpstring][id][propget] */ HRESULT ( STDMETHODCALLTYPE *get_r )( 
            IClass1 * This,
            /* [retval][out] */ VARIANT *r);
        
        /* [helpstring][id][propput] */ HRESULT ( STDMETHODCALLTYPE *put_r )( 
            IClass1 * This,
            /* [in] */ VARIANT r);
        
        /* [helpstring][id][propget] */ HRESULT ( STDMETHODCALLTYPE *get_ys )( 
            IClass1 * This,
            /* [retval][out] */ VARIANT *ys);
        
        /* [helpstring][id][propput] */ HRESULT ( STDMETHODCALLTYPE *put_ys )( 
            IClass1 * This,
            /* [in] */ VARIANT ys);
        
        /* [helpstring][id][propget] */ HRESULT ( STDMETHODCALLTYPE *get_yspmax )( 
            IClass1 * This,
            /* [retval][out] */ VARIANT *yspmax);
        
        /* [helpstring][id][propput] */ HRESULT ( STDMETHODCALLTYPE *put_yspmax )( 
            IClass1 * This,
            /* [in] */ VARIANT yspmax);
        
        /* [helpstring][id][propget] */ HRESULT ( STDMETHODCALLTYPE *get_yspmin )( 
            IClass1 * This,
            /* [retval][out] */ VARIANT *yspmin);
        
        /* [helpstring][id][propput] */ HRESULT ( STDMETHODCALLTYPE *put_yspmin )( 
            IClass1 * This,
            /* [in] */ VARIANT yspmin);
        
        /* [helpstring][id][propget] */ HRESULT ( STDMETHODCALLTYPE *get_umax )( 
            IClass1 * This,
            /* [retval][out] */ VARIANT *umax);
        
        /* [helpstring][id][propput] */ HRESULT ( STDMETHODCALLTYPE *put_umax )( 
            IClass1 * This,
            /* [in] */ VARIANT umax);
        
        /* [helpstring][id][propget] */ HRESULT ( STDMETHODCALLTYPE *get_umin )( 
            IClass1 * This,
            /* [retval][out] */ VARIANT *umin);
        
        /* [helpstring][id][propput] */ HRESULT ( STDMETHODCALLTYPE *put_umin )( 
            IClass1 * This,
            /* [in] */ VARIANT umin);
        
        /* [helpstring][id][propget] */ HRESULT ( STDMETHODCALLTYPE *get_dumax )( 
            IClass1 * This,
            /* [retval][out] */ VARIANT *dumax);
        
        /* [helpstring][id][propput] */ HRESULT ( STDMETHODCALLTYPE *put_dumax )( 
            IClass1 * This,
            /* [in] */ VARIANT dumax);
        
        /* [helpstring][id][propget] */ HRESULT ( STDMETHODCALLTYPE *get_LTRange_h )( 
            IClass1 * This,
            /* [retval][out] */ VARIANT *LTRange_h);
        
        /* [helpstring][id][propput] */ HRESULT ( STDMETHODCALLTYPE *put_LTRange_h )( 
            IClass1 * This,
            /* [in] */ VARIANT LTRange_h);
        
        /* [helpstring][id][propget] */ HRESULT ( STDMETHODCALLTYPE *get_Bias_h )( 
            IClass1 * This,
            /* [retval][out] */ VARIANT *Bias_h);
        
        /* [helpstring][id][propput] */ HRESULT ( STDMETHODCALLTYPE *put_Bias_h )( 
            IClass1 * This,
            /* [in] */ VARIANT Bias_h);
        
        /* [helpstring][id][propget] */ HRESULT ( STDMETHODCALLTYPE *get_CV )( 
            IClass1 * This,
            /* [retval][out] */ VARIANT *CV);
        
        /* [helpstring][id][propput] */ HRESULT ( STDMETHODCALLTYPE *put_CV )( 
            IClass1 * This,
            /* [in] */ VARIANT CV);
        
        /* [helpstring][id][propget] */ HRESULT ( STDMETHODCALLTYPE *get_gamaw )( 
            IClass1 * This,
            /* [retval][out] */ VARIANT *gamaw);
        
        /* [helpstring][id][propput] */ HRESULT ( STDMETHODCALLTYPE *put_gamaw )( 
            IClass1 * This,
            /* [in] */ VARIANT gamaw);
        
        /* [helpstring][id][propget] */ HRESULT ( STDMETHODCALLTYPE *get_gamal )( 
            IClass1 * This,
            /* [retval][out] */ VARIANT *gamal);
        
        /* [helpstring][id][propput] */ HRESULT ( STDMETHODCALLTYPE *put_gamal )( 
            IClass1 * This,
            /* [in] */ VARIANT gamal);
        
        /* [helpstring][id][propget] */ HRESULT ( STDMETHODCALLTYPE *get_Gw )( 
            IClass1 * This,
            /* [retval][out] */ VARIANT *Gw);
        
        /* [helpstring][id][propput] */ HRESULT ( STDMETHODCALLTYPE *put_Gw )( 
            IClass1 * This,
            /* [in] */ VARIANT Gw);
        
        /* [helpstring][id][propget] */ HRESULT ( STDMETHODCALLTYPE *get_Gl )( 
            IClass1 * This,
            /* [retval][out] */ VARIANT *Gl);
        
        /* [helpstring][id][propput] */ HRESULT ( STDMETHODCALLTYPE *put_Gl )( 
            IClass1 * This,
            /* [in] */ VARIANT Gl);
        
        /* [helpstring][id][propget] */ HRESULT ( STDMETHODCALLTYPE *get_Gg )( 
            IClass1 * This,
            /* [retval][out] */ VARIANT *Gg);
        
        /* [helpstring][id][propput] */ HRESULT ( STDMETHODCALLTYPE *put_Gg )( 
            IClass1 * This,
            /* [in] */ VARIANT Gg);
        
        /* [helpstring][id][propget] */ HRESULT ( STDMETHODCALLTYPE *get_C )( 
            IClass1 * This,
            /* [retval][out] */ VARIANT *C);
        
        /* [helpstring][id][propput] */ HRESULT ( STDMETHODCALLTYPE *put_C )( 
            IClass1 * This,
            /* [in] */ VARIANT C);
        
        /* [helpstring][id][propget] */ HRESULT ( STDMETHODCALLTYPE *get_D )( 
            IClass1 * This,
            /* [retval][out] */ VARIANT *D);
        
        /* [helpstring][id][propput] */ HRESULT ( STDMETHODCALLTYPE *put_D )( 
            IClass1 * This,
            /* [in] */ VARIANT D);
        
        /* [helpstring][id][propget] */ HRESULT ( STDMETHODCALLTYPE *get_u0_in1 )( 
            IClass1 * This,
            /* [retval][out] */ VARIANT *u0_in1);
        
        /* [helpstring][id][propput] */ HRESULT ( STDMETHODCALLTYPE *put_u0_in1 )( 
            IClass1 * This,
            /* [in] */ VARIANT u0_in1);
        
        /* [helpstring][id][propget] */ HRESULT ( STDMETHODCALLTYPE *get_xk_1_in1 )( 
            IClass1 * This,
            /* [retval][out] */ VARIANT *xk_1_in1);
        
        /* [helpstring][id][propput] */ HRESULT ( STDMETHODCALLTYPE *put_xk_1_in1 )( 
            IClass1 * This,
            /* [in] */ VARIANT xk_1_in1);
        
        /* [helpstring][id][propget] */ HRESULT ( STDMETHODCALLTYPE *get_Fo_in1 )( 
            IClass1 * This,
            /* [retval][out] */ VARIANT *Fo_in1);
        
        /* [helpstring][id][propput] */ HRESULT ( STDMETHODCALLTYPE *put_Fo_in1 )( 
            IClass1 * This,
            /* [in] */ VARIANT Fo_in1);
        
        /* [helpstring][id][propget] */ HRESULT ( STDMETHODCALLTYPE *get_ParametrosForaDaFaixa_in1 )( 
            IClass1 * This,
            /* [retval][out] */ VARIANT *ParametrosForaDaFaixa_in1);
        
        /* [helpstring][id][propput] */ HRESULT ( STDMETHODCALLTYPE *put_ParametrosForaDaFaixa_in1 )( 
            IClass1 * This,
            /* [in] */ VARIANT ParametrosForaDaFaixa_in1);
        
        /* [helpstring][id][propget] */ HRESULT ( STDMETHODCALLTYPE *get_h_atual )( 
            IClass1 * This,
            /* [retval][out] */ VARIANT *h_atual);
        
        /* [helpstring][id][propput] */ HRESULT ( STDMETHODCALLTYPE *put_h_atual )( 
            IClass1 * This,
            /* [in] */ VARIANT h_atual);
        
        /* [helpstring][id][propget] */ HRESULT ( STDMETHODCALLTYPE *get_h_passado_in1 )( 
            IClass1 * This,
            /* [retval][out] */ VARIANT *h_passado_in1);
        
        /* [helpstring][id][propput] */ HRESULT ( STDMETHODCALLTYPE *put_h_passado_in1 )( 
            IClass1 * This,
            /* [in] */ VARIANT h_passado_in1);
        
        /* [helpstring][id][propget] */ HRESULT ( STDMETHODCALLTYPE *get_Pvaso )( 
            IClass1 * This,
            /* [retval][out] */ VARIANT *Pvaso);
        
        /* [helpstring][id][propput] */ HRESULT ( STDMETHODCALLTYPE *put_Pvaso )( 
            IClass1 * This,
            /* [in] */ VARIANT Pvaso);
        
        /* [helpstring][id][propget] */ HRESULT ( STDMETHODCALLTYPE *get_Pjus )( 
            IClass1 * This,
            /* [retval][out] */ VARIANT *Pjus);
        
        /* [helpstring][id][propput] */ HRESULT ( STDMETHODCALLTYPE *put_Pjus )( 
            IClass1 * This,
            /* [in] */ VARIANT Pjus);
        
        END_INTERFACE
    } IClass1Vtbl;

    interface IClass1
    {
        CONST_VTBL struct IClass1Vtbl *lpVtbl;
    };

    

#ifdef COBJMACROS


#define IClass1_QueryInterface(This,riid,ppvObject)	\
    ( (This)->lpVtbl -> QueryInterface(This,riid,ppvObject) ) 

#define IClass1_AddRef(This)	\
    ( (This)->lpVtbl -> AddRef(This) ) 

#define IClass1_Release(This)	\
    ( (This)->lpVtbl -> Release(This) ) 


#define IClass1_GetTypeInfoCount(This,pctinfo)	\
    ( (This)->lpVtbl -> GetTypeInfoCount(This,pctinfo) ) 

#define IClass1_GetTypeInfo(This,iTInfo,lcid,ppTInfo)	\
    ( (This)->lpVtbl -> GetTypeInfo(This,iTInfo,lcid,ppTInfo) ) 

#define IClass1_GetIDsOfNames(This,riid,rgszNames,cNames,lcid,rgDispId)	\
    ( (This)->lpVtbl -> GetIDsOfNames(This,riid,rgszNames,cNames,lcid,rgDispId) ) 

#define IClass1_Invoke(This,dispIdMember,riid,lcid,wFlags,pDispParams,pVarResult,pExcepInfo,puArgErr)	\
    ( (This)->lpVtbl -> Invoke(This,dispIdMember,riid,lcid,wFlags,pDispParams,pVarResult,pExcepInfo,puArgErr) ) 


#define IClass1_get_MWFlags(This,ppvFlags)	\
    ( (This)->lpVtbl -> get_MWFlags(This,ppvFlags) ) 

#define IClass1_put_MWFlags(This,pvFlags)	\
    ( (This)->lpVtbl -> put_MWFlags(This,pvFlags) ) 

#define IClass1_MPC_Bifasico_dll(This,nargout,Kph,SPh,exitFlag,u0,xk_1,Fo,x0,ParametrosForaDaFaixa,h_passado,TAmost,Pfwd,PCfwd,nu,np,ny,q,r,ys,yspmax,yspmin,umax,umin,dumax,LTRange_h,Bias_h,CV,gamaw,gamal,Gw,Gl,Gg,C,D,u0_in1,xk_1_in1,Fo_in1,ParametrosForaDaFaixa_in1,h_atual,h_passado_in1,Pvaso,Pjus)	\
    ( (This)->lpVtbl -> MPC_Bifasico_dll(This,nargout,Kph,SPh,exitFlag,u0,xk_1,Fo,x0,ParametrosForaDaFaixa,h_passado,TAmost,Pfwd,PCfwd,nu,np,ny,q,r,ys,yspmax,yspmin,umax,umin,dumax,LTRange_h,Bias_h,CV,gamaw,gamal,Gw,Gl,Gg,C,D,u0_in1,xk_1_in1,Fo_in1,ParametrosForaDaFaixa_in1,h_atual,h_passado_in1,Pvaso,Pjus) ) 

#define IClass1_MCRWaitForFigures(This)	\
    ( (This)->lpVtbl -> MCRWaitForFigures(This) ) 

#define IClass1_get_Kph(This,Kph)	\
    ( (This)->lpVtbl -> get_Kph(This,Kph) ) 

#define IClass1_put_Kph(This,Kph)	\
    ( (This)->lpVtbl -> put_Kph(This,Kph) ) 

#define IClass1_get_SPh(This,SPh)	\
    ( (This)->lpVtbl -> get_SPh(This,SPh) ) 

#define IClass1_put_SPh(This,SPh)	\
    ( (This)->lpVtbl -> put_SPh(This,SPh) ) 

#define IClass1_get_exitFlag(This,exitFlag)	\
    ( (This)->lpVtbl -> get_exitFlag(This,exitFlag) ) 

#define IClass1_put_exitFlag(This,exitFlag)	\
    ( (This)->lpVtbl -> put_exitFlag(This,exitFlag) ) 

#define IClass1_get_u0(This,u0)	\
    ( (This)->lpVtbl -> get_u0(This,u0) ) 

#define IClass1_put_u0(This,u0)	\
    ( (This)->lpVtbl -> put_u0(This,u0) ) 

#define IClass1_get_xk_1(This,xk_1)	\
    ( (This)->lpVtbl -> get_xk_1(This,xk_1) ) 

#define IClass1_put_xk_1(This,xk_1)	\
    ( (This)->lpVtbl -> put_xk_1(This,xk_1) ) 

#define IClass1_get_Fo(This,Fo)	\
    ( (This)->lpVtbl -> get_Fo(This,Fo) ) 

#define IClass1_put_Fo(This,Fo)	\
    ( (This)->lpVtbl -> put_Fo(This,Fo) ) 

#define IClass1_get_x0(This,x0)	\
    ( (This)->lpVtbl -> get_x0(This,x0) ) 

#define IClass1_put_x0(This,x0)	\
    ( (This)->lpVtbl -> put_x0(This,x0) ) 

#define IClass1_get_ParametrosForaDaFaixa(This,ParametrosForaDaFaixa)	\
    ( (This)->lpVtbl -> get_ParametrosForaDaFaixa(This,ParametrosForaDaFaixa) ) 

#define IClass1_put_ParametrosForaDaFaixa(This,ParametrosForaDaFaixa)	\
    ( (This)->lpVtbl -> put_ParametrosForaDaFaixa(This,ParametrosForaDaFaixa) ) 

#define IClass1_get_h_passado(This,h_passado)	\
    ( (This)->lpVtbl -> get_h_passado(This,h_passado) ) 

#define IClass1_put_h_passado(This,h_passado)	\
    ( (This)->lpVtbl -> put_h_passado(This,h_passado) ) 

#define IClass1_get_TAmost(This,TAmost)	\
    ( (This)->lpVtbl -> get_TAmost(This,TAmost) ) 

#define IClass1_put_TAmost(This,TAmost)	\
    ( (This)->lpVtbl -> put_TAmost(This,TAmost) ) 

#define IClass1_get_Pfwd(This,Pfwd)	\
    ( (This)->lpVtbl -> get_Pfwd(This,Pfwd) ) 

#define IClass1_put_Pfwd(This,Pfwd)	\
    ( (This)->lpVtbl -> put_Pfwd(This,Pfwd) ) 

#define IClass1_get_PCfwd(This,PCfwd)	\
    ( (This)->lpVtbl -> get_PCfwd(This,PCfwd) ) 

#define IClass1_put_PCfwd(This,PCfwd)	\
    ( (This)->lpVtbl -> put_PCfwd(This,PCfwd) ) 

#define IClass1_get_nu(This,nu)	\
    ( (This)->lpVtbl -> get_nu(This,nu) ) 

#define IClass1_put_nu(This,nu)	\
    ( (This)->lpVtbl -> put_nu(This,nu) ) 

#define IClass1_get_np(This,np)	\
    ( (This)->lpVtbl -> get_np(This,np) ) 

#define IClass1_put_np(This,np)	\
    ( (This)->lpVtbl -> put_np(This,np) ) 

#define IClass1_get_ny(This,ny)	\
    ( (This)->lpVtbl -> get_ny(This,ny) ) 

#define IClass1_put_ny(This,ny)	\
    ( (This)->lpVtbl -> put_ny(This,ny) ) 

#define IClass1_get_q(This,q)	\
    ( (This)->lpVtbl -> get_q(This,q) ) 

#define IClass1_put_q(This,q)	\
    ( (This)->lpVtbl -> put_q(This,q) ) 

#define IClass1_get_r(This,r)	\
    ( (This)->lpVtbl -> get_r(This,r) ) 

#define IClass1_put_r(This,r)	\
    ( (This)->lpVtbl -> put_r(This,r) ) 

#define IClass1_get_ys(This,ys)	\
    ( (This)->lpVtbl -> get_ys(This,ys) ) 

#define IClass1_put_ys(This,ys)	\
    ( (This)->lpVtbl -> put_ys(This,ys) ) 

#define IClass1_get_yspmax(This,yspmax)	\
    ( (This)->lpVtbl -> get_yspmax(This,yspmax) ) 

#define IClass1_put_yspmax(This,yspmax)	\
    ( (This)->lpVtbl -> put_yspmax(This,yspmax) ) 

#define IClass1_get_yspmin(This,yspmin)	\
    ( (This)->lpVtbl -> get_yspmin(This,yspmin) ) 

#define IClass1_put_yspmin(This,yspmin)	\
    ( (This)->lpVtbl -> put_yspmin(This,yspmin) ) 

#define IClass1_get_umax(This,umax)	\
    ( (This)->lpVtbl -> get_umax(This,umax) ) 

#define IClass1_put_umax(This,umax)	\
    ( (This)->lpVtbl -> put_umax(This,umax) ) 

#define IClass1_get_umin(This,umin)	\
    ( (This)->lpVtbl -> get_umin(This,umin) ) 

#define IClass1_put_umin(This,umin)	\
    ( (This)->lpVtbl -> put_umin(This,umin) ) 

#define IClass1_get_dumax(This,dumax)	\
    ( (This)->lpVtbl -> get_dumax(This,dumax) ) 

#define IClass1_put_dumax(This,dumax)	\
    ( (This)->lpVtbl -> put_dumax(This,dumax) ) 

#define IClass1_get_LTRange_h(This,LTRange_h)	\
    ( (This)->lpVtbl -> get_LTRange_h(This,LTRange_h) ) 

#define IClass1_put_LTRange_h(This,LTRange_h)	\
    ( (This)->lpVtbl -> put_LTRange_h(This,LTRange_h) ) 

#define IClass1_get_Bias_h(This,Bias_h)	\
    ( (This)->lpVtbl -> get_Bias_h(This,Bias_h) ) 

#define IClass1_put_Bias_h(This,Bias_h)	\
    ( (This)->lpVtbl -> put_Bias_h(This,Bias_h) ) 

#define IClass1_get_CV(This,CV)	\
    ( (This)->lpVtbl -> get_CV(This,CV) ) 

#define IClass1_put_CV(This,CV)	\
    ( (This)->lpVtbl -> put_CV(This,CV) ) 

#define IClass1_get_gamaw(This,gamaw)	\
    ( (This)->lpVtbl -> get_gamaw(This,gamaw) ) 

#define IClass1_put_gamaw(This,gamaw)	\
    ( (This)->lpVtbl -> put_gamaw(This,gamaw) ) 

#define IClass1_get_gamal(This,gamal)	\
    ( (This)->lpVtbl -> get_gamal(This,gamal) ) 

#define IClass1_put_gamal(This,gamal)	\
    ( (This)->lpVtbl -> put_gamal(This,gamal) ) 

#define IClass1_get_Gw(This,Gw)	\
    ( (This)->lpVtbl -> get_Gw(This,Gw) ) 

#define IClass1_put_Gw(This,Gw)	\
    ( (This)->lpVtbl -> put_Gw(This,Gw) ) 

#define IClass1_get_Gl(This,Gl)	\
    ( (This)->lpVtbl -> get_Gl(This,Gl) ) 

#define IClass1_put_Gl(This,Gl)	\
    ( (This)->lpVtbl -> put_Gl(This,Gl) ) 

#define IClass1_get_Gg(This,Gg)	\
    ( (This)->lpVtbl -> get_Gg(This,Gg) ) 

#define IClass1_put_Gg(This,Gg)	\
    ( (This)->lpVtbl -> put_Gg(This,Gg) ) 

#define IClass1_get_C(This,C)	\
    ( (This)->lpVtbl -> get_C(This,C) ) 

#define IClass1_put_C(This,C)	\
    ( (This)->lpVtbl -> put_C(This,C) ) 

#define IClass1_get_D(This,D)	\
    ( (This)->lpVtbl -> get_D(This,D) ) 

#define IClass1_put_D(This,D)	\
    ( (This)->lpVtbl -> put_D(This,D) ) 

#define IClass1_get_u0_in1(This,u0_in1)	\
    ( (This)->lpVtbl -> get_u0_in1(This,u0_in1) ) 

#define IClass1_put_u0_in1(This,u0_in1)	\
    ( (This)->lpVtbl -> put_u0_in1(This,u0_in1) ) 

#define IClass1_get_xk_1_in1(This,xk_1_in1)	\
    ( (This)->lpVtbl -> get_xk_1_in1(This,xk_1_in1) ) 

#define IClass1_put_xk_1_in1(This,xk_1_in1)	\
    ( (This)->lpVtbl -> put_xk_1_in1(This,xk_1_in1) ) 

#define IClass1_get_Fo_in1(This,Fo_in1)	\
    ( (This)->lpVtbl -> get_Fo_in1(This,Fo_in1) ) 

#define IClass1_put_Fo_in1(This,Fo_in1)	\
    ( (This)->lpVtbl -> put_Fo_in1(This,Fo_in1) ) 

#define IClass1_get_ParametrosForaDaFaixa_in1(This,ParametrosForaDaFaixa_in1)	\
    ( (This)->lpVtbl -> get_ParametrosForaDaFaixa_in1(This,ParametrosForaDaFaixa_in1) ) 

#define IClass1_put_ParametrosForaDaFaixa_in1(This,ParametrosForaDaFaixa_in1)	\
    ( (This)->lpVtbl -> put_ParametrosForaDaFaixa_in1(This,ParametrosForaDaFaixa_in1) ) 

#define IClass1_get_h_atual(This,h_atual)	\
    ( (This)->lpVtbl -> get_h_atual(This,h_atual) ) 

#define IClass1_put_h_atual(This,h_atual)	\
    ( (This)->lpVtbl -> put_h_atual(This,h_atual) ) 

#define IClass1_get_h_passado_in1(This,h_passado_in1)	\
    ( (This)->lpVtbl -> get_h_passado_in1(This,h_passado_in1) ) 

#define IClass1_put_h_passado_in1(This,h_passado_in1)	\
    ( (This)->lpVtbl -> put_h_passado_in1(This,h_passado_in1) ) 

#define IClass1_get_Pvaso(This,Pvaso)	\
    ( (This)->lpVtbl -> get_Pvaso(This,Pvaso) ) 

#define IClass1_put_Pvaso(This,Pvaso)	\
    ( (This)->lpVtbl -> put_Pvaso(This,Pvaso) ) 

#define IClass1_get_Pjus(This,Pjus)	\
    ( (This)->lpVtbl -> get_Pjus(This,Pjus) ) 

#define IClass1_put_Pjus(This,Pjus)	\
    ( (This)->lpVtbl -> put_Pjus(This,Pjus) ) 

#endif /* COBJMACROS */


#endif 	/* C style interface */




#endif 	/* __IClass1_INTERFACE_DEFINED__ */



#ifndef __MPC_Bifasico_dll_LIBRARY_DEFINED__
#define __MPC_Bifasico_dll_LIBRARY_DEFINED__

/* library MPC_Bifasico_dll */
/* [helpstring][version][uuid] */ 


EXTERN_C const IID LIBID_MPC_Bifasico_dll;

EXTERN_C const CLSID CLSID_Class1;

#ifdef __cplusplus

class DECLSPEC_UUID("08021CAE-00EF-4F35-8E88-A34EF930FA14")
Class1;
#endif
#endif /* __MPC_Bifasico_dll_LIBRARY_DEFINED__ */

/* Additional Prototypes for ALL interfaces */

unsigned long             __RPC_USER  VARIANT_UserSize(     unsigned long *, unsigned long            , VARIANT * ); 
unsigned char * __RPC_USER  VARIANT_UserMarshal(  unsigned long *, unsigned char *, VARIANT * ); 
unsigned char * __RPC_USER  VARIANT_UserUnmarshal(unsigned long *, unsigned char *, VARIANT * ); 
void                      __RPC_USER  VARIANT_UserFree(     unsigned long *, VARIANT * ); 

/* end of Additional Prototypes */

#ifdef __cplusplus
}
#endif

#endif


