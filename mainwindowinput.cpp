﻿#include"mainwindow.h"
#include"ui_mainwindow.h"
void MainWindow::Init_Input()
{

    headerList.clear();
    headerList << tr("intAddr")  << tr("intDesc") << tr("exIED")<< tr("exAddr") << tr("exDesc");
    ui->tableView->setSelectionBehavior(QAbstractItemView::SelectRows);
    //ui->tableView->setAcceptDrops(true);
    m_ModelIED_Input->clear();

	ClearTableDelegate(headerList.size());
   // disconnect(m_ModelIED_Log, SIGNAL(dataChanged(const QModelIndex &, const QModelIndex &)), this, SLOT(OnLogDataChanged(const QModelIndex &, const QModelIndex &)));
    m_ModelIED_Input->setColumnCount(headerList.count());
    //BOOLTypeCombox *boolcombox = new BOOLTypeCombox(this);
    //ui->tableView->setItemDelegateForColumn(5, boolcombox);
    ui->tableView->setModel(m_ModelIED_Input);
    for (int i = 0; i < headerList.count(); i++)
    {
        m_ModelIED_Input->setHeaderData(i, Qt::Horizontal, headerList.at(i));
		ui->tableView->setItemDelegateForColumn(i, ui->tableView->itemDelegateForColumn(0));
    }

	ui->tableView->horizontalHeader()->setSectionResizeMode(QHeaderView::Interactive);


}
void MainWindow::DisplayInput()
{
    QString str = ui->comboBox_LD->currentText();
    QStringList strlist;
    strlist = str.split(":");
    QString strap, strld,strln;
    strap = strlist[0];
    strld = strlist[1];
    strln =ui->comboBox_LN->currentText();
    int recode;

    m_ModelIED_Input->setRowCount(0);
 //   recode = m_SCDPoint->GetAccessPoint(strap);
 //   recode = m_SCDPoint->GetChild("Server");
 //   if (m_SCDPoint->GetChildByname_value("LDevice", "inst", strld) != DO_OK)
 //   {
 //       m_SCDPoint->SwitchToIED();
 //       return;
 //   }
	//recode = m_SCDPoint->GetLNnode(strln);
	recode = m_SCDPoint->SwitchToNode(strIEDname, strld, strln);
    recode = m_SCDPoint->GetChild("Inputs");
    recode = m_SCDPoint->GetChild("ExtRef");
    if(recode!=DO_OK)
    {
        m_SCDPoint->SwitchToIED();
        return;
    }
    //m_SCDPoint->SetRememberEle();
    Input_Struct m_data;
	bool flag=true;
	flag= GetInputFromSCD(&m_data);
    //m_SCDPoint->switchRememberEle();
    m_ModelIED_Input->setRowCount(m_ModelIED_Input->rowCount() + 1);
	if (flag==true)
	{
		AddOneInputToTable(m_ModelIED_Input->rowCount() - 1, m_data);
	}
  

    while (m_SCDPoint->GetNextChild("ExtRef") == DO_OK)
    {
        Input_Struct m_data;
		flag = true;
        //m_SCDPoint->SetRememberEle();
		flag=GetInputFromSCD(&m_data);
        //m_SCDPoint->switchRememberEle();
        m_ModelIED_Input->setRowCount(m_ModelIED_Input->rowCount() + 1);
		if (flag==true)
		{
			AddOneInputToTable(m_ModelIED_Input->rowCount() - 1, m_data);
		}
        

    }
    m_SCDPoint->SwitchToIED();

    return;
}
bool MainWindow::GetInputFromSCD(Input_Struct* data)
{
    data->B_daName = m_SCDPoint->GetAttribute("daName");
	if (data->B_daName.isEmpty())
	{
		return false;
	}
    data->B_doName = m_SCDPoint->GetAttribute("doName");
	if (data->B_daName.isEmpty())
	{
		return false;
	}
    data->B_iedName = m_SCDPoint->GetAttribute("iedName");
	if (data->B_daName.isEmpty())
	{
		return false;
	}
    data->B_intAddr = m_SCDPoint->GetAttribute("intAddr");
	if (data->B_daName.isEmpty())
	{
		return false;
	}
    data->B_ldInst = m_SCDPoint->GetAttribute("ldInst");
	if (data->B_daName.isEmpty())
	{
		return false;
	}
    data->B_lnClass = m_SCDPoint->GetAttribute("lnClass");
    data->B_lnInst = m_SCDPoint->GetAttribute("lnInst");
    data->B_prefix = m_SCDPoint->GetAttribute("prefix");
	if (QString(data->B_lnClass + data->B_lnInst + data->B_prefix).isEmpty())
	{
		return false;
	}
	m_SCDPoint->SetRememberEle();

	data->B_intDesc = m_SCDPoint->GetSpecifytvalue(strIEDname, data->B_intAddr, "desc");
	m_SCDPoint->switchRememberEle();

	QString str;
	m_SCDPoint->SetRememberEle();
	if (data->B_daName.isEmpty())
	{
		str = data->B_ldInst + "/" + data->B_prefix + data->B_lnClass + data->B_lnInst + "." + data->B_doName;
	}
	else
	{
		str = data->B_ldInst + "/" + data->B_prefix + data->B_lnClass + data->B_lnInst + "." + data->B_doName + "." + data->B_daName;

	}
    //data->B_exDesc = m_SCDPoint->GetSpecifytvalue(data->B_iedName, str, "desc");
	data->B_exDesc = m_SCDPoint->GetDescFromSpecifNode(data->B_iedName, data->B_ldInst, data->B_prefix + data->B_lnClass + data->B_lnInst, data->B_doName);

    m_SCDPoint->switchRememberEle();

	return true;
}

void MainWindow::GetInputFromTable(int row,Input_Struct* data)
{

}
void MainWindow::AddOneInputToTable(int row,Input_Struct &data)
{
    QString str;
    // str = data.B_ldInst+"/"+data.B_prefix+data.B_lnInst+"."+data.B_doName+"."+data.B_daName;
	 if (!data.B_daName.isEmpty())
	 {
         str = data.B_ldInst + "/" + data.B_prefix + data.B_lnClass + data.B_lnInst + "." + data.B_doName + "." + data.B_daName;

	 }
	 else
	 {
         str = data.B_ldInst + "/" + data.B_prefix + data.B_lnClass + data.B_lnInst + "." + data.B_doName;

	 }
    m_ModelIED_Input->setData(m_ModelIED_Input->index(row, 2), QVariant(data.B_iedName));
    m_ModelIED_Input->setData(m_ModelIED_Input->index(row, 3), QVariant(str));
    m_ModelIED_Input->setData(m_ModelIED_Input->index(row, 4), QVariant(data.B_exDesc));
    m_ModelIED_Input->setData(m_ModelIED_Input->index(row, 0), QVariant(data.B_intAddr));
    m_ModelIED_Input->setData(m_ModelIED_Input->index(row, 1), QVariant(data.B_intDesc));
}
