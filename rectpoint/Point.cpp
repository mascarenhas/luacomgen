// Point.cpp : Implementation of CPoint
#include <assert.h>
#include "stdafx.h"
#include "RectPoint.h"
#include "Point.h"

/////////////////////////////////////////////////////////////////////////////
// CPoint


STDMETHODIMP CPoint::GetCoords(long * px, long * py)
{
    *px = m_x;
    *py = m_y;
	return S_OK;
}

STDMETHODIMP CPoint::SetCoords(long x, long y)
{
    m_x = x;
    m_y = y;
	return S_OK;
}

STDMETHODIMP CPoint::SetCoords2(/*[in]*/ VARIANT x, /*[in]*/ VARIANT y) {
  VARIANT vx, vy;
  VariantInit(&vx);
  VariantInit(&vy);
  VariantChangeType(&vx, &x, 0, VT_I4); 
  VariantChangeType(&vy, &y, 0, VT_I4);
  m_x = vx.lVal;
  m_y = vy.lVal;
  VariantClear(&vx);
  VariantClear(&vy);
  return S_OK;
}

STDMETHODIMP CPoint::GetCoords2(/*[out]*/ VARIANT *px, /*[out]*/ VARIANT *py) {
  px->vt = VT_I4;
  px->lVal = m_x;
  py->vt = VT_I4;
  py->lVal = m_y;
  return S_OK;
}

STDMETHODIMP CPoint::SetGetCoords(/*[out]*/ VARIANT *px, /*[out]*/ VARIANT *py) {
  long x, y;
  VARIANT vx, vy;
  VariantInit(&vx);
  VariantInit(&vy);
  VariantChangeType(&vx, px, 0, VT_I4); 
  VariantChangeType(&vy, py, 0, VT_I4);
  x = m_x;
  y = m_y;
  m_x = vx.lVal;
  m_y = vy.lVal;
  vx.vt = VT_I4;
  vx.lVal = x;
  vy.vt = VT_I4;
  vy.lVal = y;
  VariantChangeType(px, &vx, 0, px->vt);
  VariantChangeType(py, &vy, 0, py->vt);
  VariantClear(&vx);
  VariantClear(&vy);
  return S_OK;
}

STDMETHODIMP CPoint::GetType(/*[out, retval]*/ VARIANT *t) {
  t->vt = VT_BSTR;
  t->bstrVal = SysAllocString(OLESTR("Point"));
  return S_OK;
}

STDMETHODIMP CPoint::RoundTrip(VARIANT s1, /*[out, retval]*/ VARIANT *s2) {
  VariantCopy(s2, &s1);
  return S_OK;
}

STDMETHODIMP CPoint::GetType2(/*[out, retval]*/ BSTR *t) {
  *t = SysAllocString(OLESTR("Point"));
  return S_OK;
}

STDMETHODIMP CPoint::RoundTrip2(BSTR s1, /*[out, retval]*/ BSTR *s2) {
  *s2 = SysAllocString(s1);
  return S_OK;
}

STDMETHODIMP CPoint::GetType3(/*[out, retval]*/ LPTSTR *t) {
  *t = _T("Point");
  return S_OK;
}

STDMETHODIMP CPoint::RoundTrip3(LPTSTR s1, /*[out, retval]*/ LPTSTR *s2) {
  *s2 = s1;
  return S_OK;
}

STDMETHODIMP CPoint::GetType4(/*[out, retval]*/ LPWSTR *t) {
  *t = L"Point";
  return S_OK;
}

STDMETHODIMP CPoint::RoundTrip4(LPWSTR s1, /*[out, retval]*/ LPWSTR *s2) {
  *s2 = s1;
  return S_OK;
}

STDMETHODIMP CPoint::GetType5(/*[out, retval]*/ LPSTR *t) {
  *t = "Point";
  return S_OK;
}

STDMETHODIMP CPoint::RoundTrip5(LPSTR s1, /*[out, retval]*/ LPSTR *s2) {
  *s2 = s1;
  return S_OK;
}

STDMETHODIMP CPoint::Sum(SAFEARRAY **ppsa, /*[out, retval]*/ long *pSum) {
  assert(ppsa && *ppsa && pSum);
  assert(SafeArrayGetDim(*ppsa) == 1);
  long ubound, lbound;
  HRESULT hr = SafeArrayGetUBound(*ppsa, 1, &ubound);
  assert(SUCCEEDED(hr));
  hr = SafeArrayGetLBound(*ppsa, 1, &lbound);
  assert(SUCCEEDED(hr));
  long *prgn;
  hr = SafeArrayAccessData(*ppsa, (void**)&prgn);
  assert(SUCCEEDED(hr));
  *pSum = 0;
  for (long i = lbound; i <= ubound; i++)
    *pSum += prgn[i];
  SafeArrayUnaccessData(*ppsa);
  return S_OK;
}

STDMETHODIMP CPoint::GetCoordsArr(SAFEARRAY **ppsa) {
  if(!ppsa) return E_INVALIDARG;
  *ppsa = SafeArrayCreateVector(VT_I4, 0, 2);
  if(!*ppsa) return E_INVALIDARG;
  long *prgn = 0;
  HRESULT hr = SafeArrayAccessData(*ppsa, (void**)&prgn);
  if(!SUCCEEDED(hr)) return hr;
  prgn[0] = m_x;
  prgn[1] = m_y;
  SafeArrayUnaccessData(*ppsa);
  return S_OK;
}
