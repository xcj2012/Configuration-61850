
/*
	Copyright 2006 - 2008, All Rights Reserved.

	CRC32类之扩展

	作者	- 张鲁夺(zhangluduo)
	MSN		- zhangluduo@msn.com
	QQ群	- 34064264

	为所有爱我的人和我爱的人努力!
*/

#ifndef _CRC32EX_H
#define _CRC32EX_H

#include "CRC32.h"
#include "MemberFxn.h"

#pragma warning(disable : 4786)
#include <string>
using namespace std;

#define BUFFER_SIZE 1024

class CRC32Ex : public CRC32
{
public:

	CRC32Ex();
	virtual ~CRC32Ex();

private:

	string	m_strErr;		// 错误描述
	bool	m_bTerminate;	// 终止文件计算标志

	void OnFileProcessing(int nProgress, MemberFxn addr);
	string ResultToHex(unsigned long Result, bool bUpper = true);

public:

	// 获取文件的CRC32值
	string GetCRC32FromFile (char* FileName, bool bUpper = true, MemberFxn addr = 0);

	// 获取内存数据的CRC32值
	string GetCRC32FromBuffer(unsigned char* pData, unsigned long DataLen, bool bUpper = true);

	// 此函数可提前结束GetCRC32FromFile函数的执行
	void	StopCalcFile();

	// 获取错误描述
	string GetError();
};

#endif