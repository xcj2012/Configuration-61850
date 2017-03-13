#pragma once
#include <string.h>
#include "mainwindow.h"
//#if defined(XERCES_NEW_IOSTREAMS)
//#include <iostream>
//#else
//#include <iostream.h>
//#endif
//#include <stdlib.h>
//#include "SAX2Print.hpp"
//BEGIN_MESSAGE_MAP(SchemaCheck, SAX2PrintHandlers)
//	//{{AFX_MSG_MAP(CShellDlg)  
//	ON_MESSAGE(ERROR_MSG, SchemaCheck::setstdfile()) //自定义消息  
//	ON_MESSAGE(WARNING_MSG, SchemaCheck::setstdfile())     //自定义消息  
//
//	//}}AFX_MSG_MAP  
//END_MESSAGE_MAP()
class SchemaCheck
{
public:
	SchemaCheck();
	int FileCheck();
	~SchemaCheck();
	void setxmlfile(QString str);
	void setstdfile(QString str);
private:
	QString xmlfile;
	QString stdfile;
};

