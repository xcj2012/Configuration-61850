#include "XML.h"


XML::XML()
{
	doc = new TiXmlDocument();
	root = NULL;
}


XML::~XML()
{
}
int XML::LoadXML(QString filename, int state)
{
	if (doc != NULL)
	{
		delete doc;
	}
	doc = new TiXmlDocument();
	if (doc->LoadFile(filename.toLocal8Bit().data()))
	{
		if (state == 1)
		{
			root = doc->FirstChildElement("MAP");
			if (root == NULL)
			{
				QMessageBox::information(NULL, QString("Notice"), QString("Check the File is  Map or not "));
				return DO_FAIL;
			}
			Init_Map();
			return DO_OK;
		}
		if (state == 2)
		{
			root = doc->FirstChildElement("STACK_CFG");
			if (root == NULL)
			{
				QMessageBox::information(NULL, QString("Notice"), QString("Check the File is  IEC or not"));
				return DO_FAIL;
			}
			return DO_OK;
		}
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
		QMessageBox::information(NULL, QString("title"), QString("parse file failed at line row and column") + QString::number(row, 10) + QString(",") + QString::number(column, 10));
		return DO_FAIL;
	}
	return DO_OK;
}
int XML::CreatXML(int state)
{
	if (doc != NULL)
	{
		delete doc;
	}
	doc = new TiXmlDocument();
	if (state == 1)
	{
		if (InitXMLstruct(doc, state))
		{
			root = doc->FirstChildElement("MAP");
			Init_Map();
			return DO_OK;
		}
	}
	if (state == 2)
	{
		if (InitXMLstruct(doc, state))
		{
			root = doc->FirstChildElement("STACK_CFG");
			return DO_OK;
		}
	}




	return false;
}
int XML::InitXMLstruct(TiXmlDocument* DOCPoint, int state)
{
	if (state == 1)
	{
		TiXmlDeclaration *Declaration = new TiXmlDeclaration("1.0", "UTF-8", "");
		DOCPoint->LinkEndChild(Declaration);
		TiXmlElement *m_MAP = new TiXmlElement("MAP");
		m_MAP->SetAttribute("xmlns", "http://www.iec.ch/61850/2006/SCL");
		m_MAP->SetAttribute("xmlns:xsi", "http://www.w3.org/2001/XMLSchema-instance");
		m_MAP->SetAttribute("xsi:schemaLocation", "http://www.iec.ch/61850/2003/SCL");
		TiXmlElement *m_Header = new TiXmlElement("Header");
		TiXmlElement *m_Item;
		m_Item = new TiXmlElement("Maintaintool");
		m_Item->SetAttribute("Name", "Maintaintool");
		m_Item->SetAttribute("Version", "1.0");
		m_Header->LinkEndChild(m_Item);
		m_Item = new TiXmlElement("Vendor");
		TiXmlText *m_text = new TiXmlText("New Station");
		m_Item->LinkEndChild(m_text);
		m_Header->LinkEndChild(m_Item);
		m_Item = new TiXmlElement("Line");
		m_text = new TiXmlText("New Line");
		m_Item->LinkEndChild(m_text);
		m_Header->LinkEndChild(m_Item);
		m_Item = new TiXmlElement("ProjectName");
		m_text = new TiXmlText("New Project");
		m_Item->LinkEndChild(m_text);
		m_Header->LinkEndChild(m_Item);
		m_Item = new TiXmlElement("Version");
		m_text = new TiXmlText("1.0");
		m_Item->LinkEndChild(m_text);
		m_Header->LinkEndChild(m_Item);
		m_Item = new TiXmlElement("CreateTime");
		QDateTime current_date_time = QDateTime::currentDateTime();
		QString current_date = current_date_time.date().toString("yyyy-MM-dd");
		m_text = new TiXmlText(current_date.toStdString().data());
		m_Item->LinkEndChild(m_text);
		m_Header->LinkEndChild(m_Item);
		m_MAP->LinkEndChild(m_Header);
		DOCPoint->LinkEndChild(m_MAP);
		return 1;
	}
	if (state == 2)
	{
		TiXmlDeclaration *Declaration = new TiXmlDeclaration("1.0", "UTF-8", "");
		DOCPoint->LinkEndChild(Declaration);
		TiXmlElement *m_STACK_CFG = new TiXmlElement("STACK_CFG");
		m_STACK_CFG->SetAttribute("xmlns:xsi", "http://www.w3.org/2001/XMLSchema-instance");
		m_STACK_CFG->SetAttribute("xsi:noNamespaceSchemaLocation", "osicfg_v1.0.xsd");
		TiXmlElement *m_Header = new TiXmlElement("Header");
		TiXmlElement *m_Item;
		m_Item = new TiXmlElement("Vendor");
		TiXmlText *m_text = new TiXmlText("Keyvia");
		m_Item->LinkEndChild(m_text);
		m_Header->LinkEndChild(m_Item);
		m_Item = new TiXmlElement("Maintaintool");
		m_Item->SetAttribute("Name", "Keyvia");
		m_Item->SetAttribute("Version", "1.0");
		m_Header->LinkEndChild(m_Item);

		m_Item = new TiXmlElement("ProjectName");
		m_text = new TiXmlText("Keyvia");
		m_Item->LinkEndChild(m_text);
		m_Header->LinkEndChild(m_Item);
		m_Item = new TiXmlElement("Version");
		m_text = new TiXmlText("1.0");
		m_Item->LinkEndChild(m_text);
		m_Header->LinkEndChild(m_Item);
		m_Item = new TiXmlElement("CreateTime");
		QDateTime current_date_time = QDateTime::currentDateTime();
		QString current_date = current_date_time.date().toString("yyyy-MM-dd");
		m_text = new TiXmlText(current_date.toStdString().data());
		m_Item->LinkEndChild(m_text);
		m_Header->LinkEndChild(m_Item);
		m_STACK_CFG->LinkEndChild(m_Header);
		m_STACK_CFG->LinkEndChild(CreatClient());
		m_STACK_CFG->LinkEndChild(CreatMMS());
		m_STACK_CFG->LinkEndChild(CreatNetwork());
		m_STACK_CFG->LinkEndChild(CreatTransport());
		m_STACK_CFG->LinkEndChild(CreatNetworkAddressing());
		DOCPoint->LinkEndChild(m_STACK_CFG);
		return 1;
	}
	return 1;

}
int XML::SaveXML(QString filename)
{
	if (doc->SaveFile((filename.toLocal8Bit().data())))
	{
		return true;
	}

	return 0;
}
int XML::UpdataStationPara(StationPara_struct &data)
{
	std::string str;

	const char* ch;
	TiXmlElement *m_Header;
	m_Header = root->FirstChildElement("Header");
	TiXmlElement *Child;
	TiXmlText *m_text;
	Child = m_Header->FirstChildElement("Vendor");
	m_text = Child->FirstChild()->ToText();
	str = data.Vender.toStdString();
	ch = str.c_str();
	m_text->SetValue(ch);
	Child = m_Header->FirstChildElement("Line");
	if (Child != NULL)
	{
		m_text = Child->FirstChild()->ToText();
		str = data.Line.toStdString();
		ch = str.c_str();
		m_text->SetValue(ch);
	}

	Child = m_Header->FirstChildElement("ProjectName");
	m_text = Child->FirstChild()->ToText();
	str = data.ProjectName.toStdString();
	ch = str.c_str();
	m_text->SetValue(ch);
	Child = m_Header->FirstChildElement("Version");
	m_text = Child->FirstChild()->ToText();
	str = data.Version.toStdString();
	ch = str.c_str();
	m_text->SetValue(ch);

	return DO_OK;
}
int XML::GetStationPara(StationPara_struct &data, int state)
{
	TiXmlElement *m_Header;
	m_Header = root->FirstChildElement("Header");
	TiXmlElement *Child;
	TiXmlText *m_text;
	Child = m_Header->FirstChildElement("Vendor");
	m_text = Child->FirstChild()->ToText();
	data.Vender = m_text->Value();
	m_text->SetValue(data.Vender.toLocal8Bit().data());
	if (state == 1)
	{
		Child = m_Header->FirstChildElement("Line");
		m_text = Child->FirstChild()->ToText();
		data.Line = m_text->Value();
	}

	Child = m_Header->FirstChildElement("ProjectName");
	m_text = Child->FirstChild()->ToText();
	data.ProjectName = m_text->Value();
	Child = m_Header->FirstChildElement("Version");
	m_text = Child->FirstChild()->ToText();
	data.Version = m_text->Value();

	return DO_OK;
}
int XML::CreatOneIED(QString IEDName, QString Ventor, QString Type, QString Addr)
{
	std::string str = IEDName.toStdString();

	const char* ch = str.c_str();;
	TiXmlElement *m_IED = new TiXmlElement("IED");
	int childcount = 0;
	TiXmlElement *child;
	child = root->FirstChildElement("IED");
	while (child != NULL)
	{
		childcount++;
		child = child->NextSiblingElement("IED");
	}
	m_IED->SetAttribute("No", QString::number(childcount, 10).toStdString().data());
	m_IED->SetAttribute("Name", ch);
	m_IED->SetAttribute("Ventor", Ventor.toStdString().data());
	m_IED->SetAttribute("Type", Type.toStdString().data());
	m_IED->SetAttribute("Address", Addr.toStdString().data());
	TiXmlElement *Item;
	Item = new TiXmlElement("BI");
	m_IED->LinkEndChild(Item);
	Item = new TiXmlElement("AI");
	m_IED->LinkEndChild(Item);
	Item = new TiXmlElement("CI");
	m_IED->LinkEndChild(Item);
	Item = new TiXmlElement("BO");
	m_IED->LinkEndChild(Item);
	Item = new TiXmlElement("SG");
	m_IED->LinkEndChild(Item);
	root->LinkEndChild(m_IED);
	return DO_OK;
}

int XML::DelOneIED(QString Addr)
{
	TiXmlElement *m_IED;;
	for (m_IED = root->FirstChildElement("IED"); m_IED != NULL; m_IED = m_IED->NextSiblingElement("IED"))
	{
		if (0 == strcmp(Addr.toLocal8Bit().data(), m_IED->Attribute("Address")))
		{
			root->RemoveChild(m_IED);
            break;
            //return DO_OK;
		}
	}
    int i =0;
    for (m_IED = root->FirstChildElement("IED"); m_IED != NULL; m_IED = m_IED->NextSiblingElement("IED"))
    {
        m_IED->SetAttribute("No",QString::number(i).toStdString().data());
        i++;
    }
	Init_Map();
    return DO_OK;
}

int XML::FindOneIED(QString Addr)
{
	TiXmlElement *m_IED;;
	for (m_IED = root->FirstChildElement("IED"); m_IED != NULL; m_IED = m_IED->NextSiblingElement("IED"))
	{
		if (0 == strcmp(Addr.toLocal8Bit().data(), m_IED->Attribute("Address")))
		{
			return DO_OK;
		}
	}
	return DO_FAIL;
}

int XML::UpdataOneIED(Model_XML &model, int type)
{
	TiXmlElement *m_IED;
	TiXmlElement *m_BI;
	TiXmlElement *m_CI;
	TiXmlElement *m_AI;
	TiXmlElement *m_BO;
    TiXmlElement *m_SG;
	bool find_flag = false;
	for (m_IED = root->FirstChildElement("IED"); m_IED != NULL; m_IED = m_IED->NextSiblingElement("IED"))
	{
		if (0 == strcmp(model.Address.toLocal8Bit().data(), m_IED->Attribute("Address")))
		{
			find_flag = true;
			break;
		}
	}
	if (find_flag == false)
	{
		CreatOneIED(model.Name, model.Ventor, model.Type, model.Address);
		for (m_IED = root->FirstChildElement("IED"); m_IED != NULL; m_IED = m_IED->NextSiblingElement("IED"))
		{
			if (0 == strcmp(model.Address.toLocal8Bit().data(), m_IED->Attribute("Address")))
			{
				break;
			}
		}
	}
	else
	{
		m_IED->SetAttribute("Name", model.Name.toStdString().data());
		m_IED->SetAttribute("Ventor", model.Ventor.toStdString().data());
		m_IED->SetAttribute("Type", model.Type.toStdString().data());
	}
    if(type==YX_TYPE)
    {
        m_BI = m_IED->FirstChildElement("BI");
        if(m_BI==NULL)
        {
            m_BI = new TiXmlElement("BI");
            m_IED->LinkEndChild(m_BI);
        }
        if (model.BI_List.size() != 0)
        {
            UpdataBIList(m_BI, model.BI_List);
        }
    }
    if(type==YC_TYPE)
    {
		m_AI = m_IED->FirstChildElement("AI");
		if (m_AI == NULL)
		{
			m_AI = new TiXmlElement("AI");
			m_IED->LinkEndChild(m_AI);
		}
		if (model.AI_List.size() != 0)
		{
			UpdataAIList(m_AI, model.AI_List);
		}
    }
    if(type==KWH_TYPE)
    {
      
		m_CI = m_IED->FirstChildElement("CI");
		if (m_CI == NULL)
		{
			m_CI = new TiXmlElement("CI");
			m_IED->LinkEndChild(m_CI);
		}
		if (model.CI_List.size() != 0)
		{
			UpdataCIList(m_CI, model.CI_List);
		}
    }
    if(type==YK_TYPE)
    {
        m_BO = m_IED->FirstChildElement("BO");
        if(m_BO==NULL)
        {
            m_BO = new TiXmlElement("BO");
            m_IED->LinkEndChild(m_BO);
        }
        if (model.BO_List.size() != 0)
        {
            UpdataBOList(m_BO, model.BO_List);
        }
    }
    if(type==SG_TYPE)
    {
        m_SG = m_IED->FirstChildElement("SG");
        if(m_SG==NULL)
        {
            m_SG = new TiXmlElement("SG");
            m_IED->LinkEndChild(m_SG);
        }
        if (model.SG_List.size() != 0)
        {
			UpdataSGList(m_SG, model.SG_List);
        }
    }




	Init_Map();
	return DO_OK;
}
int XML::GetOneIED(Model_XML &model, QString no)
{
	TiXmlElement *m_IED;
	bool find_flag = false;

	for (m_IED = root->FirstChildElement("IED"); m_IED != NULL; m_IED = m_IED->NextSiblingElement("IED"))
	{
		if (0 == strcmp(no.toLocal8Bit().data(), m_IED->Attribute("Address")))
		{
			find_flag = true;
			break;
		}
	}
	if (find_flag == false)
		return DO_FAIL;
	model.No = m_IED->Attribute("No");
	model.Name = m_IED->Attribute("Name");
	model.Ventor = m_IED->Attribute("Ventor");
	model.Type = m_IED->Attribute("Type");
	model.Address = m_IED->Attribute("Address");
	GetBIList(m_IED->FirstChildElement("BI"), model.BI_List);
	GetCIList(m_IED->FirstChildElement("CI"), model.CI_List);
	GetAIList(m_IED->FirstChildElement("AI"), model.AI_List);
	GetBOList(m_IED->FirstChildElement("BO"), model.BO_List);
	GetSGList(m_IED->FirstChildElement("SG"), model.SG_List);
	return DO_OK;
}
void XML::GetBIList(TiXmlElement* Element, QVector<BI_struct>&List)
{
	TiXmlElement* Item;
	TiXmlElement* Name;
	TiXmlElement* DataNo;
	TiXmlText* m_Text;
	for (Item = Element->FirstChildElement("Item"); Item != NULL; Item = Item->NextSiblingElement("Item"))
	{
		BI_struct m_BI;
		m_BI.stVal = Item->Attribute("stVal");
		m_BI.q = Item->Attribute("q");
		m_BI.t = Item->Attribute("t");
		m_BI.TrigOsc = Item->Attribute("TrigOsc");
		Name = Item->FirstChildElement("Name");
		m_Text = Name->FirstChild()->ToText();
		m_BI.Name = m_Text->Value();
		DataNo = Item->FirstChildElement("DataNo");
		m_Text = DataNo->FirstChild()->ToText();
		m_BI.DataNo = m_Text->Value();
		List.append(m_BI);
	}
}

void XML::GetAIList(TiXmlElement* Element, QVector<AI_struct>&List)
{
	TiXmlElement* Item;
	TiXmlElement* Name;
	TiXmlElement* DataNo;
	TiXmlText* m_Text;
	for (Item = Element->FirstChildElement("Item"); Item != NULL; Item = Item->NextSiblingElement("Item"))
	{
		AI_struct m_AI;

		Name = Item->FirstChildElement("Name");
		m_Text = Name->FirstChild()->ToText();
		m_AI.Name = m_Text->Value();
		DataNo = Item->FirstChildElement("DataNo");
		m_Text = DataNo->FirstChild()->ToText();
		m_AI.DataNo = m_Text->Value();
		List.append(m_AI);
	}
}

void XML::GetCIList(TiXmlElement* Element, QVector<CI_struct>&List)
{
	TiXmlElement* Item;
	TiXmlElement* Name;
	TiXmlElement* DataNo;
	TiXmlText* m_Text;
	for (Item = Element->FirstChildElement("Item"); Item != NULL; Item = Item->NextSiblingElement("Item"))
	{
		CI_struct m_CI;
		Name = Item->FirstChildElement("Name");
		m_Text = Name->FirstChild()->ToText();
		m_CI.Name = m_Text->Value();
		DataNo = Item->FirstChildElement("DataNo");
		m_Text = DataNo->FirstChild()->ToText();
		m_CI.DataNo = m_Text->Value();
		List.append(m_CI);
	}
}

void XML::GetBOList(TiXmlElement* Element, QVector<BO_struct>&List)
{
	TiXmlElement* Item;
	TiXmlElement* Name;
	TiXmlElement* DataNo;
	TiXmlText* m_Text;
	for (Item = Element->FirstChildElement("Item"); Item != NULL; Item = Item->NextSiblingElement("Item"))
	{
		BO_struct m_BO;
		m_BO.ctlModel = Item->Attribute("ctlModel");
		Name = Item->FirstChildElement("Name");
		m_Text = Name->FirstChild()->ToText();
		m_BO.Name = m_Text->Value();
		DataNo = Item->FirstChildElement("DataNo");
		m_Text = DataNo->FirstChild()->ToText();
		m_BO.DataNo = m_Text->Value();
		List.append(m_BO);
	}
}
void XML::GetSGList(TiXmlElement* Element, QVector<SG_struct>&List)
{
	TiXmlElement* Item;
	TiXmlElement* Name;
	TiXmlElement* DataNo;
	TiXmlText* m_Text;
	for (Item = Element->FirstChildElement("Item"); Item != NULL; Item = Item->NextSiblingElement("Item"))
	{
		SG_struct m_SG;

		Name = Item->FirstChildElement("Name");
		m_Text = Name->FirstChild()->ToText();
		m_SG.Name = m_Text->Value();
		DataNo = Item->FirstChildElement("DataNo");
		m_Text = DataNo->FirstChild()->ToText();
		m_SG.DataNo = m_Text->Value();
		List.append(m_SG);
	}
}

void XML::UpdataBIList(TiXmlElement*BI_Element, QVector<BI_struct>&List)
{
	while (BI_Element->FirstChildElement() != NULL)
	{
		BI_Element->RemoveChild(BI_Element->FirstChildElement());
	}
	TiXmlElement* Item;
	TiXmlElement* Name;
	TiXmlElement* DataNo;
	TiXmlText* m_Text;
	for (int i = 0; i < List.size(); i++)
	{
		Item = new TiXmlElement("Item");
		Item->SetAttribute("stVal", List[i].stVal.toStdString().data());
		Item->SetAttribute("q", List[i].q.toStdString().data());
		Item->SetAttribute("t", List[i].t.toStdString().data());
		Item->SetAttribute("TrigOsc", List[i].TrigOsc.toStdString().data());
		Name = new TiXmlElement("Name");
		m_Text = new TiXmlText(List[i].Name.toStdString().data());
		Name->LinkEndChild(m_Text);
		Item->LinkEndChild(Name);
		DataNo = new TiXmlElement("DataNo");
		m_Text = new TiXmlText(List[i].DataNo.toStdString().data());
		DataNo->LinkEndChild(m_Text);
		Item->LinkEndChild(DataNo);
		BI_Element->LinkEndChild(Item);
	}

}

void XML::UpdataAIList(TiXmlElement*AI_Element, QVector<AI_struct>&List)
{
	while (AI_Element->FirstChildElement() != NULL)
	{
		AI_Element->RemoveChild(AI_Element->FirstChildElement());
	}
	TiXmlElement* Item;
	TiXmlElement* Name;
	TiXmlElement* DataNo;
	TiXmlText* m_Text;
	for (int i = 0; i < List.size(); i++)
	{
		Item = new TiXmlElement("Item");
		Name = new TiXmlElement("Name");
		m_Text = new TiXmlText(List[i].Name.toStdString().data());
		Name->LinkEndChild(m_Text);
		Item->LinkEndChild(Name);
		DataNo = new TiXmlElement("DataNo");
		m_Text = new TiXmlText(List[i].DataNo.toStdString().data());
		DataNo->LinkEndChild(m_Text);
		Item->LinkEndChild(DataNo);
		AI_Element->LinkEndChild(Item);
	}
}

void XML::UpdataCIList(TiXmlElement* CI_Element, QVector<CI_struct>&List)
{
	while (CI_Element->FirstChildElement() != NULL)
	{
		CI_Element->RemoveChild(CI_Element->FirstChildElement());
	}
	TiXmlElement* Item;
	TiXmlElement* Name;
	TiXmlElement* DataNo;
	TiXmlText* m_Text;
	for (int i = 0; i < List.size(); i++)
	{
		Item = new TiXmlElement("Item");
		Name = new TiXmlElement("Name");
		m_Text = new TiXmlText(List[i].Name.toStdString().data());
		Name->LinkEndChild(m_Text);
		Item->LinkEndChild(Name);
		DataNo = new TiXmlElement("DataNo");
		m_Text = new TiXmlText(List[i].DataNo.toStdString().data());
		DataNo->LinkEndChild(m_Text);
		Item->LinkEndChild(DataNo);
		CI_Element->LinkEndChild(Item);
	}
}

void XML::UpdataBOList(TiXmlElement* BO_Element, QVector<BO_struct>&List)
{
	while (BO_Element->FirstChildElement() != NULL)
	{
		BO_Element->RemoveChild(BO_Element->FirstChildElement());
	}
	TiXmlElement* Item;
	TiXmlElement* Name;
	TiXmlElement* DataNo;
	TiXmlText* m_Text;
	for (int i = 0; i < List.size(); i++)
	{
		Item = new TiXmlElement("Item");
		Item->SetAttribute("ctlModel", List[i].ctlModel.toStdString().data());
		Name = new TiXmlElement("Name");
		m_Text = new TiXmlText(List[i].Name.toStdString().data());
		Name->LinkEndChild(m_Text);
		Item->LinkEndChild(Name);
		DataNo = new TiXmlElement("DataNo");
		m_Text = new TiXmlText(List[i].DataNo.toStdString().data());
		DataNo->LinkEndChild(m_Text);
		Item->LinkEndChild(DataNo);
		BO_Element->LinkEndChild(Item);
	}
}
void XML::UpdataSGList(TiXmlElement* SG_Element,QVector<SG_struct>&List)
{
while (SG_Element->FirstChildElement() != NULL)
{
    SG_Element->RemoveChild(SG_Element->FirstChildElement());
}
TiXmlElement* Item;
TiXmlElement* Name;
TiXmlElement* DataNo;
TiXmlText* m_Text;
for (int i = 0; i < List.size(); i++)
{
    Item = new TiXmlElement("Item");
    Name = new TiXmlElement("Name");
    m_Text = new TiXmlText(List[i].Name.toStdString().data());
    Name->LinkEndChild(m_Text);
    Item->LinkEndChild(Name);
    DataNo = new TiXmlElement("DataNo");
    m_Text = new TiXmlText(List[i].DataNo.toStdString().data());
    DataNo->LinkEndChild(m_Text);
    Item->LinkEndChild(DataNo);
    SG_Element->LinkEndChild(Item);
}
}
void XML::GetDeviceTypeList(QVector<Device_Type>&List)
{
	QString path = "IEDTYPE.xml";
	TiXmlDocument* IED_Doc;
	TiXmlElement* main_node;
	if (doc->LoadFile(path.toLocal8Bit().data()))
	{

		main_node = doc->FirstChildElement("xmldata");
		TiXmlElement* m_config;
		m_config = main_node->FirstChildElement("Config");
		TiXmlElement* child;
		for (child = m_config->FirstChildElement(); child != NULL; child = child->NextSiblingElement())
		{
			Device_Type m_dev;
			m_dev.Name = child->Attribute("name");
			m_dev.Type = child->Attribute("type");
			List.append(m_dev);
		}
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
		QMessageBox::information(NULL, QString("title"), QString(ch));

	}
}
TiXmlElement* XML::CreatClient()
{
	TiXmlElement* m_Client;
	m_Client = new TiXmlElement("CLIENT");
	m_Client->SetAttribute("Plat", "LINUX");
	TiXmlElement *m_Item;
	TiXmlElement * m_child;
	m_Item = new TiXmlElement("DbaseCreatType");
	TiXmlText *m_text = new TiXmlText("LOCALDATA");
	m_Item->LinkEndChild(m_text);
	m_Client->LinkEndChild(m_Item);
	m_Item = new TiXmlElement("TimeService");
	m_Item->SetAttribute("Mode", "SERVER");
	m_Item->SetAttribute("PortNo", "123");
	m_Item->SetAttribute("GroupNum", "1");
	m_Item->SetAttribute("GroupIp1", "192.168.100.255");
	m_Item->SetAttribute("GroupIp2", "192.168.200.255");
	m_Item->SetAttribute("GroupIp3", "192.168.300.255");
	m_Item->SetAttribute("Interval", "30000");
	m_child = new TiXmlElement("TimeMode");
	m_text = new TiXmlText("UNICAST");
	m_child->LinkEndChild(m_text);
	m_Item->LinkEndChild(m_child);
	m_child = new TiXmlElement("TimeServer");
	m_child->SetAttribute("Name", "Template_S");
	m_child->SetAttribute("Mode", "SLAVE");
	m_Item->LinkEndChild(m_child);
	m_child = new TiXmlElement("TimeServer");
	m_child->SetAttribute("Name", "Template_M");
	m_child->SetAttribute("Mode", "MASTER");
	m_Item->LinkEndChild(m_child);
	m_Client->LinkEndChild(m_Item);

	m_Item = new TiXmlElement("WorkDir");
	m_Item->SetAttribute("Type", "ABSOLUTE");
	m_child = new TiXmlElement("Path");
	m_text = new TiXmlText("/home/data");
	m_child->LinkEndChild(m_text);
	m_Item->LinkEndChild(m_child);
	m_Client->LinkEndChild(m_Item);


	m_Item = new TiXmlElement("Log");
	m_Item->SetAttribute("To", "FILE");
	m_child = new TiXmlElement("File");
	m_child->SetAttribute("Name", "log001.txt");
	m_child->SetAttribute("Size", "10240");
	m_child->SetAttribute("Wrap", "1");
	m_Item->LinkEndChild(m_child);

	m_child = new TiXmlElement("Error");
	m_text = new TiXmlText("ON");
	m_child->LinkEndChild(m_text);
	m_Item->LinkEndChild(m_child);

	m_child = new TiXmlElement("Logging");
	m_text = new TiXmlText("ON");
	m_child->LinkEndChild(m_text);
	m_Item->LinkEndChild(m_child);

	m_child = new TiXmlElement("Flow");
	m_text = new TiXmlText("ON");
	m_child->LinkEndChild(m_text);
	m_Item->LinkEndChild(m_child);

	m_child = new TiXmlElement("Debug");
	m_text = new TiXmlText("ON");
	m_child->LinkEndChild(m_text);
	m_Item->LinkEndChild(m_child);
	m_Client->LinkEndChild(m_Item);
	return m_Client;
}
int XML::CreatIED(IED_IEC& IED)
{
	TiXmlElement *m_Client;
	m_Client = root->FirstChildElement("CLIENT");
	std::string str = IED.Name.toStdString();
	const char * chr = str.c_str();
	TiXmlElement* m_IED;
	TiXmlElement *m_Item;
	TiXmlElement * m_child;
	TiXmlText *m_text;
	m_IED = new TiXmlElement("IED");
	m_IED->SetAttribute("Name", chr);
	str = IED.Vendor.toStdString();
	chr = str.c_str();
	m_IED->SetAttribute("Vendor", chr);
	m_IED->SetAttribute("Type", IED.Type.toStdString().data());
	m_Item = new TiXmlElement("Communication");
	m_Item->SetAttribute("ChanMode", IED.ChanMod.toStdString().data());
	m_child = new TiXmlElement("Channel");
	str = IED.Name.toStdString() + "_m";
	chr = str.c_str();
	m_child->SetAttribute("Name", chr);
	m_child->SetAttribute("Identify", "MASTER");
	m_Item->LinkEndChild(m_child);
	m_child = new TiXmlElement("Channel");
	str = IED.Name.toStdString() + "_s";
	chr = str.c_str();
	m_child->SetAttribute("Name", chr);
	m_child->SetAttribute("Identify", "SLAVE");
	m_Item->LinkEndChild(m_child);
	m_IED->LinkEndChild(m_Item);
	m_Item = new TiXmlElement("TimeServMode");
	m_text = new TiXmlText(IED.TimeServMode.toStdString().data());
	m_Item->LinkEndChild(m_text);
	m_IED->LinkEndChild(m_Item);
	m_Item = new TiXmlElement("TimeCtrl");
	m_child = new TiXmlElement("CtlTimeOut");
	m_text = new TiXmlText(IED.CtlTimeOut.toStdString().data());
	m_child->LinkEndChild(m_text);
	m_Item->LinkEndChild(m_child);
	m_child = new TiXmlElement("GITime");
	m_text = new TiXmlText(IED.GITime.toStdString().data());
	m_child->LinkEndChild(m_text);
	m_Item->LinkEndChild(m_child);
	m_child = new TiXmlElement("RptBufTime");
	m_text = new TiXmlText(IED.RptBufTime.toStdString().data());
	m_child->LinkEndChild(m_text);
	m_Item->LinkEndChild(m_child);
	m_child = new TiXmlElement("RptIntgPd");
	m_text = new TiXmlText(IED.RptIntgPd.toStdString().data());
	m_child->LinkEndChild(m_text);
	m_Item->LinkEndChild(m_child);
	m_child = new TiXmlElement("LostConTime");
	m_text = new TiXmlText(IED.LostConTime.toStdString().data());
	m_child->LinkEndChild(m_text);
	m_Item->LinkEndChild(m_child);
	m_child = new TiXmlElement("KeepLive");
	m_text = new TiXmlText(IED.KeepLive.toStdString().data());
	m_child->LinkEndChild(m_text);
	m_Item->LinkEndChild(m_child);
	m_IED->LinkEndChild(m_Item);
	m_Item = new TiXmlElement("Logon");
	m_Item->SetAttribute("AuthMod", IED.AuthMod.toStdString().data());
	m_child = new TiXmlElement("AuthCode");
	m_text = new TiXmlText(IED.AuthCode.toStdString().data());
	m_child->LinkEndChild(m_text);
	m_Item->LinkEndChild(m_child);
	m_IED->LinkEndChild(m_Item);
	m_Client->LinkEndChild(m_IED);
	return DO_OK;
}
TiXmlElement* XML::CreatMMS()
{
	TiXmlElement* m_MMS;
	TiXmlElement *m_Item;
	TiXmlElement * m_child;
	TiXmlText *m_text;
	m_MMS = new TiXmlElement("MMS");
	m_Item = new TiXmlElement("Max_Mms_Pdu_Length");
	m_text = new TiXmlText("100000");
	m_Item->LinkEndChild(m_text);
	m_MMS->LinkEndChild(m_Item);
	m_Item = new TiXmlElement("Max_Calling_Connections");
	m_text = new TiXmlText("32");
	m_Item->LinkEndChild(m_text);
	m_MMS->LinkEndChild(m_Item);
	m_Item = new TiXmlElement("Max_Called_Connections");
	m_text = new TiXmlText("0");
	m_Item->LinkEndChild(m_text);
	m_MMS->LinkEndChild(m_Item);
	return m_MMS;
}
TiXmlElement* XML::CreatNetwork()
{
	TiXmlElement* m_Network;
	TiXmlElement *m_Item;
	TiXmlElement * m_child;
	TiXmlText *m_text;
	m_Network = new TiXmlElement("Network");
	m_Item = new TiXmlElement("Clnp");
	m_child = new TiXmlElement("Lifetime");
	m_text = new TiXmlText("50");
	m_child->LinkEndChild(m_text);
	m_Item->LinkEndChild(m_child);
	m_child = new TiXmlElement("Lifetime_Decrement");
	m_text = new TiXmlText("1");
	m_child->LinkEndChild(m_text);
	m_Item->LinkEndChild(m_child);
	m_child = new TiXmlElement("Cfg_Timer");
	m_text = new TiXmlText("120");
	m_child->LinkEndChild(m_text);
	m_Item->LinkEndChild(m_child);
	m_child = new TiXmlElement("Esh_Delay");
	m_text = new TiXmlText("5");
	m_child->LinkEndChild(m_text);
	m_Item->LinkEndChild(m_child);
	m_child = new TiXmlElement("Local_NSAP");
	m_text = new TiXmlText("49 00 01 53 49 53 43 09 01 01");
	m_child->LinkEndChild(m_text);
	m_Item->LinkEndChild(m_child);
	m_Network->LinkEndChild(m_Item);
	return m_Network;
}
TiXmlElement* XML::CreatTransport()
{
	TiXmlElement* m_Transport;
	TiXmlElement *m_Item;
	TiXmlElement * m_child;
	TiXmlText *m_text;
	m_Transport = new TiXmlElement("Transport");
	m_Item = new TiXmlElement("Tp4");
	m_child = new TiXmlElement("Max_Tpdu_Length");
	m_text = new TiXmlText("1024");
	m_child->LinkEndChild(m_text);
	m_Item->LinkEndChild(m_child);
	m_child = new TiXmlElement("Max_Remote_Cdt");
	m_text = new TiXmlText("4");
	m_child->LinkEndChild(m_text);
	m_Item->LinkEndChild(m_child);
	m_child = new TiXmlElement("Local_Cdt");
	m_text = new TiXmlText("4");
	m_child->LinkEndChild(m_text);
	m_Item->LinkEndChild(m_child);
	m_child = new TiXmlElement("Max_Num_Connections");
	m_text = new TiXmlText("8");
	m_child->LinkEndChild(m_text);
	m_Item->LinkEndChild(m_child);
	m_child = new TiXmlElement("Max_Spdu_Outstanding");
	m_text = new TiXmlText("4");
	m_child->LinkEndChild(m_text);
	m_Item->LinkEndChild(m_child);
	m_child = new TiXmlElement("Window_Time");
	m_text = new TiXmlText("10");
	m_child->LinkEndChild(m_text);
	m_Item->LinkEndChild(m_child);
	m_child = new TiXmlElement("Inactivity_Time");
	m_text = new TiXmlText("120");
	m_child->LinkEndChild(m_text);
	m_Item->LinkEndChild(m_child);
	m_child = new TiXmlElement("Retransmission_Time");
	m_text = new TiXmlText("10");
	m_child->LinkEndChild(m_text);
	m_Item->LinkEndChild(m_child);
	m_child = new TiXmlElement("Max_Transmissions");
	m_text = new TiXmlText("2");
	m_child->LinkEndChild(m_text);
	m_Item->LinkEndChild(m_child);
	m_child = new TiXmlElement("Ak_Delay");
	m_text = new TiXmlText("2");
	m_child->LinkEndChild(m_text);
	m_Item->LinkEndChild(m_child);
	m_Transport->LinkEndChild(m_Item);
	m_Item = new TiXmlElement("Tcp");
	m_child = new TiXmlElement("Rfc1006_Max_Tpdu_Len");
	m_text = new TiXmlText("1024");
	m_child->LinkEndChild(m_text);
	m_Item->LinkEndChild(m_child);
	m_child = new TiXmlElement("Rfc1006_Max_Num_Conns");
	m_text = new TiXmlText("8");
	m_child->LinkEndChild(m_text);
	m_Item->LinkEndChild(m_child);
	m_Transport->LinkEndChild(m_Item);
	return m_Transport;
}
TiXmlElement* XML::CreatNetworkAddressing()
{
	TiXmlElement* m_NetworkAddr;
	TiXmlElement *m_Item;
	TiXmlElement * m_child;
	TiXmlElement * m_leaf;
	TiXmlText *m_text;
	m_NetworkAddr = new TiXmlElement("NetworkAddressing");
	m_Item = new TiXmlElement("LocalAddressList");
	m_child = new TiXmlElement("LocalAddress");
	m_leaf = new TiXmlElement("AR_Name");
	m_text = new TiXmlText("local1");
	m_leaf->LinkEndChild(m_text);
	m_child->LinkEndChild(m_leaf);
	m_leaf = new TiXmlElement("AP_Title");
	m_text = new TiXmlText("1 3 9999 33");
	m_leaf->LinkEndChild(m_text);
	m_child->LinkEndChild(m_leaf);
	m_leaf = new TiXmlElement("AE_Qualifier");
	m_text = new TiXmlText("33");
	m_leaf->LinkEndChild(m_text);
	m_child->LinkEndChild(m_leaf);
	m_leaf = new TiXmlElement("Psel");
	m_text = new TiXmlText("00 00 00 01");
	m_leaf->LinkEndChild(m_text);
	m_child->LinkEndChild(m_leaf);
	m_leaf = new TiXmlElement("Ssel");
	m_text = new TiXmlText("00 01");
	m_leaf->LinkEndChild(m_text);
	m_child->LinkEndChild(m_leaf);
	m_leaf = new TiXmlElement("Tsel");
	m_text = new TiXmlText("00 01");
	m_leaf->LinkEndChild(m_text);
	m_child->LinkEndChild(m_leaf);
	m_leaf = new TiXmlElement("TransportType");
	m_text = new TiXmlText("TCP");
	m_leaf->LinkEndChild(m_text);
	m_child->LinkEndChild(m_leaf);
	m_Item->LinkEndChild(m_child);
	m_child = new TiXmlElement("LocalAddress");
	m_leaf = new TiXmlElement("AR_Name");
	m_text = new TiXmlText("local2");
	m_leaf->LinkEndChild(m_text);
	m_child->LinkEndChild(m_leaf);
	m_leaf = new TiXmlElement("AP_Title");
	m_text = new TiXmlText("1 3 9999 33");
	m_leaf->LinkEndChild(m_text);
	m_child->LinkEndChild(m_leaf);
	m_leaf = new TiXmlElement("AE_Qualifier");
	m_text = new TiXmlText("33");
	m_leaf->LinkEndChild(m_text);
	m_child->LinkEndChild(m_leaf);
	m_leaf = new TiXmlElement("Psel");
	m_text = new TiXmlText("00 00 00 01");
	m_leaf->LinkEndChild(m_text);
	m_child->LinkEndChild(m_leaf);
	m_leaf = new TiXmlElement("Ssel");
	m_text = new TiXmlText("00 01");
	m_leaf->LinkEndChild(m_text);
	m_child->LinkEndChild(m_leaf);
	m_leaf = new TiXmlElement("Tsel");
	m_text = new TiXmlText("00 01");
	m_leaf->LinkEndChild(m_text);
	m_child->LinkEndChild(m_leaf);
	m_leaf = new TiXmlElement("TransportType");
	m_text = new TiXmlText("TCP");
	m_leaf->LinkEndChild(m_text);
	m_child->LinkEndChild(m_leaf);
	m_Item->LinkEndChild(m_child);
	m_child = new TiXmlElement("LocalAddress");
	m_leaf = new TiXmlElement("AR_Name");
	m_text = new TiXmlText("local3");
	m_leaf->LinkEndChild(m_text);
	m_child->LinkEndChild(m_leaf);
	m_leaf = new TiXmlElement("AP_Title");
	m_text = new TiXmlText("1 3 9999 33");
	m_leaf->LinkEndChild(m_text);
	m_child->LinkEndChild(m_leaf);
	m_leaf = new TiXmlElement("AE_Qualifier");
	m_text = new TiXmlText("33");
	m_leaf->LinkEndChild(m_text);
	m_child->LinkEndChild(m_leaf);
	m_leaf = new TiXmlElement("Psel");
	m_text = new TiXmlText("00 00 00 01");
	m_leaf->LinkEndChild(m_text);
	m_child->LinkEndChild(m_leaf);
	m_leaf = new TiXmlElement("Ssel");
	m_text = new TiXmlText("00 01");
	m_leaf->LinkEndChild(m_text);
	m_child->LinkEndChild(m_leaf);
	m_leaf = new TiXmlElement("Tsel");
	m_text = new TiXmlText("00 01");
	m_leaf->LinkEndChild(m_text);
	m_child->LinkEndChild(m_leaf);
	m_leaf = new TiXmlElement("TransportType");
	m_text = new TiXmlText("TCP");
	m_leaf->LinkEndChild(m_text);
	m_child->LinkEndChild(m_leaf);
	m_Item->LinkEndChild(m_child);
	m_NetworkAddr->LinkEndChild(m_Item);


	m_Item = new TiXmlElement("RemoteAddressList");
	m_child = new TiXmlElement("RemoteAddress");
	m_leaf = new TiXmlElement("AR_Name");
	m_text = new TiXmlText("Local");
	m_leaf->LinkEndChild(m_text);
	m_child->LinkEndChild(m_leaf);
	m_leaf = new TiXmlElement("AP_Title");
	m_text = new TiXmlText("1 3 9999 23");
	m_leaf->LinkEndChild(m_text);
	m_child->LinkEndChild(m_leaf);
	m_leaf = new TiXmlElement("AE_Qualifier");
	m_text = new TiXmlText("23");
	m_leaf->LinkEndChild(m_text);
	m_child->LinkEndChild(m_leaf);
	m_leaf = new TiXmlElement("Psel");
	m_text = new TiXmlText("00 00 00 01");
	m_leaf->LinkEndChild(m_text);
	m_child->LinkEndChild(m_leaf);
	m_leaf = new TiXmlElement("Ssel");
	m_text = new TiXmlText("00 01");
	m_leaf->LinkEndChild(m_text);
	m_child->LinkEndChild(m_leaf);
	m_leaf = new TiXmlElement("Tsel");
	m_text = new TiXmlText("00 01");
	m_leaf->LinkEndChild(m_text);
	m_child->LinkEndChild(m_leaf);
	m_leaf = new TiXmlElement("NetAddr");
	m_leaf->SetAttribute("Type", "IPADDR");
	m_text = new TiXmlText("127.0.0.1");
	m_leaf->LinkEndChild(m_text);
	m_child->LinkEndChild(m_leaf);
	m_Item->LinkEndChild(m_child);
	m_NetworkAddr->LinkEndChild(m_Item);
	return m_NetworkAddr;
}
int XML::CreatRemoteAddres(RemoteAddress_Type& RemoteAddress)
{
	TiXmlElement *m_node;
	std::string str;
	const char * chr;
	m_node = root->FirstChildElement("NetworkAddressing");
	m_node = m_node->FirstChildElement("RemoteAddressList");
	TiXmlElement *Remote;
	TiXmlElement * m_child;
	TiXmlText *m_text;
	Remote = new TiXmlElement("RemoteAddress");
	m_child = new TiXmlElement("AR_Name");
	str = RemoteAddress.Name.toStdString() + "_m";
	chr = str.c_str();
	m_text = new TiXmlText(chr);
	m_child->LinkEndChild(m_text);
	Remote->LinkEndChild(m_child);
	m_child = new TiXmlElement("AP_Title");
	str = RemoteAddress.Ap_Title.toStdString();
	chr = str.c_str();
	m_text = new TiXmlText(chr);
	m_child->LinkEndChild(m_text);
	Remote->LinkEndChild(m_child);
	m_child = new TiXmlElement("AE_Qualifier");
	str = RemoteAddress.AE_Qualifier.toStdString();
	chr = str.c_str();
	m_text = new TiXmlText(chr);
	m_child->LinkEndChild(m_text);
	Remote->LinkEndChild(m_child);
	m_child = new TiXmlElement("Psel");
	str = RemoteAddress.Psel.toStdString();
	chr = str.c_str();
	m_text = new TiXmlText(chr);
	m_child->LinkEndChild(m_text);
	Remote->LinkEndChild(m_child);
	m_child = new TiXmlElement("Ssel");
	str = RemoteAddress.Ssel.toStdString();
	chr = str.c_str();
	m_text = new TiXmlText(chr);
	m_child->LinkEndChild(m_text);
	Remote->LinkEndChild(m_child);
	m_child = new TiXmlElement("Tsel");
	str = RemoteAddress.Tsel.toStdString();
	chr = str.c_str();
	m_text = new TiXmlText(chr);
	m_child->LinkEndChild(m_text);
	Remote->LinkEndChild(m_child);
	m_child = new TiXmlElement("NetAddr");
	m_child->SetAttribute("Type", "IPADDR");
	str = RemoteAddress.Addr1.toStdString();
	chr = str.c_str();
	m_text = new TiXmlText(chr);
	m_child->LinkEndChild(m_text);
	Remote->LinkEndChild(m_child);
	m_node->LinkEndChild(Remote); Remote = new TiXmlElement("RemoteAddress");
	m_child = new TiXmlElement("AR_Name");
	str = RemoteAddress.Name.toStdString() + "_s";
	chr = str.c_str();
	m_text = new TiXmlText(chr);
	m_child->LinkEndChild(m_text);
	Remote->LinkEndChild(m_child);
	m_child = new TiXmlElement("AP_Title");
	str = RemoteAddress.Ap_Title.toStdString();
	chr = str.c_str();
	m_text = new TiXmlText(chr);
	m_child->LinkEndChild(m_text);
	Remote->LinkEndChild(m_child);
	m_child = new TiXmlElement("AE_Qualifier");
	str = RemoteAddress.AE_Qualifier.toStdString();
	chr = str.c_str();
	m_text = new TiXmlText(chr);
	m_child->LinkEndChild(m_text);
	Remote->LinkEndChild(m_child);
	m_child = new TiXmlElement("Psel");
	str = RemoteAddress.Psel.toStdString();
	chr = str.c_str();
	m_text = new TiXmlText(chr);
	m_child->LinkEndChild(m_text);
	Remote->LinkEndChild(m_child);
	m_child = new TiXmlElement("Ssel");
	str = RemoteAddress.Ssel.toStdString();
	chr = str.c_str();
	m_text = new TiXmlText(chr);
	m_child->LinkEndChild(m_text);
	Remote->LinkEndChild(m_child);
	m_child = new TiXmlElement("Tsel");
	str = RemoteAddress.Tsel.toStdString();
	chr = str.c_str();
	m_text = new TiXmlText(chr);
	m_child->LinkEndChild(m_text);
	Remote->LinkEndChild(m_child);
	m_child = new TiXmlElement("NetAddr");
	m_child->SetAttribute("Type", "IPADDR");
	str = RemoteAddress.Addr2.toStdString();
	chr = str.c_str();
	m_text = new TiXmlText(chr);
	m_child->LinkEndChild(m_text);
	Remote->LinkEndChild(m_child);
	m_node->LinkEndChild(Remote);
	return DO_OK;
}
int XML::UpdateRemote(QString OldName, IED_IEC&IED, RemoteAddress_Type&RemoteAddres)
{
	if (OldName == IED.Name)
	{
		UpdateIED(OldName, IED);
		UpdateAddres(OldName, RemoteAddres);
	}
	else
	{
		int ret = CheckName(IED.Name);
		if (DO_OK == ret)
		{
            QMessageBox::about(0, QObject::tr("Notice"), QObject::tr("The IED name is exist"));
			return DO_FAIL;
		}
		else
		{
			UpdateIED(OldName, IED);
			UpdateAddres(OldName, RemoteAddres);
		}

	}


	return DO_OK;
}
int XML::UpdateIED(QString OldName, IED_IEC&IED)
{
	TiXmlElement *m_IED;
	TiXmlElement *m_Child;
	TiXmlText* m_Text;
	std::string str;
	const char * chr;
	m_IED = root->FirstChildElement("CLIENT")->FirstChildElement("IED");
	for (; m_IED != NULL; m_IED = m_IED->NextSiblingElement("IED"))
	{
		QString str = m_IED->Attribute("Name");
		if (str == OldName)
		{
			break;
		}
	}
	str = IED.Name.toStdString();
	chr = str.c_str();
	m_IED->SetAttribute("Name", chr);
	str = IED.Vendor.toStdString();
	chr = str.c_str();
	m_IED->SetAttribute("Vendor", chr);
	str = IED.Type.toStdString();
	chr = str.c_str();
	m_IED->SetAttribute("Type", chr);
	m_Child = m_IED->FirstChildElement("Communication");
	m_Child->SetAttribute("ChanMode", IED.ChanMod.toStdString().data());
	m_Child = m_Child->FirstChildElement("Channel");
	str = IED.Name.toStdString() + "_m";
	chr = str.c_str();
	m_Child->SetAttribute("Name", chr);
	m_Child = m_Child->NextSiblingElement("Channel");
	str = IED.Name.toStdString() + "_s";
	chr = str.c_str();
	m_Child->SetAttribute("Name", chr);
	m_Child = m_IED->FirstChildElement("TimeServMode");
	m_Text = m_Child->FirstChild()->ToText();
	str = IED.TimeServMode.toStdString();
	chr = str.c_str();
	m_Text->SetValue(chr);
	m_Child = m_IED->FirstChildElement("TimeCtrl");
	m_Child = m_Child->FirstChildElement("CtlTimeOut");
	m_Text = m_Child->FirstChild()->ToText();
	str = IED.CtlTimeOut.toStdString();
	chr = str.c_str();
	m_Text->SetValue(chr);
	m_Child = m_Child->NextSiblingElement("GITime");
	m_Text = m_Child->FirstChild()->ToText();
	str = IED.GITime.toStdString();
	chr = str.c_str();
	m_Text->SetValue(chr);
	m_Child = m_Child->NextSiblingElement("RptBufTime");
	m_Text = m_Child->FirstChild()->ToText();
	str = IED.RptBufTime.toStdString();
	chr = str.c_str();
	m_Text->SetValue(chr);
	m_Child = m_Child->NextSiblingElement("RptIntgPd");
	m_Text = m_Child->FirstChild()->ToText();
	str = IED.RptBufTime.toStdString();
	chr = str.c_str();
	m_Text->SetValue(chr);
	m_Child = m_Child->NextSiblingElement("LostConTime");
	m_Text = m_Child->FirstChild()->ToText();
	str = IED.LostConTime.toStdString();
	chr = str.c_str();
	m_Text->SetValue(chr);
	m_Child = m_Child->NextSiblingElement("KeepLive");
	m_Text = m_Child->FirstChild()->ToText();
	str = IED.KeepLive.toStdString();
	chr = str.c_str();
	m_Text->SetValue(chr);
	m_Child = m_IED->FirstChildElement("Logon");
	m_Child->SetAttribute("AuthMod", IED.AuthMod.toStdString().data());
	m_Child = m_Child->FirstChildElement("AuthCode");
	m_Text = m_Child->FirstChild()->ToText();
	str = IED.AuthCode.toStdString();
	chr = str.c_str();
	m_Text->SetValue(chr);
	return DO_OK;
}
int XML::UpdateAddres(QString OldName, RemoteAddress_Type&RemoteAddres)
{
	TiXmlElement *m_RemoteAddress=NULL;
	TiXmlElement *m_IED = NULL;
	TiXmlElement *m_communication= NULL;
	QString str1 = OldName + "_s";
	QString str3 = RemoteAddres.Name + "_s";
	QString str2 = OldName + "_m";
	QString str4 = RemoteAddres.Name + "_m";
	//const char * chrs= str1.c_str();
	//const char * chrm = str2.c_str();
	//for (m_IED = root->FirstChildElement("IED"); m_IED != NULL; m_IED = m_IED->NextSiblingElement("IED"))
	//{
	//	QString str;
	//	str.clear();
	//	str += m_IED->Attribute("Name");
	//	if (str==OldName)
	//	{
	//		m_communication = m_IED->FirstChildElement("Communication");
	//		m_communication->SetAttribute("ChanMode", RemoteAddres.Ch.toStdString().data());
	//	}
	//}
	m_RemoteAddress = root->FirstChildElement("NetworkAddressing")->FirstChildElement("RemoteAddressList")->FirstChildElement("RemoteAddress");
	for (; m_RemoteAddress != NULL; m_RemoteAddress = m_RemoteAddress->NextSiblingElement("RemoteAddress"))
	{
		TiXmlElement *AR_Name, *Net_Addr, *AP_Title, *AE_Qualifier, *Psel, *Ssel, *Tsel;
		TiXmlText* m_text;
		AR_Name = m_RemoteAddress->FirstChildElement("AR_Name");
		QString str;
		str += AR_Name->FirstChild()->ToText()->Value();
		if (str == str2)
		{
			m_text = AR_Name->FirstChild()->ToText();
			m_text->SetValue(str4.toStdString().data());
			Net_Addr = m_RemoteAddress->FirstChildElement("NetAddr");
			m_text = Net_Addr->FirstChild()->ToText();
			m_text->SetValue(RemoteAddres.Addr1.toStdString().data());
			AP_Title = m_RemoteAddress->FirstChildElement("AP_Title");
			m_text = AP_Title->FirstChild()->ToText();
			m_text->SetValue(RemoteAddres.Ap_Title.toStdString().data());
			AE_Qualifier = m_RemoteAddress->FirstChildElement("AE_Qualifier");
			m_text = AE_Qualifier->FirstChild()->ToText();
			m_text->SetValue(RemoteAddres.AE_Qualifier.toStdString().data());
			Psel = m_RemoteAddress->FirstChildElement("Psel");
			m_text = Psel->FirstChild()->ToText();
			m_text->SetValue(RemoteAddres.Psel.toStdString().data());
			Ssel = m_RemoteAddress->FirstChildElement("Ssel");
			m_text = Ssel->FirstChild()->ToText();
			m_text->SetValue(RemoteAddres.Ssel.toStdString().data());
			Tsel = m_RemoteAddress->FirstChildElement("Tsel");
			m_text = Tsel->FirstChild()->ToText();
			m_text->SetValue(RemoteAddres.Tsel.toStdString().data());
		}
		if (str == str1)
		{
			m_text = AR_Name->FirstChild()->ToText();
			m_text->SetValue(str3.toStdString().data());
			Net_Addr = m_RemoteAddress->FirstChildElement("NetAddr");
			m_text = Net_Addr->FirstChild()->ToText();
			m_text->SetValue(RemoteAddres.Addr2.toStdString().data());
			AP_Title = m_RemoteAddress->FirstChildElement("AP_Title");
			m_text = AP_Title->FirstChild()->ToText();
			m_text->SetValue(RemoteAddres.Ap_Title.toStdString().data());
			AE_Qualifier = m_RemoteAddress->FirstChildElement("AE_Qualifier");
			m_text = AE_Qualifier->FirstChild()->ToText();
			m_text->SetValue(RemoteAddres.AE_Qualifier.toStdString().data());
			Psel = m_RemoteAddress->FirstChildElement("Psel");
			m_text = Psel->FirstChild()->ToText();
			m_text->SetValue(RemoteAddres.Psel.toStdString().data());
			Ssel = m_RemoteAddress->FirstChildElement("Ssel");
			m_text = Ssel->FirstChild()->ToText();
			m_text->SetValue(RemoteAddres.Ssel.toStdString().data());
			Tsel = m_RemoteAddress->FirstChildElement("Tsel");
			m_text = Tsel->FirstChild()->ToText();
			m_text->SetValue(RemoteAddres.Tsel.toStdString().data());
		}
	}
	return DO_OK;
}
int XML::CreatOneRemote(IED_IEC &IED, RemoteAddress_Type &RemoteAddress)
{
	CreatIED(IED);
	CreatRemoteAddres(RemoteAddress);
	return DO_OK;
}
int XML::CheckName(QString Name)
{
	TiXmlElement *m_IED;
	m_IED = root->FirstChildElement("CLIENT")->FirstChildElement("IED");
	for (; m_IED != NULL; m_IED = m_IED->NextSiblingElement("IED"))
	{
		if (0 == strcmp(Name.toStdString().data(), m_IED->Attribute("Name")))
		{
			return DO_OK;
		}
	}
	return DO_FAIL;
}
int XML::GetDeviceList(QVector< IED_IEC>& IEDList, QVector< RemoteAddress_Type>&RemoteList)
{
	const char *chr;


	TiXmlElement *IEDNode;
	TiXmlElement *RemoteNode;
	TiXmlElement *Child;
	TiXmlText *m_text;
	IEDNode = root->FirstChildElement("CLIENT")->FirstChildElement("IED");
	if (IEDNode == NULL)
	{
		return DO_FAIL;
	}
	for (; IEDNode != NULL; IEDNode = IEDNode->NextSiblingElement("IED"))
	{
		IED_IEC m_IED;
		chr = IEDNode->Attribute("Name");
		m_IED.Name += chr;
		m_IED.Vendor += IEDNode->Attribute("Vendor");
		m_IED.Type += IEDNode->Attribute("Type");
		Child = IEDNode->FirstChildElement("Communication");
		m_IED.ChanMod += Child->Attribute("ChanMode");
		Child = Child->FirstChildElement("Channel");
		m_IED.ChanName1 += Child->Attribute("Name");
		Child = Child->NextSiblingElement("Channel");
		m_IED.ChanName2 += Child->Attribute("Name");
		Child = IEDNode->FirstChildElement("TimeServMode");
		m_text = Child->FirstChild()->ToText();
		m_IED.TimeServMode += m_text->Value();
		Child = IEDNode->FirstChildElement("TimeCtrl");
		Child = Child->FirstChildElement("CtlTimeOut");
		m_text = Child->FirstChild()->ToText();
		m_IED.CtlTimeOut += m_text->Value();
		Child = Child->NextSiblingElement("GITime");
		m_text = Child->FirstChild()->ToText();
		m_IED.GITime += m_text->Value();
		Child = Child->NextSiblingElement("RptBufTime");
		m_text = Child->FirstChild()->ToText();
		m_IED.RptBufTime += m_text->Value();
		Child = Child->NextSiblingElement("RptIntgPd");
		m_text = Child->FirstChild()->ToText();
		m_IED.RptIntgPd += m_text->Value();
		Child = Child->NextSiblingElement("LostConTime");
		m_text = Child->FirstChild()->ToText();
		m_IED.LostConTime += m_text->Value();
		Child = Child->NextSiblingElement("KeepLive");
		m_text = Child->FirstChild()->ToText();
		m_IED.KeepLive += m_text->Value();
		Child = IEDNode->FirstChildElement("Logon");
		m_IED.AuthMod = Child->Attribute("AuthMod");
		Child = Child->FirstChildElement("AuthCode");
		m_text = Child->FirstChild()->ToText();
		m_IED.AuthCode += m_text->Value();
		IEDList.append(m_IED);
	}


	for (int i = 0; i < IEDList.size(); i++)
	{
		RemoteAddress_Type m_Remote;
		m_Remote.Name = IEDList[i].Name;
		RemoteNode = root->FirstChildElement("NetworkAddressing")->FirstChildElement("RemoteAddressList")->FirstChildElement("RemoteAddress");

		for (; RemoteNode != NULL; RemoteNode = RemoteNode->NextSiblingElement("RemoteAddress"))
		{
			Child = RemoteNode->FirstChildElement("AR_Name");
			m_text = Child->FirstChild()->ToText();
			if (0 == strcmp(m_text->Value(), IEDList[i].ChanName1.toStdString().data()))
			{
				Child = RemoteNode->FirstChildElement("AP_Title");
				m_text = Child->FirstChild()->ToText();
				m_Remote.Ap_Title += m_text->Value();
				Child = RemoteNode->FirstChildElement("AE_Qualifier");
				m_text = Child->FirstChild()->ToText();
				m_Remote.AE_Qualifier += m_text->Value();
				Child = RemoteNode->FirstChildElement("Psel");
				m_text = Child->FirstChild()->ToText();
				m_Remote.Psel += m_text->Value();
				Child = RemoteNode->FirstChildElement("Ssel");
				m_text = Child->FirstChild()->ToText();
				m_Remote.Ssel += m_text->Value();
				Child = RemoteNode->FirstChildElement("Tsel");
				m_text = Child->FirstChild()->ToText();
				m_Remote.Tsel += m_text->Value();
				Child = RemoteNode->FirstChildElement("NetAddr");
				m_Remote.NetType = Child->Attribute("Type");
				m_text = Child->FirstChild()->ToText();
				m_Remote.Addr1 += m_text->Value();
			}
			if (0 == strcmp(m_text->Value(), IEDList[i].ChanName2.toStdString().data()))
			{
				Child = RemoteNode->FirstChildElement("NetAddr");
				m_text = Child->FirstChild()->ToText();
				m_Remote.Addr2 += m_text->Value();
			}
		}
		RemoteList.append(m_Remote);
	}
	return DO_OK;
}
int XML::DelOneRemote(QString IEDName)
{
	TiXmlElement *IEDNode;
	TiXmlElement *Client;
	TiXmlElement *RemoteNode;
	TiXmlElement *RemoteAddressList;
	TiXmlElement *Child;
	TiXmlText *m_text;
	TiXmlElement *m_Channel;
	IED_IEC m_IED;
	Client = root->FirstChildElement("CLIENT");
	IEDNode = Client->FirstChildElement("IED");
	for (; IEDNode != NULL; IEDNode = IEDNode->NextSiblingElement("IED"))
	{
		if (0 == strcmp(IEDName.toStdString().data(), IEDNode->Attribute("Name")))
		{
			Child = IEDNode->FirstChildElement("Communication");
			m_Channel = Child->FirstChildElement("Channel");
			m_IED.ChanName1 += m_Channel->Attribute("Name");
			m_Channel = m_Channel->NextSiblingElement("Channel");
			m_IED.ChanName2 += m_Channel->Attribute("Name");
			Client->RemoveChild(IEDNode);
			break;
		}
	}
	RemoteAddressList = root->FirstChildElement("NetworkAddressing")->FirstChildElement("RemoteAddressList");
	RemoteNode = RemoteAddressList->FirstChildElement("RemoteAddress");
	for (; RemoteNode != NULL; RemoteNode = RemoteNode->NextSiblingElement("RemoteAddress"))
	{
		Child = RemoteNode->FirstChildElement("AR_Name");
		m_text = Child->FirstChild()->ToText();
		if (0 == strcmp(m_IED.ChanName1.toStdString().data(), m_text->Value()))
		{

			RemoteAddressList->RemoveChild(RemoteNode);
			break;
		}
	}
	RemoteAddressList = root->FirstChildElement("NetworkAddressing")->FirstChildElement("RemoteAddressList");
	RemoteNode = RemoteAddressList->FirstChildElement("RemoteAddress");
	for (; RemoteNode != NULL; RemoteNode = RemoteNode->NextSiblingElement("RemoteAddress"))
	{
		Child = RemoteNode->FirstChildElement("AR_Name");
		m_text = Child->FirstChild()->ToText();
		if (0 == strcmp(m_IED.ChanName2.toStdString().data(), m_text->Value()))
		{
			RemoteAddressList->RemoveChild(RemoteNode);
			break;
		}
	}
	return  DO_OK;
}
int XML::GetTimeService(TimeServer&Timeserver)
{
	TiXmlElement *m_Node;
	TiXmlElement *Child;
	TiXmlText *m_text;
	m_Node = root->FirstChildElement("CLIENT")->FirstChildElement("TimeService");
	if (m_Node == NULL)
	{
		return DO_FAIL;
	}
	Timeserver.Mode = m_Node->Attribute("Mode");
	Timeserver.PortNo = m_Node->Attribute("PortNo");
	Timeserver.GroupNum = m_Node->Attribute("GroupNum");
	Timeserver.GroupIp1 = m_Node->Attribute("GroupIp1");
	Timeserver.GroupIp2 = m_Node->Attribute("GroupIp2");
	Timeserver.GroupIp3 = m_Node->Attribute("GroupIp3");
	Timeserver.Interval = m_Node->Attribute("Interval");
	Child = m_Node->FirstChildElement("TimeMode");
	m_text = Child->FirstChild()->ToText();
	Timeserver.TimeMode = m_text->Value();
	return DO_OK;
}
int XML::UpdateTimeService(TimeServer&Timeserver)
{
	TiXmlElement *m_Node;
	TiXmlElement *Child;
	TiXmlText *m_text;
	m_Node = root->FirstChildElement("CLIENT")->FirstChildElement("TimeService");
	if (m_Node == NULL)
	{
		return DO_FAIL;
	}
	m_Node->SetAttribute("Mode", Timeserver.Mode.toStdString().data());
	m_Node->SetAttribute("PortNo", Timeserver.PortNo.toStdString().data());
	m_Node->SetAttribute("GroupNum", Timeserver.GroupNum.toStdString().data());
	m_Node->SetAttribute("GroupIp1", Timeserver.GroupIp1.toStdString().data());
	m_Node->SetAttribute("GroupIp2", Timeserver.GroupIp2.toStdString().data());
	m_Node->SetAttribute("GroupIp3", Timeserver.GroupIp3.toStdString().data());
	m_Node->SetAttribute("Interval", Timeserver.Interval.toStdString().data());
	Child = m_Node->FirstChildElement("TimeMode");
	m_text = Child->FirstChild()->ToText();
	m_text->SetValue(Timeserver.TimeMode.toStdString().data());
	return DO_OK;
}
void XML::Init_Map()
{
	TiXmlElement *m_Node = NULL;
	TiXmlElement *Child = NULL;
	TiXmlElement *Item = NULL;
	TiXmlElement *m_BI = NULL;
	TiXmlElement *m_CI = NULL;
	TiXmlElement *m_BO = NULL;
	TiXmlElement *m_AI = NULL;
	TiXmlElement *m_SG = NULL;
	TiXmlText *m_text = NULL;
	const char* chr;
	AI_MAP.clear();
	BI_MAP.clear();
	CI_MAP.clear();
	BO_MAP.clear();
	for (m_Node = root->FirstChildElement("IED"); m_Node != NULL; m_Node = m_Node->NextSiblingElement("IED"))
	{
		m_BI = m_Node->FirstChildElement("BI");
		if (m_BI != NULL)
		{
			for (Item = m_BI->FirstChildElement(); Item != NULL; Item = Item->NextSiblingElement())
			{
				QString index;
				chr = m_Node->Attribute("Address");
				index += chr;
				index += "_";
				Child = Item->FirstChildElement("DataNo");
				chr = Child->FirstChild()->ToText()->Value();
				index += chr;
				BI_MAP.insert(index, Item);
			}
		}

		m_CI = m_Node->FirstChildElement("CI");
		if (m_CI != NULL)
		{
			for (Item = m_BI->FirstChildElement(); Item != NULL; Item = Item->NextSiblingElement())
			{
				QString index;
				chr = m_Node->Attribute("Address");
				index += chr;
				index += "_";
				Child = Item->FirstChildElement("DataNo");
				chr = Child->FirstChild()->ToText()->Value();
				index += chr;
				CI_MAP.insert(index, Item);
			}
		}

		m_BO = m_Node->FirstChildElement("BO");
		if (m_BO != NULL)
		{
			for (Item = m_BO->FirstChildElement(); Item != NULL; Item = Item->NextSiblingElement())
			{
				QString index;
				chr = m_Node->Attribute("Address");
				index += chr;
				index += "_";
				Child = Item->FirstChildElement("DataNo");
				chr = Child->FirstChild()->ToText()->Value();
				index += chr;
				BO_MAP.insert(index, Item);
			}
		}

		m_AI = m_Node->FirstChildElement("AI");
		if (m_AI != NULL)
		{
			for (Item = m_AI->FirstChildElement(); Item != NULL; Item = Item->NextSiblingElement())
			{
				QString index;
				chr = m_Node->Attribute("Address");
				index += chr;
				index += "_";
				Child = Item->FirstChildElement("DataNo");
				chr = Child->FirstChild()->ToText()->Value();
				index += chr;
				AI_MAP.insert(index, Item);
			}
		}

		m_SG = m_Node->FirstChildElement("SG");
		if (m_SG != NULL)
		{
			for (Item = m_SG->FirstChildElement(); Item != NULL; Item = Item->NextSiblingElement())
			{
				QString index;
				chr = m_Node->Attribute("Address");
				index += chr;
				index += "_";
				Child = Item->FirstChildElement("DataNo");
				chr = Child->FirstChild()->ToText()->Value();
				index += chr;
				SG_MAP.insert(index, Item);
			}
		}

	}
}
void XML::DelOneItem(QString Dev, QString index, int state)
{
	TiXmlElement *m_Node;;
	switch (state) {
	case YX_TYPE:
		if (BI_MAP.value(Dev + "_" + index)==NULL)
		{
			return;
		}
		m_Node = BI_MAP.value(Dev + "_" + index)->Parent()->ToElement();
		if (m_Node == NULL)
		{
			return;
		}
		m_Node->RemoveChild(BI_MAP.value(Dev + "_" + index));
		break;
	case YC_TYPE:
		if (AI_MAP.value(Dev + "_" + index)== NULL)
		{
			return;
		}
		m_Node = AI_MAP.value(Dev + "_" + index)->Parent()->ToElement();
		if (m_Node == NULL)
		{
			return;
		}
		m_Node->RemoveChild(AI_MAP.value(Dev + "_" + index));
		break;
	case KWH_TYPE:
		if (CI_MAP.value(Dev + "_" + index)== NULL)
		{
			return;
		}
		m_Node = CI_MAP.value(Dev + "_" + index)->Parent()->ToElement();
		if (m_Node == NULL)
		{
			return;
		}
		m_Node->RemoveChild(CI_MAP.value(Dev + "_" + index));
		break;
	case YK_TYPE:
		if (BO_MAP.value(Dev + "_" + index)== NULL)
		{
			return;
		}
		m_Node = BO_MAP.value(Dev + "_" + index)->Parent()->ToElement();
		if (m_Node == NULL)
		{
			return;
		}
		m_Node->RemoveChild(BO_MAP.value(Dev + "_" + index));
		break;
	case SG_TYPE:
		if (SG_MAP.value(Dev + "_" + index)== NULL)
		{
			return;
		}
		m_Node = SG_MAP.value(Dev + "_" + index)->Parent()->ToElement();
		if (m_Node == NULL)
		{
			return;
		}
		m_Node->RemoveChild(SG_MAP.value(Dev + "_" + index));
		break;
	default:
		break;
	}
}
