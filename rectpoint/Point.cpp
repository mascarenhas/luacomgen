// Point.cpp : Implementation of CPoint
#include "stdafx.h"
#include <assert.h>
#include <math.h>
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

STDMETHODIMP CPoint::RoundTrip3(LPCTSTR s1, /*[out, retval]*/ LPTSTR *s2) {
  *s2 = (LPTSTR)s1;
  return S_OK;
}

STDMETHODIMP CPoint::GetType4(/*[out, retval]*/ LPWSTR *t) {
  *t = L"Point";
  return S_OK;
}

STDMETHODIMP CPoint::RoundTrip4(LPCWSTR s1, /*[out, retval]*/ LPWSTR *s2) {
  *s2 = (LPWSTR)s1;
  return S_OK;
}

STDMETHODIMP CPoint::GetType5(/*[out, retval]*/ LPSTR *t) {
  *t = "Point";
  return S_OK;
}

STDMETHODIMP CPoint::RoundTrip5(LPCSTR s1, /*[out, retval]*/ LPSTR *s2) {
  *s2 = (LPSTR)s1;
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

STDMETHODIMP CPoint::GetCoordsArr2(/*out, retval */ VARIANT *pvar) {
  assert(pvar);
  pvar->vt = VT_ARRAY | VT_I4;
  pvar->parray = SafeArrayCreateVector(VT_I4, 0, 2);
  if(!pvar->parray) return E_INVALIDARG;
  long *prgn = 0;
  HRESULT hr = SafeArrayAccessData(pvar->parray, (void**)&prgn);
  if(!SUCCEEDED(hr)) return hr;
  prgn[0] = m_x;
  prgn[1] = m_y;
  SafeArrayUnaccessData(pvar->parray);
  return S_OK;
}

STDMETHODIMP CPoint::Sum2(/* in */ VARIANT var, /*[out, retval]*/ long *pSum) {
  assert(pSum);
  assert(var.vt == (VT_ARRAY | VT_I4));
  SAFEARRAY *psa = var.parray;
  assert(SafeArrayGetDim(psa) == 1);
  long ubound, lbound;
  HRESULT hr = SafeArrayGetUBound(psa, 1, &ubound);
  assert(SUCCEEDED(hr));
  hr = SafeArrayGetLBound(psa, 1, &lbound);
  assert(SUCCEEDED(hr));
  long *prgn;
  hr = SafeArrayAccessData(psa, (void**)&prgn);
  assert(SUCCEEDED(hr));
  *pSum = 0;
  for (long i = lbound; i <= ubound; i++)
    *pSum += prgn[i];
  SafeArrayUnaccessData(psa);
  return S_OK;
}

STDMETHODIMP CPoint::Length(/* in */ VARIANT var, /*[out, retval]*/ double *pSum) {
  assert(pSum);
  assert(var.vt == (VT_ARRAY | VT_UNKNOWN));
  SAFEARRAY *psa = var.parray;
  assert(SafeArrayGetDim(psa) == 1);
  long ubound, lbound;
  HRESULT hr = SafeArrayGetUBound(psa, 1, &ubound);
  if(!SUCCEEDED(hr)) return hr;
  hr = SafeArrayGetLBound(psa, 1, &lbound);
  if(!SUCCEEDED(hr)) return hr;
  IUnknown **prgn;
  hr = SafeArrayAccessData(psa, (void**)&prgn);
  if(!SUCCEEDED(hr)) return hr;
  *pSum = 0;
  for (long i = lbound + 1; i <= ubound; i++) {
    IPoint *p1, *p2;
    hr = prgn[i-1]->QueryInterface(IID_IPoint, (void**)&p1);
    if(!SUCCEEDED(hr)) return hr;
    hr = prgn[i]->QueryInterface(IID_IPoint, (void**)&p2);
    if(!SUCCEEDED(hr)) return hr;
    long x1, x2, y1, y2;
    hr = p1->GetCoords(&x1, &y1);
    if(!SUCCEEDED(hr)) return hr;
    hr = p2->GetCoords(&x2, &y2);
    if(!SUCCEEDED(hr)) return hr;
    *pSum += sqrt(pow((double)(x2-x1), 2.0) + pow((double)(y2-y1), 2.0));
    p1->Release();
    p2->Release();
  }
  SafeArrayUnaccessData(psa);
  return S_OK;
}
