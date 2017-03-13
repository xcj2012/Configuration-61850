#include "mergecompare.h"

MergeCompare::MergeCompare(QWidget *parent)
	: QDialog(parent)
{
	ui.setupUi(this);
    Model =new QStandardItemModel;
    connect(ui.pushButton_Apply, SIGNAL(clicked(bool)), this, SLOT(Pushbutton_apply()));
    connect(ui.pushButton_Cancel, SIGNAL(clicked(bool)), this, SLOT(Pushbutton_cancel()));
	connect(Model, SIGNAL(dataChanged(const QModelIndex &, const QModelIndex &)), this, SLOT(OnDataChanged(const QModelIndex &, const QModelIndex &)));

}

MergeCompare::~MergeCompare()
{

}
void MergeCompare::Init_dlg()
{
    ui.label->setText(tr("If the two SCD has IED with same name ,shoule change the name of IED "));
    ui.pushButton_Apply->setText(tr("Apply"));
    ui.pushButton_Cancel->setText(tr("Cancel"));
    headerList<<tr("Base IED")<<tr("Merge IED");
    Model->setColumnCount(headerList.size());
    for (int i = 0; i < headerList.count(); i++)
    {
        Model->setHeaderData(i, Qt::Horizontal, headerList.at(i));
    }

    ui.tableView->setModel(Model);
    ui.tableView->setSelectionBehavior(QAbstractItemView::SelectRows);
    ui.tableView->setSelectionMode(QAbstractItemView::NoSelection);

}
void MergeCompare::Display()
{
	disconnect(Model, SIGNAL(dataChanged(const QModelIndex &, const QModelIndex &)), this, SLOT(OnDataChanged(const QModelIndex &, const QModelIndex &)));

	ui.tableView->horizontalHeader()->setSectionResizeMode(QHeaderView::Stretch);

    if(IED_List.size()>IED_MAP.uniqueKeys().size())
    {
        Model->setRowCount(IED_List.size());
    }else
    {
        Model->setRowCount(IED_MAP.uniqueKeys().size());
    }
    for(int i =0;i<Model->rowCount();i++)
    {
        if(i<IED_List.size())
        {
            Model->setData(Model->index(i,0),IED_List.at(i).s_IEDname);
			Model->item(i, 0)->setFlags(Qt::ItemIsSelectable | Qt::ItemIsEnabled);
        }


    }
    for(int i =0;i<Model->rowCount();i++)
    {
        if(i<IED_MAP.uniqueKeys().size())
        {
            Model->setData(Model->index(i,1),IED_MAP.value(IED_MAP.uniqueKeys().at(i)).s_IEDname);
            if(IED_List.contains(IED_MAP.value(IED_MAP.uniqueKeys().at(i))))
            {
                Model->setData(Model->index(i,1),QColor(255,255,0),Qt::BackgroundColorRole);
				RepearList.append(IED_MAP.value(IED_MAP.uniqueKeys().at(i)).s_IEDname);
            }
            //Model->setData(Model->index(i,1),QColor(255,255,0),Qt::BackgroundColorRole);

        }
    }
	connect(Model, SIGNAL(dataChanged(const QModelIndex &, const QModelIndex &)), this, SLOT(OnDataChanged(const QModelIndex &, const QModelIndex &)));

}

void MergeCompare::Pushbutton_apply()
{
	if (RepearList.size()!=0)
	{
		QMessageBox::about(this, tr("Notice"), tr("There are same IED has same name\nThe operation will stop\nChange the IED name and continue"));
		return;
	}
    for(int i =0;i<IED_MAP.uniqueKeys().size();i++)
    {
        IEDstruct m_data;
        m_data.s_IEDname = Model->data(Model->index(i,1)).toString();
        Finil_MAP.insert(IED_MAP.value(IED_MAP.uniqueKeys().at(i)).s_IEDname,m_data);
    }
    accept();
}

void MergeCompare::Pushbutton_cancel()
{
    reject();
}
void MergeCompare::OnDataChanged(const QModelIndex & topLeft, const QModelIndex & bottomRight)
{
	disconnect(Model, SIGNAL(dataChanged(const QModelIndex &, const QModelIndex &)), this, SLOT(OnDataChanged(const QModelIndex &, const QModelIndex &)));

	RepearList.clear();

	for (int m = 0; m < IED_MAP.uniqueKeys().size(); m++)
	{
		Model->setData(Model->index(m, 1), QColor(255, 255, 255), Qt::BackgroundColorRole);

		IEDstruct m_data;
		m_data.s_IEDname = Model->data(Model->index(m, 1)).toString();
		for (int i = 0; i < Model->rowCount(); i++)
		{
			QString str = Model->data(Model->index(i, 0)).toString();
			if (str == m_data.s_IEDname)
			{
				Model->setData(Model->index(m, 1), QColor(255, 255, 0), Qt::BackgroundColorRole);
				if (!RepearList.contains(str))
				{
					RepearList.append(m_data.s_IEDname);

				}
			}

		}

	}

	connect(Model, SIGNAL(dataChanged(const QModelIndex &, const QModelIndex &)), this, SLOT(OnDataChanged(const QModelIndex &, const QModelIndex &)));




}