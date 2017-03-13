#include "importxls.h"

ImportXLS::ImportXLS(QWidget *parent)
	: QDialog(parent)
{
	ui.setupUi(this);
	Model = new QStandardItemModel;
    connect(ui.pushButton_Browse,SIGNAL(clicked(bool)),this,SLOT(Pushbutton_Browse()));
	connect(ui.pushButton_Ok, SIGNAL(clicked(bool)), this, SLOT(Pushbutton_Ok()));
	connect(ui.pushButton_Cancel, SIGNAL(clicked(bool)), this, SLOT(Pushbutton_Cancel()));


}

ImportXLS::~ImportXLS()
{

}
void ImportXLS::Init_dlg()
{
    ui.label_Path->setText(tr("File:"));
    ui.pushButton_Browse->setText(tr("Browse"));
    ui.pushButton_Ok->setText(tr("OK"));
    ui.pushButton_Cancel->setText(tr("Cancel"));
    headerList.clear();
    headerList << tr("State") << tr("IEDName") << tr("available") ;


    Model->setColumnCount(headerList.size());
    for (int i = 0; i < headerList.count(); i++)
    {
        Model->setHeaderData(i, Qt::Horizontal, headerList.at(i));
    }

	ui.tableView->setModel(Model);
	ui.tableView->setSelectionBehavior(QAbstractItemView::SelectRows);
	ui.tableView->setSelectionMode(QAbstractItemView::NoSelection);
     ui.tableView->setColumnWidth(0, 50);
     ui.tableView->setColumnWidth(1, 200);
     ui.tableView->setColumnWidth(2, 100);
	 ui.tableView->horizontalHeader()->setSectionResizeMode(QHeaderView::Interactive);

}
void ImportXLS::Check_IED()
{
    int recode;
    QString filename = ui.lineEdit_Path->text();
    recode=Point->CheckXLS_IED(filename,IED_Map);
    if(recode==DO_FAIL)
    {
		ui.pushButton_Ok->setEnabled(false);
    }else
    {
		ui.pushButton_Ok->setEnabled(true);
    }
	Model->setRowCount(IED_Map.size());
    for(int i =0;i<IED_Map.size();i++)
    {
        QStandardItem *item = new QStandardItem();
        //item->setSizeHint(QSize(ui.tableView->rowHeight(i),ui.tableView->columnWidth(0)));
        item->setCheckable(true);


        if(IED_Map.at(i).State==true)
        {
            item->setCheckState(Qt::Checked);
            item->setText("   ");
            Model->setItem(i, 0, item);
        }else
        {
            item->setCheckState(Qt::Unchecked);
            item->setText("   ");
            Model->setItem(i, 0, item);
        }
		Model->setData(Model->index(i, 1), IED_Map.at(i).IEDName, Qt::DisplayRole);
         if(IED_Map.at(i).available==true)
         {
			 Model->setData(Model->index(i, 2), tr("available"), Qt::DisplayRole);
         }else
         {
            
			 Model->setData(Model->index(i, 2), tr("invalid"), Qt::DisplayRole);
         }
         Model->item(i, 0)->setFlags( Qt::ItemIsEnabled|Qt::ItemIsUserCheckable);
		 Model->item(i, 1)->setFlags(Qt::ItemIsSelectable | Qt::ItemIsEnabled);
		 Model->item(i, 2)->setFlags(Qt::ItemIsSelectable | Qt::ItemIsEnabled);

    }
}
void ImportXLS::Pushbutton_Browse()
{
   QString fileName = QFileDialog::getOpenFileName(this,
       tr("Select XLS "),
	   QDir::currentPath(),
       tr("XLS Files (*.xls)"));
   if(fileName.isEmpty())
       return;
   ui.lineEdit_Path->setText(fileName);
   Check_IED();
}

void ImportXLS::Pushbutton_Ok()
{
    IED_Map.clear();

	for (int i = 0; i < Model->rowCount(); i++)
	{
        Map_IED m_data;
        if(Model->item(i,0)->checkState()==Qt::Unchecked)
        {
            continue;
        }
        if(Model->data(Model->index(i,2)).toString()==tr("invalid"))
        {
            continue;
        }
		m_data.State = true;
		m_data.available = true;
        m_data.IEDName=Model->data(Model->index(i,1)).toString();
		IED_Map.append(m_data);
	}
    File= ui.lineEdit_Path->text();
    accept();
}
void ImportXLS::Pushbutton_Cancel()
{
    reject();
}
