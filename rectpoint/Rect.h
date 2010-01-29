	
// Rect.h : Declaration of the CRect

#ifndef __RECT_H_
#define __RECT_H_

#include "resource.h"       // main symbols
/////////////////////////////////////////////////////////////////////////////
// CRect
class ATL_NO_VTABLE CRect : 
	public CComObjectRootEx<CComSingleThreadModel>,
	public CComCoClass<CRect, &CLSID_Rect>,
	public IRect
{
public:
 CRect(): m_topLeft(0), m_bottomRight(0)
    {
      IPoint *pPoint = 0;
      HRESULT hr = CoCreateInstance(CLSID_Point, 0, CLSCTX_ALL,
				    IID_IPoint, (void**)&pPoint);
      if (SUCCEEDED(hr))
	{
	  m_topLeft = pPoint;
	}
      hr = CoCreateInstance(CLSID_Point, 0, CLSCTX_ALL,
			    IID_IPoint, (void**)&pPoint);
      if (SUCCEEDED(hr))
	{
	  m_bottomRight = pPoint;
	}
    }
  ~CRect()
    {
      if(m_topLeft) m_topLeft->Release();
      if(m_bottomRight) m_bottomRight->Release();
    }
  

DECLARE_REGISTRY_RESOURCEID(IDR_RECT)
DECLARE_NOT_AGGREGATABLE(CRect)

BEGIN_COM_MAP(CRect)
	COM_INTERFACE_ENTRY(IRect)
END_COM_MAP()

// IRect
public:
	STDMETHOD(get_Volume)(/*[out, retval]*/ long *pVal);
	STDMETHOD(SetCoords)(/*[in]*/ long left, /*[in]*/ long top, /*[in]*/ long right, /*[in]*/ long bottom);
	STDMETHOD(SetCoords2)(SPoint topLeft, SPoint botRight);
	STDMETHOD(SetCoords3)(SPoint * topLeft, SPoint * botRight);
	STDMETHOD(SetCoords4)(IPoint * topLeft, IPoint * botRight);
	STDMETHOD(GetCoords)(SPoint * topLeft, SPoint * botRight);
	STDMETHOD(GetCoords2)(IPoint ** topLeft, IPoint ** botRight);
	STDMETHOD(DrawRect)(/* [in] */ RECTTYPE type, /* [retval][out] */ long *res);
private:
	IPoint *m_topLeft;
	IPoint *m_bottomRight;
};

#endif //__RECT_H_
