#include "scdtree.h"
#include <QObject>
#include <QDateTime>

WORD extern Crc16(BYTE* pBuf, int nLen)
{
	WORD wTmp;
	WORD wRtn;

	wRtn = 0;

	for (int j = 0; j < nLen; j++)
	{
		wTmp = *pBuf;
		wTmp <<= 1;

		for (int i = 8; i>0; i--)
		{
			wTmp >>= 1;
			if ((wTmp^wRtn) & 0x0001)
				wRtn = (wRtn >> 1) ^ 0xa001;
			else
				wRtn >>= 1;
		}
		pBuf++;
	}

	return wRtn;
}

QString extern IP_Increase(QString IP, int i)
{
	QString IPaddr;
	QString newaddr;
	QStringList addrlist;
	bool ok;
	int addr;
	addrlist = IP.split(".");

	addr = addrlist[addrlist.size() - 1].toInt(&ok, 10);
	if (addr + i > 255)
	{
		addr = 255;
	}
	else
	{
		addr = addr + i;
	}
	newaddr = QString::number(addr, 10);
	addrlist[addrlist.size() - 1] = newaddr;
	for (int i = 0; i < addrlist.size(); i++)
	{
		IPaddr += addrlist[i] + ".";
	}
	IPaddr.remove(IPaddr.length() - 1, 1);
	return IPaddr;
}

QString extern MAC_Increase(QString MAC, int i)
{
	QString MACaddr;
	QString newaddr;
	QStringList addrlist;
	bool ok;
	int addr;
	QString s;
	addrlist = MAC.split("-");
	if (addrlist[addrlist.size() - 1].size() == 0)
	{
		addrlist[addrlist.size() - 1] = "01";
	}
	s = addrlist[addrlist.size() - 1];
	addr = addrlist[addrlist.size() - 1].toUInt(&ok, 16);
	if (addr + i > 255)
	{
		addr = 255;
	}
	else
	{
		addr = addr + i;
	}
	newaddr = QString::number(addr, 16);
	newaddr = newaddr.toUpper();
	if (newaddr.size() == 1)
	{
		newaddr = "0" + newaddr;
	}
	addrlist[addrlist.size() - 1] = newaddr;
	for (int i = 0; i < addrlist.size(); i++)
	{
		MACaddr += addrlist[i] + "-";
	}
	MACaddr.remove(MACaddr.length() - 1, 1);
	return MACaddr;
}
int extern Min_Flag(QList<int> &List)
{
	int ret;
	ret = List.at(0);
	if (List.size() == 1)
	{
		return ret;
	}
	for (int i = 1; i<List.size(); i++)
	{
		if (ret >List.at(i))
			ret = List.at(i);
	}
	return ret;
}

ScdTree::ScdTree()
{

	doc = new TiXmlDocument();
	CIDDocument = new TiXmlDocument;
	Input_flag = 1;
}

int ScdTree::LoadSCD(QString filename)
{

	if (doc != NULL)
	{
		delete doc;
	}
	doc = new TiXmlDocument();
	if (doc->LoadFile(filename.toLocal8Bit().data()))
	{
		root = doc->FirstChildElement("SCL");
		CurElement = root;
		CurNode = root;
		DataTypeNode = root->FirstChildElement("DataTypeTemplates");
		return DO_OK;
	}
	else
	{
		const char* ch;
		QString error;
		int row = 0, column = 0;
		ch = doc->ErrorDesc();
		error += ch;
		row = doc->ErrorRow();
		column = doc->ErrorCol();
		QMessageBox::information(NULL, QString("title"), QString("parse file failed at line row and column") + QString::number(row, 10) + QString(",") + QString::number(column, 10) + QString::fromLocal8Bit(doc->ErrorDesc()));
		return DO_FAIL;
	}
}
int ScdTree::CreatSCD()
{
	if (doc != NULL)
	{
		delete doc;
	}
	doc = new TiXmlDocument();

	if (InitSCDstruct(doc))
	{
		root = doc->FirstChildElement("SCL");
		CurElement = root;
		CurNode = root;
		return DO_OK;
	}




	return false;
}
int ScdTree::InitSCDstruct(TiXmlDocument* DOCPoint)
{
	TiXmlDeclaration *Declaration = new TiXmlDeclaration("1.0", "UTF-8", "");
	DOCPoint->LinkEndChild(Declaration);
	TiXmlElement *SCL_element = new TiXmlElement("SCL");
	SCL_element->SetAttribute("xmlns", "http://www.iec.ch/61850/2006/SCL");
	SCL_element->SetAttribute("xmlns:xsi", "http://www.w3.org/2001/XMLSchema");
	SCL_element->SetAttribute("xmlns:kf", "http://www.keyvia.cn");
	SCL_element->SetAttribute("xsi:schemaLocation", "http://www.iec.ch/61850/2006/SCL");

	TiXmlElement *Header_element = new TiXmlElement("Header");
	Header_element->SetAttribute("id", "Template");
	Header_element->SetAttribute("version", "1.00");
	Header_element->SetAttribute("toolID", "Keyvia Configuration");
	Header_element->SetAttribute("nameStructure", "IEDName");
	TiXmlElement* new_element = new TiXmlElement("History");
	Header_element->LinkEndChild(new_element);

	new_element = new TiXmlElement("Hitem");
	new_element->SetAttribute("version", "1.0");
	new_element->SetAttribute("revision", "1.0");
	QDateTime current_date_time = QDateTime::currentDateTime();
	QString current_date = current_date_time.toString("yyyy-MM-dd hh:mm:ss");
	new_element->SetAttribute("when", current_date.toStdString().data());
	new_element->SetAttribute("who", "");
	new_element->SetAttribute("what", "");
	new_element->SetAttribute("why", "");

	Header_element->FirstChildElement()->LinkEndChild(new_element);
	SCL_element->LinkEndChild(Header_element);
	TiXmlElement *Substaion_element = new TiXmlElement("Substation");
	Substaion_element->SetAttribute("name", "");
	SCL_element->LinkEndChild(Substaion_element);
	TiXmlElement *Communication_element = new TiXmlElement("Communication");
	new_element = new TiXmlElement("SubNetwork");
	new_element->SetAttribute("name", "MMS-Subnet");
	new_element->SetAttribute("type", "8-MMS");
	new_element->SetAttribute("desc", "");
	Communication_element->LinkEndChild(new_element);
	new_element = new TiXmlElement("SubNetwork");
	new_element->SetAttribute("name", "GOOSE-Subnet");
	new_element->SetAttribute("type", "IECGOOSE");
	new_element->SetAttribute("desc", "");
	Communication_element->LinkEndChild(new_element);
	new_element = new TiXmlElement("SubNetwork");
	new_element->SetAttribute("name", "SMV-Subnet");
	new_element->SetAttribute("type", "SMV");
	new_element->SetAttribute("desc", "");
	Communication_element->LinkEndChild(new_element);
	SCL_element->LinkEndChild(Communication_element);
	DOCPoint->LinkEndChild(SCL_element);

	return true;
}
int ScdTree::SaveSCD(QString filename)
{
	//SaveIEDCRC2File();
	//SaveSCDCRC2File();
	SaveCRC();
	if (doc->SaveFile((filename.toLocal8Bit().data())))
	{
		return true;
	}

	return false;
}
int ScdTree::GetNode(QString NodeName)
{
	TiXmlElement* m_Node = NULL;
	//TiXmlElement* m_Element;
	ChildNum = 0;
	m_Node = CurElement->GetChildByName(root, NodeName.toStdString().data());
	if (m_Node == NULL)
	{
		return DO_FAIL;
	}
	CurNode = m_Node;
	CurElement = m_Node;
	return DO_OK;
}
int ScdTree::GetIEDList(QVector<IEDstruct> &list)
{
	TiXmlElement* m_Node = NULL;

	const char* chr;
	QString str;
	m_Node = root->FirstChildElement("IED");
	for (m_Node; m_Node != NULL; m_Node = m_Node->NextSiblingElement("IED"))
	{
		IEDstruct m_ied;
		chr = m_Node->Attribute("name");
		str.clear();
		str += chr;
		m_ied.s_IEDname = str;
		m_ied.s_IEDtype = QString(QLatin1String(m_Node->Attribute("type")));
		//m_ied.s_IEDvendor = QString(QLatin1String(m_Node->Attribute("manufacturer")));
		m_ied.s_IEDversion = QString(QLatin1String(m_Node->Attribute("configVersion")));

		if (m_Node->Attribute("desc") != NULL)
		{
			chr = m_Node->Attribute("desc");
			str.clear();
			str += chr;
			m_ied.s_IEDdesc = str;
		}
		if (m_Node->Attribute("manufacturer") != NULL)
		{
			chr = m_Node->Attribute("manufacturer");
			str.clear();
			str += chr;
			m_ied.s_IEDvendor = str;
		}
		list.append(m_ied);
	}
	return DO_OK;
}
int ScdTree::GetChildNum()
{
	return ChildNum;
}

int ScdTree::GetChild(QString ChildName)
{
	TiXmlElement* m_Node = NULL;
	TiXmlElement* m_Element = NULL;
	ChildNum = 0;
	m_Node = CurElement->GetChildByName(CurElement, ChildName.toStdString().data());
	if (m_Node == NULL)
	{
		return DO_FAIL;
	}
	CurElement = m_Node;
	CurNode = m_Node;
	m_Element = m_Node->FirstChildElement();
	while (m_Element != NULL)
	{
		ChildNum++;
		m_Element = m_Element->NextSiblingElement();
	}
	return DO_OK;
}
int ScdTree::GetAccessPoint(QString APName)
{

	TiXmlElement* m_Element = NULL;
	m_Element = IEDNode->FirstChildElement("AccessPoint");
	if (m_Element == NULL)
	{
		return DO_FAIL;
	}
	for (m_Element; m_Element != NULL; m_Element = m_Element->NextSiblingElement("AccessPoint"))
	{
		if (0 != strcmp(m_Element->Attribute("name"), APName.toStdString().data()))
		{
			continue;
		}
		else
		{
			CurElement = m_Element;
			CurNode = m_Element;
			return DO_OK;
		}
	}


	return DO_FAIL;
}
int ScdTree::GetLDnode(QString Ldname)
{

	TiXmlElement* m_Element = CurElement;
	TiXmlElement* childEle = NULL;

	if (0 == strcmp(m_Element->Value(), "IED"))
	{
		m_Element = m_Element->FirstChildElement("AccessPoint");
		for (; m_Element != NULL; m_Element = m_Element->NextSiblingElement("AccessPoint"))
		{
			childEle = m_Element->FirstChildElement("Server")->FirstChildElement("LDevice");
			for (; childEle != NULL; childEle = childEle->NextSiblingElement("LDevice"))
			{
				if (0 != strcmp(childEle->Attribute("inst"), Ldname.toStdString().data()))
				{
					continue;
				}
				else
				{
					CurElement = childEle;
					CurNode = childEle;
					return DO_OK;
				}
			}

		}
	}
	if (m_Element == NULL)
	{
		return DO_FAIL;

	}
	if (0 == strcmp(m_Element->Value(), "AccessPoint"))
	{
		childEle = m_Element->FirstChildElement("Server")->FirstChildElement("LDevice");
		for (; childEle != NULL; childEle = childEle->NextSiblingElement("LDevice"))
		{
			QString str;
			const char* car;
			car = childEle->Attribute("inst");
			str += car;
			if (0 != strcmp(childEle->Attribute("inst"), Ldname.toStdString().data()))
			{
				continue;
			}
			else
			{
				CurElement = childEle;
				CurNode = childEle;
				return DO_OK;
			}
		}


	}



	return DO_FAIL;
}
int ScdTree::GetLNnode(QString LNinst)
{

	TiXmlElement* m_Element = CurElement;
	TiXmlElement* childEle = NULL;
	const char* chr;
	QString str;
	if (0 != strcmp(m_Element->Value(), "LDevice"))
	{
		return DO_FAIL;
	}
	childEle = m_Element->FirstChildElement();
	for (; childEle != NULL; childEle = childEle->NextSiblingElement())
	{
		str.clear();
		chr = childEle->Attribute("prefix");
		str += chr;
		chr = childEle->Attribute("lnClass");
		str += chr;
		chr = childEle->Attribute("inst");
		str += chr;
		if (0 != strcmp(str.toStdString().data(), LNinst.toStdString().data()))
		{
			continue;
		}
		else
		{
			CurElement = childEle;
			CurNode = childEle;
			return DO_OK;
		}

	}



	return DO_FAIL;
}
int ScdTree::GetNextChild()
{
	TiXmlNode* m_Node = NULL;
	TiXmlElement* m_Element = NULL;
	ChildNum = 0;
	QString strValue;
	strValue = CurElement->Value();
	m_Node = CurElement->NextSibling(strValue.toStdString().data());
	if (m_Node == NULL)
	{
		return DO_FAIL;
	}
	CurElement = m_Node->ToElement();
	CurNode = m_Node->ToElement();
	m_Element = m_Node->FirstChildElement();
	while (m_Element != NULL)
	{
		ChildNum++;
		m_Element = m_Element->NextSiblingElement();
	}
	return DO_OK;
}
int ScdTree::GetNextChild(QString strname)
{
	TiXmlNode* m_Node = NULL;
	TiXmlElement* m_Element = NULL;
	ChildNum = 0;
	QString strValue;
	strValue = strname;
	m_Node = CurElement->NextSibling(strValue.toStdString().data());
	if (m_Node == NULL)
	{
		return DO_FAIL;
	}
	CurElement = m_Node->ToElement();
	CurNode = m_Node->ToElement();
	m_Element = m_Node->FirstChildElement();
	while (m_Element != NULL)
	{
		ChildNum++;
		m_Element = m_Element->NextSiblingElement();
	}
	return DO_OK;
}
int ScdTree::GetOneDOI(QString DOIName)
{
	TiXmlElement* m_Element = NULL;
	m_Element = CurElement->FirstChildElement("DOI");
	if (m_Element == NULL)
	{
		return DO_FAIL;
	}
	for (m_Element; m_Element != NULL; m_Element = m_Element->NextSiblingElement("DOI"))
	{
		if (0 != strcmp(m_Element->Attribute("name"), DOIName.toStdString().data()))
		{
			continue;
		}
		else
		{
			CurElement = m_Element;
			CurNode = m_Element;
			return DO_OK;
		}
	}


	return DO_FAIL;
}
TiXmlElement* ScdTree::GetOneDAI(QString DAIName)
{
	TiXmlElement* m_Element = NULL;
	if (DAIName.contains(".") == false)
	{
		m_Element = CurElement->FirstChildElement("DAI");
		if (m_Element == NULL)
		{
			return NULL;
		}
		for (m_Element; m_Element != NULL; m_Element = m_Element->NextSiblingElement("DAI"))
		{
			if (0 != strcmp(m_Element->Attribute("name"), DAIName.toStdString().data()))
			{
				continue;
			}
			else
			{
				return m_Element;
			}
		}
	}
	else
	{
		int index;
		QString strSDIname, strpath;
		index = DAIName.indexOf(".");
		strSDIname = DAIName.left(index);
		strpath = DAIName.right(index);
		m_Element = CurElement->FirstChildElement("SDI");
		if (m_Element == NULL)
		{
			return NULL;
		}
		for (m_Element; m_Element != NULL; m_Element = m_Element->NextSiblingElement("SDI"))
		{
			if (0 != strcmp(m_Element->Attribute("name"), strSDIname.toStdString().data()))
			{
				continue;
			}
			else
			{
				m_Element = GetOneDAI(strpath);
				return m_Element;
			}
		}
	}






	return NULL;
}
QString ScdTree::GetDOIValue(QString Node, QString Name, QString attriName)
{
	TiXmlElement* m_Element = NULL;
	QString str_value;
	char str[100];
	if (0 != strcmp(CurElement->Value(), "DOI"))
	{
		return NULL;

	}
	if (Name.isEmpty())
	{
		m_Element = GetOneDAI("stVal");
		if (m_Element == NULL)
		{
			return NULL;
		}
		if (m_Element->Attribute(attriName.toStdString().data()) == NULL)
		{
			return NULL;
		}
		strcpy(str, m_Element->Attribute(attriName.toStdString().data()));


		str_value += str;
		return str_value;
	}
	else
	{
		m_Element = GetOneDAI(Name);
		if (m_Element == NULL)
		{
			return NULL;
		}
		if (attriName == QObject::tr("Val"))
		{
			TiXmlText* m_text = NULL;
			if (m_Element->FirstChild("Val")->FirstChild() != NULL)
			{
				m_text = m_Element->FirstChild("Val")->FirstChild()->ToText();
				strcpy(str, m_text->Value());
			}
			else
			{
				strcpy(str, m_Element->Parent()->ToElement()->Attribute("desc"));
			}




			str_value += str;
			return str_value;
		}
		if (m_Element->Attribute(attriName.toStdString().data()) == NULL)
		{
			return NULL;
		}
		strcpy(str, m_Element->Attribute(attriName.toStdString().data()));


		str_value += str;
		return str_value;
	}
}


int ScdTree::GetChild()
{

	TiXmlElement* m_Element = NULL;

	ChildNum = 0;
	m_Element = CurElement->FirstChildElement();
	if (m_Element == NULL)
	{
		return DO_FAIL;
	}
	CurElement = m_Element;
	CurNode = m_Element;
	return DO_OK;
}
int ScdTree::GetChildList()
{

	TiXmlElement* m_Element = NULL;

	ChildNum = 0;
	m_Element = CurElement->FirstChildElement();
	if (m_Element == NULL)
	{
		return DO_FAIL;
	}
	while (m_Element != NULL)
	{
		ChildNum++;
		m_Element = m_Element->NextSiblingElement();
	}

	return DO_OK;
}
int ScdTree::GetChildByname_value(QString strName, QString strValue)
{
	TiXmlElement* m_Node = NULL;

	ChildNum = 0;
	if (CurElement == NULL)
	{
		return DO_FAIL;
	}
	m_Node = CurElement->GetChildByName_Value(CurNode, strName.toStdString().data(), strValue.toStdString().data());
	if (m_Node == NULL)
	{
		return DO_FAIL;
	}
	CurElement = m_Node;
	CurNode = m_Node;
	return 0;
}
int ScdTree::GetChildByname_value(QString NodeName, QString strName, QString strValue)
{
	TiXmlElement* m_Node = NULL;
	TiXmlNode* Node_tmp = NULL;
	if (CurElement == NULL)
	{
		return DO_FAIL;
	}
	if (strValue == NULL)
	{
		return DO_FAIL;
	}
	Node_tmp = CurElement->FirstChild(NodeName.toStdString().data());
	if (Node_tmp == NULL)
	{
		return DO_FAIL;
	}
	m_Node = Node_tmp->ToElement();
	while (m_Node != NULL)
	{
		std::string str = strValue.toStdString();

		const char* ch = str.c_str();
		if (0 == strcmp(m_Node->Attribute(strName.toStdString().data()), ch))
		{
			CurElement = m_Node;
			CurNode = m_Node;
			return DO_OK;
		}
		else
		{
			TiXmlNode* m_nextnode = m_Node->NextSibling(NodeName.toStdString().data());
			if (m_nextnode == NULL)
			{
				return DO_FAIL;
			}
			m_Node = m_nextnode->ToElement();
			continue;

		}
	}
	return DO_FAIL;
}
int ScdTree::GetChildByname_value(QString NodeName, QString strName1, QString strValue1,
	QString strName2, QString strValue2,
	QString strName3, QString strValue3)
{
	TiXmlElement* m_Node = NULL;

	if (CurElement == NULL)
	{
		return DO_FAIL;
	}
	m_Node = CurElement->FirstChild(NodeName.toStdString().data())->ToElement();
	while (m_Node != NULL)
	{
		if (!strName1.isEmpty())
		{
			if (0 != strcmp(m_Node->Attribute(strName1.toStdString().data()), strValue1.toStdString().data()))
			{
				m_Node = m_Node->NextSiblingElement();
				continue;
			}
		}
		if (!strName2.isEmpty())
		{
			if (0 != strcmp(m_Node->Attribute(strName2.toStdString().data()), strValue2.toStdString().data()))
			{
				m_Node = m_Node->NextSiblingElement();
				continue;
			}
		}
		if (!strName3.isEmpty())
		{
			if (0 != strcmp(m_Node->Attribute(strName3.toStdString().data()), strValue3.toStdString().data()))
			{
				m_Node = m_Node->NextSiblingElement();
				continue;
			}
		}
		if (!(strName1.isEmpty() && strName2.isEmpty() && strName3.isEmpty()))
		{
			CurElement = m_Node;
			CurNode = m_Node;
			return DO_OK;
		}


	}
	return DO_FAIL;
}
int ScdTree::GetChildByname_value(QString strName1, QString strValue1,
	QString strName2, QString strValue2,
	QString strName3, QString strValue3)
{
	TiXmlElement* m_Node = NULL;

	if (CurElement == NULL)
	{
		return DO_FAIL;
	}
	bool state1, state2, state3;
	state1 = state2 = state3 = false;
	m_Node = CurElement->FirstChild()->ToElement();
	while (m_Node != NULL)
	{
		if ((strValue1 != NULL) || (strValue2 != NULL) || (strValue3 != NULL))
		{
			if (strValue1 != NULL)
			{
				if (m_Node->Attribute(strName1.toStdString().data()) != NULL)
				{

					if (0 == strcmp(m_Node->Attribute(strName1.toStdString().data()), strValue1.toStdString().data()))
					{
						state1 = true;
					}
					else
					{
						TiXmlNode* m_nextnode = m_Node->NextSibling();
						if (m_nextnode == NULL)
						{
							return DO_FAIL;
						}
						m_Node = m_nextnode->ToElement();
						continue;
					}
				}


			}
			else{
				state1 = true;
			}

			if (strValue2 != NULL)
			{
				if (m_Node->Attribute(strName2.toStdString().data()) != NULL)
				{
					if (0 == strcmp(m_Node->Attribute(strName2.toStdString().data()), strValue2.toStdString().data()))
					{
						state2 = true;
					}
					else
					{
						TiXmlNode* m_nextnode = m_Node->NextSibling();
						if (m_nextnode == NULL)
						{
							return DO_FAIL;
						}
						m_Node = m_nextnode->ToElement();
						continue;
					}
				}

			}
			else
			{
				state2 = true;
			}
			if (strValue3 != NULL)
			{
				if (m_Node->Attribute(strName3.toStdString().data()) != NULL)
				{
					if (0 == strcmp(m_Node->Attribute(strName3.toStdString().data()), strValue3.toStdString().data()))
					{
						state3 = true;
					}
					else
					{
						TiXmlNode* m_nextnode = m_Node->NextSibling();
						if (m_nextnode == NULL)
						{
							return DO_FAIL;
						}
						m_Node = m_nextnode->ToElement();
						continue;
					}
				}

			}
			else
			{
				state3 = true;
			}
			if ((state1&&state2&&state3) == true)
			{
				CurElement = m_Node;
				CurNode = m_Node;
				return DO_OK;
			}
		}
		else
		{
			return DO_FAIL;
		}
	}
	return DO_FAIL;
}
int ScdTree::GetIEDByname(QString strname)
{
	TiXmlElement* m_Node = NULL;
	std::string str = strname.toStdString();

	const char* ch = str.c_str();
	ChildNum = 0;
	m_Node = CurElement->GetChildByName(root, "IED");
	if (m_Node == NULL)
	{
		return DO_FAIL;
	}
	for (m_Node; m_Node != NULL; m_Node = m_Node->NextSiblingElement("IED"))
	{
		if (0 != strcmp(m_Node->Attribute("name"), ch))
		{
			continue;
		}
		else
		{
			CurElement = m_Node;
			IEDNode = m_Node;
			CurNode = m_Node;
			TiXmlElement *m_Element = m_Node->FirstChildElement();
			while (m_Element != NULL)
			{
				ChildNum++;
				m_Element = m_Element->NextSiblingElement();
			}
			return DO_OK;
		}
	}

	return DO_FAIL;
}
int ScdTree::SwitchToIED()
{
	CurElement = IEDNode;
	CurNode = IEDNode;
	return DO_OK;
}
int ScdTree::SwitchParent()
{
	CurElement = CurElement->Parent()->ToElement();
	CurNode = CurNode->Parent()->ToElement();
	return DO_OK;
}
int ScdTree::RemoveChildByName(TiXmlElement* Element, QString ChildName)
{
	Element->RemvoeChildByName_Value(Element, "name", ChildName.toStdString().data());
	return 0;
}
int ScdTree::RemoveChildByIndex(int index)
{
	return 0;
}

int ScdTree::SetNode()
{
	return 0;
}
int ScdTree::CreatNode(QString NodeName)
{
	return 0;
}
int ScdTree::AddAttribute(QString Name, QString AttributeName)
{
	return 0;
}
int ScdTree::SetAttribute(QString AttributeName, QByteArray Value)
{
	CurElement->SetAttribute(AttributeName.toStdString().data(), Value.data());
	if (0 == strcmp(CurElement->Attribute(AttributeName.toStdString().data()), Value.data()))
	{
		return DO_OK;
	}
	else
	{
		return DO_FAIL;
	}

}

QString ScdTree::GetAttribute(int index, QString AttributeName)
{
	TiXmlElement* m_Element = NULL;

	char str[100];
	m_Element = CurElement->FirstChildElement();
	if (m_Element == NULL)
	{
		return NULL;
	}
	while (index > 0)
	{
		m_Element = m_Element->NextSiblingElement();
		if (m_Element == NULL)
		{
			return NULL;
		}
		index--;
	}
	if (m_Element == NULL)
	{
		return NULL;
	}
	if (m_Element->Attribute(AttributeName.toStdString().data()) == NULL)
	{
		return NULL;
	}
	strcpy(str, m_Element->Attribute(AttributeName.toStdString().data()));
	QString str_value;
	str_value += str;
	return str_value;

}
QString ScdTree::GetAttribute(QString AttributeName)
{
	TiXmlElement* m_Element = NULL;


	m_Element = CurElement;
	if (m_Element == NULL)
	{
		return NULL;
	}
	if (m_Element->Attribute(AttributeName.toStdString().data()) == NULL)
	{
		return NULL;
	}
	char str[100];
	strcpy(str, m_Element->Attribute(AttributeName.toStdString().data()));

	QString str_value;
	str_value += str;
	return str_value;

}
QString ScdTree::GetValue()
{
	TiXmlElement* m_Element = NULL;

	char str[100];
	m_Element = CurElement;
	if (m_Element == NULL)
	{
		return NULL;
	}
	strcpy(str, m_Element->Value());

	QString str_value;
	str_value += str;
	return str_value;

}
//int ScdTree::UpdataAttribute(int index, QString AttributeName, QByteArray AttributeValue)
//{
//	TiXmlElement* m_Element = NULL;
//	char str[100];
//	m_Element = CurElement->FirstChildElement();
//	if (m_Element == NULL)
//	{
//		return NULL;
//	}
//	while (index >= 0)
//	{
//		m_Element = m_Element->NextSiblingElement();
//		index--;
//	}
//	if (m_Element == NULL)
//	{
//		return NULL;
//	}
//	m_Element->SetAttribute(AttributeName.toStdString().data(), AttributeValue.data());
//	strcpy(str, m_Element->Attribute(AttributeName.toStdString().data()));
//	int irecode = strcmp(str, AttributeValue.data());
//	if (irecode == 0)
//	{
//		return DO_OK;
//	}
//	else
//	{
//		return DO_FAIL;
//	}

//}
//int ScdTree::UpdataAttribute(QString NodeName, QString AttributeName, QByteArray AttributeValue)
//{
//	TiXmlElement* m_Element = NULL;
//	char str[100];
//	m_Element = CurElement->FirstChildElement(NodeName.toStdString().data());

//	if (m_Element == NULL)
//	{
//		return NULL;
//	}
//	m_Element->SetAttribute(AttributeName.toStdString().data(), AttributeValue.data());
//	strcpy(str, m_Element->Attribute(AttributeName.toStdString().data()));
//	int irecode = strcmp(str, AttributeValue.data());
//	if (irecode == 0)
//	{
//		return DO_OK;
//	}
//	else
//	{
//		return DO_FAIL;
//	}

//}
//int ScdTree::UpdataAttribute(QString name, QString value)
//{
//	TiXmlElement* m_Element = NULL;
//	m_Element = CurElement;
//	std::string str = value.toStdString();

//	const char* ch = str.c_str();
//	m_Element->SetAttribute(name.toStdString().data(), ch);
//	if (0 == strcmp(m_Element->Attribute(name.toStdString().data()), ch))
//	{
//		return DO_OK;
//	}
//	return DO_FAIL;
//}

//int ScdTree::UpdataLDAttribute(QString Apname, QString inst, QByteArray value)
//{
//	TiXmlNode* m_Node = CurElement->Parent()->Parent();
//	TiXmlNode* m_Element = NULL;

//	for (m_Element = m_Node->FirstChild("AccessPoint"); m_Element != NULL; m_Element->NextSibling("AccessPoint"))
//	{
//		if (strcmp(m_Element->ToElement()->Attribute("name"), Apname.toStdString().data()) == 0)
//		{
//			break;
//		}
//	}
//	m_Element = m_Element->FirstChild()->FirstChild("LDevice");
//	for (m_Element; m_Element != NULL; m_Element = m_Element->NextSibling("LDevice"))
//	{
//		if (strcmp(m_Element->ToElement()->Attribute("inst"), inst.toStdString().data()) == 0)
//		{
//			m_Element->ToElement()->SetAttribute("desc", value.data());
//			int irecode = strcmp(value.data(), m_Element->ToElement()->Attribute("desc"));
//			if (irecode == 0)
//			{
//				return DO_OK;
//			}
//			else
//			{
//				return DO_FAIL;
//			}
//		}
//	}
//	return DO_FAIL;
//}
//int ScdTree::UpdataLNAttribute(QString inst, QByteArray value)
//{


//	TiXmlElement* m_Element = CurElement;
//	m_Element->SetAttribute("desc", value.data());
//	m_Element = m_Element->FirstChild("DOI")->ToElement();
//	if (m_Element == NULL)
//	{
//		return DO_FAIL;
//	}
//	m_Element->SetAttribute("desc", value.data());
//	m_Element = m_Element->GetChildByName_Value(m_Element, "name", "dU");
//	if (m_Element == NULL)
//	{
//		return DO_FAIL;
//	}
//	TiXmlText *m_text = m_Element->FirstChild()->FirstChild()->ToText();
//	if (m_text == NULL)
//	{
//		return DO_FAIL;
//	}
//	m_text->SetValue(value.data());
//	return DO_OK;
//}
int ScdTree::UpdataIEDAttribute(QString IEDname, QString name, QString value)
{
	TiXmlElement* m_Element = NULL;
	QMap<QString, TiXmlElement*> IED_Map;
	Init_IED_MAP(root, IED_Map);
	if (!IED_Map.uniqueKeys().contains(IEDname))
		return DO_FAIL;
	m_Element = IED_Map.value(IEDname);
	m_Element->SetAttribute(name.toLocal8Bit().data(), value.toStdString().data());
	return DO_OK;
}
int ScdTree::UpdateCommunicationAttribute(QString subnet, QString name, QString Value)
{
	TiXmlElement* m_Communication = NULL;
	TiXmlElement* m_Element = NULL;
	m_Communication = root->FirstChildElement("Communication");
	if (m_Communication == NULL)
		return DO_FAIL;
	for (m_Element = m_Communication->FirstChildElement("SubNetwork"); m_Element != NULL; m_Element = m_Element->NextSiblingElement("SubNetwork"))
	{
		if (0 == strcmp(m_Element->Attribute("name"), subnet.toLocal8Bit().data()))
		{
			m_Element->SetAttribute(name.toLocal8Bit().data(), Value.toStdString().data());
			return DO_OK;
		}
	}

	return DO_FAIL;

}
int ScdTree::SwitchRoot()
{
	CurNode = root;
	CurElement = root;
	return DO_OK;
}
int ScdTree::CreatOneHistory()
{

	TiXmlElement* new_element = new TiXmlElement("Hitem");
	new_element->SetAttribute("version", " ");
	new_element->SetAttribute("revision", " ");
	QDateTime current_date_time = QDateTime::currentDateTime();
	QString current_date = current_date_time.toString("yyyy-MM-dd hh:mm:ss");
	new_element->SetAttribute("when", current_date.toStdString().data());
	new_element->SetAttribute("who", "");
	new_element->SetAttribute("what", "");
	new_element->SetAttribute("why", "");

	TiXmlElement*m_element = root->GetChildByName(root, "Header");
	m_element = m_element->GetChildByName(m_element, "History");
	m_element->LinkEndChild(new_element);
	return DO_OK;
}
QString ScdTree::CreatOneSubNet()
{
	TiXmlElement*m_element = root->GetChildByName(root, "Communication");
	TiXmlElement* new_element = new TiXmlElement("SubNetwork");
	QString str = QObject::tr("SubNetwork") + QString::number(ChildNum);
	new_element->SetAttribute("name", str.toStdString().data());
	new_element->SetAttribute("type", "8-MMS");
	new_element->SetAttribute("desc", "");


	m_element->LinkEndChild(new_element);
	return str;
}
int ScdTree::DeleteOneSubNet(QString strname)
{

	TiXmlElement* m_element = root->FirstChildElement("Communication");


	RemoveChildByName(m_element, strname);


	return 0;
}
int ScdTree::ImportICD(QString filename, QString IEDName)
{
	int ret;
	ret = ImportCID(filename, IEDName);

	return ret;
}

int ScdTree::ImportCID(QString filename, QString IEDName)
{

	if (CIDDocument != NULL)
	{
		delete CIDDocument;
	}
	CIDDocument = new TiXmlDocument;
	if (CIDDocument->LoadFile(filename.toLocal8Bit().data()) == false)
	{
		QMessageBox::warning(0, "Alarm", "Load file false!");

		return DO_FAIL;
	}
	QMap<QString, TiXmlElement*>IEDMap_EX;
	QMap<QString, TiXmlElement*>IEDMap_IN;
	Init_IED_MAP(CIDDocument->FirstChildElement("SCL"), IEDMap_EX);
	Init_IED_MAP(root, IEDMap_IN);


	QMap<QString, TiXmlElement*>LNMap;
	QMap<QString, TiXmlElement*>LNTypeMap;
	QMap<QString, TiXmlElement*>DOTypeMap;
	QMap<QString, TiXmlElement*>DATypeMap;
	QMap<QString, TiXmlElement*>EnumMap;
	CheckDataTempLate(CIDDocument, LNMap, LNTypeMap, DOTypeMap, DATypeMap, EnumMap);
	int iret;
	if ((LNTypeMap.size() == 0) && (DOTypeMap.size() == 0) && (DATypeMap.size() == 0) && ((EnumMap.size() == 0)))
	{
		if (ImportCID(IEDName) == DO_FAIL)
		{
			RemoveIED(IEDName);
			AutoReleaseUnuseDate();
			QMessageBox::warning(0, "Alarm", "Import CID false!");
			return DO_FAIL;
		}
		TiXmlNode *m_dateNode = CIDDocument->FirstChild("SCL")->FirstChild("DataTypeTemplates")->Clone();
		if (AddDateType(m_dateNode) == DO_FAIL)
		{
			RemoveIED(IEDName);
			AutoReleaseUnuseDate();
			QMessageBox::warning(0, "Alarm", "Import CID false!");
			return DO_FAIL;
		}
		return DO_OK;
	}
	bool flag = false;
	for (int i = 0; i < IEDMap_IN.uniqueKeys().size(); i++)
	{
		for (int j = 0; j < IEDMap_EX.uniqueKeys().size(); j++)
		{
			TiXmlElement* m_IN = NULL;
			TiXmlElement* m_EX = NULL;
			m_IN = IEDMap_IN.value(IEDMap_IN.uniqueKeys().at(i));
			m_EX = IEDMap_EX.value(IEDMap_EX.uniqueKeys().at(j));
			if (0 == strcmp(m_IN->Attribute("type"), m_EX->Attribute("type")))
			{
				flag = true;
			}
		}
	}
	if (flag == false)
	{
		AddDateType_AddPrefix(IEDName, CIDDocument->FirstChildElement("SCL"));
		ImportCID(IEDName);
		AddDateType(CIDDocument->FirstChildElement("SCL")->FirstChildElement("DataTypeTemplates"));
		return DO_OK;
	}
	DataTempLate *m_dlg = new DataTempLate();
	m_dlg->strName = IEDName;
	m_dlg->SetInit(4);
	if (m_dlg->exec() == QDialog::Accepted)
	{
		iret = m_dlg->state;

		switch (iret) {
		case 0x01:
			AddDateType_AddPrefix(IEDName, CIDDocument->FirstChildElement("SCL"));
			ImportCID(IEDName);
			AddDateType(CIDDocument->FirstChildElement("SCL")->FirstChildElement("DataTypeTemplates"));
			break;
		case 0x02:
			ImportCID(IEDName);
			AddDateType_Replace(IEDName, LNMap, LNTypeMap, DOTypeMap, DATypeMap, EnumMap);
			break;
		case 0x03:
			ImportCID(IEDName);
			AddDateType_Ignore(IEDName, LNMap, LNTypeMap, DOTypeMap, DATypeMap, EnumMap);
			break;
		default:
			break;
		}
	}
	else
	{

		return DO_OD;
	}

	return DO_OK;
}
int ScdTree::ImportCID(QString IEDName)
{

	std::string str = IEDName.toStdString();
	const char* chr = NULL;
	const char* ch = str.c_str();
	const char* chName = NULL;
	QString strname;
	TiXmlNode *m_APNode = CIDDocument->FirstChild("SCL")->FirstChild("Communication");

	for (m_APNode; m_APNode != NULL; m_APNode = m_APNode->NextSibling())
	{
		if (ADDOneAp(m_APNode, IEDName) == DO_FAIL)
		{
			QMessageBox::about(0, "Alarm", "Add AccessPoint false");

			return DO_FAIL;
		}
	}


	TiXmlNode *m_IEDNode = CIDDocument->FirstChild("SCL")->FirstChild("IED")->Clone();
	TiXmlElement *m_IEDElement = m_IEDNode->ToElement();

	chName = m_IEDElement->Attribute("name");
	strname += chName;
	m_IEDElement->SetAttribute("name", ch);
	if (Input_flag == 1)
	{
		ClearInputs(m_IEDElement);
	}
	Input_flag = 1;
	QMap<QString, TiXmlElement*>Map_LD;
	QMap<QString, TiXmlElement*>Map_LN;
	QMap<QString, TiXmlElement*>Map_BLK;
	TiXmlElement* m_LD = NULL;
	TiXmlElement* m_LN = NULL;
	TiXmlElement* m_BLK = NULL;
	Init_LD_MAP(m_IEDElement, Map_LD);
	for (int i = 0; i < Map_LD.uniqueKeys().size(); i++)
	{
		m_LD = Map_LD.value(Map_LD.uniqueKeys().at(i));
		Init_LN_MAP(m_LD, Map_LN);
		for (int j = 0; j < Map_LN.uniqueKeys().size(); j++)
		{
			QString str;

			m_LN = Map_LN.value(Map_LN.uniqueKeys().at(j));
			str += m_LN->Attribute("lnType");
			Init_ControBlock_MAP(m_LN, Map_BLK, 2);
			for (int m = 0; m < Map_BLK.uniqueKeys().size(); m++)
			{
				m_BLK = Map_BLK.value(Map_BLK.uniqueKeys().at(m));
				chr = m_BLK->Attribute("appID");
				QString strAppID;
				strAppID += chr;


				//strAppID.replace(strname, IEDName);
				strAppID.replace(0, strname.length(), IEDName);
				int index1, index2;
				index1 = strAppID.indexOf("/");
				index2 = strAppID.indexOf("$");
				strAppID.replace(index1 + 1, (index2 - index1 - 1), str);
				//strAppID.replace(strname, IEDName);
				m_BLK->SetAttribute("appID", strAppID.toStdString().data());
			}
			Init_ControBlock_MAP(m_LN, Map_BLK, 3);
			for (int m = 0; m < Map_BLK.uniqueKeys().size(); m++)
			{
				m_BLK = Map_BLK.value(Map_BLK.uniqueKeys().at(m));
				chr = m_BLK->Attribute("appID");
				QString strAppID;

				strAppID += chr;

				//strAppID.replace(strname, IEDName);
				strAppID.replace(0, strname.length(), IEDName);
				int index1, index2;
				index1 = strAppID.indexOf("/");
				index2 = strAppID.indexOf("$");
				strAppID.replace(index1 + 1, (index2 - index1 - 1), str);
				m_BLK->SetAttribute("appID", strAppID.toStdString().data());
			}
		}
	}
	if (AddOneIED(m_IEDNode) == DO_FAIL)
	{
		QMessageBox::about(0, "Alarm", "Add IEDNode false");
		return DO_FAIL;
	}
	return DO_OK;
}



int ScdTree::ImportCID(QString IEDName, TiXmlDocument* SCL_Node)
{
	if (CIDDocument != NULL)
	{
		delete CIDDocument;
	}
	CIDDocument = SCL_Node;
	QMap<QString, TiXmlElement*>IEDMap_EX;
	QMap<QString, TiXmlElement*>IEDMap_IN;
	Init_IED_MAP(CIDDocument->FirstChildElement("SCL"), IEDMap_EX);
	Init_IED_MAP(root, IEDMap_IN);


	QMap<QString, TiXmlElement*>LNMap;
	QMap<QString, TiXmlElement*>LNTypeMap;
	QMap<QString, TiXmlElement*>DOTypeMap;
	QMap<QString, TiXmlElement*>DATypeMap;
	QMap<QString, TiXmlElement*>EnumMap;
	CheckDataTempLate(CIDDocument, LNMap, LNTypeMap, DOTypeMap, DATypeMap, EnumMap);
	int iret;
	if ((LNTypeMap.size() == 0) && (DOTypeMap.size() == 0) && (DATypeMap.size() == 0) && ((EnumMap.size() == 0)))
	{
		if (ImportCID(IEDName) == DO_FAIL)
		{
			RemoveIED(IEDName);
			AutoReleaseUnuseDate();
			QMessageBox::warning(0, "Alarm", "Import CID false!");
			return DO_FAIL;
		}
		TiXmlNode *m_dateNode = CIDDocument->FirstChild("SCL")->FirstChild("DataTypeTemplates")->Clone();
		if (AddDateType(m_dateNode) == DO_FAIL)
		{
			RemoveIED(IEDName);
			AutoReleaseUnuseDate();
			QMessageBox::warning(0, "Alarm", "Import CID false!");
			return DO_FAIL;
		}
		return DO_OK;
	}
	bool flag = false;
	for (int i = 0; i < IEDMap_IN.uniqueKeys().size(); i++)
	{
		for (int j = 0; j < IEDMap_EX.uniqueKeys().size(); j++)
		{
			TiXmlElement* m_IN = NULL;
			TiXmlElement* m_EX = NULL;
			m_IN = IEDMap_IN.value(IEDMap_IN.uniqueKeys().at(i));
			m_EX = IEDMap_EX.value(IEDMap_EX.uniqueKeys().at(j));
			if (0 == strcmp(m_IN->Attribute("type"), m_EX->Attribute("type")))
			{
				flag = true;
			}
		}
	}
	if (flag == false)
	{
		AddDateType_AddPrefix(IEDName, CIDDocument->FirstChildElement("SCL"));
		ImportCID(IEDName);
		AddDateType(CIDDocument->FirstChildElement("SCL")->FirstChildElement("DataTypeTemplates"));
		return DO_OK;
	}
	DataTempLate *m_dlg = new DataTempLate();
	m_dlg->strName = IEDName;
	m_dlg->SetInit(4);
	if (m_dlg->exec() == QDialog::Accepted)
	{
		iret = m_dlg->state;

		switch (iret) {
		case 0x01:
			AddDateType_AddPrefix(IEDName, CIDDocument->FirstChildElement("SCL"));
			ImportCID(IEDName);
			AddDateType(CIDDocument->FirstChildElement("SCL")->FirstChildElement("DataTypeTemplates"));
			break;
		case 0x02:
			ImportCID(IEDName);
			AddDateType_Replace(IEDName, LNMap, LNTypeMap, DOTypeMap, DATypeMap, EnumMap);
			break;
		case 0x03:
			ImportCID(IEDName);
			AddDateType_Ignore(IEDName, LNMap, LNTypeMap, DOTypeMap, DATypeMap, EnumMap);
			break;
		default:
			break;
		}
	}
	else
	{

		return DO_OD;
	}

	return DO_OK;
}
int ScdTree::RemoveIED(QString IEDName)
{
	QMap<QString, TiXmlElement*> Map;
	for (TiXmlElement* Communication_node = root->FirstChildElement("Communication"); Communication_node != NULL; Communication_node = Communication_node->NextSiblingElement("Communication"))
	{
		for (TiXmlElement* SubNet_node = Communication_node->FirstChildElement("SubNetwork"); SubNet_node != NULL; SubNet_node = SubNet_node->FirstChildElement("SubNetwork"))
		{
			Init_ConnectAP_MAP(SubNet_node, Map);
			for (int i = 0; i < Map.values(IEDName).size(); i++)
			{
				SubNet_node->RemoveChild(Map.values(IEDName).at(i));
			}
		}


	}

	Init_IED_MAP(root, Map);
	root->RemoveChild(Map.value(IEDName));

	return DO_OK;
}

int ScdTree::CheckIEDName(QString strname)
{
	TiXmlElement *m_ChildElement = NULL;
	std::string str = strname.toStdString();

	const char* ch = str.c_str();
	m_ChildElement = root->FirstChildElement("IED");
	if (m_ChildElement == NULL)
		return DO_OK;
	for (m_ChildElement; m_ChildElement != NULL; m_ChildElement = m_ChildElement->NextSiblingElement("IED"))
	{
		if (0 != strcmp(m_ChildElement->Attribute("name"), ch))
		{
			continue;
		}
		else
		{
			return DO_FAIL;
		}
	}
	return DO_OK;
}
int ScdTree::LoadIEDFile(QString filename)
{
	TiXmlDocument *m_Document = new TiXmlDocument;

	if (false == m_Document->LoadFile(filename.toLocal8Bit().data(), TIXML_ENCODING_UTF8))
	{
		QString error;
		const char *ch;
		ch = m_Document->ErrorDesc();
		error += ch;
		int row = 0, column = 0;
		row = m_Document->ErrorRow();
		column = m_Document->ErrorCol();
		QMessageBox::information(NULL, QString("title"), QString("parse file failed at line row  %1 and column %2").arg(QString::number(row, 10)).arg(QString::number(column, 10)));

		return DO_FAIL;

	}
	TiXmlElement *m_RootElement = m_Document->FirstChildElement("SCL");

	TiXmlElement *m_IEDElement = m_RootElement->FirstChildElement("IED");

	if (m_IEDElement == NULL)
	{
		return DO_FAIL;
	}
	TiXmlElement *m_DataElement = m_RootElement->FirstChildElement("DataTypeTemplates");
	if (m_DataElement == NULL)
	{
		return DO_FAIL;
	}
	const char *ch;
	ch = m_IEDElement->Attribute("name");
	QString strName;
	strName += ch;
	if (strName.isEmpty())
	{
		return DO_FAIL;
	}
	strIEDName = strName;


	return DO_OK;

}
int ScdTree::LoadIEDFile(QString filename, QString &str)
{
	TiXmlDocument *m_Document = new TiXmlDocument;

	if (false == m_Document->LoadFile(filename.toLocal8Bit().data()))
	{
		QString error;
		const char *ch;
		ch = m_Document->ErrorDesc();
		error += ch;
		int row = 0, column = 0;
		row = m_Document->ErrorRow();
		column = m_Document->ErrorCol();
		QMessageBox::information(NULL, QString("Title"), QString("Parse file failed at line row  %1 and column %2\n%3").arg(QString::number(row, 10)).arg(QString::number(column, 10).arg(error)));

		return DO_FAIL;

	}
	TiXmlElement *m_RootElement = m_Document->FirstChildElement("SCL");
	TiXmlElement *m_IEDElement = m_RootElement->FirstChildElement("IED");
	if (m_IEDElement == NULL)
	{
		return DO_FAIL;
	}
	TiXmlElement *m_DataElement = m_RootElement->FirstChildElement("DataTypeTemplates");
	if (m_DataElement == NULL)
	{
		return DO_FAIL;
	}
	const char *ch;
	ch = m_IEDElement->Attribute("name");
	QString strName;
	str += ch;
	strName = str;
	if (str.isEmpty())
	{
		return DO_FAIL;
	}


	return DO_OK;
}

QString ScdTree::GetIEDName()
{
	return strIEDName;
}
int ScdTree::ADDOneAp(TiXmlNode *Xmlnode, QString IEDName)
{

	std::string str = IEDName.toStdString();

	const char* c_ied = str.c_str();
	TiXmlElement *m_FindNode = NULL;
	TiXmlElement *m_ConnectAP = NULL;
	TiXmlElement *m_element = Xmlnode->FirstChildElement("SubNetwork");
	TiXmlElement *m_ComNode = root->FirstChildElement("Communication");
	for (; m_element != NULL; m_element = m_element->NextSiblingElement("SubNetwork"))
	{
		m_FindNode = m_ComNode->GetChildByName_Value(m_ComNode, "type", m_element->Attribute("type"));
		if (m_FindNode != NULL)
		{
			for (TiXmlNode* childe = m_element->FirstChildElement("ConnectedAP"); childe != NULL; childe = childe->NextSiblingElement("ConnectedAP"))
			{
				TiXmlNode* m_node = childe->Clone();
				m_node->ToElement()->SetAttribute("iedName", c_ied);
				m_FindNode->LinkEndChild(m_node);
			}
		}
		else
		{
			for (m_ConnectAP = m_element->FirstChildElement("ConnectedAP"); m_ConnectAP != NULL; m_ConnectAP = m_ConnectAP->NextSiblingElement("ConnectedAP"))
			{
				if (m_ConnectAP->FirstChildElement("Address") != NULL)
				{
					m_FindNode = m_ComNode->GetChildByName_Value(m_ComNode, "type", "8-MMS");
					if (m_FindNode != NULL)
					{
						TiXmlNode* m_node = m_ConnectAP->Clone();
						m_node->ToElement()->SetAttribute("iedName", c_ied);
						m_FindNode->LinkEndChild(m_node);
					}
				}
				else if (m_ConnectAP->FirstChildElement("GSE") != NULL)
				{
					m_FindNode = m_ComNode->GetChildByName_Value(m_ComNode, "type", "IECGOOSE");
					if (m_FindNode != NULL)
					{
						TiXmlNode* m_node = m_ConnectAP->Clone();
						m_node->ToElement()->SetAttribute("iedName", c_ied);
						m_FindNode->LinkEndChild(m_node);
					}
				}
				else if (m_ConnectAP->FirstChildElement("SMV") != NULL)
				{
					m_FindNode = m_ComNode->GetChildByName_Value(m_ComNode, "type", "SMV");
					if (m_FindNode != NULL)
					{
						TiXmlNode* m_node = m_ConnectAP->Clone();
						m_node->ToElement()->SetAttribute("iedName", c_ied);
						m_FindNode->LinkEndChild(m_node);
					}
				}
			}
		}


	}

	return DO_OK;

}
int ScdTree::AddOneIED(TiXmlNode *Xmlnode)
{
	TiXmlNode *m_XmlNode = root->LastChild("IED");
	if (m_XmlNode == NULL)
	{
		root->LinkEndChild(Xmlnode);
		return DO_OK;
	}
	root->InsertAfterChild(m_XmlNode, *Xmlnode);
	return DO_OK;
}
int ScdTree::AddDateType(TiXmlNode *Xmlnode)
{
	TiXmlNode *m_XmlNode = root->FirstChild("DataTypeTemplates");

	if (m_XmlNode == NULL)
	{
		root->LinkEndChild(Xmlnode);
		DataTypeNode = root->FirstChild("DataTypeTemplates")->ToElement();
		return DO_OK;
	}

	TiXmlNode *m_childnode = m_XmlNode->LastChild("LNodeType");
	QMap<QString, TiXmlElement*>Map;
	TiXmlElement *m_node = NULL;
	TiXmlNode *m_data;
	QStringList keys;
	Init_LNtype_MAP(Xmlnode->ToElement(), Map);
	keys.clear();
	keys = Map.keys();
	for (int i = 0; i < keys.size(); i++)
	{
		m_node = Map.value(keys.at(i));
		m_data = m_node->Clone();

		m_XmlNode->InsertAfterChild(m_childnode, *m_data);
	}

	m_childnode = m_XmlNode->LastChild("DOType");
	Init_DOType_MAP(Xmlnode->ToElement(), Map);
	keys.clear();
	keys = Map.keys();
	for (int i = 0; i < keys.size(); i++)
	{
		m_node = Map.value(keys.at(i));
		m_data = m_node->Clone();

		m_XmlNode->InsertAfterChild(m_childnode, *m_data);
	}

	m_childnode = m_XmlNode->LastChild("DAType");
	Init_DAtype_MAP(Xmlnode->ToElement(), Map);
	keys.clear();
	keys = Map.keys();
	for (int i = 0; i < keys.size(); i++)
	{
		m_node = Map.value(keys.at(i));
		m_data = m_node->Clone();

		m_XmlNode->InsertAfterChild(m_childnode, *m_data);
	}

	m_childnode = m_XmlNode->LastChild("EnumType");
	Init_EnumType_MAP(Xmlnode->ToElement(), Map);
	QMap<QString, TiXmlElement*>Map1;
	Init_EnumType_MAP(m_XmlNode->ToElement(), Map1);
	keys.clear();
	keys = Map.keys();
	for (int i = 0; i < keys.size(); i++)
	{
		if (!Map1.keys().contains(keys.at(i)))
		{
			m_node = Map.value(keys.at(i));
			m_data = m_node->Clone();

			m_XmlNode->InsertAfterChild(m_childnode, *m_data);
		}

	}
	DataTypeNode = root->FirstChild("DataTypeTemplates")->ToElement();

	return DO_OK;

	//	for (m_childnode; m_childnode != NULL; m_childnode = m_childnode->NextSibling("LNodeType"))
	//	{
	//		TiXmlElement *m_FindNode = m_XmlNode->GetChildByName_Value(m_XmlNode->ToElement(), "id", m_childnode->ToElement()->Attribute("id"));

	//		if (m_FindNode == NULL)
	//		{
	//			TiXmlNode *new_xmlnoe = m_childnode->Clone();
	//			QString str = QString(QLatin1String(new_xmlnoe->ToElement()->Attribute("id")));
	//			QString str2 = QString(QLatin1String(m_XmlNode->LastChild("LNodeType")->ToElement()->Attribute("id")));
	//			m_XmlNode->InsertAfterChild(m_XmlNode->LastChild("LNodeType"), *new_xmlnoe);
	//			continue;

	//		}
	//		TiXmlElement *m_childelemnet = m_childnode->FirstChildElement();

	//		for (m_childelemnet; m_childelemnet != NULL; m_childelemnet = m_childelemnet->NextSiblingElement())
	//		{
	//			TiXmlElement *m_elemnet = m_FindNode->GetChildByName_Value(m_FindNode, "name", m_childelemnet->Attribute("name"));
	//			QString str1, str2;
	//			if (m_elemnet != NULL)
	//			{
	//				str1 = QString(QLatin1String(m_childelemnet->Attribute("name")));
	//				str2 = QString(QLatin1String(m_elemnet->Attribute("name")));
	//			}
	//			if (m_elemnet == NULL)
	//			{


	//				TiXmlElement *m_newelement;
	//				m_newelement = m_childelemnet->Clone()->ToElement();

	//				m_FindNode->LinkEndChild(m_newelement);
	//			}

	//		}


	//	}
	//	m_childnode = Xmlnode->FirstChild("DOType");

	//	for (m_childnode; m_childnode != NULL; m_childnode = m_childnode->NextSibling("DOType"))
	//	{
	//		TiXmlElement *m_FindNode = m_XmlNode->GetChildByName_Value(m_XmlNode->ToElement(), "id", m_childnode->ToElement()->Attribute("id"));
	//		if (m_FindNode == NULL)
	//		{
	//			TiXmlNode *new_xmlnoe = m_childnode->Clone();
	//			m_XmlNode->InsertAfterChild(m_XmlNode->LastChild("DOType"), *new_xmlnoe);

	//			continue;
	//		}
	//		TiXmlElement *m_childelemnet = m_childnode->FirstChildElement();

	//		for (m_childelemnet; m_childelemnet != NULL; m_childelemnet = m_childelemnet->NextSiblingElement())
	//		{
	//			TiXmlElement *m_elemnet = m_FindNode->GetChildByName_Value(m_FindNode, "name", m_childelemnet->Attribute("name"));
	//			QString str1, str2;
	//			if (m_elemnet != NULL)
	//			{
	//				str1 = QString(QLatin1String(m_childelemnet->Attribute("name")));
	//				str2 = QString(QLatin1String(m_elemnet->Attribute("name")));
	//			}
	//			if (m_elemnet == NULL)
	//			{


	//				TiXmlElement *m_newelement;
	//				m_newelement = m_childelemnet->Clone()->ToElement();

	//				m_FindNode->LinkEndChild(m_newelement);
	//			}

	//		}


	//	}
	//	m_childnode = Xmlnode->FirstChild("DAType");

	//	for (m_childnode; m_childnode != NULL; m_childnode = m_childnode->NextSibling("DAType"))
	//	{
	//		TiXmlElement *m_FindNode = m_XmlNode->GetChildByName_Value(m_XmlNode->ToElement(), "id", m_childnode->ToElement()->Attribute("id"));
	//		if (m_FindNode == NULL)
	//		{
	//			TiXmlNode *new_xmlnoe = m_childnode->Clone();
	//			m_XmlNode->InsertAfterChild(m_XmlNode->LastChild("DAType"), *new_xmlnoe);
	//			continue;
	//		}
	//		TiXmlElement *m_childelemnet = m_childnode->FirstChildElement();

	//		for (m_childelemnet; m_childelemnet != NULL; m_childelemnet = m_childelemnet->NextSiblingElement())
	//		{
	//			TiXmlElement *m_elemnet = m_FindNode->GetChildByName_Value(m_FindNode, "name", m_childelemnet->Attribute("name"));
	//			QString str1, str2;
	//			if (m_elemnet != NULL)
	//			{
	//				str1 = QString(QLatin1String(m_childelemnet->Attribute("name")));
	//				str2 = QString(QLatin1String(m_elemnet->Attribute("name")));
	//			}
	//			if (m_elemnet == NULL)
	//			{


	//				TiXmlElement *m_newelement;
	//				m_newelement = m_childelemnet->Clone()->ToElement();

	//				m_FindNode->LinkEndChild(m_newelement);
	//			}

	//		}


	//	}
	//	m_childnode = Xmlnode->FirstChild("EnumType");

	//	for (m_childnode; m_childnode != NULL; m_childnode = m_childnode->NextSibling("EnumType"))
	//	{
	//		TiXmlElement *m_FindNode = m_XmlNode->GetChildByName_Value(m_XmlNode->ToElement(), "id", m_childnode->ToElement()->Attribute("id"));
	//		if (m_FindNode == NULL)
	//		{
	//			TiXmlNode *new_xmlnoe = m_childnode->Clone();
	//			m_XmlNode->InsertAfterChild(m_XmlNode->LastChild("EnumType"), *new_xmlnoe);
	//			continue;
	//		}
	//		TiXmlElement *m_childelemnet = m_childnode->FirstChildElement();

	//		for (m_childelemnet; m_childelemnet != NULL; m_childelemnet = m_childelemnet->NextSiblingElement())
	//		{
	//			TiXmlElement *m_elemnet = m_FindNode->GetChildByName_Value(m_FindNode, "ord", m_childelemnet->Attribute("ord"));
	//			QString str1, str2;
	//			if (m_elemnet != NULL)
	//			{
	//				str1 = QString(QLatin1String(m_childelemnet->Attribute("ord")));
	//				str2 = QString(QLatin1String(m_elemnet->Attribute("ord")));
	//			}
	//			if (m_elemnet == NULL)
	//			{


	//				TiXmlElement *m_newelement;
	//				m_newelement = m_childelemnet->Clone()->ToElement();

	//				m_FindNode->LinkEndChild(m_newelement);
	//			}

	//		}


	//	}
	//	DataTypeNode = root->FirstChild("DataTypeTemplates")->ToElement();

	//	return DO_OK;
}
int ScdTree::AddDateType_AddPrefix(QString IEDName, TiXmlElement* Ext_SCL)
{
	QMap<QString, TiXmlElement*> Child_Map_Local;
	QMap<QString, TiXmlElement*> Child_Map_Ext;
	QMap<QString, TiXmlElement*> LD_Map;
	QMap<QString, TiXmlElement*> LN_Map;
	QMap<QString, QString>Type_List;
	QStringList m_List;
	TiXmlElement* m_Data_Local = NULL;
	TiXmlElement* m_Data_Ext = NULL;
	TiXmlElement* m_Child = NULL;
	m_Data_Ext = Ext_SCL->FirstChildElement("DataTypeTemplates");
	m_Data_Local = root->FirstChildElement("DataTypeTemplates");
	Init_EnumType_MAP(m_Data_Ext, Child_Map_Ext);
	Init_EnumType_MAP(m_Data_Local, Child_Map_Local);
	bool flag = true;
	while (flag == true)
	{
		flag = false;

		for (int i = 0; i < Child_Map_Ext.uniqueKeys().size(); i++)
		{
			if (!Child_Map_Local.uniqueKeys().contains(Child_Map_Ext.uniqueKeys().at(i)))
			{
				flag = false;
				continue;

			}
			else
			{
				if (false == Compare_Node(Child_Map_Local.value(Child_Map_Ext.uniqueKeys().at(i)), Child_Map_Ext.value(Child_Map_Ext.uniqueKeys().at(i))))
				{
					const char* chr;
					QString str, str2;
					chr = Child_Map_Ext.value(Child_Map_Ext.uniqueKeys().at(i))->Attribute("id");
					str2 += chr;
					str = IEDName + "_";
					str += chr;
					Child_Map_Ext.value(Child_Map_Ext.uniqueKeys().at(i))->SetAttribute("id", str.toStdString().data());
					Type_List.insert(str2, str);
					m_List.append(str);
					flag = true;
				}
				else
				{
					flag = false;
					continue;
				}
			}
		}
	}

	//Init_DAtype_MAP(m_Data_Ext, Child_Map_Ext);
	//Init_DAtype_MAP(m_Data_Local, Child_Map_Local);
	flag = true;
	while (flag == true)
	{
		Init_DAtype_MAP(m_Data_Ext, Child_Map_Ext);
		Init_DAtype_MAP(m_Data_Local, Child_Map_Local);
		flag = false;
		for (int i = 0; i < Child_Map_Ext.uniqueKeys().size(); i++)
		{
			for (m_Child = Child_Map_Ext.value(Child_Map_Ext.uniqueKeys().at(i))->FirstChildElement(); m_Child != NULL; m_Child = m_Child->NextSiblingElement())
			{
				QString str, str2;
				const char* chr;
				if (m_Child->Attribute("type") == NULL)
				{
					continue;
				}
				str += m_Child->Attribute("type");

				if (Type_List.uniqueKeys().contains(str))
				{

					m_Child->SetAttribute("type", Type_List.value(str).toStdString().data());
					chr = Child_Map_Ext.value(Child_Map_Ext.uniqueKeys().at(i))->Attribute("id");
					str2.clear();

					str2 += chr;
					if (!Type_List.uniqueKeys().contains(str2))
					{
						str.clear();
						str = IEDName + "_";
						str += chr;
						//Child_Map_Ext.value(Child_Map_Ext.uniqueKeys().at(i))->SetAttribute("id", str.toStdString().data());
						//Type_List.insert(str2, str);
						//Type_List.insert(str, str);
						flag = true;
					}


				}
			}
		}
		Init_DAtype_MAP(m_Data_Ext, Child_Map_Ext);
		Init_DAtype_MAP(m_Data_Local, Child_Map_Local);
		for (int i = 0; i < Child_Map_Ext.uniqueKeys().size(); i++)
		{
			if (!Child_Map_Local.uniqueKeys().contains(Child_Map_Ext.uniqueKeys().at(i)))
			{
				flag = false;
				continue;

			}
			else
			{
				if (false == Compare_Node(Child_Map_Local.value(Child_Map_Ext.uniqueKeys().at(i)), Child_Map_Ext.value(Child_Map_Ext.uniqueKeys().at(i))))
				{
					const char* chr;
					QString str, str2;
					chr = Child_Map_Ext.value(Child_Map_Ext.uniqueKeys().at(i))->Attribute("id");
					str2.clear();
					str.clear();
					str2 += chr;
					if (Type_List.uniqueKeys().contains(str2))
					{
						continue;
					}
					str = IEDName + "_";
					str += chr;
					Child_Map_Ext.value(Child_Map_Ext.uniqueKeys().at(i))->SetAttribute("id", str.toStdString().data());
					Type_List.insert(str2, str);
					m_List.append(str);
					flag = true;
				}
				else
				{
					flag = false;
					continue;
				}
			}
		}
	}
	flag = true;
	while (flag == true)
	{
		Init_DOType_MAP(m_Data_Ext, Child_Map_Ext);
		Init_DOType_MAP(m_Data_Local, Child_Map_Local);
		flag = false;
		for (int i = 0; i < Child_Map_Ext.uniqueKeys().size(); i++)
		{
			for (m_Child = Child_Map_Ext.value(Child_Map_Ext.uniqueKeys().at(i))->FirstChildElement(); m_Child != NULL; m_Child = m_Child->NextSiblingElement())
			{
				QString str, str2;
				const char* chr;
				if (m_Child->Attribute("type") == NULL)
				{
					continue;
				}
				str += m_Child->Attribute("type");

				if (Type_List.uniqueKeys().contains(str))
				{

					m_Child->SetAttribute("type", Type_List.value(str).toStdString().data());
					chr = Child_Map_Ext.value(Child_Map_Ext.uniqueKeys().at(i))->Attribute("id");
					str2.clear();

					str2 += chr;
					if (!Type_List.uniqueKeys().contains(str2))
					{
						str.clear();
						str = IEDName + "_";
						str += chr;
						//Child_Map_Ext.value(Child_Map_Ext.uniqueKeys().at(i))->SetAttribute("id", str.toStdString().data());
						//Type_List.insert(str2, str);
						//Type_List.insert(str, str);
						flag = true;
					}


				}
			}
		}
		Init_DOType_MAP(m_Data_Ext, Child_Map_Ext);
		Init_DOType_MAP(m_Data_Local, Child_Map_Local);
		for (int i = 0; i < Child_Map_Ext.uniqueKeys().size(); i++)
		{
			if (!Child_Map_Local.uniqueKeys().contains(Child_Map_Ext.uniqueKeys().at(i)))
			{
				flag = false;
				continue;

			}
			else
			{
				if (false == Compare_Node(Child_Map_Local.value(Child_Map_Ext.uniqueKeys().at(i)), Child_Map_Ext.value(Child_Map_Ext.uniqueKeys().at(i))))
				{
					const char* chr;
					QString str, str2;
					chr = Child_Map_Ext.value(Child_Map_Ext.uniqueKeys().at(i))->Attribute("id");
					str2.clear();
					str.clear();
					str2 += chr;
					if (Type_List.uniqueKeys().contains(str2))
					{
						continue;
					}
					str = IEDName + "_";
					str += chr;
					Child_Map_Ext.value(Child_Map_Ext.uniqueKeys().at(i))->SetAttribute("id", str.toStdString().data());
					Type_List.insert(str2, str);
					m_List.append(str);
					flag = true;
				}
				else
				{
					flag = false;
					continue;
				}
			}
		}
	}
	flag = true;

	while (flag == true)
	{
		Init_LNtype_MAP(m_Data_Ext, Child_Map_Ext);
		Init_LNtype_MAP(m_Data_Local, Child_Map_Local);
		flag = false;
		for (int i = 0; i < Child_Map_Ext.uniqueKeys().size(); i++)
		{
			for (m_Child = Child_Map_Ext.value(Child_Map_Ext.uniqueKeys().at(i))->FirstChildElement(); m_Child != NULL; m_Child = m_Child->NextSiblingElement())
			{
				QString str, str2;
				const char* chr;
				if (m_Child->Attribute("type") == NULL)
				{
					continue;
				}
				str += m_Child->Attribute("type");

				if (Type_List.uniqueKeys().contains(str))
				{

					m_Child->SetAttribute("type", Type_List.value(str).toStdString().data());
					chr = Child_Map_Ext.value(Child_Map_Ext.uniqueKeys().at(i))->Attribute("id");
					str2.clear();

					str2 += chr;

					//if (!Type_List.uniqueKeys().contains(str2) )
					//{
					//	str.clear();
					//	str = IEDName + "_";
					//	str += chr;
					//	//Child_Map_Ext.value(Child_Map_Ext.uniqueKeys().at(i))->SetAttribute("id", str.toStdString().data());
					//	//Type_List.insert(str2, str);
					//	//Type_List.insert(str, str);
					//	flag = true;
					//}


				}
			}
		}
		Init_LNtype_MAP(m_Data_Ext, Child_Map_Ext);
		Init_LNtype_MAP(m_Data_Local, Child_Map_Local);
		for (int i = 0; i < Child_Map_Ext.uniqueKeys().size(); i++)
		{
			if (!Child_Map_Local.uniqueKeys().contains(Child_Map_Ext.uniqueKeys().at(i)))
			{
				flag = false;
				continue;

			}
			else
			{
				if (false == Compare_Node(Child_Map_Local.value(Child_Map_Ext.uniqueKeys().at(i)), Child_Map_Ext.value(Child_Map_Ext.uniqueKeys().at(i))))
				{
					const char* chr;
					QString str, str2;
					chr = Child_Map_Ext.value(Child_Map_Ext.uniqueKeys().at(i))->Attribute("id");
					str2.clear();
					str.clear();
					str2 += chr;
					if (Type_List.uniqueKeys().contains(str2))
					{
						continue;
					}
					str = IEDName + "_";
					str += chr;
					Child_Map_Ext.value(Child_Map_Ext.uniqueKeys().at(i))->SetAttribute("id", str.toStdString().data());
					Type_List.insert(str2, str);
					m_List.append(str);
					flag = true;
				}
				else
				{
					flag = false;
					continue;
				}
			}
		}
	}
	Init_LNtype_MAP(m_Data_Ext, Child_Map_Ext);
	Init_LNtype_MAP(m_Data_Local, Child_Map_Local);
	for (int i = 0; i < Child_Map_Ext.uniqueKeys().size(); i++)
	{
		if (Child_Map_Local.uniqueKeys().contains(Child_Map_Ext.uniqueKeys().at(i)))
		{
			m_Data_Ext->RemoveChild(Child_Map_Ext.value(Child_Map_Ext.uniqueKeys().at(i)));
		}
	}
	Init_DOType_MAP(m_Data_Ext, Child_Map_Ext);
	Init_DOType_MAP(m_Data_Local, Child_Map_Local);
	for (int i = 0; i < Child_Map_Ext.uniqueKeys().size(); i++)
	{
		if (Child_Map_Local.uniqueKeys().contains(Child_Map_Ext.uniqueKeys().at(i)))
		{
			m_Data_Ext->RemoveChild(Child_Map_Ext.value(Child_Map_Ext.uniqueKeys().at(i)));
		}
	}
	Init_DAtype_MAP(m_Data_Ext, Child_Map_Ext);
	Init_DAtype_MAP(m_Data_Local, Child_Map_Local);
	for (int i = 0; i < Child_Map_Ext.uniqueKeys().size(); i++)
	{
		if (Child_Map_Local.uniqueKeys().contains(Child_Map_Ext.uniqueKeys().at(i)))
		{
			m_Data_Ext->RemoveChild(Child_Map_Ext.value(Child_Map_Ext.uniqueKeys().at(i)));
		}
	}
	Init_EnumType_MAP(m_Data_Ext, Child_Map_Ext);
	Init_EnumType_MAP(m_Data_Local, Child_Map_Local);
	for (int i = 0; i < Child_Map_Ext.uniqueKeys().size(); i++)
	{
		if (Child_Map_Local.uniqueKeys().contains(Child_Map_Ext.uniqueKeys().at(i)))
		{
			m_Data_Ext->RemoveChild(Child_Map_Ext.value(Child_Map_Ext.uniqueKeys().at(i)));
		}
	}
	m_Child = Ext_SCL->FirstChildElement("IED");
	Init_LD_MAP(m_Child, LD_Map);
	for (int i = 0; i < LD_Map.uniqueKeys().size(); i++)
	{
		Init_LN_MAP(LD_Map.value(LD_Map.uniqueKeys().at(i)), LN_Map);
		for (int j = 0; j < LN_Map.uniqueKeys().size(); j++)
		{
			QString str;
			str += LN_Map.value(LN_Map.uniqueKeys().at(j))->Attribute("lnType");
			if (Type_List.uniqueKeys().contains(str))
			{
				LN_Map.value(LN_Map.uniqueKeys().at(j))->SetAttribute("lnType", Type_List.value(str).toStdString().data());
			}
		}
	}
	return DO_OK;


}
int ScdTree::AddDateType_AddPrefix(QString IEDName, QMap<QString, TiXmlElement*>&LNTypeMap, QMap<QString, TiXmlElement*>&DOTypeMap,
	QMap<QString, TiXmlElement*>&DATypeMap, QMap<QString, TiXmlElement*>&EnumMap)
{
	QStringList keys;
	QString str;
	QMap<QString, TiXmlElement*>ChildMap;
	QMap<QString, TiXmlElement*>IEDMap;
	Init_IED_MAP(CIDDocument->FirstChildElement("SCL"), IEDMap);
	QMap<QString, TiXmlElement*>LDMap;
	QMap<QString, TiXmlElement*>LNMap;
	for (int i = 0; i < IEDMap.keys().size(); i++)
	{
		Init_LD_MAP(IEDMap.value(IEDMap.keys().at(i)), LDMap);
		for (int j = 0; j < LDMap.keys().size(); j++)
		{
			Init_Child_Map(LDMap.value(LDMap.keys().at(j)), LNMap, "lnType");
			for (int m = 0; m < LNMap.keys().size(); m++)
			{
				if (LNTypeMap.keys().contains(QString::fromLocal8Bit(LNMap.value(LNMap.keys().at(m))->Attribute("lnType"))))
				{
					str.clear();
					str = IEDName + "__" + LNMap.keys().at(m);
					for (int n = 0; n < LNMap.values(LNMap.keys().at(m)).size(); n++)
					{
						LNMap.values(LNMap.keys().at(m)).at(n)->SetAttribute("lnType", str.toStdString().data());
					}
				}
			}
		}
	}
	for (int i = 0; i < LNTypeMap.keys().size(); i++)
	{
		str.clear();
		str = IEDName + "__" + LNTypeMap.keys().at(i);
		LNTypeMap.value(LNTypeMap.keys().at(i))->SetAttribute("id", str.toStdString().data());
		Init_Child_Map(LNTypeMap.value(LNTypeMap.keys().at(i)), ChildMap, "name");
		for (int j = 0; j < ChildMap.keys().size(); j++)
		{
			if (DOTypeMap.keys().contains(QString::fromLocal8Bit(ChildMap.value(ChildMap.keys().at(j))->Attribute("type"))) ||
				DATypeMap.keys().contains(QString::fromLocal8Bit(ChildMap.value(ChildMap.keys().at(j))->Attribute("type")))
				)
			{
				str.clear();
				str = IEDName + "__" + QString::fromLocal8Bit(ChildMap.value(ChildMap.keys().at(j))->Attribute("type"));
				ChildMap.value(ChildMap.keys().at(j))->SetAttribute("type", str.toStdString().data());
			}
		}
	}
	for (int i = 0; i < DOTypeMap.keys().size(); i++)
	{
		str.clear();
		str = IEDName + "__" + DOTypeMap.keys().at(i);
		DOTypeMap.value(DOTypeMap.keys().at(i))->SetAttribute("id", str.toStdString().data());
		Init_Child_Map(DOTypeMap.value(DOTypeMap.keys().at(i)), ChildMap, "name");
		for (int j = 0; j < ChildMap.keys().size(); j++)
		{
			if (DOTypeMap.keys().contains(QString::fromLocal8Bit(ChildMap.value(ChildMap.keys().at(j))->Attribute("type"))) ||
				DATypeMap.keys().contains(QString::fromLocal8Bit(ChildMap.value(ChildMap.keys().at(j))->Attribute("type")))
				)
			{
				str.clear();
				str = IEDName + "__" + QString::fromLocal8Bit(ChildMap.value(ChildMap.keys().at(j))->Attribute("type"));
				ChildMap.value(ChildMap.keys().at(j))->SetAttribute("type", str.toStdString().data());
			}
		}
	}
	for (int i = 0; i < DATypeMap.keys().size(); i++)
	{
		str.clear();
		str = IEDName + "__" + DATypeMap.keys().at(i);
		DATypeMap.value(DATypeMap.keys().at(i))->SetAttribute("id", str.toStdString().data());
		Init_Child_Map(DATypeMap.value(DATypeMap.keys().at(i)), ChildMap, "name");
		for (int j = 0; j < ChildMap.keys().size(); j++)
		{
			if (DOTypeMap.keys().contains(QString::fromLocal8Bit(ChildMap.value(ChildMap.keys().at(j))->Attribute("type"))) ||
				DATypeMap.keys().contains(QString::fromLocal8Bit(ChildMap.value(ChildMap.keys().at(j))->Attribute("type")))
				)
			{
				str.clear();
				str = IEDName + "__" + QString::fromLocal8Bit(ChildMap.value(ChildMap.keys().at(j))->Attribute("type"));
				ChildMap.value(ChildMap.keys().at(j))->SetAttribute("type", str.toStdString().data());

			}
		}
	}

	return DO_OK;
}

int ScdTree::AddDateType_Ignore(QString IEDName, QMap<QString, TiXmlElement*> &LNMap, QMap<QString, TiXmlElement*>&LNTypeMap, QMap<QString, TiXmlElement*>&DOTypeMap,
	QMap<QString, TiXmlElement*>&DATypeMap, QMap<QString, TiXmlElement*>&EnumMap)
{
	TiXmlElement *m_DataTemplate_EX = NULL;
	TiXmlElement *m_DataTemplate_IN = NULL;
	TiXmlNode *m_node;
	QMap<QString, TiXmlElement*> Map_EX;
	QStringList keys;

	m_DataTemplate_EX = CIDDocument->FirstChildElement("DataTypeTemplates");
	m_DataTemplate_IN = root->FirstChildElement("DataTypeTemplates");

	Init_LNtype_MAP(m_DataTemplate_EX, Map_EX);
	keys = LNTypeMap.keys();
	for (int i = 0; i < keys.size(); i++)
	{
		Map_EX.remove(keys.at(i));
	}
	keys = Map_EX.keys();
	for (int i = 0; i < keys.size(); i++)
	{
		m_node = Map_EX.value(keys.at(i))->Clone();
		m_DataTemplate_IN->InsertAfterChild(m_DataTemplate_IN->LastChild("LNodeType"), *m_node);
	}

	Init_DOType_MAP(m_DataTemplate_EX, Map_EX);
	keys = DOTypeMap.keys();
	for (int i = 0; i < keys.size(); i++)
	{
		Map_EX.remove(keys.at(i));
	}
	keys = Map_EX.keys();
	for (int i = 0; i < keys.size(); i++)
	{
		m_node = Map_EX.value(keys.at(i))->Clone();
		m_DataTemplate_IN->InsertAfterChild(m_DataTemplate_IN->LastChild("DOType"), *m_node);
	}

	Init_DAtype_MAP(m_DataTemplate_EX, Map_EX);
	keys = DATypeMap.keys();
	for (int i = 0; i < keys.size(); i++)
	{
		Map_EX.remove(keys.at(i));
	}
	keys = Map_EX.keys();
	for (int i = 0; i < keys.size(); i++)
	{
		m_node = Map_EX.value(keys.at(i))->Clone();
		m_DataTemplate_IN->InsertAfterChild(m_DataTemplate_IN->LastChild("DAType"), *m_node);
	}

	Init_EnumType_MAP(m_DataTemplate_EX, Map_EX);
	keys = EnumMap.keys();
	for (int i = 0; i < keys.size(); i++)
	{
		Map_EX.remove(keys.at(i));
	}
	keys = Map_EX.keys();
	for (int i = 0; i < keys.size(); i++)
	{
		m_node = Map_EX.value(keys.at(i))->Clone();
		m_DataTemplate_IN->InsertAfterChild(m_DataTemplate_IN->LastChild("EnumType"), *m_node);
	}
	return DO_OK;
}

int ScdTree::AddDateType_Merge(QString IEDName, QMap<QString, TiXmlElement*> &LNMap, QMap<QString, TiXmlElement*>&LNTypeMap, QMap<QString, TiXmlElement*>&DOTypeMap,
	QMap<QString, TiXmlElement*>&DATypeMap, QMap<QString, TiXmlElement*>&EnumMap)
{
	TiXmlElement *m_DataTemplate_EX = NULL;
	TiXmlElement *m_DataTemplate_IN = NULL;
	TiXmlNode *m_Node_EX = NULL;
	TiXmlNode *m_Node_IN = NULL;
	TiXmlElement *m_EleMent_EX = NULL;
	TiXmlElement *m_Element_IN = NULL;
	QMap<QString, TiXmlElement*> Map_EX;
	QMap<QString, TiXmlElement*> Map_IN;
	QMap<QString, TiXmlElement*> ChildMap_EX;
	QMap<QString, TiXmlElement*> ChildMap_IN;
	QStringList Keys_EX, Keys_IN;
	QStringList keys;
	m_DataTemplate_EX = CIDDocument->FirstChildElement("DataTypeTemplates");
	m_DataTemplate_IN = root->FirstChildElement("DataTypeTemplates");


	Init_LNtype_MAP(m_DataTemplate_IN, Map_IN);
	keys = LNTypeMap.keys();
	for (int i = 0; i < keys.size(); i++)
	{
		m_EleMent_EX = LNTypeMap.value(keys.at(i));
		m_Element_IN = Map_IN.value(keys.at(i));
		Init_Child_Map(m_EleMent_EX, ChildMap_EX, "name");
		Init_Child_Map(m_Element_IN, ChildMap_IN, "name");
		for (int j = 0; j < ChildMap_EX.keys().size(); j++)
		{
			if (!ChildMap_IN.keys().contains(ChildMap_EX.keys().at(j)))
			{
				m_Node_EX = ChildMap_EX.value(ChildMap_EX.keys().at(j))->Clone();
				m_Element_IN->LinkEndChild(m_Node_EX);
			}
			else
			{
				continue;
			}
		}
	}

	Init_DOType_MAP(m_DataTemplate_IN, Map_IN);
	keys = DOTypeMap.keys();
	for (int i = 0; i < keys.size(); i++)
	{
		m_EleMent_EX = DOTypeMap.value(keys.at(i));
		m_Element_IN = Map_IN.value(keys.at(i));
		Init_Child_Map(m_EleMent_EX, ChildMap_EX, "name");
		Init_Child_Map(m_Element_IN, ChildMap_IN, "name");
		for (int j = 0; j < ChildMap_EX.keys().size(); j++)
		{
			if (!ChildMap_IN.keys().contains(ChildMap_EX.keys().at(j)))
			{
				m_Node_EX = ChildMap_EX.value(ChildMap_EX.keys().at(j))->Clone();
				m_Element_IN->LinkEndChild(m_Node_EX);
			}
			else
			{
				continue;
			}
		}
	}
	Init_DAtype_MAP(m_DataTemplate_IN, Map_IN);
	keys = DATypeMap.keys();
	for (int i = 0; i < keys.size(); i++)
	{
		m_EleMent_EX = DATypeMap.value(keys.at(i));
		m_Element_IN = Map_IN.value(keys.at(i));
		Init_Child_Map(m_EleMent_EX, ChildMap_EX, "name");
		Init_Child_Map(m_Element_IN, ChildMap_IN, "name");
		for (int j = 0; j < ChildMap_EX.keys().size(); j++)
		{
			if (!ChildMap_IN.keys().contains(ChildMap_EX.keys().at(j)))
			{
				m_Node_EX = ChildMap_EX.value(ChildMap_EX.keys().at(j))->Clone();
				m_Element_IN->LinkEndChild(m_Node_EX);
			}
			else
			{
				continue;
			}
		}
	}

	Init_EnumType_MAP(m_DataTemplate_IN, Map_IN);
	keys = EnumMap.keys();
	for (int i = 0; i < keys.size(); i++)
	{
		m_EleMent_EX = EnumMap.value(keys.at(i));
		m_Element_IN = Map_IN.value(keys.at(i));
		Init_Child_Map(m_EleMent_EX, ChildMap_EX, "ord");
		Init_Child_Map(m_Element_IN, ChildMap_IN, "ord");
		for (int j = 0; j < ChildMap_EX.keys().size(); j++)
		{
			if (!ChildMap_IN.keys().contains(ChildMap_EX.keys().at(j)))
			{
				m_Node_EX = ChildMap_EX.value(ChildMap_EX.keys().at(j))->Clone();
				m_Element_IN->LinkEndChild(m_Node_EX);
			}
			else
			{
				continue;
			}
		}
	}
	return DO_OK;
}

int ScdTree::AddDateType_Replace(QString IEDName, QMap<QString, TiXmlElement*> &LNMap, QMap<QString, TiXmlElement*>&LNTypeMap, QMap<QString, TiXmlElement*>&DOTypeMap,
	QMap<QString, TiXmlElement*>&DATypeMap, QMap<QString, TiXmlElement*>&EnumMap)
{
	TiXmlElement *m_DataTemplate_EX = NULL;
	TiXmlElement *m_DataTemplate_IN = NULL;
	TiXmlNode *m_Node_EX;
	TiXmlElement  *m_Element_IN = NULL;
	QMap<QString, TiXmlElement*> Map_EX;
	QMap<QString, TiXmlElement*> Map_IN;

	QStringList keys;
	m_DataTemplate_EX = CIDDocument->FirstChildElement("SCL")->FirstChildElement("DataTypeTemplates");
	m_DataTemplate_IN = root->FirstChildElement("DataTypeTemplates");

	Init_LNtype_MAP(m_DataTemplate_IN, Map_IN);
	keys = LNTypeMap.keys();
	for (int i = 0; i < keys.size(); i++)
	{
		m_Element_IN = Map_IN.value(keys.at(i));
		m_DataTemplate_IN->RemoveChild(m_Element_IN);
	}
	Init_LNtype_MAP(m_DataTemplate_EX, Map_EX);
	for (int i = 0; i < Map_EX.size(); i++)
	{
		m_Node_EX = Map_EX.value(Map_EX.keys().at(i))->Clone();
		if (m_DataTemplate_IN->LastChild("LNodeType") != NULL)
		{
			m_DataTemplate_IN->InsertAfterChild(m_DataTemplate_IN->LastChild("LNodeType"), *m_Node_EX);
		}
		else
		{
			m_DataTemplate_IN->LinkEndChild(m_Node_EX);
		}

	}

	Init_DOType_MAP(m_DataTemplate_IN, Map_IN);
	keys = DOTypeMap.keys();
	for (int i = 0; i < keys.size(); i++)
	{
		m_Element_IN = Map_IN.value(keys.at(i));
		m_DataTemplate_IN->RemoveChild(m_Element_IN);
	}
	Init_DOType_MAP(m_DataTemplate_EX, Map_EX);
	for (int i = 0; i < Map_EX.size(); i++)
	{
		m_Node_EX = Map_EX.value(Map_EX.keys().at(i))->Clone();
		if (m_DataTemplate_IN->LastChild("DOType") != NULL)
		{
			m_DataTemplate_IN->InsertAfterChild(m_DataTemplate_IN->LastChild("DOType"), *m_Node_EX);

		}
		else
		{
			m_DataTemplate_IN->InsertAfterChild(m_DataTemplate_IN->LastChild("LNodeType"), *m_Node_EX);

		}
	}

	Init_DAtype_MAP(m_DataTemplate_IN, Map_IN);
	keys = DATypeMap.keys();
	for (int i = 0; i < keys.size(); i++)
	{
		m_Element_IN = Map_IN.value(keys.at(i));
		m_DataTemplate_IN->RemoveChild(m_Element_IN);
	}
	Init_DAtype_MAP(m_DataTemplate_EX, Map_EX);
	for (int i = 0; i < Map_EX.size(); i++)
	{
		m_Node_EX = Map_EX.value(Map_EX.keys().at(i))->Clone();
		if (m_DataTemplate_IN->LastChild("DAType") != NULL)
		{
			m_DataTemplate_IN->InsertAfterChild(m_DataTemplate_IN->LastChild("DAType"), *m_Node_EX);

		}
		else
		{
			m_DataTemplate_IN->InsertAfterChild(m_DataTemplate_IN->LastChild("DOType"), *m_Node_EX);

		}
	}
	Init_EnumType_MAP(m_DataTemplate_IN, Map_IN);
	keys = EnumMap.keys();
	for (int i = 0; i < keys.size(); i++)
	{
		m_Element_IN = Map_IN.value(keys.at(i));
		m_DataTemplate_IN->RemoveChild(m_Element_IN);
	}
	Init_EnumType_MAP(m_DataTemplate_EX, Map_EX);
	for (int i = 0; i < Map_EX.size(); i++)
	{
		m_Node_EX = Map_EX.value(Map_EX.keys().at(i))->Clone();
		if (m_DataTemplate_IN->LastChild("EnumType") != NULL)
		{
			m_DataTemplate_IN->InsertAfterChild(m_DataTemplate_IN->LastChild("EnumType"), *m_Node_EX);

		}
		else
		{
			m_DataTemplate_IN->InsertAfterChild(m_DataTemplate_IN->LastChild("DAType"), *m_Node_EX);

		}
	}
	return DO_OK;
}

void ScdTree::SetRememberEle()
{
	RememberElement = CurElement;
}

void ScdTree::switchRememberEle()
{
	CurElement = RememberElement;
	CurNode = RememberElement;
}
void ScdTree::SetRememberElelocal()
{
	RememberElementlocal = CurElement;
}

void ScdTree::switchRememberElelocal()
{
	CurElement = RememberElementlocal;
	CurNode = RememberElementlocal;
}
//void ScdTree::analyzeDO(QVector<Data_instStruct>&DataList, QString da_prefix, QString str_lntype)
//{

//	QString strdodesc;
//	QString strdaname;
//	QString strdainst;
//	QString strdoname;
//	QString strdU;
//	QString strDesc;
//	Data_instStruct m_dataInst;
//	QVector<Data_instStruct> instList;
//	TiXmlElement *m_element = CurElement;
//	strdodesc = m_element->Attribute("desc");
//	strdoname = m_element->Attribute("name");
//	TiXmlElement *child_element = NULL;
//	QString str;
//	const char *ne_str;
//	child_element = m_element->FirstChildElement();
//	if (child_element != NULL)
//	{
//		m_dataInst.B_Datalnst = da_prefix + "." + strdoname;
//		m_dataInst.B_DOdesc = strdodesc;
//		m_dataInst.B_dU = strdodesc;
//		instList.append(m_dataInst);
//		for (; child_element != NULL; child_element = child_element->NextSiblingElement())
//		{
//			if (0 == strcmp(child_element->Value(), "DAI"))
//			{
//				Data_instStruct dataInst;
//				dataInst.B_DOdesc = strdodesc;
//				dataInst.B_Datalnst = da_prefix + "." + strdoname + ".";
//				ne_str = child_element->Attribute("name");
//				str = ne_str;

//				dataInst.B_Datalnst += str;
//				dataInst.B_DA += str;
//				if (dataInst.B_DA == "dU")
//				{
//					TiXmlText *m_text = child_element->FirstChild()->FirstChild()->ToText();
//					ne_str = m_text->Value();
//					str = ne_str;

//					strdU += str;
//					continue;
//				}

//				if (child_element->Attribute("sAddr") != NULL)
//				{
//					ne_str = child_element->Attribute("sAddr");
//					str = QString(QLatin1String(ne_str));

//					dataInst.B_sAddr += str;
//				}
//				instList.append(dataInst);
//			}
//			if (0 == strcmp(child_element->Value(), "SDI"))
//			{
//				strdaname.clear();
//				strdainst.clear();
//				strDesc = child_element->Attribute("desc");
//				str = QString(QLatin1String(child_element->Attribute("name")));
//				strdaname = da_prefix + "." + strdoname + "." + str;
//				strdaname += ".";
//				strdainst += str;
//				strdainst += ".";
//				analyzeSDI(instList, strdaname, strdainst, child_element, strdodesc + strDesc);
//			}
//		}

//	}

//	for (int i = 0; i < instList.size(); i++)
//	{
//		instList[i].B_DOdesc = strdU + instList[i].B_DOdesc;
//		instList[i].B_dU = strdU + instList[i].B_dU;
//		if (instList[i].B_DA != NULL)
//		{
//			QString strFC;
//			strFC = GetFC_ByoneDAI(str_lntype, strdoname, instList[i].B_DA);
//			instList[i].B_FC = strFC;
//		}
//		else
//		{
//			continue;
//		}
//		DataList.append(instList[i]);
//	}
//	instList.clear();
//}
//void ScdTree::analyzeSDI(QVector<Data_instStruct> &_instList, QString strdanme, QString strdainst, TiXmlElement* proot, QString desc)
//{

//	QString  str;
//	TiXmlElement *m_element = proot;

//	TiXmlElement *child_element = NULL;
//	const char *ne_str;
//	QString str2, strdesc;
//	child_element = m_element->FirstChildElement();
//	for (; child_element != NULL; child_element = child_element->NextSiblingElement())
//	{
//		if (0 == strcmp(child_element->Value(), "DAI"))
//		{
//			Data_instStruct m_dataInst;

//			m_dataInst.B_DA += strdainst;
//			ne_str = child_element->Attribute("name");
//			str.clear();
//			str += ne_str;

//			m_dataInst.B_DA += str;
//			m_dataInst.B_dU = desc;
//			m_dataInst.B_Datalnst += strdanme;
//			m_dataInst.B_Datalnst += str;
//			if (child_element->Attribute("sAddr") != NULL)
//			{
//				//memset(str, 0, 32);
//				str.clear();
//				ne_str = child_element->Attribute("sAddr");
//				str += ne_str;

//				m_dataInst.B_sAddr += str;
//			}
//			_instList.append(m_dataInst);
//			return;
//		}
//		else if (0 == strcmp(child_element->Value(), "SDI"))
//		{
//			strdainst.remove(str2);
//			strdanme.remove(str2);
//			ne_str = child_element->Attribute("name");

//			strdesc = desc;
//			str.clear();
//			str2.clear();
//			str += ne_str;
//			str2 = str;
//			str2 += ".";

//			strdainst += str;
//			strdanme += str;
//			strdanme += ".";
//			strdainst += ".";
//			analyzeSDI(_instList, strdanme, strdainst, child_element, strdesc);
//		}
//	}
//	//        child_element = m_element->FirstChildElement("DAI");
//	//        for(child_element;child_element!=NULL;child_element=child_element->NextSiblingElement("DAI"))
//	//        {
//	//            Data_instStruct m_dataInst;

//	//			m_dataInst.B_DA += strdainst;
//	//            ne_str =child_element->Attribute("name");
//	//            str+=ne_str;
//	//            //str = QString(QLatin1String(ne_str));

//	//			//strcpy(str, child_element->Attribute("name"));
//	//			m_dataInst.B_DA += str;
//	//            m_dataInst.B_Datalnst += strdanme;
//	//			m_dataInst.B_Datalnst += str;
//	//            if(child_element->Attribute("sAddr")!=NULL)
//	//            {
//	//				//memset(str, 0, 32);
//	//                ne_str =child_element->Attribute("sAddr");
//	//                str+=ne_str;
//	//                //str = QString(QLatin1String(ne_str));
//	//                //str = QString(QLatin1String(child_element->Attribute("sAddr")));

//	//				//strcpy(str, child_element->Attribute("sAddr"));
//	//				m_dataInst.B_sAddr += str;
//	//            }
//	//            _instList.append(m_dataInst);
//	//        }
//	//        child_element = m_element->FirstChildElement("SDI");
//	//        for(child_element;child_element!=NULL;child_element=child_element->NextSiblingElement("SDI"))
//	//        {
//	//            ne_str =child_element->Attribute("name");
//	//            str+=ne_str;
//	//            //str = QString(QLatin1String(ne_str));
//	//            //str = QString(QLatin1String(child_element->Attribute("name")));

//	//            //strcpy(str, child_element->Attribute("name"));
//	//            //m_dataInst.B_Datalnst += strdanme+".";
//	//			strdainst += str;
//	//            strdanme+=str;
//	//			strdanme += ".";
//	//			strdainst += ".";
//	//            analyzeSDI(_instList, strdanme, strdainst, child_element);

//	//        }
//}
//QString ScdTree::GetFC_ByoneDAI(QString lntype, QString doname, QString daname)
//{
//	QString strtype;
//	const char* str;
//	if (daname.contains(".") == false)
//	{
//		TiXmlElement *child_element = DataTypeNode->GetChildByName_Value(DataTypeNode, "id", lntype.toStdString().data());
//		child_element = child_element->GetChildByName_Value(child_element, "name", doname.toStdString().data());
//		str = child_element->Attribute("type");
//		child_element = DataTypeNode->GetChildByName_Value(DataTypeNode, "id", str);
//		child_element = DataTypeNode->GetChildByName_Value(child_element, "name", daname.toStdString().data());
//		if (child_element == NULL)
//		{
//			return NULL;
//		}
//		str = child_element->Attribute("fc");
//		strtype += str;
//		return strtype;
//	}
//	else
//	{
//		int index;
//		QString daname_short;
//		index = daname.indexOf(".");
//		daname_short = daname.left(index);
//		TiXmlElement *child_element = DataTypeNode->GetChildByName_Value(DataTypeNode, "id", lntype.toStdString().data());
//		child_element = child_element->GetChildByName_Value(child_element, "name", doname.toStdString().data());

//		str = child_element->Attribute("type");
//		child_element = DataTypeNode->GetChildByName_Value(DataTypeNode, "id", str);
//		child_element = DataTypeNode->GetChildByName_Value(child_element, "name", daname_short.toStdString().data());

//		if (child_element == NULL)
//		{
//			return NULL;
//		}
//		str = child_element->Attribute("fc");
//		strtype += str;
//		return strtype;
//	}


//	return NULL;
//}
int ScdTree::AddOneDataToDataSet(QString datasetname, FCDA_Struct data)
{
	TiXmlElement *m_Element = NULL;
	TiXmlElement *m_dataElement = new TiXmlElement("FCDA");
	m_Element = CurElement->FirstChild("DataSet")->ToElement();
	for (; m_Element != NULL; m_Element = m_Element->NextSibling("DataSet")->ToElement())
	{
		if (0 == strcmp(m_Element->Attribute("name"), datasetname.toStdString().data()))
		{

			m_dataElement->SetAttribute("ldInst", data.B_ldInst.data());
			m_dataElement->SetAttribute("prefix", data.B_prefix.data());
			m_dataElement->SetAttribute("lnClass", data.B_lnClass.data());
			m_dataElement->SetAttribute("lnInst", data.B_lnInst.data());
			m_dataElement->SetAttribute("doName", data.B_doName.data());
			m_dataElement->SetAttribute("daName", data.B_daName.data());
			m_dataElement->SetAttribute("fc", data.B_fc.data());
			m_Element->LinkEndChild(m_dataElement);
			return DO_OK;
		}
	}
	return DO_FAIL;
}
int ScdTree::AddOneDatSet(QString IED, QString LD, QString LN, QString name, QString desc)
{
	QMap<QString, TiXmlElement*> Map_IED;
	Init_IED_MAP(root, Map_IED);
	TiXmlElement*IED_Node = Map_IED.value(IED);
	QMap<QString, TiXmlElement*> Map_LD;
	Init_LD_MAP(IED_Node, Map_LD);
	TiXmlElement*LD_Node = Map_LD.value(LD);
	QMap<QString, TiXmlElement*> Map_LN;
	Init_LN_MAP(LD_Node, Map_LN);
	TiXmlElement*LN_Node = Map_LN.value(LN);
	TiXmlElement *m_Element = NULL;
	for (m_Element = LN_Node->FirstChildElement("DataSet"); m_Element != NULL; m_Element = m_Element->NextSiblingElement("DataSet"))
	{
		if (0 == strcmp(m_Element->Attribute("name"), name.toStdString().data()))
		{
			QMessageBox::about(0, QObject::tr("Add dataset false"), QObject::tr("The dataset (%1) is exist").arg(name));
			return DO_FAIL;
		}
	}
	TiXmlElement *new_element = new TiXmlElement("DataSet");
	new_element->SetAttribute("name", name.toStdString().data());
	new_element->SetAttribute("desc", desc.toStdString().data());
	if (LN_Node->LastChild("DataSet") != NULL)
	{
		m_Element = LN_Node->LastChild("DataSet")->ToElement();
		LN_Node->InsertAfterChild(m_Element, *new_element);
		return DO_OK;
	}
	else
	{
		if (LN_Node->FirstChild() != NULL)
		{
			LN_Node->InsertAfterChild(LN_Node->FirstChild(), *new_element);
			return DO_OK;
		}
		else
		{
			LN_Node->LinkEndChild(new_element);
			return DO_OK;
		}
	}



	return DO_FAIL;
}
int ScdTree::UpdataOneDatSet(QString oldname, QString newname, QString desc)
{
	TiXmlElement *m_Element = CurElement->FirstChildElement("DataSet");
	for (; m_Element != NULL; m_Element = m_Element->NextSiblingElement())
	{
		if (0 == strcmp(m_Element->Attribute("name"), oldname.toStdString().data()))
		{
			m_Element->SetAttribute("name", newname.toStdString().data());
			m_Element->SetAttribute("desc", desc.toStdString().data());
			return DO_OK;
		}
	}
	return DO_FAIL;
}
int ScdTree::UpdataOneDatSet(QString IED, QString LD, QString LN, QString OldName, QString Name, QString desc)
{
	QMap<QString, TiXmlElement*> Map_IED;
	Init_IED_MAP(root, Map_IED);
	TiXmlElement*IED_Node = Map_IED.value(IED);
	QMap<QString, TiXmlElement*> Map_LD;
	Init_LD_MAP(IED_Node, Map_LD);
	TiXmlElement*LD_Node = Map_LD.value(LD);
	QMap<QString, TiXmlElement*> Map_LN;
	Init_LN_MAP(LD_Node, Map_LN);
	TiXmlElement*LN_Node = Map_LN.value(LN);
	TiXmlElement *Child = NULL;
	for (Child = LN_Node->FirstChildElement("DataSet"); Child != NULL; Child = Child->NextSiblingElement("DataSet"))
	{
		if (0 == strcmp(Name.toStdString().data(), Child->Attribute("name")))
		{
			if (OldName == Name)
			{
				Child->SetAttribute("desc", desc.toStdString().data());
				return DO_OK;
			}
			else
			{
				return DO_FAIL;

			}
		}
	}
	for (Child = LN_Node->FirstChildElement("DataSet"); Child != NULL; Child = Child->NextSiblingElement("DataSet"))
	{
		if (0 == strcmp(OldName.toStdString().data(), Child->Attribute("name")))
		{
			Child->SetAttribute("name", Name.toStdString().data());
			Child->SetAttribute("desc", desc.toStdString().data());
			return DO_OK;
		}
	}
	return DO_FAIL;
}

//int ScdTree::AddOneGSECtrl(QString path, QStringList list)
//{
//	const char* chr;
//	QString str, strappid;
//	QStringList datalist;
//	datalist.clear();
//	datalist = list;
//	TiXmlElement *m_elemnet = CurElement->FirstChildElement("GSEControl");
//	for (; m_elemnet != NULL; m_elemnet = m_elemnet->NextSiblingElement("GSEControl"))
//	{
//		chr = m_elemnet->Attribute("datSet");
//		str.clear();
//		str += chr;
//		if (datalist.contains(str))
//		{
//			int index = datalist.indexOf(str);
//			datalist.removeAt(index);
//		}
//	}
//	if (datalist.size() == 0)
//	{
//		QMessageBox::about(0, QObject::tr("Alarm"), QObject::tr("All of the dataset has control block"));

//		return DO_FAIL;
//	}
//	if (CurElement->LastChild("GSEControl") != NULL)
//	{
//		m_elemnet = CurElement->LastChild("GSEControl")->ToElement();
//		chr = m_elemnet->Attribute("name");
//		str.clear();
//		str += chr;
//		bool ok;
//		int num;
//		QRegExp user_reg_exp("[0-9]");
//		int index = str.indexOf(user_reg_exp, 0);
//		QString strl, strr;
//		strl = str.left(index);
//		strr = str.right(str.length() - index);
//		num = strr.toInt(&ok, 10);
//		num++;
//		str = strl + QString::number(num, 10);
//		strappid = path + "." + str;
//	}
//	else
//	{
//		str = "gocb0";
//		strappid = path + "." + str;
//		TiXmlElement *new_elemnet = new TiXmlElement("GSEControl");
//		new_elemnet->SetAttribute("name", str.toStdString().data());
//		new_elemnet->SetAttribute("datSet", datalist.at(0).toStdString().data());
//		new_elemnet->SetAttribute("confRev", "1");
//		new_elemnet->SetAttribute("type", "GOOSE");
//		std::string str1 = strappid.toStdString();

//		const char* ch = str1.c_str();
//		new_elemnet->SetAttribute("appID", ch);
//		new_elemnet->SetAttribute("desc", "");
//		CurElement->LinkEndChild(new_elemnet);
//		return DO_OK;
//	}
//	TiXmlElement *new_elemnet = new TiXmlElement("GSEControl");
//	new_elemnet->SetAttribute("name", str.toStdString().data());
//	new_elemnet->SetAttribute("datSet", datalist.at(0).toStdString().data());
//	new_elemnet->SetAttribute("confRev", "1");
//	new_elemnet->SetAttribute("type", "GOOSE");
//	std::string str1 = strappid.toStdString();

//	const char* ch = str1.c_str();
//	new_elemnet->SetAttribute("appID", ch);
//	new_elemnet->SetAttribute("desc", "");
//	CurElement->InsertAfterChild(m_elemnet, *new_elemnet);


//	return DO_OK;
//}
//int ScdTree::DelOneGSECtrl(QString name)
//{
//	TiXmlElement *m_elemnet = CurElement->FirstChildElement("GSEControl");
//	for (; m_elemnet != NULL; m_elemnet = m_elemnet->NextSiblingElement("GSEControl"))
//	{
//		if (0 == strcmp(m_elemnet->Attribute("name"), name.toStdString().data()))
//		{
//			CurElement->RemoveChild(m_elemnet);
//			return DO_OK;
//		}
//	}
//	return DO_FAIL;
//}
//int ScdTree::UpdataOneGSECtrl(QString name, GSE_InstStruct data)
//{
//	TiXmlElement *m_elemnet = CurElement->FirstChildElement("GSEControl");
//	for (; m_elemnet != NULL; m_elemnet = m_elemnet->NextSiblingElement("GSEControl"))
//	{
//		if (0 == strcmp(m_elemnet->Attribute("name"), name.toStdString().data()))
//		{
//			continue;
//		}
//		if (0 == strcmp(m_elemnet->Attribute("name"), data.B_name.toStdString().data()))
//		{
//			return DO_FAIL;
//		}
//		if (0 == strcmp(m_elemnet->Attribute("datSet"), data.B_datSet.toStdString().data()))
//		{
//			return DO_FAIL;
//		}
//	}
//	m_elemnet = CurElement->FirstChildElement("GSEControl");
//	for (; m_elemnet != NULL; m_elemnet = m_elemnet->NextSiblingElement("GSEControl"))
//	{
//		if (0 == strcmp(m_elemnet->Attribute("name"), name.toStdString().data()))
//		{
//			m_elemnet->SetAttribute("name", data.B_name.toStdString().data());
//			m_elemnet->SetAttribute("datSet", data.B_datSet.toStdString().data());
//			m_elemnet->SetAttribute("confRev", data.B_confRev.toStdString().data());
//			m_elemnet->SetAttribute("type", data.B_type.toStdString().data());
//			std::string str1 = data.B_appID.toStdString();

//			const char* ch = str1.c_str();
//			m_elemnet->SetAttribute("appID", ch);
//			std::string str2 = data.B_desc.toStdString();

//			const char* ch1 = str2.c_str();
//			m_elemnet->SetAttribute("desc", ch1);
//			return DO_OK;
//		}
//	}
//	return DO_OK;
//}
//int ScdTree::AddOneSMVCtrl(QString path, QStringList list, SMV_InstStruct& m_data)
//{
//	const char* chr;
//	QString str, strappid;
//	QStringList datalist;
//	datalist.clear();
//	datalist = list;
//	TiXmlElement *m_elemnet = CurElement->FirstChildElement("SampledValueControl");
//	for (; m_elemnet != NULL; m_elemnet = m_elemnet->NextSiblingElement("SampledValueControl"))
//	{
//		chr = m_elemnet->Attribute("datSet");
//		str.clear();
//		str += chr;
//		if (datalist.contains(str))
//		{
//			int index = datalist.indexOf(str);
//			datalist.removeAt(index);
//		}
//	}
//	if (datalist.size() == 0)
//	{
//		return DO_FAIL;
//	}
//	if (CurElement->LastChild("SampledValueControl") != NULL)
//	{
//		m_elemnet = CurElement->LastChild("SampledValueControl")->ToElement();
//		chr = m_elemnet->Attribute("name");
//		str.clear();
//		str += chr;
//		bool ok;
//		int num;
//		QRegExp user_reg_exp("[0-9]");
//		int index = str.indexOf(user_reg_exp, 0);
//		QString strl, strr;
//		strl = str.left(index);
//		strr = str.right(str.length() - index);
//		num = strr.toInt(&ok, 10);
//		//num = QString::number(strr,10);
//		num++;
//		str = strl + QString::number(num, 10);
//		strappid = path + "." + str;
//		TiXmlElement *new_elemnet = new TiXmlElement("SampledValueControl");
//		new_elemnet->SetAttribute("name", str.toStdString().data());
//		new_elemnet->SetAttribute("datSet", datalist.at(0).toStdString().data());
//		new_elemnet->SetAttribute("confRev", "1");
//		new_elemnet->SetAttribute("nofASDU", "1");
//		new_elemnet->SetAttribute("smpRate", "4000");
//		new_elemnet->SetAttribute("multicast", "true");
//		new_elemnet->SetAttribute("desc", "");
//		std::string str1 = strappid.toStdString();

//		const char* ch = str1.c_str();
//		new_elemnet->SetAttribute("smvID", ch);
//		CurElement->InsertAfterChild(m_elemnet, *new_elemnet);


//		return DO_OK;
//	}
//	else
//	{
//		str = "smvcb0";
//		strappid = path + "." + str;
//		TiXmlElement *new_elemnet = new TiXmlElement("SampledValueControl");
//		new_elemnet->SetAttribute("name", str.toStdString().data());
//		new_elemnet->SetAttribute("datSet", datalist.at(0).toStdString().data());
//		new_elemnet->SetAttribute("confRev", "1");
//		new_elemnet->SetAttribute("nofASDU", "1");
//		new_elemnet->SetAttribute("smpRate", "4000");
//		new_elemnet->SetAttribute("multicast", "true");
//		new_elemnet->SetAttribute("desc", "");
//		std::string str1 = strappid.toStdString();

//		const char* ch = str1.c_str();
//		new_elemnet->SetAttribute("smvID", ch);
//		CurElement->LinkEndChild(new_elemnet);
//		return DO_OK;
//	}

//	return DO_FAIL;
//}

//int ScdTree::DelOneSMVCtrl(QString name)
//{
//	TiXmlElement *m_elemnet = CurElement->FirstChildElement("SampledValueControl");
//	for (; m_elemnet != NULL; m_elemnet = m_elemnet->NextSiblingElement("SampledValueControl"))
//	{
//		if (0 == strcmp(m_elemnet->Attribute("name"), name.toStdString().data()))
//		{
//			CurElement->RemoveChild(m_elemnet);
//			return DO_OK;
//		}
//	}
//	return DO_FAIL;
//	return DO_FAIL;
//}

//int ScdTree::UpdataOneSMVCtrl(QString name, SMV_InstStruct data)
//{
//	TiXmlElement *m_elemnet = CurElement->FirstChildElement("SampledValueControl");
//	for (; m_elemnet != NULL; m_elemnet = m_elemnet->NextSiblingElement("SampledValueControl"))
//	{
//		if (0 == strcmp(m_elemnet->Attribute("name"), name.toStdString().data()))
//		{
//			break;
//		}
//		if (0 == strcmp(m_elemnet->Attribute("name"), data.B_name.toStdString().data()))
//		{
//			return DO_FAIL;
//		}
//		if (0 == strcmp(m_elemnet->Attribute("datSet"), data.B_datSet.toStdString().data()))
//		{
//			return DO_FAIL;
//		}
//	}
//	m_elemnet = CurElement->FirstChildElement("SampledValueControl");
//	for (; m_elemnet != NULL; m_elemnet = m_elemnet->NextSiblingElement("SampledValueControl"))
//	{
//		if (0 == strcmp(m_elemnet->Attribute("name"), name.toStdString().data()))
//		{
//			m_elemnet->SetAttribute("name", data.B_name.toStdString().data());
//			m_elemnet->SetAttribute("datSet", data.B_datSet.toStdString().data());
//			m_elemnet->SetAttribute("confRev", data.B_confRev.toStdString().data());
//			m_elemnet->SetAttribute("nofASDU", data.B_nofASDU.toStdString().data());
//			m_elemnet->SetAttribute("smpRate", data.B_smpRate.toStdString().data());
//			m_elemnet->SetAttribute("multicast", data.B_multicast.toStdString().data());
//			std::string str1 = data.B_desc.toStdString();

//			const char* ch1 = str1.c_str();
//			m_elemnet->SetAttribute("desc", ch1);
//			std::string str2 = data.B_smvID.toStdString();

//			const char* ch2 = str2.c_str();
//			m_elemnet->SetAttribute("smvID", ch2);
//			return DO_OK;
//		}
//	}
//	return DO_OK;
//}
//int ScdTree::UpdataOneRPTCtrl(QString name, RPT_CTRLStruct data)
//{
//	TiXmlElement *m_elemnet = CurElement->FirstChildElement("ReportControl");
//	for (; m_elemnet != NULL; m_elemnet = m_elemnet->NextSiblingElement("ReportControl"))
//	{
//		if (0 == strcmp(m_elemnet->Attribute("name"), name.toStdString().data()))
//		{
//			continue;
//		}
//		if (0 == strcmp(m_elemnet->Attribute("name"), data.B_name.toStdString().data()))
//		{
//			return DO_FAIL;
//		}
//		if (0 == strcmp(m_elemnet->Attribute("datSet"), data.B_datSet.toStdString().data()))
//		{
//			return DO_FAIL;
//		}
//	}
//	m_elemnet = CurElement->FirstChildElement("ReportControl");
//	for (; m_elemnet != NULL; m_elemnet = m_elemnet->NextSiblingElement("ReportControl"))
//	{
//		if (0 == strcmp(m_elemnet->Attribute("name"), name.toStdString().data()))
//		{
//			m_elemnet->SetAttribute("name", data.B_name.toStdString().data());
//			m_elemnet->SetAttribute("rptID", data.B_rptID.toStdString().data());
//			m_elemnet->SetAttribute("datSet", data.B_datSet.toStdString().data());
//			m_elemnet->SetAttribute("intgPd", data.B_intgPd.toStdString().data());
//			m_elemnet->SetAttribute("confRev", data.B_confRev.toStdString().data());
//			m_elemnet->SetAttribute("buffered", data.B_buffered.toStdString().data());
//			m_elemnet->SetAttribute("bufTime", data.B_buftime.toStdString().data());
//			m_elemnet->SetAttribute("desc", data.B_desc.toStdString().data());
//			m_elemnet = m_elemnet->FirstChildElement("TrgOps");
//			m_elemnet->SetAttribute("dchg", data.m_Trgops.B_dchg.toStdString().data());
//			m_elemnet->SetAttribute("dupd", data.m_Trgops.B_dupd.toStdString().data());
//			m_elemnet->SetAttribute("period", data.m_Trgops.B_period.toStdString().data());
//			m_elemnet->SetAttribute("qchg", data.m_Trgops.B_qchg.toStdString().data());
//			m_elemnet = m_elemnet->Parent()->ToElement();
//			m_elemnet = m_elemnet->FirstChildElement("OptFields");
//			m_elemnet->SetAttribute("seqNum", data.m_OptFields.B_seqNum.toStdString().data());
//			m_elemnet->SetAttribute("timeStamp", data.m_OptFields.B_timeStamp.toStdString().data());
//			m_elemnet->SetAttribute("dataSet", data.m_OptFields.B_dataSet.toStdString().data());
//			m_elemnet->SetAttribute("reasonCode", data.m_OptFields.B_reasonCode.toStdString().data());
//			m_elemnet->SetAttribute("dataRef", data.m_OptFields.B_dataRef.toStdString().data());
//			m_elemnet->SetAttribute("entryID", data.m_OptFields.B_entryID.toStdString().data());
//			m_elemnet->SetAttribute("configRef", data.m_OptFields.B_configRef.toStdString().data());
//			m_elemnet = m_elemnet->Parent()->ToElement();
//			m_elemnet = m_elemnet->FirstChildElement("RptEnabled");
//			m_elemnet->SetAttribute("max", data.m_RtpEnabled.B_max.toStdString().data());


//			return DO_OK;
//		}
//	}
//	return DO_OK;
//}
//int ScdTree::UpdataOneLOGCtrl(QString name, LOG_CTRLStruct data)
//{
//	TiXmlElement *m_elemnet = CurElement->FirstChildElement("LogControl");
//	for (; m_elemnet != NULL; m_elemnet = m_elemnet->NextSiblingElement("LogControl"))
//	{
//		if (0 == strcmp(m_elemnet->Attribute("name"), name.toStdString().data()))
//		{
//			continue;
//		}
//		if (0 == strcmp(m_elemnet->Attribute("name"), data.B_name.toStdString().data()))
//		{
//			return DO_FAIL;
//		}
//		if (0 == strcmp(m_elemnet->Attribute("datSet"), data.B_datSet.toStdString().data()))
//		{
//			return DO_FAIL;
//		}
//	}
//	m_elemnet = CurElement->FirstChildElement("LogControl");
//	for (; m_elemnet != NULL; m_elemnet = m_elemnet->NextSiblingElement("LogControl"))
//	{
//		if (0 == strcmp(m_elemnet->Attribute("name"), name.toStdString().data()))
//		{
//			m_elemnet->SetAttribute("name", data.B_name.toStdString().data());
//			m_elemnet->SetAttribute("desc", data.B_desc.toStdString().data());
//			m_elemnet->SetAttribute("datSet", data.B_datSet.toStdString().data());
//			m_elemnet->SetAttribute("intgPd", data.B_intgPd.toStdString().data());
//			m_elemnet->SetAttribute("logName", data.B_logName.toStdString().data());
//			m_elemnet->SetAttribute("logEna", data.B_logEna.toStdString().data());
//			m_elemnet->SetAttribute("reasonCode", data.B_reasonCode.toStdString().data());

//			m_elemnet = m_elemnet->FirstChildElement("TrgOps");
//			m_elemnet->SetAttribute("dchg", data.m_Trgops.B_dchg.toStdString().data());
//			m_elemnet->SetAttribute("dupd", data.m_Trgops.B_dupd.toStdString().data());
//			m_elemnet->SetAttribute("period", data.m_Trgops.B_period.toStdString().data());
//			m_elemnet->SetAttribute("qchg", data.m_Trgops.B_qchg.toStdString().data());
//			m_elemnet = m_elemnet->Parent()->ToElement();


//			return DO_OK;
//		}
//	}
//	return DO_OK;
//}
int ScdTree::UpdataOneINPUT(QString name, Input_Struct data, int state)
{
	TiXmlElement *m_elemnet = CurElement->FirstChildElement("ExtRef");
	for (; m_elemnet != NULL; m_elemnet = m_elemnet->NextSiblingElement("ExtRef"))
	{
		if (0 == strcmp(m_elemnet->Attribute("intAddr"), name.toStdString().data()))
		{
			std::string str = data.B_iedName.toStdString();
			if (state == LOCAL_DATA)
			{
				m_elemnet->SetAttribute("intAddr", data.B_intAddr.toStdString().data());
			}
			else if (state == EX_DATA)
			{
				const char* ch = str.c_str();
				m_elemnet->SetAttribute("iedName", ch);
				m_elemnet->SetAttribute("daName", data.B_daName.toStdString().data());
				m_elemnet->SetAttribute("doName", data.B_doName.toStdString().data());
				m_elemnet->SetAttribute("ldInst", data.B_ldInst.toStdString().data());
				m_elemnet->SetAttribute("lnClass", data.B_lnClass.toStdString().data());
				m_elemnet->SetAttribute("lnInst", data.B_lnInst.toStdString().data());
				m_elemnet->SetAttribute("prefix", data.B_prefix.toStdString().data());
			}
			return DO_OK;
		}

	}
	return DO_FAIL;
}
int ScdTree::UpdataOneINPUT(QString ied, QString ld, QString ln, QString name, Input_Struct data, int state)
{
	QMap<QString, TiXmlElement* > IEDMap;
	Init_IED_MAP(root, IEDMap);
	TiXmlElement* m_IED = NULL;
	m_IED = IEDMap.value(ied);
	QMap<QString, TiXmlElement* > LDMap;
	Init_LD_MAP(m_IED, LDMap);
	TiXmlElement* m_LD = NULL;
	m_LD = LDMap.value(ld);
	QMap<QString, TiXmlElement* > LNMap;
	Init_LN_MAP(m_LD, LNMap);
	TiXmlElement* m_LN = NULL;
	m_LN = LNMap.value(ln);
	TiXmlElement *m_element = m_LN->FirstChildElement("Inputs");
	TiXmlElement *ExRef = NULL;
	for (ExRef = m_element->FirstChildElement("ExtRef"); ExRef != NULL; ExRef = ExRef->NextSiblingElement("ExtRef"))
	{
		if (0 == strcmp(ExRef->Attribute("intAddr"), name.toStdString().data()))
		{

			if (state == LOCAL_DATA)
			{
				ExRef->SetAttribute("intAddr", data.B_intAddr.toStdString().data());
			}
			else if (state == EX_DATA)
			{
				std::string str = data.B_iedName.toStdString();
				const char* ch = str.c_str();
				ExRef->SetAttribute("iedName", ch);
				ExRef->SetAttribute("daName", data.B_daName.toStdString().data());
				ExRef->SetAttribute("doName", data.B_doName.toStdString().data());
				ExRef->SetAttribute("ldInst", data.B_ldInst.toStdString().data());
				ExRef->SetAttribute("lnClass", data.B_lnClass.toStdString().data());
				ExRef->SetAttribute("lnInst", data.B_lnInst.toStdString().data());
				ExRef->SetAttribute("prefix", data.B_prefix.toStdString().data());
			}
			return DO_OK;
		}

	}
	return DO_FAIL;
}
//int ScdTree::AddOneINPUT(Input_Struct data)
//{
//	TiXmlElement *m_element = CurElement;
//	if (0 == strcmpi(m_element->Value(), "Inputs"))
//	{
//		TiXmlElement *child_elemnet = new TiXmlElement("ExtRef");
//		std::string str = data.B_iedName.toStdString();

//		const char* ch = str.c_str();
//		child_elemnet->SetAttribute("iedName", ch);
//		child_elemnet->SetAttribute("daName", data.B_daName.toStdString().data());
//		child_elemnet->SetAttribute("doName", data.B_doName.toStdString().data());
//		child_elemnet->SetAttribute("ldInst", data.B_ldInst.toStdString().data());
//		child_elemnet->SetAttribute("lnClass", data.B_lnClass.toStdString().data());
//		child_elemnet->SetAttribute("lnInst", data.B_lnInst.toStdString().data());
//		child_elemnet->SetAttribute("prefix", data.B_prefix.toStdString().data());
//		child_elemnet->SetAttribute("intAddr", data.B_intAddr.toStdString().data());
//		CurElement->LinkEndChild(child_elemnet);
//		return DO_OK;
//	}
//	else if (0 == strcmp(m_element->Value(), "LN0"))
//	{
//		TiXmlElement *new_input = new TiXmlElement("Inputs");
//		TiXmlElement *child_elemnet = new TiXmlElement("ExtRef");
//		std::string str = data.B_iedName.toStdString();

//		const char* ch = str.c_str();
//		child_elemnet->SetAttribute("iedName", ch);
//		child_elemnet->SetAttribute("daName", data.B_daName.toStdString().data());
//		child_elemnet->SetAttribute("doName", data.B_doName.toStdString().data());
//		child_elemnet->SetAttribute("ldInst", data.B_ldInst.toStdString().data());
//		child_elemnet->SetAttribute("lnClass", data.B_lnClass.toStdString().data());
//		child_elemnet->SetAttribute("lnInst", data.B_lnInst.toStdString().data());
//		child_elemnet->SetAttribute("prefix", data.B_prefix.toStdString().data());
//		child_elemnet->SetAttribute("intAddr", data.B_intAddr.toStdString().data());
//		new_input->LinkEndChild(child_elemnet);
//		m_element->InsertEndChild(*new_input);
//		return DO_OK;
//	}
//	return DO_FAIL;
//}
int ScdTree::AddOneINPUT(QString ied, QString ap, QString ld, QString ln, Input_Struct data)
{
	QMap<QString, TiXmlElement* > IEDMap;
	Init_IED_MAP(root, IEDMap);
	TiXmlElement* m_IED = NULL;
	m_IED = IEDMap.value(ied);
	QMap<QString, TiXmlElement* > LDMap;
	Init_LD_MAP(m_IED, LDMap);
	TiXmlElement* m_LD = NULL;
	m_LD = LDMap.value(ld);
	QMap<QString, TiXmlElement* > LNMap;
	Init_LN_MAP(m_LD, LNMap);
	TiXmlElement* m_LN = NULL;
	m_LN = LNMap.value("LLN0");
	TiXmlElement *m_element = m_LN->FirstChildElement("Inputs");
	if (m_element == NULL)
	{
		TiXmlElement *new_input = new TiXmlElement("Inputs");
		m_LN->LinkEndChild(new_input);
		m_element = new_input;
	}
	TiXmlElement *child_elemnet = new TiXmlElement("ExtRef");
	std::string str = data.B_iedName.toStdString();

	const char* ch = str.c_str();
	child_elemnet->SetAttribute("iedName", ch);
	child_elemnet->SetAttribute("daName", data.B_daName.toStdString().data());
	child_elemnet->SetAttribute("doName", data.B_doName.toStdString().data());
	child_elemnet->SetAttribute("ldInst", data.B_ldInst.toStdString().data());
	child_elemnet->SetAttribute("lnClass", data.B_lnClass.toStdString().data());
	child_elemnet->SetAttribute("lnInst", data.B_lnInst.toStdString().data());
	child_elemnet->SetAttribute("prefix", data.B_prefix.toStdString().data());
	child_elemnet->SetAttribute("intAddr", data.B_intAddr.toStdString().data());
	m_element->LinkEndChild(child_elemnet);
	return DO_OK;
}
//int ScdTree::DelOneINPUT(Input_Struct data)
//{
//	TiXmlElement *m_elemnet = CurElement->FirstChildElement("ExtRef");
//	for (; m_elemnet != NULL; m_elemnet = m_elemnet->NextSiblingElement("ExtRef"))
//	{
//		if (0 == strcmp(m_elemnet->Attribute("intAddr"), data.B_intAddr.toStdString().data()))
//		{
//			CurElement->RemoveChild(m_elemnet);
//			return DO_OK;
//		}

//	}
//	return DO_FAIL;
//}
int ScdTree::DelOneINPUT(QString ied, QString ld, QString ln, QString intAddr)
{
	QMap<QString, TiXmlElement*>IED_Map;
	QMap<QString, TiXmlElement*>LD_Map;
	QMap<QString, TiXmlElement*>LN_Map;
	Init_IED_MAP(root, IED_Map);
	TiXmlElement* m_IED = NULL;
	m_IED = IED_Map.value(ied);

	Init_LD_MAP(m_IED, LD_Map);
	TiXmlElement* m_LD = NULL;
	m_LD = LD_Map.value(ld);
	TiXmlElement* m_LN = NULL;
	Init_LN_MAP(m_LD, LN_Map);
	m_LN = LN_Map.value("LLN0");
	TiXmlElement *m_inputs = NULL;
	TiXmlElement *child = NULL;
	m_inputs = m_LN->FirstChildElement("Inputs");
	for (child = m_inputs->FirstChildElement(); child != NULL; child = child->NextSiblingElement())
	{
		if (0 == strcmp(child->Attribute("intAddr"), intAddr.toLocal8Bit().data()))
		{
			m_inputs->RemoveChild(child);
			return DO_OK;
		}
	}
	return DO_FAIL;
}
int ScdTree::CreatInputs()
{
	TiXmlElement *m_elemnet = CurElement;
	TiXmlElement *m_inputs = new TiXmlElement("Inputs");
	m_elemnet->LinkEndChild(m_inputs);
	return DO_OK;
}

QString ScdTree::GetSpecifytvalue(QString iedname, QString path, QString value)
{
	int recode;
	SetRememberElelocal();
	SwitchRoot();
	recode = GetChildByname_value("IED", "name", iedname);
	if (recode == DO_FAIL)
	{
		switchRememberElelocal();
		return "invalid";
	}
	int index;
	QString str;
	QString strln;
	QString strLD;
	QString strLninst;
	QString strdo;
	QString strdesc;
	str = path;
	index = str.indexOf("/");
	strLD = str.left(index);
	str = str.right(str.length() - index);
	str.remove(0, 1);
	index = str.indexOf(".");
	strLninst = str.left(index);

	recode = GetLDnode(strLD);
	if (recode == DO_FAIL)
	{
		switchRememberElelocal();
		return "invalid";
	}
	recode = GetChild();
	if (recode == DO_FAIL)
	{
		switchRememberElelocal();
		return "invalid";
	}
	strln.clear();
	strln = GetAttribute("prefix") + GetAttribute("lnClass") + GetAttribute("lnInst");
	if (strln != strLninst)
	{
		while (GetNextChild("LN") == DO_OK)
		{
			strln.clear();
			strln = GetAttribute("prefix") + GetAttribute("lnClass") + GetAttribute("inst");
			if (strln != strLninst)
			{
				continue;
			}
			else

			{
				break;
			}
		}
	}
	str = str.right(str.length() - index);
	str.remove(0, 1);
	index = str.indexOf(".");
	strdo = str.left(index);
	recode = GetChildByname_value("DOI", "name", strdo);
	if (0 == strcmp(value.toStdString().data(), "desc"))
	{
		if (recode == DO_FAIL)
		{
			switchRememberElelocal();
			return "invalid";
		}

		strdesc = GetDOIValue("DAI", "dU", "Val");
		if (strdesc != NULL)
		{
			switchRememberElelocal();
			return strdesc;
		}
		switchRememberElelocal();
		return "invalid";
	}
	return "invalid";
}
QString ScdTree::GetDescFromSpecifNode(QString iedname, QString LDName, QString LNName, QString DOName)
{
	const char* chr;
	QString str;
	QStringList SDINameList;
	QMap<QString, TiXmlElement*>IED_Map;
	QMap<QString, TiXmlElement*>LD_Map;
	QMap<QString, TiXmlElement*>LN_Map;
	QMap<QString, TiXmlElement*>DO_Map;
	QMap<QString, TiXmlElement*>SDI_Map;
	Init_IED_MAP(root, IED_Map);
	TiXmlElement* m_IED = NULL;
	m_IED = IED_Map.value(iedname);
	if (m_IED == NULL)
	{
		return "invalid";
	}
	Init_LD_MAP(m_IED, LD_Map);
	TiXmlElement* m_LD = NULL;
	m_LD = LD_Map.value(LDName);
	if (m_LD == NULL)
	{
		return "invalid";
	}
	Init_LN_MAP(m_LD, LN_Map);
	TiXmlElement* m_LN;
	m_LN = LN_Map.value(LNName);
	if (m_LN == NULL)
	{
		return "invalid";
	}
	SDINameList = DOName.split(".");
	Init_DO_MAP(m_LN, DO_Map);
	TiXmlElement* m_DO = NULL;
	m_DO = DO_Map.value(SDINameList.at(0));
	if (m_DO == NULL)
	{
		return "invalid";
	}
	chr = m_DO->Attribute("desc");
	str += chr;
	SDINameList.removeAt(0);
	TiXmlElement* m_SDI = NULL;

	if (SDINameList.size() != 0)
	{
		Init_SDI_MAP(m_DO, SDI_Map);
		m_SDI = SDI_Map.value(SDINameList.at(0));
		if (m_SDI == NULL)
		{
			return "invalid";
		}
		chr = m_SDI->Attribute("desc");
		str += chr;
		SDINameList.removeAt(0);

		while (SDINameList.size() > 0)
		{
			SDI_Map.clear();
			Init_SDI_MAP(m_SDI, SDI_Map);
			if (m_SDI == NULL)
			{
				return "invalid";
			}
			m_SDI = SDI_Map.value(SDINameList.at(0));
			chr = m_SDI->Attribute("desc");
			if (chr == NULL)
				break;
			str += chr;
			SDINameList.removeAt(0);
		}
	}
	return str;
}

//QString ScdTree::GetCurIEDName()
//{
//	const char* chr;
//	QString str;
//	if (IEDNode == NULL)
//	{
//		return NULL;
//	}
//	chr = IEDNode->Attribute("name");
//	str.clear();
//	str += chr;
//	return str;
//}
//int ScdTree::GetSubNet(QString NetName)
//{
//	std::string str = NetName.toStdString();

//	const char* ch = str.c_str();
//	if (0 != strcmp(CurElement->Value(), "Communication"))
//	{
//		CurElement = root;
//	}
//	TiXmlElement *m_elemnet = CurElement->FirstChildElement("Communication");
//	m_elemnet = m_elemnet->FirstChildElement("SubNetwork");
//	for (; m_elemnet != NULL; m_elemnet = m_elemnet->NextSiblingElement("SubNetwork"))
//	{
//		if (0 == strcmp(m_elemnet->Attribute("name"), ch))
//		{
//			CurElement = m_elemnet;
//			CurNode = m_elemnet;
//			return DO_OK;
//		}
//	}
//	return DO_FAIL;
//}
int ScdTree::File_Integrity_Check(QString StrName, int state)
{
	const char* ch;
	QString error;
	TiXmlDocument* mdoc = new TiXmlDocument();
	mdoc->LoadFile(StrName.toLocal8Bit().data());
	int row = 0, column = 0;
	ch = mdoc->ErrorDesc();
	error += ch;
	row = mdoc->ErrorRow();
	column = mdoc->ErrorCol();
	if (error != NULL)
	{
		QMessageBox::information(NULL, QString("title"), QString("parse file failed at line row  ") + QString::number(row, 10) + QString(" and column ") + QString::number(column, 10) + QObject::tr("\n") + error);
		return DO_FAIL;
	}
	TiXmlElement* SCLElem = mdoc->FirstChildElement("SCL");
	if (SCLElem == NULL)
	{
		QMessageBox::information(NULL, QString("title"), QString("The File do not have the RootNode named SCL"));
		return DO_FAIL;
	}
	TiXmlElement* HeaderElem = SCLElem->FirstChildElement("Header");
	if (HeaderElem == NULL)
	{
		QMessageBox::information(NULL, QString("title"), QString("The File do not have the Node named Header"));
		return DO_FAIL;
	}
	TiXmlElement* IEDElem = SCLElem->FirstChildElement("IED");
	if (IEDElem == NULL)
	{
		QMessageBox::information(NULL, QString("title"), QString("The File do not have the Node named IED"));
		return DO_FAIL;
	}
	TiXmlElement* DataTypeTemplatesElem = SCLElem->FirstChildElement("DataTypeTemplates");
	if (DataTypeTemplatesElem == NULL)
	{
		QMessageBox::information(NULL, QString("title"), QString("The File do not have the Node named DataTypeTemplates"));
		return DO_FAIL;

	}
	QMessageBox::information(NULL, QString("title"), QString("The Integrity check of the file succeed"));
	return DO_FAIL;
	//QString error;
	//int row = 0, column = 0;
	//QFile file(StrName);
	//if (!file.open(QIODevice::ReadOnly))
	//	return DO_FAIL;
	//   if(!QDocumnet.setContent(&file, false, &error, &row, &column))
	//   {
	//       QMessageBox::information(NULL, QString("title"), QString("parse file failed at line row and column") + QString::number(row, 10) + QString(",") + QString::number(column, 10));
	//	file.close();
	//	return DO_FAIL;
	//   }
	//file.close();


	//QDomElement docElem = QDocumnet.documentElement();
	//QString str = docElem.tagName();
	//if (str != QObject::tr("SCL"))
	//{
	//	QMessageBox::information(NULL, QString("title"), QString("The File do not have the RootNode named SCL") );
	//	return DO_FAIL;
	//}
	//   QDomElement m_node = docElem.firstChildElement("Header");
	//m_node = docElem.firstChildElement("Substation");
	//if (m_node.)
	//{
	//	QMessageBox::information(NULL, QString("title"), QString("The File do not have the Node named Header"));
	//	return DO_FAIL;
	//}
	////if (str != QObject::tr("Header"))
	////{
	////	QMessageBox::information(NULL, QString("title"), QString("The File do not have the Node named Header"));
	////	return DO_FAIL;
	////}
	// m_node = docElem.firstChildElement("Substation");
	// if (m_node==NULL)
	// {
	//	 QMessageBox::information(NULL, QString("title"), QString("The File do not have the Node named Substation"));
	//	 return DO_FAIL;
	// }
	////str = m_node.tagName();
	////if (str != QObject::tr("Substation"))
	////{
	////	QMessageBox::information(NULL, QString("title"), QString("The File do not have the Node named Substation"));
	////	return DO_FAIL;
	////}
	//m_node = docElem.firstChildElement("Communication");
	//if (m_node == NULL)
	//{
	//	QMessageBox::information(NULL, QString("title"), QString("The File do not have the Node named Communication"));
	//	return DO_FAIL;
	//}
	////str = m_node.tagName();
	////if (str != QObject::tr("Communication"))
	////{
	////	QMessageBox::information(NULL, QString("title"), QString("The File do not have the Node named Communication"));
	////	return DO_FAIL;
	////}
	//m_node = docElem.firstChildElement("IED");
	//if (m_node == NULL)
	//{
	//	QMessageBox::information(NULL, QString("title"), QString("The File do not have the Node named IED"));
	//	return DO_FAIL;
	//}
	////str = m_node.tagName();
	////if (str != QObject::tr("IED"))
	////{
	////	QMessageBox::information(NULL, QString("title"), QString("The File do not have the Node named IED"));
	////	return DO_FAIL;
	////}
	//m_node = docElem.firstChildElement("DataTypeTemplates");
	//if (m_node == NULL)
	//{
	//	QMessageBox::information(NULL, QString("title"), QString("The File do not have the Node named DataTypeTemplates"));
	//	return DO_FAIL;
	//}
	////str = m_node.tagName();
	////if (str != QObject::tr("DataTypeTemplates"))
	////{
	////	QMessageBox::information(NULL, QString("title"), QString("The File do not have the Node named DataTypeTemplates"));
	////	return DO_FAIL;
	////}
	//if (state==0)
	//{
	//	QMessageBox::information(NULL, QString("title"), QString("The File Integrity check success"));
	//}
	//

	// return DO_OK;
}
int ScdTree::Comunication_Check(QStringList &list)
{
	QString error;
	QString str;
	QVector<ConnectedAP> RepeatIP;
	QVector<ConnectedAP> WrongIP;
	QVector<ConnectedAP> RepeatGSE;
	QVector<ConnectedAP> WrongGSE;
	QVector<ConnectedAP> RepeatSMV;
	QVector<ConnectedAP> WrongSMV;
	QVector<ConnectedAP> RepeatSMV_APPID;
	QVector<ConnectedAP> RepeatGSE_APPID;
	QVector<ConnectedAP> IPList;
	QVector<ConnectedAP> GSEList;
	QVector<ConnectedAP> SMVList;
	list.clear();
	RepeatIP.clear();
	RepeatGSE.clear();
	RepeatSMV.clear();
	RepeatSMV_APPID.clear();

	RepeatGSE_APPID.clear();
	IPList.clear();
	GSEList.clear();
	SMVList.clear();
	QString name;
	NetworkNode = root->FirstChild("Communication");
	if (NetworkNode == NULL)
	{

		return DO_FAIL;
	}
	TiXmlElement *m_Subnet = NetworkNode->FirstChildElement("SubNetwork");
	for (; m_Subnet != NULL; m_Subnet = m_Subnet->NextSiblingElement("SubNetwork"))
	{
		QString type;
		type = m_Subnet->Attribute("type");
		name = m_Subnet->Attribute("name");
		if (type.contains("MMS", Qt::CaseInsensitive))
		{
			GetConnectAPList_MMS(m_Subnet, IPList);
			for (int i = 0; i < IPList.size(); i++)
			{

				if (IPList[i].iP_addr.s_IP.isEmpty())
				{
					error.clear();
					error = QObject::tr("Error the IP Address of  iedName =%1 apName = %2 was Empty")
						.arg(RepeatIP[i].iedName).arg(RepeatIP[i].apName);
					list.append(error);
					
				}
				else
				{
					bool wrongstate = false;
					if (IPList[i].iP_addr.s_IP.count(".") != 3)
					{
						wrongstate = true;

					}

					QStringList listNum = IPList[i].iP_addr.s_IP.split(".", QString::SkipEmptyParts);
					int bCount = listNum.count();

					if (bCount != 4)
					{
						wrongstate = true;
					}

					for (int m = 0; m < bCount; m++)
					{
						bool bret;
						int iNum;
						iNum = listNum[m].toInt(&bret);
						if ((m == 0) || (m == 3))
						{
							if (iNum == 0)
								wrongstate = true;
						}
						if (!bret)
						{
							wrongstate = true;
						}

						if ((iNum >= 255))
						{
							wrongstate = true;
						}
					}
					if (wrongstate == true)
					{
						error.clear();
						error = QObject::tr("Error the IP Address %3 of  iedName =%1 apName = %2 was Wrong")
							.arg(IPList[i].iedName).arg(IPList[i].apName).arg(IPList[i].iP_addr.s_IP);
						list.append(error);
					}
				}

				if (!IPList[i].Goose_addr.isEmpty())
				{
					if (IPList[i].Goose_addr.s_MAC_addr.isEmpty())
					{
						error.clear();
						error = QObject::tr("Error the MAC Address of  iedName =%1 apName = %2 was Empty")
							.arg(IPList[i].iedName).arg(IPList[i].apName);
						list.append(error);

					}
					else
					{
						bool wrongstate = false;
						if (IPList[i].Goose_addr.s_MAC_addr.count("-") != 5)
						{
							wrongstate = true;

						}

						QStringList listMac = IPList[i].Goose_addr.s_MAC_addr.split("-", QString::SkipEmptyParts);
						int bCount = listMac.count();

						if (bCount != 6)
						{
							wrongstate = true;
						}

						for (int m = 0; m < bCount; m++)
						{
							bool bret;
							int iNum;
							iNum = listMac[m].toInt(&bret, 16);

							if (!bret)
							{
								wrongstate = true;
							}

							if ((iNum > 0xFF))
							{
								wrongstate = true;
							}
						}
						if (wrongstate == true)
						{
							error.clear();
							error = QObject::tr("Error the Mac Address %3 of  iedName =%1 apName = %2 was Wrong")
								.arg(IPList[i].iedName).arg(IPList[i].apName).arg(IPList[i].Goose_addr.s_MAC_addr);
							list.append(error);
						}
					}
					bool Ok;

					int VLANNum = IPList[i].Goose_addr.s_VLAN_ID.toUInt(&Ok, 16);
					if ((VLANNum<0x000) || (VLANNum>0xFFF))
					{
						error.clear();
						error = QObject::tr("Error the VLAN_ID %3 of  iedName =%1 apName = %2 must between 0x000 to 0xFFF")
							.arg(IPList[i].iedName).arg(IPList[i].apName).arg(IPList[i].Goose_addr.s_VLAN_ID);
						list.append(error);
					}
					int AppidNum = IPList[i].Goose_addr.s_APPID.toUInt(&Ok, 16);
					if ((AppidNum<0x000) || (AppidNum>0x3FFF))
					{
						error.clear();
						error = QObject::tr("Error the APPID %3 of  iedName =%1 apName = %2 GSE APPID must between 0x0000 to 0x3FFF")
							.arg(IPList[i].iedName).arg(IPList[i].apName).arg(IPList[i].Goose_addr.s_APPID);
						list.append(error);
					}
					if (IPList[i].Goose_addr.s_MaxTime.isEmpty())
					{
						error.clear();
						error = QObject::tr("Error the MaxTime of  iedName =%1 apName = %2 is Empty")
							.arg(IPList[i].iedName).arg(IPList[i].apName);
						list.append(error);
					}
					if (IPList[i].Goose_addr.s_MinTime.isEmpty())
					{
						error.clear();
						error = QObject::tr("Error the MinTime of  iedName =%1 apName = %2 is Empty")
							.arg(IPList[i].iedName).arg(IPList[i].apName);
						list.append(error);
					}
				}

				for (int j = 0; j < IPList.size(); j++)
				{
					if (i == j)
					{
						continue;
					}

					if ((IPList[i].Goose_addr.s_MAC_addr == IPList[j].Goose_addr.s_MAC_addr) || (IPList[i].Goose_addr.s_APPID == IPList[j].Goose_addr.s_APPID))
					{
						if ((IPList[i].Goose_addr.s_MAC_addr == IPList[j].Goose_addr.s_MAC_addr) && (!IPList[i].Goose_addr.isEmpty()))
						{

							if (!RepeatGSE.contains(IPList[i]))
							{
								RepeatGSE.append(IPList[i]);
							}

						}
						if ((IPList[i].Goose_addr.s_APPID == IPList[j].Goose_addr.s_APPID) && (!IPList[i].Goose_addr.isEmpty()))
						{
							if (!RepeatGSE_APPID.contains(IPList[i]))
							{
								RepeatGSE_APPID.append(IPList[i]);
							}
						}
					}

					if (IPList[i].iP_addr.s_IP == IPList[j].iP_addr.s_IP)

					{
						if (!RepeatIP.contains(IPList[i]))
						{
							RepeatIP.append(IPList[i]);
						}


					}

				}
			}
			for (int m = 0; m < RepeatIP.size(); m++)
			{
				error.clear();
				error = QObject::tr("Error the IP Address %3 of  iedName =%1 apName = %2 was repeated")
					.arg(RepeatIP[m].iedName).arg(RepeatIP[m].apName)
					.arg(RepeatIP[m].iP_addr.s_IP);
				list.append(error);
			}
			for (int m = 0; m < RepeatGSE.size(); m++)
			{
				error.clear();
				error = QObject::tr("Error  In the SubNetWork =%1 the GOOSE MAC Address %6 of iedName =%2 apName = %3  cbName = %4  ldInst = %5  was repeated")
					.arg(name).arg(RepeatGSE[m].iedName).arg(RepeatGSE[m].apName).arg(RepeatGSE[m].Goose_addr.s_cbName)
					.arg(RepeatGSE[m].Goose_addr.s_ldInst).arg(RepeatGSE[m].Goose_addr.s_MAC_addr);
				list.append(error);
			}
			for (int m = 0; m < RepeatGSE_APPID.size(); m++)
			{
				error.clear();
				error = QObject::tr("Error  In the SubNetWork =%1 the GOOSE APPID %6 of iedName =%2 apName = %3  cbName = %4  ldInst = %5  was repeated")
					.arg(name).arg(RepeatGSE_APPID[m].iedName).arg(RepeatGSE_APPID[m].apName).arg(RepeatGSE_APPID[m].Goose_addr.s_cbName)
					.arg(RepeatGSE_APPID[m].Goose_addr.s_ldInst).arg(RepeatGSE_APPID[m].Goose_addr.s_APPID);
				list.append(error);
			}
			continue;
		}
		if (type.contains("GOOSE", Qt::CaseInsensitive))
		{
			GetConnectAPList_GOOSE(m_Subnet, GSEList);
			RepeatGSE.clear();
			RepeatGSE_APPID.clear();
			for (int i = 0; i < GSEList.size(); i++)
			{
				if (!GSEList[i].Goose_addr.isEmpty())
				{
					if (GSEList[i].Goose_addr.s_MAC_addr.isEmpty())
					{
						error.clear();
						error = QObject::tr("Error the MAC Address of  iedName =%1 apName = %2 was Empty")
							.arg(GSEList[i].iedName).arg(GSEList[i].apName);
						list.append(error);

					}
					else
					{
						bool wrongstate = false;
						if (GSEList[i].Goose_addr.s_MAC_addr.count("-") != 5)
						{
							wrongstate = true;

						}

						QStringList listMac = GSEList[i].Goose_addr.s_MAC_addr.split("-", QString::SkipEmptyParts);
						qint8 bCount = listMac.count();

						if (bCount != 6)
						{
							wrongstate = true;
						}

						for (int m = 0; m < bCount; m++)
						{
							bool bret;
							quint8 iNum;
							iNum = listMac[m].toInt(&bret, 16);

							if (!bret)
							{
								wrongstate = true;
							}

							if ((iNum > 0xFF))
							{
								wrongstate = true;
							}
						}
						if (wrongstate == true)
						{
							error.clear();
							error = QObject::tr("Error the Mac Address %3 of  iedName =%1 apName = %2 was Wrong")
								.arg(GSEList[i].iedName).arg(GSEList[i].apName).arg(GSEList[i].Goose_addr.s_MAC_addr);
							list.append(error);
						}
					}
					bool Ok;

					int VLANNum = GSEList[i].Goose_addr.s_VLAN_ID.toUInt(&Ok, 16);
					if ((VLANNum<0x000) || (VLANNum>0xFFF))
					{
						error.clear();
						error = QObject::tr("Error the VLAN_ID %3 of  iedName =%1 apName = %2 must between 0x000 to 0xFFF")
							.arg(GSEList[i].iedName).arg(GSEList[i].apName).arg(GSEList[i].Goose_addr.s_VLAN_ID);
						list.append(error);
					}
					int AppidNum = GSEList[i].Goose_addr.s_APPID.toUInt(&Ok, 16);
					if ((AppidNum<0x000) || (AppidNum>0x3FFF))
					{
						error.clear();
						error = QObject::tr("Error the APPID %3 of  iedName =%1 apName = %2 GSE APPID must between 0x0000 to 0x3FFF")
							.arg(GSEList[i].iedName).arg(GSEList[i].apName).arg(GSEList[i].Goose_addr.s_APPID);
						list.append(error);
					}
					if (GSEList[i].Goose_addr.s_MaxTime.isEmpty())
					{
						error.clear();
						error = QObject::tr("Error the MaxTime of  iedName =%1 apName = %2 is Empty")
							.arg(GSEList[i].iedName).arg(GSEList[i].apName);
						list.append(error);
					}
					if (GSEList[i].Goose_addr.s_MinTime.isEmpty())
					{
						error.clear();
						error = QObject::tr("Error the MinTime of  iedName =%1 apName = %2 is Empty")
							.arg(GSEList[i].iedName).arg(GSEList[i].apName);
						list.append(error);
					}
				}

				for (int j = 0; j < GSEList.size(); j++)
				{
					bool ok;
					if (i == j)
					{
						continue;
					}
					if ((GSEList[i].Goose_addr.s_MAC_addr == GSEList[j].Goose_addr.s_MAC_addr) || (GSEList[i].Goose_addr.s_APPID == GSEList[j].Goose_addr.s_APPID))
					{
						if (GSEList[i].Goose_addr.s_MAC_addr == GSEList[j].Goose_addr.s_MAC_addr)
						{
							RepeatGSE.append(GSEList[i]);
						}
						if (GSEList[i].Goose_addr.s_APPID.toUInt(&ok, 16) == GSEList[j].Goose_addr.s_APPID.toUInt(&ok, 16))
						{
							RepeatGSE_APPID.append(GSEList[i]);
						}
						break;
					}
				}
			}
			for (int m = 0; m < RepeatGSE.size(); m++)
			{
				error.clear();
				error = QObject::tr("Error  In the SubNetWork =%1 the GOOSE MAC Address %6 of iedName =%2 apName = %3  cbName = %4  ldInst = %5  was repeated")
					.arg(name).arg(RepeatGSE[m].iedName).arg(RepeatGSE[m].apName).arg(RepeatGSE[m].Goose_addr.s_cbName)
					.arg(RepeatGSE[m].Goose_addr.s_ldInst).arg(RepeatGSE[m].Goose_addr.s_MAC_addr);
				list.append(error);
			}
			for (int m = 0; m < RepeatGSE_APPID.size(); m++)
			{
				error.clear();
				error = QObject::tr("Error  In the SubNetWork =%1 the GOOSE APPID %6 of iedName =%2 apName = %3  cbName = %4  ldInst = %5  was repeated")
					.arg(name).arg(RepeatGSE_APPID[m].iedName).arg(RepeatGSE_APPID[m].apName).arg(RepeatGSE_APPID[m].Goose_addr.s_cbName)
					.arg(RepeatGSE_APPID[m].Goose_addr.s_ldInst).arg(RepeatGSE_APPID[m].Goose_addr.s_APPID);
				list.append(error);
			}
			continue;
		}
		if (type.contains("SMV", Qt::CaseInsensitive))
		{
			GetConnectAPList_SMV(m_Subnet, SMVList);
			for (int i = 0; i < SMVList.size(); i++)
			{
				if (!SMVList[i].SMV_addr.isEmpty())
				{
					if (SMVList[i].SMV_addr.s_MAC_addr.isEmpty())
					{
						error.clear();
						error = QObject::tr("Error the MAC Address of  iedName =%1 apName = %2 was Empty")
							.arg(SMVList[i].iedName).arg(SMVList[i].apName);
						list.append(error);

					}
					else
					{
						bool wrongstate = false;
						if (GSEList[i].SMV_addr.s_MAC_addr.count("-") != 5)
						{
							wrongstate = true;

						}

						QStringList listMac = GSEList[i].SMV_addr.s_MAC_addr.split("-", QString::SkipEmptyParts);
						qint8 bCount = listMac.count();

						if (bCount != 6)
						{
							wrongstate = true;
						}

						for (int m = 0; m < bCount; m++)
						{
							bool bret;
							quint8 iNum;
							iNum = listMac[m].toInt(&bret, 16);

							if (!bret)
							{
								wrongstate = true;
							}

							if ((iNum >= 0xFF))
							{
								wrongstate = true;
							}
						}
						if (wrongstate == true)
						{
							error.clear();
							error = QObject::tr("Error the Mac Address %3 of  iedName =%1 apName = %2 was Wrong")
								.arg(SMVList[i].iedName).arg(SMVList[i].apName).arg(SMVList[i].SMV_addr.s_MAC_addr);
							list.append(error);
						}
					}
					bool Ok;

					int VLANNum = SMVList[i].SMV_addr.s_VLAN_ID.toUInt(&Ok, 16);
					if ((VLANNum<0x000) || (VLANNum>0xFFF))
					{
						error.clear();
						error = QObject::tr("Error the VLAN_ID %3 of  iedName =%1 apName = %2 must between 0x000 to 0xFFF")
							.arg(SMVList[i].iedName).arg(SMVList[i].apName).arg(SMVList[i].SMV_addr.s_VLAN_ID);
						list.append(error);
					}
					int AppidNum = SMVList[i].SMV_addr.s_APPID.toUInt(&Ok, 16);
					if ((AppidNum<0x4000) || (AppidNum>0x7FFF))
					{
						error.clear();
						error = QObject::tr("Error the APPID %3 of  iedName =%1 apName = %2 SMV APPID must between 0x4000 to 0x7FFF")
							.arg(SMVList[i].iedName).arg(SMVList[i].apName).arg(SMVList[i].SMV_addr.s_APPID);
						list.append(error);
					}

				}
				for (int j = 0; j < SMVList.size(); j++)
				{
					bool ok;
					if (i == j)
					{
						continue;
					}
					if ((SMVList[i].SMV_addr.s_MAC_addr == SMVList[j].SMV_addr.s_MAC_addr) || (SMVList[i].SMV_addr.s_APPID == SMVList[j].SMV_addr.s_APPID))
					{
						if (SMVList[i].SMV_addr.s_MAC_addr == SMVList[j].SMV_addr.s_MAC_addr)
						{
							RepeatSMV.append(SMVList[i]);
						}
						if (SMVList[i].SMV_addr.s_APPID.toUInt(&ok, 16) == SMVList[j].SMV_addr.s_APPID.toUInt(&ok, 16))
						{
							RepeatSMV_APPID.append(SMVList[i]);
						}
						break;
					}

				}
			}
			for (int m = 0; m < RepeatSMV.size(); m++)
			{
				error.clear();
				error = QObject::tr("Error  In the SubNetWork =%1 the SMV MAC Address %6 of iedName =%2 apName = %3  cbName = %4  ldInst = %5  was repeated")
					.arg(name).arg(RepeatSMV[m].iedName).arg(RepeatSMV[m].apName).arg(RepeatSMV[m].SMV_addr.s_cbName)
					.arg(RepeatSMV[m].SMV_addr.s_ldInst).arg(RepeatSMV[m].SMV_addr.s_MAC_addr);
				list.append(error);
			}
			for (int m = 0; m < RepeatSMV_APPID.size(); m++)
			{
				error.clear();
				error = QObject::tr("Error  In the SubNetWork =%1 the SMV APPID %6 of iedName =%2 apName = %3  cbName = %4  ldInst = %5  was repeated")
					.arg(name).arg(RepeatSMV_APPID[m].iedName).arg(RepeatSMV_APPID[m].apName).arg(RepeatSMV_APPID[m].SMV_addr.s_cbName)
					.arg(RepeatSMV_APPID[m].SMV_addr.s_ldInst).arg(RepeatSMV_APPID[m].SMV_addr.s_APPID);
				list.append(error);
			}
			continue;
		}
	}
	return DO_OK;
}
int ScdTree::CommAndIed_Check(QStringList &errList)
{

	QStringList ConnectedAPList;
	QStringList IED_List;
	TiXmlElement *m_elemnet = root->FirstChildElement("Communication");
	TiXmlElement *Child = NULL;
	QMap<QString, TiXmlElement*>APList;
	QMap<QString, TiXmlElement*>IEDMAP;
	Init_IED_MAP(root, IEDMAP);
	for (Child = m_elemnet->FirstChildElement("SubNetwork"); Child != NULL; Child = Child->NextSiblingElement("SubNetwork"))
	{
		QStringList keys1;
		Init_ConnectAP_MAP(Child, APList);
		keys1 = APList.keys();
		for (int i = 0; i < keys1.size(); i++)
		{
			if (!ConnectedAPList.contains(keys1[i]))
			{
				ConnectedAPList.append(keys1[i]);
			}
		}
	}

	QStringList keys2;
	keys2 = IEDMAP.keys();
	//	for (int i = 0; i < ConnectedAPList.size(); i++)
	//	{
	//		bool flag = false;
	//		for (int j = 0; j < keys2.size(); j++)
	//		{
	//			if (ConnectedAPList[i] == keys2[j])
	//			{
	//				flag = true;
	//				break;
	//			}
	//		}
	//		if (flag == false)
	//		{
	//			IED_List.append(ConnectedAPList[i]);
	//		}
	//	}
	for (int i = 0; i < keys2.size(); i++)
	{
		if (!ConnectedAPList.contains(keys2.at(i)))
		{
			QString errmes = QObject::tr("The IED ") + keys2.at(i) + QObject::tr("  has no communication para");
			errList.append(errmes);
		}
	}
	for (int i = 0; i < ConnectedAPList.size(); i++)
	{
		if (!keys2.contains(ConnectedAPList.at(i)))
		{
			QString errmes = QObject::tr("The IED ") + ConnectedAPList.at(i) + QObject::tr("   is not exist");
			errList.append(errmes);
		}
	}
	//	for (int i = 0; i < IED_List.size(); i++)
	//	{
	//		QString errmes = QObject::tr("The IED \"") + IED_List[i] + QObject::tr("is not exist");
	//		errList.append(errmes);

	//	}
	//QMap<QString, TiXmlElement*>Map_IED;
	//QMap<QString, TiXmlElement*>Map_LD;
	//QMap<QString, TiXmlElement*>Map_LN;
	//QMap<QString, TiXmlElement*>Map_SMV;
	//TiXmlElement*m_IED = NULL;
	//TiXmlElement*m_Access = NULL;
	//TiXmlElement*m_LD = NULL;
	//TiXmlElement*m_LN = NULL;
	//Init_IED_MAP(root, Map_IED);
	//for (int i = 0; i < Map_IED.uniqueKeys().size();i++)
	//{
	//	Init_LD_MAP(Map_IED.value(Map_IED.uniqueKeys().at(i)), Map_LD);
	//	for (int j = 0; j < Map_LD.uniqueKeys().size();j++)
	//	{
	//		Init_LN_MAP(Map_LD.value(Map_LD.uniqueKeys().at(j)), Map_LN);
	//		for (int m = 0; m < Map_LN.uniqueKeys().size(); m++)
	//		{
	//			Init_ControBlock_MAP(Map_LN.value(Map_LN.uniqueKeys().at(m)), Map_SMV,3);
	//		}
	//	}
	//}
	return DO_FAIL;
}
int ScdTree::FCDA_Check(QStringList &errList, QStringList &warnList, QStringList &RefList, QProgressBar*Bar)
{
	TiXmlElement *m_elemnet = root->FirstChildElement("IED");
	QString str1, str2, str3, str4;
	//const char* ch;
	Init_IED_MAP(root, IED_MAP);
	int value = 100 / IED_MAP.uniqueKeys().size();
	int index = 0;
	for (; m_elemnet != NULL; m_elemnet = m_elemnet->NextSiblingElement("IED"))
	{
		Bar->setValue(value*index);
		TiXmlElement *m_Ap = NULL;
		m_Ap = m_elemnet->FirstChildElement("AccessPoint");
		for (; m_Ap != NULL; m_Ap = m_Ap->NextSiblingElement("AccessPoint"))
		{
			TiXmlElement *m_LD = NULL;
			m_LD = m_Ap->FirstChildElement("Server")->FirstChildElement("LDevice");
			for (; m_LD != NULL; m_LD = m_LD->NextSiblingElement("LDevice"))
			{
				TiXmlElement *m_LN = NULL;
				m_LN = m_LD->FirstChildElement();
				for (; m_LN != NULL; m_LN = m_LN->NextSiblingElement())
				{
					TiXmlElement *m_Dataset = NULL;
					m_Dataset = m_LN->FirstChildElement("DataSet");
					for (; m_Dataset != NULL; m_Dataset = m_Dataset->NextSiblingElement("DataSet"))
					{
						TiXmlElement *m_FCDA = NULL;
						m_FCDA = m_Dataset->FirstChildElement("FCDA");
						for (; m_FCDA != NULL; m_FCDA = m_FCDA->NextSiblingElement("FCDA"))
						{
							Check_One_FCDA(m_elemnet, m_Ap, m_FCDA, errList, warnList, RefList);
						}
					}
				}
			}
		}
		index++;
	}

	return DO_OK;
}
int ScdTree::Check_One_FCDA(TiXmlElement* m_IED, TiXmlElement* m_Ap, TiXmlElement* m_FCDA,
	QStringList &errList, QStringList &warnList, QStringList &RefList)
{
	const char* chr;
	chr = m_IED->Attribute("name");
	QMap<QString, TiXmlElement*> Ln_Map;
	QString strIED, strLD;
	strIED += chr;
	strLD += m_FCDA->Attribute("ldInst");
	QMap<QString, TiXmlElement*>LD_MAP;
	Init_LD_MAP(m_IED, LD_MAP);
	TiXmlElement* m_LD = LD_MAP.value(strLD);
	if (m_LD == NULL)
	{
		QString errmes = QObject::tr("Error IED=%1 AccessPoint=%2 LDevice=%3 the DataSet of LN0 {name=%4 desc=%5} FCDA{ldInst=%6 prefix=%7 lnClass=%8 lnInst=%9 doName=%10 fc=%11 } The LD is not exist")
			.arg(strIED).arg(QString::fromStdString(m_Ap->Attribute("name")))
			.arg(strLD).arg(QString::fromStdString(m_FCDA->Parent()->ToElement()->Attribute("name")))
			.arg(QString::fromStdString(m_FCDA->Parent()->ToElement()->Attribute("desc"))).arg(QString::fromStdString(m_FCDA->Attribute("ldInst")))
			.arg(QString::fromStdString(m_FCDA->Attribute("prefix"))).arg(QString::fromStdString(m_FCDA->Attribute("lnClass")))
			.arg(QString::fromStdString(m_FCDA->Attribute("lnInst"))).arg(QString::fromStdString(m_FCDA->Attribute("doName")))
			.arg(QString::fromStdString(m_FCDA->Attribute("fc")));
		errList.append(errmes);
		return DO_FAIL;
	}
	//TiXmlElement* m_LD = m_Ap->GetChildByName_Value(m_Ap->FirstChildElement("Server"), "inst", m_FCDA->Attribute("ldInst"));
	Ln_Map.clear();
	Init_LN_MAP(m_LD, Ln_Map);
	TiXmlElement *m_LN = NULL;
	QString lninst;
	chr = m_FCDA->Attribute("prefix");
	lninst += chr;
	chr = m_FCDA->Attribute("lnClass");
	lninst += chr;
	chr = m_FCDA->Attribute("lnInst");
	lninst += chr;
	lninst = lninst.simplified();
	m_LN = Ln_Map.value(lninst);
	if (m_LN == NULL)
	{
		QString errmes = QObject::tr("Error IED=%1 AccessPoint=%2 LDevice=%3 the DataSet of LN0 {name=%4 desc=%5} FCDA{ldInst=%6 prefix=%7 lnClass=%8 lnInst=%9 doName=%10 fc=%11 } the LN is not exist ")
			.arg(strIED).arg(QString::fromStdString(m_Ap->Attribute("name")))
			.arg(QString::fromStdString(m_LD->Attribute("inst"))).arg(QString::fromStdString(m_FCDA->Parent()->ToElement()->Attribute("name")))
			.arg(QString::fromStdString(m_FCDA->Parent()->ToElement()->Attribute("desc"))).arg(QString::fromStdString(m_FCDA->Attribute("ldInst")))
			.arg(QString::fromStdString(m_FCDA->Attribute("prefix"))).arg(QString::fromStdString(m_FCDA->Attribute("lnClass")))
			.arg(QString::fromStdString(m_FCDA->Attribute("lnInst"))).arg(QString::fromStdString(m_FCDA->Attribute("doName")))
			.arg(QString::fromStdString(m_FCDA->Attribute("fc")));
		errList.append(errmes);
		return DO_FAIL;
	}
	TiXmlElement* m_DataTemplate = root->FirstChildElement("DataTypeTemplates");

	TiXmlElement * m_LNodeTye = m_DataTemplate->GetChildByName_Value(m_DataTemplate, "LNodeType", "id", m_LN->Attribute("lnType"));
	QString s_daName, s_doName;
	s_daName += m_FCDA->Attribute("daName");
	s_doName += m_FCDA->Attribute("doName");
	QStringList daList, doList;
	if (!s_daName.isEmpty())
	{
		daList = s_daName.split(".");
	}
	else
	{
		daList.clear();
	}
	if (!s_doName.isEmpty())
	{
		doList = s_doName.split(".");
	}
	else
	{
		doList.clear();
	}
	if (m_LNodeTye == NULL)
	{
		if (s_daName.isEmpty())
		{
			QString errmes = QObject::tr("Error IED=%1 AccessPoint=%2 LDevice=%3 the DataSet of LN0 {name=%4 desc=%5} FCDA{ldInst=%6 prefix=%7 lnClass=%8 lnInst=%9 doName=%10 fc=%11 }The LNodeTye is not exist in DataTypeTemplates")
				.arg(strIED).arg(QString::fromStdString(m_Ap->Attribute("name")))
				.arg(QString::fromStdString(m_LD->Attribute("inst"))).arg(QString::fromStdString(m_FCDA->Parent()->ToElement()->Attribute("name")))
				.arg(QString::fromStdString(m_FCDA->Parent()->ToElement()->Attribute("desc"))).arg(QString::fromStdString(m_FCDA->Attribute("ldInst")))
				.arg(QString::fromStdString(m_FCDA->Attribute("prefix"))).arg(QString::fromStdString(m_FCDA->Attribute("lnClass")))
				.arg(QString::fromStdString(m_FCDA->Attribute("lnInst"))).arg(QString::fromStdString(m_FCDA->Attribute("doName")))
				.arg(QString::fromStdString(m_FCDA->Attribute("fc")));
			RefList.append(errmes);
			return DO_FAIL;

		}
		else
		{
			QString errmes = QObject::tr("Error IED=%1 AccessPoint=%2 LDevice=%3 the DataSet of LN0 {name=%4 desc=%5} FCDA{ldInst=%6 prefix=%7 lnClass=%8 lnInst=%9  doName=%10 daName=%11 fc=%12 } The LNodeTye is not exist in DataTypeTemplates")
				.arg(strIED).arg(QString::fromStdString(m_Ap->Attribute("name")))
				.arg(QString::fromStdString(m_LD->Attribute("inst"))).arg(QString::fromStdString(m_FCDA->Parent()->ToElement()->Attribute("name")))
				.arg(QString::fromStdString(m_FCDA->Parent()->ToElement()->Attribute("desc"))).arg(QString::fromStdString(m_FCDA->Attribute("ldInst")))
				.arg(QString::fromStdString(m_FCDA->Attribute("prefix"))).arg(QString::fromStdString(m_FCDA->Attribute("lnClass")))
				.arg(QString::fromStdString(m_FCDA->Attribute("lnInst"))).arg(QString::fromStdString(m_FCDA->Attribute("doName")))
				.arg(QString::fromStdString(m_FCDA->Attribute("daName"))).arg(QString::fromStdString(m_FCDA->Attribute("fc")));
			RefList.append(errmes);
			return DO_FAIL;
		}
	}
	else
	{
		TiXmlElement *m_DO = NULL;
		if (doList.size() != 1)
		{
			TiXmlElement *m_temp = NULL;
			while (doList.size() > 1)
			{
				m_DO = m_LNodeTye->GetChildByName_Value(m_LNodeTye, "DO", "name", doList.at(0).toStdString().data());
				if (m_DO == NULL)
				{
					QString errmes = QObject::tr("Error IED=%1 AccessPoint=%2 LDevice=%3 the DataSet of LN0 {name=%4 desc=%5} FCDA{ldInst=%6 prefix=%7 lnClass=%8 lnInst=%9 doName=%10 fc=%11 } The doName is not exist in DataTypeTemplates")
						.arg(strIED).arg(QString::fromStdString(m_Ap->Attribute("name")))
						.arg(QString::fromStdString(m_LD->Attribute("inst"))).arg(QString::fromStdString(m_FCDA->Parent()->ToElement()->Attribute("name")))
						.arg(QString::fromStdString(m_FCDA->Parent()->ToElement()->Attribute("desc"))).arg(QString::fromStdString(m_FCDA->Attribute("ldInst")))
						.arg(QString::fromStdString(m_FCDA->Attribute("prefix"))).arg(QString::fromStdString(m_FCDA->Attribute("lnClass")))
						.arg(QString::fromStdString(m_FCDA->Attribute("lnInst"))).arg(QString::fromStdString(m_FCDA->Attribute("doName")))
						.arg(QString::fromStdString(m_FCDA->Attribute("fc")));
					RefList.append(errmes);
					return DO_FAIL;
				}
				m_temp = m_DataTemplate->GetChildByName_Value(m_DataTemplate, "DOType", "id", m_DO->Attribute("type"));
				if (m_temp == NULL)
				{
					QString errmes = QObject::tr("Error IED=%1 AccessPoint=%2 LDevice=%3 the DataSet of LN0 {name=%4 desc=%5} FCDA{ldInst=%6 prefix=%7 lnClass=%8 lnInst=%9 doName=%10 fc=%11 } The doName is not exist in DataTypeTemplates")
						.arg(strIED).arg(QString::fromStdString(m_Ap->Attribute("name")))
						.arg(QString::fromStdString(m_LD->Attribute("inst"))).arg(QString::fromStdString(m_FCDA->Parent()->ToElement()->Attribute("name")))
						.arg(QString::fromStdString(m_FCDA->Parent()->ToElement()->Attribute("desc"))).arg(QString::fromLocal8Bit(m_FCDA->Attribute("ldInst")))
						.arg(QString::fromStdString(m_FCDA->Attribute("prefix"))).arg(QString::fromStdString(m_FCDA->Attribute("lnClass")))
						.arg(QString::fromStdString(m_FCDA->Attribute("lnInst"))).arg(QString::fromStdString(m_FCDA->Attribute("doName")))
						.arg(QString::fromStdString(m_FCDA->Attribute("fc")));
					RefList.append(errmes);
					return DO_FAIL;
				}

				doList.removeAt(0);
			}
			m_DO = m_temp->GetChildByName_Value(m_temp, "SDO", "name", doList.at(0).toStdString().data());
		}
		else
		{
			m_DO = m_LNodeTye->GetChildByName_Value(m_LNodeTye, "DO", "name", doList.at(0).toStdString().data());
		}
		if (m_DO == NULL)
		{

			QString errmes = QObject::tr("Error IED=%1 AccessPoint=%2 LDevice=%3 the DataSet of LN0 {name=%4 desc=%5} FCDA{ldInst=%6 prefix=%7 lnClass=%8 lnInst=%9 doName=%10 fc=%11 } The doName is not exist in DataTypeTemplates")
				.arg(strIED).arg(QString::fromStdString(m_Ap->Attribute("name")))
				.arg(QString::fromStdString(m_LD->Attribute("inst"))).arg(QString::fromStdString(m_FCDA->Parent()->ToElement()->Attribute("name")))
				.arg(QString::fromStdString(m_FCDA->Parent()->ToElement()->Attribute("desc"))).arg(QString::fromStdString(m_FCDA->Attribute("ldInst")))
				.arg(QString::fromStdString(m_FCDA->Attribute("prefix"))).arg(QString::fromStdString(m_FCDA->Attribute("lnClass")))
				.arg(QString::fromStdString(m_FCDA->Attribute("lnInst"))).arg(QString::fromStdString(m_FCDA->Attribute("doName")))
				.arg(QString::fromStdString(m_FCDA->Attribute("fc")));

			RefList.append(errmes);
			return DO_FAIL;
		}
		else
		{
			TiXmlElement * m_DOType = m_DataTemplate->GetChildByName_Value(m_DataTemplate, "DOType", "id", m_DO->Attribute("type"));

			if (m_DOType == NULL)
			{
				QString errmes = QObject::tr("Error IED=%1 AccessPoint=%2 LDevice=%3 the DataSet of LN0 {name=%4 desc=%5} FCDA{ldInst=%6 prefix=%7 lnClass=%8 lnInst=%9 doName=%10 fc=%11 } The doName is not exist in DataTypeTemplates")
					.arg(strIED).arg(QString::fromStdString(m_Ap->Attribute("name")))
					.arg(QString::fromStdString(m_LD->Attribute("inst"))).arg(QString::fromStdString(m_FCDA->Parent()->ToElement()->Attribute("name")))
					.arg(QString::fromStdString(m_FCDA->Parent()->ToElement()->Attribute("desc"))).arg(QString::fromStdString(m_FCDA->Attribute("ldInst")))
					.arg(QString::fromStdString(m_FCDA->Attribute("prefix"))).arg(QString::fromStdString(m_FCDA->Attribute("lnClass")))
					.arg(QString::fromStdString(m_FCDA->Attribute("lnInst"))).arg(QString::fromStdString(m_FCDA->Attribute("doName")))
					.arg(QString::fromStdString(m_FCDA->Attribute("fc")));
				RefList.append(errmes);
				return DO_FAIL;

			}
			else
			{
				if (daList.size() > 1)
				{

					TiXmlElement * m_DA = m_DOType->GetChildByName_Value(m_DOType, "DA", "name", daList.at(0).toStdString().data());
					daList.removeAt(0);
					if (m_DA == NULL)
					{
						QString errmes = QObject::tr("Error IED=%1 AccessPoint=%2 LDevice=%3 the DataSet of LN0 {name=%4 desc=%5} FCDA{ldInst=%6 prefix=%7 lnClass=%8 lnInst=%9 doName=%10 daName=%11 fc=%12 } The daName is not exist in DataTypeTemplates")
							.arg(strIED).arg(QString::fromStdString(m_Ap->Attribute("name")))
							.arg(QString::fromStdString(m_LD->Attribute("inst"))).arg(QString::fromStdString(m_FCDA->Parent()->ToElement()->Attribute("name")))
							.arg(QString::fromStdString(m_FCDA->Parent()->ToElement()->Attribute("desc"))).arg(QString::fromStdString(m_FCDA->Attribute("ldInst")))
							.arg(QString::fromStdString(m_FCDA->Attribute("prefix"))).arg(QString::fromStdString(m_FCDA->Attribute("lnClass")))
							.arg(QString::fromStdString(m_FCDA->Attribute("lnInst"))).arg(QString::fromStdString(m_FCDA->Attribute("doName")))
							.arg(QString::fromStdString(m_FCDA->Attribute("daName"))).arg(QString::fromStdString(m_FCDA->Attribute("fc")));
						RefList.append(errmes);
						return DO_FAIL;
					}
					else
					{
						if (0 != strcmp(m_DA->Attribute("fc"), m_FCDA->Attribute("fc")))
						{
							QString errmes = QObject::tr("Error IED=%1 AccessPoint=%2 LDevice=%3 the DataSet of LN0 {name=%4 desc=%5} FCDA{ldInst=%6 prefix=%7 lnClass=%8 lnInst=%9 doName=%10 daName=%11 fc=%12 } The daName is not exist in DataTypeTemplates")
								.arg(strIED).arg(QString::fromLocal8Bit(m_Ap->Attribute("name")))
								.arg(QString::fromStdString(m_LD->Attribute("inst"))).arg(QString::fromStdString(m_FCDA->Parent()->ToElement()->Attribute("name")))
								.arg(QString::fromStdString(m_FCDA->Parent()->ToElement()->Attribute("desc"))).arg(QString::fromStdString(m_FCDA->Attribute("ldInst")))
								.arg(QString::fromStdString(m_FCDA->Attribute("prefix"))).arg(QString::fromStdString(m_FCDA->Attribute("lnClass")))
								.arg(QString::fromStdString(m_FCDA->Attribute("lnInst"))).arg(QString::fromStdString(m_FCDA->Attribute("doName")))
								.arg(QString::fromStdString(m_FCDA->Attribute("daName"))).arg(QString::fromStdString(m_FCDA->Attribute("fc")));
							RefList.append(errmes);
							return DO_FAIL;
						}
						else
						{

							TiXmlElement *m_DAType = NULL;
							TiXmlElement *m_BDA = NULL;
							m_DAType = m_DataTemplate->GetChildByName_Value(m_DataTemplate, "DAType", "id", m_DA->Attribute("type"));
							if (m_DAType == NULL)
							{
								QString errmes = QObject::tr("Error IED=%1 AccessPoint=%2 LDevice=%3 the DataSet of LN0 {name=%4 desc=%5} FCDA{ldInst=%6 prefix=%7 lnClass=%8 lnInst=%9  doName=%10 daName=%11 fc=%12 } The daName is not exist in DataTypeTemplates")
									.arg(strIED).arg(QString::fromStdString(m_Ap->Attribute("name")))
									.arg(QString::fromStdString(m_LD->Attribute("inst"))).arg(QString::fromStdString(m_FCDA->Parent()->ToElement()->Attribute("name")))
									.arg(QString::fromStdString(m_FCDA->Parent()->ToElement()->Attribute("desc"))).arg(QString::fromStdString(m_FCDA->Attribute("ldInst")))
									.arg(QString::fromStdString(m_FCDA->Attribute("prefix"))).arg(QString::fromStdString(m_FCDA->Attribute("lnClass")))
									.arg(QString::fromStdString(m_FCDA->Attribute("lnInst"))).arg(QString::fromStdString(m_FCDA->Attribute("doName")))
									.arg(QString::fromStdString(m_FCDA->Attribute("daName"))).arg(QString::fromStdString(m_FCDA->Attribute("fc")));
								RefList.append(errmes);
								return DO_FAIL;
							}
							while (daList.size())
							{
								//m_DAType = m_DataTemplate->GetChildByName_Value(m_DataTemplate, "DAType", "id", m_BDA->Attribute("type"));
								m_BDA = m_DAType->GetChildByName_Value(m_DAType, "BDA", "name", daList.at(0).toStdString().data());
								if (m_BDA == NULL)
								{
									QString errmes = QObject::tr("Error IED=%1 AccessPoint=%2 LDevice=%3 the DataSet of LN0 {name=%4 desc=%5} FCDA{ldInst=%6 prefix=%7 lnClass=%8 lnInst=%9  doName=%10 daName=%11 fc=%12 } The daName is not exist in DataTypeTemplates")
										.arg(strIED).arg(QString::fromStdString(m_Ap->Attribute("name")))
										.arg(QString::fromStdString(m_LD->Attribute("inst"))).arg(QString::fromStdString(m_FCDA->Parent()->ToElement()->Attribute("name")))
										.arg(QString::fromStdString(m_FCDA->Parent()->ToElement()->Attribute("desc"))).arg(QString::fromLocal8Bit(m_FCDA->Attribute("ldInst")))
										.arg(QString::fromStdString(m_FCDA->Attribute("prefix"))).arg(QString::fromStdString(m_FCDA->Attribute("lnClass")))
										.arg(QString::fromStdString(m_FCDA->Attribute("lnInst"))).arg(QString::fromStdString(m_FCDA->Attribute("doName")))
										.arg(QString::fromStdString(m_FCDA->Attribute("daName"))).arg(QString::fromStdString(m_FCDA->Attribute("fc")));
									RefList.append(errmes);
									return DO_FAIL;
								}
								if (m_BDA->Attribute("type") == NULL)
								{
									break;
								}
								m_DAType = m_DataTemplate->GetChildByName_Value(m_DataTemplate, "DAType", "id", m_BDA->Attribute("type"));
								if (m_DAType == NULL)
								{
									//QString errmes = QObject::tr("The DAType of") + QString::fromLocal8Bit(m_FCDA->Attribute("daName")) + QObject::tr("is not exist");
									QString errmes = QObject::tr("Error IED=%1 AccessPoint=%2 LDevice=%3 the DataSet of LN0 {name=%4 desc=%5} FCDA{ldInst=%6 prefix=%7 lnClass=%8 lnInst=%9  doName=%10 daName=%11 fc=%12 } The daName is not exist in DataTypeTemplates")
										.arg(strIED).arg(QString::fromLocal8Bit(m_Ap->Attribute("name")))
										.arg(QString::fromLocal8Bit(m_LD->Attribute("inst"))).arg(QString::fromLocal8Bit(m_FCDA->Parent()->ToElement()->Attribute("name")))
										.arg(QString::fromStdString(m_FCDA->Parent()->ToElement()->Attribute("desc"))).arg(QString::fromLocal8Bit(m_FCDA->Attribute("ldInst")))
										.arg(QString::fromLocal8Bit(m_FCDA->Attribute("prefix"))).arg(QString::fromLocal8Bit(m_FCDA->Attribute("lnClass")))
										.arg(QString::fromLocal8Bit(m_FCDA->Attribute("lnInst"))).arg(QString::fromLocal8Bit(m_FCDA->Attribute("doName")))
										.arg(QString::fromLocal8Bit(m_FCDA->Attribute("daName"))).arg(QString::fromStdString(m_FCDA->Attribute("fc")));
									RefList.append(errmes);
									return DO_FAIL;
								}

								daList.removeAt(0);
							}

						}
					}
				}

				else if (daList.size() == 1)
				{
					TiXmlElement * m_DA = m_DOType->GetChildByName_Value(m_DOType, "DA", "fc", m_FCDA->Attribute("fc"));
					if (m_DA == NULL)
					{
						QString errmes = QObject::tr("Error IED=%1 AccessPoint=%2 LDevice=%3 the DataSet of LN0 {name=%4 desc=%5} FCDA{ldInst=%6 prefix=%7 lnClass=%8 lnInst=%9  doName=%10 daName=%11 fc=%12 } The Fc is not exist in DataTypeTemplates")
							.arg(strIED).arg(QString::fromLocal8Bit(m_Ap->Attribute("name")))
							.arg(QString::fromLocal8Bit(m_LD->Attribute("inst"))).arg(QString::fromLocal8Bit(m_FCDA->Parent()->ToElement()->Attribute("name")))
							.arg(QString::fromStdString(m_FCDA->Parent()->ToElement()->Attribute("desc"))).arg(QString::fromLocal8Bit(m_FCDA->Attribute("ldInst")))
							.arg(QString::fromLocal8Bit(m_FCDA->Attribute("prefix"))).arg(QString::fromLocal8Bit(m_FCDA->Attribute("lnClass")))
							.arg(QString::fromLocal8Bit(m_FCDA->Attribute("lnInst"))).arg(QString::fromLocal8Bit(m_FCDA->Attribute("doName")))
							.arg(QString::fromLocal8Bit(m_FCDA->Attribute("daName"))).arg(QString::fromStdString(m_FCDA->Attribute("fc")));
						errList.append(errmes);
						return DO_FAIL;
					}
				}
			}
		}
	}
	daList.clear();
	if (!s_daName.isEmpty())
	{
		daList = s_daName.split(".");
	}
	if (!s_doName.isEmpty())
	{
		doList = s_doName.split(".");
	}
	TiXmlElement* m_DOI = NULL;
	if (doList.size() == 1)
	{
		m_DOI = m_LN->GetChildByName_Value(m_LN, "name", doList.at(0).toStdString().data());
		if ((m_DOI == NULL))
		{
			QString errmes = QObject::tr("Warning IED=%1 AccessPoint=%2 LDevice=%3 the DataSet of LN0 {name=%4 desc=%5} FCDA{ldInst=%6 prefix=%7 lnClass=%8 lnInst=%9  doName=%10 daName=%11 fc=%12 } is  exist in DataTypeTemplates,but is not instanced")
				.arg(strIED).arg(QString::fromLocal8Bit(m_Ap->Attribute("name")))
				.arg(QString::fromLocal8Bit(m_LD->Attribute("inst"))).arg(QString::fromLocal8Bit(m_FCDA->Parent()->ToElement()->Attribute("name")))
				.arg(QString::fromStdString(m_FCDA->Parent()->ToElement()->Attribute("desc"))).arg(QString::fromLocal8Bit(m_FCDA->Attribute("ldInst")))
				.arg(QString::fromLocal8Bit(m_FCDA->Attribute("prefix"))).arg(QString::fromLocal8Bit(m_FCDA->Attribute("lnClass")))
				.arg(QString::fromLocal8Bit(m_FCDA->Attribute("lnInst"))).arg(QString::fromLocal8Bit(m_FCDA->Attribute("doName")))
				.arg(QString::fromLocal8Bit(m_FCDA->Attribute("daName"))).arg(QString::fromStdString(m_FCDA->Attribute("fc")));
			warnList.append(errmes);
			return DO_FAIL;
		}
	}
	else if (doList.size() > 1)
	{
		m_DOI = m_LN->GetChildByName_Value(m_LN, "name", doList.at(0).toStdString().data());
		if ((m_DOI == NULL))
		{
			QString errmes = QObject::tr("Warning IED=%1 AccessPoint=%2 LDevice=%3 the DataSet of LN0 {name=%4 desc=%5} FCDA{ldInst=%6 prefix=%7 lnClass=%8 lnInst=%9  doName=%10 daName=%11 fc=%12 } is  exist in DataTypeTemplates,but is not instanced")
				.arg(strIED).arg(QString::fromLocal8Bit(m_Ap->Attribute("name")))
				.arg(QString::fromLocal8Bit(m_LD->Attribute("inst"))).arg(QString::fromLocal8Bit(m_FCDA->Parent()->ToElement()->Attribute("name")))
				.arg(QString::fromStdString(m_FCDA->Parent()->ToElement()->Attribute("desc"))).arg(QString::fromLocal8Bit(m_FCDA->Attribute("ldInst")))
				.arg(QString::fromLocal8Bit(m_FCDA->Attribute("prefix"))).arg(QString::fromLocal8Bit(m_FCDA->Attribute("lnClass")))
				.arg(QString::fromLocal8Bit(m_FCDA->Attribute("lnInst"))).arg(QString::fromLocal8Bit(m_FCDA->Attribute("doName")))
				.arg(QString::fromLocal8Bit(m_FCDA->Attribute("daName"))).arg(QString::fromStdString(m_FCDA->Attribute("fc")));
			warnList.append(errmes);
			return DO_FAIL;
		}
		doList.removeAt(0);
		while (doList.size())
		{
			m_DOI = m_DOI->GetChildByName_Value(m_DOI, "name", doList.at(0).toStdString().data());
			if ((m_DOI == NULL))
			{
				QString errmes = QObject::tr("Warnning IED=%1 AccessPoint=%2 LDevice=%3 the DataSet of LN0 {name=%4 desc=%5} FCDA{ldInst=%6 prefix=%7 lnClass=%8 lnInst=%9  doName=%10 daName=%11 fc=%12 } is  exist in DataTypeTemplates,but is not instanced")
					.arg(strIED).arg(QString::fromLocal8Bit(m_Ap->Attribute("name")))
					.arg(QString::fromLocal8Bit(m_LD->Attribute("inst"))).arg(QString::fromLocal8Bit(m_FCDA->Parent()->ToElement()->Attribute("name")))
					.arg(QString::fromStdString(m_FCDA->Parent()->ToElement()->Attribute("desc"))).arg(QString::fromLocal8Bit(m_FCDA->Attribute("ldInst")))
					.arg(QString::fromLocal8Bit(m_FCDA->Attribute("prefix"))).arg(QString::fromLocal8Bit(m_FCDA->Attribute("lnClass")))
					.arg(QString::fromLocal8Bit(m_FCDA->Attribute("lnInst"))).arg(QString::fromLocal8Bit(m_FCDA->Attribute("doName")))
					.arg(QString::fromLocal8Bit(m_FCDA->Attribute("daName"))).arg(QString::fromStdString(m_FCDA->Attribute("fc")));
				warnList.append(errmes);
				return DO_FAIL;
			}
			doList.removeAt(0);
		}
	}

	if (daList.size() == 0)
	{
		return DO_OK;
	}
	else
	{

		if ((m_DOI == NULL))
		{
			QString errmes = QObject::tr("Warnning IED=%1 AccessPoint=%2 LDevice=%3 the DataSet of LN0 {name=%4 desc=%5} FCDA{ldInst=%6 prefix=%7 lnClass=%8 lnInst=%9  doName=%10 daName=%11 fc=%12 } is  exist in DataTypeTemplates,but is not instanced")
				.arg(strIED).arg(QString::fromLocal8Bit(m_Ap->Attribute("name")))
				.arg(QString::fromLocal8Bit(m_LD->Attribute("inst"))).arg(QString::fromLocal8Bit(m_FCDA->Parent()->ToElement()->Attribute("name")))
				.arg(QString::fromStdString(m_FCDA->Parent()->ToElement()->Attribute("desc"))).arg(QString::fromLocal8Bit(m_FCDA->Attribute("ldInst")))
				.arg(QString::fromLocal8Bit(m_FCDA->Attribute("prefix"))).arg(QString::fromLocal8Bit(m_FCDA->Attribute("lnClass")))
				.arg(QString::fromLocal8Bit(m_FCDA->Attribute("lnInst"))).arg(QString::fromLocal8Bit(m_FCDA->Attribute("doName")))
				.arg(QString::fromLocal8Bit(m_FCDA->Attribute("daName"))).arg(QString::fromStdString(m_FCDA->Attribute("fc")));
			warnList.append(errmes);
			return DO_FAIL;
		}
		TiXmlElement *m_DAI = m_DOI->GetChildByName_Value(m_DOI, "name", daList.at(0).toStdString().data());
		if (m_DAI == NULL)
		{
			QString errmes = QObject::tr("Warnning IED=%1 AccessPoint=%2 LDevice=%3 the DataSet of LN0 {name=%4 desc=%5} FCDA{ldInst=%6 prefix=%7 lnClass=%8 lnInst=%9  doName=%10 daName=%11 fc=%12 } is  exist in DataTypeTemplates,but is not instanced")
				.arg(strIED).arg(QString::fromStdString(m_Ap->Attribute("name")))
				.arg(QString::fromLocal8Bit(m_LD->Attribute("inst"))).arg(QString::fromLocal8Bit(m_FCDA->Parent()->ToElement()->Attribute("name")))
				.arg(QString::fromStdString(m_FCDA->Parent()->ToElement()->Attribute("desc"))).arg(QString::fromLocal8Bit(m_FCDA->Attribute("ldInst")))
				.arg(QString::fromLocal8Bit(m_FCDA->Attribute("prefix"))).arg(QString::fromLocal8Bit(m_FCDA->Attribute("lnClass")))
				.arg(QString::fromLocal8Bit(m_FCDA->Attribute("lnInst"))).arg(QString::fromLocal8Bit(m_FCDA->Attribute("doName")))
				.arg(QString::fromLocal8Bit(m_FCDA->Attribute("daName"))).arg(QString::fromLocal8Bit(m_FCDA->Attribute("fc")));
			warnList.append(errmes);
			return DO_FAIL;
		}

		daList.removeAt(0);
		while (daList.size())
		{
			m_DAI = m_DAI->GetChildByName_Value(m_DAI, "name", daList.at(0).toStdString().data());
			if (m_DAI == NULL)
			{
				QString errmes = QObject::tr("Warnning IED=%1 AccessPoint=%2 LDevice=%3 the DataSet of LN0 {name=%4 desc=%5} FCDA{ldInst=%6 prefix=%7 lnClass=%8 lnInst=%9  doName=%10 daName=%11 fc=%12 } is  exist in DataTypeTemplates,but is not instanced")
					.arg(strIED).arg(QString::fromLocal8Bit(m_Ap->Attribute("name")))
					.arg(QString::fromLocal8Bit(m_LD->Attribute("inst"))).arg(QString::fromLocal8Bit(m_FCDA->Parent()->ToElement()->Attribute("name")))
					.arg(QVariant(m_FCDA->Parent()->ToElement()->Attribute("desc")).toString()).arg(QString::fromLocal8Bit(m_FCDA->Attribute("ldInst")))
					.arg(QString::fromLocal8Bit(m_FCDA->Attribute("prefix"))).arg(QString::fromLocal8Bit(m_FCDA->Attribute("lnClass")))
					.arg(QString::fromLocal8Bit(m_FCDA->Attribute("lnInst"))).arg(QString::fromLocal8Bit(m_FCDA->Attribute("doName")))
					.arg(QString::fromLocal8Bit(m_FCDA->Attribute("daName"))).arg(QString::fromLocal8Bit(m_FCDA->Attribute("fc")));
				warnList.append(errmes);
				return DO_FAIL;
			}
			daList.removeAt(0);

		}
	}


	return DO_OK;
}
int ScdTree::MappingReceiver_Check(QStringList &SerrList, QStringList &RerrList, QStringList &SwarnList, QStringList &RwarnList, QStringList &RefList, QProgressBar*Bar)
{
	TiXmlElement* m_IED = root->FirstChildElement("IED");
	Init_IED_MAP(root, IED_MAP);
	int value = 100 / IED_MAP.uniqueKeys().size();
	int index = 0;
	for (; m_IED != NULL; m_IED = m_IED->NextSiblingElement("IED"))
	{
		Bar->setValue(value*index);

		TiXmlElement* m_AP = m_IED->FirstChildElement("AccessPoint");
		for (; m_AP != NULL; m_AP = m_AP->NextSiblingElement("AccessPoint"))
		{
			DataInst_Vector.clear();
			DataMatrix_Vector.clear();
			TiXmlElement* m_LD = m_AP->FirstChildElement("Server")->FirstChildElement("LDevice");
			for (; m_LD != NULL; m_LD = m_LD->NextSiblingElement("LDevice"))
			{
				TiXmlElement* m_LN = m_LD->FirstChildElement();
				for (; m_LN != NULL; m_LN = m_LN->NextSiblingElement())
				{
					TiXmlElement* m_Inputs = m_LN->FirstChildElement("Inputs");
					if (m_Inputs != NULL)
					{
						PrepareDataForCheck(m_Inputs, m_LD);
					}

					for (; m_Inputs != NULL; m_Inputs = m_Inputs->NextSiblingElement("Inputs"))
					{
						TiXmlElement* m_ExtRef = m_Inputs->FirstChildElement("ExtRef");
						for (; m_ExtRef != NULL; m_ExtRef = m_ExtRef->NextSiblingElement("ExtRef"))
						{
							Check_One_Mapping(m_ExtRef, m_IED, m_LD, SerrList, RerrList, SwarnList, RwarnList, RefList);
						}
					}
				}
			}
		}
		index++;
	}
	return DO_OK;
}
int ScdTree::PrepareDataForCheck(TiXmlElement* Inputs, TiXmlElement*LD)
{
	QMap<QString, TiXmlElement *>IED_MAP;
	QMap<QString, TiXmlElement *>LD_MAP;
	QMap<QString, TiXmlElement *>LN_MAP;
	Init_IED_MAP(root, IED_MAP);
	const char* chr;
	QString str = LD->Attribute("inst");
	TiXmlElement *child = LD->FirstChildElement();
	for (; child != NULL; child = child->NextSiblingElement())
	{
		QString LnodeType;
		LnodeType = child->Attribute("lnType");
		if (!LNondeType_List.contains(LnodeType))
		{
			LNondeType_List.append(LnodeType);
		}
	}
	child = Inputs->FirstChildElement();
	for (; child != NULL; child = child->NextSiblingElement())
	{
		QString LnodeType;
		QString strIED, strLD, strLninst;
		chr = child->Attribute("iedName");
		strIED += chr;
		TiXmlElement *m_ied = IED_MAP.value(strIED);
		if (m_ied == NULL)
		{
			continue;
		}
		Init_LD_MAP(m_ied, LD_MAP);
		chr = child->Attribute("ldInst");
		strLD += chr;
		TiXmlElement *m_LD = NULL;
		m_LD = LD_MAP.value(strLD);
		if (m_LD == NULL)
		{
			continue;
		}
		Init_LN_MAP(m_LD, LN_MAP);
		chr = child->Attribute("prefix");
		strLninst += chr;
		chr = child->Attribute("lnClass");
		strLninst += chr;
		chr = child->Attribute("lnInst");
		strLninst += chr;
		strLninst = strLninst.simplified();
		TiXmlElement *m_ln = NULL;
		m_ln = LN_MAP.value(strLninst);
		if (m_ln == NULL)
		{
			continue;
		}
		chr = m_ln->Attribute("lnType");
		LnodeType += chr;
		if (!LNondeType_List.contains(LnodeType))
		{
			LNondeType_List.append(LnodeType);
		}

	}
	DataMatrix_Vector.clear();
	for (int j = 0; j < LNondeType_List.size(); j++)
	{

		CreatDataMatrix(LNondeType_List.at(j), DataMatrix_Vector);
	}
	return DO_OK;
}
int ScdTree::Check_One_Mapping(TiXmlElement* ExtRef, TiXmlElement* IED, TiXmlElement* LD, QStringList &SerrList, QStringList &RerrList, QStringList &SwarnList, QStringList &RwarnList, QStringList &RefList)
{
	Check_One_Sender(ExtRef, IED, LD, SerrList, SwarnList, RefList);
	Check_One_Receiver(ExtRef, IED, LD, RerrList, RwarnList, RefList);
	return DO_OK;
}
//TiXmlElement* ScdTree::GetLDeviceByName(TiXmlElement*IED, QString strName)
//{
//	TiXmlElement *m_ap = IED->FirstChildElement("AccessPoint");
//	for (; m_ap != NULL; m_ap = m_ap->NextSiblingElement("AccessPoint"))
//	{
//		TiXmlElement* m_LD = m_ap->FirstChildElement("Server")->FirstChildElement("LDevice");
//		for (; m_LD != NULL; m_LD = m_LD->NextSiblingElement("LDevice"))
//		{
//			if (0 == strcmp(m_LD->Attribute("inst"), strName.toStdString().data()))
//			{
//				return m_LD;
//			}
//		}
//	}
//	return NULL;
//}
int ScdTree::Check_One_Receiver(TiXmlElement*ExtRef, TiXmlElement*IED, TiXmlElement*LD, QStringList &errList, QStringList &warnList, QStringList &RefList)
{
	const char* chr;
	chr = IED->Attribute("name");
	QString strIED;
	strIED += chr;
	QString IEDName;
	chr = ExtRef->Attribute("iedName");
	IEDName += chr;
	QString intAddr = ExtRef->Attribute("intAddr");
	QString str;
	QStringList strlist;
	QString strln, do_da;
	QString LnodeType;
	QMap<QString, TiXmlElement* > Ln_Map;
	strlist = intAddr.split("/");
	if (strlist.size() == 0)
	{
		QString errmes = QObject::tr("The is no receiver ");
		errList.append(errmes);
		return DO_FAIL;
	}
	str = strlist.at(1);
	int index;
	index = str.indexOf(".", 0);
	strln = str.left(index);
	do_da = str.right(str.length() - index - 1);
	TiXmlElement* LN = NULL;
	int Inst_flag = false;
	Ln_Map.clear();
	Init_LN_MAP(LD, Ln_Map);
	//TiXmlElement *m_LN = NULL;
	LN = Ln_Map.value(strln);
	if (LN == NULL)
	{
		QString errmes = QObject::tr("Error IED=%1  LDevice=%2 the Inputs of LN0 {iedname=%3 doName=%4  daName=%5 ldInst =%6 lnClass =%7 lnInst=%8 prefix=%9 intAddr=%10} the  receiver is not exist ")
			.arg(strIED).arg(QString::fromLocal8Bit(LD->Attribute("inst")))
			.arg(IEDName).arg(QString::fromLocal8Bit(ExtRef->Attribute("doName")))
			.arg(QString::fromLocal8Bit(ExtRef->Attribute("daName"))).arg(QString::fromLocal8Bit(ExtRef->Attribute("ldInst")))
			.arg(QString::fromLocal8Bit(ExtRef->Attribute("lnClass")))
			.arg(QString::fromLocal8Bit(ExtRef->Attribute("lnInst"))).arg(QString::fromLocal8Bit(ExtRef->Attribute("prefix")))
			.arg(QString::fromLocal8Bit(ExtRef->Attribute("intAddr"))).arg(QString::fromLocal8Bit(ExtRef->Attribute("iedName")));
		errList.append(errmes);
		return DO_FAIL;
	}
	LnodeType = LN->Attribute("lnType");
	for (int j = 0; j < DataMatrix_Vector.size(); j++)
	{
		if (DataMatrix_Vector[j].B_LNodeType == LnodeType)
		{
			QString st;
			st = DataMatrix_Vector[j].B_doName + "." + DataMatrix_Vector[j].B_daName;
			if (st == do_da)
			{
				Inst_flag = true;
				break;
			}
		}
	}
	if (Inst_flag == false)
	{
		QString errmes = QObject::tr("Error IED=%1  LDevice=%2 the Inputs of LN0 {iedname=%3 doName=%4  daName=%5 ldInst =%6 lnClass =%7 lnInst=%8 prefix=%9 intAddr=%10} the  receiver is not exist in DataTypeTemplates ")
			.arg(strIED).arg(QString::fromLocal8Bit(LD->Attribute("inst")))
			.arg(IEDName).arg(QString::fromLocal8Bit(ExtRef->Attribute("doName")))
			.arg(QString::fromLocal8Bit(ExtRef->Attribute("daName"))).arg(QString::fromLocal8Bit(ExtRef->Attribute("ldInst")))
			.arg(QString::fromLocal8Bit(ExtRef->Attribute("lnClass")))
			.arg(QString::fromLocal8Bit(ExtRef->Attribute("lnInst"))).arg(QString::fromLocal8Bit(ExtRef->Attribute("prefix")))
			.arg(QString::fromLocal8Bit(ExtRef->Attribute("intAddr"))).arg(QString::fromLocal8Bit(ExtRef->Attribute("iedName")));
		RefList.append(errmes);
		return DO_FAIL;
	}
	strlist = do_da.split(".");
	if (strlist.size() == 0)
	{
		QString errmes = QObject::tr("The is no receiver ");
		errList.append(errmes);
		return DO_FAIL;
	}
	TiXmlElement* child = NULL;
	child = LN->GetChildByName_Value(LN, "name", strlist.at(0).toStdString().data());
	if (child == NULL)
	{
		QString errmes = QObject::tr("Warnning IED=%1  LDevice=%2 the Inputs of LN0 {iedname=%3 doName=%4  daName=%5 ldInst =%6 lnClass =%7 lnInst=%8 prefix=%9 intAddr=%10} the  receiver is not instantiated ")
			.arg(strIED).arg(QString::fromLocal8Bit(LD->Attribute("inst")))
			.arg(IEDName).arg(QString::fromLocal8Bit(ExtRef->Attribute("doName")))
			.arg(QString::fromLocal8Bit(ExtRef->Attribute("daName"))).arg(QString::fromLocal8Bit(ExtRef->Attribute("ldInst")))
			.arg(QString::fromLocal8Bit(ExtRef->Attribute("lnClass")))
			.arg(QString::fromLocal8Bit(ExtRef->Attribute("lnInst"))).arg(QString::fromLocal8Bit(ExtRef->Attribute("prefix")))
			.arg(QString::fromLocal8Bit(ExtRef->Attribute("intAddr"))).arg(QString::fromLocal8Bit(ExtRef->Attribute("iedName")));
		warnList.append(errmes);
		return DO_FAIL;
	}
	strlist.removeAt(0);
	while (strlist.size() != 0)
	{
		child = child->GetChildByName_Value(child, "name", strlist.at(0).toStdString().data());
		if (child == NULL)
		{
			QString errmes = QObject::tr("Warnning IED=%1  LDevice=%2 the Inputs of LN0 {iedname=%3 doName=%4  daName=%5 ldInst =%6 lnClass =%7 lnInst=%8 prefix=%9 intAddr=%10} the  receiver is not instantiated ")
				.arg(strIED).arg(QString::fromLocal8Bit(LD->Attribute("inst")))
				.arg(IEDName).arg(QString::fromLocal8Bit(ExtRef->Attribute("doName")))
				.arg(QString::fromLocal8Bit(ExtRef->Attribute("daName"))).arg(QString::fromLocal8Bit(ExtRef->Attribute("ldInst")))
				.arg(QString::fromLocal8Bit(ExtRef->Attribute("lnClass")))
				.arg(QString::fromLocal8Bit(ExtRef->Attribute("lnInst"))).arg(QString::fromLocal8Bit(ExtRef->Attribute("prefix")))
				.arg(QString::fromLocal8Bit(ExtRef->Attribute("intAddr"))).arg(QString::fromLocal8Bit(ExtRef->Attribute("iedName")));
			warnList.append(errmes);
			return DO_FAIL;
		}
		strlist.removeAt(0);
	}
	return DO_OK;
}
int ScdTree::MappingSender_Check(QStringList &errList, QStringList &warnList, QStringList &RefList)
{
	TiXmlElement* m_IED = root->FirstChildElement("IED");
	for (; m_IED != NULL; m_IED = m_IED->NextSiblingElement("IED"))
	{
		TiXmlElement* m_AP = m_IED->FirstChildElement("AccessPoint");
		for (; m_AP != NULL; m_AP = m_AP->NextSiblingElement("AccessPoint"))
		{
			TiXmlElement* m_LD = m_AP->FirstChildElement("Server")->FirstChildElement("LDevice");
			for (; m_LD != NULL; m_LD = m_LD->NextSiblingElement("LDevice"))
			{
				TiXmlElement* m_LN = m_LD->FirstChildElement();
				for (; m_LN != NULL; m_LN = m_LN->NextSiblingElement())
				{
					TiXmlElement* m_Iputs = m_LN->FirstChildElement("Inputs");
					for (; m_Iputs != NULL; m_Iputs = m_Iputs->NextSiblingElement("Inputs"))
					{
						TiXmlElement* m_ExtRef = m_Iputs->FirstChildElement("ExtRef");
						for (; m_ExtRef != NULL; m_ExtRef = m_ExtRef->NextSiblingElement("ExtRef"))
						{
							Check_One_Sender(m_IED, m_LD, m_ExtRef, errList, warnList, RefList);
						}

					}
				}
			}
		}
	}
	return DO_OK;
}
int ScdTree::Check_One_Sender(TiXmlElement* ExtRef, TiXmlElement* IED, TiXmlElement* LD, QStringList &errList, QStringList &warnList, QStringList &RefList)
{
	const char* chr;
	chr = IED->Attribute("name");
	QString strIED;
	QMap<QString, TiXmlElement* > Ln_Map;
	QMap<QString, TiXmlElement* > Ld_Map;
	QMap<QString, TiXmlElement* > Ied_Map;
	strIED += chr;
	QString IEDName;
	chr = ExtRef->Attribute("iedName");
	IEDName += chr;
	QString strLD = ExtRef->Attribute("ldInst");
	DataMatrix_Struct m_dataMatrix;
	bool Inst_flag = false;
	TiXmlElement *m_ied = NULL;
	Init_IED_MAP(root, Ied_Map);
	m_ied = Ied_Map.value(IEDName);
	Init_LD_MAP(m_ied, Ld_Map);
	TiXmlElement *m_LD = Ld_Map.value(strLD);
	if (m_LD == NULL)
	{
		QString errmes = QObject::tr("Error IED=%1  LDevice=%2 the Inputs of LN0 {iedname=%3 doName=%4  daName=%5 ldInst =%6 lnClass =%7 lnInst=%8 prefix=%9 intAddr=%10} the  sender is not exist ")
			.arg(strIED).arg(QString::fromLocal8Bit(LD->Attribute("inst")))
			.arg(IEDName).arg(QString::fromLocal8Bit(ExtRef->Attribute("doName")))
			.arg(QString::fromLocal8Bit(ExtRef->Attribute("daName"))).arg(QString::fromLocal8Bit(ExtRef->Attribute("ldInst")))
			.arg(QString::fromLocal8Bit(ExtRef->Attribute("lnClass")))
			.arg(QString::fromLocal8Bit(ExtRef->Attribute("lnInst"))).arg(QString::fromLocal8Bit(ExtRef->Attribute("prefix")))
			.arg(QString::fromLocal8Bit(ExtRef->Attribute("intAddr"))).arg(QString::fromLocal8Bit(ExtRef->Attribute("iedName")));
		errList.append(errmes);
		return DO_FAIL;
	}
	Ln_Map.clear();
	Init_LN_MAP(m_LD, Ln_Map);
	TiXmlElement *m_LN = NULL;
	QString lninst;
	chr = ExtRef->Attribute("prefix");
	lninst += chr;
	chr = ExtRef->Attribute("lnClass");
	lninst += chr;
	chr = ExtRef->Attribute("lnInst");
	lninst += chr;
	lninst = lninst.simplified();
	m_LN = Ln_Map.value(lninst);
	if (m_LN == NULL)
	{
		QString errmes = QObject::tr("Error IED=%1  LDevice=%2 the Inputs of LN0 {iedname=%3 doName=%4  daName=%5 ldInst =%6 lnClass =%7 lnInst=%8 prefix=%9 intAddr=%10} the  sender is not exist ")
			.arg(strIED).arg(QString::fromLocal8Bit(LD->Attribute("inst")))
			.arg(IEDName).arg(QString::fromLocal8Bit(ExtRef->Attribute("doName")))
			.arg(QString::fromLocal8Bit(ExtRef->Attribute("daName"))).arg(QString::fromLocal8Bit(ExtRef->Attribute("ldInst")))
			.arg(QString::fromLocal8Bit(ExtRef->Attribute("lnClass")))
			.arg(QString::fromLocal8Bit(ExtRef->Attribute("lnInst"))).arg(QString::fromLocal8Bit(ExtRef->Attribute("prefix")))
			.arg(QString::fromLocal8Bit(ExtRef->Attribute("intAddr"))).arg(QString::fromLocal8Bit(ExtRef->Attribute("iedName")));
		errList.append(errmes);
		return DO_FAIL;
	}
	m_dataMatrix.B_LNodeType = m_LN->Attribute("lnType");
	m_dataMatrix.B_daName = ExtRef->Attribute("daName");
	m_dataMatrix.B_doName = ExtRef->Attribute("doName");
	for (int i = 0; i < DataMatrix_Vector.size(); i++)
	{
		if (DataMatrix_Vector[i].B_LNodeType == m_dataMatrix.B_LNodeType)
		{
			if (DataMatrix_Vector[i].B_doName == m_dataMatrix.B_doName)
			{
				if (m_dataMatrix.B_daName.isEmpty())
				{
					Inst_flag = true;
					break;
				}
				if (DataMatrix_Vector[i].B_daName == m_dataMatrix.B_daName)
				{
					Inst_flag = true;
					break;
				}
			}
		}
	}
	if (Inst_flag == false)
	{
		QString errmes = QObject::tr("Error IED=%1  LDevice=%2 the Inputs of LN0 {iedname=%3 doName=%4  daName=%5 ldInst =%6 lnClass =%7 lnInst=%8 prefix=%9 intAddr=%10} the  sender is not exist in DataTypeTemplates ")
			.arg(strIED).arg(QString::fromLocal8Bit(LD->Attribute("inst")))
			.arg(IEDName).arg(QString::fromLocal8Bit(ExtRef->Attribute("doName")))
			.arg(QString::fromLocal8Bit(ExtRef->Attribute("daName"))).arg(QString::fromLocal8Bit(ExtRef->Attribute("ldInst")))
			.arg(QString::fromLocal8Bit(ExtRef->Attribute("lnClass")))
			.arg(QString::fromLocal8Bit(ExtRef->Attribute("lnInst"))).arg(QString::fromLocal8Bit(ExtRef->Attribute("prefix")))
			.arg(QString::fromLocal8Bit(ExtRef->Attribute("intAddr"))).arg(QString::fromLocal8Bit(ExtRef->Attribute("iedName")));
		RefList.append(errmes);
		return DO_FAIL;
	}
	QString doname, daname, str;
	QStringList strlist;
	doname = ExtRef->Attribute("doName");
	daname = ExtRef->Attribute("daName");
	if (daname.isEmpty())
	{
		QString errmes = QObject::tr("Error IED=%1  LDevice=%2 the Inputs of LN0 {iedname=%3 doName=%4  daName=%5 ldInst =%6 lnClass =%7 lnInst=%8 prefix=%9 intAddr=%10} the  sender do not has Da ")
			.arg(strIED).arg(QString::fromLocal8Bit(LD->Attribute("inst")))
			.arg(IEDName).arg(QString::fromLocal8Bit(ExtRef->Attribute("doName")))
			.arg(QString::fromLocal8Bit(ExtRef->Attribute("daName"))).arg(QString::fromLocal8Bit(ExtRef->Attribute("ldInst")))
			.arg(QString::fromLocal8Bit(ExtRef->Attribute("lnClass")))
			.arg(QString::fromLocal8Bit(ExtRef->Attribute("lnInst"))).arg(QString::fromLocal8Bit(ExtRef->Attribute("prefix")))
			.arg(QString::fromLocal8Bit(ExtRef->Attribute("intAddr"))).arg(QString::fromLocal8Bit(ExtRef->Attribute("iedName")));
		errList.append(errmes);
		return DO_FAIL;
	}
	else
	{
		str = doname + "." + daname;
	}

	strlist = str.split(".");
	TiXmlElement* child = NULL;
	child = m_LN->GetChildByName_Value(m_LN, "name", strlist.at(0).toStdString().data());
	if (child == NULL)
	{
		QString errmes = QObject::tr("Warnning IED=%1  LDevice=%2 the Inputs of LN0 {iedname=%3 doName=%4  daName=%5 ldInst =%6 lnClass =%7 lnInst=%8 prefix=%9 intAddr=%10} the  sender is not instantiated ")
			.arg(strIED).arg(QString::fromLocal8Bit(LD->Attribute("inst")))
			.arg(IEDName).arg(QString::fromLocal8Bit(ExtRef->Attribute("doName")))
			.arg(QString::fromLocal8Bit(ExtRef->Attribute("daName"))).arg(QString::fromLocal8Bit(ExtRef->Attribute("ldInst")))
			.arg(QString::fromLocal8Bit(ExtRef->Attribute("lnClass")))
			.arg(QString::fromLocal8Bit(ExtRef->Attribute("lnInst"))).arg(QString::fromLocal8Bit(ExtRef->Attribute("prefix")))
			.arg(QString::fromLocal8Bit(ExtRef->Attribute("intAddr"))).arg(QString::fromLocal8Bit(ExtRef->Attribute("iedName")));
		warnList.append(errmes);
		return DO_FAIL;
	}
	strlist.removeAt(0);
	while (strlist.size() != 0)
	{
		child = child->GetChildByName_Value(child, "name", strlist.at(0).toStdString().data());
		if (child == NULL)
		{
			QString errmes = QObject::tr("Warnning IED=%1  LDevice=%2 the Inputs of LN0 {iedname=%3 doName=%4  daName=%5 ldInst =%6 lnClass =%7 lnInst=%8 prefix=%9 intAddr=%10} the  sender is not instantiated ")
				.arg(strIED).arg(QString::fromLocal8Bit(LD->Attribute("inst")))
				.arg(IEDName).arg(QString::fromLocal8Bit(ExtRef->Attribute("doName")))
				.arg(QString::fromLocal8Bit(ExtRef->Attribute("daName"))).arg(QString::fromLocal8Bit(ExtRef->Attribute("ldInst")))
				.arg(QString::fromLocal8Bit(ExtRef->Attribute("lnClass")))
				.arg(QString::fromLocal8Bit(ExtRef->Attribute("lnInst"))).arg(QString::fromLocal8Bit(ExtRef->Attribute("prefix")))
				.arg(QString::fromLocal8Bit(ExtRef->Attribute("intAddr"))).arg(QString::fromLocal8Bit(ExtRef->Attribute("iedName")));
			warnList.append(errmes);
			return DO_FAIL;
		}
		strlist.removeAt(0);
	}
	return DO_OK;
}
int ScdTree::Reference_Check(QStringList &errList, QStringList &warnList, QStringList &RefList)
{
	return DO_OK;
}
//int ScdTree::GetLNListfromAP(QString ApName, QVector<DataLN_Struct>&List)
//{
//	const char* chr;
//	QString strLd, strLn;
//	TiXmlElement* m_Element = NULL;
//	DataLN_Struct m_DAtaLn;
//	m_DAtaLn.B_AP = ApName;
//	m_Element = IEDNode->FirstChildElement("AccessPoint");
//	if (m_Element == NULL)
//	{
//		return DO_FAIL;
//	}
//	for (m_Element; m_Element != NULL; m_Element = m_Element->NextSiblingElement("AccessPoint"))
//	{
//		if (0 != strcmp(m_Element->Attribute("name"), ApName.toStdString().data()))
//		{
//			continue;
//		}
//		else
//		{
//			break;
//		}
//	}
//	m_Element = m_Element->FirstChildElement("Server")->FirstChildElement("LDevice");
//	for (; m_Element != NULL; m_Element = m_Element->NextSiblingElement("LDevice"))
//	{

//		chr = m_Element->Attribute("inst");
//		strLd.clear();
//		strLd += chr;
//		m_DAtaLn.B_LD = strLd;
//		TiXmlElement* child = NULL;
//		child = m_Element->FirstChildElement();
//		for (; child != NULL; child = child->NextSiblingElement())
//		{
//			strLn.clear();
//			chr = child->Attribute("prefix");
//			strLn += chr;
//			chr = child->Attribute("lnClass");
//			strLn += chr;
//			chr = child->Attribute("inst");
//			strLn += chr;
//			m_DAtaLn.B_LN = strLn;
//			List.append(m_DAtaLn);
//		}

//	}
//	return DO_OK;
//}
int ScdTree::CreatDataMatrix(QString LNodeType, QVector<DataMatrix_Struct>&List)
{
	TiXmlElement* m_Element = NULL;
	DataMatrix_Struct m_data;
	const char* chr;
	TiXmlElement* childDO = NULL;
	QString  strda;

	m_data.B_LNodeType = LNodeType;
	m_Element = DataTypeNode->GetChildByName_Value(DataTypeNode, "LNodeType", "id", LNodeType.toStdString().data());
	childDO = m_Element->FirstChildElement("DO");
	for (; childDO != NULL; childDO = childDO->NextSiblingElement("DO"))
	{
		QString str;
		chr = childDO->Attribute("name");
		str += chr;
		if ((str == "Beh") || (str == "Health") || (str == "NamPlt"))
		{
			continue;
		}
		CreatDataMatrix_DO(childDO, m_data, strda, List);
	}
	return DO_OK;
}
int ScdTree::CreatDataMatrix_SDO(TiXmlElement* Element, DataMatrix_Struct data, QString doName, QVector<DataMatrix_Struct>&List)
{
	TiXmlElement* m_DOType = NULL;
	TiXmlElement* childDA = NULL;
	const char* chr;
	DataMatrix_Struct m_data;
	QString strdo;

	chr = Element->Attribute("name");

	m_data = data;
	m_DOType = DataTypeNode->GetChildByName_Value(DataTypeNode, "DOType", "id", Element->Attribute("type"));
	if (m_DOType == NULL)
	{
		return DO_FAIL;
	}
	childDA = m_DOType->FirstChildElement();
	for (; childDA != NULL; childDA = childDA->NextSiblingElement())
	{
		if (0 == strcmp(childDA->Value(), "SDO"))
		{
			strdo.clear();
			strdo += doName;
			strdo += ".";
			strdo += chr;
			CreatDataMatrix_SDO(childDA, m_data, strdo, List);
		}
		else if (0 == strcmp(childDA->Value(), "DA"))
		{
			strdo.clear();
			strdo += doName;
			strdo += ".";
			strdo += chr;
			m_data.B_doName = strdo;
			CreatDataMatrix_BDA(childDA, m_data, m_data.B_daName, List);
		}
	}

	return DO_OK;
}
int ScdTree::CreatDataMatrix_BDA(TiXmlElement* eLemet, DataMatrix_Struct data, QString daName, QVector<DataMatrix_Struct>&List)
{
	const char* chr;
	DataMatrix_Struct m_data;
	QString strdo, strda, strfc;
	TiXmlElement* childBDA = NULL;
	TiXmlElement* m_DAType = NULL;

	m_data = data;
	if (eLemet->Attribute("fc") != NULL)
	{
		m_data.B_Fc = eLemet->Attribute("fc");
	}
	if (eLemet->Attribute("type") == NULL)
	{

		if (daName.isEmpty())
		{
			strda = eLemet->Attribute("name");
		}
		else
		{
			chr = eLemet->Attribute("name");
			strda = daName;
			strda += ".";
			strda += chr;
		}

		m_data.B_daName = strda;
		m_data.B_bType = eLemet->Attribute("bType");

		List.append(m_data);
		return DO_OK;

	}
	else
	if (eLemet->Attribute("type") != NULL)
	{
		m_DAType = DataTypeNode->GetChildByName_Value(DataTypeNode, "DAType", "id", eLemet->Attribute("type"));
		if (m_DAType == NULL)
		{
			if (daName.isEmpty())
			{
				strda = eLemet->Attribute("name");
			}
			else
			{
				chr = eLemet->Attribute("name");
				strda = daName;
				strda += ".";
				strda += chr;
			}

			m_data.B_daName = strda;
			m_data.B_bType = eLemet->Attribute("bType");

			List.append(m_data);
			return DO_OK;
		}
		else
		{
			childBDA = m_DAType->FirstChildElement();
			for (; childBDA != NULL; childBDA = childBDA->NextSiblingElement())
			{
				if (daName.isEmpty())
				{
					strda = eLemet->Attribute("name");
				}
				else
				{
					chr = eLemet->Attribute("name");
					strda = daName;
					strda += ".";
					strda += chr;
				}
				CreatDataMatrix_BDA(childBDA, m_data, strda, List);
			}
		}
	}

	return DO_OK;
}
int ScdTree::CreatDataMatrix_DO(TiXmlElement* Elemnet, DataMatrix_Struct data, QString doName, QVector<DataMatrix_Struct>&List)
{
	const char* chr;
	QString strdo;
	TiXmlElement* m_DOType = NULL;
	TiXmlElement*m_DA = NULL;
	DataMatrix_Struct m_data;
	m_data = data;
	chr = Elemnet->Attribute("name");
	strdo += chr;
	m_DOType = DataTypeNode->GetChildByName_Value(DataTypeNode, "DOType", "id", Elemnet->Attribute("type"));
	if (m_DOType == NULL)
	{
		return DO_FAIL;
	}
	m_DA = m_DOType->FirstChildElement();
	for (; m_DA != NULL; m_DA = m_DA->NextSiblingElement())
	{

		if (0 == strcmp(m_DA->Value(), "SDO"))
		{

			CreatDataMatrix_SDO(m_DA, m_data, strdo, List);
		}
		else if (0 == strcmp(m_DA->Value(), "DA"))
		{
			m_data.B_doName = strdo;
			CreatDataMatrix_BDA(m_DA, m_data, m_data.B_daName, List);
		}
	}

	return DO_OK;
}
int ScdTree::GetLNodeTypeList(QString str, QStringList&List)
{
	QStringList strlist;
	strlist = str.split(":");
	TiXmlElement*AP = NULL;
	TiXmlElement*LD = NULL;
	TiXmlElement*LN = NULL;
	QString strLnodetype;

	AP = IEDNode->GetChildByName_Value(IEDNode, "AccessPoint", "name", strlist.at(0).toStdString().data());
	LD = AP->FirstChildElement("Server");
	LD = LD->GetChildByName_Value(LD, "LDevice", "inst", strlist.at(1).toStdString().data());
	LN = LD->FirstChildElement();
	for (; LN != NULL; LN = LN->NextSiblingElement())
	{
		strLnodetype = LN->Attribute("lnType");
		if (strLnodetype.isEmpty())
		{
			continue;
		}
		if (!List.contains(strLnodetype))
		{
			List.append(strLnodetype);
			continue;
		}

	}
	return DO_OK;
}
int ScdTree::GetLNodeTypeList(QString ied, QString ap, QString ld, QString ln, QStringList&List)
{
	const char* chr;
	QMap<QString, TiXmlElement* > IEDMap;
	Init_IED_MAP(root, IEDMap);
	TiXmlElement* m_IED = NULL;
	m_IED = IEDMap.value(ied);
	QMap<QString, TiXmlElement* > LDMap;
	Init_LD_MAP(m_IED, LDMap);
	TiXmlElement* m_LD = NULL;
	m_LD = LDMap.value(ld);
	QMap<QString, TiXmlElement* > LNMap;
	Init_LN_MAP(m_LD, LNMap);
	TiXmlElement* m_LN = NULL;
	m_LN = LNMap.value(ln);
	QString Lntype;
	chr = m_LN->Attribute("lnType");
	Lntype += chr;
	List.append(Lntype);
	return DO_OK;
}
int ScdTree::GetLNodeTypeList(QString ied, QString ap, QString ld, QStringList lnList, QStringList&List)
{
	const char* chr;
	QMap<QString, TiXmlElement* > IEDMap;
	Init_IED_MAP(root, IEDMap);
	TiXmlElement* m_IED = NULL;
	m_IED = IEDMap.value(ied);
	QMap<QString, TiXmlElement* > LDMap;
	Init_LD_MAP(m_IED, LDMap);
	TiXmlElement* m_LD = NULL;
	m_LD = LDMap.value(ld);
	QMap<QString, TiXmlElement* > LNMap;
	Init_LN_MAP(m_LD, LNMap);
	TiXmlElement* m_LN = NULL;
	QStringList keys;

	keys = LNMap.keys();
	for (int i = 0; i < keys.size(); i++)
	{
		QString Lninist;
		m_LN = LNMap.value(keys[i]);
		chr = m_LN->Attribute("prefix");
		Lninist += chr;
		chr = m_LN->Attribute("lnClass");
		Lninist += chr;
		chr = m_LN->Attribute("inst");
		Lninist += chr;
		if (lnList.size() != 0)
		{
			for (int j = 0; j < lnList.size(); j++)
			{
				if (Lninist.contains(lnList[j], Qt::CaseInsensitive))
				{
					QString Lntype;
					chr = m_LN->Attribute("lnType");
					Lntype += chr;
					if (!List.contains(Lntype))
					{
						List.append(Lntype);
					}

				}
			}
		}
		else
		{
			QString Lntype;
			chr = m_LN->Attribute("lnType");
			Lntype += chr;
			List.append(Lntype);
		}
	}


	return DO_OK;
}
int ScdTree::GetDataInstList(QString AP_LD, QVector<FCDA_Struct>&List)
{
	QStringList strlist;
	strlist = AP_LD.split(":");
	TiXmlElement*AP = NULL;
	TiXmlElement*LD = NULL;
	TiXmlElement*LN = NULL;
	TiXmlElement* child = NULL;
	QString str;
	const char* chr;
	AP = IEDNode->GetChildByName_Value(IEDNode, "AccessPoint", "name", strlist.at(0).toStdString().data());
	LD = AP->FirstChildElement("Server");
	LD = LD->GetChildByName_Value(LD, "LDevice", "inst", strlist.at(1).toStdString().data());
	str = LD->Attribute("inst");
	LN = LD->FirstChildElement();
	for (; LN != NULL; LN = LN->NextSiblingElement())
	{
		FCDA_Struct m_data;
		m_data.B_ldInst = str.toLocal8Bit();
		chr = LN->Attribute("prefix");
		m_data.B_prefix += chr;
		chr = LN->Attribute("lnClass");
		m_data.B_lnClass += chr;
		chr = LN->Attribute("inst");
		m_data.B_lnInst += chr;
		chr = LN->Attribute("lnType");
		m_data.B_LNodeType += chr;
		child = LN->FirstChildElement("DOI");
		for (; child != NULL; child = child->NextSiblingElement("DOI"))
		{
			m_data.B_doName = child->Attribute("name");
			m_data.B_DOdesc = child->Attribute("desc");
			List.append(m_data);
			GetDataInstList_DOI(child, m_data, List);
		}
	}
	return DO_OK;
}
int ScdTree::GetDataInstList(QString ied, QString ap, QString ld, QString ln, QVector<FCDA_Struct>&List)
{
	QMap<QString, TiXmlElement* > IEDMap;
	Init_IED_MAP(root, IEDMap);
	TiXmlElement* m_IED = NULL;
	m_IED = IEDMap.value(ied);
	QMap<QString, TiXmlElement* > LDMap;
	Init_LD_MAP(m_IED, LDMap);
	TiXmlElement* m_LD = NULL;
	m_LD = LDMap.value(ld);
	QMap<QString, TiXmlElement* > LNMap;
	Init_LN_MAP(m_LD, LNMap);
	TiXmlElement* m_LN = NULL;
	m_LN = LNMap.value(ln);
	QString str;
	const char* chr;
	TiXmlElement*child = NULL;
	chr = m_LD->Attribute("inst");
	str += chr;
	FCDA_Struct m_data;
	m_data.B_ldInst = str.toLocal8Bit();
	chr = m_LN->Attribute("prefix");
	m_data.B_prefix += chr;
	chr = m_LN->Attribute("lnClass");
	m_data.B_lnClass += chr;
	chr = m_LN->Attribute("inst");
	m_data.B_lnInst += chr;
	chr = m_LN->Attribute("lnType");
	m_data.B_LNodeType += chr;
	child = m_LN->FirstChildElement("DOI");
	for (; child != NULL; child = child->NextSiblingElement("DOI"))
	{
		m_data.B_doName = child->Attribute("name");
		m_data.B_DOdesc = child->Attribute("desc");
		GetDataInstList_DOI(child, m_data, List);

	}

	return DO_OK;
}
int ScdTree::GetDataInstList_DOI(TiXmlElement*Elemnet, FCDA_Struct data, QVector<FCDA_Struct>&List)
{
	TiXmlElement *child = NULL;
	FCDA_Struct m_data;
	m_data = data;
	if (Elemnet->FirstChild() == NULL)
	{
		return DO_FAIL;
	}
	child = Elemnet->FirstChildElement();
	for (; child != NULL; child = child->NextSiblingElement())
	{
		if (0 == strcmp(child->Value(), "DAI"))
		{
			GetDataInstList_DAI(child, m_data, List);
		}
		else
		if (0 == strcmp(child->Value(), "SDI"))
		{
			GetDataInstList_SDI(child, m_data, List);
		}
	}
	return DO_OK;
}
int ScdTree::GetDataInstList_DAI(TiXmlElement* Elemnet, FCDA_Struct data, QVector<FCDA_Struct>&List)
{
	QString str;
	const char* chr;
	if (0 == strcmp(Elemnet->Attribute("name"), "dU"))
	{
		TiXmlText* m_text;
		if (Elemnet->FirstChild("Val")->FirstChild() == NULL)
		{
			data.B_daName = Elemnet->Attribute("name");
			List.append(data);
			return DO_FAIL;
		}
		m_text = Elemnet->FirstChild("Val")->FirstChild()->ToText();

		chr = m_text->Value();
		str += chr;
		data.B_dU.clear();
		data.B_dU += str;
		data.B_daName = Elemnet->Attribute("name");
		List.append(data);
		return DO_OK;
	}
	else
	{
		if (data.B_daName.isEmpty())
		{
			data.B_daName = Elemnet->Attribute("name");
		}
		else
		{
			data.B_daName += ".";
			data.B_daName += Elemnet->Attribute("name");
		}
		data.B_sAddr += Elemnet->Attribute("sAddr");
		List.append(data);
		return DO_OK;
	}
}
int ScdTree::GetDataInstList_SDI(TiXmlElement* Elemnet, FCDA_Struct data, QVector<FCDA_Struct>&List)
{
	TiXmlElement* Child = NULL;

	Child = Elemnet->FirstChildElement();

	for (; Child != NULL; Child = Child->NextSiblingElement())
	{
		FCDA_Struct m_data;
		m_data = data;
		if (0 == strcmp(Child->Value(), "SDI"))
		{
			if (m_data.B_daName.isEmpty())
			{
				m_data.B_daName = Elemnet->Attribute("name");
			}
			else
			{
				m_data.B_daName += ".";
				m_data.B_daName += Elemnet->Attribute("name");
			}
			if (Elemnet->Attribute("desc") != NULL)
			{
				m_data.B_dU += Elemnet->Attribute("desc");
			}
			GetDataInstList_SDI(Child, m_data, List);
		}
		else
		if (0 == strcmp(Child->Value(), "DAI"))
		{
			if (m_data.B_daName.isEmpty())
			{
				m_data.B_daName = Elemnet->Attribute("name");
			}
			else
			{
				m_data.B_daName += ".";
				m_data.B_daName += Elemnet->Attribute("name");
			}
			if (Elemnet->Attribute("desc") != NULL)
			{
				m_data.B_dU.clear();
				m_data.B_dU += Elemnet->Attribute("desc");
			}
			GetDataInstList_DAI(Child, m_data, List);
		}
	}
	return DO_OK;
}
int ScdTree::CheckMatching(QString strName, QVector<Input_Struct>&ErrList)
{
	QVector<DataMatrix_Struct> DataMatrix_List;
	QVector<Input_Struct> DataList;
	QStringList TypeList;

	PrepareforCheckMatching(strName, DataList);
	if (DataList.size() == 0)
	{
		return DO_OD;
	}
	for (int i = 0; i < DataList.size(); i++)
	{
		if (!TypeList.contains(DataList[i].B_InType))
		{
			TypeList.append(DataList[i].B_InType);
		}
		if (!TypeList.contains(DataList[i].B_exType))
		{
			TypeList.append(DataList[i].B_exType);
		}

	}
	for (int i = 0; i < TypeList.size(); i++)
	{
		CreatDataMatrix(TypeList[i], DataMatrix_List);
	}
	for (int j = 0; j < DataList.size(); j++)
	{
		for (int m = 0; m < DataMatrix_List.size(); m++)
		{
			if ((DataMatrix_List[m].B_LNodeType != DataList[j].B_InType) && (DataMatrix_List[m].B_LNodeType != DataList[j].B_exType))
			{
				continue;
			}
			else
			{
				QString str1, str2;
				str1 = DataMatrix_List[m].B_LNodeType;
				str2 = DataList[j].B_exType;
				if ((DataMatrix_List[m].B_LNodeType == DataList[j].B_exType))
				{

					if ((DataMatrix_List[m].B_doName == DataList[j].B_doName))
					{
						if (!DataList[j].B_daName.isEmpty())
						{
							if (DataMatrix_List[m].B_daName == DataList[j].B_daName)
							{
								DataList[j].B_ExdaType = DataMatrix_List[m].B_bType;
							}
						}
						else
						{
							if (DataList[j].B_ExdaType.isEmpty())
							{
								DataList[j].B_ExdaType = "INT32";
							}
						}
					}
				}

				else if (DataMatrix_List[m].B_LNodeType == DataList[j].B_InType)
				{
					QString str;
					str = DataMatrix_List[m].B_doName + "." + DataMatrix_List[m].B_daName;
					if (DataList[j].B_intAddr.contains(str))
					{
						DataList[j].B_IndaType = DataMatrix_List[m].B_bType;
					}
				}
			}
		}
	}
	for (int m = 0; m < DataList.size(); m++)
	{
		if (DataList[m].B_ExdaType != DataList[m].B_IndaType)
		{
			DataList[m].B_InterIED = strName;
			ErrList.append(DataList[m]);
		}
	}
	return DO_OK;
}
int ScdTree::PrepareforCheckMatching(QString strName, QVector<Input_Struct> &List)
{
	TiXmlElement* m_IED = NULL;
	std::string str = strName.toStdString();
	Input_Struct ExRef;
	m_IED = root->GetChildByName_Value(root, "IED", "name", str.data());
	if (m_IED == NULL)
	{
		return DO_FAIL;
	}
	TiXmlElement* m_AP = NULL;
	m_AP = m_IED->FirstChildElement("AccessPoint");
	for (; m_AP != NULL; m_AP = m_AP->NextSiblingElement("AccessPoint"))
	{
		TiXmlElement* m_LD = NULL;
		m_LD = m_AP->FirstChildElement("Server")->FirstChildElement("LDevice");
		QString str;
		str = m_LD->Attribute("inst");
		for (; m_LD != NULL; m_LD = m_LD->NextSiblingElement("LDevice"))
		{
			TiXmlElement* m_LN = NULL;
			m_LN = m_LD->FirstChildElement();
			for (; m_LN != NULL; m_LN = m_LN->NextSiblingElement())
			{
				TiXmlElement* m_Input = NULL;
				m_Input = m_LN->FirstChildElement("Inputs");
				for (; m_Input != NULL; m_Input = m_Input->NextSiblingElement("Inputs"))
				{
					TiXmlElement* m_ExtRef;
					m_ExtRef = m_Input->FirstChildElement("ExtRef");
					for (; m_ExtRef != NULL; m_ExtRef = m_ExtRef->NextSiblingElement("ExtRef"))
					{
						ExRef.B_iedName = m_ExtRef->Attribute("iedName");
						ExRef.B_daName = m_ExtRef->Attribute("daName");
						ExRef.B_doName = m_ExtRef->Attribute("doName");
						ExRef.B_ldInst = m_ExtRef->Attribute("ldInst");
						ExRef.B_lnClass = m_ExtRef->Attribute("lnClass");
						ExRef.B_lnInst = m_ExtRef->Attribute("lnInst");
						ExRef.B_prefix = m_ExtRef->Attribute("prefix");
						ExRef.B_intAddr = m_ExtRef->Attribute("intAddr");
						int index;
						QString str;

						index = ExRef.B_intAddr.indexOf("/");
						str = ExRef.B_intAddr.right(ExRef.B_intAddr.length() - index - 1);
						index = str.indexOf(".", 0);
						str = str.left(index);
						TiXmlElement* m_ele = GetLNodeByInst(m_LD, str);
						ExRef.B_InType = m_ele->Attribute("lnType");
						List.append(ExRef);
					}
				}



			}
		}
	}
	for (int i = 0; i < List.size(); i++)
	{
		TiXmlElement *m_ln = NULL;
		TiXmlElement *child = NULL;
		TiXmlElement* m_ele = root->GetChildByName_Value(root, "IED", "name", List[i].B_iedName.toStdString().data());
		child = m_ele->FirstChildElement("AccessPoint");
		for (; child != NULL; child = child->NextSiblingElement("AccessPoint"))
		{
			m_ln = child->FirstChildElement("Server");
			m_ele = m_ln->GetChildByName_Value(m_ln, "LDevice", "inst", List[i].B_ldInst.toStdString().data());
			m_ln = m_ele->GetChildByName_ValueS(m_ele, "prefix", List[i].B_prefix.toStdString().data(), "lnClass", List[i].B_lnClass.toStdString().data(), "inst", List[i].B_lnInst.toStdString().data());
			if (m_ln == NULL)
			{
				continue;
			}
			if (m_ln != NULL)
			{
				List[i].B_exType = m_ln->Attribute("lnType");
				break;
			}
		}
	}
	return DO_OK;
}
TiXmlElement* ScdTree::GetLNodeByInst(TiXmlElement* LDevice, QString str)
{
	TiXmlElement* LNode = NULL;
	QString inst;
	const char* ch;
	LNode = LDevice->FirstChildElement();
	for (; LNode != NULL; LNode = LNode->NextSiblingElement())
	{
		inst.clear();
		ch = LNode->Attribute("prefix");
		inst += ch;
		ch = LNode->Attribute("lnClass");
		inst += ch;
		ch = LNode->Attribute("inst");
		inst += ch;
		inst = inst.simplified();
		if (inst == str)
		{
			return LNode;
		}
	}
	return NULL;
}
void ScdTree::GetLDeviceList(QString IEDname, QStringList &List)
{
	TiXmlElement *m_IED = NULL;
	m_IED = root->GetChildByName_Value(root, "IED", "name", IEDname.toStdString().data());
	TiXmlElement *m_AP = m_IED->FirstChildElement("AccessPoint");
	for (; m_AP != NULL; m_AP = m_AP->NextSiblingElement("AccessPoint"))
	{
		QString strAP;
		strAP = m_AP->Attribute("name");
		TiXmlElement *m_LD = NULL;
		m_LD = m_AP->FirstChildElement("Server");

		for (m_LD = m_LD->FirstChildElement("LDevice"); m_LD != NULL; m_LD = m_LD->NextSiblingElement("LDevice"))
		{
			QString strLD;
			strLD = m_LD->Attribute("inst");
			QString str;
			str = strAP + ":" + strLD;
			List.append(str);
		}
	}
}
void ScdTree::GetDataSetList(QString IEDName, QString str, QVector<DataSetStruct> &List)
{
	QString strAP, strIED, strLD;
	strIED = IEDName;
	const char* chr;
	strAP = str.left(str.indexOf(":"));
	strLD = str.right(str.length() - str.indexOf(":") - 1);
	QMap<QString, TiXmlElement*>IED_Map;
	TiXmlElement *m_IED = NULL;
	QMap<QString, TiXmlElement*>LD_Map;
	TiXmlElement *m_LD = NULL;
	QMap<QString, TiXmlElement*>LN_Map;
	TiXmlElement *m_LN = NULL;
	QMap<QString, TiXmlElement*>DO_Map;
	QMap<QString, TiXmlElement*>SDI_Map;
	Init_IED_MAP(root, IED_Map);
	m_IED = IED_Map.value(strIED);
	Init_LD_MAP(m_IED, LD_Map);
	m_LD = LD_Map.value(strLD);
	Init_LN_MAP(m_LD, LN_Map);
	m_LN = LN_Map.value("LLN0");
	for (int i = 0; i < LN_Map.uniqueKeys().size(); i++)
	{
		m_LN = LN_Map.value(LN_Map.uniqueKeys().at(i));
		TiXmlElement* m_DataSet = NULL;
		for (m_DataSet = m_LN->FirstChildElement("DataSet"); m_DataSet != NULL; m_DataSet = m_DataSet->NextSiblingElement("DataSet"))
		{
			DataSetStruct m_Data;
			m_Data.DataSetName = m_DataSet->Attribute("name");
			m_Data.DataSetDesc = m_DataSet->Attribute("desc");

			TiXmlElement *m_FCDA = m_DataSet->FirstChildElement();
			for (; m_FCDA != NULL; m_FCDA = m_FCDA->NextSiblingElement())
			{
				FCDA_Struct FCDA;
				FCDA.B_daName = m_FCDA->Attribute("daName");
				FCDA.B_doName = m_FCDA->Attribute("doName");
				FCDA.B_ldInst = m_FCDA->Attribute("ldInst");
				FCDA.B_prefix = m_FCDA->Attribute("prefix");
				FCDA.B_lnInst = m_FCDA->Attribute("lnInst");
				FCDA.B_lnClass = m_FCDA->Attribute("lnClass");
				FCDA.B_fc = m_FCDA->Attribute("fc");
				m_Data.FCDA_List.append(FCDA);
			}
			List.append(m_Data);
		}
	}

	for (int i = 0; i < List.size(); i++)
	{
		for (int j = 0; j < List[i].FCDA_List.size(); j++)
		{

			m_LD = LD_Map.value(List[i].FCDA_List[j].B_ldInst);
			Init_LN_MAP(m_LD, LN_Map);
			m_LN = LN_Map.value(List[i].FCDA_List[j].B_prefix + List[i].FCDA_List[j].B_lnClass + List[i].FCDA_List[j].B_lnInst);
			Init_DO_MAP(m_LN, DO_Map);
			if (!List[i].FCDA_List[j].B_doName.contains("."))
			{
				TiXmlElement* m_DO = DO_Map.value(List[i].FCDA_List[j].B_doName);
				if (m_DO == NULL)
				{
					continue;
				}
				chr = m_DO->Attribute("desc");
				List[i].FCDA_List[j].B_DOdesc += chr;
			}
			else
			{
				QStringList strlist;
				strlist = QString::fromLatin1(List[i].FCDA_List[j].B_doName).split(".");
				TiXmlElement* m_DO = DO_Map.value(strlist.at(0));
				strlist.removeAt(0);
				chr = m_DO->Attribute("desc");
				List[i].FCDA_List[j].B_DOdesc += chr;
				Init_SDI_MAP(m_DO, SDI_Map);
				TiXmlElement* m_SDI = SDI_Map.value(strlist.at(0));
				chr = m_SDI->Attribute("desc");
				List[i].FCDA_List[j].B_DOdesc += chr;
			}
		}
	}

}
void ScdTree::GetDataSetList(QString IEDName, QString str, QVector<DataSetStruct> &List, int state)
{
	QString strAP, strIED, strLD;
	strIED = IEDName;
	//const char* chr;
	strAP = str.left(str.indexOf(":"));
	strLD = str.right(str.length() - str.indexOf(":") - 1);
	QMap<QString, TiXmlElement*>IED_Map;
	TiXmlElement *m_IED = NULL;
	QMap<QString, TiXmlElement*>LD_Map;
	TiXmlElement *m_LD = NULL;
	QMap<QString, TiXmlElement*>LN_Map;
	TiXmlElement *m_LN = NULL;
	//QMap<QString, TiXmlElement*>DO_Map;
	QMap<QString, TiXmlElement*>SDI_Map;
	Init_IED_MAP(root, IED_Map);
	m_IED = IED_Map.value(strIED);
	Init_LD_MAP(m_IED, LD_Map);
	m_LD = LD_Map.value(strLD);
	Init_LN_MAP(m_LD, LN_Map);
	//m_LN = LN_Map.value("LLN0");
	for (int i = 0; i < LN_Map.uniqueKeys().size(); i++)
	{
		m_LN = LN_Map.value(LN_Map.uniqueKeys().at(i));
		QStringList LN_List;
		QStringList Type_List;
		TiXmlElement* m_DataSet = m_LN->FirstChildElement("DataSet");
		for (; m_DataSet != NULL; m_DataSet = m_DataSet->NextSiblingElement("DataSet"))
		{
			DataSetStruct m_Data;
			m_Data.DataSetName = m_DataSet->Attribute("name");
			m_Data.DataSetDesc = m_DataSet->Attribute("desc");

			TiXmlElement *m_FCDA = m_DataSet->FirstChildElement();
			for (; m_FCDA != NULL; m_FCDA = m_FCDA->NextSiblingElement())
			{
				FCDA_Struct FCDA;

				FCDA.B_doName = m_FCDA->Attribute("doName");
				FCDA.B_ldInst = m_FCDA->Attribute("ldInst");
				FCDA.B_prefix = m_FCDA->Attribute("prefix");
				FCDA.B_lnInst = m_FCDA->Attribute("lnInst");
				FCDA.B_lnClass = m_FCDA->Attribute("lnClass");
				FCDA.B_fc = m_FCDA->Attribute("fc");
				if (FCDA.B_fc != QObject::tr("MX"))
				{
					continue;
				}
				if (m_Data.FCDA_List.contains(FCDA))
				{
					continue;
				}
				FillDataSetStruct_By_FCDA(m_LD, FCDA, m_Data);
				//m_Data.FCDA_List.append(FCDA);
				if (!LN_List.contains(FCDA.B_prefix + FCDA.B_lnClass + FCDA.B_lnInst))
				{
					LN_List.append(FCDA.B_prefix + FCDA.B_lnClass + FCDA.B_lnInst);
				}
			}
			if (m_Data.FCDA_List.size() == 0)
			{
				continue;
			}
			for (int i = 0; i < LN_List.size(); i++)
			{
				m_LN = LN_Map.value(LN_List.at(i));
				QString str1;
				str1 += m_LN->Attribute("lnType");
				Type_List.append(str1);
			}
			QVector<DataMatrix_Struct> DataMatrix;
			for (int i = 0; i < Type_List.size(); i++)
			{
				CreatDataMatrix_By_FC(Type_List.at(i), DataMatrix, "MX");
			}
			for (int i = 0; i < m_Data.FCDA_List.size(); i++)
			{
				bool flag = false;
				for (int m = 0; m < DataMatrix.size(); m++)
				{
					if ((m_Data.FCDA_List.at(i).B_doName == DataMatrix.at(m).B_doName) && (m_Data.FCDA_List.at(i).B_daName == DataMatrix.at(m).B_daName))
					{
						flag = true;
						break;
					}
				}
				if (flag == false)
				{
					m_Data.FCDA_List.remove(i);
					i--;
				}
			}
			List.append(m_Data);
		}
	}



	//	for (int i = 0; i < List.size(); i++)
	//	{
	//		int j = 0;
	//		while (j < List[i].FCDA_List.size())
	//		{
	//			TiXmlElement* m_Node = NULL;

	//			m_LD = LD_Map.value(List[i].FCDA_List[j].B_ldInst);
	//			Init_LN_MAP(m_LD, LN_Map);
	//			m_LN = LN_Map.value(List[i].FCDA_List[j].B_prefix + List[i].FCDA_List[j].B_lnClass + List[i].FCDA_List[j].B_lnInst);
	//			Init_DO_MAP(m_LN, DO_Map);
	//			if (!List[i].FCDA_List[j].B_doName.contains("."))
	//			{
	//				TiXmlElement* m_DO = DO_Map.value(List[i].FCDA_List[j].B_doName);
	//				if (m_DO == NULL)
	//				{
	//					continue;
	//				}
	//				chr = m_DO->Attribute("desc");
	//				List[i].FCDA_List[j].B_DOdesc += chr;
	//				m_Node = m_DO;
	//			}
	//			else
	//			{
	//				QStringList strlist;
	//				strlist = QString::fromLatin1(List[i].FCDA_List[j].B_doName).split(".");
	//				TiXmlElement* m_DO = DO_Map.value(strlist.at(0));
	//				strlist.removeAt(0);
	//				chr = m_DO->Attribute("desc");
	//				List[i].FCDA_List[j].B_DOdesc += chr;
	//				Init_SDI_MAP(m_DO, SDI_Map);
	//				TiXmlElement* m_SDI = SDI_Map.value(strlist.at(0));
	//				chr = m_SDI->Attribute("desc");
	//				List[i].FCDA_List[j].B_DOdesc += chr;
	//				m_Node = m_SDI;
	//			}
	//            Init_SDI_MAP(m_Node, SDI_Map);
	//            for(int m=0;m<SDI_Map.uniqueKeys().size();m++)
	//            {
	//                TiXmlElement* m_SDI = NULL;
	//                m_SDI=SDI_Map.value(SDI_Map.uniqueKeys().at(m));
	//            }
	//			if (state == 0)

	//			{

	//				Init_SDI_MAP(m_Node, SDI_Map);
	//				QStringList keys;
	//				m_Node = NULL;
	//				keys = SDI_Map.keys();
	//				for (int m = 0; m < keys.size(); m++)
	//				{
	//					if (keys[m].contains("mag", Qt::CaseInsensitive))
	//					{
	//						m_Node = SDI_Map.value(keys[m]);
	//						break;
	//					}

	//				}
	//				if (m_Node == NULL)
	//				{

	//					List[i].FCDA_List.removeAt(j);
	//					continue;
	//				}
	//				chr = m_Node->Attribute("name");
	//				List[i].FCDA_List[j].B_daName += chr;
	//				m_Node = m_Node->FirstChildElement();
	//				chr = m_Node->Attribute("name");
	//				List[i].FCDA_List[j].B_daName += ".";
	//				List[i].FCDA_List[j].B_daName += chr;
	//			}
	//			else if (state == 1)
	//{
	//	Init_DAI_MAP(m_Node, SDI_Map);
	//	QStringList keys;
	//	m_Node = NULL;
	//	keys = SDI_Map.keys();
	//	for (int m = 0; m < keys.size(); m++)
	//	{
	//		if (keys[m].contains("actVal", Qt::CaseInsensitive))
	//		{
	//			m_Node = SDI_Map.value(keys[m]);
	//			break;
	//		}

	//	}
	//	if (m_Node == NULL)
	//	{
	//		List[i].FCDA_List.removeAt(j);
	//		continue;
	//	}
	//	chr = m_Node->Attribute("name");
	//	List[i].FCDA_List[j].B_daName += chr;

	//}
	//			j++;
	//		}
	//	}

}
void ScdTree::FillDataSetStruct_By_FCDA(TiXmlElement*m_Node, FCDA_Struct m_FCDA, DataSetStruct &m_Data)
{
	QMap<QString, TiXmlElement*>LN_Map;
	QMap<QString, TiXmlElement*>Da_Map;
	TiXmlElement* m_LN = NULL;
	TiXmlElement* m_DO = NULL;
	TiXmlElement* m_Child = NULL;
	Init_LN_MAP(m_Node, LN_Map);
	QStringList DoList;
	m_LN = LN_Map.value(m_FCDA.B_prefix + m_FCDA.B_lnClass + m_FCDA.B_lnInst);
	DoList = QString::fromLatin1(m_FCDA.B_doName).split(".");
	m_DO = m_LN->GetChildByName_Value("name", DoList.at(0).toStdString().data());
	m_FCDA.B_DOdesc += m_DO->Attribute("desc");
	DoList.removeAt(0);
	if (DoList.size() != 0)
	{
		m_DO = m_DO->GetChildByName_Value("name", DoList.at(0).toStdString().data());
		m_FCDA.B_DOdesc += m_DO->Attribute("desc");
	}

	for (m_Child = m_DO->FirstChildElement(); m_Child != NULL; m_Child = m_Child->NextSiblingElement())
	{
		QString str;
		str = m_Child->Attribute("name");

		if (str.contains("sub", Qt::CaseInsensitive) || str.contains("units", Qt::CaseInsensitive)
			|| str.contains("db", Qt::CaseInsensitive) || str.contains("zeroDb", Qt::CaseInsensitive)
			|| str.contains("dU", Qt::CaseInsensitive))
		{
			continue;
		}
		Da_Map.insertMulti(str, m_Child);
	}
	for (int i = 0; i < Da_Map.uniqueKeys().size(); i++)
	{
		FillDataSetStruct_By_DO(Da_Map.value(Da_Map.uniqueKeys().at(i)), m_FCDA, m_Data);
	}

}
void ScdTree::FillDataSetStruct_By_DO(TiXmlElement*m_node, FCDA_Struct m_FCDA, DataSetStruct &m_Data)
{
	if ((m_node->FirstChild() == NULL))
	{
		QString str;
		str = m_node->Attribute("name");
		m_FCDA.B_daName += str.toLatin1();
		m_Data.FCDA_List.append(m_FCDA);
	}
	else if ((m_node->FirstChild() != NULL) && (m_node->FirstChild()->Type() != 1))
	{
		QString str;
		str = m_node->Attribute("name");
		m_FCDA.B_daName += str.toLatin1();
		if (m_FCDA.B_daName.at(m_FCDA.B_daName.length() - 1) == '.')
		{
			m_FCDA.B_daName.remove(m_FCDA.B_daName.length() - 1, 1);
		}
		m_Data.FCDA_List.append(m_FCDA);
	}
	else if ((m_node->FirstChild() != NULL) && (m_node->FirstChild()->Type() == 1) && (m_node->Attribute("name") != NULL))
	{
		QString str;
		str = m_node->Attribute("name");
		str += ".";
		m_FCDA.B_daName += str.toLatin1();
		FillDataSetStruct_By_DO(m_node->FirstChildElement(), m_FCDA, m_Data);
	}
	//else if (m_node->FirstChild()->Type() == 1)
	//{
	//	QString str;
	//	str = m_node->Attribute("name");
	//	m_FCDA.B_daName = str.toLatin1();
	//	m_Data.FCDA_List.append(m_FCDA);
	//}
	//else
	//{
	//	QString str;
	//	str = m_node->Attribute("name");
	//	str += ".";
	//	m_FCDA.B_daName = str.toLatin1();
	//	FillDataSetStruct_By_DO(m_node->FirstChildElement(), m_FCDA, m_Data);
	//}
}

void ScdTree::GetCTRLDataList(QString strIED, QString ld, QVector<DataSetStruct>&List)
{
	QString strAP, strLD;
	const char* chr;
	strAP = ld.left(ld.indexOf(":"));
	strLD = ld.right(ld.length() - ld.indexOf(":") - 1);
	QMap<QString, TiXmlElement*>IED_Map;
	TiXmlElement *m_IED = NULL;
	QMap<QString, TiXmlElement*>LD_Map;
	TiXmlElement *m_LD = NULL;
	QMap<QString, TiXmlElement*>LN_Map;
	TiXmlElement *m_LN = NULL;
	QMap<QString, TiXmlElement*>DO_Map;
	TiXmlElement *m_DO = NULL;
	QMap<QString, TiXmlElement*>LnType_Map;
	TiXmlElement *m_LnType = NULL;
	TiXmlElement *m_DoType = NULL;
	//QMap<QString, TiXmlElement*>DoType_Map;
	QMap<QString, TiXmlElement*>DAI_Map;
	QMap<QString, TiXmlElement*>Child_Map;
	TiXmlElement *m_DAI = NULL;
	TiXmlElement *Child = NULL;
	TiXmlText*m_Text = NULL;
	QChar  Qchr;
	Init_IED_MAP(root, IED_Map);
	m_IED = IED_Map.value(strIED);
	Init_LD_MAP(m_IED, LD_Map);
	m_LD = LD_Map.value(strLD);
	Init_LN_MAP(m_LD, LN_Map);

	DataSetStruct m_data;

	//chr = m_LD->Attribute("name");
	m_data.DataSetName = strLD;
	chr = m_LD->Attribute("desc");
	m_data.DataSetDesc += chr;
	m_data.Goose_state = 0;
	QStringList keys1, keys2;
	keys1 = LN_Map.keys();
	QString str, type, desc;
	Init_LNtype_MAP(root->FirstChildElement("DataTypeTemplates"), LnType_Map);
	DOType_MAP.clear();
	Init_DOType_MAP(root->FirstChildElement("DataTypeTemplates"), DOType_MAP);
	for (int i = 0; i < keys1.size(); i++)
	{
		FCDA_Struct data;
		m_LN = LN_Map.value(keys1.at(i));
		str.clear();
		str += m_LN->Attribute("lnType");
		Init_DO_MAP(m_LN, DO_Map);
		m_LnType = LnType_Map.value(str);
		Init_Child_Map(m_LnType, Child_Map, "name");
		for (int j = 0; j < DO_Map.uniqueKeys().size(); j++)
		{
			m_DO = DO_Map.value(DO_Map.uniqueKeys().at(j));
			str.clear();
			str += m_DO->Attribute("name");
			Child = Child_Map.value(str);
			if (Child == NULL)
			{
				continue;
			}
			type.clear();
			if (Child->Attribute("type") == NULL)
			{
				continue;
			}
			type += Child->Attribute("type");
			m_DoType = DOType_MAP.value(type);
			if (m_DoType == NULL)
			{
				continue;
			}
			if (m_DoType->Attribute("cdc") == NULL)
			{
				continue;
			}
			type = m_DoType->Attribute("cdc");
			if (type.contains("dpc", Qt::CaseInsensitive) || type.contains("spc", Qt::CaseInsensitive))
			{
				data.B_fc = "CO";
				data.B_doName = str.toStdString().data();
				str.clear();
				data.B_ldInst = strLD.toStdString().data();
				data.B_lnInst = keys1.at(i).toStdString().data();
				str += m_DO->Attribute("desc");
				data.B_DOdesc = str.toStdString().data();
				Init_DAI_MAP(m_DO, DAI_Map);
				m_DAI = DAI_Map.value("ctlModel");
				if (m_DAI == NULL)
				{
					continue;
				}
				Child = m_DAI->FirstChildElement();
				if (Child == NULL)
				{
					continue;
				}
				if (Child->FirstChild() == NULL)
					continue;
				m_Text = Child->FirstChild()->ToText();
				chr = m_Text->Value();
				Qchr = *chr;
				if (!Qchr.isNumber())
				{
					data.B_daName.clear();
					data.B_daName += chr;
				}
				else
				{
                    if (Qchr == '0')
					{
						data.B_daName = "status-only";
					}
                    else if (Qchr == '1')
					{
						data.B_daName = "direct-with-normal-security";
					}
                    else if (Qchr == '2')
					{
						data.B_daName = "sbo-with-normal-security";
					}
                    else if (Qchr == '3')
					{
						data.B_daName = "direct-with-enhanced-security";
					}
                    else if (Qchr == '4')
					{
						data.B_daName = "sbo-with-enhanced-security";
					}
				}
				m_data.FCDA_List.append(data);
			}
		}

	}
	if (m_data.FCDA_List.size() != 0)
	{
		List.append(m_data);
	}

	//	for (int i = 0; i < keys1.size(); i++)
	//	{
	//		//if (keys1[i].contains("LLN0", Qt::CaseInsensitive) || keys1[i].contains("LPHD", Qt::CaseInsensitive))
	//		//{
	//		//	continue;
	//		//}
	//		Child = NULL;
	//		m_Text = NULL;
	//		FCDA_Struct data;
	//		data.B_ldInst = strLD.toLocal8Bit();
	//		data.B_lnInst = keys1[i].toLocal8Bit();
	//		m_LN = LN_Map.value(keys1[i]);
	//		Init_DO_MAP(m_LN, DO_Map);
	//		keys2 = DO_Map.keys();
	//		int index = keys2.indexOf(QRegExp("Pos", Qt::CaseInsensitive));
	//		if (keys2.size() == 0)
	//		{
	//			continue;
	//		}
	//		m_DO = DO_Map.value(keys2.at(index));
	//		chr = m_DO->Attribute("desc");
	//		data.B_DOdesc += chr;
	//		data.B_doName = keys2.at(index).toLocal8Bit();
	//		data.B_fc = "CO";
	//		Init_DAI_MAP(m_DO, DAI_Map);
	//		m_DAI = DAI_Map.value("ctlModel");
	//		Child = m_DAI->FirstChildElement();
	//		if (Child->FirstChild() == NULL)
	//			continue;
	//		m_Text = Child->FirstChild()->ToText();
	//		chr = m_Text->Value();
	//		Qchr = *chr;
	//		if (!Qchr.isNumber())
	//		{
	//			data.B_daName += chr;
	//		}
	//		else
	//		{
	//			if (Qchr == "0")
	//			{
	//				data.B_daName = "status-only";
	//			}
	//			else if (Qchr == "1")
	//			{
	//				data.B_daName = "direct-with-normal-security";
	//			}
	//			else if (Qchr == "2")
	//			{
	//				data.B_daName = "sbo-with-normal-security";
	//			}
	//			else if (Qchr == "3")
	//			{
	//				data.B_daName = "direct-with-enhanced-security";
	//			}
	//			else if (Qchr == "4")
	//			{
	//				data.B_daName = "sbo-with-enhanced-security";
	//			}
	//		}
	//		m_data.FCDA_List.append(data);
	//	}
	//List.append(m_data);
}
void ScdTree::GetSGDataList(QString strIED, QString ld, QVector<DataSetStruct>&List)
{
	QString strAP, strLD;
	const char* chr;
	strAP = ld.left(ld.indexOf(":"));
	strLD = ld.right(ld.length() - ld.indexOf(":") - 1);
	QMap<QString, TiXmlElement*>IED_Map;
	TiXmlElement *m_IED = NULL;
	QMap<QString, TiXmlElement*>LD_Map;
	TiXmlElement *m_LD = NULL;
	QMap<QString, TiXmlElement*>LN_Map;
	TiXmlElement *m_LN = NULL;
	QMap<QString, TiXmlElement*>DO_Map;
	TiXmlElement *m_DO = NULL;
	QMap<QString, TiXmlElement*>LnType_Map;
	TiXmlElement *m_LnType = NULL;
	TiXmlElement *m_DoType = NULL;
	TiXmlElement *m_DaType = NULL;
	//QMap<QString, TiXmlElement*>DoType_Map;
	QMap<QString, TiXmlElement*>DA_Map;
	QMap<QString, TiXmlElement*>Child_Map;
	QMap<QString, TiXmlElement*>Child_DO;
	TiXmlElement *m_DAI = NULL;
	TiXmlElement *Child = NULL;
	TiXmlText*m_Text = NULL;
	QChar  Qchr;
	Init_IED_MAP(root, IED_Map);
	m_IED = IED_Map.value(strIED);
	Init_LD_MAP(m_IED, LD_Map);
	m_LD = LD_Map.value(strLD);
	Init_LN_MAP(m_LD, LN_Map);

	DataSetStruct m_data;

	//chr = m_LD->Attribute("name");
	m_data.DataSetName = strLD;
	chr = m_LD->Attribute("desc");
	m_data.DataSetDesc += chr;
	m_data.Goose_state = 0;
	QStringList keys1, keys2;
	keys1 = LN_Map.keys();
	QString str, type, desc, da_name;
	Init_LNtype_MAP(root->FirstChildElement("DataTypeTemplates"), LnType_Map);
	DOType_MAP.clear();
	Init_DOType_MAP(root->FirstChildElement("DataTypeTemplates"), DOType_MAP);
	DAType_MAP.clear();
	Init_DAtype_MAP(root->FirstChildElement("DataTypeTemplates"), DAType_MAP);
	int m = 0;
	while (m < DOType_MAP.uniqueKeys().size())
	{
		Init_Child_Map(DOType_MAP.value(DOType_MAP.uniqueKeys().at(m)), Child_Map, "name");
		bool flag = false;
		for (int i = 0; i < Child_Map.uniqueKeys().size(); i++)
		{
			Child = Child_Map.value(Child_Map.uniqueKeys().at(i));
			str.clear();
			str += Child->Attribute("fc");
			if (str.contains("SG", Qt::CaseInsensitive))
			{
				flag = true;
				break;
			}
		}
		if (flag == false)
		{
			DOType_MAP.remove(DOType_MAP.uniqueKeys().at(m));
			m = 0;
		}
		else
		{
			m++;
		}
	}
	m = 0;
	while (m < LnType_Map.uniqueKeys().size())
	{
		Init_Child_Map(LnType_Map.value(LnType_Map.uniqueKeys().at(m)), Child_Map, "name");
		bool flag = false;
		for (int i = 0; i < Child_Map.uniqueKeys().size(); i++)
		{
			Child = Child_Map.value(Child_Map.uniqueKeys().at(i));
			str.clear();
			str += Child->Attribute("type");
			if (DOType_MAP.uniqueKeys().contains(str))
			{
				flag = true;
				break;
			}
		}
		if (flag == false)
		{
			LnType_Map.remove(LnType_Map.uniqueKeys().at(m));
			m = 0;
		}
		else
		{
			m++;
		}
	}
	for (int i = 0; i < keys1.size(); i++)
	{

		FCDA_Struct data;
		data.B_ldInst = strLD.toStdString().data();
		data.B_lnInst = keys1.at(i).toStdString().data();
		m_LN = LN_Map.value(keys1.at(i));
		str.clear();
		str += m_LN->Attribute("lnType");
		if (!LnType_Map.uniqueKeys().contains(str))
		{
			continue;
		}
		Init_DO_MAP(m_LN, DO_Map);
		m_LnType = LnType_Map.value(str);
		Init_Child_Map(m_LnType, Child_DO, "name");
		for (int j = 0; j < DO_Map.uniqueKeys().size(); j++)
		{

			Child = Child_DO.value(DO_Map.uniqueKeys().at(j));
			if (Child == NULL)
				continue;
			type.clear();
			if (Child->Attribute("type") == NULL)
				continue;
			type += Child->Attribute("type");
			if (!DOType_MAP.uniqueKeys().contains(type))
				continue;
			data.B_doName = DO_Map.uniqueKeys().at(j).toStdString().data();
			m_DO = DO_Map.value(DO_Map.uniqueKeys().at(j));
			if (m_DO->Attribute("desc") != NULL)
			{
				str.clear();
				str += m_DO->Attribute("desc");
				data.B_DOdesc = str;
			}
			m_DoType = DOType_MAP.value(type);
			Init_Child_Map(m_DoType, Child_Map, "name");
			for (int m = 0; m < Child_Map.uniqueKeys().size(); m++)
			{
				Child = Child_Map.value(Child_Map.uniqueKeys().at(m));
				str.clear();
				str += Child->Attribute("fc");
				if (!str.contains("SG", Qt::CaseInsensitive))
					continue;

				da_name.clear();
				da_name = Child_Map.uniqueKeys().at(m);
				type.clear();
				if (Child->Attribute("type") != NULL)
				{
					type += Child->Attribute("type");

					m_DaType = DAType_MAP.value(type);
					if (m_DaType == NULL)
						continue;
					Init_Child_Map(m_DaType, DA_Map, "name");
					for (int n = 0; n < DA_Map.uniqueKeys().size(); n++)
					{
						str.clear();
						data.B_fc = "SG";
						str = da_name + "." + DA_Map.uniqueKeys().at(n);
						data.B_daName = str.toStdString().data();
						m_data.FCDA_List.append(data);
					}
				}
				else if (Child->Attribute("bType") != NULL)
				{

					data.B_fc = "SG";

					data.B_daName = da_name.toStdString().data();
					m_data.FCDA_List.append(data);
				}
				{

				}

			}

		}
	}
	if (m_data.FCDA_List.size() != 0)
	{
		List.append(m_data);
	}
}

//void ScdTree::GetSGDataList(QString strIED, QString ld, QVector<DataSetStruct>&List)
//{
//	QString strAP, strLD;
//	const char* chr;
//	strAP = ld.left(ld.indexOf(":"));
//	strLD = ld.right(ld.length() - ld.indexOf(":") - 1);
//	QMap<QString, TiXmlElement*>IED_Map;
//	TiXmlElement *m_IED = NULL;
//	QMap<QString, TiXmlElement*>LD_Map;
//	TiXmlElement *m_LD = NULL;
//	QMap<QString, TiXmlElement*>LN_Map;
//	TiXmlElement *m_LN = NULL;
//	QMap<QString, TiXmlElement*>DO_Map;
//	TiXmlElement *m_DO = NULL;
//	QMap<QString, TiXmlElement*>LnType_Map;
//	TiXmlElement *m_LnType = NULL;
//	TiXmlElement *m_DoType = NULL;
//	TiXmlElement *m_DaType = NULL;
//	//QMap<QString, TiXmlElement*>DoType_Map;
//	QMap<QString, TiXmlElement*>DAI_Map;
//	QMap<QString, TiXmlElement*>Child_Map;
//    QMap<QString, TiXmlElement*>Child_DO;
//	TiXmlElement *m_DAI = NULL;
//	TiXmlElement *Child = NULL;
//	TiXmlText*m_Text = NULL;
//	QChar  Qchr;
//	Init_IED_MAP(root, IED_Map);
//	m_IED = IED_Map.value(strIED);
//	Init_LD_MAP(m_IED, LD_Map);
//	m_LD = LD_Map.value(strLD);
//	Init_LN_MAP(m_LD, LN_Map);

//	DataSetStruct m_data;

//	//chr = m_LD->Attribute("name");
//	m_data.DataSetName = strLD;
//	chr = m_LD->Attribute("desc");
//	m_data.DataSetDesc += chr;
//	m_data.Goose_state = 0;
//	QStringList keys1, keys2;
//	keys1 = LN_Map.keys();
//	QString str, type, desc;
//	Init_LNtype_MAP(root->FirstChildElement("DataTypeTemplates"), LnType_Map);
//	DOType_MAP.clear();
//	Init_DOType_MAP(root->FirstChildElement("DataTypeTemplates"), DOType_MAP);
//	int m = 0;
//	while (m < DOType_MAP.uniqueKeys().size())
//	{
//		Init_Child_Map(DOType_MAP.value(DOType_MAP.uniqueKeys().at(m)), Child_Map, "name");
//		bool flag = false;
//		for (int i = 0; i < Child_Map.uniqueKeys().size(); i++)
//		{
//			Child = Child_Map.value(Child_Map.uniqueKeys().at(i));
//			str.clear();
//			str += Child->Attribute("fc");
//			if (str.contains("SG", Qt::CaseInsensitive))
//			{
//				flag = true;
//				break;
//			}
//		}
//		if (flag == false)
//		{
//			DOType_MAP.remove(DOType_MAP.uniqueKeys().at(m));
//			m = 0;
//		}
//		else
//		{
//			m++;
//		}
//	}
//    m=0;
//    while (m < LnType_Map.uniqueKeys().size())
//    {
//        Init_Child_Map(LnType_Map.value(LnType_Map.uniqueKeys().at(m)), Child_Map, "name");
//        bool flag = false;
//        for (int i = 0; i < Child_Map.uniqueKeys().size(); i++)
//        {
//            Child = Child_Map.value(Child_Map.uniqueKeys().at(i));
//            str.clear();
//            str += Child->Attribute("type");
//            if (DOType_MAP.uniqueKeys().contains(str))
//            {
//                flag = true;
//                break;
//            }
//        }
//        if (flag == false)
//        {
//            LnType_Map.remove(LnType_Map.uniqueKeys().at(m));
//            m = 0;
//        }
//        else
//        {
//            m++;
//        }
//    }
//	for (int i = 0; i < keys1.size(); i++)
//	{
//		FCDA_Struct data;
//		m_LN = LN_Map.value(keys1.at(i));
//		str.clear();
//		str += m_LN->Attribute("lnType");
//		if (!LnType_Map.uniqueKeys().contains(str))
//		{
//			continue;
//		}
//		Init_DO_MAP(m_LN, DO_Map);
//		m_LnType = LnType_Map.value(str);
//        Init_Child_Map(m_LnType, Child_DO, "name");
//		for (int j = 0; j < DO_Map.uniqueKeys().size(); j++)
//		{
//			m_DO = DO_Map.value(DO_Map.uniqueKeys().at(j));
//			str.clear();
//			str += m_DO->Attribute("desc");
//			data.B_DOdesc = str.toStdString().data();
//			str.clear();
//			str += m_DO->Attribute("name");
//            data.B_doName = str.toStdString().data();

//			if (!Child_DO.uniqueKeys().contains(str))
//                continue;
//			Child = Child_DO.value(str);
//			if (Child == NULL)
//			{
//				continue;
//			}
//            str.clear();
//            str += Child->Attribute("type");
//            m_DoType=DOType_MAP.value(str);
//			if (m_DoType == NULL)
//			{
//				continue;
//			}
//            str.clear();
//			if (m_DoType->Attribute("cdc")==NULL)
//			{
//				continue;
//			}
//            str += m_DoType->Attribute("cdc");
//            if(str.contains("spg",Qt::CaseInsensitive)||str.contains("ing",Qt::CaseInsensitive)||str.contains("asg",Qt::CaseInsensitive))
//            {
//              Init_Child_Map(m_DO,DAI_Map,"name");
//              Init_Child_Map(m_DoType,Child_Map,"name");
//              for(int n=0;n<DAI_Map.uniqueKeys().size();n++)
//              {
//                  if(Child_Map.uniqueKeys().contains(DAI_Map.uniqueKeys().at(n)))
//                  {
//					  Child = Child_Map.value(DAI_Map.uniqueKeys().at(n));
//					  if (Child==NULL)
//					  {
//						  continue;
//					  }
//					  str.clear();
//					  str += Child->Attribute("fc");
//					  if (str.contains("SG", Qt::CaseInsensitive))
//					  {
//						  data.B_fc = "SG";

//						  str.clear();
//						  m_DAI = DAI_Map.value(DAI_Map.uniqueKeys().at(n));
//						  str += m_DAI->Attribute("name");

//						  Child = m_DAI->FirstChildElement();
//						  while (Child != NULL)
//						  {
//							  str += ".";
//							  str += Child->Attribute("name");
//							  Child = Child->FirstChildElement();
//						  }
//						  data.B_daName = str.toStdString().data();
//						  data.B_ldInst = strLD.toStdString().data();
//						  data.B_lnInst = keys1.at(i).toStdString().data();
//						  m_data.FCDA_List.append(data);

//					  }


//                  }else
//                  {
//                      continue;
//                  }
//              }
//            }else
//            {
//                continue;
//            }
//		}
//	}
//	if (m_data.FCDA_List.size() != 0)
//	{
//		List.append(m_data);
//	}

//}

//TiXmlElement* ScdTree::GetDOByName(TiXmlElement* Node, QString doName)
//{
//	TiXmlElement* m_ele = Node;
//	QStringList strList = doName.split(".");
//	while (strList.size())
//	{
//		m_ele = m_ele->GetChildByName_Value(m_ele, "name", strList.at(0).toLocal8Bit().data());
//		if (m_ele == NULL)
//		{
//			return NULL;
//		}
//		strList.removeAt(0);
//	}
//	if (m_ele == NULL)
//	{
//		return NULL;
//	}
//	else
//	{
//		return m_ele;
//	}
//}
//int ScdTree::CheckInputReceiver(Input_Struct&m_data)
//{
//	TiXmlElement* m_ele = CurNode->FirstChildElement();
//	for (; m_ele != NULL; m_ele = m_ele->NextSiblingElement())
//	{
//		if (0 == strcmp(m_data.B_intAddr.toStdString().data(), m_ele->Attribute("intAddr")))
//		{
//			return DO_FAIL;
//		}
//	}
//	return DO_OK;
//}
int ScdTree::CheckInputReceiver(QString ied, QString ap, QString ld, QString ln, Input_Struct&m_data)
{
	QMap<QString, TiXmlElement* > IEDMap;
	Init_IED_MAP(root, IEDMap);
	TiXmlElement* m_IED = NULL;
	m_IED = IEDMap.value(ied);
	QMap<QString, TiXmlElement* > LDMap;
	Init_LD_MAP(m_IED, LDMap);
	TiXmlElement* m_LD = NULL;
	m_LD = LDMap.value(ld);
	QMap<QString, TiXmlElement* > LNMap;
	Init_LN_MAP(m_LD, LNMap);
	TiXmlElement* m_LN = NULL;
	m_LN = LNMap.value(ln);
	TiXmlElement* m_ele = m_LN->FirstChildElement("Inputs");
	if (m_ele == NULL)
	{
		return DO_OK;
	}
	m_ele = m_ele->FirstChildElement();

	for (; m_ele != NULL; m_ele = m_ele->NextSiblingElement())
	{
		if (0 == strcmp(m_data.B_intAddr.toStdString().data(), m_ele->Attribute("intAddr")))
		{
			return DO_FAIL;
		}
	}
	return DO_OK;
}
//int ScdTree::CheckInputSender(Input_Struct&m_data)
//{
//	TiXmlElement* m_ele = CurNode->FirstChildElement();
//	for (; m_ele != NULL; m_ele = m_ele->NextSiblingElement())
//	{
//		if (0 == strcmp(m_data.B_iedName.toStdString().data(), m_ele->Attribute("iedName")))
//		{
//			if (0 == strcmp(m_data.B_daName.toStdString().data(), m_ele->Attribute("daName")))
//			{
//				if (0 == strcmp(m_data.B_doName.toStdString().data(), m_ele->Attribute("doName")))
//				{
//					if (0 == strcmp(m_data.B_ldInst.toStdString().data(), m_ele->Attribute("ldInst")))
//					{
//						if (0 == strcmp(m_data.B_lnClass.toStdString().data(), m_ele->Attribute("lnClass")))
//						{
//							if (0 == strcmp(m_data.B_lnInst.toStdString().data(), m_ele->Attribute("lnInst")))
//							{
//								if (0 == strcmp(m_data.B_prefix.toStdString().data(), m_ele->Attribute("prefix")))
//								{
//									return DO_FAIL;
//								}
//								continue;
//							}
//							continue;
//						}
//						continue;
//					}
//					continue;
//				}
//				continue;
//			}
//			continue;
//		}
//		continue;
//	}
//	return DO_OK;
//}
int ScdTree::ReLoadIED(QString Name, QString File)
{
	QMap<QString, TiXmlElement*>Map;

	if (CIDDocument != NULL)
		delete CIDDocument;
	CIDDocument = new TiXmlDocument();
	if (!CIDDocument->LoadFile(File.toLocal8Bit().data()))
	{
		QString error;
		const char *ch;
		ch = CIDDocument->ErrorDesc();
		error += ch;
		int row = 0, column = 0;
		row = CIDDocument->ErrorRow();
		column = CIDDocument->ErrorCol();
		QMessageBox::information(NULL, QString("title"), QString("parse file failed at line row  %1 and column %2").arg(QString::number(row, 10)).arg(QString::number(column, 10)));

		return DO_FAIL;
	}
	//ReplaceConnectAP(Name, CIDDocument->FirstChildElement("SCL")->FirstChildElement("Communication"));
	TiXmlElement* EX_IED = CIDDocument->FirstChildElement("SCL")->FirstChildElement("IED");

	Init_IED_MAP(root, Map);
	TiXmlElement* IN_IED = Map.value(Name);
	int recode;
	recode = Compare(IN_IED, EX_IED);
	if (DO_OK == recode)
	{
		DelOneIED(Name);
		ImportCID(File, Name);
		//ImportCID(Name, CIDDocument->FirstChildElement("SCL"));
	}
	else if (DO_FAIL == recode)
	{
		return DO_FAIL;
	}
	else if (DO_OD == recode)
	{
		return DO_OD;
	}


	return DO_OK;
}
int ScdTree::Compare(TiXmlElement *IN_IED, TiXmlElement *EX_IED)
{
	QMap<QString, TiXmlElement*>DataSet_Map_EX;
	QMap<QString, TiXmlElement*>Input_Map_EX;
	QMap<QString, TiXmlElement*>ContolBlock_Map_EX;
	QMap<QString, TiXmlElement*>DataSet_Map_IN;
	QMap<QString, TiXmlElement*>Input_Map_IN;
	QMap<QString, TiXmlElement*>ContolBlock_Map_IN;
	QMap<QString, TiXmlElement*>LD_Map;
	QMap<QString, TiXmlElement*>LN_Map;
	QMap<QString, TiXmlElement*>Data_Map;
	QMap<QString, QString>DataSet_EX;
	QMap<QString, QString>DataSet_IN;

	QMap<QString, QString>Input_EX;
	QMap<QString, QString>Input_IN;

	QMap<QString, QString>ContolBlock_IN;
	QMap<QString, QString>ContolBlock_EX;
	const char *chr;
	Init_LD_MAP(IN_IED, LD_Map);
	for (int i = 0; i < LD_Map.keys().size(); i++)
	{
		Init_LN_MAP(LD_Map.value(LD_Map.keys().at(i)), LN_Map);
		for (int j = 0; j < LN_Map.keys().size(); j++)
		{
			Init_DataSet_MAP(LN_Map.value(LN_Map.keys().at(j)), DataSet_Map_IN, 0);
			//DataSet_Map_IN = Data_Map;
			Init_Input_MAP(LN_Map.value(LN_Map.keys().at(j)), Input_Map_IN, 0);
			//Input_Map_IN = Data_Map;
			Init_ControBlock_MAP(LN_Map.value(LN_Map.keys().at(j)), ContolBlock_Map_IN);
			//ContolBlock_Map_IN = Data_Map;
		}
	}
	Init_LD_MAP(EX_IED, LD_Map);
	for (int i = 0; i < LD_Map.keys().size(); i++)
	{
		Init_LN_MAP(LD_Map.value(LD_Map.keys().at(i)), LN_Map);
		for (int j = 0; j < LN_Map.keys().size(); j++)
		{
			Init_DataSet_MAP(LN_Map.value(LN_Map.keys().at(j)), DataSet_Map_EX, 0);
			Init_Input_MAP(LN_Map.value(LN_Map.keys().at(j)), Input_Map_EX, 0);
			Init_ControBlock_MAP(LN_Map.value(LN_Map.keys().at(j)), ContolBlock_Map_EX);
		}
	}
	QList<QString> List;
	List.clear();
	for (int i = 0; i < DataSet_Map_EX.keys().size(); i++)
	{

		if (!List.contains(DataSet_Map_EX.keys().at(i)))
			List.append(DataSet_Map_EX.keys().at(i));
	}
	for (int m = 0; m < List.size(); m++)
	{
		for (int n = 0; n < DataSet_Map_EX.values(List.at(m)).size(); n++)
		{
			QString str;
			chr = DataSet_Map_EX.values(List.at(m)).at(n)->Attribute("name");
			str += chr;
			DataSet_EX.insertMulti(List.at(m), str);
		}
	}
	List.clear();
	for (int i = 0; i < DataSet_Map_IN.keys().size(); i++)
	{

		if (!List.contains(DataSet_Map_IN.keys().at(i)))
			List.append(DataSet_Map_IN.keys().at(i));
	}
	for (int m = 0; m < List.size(); m++)
	{
		for (int n = 0; n < DataSet_Map_IN.values(List.at(m)).size(); n++)
		{
			QString str;
			chr = DataSet_Map_IN.values(List.at(m)).at(n)->Attribute("name");
			str += chr;
			DataSet_IN.insertMulti(List.at(m), str);
		}
	}
	List.clear();
	for (int i = 0; i < Input_Map_EX.keys().size(); i++)
	{

		if (!List.contains(Input_Map_EX.keys().at(i)))
			List.append(Input_Map_EX.keys().at(i));
	}
	for (int m = 0; m < List.size(); m++)
	{
		for (int n = 0; n < Input_Map_EX.values(List.at(m)).size(); n++)
		{
			QString str;
			str += "Inputs";
			Input_EX.insertMulti(List.at(m), str);
		}
	}
	List.clear();
	for (int i = 0; i < Input_Map_IN.keys().size(); i++)
	{

		if (!List.contains(Input_Map_IN.keys().at(i)))
			List.append(Input_Map_IN.keys().at(i));
	}
	for (int m = 0; m < List.size(); m++)
	{
		for (int n = 0; n < Input_Map_IN.values(List.at(m)).size(); n++)
		{
			QString str;
			str += "Inputs";
			Input_IN.insertMulti(List.at(m), str);
		}
	}
	List.clear();
	for (int i = 0; i < ContolBlock_Map_EX.keys().size(); i++)
	{

		if (!List.contains(ContolBlock_Map_EX.keys().at(i)))
			List.append(ContolBlock_Map_EX.keys().at(i));
	}
	for (int m = 0; m < List.size(); m++)
	{
		for (int n = 0; n < ContolBlock_Map_EX.values(List.at(m)).size(); n++)
		{
			QString str;
			chr = ContolBlock_Map_EX.values(List.at(m)).at(n)->Value();
			str += chr;
			str += ":";
			chr = ContolBlock_Map_EX.values(List.at(m)).at(n)->Attribute("name");
			str += chr;
			ContolBlock_EX.insertMulti(List.at(m), str);
		}
	}
	List.clear();
	for (int i = 0; i < ContolBlock_Map_IN.keys().size(); i++)
	{

		if (!List.contains(ContolBlock_Map_IN.keys().at(i)))
			List.append(ContolBlock_Map_IN.keys().at(i));
	}
	for (int m = 0; m < List.size(); m++)
	{
		for (int n = 0; n < ContolBlock_Map_IN.values(List.at(m)).size(); n++)
		{
			QString str;
			chr = ContolBlock_Map_IN.values(List.at(m)).at(n)->Value();
			str += chr;
			str += ":";
			chr = ContolBlock_Map_IN.values(List.at(m)).at(n)->Attribute("name");
			str += chr;
			ContolBlock_IN.insertMulti(List.at(m), str);
		}
	}
	if ((ContolBlock_IN == ContolBlock_EX) && (DataSet_IN == DataSet_EX) && (Input_IN == Input_EX))
	{
		if (0 == strcmp(IN_IED->Attribute("type"), EX_IED->Attribute("type")))
		{
			if (0 == strcmp(IN_IED->Attribute("configVersion"), EX_IED->Attribute("configVersion")))
			{
				QMessageBox::about(0, QObject::tr("Notice"), QObject::tr("The reload IED file was same with old IED\n"
					"The operation will cancel"));
				return DO_OD;
			}
		}
	}
	CompareIED *m_dlg = new CompareIED;
	m_dlg->DisplayCBLK(ContolBlock_IN, ContolBlock_EX);
	m_dlg->DisplayDataSet(DataSet_IN, DataSet_EX);
	m_dlg->DisplayInput(Input_IN, Input_EX);
	if (Input_IN.size() != 0)
	{
		m_dlg->ChangeIndex(0);
	}
	else
	{
		m_dlg->ChangeIndex(1);
	}
	bool Type_flag = false;
	if (0 == strcmp(EX_IED->Attribute("manufacturer"), IN_IED->Attribute("manufacturer")))
	{
		if (0 == strcmp(EX_IED->Attribute("type"), IN_IED->Attribute("type")))
		{
			Type_flag = true;
		}
	}
	if (Type_flag == false)
	{
		m_dlg->ChangeDispaly(1);
	}
	if (m_dlg->exec() == QDialog::Accepted)
	{
		if (Type_flag == false)
		{
			return DO_OK;
		}
		else if (Type_flag == true)
		{
			if (m_dlg->state == 1)
			{
				Input_flag = 0;
				return DO_OK;
			}
			else if (m_dlg->state == 2)
			{
				ClearInputs(EX_IED);

				//for (int i = 0; i < Input_Map_EX.uniqueKeys().size(); i++)
				//{
				//	TiXmlNode *Parent_Node = NULL;
				//	TiXmlNode *m_Node = NULL;
				//	Parent_Node = Input_Map_EX.value(Input_Map_EX.uniqueKeys().at(i))->Parent();
				//	Parent_Node->RemoveChild(Input_Map_EX.value(Input_Map_EX.uniqueKeys().at(i)));
				//	m_Node = Input_Map_IN.value(Input_Map_EX.uniqueKeys().at(i))->Clone();
				//	Parent_Node->LinkEndChild(m_Node);
				//}
				return DO_OK;
			}
			else if (m_dlg->state == 3)
			{
				ClearInputs(EX_IED);
				Input_flag = 0;
				//for (int i = 0; i < Input_Map_EX.uniqueKeys().size(); i++)
				//{
				//	TiXmlNode *Parent_Node = NULL;
				//	TiXmlNode *m_Node = NULL;
				//	Parent_Node = Input_Map_EX.value(Input_Map_EX.uniqueKeys().at(i))->Parent();
				//	Parent_Node->RemoveChild(Input_Map_EX.value(Input_Map_EX.uniqueKeys().at(i)));
				//	m_Node = Input_Map_IN.value(Input_Map_EX.uniqueKeys().at(i))->Clone();
				//	Parent_Node->LinkEndChild(m_Node);
				//}
				for (int i = 0; i < DataSet_Map_EX.uniqueKeys().size(); i++)
				{
					TiXmlNode *Parent_Node = NULL;
					TiXmlNode *m_Node = NULL;
					Parent_Node = DataSet_Map_EX.value(DataSet_Map_EX.uniqueKeys().at(i))->Parent();
					Parent_Node->RemoveChild(DataSet_Map_EX.value(DataSet_Map_EX.uniqueKeys().at(i)));
					m_Node = DataSet_Map_IN.value(DataSet_Map_EX.uniqueKeys().at(i))->Clone();
					Parent_Node->LinkEndChild(m_Node);
				}
				for (int i = 0; i < ContolBlock_Map_EX.uniqueKeys().size(); i++)
				{
					TiXmlNode *Parent_Node = NULL;
					TiXmlNode *m_Node = NULL;
					Parent_Node = ContolBlock_Map_EX.value(ContolBlock_Map_EX.uniqueKeys().at(i))->Parent();
					Parent_Node->RemoveChild(ContolBlock_Map_EX.value(ContolBlock_Map_EX.uniqueKeys().at(i)));
					m_Node = ContolBlock_Map_IN.value(ContolBlock_Map_EX.uniqueKeys().at(i))->Clone();
					Parent_Node->LinkEndChild(m_Node);
				}
				return DO_OK;
			}
			else  if (m_dlg->state == 4)
			{
				return DO_OD;
			}

		}

	}
	else
	{
		return DO_OD;
	}
	//return DO_OD;

}

int ScdTree::DelOneIED(QString Name)
{
	DelOneConnectAP(Name);
	TiXmlElement* m_IED = root->FirstChildElement("IED");
	for (; m_IED != NULL; m_IED = m_IED->NextSiblingElement("IED"))
	{
		if (0 == strcmp(Name.toStdString().data(), m_IED->Attribute("name")))
		{
			break;
		}
	}
	if (m_IED != NULL)
	{
		root->RemoveChild(m_IED);
		AutoReleaseUnuseDate();
		return DO_OK;
	}
	return DO_FAIL;
}
int ScdTree::AutoReleaseUnuseDate()
{
	QMap<QString, TiXmlElement *> Map_IED;
	QMap<QString, TiXmlElement *> Map_LD;
	QMap<QString, TiXmlElement *> Map_LN;
	QMap<QString, TiXmlElement *> Map_Child;
	Init_IED_MAP(root, Map_IED);
	QStringList LNTypeList;
	const char* chr;
	for (int i = 0; i < Map_IED.uniqueKeys().size(); i++)
	{
		Init_LD_MAP(Map_IED.value(Map_IED.uniqueKeys().at(i)), Map_LD);
		for (int m = 0; m < Map_LD.uniqueKeys().size(); m++)
		{
			Init_LN_MAP(Map_LD.value(Map_LD.uniqueKeys().at(m)), Map_LN);
			for (int n = 0; n < Map_LN.uniqueKeys().size(); n++)
			{
				chr = Map_LN.value(Map_LN.uniqueKeys().at(n))->Attribute("lnType");
				if (!LNTypeList.contains(QString::fromLocal8Bit(chr)))
				{
					LNTypeList.append(QString::fromLocal8Bit(chr));
				}

			}
		}
	}

	//TiXmlElement *M_LNType = NULL;
	//TiXmlElement *TEMP = NULL;
	QMap<QString, TiXmlElement *> Map_LNType;
	QMap<QString, TiXmlElement *> Map_DO;
	QMap<QString, TiXmlElement *> Map_DA;
	Init_LNtype_MAP(root->FirstChildElement("DataTypeTemplates"), Map_LNType);
	for (int i = 0; i < Map_LNType.uniqueKeys().size(); i++)
	{
		for (int j = 0; j < Map_LNType.values(Map_LNType.uniqueKeys().at(i)).size(); j++)
		{
			if (!LNTypeList.contains(Map_LNType.keys().at(i)))
			{
				root->FirstChildElement("DataTypeTemplates")->RemoveChild(Map_LNType.values(Map_LNType.keys().at(i)).at(j));
			}
		}

	}
	for (int u = 0; u < 2; u++)
	{
		Init_LNtype_MAP(root->FirstChildElement("DataTypeTemplates"), Map_LNType);
		Init_DOType_MAP(root->FirstChildElement("DataTypeTemplates"), Map_DO);
		for (int i = 0; i<Map_DO.uniqueKeys().size(); i++)
		{
			if (Map_DO.values(Map_DO.uniqueKeys().at(i)).size()>1)
			{
				for (int k = 1; k < Map_DO.values(Map_DO.uniqueKeys().at(i)).size(); k++)
				{
					root->FirstChildElement("DataTypeTemplates")->RemoveChild(Map_DO.values(Map_DO.uniqueKeys().at(i)).at(k));

				}
			}
		}
		Init_DOType_MAP(root->FirstChildElement("DataTypeTemplates"), Map_DO);
		QStringList DoList;
		for (int i = 0; i < Map_LNType.uniqueKeys().size(); i++)
		{
			Init_Child_Map(Map_LNType.value(Map_LNType.uniqueKeys().at(i)), Map_Child, "type");
			for (int j = 0; j < Map_Child.uniqueKeys().size(); j++)
			{
				if (!DoList.contains(Map_Child.uniqueKeys().at(j)))
				{
					DoList.append(Map_Child.uniqueKeys().at(j));
				}
			}
		}
		for (int i = 0; i < Map_DO.uniqueKeys().size(); i++)
		{
			Init_Child_Map(Map_DO.value(Map_DO.uniqueKeys().at(i)), Map_Child, "type");
			for (int j = 0; j < Map_Child.uniqueKeys().size(); j++)
			{
				if (0 == strcmp("SDO", Map_Child.value(Map_Child.uniqueKeys().at(j))->Value()))
				{
					if (!DoList.contains(Map_Child.uniqueKeys().at(j)))
					{
						DoList.append(Map_Child.uniqueKeys().at(j));
					}
				}

			}
		}
		for (int i = 0; i < Map_DO.uniqueKeys().size(); i++)
		{
			if (!DoList.contains(Map_DO.uniqueKeys().at(i)))
			{
				root->FirstChildElement("DataTypeTemplates")->RemoveChild(Map_DO.value(Map_DO.uniqueKeys().at(i)));

			}
		}


	}

	for (int u = 0; u < 2; u++)
	{
		Init_DOType_MAP(root->FirstChildElement("DataTypeTemplates"), Map_DO);
		Init_DAtype_MAP(root->FirstChildElement("DataTypeTemplates"), Map_DA);
		for (int i = 0; i<Map_DA.uniqueKeys().size(); i++)
		{
			if (Map_DA.values(Map_DA.uniqueKeys().at(i)).size()>1)
			{
				for (int k = 1; k < Map_DA.values(Map_DA.uniqueKeys().at(i)).size(); k++)
				{
					root->FirstChildElement("DataTypeTemplates")->RemoveChild(Map_DA.values(Map_DA.uniqueKeys().at(i)).at(k));

				}
			}
		}
		Init_DAtype_MAP(root->FirstChildElement("DataTypeTemplates"), Map_DA);
		QStringList DaList;
		for (int i = 0; i < Map_DO.uniqueKeys().size(); i++)
		{
			Init_Child_Map(Map_DO.value(Map_DO.uniqueKeys().at(i)), Map_Child, "type");
			for (int j = 0; j < Map_Child.uniqueKeys().size(); j++)
			{
				if (!DaList.contains(Map_Child.uniqueKeys().at(j)))
				{
					DaList.append(Map_Child.uniqueKeys().at(j));
				}
			}
		}
		for (int i = 0; i < Map_DA.uniqueKeys().size(); i++)
		{
			Init_Child_Map(Map_DA.value(Map_DA.uniqueKeys().at(i)), Map_Child, "type");
			for (int j = 0; j < Map_Child.uniqueKeys().size(); j++)
			{
				if (0 == strcmp("Struct", Map_Child.value(Map_Child.uniqueKeys().at(j))->Attribute("bType")))
				{
					if (!DaList.contains(Map_Child.uniqueKeys().at(j)))
					{
						DaList.append(Map_Child.uniqueKeys().at(j));
					}
				}

			}
		}
		for (int i = 0; i < Map_DA.uniqueKeys().size(); i++)
		{
			if (!DaList.contains(Map_DA.uniqueKeys().at(i)))
			{
				root->FirstChildElement("DataTypeTemplates")->RemoveChild(Map_DA.value(Map_DA.uniqueKeys().at(i)));

			}
		}
	}

	return DO_OK;
}
//int ScdTree::ReplaceConnectAP(QString Name, TiXmlElement *Communication_Node)
//{
//	TiXmlElement *SubNetwork = NULL;
//	TiXmlElement *ConnectedAP = NULL;
//	for (SubNetwork = Communication_Node->FirstChildElement(); SubNetwork != NULL; SubNetwork = SubNetwork->NextSiblingElement())
//	{
//		for (ConnectedAP = SubNetwork->FirstChildElement(); ConnectedAP != NULL; ConnectedAP = ConnectedAP->NextSiblingElement())

//		{
//			ConnectedAP->SetAttribute("iedName", Name.toLocal8Bit().data());
//		}
//	}
//	TiXmlElement *Communication = root->FirstChildElement("Communication");
//	for (TiXmlElement *SubNet = Communication->FirstChildElement("SubNetwork"); SubNet != NULL; SubNet = SubNet->NextSiblingElement("SubNetwork"))
//	{
//		TiXmlElement *ApNode = SubNet->FirstChildElement("ConnectedAP");
//		while (ApNode != NULL)
//		{
//			if (0 == strcmp(ApNode->Attribute("iedName"), Name.toLocal8Bit().data()))
//			{
//				SubNet->RemoveChild(ApNode);
//				ApNode = SubNet->FirstChildElement("ConnectedAP");
//			}
//			else
//			{
//				ApNode = ApNode->NextSiblingElement("ConnectedAP");
//			}
//		}
//	}
//	ADDOneAp(Communication_Node, Name);
//	return 0;
//}

int ScdTree::DelOneConnectAP(QString Name)
{
	TiXmlElement *Communication = root->FirstChildElement("Communication");
	TiXmlElement *SubNetwork = NULL;
	//TiXmlElement *ConnectedAP = NULL;
	//TiXmlElement *TEMP = NULL;
	for (SubNetwork = Communication->FirstChildElement(); SubNetwork != NULL; SubNetwork = SubNetwork->NextSiblingElement())
	{
		TiXmlElement *ApNode = SubNetwork->FirstChildElement("ConnectedAP");
		while (ApNode != NULL)
		{
			if (0 == strcmp(ApNode->Attribute("iedName"), Name.toStdString().data()))
			{
				SubNetwork->RemoveChild(ApNode);
				ApNode = SubNetwork->FirstChildElement("ConnectedAP");
			}
			else
			{
				ApNode = ApNode->NextSiblingElement("ConnectedAP");
			}
		}

	}
	return DO_OK;
}
int ScdTree::GetDataSetVector(QVector<DataSetStruct>&DataSetVector)
{
	TiXmlElement *M_LN = CurElement;
	TiXmlElement *DataSet = NULL;
	//TiXmlElement *Child = NULL;
	for (DataSet = M_LN->FirstChildElement("DataSet"); DataSet != NULL; DataSet = DataSet->NextSiblingElement("DataSet"))
	{
		DataSetStruct m_data;
		m_data.DataSetName = DataSet->Attribute("name");
		if (m_data.DataSetName.contains("dsGOOSE", Qt::CaseInsensitive))
		{
			m_data.Goose_state = 1;
		}
		else if (m_data.DataSetName.contains("dsSV", Qt::CaseInsensitive))
		{
			m_data.Goose_state = 2;
		}
		else
		{
			m_data.Goose_state = 0;
		}
		m_data.DataSetDesc = DataSet->Attribute("desc");
		DataSetVector.append(m_data);
	}
	return DO_OK;
}
int ScdTree::GetDataSetVector(QString IEDName, QVector<DataSetStruct>&DataSetVector)
{
	QMap<QString, TiXmlElement*>IED_Map;
	const char* chr;
	Init_IED_MAP(root, IED_Map);
	QStringList key1, key2;
	TiXmlElement *m_IED = IED_Map.value(IEDName);
	QMap<QString, TiXmlElement*>LD_Map;
	Init_LD_MAP(m_IED, LD_Map);
	key1 = LD_Map.keys();
	for (int i = 0; i < key1.size(); i++)
	{
		TiXmlElement *m_LD = NULL;
		m_LD = LD_Map.value(key1[i]);
		QMap<QString, TiXmlElement*>LN_Map;
		Init_LN_MAP(m_LD, LN_Map);
		key2 = LN_Map.keys();
		for (int m = 0; m < key2.size(); m++)
		{
			TiXmlElement *M_LN = LN_Map.value(key2[m]);
			TiXmlElement *DataSet = NULL;
			TiXmlElement *Child = NULL;
			for (DataSet = M_LN->FirstChildElement("DataSet"); DataSet != NULL; DataSet = DataSet->NextSiblingElement("DataSet"))
			{
				DataSetStruct m_data;
				TiXmlElement *m_Ele = NULL;
				m_data.DataSetName = DataSet->Attribute("name");
				m_data.DataSetDesc = DataSet->Attribute("desc");

				for (m_Ele = DataSet->FirstChildElement(); m_Ele != NULL; m_Ele = m_Ele->NextSiblingElement())
				{
					FCDA_Struct m_FCDA;
					chr = m_Ele->Attribute("ldInst");
					m_FCDA.B_ldInst += chr;
					chr = m_Ele->Attribute("prefix");
					m_FCDA.B_prefix += chr;
					chr = m_Ele->Attribute("lnInst");
					m_FCDA.B_lnInst += chr;
					chr = m_Ele->Attribute("lnClass");
					m_FCDA.B_lnClass += chr;
					chr = m_Ele->Attribute("doName");
					m_FCDA.B_doName += chr;
					chr = m_Ele->Attribute("daName");
					m_FCDA.B_daName += chr;
					chr = m_Ele->Attribute("fc");
					m_FCDA.B_fc += chr;
					m_data.FCDA_List.append(m_FCDA);
				}
				DataSetVector.append(m_data);
			}
			for (Child = M_LN->FirstChildElement(); Child != NULL; Child = Child->NextSiblingElement())
			{
				const char* chr;
				chr = Child->Value();
				if ((0 != strcmp("SampledValueControl", chr)) && (0 != strcmp("GSEControl", chr)))
				{
					continue;
				}
				for (int i = 0; i < DataSetVector.size(); i++)
				{
					if (0 == strcmp(Child->Attribute("datSet"), DataSetVector[i].DataSetName.toStdString().data()))
					{
						if ((0 == strcmp(Child->Value(), "GSEControl")) || (0 == strcmp(Child->Value(), "SampledValueControl")))
						{
							DataSetVector[i].Goose_state = 1;
						}
						else
						{
							DataSetVector[i].Goose_state = 0;
						}
						break;
					}
				}
			}
		}

	}

	return DO_OK;
}
int ScdTree::GetFCDAList(QVector<FCDA_Struct> &DataList, QMap<quint16, FCDA_Struct>&DataMap)
{
	FCDA_Struct m_date;
	TiXmlElement *DataSet = NULL;
	TiXmlElement *Child = NULL;
	FCDAPoint_Vector.clear();
	DataSet = CurElement;
	QString str;
	for (Child = DataSet->FirstChildElement(); Child != NULL; Child = Child->NextSiblingElement())
	{
		str.clear();
		m_date.B_daName = Child->Attribute("daName");
		str += m_date.B_daName;
		m_date.B_ldInst = Child->Attribute("ldInst");
		str += m_date.B_ldInst;
		m_date.B_prefix = Child->Attribute("prefix");
		str += m_date.B_prefix;
		m_date.B_lnClass = Child->Attribute("lnClass");
		str += m_date.B_lnClass;
		m_date.B_lnInst = Child->Attribute("lnInst");
		str += m_date.B_lnInst;
		m_date.B_doName = Child->Attribute("doName");
		str += m_date.B_doName;
		m_date.B_fc = Child->Attribute("fc");
		str += m_date.B_fc;
		QByteArray byteArray = str.toLatin1();
		DataList.append(m_date);
		WORD Crc = Crc16((byte*)byteArray.data(), str.length());
		FCDAPoint_Vector.insert(Crc, Child);
		DataMap.insert(Crc, m_date);
	}
	return DO_OK;
}
int ScdTree::DelOneData(WORD Crc)
{
	bool recode;
	TiXmlElement *m_Child = NULL;
	TiXmlElement *m_Parent = NULL;
	m_Child = FCDAPoint_Vector.value(Crc);
	m_Parent = m_Child->Parent()->ToElement();
	recode = m_Parent->RemoveChild(m_Child);
	if (recode == true)
	{
		return DO_OK;
	}
	return DO_FAIL;
}
int ScdTree::GetConnectAPList(QString str, QVector<ConnectedAP> &List)
{
	QString name;
	TiXmlElement* m_SubNet = NULL;
	m_SubNet = root->FirstChildElement("Communication")->FirstChildElement("SubNetwork");
	for (; m_SubNet != NULL; m_SubNet = m_SubNet->NextSiblingElement("SubNetwork"))
	{
		name = m_SubNet->Attribute("name");
		if (name == str)
		{
			QString type;
			type = m_SubNet->Attribute("type");
			if (type.contains("MMS", Qt::CaseInsensitive))
			{
				GetConnectAPList_MMS(m_SubNet, List);
				return DO_OK;
			}
			if (type.contains("GOOSE", Qt::CaseInsensitive))
			{
				GetConnectAPList_GOOSE(m_SubNet, List);
				return DO_OK;
			}
			if (type.contains("SMV", Qt::CaseInsensitive) || type.contains("SV", Qt::CaseInsensitive))
			{
				GetConnectAPList_SMV(m_SubNet, List);
				return DO_OK;
			}
		}

	}
	return DO_FAIL;

}

int ScdTree::GetConnectAPList_MMS(TiXmlElement *Node, QVector<ConnectedAP>&List)
{
	TiXmlElement *m_ConnectedAP = NULL;
	TiXmlElement *m_Address = NULL;
	TiXmlElement *m_GSE = NULL;
	TiXmlElement *m_SMV = NULL;
	TiXmlElement *child = NULL;
	TiXmlText *m_P = NULL;
	CurConnectAP_MAP.clear();

	for (m_ConnectedAP = Node->FirstChildElement("ConnectedAP"); m_ConnectedAP != NULL; m_ConnectedAP = m_ConnectedAP->NextSiblingElement("ConnectedAP"))
	{
		ConnectedAP m_data;

		m_data.iedName = m_ConnectedAP->Attribute("iedName");
		m_data.apName = m_ConnectedAP->Attribute("apName");
		CurConnectAP_MAP.insertMulti(m_data.iedName, m_ConnectedAP);
		m_Address = m_ConnectedAP->FirstChildElement("Address");
		if (m_Address != NULL)
		{
			for (child = m_Address->FirstChildElement("P"); child != NULL; child = child->NextSiblingElement("P"))
			{
				if (child->FirstChild() == NULL)
				{
					continue;
				}
				m_P = child->FirstChild()->ToText();
				if (0 == strcmp("OSI-AP-Title", child->Attribute("type")))
				{
					if (m_P != NULL)
					{
						m_data.iP_addr.s_AP_Title = m_P->Value();
						continue;
					}

				}
				if (0 == strcmp("OSI-AE-Qualifier", child->Attribute("type")))
				{
					if (m_P != NULL)
					{
						m_data.iP_addr.s_AE_Qualifier = m_P->Value();
						continue;
					}

				}
				if (0 == strcmp("OSI-PSEL", child->Attribute("type")))
				{
					if (m_P != NULL)
					{
						m_data.iP_addr.s_PSEL = m_P->Value();
						continue;
					}

				}
				if (0 == strcmp("OSI-SSEL", child->Attribute("type")))
				{
					if (m_P != NULL)

					{
						m_data.iP_addr.s_SSEL = m_P->Value();
						continue;
					}

				}
				if (0 == strcmp("OSI-TSEL", child->Attribute("type")))
				{
					if (m_P != NULL)
					{
						m_data.iP_addr.s_TSEL = m_P->Value();
						continue;
					}

				}
				if (0 == strcmp("IP", child->Attribute("type")))
				{
					if (m_P != NULL)
					{
						m_data.iP_addr.s_IP = m_P->Value();
						continue;
					}

				}
			}
		}
		m_GSE = m_ConnectedAP->FirstChildElement("GSE");
		for (; m_GSE != NULL; m_GSE = m_GSE->NextSiblingElement("GSE"))
		{
			m_data.Goose_addr.s_cbName = m_GSE->Attribute("cbName");
			m_data.Goose_addr.s_ldInst = m_GSE->Attribute("ldInst");
			for (child = m_GSE->FirstChildElement("Address")->FirstChildElement(); child != NULL; child = child->NextSiblingElement())
			{

				if (0 == strcmp("MAC-Address", child->Attribute("type")))
				{
					if (child->FirstChild() == NULL)
					{
						continue;
					}
					m_P = child->FirstChild()->ToText();
					if (m_P != NULL)
					{
						m_data.Goose_addr.s_MAC_addr = m_P->Value();
						continue;
					}

				}
				if (0 == strcmp("VLAN-ID", child->Attribute("type")))
				{
					if (child->FirstChild() == NULL)
					{
						continue;
					}
					m_P = child->FirstChild()->ToText();
					if (m_P != NULL)
					{
						m_data.Goose_addr.s_VLAN_ID = m_P->Value();
						continue;
					}

				}
				if (0 == strcmp("APPID", child->Attribute("type")))
				{
					if (child->FirstChild() == NULL)
					{
						continue;
					}
					m_P = child->FirstChild()->ToText();
					if (m_P != NULL)
					{
						m_data.Goose_addr.s_APPID = m_P->Value();
						continue;
					}

				}
				if (0 == strcmp("VLAN-PRIORITY", child->Attribute("type")))
				{
					if (child->FirstChild() == NULL)
					{
						continue;
					}
					m_P = child->FirstChild()->ToText();
					if (m_P != NULL)
					{
						m_data.Goose_addr.s_VLAN_PRIORITY = m_P->Value();
					}

					continue;
				}
			}
			child = m_GSE->FirstChildElement("MinTime");
			if (child != NULL)
			{

				if (child->FirstChild() == NULL)
				{
					continue;
				}
				m_P = child->FirstChild()->ToText();
				if (m_P != NULL)
				{
					m_data.Goose_addr.s_MinTime = m_P->Value();
				}

			}

			child = m_GSE->FirstChildElement("MaxTime");
			if (child != NULL)
			{

				if (child->FirstChild() == NULL)
				{
					continue;
				}
				m_P = child->FirstChild()->ToText();
				if (m_P != NULL)
				{
					m_data.Goose_addr.s_MaxTime = m_P->Value();
				}

			}

		}
		m_SMV = m_ConnectedAP->FirstChildElement("SMV");
		for (; m_SMV != NULL; m_SMV = m_SMV->FirstChildElement("SMV"))
		{

			m_data.SMV_addr.s_cbName = m_SMV->Attribute("cbName");
			m_data.SMV_addr.s_ldInst = m_SMV->Attribute("ldInst");
			for (child = m_SMV->FirstChildElement("Address")->FirstChildElement(); child != NULL; child = child->NextSiblingElement())
			{
				m_P = child->FirstChild()->ToText();
				if (0 == strcmp("MAC-Address", child->Attribute("type")))
				{
					if (m_P != NULL)
					{
						m_data.SMV_addr.s_MAC_addr = m_P->Value();
						continue;
					}

				}
				if (0 == strcmp("VLAN-ID", child->Attribute("type")))
				{
					if (m_P != NULL)
					{
						m_data.SMV_addr.s_VLAN_ID = m_P->Value();
						continue;
					}

				}
				if (0 == strcmp("APPID", child->Attribute("type")))
				{
					if (m_P != NULL)
					{
						m_data.SMV_addr.s_APPID = m_P->Value();
						continue;
					}

				}
				if (0 == strcmp("VLAN-PRIORITY", child->Attribute("type")))
				{
					if (m_P != NULL)
					{
						m_data.SMV_addr.s_VLAN_PRIORITY = m_P->Value();
						continue;
					}

				}
			}
			child = m_SMV->FirstChildElement("MinTime");
			if (child != NULL)
			{
				m_P = child->FirstChild()->ToText();
				if (m_P != NULL)
				{
					m_data.SMV_addr.s_MinTime = m_P->Value();

				}
			}

			child = m_SMV->FirstChildElement("MaxTime");
			if (child != NULL)
			{
				m_P = child->FirstChild()->ToText();
				if (m_P != NULL)
				{
					m_data.SMV_addr.s_MaxTime = m_P->Value();

				}
			}
		}
		List.append(m_data);
	}
	return DO_OK;
}
int ScdTree::GetConnectAPList_GOOSE(TiXmlElement *Node, QVector<ConnectedAP>&List)
{
	TiXmlElement *m_ConnectedAP = NULL;

	TiXmlElement *m_GSE = NULL;

	TiXmlElement *child = NULL;
	TiXmlText *m_P;
	CurConnectAP_MAP.clear();

	for (m_ConnectedAP = Node->FirstChildElement("ConnectedAP"); m_ConnectedAP != NULL; m_ConnectedAP = m_ConnectedAP->NextSiblingElement("ConnectedAP"))
	{

		m_GSE = m_ConnectedAP->FirstChildElement("GSE");
		for (; m_GSE != NULL; m_GSE = m_GSE->NextSiblingElement("GSE"))
		{
			ConnectedAP m_data;
			m_data.iedName = m_ConnectedAP->Attribute("iedName");
			CurConnectAP_MAP.insertMulti(m_data.iedName, m_ConnectedAP);
			m_data.iedName = m_ConnectedAP->Attribute("iedName");
			m_data.apName = m_ConnectedAP->Attribute("apName");
			m_data.Goose_addr.s_cbName = m_GSE->Attribute("cbName");
			m_data.Goose_addr.s_ldInst = m_GSE->Attribute("ldInst");
			for (child = m_GSE->FirstChildElement("Address")->FirstChildElement(); child != NULL; child = child->NextSiblingElement())
			{
				if (child->FirstChild() == NULL)
				{
					continue;
				}
				m_P = child->FirstChild()->ToText();
				if (0 == strcmp("MAC-Address", child->Attribute("type")))
				{

					m_data.Goose_addr.s_MAC_addr = m_P->Value();
					continue;
				}
				if (0 == strcmp("VLAN-ID", child->Attribute("type")))
				{

					m_data.Goose_addr.s_VLAN_ID = m_P->Value();
					continue;
				}
				if (0 == strcmp("APPID", child->Attribute("type")))
				{

					m_data.Goose_addr.s_APPID = m_P->Value();
					continue;
				}
				if (0 == strcmp("VLAN-PRIORITY", child->Attribute("type")))
				{

					m_data.Goose_addr.s_VLAN_PRIORITY = m_P->Value();
					continue;
				}
			}
			child = m_GSE->FirstChildElement("MinTime");
			if (child != NULL)
			{
				m_P = child->FirstChild()->ToText();
				m_data.Goose_addr.s_MinTime = m_P->Value();
			}

			child = m_GSE->FirstChildElement("MaxTime");
			if (child != NULL)
			{
				m_P = child->FirstChild()->ToText();
				m_data.Goose_addr.s_MaxTime = m_P->Value();
			}
			List.append(m_data);
		}


	}
	return DO_OK;
}
int ScdTree::GetConnectAPList_SMV(TiXmlElement *Node, QVector<ConnectedAP>&List)
{
	TiXmlElement *m_ConnectedAP = NULL;

	TiXmlElement *m_SMV = NULL;
	TiXmlElement *child = NULL;
	TiXmlText *m_P = NULL;
	CurConnectAP_MAP.clear();

	for (m_ConnectedAP = Node->FirstChildElement("ConnectedAP"); m_ConnectedAP != NULL; m_ConnectedAP = m_ConnectedAP->NextSiblingElement("ConnectedAP"))
	{

		for (m_SMV = m_ConnectedAP->FirstChildElement("SMV"); m_SMV != NULL; m_SMV = m_SMV->NextSiblingElement("SMV"))
		{
			ConnectedAP m_data;
			m_data.iedName = m_ConnectedAP->Attribute("iedName");
			CurConnectAP_MAP.insertMulti(m_data.iedName, m_ConnectedAP);
			m_data.iedName = m_ConnectedAP->Attribute("iedName");
			m_data.apName = m_ConnectedAP->Attribute("apName");

			m_data.SMV_addr.s_cbName = m_SMV->Attribute("cbName");
			m_data.SMV_addr.s_ldInst = m_SMV->Attribute("ldInst");
			for (child = m_SMV->FirstChildElement("Address")->FirstChildElement(); child != NULL; child = child->NextSiblingElement())
			{
				if (child->FirstChild() == NULL)
				{
					continue;
				}
				m_P = child->FirstChild()->ToText();
				if (0 == strcmp("MAC-Address", child->Attribute("type")))
				{

					m_data.SMV_addr.s_MAC_addr = m_P->Value();
					continue;
				}
				if (0 == strcmp("VLAN-ID", child->Attribute("type")))
				{

					m_data.SMV_addr.s_VLAN_ID = m_P->Value();
					continue;
				}
				if (0 == strcmp("APPID", child->Attribute("type")))
				{

					m_data.SMV_addr.s_APPID = m_P->Value();
					continue;
				}
				if (0 == strcmp("VLAN-PRIORITY", child->Attribute("type")))
				{

					m_data.SMV_addr.s_VLAN_PRIORITY = m_P->Value();
					continue;
				}
			}
			child = m_SMV->FirstChildElement("MinTime");
			if (child != NULL)
			{
				m_P = child->FirstChild()->ToText();
				m_data.SMV_addr.s_MinTime = m_P->Value();
			}

			child = m_SMV->FirstChildElement("MaxTime");
			if (child != NULL)
			{
				m_P = child->FirstChild()->ToText();
				m_data.SMV_addr.s_MaxTime = m_P->Value();
			}
			List.append(m_data);
		}

	}
	return DO_OK;
}
int ScdTree::UpdateConnectAPMMS(QString node, ConnectedAP &data, int state)
{
	TiXmlElement *m_ConnectedAP = NULL;
	TiXmlElement *m_Address = NULL;
	//TiXmlElement *m_GSE = NULL;
	//TiXmlElement *child = NULL;
	TiXmlElement *m_P = NULL;
	TiXmlText *m_Text = NULL;
	QMap<QString, TiXmlElement*> P_Map;
	for (int i = 0; i < CurConnectAP_MAP.values(node).size(); i++)
	{
		if (0 == strcmp(CurConnectAP_MAP.values(node).at(i)->Attribute("apName"), data.apName.toLocal8Bit().data()))
		{
			m_ConnectedAP = CurConnectAP_MAP.values(node).at(i);
		}
	}
	//m_ConnectedAP = CurConnectAP_MAP.value(node);
	if (m_ConnectedAP == NULL)
	{
		return DO_FAIL;
	}
	m_Address = m_ConnectedAP->FirstChildElement("Address");
	if (m_Address == NULL)
	{
		return DO_FAIL;
	}
	Init_P_Map(m_Address, P_Map, 0);
	m_P = P_Map.value("IP");
	if (m_P != NULL)
	{
		m_Text = m_P->FirstChild()->ToText();
		m_Text->SetValue(data.iP_addr.s_IP.toStdString().data());
	}
	else
	{
		m_P = new TiXmlElement("P");
		m_P->SetAttribute("type", "IP");
		m_Text = new TiXmlText(data.iP_addr.s_IP.toStdString().data());
		m_P->LinkEndChild(m_Text);
		m_Address->LinkEndChild(m_P);
	}
	m_P = P_Map.value("OSI-PSEL");
	if (m_P != NULL)
	{

		if (m_P->FirstChild() != NULL)
		{
			m_Text = m_P->FirstChild()->ToText();
			m_Text->SetValue(data.iP_addr.s_PSEL.toStdString().data());
		}
		else
		{
			m_Text = new TiXmlText(data.iP_addr.s_PSEL.toStdString().data());
			m_P->LinkEndChild(m_Text);
		}

	}
	else
	{
		m_P = new TiXmlElement("P");
		m_P->SetAttribute("type", "OSI-PSEL");
		m_Text = new TiXmlText(data.iP_addr.s_PSEL.toStdString().data());
		m_P->LinkEndChild(m_Text);
		m_Address->LinkEndChild(m_P);
	}
	m_P = P_Map.value("OSI-SSEL");
	if (m_P != NULL)
	{
		//m_Text = m_P->FirstChild()->ToText();
		//m_Text->SetValue(data.iP_addr.s_SSEL.toStdString().data());
		if (m_P->FirstChild() != NULL)
		{
			m_Text = m_P->FirstChild()->ToText();
			m_Text->SetValue(data.iP_addr.s_SSEL.toStdString().data());
		}
		else
		{
			m_Text = new TiXmlText(data.iP_addr.s_SSEL.toStdString().data());
			m_P->LinkEndChild(m_Text);
		}
	}
	else
	{
		m_P = new TiXmlElement("P");
		m_P->SetAttribute("type", "OSI-SSEL");
		m_Text = new TiXmlText(data.iP_addr.s_SSEL.toStdString().data());
		m_P->LinkEndChild(m_Text);
		m_Address->LinkEndChild(m_P);
	}
	m_P = P_Map.value("OSI-TSEL");
	if (m_P != NULL)
	{
		//m_Text = m_P->FirstChild()->ToText();
		//m_Text->SetValue(data.iP_addr.s_TSEL.toStdString().data());
		if (m_P->FirstChild() != NULL)
		{
			m_Text = m_P->FirstChild()->ToText();
			m_Text->SetValue(data.iP_addr.s_TSEL.toStdString().data());
		}
		else
		{
			m_Text = new TiXmlText(data.iP_addr.s_TSEL.toStdString().data());
			m_P->LinkEndChild(m_Text);
		}
	}
	else
	{
		m_P = new TiXmlElement("P");
		m_P->SetAttribute("type", "OSI-TSEL");
		m_Text = new TiXmlText(data.iP_addr.s_TSEL.toStdString().data());
		m_P->LinkEndChild(m_Text);
		m_Address->LinkEndChild(m_P);
	}
	m_P = P_Map.value("OSI-AP-Title");
	if (m_P != NULL)
	{
		//m_Text = m_P->FirstChild()->ToText();
		//m_Text->SetValue(data.iP_addr.s_AP_Title.toStdString().data());
		if (m_P->FirstChild() != NULL)
		{
			m_Text = m_P->FirstChild()->ToText();
			m_Text->SetValue(data.iP_addr.s_AP_Title.toStdString().data());
		}
		else
		{
			m_Text = new TiXmlText(data.iP_addr.s_AP_Title.toStdString().data());
			m_P->LinkEndChild(m_Text);
		}
	}
	else
	{
		m_P = new TiXmlElement("P");
		m_P->SetAttribute("type", "OSI-AP-Title");
		m_Text = new TiXmlText(data.iP_addr.s_AP_Title.toStdString().data());
		m_P->LinkEndChild(m_Text);
		m_Address->LinkEndChild(m_P);
	}
	m_P = P_Map.value("OSI-AE-Qualifier");
	if (m_P != NULL)
	{
		//m_Text = m_P->FirstChild()->ToText();
		//m_Text->SetValue(data.iP_addr.s_AE_Qualifier.toStdString().data());
		if (m_P->FirstChild() != NULL)
		{
			m_Text = m_P->FirstChild()->ToText();
			m_Text->SetValue(data.iP_addr.s_AE_Qualifier.toStdString().data());
		}
		else
		{
			m_Text = new TiXmlText(data.iP_addr.s_AE_Qualifier.toStdString().data());
			m_P->LinkEndChild(m_Text);
		}
	}
	else
	{
		m_P = new TiXmlElement("P");
		m_P->SetAttribute("type", "OSI-AE-Qualifier");
		m_Text = new TiXmlText(data.iP_addr.s_AE_Qualifier.toStdString().data());
		m_P->LinkEndChild(m_Text);
		m_Address->LinkEndChild(m_P);
	}
	//if ((state == MMSNETPARA_WITH) || (state == MMSNETPARA_WITHOUT))
	//{
	//	m_Address = m_ConnectedAP->FirstChildElement("Address");
	//	for (child = m_Address->FirstChildElement(); child != NULL; child = child->NextSiblingElement())
	//	{
	//		if (0 == strcmp(child->Attribute("type"), "IP"))
	//		{
	//			m_P = child->FirstChild()->ToText();
	//			m_P->SetValue(data.iP_addr.s_IP.toStdString().data());
	//		}
	//		if (0 == strcmp(child->Attribute("type"), "OSI-PSEL"))
	//		{
	//			m_P = child->FirstChild()->ToText();
	//			m_P->SetValue(data.iP_addr.s_PSEL.toStdString().data());
	//		}
	//		if (0 == strcmp(child->Attribute("type"), "OSI-SSEL"))
	//		{
	//			m_P = child->FirstChild()->ToText();
	//			m_P->SetValue(data.iP_addr.s_SSEL.toStdString().data());
	//		}
	//		if (0 == strcmp(child->Attribute("type"), "OSI-TSEL"))
	//		{
	//			m_P = child->FirstChild()->ToText();
	//			m_P->SetValue(data.iP_addr.s_TSEL.toStdString().data());
	//		}
	//		if (0 == strcmp(child->Attribute("type"), "OSI-AP-Title"))
	//		{
	//			m_P = child->FirstChild()->ToText();
	//			m_P->SetValue(data.iP_addr.s_AP_Title.toStdString().data());
	//		}
	//		if (0 == strcmp(child->Attribute("type"), "OSI-AE-Qualifier"))
	//		{
	//			m_P = child->FirstChild()->ToText();
	//			m_P->SetValue(data.iP_addr.s_AE_Qualifier.toStdString().data());
	//		}
	//	}

	//}
	//if (state == MMSNETPARA_WITH)
	//{
	//	TiXmlElement *m_GSE = m_ConnectedAP->FirstChildElement("GSE");
	//	if (m_GSE == NULL)
	//	{
	//		return DO_OK;
	//	}
	//	m_GSE = m_GSE->FirstChildElement("Address");
	//	for (child = m_GSE->FirstChildElement(); child != NULL; child = child->NextSiblingElement())
	//	{
	//		if (0 == strcmp(child->Attribute("type"), "MAC-Address"))
	//		{
	//			m_P = child->FirstChild()->ToText();
	//			m_P->SetValue(data.Goose_addr.s_MAC_addr.toStdString().data());
	//		}
	//		if (0 == strcmp(child->Attribute("type"), "VLAN-ID"))
	//		{
	//			m_P = child->FirstChild()->ToText();
	//			m_P->SetValue(data.Goose_addr.s_VLAN_ID.toStdString().data());
	//		}
	//		if (0 == strcmp(child->Attribute("type"), "APPID"))
	//		{
	//			m_P = child->FirstChild()->ToText();
	//			m_P->SetValue(data.Goose_addr.s_APPID.toStdString().data());
	//		}
	//		if (0 == strcmp(child->Attribute("type"), "VLAN-PRIORITY"))
	//		{
	//			m_P = child->FirstChild()->ToText();
	//			m_P->SetValue(data.Goose_addr.s_VLAN_PRIORITY.toStdString().data());
	//		}
	//	}
	//	child = m_GSE->FirstChildElement("MinTime");
	//	if (child != NULL)
	//	{
	//		m_P = child->FirstChild()->ToText();
	//		m_P->SetValue(data.Goose_addr.s_MinTime.toStdString().data());
	//	}
	//	child = m_GSE->FirstChildElement("MaxTime");
	//	if (child != NULL)
	//	{
	//		m_P = child->FirstChild()->ToText();
	//		m_P->SetValue(data.Goose_addr.s_MaxTime.toStdString().data());
	//	}
	//}
	return DO_OK;
}
int ScdTree::UpdateConnectAPGOOSE(QString node, ConnectedAP &data)
{
	TiXmlElement *m_ConnectedAP = NULL;
	TiXmlElement *m_Address = NULL;
	TiXmlElement *m_GSE = NULL;
	TiXmlElement *child = NULL;
	TiXmlText *m_P = NULL;
	m_ConnectedAP = CurConnectAP_MAP.value(node);
	if (m_ConnectedAP == NULL)
	{
		return DO_FAIL;
	}


	for (m_GSE = m_ConnectedAP->FirstChildElement("GSE"); m_GSE != NULL; m_GSE = m_GSE->NextSiblingElement("GSE"))
	{
		if (0 == strcmp(data.Goose_addr.s_cbName.toLocal8Bit().data(), m_GSE->Attribute("cbName")))
		{
			if (0 == strcmp(data.Goose_addr.s_ldInst.toLocal8Bit().data(), m_GSE->Attribute("ldInst")))
			{

				m_Address = m_GSE->FirstChildElement("Address");
				for (child = m_Address->FirstChildElement(); child != NULL; child = child->NextSiblingElement())
				{
					if (0 == strcmp(child->Attribute("type"), "MAC-Address"))
					{
						if (child->FirstChild() != NULL)
						{
							m_P = child->FirstChild()->ToText();
							m_P->SetValue(data.Goose_addr.s_MAC_addr.toStdString().data());
						}
						else
						{
							m_P = new TiXmlText(data.Goose_addr.s_MAC_addr.toStdString().data());
							child->LinkEndChild(m_P);
						}

					}
					if (0 == strcmp(child->Attribute("type"), "VLAN-ID"))
					{
						if (child->FirstChild() != NULL)
						{
							m_P = child->FirstChild()->ToText();
							m_P->SetValue(data.Goose_addr.s_VLAN_ID.toStdString().data());
						}
						else
						{
							m_P = new TiXmlText(data.Goose_addr.s_VLAN_ID.toStdString().data());
							child->LinkEndChild(m_P);
						}

					}
					if (0 == strcmp(child->Attribute("type"), "APPID"))
					{
						if (child->FirstChild() != NULL)
						{
							m_P = child->FirstChild()->ToText();
							m_P->SetValue(data.Goose_addr.s_APPID.toStdString().data());
						}
						else
						{
							m_P = new TiXmlText(data.Goose_addr.s_APPID.toStdString().data());
							child->LinkEndChild(m_P);
						}

					}
					if (0 == strcmp(child->Attribute("type"), "VLAN-PRIORITY"))
					{
						if (child->FirstChild() != NULL)
						{
							m_P = child->FirstChild()->ToText();
							m_P->SetValue(data.Goose_addr.s_VLAN_PRIORITY.toStdString().data());
						}
						else
						{
							m_P = new TiXmlText(data.Goose_addr.s_VLAN_PRIORITY.toStdString().data());
							child->LinkEndChild(m_P);
						}

					}
				}
				child = m_GSE->FirstChildElement("MinTime");
				if (child != NULL)
				{
					if (child->FirstChild() != NULL)
					{
						m_P = child->FirstChild()->ToText();
						m_P->SetValue(data.Goose_addr.s_MinTime.toStdString().data());
					}
					else
					{
						m_P = new TiXmlText(data.Goose_addr.s_MinTime.toStdString().data());
						child->LinkEndChild(m_P);
					}

				}
				child = m_GSE->FirstChildElement("MaxTime");
				if (child != NULL)
				{
					if (child->FirstChild() != NULL)
					{
						m_P = child->FirstChild()->ToText();
						m_P->SetValue(data.Goose_addr.s_MaxTime.toStdString().data());
					}
					else
					{
						m_P = new TiXmlText(data.Goose_addr.s_MaxTime.toStdString().data());
						child->LinkEndChild(m_P);
					}

				}
				return DO_OK;
			}
		}
	}
	return DO_FAIL;
}
int ScdTree::UpdateConnectAPSMV(QString node, ConnectedAP &data)
{
	TiXmlElement *m_ConnectedAP = NULL;
	TiXmlElement *m_Address = NULL;
	TiXmlElement *m_SMV = NULL;
	TiXmlElement *child = NULL;
	TiXmlText *m_P = NULL;
	m_ConnectedAP = CurConnectAP_MAP.value(node);
	m_SMV = m_ConnectedAP->FirstChildElement("SMV");
	if (m_SMV == NULL)
	{
		return DO_FAIL;
	}
	for (; m_SMV != NULL; m_SMV = m_SMV->NextSiblingElement("SMV"))
	{
		if (0 == strcmp(data.SMV_addr.s_cbName.toLocal8Bit().data(), m_SMV->Attribute("cbName")))
		{
			m_Address = m_SMV->FirstChildElement("Address");
			if (m_Address == NULL)
			{
				continue;
			}
			for (child = m_Address->FirstChildElement(); child != NULL; child = child->NextSiblingElement())
			{
				if (0 == strcmp(child->Attribute("type"), "MAC-Address"))
				{
					if (child->FirstChild() != NULL)
					{
						m_P = child->FirstChild()->ToText();
						m_P->SetValue(data.SMV_addr.s_MAC_addr.toStdString().data());
					}
					else
					{
						m_P = new TiXmlText(data.SMV_addr.s_MAC_addr.toStdString().data());
						child->LinkEndChild(m_P);
					}


				}
				if (0 == strcmp(child->Attribute("type"), "VLAN-ID"))
				{
					if (child->FirstChild() != NULL)
					{
						m_P = child->FirstChild()->ToText();
						m_P->SetValue(data.SMV_addr.s_VLAN_ID.toStdString().data());
					}
					else
					{
						m_P = new TiXmlText(data.SMV_addr.s_VLAN_ID.toStdString().data());
						child->LinkEndChild(m_P);
					}

				}
				if (0 == strcmp(child->Attribute("type"), "APPID"))
				{
					if (child->FirstChild() != NULL)
					{
						m_P = child->FirstChild()->ToText();
						m_P->SetValue(data.SMV_addr.s_APPID.toStdString().data());
					}
					else
					{
						m_P = new TiXmlText(data.SMV_addr.s_APPID.toStdString().data());
						child->LinkEndChild(m_P);
					}

				}
				if (0 == strcmp(child->Attribute("type"), "VLAN-PRIORITY"))
				{
					if (child->FirstChild() != NULL)
					{
						m_P = child->FirstChild()->ToText();
						m_P->SetValue(data.SMV_addr.s_VLAN_PRIORITY.toStdString().data());
					}
					else
					{
						m_P = new TiXmlText(data.SMV_addr.s_VLAN_PRIORITY.toStdString().data());
						child->LinkEndChild(m_P);
					}

				}
			}
			//child = m_SMV->FirstChildElement("MinTime");
			//if (child != NULL)
			//{
			//	m_P = child->FirstChild()->ToText();
			//	m_P->SetValue(data.SMV_addr.s_MinTime.toStdString().data());
			//}
			//child = m_SMV->FirstChildElement("MaxTime");
			//if (child != NULL)
			//{
			//	m_P = child->FirstChild()->ToText();
			//	m_P->SetValue(data.SMV_addr.s_MaxTime.toStdString().data());
			//}
			return DO_OK;
		}
	}
	return DO_FAIL;
}
void ScdTree::AutoSet_MMS()
{
	TiXmlElement *m_SubNet = NULL;
	TiXmlElement *m_ConnectedAP = NULL;
	TiXmlElement *m_Address = NULL;
	//TiXmlElement *m_SMV = NULL;
	TiXmlElement *child = NULL;
	TiXmlText *m_P = NULL;
	ConnectedAP m_data;
	m_data.iP_addr.s_IP = "192.168.100.1";
	m_data.iP_addr.s_AE_Qualifier = "23";
	m_data.iP_addr.s_AP_Title = "1 3 9999 23";
	m_data.iP_addr.s_PSEL = "00 00 00 01";
	m_data.iP_addr.s_SSEL = "00 01";
	m_data.iP_addr.s_TSEL = "00 01";
	m_SubNet = root->FirstChildElement("Communication")->FirstChildElement("SubNetwork");
	for (m_SubNet; m_SubNet != NULL; m_SubNet = m_SubNet->NextSiblingElement("SubNetwork"))
	{
		if (0 == strcmp("8-MMS", m_SubNet->Attribute("type")))
		{
			break;
		}
	}
	if (m_SubNet == NULL)
	{
		return;
	}
	int i = 0;
	for (m_ConnectedAP = m_SubNet->FirstChildElement("ConnectedAP"); m_ConnectedAP != NULL; m_ConnectedAP = m_ConnectedAP->NextSiblingElement("ConnectedAP"))
	{
		m_Address = m_ConnectedAP->FirstChildElement("Address");
		if (m_Address == NULL)
		{
			continue;
		}
		for (child = m_Address->FirstChildElement(); child != NULL; child = child->NextSiblingElement())
		{
			if (0 == strcmp(child->Attribute("type"), "IP"))
			{
				m_P = child->FirstChild()->ToText();
				m_P->SetValue(IP_Increase(m_data.iP_addr.s_IP, i).toStdString().data());
			}
			if (0 == strcmp(child->Attribute("type"), "OSI-PSEL"))
			{
				m_P = child->FirstChild()->ToText();
				m_P->SetValue(m_data.iP_addr.s_PSEL.toStdString().data());
			}
			if (0 == strcmp(child->Attribute("type"), "OSI-SSEL"))
			{
				m_P = child->FirstChild()->ToText();
				m_P->SetValue(m_data.iP_addr.s_SSEL.toStdString().data());
			}
			if (0 == strcmp(child->Attribute("type"), "OSI-TSEL"))
			{
				m_P = child->FirstChild()->ToText();
				m_P->SetValue(m_data.iP_addr.s_TSEL.toStdString().data());
			}
			if (0 == strcmp(child->Attribute("type"), "OSI-AP-Title"))
			{
				m_P = child->FirstChild()->ToText();
				m_P->SetValue(m_data.iP_addr.s_AP_Title.toStdString().data());
			}
			if (0 == strcmp(child->Attribute("type"), "OSI-AE-Qualifier"))
			{
				m_P = child->FirstChild()->ToText();
				m_P->SetValue(m_data.iP_addr.s_AE_Qualifier.toStdString().data());
			}
		}
		i++;
	}
}
void ScdTree::AutoSet_GOOSE()
{
	TiXmlElement *m_SubNet = NULL;
	TiXmlElement *m_ConnectedAP = NULL;
	TiXmlElement *m_Address = NULL;
	TiXmlElement *m_GSE = NULL;
	TiXmlElement *child = NULL;
	TiXmlText *m_P = NULL;
	ConnectedAP m_data;
	m_data.Goose_addr.s_MAC_addr = "01-0C-CD-01-01-";
	m_data.Goose_addr.s_APPID = "0000";
	m_data.Goose_addr.s_VLAN_ID = "000";
	m_data.Goose_addr.s_VLAN_PRIORITY = "4";
	m_data.Goose_addr.s_MaxTime = "5000";
	m_data.Goose_addr.s_MinTime = "2";
	m_SubNet = root->FirstChildElement("Communication")->FirstChildElement("SubNetwork");
	for (m_SubNet; m_SubNet != NULL; m_SubNet = m_SubNet->NextSiblingElement("SubNetwork"))
	{
		if (0 == strcmp("IECGOOSE", m_SubNet->Attribute("type")))
		{
			break;
		}
	}
	if (m_SubNet == NULL)
	{
		return;
	}
	int i = 0;
	for (m_ConnectedAP = m_SubNet->FirstChildElement("ConnectedAP"); m_ConnectedAP != NULL; m_ConnectedAP = m_ConnectedAP->NextSiblingElement("ConnectedAP"))
	{
		m_GSE = m_ConnectedAP->FirstChildElement("GSE");
		if (m_GSE == NULL)
		{
			continue;
		}
		for (m_GSE; m_GSE != NULL; m_GSE = m_GSE->NextSiblingElement("GSE"))
		{
			m_Address = m_GSE->FirstChildElement("Address");
			if (m_Address == NULL)
			{
				continue;
			}
			for (child = m_Address->FirstChildElement(); child != NULL; child = child->NextSiblingElement())
			{
				if (0 == strcmp(child->Attribute("type"), "MAC-Address"))
				{
					m_P = child->FirstChild()->ToText();
					m_P->SetValue(MAC_Increase(m_data.Goose_addr.s_MAC_addr, i).toStdString().data());
				}
				if (0 == strcmp(child->Attribute("type"), "VLAN-ID"))
				{

					m_P = child->FirstChild()->ToText();
					m_P->SetValue(m_data.Goose_addr.s_VLAN_ID.toStdString().data());
				}
				if (0 == strcmp(child->Attribute("type"), "APPID"))
				{
					bool ok;
					int m_APPID = m_data.Goose_addr.s_APPID.toInt(&ok, 16);
					m_APPID = m_APPID + i;
					QString str = QString::number(m_APPID, 16);
					int i = 4 - str.length();
					while (i > 0)
					{
						str = "0" + str;
						i--;
					}
					m_P = child->FirstChild()->ToText();
					m_P->SetValue(str.toStdString().data());
				}
				if (0 == strcmp(child->Attribute("type"), "VLAN-PRIORITY"))
				{
					m_P = child->FirstChild()->ToText();
					m_P->SetValue(m_data.Goose_addr.s_VLAN_PRIORITY.toStdString().data());
				}
			}
			child = m_GSE->FirstChildElement("MinTime");
			if (child != NULL)
			{
				m_P = child->FirstChild()->ToText();
				m_P->SetValue(m_data.Goose_addr.s_MinTime.toStdString().data());
			}
			child = m_GSE->FirstChildElement("MaxTime");
			if (child != NULL)
			{
				m_P = child->FirstChild()->ToText();
				m_P->SetValue(m_data.Goose_addr.s_MaxTime.toStdString().data());
			}
			i++;
		}

	}

}
void ScdTree::AutoSet_SMV()
{
	TiXmlElement *m_SubNet = NULL;
	TiXmlElement *m_ConnectedAP = NULL;
	TiXmlElement *m_Address = NULL;
	TiXmlElement *m_SMV = NULL;
	TiXmlElement *child = NULL;
	TiXmlText *m_P = NULL;
	ConnectedAP m_data;
	m_data.SMV_addr.s_MAC_addr = "01-0C-CD-01-01-";
	m_data.SMV_addr.s_APPID = "4000";
	m_data.SMV_addr.s_VLAN_ID = "000";
	m_data.SMV_addr.s_VLAN_PRIORITY = "4";
	m_data.SMV_addr.s_MaxTime = "5000";
	m_data.SMV_addr.s_MinTime = "2";
	m_SubNet = root->FirstChildElement("Communication")->FirstChildElement("SubNetwork");
	for (m_SubNet; m_SubNet != NULL; m_SubNet = m_SubNet->NextSiblingElement("SubNetwork"))
	{
		if (0 == strcmp("SMV", m_SubNet->Attribute("type")))
		{
			break;
		}
	}
	if (m_SubNet == NULL)
	{
		return;
	}
	int i = 0;
	for (m_ConnectedAP = m_SubNet->FirstChildElement("ConnectedAP"); m_ConnectedAP != NULL; m_ConnectedAP = m_ConnectedAP->NextSiblingElement("ConnectedAP"))
	{
		m_SMV = m_ConnectedAP->FirstChildElement("SMV");
		if (m_SMV == NULL)
		{
			continue;
		}
		m_Address = m_SMV->FirstChildElement("Address");
		if (m_Address == NULL)
		{
			continue;
		}
		for (child = m_Address->FirstChildElement(); child != NULL; child = child->NextSiblingElement())
		{
			if (0 == strcmp(child->Attribute("type"), "MAC-Address"))
			{
				m_P = child->FirstChild()->ToText();
				m_P->SetValue(MAC_Increase(m_data.SMV_addr.s_MAC_addr, i).toStdString().data());
			}
			if (0 == strcmp(child->Attribute("type"), "VLAN-ID"))
			{
				m_P = child->FirstChild()->ToText();
				m_P->SetValue(m_data.SMV_addr.s_VLAN_ID.toStdString().data());
			}
			if (0 == strcmp(child->Attribute("type"), "APPID"))
			{
				bool ok;
				int m_APPID = m_data.SMV_addr.s_APPID.toInt(&ok, 16);
				m_APPID = m_APPID + i;
				m_P = child->FirstChild()->ToText();
				m_P->SetValue(QString::number(m_APPID, 16).toStdString().data());
			}
			if (0 == strcmp(child->Attribute("type"), "VLAN-PRIORITY"))
			{
				m_P = child->FirstChild()->ToText();
				m_P->SetValue(m_data.SMV_addr.s_VLAN_PRIORITY.toStdString().data());
			}
		}
		child = m_SMV->FirstChildElement("MinTime");
		if (child != NULL)
		{
			m_P = child->FirstChild()->ToText();
			m_P->SetValue(m_data.SMV_addr.s_MinTime.toStdString().data());
		}
		child = m_SMV->FirstChildElement("MaxTime");
		if (child != NULL)
		{
			m_P = child->FirstChild()->ToText();
			m_P->SetValue(m_data.SMV_addr.s_MaxTime.toStdString().data());
		}
		i++;
	}
}
void ScdTree::Init_LN_MAP(TiXmlElement* LD, QMap<QString, TiXmlElement* >&map)
{
	TiXmlElement* Child = NULL;
	const char* chr;
	map.clear();
	if (LD == NULL)
	{
		return;
	}
	for (Child = LD->FirstChildElement(); Child != NULL; Child = Child->NextSiblingElement())
	{
		QString Lninst;
		chr = Child->Attribute("prefix");
		Lninst += chr;
		chr = Child->Attribute("lnClass");
		Lninst += chr;
		chr = Child->Attribute("inst");
		Lninst += chr;
		Lninst = Lninst.simplified();
		map.insert(Lninst, Child);
	}
}
void ScdTree::Init_LD_MAP(TiXmlElement *IED, QMap<QString, TiXmlElement* >&LDMap)
{
	TiXmlElement *m_AP = NULL;
	TiXmlElement *m_LD = NULL;
	const char* chr;
	LDMap.clear();
	if (IED == NULL)
	{
		return;
	}
	for (m_AP = IED->FirstChildElement("AccessPoint"); m_AP != NULL; m_AP = m_AP->NextSiblingElement("AccessPoint"))
	{
		for (m_LD = m_AP->FirstChildElement("Server")->FirstChildElement("LDevice"); m_LD != NULL; m_LD = m_LD->NextSiblingElement("LDevice"))
		{
			QString LDName;
			chr = m_LD->Attribute("inst");
			LDName += chr;
			LDMap.insert(LDName, m_LD);
		}
	}
}
void ScdTree::Init_AP_MAP(TiXmlElement *IED, QMap<QString, TiXmlElement* >&APMap)
{
	TiXmlElement *m_AP = NULL;

	const char* chr;
	APMap.clear();
	if (IED == NULL)
	{
		return;
	}
	for (m_AP = IED->FirstChildElement("AccessPoint"); m_AP != NULL; m_AP = m_AP->NextSiblingElement("AccessPoint"))
	{
		QString APName;
		chr = m_AP->Attribute("name");
		APName += chr;
		APMap.insert(APName, m_AP);
	}
}
void ScdTree::Init_IED_MAP(TiXmlElement *SCL, QMap<QString, TiXmlElement* >&IEDMap)
{
	TiXmlElement *m_IED = NULL;
	const char* chr;
	IEDMap.clear();
	if (SCL == NULL)
	{
		return;
	}
	for (m_IED = SCL->FirstChildElement("IED"); m_IED != NULL; m_IED = m_IED->NextSiblingElement("IED"))
	{
		QString IEDName;
		chr = m_IED->Attribute("name");
		IEDName += chr;
		IEDMap.insert(IEDName, m_IED);
	}
}
void ScdTree::Init_DO_MAP(TiXmlElement *LN, QMap<QString, TiXmlElement* >&Map)
{
	TiXmlElement *m_DO = NULL;
	const char* chr;
	Map.clear();
	if (LN == NULL)
	{
		return;
	}
	for (m_DO = LN->FirstChildElement("DOI"); m_DO != NULL; m_DO = m_DO->NextSiblingElement("DOI"))
	{
		QString DoName;
		chr = m_DO->Attribute("name");
		DoName += chr;
		Map.insert(DoName, m_DO);
	}
}
void ScdTree::Init_SDI_MAP(TiXmlElement *DO, QMap<QString, TiXmlElement* >&Map)
{
	TiXmlElement *m_SDI = NULL;
	const char* chr;
	Map.clear();
	if (DO == NULL)
	{
		return;
	}
	for (m_SDI = DO->FirstChildElement("SDI"); m_SDI != NULL; m_SDI = m_SDI->NextSiblingElement("SDI"))
	{
		QString SDIName;
		chr = m_SDI->Attribute("name");
		SDIName += chr;
		Map.insert(SDIName, m_SDI);
	}
}
void ScdTree::Init_DAI_MAP(TiXmlElement *DO, QMap<QString, TiXmlElement* >&Map)
{
	TiXmlElement *m_SDI = NULL;
	const char* chr;
	Map.clear();
	if (DO == NULL)
	{
		return;
	}
	for (m_SDI = DO->FirstChildElement("DAI"); m_SDI != NULL; m_SDI = m_SDI->NextSiblingElement("DAI"))
	{
		QString SDIName;
		chr = m_SDI->Attribute("name");
		SDIName += chr;
		Map.insert(SDIName, m_SDI);
	}
}
void ScdTree::Init_ConnectAP_MAP(TiXmlElement *SubNet, QMap<QString, TiXmlElement* >&APMap)
{
	TiXmlElement *m_AP = NULL;
	const char* chr;
	APMap.clear();
	if (SubNet == NULL)
	{
		return;
	}
	for (m_AP = SubNet->FirstChildElement("ConnectedAP"); m_AP != NULL; m_AP = m_AP->NextSiblingElement("ConnectedAP"))
	{
		QString iedName;
		chr = m_AP->Attribute("iedName");
		iedName += chr;
		APMap.insertMulti(iedName, m_AP);
	}
}
void ScdTree::Init_LNtype_MAP(TiXmlElement*Node, QMap<QString, TiXmlElement* >&MAP)
{
	TiXmlElement* LNodeType = NULL;
	const char* chr;
	MAP.clear();
	if (Node == NULL)
	{
		return;
	}
	for (LNodeType = Node->FirstChildElement("LNodeType"); LNodeType != NULL; LNodeType = LNodeType->NextSiblingElement("LNodeType"))
	{
		QString str;
		chr = LNodeType->Attribute("id");
		str += chr;
		MAP.insertMulti(str, LNodeType);
	}
}
void ScdTree::Init_DOType_MAP(TiXmlElement*Node, QMap<QString, TiXmlElement* >&MAP)
{
	TiXmlElement* DOType = NULL;
	const char* chr;
	MAP.clear();
	if (Node == NULL)
	{
		return;
	}
	for (DOType = Node->FirstChildElement("DOType"); DOType != NULL; DOType = DOType->NextSiblingElement("DOType"))
	{
		QString str;
		chr = DOType->Attribute("id");
		str += chr;
		MAP.insertMulti(str, DOType);
	}
}
void ScdTree::Init_DAtype_MAP(TiXmlElement*Node, QMap<QString, TiXmlElement* >&MAP)
{
	TiXmlElement* DAType = NULL;
	const char* chr;
	MAP.clear();
	if (Node == NULL)
	{
		return;

	}
	for (DAType = Node->FirstChildElement("DAType"); DAType != NULL; DAType = DAType->NextSiblingElement("DAType"))
	{
		QString str;
		chr = DAType->Attribute("id");
		str += chr;
		MAP.insertMulti(str, DAType);
	}
}
void ScdTree::Init_EnumType_MAP(TiXmlElement*Node, QMap<QString, TiXmlElement* >&MAP)
{
	TiXmlElement* EnumType = NULL;
	const char* chr;
	MAP.clear();
	if (Node == NULL)
	{
		return;
	}
	for (EnumType = Node->FirstChildElement("EnumType"); EnumType != NULL; EnumType = EnumType->NextSiblingElement("EnumType"))
	{
		QString str;
		chr = EnumType->Attribute("id");
		str += chr;
		MAP.insertMulti(str, EnumType);
	}
}
void ScdTree::Filling_OneData(FCDA_Struct &data, int state)
{
	const char *chr;
	QString Ln_inst;
	QMap<QString, TiXmlElement*>LD_Map;
	Init_LD_MAP(CurElement, LD_Map);
	TiXmlElement* m_LD = NULL;
	m_LD = LD_Map.value(data.B_ldInst);
	QMap<QString, TiXmlElement*>LN_Map;
	Init_LN_MAP(m_LD, LN_Map);
	TiXmlElement* m_LN = NULL;
	Ln_inst = data.B_prefix + data.B_lnClass + data.B_lnInst;
	m_LN = LN_Map.value(Ln_inst);
	TiXmlElement* m_DO = NULL;
	QString doName = QString::fromLatin1(data.B_doName);
	QStringList dolist = doName.split(".");
	m_DO = m_LN->GetChildByName_Value(m_LN, "DOI", "name", dolist.at(0).toStdString().data());
	if (m_DO == NULL)
	{
		return;
	}
	chr = m_DO->Attribute("desc");
	data.B_DOdesc += chr;
	dolist.removeAt(0);
	while (dolist.size() != 0)
	{
		m_DO = m_LN->GetChildByName_Value(m_DO, "SDI", "name", dolist.at(0).toStdString().data());
		chr = m_DO->Attribute("desc");
		data.B_DOdesc += chr;
		dolist.removeAt(0);
	}
	if (state == 1)
	{
		TiXmlElement* m_DA = NULL;
		QString daName = QString::fromLatin1(data.B_daName);
		if (daName.isEmpty())
		{
			return;
		}
		QStringList dalist = daName.split(".");
		if (dalist.size() == 1)
		{
			m_DA = m_LN->GetChildByName_Value(m_DO, "DAI", "name", dalist.at(0).toStdString().data());
			if (m_DA == NULL)
			{
				return;
			}
			chr = m_DA->Attribute("sAddr");
			data.B_sAddr += chr;
			return;
		}
		else
		{
			m_DA = m_LN->GetChildByName_Value(m_DO, "SDI", "name", dalist.at(0).toStdString().data());
			if (m_DA == NULL)
			{
				return;
			}
			dalist.removeAt(0);
			while (dolist.size() > 1)
			{
				m_DA = m_LN->GetChildByName_Value(m_DA, "SDI", "name", dalist.at(0).toStdString().data());
				dalist.removeAt(0);
			}
			m_DA = m_LN->GetChildByName_Value(m_DA, "DAI", "name", dalist.at(0).toStdString().data());
			chr = m_DA->Attribute("sAddr");
			data.B_sAddr += chr;
		}

	}
}
void ScdTree::Filling_OneData(QString iedName, FCDA_Struct &data, int state)
{
	const char *chr;
	QString Ln_inst;
	QMap<QString, TiXmlElement*>IED_Map;
	Init_IED_MAP(root, IED_Map);
	TiXmlElement* m_IED = NULL;
	m_IED = IED_Map.value(iedName);
	QMap<QString, TiXmlElement*>LD_Map;
	Init_LD_MAP(m_IED, LD_Map);
	TiXmlElement* m_LD = NULL;
	m_LD = LD_Map.value(data.B_ldInst);
	QMap<QString, TiXmlElement*>LN_Map;
	Init_LN_MAP(m_LD, LN_Map);
	TiXmlElement* m_LN = NULL;
	Ln_inst = data.B_prefix + data.B_lnClass + data.B_lnInst;
	m_LN = LN_Map.value(Ln_inst);
	TiXmlElement* m_DO = NULL;
	QString doName = QString::fromLatin1(data.B_doName);
	QStringList dolist = doName.split(".");
	m_DO = m_LN->GetChildByName_Value(m_LN, "DOI", "name", dolist.at(0).toStdString().data());
	if (m_DO == NULL)
	{
		return;
	}
	chr = m_DO->Attribute("desc");
	data.B_DOdesc += chr;
	dolist.removeAt(0);
	while (dolist.size() != 0)
	{
		m_DO = m_LN->GetChildByName_Value(m_DO, "SDI", "name", dolist.at(0).toStdString().data());
		chr = m_DO->Attribute("desc");
		data.B_DOdesc += chr;
		dolist.removeAt(0);
	}
	if (state == 1)
	{
		TiXmlElement* m_DA = NULL;
		QString daName = QString::fromLatin1(data.B_daName);
		if (daName.isEmpty())
		{
			return;
		}
		QStringList dalist = daName.split(".");
		if (dalist.size() == 1)
		{
			m_DA = m_LN->GetChildByName_Value(m_DO, "DAI", "name", dalist.at(0).toStdString().data());
			if (m_DA == NULL)
			{
				return;
			}
			chr = m_DA->Attribute("sAddr");
			data.B_sAddr += chr;
			return;
		}
		else
		{
			m_DA = m_LN->GetChildByName_Value(m_DO, "SDI", "name", dalist.at(0).toStdString().data());
			if (m_DA == NULL)
			{
				return;
			}
			dalist.removeAt(0);
			while (dolist.size() > 1)
			{
				m_DA = m_LN->GetChildByName_Value(m_DA, "SDI", "name", dalist.at(0).toStdString().data());
				dalist.removeAt(0);
			}
			m_DA = m_LN->GetChildByName_Value(m_DA, "DAI", "name", dalist.at(0).toStdString().data());
			chr = m_DA->Attribute("sAddr");
			data.B_sAddr += chr;
		}

	}
}
void ScdTree::ExportCID_FILE(QString IEDName, QString File)
{
	std::string str = IEDName.toStdString();

	const char* chr = str.c_str();
	QMap<QString, TiXmlElement* > APMap;
	QMap<QString, TiXmlElement* > IEDMap;
	QMap<QString, TiXmlElement* > LnTypeMap;
	QMap<QString, TiXmlElement* > DOTypeMap;
	QMap<QString, TiXmlElement* > DATypeMap;
	QMap<QString, TiXmlElement* > EnumTypeMap;
	QStringList LnTypeList;
	QStringList DOTypeList;
	QStringList DATypeList;
	QStringList EnumTypeList;
	TiXmlElement*node = NULL;
	TiXmlDocument *DOCPoint = new TiXmlDocument;
	TiXmlDeclaration *Declaration = new TiXmlDeclaration("1.0", "UTF-8", "");
	DOCPoint->LinkEndChild(Declaration);
	TiXmlElement *SCL_element = new TiXmlElement("SCL");
	SCL_element->SetAttribute("xmlns", "http://www.iec.ch/61850/2003/SCL");
	SCL_element->SetAttribute("xmlns:xsi", "http://www.w3.org/2001/XMLSchema-instance");
	SCL_element->SetAttribute("xmlns:kf", "http://www.keyvia.cn");
	SCL_element->SetAttribute("xsi:schemaLocation", "http://www.iec.ch/61850/2003/SCL SCL.xsd");

	TiXmlElement *Header_element = new TiXmlElement("Header");
	Header_element->SetAttribute("id", chr);
	Header_element->SetAttribute("version", "1.00");
	Header_element->SetAttribute("toolID", "Keyvia Configuration");
	Header_element->SetAttribute("nameStructure", "IEDName");
	SCL_element->LinkEndChild(Header_element);

	TiXmlElement *Comm_element = new TiXmlElement("Communication");
	TiXmlElement *SubNet = root->FirstChildElement("Communication")->FirstChildElement("SubNetwork");
	for (; SubNet != NULL; SubNet = SubNet->NextSiblingElement("SubNetwork"))
	{
		APMap.clear();
		Init_ConnectAP_MAP(SubNet, APMap);
		if (APMap.contains(IEDName))
		{
			TiXmlElement *NetNode = new TiXmlElement(SubNet->Value());
			NetNode->SetAttribute("name", SubNet->Attribute("name"));
			NetNode->SetAttribute("type", SubNet->Attribute("type"));
			NetNode->SetAttribute("desc", SubNet->Attribute("desc"));
			node = APMap.value(IEDName);
			NetNode->LinkEndChild(node->Clone()->ToElement());
			Comm_element->LinkEndChild(NetNode);
		}
	}
	SCL_element->LinkEndChild(Comm_element);
	Init_IED_MAP(root, IEDMap);

	node = IEDMap.value(IEDName);
	SCL_element->LinkEndChild(node->Clone()->ToElement());
	TiXmlElement *DataType_element = new TiXmlElement("DataTypeTemplates");
	GetLnTypeList(IEDMap.value(IEDName), LnTypeList);
	Init_LNtype_MAP(root->FirstChildElement("DataTypeTemplates"), LnTypeMap);
	Init_DOType_MAP(root->FirstChildElement("DataTypeTemplates"), DOTypeMap);
	Init_DAtype_MAP(root->FirstChildElement("DataTypeTemplates"), DATypeMap);
	Init_EnumType_MAP(root->FirstChildElement("DataTypeTemplates"), EnumTypeMap);
	for (int i = 0; i < LnTypeList.size(); i++)
	{
		node = LnTypeMap.value(LnTypeList[i]);
		GetDoTypeList(node, DOTypeList);
		DataType_element->LinkEndChild(node->Clone()->ToElement());
	}
	while (DOTypeList.size()>0)
	{
		node = DOTypeMap.value(DOTypeList.at(0));
		GetDaTypeList(node, DOTypeList, DATypeList, EnumTypeList);
		DataType_element->LinkEndChild(node->Clone()->ToElement());
		DOTypeList.removeAt(0);
	}
	while (DATypeList.size() > 0)
	{
		node = DATypeMap.value(DATypeList.at(0));
		GetEnumTypeList(node, DATypeList, EnumTypeList);
		DataType_element->LinkEndChild(node->Clone()->ToElement());
		DATypeList.removeAt(0);
	}
	while (EnumTypeList.size() > 0)
	{
		node = EnumTypeMap.value(EnumTypeList.at(0));
		//GetEnumTypeList(node, EnumTypeList);
		DataType_element->LinkEndChild(node->Clone()->ToElement());
		EnumTypeList.removeAt(0);
	}
	SCL_element->LinkEndChild(DataType_element);
	DOCPoint->LinkEndChild(SCL_element);
	DOCPoint->SaveFile(File.toLocal8Bit().data());
}
void ScdTree::GetLnTypeList(TiXmlElement*IEDNode, QStringList &List)
{
	QMap<QString, TiXmlElement* > LDMap;
	QMap<QString, TiXmlElement* > LNMap;

	const char* chr;
	Init_LD_MAP(IEDNode, LDMap);
	QStringList LDkeylist = LDMap.keys();
	for (int i = 0; i < LDkeylist.size(); i++)
	{
		Init_LN_MAP(LDMap.value(LDkeylist[i]), LNMap);
		QStringList LNkeylist = LNMap.keys();
		for (int m = 0; m < LNkeylist.size(); m++)
		{
			TiXmlElement* LN = NULL;
			QString LNtype;
			LN = LNMap.value(LNkeylist[m]);
			chr = LN->Attribute("lnType");
			LNtype += chr;
			if (!List.contains(LNtype))
			{
				List.append(LNtype);
			}
		}
	}
}
void ScdTree::GetDoTypeList(TiXmlElement*Node, QStringList&List)
{
	TiXmlElement *child = NULL;
	const char* chr;
	for (child = Node->FirstChildElement(); child != NULL; child = child->NextSiblingElement())
	{
		QString str;
		chr = child->Attribute("type");
		str += chr;
		if (!List.contains(str))
		{
			List.append(str);
		}
	}


}
void ScdTree::GetDaTypeList(TiXmlElement*Node, QStringList&DoList, QStringList&DaList, QStringList&EnumList)
{
	TiXmlElement *child;
	const char* chr;
	for (child = Node->FirstChildElement(); child != NULL; child = child->NextSiblingElement())
	{
		QString str;
		chr = child->Attribute("type");
		if (chr == NULL)
		{
			continue;
		}
		str += chr;
		if (0 == strcmp(child->Value(), "SDO"))
		{
			if (!DoList.contains(str))
			{
				DoList.append(str);
			}
		}
		else 		if (0 == strcmp(child->Value(), "DA"))
		{
			if (0 == strcmp(child->Attribute("bType"), "Enum"))
			{
				if (!EnumList.contains(str))
				{
					EnumList.append(str);
				}
			}
			else if (0 == strcmp(child->Attribute("bType"), "Struct"))
			{
				if (!DaList.contains(str))
				{
					DaList.append(str);
				}
			}

		}

	}
}
void ScdTree::GetEnumTypeList(TiXmlElement*Node, QStringList&DaList, QStringList&EnumList)
{
	TiXmlElement *child = NULL;
	const char* chr;
	for (child = Node->FirstChildElement(); child != NULL; child = child->NextSiblingElement())
	{
		QString str;
		chr = child->Attribute("type");
		if (chr == NULL)
		{
			continue;
		}
		str += chr;
		if (0 == strcmp(child->Attribute("bType"), "Enum"))
		{
			if (!EnumList.contains(str))
			{
				EnumList.append(str);
			}
		}
		else if (0 == strcmp(child->Attribute("bType"), "Struct"))
		{
			if (!DaList.contains(str))
			{
				DaList.append(str);
			}
		}
	}
}
int ScdTree::ExportCONFIG_FILE(QString IEDName, QString File)
{
	Init_FCDA_MAP();
	QMap<QString, TiXmlElement* > IEDMap;
	QVector<INPUT_Config>Input_Vector;
	TiXmlDocument* DOCPoint = new TiXmlDocument;
	Init_ConfigFIle(DOCPoint);
	Init_IED_MAP(root, IEDMap);
	TiXmlElement* m_IED = NULL;
	m_IED = IEDMap.value(IEDName);
	QMap<QString, TiXmlElement* > LDMap;
	QMap<QString, TiXmlElement* > LNMap;
	TiXmlElement* m_LD = NULL;
	TiXmlElement* m_LN = NULL;
	TiXmlElement* m_Inputs = NULL;
	TiXmlElement* m_EXRef = NULL;
	//const char* chr;
	Init_LD_MAP(m_IED, LDMap);
	QString strVendr;
	bool flag = false;
	strVendr += m_IED->Attribute("manufacturer");
	if (strVendr != "KF")
	{
		return DO_OD;
	}
	for (int i = 0; i < LDMap.uniqueKeys().size(); i++)
	{
		Input_Vector.clear();
		m_LD = LDMap.value(LDMap.uniqueKeys().at(i));
		Init_LN_MAP(m_LD, LNMap);
		m_LN = LNMap.value("LLN0");
		m_Inputs = m_LN->FirstChildElement("Inputs");
		if (m_Inputs == NULL)
		{
			continue;
		}
		for (m_EXRef = m_Inputs->FirstChildElement(); m_EXRef != NULL; m_EXRef = m_EXRef->NextSiblingElement())
		{

			bool flag = true;
			flag = Fill_Input_config(m_EXRef, Input_Vector, 1);
			if (flag == false)
			{
				QMessageBox::about(0, QObject::tr("Alarm"), QObject::tr("There is error in mapping about %1").arg(IEDName));
				return DO_FAIL;

			}

		}
		for (int i = 0; i < Input_Vector.size(); i++)
		{
			WriteData2Config(IEDName, DOCPoint, Input_Vector[i], i, 1);
			flag = true;

		}

	}
	if (flag == true)
	{
		DOCPoint->SaveFile(File.toLocal8Bit().data());
	}
	return DO_FAIL;

}
bool ScdTree::Fill_Input_config(TiXmlElement*ExRef, QVector<INPUT_Config>&List, int state)
{
	const char* chr = NULL;
	QString IEDName, strCrc, DataSetName, str, strln;
	chr = ExRef->Attribute("iedName");

	IEDName += chr;
	if (IEDName.isEmpty())
	{
		return false;
	}
	strCrc += chr;
	chr = NULL;
	chr = ExRef->Attribute("ldInst");
	str.clear();
	str += ExRef->Attribute("ldInst");
	if (str.isEmpty())
	{
		return false;
	}
	strCrc += chr;
	chr = NULL;
	chr = ExRef->Attribute("prefix");

	strln += ExRef->Attribute("prefix");
	strCrc += chr;
	chr = NULL;
	chr = ExRef->Attribute("lnClass");
	strln += ExRef->Attribute("lnClass");
	strCrc += chr;
	chr = NULL;
	chr = ExRef->Attribute("lnInst");
	strln += ExRef->Attribute("lnInst");
	if (strln.isEmpty())
	{
		return false;
	}
	strCrc += chr;
	chr = NULL;

	chr = ExRef->Attribute("doName");
	str.clear();
	str += ExRef->Attribute("doName");
	if (str.isEmpty())
	{
		return false;
	}
	strCrc += chr;
	chr = NULL;
	chr = ExRef->Attribute("daName");
	str.clear();
	str += ExRef->Attribute("daName");
	if (str.isEmpty())
	{
		return false;
	}
	strCrc += chr;
	strCrc = strCrc.simplified();
	TiXmlElement* m_DataSet = NULL;
	TiXmlElement*m_GSE = NULL;
	TiXmlElement*m_SMV = NULL;
	TiXmlElement*m_Child = NULL;
	INPUT_Map m_input;
	TiXmlElement* m_FCDA = FCDA_MAP.value(strCrc);
	m_DataSet = m_FCDA->Parent()->ToElement();
	chr = m_DataSet->Attribute("name");
	DataSetName += chr;
	int i = 0;
	for (m_Child = m_DataSet->FirstChildElement("FCDA"); m_Child != NULL; m_Child = m_Child->NextSiblingElement("FCDA"))
	{
		if (m_Child == m_FCDA)
		{
			m_input.index = i;
			m_input.EXEefList = ExRef;
		}
		i++;
	}
	//	if (state == 1)
	//	{
	for (m_GSE = m_DataSet->Parent()->ToElement()->FirstChildElement("GSEControl"); m_GSE != NULL; m_GSE = m_GSE->NextSiblingElement("GSEControl"))
	{
		if (0 == strcmp(chr, m_GSE->Attribute("datSet")))
		{
			break;
		}
	}
	//	}
	//	if (state == 0)
	//	{
	if (m_GSE == NULL)
	{
		for (m_SMV = m_DataSet->Parent()->ToElement()->FirstChildElement("SampledValueControl"); m_SMV != NULL; m_SMV = m_SMV->NextSiblingElement("SampledValueControl"))
		{
			if (0 == strcmp(chr, m_SMV->Attribute("datSet")))
			{
				break;
			}
		}
	}

	//	}
	INPUT_Config m_data;
	m_data.IEDName = IEDName;
	if (m_GSE != NULL)
	{
		m_data.GSENode = m_GSE;
	}
	else
	{
		m_data.SMVNode = m_SMV;
	}


	m_data.DataSetName = DataSetName;
	if (List.contains(m_data))
	{
		List[List.indexOf(m_data)].EXEefList.append(m_input);
		return true;
	}
	else
	{
		m_data.EXEefList.append(m_input);
		List.append(m_data);
		return true;
	}
}

void ScdTree::Init_ConfigFIle(TiXmlDocument*DOCPoint)
{

	TiXmlDeclaration *Declaration = new TiXmlDeclaration("1.0", "UTF-8", "");
	DOCPoint->LinkEndChild(Declaration);
	TiXmlElement *SCL_element = new TiXmlElement("Config");
	TiXmlElement *DATAINFO_element = new TiXmlElement("DATAINFO");

	TiXmlElement *GOOSE_element = new TiXmlElement("SUB_GOOSE");

	TiXmlElement *SMV_element = new TiXmlElement("SUB_SMV");
	DATAINFO_element->LinkEndChild(GOOSE_element);
	DATAINFO_element->LinkEndChild(SMV_element);
	SCL_element->LinkEndChild(DATAINFO_element);
	DOCPoint->LinkEndChild(SCL_element);
}
void ScdTree::WriteData2Config(QString curIED, TiXmlDocument*Point, INPUT_Config&m_data, int index, int state)
{
	TiXmlElement *SCL_element = Point->LastChild("Config")->ToElement();
	TiXmlElement *DATAINFO_element = SCL_element->LastChild("DATAINFO")->ToElement();
	TiXmlElement *GOOSE_element = DATAINFO_element->LastChild("SUB_GOOSE")->ToElement();
	TiXmlElement *GCB = new TiXmlElement("GCB");
	GOOSE_element->LinkEndChild(GCB);
	TiXmlElement *Node = NULL;
	QString LDName;
	QString DatasetRef;

	QString strGcRef;
	std::string str = m_data.IEDName.toStdString();
	const char* chr;
	GCB->SetAttribute("IEDName", str.c_str());
	if (m_data.GSENode != NULL)
	{
		GCB->SetAttribute("GoID", m_data.GSENode->Attribute("appID"));
		GCB->SetAttribute("ConfRev", m_data.GSENode->Attribute("confRev"));
		chr = m_data.GSENode->Attribute("datSet");
		DatasetRef += chr;
		chr = m_data.GSENode->Attribute("name");
		strGcRef += chr;
		DatasetRef = "$" + DatasetRef;
		strGcRef = "." + strGcRef;
		Node = m_data.GSENode->Parent()->ToElement();
		chr = Node->Attribute("inst");
	}
	else
	{
		GCB->SetAttribute("smvID", m_data.SMVNode->Attribute("smvID"));
		GCB->SetAttribute("ConfRev", m_data.SMVNode->Attribute("confRev"));
		chr = m_data.SMVNode->Attribute("datSet");
		DatasetRef += chr;
		chr = m_data.SMVNode->Attribute("name");
		strGcRef += chr;
		DatasetRef = "$" + DatasetRef;
		strGcRef = "." + strGcRef;
		Node = m_data.SMVNode->Parent()->ToElement();
		chr = Node->Attribute("inst");
	}



	strGcRef += chr;
	DatasetRef = chr + DatasetRef;
	strGcRef = chr + strGcRef;
	chr = Node->Attribute("lnClass");
	strGcRef += chr;
	DatasetRef = chr + DatasetRef;
	strGcRef = chr + strGcRef;
	chr = Node->Attribute("prefix");
	strGcRef += chr;
	DatasetRef = chr + DatasetRef;
	strGcRef = chr + strGcRef;
	DatasetRef = "/" + DatasetRef;
	strGcRef = "/" + strGcRef;
	Node = Node->Parent()->ToElement();
	chr = Node->Attribute("inst");
	LDName += chr;
	DatasetRef = chr + DatasetRef;
	strGcRef = chr + DatasetRef;
	DatasetRef = m_data.IEDName + DatasetRef;
	str = DatasetRef.toStdString();
	GCB->SetAttribute("DatasetRef", str.c_str());
	strGcRef = DatasetRef;
	str = strGcRef.toStdString();
	GCB->SetAttribute("GcRef", str.c_str());
	GCB->SetAttribute("DESC", "");
	GCB->SetAttribute("YabanID", QString::number(index, 10).toStdString().data());
	GCB->SetAttribute("T0", QString::number(5000, 10).toStdString().data());
	GCB->SetAttribute("T1", QString::number(2, 10).toStdString().data());
	GCB->SetAttribute("Priority", "");
	TiXmlElement *NET = new TiXmlElement("GCB");
	GCB->LinkEndChild(NET);
	NET->SetAttribute("Type", "SINGLE");
	TiXmlElement *Address = new TiXmlElement("Address");
	NET->LinkEndChild(Address);
	TiXmlElement *Port = new TiXmlElement("PORT");
	TiXmlText *Chile_text = new TiXmlText("1");
	Port->LinkEndChild(Chile_text);
	Address->LinkEndChild(Port);
	TiXmlElement *VLANID = new TiXmlElement("VLANID");
	Address->LinkEndChild(VLANID);
	Chile_text = new TiXmlText("");
	VLANID->LinkEndChild(Chile_text);
	TiXmlElement *MAC = new TiXmlElement("MAC");
	Address->LinkEndChild(MAC);
	Chile_text = new TiXmlText("");
	MAC->LinkEndChild(Chile_text);
	QMap<QString, TiXmlElement*> ConnectApMap;
	Init_ConnectAP_MAP(root->FirstChildElement("Communication"), ConnectApMap, 0);
	Node = Node->Parent()->Parent()->ToElement();
	chr = Node->Attribute("name");
	QString strcrc;
	strcrc += m_data.IEDName;
	strcrc += chr;
	TiXmlElement* child = NULL;
	TiXmlElement* m_P = NULL;
	TiXmlText *m_text = NULL;
	TiXmlElement* ConnectAP = ConnectApMap.value(strcrc);
	if (m_data.GSENode != NULL)
	{
		child = ConnectAP->FirstChildElement("GSE");
	}
	else if (m_data.SMVNode != NULL)
	{
		child = ConnectAP->FirstChildElement("SMV");
	}
	for (m_P = child->FirstChildElement("Address")->FirstChildElement(); m_P != NULL; m_P = m_P->NextSiblingElement())
	{
		if (0 == strcmp(m_P->Attribute("type"), "MAC-Address"))
		{
			m_text = m_P->FirstChild()->ToText();
			chr = m_text->Value();
			MAC->FirstChild()->ToText()->SetValue(chr);
		}
		if (0 == strcmp(m_P->Attribute("type"), "VLAN-ID"))
		{
			m_text = m_P->FirstChild()->ToText();
			chr = m_text->Value();
			VLANID->FirstChild()->ToText()->SetValue(chr);
		}
		if (0 == strcmp(m_P->Attribute("type"), "APPID"))
		{
			m_text = m_P->FirstChild()->ToText();
			chr = m_text->Value();
			GCB->SetAttribute("AppID", chr);

		}
	}
	TiXmlElement *DataSet = new TiXmlElement("DATASET");
	GCB->LinkEndChild(DataSet);
	for (int i = 0; i < m_data.EXEefList.size(); i++)
	{
		TiXmlElement *FCDA = new TiXmlElement("FCDA");
		QString desc, inst, saddr;
		QStringList list;
		chr = m_data.EXEefList[i].EXEefList->Attribute("intAddr");
		inst += chr;
		std::string tmep;
		saddr.clear();
		saddr = GetSaddrByInst(curIED, inst, desc);
		if (saddr.isEmpty())
		{
			continue;

		}
		list = saddr.split(".");

		//tmep = desc.toStdString();
		FCDA->SetAttribute("DESC", desc.toStdString().data());
		FCDA->SetAttribute("EXTINDEX", QString::number(m_data.EXEefList[i].index).toStdString().data());
		if (list[0] == "1")
		{
			FCDA->SetAttribute("DATATYPE", "SPS");
			if (list[3] == "1")
			{
				FCDA->SetAttribute("FUNCTYPE", "STATUS");
			}
			else if (list[3] == "2")
			{
				FCDA->SetAttribute("FUNCTYPE", "QUALITY");
			}
			else if (list[3] == "3")
			{
				FCDA->SetAttribute("FUNCTYPE", "TIME");
			}
		}
		else 		if (list[0] == "2")
		{
			FCDA->SetAttribute("DATATYPE", "AI");
			if (list[3] == "11")
			{
				FCDA->SetAttribute("FUNCTYPE", "FLOATVALUE ");
			}
			else if (list[3] == "1")
			{
				FCDA->SetAttribute("FUNCTYPE", "INTVALUE");
			}
		}
		if (list.size() > 2)
		{
			FCDA->SetAttribute("INTINDEX", list[2].toStdString().data());
		}

		DataSet->LinkEndChild(FCDA);
	}

}
void ScdTree::ExportXLS_FILE(QString IEDName, QString File)
{
	Init_FCDA_MAP();
	File.replace("CID", "XLS");
	QAxObject *pWorkBooks = NULL;
	QAxObject *pWorkBook = NULL;
	//QAxObject *pSheets;
	//QAxObject *pSheet = NULL;
	QString FileName = File;
	FileName.replace("/", "\\");
	QAxObject *pApplication = new QAxObject("Excel.Application");
	pApplication->setProperty("Visible", false);
	pWorkBooks = pApplication->querySubObject("WorkBooks");
	pWorkBooks->dynamicCall("Add");
	QFile XLSfile(File);
	if (XLSfile.exists())
	{
		QFile::remove(File);
	}
	Init_XLSFFIle(FileName, pApplication);


	QMap<QString, TiXmlElement* > IEDMap;
	Init_IED_MAP(root, IEDMap);
	TiXmlElement* m_IED = NULL;
	m_IED = IEDMap.value(IEDName);
	QMap<QString, TiXmlElement* > LDMap;
	QMap<QString, TiXmlElement* > LNMap;
	QStringList LDList;
	QStringList LNList;
	TiXmlElement* m_LD = NULL;
	TiXmlElement* m_LN = NULL;
	TiXmlElement* m_Inputs = NULL;
	//TiXmlElement* ExtRef = NULL;

	const char* chr;
	Init_LD_MAP(m_IED, LDMap);
	LDList = LDMap.keys();
	int row = 3;
	for (int i = 0; i < LDList.size(); i++)
	{
		m_LD = LDMap.value(LDList[i]);
		chr = m_LD->Attribute("inst");
		LNMap.clear();
		Init_LN_MAP(m_LD, LNMap);
		LNList = LNMap.keys();
		for (int k = 0; k < LNList.size(); k++)
		{

			QString s_name;
			s_name += "Inputs:";
			m_LN = LNMap.value(LNList[k]);
			s_name += chr;
			s_name += "/";
			chr = m_LN->Attribute("prefix");
			s_name += chr;
			chr = m_LN->Attribute("lnClass");
			s_name += chr;
			chr = m_LN->Attribute("inst");
			s_name += chr;
			m_Inputs = m_LN->FirstChildElement("Inputs");
			if (m_Inputs == NULL)
			{
				continue;
			}
			row = Write_DataSet2File(m_IED, m_Inputs, row, s_name, pApplication);

		}
	}
	pWorkBook = pApplication->querySubObject("ActiveWorkBook");
	pWorkBook->dynamicCall("SaveAs (const QString&,int,const QString&,const QString&,bool,bool)",
		FileName, 39, QString(""), QString(""), false, false);
	pWorkBook->dynamicCall("Close()");
	pApplication->dynamicCall("Quit()");
	delete pApplication;
	return;

}
void ScdTree::ExportXLS_FILE(QStringList IEDList, QString FilePath, QProgressBar* Bar)
{
	QMap<QString, TiXmlElement*> IED_Map;
	Init_FCDA_MAP();
	Init_IED_MAP(root, IED_Map);
	using namespace libxl;
	bool recode;
	QString error;
	Book* book = xlCreateBook(); // use xlCreateXMLBook() for working with xlsx files
	book->setKey("Halil Kural", "windows-2723210a07c4e90162b26966a8jcdboe");
	int value = 0;
	if (IEDList.size() < 100)
	{
		value = 100 / IEDList.size();
		Bar->setMaximum(100);
	}
	else if ((100 < IEDList.size()) && (IEDList.size() < 1000))
	{
		value = 1000 / IEDList.size();
		Bar->setMaximum(1000);
	}
	for (int i = 0; i < IEDList.size(); i++)
	{
		Bar->setValue(i*value);
		Sheet* sheet = book->addSheet(IEDList.at(i).toLocal8Bit().data());
		error = QString::fromLocal8Bit(book->errorMessage());

		Format* FontFormat = book->addFormat();
		Format* Bord_Left = book->addFormat();
		Format* Bord_Right = book->addFormat();
		Format* Bord_Top = book->addFormat();
		Format* Bord_Buttom = book->addFormat();
		Format* BordFormat = book->addFormat();
		FontFormat->setAlignH(ALIGNH_CENTER);
		FontFormat->setAlignV(ALIGNV_CENTER);
		Bord_Left->setBorderLeft(BORDERSTYLE_THICK);
		Bord_Right->setBorderLeft(BORDERSTYLE_THICK);
		Bord_Top->setBorderLeft(BORDERSTYLE_THICK);
		Bord_Buttom->setBorderLeft(BORDERSTYLE_THICK);
		BordFormat->setBorder(BORDERSTYLE_THICK);
		BordFormat->setAlignH(ALIGNH_CENTER);
		BordFormat->setAlignV(ALIGNV_CENTER);
		BordFormat->setFillPattern(FILLPATTERN_SOLID);
		BordFormat->setPatternForegroundColor(COLOR_LIGHTTURQUOISE);
		sheet->setMerge(0, 1, 0, 0);
		recode = sheet->writeBlank(0, 0, BordFormat);

		recode = sheet->writeBlank(1, 0, BordFormat);
		recode = sheet->writeStr(0, 0, QObject::tr("Index").toLocal8Bit().data());

		sheet->setMerge(0, 1, 1, 1);
		recode = sheet->writeBlank(0, 1, BordFormat);

		recode = sheet->writeBlank(1, 1, BordFormat);
		sheet->writeStr(0, 1, QObject::tr("DataSet").toLocal8Bit().data());
		//sheet->writeFormula(0, 1, QObject::tr("DataSet").toStdString().data(), dateFormat);

		sheet->setMerge(0, 0, 2, 5);
		recode = sheet->writeBlank(0, 2, BordFormat);
		recode = sheet->writeBlank(0, 3, BordFormat);
		recode = sheet->writeBlank(0, 4, BordFormat);
		recode = sheet->writeBlank(0, 5, BordFormat);
		sheet->writeStr(0, 2, QObject::tr("Sender Device").toLocal8Bit().data());
		//sheet->writeFormula(0, 2, QObject::tr("Sender Device").toStdString().data(), dateFormat);

		sheet->setMerge(0, 0, 6, 9);
		recode = sheet->writeBlank(0, 6, BordFormat);
		recode = sheet->writeBlank(0, 7, BordFormat);
		recode = sheet->writeBlank(0, 8, BordFormat);
		recode = sheet->writeBlank(0, 9, BordFormat);
		sheet->writeStr(0, 6, QObject::tr("Receiver Device").toLocal8Bit().data());
		recode = sheet->writeBlank(1, 2, BordFormat);
		sheet->writeStr(1, 2, QObject::tr("Virtual terminal definition").toLocal8Bit().data());
		recode = sheet->writeBlank(1, 3, BordFormat);
		sheet->writeStr(1, 3, QObject::tr("Device Name").toLocal8Bit().data());
		recode = sheet->writeBlank(1, 4, BordFormat);
		sheet->writeStr(1, 4, QObject::tr("Virtual terminal Index").toLocal8Bit().data());
		recode = sheet->writeBlank(1, 5, BordFormat);
		sheet->writeStr(1, 5, QObject::tr("Data Attribute").toLocal8Bit().data());
		recode = sheet->writeBlank(1, 6, BordFormat);
		sheet->writeStr(1, 6, QObject::tr("Virtual terminal definition").toLocal8Bit().data());
		recode = sheet->writeBlank(1, 7, BordFormat);
		sheet->writeStr(1, 7, QObject::tr("Device Name").toLocal8Bit().data());
		recode = sheet->writeBlank(1, 8, BordFormat);
		sheet->writeStr(1, 8, QObject::tr("Virtual terminal Index").toLocal8Bit().data());
		recode = sheet->writeBlank(1, 9, BordFormat);
		sheet->writeStr(1, 9, QObject::tr("Data Attribute").toLocal8Bit().data());
		Write_DataSet2File(IED_Map.value(IEDList.at(i)), sheet, BordFormat);

		sheet->setCol(0, 9, -1);
	}
	Bar->setValue(100);
	//	if (FilePath.at(FilePath.length() - 1) == "/")
	//	{
	//		FilePath += "Vitrtul.xls";
	//	}
	//     else
	//        {
	//	FilePath += "/Vitrtul.xls";
	//        }

	FilePath += ".xls";
	recode = book->save(FilePath.toLocal8Bit().data());
	error = QString::fromLocal8Bit(book->errorMessage());
	book->release();
}

void ScdTree::Init_XLSFFIle(QString FileName, QAxObject *pApplication)
{
	QAxObject *cell_1_A = pApplication->querySubObject("Cells(int,int)", 1, 1);
	cell_1_A->setProperty("Value", QObject::tr("Index").toLocal8Bit().data());  //设置单元格值
	QAxObject *cell_1_B = pApplication->querySubObject("Cells(int,int)", 1, 2);
	cell_1_B->setProperty("Value", QObject::tr("DataSet Index").toLocal8Bit().data());  //设置单元格值
	QAxObject *cell_1_C = pApplication->querySubObject("Cells(int,int)", 1, 2);
	cell_1_C->setProperty("Value", QObject::tr("Sender Device").toLocal8Bit().data());  //设置单元格值
	QAxObject *cell_1_G = pApplication->querySubObject("Cells(int,int)", 1, 2);
	cell_1_G->setProperty("Value", QObject::tr("Receiver Device").toLocal8Bit().data());  //设置单元格值


	QString merge_cell;
	merge_cell.append(QChar('A'));  //初始列
	merge_cell.append(QString::number(1));  //初始行
	merge_cell.append(":");
	merge_cell.append(QChar('A'));  //终止列
	merge_cell.append(QString::number(2));  //终止行
	QAxObject *merge_range = pApplication->querySubObject("Range(const QString&)", merge_cell);

	merge_range->setProperty("MergeCells", true);  //合并单元格

	merge_cell.clear();
	merge_cell.append(QChar('B'));  //初始列
	merge_cell.append(QString::number(1));  //初始行
	merge_cell.append(":");
	merge_cell.append(QChar('B'));  //终止列
	merge_cell.append(QString::number(2));  //终止行
	merge_range = pApplication->querySubObject("Range(const QString&)", merge_cell);

	merge_range->setProperty("MergeCells", true);  //合并单元格

	merge_cell.clear();
	merge_cell.append(QChar('C'));  //初始列
	merge_cell.append(QString::number(1));  //初始行
	merge_cell.append(":");
	merge_cell.append(QChar('F'));  //终止列
	merge_cell.append(QString::number(1));  //终止行
	merge_range = pApplication->querySubObject("Range(const QString&)", merge_cell);

	merge_range->setProperty("MergeCells", true);  //合并单元格

	merge_cell.clear();
	merge_cell.append(QChar('G'));  //初始列
	merge_cell.append(QString::number(1));  //初始行
	merge_cell.append(":");
	merge_cell.append(QChar('J'));  //终止列
	merge_cell.append(QString::number(1));  //终止行
	merge_range = pApplication->querySubObject("Range(const QString&)", merge_cell);

	merge_range->setProperty("MergeCells", true);  //合并单元格
	//	cell_2_1->setProperty("RowHeight", 20);  //设置单元格行高
	//	cell_2_1->setProperty("HorizontalAlignment", -4108);
	//	QAxObject* interior = cell_2_1->querySubObject("Interior");
	//interior->setProperty("Color", QColor(0, 0, 255));   //设置单元格背景色（）
	//	QAxObject *font = cell_2_1->querySubObject("Font");  //获取单元格字体
	//	font->setProperty("Size", 20);  //设置单元格字体大小
	//	font->setProperty("Color", QColor(108, 192, 244));

}
int ScdTree::Write_DataSet2File(TiXmlElement* IED, TiXmlElement*Node, int row, QString s_name, QAxObject *pApplication)
{
	int recode;

	recode = Build_Struct_XLS(row, s_name, pApplication);
	TiXmlElement*ExtRef = NULL;
	int index = 1;
	for (ExtRef = Node->FirstChildElement(); ExtRef != NULL; ExtRef = ExtRef->NextSiblingElement())
	{
		Input_Mapping m_data;
		m_data.Index = index;
		Fill_Input_Mapping(IED, ExtRef, m_data);
		Write_Input_Mapping(recode, m_data, pApplication);
		index++;
		recode++;
	}

	return recode;
}
int ScdTree::Write_DataSet2File(TiXmlElement* IED, Sheet* m_sheet, Format* dataFormat)
{
	int recode = 0;
	QMap<QString, TiXmlElement*> Map_LD;
	QMap<QString, TiXmlElement*> Map_LN;
	QMap<QString, TiXmlElement*> Map_ExtRef;
	TiXmlElement*m_LD = NULL;
	TiXmlElement*m_LN = NULL;
	TiXmlElement*m_INPUT = NULL;
	TiXmlElement*ExtRef = NULL;
	Init_LD_MAP(IED, Map_LD);
	int m_Row = 2;
	int m_Index = 1;
	for (int i = 0; i < Map_LD.uniqueKeys().size(); i++)
	{
		m_LD = Map_LD.value(Map_LD.uniqueKeys().at(i));
		Init_LN_MAP(m_LD, Map_LN);
		for (int j = 0; j < Map_LN.uniqueKeys().size(); j++)
		{
			m_LN = Map_LN.value(Map_LN.uniqueKeys().at(j));
			m_INPUT = m_LN->FirstChildElement("Inputs");
			Init_Child_Map(m_INPUT, Map_ExtRef, "iedName");
			QVector<Input_Mapping  > dataList;
			for (int m = 0; m < Map_ExtRef.uniqueKeys().size(); m++)
			{
				dataList.clear();
				for (int n = Map_ExtRef.values(Map_ExtRef.uniqueKeys().at(m)).size() - 1; n >= 0; n--)
				{
					Input_Mapping m_data;
					ExtRef = Map_ExtRef.values(Map_ExtRef.uniqueKeys().at(m)).at(n);
					m_data.Index = GetIndexByChild(ExtRef->Parent()->ToElement(), ExtRef);
					Fill_Input_Mapping(IED, ExtRef, m_data);
					dataList.append(m_data);

				}
				QMap<int, Input_Mapping> Map_Data;
				foreach(const Input_Mapping &m_data, dataList)
				{
					Map_Data.insert(m_data.Index, m_data);
				}
				for (int k = 0; k < Map_Data.uniqueKeys().size(); k++)
				{
					Input_Mapping data = Map_Data.value(Map_Data.uniqueKeys().at(k));
					Write_Input_Mapping(m_Row, m_Index, data, m_sheet, dataFormat);
					m_Index++;
					m_Row++;
				}
				if (dataList.size() != 0)
				{
					m_Row = m_Row + 4;
				}
			}



		}
	}


	return recode;
}

void ScdTree::Fill_Input_Mapping(TiXmlElement*IED, TiXmlElement*ExtRef, Input_Mapping&m_data)
{
	const char* chr;
	QString strcrc;
	QString IedName;
	QString LDName;
	QString LNName;
	QString DOName;
	QString DAName;
	QStringList SDINameList;
	int index;
	QString strintAddr;
	chr = IED->Attribute("name");
	IedName += chr;

	chr = IED->Attribute("desc");
	if (chr != NULL)
	{
		IedName += ":";
		IedName += chr;
	}

	m_data.Interior_IED = IedName;
	chr = ExtRef->Attribute("intAddr");
	m_data.Interior_Reference += chr;
	strintAddr += chr;
	index = strintAddr.indexOf("/");
	LDName = strintAddr.left(index);
	strintAddr = strintAddr.right(strintAddr.length() - index - 1);
	strintAddr = strintAddr.remove("/");
	index = strintAddr.indexOf(".");
	LNName = strintAddr.left(index);
	strintAddr = strintAddr.right(strintAddr.length() - index - 1);
	index = strintAddr.indexOf(".");
	DOName = strintAddr.left(index);
	SDINameList = strintAddr.left(strintAddr.length() - index - 1).split(".");
	QMap<QString, TiXmlElement*>LD_Map;
	Init_LD_MAP(IED, LD_Map);
	TiXmlElement* m_LD = NULL;
	m_LD = LD_Map.value(LDName);
	if (m_LD == NULL)
	{
		return;
	}
	QMap<QString, TiXmlElement*>LN_Map;
	Init_LN_MAP(m_LD, LN_Map);
	TiXmlElement* m_LN = NULL;
	m_LN = LN_Map.value(LNName);
	if (m_LN == NULL)
	{
		return;
	}
	QMap<QString, TiXmlElement*>DO_Map;
	Init_DO_MAP(m_LN, DO_Map);
	TiXmlElement* m_DO = NULL;
	m_DO = DO_Map.value(DOName);
	if (m_DO == NULL)
	{
		return;
	}
	chr = NULL;
	if (m_DO != NULL)
	{
		if (m_DO->Attribute("desc") != NULL)
		{
			chr = m_DO->Attribute("desc");
			m_data.Interior_ReferenceDesc += chr;
		}
	}
	else
	{
		m_data.Interior_ReferenceDesc = QObject::tr("invalide");
	}
	//return;


	//m_data.Interior_ReferenceDesc += chr;
	// QString::fromStdString(chr);
	QMap<QString, TiXmlElement*>SDI_Map;
	Init_SDI_MAP(m_DO, SDI_Map);

	TiXmlElement* m_SDI = NULL;

	m_SDI = SDI_Map.value(SDINameList.at(0));
	if (m_SDI != NULL)
	{
		chr = m_SDI->Attribute("desc");
		m_data.Interior_ReferenceDesc += chr;
		SDINameList.removeAt(0);

		while (SDINameList.size() > 0)
		{
			SDI_Map.clear();
			Init_SDI_MAP(m_SDI, SDI_Map);

			m_SDI = SDI_Map.value(SDINameList.at(0));
			if (m_SDI != NULL)
			{
				chr = m_SDI->Attribute("desc");
				if (chr == NULL)
					break;
				//m_data.Interior_ReferenceDesc += chr;
				m_data.Interior_ReferenceDesc += chr;
				SDINameList.removeAt(0);
			}

		}
	}

	QMap<QString, TiXmlElement*>IED_Map;
	Init_IED_MAP(root, IED_Map);
	TiXmlElement* m_IED = NULL;

	chr = ExtRef->Attribute("iedName");
	IedName.clear();
	IedName += chr;
	m_IED = IED_Map.value(IedName);
	if (m_IED == NULL)
	{
		return;
	}
	chr = m_IED->Attribute("desc");
	if (chr != NULL)
	{
		IedName += ":";
		IedName += chr;
	}
	chr = ExtRef->Attribute("ldInst");
	LDName.clear();
	LDName += chr;
	m_data.External_IED = IedName;
	LD_Map.clear();
	Init_LD_MAP(m_IED, LD_Map);

	m_LD = LD_Map.value(LDName);
	if (m_LD == NULL)
	{
		return;
	}
	LNName.clear();
	chr = ExtRef->Attribute("prefix");
	LNName += chr;
	chr = ExtRef->Attribute("lnClass");
	LNName += chr;
	chr = ExtRef->Attribute("lnInst");
	LNName += chr;
	LN_Map.clear();
	Init_LN_MAP(m_LD, LN_Map);
	m_LN = LN_Map.value(LNName);
	if (m_LN == NULL)
	{
		return;
	}
	chr = ExtRef->Attribute("doName");
	DOName.clear();
	DOName += chr;
	chr = ExtRef->Attribute("daName");
	DAName.clear();
	DAName += chr;
	SDINameList = DOName.split(".");
	DO_Map.clear();
	Init_DO_MAP(m_LN, DO_Map);
	m_DO = DO_Map.value(SDINameList.at(0));
	if (m_DO == NULL)
	{
		return;
	}
	chr = m_DO->Attribute("desc");
	m_data.External_ReferenceDesc += chr;
	SDINameList.removeAt(0);


	if (SDINameList.size() != 0)
	{
		Init_SDI_MAP(m_DO, SDI_Map);
		m_SDI = SDI_Map.value(SDINameList.at(0));
		if (m_SDI == NULL)
		{
			return;
		}
		chr = m_SDI->Attribute("desc");
		m_data.External_ReferenceDesc += chr;
		SDINameList.removeAt(0);

		while (SDINameList.size() > 0)
		{
			SDI_Map.clear();
			Init_SDI_MAP(m_SDI, SDI_Map);

			m_SDI = SDI_Map.value(SDINameList.at(0));
			if (m_SDI == NULL)
			{
				return;
			}
			chr = m_SDI->Attribute("desc");
			if (chr == NULL)
				break;
			m_data.External_ReferenceDesc += chr;
			SDINameList.removeAt(0);
		}
	}
	m_data.External_Reference = LDName + "/" + LNName + "." + DOName;
	if (!DAName.isEmpty())
	{
		m_data.External_Reference += "." + DAName;
	}
	chr = ExtRef->Attribute("iedName");
	strcrc += chr;
	chr = ExtRef->Attribute("ldInst");
	strcrc += chr;
	chr = ExtRef->Attribute("prefix");
	strcrc += chr;
	chr = ExtRef->Attribute("lnClass");
	strcrc += chr;
	chr = ExtRef->Attribute("lnInst");
	strcrc += chr;
	chr = ExtRef->Attribute("doName");
	strcrc += chr;
	chr = ExtRef->Attribute("daName");
	strcrc += chr;
	strcrc = strcrc.simplified();
	TiXmlElement* m_Node = NULL;
	TiXmlElement* m_ControlBlock = NULL;
	m_Node = FCDA_MAP.value(strcrc);

	index = GetIndexByChild(m_Node->Parent()->ToElement(), m_Node);
	m_data.External_Index = QString::number(index, 10);
	m_Node = m_Node->Parent()->ToElement();
	chr = m_Node->Attribute("name");

	m_data.External_DataSet += chr;
	m_Node = m_Node->Parent()->ToElement();
	int state = 0;
	if (m_data.External_DataSet.contains("goose", Qt::CaseInsensitive))
	{
		m_ControlBlock = m_Node->FirstChildElement("GSEControl");
		for (; m_ControlBlock != NULL; m_ControlBlock = m_ControlBlock->NextSiblingElement("GSEControl"))
		{
			if (0 == strcmp(m_ControlBlock->Attribute("datSet"), chr))
			{
				chr = m_ControlBlock->Attribute("name");
				m_data.External_Block += chr;
				chr = m_ControlBlock->Attribute("appID");
				m_data.External_APPID += chr;
				state = GOOSENTPARA;
				break;
			}
		}
	}
	if (m_data.External_DataSet.contains("SV", Qt::CaseInsensitive))
	{
		m_ControlBlock = m_Node->FirstChildElement("SampledValueControl");
		for (; m_ControlBlock != NULL; m_ControlBlock = m_ControlBlock->NextSiblingElement("SampledValueControl"))
		{
			if (0 == strcmp(m_ControlBlock->Attribute("datSet"), chr))
			{
				chr = m_ControlBlock->Attribute("name");
				m_data.External_Block += chr;
				chr = m_ControlBlock->Attribute("smvID");
				m_data.External_APPID += chr;
				state = SMVNTPARA;
				break;
			}
		}
	}
	m_Node = m_LD->Parent()->ToElement();
	m_Node = m_Node->Parent()->ToElement();

	QString strAp, stried;
	chr = m_Node->Attribute("name");
	strAp += chr;
	chr = ExtRef->Attribute("iedName");;
	stried += chr;
	TiXmlElement* m_Communication = NULL;
	TiXmlElement* m_SubnetWork = NULL;
	TiXmlElement* m_ConnectAP = NULL;
	TiXmlElement* m_Address = NULL;
	TiXmlElement* m_P = NULL;
	TiXmlText* m_Text = NULL;
	m_Communication = root->FirstChildElement("Communication");
	for (m_SubnetWork = m_Communication->FirstChildElement(); m_SubnetWork != NULL; m_SubnetWork = m_SubnetWork->NextSiblingElement())
	{
		QMap<QString, TiXmlElement*>Ap_Map;
		Init_ConnectAP_MAP(m_SubnetWork, Ap_Map);
		m_ConnectAP = Ap_Map.value(stried);
		if (m_ConnectAP == NULL)
		{
			continue;
		}
		if (0 == strcmp(strAp.toLocal8Bit().data(), m_ConnectAP->Attribute("apName")))
		{
			break;
		}
	}
	if (state == GOOSENTPARA)
	{
		m_Node = m_ConnectAP->FirstChildElement("GSE");
	}
	else if (state == SMVNTPARA)
	{
		m_Node = m_ConnectAP->FirstChildElement("SMV");
	}
	if (m_Node == NULL)
	{
		return;
	}
	m_Address = m_Node->FirstChildElement("Address");
	if (m_Address == NULL)
	{
		return;
	}
	for (m_P = m_Address->FirstChildElement("P"); m_P != NULL; m_P = m_P->NextSiblingElement("P"))
	{
		if (0 == strcmp("MAC-Address", m_P->Attribute("type")))
		{
			m_Text = m_P->FirstChild()->ToText();
			chr = m_Text->Value();
			m_data.External_MACAddr += chr;
			break;
		}
	}
}
void ScdTree::Write_Input_Mapping(int row, Input_Mapping&m_data, QAxObject*pApplication)
{
	std::string str;

	//const char* ch;
	QAxObject* interior;
	QAxObject *cell = pApplication->querySubObject("Cells(int,int)", row, 1);
	cell = pApplication->querySubObject("Cells(int,int)", row, 1);
	cell->setProperty("Value", m_data.Index);
	interior = cell->querySubObject("Interior");
	if (row % 2 == 0)
	{
		interior->setProperty("Color", QColor(219, 229, 255));   //设置单元格背景色（）
	}
	else
	{
		interior->setProperty("Color", QColor(150, 204, 255));   //设置单元格背景色（）
	}

	cell = pApplication->querySubObject("Cells(int,int)", row, 2);
	cell->setProperty("Value", m_data.Interior_IED);
	interior = cell->querySubObject("Interior");
	if (row % 2 == 0)
	{
		interior->setProperty("Color", QColor(219, 229, 255));   //设置单元格背景色（）
	}
	else
	{
		interior->setProperty("Color", QColor(150, 204, 255));   //设置单元格背景色（）
	}
	cell = pApplication->querySubObject("Cells(int,int)", row, 3);
	cell->setProperty("Value", m_data.Interior_Reference);
	interior = cell->querySubObject("Interior");
	if (row % 2 == 0)
	{
		interior->setProperty("Color", QColor(219, 229, 255));   //设置单元格背景色（）
	}
	else
	{
		interior->setProperty("Color", QColor(150, 204, 255));   //设置单元格背景色（）
	}
	cell = pApplication->querySubObject("Cells(int,int)", row, 4);
	cell->setProperty("Value", m_data.Interior_ReferenceDesc);
	interior = cell->querySubObject("Interior");
	if (row % 2 == 0)
	{
		interior->setProperty("Color", QColor(219, 229, 255));   //设置单元格背景色（）
	}
	else
	{
		interior->setProperty("Color", QColor(150, 204, 255));   //设置单元格背景色（）
	}
	cell = pApplication->querySubObject("Cells(int,int)", row, 5);
	cell->setProperty("Value", QObject::tr("<<"));
	interior = cell->querySubObject("Interior");
	if (row % 2 == 0)
	{
		interior->setProperty("Color", QColor(219, 229, 255));   //设置单元格背景色（）
	}
	else
	{
		interior->setProperty("Color", QColor(150, 204, 255));   //设置单元格背景色（）
	}
	cell = pApplication->querySubObject("Cells(int,int)", row, 6);
	cell->setProperty("Value", m_data.External_IED);
	interior = cell->querySubObject("Interior");
	if (row % 2 == 0)
	{
		interior->setProperty("Color", QColor(219, 229, 255));   //设置单元格背景色（）
	}
	else
	{
		interior->setProperty("Color", QColor(150, 204, 255));   //设置单元格背景色（）
	}
	cell = pApplication->querySubObject("Cells(int,int)", row, 7);
	cell->setProperty("Value", m_data.External_Reference);
	interior = cell->querySubObject("Interior");
	if (row % 2 == 0)
	{
		interior->setProperty("Color", QColor(219, 229, 255));   //设置单元格背景色（）
	}
	else
	{
		interior->setProperty("Color", QColor(150, 204, 255));   //设置单元格背景色（）
	}
	cell = pApplication->querySubObject("Cells(int,int)", row, 8);
	cell->setProperty("Value", m_data.External_ReferenceDesc);
	interior = cell->querySubObject("Interior");
	if (row % 2 == 0)
	{
		interior->setProperty("Color", QColor(219, 229, 255));   //设置单元格背景色（）
	}
	else
	{
		interior->setProperty("Color", QColor(150, 204, 255));   //设置单元格背景色（）
	}
	cell = pApplication->querySubObject("Cells(int,int)", row, 9);
	cell->setProperty("Value", m_data.External_DataSet);
	interior = cell->querySubObject("Interior");
	if (row % 2 == 0)
	{
		interior->setProperty("Color", QColor(219, 229, 255));   //设置单元格背景色（）
	}
	else
	{
		interior->setProperty("Color", QColor(150, 204, 255));   //设置单元格背景色（）
	}
	cell = pApplication->querySubObject("Cells(int,int)", row, 10);
	cell->setProperty("Value", m_data.External_Block);
	interior = cell->querySubObject("Interior");
	if (row % 2 == 0)
	{
		interior->setProperty("Color", QColor(219, 229, 255));   //设置单元格背景色（）
	}
	else
	{
		interior->setProperty("Color", QColor(150, 204, 255));   //设置单元格背景色（）
	}
	cell = pApplication->querySubObject("Cells(int,int)", row, 11);
	cell->setProperty("Value", m_data.External_MACAddr);
	interior = cell->querySubObject("Interior");
	if (row % 2 == 0)
	{
		interior->setProperty("Color", QColor(219, 229, 255));   //设置单元格背景色（）
	}
	else
	{
		interior->setProperty("Color", QColor(150, 204, 255));   //设置单元格背景色（）
	}
	cell = pApplication->querySubObject("Cells(int,int)", row, 12);
	cell->setProperty("Value", m_data.External_APPID);
	interior = cell->querySubObject("Interior");
	if (row % 2 == 0)
	{
		interior->setProperty("Color", QColor(219, 229, 255));   //设置单元格背景色（）
	}
	else
	{
		interior->setProperty("Color", QColor(150, 204, 255));   //设置单元格背景色（）
	}
	cell = pApplication->querySubObject("Cells(int,int)", row, 13);
	cell->setProperty("Value", m_data.External_Index);
	interior = cell->querySubObject("Interior");
	if (row % 2 == 0)
	{
		interior->setProperty("Color", QColor(219, 229, 255));   //设置单元格背景色（）
	}
	else
	{
		interior->setProperty("Color", QColor(150, 204, 255));   //设置单元格背景色（）
	}
}
void ScdTree::Write_Input_Mapping(int row, int index, Input_Mapping& data, Sheet*m_sheet, Format*dataFormat)
{
	m_sheet->writeBlank(row, 0, dataFormat);
	m_sheet->writeNum(row, 0, index);
	m_sheet->writeBlank(row, 1, dataFormat);
	m_sheet->writeStr(row, 1, data.External_DataSet.toLocal8Bit().data());
	m_sheet->writeBlank(row, 2, dataFormat);
	m_sheet->writeStr(row, 2, data.External_ReferenceDesc.toLocal8Bit().data());
	m_sheet->writeBlank(row, 3, dataFormat);
	m_sheet->writeStr(row, 3, data.External_IED.toLocal8Bit().data());
	m_sheet->writeBlank(row, 4, dataFormat);
	QString str = "GOOUT_" + data.External_Index;
	m_sheet->writeStr(row, 4, str.toLocal8Bit().data());
	m_sheet->writeBlank(row, 5, dataFormat);
	m_sheet->writeStr(row, 5, data.External_Reference.toLocal8Bit().data());
	m_sheet->writeBlank(row, 6, dataFormat);
	m_sheet->writeStr(row, 6, data.Interior_ReferenceDesc.toLocal8Bit().data());
	m_sheet->writeBlank(row, 7, dataFormat);
	m_sheet->writeStr(row, 7, data.Interior_IED.toLocal8Bit().data());
	m_sheet->writeBlank(row, 8, dataFormat);
	str.clear();
	str += "GOOIN_";
	str += QString::number(data.Index);
	m_sheet->writeStr(row, 8, str.toLocal8Bit().data());
	m_sheet->writeBlank(row, 9, dataFormat);
	m_sheet->writeStr(row, 9, data.Interior_Reference.toLocal8Bit().data());
}

int ScdTree::Build_Struct_XLS(int row, QString s_name, QAxObject*pApplication)
{
	QAxObject* interior;
	QString strcell;

	QAxObject *cell = pApplication->querySubObject("Cells(int,int)", row, 1);
	cell->setProperty("Value", s_name.toLocal8Bit().data());  //设置单元格值
	QString merge_cell;
	merge_cell.append(QChar('A'));  //初始列
	merge_cell.append(QString::number(row));  //初始行
	merge_cell.append(":");
	merge_cell.append(QChar(2 + 'A'));  //终止列
	merge_cell.append(QString::number(row));  //终止行
	QAxObject *merge_range = pApplication->querySubObject("Range(const QString&)", merge_cell);
	merge_range->setProperty("MergeCells", true);  //合并单元格
	row++;
	cell = pApplication->querySubObject("Cells(int,int)", row, 1);

	cell->setProperty("Value", QObject::tr("Index"));
	cell->setProperty("ColumnWidth", 7.63);  //设置单元格行宽
	interior = cell->querySubObject("Interior");
	interior->setProperty("Color", QColor(221, 217, 195));   //设置单元格背景色（）
	cell = pApplication->querySubObject("Cells(int,int)", row, 2);
	cell->setProperty("ColumnWidth", 18.75);  //设置单元格行宽

	cell->setProperty("Value", QObject::tr("Interior IED Name"));
	interior = cell->querySubObject("Interior");
	interior->setProperty("Color", QColor(221, 217, 195));   //设置单元格背景色（）
	cell = pApplication->querySubObject("Cells(int,int)", row, 3);
	cell->setProperty("ColumnWidth", 28.75);  //设置单元格行宽


	cell->setProperty("Value", QObject::tr("Interior Reference"));
	interior = cell->querySubObject("Interior");
	interior->setProperty("Color", QColor(221, 217, 195));   //设置单元格背景色（）
	cell = pApplication->querySubObject("Cells(int,int)", row, 4);
	cell->setProperty("ColumnWidth", 18.75);  //设置单元格行宽

	cell->setProperty("Value", QObject::tr("Interior IED Desc"));
	interior = cell->querySubObject("Interior");
	interior->setProperty("Color", QColor(221, 217, 195));   //设置单元格背景色（）
	cell = pApplication->querySubObject("Cells(int,int)", row, 5);
	cell->setProperty("ColumnWidth", 2.88);  //设置单元格行宽

	interior = cell->querySubObject("Interior");
	interior->setProperty("Color", QColor(221, 217, 195));   //设置单元格背景色（）
	cell = pApplication->querySubObject("Cells(int,int)", row, 6);
	cell->setProperty("ColumnWidth", 18.75);  //设置单元格行宽

	cell->setProperty("Value", QObject::tr("External IED Name"));
	interior = cell->querySubObject("Interior");
	interior->setProperty("Color", QColor(221, 217, 195));   //设置单元格背景色（）
	cell = pApplication->querySubObject("Cells(int,int)", row, 7);
	cell->setProperty("ColumnWidth", 24.38);  //设置单元格行宽

	cell->setProperty("Value", QObject::tr("External IED Reference"));
	interior = cell->querySubObject("Interior");
	interior->setProperty("Color", QColor(221, 217, 195));   //设置单元格背景色（）
	cell = pApplication->querySubObject("Cells(int,int)", row, 8);
	cell->setProperty("ColumnWidth", 18.75);  //设置单元格行宽

	cell->setProperty("Value", QObject::tr("External IED Desc"));
	interior = cell->querySubObject("Interior");
	interior->setProperty("Color", QColor(221, 217, 195));   //设置单元格背景色（）
	cell = pApplication->querySubObject("Cells(int,int)", row, 9);
	cell->setProperty("ColumnWidth", 23.25);  //设置单元格行宽

	cell->setProperty("Value", QObject::tr("External DataSet Name"));
	interior = cell->querySubObject("Interior");
	interior->setProperty("Color", QColor(221, 217, 195));   //设置单元格背景色（）
	cell = pApplication->querySubObject("Cells(int,int)", row, 10);
	cell->setProperty("ColumnWidth", 29.88);  //设置单元格行宽

	cell->setProperty("Value", QObject::tr("External Control Block Name"));
	interior = cell->querySubObject("Interior");
	interior->setProperty("Color", QColor(221, 217, 195));   //设置单元格背景色（）
	cell = pApplication->querySubObject("Cells(int,int)", row, 11);
	cell->setProperty("ColumnWidth", 22.13);  //设置单元格行宽

	cell->setProperty("Value", QObject::tr("External MaC Address"));
	interior = cell->querySubObject("Interior");
	interior->setProperty("Color", QColor(221, 217, 195));   //设置单元格背景色（）

	cell = pApplication->querySubObject("Cells(int,int)", row, 12);
	cell->setProperty("ColumnWidth", 15.25);  //设置单元格行宽

	cell->setProperty("Value", QObject::tr("External APPID"));
	interior = cell->querySubObject("Interior");
	interior->setProperty("Color", QColor(221, 217, 195));   //设置单元格背景色（）
	cell = pApplication->querySubObject("Cells(int,int)", row, 13);
	cell->setProperty("ColumnWidth", 27.63);  //设置单元格行宽
	//cell->setProperty("WrapText", true);

	cell->setProperty("Value", QObject::tr("Index In External DataSet"));
	interior = cell->querySubObject("Interior");
	interior->setProperty("Color", QColor(221, 217, 195));   //设置单元格背景色（）
	row++;
	return row;
}
int ScdTree::SwitchToNode(QString ied, QString ld, QString ln)
{
	QMap<QString, TiXmlElement*>IED_Map;
	Init_IED_MAP(root, IED_Map);
	TiXmlElement* m_IED = NULL;
	m_IED = IED_Map.value(ied);
	if (ld.isEmpty())
	{
		CurElement = m_IED;
		return DO_OK;
	}
	QMap<QString, TiXmlElement*>LD_Map;
	Init_LD_MAP(m_IED, LD_Map);
	TiXmlElement* m_LD = NULL;
	m_LD = LD_Map.value(ld);
	if (ln.isEmpty())
	{
		CurElement = m_LD;
		return DO_OK;
	}
	QMap<QString, TiXmlElement*>LN_Map;
	Init_LN_MAP(m_LD, LN_Map);
	TiXmlElement* m_LN = NULL;
	m_LN = LN_Map.value(ln);
	CurElement = m_LN;
	return DO_OK;
}
void ScdTree::Init_FCDA_MAP()
{
	FCDAPoint_Vector.clear();
	QStringList key_ied, key_ld, key_ln, key_DataSet;
	QString strcrc;
	const char* chr;
	QMap<QString, TiXmlElement*>IED_Map;
	Init_IED_MAP(root, IED_Map);
	key_ied = IED_Map.keys();
	for (int i = 0; i < key_ied.size(); i++)
	{

		TiXmlElement* m_IED = NULL;
		m_IED = IED_Map.value(key_ied[i]);

		QMap<QString, TiXmlElement*>LD_Map;
		Init_LD_MAP(m_IED, LD_Map);
		key_ld = LD_Map.keys();
		for (int j = 0; j < key_ld.size(); j++)
		{
			TiXmlElement* m_LD = NULL;
			m_LD = LD_Map.value(key_ld[j]);

			QMap<QString, TiXmlElement*>LN_Map;
			Init_LN_MAP(m_LD, LN_Map);
			key_ln = LN_Map.keys();
			for (int k = 0; k < key_ln.size(); k++)
			{
				TiXmlElement* m_LN = NULL;
				m_LN = LN_Map.value(key_ln[k]);
				QMap<QString, TiXmlElement*>DataSet_Map;
				Init_DataSet_MAP(m_LN, DataSet_Map);

				key_DataSet = DataSet_Map.keys();
				for (int m = 0; m < key_DataSet.size(); m++)
				{
					TiXmlElement* m_DataSet = NULL;
					m_DataSet = DataSet_Map.value(key_DataSet[m]);
					TiXmlElement* m_FCDA = NULL;
					for (m_FCDA = m_DataSet->FirstChildElement(); m_FCDA != NULL; m_FCDA = m_FCDA->NextSiblingElement())
					{
						strcrc.clear();
						chr = m_IED->Attribute("name");
						strcrc += chr;
						chr = m_FCDA->Attribute("ldInst");
						strcrc += chr;
						chr = m_FCDA->Attribute("prefix");
						strcrc += chr;
						chr = m_FCDA->Attribute("lnClass");
						strcrc += chr;
						chr = m_FCDA->Attribute("lnInst");
						strcrc += chr;
						chr = m_FCDA->Attribute("doName");
						strcrc += chr;
						chr = m_FCDA->Attribute("daName");
						strcrc += chr;
						strcrc = strcrc.simplified();
						FCDA_MAP.insert(strcrc, m_FCDA);
					}

				}
			}

		}

	}

}
void ScdTree::Init_DataSet_MAP(TiXmlElement* LN, QMap<QString, TiXmlElement* >&Map)
{
	TiXmlElement* Child = NULL;
	const char* chr;
	Map.clear();
	for (Child = LN->FirstChildElement("DataSet"); Child != NULL; Child = Child->NextSiblingElement("DataSet"))
	{
		QString Dataset;
		chr = Child->Attribute("name");
		Dataset += chr;
		Dataset = Dataset.simplified();
		Map.insert(Dataset, Child);
	}
}
void ScdTree::Init_DataSet_MAP(TiXmlElement* LN, QMap<QString, TiXmlElement* >&Map, int state)
{
	TiXmlElement* Child = NULL;
	const char* chr;

	for (Child = LN->FirstChildElement("DataSet"); Child != NULL; Child = Child->NextSiblingElement("DataSet"))
	{
		QString Dataset;
		chr = LN->Parent()->ToElement()->Attribute("inst");
		Dataset += chr;
		Dataset += ":";
		chr = LN->Attribute("prefix");
		Dataset += chr;
		chr = LN->Attribute("lnType");
		Dataset += chr;
		chr = LN->Attribute("inst");
		Dataset += chr;
		Dataset = Dataset.simplified();
		Map.insertMulti(Dataset, Child);
	}
}
void ScdTree::Init_ControBlock_MAP(TiXmlElement*LN, QMap<QString, TiXmlElement* >&Map, int state)
{
	TiXmlElement* Child = NULL;
	const char* chr;
	Map.clear();
	if (state == 0)
	{
		for (Child = LN->FirstChildElement("ReportControl"); Child != NULL; Child = Child->NextSiblingElement("ReportControl"))
		{
			QString str;
			chr = Child->Parent()->Value();
			str += chr;
			str += ":";
			chr = LN->Attribute("prefix");
			str += chr;
			chr = LN->Attribute("lnClass");
			str += chr;
			chr = LN->Attribute("inst");
			str += chr;
			str = str.simplified();
			Map.insertMulti(str, Child);
		}
		for (Child = LN->FirstChildElement("SampledValueControl"); Child != NULL; Child = Child->NextSiblingElement("SampledValueControl"))
		{
			QString str;
			chr = Child->Parent()->Value();
			str += chr;
			str += ":";
			chr = LN->Attribute("prefix");
			str += chr;
			chr = LN->Attribute("lnClass");
			str += chr;
			chr = LN->Attribute("inst");
			str += chr;
			str = str.simplified();
			Map.insertMulti(str, Child);
		}
		for (Child = LN->FirstChildElement("GSEControl"); Child != NULL; Child = Child->NextSiblingElement("GSEControl"))
		{
			QString str;
			chr = Child->Parent()->Value();
			str += chr;
			str += ":";
			chr = LN->Attribute("prefix");
			str += chr;
			chr = LN->Attribute("lnClass");
			str += chr;
			chr = LN->Attribute("inst");
			str += chr;
			str = str.simplified();
			Map.insertMulti(str, Child);
		}
	}
	else if (state == 1)
	{
		for (Child = LN->FirstChildElement("ReportControl"); Child != NULL; Child = Child->NextSiblingElement("ReportControl"))
		{
			QString str;
			chr = Child->Attribute("name");
			str += chr;
			Map.insertMulti(str, Child);
		}
	}
	else if (state == 2)
	{
		for (Child = LN->FirstChildElement("GSEControl"); Child != NULL; Child = Child->NextSiblingElement("GSEControl"))
		{
			QString str;
			chr = Child->Attribute("name");
			str += chr;
			Map.insertMulti(str, Child);
		}
	}
	else if (state == 3)
	{
		for (Child = LN->FirstChildElement("SampledValueControl"); Child != NULL; Child = Child->NextSiblingElement("SampledValueControl"))
		{
			QString str;
			chr = Child->Attribute("name");
			str += chr;
			Map.insertMulti(str, Child);
		}
	}
	else if (state == 4)
	{
		for (Child = LN->FirstChildElement("LogControl"); Child != NULL; Child = Child->NextSiblingElement("LogControl"))
		{
			QString str;
			chr = Child->Attribute("name");
			str += chr;
			Map.insertMulti(str, Child);
		}
	}

}
void ScdTree::Init_ControBlock_MAP(TiXmlElement*LN, QMap<QString, TiXmlElement* >&Map)
{
	TiXmlElement* Child = NULL;
	const char* chr;
	for (Child = LN->FirstChildElement("ReportControl"); Child != NULL; Child = Child->NextSiblingElement("ReportControl"))
	{
		QString str;
		chr = Child->Parent()->Value();
		str += chr;
		str += ":";
		chr = LN->Attribute("prefix");
		str += chr;
		chr = LN->Attribute("lnClass");
		str += chr;
		chr = LN->Attribute("inst");
		str += chr;
		str = str.simplified();
		Map.insertMulti(str, Child);
	}
	for (Child = LN->FirstChildElement("SampledValueControl"); Child != NULL; Child = Child->NextSiblingElement("SampledValueControl"))
	{
		QString str;
		chr = Child->Parent()->Value();
		str += chr;
		str += ":";
		chr = LN->Attribute("prefix");
		str += chr;
		chr = LN->Attribute("lnClass");
		str += chr;
		chr = LN->Attribute("inst");
		str += chr;
		str = str.simplified();
		Map.insertMulti(str, Child);
	}
	for (Child = LN->FirstChildElement("GSEControl"); Child != NULL; Child = Child->NextSiblingElement("GSEControl"))
	{
		QString str;
		chr = Child->Parent()->Value();
		str += chr;
		str += ":";
		chr = LN->Attribute("prefix");
		str += chr;
		chr = LN->Attribute("lnClass");
		str += chr;
		chr = LN->Attribute("inst");
		str += chr;
		str = str.simplified();
		Map.insertMulti(str, Child);
	}
}
void ScdTree::Init_Input_MAP(TiXmlElement* LN, QMap<QString, TiXmlElement* >&Map, int stat)
{
	TiXmlElement* Child = NULL;
	const char* chr;

	for (Child = LN->FirstChildElement("Inputs"); Child != NULL; Child = Child->NextSiblingElement("Inputs"))
	{
		QString str;
		chr = LN->Attribute("prefix");
		str += chr;
		chr = LN->Attribute("lnType");
		str += chr;
		chr = LN->Attribute("inst");
		str += chr;
		str = str.simplified();
		Map.insertMulti(str, Child);
	}
}

void ScdTree::Init_Child_Map(TiXmlElement *Node, QMap<QString, TiXmlElement *> &Map, QString Attribute)
{
	TiXmlElement* Child = NULL;
	const char* chr;
	Map.clear();
	if (Node == NULL)
	{
		return;
	}
	for (Child = Node->FirstChildElement(); Child != NULL; Child = Child->NextSiblingElement())
	{
		QString str;
		chr = Child->Attribute(Attribute.toLocal8Bit().data());
		str += chr;
		str = str.simplified();
		Map.insertMulti(str, Child);
	}
}

void ScdTree::Init_GSE_Map(TiXmlElement*Node, QMap<QString, TiXmlElement* >&Map, int state)
{
	TiXmlElement* Child = NULL;
	const char* chr;
	if (state == 0)
	{
		Map.clear();
	}
	if (Node == NULL)
	{
		return;
	}
	for (Child = Node->FirstChildElement("GSEControl"); Child != NULL; Child = Child->NextSiblingElement("GSEControl"))
	{
		QString str;
		chr = Child->Attribute("appID");
		str += chr;
		str = str.simplified();
		Map.insertMulti(str, Child);
	}
}
void ScdTree::Init_SMV_Map(TiXmlElement*Node, QMap<QString, TiXmlElement* >&Map, int state)
{
	TiXmlElement* Child = NULL;
	const char* chr;
	if (state == 0)
	{
		Map.clear();
	}
	if (Node == NULL)
	{
		return;
	}
	for (Child = Node->FirstChildElement("SampledValueControl"); Child != NULL; Child = Child->NextSiblingElement("SampledValueControl"))
	{
		QString str;
		chr = Child->Attribute("smvID");
		str += chr;
		str = str.simplified();
		Map.insertMulti(str, Child);
	}
}
int ScdTree::GetLnListFromLD(QString ied, QString ld, QStringList &list)
{
	const char* chr;
	QMap<QString, TiXmlElement*>IED_Map;
	QMap<QString, TiXmlElement*>LD_Map;

	Init_IED_MAP(root, IED_Map);
	TiXmlElement* m_IED = NULL;
	m_IED = IED_Map.value(ied);

	Init_LD_MAP(m_IED, LD_Map);
	TiXmlElement* m_LD = NULL;
	m_LD = LD_Map.value(ld);
	TiXmlElement* m_LN = NULL;
	for (m_LN = m_LD->FirstChildElement(); m_LN != NULL; m_LN = m_LN->NextSiblingElement())
	{
		QString strLn;
		chr = m_LN->Attribute("prefix");
		strLn += chr;
		chr = m_LN->Attribute("lnClass");
		strLn += chr;
		chr = m_LN->Attribute("inst");
		strLn += chr;
		if (strLn.isEmpty())
		{
			continue;
		}
		list.append(strLn);
	}

	return DO_OK;
}
int ScdTree::GetIndexByChild(TiXmlElement*m_parent, TiXmlElement*m_child)
{
	int index = 1;
	TiXmlElement*m_Ele = NULL;
	for (m_Ele = m_parent->FirstChildElement(); m_Ele != NULL; m_Ele = m_Ele->NextSiblingElement())
	{
		if (m_Ele == m_child)
		{
			return index;
		}
		index++;
	}
	return -1;
}
void ScdTree::Init_ConnectAP_MAP(TiXmlElement*Communication, QMap<QString, TiXmlElement* >&Map, int state)
{
	TiXmlElement* SubNe = NULL;
	TiXmlElement* ConnectAP = NULL;
	//TiXmlElement* Child = NULL;
	if (state == 0)
	{
		const char* chr = NULL;
		for (SubNe = Communication->FirstChildElement(); SubNe != NULL; SubNe = SubNe->NextSiblingElement())
		{
			for (ConnectAP = SubNe->FirstChildElement(); ConnectAP != NULL; ConnectAP = ConnectAP->NextSiblingElement())
			{
				QString strCrc;
				chr = ConnectAP->Attribute("iedName");
				strCrc += chr;
				chr = ConnectAP->Attribute("apName");
				strCrc += chr;
				Map.insert(strCrc, ConnectAP);
			}
		}
	}
	else if (state == 1)
	{
		const char* chr = NULL;
		for (SubNe = Communication->FirstChildElement(); SubNe != NULL; SubNe = SubNe->NextSiblingElement())
		{
			for (ConnectAP = SubNe->FirstChildElement(); ConnectAP != NULL; ConnectAP = ConnectAP->NextSiblingElement())
			{
				QString strCrc;
				chr = ConnectAP->Attribute("iedName");
				strCrc += chr;
				strCrc += ":";
				chr = ConnectAP->Attribute("apName");
				strCrc += chr;
				strCrc += ":";
				Map.insert(strCrc, ConnectAP);
			}
		}
	}
	else if (state == 2)
	{
		const char* chr = NULL;
		for (SubNe = Communication->FirstChildElement(); SubNe != NULL; SubNe = SubNe->NextSiblingElement())
		{
			for (ConnectAP = SubNe->FirstChildElement(); ConnectAP != NULL; ConnectAP = ConnectAP->NextSiblingElement())
			{
				QString strCrc;
				chr = ConnectAP->Attribute("iedName");
				strCrc += chr;
				strCrc += ":";
				chr = ConnectAP->Attribute("apName");
				strCrc += chr;
				strCrc += ":";
				Map.insert(strCrc, ConnectAP);
			}
		}
	}
	else if (state == 3)
	{
		const char* chr = NULL;
		for (SubNe = Communication->FirstChildElement(); SubNe != NULL; SubNe = SubNe->NextSiblingElement())
		{
			for (ConnectAP = SubNe->FirstChildElement(); ConnectAP != NULL; ConnectAP = ConnectAP->NextSiblingElement())
			{
				QString strCrc;
				chr = ConnectAP->Attribute("iedName");
				strCrc += chr;
				strCrc += ":";
				chr = ConnectAP->Attribute("apName");
				strCrc += chr;
				strCrc += ":";
				Map.insert(strCrc, ConnectAP);
			}
		}
	}


}
QString ScdTree::GetSaddrByInst(QString IedName, QString inst, QString &desc)
{
	QMap<QString, TiXmlElement*>IED_Map;
	QMap<QString, TiXmlElement*>LD_Map;
	QMap<QString, TiXmlElement*>LN_Map;
	QStringList strList;
	QString LD, str;
	const char* chr;
	int index;
	index = inst.indexOf("/");
	LD = inst.left(index);
	strList = inst.right(inst.length() - index - 1).split(".");
	Init_IED_MAP(root, IED_Map);
	TiXmlElement* m_IED = NULL;
	m_IED = IED_Map.value(IedName);

	Init_LD_MAP(m_IED, LD_Map);
	TiXmlElement* m_LD = NULL;
	m_LD = LD_Map.value(LD);
	TiXmlElement* m_LN = NULL;
	Init_LN_MAP(m_LD, LN_Map);
	m_LN = LN_Map.value(strList.at(0));
	strList.removeAt(0);
	TiXmlElement* m_DO = NULL;
	QMap<QString, TiXmlElement*>DO_Map;
	Init_DO_MAP(m_LN, DO_Map);
	m_DO = DO_Map.value(strList.at(0));
	strList.removeAt(0);
	chr = m_DO->Attribute("desc");
	desc += chr;
	if (strList.size() == 1)
	{
		TiXmlElement* m_DA = NULL;
		QMap<QString, TiXmlElement*>DA_Map;
		Init_DAI_MAP(m_DO, DA_Map);
		m_DA = DA_Map.value(strList.at(0));
		if (m_DA == NULL)
		{
			chr = "invalid";
		}
		else
		{
			chr = m_DA->Attribute("sAddr");
			str.clear();
		}

		str += chr;
		return str;
	}
	else
	{
		QMap<QString, TiXmlElement*>SDI_Map;
		Init_SDI_MAP(m_DO, SDI_Map);

		TiXmlElement* m_SDI = NULL;
		m_SDI = SDI_Map.value(strList.at(0));
		if (m_SDI == NULL)
		{
			return str;
		}
		chr = m_SDI->Attribute("desc");
		desc += chr;
		strList.removeAt(0);
		if (m_SDI != NULL)
		{
			while (strList.size() > 1)
			{
				SDI_Map.clear();
				Init_SDI_MAP(m_SDI, SDI_Map);

				m_SDI = SDI_Map.value(strList.at(0));
				chr = m_SDI->Attribute("desc");
				if (chr == NULL)
					break;
				desc += chr;
				strList.removeAt(0);
			}
			if (strList.size() == 1)
			{
				TiXmlElement* m_DA = NULL;
				QMap<QString, TiXmlElement*>DA_Map;
				Init_DAI_MAP(m_DO, DA_Map);
				m_DA = DA_Map.value(strList.at(0));
				if (m_DA == NULL)
				{
					return str;
				}
				chr = m_DA->Attribute("sAddr");
				str.clear();
				str += chr;
				return str;
			}
		}
		return NULL;
	}

}
void ScdTree::GetDoInstVector(QString IED, QString LD, QString LN, QVector<FCDA_Struct>&Map)
{
	QMap<QString, TiXmlElement*>IED_Map;
	QMap<QString, TiXmlElement*>LD_Map;
	QMap<QString, TiXmlElement*>LN_Map;
	QMap<QString, TiXmlElement*>DO_Map;
	QMap<QString, TiXmlElement*>SDI_Map;
	TiXmlElement* m_IED = NULL;
	TiXmlElement* m_LD = NULL;
	TiXmlElement* m_LN = NULL;
	TiXmlElement* m_DO = NULL;
	TiXmlElement* m_SDI = NULL;
	const char* chr;
	Init_IED_MAP(root, IED_Map);
	m_IED = IED_Map.value(IED);
	Init_LD_MAP(m_IED, LD_Map);
	m_LD = LD_Map.value(LD);
	Init_LN_MAP(m_LD, LN_Map);
	m_LN = LN_Map.value(LN);

	Init_DO_MAP(m_LN, DO_Map);
	QStringList keys_1, keys_2;
	keys_1 = DO_Map.keys();
	for (int i = 0; i < keys_1.size(); i++)
	{
		m_DO = DO_Map.value(keys_1[i]);

		Init_SDI_MAP(m_DO, SDI_Map);
		keys_2 = SDI_Map.keys();
		if (keys_2.size() == 0)
		{
			FCDA_Struct m_data;

			chr = m_LD->Attribute("inst");
			m_data.B_ldInst += chr;
			chr = m_LN->Attribute("prefix");
			m_data.B_prefix += chr;
			chr = m_LN->Attribute("lnClass");
			m_data.B_lnClass += chr;
			chr = m_LN->Attribute("inst");
			m_data.B_lnInst += chr;
			chr = m_DO->Attribute("name");
			m_data.B_doName += chr;
			chr = m_DO->Attribute("desc");
			m_data.B_DOdesc += chr;
			Map.append(m_data);
			continue;
		}
		else
		{
			FCDA_Struct m_data;

			chr = m_LD->Attribute("inst");
			m_data.B_ldInst += chr;
			chr = m_LN->Attribute("prefix");
			m_data.B_prefix += chr;
			chr = m_LN->Attribute("lnClass");
			m_data.B_lnClass += chr;
			chr = m_LN->Attribute("inst");
			m_data.B_lnInst += chr;
			chr = m_DO->Attribute("name");
			m_data.B_doName += chr;
			chr = m_DO->Attribute("desc");
			m_data.B_DOdesc += chr;
			Map.append(m_data);
			for (int j = 0; j < keys_2.size(); j++)
			{
				m_data.Clear();
				m_SDI = SDI_Map.value(keys_2[j]);
				chr = m_LD->Attribute("inst");
				m_data.B_ldInst += chr;
				chr = m_LN->Attribute("prefix");
				m_data.B_prefix += chr;
				chr = m_LN->Attribute("lnClass");
				m_data.B_lnClass += chr;
				chr = m_LN->Attribute("inst");
				m_data.B_lnInst += chr;
				chr = m_DO->Attribute("name");
				m_data.B_doName += chr;
				m_data.B_doName += ".";
				chr = m_SDI->Attribute("name");
				m_data.B_doName += chr;
				chr = m_DO->Attribute("desc");
				m_data.B_DOdesc += chr;
				chr = m_SDI->Attribute("desc");
				m_data.B_DOdesc += chr;
				Map.append(m_data);
			}
		}

	}
}
void ScdTree::ClearInputs(TiXmlElement*IED)
{
	QMap<QString, TiXmlElement*>LD_Map;
	QMap<QString, TiXmlElement*>LN_Map;

	TiXmlElement* m_LD = NULL;
	TiXmlElement* m_LN = NULL;
	TiXmlElement* m_INPUT = NULL;
	QStringList keys1, keys2;
	Init_LD_MAP(IED, LD_Map);
	keys1 = LD_Map.keys();
	for (int i = 0; i < keys1.size(); i++)
	{
		m_LD = LD_Map.value(keys1[i]);
		Init_LN_MAP(m_LD, LN_Map);
		keys2 = LN_Map.keys();
		for (int m = 0; m < keys2.size(); m++)
		{
			m_INPUT = NULL;
			m_LN = LN_Map.value(keys2[m]);
			while (m_LN->FirstChildElement("Inputs") != NULL)
			{
				m_INPUT = m_LN->FirstChildElement("Inputs");
				m_LN->RemoveChild(m_INPUT);
			}
			//for (m_INPUT = m_LN->FirstChildElement("Inputs"); m_INPUT != NULL; m_INPUT = m_INPUT->NextSiblingElement("Inputs"))
			//{
			//	
			//	break;
			//}

		}
	}
}
void ScdTree::ClearAllInput()
{
	QMap<QString, TiXmlElement*>IED_Map;
	TiXmlElement* m_IED = NULL;
	Init_IED_MAP(root, IED_Map);
	QStringList keys = IED_Map.keys();
	for (int i = 0; i < keys.size(); i++)
	{
		m_IED = IED_Map.value(keys[i]);
		ClearInputs(m_IED);
	}
}
int ScdTree::CheckDataTempLate(TiXmlDocument *CID, QMap<QString, TiXmlElement*>&LNMap, QMap<QString, TiXmlElement*>&LNTypeMap, QMap<QString, TiXmlElement*>&DOTypeMap,
	QMap<QString, TiXmlElement*>&DATypeMap, QMap<QString, TiXmlElement*>&EnumMap)
{
	QMap<QString, TiXmlElement*>LD_MAP;
	QMap<QString, TiXmlElement*>LN_MAP;
	QMap<QString, TiXmlElement*>IED_LNTYPE_MAP;
	const char* chr;
	TiXmlElement *m_LN = NULL;
	QString str;
	QStringList key_ld, key_ln;

	TiXmlElement  *DataTemp_IN, *DataTemp_EX;
	DataTemp_EX = CID->FirstChildElement("SCL")->FirstChildElement("DataTypeTemplates");
	DataTemp_IN = root->FirstChildElement("DataTypeTemplates");
	QMap<QString, TiXmlElement*>MAP_IN, MAP_EX;

	Init_LNtype_MAP(DataTemp_IN, MAP_IN);
	if (MAP_IN.keys().size() != 0)
	{
		Init_LNtype_MAP(DataTemp_EX, MAP_EX);
		for (int i = 0; i < MAP_EX.keys().size(); i++)
		{
			if (MAP_IN.keys().contains(MAP_EX.keys().at(i)))
			{
				LNTypeMap.insert(MAP_EX.keys().at(i), MAP_EX.value(MAP_EX.keys().at(i)));
			}
		}
	}

	Init_LD_MAP(CID->FirstChildElement("SCL")->FirstChildElement("IED"), LD_MAP);
	key_ld = LD_MAP.keys();
	for (int i = 0; i < key_ld.size(); i++)
	{
		Init_LN_MAP(LD_MAP.value(key_ld[i]), LN_MAP);
		key_ln = LN_MAP.keys();
		for (int j = 0; j < key_ln.size(); j++)
		{
			str.clear();
			m_LN = LN_MAP.value(key_ln[j]);
			chr = m_LN->Attribute("lnType");
			str += chr;
			if (LNTypeMap.keys().contains(str))
			{
				LNMap.insertMulti(str, m_LN);
			}

		}
	}



	Init_DOType_MAP(DataTemp_IN, MAP_IN);
	if (MAP_IN.keys().size() != 0)
	{
		Init_DOType_MAP(DataTemp_EX, MAP_EX);
		for (int i = 0; i < MAP_EX.keys().size(); i++)
		{
			if (MAP_IN.keys().contains(MAP_EX.keys().at(i)))
			{
				DOTypeMap.insert(MAP_EX.keys().at(i), MAP_EX.value(MAP_EX.keys().at(i)));
			}
		}
	}


	Init_DAtype_MAP(DataTemp_IN, MAP_IN);
	if (MAP_IN.keys().size() != 0)
	{
		Init_DAtype_MAP(DataTemp_EX, MAP_EX);
		for (int i = 0; i < MAP_EX.keys().size(); i++)
		{
			if (MAP_IN.keys().contains(MAP_EX.keys().at(i)))
			{
				DATypeMap.insert(MAP_EX.keys().at(i), MAP_EX.value(MAP_EX.keys().at(i)));
			}
		}
	}

	Init_EnumType_MAP(DataTemp_EX, MAP_EX);
	Init_EnumType_MAP(DataTemp_IN, MAP_IN);
	for (int i = 0; i < MAP_EX.keys().size(); i++)
	{
		if (MAP_IN.keys().contains(MAP_EX.keys().at(i)))
		{
			EnumMap.insert(MAP_EX.keys().at(i), MAP_EX.value(MAP_EX.keys().at(i)));
		}
	}


	return DO_OK;
}
void ScdTree::AddNewHistoryItem(int state)
{
	TiXmlElement* m_header = root->FirstChildElement("Header");
	TiXmlElement* m_histroy = m_header->FirstChildElement("History");
	TiXmlElement* m_Item = NULL;
	TiXmlElement* new_Item = NULL;
	if (m_histroy == NULL)
	{
		m_histroy = new TiXmlElement("History");
		m_header->LinkEndChild(m_histroy);
	}
	if (m_histroy->LastChild("Hitem") != NULL)
	{
		m_Item = m_histroy->LastChild("Hitem")->ToElement();
		new_Item = m_Item->Clone()->ToElement();
	}
	else
	{
		new_Item = new TiXmlElement("Hitem");
		new_Item->SetAttribute("version", "1.0");
		new_Item->SetAttribute("revision", "1.0");

	}
	m_histroy->LinkEndChild(new_Item);
	new_Item->SetAttribute("who", "");
	new_Item->SetAttribute("what", "");
	new_Item->SetAttribute("why", "");
	//TiXmlElement* new_Item = m_Item->Clone()->ToElement();
	QDateTime current_date_time = QDateTime::currentDateTime();
	QString current_date = current_date_time.toString("yyyy-MM-dd hh:mm:ss");

	QString str;
	float ver;
	if (state == 1)
	{
		str = QString::fromLocal8Bit(new_Item->Attribute("version"));
		ver = str.toFloat();
		ver = ver + 0.1;
		str = QString::number(ver, 'g', 2);
		new_Item->SetAttribute("version", str.toStdString().data());
		new_Item->SetAttribute("revision", "1.0");
		new_Item->SetAttribute("when", current_date.toStdString().data());
	}
	else if (state == 2)
	{
		str = QString::fromLocal8Bit(new_Item->Attribute("revision"));
		ver = str.toFloat();
		ver = ver + 0.1;
		str = QString::number(ver, 'g', 2);
		new_Item->SetAttribute("revision", str.toStdString().data());
		new_Item->SetAttribute("when", current_date.toStdString().data());
	}
	//m_histroy->LinkEndChild(new_Item);
}
int ScdTree::UpdataHistoryItem(HistoryItem old_Itme, HistoryItem new_Itme)
{
	TiXmlElement* m_header = root->FirstChildElement("Header");
	TiXmlElement* m_histroy = m_header->FirstChildElement("History");
	for (TiXmlElement* m_Item = m_histroy->FirstChildElement("Hitem"); m_Item != NULL; m_Item = m_Item->NextSiblingElement("Hitem"))
	{
		if (0 == strcmp(m_Item->Attribute("version"), old_Itme.s_Version.toStdString().data()))
		{
			if (0 == strcmp(m_Item->Attribute("revision"), old_Itme.s_Reversion.toStdString().data()))
			{
				if (0 == strcmp(m_Item->Attribute("when"), old_Itme.s_Time.toStdString().data()))
				{
					m_Item->SetAttribute("version", new_Itme.s_Version.toStdString().data());
					m_Item->SetAttribute("revision", new_Itme.s_Reversion.toStdString().data());
					m_Item->SetAttribute("when", new_Itme.s_Time.toStdString().data());
					m_Item->SetAttribute("who", new_Itme.s_Who.toStdString().data());
					m_Item->SetAttribute("what", new_Itme.s_What.toStdString().data());
					m_Item->SetAttribute("why", new_Itme.s_Reason.toStdString().data());
					return DO_OK;
				}
			}
		}
	}
	return DO_FAIL;
}
int ScdTree::UpdataLDDesc(QString IED, QString LD, QString Desc)
{
	QMap<QString, TiXmlElement*> Map_IED;
	Init_IED_MAP(root, Map_IED);
	TiXmlElement*IED_Node = Map_IED.value(IED);
	QMap<QString, TiXmlElement*> Map_LD;
	Init_LD_MAP(IED_Node, Map_LD);
	TiXmlElement*LD_Node = Map_LD.value(LD);
	if (LD_Node != NULL)
	{
		LD_Node->SetAttribute("desc", Desc.toStdString().data());
		return DO_OK;
	}
	return DO_FAIL;
}
int ScdTree::UpdataLNDesc(QString IED, QString LD, QString LN, QString Desc)
{
	QMap<QString, TiXmlElement*> Map_IED;
	Init_IED_MAP(root, Map_IED);
	TiXmlElement*IED_Node = Map_IED.value(IED);
	QMap<QString, TiXmlElement*> Map_LD;
	Init_LD_MAP(IED_Node, Map_LD);
	TiXmlElement*LD_Node = Map_LD.value(LD);
	QMap<QString, TiXmlElement*> Map_LN;
	Init_LN_MAP(LD_Node, Map_LN);
	TiXmlElement*LN_Node = Map_LN.value(LN);
	if (LN_Node != NULL)
	{
		LN_Node->SetAttribute("desc", Desc.toStdString().data());
		return DO_OK;
	}
	return DO_FAIL;
}
int ScdTree::GetDataDesc(QString IED, QString Inst, QString &Desc1, QString &Desc2, QString &dU1, QString &dU2)
{
	QString str, LD, LN;
	const char *chr;
	QMap<QString, TiXmlElement*> Map_IED;
	Init_IED_MAP(root, Map_IED);
	TiXmlElement*IED_Node = Map_IED.value(IED);
	QMap<QString, TiXmlElement*> Map_LD;
	Init_LD_MAP(IED_Node, Map_LD);
	QStringList strlist = Inst.split("/");
	LD = strlist.at(0);
	str = strlist.at(1);

	QStringList doList = str.split(".");
	LN = doList.at(0);
	doList.takeAt(0);
	TiXmlElement*LD_Node = Map_LD.value(LD);
	QMap<QString, TiXmlElement*> Map_LN;
	Init_LN_MAP(LD_Node, Map_LN);
	TiXmlElement*LN_Node = Map_LN.value(LN);
	QMap<QString, TiXmlElement*> Map_DO;
	QMap<QString, TiXmlElement*> Map_DA;
	Init_DO_MAP(LN_Node, Map_DO);
	TiXmlElement*DO_Node = NULL;
	TiXmlElement*DA_Node = NULL;
	if (doList.size() == 1)
	{
		DO_Node = Map_DO.value(doList.at(0));
		chr = DO_Node->Attribute("desc");
		Desc1 += chr;
		Desc2.clear();
		Init_DAI_MAP(DO_Node, Map_DA);
		DA_Node = Map_DA.value("dU");
		TiXmlText *Text = NULL;
		Text = DA_Node->FirstChildElement()->FirstChild()->ToText();
		chr = Text->Value();
		dU1 += chr;
	}
	else if (doList.size() > 1)
	{
		DO_Node = Map_DO.value(doList.at(0));
		chr = DO_Node->Attribute("desc");
		Desc1 += chr;
		Init_DAI_MAP(DO_Node, Map_DA);
		DA_Node = Map_DA.value("dU");
		TiXmlText *Text = NULL;
		if (DA_Node != NULL)
		{

			Text = DA_Node->FirstChildElement()->FirstChild()->ToText();
			chr = Text->Value();
			dU1 += chr;
		}

		Init_SDI_MAP(DO_Node, Map_DO);
		DO_Node = Map_DO.value(doList.at(1));
		chr = DO_Node->Attribute("desc");
		Desc2 += chr;
		Init_DAI_MAP(DO_Node, Map_DA);
		DA_Node = Map_DA.value("dU");
		if (DA_Node != NULL)
		{
			Text = DA_Node->FirstChildElement()->FirstChild()->ToText();
			chr = Text->Value();
			dU2 += chr;
		}

	}

	return	0;
}
int ScdTree::UpdataDataDesc(QString IED, QString Inst, QString &Desc1, QString &Desc2, QString &dU1, QString &dU2)
{
	QString str, LD, LN;
	//const char *chr;
	QMap<QString, TiXmlElement*> Map_IED;
	Init_IED_MAP(root, Map_IED);
	TiXmlElement*IED_Node = Map_IED.value(IED);
	QMap<QString, TiXmlElement*> Map_LD;
	Init_LD_MAP(IED_Node, Map_LD);
	QStringList strlist = Inst.split("/");
	LD = strlist.at(0);
	str = strlist.at(1);

	QStringList doList = str.split(".");
	LN = doList.at(0);
	doList.takeAt(0);
	TiXmlElement*LD_Node = Map_LD.value(LD);
	QMap<QString, TiXmlElement*> Map_LN;
	Init_LN_MAP(LD_Node, Map_LN);
	TiXmlElement*LN_Node = Map_LN.value(LN);
	QMap<QString, TiXmlElement*> Map_DO;
	QMap<QString, TiXmlElement*> Map_DA;
	Init_DO_MAP(LN_Node, Map_DO);
	TiXmlElement*DO_Node = NULL;
	TiXmlElement*DA_Node = NULL;
	if (doList.size() == 1)
	{
		DO_Node = Map_DO.value(doList.at(0));
		DO_Node->SetAttribute("desc", Desc1.toStdString().data());

		Init_DAI_MAP(DO_Node, Map_DA);
		DA_Node = Map_DA.value("dU");
		TiXmlText *Text = NULL;
		if (DA_Node != NULL)
		{
			Text = DA_Node->FirstChildElement()->FirstChild()->ToText();
			Text->SetValue(dU1.toStdString().data());
		}
		else
		{
			Text = new TiXmlText(dU1.toStdString().data());
			TiXmlElement *Child = new TiXmlElement("Val");
			Child->LinkEndChild(Text);
			TiXmlElement *m_DA = new TiXmlElement("DAI");
			m_DA->SetAttribute("name", "dU");
			m_DA->LinkEndChild(Child);
			DO_Node->LinkEndChild(m_DA);
		}


	}
	else if (doList.size() > 1)
	{
		DO_Node = Map_DO.value(doList.at(0));
		DO_Node->SetAttribute("desc", Desc1.toStdString().data());

		Init_DAI_MAP(DO_Node, Map_DA);
		DA_Node = Map_DA.value("dU");
		TiXmlText *Text = NULL;
		if (DA_Node != NULL)
		{
			Text = DA_Node->FirstChildElement()->FirstChild()->ToText();
			Text->SetValue(dU1.toStdString().data());
		}
		else
		{
			Text = new TiXmlText(dU1.toStdString().data());
			TiXmlElement *Child = new TiXmlElement("Val");
			Child->LinkEndChild(Text);
			TiXmlElement *m_DA = new TiXmlElement("DAI");
			m_DA->SetAttribute("name", "dU");
			m_DA->LinkEndChild(Child);
			DO_Node->LinkEndChild(m_DA);
		}

		Init_SDI_MAP(DO_Node, Map_DO);
		DO_Node = Map_DO.value(doList.at(1));
		DO_Node->SetAttribute("desc", Desc2.toStdString().data());

		Init_DAI_MAP(DO_Node, Map_DA);
		DA_Node = Map_DA.value("dU");
		if (DA_Node != NULL)
		{
			Text = DA_Node->FirstChildElement()->FirstChild()->ToText();
			Text->SetValue(dU2.toStdString().data());

		}
		else
		{
			Text = new TiXmlText(dU1.toStdString().data());
			TiXmlElement *Child = new TiXmlElement("Val");
			Child->LinkEndChild(Text);
			TiXmlElement *m_DA = new TiXmlElement("DAI");
			m_DA->SetAttribute("name", "dU");
			m_DA->LinkEndChild(Child);
			DO_Node->LinkEndChild(m_DA);
		}

	}

	return	0;
}
int ScdTree::DelOneDataSet(QString IED, QString LD, QString LN, QString DataSet)
{
	QMap<QString, TiXmlElement*> Map_IED;
	Init_IED_MAP(root, Map_IED);
	TiXmlElement*IED_Node = Map_IED.value(IED);
	QMap<QString, TiXmlElement*> Map_LD;
	Init_LD_MAP(IED_Node, Map_LD);
	TiXmlElement*LD_Node = Map_LD.value(LD);
	QMap<QString, TiXmlElement*> Map_LN;
	Init_LN_MAP(LD_Node, Map_LN);
	TiXmlElement*LN_Node = Map_LN.value(LN);
	QMap<QString, TiXmlElement*> Map_DataSet;
	Init_DataSet_MAP(LN_Node, Map_DataSet);

	for (int i = 0; i < Map_DataSet.values(DataSet).size(); i++)
	{
		LN_Node->RemoveChild(Map_DataSet.values(DataSet).at(i));
	}
	return DO_OK;
}
void ScdTree::Auto_AddControlBlock()
{
	QMap<QString, TiXmlElement*> Map_IED;
	QMap<QString, TiXmlElement*> Map_LD;
	QMap<QString, TiXmlElement*> Map_LN;
	QMap<QString, TiXmlElement*> Map_DataSet;
	QMap<QString, TiXmlElement*> Map_ControlBLk;
	Init_IED_MAP(root, Map_IED);
	TiXmlElement*IED_Node = NULL;
	TiXmlElement*LD_Node = NULL;
	TiXmlElement*LN_Node = NULL;
	TiXmlElement*BLK_Node = NULL;
	for (int i = 0; i < Map_IED.keys().size(); i++)
	{
		IED_Node = Map_IED.value(Map_IED.keys().at(i));
		Init_LD_MAP(IED_Node, Map_LD);
		for (int j = 0; j < Map_LD.keys().size(); j++)
		{
			LD_Node = Map_LD.value(Map_LD.keys().at(j));
			Init_LN_MAP(LD_Node, Map_LN);
			for (int m = 0; m < Map_LN.keys().size(); m++)
			{
				LN_Node = Map_LN.value(Map_LN.keys().at(m));
				Init_DataSet_MAP(LN_Node, Map_DataSet);
				QStringList datalist;
				for (int n = 0; n < Map_DataSet.keys().size(); n++)
				{
					bool flag = false;
					if (Map_DataSet.keys().at(n).contains("dsGOOSE"))
					{
						datalist.append(Map_DataSet.keys().at(n));
					}
					if (datalist.size() == 0)
					{
						continue;
					}
					Init_ControBlock_MAP(LN_Node, Map_ControlBLk, 2);
					for (int k = 0; k < Map_ControlBLk.keys().size(); k++)
					{
						QString str;
						str += Map_ControlBLk.value(Map_ControlBLk.uniqueKeys().at(k))->Attribute("datSet");
						if (datalist.contains(str))
						{
							datalist.removeOne(str);
						}
					}
				}
				if (datalist.size() != 0)
				{
					for (int o = 0; o < datalist.size(); o++)
					{
						GSE_InstStruct m_data;
						QString str = datalist.at(o);
						str.replace("ds", "gs", Qt::CaseInsensitive);
						QString str1;
						str1 += LN_Node->Attribute("lnType");
						QString strappid = Map_IED.keys().at(i) + Map_LD.keys().at(j) + "/" + str1 + "$GO$" + str;
						BLK_Node = new TiXmlElement("GSEControl");
						m_data.B_name = str;
						BLK_Node->SetAttribute("name", str.toStdString().data());
						m_data.B_datSet = datalist.at(o);
						BLK_Node->SetAttribute("datSet", datalist.at(o).toStdString().data());
						m_data.B_confRev = "1";
						BLK_Node->SetAttribute("confRev", "1");
						m_data.B_type = "GOOSE";
						BLK_Node->SetAttribute("type", "GOOSE");
						m_data.B_appID = strappid;
						BLK_Node->SetAttribute("appID", strappid.toStdString().data());
						BLK_Node->SetAttribute("desc", "");
						LN_Node->InsertAfterChild(LN_Node->LastChild("DataSet"), *BLK_Node);
						AddConnectAPByGOOSE(Map_IED.keys().at(i), GetAPByLD(LD_Node)->Attribute("name"), Map_LD.keys().at(j), m_data);
					}

					//else if (Map_DataSet.keys().at(n).contains("dsSV"))
					//{
					//	Init_ControBlock_MAP(LN_Node, Map_ControlBLk, 3);
					//	for (int k = 0; k < Map_ControlBLk.keys().size(); k++)
					//	{
					//		if (0 == strcmp(Map_DataSet.keys().at(n).toStdString().data(), Map_ControlBLk.value(Map_ControlBLk.keys().at(k))->Attribute("datSet")))
					//		{
					//			flag = true;
					//			break;
					//		}
					//	}
					//}
					//else
					//{
					//	Init_ControBlock_MAP(LN_Node, Map_ControlBLk, 1);
					//	for (int k = 0; k < Map_ControlBLk.keys().size(); k++)
					//	{
					//		if (0 == strcmp(Map_DataSet.keys().at(n).toStdString().data(), Map_ControlBLk.value(Map_ControlBLk.keys().at(k))->Attribute("datSet")))
					//		{
					//			flag = true;
					//			break;
					//		}
					//	}
					//}
					//if (flag == false)
					//{
					//	if (Map_DataSet.keys().at(n).contains("dsGOOSE"))
					//	{
					//		TiXmlNode* m_node = CreatBLKNode(Map_IED.keys().at(i), Map_LD.keys().at(j), Map_LN.keys().at(m), 1, Map_DataSet.keys().at(n))->Clone();
					//		LN_Node->InsertAfterChild(LN_Node->LastChild("DataSet"), *m_node);
					//	}
					//	GSE_InstStruct m_Data;
					//	AddOneGSECtrl(Map_IED.keys().at(i), Map_LD.keys().at(j), Map_LN.keys().at(m), datasetlist, m_Data);
					//	//m_SCDPoint->AddConnectAPByGOOSE(strIEDname, strap, strld, m_Data);
					//	if (recode == DO_OK)
					//	{
					//		recode = m_SCDPoint->AddConnectAPByGOOSE(strIEDname, strap, strld, m_Data);

					//	}
					//else if (Map_DataSet.keys().at(n).contains("dsSV"))
					//{
					//	TiXmlNode* m_node = CreatBLKNode(Map_IED.keys().at(i), Map_LD.keys().at(j), Map_LN.keys().at(m), 2, Map_DataSet.keys().at(n))->Clone();
					//	LN_Node->InsertAfterChild(LN_Node->LastChild("DataSet"), *m_node);
					//}
					//else
					//{
					//	TiXmlNode* m_node = CreatBLKNode(Map_IED.keys().at(i), Map_LD.keys().at(j), Map_LN.keys().at(m), 0, Map_DataSet.keys().at(n))->Clone();
					//	LN_Node->InsertAfterChild(LN_Node->LastChild("DataSet"), *m_node);
					//}
				}
			}
		}
	}
}

TiXmlElement* ScdTree::GetAPByLD(TiXmlElement*node)
{
	TiXmlElement*m_AP = NULL;
	QString str;
	while (true)
	{
		if (node == NULL)
		{
			return NULL;
		}
		str.clear();
		str += node->Value();
		if (str != "AccessPoint")
		{
			node = node->Parent()->ToElement();
		}
		else
		{
			m_AP = node;
			return m_AP;
		}

	}
}

TiXmlElement* ScdTree::CreatBLKNode(QString IED, QString LD, QString LN, int state, QString Name)
{
	TiXmlElement *BLK_Node = NULL;
	if (state == 0)
	{
		QString str;
		BLK_Node = new TiXmlElement("ReportControl");
		BLK_Node->SetAttribute("datSet", Name.toStdString().data());

		if (Name.contains("dsAin"))
		{
			str = Name.remove("ds", Qt::CaseInsensitive);
			str = "urcb" + str;
			BLK_Node->SetAttribute("name", str.toStdString().data());
			str = IED + LD + "/" + LN + "." + str;
			BLK_Node->SetAttribute("rptID", str.toStdString().data());
		}
		else
		{
			str = Name.remove("ds", Qt::CaseInsensitive);
			str = "brcb" + str;
			BLK_Node->SetAttribute("name", str.toStdString().data());
			str = IED + LD + "/" + LN + "." + str;
			BLK_Node->SetAttribute("rptID", str.toStdString().data());
		}
		BLK_Node->SetAttribute("intgPd", "0");
		BLK_Node->SetAttribute("confRev", "1");
		BLK_Node->SetAttribute("buffered", "false");
		BLK_Node->SetAttribute("bufTime", "");
		BLK_Node->SetAttribute("desc", "");
		TiXmlElement *TrgOps_Node = NULL;
		TiXmlElement *OptFields_Node = NULL;
		TiXmlElement *RptEnabled_Node = NULL;
		TrgOps_Node = new TiXmlElement("TrgOps");
		TrgOps_Node->SetAttribute("dchg", "true");
		TrgOps_Node->SetAttribute("dupd", "true");
		TrgOps_Node->SetAttribute("period", "true");
		TrgOps_Node->SetAttribute("qchg", "true");
		BLK_Node->LinkEndChild(TrgOps_Node);
		OptFields_Node = new TiXmlElement("OptFields");
		OptFields_Node->SetAttribute("seqNum", "true");
		OptFields_Node->SetAttribute("timeStamp", "true");
		OptFields_Node->SetAttribute("dataSet", "true");
		OptFields_Node->SetAttribute("reasonCode", "true");
		OptFields_Node->SetAttribute("dataRef", "true");
		OptFields_Node->SetAttribute("entryID", "true");
		OptFields_Node->SetAttribute("configRef", "true");
		BLK_Node->LinkEndChild(OptFields_Node);
		RptEnabled_Node = new TiXmlElement("RptEnabled");
		RptEnabled_Node->SetAttribute("max", "4");
		BLK_Node->LinkEndChild(RptEnabled_Node);

	}
	else if (state == 1)
	{
		QString str, str1;
		BLK_Node = new TiXmlElement("GSEControl");
		BLK_Node->SetAttribute("datSet", Name.toStdString().data());
		str = Name.replace("ds", "gs");
		BLK_Node->SetAttribute("name", str.toStdString().data());
		BLK_Node->SetAttribute("confRev", "1");
		str1 = IED + LD + "/" + LN + "." + str;
		BLK_Node->SetAttribute("appID", str1.toStdString().data());
		BLK_Node->SetAttribute("type", "GOOSE");
	}
	else if (state == 2)
	{
		BLK_Node = new TiXmlElement("SampledValueControl");
		BLK_Node->SetAttribute("datSet", Name.toStdString().data());
		QString str, str1;

		if (Name == "dsSV")
		{
			str1 = "MSVCB";
		}
		else
		{
			str = Name.remove("dsSV");
			str1 = "MSVCB" + str;
		}
		BLK_Node->SetAttribute("name", str1.toStdString().data());
		BLK_Node->SetAttribute("confRev", "1");
		BLK_Node->SetAttribute("nofASDU", "1");
		BLK_Node->SetAttribute("smpRate", "80");
		BLK_Node->SetAttribute("multicast", "true");
		str = IED + LD + "/" + LN + "." + str1;
		BLK_Node->SetAttribute("smvID", str.toStdString().data());
		TiXmlElement *SmvOpts_Node = NULL;
		SmvOpts_Node = new TiXmlElement("SmvOpts");
		SmvOpts_Node->SetAttribute("refreshTime", "false");
		SmvOpts_Node->SetAttribute("sampleRate", "true");
		SmvOpts_Node->SetAttribute("sampleSynchronized", "true");
		SmvOpts_Node->SetAttribute("security", "false");
		SmvOpts_Node->SetAttribute("dataRef", "false");
		BLK_Node->LinkEndChild(SmvOpts_Node);
	}
	return BLK_Node;
}
int ScdTree::GetRPTList(QString IED, QString LD, QString LN, QVector<RPT_CTRLStruct>&Vector)
{
	const char *chr;
	QMap<QString, TiXmlElement*> Map_IED;
	QMap<QString, TiXmlElement*> Map_LD;
	QMap<QString, TiXmlElement*> Map_LN;

	QMap<QString, TiXmlElement*> Map_ControlBLk;
	TiXmlElement*IED_Node = NULL;
	TiXmlElement*LD_Node = NULL;
	TiXmlElement*LN_Node = NULL;
	TiXmlElement*BLK_Node = NULL;
	TiXmlElement*Chid_Node = NULL;
	Vector.clear();
	Init_IED_MAP(root, Map_IED);
	IED_Node = Map_IED.value(IED);
	Init_LD_MAP(IED_Node, Map_LD);
	LD_Node = Map_LD.value(LD);
	Init_LN_MAP(LD_Node, Map_LN);
	LN_Node = Map_LN.value(LN);
	Init_ControBlock_MAP(LN_Node, Map_ControlBLk, 1);
	for (int i = 0; i < Map_ControlBLk.uniqueKeys().size(); i++)
	{
		for (int j = 0; j < Map_ControlBLk.values(Map_ControlBLk.uniqueKeys().at(i)).size(); j++)
		{
			BLK_Node = Map_ControlBLk.values(Map_ControlBLk.uniqueKeys().at(i)).at(j);
			RPT_CTRLStruct m_RPT;

			chr = BLK_Node->Attribute("name");
			m_RPT.B_name += chr;

			chr = BLK_Node->Attribute("datSet");
			m_RPT.B_datSet += chr;

			chr = BLK_Node->Attribute("rptID");
			m_RPT.B_rptID += chr;

			chr = BLK_Node->Attribute("intgPd");
			m_RPT.B_intgPd += chr;

			chr = BLK_Node->Attribute("confRev");
			m_RPT.B_confRev += chr;

			chr = BLK_Node->Attribute("buffered");
			m_RPT.B_buffered += chr;

			chr = BLK_Node->Attribute("bufTime");
			m_RPT.B_buftime = chr;

			chr = BLK_Node->Attribute("desc");
			m_RPT.B_desc += chr;

			Chid_Node = BLK_Node->FirstChildElement("TrgOps");

			chr = Chid_Node->Attribute("dchg");

			m_RPT.m_Trgops.B_dchg += chr;

			chr = Chid_Node->Attribute("dupd");
			m_RPT.m_Trgops.B_dupd += chr;

			chr = Chid_Node->Attribute("period");
			m_RPT.m_Trgops.B_period += chr;

			chr = Chid_Node->Attribute("qchg");
			m_RPT.m_Trgops.B_qchg += chr;
			Chid_Node = BLK_Node->FirstChildElement("OptFields");

			chr = Chid_Node->Attribute("seqNum");
			m_RPT.m_OptFields.B_seqNum += chr;

			chr = Chid_Node->Attribute("timeStamp");
			m_RPT.m_OptFields.B_timeStamp += chr;

			chr = Chid_Node->Attribute("dataSet");
			m_RPT.m_OptFields.B_dataSet += chr;

			chr = Chid_Node->Attribute("reasonCode");
			m_RPT.m_OptFields.B_reasonCode += chr;

			chr = Chid_Node->Attribute("dataRef");
			m_RPT.m_OptFields.B_dataRef += chr;

			chr = Chid_Node->Attribute("entryID");
			m_RPT.m_OptFields.B_entryID += chr;

			chr = Chid_Node->Attribute("configRef");
			m_RPT.m_OptFields.B_configRef += chr;
			Chid_Node = BLK_Node->FirstChildElement("RptEnabled");

			chr = Chid_Node->Attribute("max");
			m_RPT.m_RtpEnabled.B_max += chr;
			Vector.append(m_RPT);
		}
	}
	return 0;
}
int ScdTree::UpdataOneRPTCtrl(QString IED, QString LD, QString LN, RPT_CTRLStruct data, QString oldname)
{
	QMap<QString, TiXmlElement*> Map_IED;
	QMap<QString, TiXmlElement*> Map_LD;
	QMap<QString, TiXmlElement*> Map_LN;

	QMap<QString, TiXmlElement*> Map_ControlBLk;
	TiXmlElement*IED_Node = NULL;
	TiXmlElement*LD_Node = NULL;
	TiXmlElement*LN_Node = NULL;
	TiXmlElement*BLK_Node = NULL;
	TiXmlElement*Chid_Node = NULL;
	Init_IED_MAP(root, Map_IED);
	IED_Node = Map_IED.value(IED);
	Init_LD_MAP(IED_Node, Map_LD);
	LD_Node = Map_LD.value(LD);
	Init_LN_MAP(LD_Node, Map_LN);
	LN_Node = Map_LN.value(LN);
	Init_ControBlock_MAP(LN_Node, Map_ControlBLk, 1);

	if (data.B_name != oldname)
	{

		BLK_Node = Map_ControlBLk.value(data.B_name);
		if (BLK_Node != NULL)
		{
			return DO_FAIL;
		}
		else
		{
			BLK_Node = Map_ControlBLk.value(oldname);
			LN_Node->RemoveChild(BLK_Node);
			BLK_Node = NULL;
			BLK_Node = new TiXmlElement("ReportControl");
			data.B_rptID.replace(oldname, data.B_name);
			BLK_Node->SetAttribute("name", data.B_name.toStdString().data());
			BLK_Node->SetAttribute("datSet", data.B_datSet.toStdString().data());
			BLK_Node->SetAttribute("rptID", data.B_rptID.toStdString().data());
			BLK_Node->SetAttribute("intgPd", data.B_intgPd.toStdString().data());
			BLK_Node->SetAttribute("confRev", data.B_confRev.toStdString().data());
			BLK_Node->SetAttribute("buffered", data.B_buffered.toStdString().data());
			BLK_Node->SetAttribute("bufTime", data.B_buftime.toStdString().data());
			BLK_Node->SetAttribute("desc", data.B_desc.toStdString().data());
			Chid_Node = new TiXmlElement("TrgOps");

			Chid_Node->SetAttribute("dchg", data.m_Trgops.B_dchg.toStdString().data());
			Chid_Node->SetAttribute("dupd", data.m_Trgops.B_dupd.toStdString().data());
			Chid_Node->SetAttribute("period", data.m_Trgops.B_period.toStdString().data());
			Chid_Node->SetAttribute("qchg", data.m_Trgops.B_qchg.toStdString().data());
			BLK_Node->LinkEndChild(Chid_Node);
			Chid_Node = new TiXmlElement("OptFields");

			Chid_Node->SetAttribute("seqNum", data.m_OptFields.B_seqNum.toStdString().data());
			Chid_Node->SetAttribute("timeStamp", data.m_OptFields.B_timeStamp.toStdString().data());
			Chid_Node->SetAttribute("dataSet", data.m_OptFields.B_dataSet.toStdString().data());
			Chid_Node->SetAttribute("reasonCode", data.m_OptFields.B_reasonCode.toStdString().data());
			Chid_Node->SetAttribute("dataRef", data.m_OptFields.B_dataRef.toStdString().data());
			Chid_Node->SetAttribute("entryID", data.m_OptFields.B_entryID.toStdString().data());
			Chid_Node->SetAttribute("configRef", data.m_OptFields.B_configRef.toStdString().data());
			BLK_Node->LinkEndChild(Chid_Node);
			Chid_Node = new TiXmlElement("RptEnabled");

			Chid_Node->SetAttribute("max", data.m_RtpEnabled.B_max.toStdString().data());
			BLK_Node->LinkEndChild(Chid_Node);
			LN_Node->InsertAfterChild(LN_Node->LastChild("DataSet"), *BLK_Node);
		}
	}
	else if (data.B_name == oldname)
	{
		data.B_rptID.replace(oldname, data.B_name);
		BLK_Node = Map_ControlBLk.value(data.B_name);
		BLK_Node->SetAttribute("datSet", data.B_datSet.toStdString().data());
		BLK_Node->SetAttribute("rptID", data.B_rptID.toStdString().data());
		BLK_Node->SetAttribute("intgPd", data.B_intgPd.toStdString().data());
		BLK_Node->SetAttribute("confRev", data.B_confRev.toStdString().data());
		BLK_Node->SetAttribute("buffered", data.B_buffered.toStdString().data());
		BLK_Node->SetAttribute("bufTime", data.B_buftime.toStdString().data());
		BLK_Node->SetAttribute("desc", data.B_desc.toStdString().data());
		Chid_Node = BLK_Node->FirstChildElement("TrgOps");
		Chid_Node->SetAttribute("dchg", data.m_Trgops.B_dchg.toStdString().data());
		Chid_Node->SetAttribute("dupd", data.m_Trgops.B_dupd.toStdString().data());
		Chid_Node->SetAttribute("period", data.m_Trgops.B_period.toStdString().data());
		Chid_Node->SetAttribute("qchg", data.m_Trgops.B_qchg.toStdString().data());
		Chid_Node = BLK_Node->FirstChildElement("OptFields");
		Chid_Node->SetAttribute("seqNum", data.m_OptFields.B_seqNum.toStdString().data());
		Chid_Node->SetAttribute("timeStamp", data.m_OptFields.B_timeStamp.toStdString().data());
		Chid_Node->SetAttribute("dataSet", data.m_OptFields.B_dataSet.toStdString().data());
		Chid_Node->SetAttribute("reasonCode", data.m_OptFields.B_reasonCode.toStdString().data());
		Chid_Node->SetAttribute("dataRef", data.m_OptFields.B_dataRef.toStdString().data());
		Chid_Node->SetAttribute("entryID", data.m_OptFields.B_entryID.toStdString().data());
		Chid_Node->SetAttribute("configRef", data.m_OptFields.B_configRef.toStdString().data());
		Chid_Node = BLK_Node->FirstChildElement("RptEnabled");
		Chid_Node->SetAttribute("max", data.m_RtpEnabled.B_max.toStdString().data());
	}
	return DO_OK;
}
void ScdTree::GetDataSetList(QString strIED, QString LD, QString LN, QStringList &list)
{
	QMap<QString, TiXmlElement*> Map_IED;
	QMap<QString, TiXmlElement*> Map_LD;
	QMap<QString, TiXmlElement*> Map_LN;

	QMap<QString, TiXmlElement*> Map_DataSet;
	TiXmlElement*IED_Node = NULL;
	TiXmlElement*LD_Node = NULL;
	TiXmlElement*LN_Node = NULL;
	Init_IED_MAP(root, Map_IED);
	IED_Node = Map_IED.value(strIED);
	Init_LD_MAP(IED_Node, Map_LD);
	LD_Node = Map_LD.value(LD);
	Init_LN_MAP(LD_Node, Map_LN);
	LN_Node = Map_LN.value(LN);
	Init_DataSet_MAP(LN_Node, Map_DataSet);
	list = Map_DataSet.uniqueKeys();
}
int ScdTree::DelOneGSEBlK(QString IED, QString LD, QString LN, QString BLK_Name)
{
	QMap<QString, TiXmlElement*> Map_IED;
	QMap<QString, TiXmlElement*> Map_LD;
	QMap<QString, TiXmlElement*> Map_LN;

	QMap<QString, TiXmlElement*> Map_ControlBLk;
	TiXmlElement*IED_Node = NULL;
	TiXmlElement*LD_Node = NULL;
	TiXmlElement*LN_Node = NULL;
	TiXmlElement*BLK_Node = NULL;
	Init_IED_MAP(root, Map_IED);
	IED_Node = Map_IED.value(IED);
	Init_LD_MAP(IED_Node, Map_LD);
	LD_Node = Map_LD.value(LD);
	Init_LN_MAP(LD_Node, Map_LN);
	LN_Node = Map_LN.value(LN);
	Init_ControBlock_MAP(LN_Node, Map_ControlBLk, 2);
	BLK_Node = Map_ControlBLk.value(BLK_Name);
	if (BLK_Node == NULL)
	{
		return DO_FAIL;
	}
	LN_Node->RemoveChild(BLK_Node);
	return DO_OK;
}
int ScdTree::UpdataOneGSEBLK(QString IED, QString LD, QString LN, GSE_InstStruct data, QString oldname)
{
	QMap<QString, TiXmlElement*> Map_IED;
	QMap<QString, TiXmlElement*> Map_LD;
	QMap<QString, TiXmlElement*> Map_LN;

	QMap<QString, TiXmlElement*> Map_ControlBLk;
	TiXmlElement*IED_Node = NULL;
	TiXmlElement*LD_Node = NULL;
	TiXmlElement*LN_Node = NULL;
	TiXmlElement*BLK_Node = NULL;
	QString str;
	QString str1;
	Init_IED_MAP(root, Map_IED);
	IED_Node = Map_IED.value(IED);
	Init_LD_MAP(IED_Node, Map_LD);
	LD_Node = Map_LD.value(LD);
	Init_LN_MAP(LD_Node, Map_LN);
	LN_Node = Map_LN.value(LN);
	str1 += LN_Node->Attribute("lnType");
	Init_ControBlock_MAP(LN_Node, Map_ControlBLk, 2);
	BLK_Node = Map_ControlBLk.value(oldname);
	if (BLK_Node == NULL)
		return  DO_OK;
	Map_ControlBLk.remove(oldname);
	for (int i = 0; i < Map_ControlBLk.uniqueKeys().size(); i++)
	{
		if (0 == strcmp(Map_ControlBLk.value(Map_ControlBLk.uniqueKeys().at(i))->Attribute("datSet"), data.B_datSet.toStdString().data()))
			return DO_FAIL;
	}

	LN_Node->RemoveChild(BLK_Node);
	BLK_Node = new TiXmlElement("GSEControl");

	BLK_Node->SetAttribute("name", data.B_name.toStdString().data());
	BLK_Node->SetAttribute("datSet", data.B_datSet.toStdString().data());
	BLK_Node->SetAttribute("confRev", data.B_confRev.toStdString().data());
	BLK_Node->SetAttribute("type", data.B_type.toStdString().data());
	if (data.B_appID.contains(oldname, Qt::CaseInsensitive))
	{
		data.B_appID.replace(oldname, data.B_name, Qt::CaseInsensitive);
	}
	else
	{
		data.B_appID = IED + LD + "/" + str1 + "$GO$" + data.B_name;
	}

	BLK_Node->SetAttribute("appID", data.B_appID.toStdString().data());
	BLK_Node->SetAttribute("desc", data.B_desc.toStdString().data());
	LN_Node->LinkEndChild(BLK_Node);
	return DO_OK;
}
int ScdTree::AddOneGSECtrl(QString IED, QString LD, QString LN, QStringList list, GSE_InstStruct& m_data)
{
	QMap<QString, TiXmlElement*> Map_IED;
	QMap<QString, TiXmlElement*> Map_LD;
	QMap<QString, TiXmlElement*> Map_LN;

	QMap<QString, TiXmlElement*> Map_ControlBLk;
	TiXmlElement*IED_Node = NULL;
	TiXmlElement*LD_Node = NULL;
	TiXmlElement*LN_Node = NULL;
	TiXmlElement*BLK_Node = NULL;
	//bool flag = true;

	QString str, str1;
	const char* chr;
	Init_IED_MAP(root, Map_IED);
	IED_Node = Map_IED.value(IED);
	Init_LD_MAP(IED_Node, Map_LD);
	LD_Node = Map_LD.value(LD);
	Init_LN_MAP(LD_Node, Map_LN);
	LN_Node = Map_LN.value(LN);
	str1 += LN_Node->Attribute("lnType");
	Init_ControBlock_MAP(LN_Node, Map_ControlBLk, 2);
	for (int i = 0; i < Map_ControlBLk.uniqueKeys().size(); i++)
	{
		chr = Map_ControlBLk.value(Map_ControlBLk.uniqueKeys().at(i))->Attribute("datSet");
		str.clear();
		str += chr;
		list.removeOne(str);
	}

	if (list.size() == 0)
	{
		QMessageBox::about(0, QObject::tr("Alarm"), QObject::tr("All of the dataset has control block"));

		return DO_FAIL;
	}
	Init_ControBlock_MAP(LN_Node, Map_ControlBLk, 2);

	str = list.at(0);
	str.replace("ds", "gs", Qt::CaseInsensitive);
	QString strappid = IED + LD + "/" + str1 + "$GO$" + str;
	BLK_Node = new TiXmlElement("GSEControl");
	m_data.B_name = str;
	BLK_Node->SetAttribute("name", str.toStdString().data());
	m_data.B_datSet = list.at(0);
	BLK_Node->SetAttribute("datSet", list.at(0).toStdString().data());
	m_data.B_confRev = "1";
	BLK_Node->SetAttribute("confRev", "1");
	m_data.B_type = "GOOSE";
	BLK_Node->SetAttribute("type", "GOOSE");
	m_data.B_appID = strappid;
	BLK_Node->SetAttribute("appID", strappid.toStdString().data());
	BLK_Node->SetAttribute("desc", "");
	LN_Node->InsertAfterChild(LN_Node->LastChild("DataSet"), *BLK_Node);

	return DO_OK;
}
int ScdTree::DelOneSMVBlK(QString IED, QString LD, QString LN, QString BLK_Name)
{
	QMap<QString, TiXmlElement*> Map_IED;
	QMap<QString, TiXmlElement*> Map_LD;
	QMap<QString, TiXmlElement*> Map_LN;

	QMap<QString, TiXmlElement*> Map_ControlBLk;
	TiXmlElement*IED_Node = NULL;
	TiXmlElement*LD_Node = NULL;
	TiXmlElement*LN_Node = NULL;
	TiXmlElement*BLK_Node = NULL;
	Init_IED_MAP(root, Map_IED);
	IED_Node = Map_IED.value(IED);
	Init_LD_MAP(IED_Node, Map_LD);
	LD_Node = Map_LD.value(LD);
	Init_LN_MAP(LD_Node, Map_LN);
	LN_Node = Map_LN.value(LN);
	Init_ControBlock_MAP(LN_Node, Map_ControlBLk, 3);
	BLK_Node = Map_ControlBLk.value(BLK_Name);
	if (BLK_Node == NULL)
	{
		return DO_FAIL;
	}
	LN_Node->RemoveChild(BLK_Node);
	return DO_OK;
}
int ScdTree::AddOneSMVCtrl(QString IED, QString LD, QString LN, QStringList list, SMV_InstStruct& m_data)
{
	QMap<QString, TiXmlElement*> Map_IED;
	QMap<QString, TiXmlElement*> Map_LD;
	QMap<QString, TiXmlElement*> Map_LN;

	QMap<QString, TiXmlElement*> Map_ControlBLk;
	TiXmlElement*IED_Node = NULL;
	TiXmlElement*LD_Node = NULL;
	TiXmlElement*LN_Node = NULL;
	TiXmlElement*BLK_Node = NULL;
	QString str;
	const char* chr;
	Init_IED_MAP(root, Map_IED);
	IED_Node = Map_IED.value(IED);
	Init_LD_MAP(IED_Node, Map_LD);
	LD_Node = Map_LD.value(LD);
	Init_LN_MAP(LD_Node, Map_LN);
	LN_Node = Map_LN.value(LN);
	Init_ControBlock_MAP(LN_Node, Map_ControlBLk, 3);
	for (int i = 0; i < Map_ControlBLk.uniqueKeys().size(); i++)
	{
		chr = Map_ControlBLk.value(Map_ControlBLk.uniqueKeys().at(i))->Attribute("datSet");
		str.clear();
		str += chr;
		list.removeOne(str);
	}
	if (list.size() == 0)
	{
		QMessageBox::about(0, QObject::tr("Alarm"), QObject::tr("All of the dataset has control block"));

		return DO_FAIL;
	}
	Init_ControBlock_MAP(LN_Node, Map_ControlBLk, 3);

	str = list.at(0);
	str.replace("ds", "smvcb", Qt::CaseInsensitive);
	m_data.B_name = str;
	QString strappid = IED + LD + "/" + LN + "." + str;
	BLK_Node = new TiXmlElement("SampledValueControl");
	BLK_Node->SetAttribute("name", str.toStdString().data());
	BLK_Node->SetAttribute("datSet", list.at(0).toStdString().data());
	m_data.B_datSet = list.at(0);
	BLK_Node->SetAttribute("confRev", "1");
	m_data.B_confRev == "1";
	BLK_Node->SetAttribute("nofASDU", "1");
	m_data.B_nofASDU = "1";
	BLK_Node->SetAttribute("smpRate", "4000");
	m_data.B_smpRate = "4000";
	BLK_Node->SetAttribute("multicast", "true");
	m_data.B_multicast = "true";
	BLK_Node->SetAttribute("desc", "");

	BLK_Node->SetAttribute("smvID", strappid.toStdString().data());
	m_data.B_smvID = strappid;
	LN_Node->InsertAfterChild(LN_Node->LastChild("DataSet"), *BLK_Node);

	return DO_OK;
}
int ScdTree::UpdataOneSMVBLK(QString IED, QString LD, QString LN, SMV_InstStruct data, QString oldname)
{
	QMap<QString, TiXmlElement*> Map_IED;
	QMap<QString, TiXmlElement*> Map_LD;
	QMap<QString, TiXmlElement*> Map_LN;

	QMap<QString, TiXmlElement*> Map_ControlBLk;
	TiXmlElement*IED_Node = NULL;
	TiXmlElement*LD_Node = NULL;
	TiXmlElement*LN_Node = NULL;
	TiXmlElement*BLK_Node = NULL;

	Init_IED_MAP(root, Map_IED);
	IED_Node = Map_IED.value(IED);
	Init_LD_MAP(IED_Node, Map_LD);
	LD_Node = Map_LD.value(LD);
	Init_LN_MAP(LD_Node, Map_LN);
	LN_Node = Map_LN.value(LN);
	Init_ControBlock_MAP(LN_Node, Map_ControlBLk, 3);
	BLK_Node = Map_ControlBLk.value(oldname);
	if (BLK_Node == NULL)
		return  DO_FAIL;
	Map_ControlBLk.remove(oldname);
	for (int i = 0; i < Map_ControlBLk.uniqueKeys().size(); i++)
	{
		if (0 == strcmp(Map_ControlBLk.value(Map_ControlBLk.uniqueKeys().at(i))->Attribute("datSet"), data.B_datSet.toStdString().data()))
			return DO_FAIL;
	}
	LN_Node->RemoveChild(BLK_Node);
	BLK_Node = new TiXmlElement("SampledValueControl");
	BLK_Node->SetAttribute("name", data.B_name.toStdString().data());
	BLK_Node->SetAttribute("datSet", data.B_datSet.toStdString().data());
	BLK_Node->SetAttribute("nofASDU", data.B_nofASDU.toStdString().data());
	BLK_Node->SetAttribute("confRev", data.B_confRev.toStdString().data());
	BLK_Node->SetAttribute("smpRate", data.B_smpRate.toStdString().data());
	data.B_smvID.replace(oldname, data.B_name, Qt::CaseInsensitive);
	BLK_Node->SetAttribute("multicast", data.B_multicast.toStdString().data());
	BLK_Node->SetAttribute("smvID", data.B_smvID.toStdString().data());

	BLK_Node->SetAttribute("desc", data.B_desc.toStdString().data());
	LN_Node->LinkEndChild(BLK_Node);
	return DO_OK;
	//if (data.B_name != oldname)
	//{

	//	BLK_Node = Map_ControlBLk.value(data.B_name);
	//	if (BLK_Node != NULL)
	//	{
	//		return DO_FAIL;
	//	}
	//	else
	//	{

	//		BLK_Node = Map_ControlBLk.value(oldname);
	//		LN_Node->RemoveChild(BLK_Node);
	//		BLK_Node = NULL;
	//		BLK_Node = new TiXmlElement("SampledValueControl");
	//		BLK_Node->SetAttribute("name", data.B_name.toStdString().data());
	//		BLK_Node->SetAttribute("datSet", data.B_datSet.toStdString().data());
	//		BLK_Node->SetAttribute("confRev", data.B_confRev.toStdString().data());
	//		BLK_Node->SetAttribute("nofASDU", data.B_nofASDU.toStdString().data());
	//		BLK_Node->SetAttribute("smpRate", data.B_smpRate.toStdString().data());
	//		BLK_Node->SetAttribute("multicast", data.B_multicast.toStdString().data());
	//		BLK_Node->SetAttribute("desc", data.B_desc.toStdString().data());
	//		BLK_Node->SetAttribute("smvID", data.B_smvID.toStdString().data());
	//		LN_Node->InsertAfterChild(LN_Node->LastChild("DataSet"), *BLK_Node);
	//	}
	//}
	//else if (data.B_name == oldname)
	//{

	//	BLK_Node = Map_ControlBLk.value(data.B_name);
	//	BLK_Node->SetAttribute("name", data.B_name.toStdString().data());
	//	BLK_Node->SetAttribute("datSet", data.B_datSet.toStdString().data());
	//	BLK_Node->SetAttribute("confRev", data.B_confRev.toStdString().data());
	//	BLK_Node->SetAttribute("nofASDU", data.B_nofASDU.toStdString().data());
	//	BLK_Node->SetAttribute("smpRate", data.B_smpRate.toStdString().data());
	//	BLK_Node->SetAttribute("multicast", data.B_multicast.toStdString().data());
	//	BLK_Node->SetAttribute("desc", data.B_desc.toStdString().data());
	//	BLK_Node->SetAttribute("smvID", data.B_smvID.toStdString().data());

	//}
	//return DO_OK;
}
int ScdTree::GetSMVList(QString IED, QString LD, QString LN, QVector<SMV_InstStruct>&List)
{
	QMap<QString, TiXmlElement*> Map_IED;
	QMap<QString, TiXmlElement*> Map_LD;
	QMap<QString, TiXmlElement*> Map_LN;

	QMap<QString, TiXmlElement*> Map_ControlBLk;
	TiXmlElement*IED_Node = NULL;
	TiXmlElement*LD_Node = NULL;
	TiXmlElement*LN_Node = NULL;
	TiXmlElement*BLK_Node = NULL;
	const char* chr;
	Init_IED_MAP(root, Map_IED);
	IED_Node = Map_IED.value(IED);
	Init_LD_MAP(IED_Node, Map_LD);
	LD_Node = Map_LD.value(LD);
	Init_LN_MAP(LD_Node, Map_LN);
	LN_Node = Map_LN.value(LN);
	Init_ControBlock_MAP(LN_Node, Map_ControlBLk, 3);
	for (int i = 0; i < Map_ControlBLk.uniqueKeys().size(); i++)
	{
		SMV_InstStruct m_data;
		BLK_Node = Map_ControlBLk.value(Map_ControlBLk.uniqueKeys().at(i));

		chr = BLK_Node->Attribute("name");
		m_data.B_name += chr;
		chr = BLK_Node->Attribute("datSet");
		m_data.B_datSet += chr;
		chr = BLK_Node->Attribute("confRev");
		m_data.B_confRev += chr;
		chr = BLK_Node->Attribute("nofASDU");
		m_data.B_nofASDU += chr;
		chr = BLK_Node->Attribute("smpRate");
		m_data.B_smpRate += chr;
		chr = BLK_Node->Attribute("multicast");
		m_data.B_multicast += chr;
		chr = BLK_Node->Attribute("desc");
		m_data.B_desc += chr;
		chr = BLK_Node->Attribute("smvID");
		m_data.B_smvID += chr;
		List.append(m_data);
	}
	return DO_OK;
}
int ScdTree::GetGSEList(QString IED, QString LD, QString LN, QVector<GSE_InstStruct>&List)
{
	QMap<QString, TiXmlElement*> Map_IED;
	QMap<QString, TiXmlElement*> Map_LD;
	QMap<QString, TiXmlElement*> Map_LN;

	QMap<QString, TiXmlElement*> Map_ControlBLk;
	TiXmlElement*IED_Node = NULL;
	TiXmlElement*LD_Node = NULL;
	TiXmlElement*LN_Node = NULL;
	TiXmlElement*BLK_Node = NULL;
	const char* chr;
	Init_IED_MAP(root, Map_IED);
	IED_Node = Map_IED.value(IED);
	Init_LD_MAP(IED_Node, Map_LD);
	LD_Node = Map_LD.value(LD);
	Init_LN_MAP(LD_Node, Map_LN);
	LN_Node = Map_LN.value(LN);
	Init_ControBlock_MAP(LN_Node, Map_ControlBLk, 2);
	for (int i = 0; i < Map_ControlBLk.uniqueKeys().size(); i++)
	{
		GSE_InstStruct m_data;
		BLK_Node = Map_ControlBLk.value(Map_ControlBLk.uniqueKeys().at(i));

		chr = BLK_Node->Attribute("name");
		m_data.B_name += chr;
		chr = BLK_Node->Attribute("datSet");
		m_data.B_datSet += chr;
		chr = BLK_Node->Attribute("confRev");
		m_data.B_confRev += chr;
		chr = BLK_Node->Attribute("type");
		m_data.B_type += chr;
		chr = BLK_Node->Attribute("appID");
		m_data.B_appID += chr;
		chr = BLK_Node->Attribute("desc");
		m_data.B_desc += chr;
		List.append(m_data);
	}
	return DO_OK;
}
int ScdTree::GetLOGList(QString IED, QString LD, QString LN, QVector<LOG_CTRLStruct>&List)
{
	QMap<QString, TiXmlElement*> Map_IED;
	QMap<QString, TiXmlElement*> Map_LD;
	QMap<QString, TiXmlElement*> Map_LN;

	QMap<QString, TiXmlElement*> Map_ControlBLk;
	TiXmlElement*IED_Node = NULL;
	TiXmlElement*LD_Node = NULL;
	TiXmlElement*LN_Node = NULL;
	TiXmlElement*BLK_Node = NULL;
	TiXmlElement*Chid_Node = NULL;
	const char* chr;
	Init_IED_MAP(root, Map_IED);
	IED_Node = Map_IED.value(IED);
	Init_LD_MAP(IED_Node, Map_LD);
	LD_Node = Map_LD.value(LD);
	Init_LN_MAP(LD_Node, Map_LN);
	LN_Node = Map_LN.value(LN);
	Init_ControBlock_MAP(LN_Node, Map_ControlBLk, 4);
	for (int i = 0; i < Map_ControlBLk.uniqueKeys().size(); i++)
	{
		LOG_CTRLStruct m_data;
		BLK_Node = Map_ControlBLk.value(Map_ControlBLk.uniqueKeys().at(i));
		chr = BLK_Node->Attribute("name");
		m_data.B_name += chr;
		chr = BLK_Node->Attribute("desc");
		m_data.B_desc += chr;
		chr = BLK_Node->Attribute("datSet");
		m_data.B_datSet += chr;
		chr = BLK_Node->Attribute("intgPd");
		m_data.B_intgPd += chr;
		chr = BLK_Node->Attribute("logName");
		m_data.B_logName += chr;
		chr = BLK_Node->Attribute("logEna");
		m_data.B_logEna += chr;
		chr = BLK_Node->Attribute("reasonCode");
		m_data.B_reasonCode += chr;
		Chid_Node = BLK_Node->FirstChildElement("TrgOps");
		chr = Chid_Node->Attribute("qchg");
		m_data.m_Trgops.B_qchg += chr;
		chr = Chid_Node->Attribute("period");
		m_data.m_Trgops.B_period += chr;
		chr = Chid_Node->Attribute("dupd");
		m_data.m_Trgops.B_dupd += chr;
		chr = Chid_Node->Attribute("dchg");
		m_data.m_Trgops.B_dchg += chr;
		List.append(m_data);

	}
	return DO_OK;
}

int ScdTree::AddOneLOGCtrl(QString IED, QString LD, QString LN, QStringList list)
{
	return DO_OK;
}

int ScdTree::DelOneLOGBlK(QString IED, QString LD, QString LN, QString BLK_Name)
{
	QMap<QString, TiXmlElement*> Map_IED;
	QMap<QString, TiXmlElement*> Map_LD;
	QMap<QString, TiXmlElement*> Map_LN;

	QMap<QString, TiXmlElement*> Map_ControlBLk;
	TiXmlElement*IED_Node = NULL;
	TiXmlElement*LD_Node = NULL;
	TiXmlElement*LN_Node = NULL;
	TiXmlElement*BLK_Node = NULL;

	Init_IED_MAP(root, Map_IED);
	IED_Node = Map_IED.value(IED);
	Init_LD_MAP(IED_Node, Map_LD);
	LD_Node = Map_LD.value(LD);
	Init_LN_MAP(LD_Node, Map_LN);
	LN_Node = Map_LN.value(LN);
	Init_ControBlock_MAP(LN_Node, Map_ControlBLk, 4);
	BLK_Node = Map_ControlBLk.value(BLK_Name);
	LN_Node->RemoveChild(BLK_Node);
	return DO_OK;
}

int ScdTree::UpdataOneLOGBLK(QString IED, QString LD, QString LN, LOG_CTRLStruct data, QString oldname)
{
	QMap<QString, TiXmlElement*> Map_IED;
	QMap<QString, TiXmlElement*> Map_LD;
	QMap<QString, TiXmlElement*> Map_LN;

	QMap<QString, TiXmlElement*> Map_ControlBLk;
	TiXmlElement*IED_Node = NULL;
	TiXmlElement*LD_Node = NULL;
	TiXmlElement*LN_Node = NULL;
	TiXmlElement*BLK_Node = NULL;
	TiXmlElement*Child_Node = NULL;
	Init_IED_MAP(root, Map_IED);
	IED_Node = Map_IED.value(IED);
	Init_LD_MAP(IED_Node, Map_LD);
	LD_Node = Map_LD.value(LD);
	Init_LN_MAP(LD_Node, Map_LN);
	LN_Node = Map_LN.value(LN);
	Init_ControBlock_MAP(LN_Node, Map_ControlBLk, 4);
	if (data.B_name != oldname)
	{

		BLK_Node = Map_ControlBLk.value(data.B_name);
		if (BLK_Node != NULL)
		{
			return DO_FAIL;
		}
		else
		{

			BLK_Node = Map_ControlBLk.value(oldname);
			LN_Node->RemoveChild(BLK_Node);
			BLK_Node = NULL;
			BLK_Node = new TiXmlElement("LogControl");
			BLK_Node->SetAttribute("name", data.B_name.toStdString().data());
			BLK_Node->SetAttribute("datSet", data.B_datSet.toStdString().data());
			BLK_Node->SetAttribute("desc", data.B_desc.toStdString().data());
			BLK_Node->SetAttribute("intgPd", data.B_intgPd.toStdString().data());
			BLK_Node->SetAttribute("logName", data.B_logName.toStdString().data());
			BLK_Node->SetAttribute("logEna", data.B_logEna.toStdString().data());
			BLK_Node->SetAttribute("reasonCode", data.B_reasonCode.toStdString().data());
			Child_Node = new TiXmlElement("TrgOps");
			Child_Node->SetAttribute("qchg", data.m_Trgops.B_qchg.toStdString().data());
			Child_Node->SetAttribute("period", data.m_Trgops.B_period.toStdString().data());
			Child_Node->SetAttribute("dupd", data.m_Trgops.B_dupd.toStdString().data());
			Child_Node->SetAttribute("dchg", data.m_Trgops.B_dchg.toStdString().data());
			BLK_Node->LinkEndChild(Child_Node);
			LN_Node->InsertAfterChild(LN_Node->LastChild("DataSet"), *BLK_Node);
		}
	}
	else if (data.B_name == oldname)
	{

		BLK_Node = Map_ControlBLk.value(data.B_name);
		BLK_Node->SetAttribute("name", data.B_name.toStdString().data());
		BLK_Node->SetAttribute("datSet", data.B_datSet.toStdString().data());
		BLK_Node->SetAttribute("desc", data.B_desc.toStdString().data());
		BLK_Node->SetAttribute("intgPd", data.B_intgPd.toStdString().data());
		BLK_Node->SetAttribute("logName", data.B_logName.toStdString().data());
		BLK_Node->SetAttribute("logEna", data.B_logEna.toStdString().data());
		BLK_Node->SetAttribute("reasonCode", data.B_reasonCode.toStdString().data());
		Child_Node = BLK_Node->FirstChildElement("TrgOps");
		Child_Node->SetAttribute("qchg", data.m_Trgops.B_qchg.toStdString().data());
		Child_Node->SetAttribute("period", data.m_Trgops.B_period.toStdString().data());
		Child_Node->SetAttribute("dupd", data.m_Trgops.B_dupd.toStdString().data());
		Child_Node->SetAttribute("dchg", data.m_Trgops.B_dchg.toStdString().data());


	}
	return DO_OK;
}
int ScdTree::Print_Test(TiXmlElement* Node, QString filename)
{
	Node->Clone()->ToDocument()->SaveFile(filename.toLocal8Bit().data());
	return 0;
}
int ScdTree::UpdataConnectAPByGOOSE(QString IED, QString AP, QString LD, QString OldName, GSE_InstStruct data)
{

	QMap<QString, TiXmlElement*> Map_GSE;
	QMap<QString, TiXmlElement*> Map_Child;
	TiXmlElement* m_SubNet = NULL;
	TiXmlElement* m_GSE = NULL;
	//TiXmlElement* m_AP = NULL;
	m_SubNet = root->FirstChildElement("Communication")->FirstChildElement("SubNetwork");
	for (m_SubNet; m_SubNet != NULL; m_SubNet = m_SubNet->NextSiblingElement())
	{
		if (0 == strcmp(m_SubNet->Attribute("type"), "8-MMS"))
		{
			Init_ConnectAP_MAP(m_SubNet, Map_GSE);

			for (int m = 0; m < Map_GSE.values(IED).size(); m++)
			{
				m_GSE = Map_GSE.values(IED).at(m)->FirstChildElement("GSE");
				if (m_GSE != NULL)
				{
					if (0 == strcmp(m_GSE->Attribute("ldInst"), LD.toStdString().data()))
					{
						if (0 == strcmp(m_GSE->Attribute("cbName"), OldName.toStdString().data()))
						{
							break;
						}
						else
						{
							m_GSE = NULL;
						}
					}
					else
					{
						m_GSE = NULL;
					}
				}
				else
				{
					break;
				}
			}
			if (m_GSE != NULL)
			{
				break;
			}
		}
		else if (0 == strcmp(m_SubNet->Attribute("type"), "IECGOOSE"))
		{
			Init_ConnectAP_MAP(m_SubNet, Map_GSE);

			for (int m = 0; m < Map_GSE.values(IED).size(); m++)
			{
				m_GSE = Map_GSE.values(IED).at(m)->FirstChildElement("GSE");
				if (m_GSE != NULL)
				{
					if (0 == strcmp(m_GSE->Attribute("ldInst"), LD.toStdString().data()))
					{
						if (0 == strcmp(m_GSE->Attribute("cbName"), OldName.toStdString().data()))
						{
							break;
						}
						else
						{
							m_GSE = NULL;
						}
					}
					else
					{
						m_GSE = NULL;
					}
				}
			}
			if (m_GSE != NULL)
			{
				break;
			}

		}
	}
	if (m_GSE != NULL)
	{
		m_GSE->SetAttribute("cbName", data.B_name.toStdString().data());
		return DO_OK;
	}
	return DO_FAIL;
	//for (m_SubNet = root->FirstChildElement("Communication")->FirstChildElement("SubNetwork"); m_SubNet != NULL; m_SubNet = m_SubNet->NextSiblingElement("SubNetwork"))
	//{
	//    if (0 == strcmp(m_SubNet->Attribute("type"), "IECGOOSE"))
	//    {
	//        break;
	//    }
	//}
	//Init_ConnectAP_MAP(m_SubNet, Map_GSE);
	//for (int i = 0; i < Map_GSE.values(IED).size(); i++)
	//{
	//    m_AP = Map_GSE.values(IED).at(i);
	//    if (0 == strcmp(m_AP->Attribute("apName"), AP.toStdString().data()))
	//    {
	//        break;
	//    }
	//    else
	//    {
	//        m_AP = NULL;
	//    }
	//}
	//if (m_AP != NULL)
	//{
	//    Init_Child_Map(m_AP, Map_Child, "ldInst");
	//    for (int i = 0; i < Map_Child.values(LD).size(); i++)
	//    {
	//        m_GSE = Map_Child.values(LD).at(i);
	//        if (0 == strcmp(m_GSE->Attribute("cbName"), OldName.toStdString().data()))
	//        {
	//            break;
	//        }
	//        else
	//        {
	//            m_GSE = NULL;
	//        }
	//    }
	//}
	//if (m_GSE != NULL)
	//{
	//    m_GSE->SetAttribute("cbName", data.B_name.toStdString().data());
	//    return DO_OK;
	//}
	//else
	//{
	//    for (m_SubNet = root->FirstChildElement("Communication")->FirstChildElement("SubNetwork"); m_SubNet != NULL; m_SubNet = m_SubNet->NextSiblingElement("SubNetwork"))
	//    {
	//        if (0 == strcmp(m_SubNet->Attribute("type"), "8-MMS"))
	//        {
	//            break;
	//        }
	//    }
	//    Init_ConnectAP_MAP(m_SubNet, Map_GSE);
	//    for (int i = 0; i < Map_GSE.values(IED).size(); i++)
	//    {
	//        m_AP = Map_GSE.values(IED).at(i);
	//        if (0 == strcmp(m_AP->Attribute("apName"), AP.toStdString().data()))
	//        {
	//            break;
	//        }
	//        else
	//        {
	//            m_AP = NULL;
	//        }
	//    }
	//    if (m_AP == NULL)
	//        return DO_FAIL;
	//    Init_Child_Map(m_AP, Map_Child, "ldInst");
	//    for (int i = 0; i < Map_Child.values(LD).size(); i++)
	//    {
	//        m_GSE = Map_Child.values(LD).at(i);
	//        if (0 == strcmp(m_GSE->Attribute("cbName"), OldName.toStdString().data()))
	//        {
	//            break;
	//        }
	//        else
	//        {
	//            m_GSE = NULL;
	//        }
	//    }
	//    if (m_GSE == NULL)
	//        return DO_FAIL;
	//    if (m_GSE != NULL)
	//    {
	//        m_GSE->SetAttribute("cbName", data.B_name.toStdString().data());
	//        return DO_OK;
	//    }
	//}


}
int ScdTree::AddConnectAPByGOOSE(QString IED, QString AP, QString LD, GSE_InstStruct data)
{
	QMap<QString, TiXmlElement*> Map_GSE;
	QMap<QString, TiXmlElement*> Map_Child;
	TiXmlElement* m_SubNet = NULL;
	TiXmlElement* m_Child = NULL;
	TiXmlElement* m_P = NULL;
	TiXmlText* m_Text = NULL;
	TiXmlElement* m_GSE = NULL;
	TiXmlElement* m_AP = NULL;

	m_SubNet = root->FirstChildElement("Communication")->FirstChildElement("SubNetwork");
	for (m_SubNet; m_SubNet != NULL; m_SubNet = m_SubNet->NextSiblingElement("SubNetwork"))
	{
		Init_ConnectAP_MAP(m_SubNet, Map_GSE);
		for (int i = 0; i < Map_GSE.values(IED).size(); i++)
		{
			if (0 == strcmp(AP.toStdString().data(), Map_GSE.values(IED).at(i)->Attribute("apName")))
			{
				m_AP = Map_GSE.values(IED).at(i);
				break;
			}
			else
			{
				m_AP = NULL;
			}
		}
		if (m_AP != NULL)
		{
			break;
		}
	}
	if (m_AP != NULL)
	{
		m_GSE = new TiXmlElement("GSE");
		m_GSE->SetAttribute("cbName", data.B_name.toStdString().data());
		m_GSE->SetAttribute("ldInst", LD.toStdString().data());
		m_Child = new TiXmlElement("Address");

		m_P = new TiXmlElement("P");
		m_P->SetAttribute("type", "MAC-Address");
		m_Text = new TiXmlText("01-0C-CD-04-01-01");
		m_P->LinkEndChild(m_Text);
		m_Child->LinkEndChild(m_P);
		m_P = new TiXmlElement("P");
		m_P->SetAttribute("type", "VLAN-ID");
		m_Text = new TiXmlText("000");
		m_P->LinkEndChild(m_Text);
		m_Child->LinkEndChild(m_P);
		m_P = new TiXmlElement("P");
		m_P->SetAttribute("type", "VLAN-PRIORITY");
		m_Text = new TiXmlText("4");
		m_P->LinkEndChild(m_Text);
		m_Child->LinkEndChild(m_P);
		m_P = new TiXmlElement("P");
		m_P->SetAttribute("type", "APPID");
		m_Text = new TiXmlText("0000");
		m_P->LinkEndChild(m_Text);

		m_Child->LinkEndChild(m_P);
		m_GSE->LinkEndChild(m_Child);
		m_P = new TiXmlElement("MinTime");
		m_P->SetAttribute("unit", "s");
		m_P->SetAttribute("multiplier", "m");
		m_Text = new TiXmlText("2");
		m_P->LinkEndChild(m_Text);
		m_GSE->LinkEndChild(m_P);
		m_P = new TiXmlElement("MaxTime");
		m_P->SetAttribute("unit", "s");
		m_P->SetAttribute("multiplier", "m");
		m_Text = new TiXmlText("5000");
		m_P->LinkEndChild(m_Text);
		m_GSE->LinkEndChild(m_P);
		m_AP->LinkEndChild(m_GSE);
		return DO_OK;
	}
	else
	{
		for (m_SubNet; m_SubNet != NULL; m_SubNet = m_SubNet->NextSiblingElement("SubNetwork"))
		{
			QString str;
			str += m_SubNet->Attribute("type");
			if (str.contains("IECGOOSE", Qt::CaseInsensitive))
			{
				break;
			}
		}
		if (m_SubNet == NULL)
		{
			return DO_FAIL;
		}
		m_AP = new TiXmlElement("ConnectedAP");
		m_AP->SetAttribute("iedName", IED.toStdString().data());
		m_AP->SetAttribute("apName", AP.toStdString().data());
		m_SubNet->LinkEndChild(m_AP);
		m_GSE = new TiXmlElement("GSE");
		m_GSE->SetAttribute("cbName", data.B_name.toStdString().data());
		m_GSE->SetAttribute("ldInst", LD.toStdString().data());
		m_Child = new TiXmlElement("Address");

		m_P = new TiXmlElement("P");
		m_P->SetAttribute("type", "MAC-Address");
		m_Text = new TiXmlText("01-0C-CD-04-01-01");
		m_P->LinkEndChild(m_Text);
		m_Child->LinkEndChild(m_P);
		m_P = new TiXmlElement("P");
		m_P->SetAttribute("type", "VLAN-ID");
		m_Text = new TiXmlText("000");
		m_P->LinkEndChild(m_Text);
		m_Child->LinkEndChild(m_P);
		m_P = new TiXmlElement("P");
		m_P->SetAttribute("type", "VLAN-PRIORITY");
		m_Text = new TiXmlText("4");
		m_P->LinkEndChild(m_Text);
		m_Child->LinkEndChild(m_P);
		m_P = new TiXmlElement("P");
		m_P->SetAttribute("type", "APPID");
		m_Text = new TiXmlText("0000");
		m_P->LinkEndChild(m_Text);

		m_Child->LinkEndChild(m_P);
		m_GSE->LinkEndChild(m_Child);
		m_P = new TiXmlElement("MinTime");
		m_P->SetAttribute("unit", "s");
		m_P->SetAttribute("multiplier", "m");
		m_Text = new TiXmlText("2");
		m_P->LinkEndChild(m_Text);
		m_GSE->LinkEndChild(m_P);
		m_P = new TiXmlElement("MaxTime");
		m_P->SetAttribute("unit", "s");
		m_P->SetAttribute("multiplier", "m");
		m_Text = new TiXmlText("5000");
		m_P->LinkEndChild(m_Text);
		m_GSE->LinkEndChild(m_P);
		m_AP->LinkEndChild(m_GSE);
		return DO_OK;
	}
	//Init_ConnectAP_MAP(m_SubNet, Map_GSE);
	//for (int i = 0; i < Map_GSE.values(IED).size(); i++)
	//{
	//	m_AP = Map_GSE.values(IED).at(i);
	//	if (0 == strcmp(m_AP->Attribute("apName"), AP.toStdString().data()))
	//	{
	//		break;
	//	}
	//	else
	//	{
	//		m_AP = NULL;
	//	}
	//}
	//if (m_AP != NULL)
	//{
	//	m_GSE = new TiXmlElement("GSE");
	//	m_GSE->SetAttribute("cbName", data.B_name.toStdString().data());
	//	m_GSE->SetAttribute("ldInst", LD.toStdString().data());
	//	m_Child = new TiXmlElement("Address");

	//	m_P = new TiXmlElement("P");
	//	m_P->SetAttribute("type", "MAC-Address");
	//	m_Text = new TiXmlText("01-0C-CD-04-01-01");
	//	m_P->LinkEndChild(m_Text);
	//	m_Child->LinkEndChild(m_P);
	//	m_P = new TiXmlElement("P");
	//	m_P->SetAttribute("type", "VLAN-ID");
	//	m_Text = new TiXmlText("000");
	//	m_P->LinkEndChild(m_Text);
	//	m_Child->LinkEndChild(m_P);
	//	m_P = new TiXmlElement("P");
	//	m_P->SetAttribute("type", "VLAN-PRIORITY");
	//	m_Text = new TiXmlText("4");
	//	m_P->LinkEndChild(m_Text);
	//	m_Child->LinkEndChild(m_P);
	//	m_P = new TiXmlElement("P");
	//	m_P->SetAttribute("type", "APPID");
	//	m_Text = new TiXmlText("0000");
	//	m_P->LinkEndChild(m_Text);
	//	m_Child->LinkEndChild(m_P);
	//	m_GSE->LinkEndChild(m_Child);
	//}
	//else
	//{
	//	m_AP = new TiXmlElement("ConnectedAP");
	//	m_AP->SetAttribute("iedName", IED.toStdString().data());
	//	m_AP->SetAttribute("apName", AP.toStdString().data());
	//	m_GSE = new TiXmlElement("GSE");
	//	m_GSE->SetAttribute("cbName", data.B_name.toStdString().data());
	//	m_GSE->SetAttribute("ldInst", LD.toStdString().data());
	//	m_Child = new TiXmlElement("Address");

	//	m_P = new TiXmlElement("P");
	//	m_P->SetAttribute("type", "MAC-Address");
	//	m_Text = new TiXmlText("01-0C-CD-04-01-01");
	//	m_P->LinkEndChild(m_Text);
	//	m_Child->LinkEndChild(m_P);
	//	m_P = new TiXmlElement("P");
	//	m_P->SetAttribute("type", "VLAN-ID");
	//	m_Text = new TiXmlText("000");
	//	m_P->LinkEndChild(m_Text);
	//	m_Child->LinkEndChild(m_P);
	//	m_P = new TiXmlElement("P");
	//	m_P->SetAttribute("type", "VLAN-PRIORITY");
	//	m_Text = new TiXmlText("4");
	//	m_P->LinkEndChild(m_Text);
	//	m_Child->LinkEndChild(m_P);
	//	m_P = new TiXmlElement("P");
	//	m_P->SetAttribute("type", "APPID");
	//	m_Text = new TiXmlText("0000");
	//	m_P->LinkEndChild(m_Text);
	//	m_Child->LinkEndChild(m_P);
	//	m_GSE->LinkEndChild(m_Child);
	//	m_AP->LinkEndChild(m_GSE);
	//	m_SubNet->LinkEndChild(m_AP);
	//}
	return DO_OK;
}
int ScdTree::DelConnectAPByGOOSE(QString IED, QString AP, QString LD, GSE_InstStruct data)
{
	QMap<QString, TiXmlElement*> Map_GSE;
	QMap<QString, TiXmlElement*> Map_Child;
	TiXmlElement* m_SubNet = NULL;
	TiXmlElement* m_Child = NULL;

	TiXmlElement* m_AP = NULL;
	m_SubNet = root->FirstChildElement("Communication")->FirstChildElement("SubNetwork");
	for (m_SubNet; m_SubNet != NULL; m_SubNet = m_SubNet->NextSiblingElement("SubNetwork"))
	{
		Init_ConnectAP_MAP(m_SubNet, Map_GSE);
		for (int i = 0; i < Map_GSE.values(IED).size(); i++)
		{
			if (0 == strcmp(AP.toStdString().data(), Map_GSE.values(IED).at(i)->Attribute("apName")))
			{
				m_AP = Map_GSE.values(IED).at(i);
				break;
			}
			else
			{
				m_AP = NULL;
			}
		}
		if (m_AP != NULL)
		{
			break;
		}
	}
	for (m_Child = m_AP->FirstChildElement("GSE"); m_Child != NULL; m_Child = m_Child->NextSiblingElement("GSE"))
	{
		if (0 == strcmp(m_Child->Attribute("ldInst"), LD.toStdString().data()))
		{
			if (0 == strcmp(m_Child->Attribute("cbName"), data.B_name.toStdString().data()))
			{
				m_AP->RemoveChild(m_Child);
				return DO_OK;
			}
		}
	}
	return DO_FAIL;
	//for (m_SubNet = root->FirstChildElement("Communication")->FirstChildElement("SubNetwork"); m_SubNet != NULL; m_SubNet = m_SubNet->NextSiblingElement("SubNetwork"))
	//{
	//	if (0 == strcmp(m_SubNet->Attribute("type"), "IECGOOSE"))
	//	{
	//		break;
	//	}
	//}
	//Init_ConnectAP_MAP(m_SubNet, Map_GSE);
	//for (int i = 0; i < Map_GSE.values(IED).size(); i++)
	//{
	//	if (0 == strcmp(Map_GSE.values(IED).at(i)->Attribute("apName"), AP.toStdString().data()))
	//	{
	//		m_AP = Map_GSE.values(IED).at(i);
	//	}
	//	else
	//	{
	//		m_AP = NULL;
	//	}
	//}
	//if (m_AP != NULL)
	//{
	//	Init_Child_Map(m_AP, Map_Child, "ldInst");
	//	for (int i = 0; i < Map_Child.values(LD).size(); i++)
	//	{
	//		if (0 == strcmp(Map_Child.values(LD).at(i)->Attribute("cbName"), data.B_name.toStdString().data()))
	//		{
	//			m_AP->RemoveChild(Map_Child.values(LD).at(i));
	//			return DO_OK;
	//		}
	//	}
	//}

}
int ScdTree::UpdataConnectAPBySMV(QString IED, QString AP, QString LD, QString OldName, SMV_InstStruct data)
{
	QMap<QString, TiXmlElement*> Map_SMV;
	QMap<QString, TiXmlElement*> Map_Child;
	TiXmlElement* m_SubNet = NULL;
	TiXmlElement* m_SMV = NULL;
	TiXmlElement* m_AP = NULL;
	for (m_SubNet = root->FirstChildElement("Communication")->FirstChildElement("SubNetwork"); m_SubNet != NULL; m_SubNet = m_SubNet->NextSiblingElement("SubNetwork"))
	{
		if (0 == strcmp(m_SubNet->Attribute("type"), "SMV"))
		{
			break;
		}
	}
	Init_ConnectAP_MAP(m_SubNet, Map_SMV);
	for (int i = 0; i < Map_SMV.values(IED).size(); i++)
	{
		m_AP = Map_SMV.values(IED).at(i);
		if (0 == strcmp(m_AP->Attribute("apName"), AP.toStdString().data()))
		{
			break;
		}
		else
		{
			m_AP = NULL;
		}
	}
	Init_Child_Map(m_AP, Map_Child, "ldInst");
	for (int i = 0; i < Map_Child.values(LD).size(); i++)
	{
		m_SMV = Map_Child.values(LD).at(i);
		if (0 == strcmp(m_SMV->Attribute("cbName"), OldName.toStdString().data()))
		{
			break;
		}
		else
		{
			m_AP = NULL;
		}
	}
	if (m_AP == NULL)
		return DO_FAIL;
	m_SMV->SetAttribute("cbName", data.B_name.toStdString().data());
	return DO_OK;
}

int ScdTree::AddConnectAPBySMV(QString IED, QString AP, QString LD, SMV_InstStruct data)
{
	QMap<QString, TiXmlElement*> Map_SMV;
	QMap<QString, TiXmlElement*> Map_Child;
	TiXmlElement* m_SubNet = NULL;
	TiXmlElement* m_Child = NULL;
	TiXmlElement* m_P = NULL;
	TiXmlText* m_Text = NULL;
	TiXmlElement* m_SMV = NULL;
	TiXmlElement* m_AP = NULL;
	for (m_SubNet = root->FirstChildElement("Communication")->FirstChildElement("SubNetwork"); m_SubNet != NULL; m_SubNet = m_SubNet->NextSiblingElement("SubNetwork"))
	{
		if (0 == strcmp(m_SubNet->Attribute("type"), "SMV"))
		{
			break;
		}
	}
	Init_ConnectAP_MAP(m_SubNet, Map_SMV);
	for (int i = 0; i < Map_SMV.values(IED).size(); i++)
	{
		m_AP = Map_SMV.values(IED).at(i);
		if (0 == strcmp(m_AP->Attribute("apName"), AP.toStdString().data()))
		{
			break;
		}
		else
		{
			m_AP = NULL;
		}
	}
	if (m_AP != NULL)
	{
		m_SMV = new TiXmlElement("SMV");
		m_SMV->SetAttribute("cbName", data.B_name.toStdString().data());
		m_SMV->SetAttribute("ldInst", LD.toStdString().data());
		m_Child = new TiXmlElement("Address");

		m_P = new TiXmlElement("P");
		m_P->SetAttribute("type", "MAC-Address");
		m_Text = new TiXmlText("01-0C-CD-04-01-01");
		m_P->LinkEndChild(m_Text);
		m_Child->LinkEndChild(m_P);
		m_P = new TiXmlElement("P");
		m_P->SetAttribute("type", "VLAN-ID");
		m_Text = new TiXmlText("000");
		m_P->LinkEndChild(m_Text);
		m_Child->LinkEndChild(m_P);
		m_P = new TiXmlElement("P");
		m_P->SetAttribute("type", "VLAN-PRIORITY");
		m_Text = new TiXmlText("4");
		m_P->LinkEndChild(m_Text);
		m_Child->LinkEndChild(m_P);
		m_P = new TiXmlElement("P");
		m_P->SetAttribute("type", "APPID");
		m_Text = new TiXmlText("3FFF");
		m_P->LinkEndChild(m_Text);
		m_Child->LinkEndChild(m_P);
		m_SMV->LinkEndChild(m_Child);
		m_AP->LinkEndChild(m_SMV);
	}
	else
	{
		m_AP = new TiXmlElement("ConnectedAP");
		m_AP->SetAttribute("iedName", IED.toStdString().data());
		m_AP->SetAttribute("apName", AP.toStdString().data());
		m_SMV = new TiXmlElement("SMV");
		m_SMV->SetAttribute("cbName", data.B_name.toStdString().data());
		m_SMV->SetAttribute("ldInst", LD.toStdString().data());
		m_Child = new TiXmlElement("Address");

		m_P = new TiXmlElement("P");
		m_P->SetAttribute("type", "MAC-Address");
		m_Text = new TiXmlText("01-0C-CD-04-01-01");
		m_P->LinkEndChild(m_Text);
		m_Child->LinkEndChild(m_P);
		m_P = new TiXmlElement("P");
		m_P->SetAttribute("type", "VLAN-ID");
		m_Text = new TiXmlText("000");
		m_P->LinkEndChild(m_Text);
		m_Child->LinkEndChild(m_P);
		m_P = new TiXmlElement("P");
		m_P->SetAttribute("type", "VLAN-PRIORITY");
		m_Text = new TiXmlText("4");
		m_P->LinkEndChild(m_Text);
		m_Child->LinkEndChild(m_P);
		m_P = new TiXmlElement("P");
		m_P->SetAttribute("type", "APPID");
		m_Text = new TiXmlText("3FFF");
		m_P->LinkEndChild(m_Text);
		m_Child->LinkEndChild(m_P);
		m_SMV->LinkEndChild(m_Child);
		m_AP->LinkEndChild(m_SMV);
		m_SubNet->LinkEndChild(m_AP);
	}
	return DO_OK;
}

int ScdTree::DelConnectAPBySMV(QString IED, QString AP, QString LD, SMV_InstStruct data)
{
	QMap<QString, TiXmlElement*> Map_SMV;
	QMap<QString, TiXmlElement*> Map_Child;
	TiXmlElement* m_SubNet = NULL;

	TiXmlElement* m_AP = NULL;
	for (m_SubNet = root->FirstChildElement("Communication")->FirstChildElement("SubNetwork"); m_SubNet != NULL; m_SubNet = m_SubNet->NextSiblingElement("SubNetwork"))
	{
		if (0 == strcmp(m_SubNet->Attribute("type"), "SMV"))
		{
			break;
		}
	}
	Init_ConnectAP_MAP(m_SubNet, Map_SMV);
	for (int i = 0; i < Map_SMV.values(IED).size(); i++)
	{
		if (0 == strcmp(Map_SMV.values(IED).at(i)->Attribute("apName"), AP.toStdString().data()))
		{
			m_AP = Map_SMV.values(IED).at(i);
		}
		else
		{
			m_AP = NULL;
		}
	}
	if (m_AP != NULL)
	{
		Init_Child_Map(m_AP, Map_Child, "ldInst");
		for (int i = 0; i < Map_Child.values(LD).size(); i++)
		{
			if (0 == strcmp(Map_Child.values(LD).at(i)->Attribute("cbName"), data.B_name.toStdString().data()))
			{
				m_AP->RemoveChild(Map_Child.values(LD).at(i));
				return DO_OK;
			}
		}
	}
	return DO_FAIL;

}
int ScdTree::GetReportSetting(QString IED)
{
	int state = 0;
	QMap<QString, TiXmlElement*> Map_IED;
	TiXmlElement* m_IED = NULL;
	Init_IED_MAP(root, Map_IED);
	m_IED = Map_IED.value(IED);
	TiXmlElement* m_Server = NULL;
	TiXmlElement* m_RPT = NULL;
	if (m_IED == NULL)
		return 0;
	m_Server = m_IED->FirstChildElement("Services");
	if (m_Server == NULL)
		return 0;
	m_RPT = m_Server->FirstChildElement("ReportSettings");
	if (m_RPT == NULL)
	{
		state = 0;
		return 0;
	}
	if (m_RPT->Attribute("cbName") != NULL)
	{
		if (0 != strcmp("Fix", m_RPT->Attribute("cbName")))
		{
			state += CBNAME_ENA;
		}
	}
	if (m_RPT->Attribute("datSet") != NULL)
	{
		if (0 != strcmp("Fix", m_RPT->Attribute("datSet")))
		{
			state += DATASET_ENA;
		}
	}
	if (m_RPT->Attribute("rptID") != NULL)
	{
		if (0 != strcmp("Fix", m_RPT->Attribute("rptID")))
		{
			state += RPTID_ENA;
		}
	}
	if (m_RPT->Attribute("optFields") != NULL)
	{
		if (0 != strcmp("Fix", m_RPT->Attribute("optFields")))
		{
			state += OPTFIELDS_ENA;
		}
	}
	if (m_RPT->Attribute("bufTime") != NULL)
	{
		if (0 != strcmp("Fix", m_RPT->Attribute("bufTime")))
		{
			state += BUFTIME_ENA;
		}
	}
	if (m_RPT->Attribute("trgOps") != NULL)
	{
		if (0 != strcmp("Fix", m_RPT->Attribute("trgOps")))
		{
			state += TRPOPS_ENA;
		}
	}
	if (m_RPT->Attribute("intgPd") != NULL)
	{
		if (0 != strcmp("Fix", m_RPT->Attribute("intgPd")))
		{
			state += INTGPD_ENA;
		}
	}

	return state;
}
int ScdTree::GetGSESetting(QString IED)
{
	int state = 0;
	QMap<QString, TiXmlElement*> Map_IED;
	TiXmlElement* m_IED = NULL;
	Init_IED_MAP(root, Map_IED);
	m_IED = Map_IED.value(IED);
	TiXmlElement* m_Server = NULL;
	TiXmlElement* m_RPT = NULL;
	if (m_IED == NULL)
		return 0;
	m_Server = m_IED->FirstChildElement("Services");
	if (m_Server == NULL)
		return 0;
	m_RPT = m_Server->FirstChildElement("GSESettings");
	if (m_RPT == NULL)
	{
		//state += CBNAME_ENA;
		//state += DATASET_ENA;
		//state += APPID_ENA;
		state = 0;
		return state;
	}
	if (m_RPT->Attribute("cbName") != NULL)
	{
		if (0 != strcmp("Fix", m_RPT->Attribute("cbName")))
		{
			state += CBNAME_ENA;
		}
	}
	if (m_RPT->Attribute("datSet") != NULL)
	{
		if (0 != strcmp("Fix", m_RPT->Attribute("datSet")))
		{
			state += DATASET_ENA;
		}
	}
	if (m_RPT->Attribute("appID") != NULL)
	{
		if (0 != strcmp("Fix", m_RPT->Attribute("appID")))
		{
			state += APPID_ENA;
		}
	}


	return state;
}
int ScdTree::UpdataBLKConfRev(QString IED, QString LD, QString DataSet, bool flag)
{
	if (flag == false)
		return DO_FAIL;
	QMap<QString, TiXmlElement*> Map_IED;
	QMap<QString, TiXmlElement*> Map_LD;
	QMap<QString, TiXmlElement*> Map_LN;
	QMap<QString, TiXmlElement*> Map_BLK;
	TiXmlElement* m_IED = NULL;
	TiXmlElement* m_LD = NULL;
	TiXmlElement* m_LN = NULL;
	TiXmlElement* m_BLK = NULL;
	Init_IED_MAP(root, Map_IED);
	m_IED = Map_IED.value(IED);
	Init_LD_MAP(m_IED, Map_LD);
	m_LD = Map_LD.value(LD);
	Init_LN_MAP(m_LD, Map_LN);
	for (int i = 0; i < Map_LN.uniqueKeys().size(); i++)
	{
		for (int j = 0; j < Map_LN.values(Map_LN.uniqueKeys().at(i)).size(); j++)
		{
			m_LN = Map_LN.values(Map_LN.uniqueKeys().at(i)).at(j);
			Init_ControBlock_MAP(m_LN, Map_BLK, 0);
			for (int m = 0; m < Map_BLK.uniqueKeys().size(); m++)
			{
				for (int n = 0; n < Map_BLK.values(Map_BLK.uniqueKeys().at(m)).size(); n++)
				{
					m_BLK = Map_BLK.values(Map_BLK.uniqueKeys().at(m)).at(n);
					if (0 == strcmp(DataSet.toStdString().data(), m_BLK->Attribute("datSet")))
					{
						const char *chr = m_BLK->Attribute("confRev");
						QString str;
						str += chr;
						int ver = str.toInt();
						ver = ver + 1;
						m_BLK->SetAttribute("confRev", QString::number(ver).toStdString().data());
						return DO_OK;

					}
				}
			}
		}
	}
	return DO_FAIL;

}
int ScdTree::SaveCRC()
{
	QMap<QString, TiXmlElement*> Map_IED;
	TiXmlElement* m_IED = NULL;
	TiXmlElement* m_SCL = NULL;
	TiXmlDocument* IED_Doc = NULL;
	TiXmlDocument* SCD_Doc = NULL;
	TiXmlDeclaration *Declaration = NULL;
	TiXmlElement* m_P = NULL;
	TiXmlElement* m_Server = NULL;
	TiXmlElement* m_Private = NULL;
	TiXmlText* m_Text = NULL;
	TiXmlPrinter Pstr_ALL;
	Init_IED_MAP(root, Map_IED);
	SCD_Doc = new TiXmlDocument;
	Declaration = new TiXmlDeclaration("1.0", "UTF-8", "");
	SCD_Doc->LinkEndChild(Declaration);
	for (int i = 0; i < Map_IED.uniqueKeys().size(); i++)
	{
		TiXmlPrinter Pstr;
		IED_Doc = new TiXmlDocument;
		//Declaration = new TiXmlDeclaration("1.0", "UTF-8", "");
		IED_Doc->LinkEndChild(Declaration->Clone()->ToDeclaration());
		m_IED = Map_IED.value(Map_IED.uniqueKeys().at(i));
		//m_SCL = new TiXmlElement("SCL");
		m_SCL = SaveIEDCRC2File(m_IED);
		IED_Doc->LinkEndChild(m_SCL);
		SCD_Doc->LinkEndChild(m_SCL->Clone()->ToElement());
		IED_Doc->Accept(&Pstr);
		const char *TempPstr = Pstr.CStr();//把指针取出
		int len = strlen(TempPstr);//计算长度
		if (len == 0) continue;
		char * RPstr = new char[len];
		//QMessageBox::about(0, "notice", QString::number(len));
		memcpy(RPstr, TempPstr, len);
		QString str;
		str.clear();
		str += RPstr;
		str = str.simplified();
		unsigned long crc;
		m_SumCheck.CRCInit(crc);
		m_SumCheck.CRCUpdate(str.toLocal8Bit().data(), str.length(), crc);
		m_SumCheck.CRCFinal(crc);
		m_Server = m_IED->FirstChildElement("Services");
		//QMessageBox::about(0, "notice", Map_IED.uniqueKeys().at(i));
		m_P = NULL;
		for (m_Private = m_Server->FirstChildElement("Private"); m_Private != NULL; m_Private = m_Private->NextSiblingElement("Private"))
		{
			if (0 == strcmp("IED virtual terminal conection CRC", m_Private->Attribute("type")))
			{
				m_P = m_Private;
				break;
			}
			else
			{
				m_P = NULL;
			}
		}
		QString key;

		key = QString("%1").arg(crc, 8, 16, QLatin1Char('0'));
		if (m_P == NULL)
		{
			m_P = new TiXmlElement("Private");
			m_P->SetAttribute("type", "IED virtual terminal conection CRC");

			m_Text = new TiXmlText(key.toUpper().toStdString().data());
			m_P->LinkEndChild(m_Text);
			m_Server->LinkEndChild(m_P);
		}
		else
		{
			m_Text = m_P->FirstChild()->ToText();
			m_Text->SetValue(key.toUpper().toStdString().data());
		}
	}
	SCD_Doc->Accept(&Pstr_ALL);
	m_P = NULL;
	m_Private = NULL;
	//QMessageBox::about(0, "notice", QString::number(__LINE__));
	const char *TempPstr = Pstr_ALL.CStr();//把指针取出
	int len = strlen(TempPstr);//计算长度
	//QMessageBox::about(0, "notice", QString::number(__LINE__)+"And"+QString::number(len));
	if (len == 0)return DO_FAIL;
	//QMessageBox::about(0, "notice", QString::number(__LINE__));

	char * RPstr = new char[len];
	//QMessageBox::about(0, "notice", QString::number(__LINE__));

	memcpy(RPstr, TempPstr, len);
	//QMessageBox::about(0, "notice", QString::number(__LINE__));

	QString str;
	str.clear();
	str += RPstr;
	str = str.simplified();
	unsigned long crc;
	m_SumCheck.CRCInit(crc);
	m_SumCheck.CRCUpdate(str.toLocal8Bit().data(), str.length(), crc);
	m_SumCheck.CRCFinal(crc);
	//m_Private =root->FirstChildElement("Private");
	//QMessageBox::about(0, "notice", "ALL");
	for (m_Private = root->FirstChildElement("Private"); m_Private != NULL; m_Private = m_Private->NextSiblingElement("Private"))
	{
		if (0 == strcmp("Substation virtual terminal conection CRC", m_Private->Attribute("type")))
		{
			m_P = m_Private;
			break;
		}
		else
		{
			m_P = NULL;
		}
	}
	QString key;

	key = QString("%1").arg(crc, 8, 16, QLatin1Char('0'));
	if (m_P == NULL)
	{
		m_P = new TiXmlElement("Private");
		m_P->SetAttribute("type", "Substation virtual terminal conection CRC");
		m_Text = new TiXmlText(key.toUpper().toStdString().data());
		m_P->LinkEndChild(m_Text);
		root->InsertBeforeChild(root->FirstChildElement("Header"), *m_P);
	}
	else
	{
		m_Text = m_P->FirstChild()->ToText();
		m_Text->SetValue(key.toUpper().toStdString().data());
	}
	//SCD_Doc->SaveFile("111.xml");
	return DO_OK;
}
TiXmlElement* ScdTree::SaveIEDCRC2File(TiXmlElement* m_IED)
{
	QMap<QString, TiXmlElement*> Map_LD;
	QMap<QString, TiXmlElement*> Map_LN;
	QMap<QString, TiXmlElement*> DataSet_Map;
	QMap<QString, TiXmlElement*> CBL_Map;
	TiXmlElement *m_SCL = NULL;
	TiXmlElement* m_LD = NULL;
	TiXmlElement* m_LN = NULL;
	//TiXmlElement* m_Input = NULL;
	TiXmlElement* m_DataSet = NULL;
	TiXmlElement* m_CBL = NULL;
	TiXmlElement* m_GOOSESUB = new TiXmlElement("GOOSESUB");
	TiXmlElement* m_GOOSEPUB = new TiXmlElement("GOOSEPUB");
	TiXmlElement* m_SMVSUB = new TiXmlElement("SVSUB");
	TiXmlElement* m_SMVPUB = new TiXmlElement("SVPUB");
	TiXmlElement* m_AP = NULL;
	TiXmlElement* m_ConnectAP = NULL;
	TiXmlElement* m_GOCBref = NULL;
	TiXmlElement* m_SMVCBref = NULL;
	TiXmlElement* m_Child = NULL;
	TiXmlElement* m_FCDA = NULL;
	TiXmlElement* m_Set = NULL;
	QString strIED;
	QString str;
	QString strAP;
	strIED += m_IED->Attribute("name");
	m_SCL = new TiXmlElement("IED");
	m_SCL->SetAttribute("name", strIED.toStdString().data());
	m_SCL->LinkEndChild(m_GOOSEPUB);
	m_SCL->LinkEndChild(m_GOOSESUB);
	m_SCL->LinkEndChild(m_SMVPUB);
	m_SCL->LinkEndChild(m_SMVSUB);
	Init_LD_MAP(m_IED, Map_LD);
	for (int i = 0; i < Map_LD.uniqueKeys().size(); i++)
	{
		m_LD = Map_LD.value(Map_LD.uniqueKeys().at(i));
		m_AP = m_LD->Parent()->Parent()->ToElement();
		strAP.clear();
		strAP += m_AP->Attribute("name");
		Init_LN_MAP(m_LD, Map_LN);
		for (int j = 0; j < Map_LN.uniqueKeys().size(); j++)
		{
			m_LN = Map_LN.value(Map_LN.uniqueKeys().at(j));
			//m_Input = m_LN->FirstChildElement("Inputs");
			CBL_Map.clear();
			Init_GSE_Map(m_LN, CBL_Map, 0);
			DataSet_Map.clear();
			Init_DataSet_MAP(m_LN, DataSet_Map);
			for (int m = 0; m < CBL_Map.uniqueKeys().size(); m++)
			{
				m_CBL = CBL_Map.value(CBL_Map.uniqueKeys().at(m));
				str.clear();
				str += m_CBL->Attribute("appID");
				m_GOCBref = new TiXmlElement("GOCBref");
				m_GOCBref->SetAttribute("name", str.toStdString().data());
				m_GOOSEPUB->LinkEndChild(m_GOCBref);
				m_GOCBref->LinkEndChild(m_CBL->Clone()->ToElement());
				str.clear();
				str += m_CBL->Attribute("name");
				m_ConnectAP = GetConnectAP(strIED, strAP, Map_LD.uniqueKeys().at(i), str, 1);
				if (!m_ConnectAP == NULL)
				{
					m_GOCBref->LinkEndChild(m_ConnectAP);
				}

				m_Set = new TiXmlElement("DataSet");

				m_Set->SetAttribute("name", m_CBL->Attribute("datSet"));
				m_GOCBref->LinkEndChild(m_Set);
				str.clear();
				str += m_CBL->Attribute("datSet");
				m_DataSet = DataSet_Map.value(str);

				//int i = 0;
				for (m_Child = m_DataSet->FirstChildElement(); m_Child != NULL; m_Child = m_Child->NextSiblingElement())
				{
					m_FCDA = new TiXmlElement("FCDA");
					if (m_Child->Attribute("daName") != NULL)
					{
						m_FCDA->SetAttribute("daName", m_Child->Attribute("daName"));
					}
					if (m_Child->Attribute("doName") != NULL)
					{
						m_FCDA->SetAttribute("doName", m_Child->Attribute("doName"));
					}
					if (m_Child->Attribute("fc") != NULL)
					{
						m_FCDA->SetAttribute("fc", m_Child->Attribute("fc"));
					}
					if (m_Child->Attribute("ldInst") != NULL)
					{
						m_FCDA->SetAttribute("ldInst", m_Child->Attribute("ldInst"));

					}
					if (m_Child->Attribute("lnClass") != NULL)
					{
						m_FCDA->SetAttribute("lnClass", m_Child->Attribute("lnClass"));

					}
					if (m_Child->Attribute("lnInst") != NULL)
					{
						m_FCDA->SetAttribute("lnInst", m_Child->Attribute("lnInst"));

					}
					if (m_Child->Attribute("prefix") != NULL)
					{
						m_FCDA->SetAttribute("prefix", m_Child->Attribute("prefix"));

					}
					//QMessageBox::about(0, "notice", QString::number(i));
					//i++;
					m_FCDA = Fill_FCDA_GOOSE(m_LD, m_FCDA);
					m_Set->LinkEndChild(m_FCDA);
				}
			}
			CBL_Map.clear();
			Init_SMV_Map(m_LN, CBL_Map, 0);
			for (int m = 0; m < CBL_Map.uniqueKeys().size(); m++)
			{
				m_CBL = CBL_Map.value(CBL_Map.uniqueKeys().at(m));
				str.clear();
				str += m_CBL->Attribute("smvID");
				m_SMVCBref = new TiXmlElement("MSVCBRef");
				m_SMVCBref->SetAttribute("name", str.toStdString().data());
				m_SMVPUB->LinkEndChild(m_SMVCBref);
				m_SMVCBref->LinkEndChild(m_CBL->Clone()->ToElement());
				str.clear();
				str += m_CBL->Attribute("name");
				m_ConnectAP = GetConnectAP(strIED, strAP, Map_LD.uniqueKeys().at(i), str, 2);
				if (m_ConnectAP != NULL)
				{
					m_SMVCBref->LinkEndChild(m_ConnectAP);

				}
				m_Set = new TiXmlElement("DataSet");
				m_Set->SetAttribute("name", m_CBL->Attribute("datSet"));
				m_SMVCBref->LinkEndChild(m_Set);
				str.clear();
				str += m_CBL->Attribute("datSet");
				m_DataSet = DataSet_Map.value(str);
				//QMessageBox::about(0, "notice", str);
				for (m_Child = m_DataSet->FirstChildElement(); m_Child != NULL; m_Child = m_Child->NextSiblingElement())
				{
					m_FCDA = new TiXmlElement("FCDA");
					str.clear();
					str += m_Child->Attribute("prefix");
					str += m_Child->Attribute("prefix");
					str += m_Child->Attribute("doName");
					//m_FCDA->SetAttribute("daName", m_Child->Attribute("daName"));
					if (m_Child->Attribute("doName") != NULL)
					{
						m_FCDA->SetAttribute("doName", m_Child->Attribute("doName"));

					}
					if (m_Child->Attribute("fc") != NULL)
					{
						m_FCDA->SetAttribute("fc", m_Child->Attribute("fc"));

					}
					if (m_Child->Attribute("ldInst") != NULL)
					{
						m_FCDA->SetAttribute("ldInst", m_Child->Attribute("ldInst"));

					}
					if (m_Child->Attribute("lnClass") != NULL)
					{
						m_FCDA->SetAttribute("lnClass", m_Child->Attribute("lnClass"));

					}
					if (m_Child->Attribute("lnInst") != NULL)
					{
						m_FCDA->SetAttribute("lnInst", m_Child->Attribute("lnInst"));

					}
					if (m_Child->Attribute("prefix") != NULL)
					{
						m_FCDA->SetAttribute("prefix", m_Child->Attribute("prefix"));

					}
					m_FCDA = Fill_FCDA_SMV(m_LD, m_FCDA);
					m_Set->LinkEndChild(m_FCDA);
				}
			}
		}
	}
	return m_SCL;
	//Init_FCDA_MAP();
	//QMap<QString, TiXmlElement*> Map_IED;
	//QMap<QString, TiXmlElement*> Map_LD;
	//QMap<QString, TiXmlElement*> Map_LN;
	//QMap<QString, TiXmlElement*> DataSet_Map;
	//QMap<QString, TiXmlElement*> CBL_Map;
	//TiXmlElement* m_IED = NULL;
	//TiXmlElement* m_LD = NULL;
	//TiXmlElement* m_LN = NULL;
	//TiXmlElement* m_Input = NULL;
	//TiXmlElement* m_DataSet= NULL;
	//TiXmlElement* m_Private = NULL;
	//TiXmlElement* m_P = NULL;
	//TiXmlElement* m_Server = NULL;
	//TiXmlElement* m_EXRef = NULL;
	//TiXmlText* m_Text = NULL;
	//TiXmlDocument* m_DOC = NULL;
	//TiXmlDocument* m_GOOSESUB = NULL;
	//TiXmlDocument* m_root = NULL;
	//TiXmlPrinter Pstr;
	//Init_IED_MAP(root, Map_IED);
	////QVector<INPUT_Config>Input_Vector;
	////TiXmlDocument* DOCPoint = NULL;

	//for (int i = 0; i < Map_IED.uniqueKeys().size(); i++)
	//{
	//	m_P = NULL;
	//	m_DOC = new TiXmlDocument;
	//	TiXmlDeclaration *Declaration = new TiXmlDeclaration("1.0", "UTF-8", "");
	//	m_DOC->LinkEndChild(Declaration);
	//	//Init_ConfigFIle(DOCPoint);
	//	m_IED = Map_IED.value(Map_IED.uniqueKeys().at(i));
	//	m_root = new TiXmlDocument(Map_IED.uniqueKeys().at(i).toStdString().data());
	//	m_DOC->LinkEndChild(m_root);
	//	m_GOOSESUB = new TiXmlDocument("GOOSEPUB");
	//	m_root->LinkEndChild(m_GOOSESUB);
	//	Init_LD_MAP(m_IED, Map_LD);
	//	for (int j = 0; j < Map_LD.uniqueKeys().size(); j++)
	//	{
	//		m_LD = Map_LD.value(Map_LD.uniqueKeys().at(j));
	//		Init_LN_MAP(m_LD, Map_LN);
	//		for (int m = 0; m < Map_LN.uniqueKeys().size(); m++)
	//		{
	//			m_LN = Map_LN.value(Map_LN.uniqueKeys().at(m));
	//			Init_ControBlock_MAP(m_LN, CBL_Map, 2);
	//			for (int n = 0; n < CBL_Map.uniqueKeys().size();n++)
	//			{

	//			}
	//		}
	//	}

	//for (int m = 0; m < Map_LN.uniqueKeys().size(); m++)
	//{
	//	m_LN = Map_LN.value(Map_LN.uniqueKeys().at(m));
	//	m_Input = m_LN->FirstChildElement("Inputs");
	//	if (m_Input == NULL)
	//	{
	//		continue;
	//	}
	//	else
	//	{
	//		for (m_EXRef = m_Input->FirstChildElement(); m_EXRef != NULL; m_EXRef = m_EXRef->NextSiblingElement())
	//		{
	//			Fill_Input_config(m_EXRef, Input_Vector, 1);
	//		}
	//	}

	//}
	//if (Input_Vector.size() == 0)
	//{
	//	continue;

	//}
	//else
	//{
	//	m_DOC = new TiXmlDocument;
	//	Init_ConfigFIle(m_DOC);
	//}
	//for (int k = 0; k < Input_Vector.size(); k++)
	//{
	//	WriteData2Config(Map_IED.uniqueKeys().at(i), m_DOC, Input_Vector[k], k, 1);

	//}
	//Input_Vector.clear();
	//	m_DOC->Accept(&Pstr);
	//	delete m_DOC;
	//	const char *TempPstr = Pstr.CStr();//把指针取出
	//	int len = strlen(TempPstr);//计算长度
	//	if (len == 0)return DO_FAIL;
	//	char * RPstr = new char[len];
	//	memcpy(RPstr, TempPstr, len + 1);
	//	QString str;
	//	str.clear();
	//	str += RPstr;
	//	str = str.simplified();
	//	unsigned long crc;
	//	m_SumCheck.CRCInit(crc);
	//	m_SumCheck.CRCUpdate(str.toLocal8Bit().data(), str.length(), crc);
	//	m_SumCheck.CRCFinal(crc);
	//	m_Server = m_IED->FirstChildElement("Services");
	//	for (m_Private = m_Server->FirstChildElement("Private"); m_Private != NULL; m_Private = m_Private->NextSiblingElement("Private"))
	//	{
	//		if (0 == strcmp("IED virtual terminal conection CRC", m_Private->Attribute("type")))
	//		{
	//			m_P = m_Private;
	//			break;
	//		}
	//		else
	//		{
	//			m_P = NULL;
	//		}
	//	}
	//	if (m_P == NULL)
	//	{
	//		m_P = new TiXmlElement("Private");
	//		m_P->SetAttribute("type", "IED virtual terminal conection CRC");
	//		m_Text = new TiXmlText(QString::number(crc).toUpper().toStdString().data());
	//		m_P->LinkEndChild(m_Text);
	//		m_Server->LinkEndChild(m_P);
	//	}
	//	else
	//	{
	//		m_Text = m_P->FirstChild()->ToText();
	//		m_Text->SetValue(QString::number(crc).toUpper().toStdString().data());
	//	}
	//}

	//return DO_OK;
}
TiXmlElement* ScdTree::GetConnectAP(QString IED, QString AP, QString LD, QString CB, int state)
{
	QMap<QString, TiXmlElement*> Map_AP;
	TiXmlElement* m_AP = NULL;
	TiXmlElement* m_SubNet = NULL;
	TiXmlElement* m_Communication = NULL;
	TiXmlElement* m_GSE = NULL;
	m_Communication = root->FirstChildElement("Communication");

	for (m_SubNet = m_Communication->FirstChildElement("SubNetwork"); m_SubNet != NULL; m_SubNet = m_SubNet->NextSiblingElement("SubNetwork"))
	{
		Init_ConnectAP_MAP(m_SubNet, Map_AP);
		for (int i = 0; i < Map_AP.uniqueKeys().size(); i++)
		{
			for (int j = 0; j < Map_AP.values(IED).size(); j++)
			{
				m_AP = Map_AP.values(IED).at(j);
				if (0 == strcmp(AP.toStdString().data(), m_AP->Attribute("apName")))
				{
					if (CB.isEmpty())
					{
						return m_AP->Clone()->ToElement();
					}
					else
					{
						if (state == 1)
						{
							for (m_GSE = m_AP->FirstChildElement("GSE"); m_GSE != NULL; m_GSE = m_GSE->NextSiblingElement("GSE"))
							{
								if (0 == strcmp(LD.toStdString().data(), m_GSE->Attribute("ldInst")))
								{
									if (0 == strcmp(CB.toStdString().data(), m_GSE->Attribute("cbName")))
									{
										return m_AP->Clone()->ToElement();
									}
								}
							}
						}
						else if (state == 2)
						{
							for (m_GSE = m_AP->FirstChildElement("SMV"); m_GSE != NULL; m_GSE = m_GSE->NextSiblingElement("SMV"))
							{
								if (0 == strcmp(LD.toStdString().data(), m_GSE->Attribute("ldInst")))
								{
									if (0 == strcmp(CB.toStdString().data(), m_GSE->Attribute("cbName")))
									{
										return m_AP->Clone()->ToElement();
									}
								}
							}
						}

					}

				}
			}
		}
	}
	return NULL;
}
TiXmlElement* ScdTree::Fill_FCDA_GOOSE(TiXmlElement* m_LD, TiXmlElement* m_FCDA)
{
	TiXmlElement* m_DAI = NULL;
	QString str;
	QMap<QString, TiXmlElement*> Map_LN;
	QMap<QString, TiXmlElement*> Map_Type;
	TiXmlElement* m_LN = NULL;
	TiXmlElement* m_Child = NULL;
	QStringList strList;
	str += m_FCDA->Attribute("prefix");
	str += m_FCDA->Attribute("lnClass");
	str += m_FCDA->Attribute("lnInst");
	Init_LN_MAP(m_LD, Map_LN);
	m_LN = Map_LN.value(str);
	if (m_LN == NULL)
	{
		return m_FCDA->Clone()->ToElement();
	}
	str.clear();
	str += m_FCDA->Attribute("doName");
	str += ".";
	str += m_FCDA->Attribute("daName");
	strList = str.split(".");
	m_Child = m_LN->GetChildByName_Value("name", strList.at(0).toStdString().data());
	if (m_Child == NULL)
	{
		return m_FCDA->Clone()->ToElement();
	}
	for (int i = 1; i < strList.size(); i++)
	{
		m_Child = m_Child->GetChildByName_Value("name", strList.at(i).toStdString().data());
		if (m_Child == NULL)
		{
			return m_FCDA->Clone()->ToElement();
		}
	}

	if (m_Child == NULL)
	{
		return m_FCDA->Clone()->ToElement();
	}
	m_FCDA->LinkEndChild(m_Child->Clone());
	str.clear();
	str += m_LN->Attribute("lnType");
	TiXmlElement* m_DataTemp = NULL;
	TiXmlElement* m_LnType = NULL;
	TiXmlElement* m_DoType = NULL;
	TiXmlElement* m_DaType = NULL;
	m_DataTemp = root->FirstChildElement("DataTypeTemplates");

	Init_LNtype_MAP(m_DataTemp, Map_Type);
	m_LnType = Map_Type.value(str);
	if (m_LnType == NULL)
	{
		return m_FCDA->Clone()->ToElement();
	}
	str.clear();
	str += m_FCDA->Attribute("doName");

	if (!str.contains("."))
	{
		m_Child = m_LnType->GetChildByName_Value("name", str.toStdString().data());
		if (m_Child == NULL)
		{
			return m_FCDA->Clone()->ToElement();
		}

		str.clear();
		str += m_Child->Attribute("type");
		Init_DOType_MAP(m_DataTemp, Map_Type);
		m_DoType = Map_Type.value(str);
	}
	else
	{
		QStringList list;
		list = str.split(".");
		m_Child = m_LnType->GetChildByName_Value("name", list.at(0).toStdString().data());
		if (m_Child == NULL)
		{
			return m_FCDA->Clone()->ToElement();
		}
		str.clear();
		str += m_Child->Attribute("type");
		Init_DOType_MAP(m_DataTemp, Map_Type);
		m_DoType = Map_Type.value(str);
		if (m_DoType == NULL)
		{
			return m_FCDA->Clone()->ToElement();
		}
		m_Child = m_DoType->GetChildByName_Value("name", list.at(1).toStdString().data());
		if (m_Child == NULL)
		{
			return m_FCDA->Clone()->ToElement();
		}
		str.clear();
		str += m_Child->Attribute("type");
		Init_DOType_MAP(m_DataTemp, Map_Type);
		m_DoType = Map_Type.value(str);
	}
	str.clear();
	str += m_FCDA->Attribute("daName");
	if (m_DoType == NULL)
	{
		return m_FCDA->Clone()->ToElement();
	}
	if (!str.contains("."))
	{
		m_Child = m_DoType->GetChildByName_Value("name", str.toStdString().data());
		QString chr;
		chr += m_Child->Attribute("type");

	}
	else
	{
		QStringList list;
		list = str.split(".");
		m_Child = m_DoType->GetChildByName_Value("name", list.at(0).toStdString().data());
		if (m_Child == NULL)
		{
			return m_FCDA->Clone()->ToElement();
		}
		list.removeAt(0);
		Init_DAtype_MAP(m_DataTemp, Map_Type);
		str.clear();
		str += m_Child->Attribute("type");
		m_DaType = Map_Type.value(str);
		if (m_DaType == NULL)
		{
			return m_FCDA->Clone()->ToElement();
		}
		for (int i = 0; i < list.size(); i++)
		{
			m_Child = m_DaType->GetChildByName_Value("name", list.at(i).toStdString().data());
			if (m_Child == NULL)
			{
				return m_FCDA->Clone()->ToElement();
			}
			if (m_DaType->Attribute("type") != NULL)
			{
				str.clear();
				str += m_DaType->Attribute("type");
				m_DaType = Map_Type.value(str);
				if (m_DaType == NULL)
				{
					return m_FCDA->Clone()->ToElement();
				}
			}
			//str.clear();
			//str += m_Child->Attribute("bType");
			//QMessageBox::about(0, "notice", str);
		}
	}
	if (m_Child == NULL)
	{
		return m_FCDA->Clone()->ToElement();
	}
	else
	{
		m_FCDA->SetAttribute("bType", m_Child->Attribute("bType"));
		return m_FCDA->Clone()->ToElement();
	}
}

TiXmlElement* ScdTree::Fill_FCDA_SMV(TiXmlElement* m_LD, TiXmlElement* m_FCDA)
{
	TiXmlElement* m_DAI = NULL;
	QString str;
	QMap<QString, TiXmlElement*> Map_LN;
	QMap<QString, TiXmlElement*> Map_Type;
	TiXmlElement* m_LN = NULL;
	TiXmlElement* m_Child = NULL;
	QStringList strList;
	str += m_FCDA->Attribute("prefix");
	str += m_FCDA->Attribute("lnClass");
	str += m_FCDA->Attribute("lnInst");
	Init_LN_MAP(m_LD, Map_LN);
	m_LN = Map_LN.value(str);
	if (m_LN == NULL)
	{
		return m_FCDA->Clone()->ToElement();
	}
	str.clear();
	str += m_FCDA->Attribute("doName");
	strList = str.split(".");
	m_Child = m_LN->GetChildByName_Value("name", strList.at(0).toStdString().data());
	strList.removeAt(0);
	if (m_Child == NULL)
	{
		return m_FCDA->Clone()->ToElement();
	}
	for (int i = 0; i < strList.size(); i++)
	{
		m_Child = m_Child->GetChildByName_Value("name", strList.at(i).toStdString().data());
		if (m_Child == NULL)
		{
			return m_FCDA->Clone()->ToElement();
		}
	}
	if (m_Child == NULL)
	{
		return m_FCDA->Clone()->ToElement();
	}
	m_FCDA->LinkEndChild(m_Child->Clone());
	return m_FCDA->Clone()->ToElement();
}
//int ScdTree::SaveSCDCRC2File()
//{
//	Init_FCDA_MAP();
//	QMap<QString, TiXmlElement*> Map_IED;
//	QMap<QString, TiXmlElement*> Map_LD;
//	QMap<QString, TiXmlElement*> Map_LN;
//	TiXmlElement* m_IED = NULL;
//	TiXmlElement* m_LD = NULL;
//	TiXmlElement* m_LN = NULL;
//	TiXmlElement* m_Input = NULL;
//	TiXmlElement* m_Private = NULL;
//	TiXmlElement* m_P = NULL;
//	TiXmlElement* m_Server = NULL;
//	TiXmlElement* m_EXRef = NULL;
//	TiXmlText* m_Text = NULL;
//
//	TiXmlPrinter Pstr;
//	Init_IED_MAP(root, Map_IED);
//	QVector<INPUT_Config>Input_Vector;
//	TiXmlDocument* DOCPoint = NULL;
//	TiXmlDocument* m_DOC = new TiXmlDocument;
//	TiXmlDeclaration *Declaration = new TiXmlDeclaration("1.0", "UTF-8", "");
//	m_DOC->LinkEndChild(Declaration);
//	TiXmlElement *SCL_element = new TiXmlElement("Config");
//	m_DOC->LinkEndChild(SCL_element);
//	for (int i = 0; i < Map_IED.uniqueKeys().size(); i++)
//	{
//		m_P = NULL;
//		DOCPoint = new TiXmlDocument;
//		Init_ConfigFIle(DOCPoint);
//		m_IED = Map_IED.value(Map_IED.uniqueKeys().at(i));
//
//		Init_LD_MAP(m_IED, Map_LD);
//		for (int j = 0; j < Map_LD.uniqueKeys().size(); j++)
//		{
//			m_LD = Map_LD.value(Map_LD.uniqueKeys().at(j));
//			Init_LN_MAP(m_LD, Map_LN);
//			for (int m = 0; m < Map_LN.uniqueKeys().size(); m++)
//			{
//				m_LN = Map_LN.value(Map_LN.uniqueKeys().at(m));
//				m_Input = m_LN->FirstChildElement("Inputs");
//				if (m_Input == NULL)
//				{
//					continue;
//				}
//				else
//				{
//					for (m_EXRef = m_Input->FirstChildElement(); m_EXRef != NULL; m_EXRef = m_EXRef->NextSiblingElement())
//					{
//						Fill_Input_config(m_EXRef, Input_Vector, 1);
//					}
//				}
//
//			}
//		}
//		if (Input_Vector.size() != 0)
//		{
//
//			for (int k = 0; k < Input_Vector.size(); k++)
//			{
//				WriteData2Config(Map_IED.uniqueKeys().at(i), DOCPoint, Input_Vector[k], k, 1);
//
//			}
//			Input_Vector.clear();
//			m_P = DOCPoint->FirstChildElement("Config")->FirstChild()->Clone()->ToElement();
//			m_DOC->FirstChildElement("Config")->LinkEndChild(m_P);
//			delete DOCPoint;
//		}
//
//
//	}
//	//m_DOC->SaveFile(filename.replace(".SCD",".xml").toStdString().data());
//
//	Input_Vector.clear();
//	m_DOC->Accept(&Pstr);
//	delete m_DOC;
//	const char *TempPstr = Pstr.CStr();//把指针取出
//	int len = strlen(TempPstr);//计算长度
//	if (len == 0)return DO_FAIL;
//	char * RPstr = new char[len];
//	memcpy(RPstr, TempPstr, len + 1);
//	QString str;
//	str.clear();
//	str += RPstr;
//	str = str.simplified();
//	unsigned long crc;
//	m_SumCheck.CRCInit(crc);
//	m_SumCheck.CRCUpdate(str.toLocal8Bit().data(), str.length(), crc);
//	m_SumCheck.CRCFinal(crc);
//	//m_Private =root->FirstChildElement("Private");
//	for (m_Private = root->FirstChildElement("Private"); m_Private != NULL; m_Private = m_Private->NextSiblingElement("Private"))
//	{
//		if (0 == strcmp("Substation virtual terminal conection CRC", m_Private->Attribute("type")))
//		{
//			m_P = m_Private;
//			break;
//		}
//		else
//		{
//			m_P = NULL;
//		}
//	}
//	if (m_P == NULL)
//	{
//		m_P = new TiXmlElement("Private");
//		m_P->SetAttribute("type", "Substation virtual terminal conection CRC");
//		m_Text = new TiXmlText(QString::number(crc).toUpper().toStdString().data());
//		m_P->LinkEndChild(m_Text);
//		root->InsertBeforeChild(root->FirstChildElement("Header"), *m_P);
//	}
//	else
//	{
//		m_Text = m_P->FirstChild()->ToText();
//		m_Text->SetValue(QString::number(crc).toUpper().toStdString().data());
//	}
//
//
//	return DO_OK;
//}
int ScdTree::CheckXLS_IED(QString File, QVector<Map_IED>&Map)
{
	using namespace libxl;
	//bool recode;
	QString error;
	Book* book = xlCreateBook(); // use xlCreateXMLBook() for working with xlsx files
	book->setKey("Halil Kural", "windows-2723210a07c4e90162b26966a8jcdboe");

	if (!book->load(File.toLocal8Bit().data()))
	{
		error = QString::fromLocal8Bit(book->errorMessage());
		QMessageBox::about(0, "Notice", error);
		return DO_FAIL;
	}
	int count = book->sheetCount();
	QMap<QString, TiXmlElement*>IED_Map;
	Init_IED_MAP(root, IED_Map);
	for (int i = 0; i < count; i++)
	{
		Map_IED m_data;
		Sheet *m_sheet = book->getSheet(i);
		m_data.State = true;
		m_data.available = true;
		m_data.IEDName = QString::fromLocal8Bit(m_sheet->name());
		if (!IED_Map.keys().contains(m_data.IEDName))
		{
			m_data.State = false;
			m_data.available = false;
		}
		Map.append(m_data);
	}
	return DO_OK;
}

void ScdTree::ImportXLS(QString File, QVector<Map_IED>Map)
{
	QMap<QString, Input_Mapping>Input_Map;

	QMap<QString, Input_Mapping>Map_Repeat;
	QMap<QString, Input_Mapping>Map_invalid_IN;
	QMap<QString, Input_Mapping>Map_invalid_OUT;

	QMap<QString, Input_Mapping>Map_available;
	using namespace libxl;
	//bool recode;
	QString error;
	QString strIED;
	Book* book = xlCreateBook(); // use xlCreateXMLBook() for working with xlsx files
	book->setKey("Halil Kural", "windows-2723210a07c4e90162b26966a8jcdboe");

	if (!book->load(File.toLocal8Bit().data()))
	{
		error = QString::fromLocal8Bit(book->errorMessage());
		QMessageBox::about(0, "Notice", error);

		return;
	}

	for (int j = 0; j < Map.size(); j++)
	{
		Input_Map.clear();
		for (int i = 0; i < book->sheetCount(); i++)
		{
			Sheet *m_sheet = book->getSheet(i);
			if (0 == strcmp(m_sheet->name(), Map.at(j).IEDName.toLocal8Bit().data()))
			{
				if (QString::number(m_sheet->readNum(2, 0)).isEmpty())
				{
					break;
				}
				Input_Mapping m_data;
				int Empty_Count = 0;
				int row = 2;
				while (Empty_Count < 5)
				{
					if (m_sheet->readNum(row, 0) == 0)
					{
						Empty_Count++;
						row++;
						continue;
					}
					else
					{
						Empty_Count = 0;
					}
					m_data.External_DataSet = QString::fromLocal8Bit(m_sheet->readStr(row, 1));

					strIED = QString::fromLocal8Bit(m_sheet->readStr(row, 3));
					if (strIED.contains(":"))
					{
						m_data.External_IED = strIED.left(strIED.indexOf(":"));
					}
					else
					{
						m_data.External_IED = strIED;
					}

					m_data.External_Index = QString::fromLocal8Bit(m_sheet->readStr(row, 4)).remove("GOOUT_");
					m_data.External_Reference = QString::fromLocal8Bit(m_sheet->readStr(row, 5));

					strIED = QString::fromLocal8Bit(m_sheet->readStr(row, 7));
					if (strIED.contains(":"))
					{
						m_data.Interior_IED = strIED.left(strIED.indexOf(":"));
					}
					else
					{
						m_data.Interior_IED = strIED;
					}
					m_data.Index = QString::fromLocal8Bit(m_sheet->readStr(row, 8)).toInt();
					m_data.Interior_Reference = QString::fromLocal8Bit(m_sheet->readStr(row, 9)).remove("GOOIN_");
					row++;
					Input_Map.insertMulti(QString::fromLocal8Bit(m_sheet->name()), m_data);

				}


			}
		}
		for (int i = 0; i < Input_Map.uniqueKeys().size(); i++)
		{
			for (int j = 0; j < Input_Map.values(Input_Map.uniqueKeys().at(i)).size(); j++)
			{
				CheckXLS_Input(Input_Map.values(Input_Map.uniqueKeys().at(i)).at(j), Map_Repeat, Map_invalid_IN, Map_invalid_OUT, Map_available);
			}
		}
	}
	ImportXLS_RS *m_dlg = new ImportXLS_RS;
	m_dlg->Map_available = Map_available;
	m_dlg->Map_invalid_IN = Map_invalid_IN;
	m_dlg->Map_invalid_OUT = Map_invalid_OUT;
	m_dlg->Map_Repeat = Map_Repeat;
	m_dlg->Init_dlg();
	m_dlg->Display();
	if (m_dlg->exec() == QDialog::Accepted)
	{
		ImportXLS_Map(Map_available);
	}

}
void ScdTree::CheckXLS_Input(Input_Mapping m_data, QMap<QString, Input_Mapping>&Map_Repeat,
	QMap<QString, Input_Mapping>&Map_invalid_IN, QMap<QString, Input_Mapping>&Map_invalid_OUT, QMap<QString, Input_Mapping>&Map_available)
{
	QMap<QString, TiXmlElement*>IED_Map;
	QMap<QString, TiXmlElement*>LD_Map;
	QMap<QString, TiXmlElement*>LN_Map;
	QMap<QString, TiXmlElement*>DataSet_Map;
	TiXmlElement* m_IED = NULL;
	TiXmlElement* m_LD = NULL;
	TiXmlElement* m_LN = NULL;
	TiXmlElement* m_DataSet = NULL;
	TiXmlElement* m_Input = NULL;
	TiXmlElement* m_Child = NULL;
	QString strLD;
	Init_IED_MAP(root, IED_Map);
	m_IED = IED_Map.value(m_data.External_IED);
	int index;
	index = m_data.External_Reference.indexOf("/");
	strLD = m_data.External_Reference.left(index);
	Init_LD_MAP(m_IED, LD_Map);
	m_LD = LD_Map.value(strLD);
	m_LN = m_LD->FirstChildElement("LN0");
	Init_DataSet_MAP(m_LN, DataSet_Map);
	m_DataSet = DataSet_Map.value(m_data.External_DataSet);
	QStringList InstanceList;
	for (m_Child = m_DataSet->FirstChildElement(); m_Child != NULL; m_Child = m_Child->NextSiblingElement())
	{
		QString Instance;
		QString str;
		str.clear();
		str += m_Child->Attribute("ldInst");
		Instance += str + "/";
		str.clear();
		str += m_Child->Attribute("prefix");
		Instance += str;
		str.clear();
		str += m_Child->Attribute("lnClass");
		Instance += str;
		str.clear();
		str += m_Child->Attribute("lnInst");
		Instance += str;
		Instance += ".";
		str.clear();
		str += m_Child->Attribute("doName");
		Instance += str;
		Instance += ".";
		str.clear();
		str += m_Child->Attribute("daName");
		Instance += str;
		InstanceList.append(Instance);
	}
	if (!InstanceList.contains(m_data.External_Reference))
	{
		Map_invalid_OUT.insertMulti(m_data.Interior_IED, m_data);
		return;
	}
	m_IED = IED_Map.value(m_data.Interior_IED);
	index = m_data.Interior_Reference.indexOf("/");
	strLD = m_data.Interior_Reference.left(index);
	Init_LD_MAP(m_IED, LD_Map);
	m_LD = LD_Map.value(strLD);
	m_LN = m_LD->FirstChildElement("LN0");
	m_Input = m_LN->FirstChildElement("Inputs");
	if (m_Input != NULL)
	{
		InstanceList.clear();
		for (m_Child = m_Input->FirstChildElement(); m_Child != NULL; m_Child = m_Child->NextSiblingElement())
		{
			QString Instance;
			Instance += m_Child->Attribute("intAddr");
			InstanceList.append(Instance);
		}
		if (InstanceList.contains(m_data.Interior_Reference))
		{
			Map_Repeat.insertMulti(m_data.Interior_IED, m_data);
			return;
		}
	}

	QString strrest;
	strrest = m_data.Interior_Reference.right(m_data.Interior_Reference.length() - index - 1);
	QStringList list;
	m_LN = NULL;
	list = strrest.split(".");
	Init_LN_MAP(m_LD, LN_Map);
	m_LN = LN_Map.value(list.at(0));
	list.takeAt(0);
	if (m_LN == NULL)
	{
		Map_invalid_IN.insertMulti(m_data.Interior_IED, m_data);
		return;
	}
	m_Child = m_LN;
	while (list.size() != 0)
	{
		QString str = list.at(0);
		m_Child = m_Child->GetChildByName_Value("name", str.toStdString().data());
		list.takeAt(0);
		if (m_Child == NULL)
		{
			Map_invalid_IN.insertMulti(m_data.Interior_IED, m_data);
			return;
		}
	}
	Map_available.insertMulti(m_data.Interior_IED, m_data);
	return;
}

void ScdTree::ImportXLS_Map(QMap<QString, Input_Mapping>&Map)
{
	QMap<QString, TiXmlElement*>IED_Map;
	QMap<QString, TiXmlElement*>LD_Map;
	QMap<QString, TiXmlElement*>LN_Map;
	QMap<QString, TiXmlElement*>DataSet_Map;
	QVector<DataMatrix_Struct> DataVector;
	QMap<QString, Input_Struct> Input_Map;
	TiXmlElement* m_IED = NULL;
	TiXmlElement* m_LD = NULL;
	TiXmlElement* m_LN = NULL;
	TiXmlElement* m_DataSet = NULL;
	TiXmlElement* m_Input = NULL;
	int index;
	QString strLD;
	Init_IED_MAP(root, IED_Map);
	//CreatDataMatrix(QString LNodeType,QVector<DataMatrix_Struct>&);
	for (int i = 0; i < Map.uniqueKeys().size(); i++)
	{
		for (int j = 0; j < Map.values(Map.uniqueKeys().at(i)).size(); j++)
		{
			Input_Struct m_data;
			GetSender_Struct(Map.values(Map.uniqueKeys().at(i)).at(j), m_data);
			m_data.B_intAddr = Map.values(Map.uniqueKeys().at(i)).at(j).Interior_Reference;
			m_data.B_iedName = Map.values(Map.uniqueKeys().at(i)).at(j).External_IED;
			m_data.B_InterIED = Map.values(Map.uniqueKeys().at(i)).at(j).Interior_IED;
			Input_Map.insertMulti(m_data.B_InterIED, m_data);
		}
	}
	for (int i = 0; i < Input_Map.uniqueKeys().size(); i++)
	{
		m_IED = IED_Map.value(Input_Map.uniqueKeys().at(i));
		for (int j = 0; j < Input_Map.values(Input_Map.uniqueKeys().at(i)).size(); j++)
		{
			index = Input_Map.values(Input_Map.uniqueKeys().at(i)).at(j).B_intAddr.indexOf("/");
			strLD = Input_Map.values(Input_Map.uniqueKeys().at(i)).at(j).B_intAddr.left(index);
			Init_LD_MAP(m_IED, LD_Map);
			m_LD = LD_Map.value(strLD);
			m_LN = m_LD->FirstChildElement("LN0");
			m_Input = m_LN->FirstChildElement("Inputs");
			if (m_Input == NULL)
			{
				m_Input = new TiXmlElement("Inputs");
				m_LN->InsertBeforeChild(m_LN->FirstChild(), *m_Input);
			}
			TiXmlElement *m_EXRef = new TiXmlElement("ExtRef");
			m_EXRef->SetAttribute("iedName", Input_Map.values(Input_Map.uniqueKeys().at(i)).at(j).B_iedName.toStdString().data());
			m_EXRef->SetAttribute("ldInst", Input_Map.values(Input_Map.uniqueKeys().at(i)).at(j).B_ldInst.toStdString().data());

			m_EXRef->SetAttribute("prefix", Input_Map.values(Input_Map.uniqueKeys().at(i)).at(j).B_prefix.toStdString().data());
			m_EXRef->SetAttribute("lnClass", Input_Map.values(Input_Map.uniqueKeys().at(i)).at(j).B_lnClass.toStdString().data());
			m_EXRef->SetAttribute("lnInst", Input_Map.values(Input_Map.uniqueKeys().at(i)).at(j).B_lnInst.toStdString().data());
			m_EXRef->SetAttribute("doName", Input_Map.values(Input_Map.uniqueKeys().at(i)).at(j).B_doName.toStdString().data());
			m_EXRef->SetAttribute("daName", Input_Map.values(Input_Map.uniqueKeys().at(i)).at(j).B_daName.toStdString().data());
			m_EXRef->SetAttribute("intAddr", Input_Map.values(Input_Map.uniqueKeys().at(i)).at(j).B_intAddr.toStdString().data());

			m_Input->LinkEndChild(m_EXRef);
		}
	}
}
void ScdTree::GetSender_Struct(Input_Mapping m_data, Input_Struct&m_sender)
{
	QMap<QString, TiXmlElement*>IED_Map;
	QMap<QString, TiXmlElement*>LD_Map;
	QMap<QString, TiXmlElement*>LN_Map;
	QVector<DataMatrix_Struct> DataVector;
	TiXmlElement* m_IED = NULL;
	TiXmlElement* m_LD = NULL;
	TiXmlElement* m_LN = NULL;
	Init_IED_MAP(root, IED_Map);
	m_IED = IED_Map.value(m_data.External_IED);
	Init_LD_MAP(m_IED, LD_Map);
	int index;
	QString str, str1, str2, str3;
	str = m_data.External_Reference;
	index = str.indexOf("/");
	str1 = str.left(index);
	str2 = str.right(str.length() - index - 1);
	QStringList list;
	list = str2.split(".");
	m_LD = LD_Map.value(str1);
	Init_LN_MAP(m_LD, LN_Map);
	m_LN = LN_Map.value(list.at(0));
	str3 += m_LN->Attribute("lnType");
	m_sender.B_ldInst = str1;
	m_sender.B_prefix += m_LN->Attribute("prefix");
	m_sender.B_lnClass += m_LN->Attribute("lnClass");
	m_sender.B_lnInst += m_LN->Attribute("inst");
	CreatDataMatrix(str3, DataVector);
	str2.remove(list.at(0) + ".");
	for (int i = 0; i < DataVector.size(); i++)
	{
		str.clear();
		str = DataVector.at(i).B_doName + ".";
		str += DataVector.at(i).B_daName;
		if (str2 == str)
		{
			m_sender.B_doName = DataVector.at(i).B_doName;
			m_sender.B_daName = DataVector.at(i).B_daName;
		}
	}
}
void ScdTree::ExportCID_Node(QString oldName, QString name, TiXmlDocument* m_doc)
{
	std::string str = name.toStdString();

	const char* chr = str.c_str();
	QMap<QString, TiXmlElement* > APMap;
	QMap<QString, TiXmlElement* > IEDMap;
	QMap<QString, TiXmlElement* > LnTypeMap;
	QMap<QString, TiXmlElement* > DOTypeMap;
	QMap<QString, TiXmlElement* > DATypeMap;
	QMap<QString, TiXmlElement* > EnumTypeMap;
	QStringList LnTypeList;
	QStringList DOTypeList;
	QStringList DATypeList;
	QStringList EnumTypeList;
	TiXmlElement*node = NULL;

	TiXmlDeclaration *Declaration = new TiXmlDeclaration("1.0", "UTF-8", "");
	m_doc->LinkEndChild(Declaration);
	TiXmlElement *SCL_element = new TiXmlElement("SCL");
	SCL_element->SetAttribute("xmlns", "http://www.iec.ch/61850/2003/SCL");
	SCL_element->SetAttribute("xmlns:xsi", "http://www.w3.org/2001/XMLSchema-instance");
	SCL_element->SetAttribute("xmlns:kf", "http://www.keyvia.cn");
	SCL_element->SetAttribute("xsi:schemaLocation", "http://www.iec.ch/61850/2003/SCL SCL.xsd");

	TiXmlElement *Header_element = new TiXmlElement("Header");
	Header_element->SetAttribute("id", chr);
	Header_element->SetAttribute("version", "1.00");
	Header_element->SetAttribute("toolID", "Keyvia Configuration");
	Header_element->SetAttribute("nameStructure", "IEDName");
	SCL_element->LinkEndChild(Header_element);

	TiXmlElement *Comm_element = new TiXmlElement("Communication");
	TiXmlElement *SubNet = root->FirstChildElement("Communication")->FirstChildElement("SubNetwork");
	for (; SubNet != NULL; SubNet = SubNet->NextSiblingElement("SubNetwork"))
	{
		APMap.clear();
		Init_ConnectAP_MAP(SubNet, APMap);
		if (APMap.contains(oldName))
		{
			TiXmlElement *NetNode = new TiXmlElement(SubNet->Value());
			NetNode->SetAttribute("name", chr);
			NetNode->SetAttribute("type", SubNet->Attribute("type"));
			NetNode->SetAttribute("desc", SubNet->Attribute("desc"));
			node = APMap.value(oldName);
			NetNode->LinkEndChild(node->Clone()->ToElement());
			Comm_element->LinkEndChild(NetNode);
		}
	}
	SCL_element->LinkEndChild(Comm_element);
	Init_IED_MAP(root, IEDMap);

	node = IEDMap.value(oldName);
	node->SetAttribute("name", chr);
	SCL_element->LinkEndChild(node->Clone()->ToElement());
	TiXmlElement *DataType_element = new TiXmlElement("DataTypeTemplates");
	GetLnTypeList(IEDMap.value(oldName), LnTypeList);
	Init_LNtype_MAP(root->FirstChildElement("DataTypeTemplates"), LnTypeMap);
	Init_DOType_MAP(root->FirstChildElement("DataTypeTemplates"), DOTypeMap);
	Init_DAtype_MAP(root->FirstChildElement("DataTypeTemplates"), DATypeMap);
	Init_EnumType_MAP(root->FirstChildElement("DataTypeTemplates"), EnumTypeMap);
	for (int i = 0; i < LnTypeList.size(); i++)
	{
		node = LnTypeMap.value(LnTypeList[i]);
		GetDoTypeList(node, DOTypeList);
		DataType_element->LinkEndChild(node->Clone()->ToElement());
	}
	while (DOTypeList.size()>0)
	{
		node = DOTypeMap.value(DOTypeList.at(0));
		GetDaTypeList(node, DOTypeList, DATypeList, EnumTypeList);
		DataType_element->LinkEndChild(node->Clone()->ToElement());
		DOTypeList.removeAt(0);
	}
	while (DATypeList.size() > 0)
	{
		node = DATypeMap.value(DATypeList.at(0));
		GetEnumTypeList(node, DATypeList, EnumTypeList);
		DataType_element->LinkEndChild(node->Clone()->ToElement());
		DATypeList.removeAt(0);
	}
	while (EnumTypeList.size() > 0)
	{
		node = EnumTypeMap.value(EnumTypeList.at(0));
		//GetEnumTypeList(node, EnumTypeList);
		DataType_element->LinkEndChild(node->Clone()->ToElement());
		EnumTypeList.removeAt(0);
	}
	SCL_element->LinkEndChild(DataType_element);
	m_doc->LinkEndChild(SCL_element);

}
bool ScdTree::ImportCID_Node(QString IEDName, TiXmlDocument* m_Doc)
{
	std::string str = IEDName.toStdString();
	const char* chr = NULL;
	const char* ch = str.c_str();
	const char* chName = NULL;
	QString strname;
	//TiXmlNode *m_APNode = m_Doc->FirstChild("SCL")->FirstChild("Communication");
	ImportCID(IEDName, m_Doc);
	return true;
	//for (m_APNode; m_APNode != NULL; m_APNode = m_APNode->NextSibling())
	//{
	//	if (ADDOneAp(m_APNode, IEDName) == DO_FAIL)
	//	{
	//		QMessageBox::about(0, "Alarm", "Add AccessPoint false");

	//		return DO_FAIL;
	//	}
	//}


	//TiXmlNode *m_IEDNode = m_Doc->FirstChild("SCL")->FirstChild("IED")->Clone();
	//TiXmlElement *m_IEDElement = m_IEDNode->ToElement();
	//chName = m_IEDElement->Attribute("name");
	//strname += chName;
	//m_IEDElement->SetAttribute("name", ch);
	//QMap<QString, TiXmlElement*>Map_LD;
	//QMap<QString, TiXmlElement*>Map_LN;
	//QMap<QString, TiXmlElement*>Map_BLK;
	//TiXmlElement* m_LD = NULL;
	//TiXmlElement* m_LN = NULL;
	//TiXmlElement* m_BLK = NULL;
	//Init_LD_MAP(m_IEDElement, Map_LD);
	//for (int i = 0; i < Map_LD.uniqueKeys().size(); i++)
	//{
	//	m_LD = Map_LD.value(Map_LD.uniqueKeys().at(i));
	//	Init_LN_MAP(m_LD, Map_LN);
	//	for (int j = 0; j < Map_LN.uniqueKeys().size(); j++)
	//	{
	//		m_LN = Map_LN.value(Map_LN.uniqueKeys().at(j));
	//		Init_ControBlock_MAP(m_LN, Map_BLK, 2);
	//		for (int m = 0; m < Map_BLK.uniqueKeys().size(); m++)
	//		{
	//			m_BLK = Map_BLK.value(Map_BLK.uniqueKeys().at(m));
	//			chr = m_BLK->Attribute("appID");
	//			QString strAppID;
	//			strAppID += chr;
	//			strAppID.replace(strname, IEDName);
	//			m_BLK->SetAttribute("appID", strAppID.toStdString().data());
	//		}
	//		Init_ControBlock_MAP(m_LN, Map_BLK, 3);
	//		for (int m = 0; m < Map_BLK.uniqueKeys().size(); m++)
	//		{
	//			m_BLK = Map_BLK.value(Map_BLK.uniqueKeys().at(m));
	//			chr = m_BLK->Attribute("appID");
	//			QString strAppID;
	//			strAppID += chr;
	//			strAppID.replace(strname, IEDName);
	//			m_BLK->SetAttribute("appID", strAppID.toStdString().data());
	//		}
	//	}
	//}
	//if (AddOneIED(m_IEDNode) == DO_FAIL)
	//{
	//	QMessageBox::about(0, "Alarm", "Add IEDNode false");
	//	return DO_FAIL;
	//}
	//return DO_OK;
}
void ScdTree::CleanInvalidInput(QString IEDName)
{
	QMap<QString, TiXmlElement*>Map_IED;
	QMap<QString, TiXmlElement*>Map_LD;
	QMap<QString, TiXmlElement*>Map_LN;
	TiXmlElement* m_IED = NULL;
	TiXmlElement* m_LD = NULL;
	TiXmlElement* m_LN = NULL;
	TiXmlElement* m_IN = NULL;
	TiXmlElement* m_Child = NULL;
	Init_IED_MAP(root, Map_IED);
	m_IED = Map_IED.value(IEDName);
	Init_LD_MAP(m_IED, Map_LD);
	for (int i = 0; i < Map_LD.uniqueKeys().size(); i++)
	{
		m_LD = Map_LD.value(Map_LD.uniqueKeys().at(i));
		Init_LN_MAP(m_LD, Map_LN);
		for (int j = 0; j < Map_LN.uniqueKeys().size(); j++)
		{
			m_LN = Map_LN.value(Map_LN.uniqueKeys().at(j));
			m_IN = m_LN->FirstChildElement("Inputs");
			if (m_IN == NULL)
				continue;
			m_Child = m_IN->FirstChildElement();
			if (m_Child == NULL)
			{
				m_LN->RemoveChild(m_IN);
				continue;
			}
			while (m_Child != NULL)
			{
				QString str;
				str += m_Child->Attribute("iedName");
				if (str.isEmpty())
				{
					m_IN->RemoveChild(m_Child);
					m_Child = m_IN->FirstChildElement();
				}
				else
				{
					m_Child = m_Child->NextSiblingElement();
				}
			}
		}
	}

}
int ScdTree::CreatDataMatrix_By_FC(QString LNodeType, QVector<DataMatrix_Struct>&List, QString FC)
{
	TiXmlElement* m_Element = NULL;
	DataMatrix_Struct m_data;
	const char* chr;
	TiXmlElement* childDO = NULL;
	QString  strda;

	m_data.B_LNodeType = LNodeType;
	m_Element = DataTypeNode->GetChildByName_Value(DataTypeNode, "LNodeType", "id", LNodeType.toStdString().data());
	childDO = m_Element->FirstChildElement("DO");
	for (; childDO != NULL; childDO = childDO->NextSiblingElement("DO"))
	{
		QString str;
		chr = childDO->Attribute("name");
		str += chr;
		if ((str == "Beh") || (str == "Health") || (str == "NamPlt"))
		{
			continue;
		}
		CreatDataMatrix_DO_By_FC(childDO, m_data, strda, List, FC);
	}
	return DO_OK;
}
int ScdTree::CreatDataMatrix_SDO_By_FC(TiXmlElement* Element, DataMatrix_Struct data, QString doName, QVector<DataMatrix_Struct>&List, QString FC)
{
	TiXmlElement* m_DOType = NULL;
	TiXmlElement* childDA = NULL;
	const char* chr;
	DataMatrix_Struct m_data;
	QString strdo;

	chr = Element->Attribute("name");

	m_data = data;
	m_DOType = DataTypeNode->GetChildByName_Value(DataTypeNode, "DOType", "id", Element->Attribute("type"));
	childDA = m_DOType->FirstChildElement();
	for (; childDA != NULL; childDA = childDA->NextSiblingElement())
	{
		if (0 == strcmp(childDA->Value(), "SDO"))
		{
			strdo.clear();
			strdo += doName;
			strdo += ".";
			strdo += chr;
			CreatDataMatrix_SDO_By_FC(childDA, m_data, strdo, List, FC);
		}
		else if (0 == strcmp(childDA->Value(), "DA"))
		{
			strdo.clear();
			strdo += doName;
			strdo += ".";
			strdo += chr;
			m_data.B_doName = strdo;
			chr = childDA->Attribute("fc");
			if (FC != QString::fromLocal8Bit(chr))
			{
				continue;
			}
			CreatDataMatrix_BDA(childDA, m_data, m_data.B_daName, List);
		}
	}

	return DO_OK;
}
int ScdTree::CreatDataMatrix_DO_By_FC(TiXmlElement* Elemnet, DataMatrix_Struct data, QString doName, QVector<DataMatrix_Struct>&List, QString FC)
{
	const char* chr;
	QString strdo;
	TiXmlElement* m_DOType = NULL;
	TiXmlElement*m_DA = NULL;
	DataMatrix_Struct m_data;
	m_data = data;
	chr = Elemnet->Attribute("name");
	strdo += chr;
	m_DOType = DataTypeNode->GetChildByName_Value(DataTypeNode, "DOType", "id", Elemnet->Attribute("type"));
	m_DA = m_DOType->FirstChildElement();
	for (; m_DA != NULL; m_DA = m_DA->NextSiblingElement())
	{

		if (0 == strcmp(m_DA->Value(), "SDO"))
		{

			CreatDataMatrix_SDO_By_FC(m_DA, m_data, strdo, List, FC);
		}
		else if (0 == strcmp(m_DA->Value(), "DA"))
		{
			m_data.B_doName = strdo;
			chr = m_DA->Attribute("fc");
			if (FC != QString::fromLocal8Bit(chr))
			{
				continue;
			}
			CreatDataMatrix_BDA(m_DA, m_data, m_data.B_daName, List);
		}
	}

	return DO_OK;
}
bool ScdTree::Compare_CID_Contain(QString filename)

{
	TiXmlDocument *ex_doc = new TiXmlDocument;
	TiXmlElement* m_IED;
	QString IEDName;
	if (!ex_doc->LoadFile(filename.toLocal8Bit().data()))
	{
		QMessageBox::about(0, QObject::tr("Warnning"), QObject::tr("The CID file was wrong"));
		return false;
	}
	m_IED = ex_doc->FirstChildElement("SCL")->FirstChildElement("IED");
	IEDName.clear();
	IEDName += m_IED->Attribute("name");
	TiXmlPrinter Pstr;
	ex_doc->Accept(&Pstr);
	const char *TempPstr = Pstr.CStr();//把指针取出
	int len = strlen(TempPstr);//计算长度
	if (len == 0)return DO_FAIL;
	char * RPstr = new char[len + 1];
	memcpy(RPstr, TempPstr, len + 1);
	QString str;
	str.clear();
	str += RPstr;
	unsigned long crc;
	m_SumCheck.CRCInit(crc);
	m_SumCheck.CRCUpdate(str.toLocal8Bit().data(), str.length(), crc);
	m_SumCheck.CRCFinal(crc);

	QMap<QString, TiXmlElement* > APMap;
	QMap<QString, TiXmlElement* > IEDMap;
	QMap<QString, TiXmlElement* > LnTypeMap;
	QMap<QString, TiXmlElement* > DOTypeMap;
	QMap<QString, TiXmlElement* > DATypeMap;
	QMap<QString, TiXmlElement* > EnumTypeMap;
	QStringList LnTypeList;
	QStringList DOTypeList;
	QStringList DATypeList;
	QStringList EnumTypeList;
	TiXmlElement*node = NULL;
	Init_IED_MAP(root, IEDMap);

	node = IEDMap.value(IEDName);
	if (node == NULL)
	{
		QMessageBox::about(0, QObject::tr("Warnning"), QObject::tr("The SCD do not contian IED which named %1").arg(IEDName));

		return false;
	}
	TiXmlDocument *DOCPoint = new TiXmlDocument;
	TiXmlDeclaration *Declaration = new TiXmlDeclaration("1.0", "UTF-8", "");
	DOCPoint->LinkEndChild(Declaration);
	TiXmlElement *SCL_element = new TiXmlElement("SCL");
	SCL_element->SetAttribute("xmlns", "http://www.iec.ch/61850/2003/SCL");
	SCL_element->SetAttribute("xmlns:xsi", "http://www.w3.org/2001/XMLSchema-instance");
	SCL_element->SetAttribute("xmlns:kf", "http://www.keyvia.cn");
	SCL_element->SetAttribute("xsi:schemaLocation", "http://www.iec.ch/61850/2003/SCL SCL.xsd");

	TiXmlElement *Header_element = new TiXmlElement("Header");
	Header_element->SetAttribute("id", IEDName.toStdString().data());
	Header_element->SetAttribute("version", "1.00");
	Header_element->SetAttribute("toolID", "Keyvia Configuration");
	Header_element->SetAttribute("nameStructure", "IEDName");
	SCL_element->LinkEndChild(Header_element);

	TiXmlElement *Comm_element = new TiXmlElement("Communication");
	TiXmlElement *SubNet = root->FirstChildElement("Communication")->FirstChildElement("SubNetwork");
	for (; SubNet != NULL; SubNet = SubNet->NextSiblingElement("SubNetwork"))
	{
		APMap.clear();
		Init_ConnectAP_MAP(SubNet, APMap);

		if (APMap.contains(IEDName))
		{
			TiXmlElement *NetNode = new TiXmlElement(SubNet->Value());
			NetNode->SetAttribute("name", SubNet->Attribute("name"));
			NetNode->SetAttribute("type", SubNet->Attribute("type"));
			NetNode->SetAttribute("desc", SubNet->Attribute("desc"));
			node = APMap.value(IEDName);
			if (node == NULL)
			{
				continue;
			}
			NetNode->LinkEndChild(node->Clone()->ToElement());
			Comm_element->LinkEndChild(NetNode);
		}
	}

	SCL_element->LinkEndChild(Comm_element);

	SCL_element->LinkEndChild(node->Clone()->ToElement());
	TiXmlElement *DataType_element = new TiXmlElement("DataTypeTemplates");
	GetLnTypeList(IEDMap.value(IEDName), LnTypeList);
	Init_LNtype_MAP(root->FirstChildElement("DataTypeTemplates"), LnTypeMap);
	Init_DOType_MAP(root->FirstChildElement("DataTypeTemplates"), DOTypeMap);
	Init_DAtype_MAP(root->FirstChildElement("DataTypeTemplates"), DATypeMap);
	Init_EnumType_MAP(root->FirstChildElement("DataTypeTemplates"), EnumTypeMap);
	for (int i = 0; i < LnTypeList.size(); i++)
	{
		node = LnTypeMap.value(LnTypeList[i]);
		GetDoTypeList(node, DOTypeList);
		if (node == NULL)
		{
			continue;
		}
		DataType_element->LinkEndChild(node->Clone()->ToElement());
		//QMessageBox::about(0, QObject::tr("Warnning"), QObject::tr("1"));

	}
	while (DOTypeList.size() > 0)
	{
		node = DOTypeMap.value(DOTypeList.at(0));
		GetDaTypeList(node, DOTypeList, DATypeList, EnumTypeList);
		if (node == NULL)
		{
			DOTypeList.removeAt(0);
			continue;
		}
		DataType_element->LinkEndChild(node->Clone()->ToElement());
		DOTypeList.removeAt(0);
		//QMessageBox::about(0, QObject::tr("Warnning"), QObject::tr("2"));

	}
	while (DATypeList.size() > 0)
	{
		node = DATypeMap.value(DATypeList.at(0));
		GetEnumTypeList(node, DATypeList, EnumTypeList);
		if (node == NULL)
		{
			DOTypeList.removeAt(0);
			continue;
		}
		DataType_element->LinkEndChild(node->Clone()->ToElement());
		DATypeList.removeAt(0);
		//QMessageBox::about(0, QObject::tr("Warnning"), QObject::tr("3"));

	}
	while (EnumTypeList.size() > 0)
	{
		node = EnumTypeMap.value(EnumTypeList.at(0));
		//GetEnumTypeList(node, EnumTypeList);
		if (node == NULL)
		{
			DOTypeList.removeAt(0);
			continue;
		}
		DataType_element->LinkEndChild(node->Clone()->ToElement());
		EnumTypeList.removeAt(0);
		//QMessageBox::about(0, QObject::tr("Warnning"), QObject::tr("4"));

	}
	SCL_element->LinkEndChild(DataType_element);
	DOCPoint->LinkEndChild(SCL_element);
	//QMessageBox::about(0, QObject::tr("Warnning"), QObject::tr("5"));

	TiXmlPrinter Pstr_local;
	DOCPoint->Accept(&Pstr_local);
	//QMessageBox::about(0, QObject::tr("Warnning"), QObject::tr("5"));
	const char *TempPstr_local = Pstr_local.CStr();//把指针取出
	int len_local = strlen(TempPstr_local);//计算长度
	//QMessageBox::about(0, QObject::tr("Warnning"), QObject::tr("6"));
	if (len == 0)return DO_FAIL;
	char * RPstr_local = new char[len_local + 1];
	//QMessageBox::about(0, QObject::tr("Warnning"), QObject::tr("7"));
	memcpy(RPstr_local, TempPstr_local, len_local + 1);

	str.clear();
	str += RPstr_local;
	//str = str.simplified();
	unsigned long crc_local;
	//QMessageBox::about(0, QObject::tr("Warnning"), QObject::tr("8"));

	m_SumCheck.CRCInit(crc_local);
	//QMessageBox::about(0, QObject::tr("Warnning"), QObject::tr("9"));

	m_SumCheck.CRCUpdate(str.toLocal8Bit().data(), str.length(), crc_local);
	//QMessageBox::about(0, QObject::tr("Warnning"), QObject::tr("10"));

	m_SumCheck.CRCFinal(crc_local);
	//QMessageBox::about(0, QObject::tr("Warnning"), QObject::tr("11"));

	if (crc_local == crc)
	{
		QMessageBox::about(0, QObject::tr("Warnning"), QObject::tr("The CID file was exported from this SCD"));
		delete DOCPoint;
		delete ex_doc;
		return true;
	}
	else
	{
		QMessageBox::about(0, QObject::tr("Warnning"), QObject::tr("The CID file was  not exported from this SCD"));
		delete DOCPoint;
		delete ex_doc;
		return false;
	}
}
bool ScdTree::Compare_Node(TiXmlElement*Local, TiXmlElement*Ext)
{
	QMap<QString, TiXmlElement*>Child_Map_Local;
	QMap<QString, TiXmlElement*>Child_Map_Ext;
	TiXmlElement* m_Child = NULL;
	TiXmlText *m_Text = NULL;
	QMap<QString, Attribue_Valuse>Value_Map;
	QMap<QString, QString>Enum_Map;
	const char* chr_Att;
	const char* chr_value;
	QString str;
	TiXmlAttribute *m_Attribue;
	if (0 == strcmp("EnumType", Ext->Value()))
	{
		Init_Child_Map(Local, Child_Map_Local, "ord");
		for (m_Child = Local->FirstChildElement(); m_Child != NULL; m_Child = m_Child->NextSiblingElement())
		{
			chr_value = m_Child->Attribute("ord");
			str.clear();
			str += chr_value;
			if (m_Child->FirstChild() != NULL)
			{
				m_Text = m_Child->FirstChild()->ToText();
				QString str2;
				str2 += m_Text->Value();
				Enum_Map.insert(str, str2);
			}
			else
			{
				Enum_Map.insert(str, "Empty");
			}


		}
		Init_Child_Map(Ext, Child_Map_Ext, "ord");
		if (Child_Map_Local.uniqueKeys() != Child_Map_Ext.uniqueKeys())
			return false;
		for (int i = 0; i < Child_Map_Ext.uniqueKeys().size(); i++)
		{
			m_Child = Child_Map_Ext.value(Child_Map_Ext.uniqueKeys().at(i));
			if (m_Child->FirstChild() != NULL)
			{
				m_Text = m_Child->FirstChild()->ToText();
				str.clear();
				str += m_Text->Value();
			}
			else
			{
				str.clear();
				str = "Empty";
			}

			if (0 == strcmp(str.toLocal8Bit().data(), Enum_Map.value(Child_Map_Ext.uniqueKeys().at(i)).toLocal8Bit().data()))
			{
				continue;
			}
			else
			{
				return false;
			}
		}
	}
	else
	{
		Init_Child_Map(Local, Child_Map_Local, "name");
		for (int i = 0; i < Child_Map_Local.uniqueKeys().size(); i++)
		{
			m_Child = Child_Map_Local.value(Child_Map_Local.uniqueKeys().at(i));
			for (m_Attribue = m_Child->FirstAttribute(); m_Attribue != NULL; m_Attribue = m_Attribue->Next())
			{
				Attribue_Valuse m_data;
				chr_Att = m_Attribue->Name();

				chr_value = m_Attribue->Value();
				m_data.Attribue += chr_Att;
				m_data.Valuse += chr_value;
				Value_Map.insertMulti(Child_Map_Local.uniqueKeys().at(i), m_data);
			}
		}
		Init_Child_Map(Ext, Child_Map_Ext, "name");
		if (Child_Map_Local.uniqueKeys() != Child_Map_Ext.uniqueKeys())
			return false;
		for (int i = 0; i < Child_Map_Ext.uniqueKeys().size(); i++)
		{
			if (Child_Map_Local.uniqueKeys().contains(Child_Map_Ext.uniqueKeys().at(i)))
			{
				QList<Attribue_Valuse> m_List;
				QList<Attribue_Valuse>Ext_List;
				m_List = Value_Map.values(Child_Map_Ext.uniqueKeys().at(i));
				for (m_Attribue = Child_Map_Ext.value(Child_Map_Ext.uniqueKeys().at(i))->FirstAttribute(); m_Attribue != NULL; m_Attribue = m_Attribue->Next())
				{
					Attribue_Valuse m_data;
					m_data.Valuse += m_Attribue->Name();
					m_data.Valuse += m_Attribue->Value();
					Ext_List.append(m_data);
				}
				if (Ext_List.size() != m_List.size())
				{
					return false;
				}
				for (int k = 0; k < m_List.size(); k++)
				{
					Attribue_Valuse m_data;
					m_data = m_List.at(k);
					str.clear();
					str += Child_Map_Ext.value(Child_Map_Ext.uniqueKeys().at(i))->Attribute(m_data.Attribue.toLocal8Bit());
					if (0 == strcmp(m_data.Valuse.toLocal8Bit().data(), str.toLocal8Bit().data()))
					{
						continue;
					}
					else
					{
						return false;
					}
				}
			}
			else
			{
				return false;
			}
		}
	}

	return true;
}
void ScdTree::GetConnectAPData(QString IED, QString AP, ConnectedAP& m_AP, QVector<Address_GOOSE>&GooseList, QVector<Address_SMV>&SmvList)
{
	TiXmlElement *m_Subnet = NULL;
	TiXmlElement *m_ConnectAP = NULL;
	TiXmlElement *child = NULL;
	TiXmlElement *m_Address = NULL;
	TiXmlElement *m_GSE = NULL;
	TiXmlElement *m_SMV = NULL;
	TiXmlText *m_P = NULL;
	QMap<QString, TiXmlElement*>AP_Map;
	m_Subnet = root->FirstChildElement("Communication")->FirstChildElement("SubNetwork");
	for (m_Subnet; m_Subnet != NULL; m_Subnet = m_Subnet->NextSiblingElement())
	{
		QString str;
		str += m_Subnet->Attribute("type");
		if (str.contains("MMS", Qt::CaseInsensitive))
		{
			break;
		}
	}
	if (m_Subnet == NULL)
		return;
	Init_ConnectAP_MAP(m_Subnet, AP_Map);
	m_AP.iedName = IED;
	for (int i = 0; i < AP_Map.uniqueKeys().size(); i++)
	{
		for (int m = 0; m < AP_Map.values(AP_Map.uniqueKeys().at(i)).size(); m++)
		{
			m_ConnectAP = AP_Map.values(IED).at(m);
			if (0 == strcmp(m_ConnectAP->Attribute("apName"), AP.toStdString().data()))
			{
				m_AP.apName = AP;
				break;
			}
			else
			{
				m_ConnectAP = NULL;
			}
		}
		if (m_ConnectAP != NULL)
			break;
	}
	m_Address = m_ConnectAP->FirstChildElement("Address");
	if (m_Address != NULL)
	{
		for (child = m_Address->FirstChildElement(); child != NULL; child = child->NextSiblingElement())
		{
			m_P = child->FirstChild()->ToText();
			if (0 == strcmp("OSI-AP-Title", child->Attribute("type")))
			{

				m_AP.iP_addr.s_AP_Title = m_P->Value();
				continue;
			}
			if (0 == strcmp("OSI-AE-Qualifier", child->Attribute("type")))
			{

				m_AP.iP_addr.s_AE_Qualifier = m_P->Value();
				continue;
			}
			if (0 == strcmp("OSI-PSEL", child->Attribute("type")))
			{

				m_AP.iP_addr.s_PSEL = m_P->Value();
				continue;
			}
			if (0 == strcmp("OSI-SSEL", child->Attribute("type")))
			{

				m_AP.iP_addr.s_SSEL = m_P->Value();
				continue;
			}
			if (0 == strcmp("OSI-TSEL", child->Attribute("type")))
			{

				m_AP.iP_addr.s_TSEL = m_P->Value();
				continue;
			}
			if (0 == strcmp("IP", child->Attribute("type")))
			{

				m_AP.iP_addr.s_IP = m_P->Value();
				continue;
			}
		}
	}
	m_GSE = m_ConnectAP->FirstChildElement("GSE");
	for (m_GSE; m_GSE != NULL; m_GSE = m_GSE->NextSiblingElement("GSE"))
	{
		Address_GOOSE m_data;
		m_data.s_cbName = m_GSE->Attribute("cbName");
		m_data.s_ldInst = m_GSE->Attribute("ldInst");
		for (child = m_GSE->FirstChildElement("Address")->FirstChildElement(); child != NULL; child = child->NextSiblingElement())
		{
			if (child->FirstChild() == NULL)
			{
				continue;
			}
			m_P = child->FirstChild()->ToText();
			if (0 == strcmp("MAC-Address", child->Attribute("type")))
			{

				m_data.s_MAC_addr = m_P->Value();
				continue;
			}
			if (0 == strcmp("VLAN-ID", child->Attribute("type")))
			{

				m_data.s_VLAN_ID = m_P->Value();
				continue;
			}
			if (0 == strcmp("APPID", child->Attribute("type")))
			{

				m_data.s_APPID = m_P->Value();
				continue;
			}
			if (0 == strcmp("VLAN-PRIORITY", child->Attribute("type")))
			{

				m_data.s_VLAN_PRIORITY = m_P->Value();
				continue;
			}
		}
		child = m_GSE->FirstChildElement("MinTime");
		if (child != NULL)
		{
			m_P = child->FirstChild()->ToText();
			m_data.s_MinTime = m_P->Value();
		}

		child = m_GSE->FirstChildElement("MaxTime");
		if (child != NULL)
		{
			m_P = child->FirstChild()->ToText();
			m_data.s_MaxTime = m_P->Value();
		}
		GooseList.append(m_data);
	}
	m_SMV = m_ConnectAP->FirstChildElement("SMV");
	for (; m_SMV != NULL; m_SMV = m_SMV->FirstChildElement("SMV"))
	{
		Address_SMV m_data;
		m_data.s_cbName = m_SMV->Attribute("cbName");
		m_data.s_ldInst = m_SMV->Attribute("ldInst");
		for (child = m_SMV->FirstChildElement("Address")->FirstChildElement(); child != NULL; child = child->NextSiblingElement())
		{
			if (child->FirstChild() == NULL)
			{
				continue;
			}
			m_P = child->FirstChild()->ToText();
			if (0 == strcmp("MAC-Address", child->Attribute("type")))
			{

				m_data.s_MAC_addr = m_P->Value();
				continue;
			}
			if (0 == strcmp("VLAN-ID", child->Attribute("type")))
			{

				m_data.s_VLAN_ID = m_P->Value();
				continue;
			}
			if (0 == strcmp("APPID", child->Attribute("type")))
			{

				m_data.s_APPID = m_P->Value();
				continue;
			}
			if (0 == strcmp("VLAN-PRIORITY", child->Attribute("type")))
			{

				m_data.s_VLAN_PRIORITY = m_P->Value();
				continue;
			}
		}
	}
}
void ScdTree::UpdataConnectAPMMS(ConnectedAP& m_AP, QVector<Address_GOOSE>&m_GOOSE, QVector<Address_SMV>&m_SMV)
{
	TiXmlElement *m_Subnet = NULL;
	TiXmlElement *m_ConnectAP = NULL;
	TiXmlElement *child = NULL;
	TiXmlElement *m_Address = NULL;
	TiXmlElement *n_GSE = NULL;
	TiXmlElement *n_SMV = NULL;
	TiXmlText *m_P = NULL;
	QMap<QString, TiXmlElement*>AP_Map;
	m_Subnet = root->FirstChildElement("Communication")->FirstChildElement("SubNetwork");
	for (m_Subnet; m_Subnet != NULL; m_Subnet = m_Subnet->NextSiblingElement())
	{
		QString str;
		str += m_Subnet->Attribute("type");
		if (str.contains("MMS", Qt::CaseInsensitive))
		{
			break;
		}
	}
	if (m_Subnet == NULL)
		return;
	Init_ConnectAP_MAP(m_Subnet, AP_Map);
	for (int i = 0; i < AP_Map.uniqueKeys().size(); i++)
	{
		for (int m = 0; m < AP_Map.values(AP_Map.uniqueKeys().at(i)).size(); m++)
		{
			m_ConnectAP = AP_Map.values(m_AP.iedName).at(m);
			if (0 == strcmp(m_ConnectAP->Attribute("apName"), m_AP.apName.toStdString().data()))
			{
				break;
			}
			else
			{
				m_ConnectAP = NULL;
			}
		}
		if (m_ConnectAP != NULL)
			break;
	}
	m_Address = m_ConnectAP->FirstChildElement("Address");
	m_ConnectAP->RemoveChild(m_Address);
	n_GSE = m_ConnectAP->FirstChildElement("GSE");
	while (n_GSE != NULL)
	{
		m_ConnectAP->RemoveChild(n_GSE);
		n_GSE = m_ConnectAP->FirstChildElement("GSE");
	}
	n_SMV = m_ConnectAP->FirstChildElement("SMV");
	while (n_SMV != NULL)
	{
		m_ConnectAP->RemoveChild(n_SMV);
		n_SMV = m_ConnectAP->FirstChildElement("SMV");
	}
	m_Address = new TiXmlElement("Address");
	child = new TiXmlElement("P");
	child->SetAttribute("type", "IP");
	m_P = new TiXmlText(m_AP.iP_addr.s_IP.toStdString().data());
	child->LinkEndChild(m_P);
	m_Address->LinkEndChild(child);
	child = new TiXmlElement("P");
	child->SetAttribute("type", "OSI-AP-Title");
	m_P = new TiXmlText(m_AP.iP_addr.s_AP_Title.toStdString().data());
	child->LinkEndChild(m_P);
	m_Address->LinkEndChild(child);
	child = new TiXmlElement("P");
	child->SetAttribute("type", "OSI-AE-Qualifier");
	m_P = new TiXmlText(m_AP.iP_addr.s_AE_Qualifier.toStdString().data());
	child->LinkEndChild(m_P);
	m_Address->LinkEndChild(child);
	child = new TiXmlElement("P");
	child->SetAttribute("type", "OSI-PSEL");
	m_P = new TiXmlText(m_AP.iP_addr.s_PSEL.toStdString().data());
	child->LinkEndChild(m_P);
	m_Address->LinkEndChild(child);
	child = new TiXmlElement("P");
	child->SetAttribute("type", "OSI-SSEL");
	m_P = new TiXmlText(m_AP.iP_addr.s_SSEL.toStdString().data());
	child->LinkEndChild(m_P);
	m_Address->LinkEndChild(child);
	child = new TiXmlElement("P");
	child->SetAttribute("type", "OSI-TSEL");
	m_P = new TiXmlText(m_AP.iP_addr.s_TSEL.toStdString().data());
	child->LinkEndChild(m_P);
	m_Address->LinkEndChild(child);
	m_ConnectAP->LinkEndChild(m_Address);
	for (int i = 0; i < m_GOOSE.size(); i++)
	{
		n_GSE = new TiXmlElement("GSE");
		n_GSE->SetAttribute("ldInst", m_GOOSE.at(i).s_ldInst.toStdString().data());
		n_GSE->SetAttribute("cbName", m_GOOSE.at(i).s_cbName.toStdString().data());
		m_Address = new TiXmlElement("Address");
		n_GSE->LinkEndChild(m_Address);
		child = new TiXmlElement("P");
		child->SetAttribute("type", "MAC-Address");
		m_P = new TiXmlText(m_GOOSE.at(i).s_MAC_addr.toStdString().data());
		child->LinkEndChild(m_P);
		m_Address->LinkEndChild(child);
		child = new TiXmlElement("P");
		child->SetAttribute("type", "VLAN-ID");
		m_P = new TiXmlText(m_GOOSE.at(i).s_VLAN_ID.toStdString().data());
		child->LinkEndChild(m_P);
		m_Address->LinkEndChild(child);
		child = new TiXmlElement("P");
		child->SetAttribute("type", "APPID");
		m_P = new TiXmlText(m_GOOSE.at(i).s_APPID.toStdString().data());
		child->LinkEndChild(m_P);
		m_Address->LinkEndChild(child);
		child = new TiXmlElement("P");
		child->SetAttribute("type", "VLAN-PRIORITY");
		m_P = new TiXmlText(m_GOOSE.at(i).s_VLAN_PRIORITY.toStdString().data());
		child->LinkEndChild(m_P);
		m_Address->LinkEndChild(child);
		child = new TiXmlElement("MinTime");
		child->SetAttribute("unit", "s");
		child->SetAttribute("multiplier", "m");
		m_P = new TiXmlText(m_GOOSE.at(i).s_MinTime.toStdString().data());
		child->LinkEndChild(m_P);
		n_GSE->LinkEndChild(child);
		child = new TiXmlElement("MaxTime");
		child->SetAttribute("unit", "s");
		child->SetAttribute("multiplier", "m");
		m_P = new TiXmlText(m_GOOSE.at(i).s_MaxTime.toStdString().data());
		child->LinkEndChild(m_P);
		n_GSE->LinkEndChild(child);
		m_ConnectAP->LinkEndChild(n_GSE);
	}
	for (int i = 0; i < m_SMV.size(); i++)
	{
		n_SMV = new TiXmlElement("SMV");
		n_SMV->SetAttribute("ldInst", m_SMV.at(i).s_ldInst.toStdString().data());
		n_SMV->SetAttribute("cbName", m_SMV.at(i).s_cbName.toStdString().data());
		m_Address = new TiXmlElement("Address");
		n_SMV->LinkEndChild(m_Address);
		child = new TiXmlElement("P");
		child->SetAttribute("type", "MAC-Address");
		m_P = new TiXmlText(m_SMV.at(i).s_MAC_addr.toStdString().data());
		child->LinkEndChild(m_P);
		m_Address->LinkEndChild(child);
		child = new TiXmlElement("P");
		child->SetAttribute("type", "VLAN-ID");
		m_P = new TiXmlText(m_SMV.at(i).s_APPID.toStdString().data());
		child->LinkEndChild(m_P);
		m_Address->LinkEndChild(child);
		child = new TiXmlElement("P");
		child->SetAttribute("type", "APPID");
		m_P = new TiXmlText(m_SMV.at(i).s_APPID.toStdString().data());
		child->LinkEndChild(m_P);
		m_Address->LinkEndChild(child);
		child = new TiXmlElement("P");
		child->SetAttribute("type", "VLAN-PRIORITY");
		m_P = new TiXmlText(m_SMV.at(i).s_VLAN_PRIORITY.toStdString().data());
		child->LinkEndChild(m_P);
		m_Address->LinkEndChild(child);
		m_ConnectAP->LinkEndChild(n_GSE);
	}
}
void ScdTree::Init_P_Map(TiXmlElement* Node, QMap<QString, TiXmlElement* >&Map, int state)
{
	if (state == 0)
	{
		Map.clear();
	}
	TiXmlElement* Child = NULL;
	for (Child = Node->FirstChildElement("P"); Child != NULL; Child = Child->NextSiblingElement("P"))
	{
		QString str;
		str += Child->Attribute("type");
		Map.insert(str, Child);
	}

}
void ScdTree::GetLDList(QString IED, QVector<AP_LD>&Vector)
{
	QMap<QString, TiXmlElement*> Map;
	TiXmlElement* m_IED = NULL;
	TiXmlElement* m_AP = NULL;
	TiXmlElement* m_LD = NULL;
	TiXmlElement* m_Server = NULL;
	Init_IED_MAP(root, Map);
	m_IED = Map.value(IED);
	for (m_AP = m_IED->FirstChildElement("AccessPoint"); m_AP != NULL; m_AP = m_AP->NextSiblingElement("AccessPoint"))
	{
		m_Server = m_AP->FirstChildElement("Server");
		for (m_LD = m_Server->FirstChildElement("LDevice"); m_LD != NULL; m_LD = m_LD->NextSiblingElement("LDevice"))
		{
			AP_LD m_data;
			QString str;
			str += m_AP->Attribute("name");
			m_data.AP = str;
			str.clear();
			str += m_LD->Attribute("inst");
			m_data.LD = str;
			str.clear();
			str += m_LD->Attribute("desc");
			m_data.Dese = str;
			Vector.append(m_data);
		}
	}
}
