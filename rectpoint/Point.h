// Point.h : Declaration of the CPoint

#ifndef __POINT_H_
#define __POINT_H_

#include "resource.h"       // main symbols

/////////////////////////////////////////////////////////////////////////////
// CPoint
class ATL_NO_VTABLE CPoint : 
	public CComObjectRootEx<CComSingleThreadModel>,
	public CComCoClass<CPoint, &CLSID_Point>,
	IPoint
{
public:
    CPoint() : m_x(0), m_y(0)
	{
	}

DECLARE_REGISTRY_RESOURCEID(IDR_POINT)
DECLARE_NOT_AGGREGATABLE(CPoint)

BEGIN_COM_MAP(CPoint)
	COM_INTERFACE_ENTRY(IPoint)
END_COM_MAP()

// IPoint
public:
	STDMETHOD(SetCoords)(/*[in]*/ long x, /*[in]*/ long y);
	STDMETHOD(SetCoords2)(/*[in]*/ VARIANT x, /*[in]*/ VARIANT y);
	STDMETHOD(GetCoords)(/*[out]*/ long *px, /*[out]*/ long *py);
	STDMETHOD(GetCoords2)(/*[out]*/ VARIANT *px, /*[out]*/ VARIANT *py);
	STDMETHOD(SetGetCoords)(/*[out]*/ VARIANT *px, /*[out]*/ VARIANT *py);
	STDMETHOD(GetType)(/*[out, retval]*/ VARIANT *t);
	STDMETHOD(RoundTrip)(VARIANT s1, /*[out, retval]*/ VARIANT *s2);
	STDMETHOD(GetType2)(/*[out, retval]*/ BSTR *t);
	STDMETHOD(RoundTrip2)(BSTR s1, /*[out, retval]*/ BSTR *s2);
	STDMETHOD(GetType3)(/*[out, retval]*/ LPTSTR *t);
	STDMETHOD(RoundTrip3)(LPCTSTR s1, /*[out, retval]*/ LPTSTR *s2);
	STDMETHOD(GetType4)(/*[out, retval]*/ LPWSTR *t);
	STDMETHOD(RoundTrip4)(LPCWSTR s1, /*[out, retval]*/ LPWSTR *s2);
	STDMETHOD(GetType5)(/*[out, retval]*/ LPSTR *t);
	STDMETHOD(RoundTrip5)(LPCSTR s1, /*[out, retval]*/ LPSTR *s2);
	STDMETHOD(Sum)(SAFEARRAY **ppsa, /*[out, retval]*/ long *pSum);
	STDMETHOD(GetCoordsArr)(SAFEARRAY **ppsa);
	STDMETHOD(Sum2)(VARIANT var, /*[out, retval]*/ long *pSum);
	STDMETHOD(GetCoordsArr2)(VARIANT *pvar);
	STDMETHOD(Length)(VARIANT var, /*[out, retval]*/ double *pSum);
private:
	long m_x;
	long m_y;
};

#endif //__POINT_H_
