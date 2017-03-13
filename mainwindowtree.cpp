#include"mainwindow.h"
#include "ui_mainwindow.h"
void MainWindow::Init_Tree()
{

    ui->splitter_2->setStretchFactor(0, 40);
    ui->splitter_2->setStretchFactor(1, 55);
    ui->splitter_2->setStretchFactor(2, 5);
    ui->mainToolBar->hide();
    ui->checkBox_DA_END->hide();
    ui->Button_DataSet->hide();
    ui->Button_GSE->hide();
    ui->Button_Input->hide();
    ui->Button_Log->hide();
    ui->Button_LogicDevice->hide();
    ui->Button_LogiceNode->hide();
    ui->Button_Report->hide();
    ui->Button_SMV->hide();
    ui->Button_Add->hide();
    ui->Button_Del->hide();
    ui->SubstationTree->hide();
    ui->pushButton_Addres->hide();
    ui->pushButton_GSE->hide();
    ui->pushButton_SMV->hide();
    ui->label_LD->hide();
    ui->label_LN->hide();
    ui->comboBox_LD->hide();
    ui->comboBox_LN->hide();
    ui->tableView_data->hide();
    ui->frame->hide();
    int i =ui->Tree->topLevelItemCount();
    if(ui->Tree->topLevelItemCount()!=0)
        return;
    ui->Tree->setColumnCount(2);
    headerList.clear();
    headerList << tr("attribue") << tr("value") ;
    ui->tableView->setSelectionBehavior(QAbstractItemView::SelectItems); //设置选择行为，以行为单位
    ui->tableView->setSelectionMode(QAbstractItemView::SingleSelection); //设置选择模式，选择单行
    m_ModelTree->setColumnCount(headerList.size());
    for (int i = 0; i < headerList.count(); i++)
    {
        m_ModelTree->setHeaderData(i, Qt::Horizontal, headerList.at(i));
    }
    ui->tableView->setModel(m_ModelTree);
    ui->tableView->setColumnWidth(0,200);
     ui->tableView->setColumnWidth(1,400);
    if(m_SCDPoint!=NULL)
    {
        m_SCDPoint->AddRoot_Node(ui->Tree);

    }

}
 void MainWindow::Action_currentChanged(int index)
 {
        if(index==0)
        {
            Init();
        }else if(index==1)
        {
            Init_Tree();
            //ui->Tree->fo
        }
 }
 void MainWindow::Tree_itemClicked(QTreeWidgetItem *item, int column)
 {
        if(item==ui->Tree->invisibleRootItem())
            return;
        QString text =item->text(column);
        QList<Item_Node> List;
        m_SCDPoint->Get_Attribute_List(item,List);
        m_SCDPoint->Display_AttributeByNode(List,m_ModelTree);
 }
