#include "rptchange.h"
#include "ui_rptchange.h"

RptChange::RptChange(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::RptChange)
{
    
    ui->setupUi(this);
	
	//ui->lineEdit->setValidator(new QIntValidator(0, 20, this));
    istate=0;
    ui->tableView->hide();
    ui->label->hide();
    ui->lineEdit->hide();
    ui->pushButton_ok->setText(tr("Ok"));
    ui->pushButton_Cancel->setText(tr("Cancel"));
    m_Model = new QStandardItemModel(this);
    Interactive.clear();
    Interactive << tr("State") << tr("name") ;
    m_Model->clear();
    ui->tableView->setSelectionBehavior(QAbstractItemView::SelectRows);
    m_Model->setColumnCount(Interactive.count());
    ui->label->setText(tr("Max="));
	ui->tableView->setModel(m_Model);
    for (int i = 0; i < Interactive.count(); i++)
    {
        m_Model->setHeaderData(i, Qt::Horizontal, Interactive.at(i));

    }
    connect(ui->pushButton_ok,SIGNAL(clicked()),this,SLOT(on_pushbutton_ok_clicked()));
    connect(ui->pushButton_Cancel,SIGNAL(clicked()),this,SLOT(on_pushbutton_cancel_clicked()));

}

RptChange::~RptChange()
{
    delete ui;
}
void RptChange::init_dlg()
{
    if(istate==0)
    {
        return;
    }
    if(istate==1)
    {
        ui->tableView->show();
        m_Model->setRowCount(4);
		BOOLTypeCombox *m_boolcombox = new BOOLTypeCombox(this);
        ui->tableView->setItemDelegateForColumn(0,m_boolcombox);
        m_Model->setData(m_Model->index(0, 1), QVariant(tr("dchg")));
        m_Model->item(0, 1)->setFlags(Qt::ItemIsSelectable | Qt::ItemIsEnabled);
        m_Model->setData(m_Model->index(1, 1), QVariant(tr("dupd")));
        m_Model->item(1, 1)->setFlags(Qt::ItemIsSelectable | Qt::ItemIsEnabled);
        m_Model->setData(m_Model->index(2, 1), QVariant(tr("period")));
        m_Model->item(2, 1)->setFlags(Qt::ItemIsSelectable | Qt::ItemIsEnabled);
        m_Model->setData(m_Model->index(3, 1), QVariant(tr("qchg")));
        m_Model->item(3, 1)->setFlags(Qt::ItemIsSelectable | Qt::ItemIsEnabled);
		return;

    }
    if(istate==2)
    {
         ui->tableView->show();
        m_Model->setRowCount(7);
		BOOLTypeCombox *m_boolcombox = new BOOLTypeCombox(this);
        ui->tableView->setItemDelegateForColumn(0,m_boolcombox);
        m_Model->setData(m_Model->index(0, 1), QVariant(tr("seqNum")));
        m_Model->item(0, 1)->setFlags(Qt::ItemIsSelectable | Qt::ItemIsEnabled);
        m_Model->setData(m_Model->index(1, 1), QVariant(tr("timeStamp")));
        m_Model->item(1, 1)->setFlags(Qt::ItemIsSelectable | Qt::ItemIsEnabled);
        m_Model->setData(m_Model->index(2, 1), QVariant(tr("dataSet")));
        m_Model->item(2, 1)->setFlags(Qt::ItemIsSelectable | Qt::ItemIsEnabled);
        m_Model->setData(m_Model->index(3, 1), QVariant(tr("reasonCode")));
        m_Model->item(3, 1)->setFlags(Qt::ItemIsSelectable | Qt::ItemIsEnabled);
        m_Model->setData(m_Model->index(4, 1), QVariant(tr("dataRef")));
        m_Model->item(4, 1)->setFlags(Qt::ItemIsSelectable | Qt::ItemIsEnabled);
        m_Model->setData(m_Model->index(5, 1), QVariant(tr("entryID")));
        m_Model->item(5, 1)->setFlags(Qt::ItemIsSelectable | Qt::ItemIsEnabled);
        m_Model->setData(m_Model->index(6, 1), QVariant(tr("configRef")));
        m_Model->item(6, 1)->setFlags(Qt::ItemIsSelectable | Qt::ItemIsEnabled);
		return;
    }
    if(istate==3)
    {
        ui->label->show();
        ui->lineEdit->show();
		return;
    }
}
void RptChange::on_pushbutton_ok_clicked()
{
    if(istate==0)
    {
        reject();
    }
    if(istate==1)
    {
        m_Trgops.B_dchg=m_Model->data(m_Model->index(0, 0), Qt::EditRole).toString();
        m_Trgops.B_dupd=m_Model->data(m_Model->index(1, 0), Qt::EditRole).toString();
        m_Trgops.B_period=m_Model->data(m_Model->index(2, 0), Qt::EditRole).toString();
        m_Trgops.B_qchg=m_Model->data(m_Model->index(3, 0), Qt::EditRole).toString();
    }
    if(istate==2)
    {
        m_OptField.B_seqNum=m_Model->data(m_Model->index(0, 0), Qt::EditRole).toString();
        m_OptField.B_timeStamp=m_Model->data(m_Model->index(1, 0), Qt::EditRole).toString();
        m_OptField.B_dataSet=m_Model->data(m_Model->index(2, 0), Qt::EditRole).toString();
        m_OptField.B_reasonCode=m_Model->data(m_Model->index(3, 0), Qt::EditRole).toString();
        m_OptField.B_dataRef=m_Model->data(m_Model->index(4, 0), Qt::EditRole).toString();
        m_OptField.B_entryID=m_Model->data(m_Model->index(5, 0), Qt::EditRole).toString();
        m_OptField.B_configRef=m_Model->data(m_Model->index(6, 0), Qt::EditRole).toString();
    }
    if(istate==3)
    {
        m_RptEndabled.B_max =ui->lineEdit->text();
    }
    accept();
}
void RptChange::on_pushbutton_cancel_clicked()
{
    reject();
}
void RptChange::Displaydata()
{
    if(istate==0)
    {
        return;
    }
    if(istate==1)
    {
        m_Model->setData(m_Model->index(0, 0), QVariant(m_Trgops.B_dchg));
        m_Model->setData(m_Model->index(1, 0), QVariant(m_Trgops.B_dupd));
        m_Model->setData(m_Model->index(2, 0), QVariant(m_Trgops.B_period));
        m_Model->setData(m_Model->index(3, 0), QVariant(m_Trgops.B_qchg));
    }
    if(istate==2)
    {
        m_Model->setData(m_Model->index(0, 0), QVariant(m_OptField.B_seqNum));
        m_Model->setData(m_Model->index(1, 0), QVariant(m_OptField.B_timeStamp));
        m_Model->setData(m_Model->index(2, 0), QVariant(m_OptField.B_dataSet));
        m_Model->setData(m_Model->index(3, 0), QVariant(m_OptField.B_reasonCode));
        m_Model->setData(m_Model->index(4, 0), QVariant(m_OptField.B_dataRef));
        m_Model->setData(m_Model->index(5, 0), QVariant(m_OptField.B_entryID));
        m_Model->setData(m_Model->index(6, 0), QVariant(m_OptField.B_configRef));
    }
    if(istate==3)
    {
        ui->lineEdit->setText(m_RptEndabled.B_max);
    }
}
