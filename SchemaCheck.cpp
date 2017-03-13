#include "SchemaCheck.h"

SchemaCheck::SchemaCheck()
{
}


SchemaCheck::~SchemaCheck()
{
}
int SchemaCheck::FileCheck()
{
	////xmlfile.replace("/", "\\");
	//std::string str1 = xmlfile.toStdString();

	//const char* chxml = str1.c_str();
	////stdfile.replace("/", "\\");
	//std::string str2 = stdfile.toStdString();

	//const char* chstd = str2.c_str();
	//char *chstr;
	//char *cherr;
	//char *chexper;
	//QString str;
	//QString strerror;
	//QString strexper;
	////系统初始化  
	//try
	//{
	//	XMLPlatformUtils::Initialize();
	//}
	//catch (const XMLException &xe)
	//{
	//	printf("%s", (const char*)xe.getMessage());

	//	return -1;
	//}

	//// 创建解析器  
	//SAX2XMLReader* parser = XMLReaderFactory::createXMLReader();

	////设置名称空间属性, 如果没有如下两行则忽略名称空间 及名称空间前缀  
	//parser->setFeature(XMLUni::fgSAX2CoreNameSpaces, false);
	//parser->setFeature(XMLUni::fgSAX2CoreNameSpacePrefixes, false);

	////设置验证属性  
	//parser->setFeature(XMLUni::fgXercesValidationErrorAsFatal, true);
	//parser->setFeature(XMLUni::fgSAX2CoreValidation, true);
	//parser->setFeature(XMLUni::fgXercesSchema, true);
	//parser->setFeature(XMLUni::fgXercesSchemaFullChecking, true);

	////加载XSD文件  
	//parser->loadGrammar(chstd, Grammar::SchemaGrammarType, true);
	//parser->setFeature(XMLUni::fgXercesUseCachedGrammarInParse, true);
	//int errorCount = 0;
	//int errorCode = 0;
	////定义打印对象  
	//try
	//{

	//	SAX2PrintHandlers handler("UTF-8", XMLFormatter::UnRep_CharRef, false);

	//	//设置内容打印函数: 如果没有这行,则不打印出XML文档内容  
	//	parser->setContentHandler(&handler);

	//	//设置错误打印函数: 如果没有这行,则不打印错误信息  
	//	parser->setErrorHandler(&handler);

	//	//解析并验证XML文档  
	//	parser->parse(chxml);
	//	errorCode = parser->getErrorCount();
	//}
	//catch (const OutOfMemoryException &ome)
	//{
	//	printf(cherr, (const char*)ome.getMessage());
	//	
	//	
	//}
	//catch (const XMLException &xe)
	//{
	//	printf(chexper, (const char*)xe.getMessage());
	//}
	//ULONG_PTR count;
	//count = parser->getErrorCount();
	//printf("Error count: %d/n", parser->getErrorCount());

	//delete parser;

	//XMLPlatformUtils::Terminate();

	return 0;
}
void SchemaCheck::setstdfile(QString str)
{
	stdfile = str;
}
void SchemaCheck::setxmlfile(QString str)
{
	xmlfile = str;
}
