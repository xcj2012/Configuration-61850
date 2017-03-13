
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

#include "Thunk.h" 

void* Thunk::Thiscall(void* pThis, unsigned long MemberFxnAddr)
{
//	Encoded machine instruction   Equivalent assembly languate notation
//	---------------------------   -------------------------------------
//	B9 ?? ?? ?? ??                mov    ecx, pThis  ; Load ecx with this pointer
//	E9 ?? ?? ?? ??                jmp    target addr ; Jump to target message handler

//	unsigned long JmpAddr					= MemberFxnAddr - (unsigned long) &m_ThiscallCode - sizeof(m_ThiscallCode);
//	m_ThiscallCode[0]						= 0xB9;
//	m_ThiscallCode[5]						= 0xE9;
//	*((unsigned long *) &m_ThiscallCode[1]) = (unsigned long) pThis;
//	*((unsigned long *) &m_ThiscallCode[6]) = JmpAddr;
//
//	return (void*)m_ThiscallCode;

	m_THISCALL.Mov	= 0xB9;
	m_THISCALL.This	= (unsigned long) pThis;
	m_THISCALL.Jmp	= 0xE9;
	m_THISCALL.Adrr	= MemberFxnAddr - (unsigned long)&m_THISCALL - sizeof(THUNK_THISCALL);

	return (void*)(&m_THISCALL);
}

void* Thunk::Stdcall(void* pThis, unsigned long MemberFxnAddr)
{
//	Encoded machine instruction   Equivalent assembly languate notation
//	---------------------------   -------------------------------------
//	FF 34 24                      push  dword ptr [esp]				; Save (or duplicate)
//																	; the return Address into stack
//	C7 44 24 04 ?? ?? ?? ??       mov   dword ptr [esp+4], pThis	; Overwite the old; 
//																	; Return Address with 'this pointer'
//	E9 ?? ?? ?? ??                jmp   target addr					; Jump to target message handler

//	unsigned long JmpAddr					= MemberFxnAddr - (unsigned long) &m_StdcallCode - sizeof(m_StdcallCode);
//	m_StdcallCode[11]						= 0xE9; 
//	*((unsigned long *) &m_StdcallCode[ 0]) = 0x002434FF;
//	*((unsigned long *) &m_StdcallCode[ 3]) = 0x042444C7;
//	*((unsigned long *) &m_StdcallCode[ 7]) = (unsigned long) pThis;
//	*((unsigned long *) &m_StdcallCode[12]) = JmpAddr;
//
//	return (void*)m_StdcallCode;

	m_STDCALL.Push[0]	= 0xFF;
	m_STDCALL.Push[1]	= 0x34;
	m_STDCALL.Push[2]	= 0x24;
	m_STDCALL.Move		= 0x042444C7;
	m_STDCALL.This		= (unsigned long) pThis;
	m_STDCALL.Jmp		= 0xE9;
	m_STDCALL.Adrr		= MemberFxnAddr - (unsigned long)&m_STDCALL - sizeof(THUNK_STDCALL);

	return (void*)(&m_STDCALL);
}
