
/*
	Copyright 2006 - 2008, All Rights Reserved.

	thunk - 动态替换CPU指令
	利用这个类可以将Windows API的回调函数封装
	成C++类成员.这份代码只能在x86的CPU上执行.

	作者	- 张鲁夺(zhangluduo)
	MSN		- zhangluduo@msn.com
	QQ群	- 34064264

	为所有爱我的人和我爱的人努力!
*/

#ifndef _THUNK_H
#define _THUNK_H

#ifndef _UNION_CAST
#define _UNION_CAST
	template <class ToType, class FromType>
	ToType union_cast (FromType f)
	{
		union 
		{
			FromType _f;
			ToType   _t;
		}	ut;
		ut._f = f;
		return ut._t;
	}
#endif

class Thunk  
{
private:

//	unsigned char m_ThiscallCode[10];
//	unsigned char m_StdcallCode [16];

	#pragma pack(push, 1)

		typedef struct		_THUNK_THISCALL
		{
			unsigned char	Mov;		// 0xB9
			unsigned long	This;		// this pointer
			unsigned char	Jmp;		// 0xE9
			unsigned long	Adrr;		// target address
		}	THUNK_THISCALL, *PTHUNK_THISCALL;

		typedef struct		_THUNK_STDCALL
		{
			unsigned char	Push[3];	// push dword ptr [esp] ;
			unsigned long	Move;		// mov	dword ptr [esp + 4], ?? ?? ?? ?? ;
			unsigned long	This;		// this pointer
			unsigned char	Jmp;		// 0xE9
			unsigned long	Adrr;		// target address
		}	THUNK_STDCALL, *PTHUNK_STDCALL;

	#pragma pack(pop)

	THUNK_THISCALL	m_THISCALL;
	THUNK_STDCALL	m_STDCALL;

public:

	template <typename T> static unsigned long GetMemberFxnAddr(T MemberFxnName)
	{
		return union_cast<unsigned long>(MemberFxnName);
	}

	void* Thiscall(void* pThis, unsigned long MemberFxnAddr);

	void* Stdcall (void* pThis, unsigned long MemberFxnAddr);
};

#endif
