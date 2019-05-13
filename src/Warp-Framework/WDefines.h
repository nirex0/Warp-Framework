// © 2019 NIREX ALL RIGHTS RESERVED

#ifndef _W_DEFINES_H_
#define _W_DEFINES_H_

#define WDBG
#define W_CALL					__stdcall
#define W_ENTRY					__stdcall
#define WARP_CALL				__stdcall
#define WARP_ENTRY				__stdcall

// Used to determine whether warp should load its configuration from config.cfg or not.
#define W_USE_CONFIG

#define WARP_FRAMEWORK
#define W_FRAMEWORK
#define WARP

typedef int						W_INT;
typedef char					W_CHAR;
typedef long					W_LONG;
typedef long long				W_LONGLONG;

typedef int						W_SBYTE;
typedef char					W_SWORD;
typedef long					W_SDWORD;
typedef long long				W_SQWORD;

typedef unsigned int			W_UINT;
typedef unsigned char			W_UCHAR;
typedef unsigned long			W_ULONG;
typedef unsigned long long		W_ULONGLONG;

typedef unsigned char			W_BYTE;
typedef unsigned short			W_WORD;
typedef unsigned long			W_DWORD;
typedef unsigned long long		W_QWORD;

typedef signed char				W_INT8;
typedef short					W_INT16;
typedef int						W_INT32;
typedef long long				W_INT64;

typedef unsigned long			W_STYLE;
typedef float					W_FLOAT;
typedef double					W_DOUBLE;
typedef double					DELTATIME;

typedef struct					W_8BSCT
{
	bool BIT0 : 1;
	bool BIT1 : 1;
	bool BIT2 : 1;
	bool BIT3 : 1;
	bool BIT4 : 1;
	bool BIT5 : 1;
	bool BIT6 : 1;
	bool BIT7 : 1;
} W_8BSTR;

typedef union					W_BYTE_EX
{
	W_BYTE Byte;
	W_8BSCT Bits;
}W_BYTE_EX;

typedef union					W_WORD_EX
{
	struct Bytes
	{
		W_BYTE_EX BYTE0;
		W_BYTE_EX BYTE1;
	} Bytes;
}W_WORD_EX;

typedef union					W_DWORD_EX
{
	struct Bytes
	{
		W_BYTE_EX BYTE0;
		W_BYTE_EX BYTE1;
		W_BYTE_EX BYTE2;
		W_BYTE_EX BYTE3;
	} Bytes;
}W_DWORD_EX;

typedef union					W_QWORD_EX
{
	struct Bytes
	{
		W_BYTE_EX BYTE0;
		W_BYTE_EX BYTE1;
		W_BYTE_EX BYTE2;
		W_BYTE_EX BYTE3;
		W_BYTE_EX BYTE4;
		W_BYTE_EX BYTE5;
		W_BYTE_EX BYTE6;
		W_BYTE_EX BYTE7;
	} Bytes;
}W_QWORD_EX;

typedef enum WMouseKey
{
	MK_INVALID,
	MK_RIGHT,
	MK_LEFT,
	MK_MIDDLE
}WMouseKey;

#endif // !_W_DEFINES_H_
