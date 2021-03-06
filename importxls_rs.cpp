﻿#include "importxls_rs.h"

ImportXLS_RS::ImportXLS_RS(QWidget *parent)
	: QDialog(parent)
{
	ui.setupUi(this);

    IEDList.clear();
    ui.pushButton_Apply->setText(tr("Apply"));
    ui.pushButton_Cancel->setText(tr("Cancel"));
    ui.label->setText(tr("The invalid Virtual terminal will not import,the repeat will replace "));
    connect(ui.pushButton_Apply, SIGNAL(clicked(bool)), this, SLOT(Pushbutton_Apply()));
    connect(ui.pushButton_Cancel, SIGNAL(clicked(bool)), this, SLOT(Pushbutton_Cancel()));

}

ImportXLS_RS::~ImportXLS_RS()
{

}
void ImportXLS_RS::Init_dlg()
{
    for(int i=0;i<Map_available.uniqueKeys().size();i++)
    {
        if(!IEDList.contains(Map_available.uniqueKeys().at(i)))
            IEDList.append(Map_available.uniqueKeys().at(i));
    }
    for(int i=0;i<Map_invalid_IN.uniqueKeys().size();i++)
    {
        if(!IEDList.contains(Map_invalid_IN.uniqueKeys().at(i)))
            IEDList.append(Map_invalid_IN.uniqueKeys().at(i));
    }
    for(int i=0;i<Map_Repeat.uniqueKeys().size();i++)
    {
        if(!IEDList.contains(Map_Repeat.uniqueKeys().at(i)))
            IEDList.append(Map_Repeat.uniqueKeys().at(i));
    }
    for(int i=0;i<Map_invalid_OUT.uniqueKeys().size();i++)
    {
        if(!IEDList.contains(Map_invalid_OUT.uniqueKeys().at(i)))
            IEDList.append(Map_invalid_OUT.uniqueKeys().at(i));
    }

    ui.tabWidget->setTabText(0,IEDList.at(0));

    ui.tableView->setObjectName(tr("tableView")+IEDList.at(0));
    QStandardItemModel *m_Model=new QStandardItemModel;
    m_Model->setObjectName("Model"+IEDList.at(0));
	ModelMap.insert(IEDList.at(0), m_Model);
	tableViewMap.insert(IEDList.at(0), ui.tableView);
    for(int i =1;i<IEDList.size();i++)
    {
        QWidget *tab =new QWidget();
        tab->setObjectName(QStringLiteral("tab"));
		QGridLayout *gridLayout = new QGridLayout(tab);
        gridLayout->setSpacing(6);
        gridLayout->setContentsMargins(11, 11, 11, 11);
        gridLayout->setObjectName(QStringLiteral("gridLayout"));
        tableView = new QTableView(tab);
        tableView->setObjectName(tr("tableView")+IEDList.at(i));
        m_Model=new QStandardItemModel;
        m_Model->setObjectName("Model"+IEDList.at(i));
		ModelMap.insert(IEDList.at(i), m_Model);
		
        gridLayout->addWidget(tableView, 0, 0, 1, 1);
        ui.tabWidget->insertTab(i,tab,IEDList.at(i));
        tableViewMap.insert(IEDList.at(i), tableView);
    }
	ui.tableView->horizontalHeader()->setSectionResizeMode(QHeaderView::Interactive);

}

void ImportXLS_RS::Display()
{
	for (int i = 0; i < IEDList.size();i++)
	{
        tableView = tableViewMap.value(IEDList.at(i));
        Model = ModelMap.value(IEDList.at(i));
        QStringList headerList;
		headerList << tr("Status") << tr("DataSet") << tr("Sender Device ") << tr("Sender Attribute") << tr("Receiver Device ") << tr("Receiver Attribute");


        Model->setColumnCount(headerList.size());
        for (int j = 0; j < headerList.count(); j++)
        {
            Model->setHeaderData(j, Qt::Horizontal, headerList.at(j));
        }
        tableView->setModel(Model);
        tableView->setSelectionBehavior(QAbstractItemView::SelectRows);
        tableView->setSelectionMode(QAbstractItemView::NoSelection);
        for (int j = 0; j < Map_Repeat.values(IEDList.at(i)).size(); j++)
		{
			Model->setRowCount(Model->rowCount() + 1);
            Model->setData(Model->index(Model->rowCount()-1,0),tr("Repeat"));
            Model->setData(Model->index(Model->rowCount()-1,1),Map_Repeat.values(IEDList.at(i)).at(j).External_DataSet);
            Model->setData(Model->index(Model->rowCount()-1,2),Map_Repeat.values(IEDList.at(i)).at(j).External_IED);
            Model->setData(Model->index(Model->rowCount()-1,3),Map_Repeat.values(IEDList.at(i)).at(j).External_Reference);
            Model->setData(Model->index(Model->rowCount()-1,4),Map_Repeat.values(IEDList.at(i)).at(j).Interior_IED);
            Model->setData(Model->index(Model->rowCount()-1,5),Map_Repeat.values(IEDList.at(i)).at(j).Interior_Reference);
            Model->item(Model->rowCount()-1, 0)->setFlags(Qt::ItemIsSelectable | Qt::ItemIsEnabled);
            Model->item(Model->rowCount()-1, 1)->setFlags(Qt::ItemIsSelectable | Qt::ItemIsEnabled);
            Model->item(Model->rowCount()-1, 2)->setFlags(Qt::ItemIsSelectable | Qt::ItemIsEnabled);
            Model->item(Model->rowCount()-1, 3)->setFlags(Qt::ItemIsSelectable | Qt::ItemIsEnabled);
            Model->item(Model->rowCount()-1, 4)->setFlags(Qt::ItemIsSelectable | Qt::ItemIsEnabled);
            Model->item(Model->rowCount()-1, 5)->setFlags(Qt::ItemIsSelectable | Qt::ItemIsEnabled);
            Model->setData(Model->index(Model->rowCount()-1,0),QColor(255,255,0),Qt::BackgroundColorRole);

        }
        for (int j = 0; j < Map_invalid_OUT.values(IEDList.at(i)).size(); j++)
        {
            Model->setRowCount(Model->rowCount() + 1);
            Model->setData(Model->index(Model->rowCount()-1,0),tr("Sender Invalid"));
            Model->setData(Model->index(Model->rowCount()-1,1),Map_invalid_OUT.values(IEDList.at(i)).at(j).External_DataSet);
            Model->setData(Model->index(Model->rowCount()-1,2),Map_invalid_OUT.values(IEDList.at(i)).at(j).External_IED);
            Model->setData(Model->index(Model->rowCount()-1,3),Map_invalid_OUT.values(IEDList.at(i)).at(j).External_Reference);
            Model->setData(Model->index(Model->rowCount()-1,4),Map_invalid_OUT.values(IEDList.at(i)).at(j).Interior_IED);
            Model->setData(Model->index(Model->rowCount()-1,5),Map_invalid_OUT.values(IEDList.at(i)).at(j).Interior_Reference);
            Model->item(Model->rowCount()-1, 0)->setFlags(Qt::ItemIsSelectable | Qt::ItemIsEnabled);
            Model->item(Model->rowCount()-1, 1)->setFlags(Qt::ItemIsSelectable | Qt::ItemIsEnabled);
            Model->item(Model->rowCount()-1, 2)->setFlags(Qt::ItemIsSelectable | Qt::ItemIsEnabled);
            Model->item(Model->rowCount()-1, 3)->setFlags(Qt::ItemIsSelectable | Qt::ItemIsEnabled);
            Model->item(Model->rowCount()-1, 4)->setFlags(Qt::ItemIsSelectable | Qt::ItemIsEnabled);
            Model->item(Model->rowCount()-1, 5)->setFlags(Qt::ItemIsSelectable | Qt::ItemIsEnabled);
            Model->setData(Model->index(Model->rowCount()-1,0),QColor(0,255,0),Qt::BackgroundColorRole);
            Model->setData(Model->index(Model->rowCount()-1,3),QColor(0,255,0),Qt::BackgroundColorRole);

        }
        for (int j = 0; j < Map_invalid_IN.values(IEDList.at(i)).size(); j++)
        {
            Model->setRowCount(Model->rowCount() + 1);

            Model->setData(Model->index(Model->rowCount()-1,0),tr("Receiver Invalid"));
            Model->setData(Model->index(Model->rowCount()-1,1),Map_invalid_IN.values(IEDList.at(i)).at(j).External_DataSet);
            Model->setData(Model->index(Model->rowCount()-1,2),Map_invalid_IN.values(IEDList.at(i)).at(j).External_IED);
            Model->setData(Model->index(Model->rowCount()-1,3),Map_invalid_IN.values(IEDList.at(i)).at(j).External_Reference);
            Model->setData(Model->index(Model->rowCount()-1,4),Map_invalid_IN.values(IEDList.at(i)).at(j).Interior_IED);
            Model->setData(Model->index(Model->rowCount()-1,5),Map_invalid_IN.values(IEDList.at(i)).at(j).Interior_Reference);
            Model->item(Model->rowCount()-1, 0)->setFlags(Qt::ItemIsSelectable | Qt::ItemIsEnabled);
            Model->item(Model->rowCount()-1, 1)->setFlags(Qt::ItemIsSelectable | Qt::ItemIsEnabled);
            Model->item(Model->rowCount()-1, 2)->setFlags(Qt::ItemIsSelectable | Qt::ItemIsEnabled);
            Model->item(Model->rowCount()-1, 3)->setFlags(Qt::ItemIsSelectable | Qt::ItemIsEnabled);
            Model->item(Model->rowCount()-1, 4)->setFlags(Qt::ItemIsSelectable | Qt::ItemIsEnabled);
            Model->item(Model->rowCount()-1, 5)->setFlags(Qt::ItemIsSelectable | Qt::ItemIsEnabled);
            Model->setData(Model->index(Model->rowCount()-1,0),QColor(255,0,0),Qt::BackgroundColorRole);
            Model->setData(Model->index(Model->rowCount()-1,5),QColor(255,0,0),Qt::BackgroundColorRole);

        }
        for (int j = 0; j < Map_available.values(IEDList.at(i)).size(); j++)
        {
            Model->setRowCount(Model->rowCount() + 1);
            Model->setData(Model->index(Model->rowCount()-1,0),tr("Available"));
            Model->setData(Model->index(Model->rowCount()-1,1),Map_available.values(IEDList.at(i)).at(j).External_DataSet);
            Model->setData(Model->index(Model->rowCount()-1,2),Map_available.values(IEDList.at(i)).at(j).External_IED);
            Model->setData(Model->index(Model->rowCount()-1,3),Map_available.values(IEDList.at(i)).at(j).External_Reference);
            Model->setData(Model->index(Model->rowCount()-1,4),Map_available.values(IEDList.at(i)).at(j).Interior_IED);
            Model->setData(Model->index(Model->rowCount()-1,5),Map_available.values(IEDList.at(i)).at(j).Interior_Reference);
            Model->item(Model->rowCount()-1, 0)->setFlags(Qt::ItemIsSelectable | Qt::ItemIsEnabled);
            Model->item(Model->rowCount()-1, 1)->setFlags(Qt::ItemIsSelectable | Qt::ItemIsEnabled);
            Model->item(Model->rowCount()-1, 2)->setFlags(Qt::ItemIsSelectable | Qt::ItemIsEnabled);
            Model->item(Model->rowCount()-1, 3)->setFlags(Qt::ItemIsSelectable | Qt::ItemIsEnabled);
            Model->item(Model->rowCount()-1, 4)->setFlags(Qt::ItemIsSelectable | Qt::ItemIsEnabled);
            Model->item(Model->rowCount()-1, 5)->setFlags(Qt::ItemIsSelectable | Qt::ItemIsEnabled);

        }

	}
}
void ImportXLS_RS::Pushbutton_Apply()
{
    accept();
}

void ImportXLS_RS::Pushbutton_Cancel()
{
    reject();
}
