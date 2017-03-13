#include "mainwindow.h"
#include "ui_mainwindow.h"
#include <QDebug>
#include <stdio.h>  
#include <xercesc/util/PlatformUtils.hpp>
#include <xercesc/util/TransService.hpp>
#include <xercesc/sax2/SAX2XMLReader.hpp>
#include <xercesc/sax2/XMLReaderFactory.hpp>
#include "SAX2Print.hpp"
#include <xercesc/util/OutOfMemoryException.hpp>
#include <QFileInfo>
XERCES_CPP_NAMESPACE_USE
void MainWindow::Action_Integrity_Check()
{
	QString   fileName = QFileDialog::getOpenFileName(this,
		tr("Open File"), QDir::currentPath(), tr("CID Files (*.CID *.ICD )"));
	if (!fileName.isEmpty())
	{
        QFileInfo m_file =QFileInfo(fileName);
		File_Integrity_Check(fileName);
        QStringList ErrorList;
        QDir dir;
        QString strfile = dir.currentPath();
        strfile += "/test_Conformance/SCL.xsd";
        QString Errorfile;
        Errorfile = m_file.absolutePath() +"/"+m_file.baseName()+ "_ErrorLog.txt";
        string str1(strfile.toLocal8Bit().data());

        const char* chstd = str1.c_str();
        //const char* chstd = strfile.toLocal8Bit()
        string str2(SCD_FilePath.toLocal8Bit().data());

        const char*  chxml = str2.c_str();
        QString str;
        QString strerror;
        QString strexper;
        //系统初始化
        try
        {
            XMLPlatformUtils::Initialize();
        }
        catch (const XMLException &xe)
        {
            printf("%s", (const char*)xe.getMessage());

            return ;
        }

        // 创建解析器
        SAX2XMLReader* parser = XMLReaderFactory::createXMLReader();

        //设置名称空间属性, 如果没有如下两行则忽略名称空间 及名称空间前缀
        parser->setFeature(XMLUni::fgSAX2CoreNameSpaces, true);
        parser->setFeature(XMLUni::fgSAX2CoreNameSpacePrefixes, true);

        //设置验证属性
        parser->setFeature(XMLUni::fgXercesValidationErrorAsFatal, false);
        parser->setFeature(XMLUni::fgSAX2CoreValidation, true);
        parser->setFeature(XMLUni::fgXercesSchema, true);
        parser->setFeature(XMLUni::fgXercesSchemaFullChecking, true);

        //加载XSD文件

        parser->loadGrammar(chstd, Grammar::SchemaGrammarType, true);
        parser->setFeature(XMLUni::fgXercesUseCachedGrammarInParse, true);

        try
        {
            //定义打印对象
            SAX2PrintHandlers handler("UTF-8", XMLFormatter::UnRep_CharRef, false);

            //设置内容打印函数: 如果没有这行,则不打印出XML文档内容
            parser->setContentHandler(&handler);

            //设置错误打印函数: 如果没有这行,则不打印错误信息
            parser->setErrorHandler(&handler);

            //解析并验证XML文档
            parser->parse(chxml);
            str = "Error count:";
            int count = parser->getErrorCount();

            str += QString::number(count, 10);
            ErrorList.append(str);
                for (int i = 0; i < handler.errorList.size(); i++)
                {
                    ErrorList.append(handler.errorList[i]);
                }
                for (int i = 0; i < handler.warningList.size(); i++)
                {
                    ErrorList.append(handler.warningList[i]);
                }


        }
        catch (const OutOfMemoryException &ome)
        {
            std::cout << (const char*)ome.getMessage();

            OutputDebugString(strerror.toStdWString().data());

        }
        catch (const XMLException &xe)
        {
            OutputDebugString(strexper.toStdWString().data());
        }


        delete parser;
        OutputDebugString(str.toStdWString().data());
        XMLPlatformUtils::Terminate();
        if(ErrorList.size()>1)
        {
            QFile file(Errorfile);
            if (!file.open(QIODevice::WriteOnly | QIODevice::Text))
                return;

            QTextStream out(&file);
            for(int i =0;i<ErrorList.size();i++)
            {
                out<<ErrorList.at(i)<<"\n";
            }
            file.close();
			QMessageBox::about(this, tr("Notice"), tr("The Schema erroe save in file(%1)").arg(Errorfile));
            //out << "The magic number is: " << /49 << "\n";
        }
	}
}
int MainWindow::File_Integrity_Check(int state)
{
	int recode;
	recode = m_SCDPoint->File_Integrity_Check(SCD_FilePath, state);
	return recode;
}
int MainWindow::File_Integrity_Check(QString str)
{
	int recode;
	recode = m_SCDPoint->File_Integrity_Check(str, 0);
	return recode;
}
void MainWindow::Action_Communication_Check()
{
	Comm_check *m_dlg = new Comm_check(this);
	m_dlg->Point = m_SCDPoint;
	//m_dlg->SetPoint(m_SCDPoint);
	m_dlg->exec();
}
void MainWindow::Action_Schema_Check()
{
    if(SCD_FilePath.isEmpty()||Reversion_Flag||Version_Flag)
    {
        QMessageBox msgBox;
        msgBox.setText(tr("The file has been changed"));
        msgBox.setInformativeText(tr("Please save the change first"));
        msgBox.setStandardButtons(QMessageBox::Yes );
        msgBox.setDefaultButton(QMessageBox::Yes);
        return;
    }
    Wait_Dlg m_dlg;
    m_dlg.Set(tr("Checking the Schema, Please wait"));
    m_dlg.show();
    m_dlg.Display();

	Schema_Check();
    m_dlg.m_Close();
}
int MainWindow::Schema_Check()
{
	QDir dir;
	//QString strerr;
	//MessageHandler* messageHandler = new MessageHandler;
	QString strfile = dir.currentPath();
	strfile += "/test_Conformance/SCL.xsd";

    string str1(strfile.toLocal8Bit().data());

	const char* chstd = str1.c_str();

    string str2(SCD_FilePath.toLocal8Bit().data());

	const char*  chxml = str2.c_str();
	char *chstr;
	char *cherr;
	char *chexper;
	QString str;
	QString strerror;
	QString strexper;
	//系统初始化  
	try
	{
		XMLPlatformUtils::Initialize();
	}
	catch (const XMLException &xe)
	{
		printf("%s", (const char*)xe.getMessage());

		return -1;
	}

	// 创建解析器  
	SAX2XMLReader* parser = XMLReaderFactory::createXMLReader();

	//设置名称空间属性, 如果没有如下两行则忽略名称空间 及名称空间前缀  
	parser->setFeature(XMLUni::fgSAX2CoreNameSpaces, true);
	parser->setFeature(XMLUni::fgSAX2CoreNameSpacePrefixes, true);

	//设置验证属性  
	parser->setFeature(XMLUni::fgXercesValidationErrorAsFatal, false);
	parser->setFeature(XMLUni::fgSAX2CoreValidation, true);
	parser->setFeature(XMLUni::fgXercesSchema, true);
	parser->setFeature(XMLUni::fgXercesSchemaFullChecking, true);

	//加载XSD文件  

	parser->loadGrammar(chstd, Grammar::SchemaGrammarType, true);
	parser->setFeature(XMLUni::fgXercesUseCachedGrammarInParse, true);

	try
	{
		//定义打印对象  
		SAX2PrintHandlers handler("UTF-8", XMLFormatter::UnRep_CharRef, false);

		//设置内容打印函数: 如果没有这行,则不打印出XML文档内容  
		parser->setContentHandler(&handler);

		//设置错误打印函数: 如果没有这行,则不打印错误信息  
		parser->setErrorHandler(&handler);

		//解析并验证XML文档  
		parser->parse(chxml);
		str = "Error count:";
		int count = parser->getErrorCount();

		str += QString::number(count, 10);
		ui->textBrowser->clear();
		ui->textBrowser->append(str);
		if ((handler.errorList.size()>99) || (handler.warningList.size()>99))	
		{
			ui->textBrowser->append("To many error! check the file");
		}
		else
		{
			for (int i = 0; i < handler.errorList.size(); i++)
			{
				ui->textBrowser->append(handler.errorList[i]);
			}
			for (int i = 0; i < handler.warningList.size(); i++)
			{
				ui->textBrowser->append(handler.warningList[i]);
			}
		}

	}
	catch (const OutOfMemoryException &ome)
	{
		//printf(cherr,"int:%d\n", (const char*)ome.getMessage());
		std::cout << (const char*)ome.getMessage();
		//OutputDebugString(cherr);

		//qDebug() << (const char*)ome.getMessage();
		//strerror.clear();
		//strerror += cherr;
		OutputDebugString(strerror.toStdWString().data());
		//ui->textBrowser->append(strerror);
		//cherr = (const char*)ome.getMessage();
	}
	catch (const XMLException &xe)
	{
		//printf(chexper, "int:%d\n", (const char*)xe.getMessage());
		//OutputDebugString(chexper);
		//printf(chexper, (const char*)xe.getMessage());
		//strexper.clear();
		
		//qDebug() << (const char*)xe.getMessage();
		//strexper += chexper;
		//ui->textBrowser->append(strexper);
		//chexper = 
		OutputDebugString(strexper.toStdWString().data());
	}

	
	//printf("Error count:%d\n", parser->getErrorCount());

	delete parser;
	OutputDebugString(str.toStdWString().data());
	XMLPlatformUtils::Terminate();













//SchemaCheck *m_schema_check = new SchemaCheck();
//m_schema_check->setstdfile(strfile);
//m_schema_check->setxmlfile(SCD_FilePath);
//m_schema_check->FileCheck();
	//QFile stdfile(str);
	//stdfile.open(QIODevice::ReadOnly);

	//QXmlSchema schema;
	//QFile xmlfile(SCD_FilePath);
	//QXmlSchemaValidator* validator;
	//schema.load(&stdfile, QUrl::fromLocalFile(stdfile.fileName()));
	//if (schema.isValid()) {
	//	
	//	xmlfile.open(QIODevice::ReadOnly);

	//	validator = new QXmlSchemaValidator(schema);
	//	
	//	validator->setMessageHandler(messageHandler);
	//	if (!validator->validate(&xmlfile, QUrl::fromLocalFile(xmlfile.fileName())))
	//	{
	//		ui->textBrowser->append("Error");
	//		strerr = messageHandler->statusMessage();
	//		ui->textBrowser->append(strerr);
	//	}


	

	return DO_OK;
}
