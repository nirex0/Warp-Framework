// © 2018 NIREX ALL RIGHTS RESERVED

#ifndef _W_SAFE_RELEASE_H_
#define _W_SAFE_RELEASE_H_

#include "WWin.h"

template <class T> 
HRESULT SafeRelease(T** ppResource)
{
    if (*ppResource)
    {
        (*ppResource)->Release();
        *ppResource = nullptr;
		return S_OK;
    }
	return E_ABORT;
}

#endif // !_W_SAFE_RELEASE_H_
