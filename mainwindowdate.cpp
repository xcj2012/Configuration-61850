#include"mainwindow.h"
#include"ui_mainwindow.h"

void MainWindow::Init_DataSet()
{


	headerList.clear();
	headerList << tr("name") << tr("desc");


	ui->tableView->setSelectionBehavior(QAbstractItemView::SelectRows);
	ui->tableView->setSelectionMode(QAbstractItemView::SingleSelection);
	m_ModelIED_DataSet->clear();
	ClearTableDelegate(headerList.size());
	disconnect(m_ModelIED_DataSet, SIGNAL(dataChanged(const QModelIndex &, const QModelIndex &)), this, SLOT(OnDataDataChanged(const QModelIndex &, const QModelIndex &)));
	m_ModelIED_DataSet->setColumnCount(headerList.count());
	ui->comboBox_LN->setEnabled(false);
	ui->tableView->setModel(m_ModelIED_DataSet);
	for (int i = 0; i < headerList.count(); i++)
	{
		m_ModelIED_DataSet->setHeaderData(i, Qt::Horizontal, headerList.at(i));
		ui->tableView->setItemDelegateForColumn(i, ui->tableView->itemDelegateForColumn(0));
	}

	//ui->tableView->setColumnWidth(0, 200);
	//ui->tableView->setColumnWidth(1, 200);
	ui->tableView->horizontalHeader()->setSectionResizeMode(QHeaderView::Interactive);

	connect(m_ModelIED_DataSet, SIGNAL(dataChanged(const QModelIndex &, const QModelIndex &)), this, SLOT(OnDataDataChanged(const QModelIndex &, const QModelIndex &)));
	connect(ui->tableView, SIGNAL(clicked(const QModelIndex &)), this, SLOT(OnDataSetdoubleClicked(const QModelIndex &)));
	connect(ui->tableView_data, SIGNAL(doubleClicked(const QModelIndex &)), this, SLOT(OnDataSetDataClicked(const QModelIndex &)));

}

void MainWindow::OnDataDataChanged(const QModelIndex & topLeft, const QModelIndex & bottomRight)
{
	int istartrow, istartcolumn, iendrow, iendcolumn;
	istartrow = topLeft.row();
	istartcolumn = topLeft.column();
	iendrow = bottomRight.row();
	iendcolumn = bottomRight.column();
	QString str1, strLD, strLN, strSet, strDesc;
	QStringList strlist;
	str1 = ui->comboBox_LD->currentText();
	strlist = str1.split(":");
	strLD = strlist.at(1);
	strLN = ui->comboBox_LN->currentText();
	strSet = m_ModelIED_DataSet->data(m_ModelIED_DataSet->index(istartrow, 0), Qt::EditRole).toString();
	strDesc = m_ModelIED_DataSet->data(m_ModelIED_DataSet->index(istartrow, 1), Qt::EditRole).toString();
	//QByteArray str2 = m_ModelIED_DataSet->data(topLeft, Qt::EditRole).toByteArray();
	int recode = DO_OD;
	recode = m_SCDPoint->UpdataOneDatSet(strIEDname, strLD, strLN, currentDataset, strSet, strDesc);
	if (recode == DO_OK)
	{
		Change_Flag = 1;
		Reversion_Flag = 1;
	}
	if (recode == DO_FAIL)
	{
		QMessageBox::about(0, tr("Alarm"), tr("Modify Value  false!"));
	}

}
void MainWindow::DisplayDataSet()
{

	disconnect(m_ModelIED_DataSet, SIGNAL(dataChanged(const QModelIndex &, const QModelIndex &)), this, SLOT(OnDataDataChanged(const QModelIndex &, const QModelIndex &)));
	currentDataset.clear();
	m_ModelIED_DataSet->setRowCount(0);
	if (GetCurrentLD() == DO_FAIL)
	{
		m_SCDPoint->SwitchToIED();
		connect(m_ModelIED_DataSet, SIGNAL(dataChanged(const QModelIndex &, const QModelIndex &)), this, SLOT(OnDataDataChanged(const QModelIndex &, const QModelIndex &)));
		return;
	}
	if (m_SCDPoint->GetLNnode(ui->comboBox_LN->currentText()) == DO_FAIL)
	{
		m_SCDPoint->SwitchToIED();
		connect(m_ModelIED_DataSet, SIGNAL(dataChanged(const QModelIndex &, const QModelIndex &)), this, SLOT(OnDataDataChanged(const QModelIndex &, const QModelIndex &)));
		return;
	}
	DataSet_Vector.clear();
	m_SCDPoint->GetDataSetVector(DataSet_Vector);
	for (int i = 0; i < DataSet_Vector.size(); i++)
	{
		m_ModelIED_DataSet->setRowCount(i + 1);
		AddOneDataSetToTable(i);
	}
	m_SCDPoint->SwitchToIED();
	connect(m_ModelIED_DataSet, SIGNAL(dataChanged(const QModelIndex &, const QModelIndex &)), this, SLOT(OnDataDataChanged(const QModelIndex &, const QModelIndex &)));
	return;
}
void MainWindow::AddOneDataSetToTable(int row)
{
	m_ModelIED_DataSet->setData(m_ModelIED_DataSet->index(row, 0), QVariant(DataSet_Vector[row].DataSetName));
	m_ModelIED_DataSet->setData(m_ModelIED_DataSet->index(row, 1), QVariant(DataSet_Vector[row].DataSetDesc));
	m_ModelIED_DataSet->item(row, 0)->setFlags(Qt::ItemIsSelectable | Qt::ItemIsEnabled);
    m_ModelIED_DataSet->item(row, 1)->setFlags(Qt::ItemIsSelectable | Qt::ItemIsEnabled);

    //m_ModelIED_DataSet->item(row, 1)->setFlags(Qt::ItemIsSelectable | Qt::ItemIsEnabled);
}
void MainWindow::OnDataSetdoubleClicked(const QModelIndex & index)
{
	if ((ChildNodeType == NODE_DATASET) || (ChildNodeType == NODE_DATA))
	{
		QString strname = m_ModelIED_DataSet->data(m_ModelIED_DataSet->index(index.row(), 0)).toString();
		if (currentDataset == strname)
			return;
		if (!currentDataset.isEmpty())
		{
			QString str1 = ui->comboBox_LD->currentText();
			QStringList strlist = str1.split(":");
			QString strLD = strlist.at(1);
			m_SCDPoint->UpdataBLKConfRev(strIEDname, strLD, currentDataset, DataSet_Change);
			DataSet_Change = false;
		}
		currentDataset = strname;
		ui->tableView_data->show();
		DisplayDataSetDate(strname);
		ui->frame->show();
		ui->checkBox_DA_END->hide();
		ui->label_LN_C->show();
		ui->lineEdit_LN->show();
		ui->checkBox_DA->hide();
		ui->label_DA->show();
		ui->lineEdit_DA->show();
		ui->checkBox_DA_END->hide();
		ui->label_AP->show();
		ui->comboBox_AP->show();
		ui->label_FC->show();
		ui->comboBox_FC->show();
		ui->checkBox_Disp->show();
		ui->pushButton_fresh->show();
		ui->comboBox_AP->setEnabled(false);
		ui->IEDTree->clear();
		Init_Frame();
		m_SCDPoint->SwitchToIED();
		ChildNodeType = NODE_DATA;
		return;
	}

}
void MainWindow::OnDataSetDataClicked(const QModelIndex & index)
{
	disconnect(ui->tableView_data, SIGNAL(doubleClicked(const QModelIndex &)), this, SLOT(OnDataSetDataClicked(const QModelIndex &)));

	DataDescChange m_dlg;
	QString strLD, strLN, strSet, strDo;
	strLD = ui->comboBox_LD->currentText().split(":").at(1);
	strLN = ui->comboBox_LN->currentText();
	strSet = currentDataset;
	QItemSelectionModel *Model_Selected = ui->tableView_data->selectionModel();
	QModelIndexList IndexList = Model_Selected->selectedRows();
	if (IndexList.size() == 0)
	{
		connect(ui->tableView_data, SIGNAL(doubleClicked(const QModelIndex &)), this, SLOT(OnDataSetDataClicked(const QModelIndex &)));

		return;
	}
	QModelIndex indexs;
	if (IndexList.size() > 1)
	{
		connect(ui->tableView_data, SIGNAL(doubleClicked(const QModelIndex &)), this, SLOT(OnDataSetDataClicked(const QModelIndex &)));

		return;
	}

	foreach(indexs, IndexList)
	{
		strDo = m_ModelIED_DataSetData->data(m_ModelIED_DataSetData->index(indexs.row(), 2)).toString();
	}
	QString strDesc1, strDesc2, strdU1, strdU2;
	m_SCDPoint->GetDataDesc(strIEDname, strDo, strDesc1, strDesc2, strdU1, strdU2);
	m_dlg.Display(strDesc1, strDesc2, strdU1, strdU2);
	if (m_dlg.exec() == QDialog::Accepted)
	{

		strDesc1 = m_dlg.strDesc1;
		strDesc2 = m_dlg.strDesc2;
		strdU1 = m_dlg.strDU1;
		strdU2 = m_dlg.strDU2;
		m_SCDPoint->UpdataDataDesc(strIEDname, strDo, strDesc1, strDesc2, strdU1, strdU2);
		m_ModelIED_DataSetData->setData(m_ModelIED_DataSetData->index(IndexList.at(0).row(), 5), QVariant(strDesc1 + strDesc2));
	}
	else
	{
		connect(ui->tableView_data, SIGNAL(doubleClicked(const QModelIndex &)), this, SLOT(OnDataSetDataClicked(const QModelIndex &)));

		return;
	}
	connect(ui->tableView_data, SIGNAL(doubleClicked(const QModelIndex &)), this, SLOT(OnDataSetDataClicked(const QModelIndex &)));

	return;
}

void MainWindow::DisplayDataSetDate(QString strname)
{
	DataSetStruct m_dataSet;
	for (int i = 0; i < DataSet_Vector.size(); i++)
	{
		if (DataSet_Vector[i].DataSetName == strname)
		{
			m_dataSet = DataSet_Vector[i];
		}
	}
	Init_DataSetData(m_dataSet.Goose_state);
	m_ModelIED_DataSetData->setRowCount(0);
	if (GetCurrentLD() == DO_FAIL)
	{
		m_SCDPoint->SwitchToIED();
		return;
	}
	if (m_SCDPoint->GetLNnode(ui->comboBox_LN->currentText()) == DO_FAIL)
	{
		m_SCDPoint->SwitchToIED();
		return;
	}
	if (m_SCDPoint->GetChildByname_value("DataSet", "name", strname) == DO_OK)
	{
		GetDataSetData();
		m_SCDPoint->SwitchToIED();
		if (DataSetDataList.size() == 0)
			return;
	}

	GetDataSetData_inst(m_dataSet.Goose_state);

}
void MainWindow::Init_DataSetData(int state)
{

	headerList.clear();
	if (state == 1)
	{
		headerList << tr("NO") << tr("IEDname") << tr("Data reference") << tr("DA") << tr("FC") << tr("DO Desc") << tr("sAddr");

	}
	else if (state == 2)
	{
		headerList << tr("NO") << tr("IEDname") << tr("Data reference") << tr("DA") << tr("FC") << tr("DO Desc") << tr("sAddr");

	}
	else if (state == 0)
	{
		headerList << tr("NO") << tr("IEDname") << tr("Data reference") << tr("DA") << tr("FC") << tr("DO Desc");

	}

	ui->tableView_data->setSelectionBehavior(QAbstractItemView::SelectRows);
	ui->tableView_data->setSelectionMode(QAbstractItemView::ExtendedSelection);
	m_ModelIED_DataSetData->clear();
	ui->tableView_data->verticalHeader()->hide();

	m_ModelIED_DataSetData->setColumnCount(headerList.count());

	ui->tableView_data->setModel(m_ModelIED_DataSetData);
	for (int i = 0; i < headerList.count(); i++)
	{
		m_ModelIED_DataSetData->setHeaderData(i, Qt::Horizontal, headerList.at(i));

	}

	ui->tableView_data->setColumnWidth(0, 30);
	ui->tableView_data->setColumnWidth(1, 100);
	ui->tableView_data->setColumnWidth(4, 50);
	connect(ui->IEDTree, SIGNAL(itemDoubleClicked(QTreeWidgetItem*, int)), this, SLOT(IEDTreeDoubleClicked(QTreeWidgetItem*, int)));
}

void MainWindow::GetDataSetData()
{
	DataSetDataList.clear();
	FCDA_MAP.clear();
	m_SCDPoint->GetFCDAList(DataSetDataList, FCDA_MAP);

	m_SCDPoint->SwitchParent();
}
void MainWindow::GetDataSetData_inst()
{
	Data_instStruct m_datainst;
	int recode;
	Data_instList.clear();
	for (int i = 0; i < DataSetDataList.size(); i++)
	{
		recode = GetSpecifytLD(DataSetDataList[i].B_ldInst);
		if (m_SCDPoint->GetChildByname_value("prefix", DataSetDataList[i].B_prefix, "lnClass", DataSetDataList[i].B_lnClass, "inst", DataSetDataList[i].B_lnInst) == DO_OK)
		{

			m_datainst.B_Datalnst = DataSetDataList[i].B_ldInst + "/" + DataSetDataList[i].B_prefix + DataSetDataList[i].B_lnClass + DataSetDataList[i].B_lnInst + "." + DataSetDataList[i].B_doName;
			m_datainst.B_DA = DataSetDataList[i].B_daName;
			m_datainst.B_FC = DataSetDataList[i].B_fc;
			if (m_SCDPoint->GetOneDOI(DataSetDataList[i].B_doName) == DO_FAIL)
			{
				m_SCDPoint->SwitchToIED();
				continue;
			}
			m_datainst.B_DOdesc = m_SCDPoint->GetAttribute("desc");
			m_datainst.B_sAddr = m_SCDPoint->GetDOIValue("DAI", DataSetDataList[i].B_daName, "sAddr");
			m_datainst.B_dU = m_SCDPoint->GetDOIValue("DAI", "dU", "Val");

			Data_instList.append(m_datainst);
		}
		m_SCDPoint->SwitchToIED();
	}


}
void MainWindow::GetDataSetData_inst(int state)
{
	m_ModelIED_DataSetData->setRowCount(DataSetDataList.size());
	for (int i = 0; i < DataSetDataList.size(); i++)
	{

		m_SCDPoint->Filling_OneData(DataSetDataList[i], state);
		AddOneDataToTable(i, DataSetDataList[i], state);
	}

}
void MainWindow::AddOneDataToTable(int row, Data_instStruct m_data, int state)
{

	if (state == 1)
	{
		m_ModelIED_DataSetData->setData(m_ModelIED_DataSetData->index(row, 0), QVariant(row));
		m_ModelIED_DataSetData->setData(m_ModelIED_DataSetData->index(row, 1), QVariant(strIEDname));
		m_ModelIED_DataSetData->setData(m_ModelIED_DataSetData->index(row, 2), QVariant(m_data.B_Datalnst));
		m_ModelIED_DataSetData->setData(m_ModelIED_DataSetData->index(row, 3), QVariant(m_data.B_DA));
		m_ModelIED_DataSetData->setData(m_ModelIED_DataSetData->index(row, 4), QVariant(m_data.B_FC));
		//m_ModelIED_DataSetData->setData(m_ModelIED_DataSetData->index(row, 5), QVariant(m_data.B_dU));
		m_ModelIED_DataSetData->setData(m_ModelIED_DataSetData->index(row, 5), QVariant(m_data.B_DOdesc));

		m_ModelIED_DataSetData->item(row, 0)->setFlags(Qt::ItemIsSelectable | Qt::ItemIsEnabled);
		m_ModelIED_DataSetData->item(row, 1)->setFlags(Qt::ItemIsSelectable | Qt::ItemIsEnabled);
		m_ModelIED_DataSetData->item(row, 2)->setFlags(Qt::ItemIsSelectable | Qt::ItemIsEnabled);
		m_ModelIED_DataSetData->item(row, 3)->setFlags(Qt::ItemIsSelectable | Qt::ItemIsEnabled);
		m_ModelIED_DataSetData->item(row, 4)->setFlags(Qt::ItemIsSelectable | Qt::ItemIsEnabled);
		m_ModelIED_DataSetData->item(row, 5)->setFlags(Qt::ItemIsSelectable | Qt::ItemIsEnabled);

		m_ModelIED_DataSetData->setData(m_ModelIED_DataSetData->index(row, 6), QVariant(m_data.B_sAddr));
		m_ModelIED_DataSetData->item(row, 6)->setFlags(Qt::ItemIsSelectable | Qt::ItemIsEnabled);
		//m_ModelIED_DataSetData->item(row, 7)->setFlags(Qt::ItemIsSelectable | Qt::ItemIsEnabled);
	}
	else if (state == 0)
	{
		m_ModelIED_DataSetData->setData(m_ModelIED_DataSetData->index(row, 0), QVariant(row));
		m_ModelIED_DataSetData->setData(m_ModelIED_DataSetData->index(row, 1), QVariant(strIEDname));
		m_ModelIED_DataSetData->setData(m_ModelIED_DataSetData->index(row, 2), QVariant(m_data.B_Datalnst));
		m_ModelIED_DataSetData->setData(m_ModelIED_DataSetData->index(row, 3), QVariant(m_data.B_DA));
		m_ModelIED_DataSetData->setData(m_ModelIED_DataSetData->index(row, 4), QVariant(m_data.B_FC));
		//m_ModelIED_DataSetData->setData(m_ModelIED_DataSetData->index(row, 5), QVariant(m_data.B_dU));
		m_ModelIED_DataSetData->setData(m_ModelIED_DataSetData->index(row, 5), QVariant(m_data.B_DOdesc));
		//m_ModelIED_DataSetData->setData(m_ModelIED_DataSetData->index(row, 6), QVariant(m_data.B_sAddr));
		m_ModelIED_DataSetData->item(row, 0)->setFlags(Qt::ItemIsSelectable | Qt::ItemIsEnabled);
		m_ModelIED_DataSetData->item(row, 1)->setFlags(Qt::ItemIsSelectable | Qt::ItemIsEnabled);
		m_ModelIED_DataSetData->item(row, 2)->setFlags(Qt::ItemIsSelectable | Qt::ItemIsEnabled);
		m_ModelIED_DataSetData->item(row, 3)->setFlags(Qt::ItemIsSelectable | Qt::ItemIsEnabled);
		m_ModelIED_DataSetData->item(row, 4)->setFlags(Qt::ItemIsSelectable | Qt::ItemIsEnabled);
		m_ModelIED_DataSetData->item(row, 5)->setFlags(Qt::ItemIsSelectable | Qt::ItemIsEnabled);
		//m_ModelIED_DataSetData->item(row, 6)->setFlags(Qt::ItemIsSelectable | Qt::ItemIsEnabled);

		//m_ModelIED_DataSetData->item(row, 7)->setFlags(Qt::ItemIsSelectable | Qt::ItemIsEnabled);
	}



}
void MainWindow::Init_Frame()
{
	headerList.clear();
	headerList << "Object" << "Desc";
	ui->IEDTree->setHeaderLabels(headerList);
	ui->IEDTree->setColumnWidth(0, 200);
	ui->IEDTree->setColumnWidth(1, 60);


	Init_Combox_FC();
	Init_LineEdit_DA();
}
void MainWindow::AddOneApToCombox(QString strAp)
{
	ui->comboBox_AP->addItem(strAp);
}
void MainWindow::Init_Combox_FC()
{
	ui->comboBox_FC->clear();
	QStringList fclist;
	fclist << tr("ST") << tr("MX") << tr("CO") << tr("CF") << tr("DC") << tr("SP") << tr("SG") << tr("RP") << tr("LG") << tr("BR") << tr("GO")
		<< tr("GS") << tr("SV") << tr("SE") << tr("MS") << tr("SC") << tr("US") << tr("MX");
	ui->comboBox_FC->addItems(fclist);
}
void MainWindow::Init_LineEdit_DA()
{

	ui->lineEdit_DA->clear();
	ui->lineEdit_DA->setText(tr("stVal|mag|instMag|f|i"));
	ui->checkBox_DA->setChecked(true);
	ui->checkBox_DA_END->setChecked(true);
	ui->checkBox_Disp->setChecked(true);
	ui->checkBox_Disp->setEnabled(false);
	ui->checkBox_DA->setEnabled(false);
}
void MainWindow::PushButton_Fresh()
{
	disconnect(ui->pushButton_fresh, SIGNAL(clicked()), this, SLOT(PushButton_Fresh()));
	DataSetStruct m_dataSet;
	for (int i = 0; i < DataSet_Vector.size(); i++)
	{
		if (DataSet_Vector[i].DataSetName == currentDataset)
		{
			m_dataSet = DataSet_Vector[i];
		}
	}
	//QString strapname = ui->comboBox_AP->currentText();

	//QVector<DataLN_Struct>DataLN_List;
	//QVector<DataLN_Struct>DataLN_Vector;
	QStringList strlnlist, dalist;
	QString strtmp, strda;
	DatainstList.clear();
	strlnlist.clear();
	DataInstList_Select.clear();
	QString strfc;
	strda = ui->lineEdit_DA->text();
	strfc = ui->comboBox_FC->currentText();

	ui->IEDTree->clear();
	strtmp = ui->lineEdit_LN->text();
	if (strtmp != NULL)
	{
		strlnlist = strtmp.split("|");
	}
	if (strda != NULL)
	{
		dalist = strda.split("|");
	}
	if (m_dataSet.Goose_state == 1)
	{

		if (strlnlist.size() == 0)
		{
			FCDA_Struct m_datainst;
			for (int i = 0; i < DataInstList_LD.size(); i++)
			{
				m_datainst = DataInstList_LD[i];
				if ((0 == strcmp(m_datainst.B_doName, "PhyHealth")) || (0 == strcmp(m_datainst.B_doName, "Mod")) || (0 == strcmp(m_datainst.B_doName, "Beh")) || 0 == strcmp(m_datainst.B_doName, "Health"))
				{
					continue;
				}
				Filter_datainst(m_datainst);
				if (m_datainst.B_fc.isEmpty())
				{
					m_datainst.B_fc += strfc;
				}
				else
				{
					if (0 != strcmp(m_datainst.B_fc.data(), strfc.toLocal8Bit().data()))
					{
						continue;
					}
					if (dalist.size() != 0)
					{
						bool flag = false;
						for (int j = 0; j < dalist.size(); j++)
						{
							if (m_datainst.B_daName.contains(dalist.at(j).toLocal8Bit()))
							{
								flag = true;
								break;
							}
						}
						if (flag == false)
						{
							continue;
						}
					}
				}
				DataInstList_Select.append(m_datainst);
			}
		}
		else if (strlnlist.size() != 0)
		{
			FCDA_Struct m_datainst;
			for (int i = 0; i < DataInstList_LD.size(); i++)
			{
				m_datainst = DataInstList_LD[i];
				if ((0 == strcmp(m_datainst.B_doName, "Mod")) || (0 == strcmp(m_datainst.B_doName, "Beh")) || 0 == strcmp(m_datainst.B_doName, "Health"))
				{
					continue;
				}
				QString str;
				str += (m_datainst.B_prefix + m_datainst.B_lnClass + m_datainst.B_lnInst);
				for (int j = 0; j < strlnlist.size(); j++)
				{
					if (str.contains(strlnlist.at(j)))
					{
						Filter_datainst(m_datainst);
						if (m_datainst.B_fc.isEmpty())
						{
							m_datainst.B_fc += strfc;
						}
						else
						{
							if (0 != strcmp(m_datainst.B_fc.data(), strfc.toLocal8Bit().data()))
							{
								continue;
							}
							if (dalist.size() != 0)
							{
								bool flag = false;
								for (int j = 0; j < dalist.size(); j++)
								{
									if (m_datainst.B_daName.contains(dalist.at(j).toLocal8Bit()))
									{
										flag = true;
										break;
									}
								}
								if (flag == false)
								{
									continue;
								}
							}
						}
						DataInstList_Select.append(m_datainst);
						break;
					}
				}

			}
		}
		for (int i = 0; i < DataSet_Vector.size(); i++)
		{
			if (currentDataset == DataSet_Vector[i].DataSetName)
			{
				if (DataSet_Vector[i].Goose_state != 1)
				{
					for (int m = 0; m < DataInstList_Select.size(); m++)
					{
						if (!DataInstList_Select[m].B_daName.isEmpty())
						{
							DataInstList_Select.removeAt(m);
							m--;
						}
					}
				}
				else
				{
					for (int m = 0; m < DataInstList_Select.size(); m++)
					{
						if (DataInstList_Select[m].B_daName.isEmpty())
						{
							DataInstList_Select.removeAt(m);
							m--;
						}
					}
				}
			}
		}
		ADDDatainstListTOTree(DataInstList_Select);
	}
	else if (m_dataSet.Goose_state != 1)
	{
		QString StrLD, str;
		str = ui->comboBox_LD->currentText();
		StrLD = str.right(str.length() - str.indexOf(":") - 1);
		QStringList LnTypeList;
		//DataInstList_LD.clear();
		QStringList LnList;
		QStringList LnListLimnt;
		QVector<DataMatrix_Struct> DataMatrix_Vector;
		QVector<DataMatrix_Struct> DataMatrix_VectorLimnt;
		QVector<FCDA_Struct>  m_dataList;
		DataMatrix_Vector.clear();
		LnTypeList.clear();
		m_SCDPoint->GetLnListFromLD(strIEDname, StrLD, LnList);
		for (int i = 0; i < LnList.size(); i++)
		{
			if (strlnlist.size() == 0)
			{
				LnListLimnt.append(LnList[i]);
				continue;
			}
			for (int j = 0; j < strlnlist.size(); j++)
			{
				if (LnList[i].contains(strlnlist[j], Qt::CaseInsensitive))
				{
					LnListLimnt.append(LnList[i]);
				}
			}
		}
		for (int m = 0; m < LnListLimnt.size(); m++)
		{
			LnTypeList.clear();
			m_dataList.clear();
			m_SCDPoint->GetLNodeTypeList(strIEDname, StrLD, StrLD, LnListLimnt[m], LnTypeList);
			DataMatrix_Vector.clear();
			m_SCDPoint->CreatDataMatrix(LnTypeList.at(0), DataMatrix_Vector);
			for (int i = 0; i < DataMatrix_Vector.size(); i++)
			{
				if (DataMatrix_Vector[i].B_Fc == strfc)
				{
					if ((0 == strcmp(DataMatrix_Vector[i].B_doName.toLocal8Bit(), "PhyHealth")) || (0 == strcmp(DataMatrix_Vector[i].B_doName.toLocal8Bit(), "Mod")) || (0 == strcmp(DataMatrix_Vector[i].B_doName.toLocal8Bit(), "Beh"))
						|| 0 == strcmp(DataMatrix_Vector[i].B_doName.toLocal8Bit(), "Health") || 0 == strcmp(DataMatrix_Vector[i].B_doName.toLocal8Bit(), "Proxy"))
					{
						continue;
					}
					DataMatrix_VectorLimnt.append(DataMatrix_Vector[i]);
				}
			}
			if (DataMatrix_VectorLimnt.size() != 0)
			{
				m_SCDPoint->GetDoInstVector(strIEDname, StrLD, LnListLimnt[m], m_dataList);

				CreatFCDAList(DataMatrix_VectorLimnt, m_dataList, DataInstList_Select);

			}

		}

		ADDDatainstListTOTree(DataInstList_Select);
	}


	connect(ui->pushButton_fresh, SIGNAL(clicked()), this, SLOT(PushButton_Fresh()));
}
void MainWindow::ADDDatainstListTOTree(QVector<FCDA_Struct>&List)
{
	int i = 0;
	QTreeWidgetItem *firstClassItem;
	//QTreeWidgetItem *Item;// = new QTreeWidgetItem;
	QTreeWidgetItem *m_rootItem = ui->IEDTree->invisibleRootItem();
	while (i < List.size())
	{
		if (List[i].B_daName.isEmpty())
		{
			firstClassItem = new QTreeWidgetItem(m_rootItem);
			firstClassItem->setText(0, List[i].B_ldInst + "/" + List[i].B_prefix + List[i].B_lnClass + List[i].B_lnInst + "." + List[i].B_doName);
			firstClassItem->setText(1, List[i].B_DOdesc);
			i++;
			continue;
		}
		else
		{
			firstClassItem = new QTreeWidgetItem(m_rootItem);
			//Item = new QTreeWidgetItem;
			firstClassItem->setText(0, List[i].B_ldInst + "/" + List[i].B_prefix + List[i].B_lnClass + List[i].B_lnInst + "." + List[i].B_doName + "." + List[i].B_daName);
			if (List[i].B_dU.isEmpty())

			{
				firstClassItem->setText(1, List[i].B_DOdesc);
			}
			else
			{
				firstClassItem->setText(1, List[i].B_dU);
			}

			//firstClassItem->addChild(Item);
		}

		i++;
	}
}
void MainWindow::ADDDatainstListTOTree(LN_InstStruct &LNlist, QVector<Data_instStruct> &Datalist)
{
	Datalist.clear();
	//QTreeWidgetItem *firstClassItem;
	//QString str_FC;
	//QString LN_path;
	//QStringList limt_list;
	//str_FC = ui->comboBox_FC->currentText();
	//limt_list = ui->lineEdit_DA->text().split("|");
	//QTreeWidgetItem *IED_parent = ui->IEDTree->invisibleRootItem();
	//LN_path = LNlist.B_ldinst + "/" + LNlist.B_prefix + LNlist.B_lnClass + LNlist.B_inst;
	//firstClassItem = new QTreeWidgetItem(IED_parent);

	//firstClassItem->setText(0, LN_path);
	//firstClassItem->setText(1, LNlist.B_desc);
	//for (int i = 0; i < Datalist.size(); i++)
	//{
	//	if ((str_FC == Datalist[i].B_FC) || (Datalist[i].B_FC == NULL))
	//	{
	//		if (limt_list.size() == 0)
	//		{
	//			QTreeWidgetItem *Item = new QTreeWidgetItem;
	//			Item->setText(0, Datalist[i].B_Datalnst);
	//			Item->setText(1, Datalist[i].B_dU);
	//			firstClassItem->addChild(Item);
	//			DatainstList.append(Datalist[i]);
	//		}
	//		else
	//		{
	//			bool Limt_flag = false;
	//			for (int j = 0; j < limt_list.size(); j++)
	//			{
	//				if (Datalist[i].B_DA == NULL)
	//				{
	//					Limt_flag = true;
	//				}
	//				if (Datalist[i].B_DA.contains(limt_list[j]))
	//				{
	//					Limt_flag = true;
	//				}
	//			}
	//			if (Limt_flag == true)
	//			{
	//				QTreeWidgetItem *Item = new QTreeWidgetItem;
	//				Item->setText(0, Datalist[i].B_Datalnst);
	//				Item->setText(1, Datalist[i].B_dU);
	//				firstClassItem->addChild(Item);
	//				DatainstList.append(Datalist[i]);
	//			}
	//		}

	//	}

	//}

}
void MainWindow::analyzeLN(DataLN_Struct m_DataLN)
{
	QString strld;
	QString strapname;
	QString da_prefix;
	//QVector<LN_InstStruct>LN_instList;
	QVector<FCDA_Struct> DataInistList;
	QVector<DataMatrix_Struct> DataMatric_Vector;
	//strapname = ui->comboBox_AP->currentText();
	//QString strap;

	//strap = ui->comboBox_AP->currentText();
	//int recode = m_SCDPoint->GetAccessPoint(m_DataLN.B_AP);
	//recode = m_SCDPoint->GetLDnode(m_DataLN.B_LD);
	//recode = m_SCDPoint->GetLNnode(m_DataLN.B_LN);
	//QString strVale = m_SCDPoint->GetAttribute("lnType");
	//recode = m_SCDPoint->CreatDataMatrix(strVale, DataMatric_Vector);
	//if (recode == DO_FAIL)
	//{
	//	return;
	//}

	//if (GetSpecifytLN(strapname, LnName.toLocal8Bit().data(), strld, LN_instList) == DO_FAIL)
	//{
	//	return;
	//}
	//for (int i = 0; i < LN_instList.size(); i++)
	//{
	//	QVector<Data_instStruct> instList;
	//	int  recode = m_SCDPoint->GetAccessPoint(strapname);
	//	recode = m_SCDPoint->GetChild("Server");
	//	recode = m_SCDPoint->GetChildByname_value("LDevice", "inst", LN_instList[i].B_ldinst);
	//	da_prefix = LN_instList[i].B_ldinst;
	//	da_prefix += "/";
	//	if (recode == DO_FAIL)
	//	{
	//		m_SCDPoint->SwitchToIED();
	//		continue;
	//	}
	//	recode = m_SCDPoint->GetChildByname_value("lnType", LN_instList[i].B_lnType);
	//	da_prefix += LN_instList[i].B_prefix + LN_instList[i].B_lnClass + LN_instList[i].B_inst;
	//	if (recode == DO_FAIL)
	//	{
	//		m_SCDPoint->SwitchToIED();
	//		continue;
	//	}
	//	if (m_SCDPoint->GetChild("DOI") == DO_FAIL)
	//	{
	//		m_SCDPoint->SwitchToIED();
	//		continue;
	//	}
	//	m_SCDPoint->SetRememberEle();
	//	m_SCDPoint->analyzeDO(instList, da_prefix, LN_instList[i].B_lnType);
	//	m_SCDPoint->switchRememberEle();
	//	while (m_SCDPoint->GetNextChild("DOI") != DO_FAIL)
	//	{
	//		m_SCDPoint->SetRememberEle();
	//		m_SCDPoint->analyzeDO(instList, da_prefix, LN_instList[i].B_lnType);
	//		m_SCDPoint->switchRememberEle();
	//	}
	//	m_SCDPoint->SwitchToIED();

	//	ADDDatainstListTOTree(LN_instList[i], instList);


	//}
}
void MainWindow::IEDTreeDoubleClicked(QTreeWidgetItem * item, int column)
{
	disconnect(ui->IEDTree, SIGNAL(itemDoubleClicked(QTreeWidgetItem*, int)), this, SLOT(IEDTreeDoubleClicked(QTreeWidgetItem*, int)));

	QString str;
	Data_instStruct m_instData;
	QTreeWidgetItem *root = ui->IEDTree->invisibleRootItem();
	int index = root->indexOfChild(item);
	str = item->text(0);
	FCDA_Struct m_data;
	int flag;
	m_data = DataInstList_Select.at(index);
	if (m_data.B_fc.isEmpty())
	{
		m_data.B_fc = ui->comboBox_FC->currentText().toLocal8Bit();
	}
	m_ModelIED_DataSetData->setRowCount(m_ModelIED_DataSetData->rowCount() + 1);
	flag = AddOneDataToDataSet(m_data);
	DisplayDataSetDate(currentDataset.toLatin1());
	if (flag != DO_FAIL)
	{
		ui->tableView_data->scrollToBottom();
	}

	connect(ui->IEDTree, SIGNAL(itemDoubleClicked(QTreeWidgetItem*, int)), this, SLOT(IEDTreeDoubleClicked(QTreeWidgetItem*, int)));

}
int MainWindow::AddOneDataToDataSet(FCDA_Struct data)
{
	int index;
	QString str;
	FCDA_Struct m_data;

	QString curLN, curAP_LD;
	QString curAP, curLD;
	QString AP_choice;
	AP_choice = ui->comboBox_AP->currentText();
	curAP_LD = ui->comboBox_LD->currentText();
	index = curAP_LD.indexOf(":");
	curAP = curAP_LD.left(index);
	curLD = curAP_LD.right(curAP_LD.length() - index).remove(":");
	curLN = ui->comboBox_LN->currentText();

	m_data.B_daName = data.B_daName;
	m_data.B_doName = data.B_doName;
	m_data.B_fc = data.B_fc;
	m_data.B_ldInst = data.B_ldInst;
	m_data.B_prefix = data.B_prefix;
	m_data.B_lnClass = data.B_lnClass;
	m_data.B_lnInst = data.B_lnInst;

	str.clear();

	str += m_data.B_daName;

	str += m_data.B_ldInst;
	str += m_data.B_prefix;
	str += m_data.B_lnClass;
	str += m_data.B_lnInst;
	str += m_data.B_doName;
	str += m_data.B_fc;
	QByteArray byteArray = str.toLatin1();
	WORD Crc = Crc16((byte*)byteArray.data(), str.length());
	if (m_ModelIED_DataSetData->rowCount() == 256)
	{
		QMessageBox::about(0, tr("Alarm"), tr("The number of data from dataset must be under 256"));
		return DO_FAIL;
	}
	if (FCDA_MAP.contains(Crc) == true)
	{
		return DO_FAIL;
	}
	int recode = m_SCDPoint->GetAccessPoint(curAP);
	recode = m_SCDPoint->GetChild("Server");
	recode = m_SCDPoint->GetChildByname_value("LDevice", "inst", curLD);
	recode = m_SCDPoint->GetChildByname_value("lnClass", curLN);
	recode = m_SCDPoint->AddOneDataToDataSet(currentDataset, m_data);
	if (recode == DO_OK)
	{
		Reversion_Flag = 1;

		DataSet_Change = true;
	}
	return DO_OK;
}
void MainWindow::AddOneDatSet()
{
	AddDateSetdlg *m_AddDatSet = new AddDateSetdlg(this);
	QString m_name;
	QString m_desc;
	QString str1, strLD, strLN, strSet, strDesc;
	QStringList strlist;
	str1 = ui->comboBox_LD->currentText();
	strlist = str1.split(":");
	strLD = strlist.at(1);
	strLN = ui->comboBox_LN->currentText();
	m_AddDatSet->setstate(1);
	m_AddDatSet->init_dlg();
	if (m_AddDatSet->exec() == QDialog::Accepted)
	{
		m_name = m_AddDatSet->GetDataSetName();
		m_desc = m_AddDatSet->GetDataSetDesc();
		//if (GetCurrentLD() == DO_FAIL)
		//{
		//	return;
		//}
		//if (m_SCDPoint->GetLNnode(ui->comboBox_LN->currentText()) == DO_FAIL)
		//{
		//	return;
		//}
		int recode = m_SCDPoint->AddOneDatSet(strIEDname,strLD,strLN,m_name, m_desc);
		if (recode != DO_OK)
		{
			QMessageBox::about(0, tr("Alarm"), tr("Add DatSet name: %1 false").arg(m_name));
		}
		else
		{
			Reversion_Flag = 1;
		}

		m_SCDPoint->SwitchToIED();
		ui->comboBox_LN->activated(ui->comboBox_LN->currentText());

	}
	else
		return;


}
void MainWindow::RenameOneDatSet(QString name, QString desc)
{
	AddDateSetdlg *m_RenameDatSet = new AddDateSetdlg(this);
	QString m_name;
	QString m_desc;
	QString str1, strLD, strLN, strSet, strDesc;
	QStringList strlist;
	str1 = ui->comboBox_LD->currentText();
	strlist = str1.split(":");
	strLD = strlist.at(1);
	strLN = ui->comboBox_LN->currentText();
	m_RenameDatSet->SetDataSetName(name);
	m_RenameDatSet->SetDataSetDesc(desc);
	m_RenameDatSet->setstate(2);
	m_RenameDatSet->init_dlg();
	if (m_RenameDatSet->exec() == QDialog::Accepted)
	{
		m_name = m_RenameDatSet->GetDataSetName();
		m_desc = m_RenameDatSet->GetDataSetDesc();
		//if (GetCurrentLD() == DO_FAIL)
		//{
		//	return;
		//}
		//if (m_SCDPoint->GetLNnode(ui->comboBox_LN->currentText()) == DO_FAIL)
		//{
		//	return;
		//}
        int recode;
        recode = m_SCDPoint->UpdataOneDatSet(strIEDname, strLD, strLN, currentDataset, m_name, m_desc);


		//int recode = m_SCDPoint->UpdataOneDatSet(name, m_name, QVariant(m_desc).toString());
		if (recode != DO_OK)
		{
			QMessageBox::about(0, tr("Alarm"), tr("Updata DatSet name: %1 false").arg(currentDataset));
		}
		else
		{
			Reversion_Flag = 1;
			QMessageBox::about(0, tr("Notice"), tr("Updata DatSet name: %1 success,Make sure change the control block").arg(currentDataset));

		}
		m_SCDPoint->SwitchToIED();
		ui->comboBox_LN->activated(ui->comboBox_LN->currentText());
	}
}
int MainWindow::Filter_datainst(FCDA_Struct &m_data)
{
	QString str1, str2;
	if (m_data.B_daName.isEmpty())
	{
		return DO_FAIL;

	}
	str1 = m_data.B_doName + m_data.B_daName;
	str1.remove(".");
	for (int i = 0; i < DataMatrix_Vector_LD.size(); i++)
	{
		str2 = DataMatrix_Vector_LD[i].B_doName + DataMatrix_Vector_LD[i].B_daName;
		str2.remove(".");
		if (m_data.B_LNodeType == DataMatrix_Vector_LD[i].B_LNodeType)
		{
			if (str1 == str2)
			{
				m_data.B_doName.clear();
				m_data.B_daName.clear();
				m_data.B_doName += DataMatrix_Vector_LD[i].B_doName;
				m_data.B_daName += DataMatrix_Vector_LD[i].B_daName;
				m_data.B_fc += DataMatrix_Vector_LD[i].B_Fc;
				return DO_OK;
			}
		}

	}
	return DO_FAIL;

}
void	MainWindow::DelDataSetData()
{
	QString str;

	QModelIndex index;
	QModelIndexList indexes;
	m_ModelSlection = ui->tableView_data->selectionModel();
	indexes.clear();
	indexes = m_ModelSlection->selectedRows();
	if (indexes.size() == 0)
	{
		return;
	}
	foreach(index, indexes)
	{
		str.clear();
		FCDA_Struct m_data;
		m_data = DataSetDataList[index.row()];
		str += m_data.B_daName;
		str += m_data.B_ldInst;
		str += m_data.B_prefix;
		str += m_data.B_lnClass;
		str += m_data.B_lnInst;
		str += m_data.B_doName;
		str += m_data.B_fc;
		QByteArray byteArray = str.toLatin1();
		WORD Crc = Crc16((byte*)byteArray.data(), str.length());
		m_SCDPoint->DelOneData(Crc);
		DataSet_Change = true;
		Reversion_Flag = 1;

	}
	DisplayDataSetDate(currentDataset.toLatin1());
	ui->tableView_data->scrollToBottom();
}
void MainWindow::AddOneDataToTable(int row, FCDA_Struct m_data, int state)
{
	QString do_Reference;

	do_Reference = m_data.B_ldInst + "/" + m_data.B_prefix + m_data.B_lnClass + m_data.B_lnInst + "." + m_data.B_doName;
	if (state == 1)
	{
		m_ModelIED_DataSetData->setData(m_ModelIED_DataSetData->index(row, 0), QVariant(row));
		m_ModelIED_DataSetData->setData(m_ModelIED_DataSetData->index(row, 1), QVariant(strIEDname));
		m_ModelIED_DataSetData->setData(m_ModelIED_DataSetData->index(row, 2), QVariant(do_Reference));
		m_ModelIED_DataSetData->setData(m_ModelIED_DataSetData->index(row, 3), QVariant(m_data.B_daName));
		m_ModelIED_DataSetData->setData(m_ModelIED_DataSetData->index(row, 4), QVariant(m_data.B_fc));
		//m_ModelIED_DataSetData->setData(m_ModelIED_DataSetData->index(row, 5), QVariant(m_data.B_dU));
		m_ModelIED_DataSetData->setData(m_ModelIED_DataSetData->index(row, 5), QVariant(m_data.B_DOdesc));

		m_ModelIED_DataSetData->item(row, 0)->setFlags(Qt::ItemIsSelectable | Qt::ItemIsEnabled);
		m_ModelIED_DataSetData->item(row, 1)->setFlags(Qt::ItemIsSelectable | Qt::ItemIsEnabled);
		m_ModelIED_DataSetData->item(row, 2)->setFlags(Qt::ItemIsSelectable | Qt::ItemIsEnabled);
		m_ModelIED_DataSetData->item(row, 3)->setFlags(Qt::ItemIsSelectable | Qt::ItemIsEnabled);
		m_ModelIED_DataSetData->item(row, 4)->setFlags(Qt::ItemIsSelectable | Qt::ItemIsEnabled);
		m_ModelIED_DataSetData->item(row, 5)->setFlags(Qt::ItemIsSelectable | Qt::ItemIsEnabled);

		m_ModelIED_DataSetData->setData(m_ModelIED_DataSetData->index(row, 6), QVariant(m_data.B_sAddr));
		m_ModelIED_DataSetData->item(row, 6)->setFlags(Qt::ItemIsSelectable | Qt::ItemIsEnabled);
		//m_ModelIED_DataSetData->item(row, 7)->setFlags(Qt::ItemIsSelectable | Qt::ItemIsEnabled);
	}
	else if (state == 2)
	{
		m_ModelIED_DataSetData->setData(m_ModelIED_DataSetData->index(row, 0), QVariant(row));
		m_ModelIED_DataSetData->setData(m_ModelIED_DataSetData->index(row, 1), QVariant(strIEDname));
		m_ModelIED_DataSetData->setData(m_ModelIED_DataSetData->index(row, 2), QVariant(do_Reference));
		m_ModelIED_DataSetData->setData(m_ModelIED_DataSetData->index(row, 3), QVariant(m_data.B_daName));
		m_ModelIED_DataSetData->setData(m_ModelIED_DataSetData->index(row, 4), QVariant(m_data.B_fc));
		//m_ModelIED_DataSetData->setData(m_ModelIED_DataSetData->index(row, 5), QVariant(m_data.B_dU));
		m_ModelIED_DataSetData->setData(m_ModelIED_DataSetData->index(row, 5), QVariant(m_data.B_DOdesc));

		//m_ModelIED_DataSetData->item(row, 0)->setFlags(Qt::ItemIsSelectable | Qt::ItemIsEnabled);
		//m_ModelIED_DataSetData->item(row, 1)->setFlags(Qt::ItemIsSelectable | Qt::ItemIsEnabled);
		//m_ModelIED_DataSetData->item(row, 2)->setFlags(Qt::ItemIsSelectable | Qt::ItemIsEnabled);
		//m_ModelIED_DataSetData->item(row, 3)->setFlags(Qt::ItemIsSelectable | Qt::ItemIsEnabled);
		//m_ModelIED_DataSetData->item(row, 4)->setFlags(Qt::ItemIsSelectable | Qt::ItemIsEnabled);
		//m_ModelIED_DataSetData->item(row, 5)->setFlags(Qt::ItemIsSelectable | Qt::ItemIsEnabled);

		m_ModelIED_DataSetData->setData(m_ModelIED_DataSetData->index(row, 6), QVariant(m_data.B_sAddr));
		//m_ModelIED_DataSetData->item(row, 6)->setFlags(Qt::ItemIsSelectable | Qt::ItemIsEnabled);
		//m_ModelIED_DataSetData->item(row, 7)->setFlags(Qt::ItemIsSelectable | Qt::ItemIsEnabled);
	}
	else if (state == 0)
	{
		m_ModelIED_DataSetData->setData(m_ModelIED_DataSetData->index(row, 0), QVariant(row));
		m_ModelIED_DataSetData->setData(m_ModelIED_DataSetData->index(row, 1), QVariant(strIEDname));
		m_ModelIED_DataSetData->setData(m_ModelIED_DataSetData->index(row, 2), QVariant(do_Reference));
		m_ModelIED_DataSetData->setData(m_ModelIED_DataSetData->index(row, 3), QVariant(m_data.B_daName));
		m_ModelIED_DataSetData->setData(m_ModelIED_DataSetData->index(row, 4), QVariant(m_data.B_fc));
		//m_ModelIED_DataSetData->setData(m_ModelIED_DataSetData->index(row, 5), QVariant(m_data.B_dU));
		m_ModelIED_DataSetData->setData(m_ModelIED_DataSetData->index(row, 5), QVariant(m_data.B_DOdesc));
		//m_ModelIED_DataSetData->setData(m_ModelIED_DataSetData->index(row, 6), QVariant(m_data.B_sAddr));
		m_ModelIED_DataSetData->item(row, 0)->setFlags(Qt::ItemIsSelectable | Qt::ItemIsEnabled);
		m_ModelIED_DataSetData->item(row, 1)->setFlags(Qt::ItemIsSelectable | Qt::ItemIsEnabled);
		m_ModelIED_DataSetData->item(row, 2)->setFlags(Qt::ItemIsSelectable | Qt::ItemIsEnabled);
		m_ModelIED_DataSetData->item(row, 3)->setFlags(Qt::ItemIsSelectable | Qt::ItemIsEnabled);
		m_ModelIED_DataSetData->item(row, 4)->setFlags(Qt::ItemIsSelectable | Qt::ItemIsEnabled);
		m_ModelIED_DataSetData->item(row, 5)->setFlags(Qt::ItemIsSelectable | Qt::ItemIsEnabled);
		//m_ModelIED_DataSetData->item(row, 6)->setFlags(Qt::ItemIsSelectable | Qt::ItemIsEnabled);

		//m_ModelIED_DataSetData->item(row, 7)->setFlags(Qt::ItemIsSelectable | Qt::ItemIsEnabled);
	}
}
void MainWindow::CreatFCDAList(QVector<DataMatrix_Struct> Map1, QVector<FCDA_Struct>Map2, QVector<FCDA_Struct>&List)
{
	for (int i = 0; i < Map2.size(); i++)
	{
		for (int j = 0; j < Map1.size(); j++)
		{
			QString str1, str2;
			str1 = Map1[j].B_doName;
			str2 = Map2[i].B_doName;
			if (Map1[j].B_doName == Map2[i].B_doName)
			{
				List.append(Map2[i]);
				break;
			}
		}
	}

}
void MainWindow::DelDataSet()
{
	QModelIndex index;
	QModelIndexList indexes;
	QString strSet;
	QString strLD, strLN;
	strLD = ui->comboBox_LD->currentText().split(":").at(1);
	strLN = ui->comboBox_LN->currentText();
	m_ModelSlection = ui->tableView->selectionModel();
	indexes.clear();
	indexes = m_ModelSlection->selectedRows();
	if (indexes.size() == 0)
	{
		return;
	}
	QMessageBox msgBox;
	msgBox.setText(tr("Delete DataSet"));
	msgBox.setInformativeText(tr("Do you want to delete the dataset?"));
	msgBox.setStandardButtons(QMessageBox::Yes | QMessageBox::No);
	msgBox.setDefaultButton(QMessageBox::Yes);
	int ret = msgBox.exec();
	if (ret == QMessageBox::Yes)
	{
		foreach(index, indexes)
		{
			strSet = m_ModelIED_DataSet->data(m_ModelIED_DataSet->index(index.row(), 0)).toString();
			m_SCDPoint->DelOneDataSet(strIEDname, strLD, strLN, strSet);
			m_ModelIED_DataSet->removeRow(index.row());
			Reversion_Flag = 1;

		}
	}

}
