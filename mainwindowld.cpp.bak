#include"mainwindow.h"
#include"ui_mainwindow.h"
void MainWindow::Init_LogicDevice()
{
    ui->comboBox_LD->setEnabled(false);
    ui->comboBox_LN->setEnabled(false);
	headerList.clear();
    headerList << tr("Access Point") << tr("LD Name") << tr("Desc");


    ui->tableView->setSelectionBehavior(QAbstractItemView::SelectRows); //设置选择行为，以行为单位
	ui->tableView->setSelectionMode(QAbstractItemView::SingleSelection); //设置选择模式，选择单行
	m_ModelIED_LD->clear();
	ClearTableDelegate(headerList.size());
	disconnect(m_ModelIED_LD, SIGNAL(dataChanged(const QModelIndex &, const QModelIndex &)), this, SLOT(OnLDDataChanged(const QModelIndex &, const QModelIndex &)));
	m_ModelIED_LD->setColumnCount(headerList.count());

	ui->tableView->setModel(m_ModelIED_LD);
	for (int i = 0; i < headerList.count(); i++)
	{
		m_ModelIED_LD->setHeaderData(i, Qt::Horizontal, headerList.at(i));
		ui->tableView->setItemDelegateForColumn(i, ui->tableView->itemDelegateForColumn(0));
	}

    ui->tableView->setColumnWidth(0, 200);
    ui->tableView->setColumnWidth(1, 200);
    ui->tableView->setColumnWidth(2, 200);
    ui->tableView->horizontalHeader()->setSectionResizeMode(QHeaderView::ResizeToContents);

	connect(m_ModelIED_LD, SIGNAL(dataChanged(const QModelIndex &, const QModelIndex &)), this, SLOT(OnLDDataChanged(const QModelIndex &, const QModelIndex &)));

}
void MainWindow::GetOneLogicDevice()
{

}
void MainWindow::DisplayLD()
{
	disconnect(m_ModelIED_LD, SIGNAL(dataChanged(const QModelIndex &, const QModelIndex &)), this, SLOT(OnLDDataChanged(const QModelIndex &, const QModelIndex &)));
	QVector<AP_LD> LD_Vector;
	m_ModelIED_LD->setRowCount(0);
    ui->comboBox_LD->clear();
    ui->comboBox_LN->clear();
	m_SCDPoint->GetLDList(strIEDname, LD_Vector);
	m_ModelIED_LD->setRowCount(LD_Vector.size());
	for (int i = 0; i < LD_Vector.size(); i++)
	{
		m_ModelIED_LD->setData(m_ModelIED_LD->index(i, 0), LD_Vector.at(i).AP);

		m_ModelIED_LD->setData(m_ModelIED_LD->index(i, 1), LD_Vector.at(i).LD);

		m_ModelIED_LD->setData(m_ModelIED_LD->index(i, 2), LD_Vector.at(i).Dese);
		m_ModelIED_LD->item(i, 0)->setFlags(Qt::ItemIsSelectable | Qt::ItemIsEnabled);
		m_ModelIED_LD->item(i, 1)->setFlags(Qt::ItemIsSelectable | Qt::ItemIsEnabled);
	}
	//if (m_SCDPoint->GetChild("AccessPoint") == DO_OK)
	//{
	//	QString strAp = m_SCDPoint->GetAttribute("name");
	//	AddLDToTable(strAp);
	//}
	//while (m_SCDPoint->GetNextChild() == DO_OK)
	//{
	//	QString strAp = m_SCDPoint->GetAttribute("name");
	//	AddLDToTable(strAp);
	//}
	connect(m_ModelIED_LD, SIGNAL(dataChanged(const QModelIndex &, const QModelIndex &)), this, SLOT(OnLDDataChanged(const QModelIndex &, const QModelIndex &)));

}
void MainWindow::AddOneLDToTable(int row)
{
	QString strvalue;
	strvalue = m_SCDPoint->GetAttribute("inst");
	m_ModelIED_LD->setData(m_ModelIED_LD->index(row, 1), QVariant(strvalue));
	strvalue=m_SCDPoint->GetAttribute("desc");
	m_ModelIED_LD->setData(m_ModelIED_LD->index(row, 2), QVariant(strvalue));
	m_ModelIED_LD->item(row, 0)->setFlags(Qt::ItemIsSelectable | Qt::ItemIsEnabled);
	m_ModelIED_LD->item(row, 1)->setFlags(Qt::ItemIsSelectable | Qt::ItemIsEnabled);
    //m_ModelIED_LD->item(row, 2)->setFlags(Qt::ItemIsSelectable | Qt::ItemIsEnabled);
}
void MainWindow::AddLDToTable(QString strAp)
{
    m_SCDPoint->SetRememberEle();
	m_SCDPoint->GetChild("Server");
	//m_SCDPoint->GetChild("Authentication");

	if (m_SCDPoint->GetChild("LDevice") == DO_OK)
	{
		m_ModelIED_LD->setRowCount(m_ModelIED_LD->rowCount() + 1);
		//int m = m_ModelIED_LD->rowCount();
		m_ModelIED_LD->setData(m_ModelIED_LD->index(m_ModelIED_LD->rowCount() - 1, 0), QVariant(strAp));
		AddOneLDToTable(m_ModelIED_LD->rowCount() - 1);
	}
	else
	{
		return;
	}
	while (m_SCDPoint->GetNextChild() == DO_OK)
	{
		m_ModelIED_LD->setRowCount(m_ModelIED_LD->rowCount() + 1);
		int m = m_ModelIED_LD->rowCount();
		m_ModelIED_LD->setData(m_ModelIED_LD->index(m_ModelIED_LD->rowCount()-1, 0), QVariant(strAp));
		AddOneLDToTable(m_ModelIED_LD->rowCount() - 1);
	}
    m_SCDPoint->switchRememberEle();
//	m_SCDPoint->SwitchParent();
//	m_SCDPoint->SwitchParent();
}
void MainWindow::OnLDDataChanged(const QModelIndex & topLeft, const QModelIndex & bottomRight)
{
	int istartrow, istartcolumn, iendrow, iendcolumn;
	istartrow = topLeft.row();
	istartcolumn = topLeft.column();
	iendrow = bottomRight.row();
	iendcolumn = bottomRight.column();
    QString strDesc;
    QString strLD;
    strLD = m_ModelIED_LD->data(m_ModelIED_LD->index(istartrow, 1), Qt::EditRole).toString();
    strDesc = m_ModelIED_LD->data(m_ModelIED_LD->index(istartrow, 2), Qt::EditRole).toString();
	int recode;
    recode = m_SCDPoint->UpdataLDDesc(strIEDname,strLD,strDesc);
	if (recode == DO_OK)
	{
        Change_Flag = 1;
        Reversion_Flag=1;
	}
	if (recode == DO_FAIL)
	{
		QMessageBox::about(0, tr("Alarm"), tr("Modify Value  false!"));
	}

}
