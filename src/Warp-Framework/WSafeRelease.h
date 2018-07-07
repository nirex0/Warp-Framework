// © 2018 NIREX ALL RIGHTS RESERVED

#ifndef _W_SAFE_RELEASE_H_
#define _W_SAFE_RELEASE_H_

template <class T> 
void SafeRelease(T** ppT)
{
    if (*ppT)
    {
        (*ppT)->Release();
        *ppT = nullptr;
    }
}

#endif // !_W_SAFE_RELEASE_H_
