#include "compareied.h"

CompareIED::CompareIED(QWidget *parent)
	: QDialog(parent)
{
	ui.setupUi(this);
    ModelDataSet = new QStandardItemModel;
      ModelInput = new QStandardItemModel;
      ModelControlBLK =new QStandardItemModel;
     Init();
	 state = 0;
     connect(ui.pushButton_Cancel, SIGNAL(clicked()), this, SLOT(On_Pushbutton_Cancel()));
     connect(ui.pushButton_Ignore, SIGNAL(clicked()), this, SLOT(On_Pushbutton_Ignore()));
     connect(ui.pushButton_Replace_1, SIGNAL(clicked()), this, SLOT(On_Pushbutton_Replace_1()));
     connect(ui.pushButton_Replace_2, SIGNAL(clicked()), this, SLOT(On_Pushbutton_Replace_2()));
}

CompareIED::~CompareIED()
{

}
void CompareIED::Init()
{
    ui.tab->setTabText(0,tr("Input"));
    ui.tab->setTabText(1,tr("DataSet"));
    ui.tab->setTabText(2,tr("Control Block"));

    ui.pushButton_Cancel->setText(tr("Cancel"));
    ui.pushButton_Ignore->setText(tr("Ignore"));
    ui.pushButton_Replace_1->setText(tr("Replace All"));
    ui.pushButton_Replace_2->setText(tr("Replace and Ignore Input"));
    ui.label->setText(tr("If the address do not match, the replace operation will ignore the data"));
    headerlist.clear();
    headerlist << tr("Local Address") << tr("Local name") << tr("Extern Address") << tr("Extern name");


    ui.tableView_input->setSelectionBehavior(QAbstractItemView::SelectItems); //设置选择行为，以行为单位
    ui.tableView_input->setSelectionMode(QAbstractItemView::SingleSelection); //设置选择模式，选择单行
    ui.tableView_cblk->setSelectionBehavior(QAbstractItemView::SelectItems); //设置选择行为，以行为单位
    ui.tableView_cblk->setSelectionMode(QAbstractItemView::SingleSelection); //设置选择模式，选择单行
    ui.tableView_data->setSelectionBehavior(QAbstractItemView::SelectItems); //设置选择行为，以行为单位
    ui.tableView_data->setSelectionMode(QAbstractItemView::SingleSelection); //设置选择模式，选择单行

    ModelDataSet->clear();
    ModelInput->clear();
    ModelControlBLK->clear();

    ModelDataSet->setColumnCount(headerlist.count());
    ModelInput->setColumnCount(headerlist.count());
    ModelControlBLK->setColumnCount(headerlist.count());
    ui.tableView_input->setModel(ModelInput);
    for (int i = 0; i < headerlist.count(); i++)
    {
        ModelInput->setHeaderData(i, Qt::Horizontal, headerlist.at(i));
       // ui.tableView_input->setItemDelegateForColumn(i, ui.tableView_input->itemDelegateForColumn(0));
    }
    ui.tableView_cblk->setModel(ModelControlBLK);
    for (int i = 0; i < headerlist.count(); i++)
    {
        ModelControlBLK->setHeaderData(i, Qt::Horizontal, headerlist.at(i));
      //  ui.tableView_cblk->setItemDelegateForColumn(i, ui.tableView_cblk->itemDelegateForColumn(0));
    }
    ui.tableView_data->setModel(ModelDataSet);
    for (int i = 0; i < headerlist.count(); i++)
    {
        ModelDataSet->setHeaderData(i, Qt::Horizontal, headerlist.at(i));
        //ui.tableView_data->setItemDelegateForColumn(i, ui.tableView_data->itemDelegateForColumn(0));
    }
}
void CompareIED::ChangeIndex(int index)
{
    ui.tab->setCurrentIndex(index);
}
void CompareIED::ChangeDispaly(int st)
{
    if(st==1)
    {
        ui.pushButton_Ignore->hide();
        ui.pushButton_Replace_2->hide();
        ui.pushButton_Replace_1->setText(tr("Apply"));
    }
}

void CompareIED::DisplayDataSet(QMap<QString,QString>&IN_Map,QMap<QString,QString>&EX_Map)
{
    int count_in=0;
    int count_ex = 0;
    int count;
	for (int i = 0; i<IN_Map.uniqueKeys().size(); i++)
    {
		count_in += IN_Map.values(IN_Map.uniqueKeys().at(i)).size();
    }
	for (int i = 0; i<EX_Map.uniqueKeys().size(); i++)
    {
		count_ex += EX_Map.values(EX_Map.uniqueKeys().at(i)).size();
    }
    if(count_ex>count_in)
    {
     ModelDataSet->setRowCount(count_ex);
     count =count_ex;
    }
    else
    {
        ModelDataSet->setRowCount(count_in);
        count =count_in;
    }
    int j=0;
	for (int i = 0; i<IN_Map.uniqueKeys().size(); i++)
    {
		for (int m = 0; m<IN_Map.values(IN_Map.uniqueKeys().at(i)).size(); m++)
        {
			ModelDataSet->setData(ModelDataSet->index(j, 0), QVariant(IN_Map.uniqueKeys().at(i)));
            ModelDataSet->setData(ModelDataSet->index(j, 1), QVariant(IN_Map.values(IN_Map.uniqueKeys().at(i)).at(m)));
            ModelDataSet->item(j, 0)->setFlags(Qt::ItemIsSelectable | Qt::ItemIsEnabled);
            ModelDataSet->item(j, 1)->setFlags(Qt::ItemIsSelectable | Qt::ItemIsEnabled);
            j++;
        }


    }
     j=0;
    for(int i=0;i<EX_Map.uniqueKeys().size();i++)
    {
        for(int m=0;m<EX_Map.values(EX_Map.uniqueKeys().at(i)).size();m++)
        {
            ModelDataSet->setData(ModelDataSet->index(j, 2), QVariant(EX_Map.uniqueKeys().at(i)));
            ModelDataSet->setData(ModelDataSet->index(j, 3), QVariant(EX_Map.values(EX_Map.uniqueKeys().at(i)).at(m)));
            ModelDataSet->item(j, 2)->setFlags(Qt::ItemIsSelectable | Qt::ItemIsEnabled);

				if (!IN_Map.uniqueKeys().contains(EX_Map.uniqueKeys().at(i)))
				{
					ModelDataSet->setData(ModelDataSet->index(j, 2), QColor(255, 0, 0), Qt::TextColorRole);
					ModelDataSet->setData(ModelDataSet->index(j, 3), QColor(255, 0, 0), Qt::TextColorRole);
				}else
				if(!IN_Map.values(EX_Map.uniqueKeys().at(i)).contains(EX_Map.values(EX_Map.uniqueKeys().at(i)).at(m)))
                {
                    ModelDataSet->setData(ModelDataSet->index(j,3),QColor(255,0,0),Qt::TextColorRole);

                }

      
            ModelDataSet->item(j, 3)->setFlags(Qt::ItemIsSelectable | Qt::ItemIsEnabled);
            j++;
        }


    }
    ui.tableView_data->resizeColumnsToContents();
    ui.tableView_data->resizeRowsToContents();
}


void CompareIED::DisplayInput(QMap<QString,QString>&IN_Map,QMap<QString,QString>&EX_Map)
{
    int count_in = 0;
    int count_ex = 0;
    int count;
    for(int i =0;i<IN_Map.uniqueKeys().size();i++)
    {
        count_in+=IN_Map.values(IN_Map.uniqueKeys().at(i)).size();
    }
    for(int i =0;i<EX_Map.uniqueKeys().size();i++)
    {
        count_ex+=EX_Map.values(EX_Map.uniqueKeys().at(i)).size();
    }
    if(count_ex>count_in)
    {
     ModelInput->setRowCount(count_ex);
     count =count_ex;
    }
    else
    {
        ModelInput->setRowCount(count_in);
        count =count_in;
    }
    int j=0;
    for(int i=0;i<IN_Map.uniqueKeys().size();i++)
    {
        for(int m=0;m<IN_Map.values(IN_Map.uniqueKeys().at(i)).size();m++)
        {
            ModelInput->setData(ModelInput->index(j, 0), QVariant(IN_Map.uniqueKeys().at(i)));
            ModelInput->setData(ModelInput->index(j, 1), QVariant(IN_Map.values(IN_Map.uniqueKeys().at(i)).at(m)));
            ModelInput->item(j, 0)->setFlags(Qt::ItemIsSelectable | Qt::ItemIsEnabled);
            ModelInput->item(j, 1)->setFlags(Qt::ItemIsSelectable | Qt::ItemIsEnabled);
            j++;
        }


    }
     j=0;
    for(int i=0;i<EX_Map.uniqueKeys().size();i++)
    {
        for(int m=0;m<EX_Map.values(EX_Map.uniqueKeys().at(i)).size();m++)
        {

            ModelInput->setData(ModelInput->index(j, 2), QVariant(EX_Map.uniqueKeys().at(i)));
            ModelInput->setData(ModelInput->index(j, 3), QVariant(EX_Map.values(EX_Map.uniqueKeys().at(i)).at(m)));
            ModelInput->item(j, 2)->setFlags(Qt::ItemIsSelectable | Qt::ItemIsEnabled);
            if (!IN_Map.uniqueKeys().contains(EX_Map.uniqueKeys().at(i)))
            {
                ModelInput->setData(ModelInput->index(j, 2), QColor(255, 0, 0), Qt::TextColorRole);
                ModelInput->setData(ModelInput->index(j, 3), QColor(255, 0, 0), Qt::TextColorRole);
            }else
            if(!IN_Map.values(EX_Map.uniqueKeys().at(i)).contains(EX_Map.values(EX_Map.uniqueKeys().at(i)).at(m)))
            {
                ModelInput->setData(ModelInput->index(j,3),QColor(255,0,0),Qt::TextColorRole);

            }
            ModelInput->item(j, 3)->setFlags(Qt::ItemIsSelectable | Qt::ItemIsEnabled);
            j++;
        }


    }
    ui.tableView_input->resizeColumnsToContents();
    ui.tableView_input->resizeRowsToContents();
}

void CompareIED::DisplayCBLK(QMap<QString,QString>&IN_Map,QMap<QString,QString>&EX_Map)
{
    int count_in = 0;
    int count_ex = 0;
    int count;
    for(int i =0;i<IN_Map.uniqueKeys().size();i++)
    {
        count_in+=IN_Map.values(IN_Map.uniqueKeys().at(i)).size();
    }
    for(int i =0;i<EX_Map.uniqueKeys().size();i++)
    {
        count_ex+=EX_Map.values(EX_Map.uniqueKeys().at(i)).size();
    }
    if(count_ex>count_in)
    {
     ModelControlBLK->setRowCount(count_ex);
     count =count_ex;
    }
    else
    {
        ModelControlBLK->setRowCount(count_in);
        count =count_in;
    }
    int j=0;
    for(int i=0;i<IN_Map.uniqueKeys().size();i++)
    {
        for(int m=0;m<IN_Map.values(IN_Map.uniqueKeys().at(i)).size();m++)
        {
            ModelControlBLK->setData(ModelControlBLK->index(j, 0), QVariant(IN_Map.uniqueKeys().at(i)));
            ModelControlBLK->setData(ModelControlBLK->index(j, 1), QVariant(IN_Map.values(IN_Map.uniqueKeys().at(i)).at(m)));
            ModelControlBLK->item(j, 0)->setFlags(Qt::ItemIsSelectable | Qt::ItemIsEnabled);

            ModelControlBLK->item(j, 1)->setFlags(Qt::ItemIsSelectable | Qt::ItemIsEnabled);
            j++;
        }


    }
     j=0;
    for(int i=0;i<EX_Map.uniqueKeys().size();i++)
    {
        for(int m=0;m<EX_Map.values(EX_Map.uniqueKeys().at(i)).size();m++)
        {
            ModelControlBLK->setData(ModelControlBLK->index(j, 2), QVariant(EX_Map.uniqueKeys().at(i)));
            ModelControlBLK->setData(ModelControlBLK->index(j, 3), QVariant(EX_Map.values(EX_Map.uniqueKeys().at(i)).at(m)));
            ModelControlBLK->item(j, 2)->setFlags(Qt::ItemIsSelectable | Qt::ItemIsEnabled);
            if (!IN_Map.uniqueKeys().contains(EX_Map.uniqueKeys().at(i)))
            {
                ModelControlBLK->setData(ModelControlBLK->index(j, 2), QColor(255, 0, 0), Qt::TextColorRole);
                ModelControlBLK->setData(ModelControlBLK->index(j, 3), QColor(255, 0, 0), Qt::TextColorRole);
            }else
            if(!IN_Map.values(EX_Map.uniqueKeys().at(i)).contains(EX_Map.values(EX_Map.uniqueKeys().at(i)).at(m)))
            {
                ModelControlBLK->setData(ModelControlBLK->index(j,3),QColor(255,0,0),Qt::TextColorRole);

            }
            ModelControlBLK->item(j, 3)->setFlags(Qt::ItemIsSelectable | Qt::ItemIsEnabled);
            j++;
        }


    }
    ui.tableView_cblk->resizeColumnsToContents();
    ui.tableView_cblk->resizeRowsToContents();
}
void CompareIED::On_Pushbutton_Replace_1()
{
    state=1;
    accept();
}

void CompareIED::On_Pushbutton_Replace_2()
{
    state=2;
    accept();
}

void CompareIED::On_Pushbutton_Ignore()
{
    state=3;
    accept();
}

void CompareIED::On_Pushbutton_Cancel()
{
	state = 4;
    reject();
}
