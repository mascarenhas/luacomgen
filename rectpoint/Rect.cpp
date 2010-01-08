// Rect.cpp : Implementation of CRect
#include "stdafx.h"
#include "RectPoint.h"
#include "Rect.h"
#include <assert.h>
/////////////////////////////////////////////////////////////////////////////
// CRect

STDMETHODIMP CRect::SetCoords(long left, long top, long right, long bottom)
{
    HRESULT hr = S_OK;
    if(m_topLeft)
      hr = m_topLeft->SetCoords(left, top);
    if (FAILED(hr))
      return hr;
    if(m_bottomRight)
      hr = m_bottomRight->SetCoords(right, bottom);
    return hr;
}

STDMETHODIMP CRect::get_Volume(long * pVal)
{
    HRESULT hr = S_OK;
    *pVal = 0;
    long top, left, right, bottom;
    if(m_topLeft)
      hr = m_topLeft->GetCoords(&left, &top);
    if (SUCCEEDED(hr)) {
      if(m_bottomRight)
	hr = m_bottomRight->GetCoords(&right, &bottom);
    }
    if (SUCCEEDED(hr))
      *pVal = (right - left) * (bottom - top);
    return hr;
}
