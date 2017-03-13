#include"mainwindow.h"
#include"ui_mainwindow.h"
void MainWindow::Init_SMV()
{
	headerList.clear();
	headerList << tr("name") << tr("datSet") << tr("confRev") << tr("ASDU NO") << tr("smpRate") << tr("multicast") << tr("smvID") << tr("desc");


	ui->tableView->setSelectionBehavior(QAbstractItemView::SelectRows);
	ui->tableView->setSelectionMode(QAbstractItemView::SingleSelection);
	m_ModelIED_SMV->clear();


	disconnect(m_ModelIED_SMV, SIGNAL(dataChanged(const QModelIndex &, const QModelIndex &)), this, SLOT(OnSMVDataChanged(const QModelIndex &, const QModelIndex &)));
	m_ModelIED_SMV->setColumnCount(headerList.count());

	ui->tableView->setModel(m_ModelIED_SMV);
	for (int i = 0; i < headerList.count(); i++)
	{
		m_ModelIED_SMV->setHeaderData(i, Qt::Horizontal, headerList.at(i));

		ui->tableView->setItemDelegateForColumn(i, ui->tableView->itemDelegateForColumn(0));

	}
	BOOLTypeCombox *gooseCombox = new BOOLTypeCombox(this);
	ui->tableView->setItemDelegateForColumn(5, gooseCombox);
	connect(m_ModelIED_SMV, SIGNAL(dataChanged(const QModelIndex &, const QModelIndex &)), this, SLOT(OnSMVDataChanged(const QModelIndex &, const QModelIndex &)));

	ui->tableView->horizontalHeader()->setSectionResizeMode(QHeaderView::Interactive);

}
void MainWindow::OnSMVDataChanged(const QModelIndex & topLeft, const QModelIndex & bottomRight)
{
	disconnect(m_ModelIED_SMV, SIGNAL(dataChanged(const QModelIndex &, const QModelIndex &)), this, SLOT(OnSMVDataChanged(const QModelIndex &, const QModelIndex &)));

	int istartrow, istartcolumn, iendrow, iendcolumn;
	istartrow = topLeft.row();
	istartcolumn = topLeft.column();
	iendrow = bottomRight.row();
	iendcolumn = bottomRight.column();
	SMV_InstStruct m_data;
	QString str = ui->comboBox_LD->currentText();
	QStringList strlist;
	strlist = str.split(":");
	QString strap, strld, strln;
	strap = strlist[0];
	strld = strlist[1];
	strln = ui->comboBox_LN->currentText();

	int recode;
	GetSMVBLKFromTable(istartrow, m_data);
	if (istartcolumn == 2)
	{
		m_data.B_confRev = "1.0";
	}
	str = m_data.B_datSet;
	str.replace("ds", "smvcb", Qt::CaseInsensitive);
	m_data.B_name = str;
	recode = m_SCDPoint->UpdataOneSMVBLK(strIEDname, strld, strln, m_data, strSMVname);
	if (recode == DO_OK)
	{
		if (strSMVname != m_data.B_name)
		{
			recode = m_SCDPoint->UpdataConnectAPBySMV(strIEDname, strap, strld, strSMVname, m_data);

		}

	}
	if (recode == DO_OK)
	{
		Change_Flag = 1;
		Reversion_Flag = 1;


		// connect(m_ModelIED_SMV, SIGNAL(dataChanged(const QModelIndex &, const QModelIndex &)), this, SLOT(OnSMVDataChanged(const QModelIndex &, const QModelIndex &)));

		//return;
	}
	if (recode == DO_FAIL)
	{
		QMessageBox::about(0, tr("Alarm"), tr("Modify Value  false!,the name or datset must be not repeat"));

		//ui->comboBox_LD->activated(ui->comboBox_LD->currentText());
		return;
	}
	ui->comboBox_LD->activated(ui->comboBox_LD->currentText());
	connect(m_ModelIED_SMV, SIGNAL(dataChanged(const QModelIndex &, const QModelIndex &)), this, SLOT(OnSMVDataChanged(const QModelIndex &, const QModelIndex &)));

}
void MainWindow::DisplaySMV()
{
	disconnect(m_ModelIED_SMV, SIGNAL(dataChanged(const QModelIndex &, const QModelIndex &)), this, SLOT(OnSMVDataChanged(const QModelIndex &, const QModelIndex &)));
	QString str = ui->comboBox_LD->currentText();
	QStringList strlist;
	int index = 0;
	strlist = str.split(":");
	QString strap, strld, strln;
	strap = strlist[0];
	strld = strlist[1];
	strln = ui->comboBox_LN->currentText();
	QVector<SMV_InstStruct>List;
	int recode;
	datasetlist.clear();
	m_ModelIED_SMV->setRowCount(0);
	datasetlist.clear();
	DataSetListCombox *DataSetCombox = new DataSetListCombox(this);
	BOOLTypeCombox *m_boolCombox = new BOOLTypeCombox(this);

	ui->tableView->setItemDelegateForColumn(1, DataSetCombox);
	ui->tableView->setItemDelegateForColumn(5, m_boolCombox);
	m_SCDPoint->GetDataSetList(strIEDname, strld, strln, datasetlist);
	while (index < datasetlist.size())
	{
		if (!datasetlist.at(index).contains("SV", Qt::CaseInsensitive))
		{
			datasetlist.removeAt(index);
			index = 0;
		}
		else
		{
			index++;
		}

	}
	DataSetCombox->DatasetList = datasetlist;
	m_SCDPoint->GetSMVList(strIEDname, strld, strln, List);
	for (int i = 0; i < List.size(); i++)
	{
		m_ModelIED_SMV->setRowCount(i + 1);
		AddOneSMVToTable(i, List[i]);
	}





	connect(m_ModelIED_SMV, SIGNAL(dataChanged(const QModelIndex &, const QModelIndex &)), this, SLOT(OnSMVDataChanged(const QModelIndex &, const QModelIndex &)));

	return;

}
void MainWindow::AddOneSMVToTable(int row)
{
	QString strvalue;
	strvalue = m_SCDPoint->GetAttribute("name");
	strvalue = m_SCDPoint->GetAttribute("datSet");
	strvalue = m_SCDPoint->GetAttribute("confRev");
	strvalue = m_SCDPoint->GetAttribute("nofASDU");
	strvalue = m_SCDPoint->GetAttribute("smpRate");
	strvalue = m_SCDPoint->GetAttribute("multicast");
	strvalue = m_SCDPoint->GetAttribute("desc");
	strvalue = m_SCDPoint->GetAttribute("smvID");

	m_ModelIED_SMV->setData(m_ModelIED_SMV->index(row, 0), QVariant(m_SCDPoint->GetAttribute("name")));
	m_ModelIED_SMV->setData(m_ModelIED_SMV->index(row, 1), QVariant(m_SCDPoint->GetAttribute("datSet")));
	m_ModelIED_SMV->setData(m_ModelIED_SMV->index(row, 2), QVariant(m_SCDPoint->GetAttribute("confRev")));
	m_ModelIED_SMV->setData(m_ModelIED_SMV->index(row, 3), QVariant(m_SCDPoint->GetAttribute("nofASDU")));
	m_ModelIED_SMV->setData(m_ModelIED_SMV->index(row, 4), QVariant(m_SCDPoint->GetAttribute("smpRate")));
	m_ModelIED_SMV->setData(m_ModelIED_SMV->index(row, 5), QVariant(m_SCDPoint->GetAttribute("multicast")));
	m_ModelIED_SMV->setData(m_ModelIED_SMV->index(row, 7), QVariant(m_SCDPoint->GetAttribute("desc")));
	m_ModelIED_SMV->setData(m_ModelIED_SMV->index(row, 6), QVariant(m_SCDPoint->GetAttribute("smvID")));
	m_ModelIED_SMV->item(row, 0)->setFlags(Qt::ItemIsSelectable | Qt::ItemIsEnabled);
	m_ModelIED_SMV->item(row, 6)->setFlags(Qt::ItemIsSelectable | Qt::ItemIsEnabled);


}
void MainWindow::AddOneSMVToTable(int row, SMV_InstStruct &data)
{
	m_ModelIED_SMV->setData(m_ModelIED_SMV->index(row, 0), QVariant(data.B_name));
	m_ModelIED_SMV->setData(m_ModelIED_SMV->index(row, 1), QVariant(data.B_datSet));
	m_ModelIED_SMV->setData(m_ModelIED_SMV->index(row, 2), QVariant(data.B_confRev));
	m_ModelIED_SMV->setData(m_ModelIED_SMV->index(row, 3), QVariant(data.B_nofASDU));
	m_ModelIED_SMV->setData(m_ModelIED_SMV->index(row, 4), QVariant(data.B_smpRate));
	m_ModelIED_SMV->setData(m_ModelIED_SMV->index(row, 5), QVariant(data.B_multicast));
	m_ModelIED_SMV->setData(m_ModelIED_SMV->index(row, 7), QVariant(data.B_desc));
	m_ModelIED_SMV->setData(m_ModelIED_SMV->index(row, 6), QVariant(data.B_smvID));
	m_ModelIED_SMV->item(row, 6)->setFlags(Qt::ItemIsSelectable | Qt::ItemIsEnabled);
	m_ModelIED_SMV->item(row, 0)->setFlags(Qt::ItemIsSelectable | Qt::ItemIsEnabled);

}

void MainWindow::AddOneSMVCTRL()
{

	QString str = ui->comboBox_LD->currentText();
	QStringList strlist;
	strlist = str.split(":");
	QString strap, strld, strln;
	strap = strlist[0];
	strld = strlist[1];
	strln = ui->comboBox_LN->currentText();
	SMV_InstStruct m_Data;
	int recode = m_SCDPoint->AddOneSMVCtrl(strIEDname, strld, strln, datasetlist, m_Data);
	if (recode == DO_OK)
	{
		Reversion_Flag = 1;
		recode = m_SCDPoint->AddConnectAPBySMV(strIEDname, strap, strld, m_Data);
	}


	ui->comboBox_LD->activated(ui->comboBox_LD->currentText());
	//GetSMVBLKFromTable(m_ModelIED_SMV->rowCount()-1,m_Data);


}
void MainWindow::DelOneSMVCTRL()
{
	QModelIndex index;
	QModelIndexList indexes;
	QString str = ui->comboBox_LD->currentText();
	QStringList strlist;
	strlist = str.split(":");
	QString strap, strld, strln;
	strap = strlist[0];
	strld = strlist[1];
	strln = ui->comboBox_LN->currentText();
	m_ModelSlection = ui->tableView->selectionModel();
	indexes.clear();
	indexes = m_ModelSlection->selectedRows();
	if (indexes.size() == 0)
	{

		return;
	}
	foreach(index, indexes)
	{
		SMV_InstStruct m_Data;
		GetSMVBLKFromTable(index.row(), m_Data);
		//QMessageBox::about(0, tr("Notice"), m_Data.B_datSet);
		m_SCDPoint->DelOneSMVBlK(strIEDname, strld, strln, m_Data.B_name);
		m_SCDPoint->DelConnectAPBySMV(strIEDname, strap, strld, m_Data);

	}
	Reversion_Flag = 1;
	ui->comboBox_LD->activated(ui->comboBox_LD->currentText());

}
void MainWindow::OnSMVCtrlClicked(const QModelIndex & index)
{
	strSMVname = m_ModelIED_SMV->data(m_ModelIED_SMV->index(index.row(), 0)).toString();

}
void MainWindow::GetSMVBLKFromTable(int row, SMV_InstStruct &data)
{
	data.B_name = m_ModelIED_SMV->data(m_ModelIED_SMV->index(row, 0), Qt::EditRole).toString();

	data.B_datSet = m_ModelIED_SMV->data(m_ModelIED_SMV->index(row, 1), Qt::EditRole).toString();
	data.B_confRev = m_ModelIED_SMV->data(m_ModelIED_SMV->index(row, 2), Qt::EditRole).toString();
	data.B_nofASDU = m_ModelIED_SMV->data(m_ModelIED_SMV->index(row, 3), Qt::EditRole).toString();
	data.B_smpRate = m_ModelIED_SMV->data(m_ModelIED_SMV->index(row, 4), Qt::EditRole).toString();
	data.B_multicast = m_ModelIED_SMV->data(m_ModelIED_SMV->index(row, 5), Qt::EditRole).toString();
	data.B_desc = m_ModelIED_SMV->data(m_ModelIED_SMV->index(row, 7), Qt::EditRole).toString();
	data.B_smvID = m_ModelIED_SMV->data(m_ModelIED_SMV->index(row, 6), Qt::EditRole).toString();


}
