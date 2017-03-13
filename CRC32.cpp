
/*
	Copyright 2006 - 2008, All Rights Reserved.

	CRC32算法实现

	作者	- 张鲁夺(zhangluduo)
	MSN		- zhangluduo@msn.com
	QQ群	- 34064264

	为所有爱我的人和我爱的人努力!
*/


#include "CRC32.h"

CRC32::CRC32()
{
	// init CRC-32 table
    // This is the official polynomial used by CRC-32
    unsigned long ulPolynomial = 0x04C11DB7;

    // 256 values representing ASCII character codes.
    for (int i = 0; i <= 0xFF; i++)
    {
        m_Table[i] = Reflect(i, 8) << 24;
        for (int j = 0; j < 8; j++)
            m_Table[i] = (m_Table[i] << 1) ^ (m_Table[i] & (1 << 31) ? ulPolynomial : 0);
        m_Table[i] = Reflect(m_Table[i], 32);
    }
}

CRC32::~CRC32()
{

}

unsigned long CRC32::Reflect(unsigned long ref, char ch)
{
    unsigned long value = 0;

    // Swap bit 0 for bit 7, bit 1 for bit 6, etc.
    for(int i = 1; i < (ch + 1); i++)
    {
        if (ref & 1)
            value |= 1 << (ch - i);
        ref >>= 1;
    }
    return value;
}

void CRC32::CRCUpdate( char* buffer, unsigned long size, unsigned long &Result)
{
    while (size--)
        Result = (Result >> 8) ^ m_Table[(Result & 0xFF) ^ *buffer++];
}

void CRC32::CRCInit(unsigned long &Result)
{
	Result = 0xFFFFFFFF;
}
void CRC32::CRCFinal(unsigned long &Result)
{
	Result ^= 0xFFFFFFFF;
}