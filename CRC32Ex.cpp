
/*
	Copyright 2006 - 2008, All Rights Reserved.

	CRC32类之扩展

	作者	- 张鲁夺(zhangluduo)
	MSN		- zhangluduo@msn.com
	QQ群	- 34064264

	为所有爱我的人和我爱的人努力!
*/


#include "CRC32Ex.h"

CRC32Ex::CRC32Ex()
{

}

CRC32Ex::~CRC32Ex()
{

}

//void CRC32Ex::OnFileProcessing(int nProgress, MemberFxn addr)
//{
//	void*			pThis	= addr.GetThis();
//	unsigned long	Addr	= addr.GetAddr();

//	/** the Calling Convention must be __stdcall or
//		thiscall (thiscall not a keyword),
//		thiscall is the default calling convention used by C++ member functions
//	*/
//	__asm
//	{
//		push	nProgress	;
//	 	mov		ecx, pThis	;
//		call	Addr		;
//	}
//}

void CRC32Ex::StopCalcFile()
{
	m_bTerminate = true;
}

string CRC32Ex::GetError()
{
	return m_strErr;
}

//string CRC32Ex::GetCRC32FromFile(char* FileName, bool bUpper, MemberFxn addr)
//{
//	FILE *file							= 0;
//	unsigned char buffer[BUFFER_SIZE]	= { 0 };
//	m_bTerminate						= false;
//	m_strErr							= "";
	
//	try
//	{
//		if ((file = fopen (FileName, "rb")) == NULL)
//		{
//			m_strErr = "The file can't be opened!";
//			return "";
//		}
//		else
//		{
//			int len					= 0;
//			int ReadCount			= 0;
//			unsigned long nFileSize = 0;

//			// 获取文件大小, 以下方式只能获取小于2^32字节的文件大小
//			{
//				HANDLE hFile = CreateFile(FileName, NULL, FILE_SHARE_READ, NULL, OPEN_EXISTING,FILE_ATTRIBUTE_NORMAL, 0);
//				if(hFile== NULL)
//				{
//					m_strErr = "Get file size failed!";
//					return "";
//				}
//				nFileSize=::GetFileSize(hFile, NULL);
//				CloseHandle(hFile);
//			}

//			if(!addr.IsNull())
//				OnFileProcessing(0, addr);

//			unsigned long CRCResult;
//			CRCInit(CRCResult);

//			while (len = fread (buffer, 1, BUFFER_SIZE, file))
//			{
//				ReadCount++;

//				if(m_bTerminate)
//				{
//					m_strErr = "User terminate calculate!";
//					return "";
//				}
				
//				CRCUpdate((unsigned char *)buffer, len, CRCResult);

//				if(!addr.IsNull())
//				{
//					int n = (int)(nFileSize / 100);
//					if(n <= 0)
//						n = 1;
//					OnFileProcessing((int)(BUFFER_SIZE * ReadCount / n), addr);
//				}

//				memset(buffer, 0, BUFFER_SIZE);
//			}

//			CRCFinal(CRCResult);

//			if(!addr.IsNull())
//				OnFileProcessing(100, addr);

//			fclose (file);
//			return ResultToHex(CRCResult, bUpper);
//		}
//	}
//	catch(...)
//	{
//		m_strErr = "UnKnow error!";
//		return "";
//	}
//}

string CRC32Ex::ResultToHex(unsigned long Result, bool bUpper)
{
	char buf[10] = { 0 };
	if(bUpper)
		sprintf(buf, "%.8X", Result);
	else 
		sprintf(buf, "%.8x", Result);
	return string(buf);
}

string CRC32Ex::GetCRC32FromBuffer	(unsigned char* pData, unsigned long DataLen, bool bUpper)
{
	m_strErr = "";
	unsigned long CRCResult;
	CRCInit(CRCResult);
    CRCUpdate((char*)pData, DataLen, CRCResult);
	CRCFinal(CRCResult);
	return ResultToHex(CRCResult, bUpper);
}
