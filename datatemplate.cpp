#include "datatemplate.h"
#include "ui_datatemplate.h"

DataTempLate::DataTempLate(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::DataTempLate)
{
    ui->setupUi(this);
    ui->radioButton_Add->setText(tr("Add Prefix"));
    ui->radioButton_Ignore->setText(tr("Ignore"));
    ui->radioButton_Replace->setText(tr("Replace"));
    ui->pushButton_Apply->setText(tr("Apply"));
    ui->pushButton_Cancel->setText(tr("Cancel"));
    //m_LNModel = new QStandardItemModel;
   // m_DOModel = new QStandardItemModel;
   // m_DAModel = new QStandardItemModel;
  //  m_EnumModel = new QStandardItemModel;
    //ui->tableView_Enum->setEnabled(false);
   // ui->pushButton_Merge->setFocus();
  //  connect(ui->pushButton_Add, SIGNAL(clicked()), this, SLOT(Pushbutton_Add()));
    connect(ui->pushButton_Apply, SIGNAL(clicked()), this, SLOT(Pushbutton_Apply()));

    connect(ui->pushButton_Cancel, SIGNAL(clicked()), this, SLOT(Pushbutton_Cancel()));
   // connect(ui->pushButton_Ignore, SIGNAL(clicked()), this, SLOT(Pushbutton_Ignore()));
    //connect(ui->pushButton_Merge, SIGNAL(clicked()), this, SLOT(Pushbutton_Merge()));
   // connect(ui->pushButton_Replace, SIGNAL(clicked()), this, SLOT(Pushbutton_Replace()));
    //ui->tabWidget->setCurrentIndex(0);
    init_dlg();
}

DataTempLate::~DataTempLate()
{
    delete ui;
}
void DataTempLate::SetInit(int state)
{
if(state ==2)
{
    ui->radioButton_Add->setChecked(true);
    ui->label->setText(tr("The same type of %1 CID exist!").arg(strName));
}else if(state==3)
{
    //ui->radioButton_Add->hide();
    ui->radioButton_Add->setChecked(true);
    ui->label->setText(tr("There is same manufacturer %1 CID exist!").arg(strName));
}else if(state ==4)
{
     ui->radioButton_Add->setChecked(true);
     ui->label->setText(tr("Some DataTemplate of IED name(%1) conflict with SCD").arg(strName));

}
}

void DataTempLate::init_dlg()
{
//    headerList.clear();
//    headerList << tr("Duplicate Name");


//    ui->tableView_DA->setSelectionBehavior(QAbstractItemView::SelectRows);
//    ui->tableView_DO->setSelectionBehavior(QAbstractItemView::SelectRows);
//    ui->tableView_LN->setSelectionBehavior(QAbstractItemView::SelectRows);
//    ui->tableView_Enum->setSelectionBehavior(QAbstractItemView::SelectRows);
//    m_LNModel->setColumnCount(headerList.count());
//    m_DOModel->setColumnCount(headerList.count());
//    m_DAModel->setColumnCount(headerList.count());
//    m_EnumModel->setColumnCount(headerList.count());
//    ui->pushButton_Add->setText(tr("Add_Prefix"));
//    ui->pushButton_Cancel->setText(tr("Cancel"));
//    ui->pushButton_Ignore->setText(tr("Ignore"));
//    ui->pushButton_Merge->setText(tr("Merge"));
//    ui->pushButton_Replace->setText(tr("Replace"));
//    ui->tableView_LN->setModel(m_LNModel);
//    ui->tableView_DA->setModel(m_DAModel);
//    ui->tableView_DO->setModel(m_DOModel);
//    ui->tableView_Enum->setModel(m_EnumModel);
//    for (int i = 0; i < headerList.count(); i++)
//    {
//        m_LNModel->setHeaderData(i, Qt::Horizontal, headerList.at(i));
//        m_DOModel->setHeaderData(i, Qt::Horizontal, headerList.at(i));
//        m_DAModel->setHeaderData(i, Qt::Horizontal, headerList.at(i));
//        m_EnumModel->setHeaderData(i, Qt::Horizontal, headerList.at(i));
// //       ui->tableView->setItemDelegateForColumn(i, ui->tableView->itemDelegateForColumn(0));
//    }
//    ui->tableView_LN->setColumnWidth(0, 480);
//    ui->tableView_DA->setColumnWidth(0, 480);
//    ui->tableView_DO->setColumnWidth(0, 480);
//    ui->tableView_Enum->setColumnWidth(0, 480);
}
void DataTempLate::Pushbutton_Apply()
{
    if(ui->radioButton_Add->isChecked())
    {
        state=0x1;
    }else if(ui->radioButton_Ignore->isChecked())
    {
        state=0x3;
    }else if(ui->radioButton_Replace->isChecked())
    {
        state=0x2;
    }
    accept();
}

void DataTempLate::Pushbutton_Cancel()
{
	reject();
}

//void DataTempLate::Display(QStringList LnList,QStringList DOList,QStringList DAList,QStringList EnumList)
//{
////    m_LNModel->item(row, 0)->setFlags(Qt::ItemIsSelectable | Qt::ItemIsEnabled);
//    if(LnList.size()!=0)
//    {
//        ui->tabWidget->setCurrentIndex(0);
//    }else if(DOList.size()!=0)
//    {
//        ui->tabWidget->setCurrentIndex(1);
//    }else if(DAList.size()!=0)
//    {
//        ui->tabWidget->setCurrentIndex(2);
//    }else if(EnumList.size()!=0)
//    {
//        ui->tabWidget->setCurrentIndex(3);
//    }
//    m_LNModel->setRowCount(LnList.size());
//    for(int i =0;i<LnList.size();i++)
//    {
//        m_LNModel->setData(m_LNModel->index(i, 0),LnList.at(i));
//		m_LNModel->item(i, 0)->setFlags(Qt::ItemIsSelectable | Qt::ItemIsEnabled);
//    }
//    m_DOModel->setRowCount(DOList.size());
//    for(int i =0;i<DOList.size();i++)
//    {
//        m_DOModel->setData(m_DOModel->index(i, 0),DOList.at(i));
//		m_DOModel->item(i, 0)->setFlags(Qt::ItemIsSelectable | Qt::ItemIsEnabled);
//    }
//    m_DAModel->setRowCount(DAList.size());
//    for(int i =0;i<DAList.size();i++)
//    {
//        m_DAModel->setData(m_DAModel->index(i, 0),DAList.at(i));
//		m_DAModel->item(i, 0)->setFlags(Qt::ItemIsSelectable | Qt::ItemIsEnabled);
//    }
//    m_EnumModel->setRowCount(EnumList.size());
//    for(int i =0;i<EnumList.size();i++)
//    {
//        m_EnumModel->setData(m_EnumModel->index(i, 0),EnumList.at(i));
//		m_EnumModel->item(i, 0)->setFlags(Qt::ItemIsSelectable | Qt::ItemIsEnabled);
//    }
//}

//void DataTempLate::Pushbutton_Add()
//{
//    state = 0x01;
//    accept();
//}

//void DataTempLate::Pushbutton_Replace()
//{
//    state = 0x02;
//    accept();
//}

//void DataTempLate::Pushbutton_Ignore()
//{
//    state = 0x04;
//    accept();
//}

//void DataTempLate::Pushbutton_Cancel()
//{
//    reject();
//}
//void DataTempLate::Pushbutton_Merge()
//{
//    state = 0x08;
//    accept();
//}
