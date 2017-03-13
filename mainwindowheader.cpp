#include"mainwindow.h"
#include"ui_mainwindow.h"

void MainWindow::DisplayHeader(QString str)
{
		
        Get_History(str);
        //m_ModelHeader->clear();
        m_ModelHeader->setRowCount(0);
		ClearTableDelegate(headerList.size());
        ui->tableView->setSelectionBehavior(QAbstractItemView::SelectRows);
        ui->tableView->setSelectionMode(QAbstractItemView::SingleSelection);
        disconnect(m_ModelHeader,SIGNAL(dataChanged(const QModelIndex &,const QModelIndex &)),this,SLOT(OnHeaderDataChanged(const QModelIndex &,const QModelIndex &)));

        for(int i =0;i<HistoryItemList.size();i++)
        {
            m_ModelHeader->setRowCount(m_ModelHeader->rowCount()+1);
            AddOneHistoryToTable(i,HistoryItemList[i]);
        }
		ui->tableView->horizontalHeader()->setSectionResizeMode(QHeaderView::Interactive);

        connect(m_ModelHeader,SIGNAL(dataChanged(const QModelIndex &,const QModelIndex &)),this,SLOT(OnHeaderDataChanged(const QModelIndex &,const QModelIndex &)));

}
void MainWindow::Get_History(QString str)
{
    int recordcount = m_SCDPoint->GetChildNum();
	HistoryItemList.clear();
    for(int i=0;i<recordcount;i++)
    {
        HistoryItem m_historyItem;
        m_historyItem.s_Version = m_SCDPoint->GetAttribute(i,"version");
        m_historyItem.s_Reversion = m_SCDPoint->GetAttribute(i,"revision");
        m_historyItem.s_Time = m_SCDPoint->GetAttribute(i,"when");
        m_historyItem.s_Who = m_SCDPoint->GetAttribute(i,"who");
        m_historyItem.s_What = m_SCDPoint->GetAttribute(i,"what");
        m_historyItem.s_Reason = m_SCDPoint->GetAttribute(i,"why");
        HistoryItemList.append(m_historyItem);
    }
}
void MainWindow::AddOneHistoryToTable(int row, HistoryItem Item)
{
    m_ModelHeader->setData(m_ModelHeader->index(row,0),QVariant(Item.s_Version));
    m_ModelHeader->setData(m_ModelHeader->index(row,1),QVariant(Item.s_Reversion));
    m_ModelHeader->setData(m_ModelHeader->index(row,2),QVariant(Item.s_Time));
    m_ModelHeader->setData(m_ModelHeader->index(row,3),QVariant(Item.s_Who));
    m_ModelHeader->setData(m_ModelHeader->index(row,4),QVariant(Item.s_What));
    m_ModelHeader->setData(m_ModelHeader->index(row,5),QVariant(Item.s_Reason));
//	m_ModelHeader->item(row, 0)->setFlags(Qt::ItemIsSelectable | Qt::ItemIsEnabled);
//	m_ModelHeader->item(row, 1)->setFlags(Qt::ItemIsSelectable | Qt::ItemIsEnabled);
    m_ModelHeader->item(row, 2)->setFlags(Qt::ItemIsSelectable | Qt::ItemIsEnabled);


}
void MainWindow::OnHeaderDataChanged(const QModelIndex & topLeft, const QModelIndex & bottomRight)
{
    int istartrow,istartcolumn,iendrow,iendcolumn;
    istartrow=topLeft.row();
    istartcolumn=topLeft.column();
    iendrow=bottomRight.row();
    iendcolumn=bottomRight.column();
    QString str1,str2,str3;
    HistoryItem m_Item;
    int recode;
	m_Item.s_Version = m_ModelHeader->data(m_ModelHeader->index(istartrow, 0)).toString();
	m_Item.s_Reversion = m_ModelHeader->data(m_ModelHeader->index(istartrow, 1)).toString();
	m_Item.s_Time = m_ModelHeader->data(m_ModelHeader->index(istartrow, 2)).toString();
	m_Item.s_Who = m_ModelHeader->data(m_ModelHeader->index(istartrow, 3)).toByteArray();
	m_Item.s_What = m_ModelHeader->data(m_ModelHeader->index(istartrow, 4)).toByteArray();
	m_Item.s_Reason = m_ModelHeader->data(m_ModelHeader->index(istartrow, 5)).toByteArray();
	m_SCDPoint->UpdataHistoryItem(CurrentHistoryItem, m_Item);
//    str1 = headerList[istartcolumn];

//    str2 = m_ModelHeader->data(topLeft,Qt::EditRole).toString();
//	ui->tableView->selectionModel()->clear();

//    QByteArray data =m_ModelHeader->data(topLeft,Qt::EditRole).toByteArray();
//	recode = m_SCDPoint->UpdataAttribute(iendrow, str1, data);
//    Change_Flag = 1;

//    if(recode==DO_FAIL)
//    {
//        QMessageBox::about(0,tr("Alarm"),tr("Modify Value  false!"));
//    }

}
