#include"mainwindow.h"
#include"ui_mainwindow.h"
#include"rptchange.h"
void MainWindow::Init_Report()
{
	headerList.clear();
	headerList << tr("name") << tr("datSet") << tr("intgPd") << tr("rptID") << tr("confRev") << tr("buffered") << tr("buftime") << tr("TrgOps") << tr("OptFields") << tr("RptEnabled") << tr("desc");
	ui->tableView->setSelectionBehavior(QAbstractItemView::SelectRows);
	m_ModelIED_Report->clear();
	ClearTableDelegate(headerList.size());

	disconnect(m_ModelIED_Report, SIGNAL(dataChanged(const QModelIndex &, const QModelIndex &)), this, SLOT(OnRptDataChanged(const QModelIndex &, const QModelIndex &)));
	m_ModelIED_Report->setColumnCount(headerList.count());

	ui->tableView->setModel(m_ModelIED_Report);
	for (int i = 0; i < headerList.count(); i++)
	{
		m_ModelIED_Report->setHeaderData(i, Qt::Horizontal, headerList.at(i));
		ui->tableView->setItemDelegateForColumn(i, ui->tableView->itemDelegateForColumn(0));
	}
	BOOLTypeCombox *boolcombox = new BOOLTypeCombox(this);
	ui->tableView->setItemDelegateForColumn(5, boolcombox);

	connect(m_ModelIED_Report, SIGNAL(dataChanged(const QModelIndex &, const QModelIndex &)), this, SLOT(OnRptDataChanged(const QModelIndex &, const QModelIndex &)));
	ui->tableView->horizontalHeader()->setSectionResizeMode(QHeaderView::Interactive);


}
void MainWindow::OnRptDataChanged(const QModelIndex & topLeft, const QModelIndex & bottomRight)
{
	disconnect(m_ModelIED_Report, SIGNAL(dataChanged(const QModelIndex &, const QModelIndex &)), this, SLOT(OnRptDataChanged(const QModelIndex &, const QModelIndex &)));

	int istartrow, istartcolumn, iendrow, iendcolumn;
	istartrow = topLeft.row();
	istartcolumn = topLeft.column();
	iendrow = bottomRight.row();
	iendcolumn = bottomRight.column();
	RPT_CTRLStruct m_data;
	QString str = ui->comboBox_LD->currentText();
	QStringList strlist;
	strlist = str.split(":");
	QString strap, strld, strln;
	strap = strlist[0];
	strld = strlist[1];
	strln = ui->comboBox_LN->currentText();
	GetRPTFromTable(istartrow, &m_data);
	for (int i = 0; i < m_ModelIED_Report->rowCount(); i++)
	{
		str.clear();
		if (istartrow==i)
		{
			continue;
		}
		str = m_ModelIED_Report->data(m_ModelIED_Report->index(i, 1)).toString();
		if (str == m_data.B_datSet)
		{
			QMessageBox::about(this, tr("Notice"), tr("The dataset name =%1 was exist").arg(str));
			ui->comboBox_LD->activated(ui->comboBox_LD->currentText());
			connect(m_ModelIED_Report, SIGNAL(dataChanged(const QModelIndex &, const QModelIndex &)), this, SLOT(OnRptDataChanged(const QModelIndex &, const QModelIndex &)));
			return;
		}
	}
	if (strRPTname != m_data.B_datSet)
	{
		m_data.B_confRev = "1";
	}
	if (m_data.B_buffered == "false")
	{
		m_data.B_buftime = "0";
		str.clear();
		str += m_data.B_datSet.at(0);
		str += m_data.B_datSet.at(1);
		if (str.contains("ds", Qt::CaseInsensitive))
		{
			str.clear();
			str = m_data.B_datSet;
			str.remove(0, 2);
		}else
		{
			str.clear();
			str = m_data.B_datSet;
		}
		str = "urcb" + str;
		m_data.B_name = str;
		m_data.B_rptID = str;
	}
	else if (m_data.B_buffered == "true")
	{
		str.clear();
		str += m_data.B_datSet.at(0);
		str += m_data.B_datSet.at(1);
		if (str.contains("ds", Qt::CaseInsensitive))
		{
			str.clear();
			str = m_data.B_datSet;
			str.remove(0, 2);
		}else
		{
			str.clear();
			str = m_data.B_datSet;
		}
		str = "brcb" + str;
		m_data.B_name = str;
		m_data.B_rptID = str;
	}
	int recode;
	recode = m_SCDPoint->UpdataOneRPTCtrl(strIEDname, strld, strln, m_data, strRPTname);
	if (recode == DO_FAIL)
	{
		QMessageBox::about(this, tr("Notice"), tr("The RPT  name =%1 was exist").arg(strRPTname));
		ui->comboBox_LD->activated(ui->comboBox_LD->currentText());
		connect(m_ModelIED_Report, SIGNAL(dataChanged(const QModelIndex &, const QModelIndex &)), this, SLOT(OnRptDataChanged(const QModelIndex &, const QModelIndex &)));

		return;
	}
	Reversion_Flag = 1;
	ui->comboBox_LD->activated(ui->comboBox_LD->currentText());
	connect(m_ModelIED_Report, SIGNAL(dataChanged(const QModelIndex &, const QModelIndex &)), this, SLOT(OnRptDataChanged(const QModelIndex &, const QModelIndex &)));

	return;
}
void MainWindow::DisplayRPT()
{
	disconnect(m_ModelIED_Report, SIGNAL(dataChanged(const QModelIndex &, const QModelIndex &)), this, SLOT(OnRptDataChanged(const QModelIndex &, const QModelIndex &)));
	QString str = ui->comboBox_LD->currentText();
	QStringList strlist;
	strlist = str.split(":");
	QString strap, strld, strln;
	strap = strlist[0];
	strld = strlist[1];
	QVector<RPT_CTRLStruct> RPT_List;
	m_ModelIED_Report->setRowCount(0);
	strln = ui->comboBox_LN->currentText();
	datasetlist.clear();
	m_SCDPoint->GetDataSetList(strIEDname, strld, strln, datasetlist);
	int i = 0;
	while (i < datasetlist.size())
	{
		if (datasetlist.at(i).contains("goose", Qt::CaseInsensitive) || datasetlist.at(i).contains("log", Qt::CaseInsensitive))
		{
			datasetlist.removeAt(i);
			i = 0;
		}
		else
		{
			i++;
		}
	}
	ListCombox *listcombox = new ListCombox(this);
	listcombox->list = datasetlist;
	ui->tableView->setItemDelegateForColumn(1, listcombox);

	m_SCDPoint->GetRPTList(strIEDname, strld, strln, RPT_List);
	m_ModelIED_Report->setRowCount(RPT_List.size());
	for (int i = 0; i < RPT_List.size(); i++)
	{
		AddOneRPTToTable(i, RPT_List[i]);
	}
	connect(m_ModelIED_Report, SIGNAL(dataChanged(const QModelIndex &, const QModelIndex &)), this, SLOT(OnRptDataChanged(const QModelIndex &, const QModelIndex &)));

	return;

}

void MainWindow::AddOneRPTToTable(int row, RPT_CTRLStruct &data)
{
	QString strvalue;
	strvalue.clear();
	m_ModelIED_Report->setData(m_ModelIED_Report->index(row, 0), QVariant(data.B_name));
	m_ModelIED_Report->item(row, 0)->setFlags(Qt::ItemIsSelectable | Qt::ItemIsEnabled);
	//if ((RPT_STATE&CBNAME_ENA) != CBNAME_ENA)
	//{
	//	m_ModelIED_Report->item(row, 0)->setFlags(Qt::ItemIsSelectable | Qt::ItemIsEnabled);
	//}
	m_ModelIED_Report->setData(m_ModelIED_Report->index(row, 1), QVariant(data.B_datSet));
	if ((RPT_STATE&DATASET_ENA) != DATASET_ENA)
	{
		m_ModelIED_Report->item(row, 1)->setFlags(Qt::ItemIsSelectable | Qt::ItemIsEnabled);
	}
	m_ModelIED_Report->setData(m_ModelIED_Report->index(row, 2), QVariant(data.B_intgPd));

	//if ((RPT_STATE&INTGPD_ENA) != INTGPD_ENA)
	//{
	//	m_ModelIED_Report->item(row, 2)->setFlags(Qt::ItemIsSelectable | Qt::ItemIsEnabled);
	//}
	m_ModelIED_Report->setData(m_ModelIED_Report->index(row, 3), QVariant(data.B_rptID));
	m_ModelIED_Report->item(row, 3)->setFlags(Qt::ItemIsSelectable | Qt::ItemIsEnabled);
	//if ((RPT_STATE&RPTID_ENA) != RPTID_ENA)
	//{
	//	m_ModelIED_Report->item(row, 3)->setFlags(Qt::ItemIsSelectable | Qt::ItemIsEnabled);
	//}
	// m_ModelIED_Report->item(row, 3)->setFlags(Qt::ItemIsSelectable | Qt::ItemIsEnabled);

	m_ModelIED_Report->setData(m_ModelIED_Report->index(row, 4), QVariant(data.B_confRev));
	m_ModelIED_Report->setData(m_ModelIED_Report->index(row, 5), QVariant(data.B_buffered));
	if ((RPT_STATE&BUFTIME_ENA) != BUFTIME_ENA)
	{
		m_ModelIED_Report->item(row, 5)->setFlags(Qt::ItemIsSelectable | Qt::ItemIsEnabled);
	}
	m_ModelIED_Report->setData(m_ModelIED_Report->index(row, 6), QVariant(data.B_buftime));

	if (data.B_buffered == "false")
	{
		m_ModelIED_Report->item(row, 6)->setFlags(Qt::ItemIsSelectable | Qt::ItemIsEnabled);
	}
	strvalue = "dchg=" + data.m_Trgops.B_dchg + ",dupd=" + data.m_Trgops.B_dupd + ",period=" + data.m_Trgops.B_period + ",qchg" + data.m_Trgops.B_qchg;
	m_ModelIED_Report->setData(m_ModelIED_Report->index(row, 7), QVariant(strvalue));

	m_ModelIED_Report->item(row, 7)->setFlags(Qt::ItemIsSelectable | Qt::ItemIsEnabled);

	strvalue = "seqNum=" + data.m_OptFields.B_seqNum + ",timeStamp=" + data.m_OptFields.B_timeStamp + ",dataSet=" + data.m_OptFields.B_dataSet
		+ ",reasonCode=" + data.m_OptFields.B_reasonCode + ",dataRef=" + data.m_OptFields.B_dataRef
		+ ",entryID" + data.m_OptFields.B_entryID + ",configRef=" + data.m_OptFields.B_configRef;

	m_ModelIED_Report->setData(m_ModelIED_Report->index(row, 8), QVariant(strvalue));
	m_ModelIED_Report->item(row, 8)->setFlags(Qt::ItemIsSelectable | Qt::ItemIsEnabled);

	strvalue = "max=" + data.m_RtpEnabled.B_max;
	m_ModelIED_Report->setData(m_ModelIED_Report->index(row, 9), QVariant(strvalue));
	m_ModelIED_Report->setData(m_ModelIED_Report->index(row, 10), QVariant(data.B_desc));

}
void MainWindow::GetRPTFromSCD(RPT_CTRLStruct* data)
{
	data->B_name = m_SCDPoint->GetAttribute("name");
	data->B_rptID = m_SCDPoint->GetAttribute("rptID");
	data->B_datSet = m_SCDPoint->GetAttribute("datSet");
	data->B_intgPd = m_SCDPoint->GetAttribute("intgPd");
	data->B_confRev = m_SCDPoint->GetAttribute("confRev");
	data->B_buffered = m_SCDPoint->GetAttribute("buffered");
	data->B_buftime = m_SCDPoint->GetAttribute("bufTime");
	data->B_desc = m_SCDPoint->GetAttribute("desc");
	m_SCDPoint->GetChild("TrgOps");
	data->m_Trgops.B_dchg = m_SCDPoint->GetAttribute("dchg");
	data->m_Trgops.B_dupd = m_SCDPoint->GetAttribute("dupd");
	data->m_Trgops.B_period = m_SCDPoint->GetAttribute("period");
	data->m_Trgops.B_qchg = m_SCDPoint->GetAttribute("qchg");
	m_SCDPoint->SwitchParent();
	m_SCDPoint->GetChild("OptFields");
	data->m_OptFields.B_seqNum = m_SCDPoint->GetAttribute("seqNum");
	data->m_OptFields.B_timeStamp = m_SCDPoint->GetAttribute("timeStamp");
	data->m_OptFields.B_dataSet = m_SCDPoint->GetAttribute("dataSet");
	data->m_OptFields.B_reasonCode = m_SCDPoint->GetAttribute("reasonCode");
	data->m_OptFields.B_dataRef = m_SCDPoint->GetAttribute("dataRef");
	data->m_OptFields.B_entryID = m_SCDPoint->GetAttribute("entryID");
	data->m_OptFields.B_configRef = m_SCDPoint->GetAttribute("configRef");
	m_SCDPoint->SwitchParent();
	m_SCDPoint->GetChild("RptEnabled");
	data->m_RtpEnabled.B_max = m_SCDPoint->GetAttribute("max");
}
void MainWindow::OnRPTCtrlClicked(const QModelIndex & index)
{
	strRPTname = m_ModelIED_Report->data(m_ModelIED_Report->index(index.row(), 0)).toString();

}
void MainWindow::GetRPTFromTable(int row, RPT_CTRLStruct* data)
{
	QStringList strlist;
	QString str;
	data->B_name = m_ModelIED_Report->data(m_ModelIED_Report->index(row, 0), Qt::EditRole).toString();
	data->B_datSet = m_ModelIED_Report->data(m_ModelIED_Report->index(row, 1), Qt::EditRole).toString();

	data->B_intgPd = m_ModelIED_Report->data(m_ModelIED_Report->index(row, 2), Qt::EditRole).toString();

	data->B_rptID = m_ModelIED_Report->data(m_ModelIED_Report->index(row, 3), Qt::EditRole).toString();

	data->B_confRev = m_ModelIED_Report->data(m_ModelIED_Report->index(row, 4), Qt::EditRole).toString();
	data->B_buffered = m_ModelIED_Report->data(m_ModelIED_Report->index(row, 5), Qt::EditRole).toString();
	data->B_buftime = m_ModelIED_Report->data(m_ModelIED_Report->index(row, 6), Qt::EditRole).toString();

	str = m_ModelIED_Report->data(m_ModelIED_Report->index(row, 7), Qt::EditRole).toString();
	strlist = str.split(",");
	for (int i = 0; i < strlist.size(); i++)
	{
		str = strlist.at(i);
		if (str.contains("dchg"))
		{
			if (str.contains("true"))
			{
				data->m_Trgops.B_dchg = "true";
			}
			else
			{
				data->m_Trgops.B_dchg = "false";
			}
		}
		if (str.contains("dupd"))
		{
			if (str.contains("true"))
			{
				data->m_Trgops.B_dupd = "true";
			}
			else
			{
				data->m_Trgops.B_dupd = "false";
			}
		}
		if (str.contains("period"))
		{
			if (str.contains("true"))
			{
				data->m_Trgops.B_period = "true";
			}
			else
			{
				data->m_Trgops.B_period = "false";
			}
		}
		if (str.contains("qchg"))
		{
			if (str.contains("true"))
			{
				data->m_Trgops.B_qchg = "true";
			}
			else
			{
				data->m_Trgops.B_qchg = "false";
			}
		}
	}
	str = m_ModelIED_Report->data(m_ModelIED_Report->index(row, 8), Qt::EditRole).toString();
	strlist = str.split(",");
	for (int i = 0; i < strlist.size(); i++)
	{
		str = strlist.at(i);
		if (str.contains("seqNum"))
		{
			if (str.contains("true"))
			{
				data->m_OptFields.B_seqNum = "true";
			}
			else
			{
				data->m_OptFields.B_seqNum = "false";
			}
		}
		if (str.contains("timeStamp"))
		{
			if (str.contains("true"))
			{
				data->m_OptFields.B_timeStamp = "true";
			}
			else
			{
				data->m_OptFields.B_timeStamp = "false";
			}
		}
		if (str.contains("dataSet"))
		{
			if (str.contains("true"))
			{
				data->m_OptFields.B_dataSet = "true";
			}
			else
			{
				data->m_OptFields.B_dataSet = "false";
			}
		}
		if (str.contains("reasonCode"))
		{
			if (str.contains("true"))
			{
				data->m_OptFields.B_reasonCode = "true";
			}
			else
			{
				data->m_OptFields.B_reasonCode = "false";
			}
		}
		if (str.contains("dataRef"))
		{
			if (str.contains("true"))
			{
				data->m_OptFields.B_dataRef = "true";
			}
			else
			{
				data->m_OptFields.B_dataRef = "false";
			}
		}
		if (str.contains("entryID"))
		{
			if (str.contains("true"))
			{
				data->m_OptFields.B_entryID = "true";
			}
			else
			{
				data->m_OptFields.B_entryID = "false";
			}
		}
		if (str.contains("configRef"))
		{
			if (str.contains("true"))
			{
				data->m_OptFields.B_configRef = "true";
			}
			else
			{
				data->m_OptFields.B_configRef = "false";
			}
		}

	}
	str = m_ModelIED_Report->data(m_ModelIED_Report->index(row, 9), Qt::EditRole).toString();
	str.remove("max=");
	data->m_RtpEnabled.B_max = str;
	data->B_desc = m_ModelIED_Report->data(m_ModelIED_Report->index(row, 10), Qt::EditRole).toString();

}
void MainWindow::OnRPTCtrldoubleClicked(const QModelIndex & index)
{
	RPT_CTRLStruct m_data;
	GetRPTFromTable(index.row(), &m_data);
	if (index.column() == 7)
	{
		//if (!((RPT_STATE&TRPOPS_ENA) && TRPOPS_ENA))
		//{
		//	return;
		//}

		RptChange *m_dlg = new RptChange(this);
		m_dlg->istate = 1;
		m_dlg->m_Trgops = m_data.m_Trgops;
		m_dlg->init_dlg();
		m_dlg->Displaydata();
		if (m_dlg->exec() == QDialog::Accepted)
		{
			m_data.m_Trgops = m_dlg->m_Trgops;
			AddOneRPTToTable(index.row(), m_data);
		}
		else
		{
			return;
		}
	}
	if (index.column() == 8)
	{
		//if (!((RPT_STATE&OPTFIELDS_ENA) && OPTFIELDS_ENA))
		//{
		//	return;
		//}
		RptChange *m_dlg = new RptChange(this);
		m_dlg->istate = 2;
		m_dlg->m_OptField = m_data.m_OptFields;
		m_dlg->init_dlg();
		m_dlg->Displaydata();
		if (m_dlg->exec() == QDialog::Accepted)
		{
			m_data.m_OptFields = m_dlg->m_OptField;
			AddOneRPTToTable(index.row(), m_data);
		}
		else
		{
			return;
		}
	}
	if (index.column() == 9)
	{
		//if (!((RPT_STATE&INTGPD_ENA) && INTGPD_ENA))
		//{
		//	return;
		//}
		RptChange *m_dlg = new RptChange(this);
		m_dlg->istate = 3;
		m_dlg->m_RptEndabled = m_data.m_RtpEnabled;
		m_dlg->init_dlg();
		m_dlg->Displaydata();
		if (m_dlg->exec() == QDialog::Accepted)
		{
			m_data.m_RtpEnabled = m_dlg->m_RptEndabled;
			AddOneRPTToTable(index.row(), m_data);
		}
		else
		{
			return;
		}
	}


	return;
}
