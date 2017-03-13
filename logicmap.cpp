#include "logicmap.h"
#include "ui_logicmap.h"

inline QString BIG2UTF8(const QString &inStr)
{
	QTextCodec *gbk = QTextCodec::codecForName("BIG5");
	QTextCodec *utf8 = QTextCodec::codecForName("UTF-8");

	QString g2u = utf8->toUnicode(gbk->fromUnicode(inStr));              // gbk  convert utf8  
	return g2u;
}
char* G2U(const char* gb2312)
{
	int len = MultiByteToWideChar(CP_ACP, 0, gb2312, -1, NULL, 0);
	wchar_t* wstr = new wchar_t[len + 1];
	memset(wstr, 0, len + 1);
	MultiByteToWideChar(CP_ACP, 0, gb2312, -1, wstr, len);
	len = WideCharToMultiByte(CP_UTF8, 0, wstr, -1, NULL, 0, NULL, NULL);
	char* str = new char[len + 1];
	memset(str, 0, len + 1);
	WideCharToMultiByte(CP_UTF8, 0, wstr, -1, str, len, NULL, NULL);
	if (wstr) delete[] wstr;
	return str;
}
LogicMap::LogicMap(QWidget *parent) :
QDialog(parent),
ui(new Ui::LogicMap)
{
	ui->setupUi(this);
	m_ModelDEV = new QStandardItemModel;
	m_ModelIED = new QStandardItemModel;
	m_ModelMAP = new QStandardItemModel;
	Point_MAP = new XML();
	GetDeviceList();
	Init_dlg();
	Inittableview_dev(0);
	Initcombox_type();
	Initcombox_IEDtype();
	Save_flag = true;
	connect(ui->radioButton_new, SIGNAL(clicked(bool)), this, SLOT(radioButton_new_clicked()));
	connect(ui->radioButton_browse, SIGNAL(clicked(bool)), this, SLOT(radioButton_browse_clicked()));
	connect(ui->pushButton_browse, SIGNAL(clicked(bool)), this, SLOT(pushbutton_browse()));
	connect(ui->pushButton_open, SIGNAL(clicked(bool)), this, SLOT(pushbutton_DB()));
	connect(ui->pushButton_save, SIGNAL(clicked(bool)), this, SLOT(pushbutton_save()));
	connect(ui->comboBox_dev, SIGNAL(activated(QString)), this, SLOT(comboxe_dev_change(QString)));
	connect(ui->comboBox_ied, SIGNAL(activated(QString)), this, SLOT(comboxe_ied_change(QString)));
	connect(ui->comboBox_ld, SIGNAL(activated(QString)), this, SLOT(comboxe_ld_change(QString)));
	connect(ui->comboBox_type, SIGNAL(activated(QString)), this, SLOT(comboxe_type_change(QString)));
	connect(ui->comboBox_IED_Type, SIGNAL(activated(QString)), this, SLOT(comboxe_Iedtype_change(QString)));
	// connect(ui->comboBox_IED_Type, SIGNAL(activated(QString)), this, SLOT(comboxe_Iedtype_change(QString)));
	connect(ui->pushButton_Config, SIGNAL(clicked(bool)), this, SLOT(pushbutton_station()));
	connect(ui->dropTable, SIGNAL(senddragMoveEvent(QDropEvent*)), this, SLOT(receivedragEnterEvent(QDropEvent*)));
	connect(ui->pushButton_Apply, SIGNAL(clicked(bool)), this, SLOT(pushbutton_apply()));
	connect(ui->pushButton_Clear, SIGNAL(clicked(bool)), this, SLOT(pushbutton_Del()));
	connect(ui->pushButton_Del, SIGNAL(clicked(bool)), this, SLOT(pushbutton_clear()));

    ui->radioButton_new->clicked(true);
	ui->pushButton_open->setEnabled(false);
}

LogicMap::~LogicMap()
{
	delete ui;
}
void LogicMap::Init_dlg()
{
	ui->label_MAP->setText(tr("MAP File:"));
	ui->label_DB->setText(tr("DB File:"));
	ui->label_dev->setText(tr("Device"));
	ui->label_IED->setText(tr("IED"));
	ui->label_ld->setText(tr("LDevice"));
	ui->label_type->setText(tr("Type"));
	ui->radioButton_new->setText(tr("New"));
	ui->radioButton_browse->setText(tr("Load"));
	ui->radioButton_new->setChecked(true);
	ui->pushButton_browse->setText(tr("Browse"));
	ui->pushButton_open->setText(tr("Open"));
	ui->pushButton_save->setText(tr("Save"));
	ui->label_IED_Type->setText(tr("IED Type"));
	ui->pushButton_Config->setText(tr("Station Para"));
	ui->pushButton_Apply->setText(tr("Apply"));
	ui->dropTable->setEnabled(false);
	ui->comboBox_dev->setEnabled(false);
	ui->comboBox_ied->setEnabled(false);
	ui->pushButton_Apply->setEnabled(false);
	ui->pushButton_Clear->setEnabled(false);
	ui->pushButton_Config->setEnabled(false);
	ui->pushButton_save->setEnabled(false);
	ui->pushButton_Clear->setText(tr("RM IED"));
    ui->pushButton_Del->setText(tr("Del item"));
	ui->splitter->setStretchFactor(0, 50);
	ui->splitter->setStretchFactor(1, 50);
	ui->treeWidget->setDragDropMode(QAbstractItemView::DragOnly);
	ui->treeWidget->setSelectionMode(QAbstractItemView::ExtendedSelection);
	//Inittableview_dev(0);

}
void LogicMap::radioButton_new_clicked()
{
	ui->pushButton_browse->setText(tr("New"));
	Creat_flag = 1;

}

void LogicMap::radioButton_browse_clicked()
{
	ui->pushButton_browse->setText(tr("Load"));
	Creat_flag = 2;

}
void LogicMap::pushbutton_DB()
{

	QString fileName = QFileDialog::getOpenFileName(this,
		tr("Open DB"),
		QDir::currentPath(),
		tr("DB Files (*.DB)"));
	if (!fileName.isNull())
	{
		ui->lineEdit_DB->setText(fileName);
		file_db = fileName;
		int recode;
		recode = Init_DB(fileName);
		if (recode == DO_FAIL)
		{
			ui->comboBox_dev->setEnabled(false);
			ui->dropTable->setEnabled(false);
			ui->comboBox_dev->setEnabled(false);
			ui->comboBox_ied->setEnabled(false);
			ui->pushButton_Apply->setEnabled(false);
			ui->pushButton_Clear->setEnabled(false);
			ui->pushButton_Config->setEnabled(false);
			ui->pushButton_save->setEnabled(false);
			return;
		}
		Init_combox_dev();
		ui->comboBox_dev->setEnabled(true);
		ui->comboBox_dev->activated(ui->comboBox_dev->currentText());
		ui->comboBox_type->activated(ui->comboBox_type->currentIndex());
		ui->dropTable->setEnabled(true);
		ui->comboBox_dev->setEnabled(true);
		ui->comboBox_ied->setEnabled(true);
		ui->pushButton_Apply->setEnabled(true);
		ui->pushButton_Clear->setEnabled(true);
		ui->pushButton_Config->setEnabled(true);
		ui->pushButton_save->setEnabled(true);
	}
}

void LogicMap::pushbutton_browse()
{
	if (Save_flag == false)
	{
		QMessageBox msgBox;
		msgBox.setText("The MAP file has not been saved");
		msgBox.setInformativeText("Do you want to save your changes?");
		msgBox.setStandardButtons(QMessageBox::Save | QMessageBox::Discard | QMessageBox::Cancel);
		msgBox.setDefaultButton(QMessageBox::Save);
		int ret = msgBox.exec();
		if (ret == QMessageBox::Save)
		{
			ui->pushButton_save->clicked();
			return;
		}
	}
	if (Creat_flag == 1)
	{

		Point_MAP->CreatXML(1);
		ui->comboBox_ied->setEnabled(true);
		ui->dropTable->setEnabled(true);
		ui->pushButton_open->setEnabled(true);
	}
	else if (Creat_flag == 2)
	{
		QString fileName = QFileDialog::getOpenFileName(this,
			tr("Open XML"),
			QDir::currentPath(),
            tr("XML Files (*.xml)"));
		if (!fileName.isNull())
		{
			ui->lineEdit_MAP->setText(fileName);
			Point_MAP = new XML();
			file_map = fileName;
			if (Point_MAP->LoadXML(fileName, 1) == DO_OK)
			{
				ui->comboBox_ied->setEnabled(true);
				ui->dropTable->setEnabled(true);
				ui->pushButton_open->setEnabled(true);
			}
			else
			{
				ui->comboBox_ied->setEnabled(false);
				ui->dropTable->setEnabled(false);
				ui->pushButton_open->setEnabled(false);
			}

		}
	}


	return;
}

void LogicMap::pushbutton_save()
{
	if (file_map.isEmpty())
	{
		QString fileName = QFileDialog::getSaveFileName(this,
			tr("Open XML"),
			"",
            tr("XML Files (*.xml)"));
		if (!fileName.isNull())
		{
			Point_MAP->SaveXML(fileName);
			file_map = fileName;
			ui->lineEdit_MAP->setText(fileName);
			Save_flag = true;
		}
	}
	else
	{
		Point_MAP->SaveXML(file_map);
        QMessageBox::about(0, QObject::tr("Notice"), QObject::tr("Save file success"));

		Save_flag = true;
	}
	//	if (Creat_flag==false)
	//	{
	//		if (!file_map.isNull())
	//		{
	//			Point_MAP->SaveSCD(file_map);
	//		}
	//		else
	//		{
	//			return;
	//		}
	//	}
	//else
	//{
	//	QString fileName = QFileDialog::getSaveFileName(this,
	//		tr("Open SCD"),
	//		"",
	//		tr("SCD Files (*.SCD)"));
	//	if (!fileName.isNull())
	//	{
	//		Point_MAP->SaveSCD(fileName);
	//		file_map = fileName;
	//	}
	//	else
	//	{
	//		return;
	//	}
	//}
	//


}

void LogicMap::comboxe_dev_change(QString index)
{
	QString strType;
	strType = ui->comboBox_type->currentText();
	if (file_db.isEmpty())
		return;

	if (strType == tr("YX"))
	{
		//Initcombox_dev(YX_TYPE);
		DisplayDev(YX_TYPE);
	}
	else 	if (strType == tr("YC"))
	{
		//Initcombox_dev(YC_TYPE);
		DisplayDev(YC_TYPE);
	}
	else 	if (strType == tr("KWH"))
	{
		//Initcombox_dev(KWH_TYPE);
		DisplayDev(KWH_TYPE);
	}
	else 	if (strType == tr("YK"))
	{
		//Initcombox_dev(YK_TYPE);
		DisplayDev(YK_TYPE);
	}
	else 	if (strType == tr("SG"))
	{
		//Initcombox_dev(YK_TYPE);
		DisplayDev(SG_TYPE);
	}
}

void LogicMap::comboxe_type_change(QString index)
{
	if (file_db.isEmpty())
		return;
	if (index == tr("YX"))
	{
		//Initcombox_dev(YX_TYPE);
		State_Type = YX_TYPE;
		DisplayDev(YX_TYPE);
	}
	else 	if (index == tr("YC"))
	{
		//Initcombox_dev(YC_TYPE);
		State_Type = YC_TYPE;
		DisplayDev(YC_TYPE);
	}
	else 	if (index == tr("KWH"))
	{
		//Initcombox_dev(KWH_TYPE);
		State_Type = KWH_TYPE;
		DisplayDev(KWH_TYPE);
	}
	else 	if (index == tr("YK"))
	{
		//Initcombox_dev(YK_TYPE);
		State_Type = YK_TYPE;
		DisplayDev(YK_TYPE);
	}
	else 	if (index == tr("SG"))
	{
		//Initcombox_dev(YK_TYPE);
		State_Type = SG_TYPE;
		DisplayDev(SG_TYPE);
	}
}

void LogicMap::comboxe_ied_change(QString index)
{
	Initcombox_LD(index);
	ui->comboBox_ld->setCurrentIndex(0);
	ui->comboBox_ld->activated(ui->comboBox_ld->currentText());
}

void LogicMap::comboxe_ld_change(QString index)
{
	DisplayDataFromLD(index);
}
void LogicMap::comboxe_Iedtype_change(QString index)
{

}


int LogicMap::Init_DB(QString filename)
{

	Model_List.clear();



	int rc = sqlite3_open(filename.toUtf8().data(), &db);
	if (rc)
	{
		QMessageBox::warning(0, QObject::tr("The Database Can not open"), QObject::tr(sqlite3_errmsg(db)));
		sqlite3_close(db);
		return DO_FAIL;
	}
	QString sSql = tr("select * from RTU_EquipPara order by ComGroupNo");
	rc = sqlite3_prepare(db, sSql.toLocal8Bit().data(), -1, &stmt, 0);
	rc = sqlite3_step(stmt);
	while (rc == SQLITE_ROW)
	{
		Model_Struct m_model;
		char chr[64];
		memset(chr, 0, RTUMT_DESC_MAXLEN);
		memcpy(chr, sqlite3_column_text(stmt, 1), 64);
		m_model.Model_Name += chr;
		memcpy(chr, sqlite3_column_text(stmt, 0), 64);
		m_model.Model_No += chr;
		rc = sqlite3_step(stmt);
		Model_List.append(m_model);
	}
	for (int i = 0; i < Model_List.size(); i++)
	{
		QString sSqlyx = tr("select * from RTU_Status where UnitName = '%1' order by IndexNo ").arg(Model_List[i].Model_Name);
		rc = sqlite3_prepare(db, sSqlyx.toLocal8Bit().data(), -1, &stmt, 0);
		rc = sqlite3_step(stmt);
		while (rc == SQLITE_ROW)
		{
			YX_Struct m_Yx;
			char chr[64];
			memcpy(chr, sqlite3_column_text(stmt, 0), 64);
			m_Yx.YX_Name += chr;
			memcpy(m_Yx.YX_Desc, sqlite3_column_text(stmt, 1), 64);
			memcpy(chr, sqlite3_column_text(stmt, 6), 64);
			m_Yx.YX_No += chr;
			rc = sqlite3_step(stmt);
			Model_List[i].YX_List.append(m_Yx);
		}
		QString sSqlyc = tr("select * from RTU_Analog where UnitName = '%1' order by IndexNo ").arg(Model_List[i].Model_Name);
		rc = sqlite3_prepare(db, sSqlyc.toLocal8Bit().data(), -1, &stmt, 0);
		rc = sqlite3_step(stmt);
		while (rc == SQLITE_ROW)
		{
			YC_Struct m_Yc;
			char chr[64];
			memcpy(chr, sqlite3_column_text(stmt, 0), 64);
			m_Yc.YC_Name += chr;
			memcpy(m_Yc.YC_Desc, sqlite3_column_text(stmt, 1), 64);
			memcpy(chr, sqlite3_column_text(stmt, 6), 64);
			m_Yc.YC_No += chr;
			rc = sqlite3_step(stmt);
			Model_List[i].YC_List.append(m_Yc);
		}
		QString sSqlkwh = tr("select * from RTU_Kwh where UnitName = '%1' order by IndexNo ").arg(Model_List[i].Model_Name);
		rc = sqlite3_prepare(db, sSqlkwh.toLocal8Bit().data(), -1, &stmt, 0);
		rc = sqlite3_step(stmt);
		while (rc == SQLITE_ROW)
		{
			KWH_Struct m_Kwh;
			char chr[64];
			memcpy(chr, sqlite3_column_text(stmt, 0), 64);
			m_Kwh.KWH_Name += chr;
			memcpy(m_Kwh.KWH_Desc, sqlite3_column_text(stmt, 1), 64);
			memcpy(chr, sqlite3_column_text(stmt, 6), 64);
			m_Kwh.KWH_No += chr;
			rc = sqlite3_step(stmt);
			Model_List[i].KWH_List.append(m_Kwh);
		}
		QString sSqlyk = tr("select * from RTU_YkV2 where UnitName = '%1' order by IndexNo ").arg(Model_List[i].Model_Name);
		rc = sqlite3_prepare(db, sSqlyk.toLocal8Bit().data(), -1, &stmt, 0);
		rc = sqlite3_step(stmt);
		while (rc == SQLITE_ROW)
		{
			YK_Struct m_Yk;
			char chr[64];
			memcpy(chr, sqlite3_column_text(stmt, 9), 64);
			m_Yk.YK_Name += chr;
			memcpy(m_Yk.YK_Desc, sqlite3_column_text(stmt, 10), 64);
			memcpy(chr, sqlite3_column_text(stmt, 4), 64);
			m_Yk.YK_No += chr;
			rc = sqlite3_step(stmt);
			Model_List[i].YK_List.append(m_Yk);
		}
		QString sSqlsg = tr("select * from RTU_Setting where UnitName='%1' order by IFNO").arg(Model_List[i].Model_Name);
		rc = sqlite3_prepare(db, sSqlsg.toLocal8Bit().data(), -1, &stmt, 0);
		rc = sqlite3_step(stmt);
		while (rc == SQLITE_ROW)
		{
			SG_Struct m_SG;
			char chr[64];
			memcpy(chr, sqlite3_column_text(stmt, 1), 64);
			m_SG.SG_Name += chr;
			memcpy(m_SG.SG_Desc, sqlite3_column_text(stmt, 2), 64);
			memcpy(chr, sqlite3_column_text(stmt, 0), 64);
			m_SG.SG_No += chr;
			rc = sqlite3_step(stmt);
			Model_List[i].SG_List.append(m_SG);
		}
	}
	sqlite3_close(db);
	return DO_OK;
	//for (int i = 0; i < Model_List.size(); i++)
	//{
	//	QString sSqlyx = tr("select * from RTU_Status where UnitName = '%1' order by IndexNo ").arg(Model_List[i].Model_Name);
	//	m_Sql->exec(sSqlyx);
	//	while (m_Sql->next())
	//	{
	//		YX_Struct m_Yx;
	//		QString str= m_Sql->value("Description").toString();
	//		m_Yx.YX_Name = m_Sql->value("Name").toString();
	//		m_Yx.YX_Desc = BIG2UTF8(str.toLocal8Bit().data());
	//		//m_Yx.YX_Desc = QString::fromUtf8(m_Sql->value("Description").toByteArray().data());
	//		m_Yx.YX_No = m_Sql->value("IndexNo").toString();

	//		Model_List[i].YX_List.append(m_Yx);
	//	}
	//	QString sSqlyc = tr("select * from RTU_Analog  where UnitName = '%1' order by IndexNo").arg(Model_List[i].Model_Name);
	//	m_Sql->exec(sSqlyc);
	//	while (m_Sql->next())
	//	{
	//		YC_Struct m_Yc;
	//		m_Yc.YC_Name = m_Sql->value("Name").toString();
	//		m_Yc.YC_Desc += G2U(m_Sql->value("Description").toByteArray().data());
	//		m_Yc.YC_No = m_Sql->value("IndexNo").toString();

	//		Model_List[i].YC_List.append(m_Yc);
	//	}
	//	QString sSqldd = tr("select * from RTU_Kwh where UnitName = '%1' order by IndexNo").arg(Model_List[i].Model_Name);
	//	m_Sql->exec(sSqldd);
	//	while (m_Sql->next())
	//	{
	//		KWH_Struct m_Kwh;
	//		m_Kwh.KWH_Name = m_Sql->value("Name").toString();
	//		m_Kwh.KWH_Desc += G2U(m_Sql->value("Description").toByteArray().data());
	//		m_Kwh.KWH_No = m_Sql->value("IndexNo").toString();

	//		Model_List[i].KWH_List.append(m_Kwh);
	//	}
	//	QString sSqlyk = tr("select * from RTU_YkV2  where UnitName = '%1' order by IndexNo").arg(Model_List[i].Model_Name);
	//	m_Sql->exec(sSqlyk);
	//	while (m_Sql->next())
	//	{
	//		YK_Struct m_Yk;
	//		m_Yk.YK_Name = m_Sql->value("YKName").toString();
	//		m_Yk.YK_Desc = G2U(m_Sql->value("YKDesc").toByteArray().data());
	//		m_Yk.YK_No = m_Sql->value("IndexNo").toString();

	//		Model_List[i].YK_List.append(m_Yk);
	//	}
	//}
}
void LogicMap::Inittableview_dev(int type)
{
	if (type == YX_TYPE)
	{
		headerList.clear();
		headerList << tr("Name") << tr("Desc") << tr("Index") << tr("InstAddr") << tr("stVal") << tr("q") << tr("t") << tr("TrigOsc");


		ui->dropTable->setSelectionBehavior(QAbstractItemView::SelectRows); //
		m_ModelDEV->clear();
		m_ModelDEV->setColumnCount(headerList.count());

		ui->dropTable->setModel(m_ModelDEV);
		for (int i = 0; i < headerList.count(); i++)
		{
			m_ModelDEV->setHeaderData(i, Qt::Horizontal, headerList.at(i));

		}
		for (int i = 0; i < headerList.size(); i++)
		{
			ui->dropTable->setItemDelegateForColumn(i, ui->dropTable->itemDelegateForColumn(0));
		}
		YES_NOCombox* m_boolBox = new YES_NOCombox(this);
		ui->dropTable->setItemDelegateForColumn(4, m_boolBox);
		ui->dropTable->setItemDelegateForColumn(5, m_boolBox);
		ui->dropTable->setItemDelegateForColumn(6, m_boolBox);
		ui->dropTable->setItemDelegateForColumn(7, m_boolBox);
		//for (int i = 0; i < headerList.size(); i++)
		//{
		//	ui->dropTable->setItemDelegateForColumn(i, ui->dropTable->itemDelegateForColumn(0));
		//}

		ui->dropTable->setColumnWidth(0, 100);
		ui->dropTable->setColumnWidth(1, 150);
		ui->dropTable->setColumnWidth(2, 50);
		ui->dropTable->setColumnWidth(3, 200);
		return;
	}
	if ((type == YC_TYPE) || (type == KWH_TYPE))
	{
		headerList.clear();
		headerList << tr("Name") << tr("Desc") << tr("Index") << tr("InstAddr");


		ui->dropTable->setSelectionBehavior(QAbstractItemView::SelectRows); //
		//ui->tableView->setSelectionMode(QAbstractItemView::SingleSelection); //设置选择模式，选择单行
		m_ModelDEV->clear();
		m_ModelDEV->setColumnCount(headerList.count());

		ui->dropTable->setModel(m_ModelDEV);
		for (int i = 0; i < headerList.count(); i++)
		{
			m_ModelDEV->setHeaderData(i, Qt::Horizontal, headerList.at(i));

		}
		for (int i = 0; i < headerList.size(); i++)
		{
			ui->dropTable->setItemDelegateForColumn(i, ui->dropTable->itemDelegateForColumn(0));
		}
		ui->dropTable->setColumnWidth(0, 100);
		ui->dropTable->setColumnWidth(1, 150);
		ui->dropTable->setColumnWidth(2, 50);
		ui->dropTable->setColumnWidth(3, 200);
		return;
	}
	if (type == YK_TYPE)
	{
		headerList.clear();
		headerList << tr("Name") << tr("Desc") << tr("Index") << tr("InstAddr") << tr("ctModel");


		ui->dropTable->setSelectionBehavior(QAbstractItemView::SelectRows); //
		m_ModelDEV->clear();
		m_ModelDEV->setColumnCount(headerList.count());
		for (int i = 0; i < headerList.size(); i++)
		{
			ui->dropTable->setItemDelegateForColumn(i, ui->dropTable->itemDelegateForColumn(0));
		}
		CtModelBox *CtmodeCombox = new CtModelBox(this);
		ui->dropTable->setItemDelegateForColumn(4, CtmodeCombox);
		ui->dropTable->setModel(m_ModelDEV);
		for (int i = 0; i < headerList.count(); i++)
		{

			m_ModelDEV->setHeaderData(i, Qt::Horizontal, headerList.at(i));

		}
		ui->dropTable->setColumnWidth(0, 100);
		ui->dropTable->setColumnWidth(1, 150);
		ui->dropTable->setColumnWidth(2, 50);
		ui->dropTable->setColumnWidth(3, 200);
		ui->dropTable->setColumnWidth(4, 200);
		return;
	}
	if (type == SG_TYPE)
	{
		headerList.clear();
		headerList << tr("Name") << tr("Desc") << tr("Index") << tr("InstAddr");


		ui->dropTable->setSelectionBehavior(QAbstractItemView::SelectRows); //
		m_ModelDEV->clear();
		m_ModelDEV->setColumnCount(headerList.count());
		for (int i = 0; i < headerList.size(); i++)
		{
			ui->dropTable->setItemDelegateForColumn(i, ui->dropTable->itemDelegateForColumn(0));
		}
		ui->dropTable->setModel(m_ModelDEV);
		for (int i = 0; i < headerList.count(); i++)
		{

			m_ModelDEV->setHeaderData(i, Qt::Horizontal, headerList.at(i));

		}
		ui->dropTable->setColumnWidth(0, 100);
		ui->dropTable->setColumnWidth(1, 150);
		ui->dropTable->setColumnWidth(2, 50);
		ui->dropTable->setColumnWidth(3, 200);
		return;
	}

}
void LogicMap::DisplayDev(int type)
{

	Model_Struct m_model;
	Model_XML m_ModelXML;
	QString strname;
	strname = ui->comboBox_dev->currentText();
	for (int i = 0; i < Model_List.size(); i++)
	{
		if (strname == Model_List[i].Model_Name)
		{
			m_model = Model_List[i];
			break;
		}
	}
	Point_MAP->GetOneIED(m_ModelXML, m_model.Model_No);
	if (m_ModelXML.Type.isEmpty())
	{
		ui->comboBox_IED_Type->setCurrentIndex(-1);
	}
	else
	{
		ui->comboBox_IED_Type->setCurrentText(m_ModelXML.Type);
		ui->comboBox_ied->activated(m_ModelXML.Name);
	}
	Model_CUR = m_ModelXML;
	switch (type)
	{
	case  YX_TYPE:
		Inittableview_dev(YX_TYPE);
		DisplayYX(m_model.YX_List, m_ModelXML.BI_List);

		break;
	case  YC_TYPE:
		Inittableview_dev(YC_TYPE);
		DisplayYC(m_model.YC_List, m_ModelXML.AI_List);
		break;
	case  KWH_TYPE:
		Inittableview_dev(KWH_TYPE);
		DisplayKWH(m_model.KWH_List, m_ModelXML.CI_List);
		break;
	case  YK_TYPE:
		Inittableview_dev(YK_TYPE);
		DisplayYK(m_model.YK_List, m_ModelXML.BO_List);
		break;
	case  SG_TYPE:
		Inittableview_dev(SG_TYPE);
		DisplaySG(m_model.SG_List, m_ModelXML.SG_List);
		break;
	default:
		break;
	}
}
void LogicMap::DisplayYX(QVector<YX_Struct>&List, QVector<BI_struct>&XMLList)
{
	disconnect(m_ModelDEV, SIGNAL(dataChanged(const QModelIndex &, const QModelIndex &)), this, SLOT(OnDataChanged(const QModelIndex &, const QModelIndex &)));

	m_ModelDEV->setRowCount(0);
	for (int i = 0; i < List.size(); i++)
	{
		m_ModelDEV->setRowCount(i + 1);
		m_ModelDEV->setData(m_ModelDEV->index(i, 0), List[i].YX_Name);
		m_ModelDEV->setData(m_ModelDEV->index(i, 1), QVariant(QString::fromLocal8Bit(List[i].YX_Desc)));
		m_ModelDEV->setData(m_ModelDEV->index(i, 2), List[i].YX_No);
		for (int m = 0; m < XMLList.size(); m++)
		{
			if (XMLList[m].DataNo == List[i].YX_No)
			{
				m_ModelDEV->setData(m_ModelDEV->index(i, 3), XMLList[m].Name);
				m_ModelDEV->setData(m_ModelDEV->index(i, 4), XMLList[m].stVal);
				m_ModelDEV->setData(m_ModelDEV->index(i, 5), XMLList[m].q);
				m_ModelDEV->setData(m_ModelDEV->index(i, 6), XMLList[m].t);
				m_ModelDEV->setData(m_ModelDEV->index(i, 7), XMLList[m].TrigOsc);

				break;
			}


		}

		m_ModelDEV->item(i, 0)->setFlags(Qt::ItemIsSelectable | Qt::ItemIsEnabled);
		m_ModelDEV->item(i, 1)->setFlags(Qt::ItemIsSelectable | Qt::ItemIsEnabled);
		m_ModelDEV->item(i, 2)->setFlags(Qt::ItemIsSelectable | Qt::ItemIsEnabled);


	}

	connect(m_ModelDEV, SIGNAL(dataChanged(const QModelIndex &, const QModelIndex &)), this, SLOT(OnDataChanged(const QModelIndex &, const QModelIndex &)));

}
void LogicMap::DisplayYC(QVector<YC_Struct>&List, QVector<AI_struct>&XMLList)
{
	disconnect(m_ModelDEV, SIGNAL(dataChanged(const QModelIndex &, const QModelIndex &)), this, SLOT(OnDataChanged(const QModelIndex &, const QModelIndex &)));

	m_ModelDEV->setRowCount(0);
	for (int i = 0; i < List.size(); i++)
	{
		m_ModelDEV->setRowCount(i + 1);
		m_ModelDEV->setData(m_ModelDEV->index(i, 0), List[i].YC_Name);
		m_ModelDEV->setData(m_ModelDEV->index(i, 1), QVariant(QString::fromLocal8Bit(List[i].YC_Desc)));
		m_ModelDEV->setData(m_ModelDEV->index(i, 2), List[i].YC_No);
		for (int m = 0; m < XMLList.size(); m++)
		{
			if (XMLList[m].DataNo == List[i].YC_No)
			{
				m_ModelDEV->setData(m_ModelDEV->index(i, 3), XMLList[m].Name);
				break;
			}



		}
		m_ModelDEV->item(i, 0)->setFlags(Qt::ItemIsSelectable | Qt::ItemIsEnabled);
		m_ModelDEV->item(i, 1)->setFlags(Qt::ItemIsSelectable | Qt::ItemIsEnabled);
		m_ModelDEV->item(i, 2)->setFlags(Qt::ItemIsSelectable | Qt::ItemIsEnabled);


	}
	connect(m_ModelDEV, SIGNAL(dataChanged(const QModelIndex &, const QModelIndex &)), this, SLOT(OnDataChanged(const QModelIndex &, const QModelIndex &)));

}
void LogicMap::DisplayKWH(QVector<KWH_Struct>&List, QVector<CI_struct>&XMLList)
{
	disconnect(m_ModelDEV, SIGNAL(dataChanged(const QModelIndex &, const QModelIndex &)), this, SLOT(OnDataChanged(const QModelIndex &, const QModelIndex &)));

	m_ModelDEV->setRowCount(0);
	for (int i = 0; i < List.size(); i++)
	{
		m_ModelDEV->setRowCount(i + 1);
		m_ModelDEV->setData(m_ModelDEV->index(i, 0), List[i].KWH_Name);
		m_ModelDEV->setData(m_ModelDEV->index(i, 1), QVariant(QString::fromLocal8Bit(List[i].KWH_Desc)));
		m_ModelDEV->setData(m_ModelDEV->index(i, 2), List[i].KWH_No);
		for (int m = 0; m < XMLList.size(); m++)
		{
			if (XMLList[m].DataNo == List[i].KWH_No)
			{
				m_ModelDEV->setData(m_ModelDEV->index(i, 3), XMLList[m].Name);
				break;
			}

		}
		m_ModelDEV->item(i, 0)->setFlags(Qt::ItemIsSelectable | Qt::ItemIsEnabled);
		m_ModelDEV->item(i, 1)->setFlags(Qt::ItemIsSelectable | Qt::ItemIsEnabled);
		m_ModelDEV->item(i, 2)->setFlags(Qt::ItemIsSelectable | Qt::ItemIsEnabled);


	}
	connect(m_ModelDEV, SIGNAL(dataChanged(const QModelIndex &, const QModelIndex &)), this, SLOT(OnDataChanged(const QModelIndex &, const QModelIndex &)));

}
void LogicMap::DisplayYK(QVector<YK_Struct>&List, QVector<BO_struct>&XMLList)
{
	disconnect(m_ModelDEV, SIGNAL(dataChanged(const QModelIndex &, const QModelIndex &)), this, SLOT(OnDataChanged(const QModelIndex &, const QModelIndex &)));

	m_ModelDEV->setRowCount(0);
	for (int i = 0; i < List.size(); i++)
	{

		bool flag = false;
		for (int m = 0; m < m_ModelDEV->rowCount(); m++)
		{
			if (m_ModelDEV->data(m_ModelDEV->index(m, 2)).toString() == List[i].YK_No)
			{
				flag = true;
			}
		}
		if (flag == true)
			continue;
		m_ModelDEV->setRowCount(m_ModelDEV->rowCount() + 1);
		m_ModelDEV->setData(m_ModelDEV->index(m_ModelDEV->rowCount() - 1, 0), List[i].YK_Name);
		m_ModelDEV->setData(m_ModelDEV->index(m_ModelDEV->rowCount() - 1, 1), QVariant(QString::fromLocal8Bit(List[i].YK_Desc)));
		m_ModelDEV->setData(m_ModelDEV->index(m_ModelDEV->rowCount() - 1, 2), List[i].YK_No);
		for (int m = 0; m < XMLList.size(); m++)
		{
			if (XMLList[m].DataNo == List[i].YK_No)
			{
				m_ModelDEV->setData(m_ModelDEV->index(m_ModelDEV->rowCount() - 1, 3), XMLList[m].Name);
				m_ModelDEV->setData(m_ModelDEV->index(m_ModelDEV->rowCount() - 1, 4), XMLList[m].ctlModel);
				break;

			}

		}
		m_ModelDEV->item(m_ModelDEV->rowCount() - 1, 0)->setFlags(Qt::ItemIsSelectable | Qt::ItemIsEnabled);
		m_ModelDEV->item(m_ModelDEV->rowCount() - 1, 1)->setFlags(Qt::ItemIsSelectable | Qt::ItemIsEnabled);
		m_ModelDEV->item(m_ModelDEV->rowCount() - 1, 2)->setFlags(Qt::ItemIsSelectable | Qt::ItemIsEnabled);


	}
	connect(m_ModelDEV, SIGNAL(dataChanged(const QModelIndex &, const QModelIndex &)), this, SLOT(OnDataChanged(const QModelIndex &, const QModelIndex &)));

}
void LogicMap::DisplaySG(QVector<SG_Struct>&List, QVector<SG_struct>&XMLList)
{
	disconnect(m_ModelDEV, SIGNAL(dataChanged(const QModelIndex &, const QModelIndex &)), this, SLOT(OnDataChanged(const QModelIndex &, const QModelIndex &)));

	m_ModelDEV->setRowCount(0);
	for (int i = 0; i < List.size(); i++)
	{

		bool flag = false;
		for (int m = 0; m < m_ModelDEV->rowCount(); m++)
		{
			if (m_ModelDEV->data(m_ModelDEV->index(m, 2)).toString() == List[i].SG_No)
			{
				flag = true;
			}
		}
		if (flag == true)
			continue;
		m_ModelDEV->setRowCount(m_ModelDEV->rowCount() + 1);
		m_ModelDEV->setData(m_ModelDEV->index(m_ModelDEV->rowCount() - 1, 0), List[i].SG_Name);
		m_ModelDEV->setData(m_ModelDEV->index(m_ModelDEV->rowCount() - 1, 1), QVariant(QString::fromLocal8Bit(List[i].SG_Desc)));
		m_ModelDEV->setData(m_ModelDEV->index(m_ModelDEV->rowCount() - 1, 2), List[i].SG_No);
		for (int m = 0; m < XMLList.size(); m++)
		{
			if (XMLList[m].DataNo == List[i].SG_No)
			{
				m_ModelDEV->setData(m_ModelDEV->index(m_ModelDEV->rowCount() - 1, 3), XMLList[m].Name);
				break;

			}

		}
		m_ModelDEV->item(m_ModelDEV->rowCount() - 1, 0)->setFlags(Qt::ItemIsSelectable | Qt::ItemIsEnabled);
		m_ModelDEV->item(m_ModelDEV->rowCount() - 1, 1)->setFlags(Qt::ItemIsSelectable | Qt::ItemIsEnabled);
		m_ModelDEV->item(m_ModelDEV->rowCount() - 1, 2)->setFlags(Qt::ItemIsSelectable | Qt::ItemIsEnabled);


	}
	connect(m_ModelDEV, SIGNAL(dataChanged(const QModelIndex &, const QModelIndex &)), this, SLOT(OnDataChanged(const QModelIndex &, const QModelIndex &)));

}
void LogicMap::Initcombox_type()
{
	QStringList list;
    list << tr("YX") << tr("YC") << tr("KWH") << tr("YK") << tr("SG");
	ui->comboBox_type->addItems(list);
}
void LogicMap::Initcombox_IEDtype()
{
	//QStringList list;
	for (int i = 0; i < DeviceType_List.size(); i++)
	{
		ui->comboBox_IED_Type->addItem(DeviceType_List[i].Name);
	}

}
void LogicMap::Init_combox_dev()
{
	QStringList list;
	Dev_Map.clear();
	ui->comboBox_dev->clear();
	for (int i = 0; i < Model_List.size(); i++)
	{
		QString str;
		str = Model_List[i].Model_Name;
		list.append(str);
		Dev_Map.insert(Model_List[i].Model_Name, Model_List[i].Model_No);
	}
	ui->comboBox_dev->addItems(list);
	ui->comboBox_dev->setCurrentIndex(0);
}
void LogicMap::Initcombox_ied()
{
	QVector<IEDstruct> iedlist;
	int recode = Point_SCD->GetIEDList(iedlist);
	ui->comboBox_ied->clear();
	for (int i = 0; i < iedlist.size(); i++)
	{
		ui->comboBox_ied->addItem(iedlist[i].s_IEDname);
	}
	ui->comboBox_ied->setCurrentIndex(-1);
}
void LogicMap::Initcombox_LD(QString IEDName)
{
	QStringList LDList;
	ui->comboBox_ld->clear();
	Point_SCD->GetLDeviceList(IEDName, LDList);
	ui->comboBox_ld->addItems(LDList);

}
void LogicMap::DisplayDataFromLD(QString str)
{
	headerList.clear();
	headerList << "name" << "Desc";
	ui->treeWidget->clear();
	QTreeWidgetItem *DataSetNode = ui->treeWidget->invisibleRootItem();
	DataSetNode->takeChildren();
	ui->treeWidget->setHeaderLabels(headerList);
    ui->treeWidget->setColumnWidth(0,300);
    ui->treeWidget->setColumnWidth(1,100);
	//QString str3 = ui->comboBox_type->currentText();
	//if ((ui->comboBox_type->currentText() != tr("YC")) && (ui->comboBox_type->currentText() != tr("KWH")) && (ui->comboBox_type->currentText() == tr("YK")))
	//{
	if (ui->comboBox_type->currentText() == tr("YX"))
	{
		DataSetList.clear();
		QString ied = ui->comboBox_ied->currentText();
		QString ld = ui->comboBox_ld->currentText();
		Point_SCD->GetDataSetList(ied, ld, DataSetList);
	}
	else if (ui->comboBox_type->currentText() == tr("YC"))
	{
		DataSetList.clear();
		QString ied = ui->comboBox_ied->currentText();
		QString ld = ui->comboBox_ld->currentText();
		Point_SCD->GetDataSetList(ied, ld, DataSetList, 0);

	}
	else if (ui->comboBox_type->currentText() == tr("KWH"))
	{
		DataSetList.clear();
		QString ied = ui->comboBox_ied->currentText();
		QString ld = ui->comboBox_ld->currentText();
		Point_SCD->GetDataSetList(ied, ld, DataSetList, 1);

	}
	else if (ui->comboBox_type->currentText() == tr("SG"))
	{
		DataSetList.clear();
		QString ied = ui->comboBox_ied->currentText();
		QString ld = ui->comboBox_ld->currentText();
		Point_SCD->GetSGDataList(ied, ld, DataSetList);

	}
	else if (ui->comboBox_type->currentText() == tr("YK"))
	{

		DataSetList.clear();
		QString ld = ui->comboBox_ld->currentText();
		//		 if (!ld.contains(tr("ctrl"), Qt::CaseInsensitive))
		//                return;
		QString ied = ui->comboBox_ied->currentText();
		Point_SCD->GetCTRLDataList(ied, ld, DataSetList);
		
	}

	QTreeWidgetItem* firstClassItem;
	if (ui->comboBox_type->currentText() != tr("YK"))
	{
		for (int i = 0; i < DataSetList.size(); i++)
		{
			firstClassItem = new QTreeWidgetItem(DataSetNode);
			firstClassItem->setText(0, DataSetList[i].DataSetName);
			firstClassItem->setText(1, DataSetList[i].DataSetDesc);
			for (int m = 0; m < DataSetList[i].FCDA_List.size(); m++)
			{


				QTreeWidgetItem *Item = new QTreeWidgetItem;
				QString str;
				if (DataSetList[i].FCDA_List[m].B_daName.isEmpty())
				{
					str = ui->comboBox_ied->currentText() + "$" + ui->comboBox_ied->currentText() + DataSetList[i].FCDA_List[m].B_ldInst + "$"
						+ DataSetList[i].FCDA_List[m].B_prefix + DataSetList[i].FCDA_List[m].B_lnClass
						+ DataSetList[i].FCDA_List[m].B_lnInst + "." + DataSetList[i].FCDA_List[m].B_fc + "."
						+ DataSetList[i].FCDA_List[m].B_doName;
				}
				else
				{
					str = ui->comboBox_ied->currentText() + "$" + ui->comboBox_ied->currentText() + DataSetList[i].FCDA_List[m].B_ldInst + "$"
						+ DataSetList[i].FCDA_List[m].B_prefix + DataSetList[i].FCDA_List[m].B_lnClass
						+ DataSetList[i].FCDA_List[m].B_lnInst + "." + DataSetList[i].FCDA_List[m].B_fc + "."
						+ DataSetList[i].FCDA_List[m].B_doName + "." + DataSetList[i].FCDA_List[m].B_daName;
				}
				if (ui->comboBox_type->currentText() == tr("YX"))
				{
					if (DataSetList[i].FCDA_List[m].B_fc != "ST")
					{
						continue;
					}
					

				}
				else if (ui->comboBox_type->currentText() == tr("YC") || ui->comboBox_type->currentText() == tr("KWH"))
				{
					if (DataSetList[i].FCDA_List[m].B_fc != "MX")
					{
						continue;
					}
				}
				else  	if (ui->comboBox_type->currentText() == tr("SG"))
				{
					if (DataSetList[i].FCDA_List[m].B_fc != "SG")
					{
						continue;
					}
				}
				Item->setText(0, str);
				Item->setText(1, DataSetList[i].FCDA_List[m].B_DOdesc);
				firstClassItem->addChild(Item);
			}
		}
	}
	else if (ui->comboBox_type->currentText() == tr("YK"))
	{
		for (int i = 0; i < DataSetList.size(); i++)
		{
			firstClassItem = new QTreeWidgetItem(DataSetNode);
			firstClassItem->setText(0, DataSetList[i].DataSetName);
			firstClassItem->setText(1, DataSetList[i].DataSetDesc);
			for (int m = 0; m < DataSetList[i].FCDA_List.size(); m++)
			{
				QTreeWidgetItem *Item = new QTreeWidgetItem;
				QString str;

				str = ui->comboBox_ied->currentText() + "$" + ui->comboBox_ied->currentText() + DataSetList[i].FCDA_List[m].B_ldInst + "$"
					+ DataSetList[i].FCDA_List[m].B_prefix + DataSetList[i].FCDA_List[m].B_lnClass
					+ DataSetList[i].FCDA_List[m].B_lnInst + "." + DataSetList[i].FCDA_List[m].B_fc + "."
					+ DataSetList[i].FCDA_List[m].B_doName;

				Item->setText(0, str);
				Item->setText(1, DataSetList[i].FCDA_List[m].B_DOdesc);
				firstClassItem->addChild(Item);
			}
		}
	}



}
void LogicMap::pushbutton_station()
{
	StationPara m_dlg;
	StationPara_struct m_data;
	Point_MAP->GetStationPara(m_data, 1);
	m_dlg.vendor = m_data.Vender;
	m_dlg.Version = m_data.Version;
	m_dlg.ProjectName = m_data.ProjectName;
	m_dlg.Line = m_data.Line;
	m_dlg.display(1);
	if (m_dlg.exec() == QDialog::Accepted)
	{
		m_data.Vender = m_dlg.vendor;
		m_data.Version = m_dlg.Version;
		m_data.Line = m_dlg.Line;
		m_data.ProjectName = m_dlg.ProjectName;
		Point_MAP->UpdataStationPara(m_data);
		return;
	}
}
void LogicMap::receivedragEnterEvent(QDropEvent *event)
{
    disconnect(m_ModelDEV, SIGNAL(dataChanged(const QModelIndex &, const QModelIndex &)), this, SLOT(OnDataChanged(const QModelIndex &, const QModelIndex &)));

     QStringList dataList;
     QModelIndex curIndex = ui->dropTable->indexAt(event->pos());
     QList<QTreeWidgetItem*> itemlist;
     if ((!Model_CUR.Name.isEmpty()) && (Model_CUR.Name != ui->comboBox_ied->currentText()))
     {
         QMessageBox msgBox;
         msgBox.setText(tr("The operation will change the IED of device"));
         msgBox.setInformativeText(tr("Do you want to  change?"));
         msgBox.setStandardButtons(QMessageBox::Yes | QMessageBox::No);
         msgBox.setDefaultButton(QMessageBox::Yes);
         int ret = msgBox.exec();
         if(ret==QMessageBox::No)
         {
           connect(m_ModelDEV, SIGNAL(dataChanged(const QModelIndex &, const QModelIndex &)), this, SLOT(OnDataChanged(const QModelIndex &, const QModelIndex &)));

           return;
         }else
         {
         Point_MAP->DelOneIED(Dev_Map.value(ui->comboBox_dev->currentText()));
         if (ui->comboBox_type->currentText() == tr("YX"))
         {
           DisplayDev(YX_TYPE);
         }
         if (ui->comboBox_type->currentText() == tr("YC"))
         {
           DisplayDev(YC_TYPE);
         }
         if (ui->comboBox_type->currentText() == tr("YK"))
         {
           DisplayDev(YK_TYPE);
         }
         if (ui->comboBox_type->currentText() == tr("KWH"))
         {
           DisplayDev(KWH_TYPE);
         }
         if (ui->comboBox_type->currentText() == tr("SG"))
         {
           DisplayDev(SG_TYPE);
         }
         }
   }
     itemlist = ui->treeWidget->selectedItems();
     if(itemlist.at(0)->childCount()!=0)
     {
     connect(m_ModelDEV, SIGNAL(dataChanged(const QModelIndex &, const QModelIndex &)), this, SLOT(OnDataChanged(const QModelIndex &, const QModelIndex &)));
     return;
     }

     for (int i = 0; i < itemlist.size(); i++)
     {
        dataList.append(itemlist[i]->text(0));
     }
     for (int m = 0; m < dataList.size(); m++)
     {
         if ((m + curIndex.row()) >= m_ModelDEV->rowCount())
         {
             break;
         }
        for(int k=0;k<m_ModelDEV->rowCount();k++)
        {
            QString str = m_ModelDEV->data(m_ModelDEV->index(k,3)).toString();
            if(str==dataList.at(m))
            {
                QMessageBox msgBox;
                msgBox.setText(tr("The data (%1) is already exist").arg(dataList.at(m)));
                msgBox.setInformativeText(tr("Do you want to  continue?"));
                msgBox.setStandardButtons(QMessageBox::Yes | QMessageBox::No);
                msgBox.setDefaultButton(QMessageBox::Yes);
                int ret = msgBox.exec();
                if(ret==QMessageBox::No)
                {
                  connect(m_ModelDEV, SIGNAL(dataChanged(const QModelIndex &, const QModelIndex &)), this, SLOT(OnDataChanged(const QModelIndex &, const QModelIndex &)));

                  return;
                }
            }
        }
         m_ModelDEV->setData(m_ModelDEV->index(curIndex.row() + m, 3), dataList[m]);
         if (ui->comboBox_type->currentText() == tr("YX"))
         {
             m_ModelDEV->setData(m_ModelDEV->index(curIndex.row() + m, 4), QVariant("YES"));
             m_ModelDEV->setData(m_ModelDEV->index(curIndex.row() + m, 5), QVariant("NO"));
             m_ModelDEV->setData(m_ModelDEV->index(curIndex.row() + m, 6), QVariant("YES"));
             m_ModelDEV->setData(m_ModelDEV->index(curIndex.row() + m, 7), QVariant("NO"));
         }
         else if (ui->comboBox_type->currentText() == tr("YK"))
         {
             m_ModelDEV->setData(m_ModelDEV->index(curIndex.row() + m, 4), QVariant(DataSetList[0].FCDA_List[m].B_daName));
         }

     }
     connect(m_ModelDEV, SIGNAL(dataChanged(const QModelIndex &, const QModelIndex &)), this, SLOT(OnDataChanged(const QModelIndex &, const QModelIndex &)));

}

//{
//	QStringList dataList;
//	QModelIndex curIndex = ui->dropTable->indexAt(event->pos());
//	QList<QTreeWidgetItem*> itemlist;
//	if ((!Model_CUR.Name.isEmpty()) && (Model_CUR.Name != ui->comboBox_ied->currentText()))
//	{
//		QMessageBox msgBox;
//		msgBox.setText("The MAP file has not been saved");
//		msgBox.setInformativeText("Do you want to save your changes?");
//        msgBox.setStandardButtons(QMessageBox::Yes | QMessageBox::No);
//        msgBox.setDefaultButton(QMessageBox::Yes);
//		int ret = msgBox.exec();
//        if (ret == QMessageBox::Yes)
//		{
//			Model_CUR.Name = ui->comboBox_ied->currentText();
//			Point_MAP->DelOneIED(Dev_Map.value(ui->comboBox_dev->currentText()));
//			for (int i = 0; i < m_ModelDEV->rowCount(); i++)
//			{
//				m_ModelDEV->setData(m_ModelDEV->index(i, 3), QVariant(""));
//				m_ModelDEV->setData(m_ModelDEV->index(i, 4), QVariant(""));
//				m_ModelDEV->setData(m_ModelDEV->index(i, 5), QVariant(""));
//				m_ModelDEV->setData(m_ModelDEV->index(i, 6), QVariant(""));
//			}
//			if (ui->comboBox_type->currentText() == tr("YX"))
//				DisplayDev(YX_TYPE);
//			if (ui->comboBox_type->currentText() == tr("YC"))
//				DisplayDev(YC_TYPE);
//			if (ui->comboBox_type->currentText() == tr("KWH"))
//				DisplayDev(KWH_TYPE);
//			if (ui->comboBox_type->currentText() == tr("YK"))
//				DisplayDev(YK_TYPE);
//		}
//		else
//		{
//			if (ui->comboBox_type->currentText() == tr("YX"))
//				DisplayDev(YX_TYPE);
//			if (ui->comboBox_type->currentText() == tr("YC"))
//				DisplayDev(YC_TYPE);
//			if (ui->comboBox_type->currentText() == tr("KWH"))
//				DisplayDev(KWH_TYPE);
//			if (ui->comboBox_type->currentText() == tr("YK"))
//				DisplayDev(YK_TYPE);
//			return;
//		}
//	}

//	itemlist = ui->treeWidget->selectedItems();

//	for (int i = 0; i < itemlist.size(); i++)
//	{
//		dataList.append(itemlist[i]->text(0));
//	}
//    if(itemlist.at(0)->childCount()!=0)
//        return;
//	disconnect(m_ModelDEV, SIGNAL(dataChanged(const QModelIndex &, const QModelIndex &)), this, SLOT(OnDataChanged(const QModelIndex &, const QModelIndex &)));

//	for (int m = 0; m < dataList.size(); m++)
//	{
//		if ((m + curIndex.row()) >= m_ModelDEV->rowCount())
//		{
//			break;
//		}

//		m_ModelDEV->setData(m_ModelDEV->index(curIndex.row() + m, 3), dataList[m]);
//		if (ui->comboBox_type->currentText() == tr("YX"))
//		{
//			m_ModelDEV->setData(m_ModelDEV->index(curIndex.row() + m, 4), QVariant("YES"));
//			m_ModelDEV->setData(m_ModelDEV->index(curIndex.row() + m, 5), QVariant("YES"));
//			m_ModelDEV->setData(m_ModelDEV->index(curIndex.row() + m, 6), QVariant("NO"));
//			m_ModelDEV->setData(m_ModelDEV->index(curIndex.row() + m, 7), QVariant("NO"));
//		}
//		else if (ui->comboBox_type->currentText() == tr("YK"))
//		{
//			m_ModelDEV->setData(m_ModelDEV->index(curIndex.row() + m, 4), QVariant(DataSetList[0].FCDA_List[m].B_daName));
//		}

//	}
//	connect(m_ModelDEV, SIGNAL(dataChanged(const QModelIndex &, const QModelIndex &)), this, SLOT(OnDataChanged(const QModelIndex &, const QModelIndex &)));
//	return;

//}
void LogicMap::OnDataChanged(const QModelIndex & topLeft, const QModelIndex & bottomRight)
{
	disconnect(m_ModelDEV, SIGNAL(dataChanged(const QModelIndex &, const QModelIndex &)), this, SLOT(OnDataChanged(const QModelIndex &, const QModelIndex &)));

	int istartrow, istartcolumn, iendrow, iendcolumn;
	istartrow = topLeft.row();
	istartcolumn = topLeft.column();
	iendrow = bottomRight.row();
	iendcolumn = bottomRight.column();
	for (int i = istartrow; i <= iendrow; i++)
	{
		for (int j = istartcolumn; j <= iendcolumn; j++)
		{
			m_ModelDEV->setData(m_ModelDEV->index(i, j), QColor(255, 0, 0), Qt::TextColorRole);
			Save_flag = false;

		}
	}

	connect(m_ModelDEV, SIGNAL(dataChanged(const QModelIndex &, const QModelIndex &)), this, SLOT(OnDataChanged(const QModelIndex &, const QModelIndex &)));

}
void LogicMap::pushbutton_apply()
{
	Save_flag = false;
	Model_XML m_ModelXML;
	Device_Type m_devType;
	m_devType.Name = ui->comboBox_IED_Type->currentText();
	m_ModelXML.Name = ui->comboBox_ied->currentText();
	if (!m_devType.Name.isEmpty())
	{
		m_ModelXML.Ventor = m_devType.Name;
		m_ModelXML.Type = DeviceType_List.at(DeviceType_List.indexOf(m_devType)).Type;
	}

	for (int i = 0; i < Model_List.size(); i++)
	{
		if (Model_List[i].Model_Name == ui->comboBox_dev->currentText())
		{
			m_ModelXML.Address = Model_List[i].Model_No;
			break;
		}
	}
	if (ui->comboBox_type->currentText() == tr("YX"))
	{
		for (int i = 0; i < m_ModelDEV->rowCount(); i++)
		{
			BI_struct m_BI;
			m_BI.stVal = m_ModelDEV->data(m_ModelDEV->index(i, 4)).toString();
			m_BI.q = m_ModelDEV->data(m_ModelDEV->index(i, 5)).toString();
			m_BI.t = m_ModelDEV->data(m_ModelDEV->index(i, 6)).toString();
			m_BI.TrigOsc = m_ModelDEV->data(m_ModelDEV->index(i, 7)).toString();
			m_BI.DataNo = m_ModelDEV->data(m_ModelDEV->index(i, 2)).toString();
			m_BI.Name = m_ModelDEV->data(m_ModelDEV->index(i, 3)).toString();
			if (m_BI.Name.isEmpty())
			{
				continue;
			}
			m_ModelXML.BI_List.append(m_BI);
		}
        Point_MAP->UpdataOneIED(m_ModelXML,YX_TYPE);
		DisplayDev(YX_TYPE);
	}
	if (ui->comboBox_type->currentText() == tr("YC"))
	{
		for (int i = 0; i < m_ModelDEV->rowCount(); i++)
		{
			AI_struct m_AI;
			m_AI.DataNo = m_ModelDEV->data(m_ModelDEV->index(i, 2)).toString();
			m_AI.Name = m_ModelDEV->data(m_ModelDEV->index(i, 3)).toString();
			if (m_AI.Name.isEmpty())
			{
				continue;
			}
			m_ModelXML.AI_List.append(m_AI);
		}
        Point_MAP->UpdataOneIED(m_ModelXML,YC_TYPE);
		DisplayDev(YC_TYPE);
	}

	if (ui->comboBox_type->currentText() == tr("KWH"))
	{
		for (int i = 0; i < m_ModelDEV->rowCount(); i++)
		{
			CI_struct m_CI;
			m_CI.DataNo = m_ModelDEV->data(m_ModelDEV->index(i, 2)).toString();
			m_CI.Name = m_ModelDEV->data(m_ModelDEV->index(i, 3)).toString();
			if (m_CI.Name.isEmpty())
			{
				continue;
			}
			m_ModelXML.CI_List.append(m_CI);
		}
        Point_MAP->UpdataOneIED(m_ModelXML,KWH_TYPE);
		DisplayDev(KWH_TYPE);
	}

	if (ui->comboBox_type->currentText() == tr("YK"))
	{
		for (int i = 0; i < m_ModelDEV->rowCount(); i++)
		{
			BO_struct m_BO;
			m_BO.DataNo = m_ModelDEV->data(m_ModelDEV->index(i, 2)).toString();
			m_BO.Name = m_ModelDEV->data(m_ModelDEV->index(i, 3)).toString();
			m_BO.ctlModel = m_ModelDEV->data(m_ModelDEV->index(i, 4)).toString();
			if (m_BO.Name.isEmpty())
			{
				continue;
			}
			m_ModelXML.BO_List.append(m_BO);
		}
        Point_MAP->UpdataOneIED(m_ModelXML,YK_TYPE);
		DisplayDev(YK_TYPE);
	}
    if (ui->comboBox_type->currentText() == tr("SG"))
    {
        for (int i = 0; i < m_ModelDEV->rowCount(); i++)
        {
            SG_struct m_SG;
            m_SG.DataNo = m_ModelDEV->data(m_ModelDEV->index(i, 2)).toString();
            m_SG.Name = m_ModelDEV->data(m_ModelDEV->index(i, 3)).toString();
            if (m_SG.Name.isEmpty())
            {
                continue;
            }
            m_ModelXML.SG_List.append(m_SG);
        }
        Point_MAP->UpdataOneIED(m_ModelXML,SG_TYPE);
        DisplayDev(SG_TYPE);
    }
}
void LogicMap::GetDeviceList()
{
	Point_MAP->GetDeviceTypeList(DeviceType_List);
}
void LogicMap::pushbutton_clear()
{
	//QString str = ui->comboBox_dev->currentText();
	QString state = ui->comboBox_type->currentText();
	m_ModelSlection = ui->dropTable->selectionModel();
	QModelIndexList indexes;
	QModelIndex index;
	indexes.clear();
	indexes = m_ModelSlection->selectedRows();

	foreach(index, indexes)
	{
		QString str = m_ModelDEV->data(m_ModelDEV->index(index.row(), 2)).toString();
		QString str2 = m_ModelDEV->data(m_ModelDEV->index(index.row(), 3)).toString();
        //m_ModelDEV->setData(m_ModelDEV->index(index.row(), 3), QVariant());
		if (str2.isEmpty())
		{
			continue;
		}
		if (state == tr("YX"))
		{
            m_ModelDEV->setData(m_ModelDEV->index(index.row(), 3), QVariant());
            m_ModelDEV->setData(m_ModelDEV->index(index.row(), 4), QVariant());
            m_ModelDEV->setData(m_ModelDEV->index(index.row(), 5), QVariant());
            m_ModelDEV->setData(m_ModelDEV->index(index.row(), 6), QVariant());
			m_ModelDEV->setData(m_ModelDEV->index(index.row(), 7), QVariant());
			Point_MAP->DelOneItem(Dev_Map.value(ui->comboBox_dev->currentText()), str, YX_TYPE);
		}

		else if (state == tr("YC"))
		{
			Point_MAP->DelOneItem(Dev_Map.value(ui->comboBox_dev->currentText()), str, YC_TYPE);
            m_ModelDEV->setData(m_ModelDEV->index(index.row(), 3), QVariant());

		}
		else if (state == tr("KWH"))
		{
			Point_MAP->DelOneItem(Dev_Map.value(ui->comboBox_dev->currentText()), str, KWH_TYPE);
            m_ModelDEV->setData(m_ModelDEV->index(index.row(), 3), QVariant());

		}
		else if (state == tr("YK"))
		{
            m_ModelDEV->setData(m_ModelDEV->index(index.row(), 3), QVariant());
            m_ModelDEV->setData(m_ModelDEV->index(index.row(), 4), QVariant());

			Point_MAP->DelOneItem(Dev_Map.value(ui->comboBox_dev->currentText()), str, YK_TYPE);
		}
		else if (state == tr("SG"))
        {
            Point_MAP->DelOneItem(Dev_Map.value(ui->comboBox_dev->currentText()), str, SG_TYPE);
            m_ModelDEV->setData(m_ModelDEV->index(index.row(), 3), QVariant());

        }
	}

	//ui->comboBox_dev->activated(ui->comboBox_dev->currentText());
}
void LogicMap::pushbutton_Del()
{
    Save_flag = false;
    Point_MAP->DelOneIED(Dev_Map.value(ui->comboBox_dev->currentText()));
    if (ui->comboBox_type->currentText() == tr("YX"))
    {
      DisplayDev(YX_TYPE);
    }
    if (ui->comboBox_type->currentText() == tr("YC"))
    {
      DisplayDev(YC_TYPE);
    }
    if (ui->comboBox_type->currentText() == tr("YK"))
    {
      DisplayDev(YK_TYPE);
    }
    if (ui->comboBox_type->currentText() == tr("KWH"))
    {
      DisplayDev(KWH_TYPE);
    }
    if (ui->comboBox_type->currentText() == tr("SG"))
    {
      DisplayDev(SG_TYPE);
    }
}
