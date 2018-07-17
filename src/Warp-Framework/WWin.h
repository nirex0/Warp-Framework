// © 2018 NIREX ALL RIGHTS RESERVED

#ifndef _W_WIN_H_
#define _W_WIN_H_

#ifndef _STD_WINDOWS_H_
#define _STD_WINDOWS_H_

#undef WINVER 
#define WINVER 0x0501

#undef _WIN32_WINNT 
#define _WIN32_WINNT 0x0501

#define WIN32_LEAN_AND_MEAN
#define NOGDICAPMASKS
#define NOMENUS
#define NOICONS
#define NOSYSCOMMANDS
#define NORASTEROPS
#define OEMRESOURCE
#define NOATOM
#define NOCLIPBOARD
#define NOCOLOR
#define NOCTLMGR
#define NODRAWTEXT
#define NOKERNEL
#define NONLS
#define NOMEMMGR
#define NOMETAFILE
#define NOMINMAX
#define NOOPENFILE
#define NOSCROLL
#define NOSERVICE
#define NOSOUND
#define NOTEXTMETRIC
#define NOWH
#define NOCOMM
#define NOKANJI
#define NOHELP
#define NOPROFILER
#define NODEFERWINDOWPOS
#define NOMCX
#define NORPC
#define NOPROXYSTUB
#define NOIMAGE
#define NOTAPE

#include <Windows.h>
#endif // !_STD_WINDOWS_H_

#endif // !_W_WIN_H_

