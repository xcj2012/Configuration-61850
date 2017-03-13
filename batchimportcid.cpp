#include "batchimportcid.h"
#include "ui_batchimportcid.h"

BatchImportCID::BatchImportCID(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::BatchImportCID)
{
    ui->setupUi(this);
    ui->radioButton_Skip->hide();
    Point =new ScdTree();
	Model = new BatchImportModel();
	connect(ui->pushButton_Import, SIGNAL(clicked()), this, SLOT(Pushbutton_import()));
	connect(ui->pushButton_checkAll, SIGNAL(clicked()), this, SLOT(Pushbutton_all()));
	connect(ui->pushButton_NoAll, SIGNAL(clicked()), this, SLOT(Pushbutton_noall()));
	connect(ui->tableView, SIGNAL(doubleClicked(const QModelIndex &)), this, SLOT(OnDatadoubleClicked(const QModelIndex &)));

}

BatchImportCID::~BatchImportCID()
{
  //  delete Point;
    delete ui;
}
void BatchImportCID::SetPoint(ScdTree* PT)
{
	Point = PT;
}
void BatchImportCID::Init_dlg()
{
    ui->pushButton_Import->setText(tr("Import"));
    ui->pushButton_checkAll->setText(tr("Check All"));
    ui->pushButton_NoAll->setText(tr("ALL NO"));
    ui->radioButton_Skip->setText(tr("Skip the same name"));
	ui->radioButton_Skip->setChecked(true);
	ui->label_IED->setText(tr("IED"));
    ui->label_notice->setText(tr("Batch ImportCID will not import the Communication,the communication will needed to Manual setup"));
    ui->tableView->setSelectionBehavior(QAbstractItemView::SelectRows);
    Model->setcolumncount(3);
    Model->setrowcount(fileList.size());

    ui->tableView->setModel(Model);
    ui->tableView->setColumnWidth(0, 300);
    ui->tableView->setColumnWidth(1, 500);
    ui->tableView->setColumnWidth(1, 300);
}
void BatchImportCID::Display()
{
    //int index;
    //QString str,FileName;
    for(int i =0;i<fileList.size();i++)
    {
        Model->setrowcount(i+1);
        Model->setData(Model->index(i, 1), QVariant(fileList.at(i)), Qt::DisplayRole);
       QString str = fileList[i];

		str.clear();
		QModelIndex index;
        int ret = Point->LoadIEDFile(fileList.at(i),str);

        if(ret==DO_OK)
        {
         if(Point->CheckIEDName(str)==DO_FAIL)
         {
          Model->setData(Model->index(i, 0), QVariant(str), Qt::DisplayRole);
         Model->setData(Model->index(i, 2), QVariant(tr("IED name was repetition")), Qt::DisplayRole);
		 Model->setData(Model->index(i, 0), QColor(255, 0, 0), Qt::TextColorRole);
         }else
         {
          bool flag =false;
		  for (int m = 0; m<Model->rowCount(index); m++)
          {
              QString strname = Model->data(Model->index(m, 0), Qt::DisplayRole).toString();
              if ( strname== str)
           {
               Model->setData(Model->index(m, 2), QVariant(tr("IED name was repetition")), Qt::DisplayRole);
               Model->setData(Model->index(m, 0), QColor(255, 0, 0), Qt::TextColorRole);
               flag=true;
           }
          }
          if(flag==true)
          {
              Model->setData(Model->index(i, 0), QVariant(str), Qt::DisplayRole);
              Model->setData(Model->index(i, 2), QVariant(tr("IED name was repetition")), Qt::DisplayRole);
              Model->setData(Model->index(i, 0), QColor(255, 0, 0), Qt::TextColorRole);
          }else
          {
              Model->setData(Model->index(i, 0), QVariant(str), Qt::DisplayRole);
              Model->setData(Model->index(i, 2), QVariant(tr("No error")), Qt::DisplayRole);

          }
         }

        }else
        {
        Model->setData(Model->index(i, 0), QVariant(str), Qt::DisplayRole);
        Model->setData(Model->index(i, 2), QVariant(tr("Error")), Qt::DisplayRole);
        }
		Model->setData(Model->index(i, 0), QVariant(Qt::Checked), Qt::CheckStateRole);
    }
	ui->tableView->resizeColumnToContents(2);
}
void BatchImportCID::Pushbutton_all()
{
	QModelIndex index;
	for (int i = 0; i < Model->rowCount(index); i++)
    {

        Model->setData(Model->index(i, 0), QVariant(Qt::Checked), Qt::CheckStateRole);

    }
    ui->tableView->setFocus();
}

void BatchImportCID::Pushbutton_noall()
{
	QModelIndex index;
	for (int i = 0; i < Model->rowCount(index); i++)
    {

        Model->setData(Model->index(i, 0), QVariant(Qt::Unchecked), Qt::CheckStateRole);

    }
    ui->tableView->setFocus();
}

void BatchImportCID::Pushbutton_import()
{
    QString IEDName,FilePath,error;
	QModelIndex index;
	QColor m_color;
    File_Map.clear();
	//for (int i = 0; i < Model->rowCount(index);i++)
	//{
	//	m_color = Model->data(Model->index(i, 0), Qt::TextColorRole).value<QColor>();
 //       if (m_color==QColor::fromRgb(255,0,0))
	//	{
	//		QMessageBox::about(0, tr("Alarm"), tr("The was repetition IED Name"));
 //           return;
	//	}
	//}
	for (int i = 0; i < Model->rowCount(index); i++)
	{

		int state = Model->data(Model->index(i, 0), Qt::CheckStateRole).toInt();
		if (state == Qt::Unchecked)
		{
			continue;
		}
		m_color = Model->data(Model->index(i, 0), Qt::TextColorRole).value<QColor>();
		if (m_color == QColor::fromRgb(255, 0, 0))
		{
			QMessageBox::about(0, tr("Alarm"), tr("The was repetition IED Name"));
			return;
		}
		error = Model->data(Model->index(i, 2), Qt::DisplayRole).toString();
		if (error != tr("No error"))
		{
            QString str = Model->data(Model->index(i, 0), Qt::DisplayRole).toString();
            QMessageBox msgBox;
            msgBox.setText(tr("The IED(%1) File was error").arg(str));
            msgBox.setInformativeText("Select your next operation ");
            msgBox.setStandardButtons(QMessageBox::Ignore | QMessageBox::Abort);
            msgBox.setDefaultButton(QMessageBox::Ignore);
            int ret = msgBox.exec();
            if(ret==QMessageBox::Ignore)
            {
            continue;
            }else
            {
                return;
            }

		}
		IEDName = Model->data(Model->index(i, 0), Qt::DisplayRole).toString();
		if (!File_Map.contains(IEDName))
		{
			FilePath = Model->data(Model->index(i, 1), Qt::DisplayRole).toString();
			File_Map.insert(IEDName, FilePath);
		}

		accept();
	}

}
void BatchImportCID::OnDatadoubleClicked(const QModelIndex &index)
{
	QString IEDName = Model->data(Model->index(index.row(), 0), Qt::DisplayRole).toString();

	bool ok;
//    QModelIndex index;
	QString text = QInputDialog::getText(this, tr("Change IED name"),
		tr("IEDName:"), QLineEdit::Normal,
		IEDName, &ok);
	if (!text.isEmpty())
	{
        if(Point->CheckIEDName(text)==DO_OK)
        {
            bool flag =false;
            for(int i =0;i<Model->rowCount(index);i++)
            {
                QString strname =  Model->data(Model->index(i, 0), Qt::DisplayRole).toString();
                if ( strname== text)
             {
                 //Model->setData(Model->index(i, 0), QVariant(str), Qt::DisplayRole);
                 Model->setData(Model->index(i, 2), QVariant(tr("IED name was repetition")), Qt::DisplayRole);
                 Model->setData(Model->index(i, 0), QColor(255, 0, 0), Qt::TextColorRole);
                 flag=true;
             }
            }
            if(flag ==true)
            {
                Model->setData(Model->index(index.row(), 0), QVariant(text), Qt::DisplayRole);

                Model->setData(Model->index(index.row(), 2), QVariant(tr("IED name was repetition")), Qt::DisplayRole);
                Model->setData(Model->index(index.row(), 0), QColor(255, 0, 0), Qt::TextColorRole);

            }else
            {
                Model->setData(Model->index(index.row(), 0), QVariant(text), Qt::DisplayRole);
                Model->setData(Model->index(index.row(), 0), QColor(0, 0, 0), Qt::TextColorRole);
                Model->setData(Model->index(index.row(), 2), QVariant(tr("No error")), Qt::DisplayRole);

            }
        }else
        {
            QMessageBox::about(0,tr("Alarm"),tr("The name(%1) was repetition").arg(text));
            OnDatadoubleClicked(index);
        }
        for(int i =0;i<Model->rowCount(index);i++)
        {
            bool flag = false;
			Model->setData(Model->index(i, 0), QColor(0, 0, 0), Qt::TextColorRole);
			Model->setData(Model->index(i, 2), QVariant(tr("No error")), Qt::DisplayRole);
            for(int m =0;m<Model->rowCount(index);m++)
            {
                if(i==m)
                {
                   continue;
                }else
                {
                    if( Model->data(Model->index(i, 0), Qt::DisplayRole).toString()== Model->data(Model->index(m, 0), Qt::DisplayRole).toString())
                    {
                      Model->setData(Model->index(i, 0), QColor(255, 0, 0), Qt::TextColorRole);
                      Model->setData(Model->index(i, 2), QVariant(tr("IED name was repetition")), Qt::DisplayRole);
                      break;
                    }
                }
            }
            if(Point->CheckIEDName(Model->data(Model->index(i, 0), Qt::DisplayRole).toString())==DO_FAIL)
            {
                Model->setData(Model->index(i, 0), QColor(255, 0, 0), Qt::TextColorRole);
                Model->setData(Model->index(i, 2), QVariant(tr("IED name was repetition")), Qt::DisplayRole);

            }
        }
//        for(int i=0;i<Model->rowCount(index)-1;i++)
//        {
//			bool flag = false;
//            for(int m=i+1;m<Model->rowCount(index);m++)
//            {
//            if( Model->data(Model->index(i, 0), Qt::DisplayRole).toString()!= Model->data(Model->index(m, 0), Qt::DisplayRole).toString())
//            {
//    //            Model->setData(Model->index(m, 0), QColor(0, 0, 0), Qt::TextColorRole);
//    //            Model->setData(Model->index(m, 2), QVariant(tr("No error")), Qt::DisplayRole);
//				//Model->setData(Model->index(i, 0), QColor(0, 0, 0), Qt::TextColorRole);
//				//Model->setData(Model->index(i, 2), QVariant(tr("No error")), Qt::DisplayRole);
//				if (flag!=true)
//				{
//					Model->setData(Model->index(i, 0), QColor(0, 0, 0), Qt::TextColorRole);
//					Model->setData(Model->index(i, 2), QVariant(tr("No error")), Qt::DisplayRole);
//				}

//            }else
//            {
//                Model->setData(Model->index(i, 0), QColor(255, 0, 0), Qt::TextColorRole);
//                Model->setData(Model->index(i, 2), QVariant(tr("IED name was repetition")), Qt::DisplayRole);
//                Model->setData(Model->index(m, 0), QColor(255, 0, 0), Qt::TextColorRole);
//                Model->setData(Model->index(m, 2), QVariant(tr("IED name was repetition")), Qt::DisplayRole);
//				flag = true;

//            }
//            }
//        }
		return;
	}
}
