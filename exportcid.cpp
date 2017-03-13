#include "exportcid.h"
#include "ui_exportcid.h"

ExPortCID::ExPortCID(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::ExPortCID)
{
    ui->setupUi(this);
    Model = new BatchExport;
    connect(ui->pushButton_All, SIGNAL(clicked()), this, SLOT(Pushbutton_all()));
    connect(ui->pushButton_Apply, SIGNAL(clicked()), this, SLOT(Pushbutton_export()));
    connect(ui->pushButton_Browse, SIGNAL(clicked()), this, SLOT(Pushbutton_browse()));
    connect(ui->pushButton_NoAll, SIGNAL(clicked()), this, SLOT(Pushbutton_noall()));
    connect(ui->pushButton_Cancel, SIGNAL(clicked()), this, SLOT(Pushbutton_Cancel()));
    connect(ui->tableView, SIGNAL(doubleClicked(const QModelIndex &)), this, SLOT(OnDatadoubleClicked(const QModelIndex &)));
    ui->progressBar->setValue(0);
}

ExPortCID::~ExPortCID()
{

    delete ui;
}
void ExPortCID::Init_dlg(int state)
{
	SETState = state;
	if (state ==0x01)
	{
		setWindowTitle(tr("Export XML"));
	}
	else 	if (state == 0x02)
	{
		setWindowTitle(tr("Export XLS"));
	}
	else 	if (state == 0x04)
	{
		setWindowTitle(tr("Export CID"));
	}
    header<<tr("IEDName")<<tr("Type")<<tr("Vendor")<<tr("Desc")<<tr("FileName");
    Model->SetHeaderList(header);
    ui->pushButton_All->setText(tr("Chose All"));
    ui->pushButton_Apply->setText(tr("Export"));
    ui->pushButton_Apply->setEnabled(false);
    ui->pushButton_NoAll->setText(tr("ALL NO"));
    ui->pushButton_Browse->setText(tr("Browse"));
    ui->pushButton_Cancel->setText(tr("Cancel"));
    ui->label_Path->setText(tr("Export Path:"));
    ui->tableView->setSelectionBehavior(QAbstractItemView::SelectRows);
    Model->setcolumncount(header.size());
   
    ui->tableView->setModel(Model);
    ui->tableView->setColumnWidth(0, 200);
    ui->tableView->setColumnWidth(1, 100);
    ui->tableView->setColumnWidth(2, 100);
	ui->tableView->setColumnWidth(3, 200);
	ui->tableView->setColumnWidth(4, 100);
	ui->tableView->horizontalHeader()->setSectionResizeMode(QHeaderView::Interactive);

}

void ExPortCID::Display()
{
    for(int i =0;i<IedList.size();i++)
    {
		Model->setrowcount(i+1);
        Model->setData(Model->index(i, 0), QVariant(IedList[i].s_IEDname), Qt::DisplayRole);
        Model->setData(Model->index(i, 0), QVariant(Qt::Checked), Qt::CheckStateRole);
        Model->setData(Model->index(i, 1), QVariant(IedList[i].s_IEDtype), Qt::DisplayRole);
        Model->setData(Model->index(i, 2), QVariant(IedList[i].s_IEDvendor), Qt::DisplayRole);
        Model->setData(Model->index(i, 3), QVariant(IedList[i].s_IEDdesc), Qt::DisplayRole);
		if (SETState == 0x01)
		{
			Model->setData(Model->index(i, 4), QVariant(IedList[i].s_IEDname + ".XML"), Qt::DisplayRole);
		}
		else 		if (SETState == 0x04)
		{
			Model->setData(Model->index(i, 4), QVariant(IedList[i].s_IEDname + ".CID"), Qt::DisplayRole);
		}
		else 		if (SETState == 0x2)
		{
			ui->tableView->setColumnHidden(4, true);

		}
    }
}
void ExPortCID::Pushbutton_all()
{
    QModelIndex index;
    for (int i = 0; i < Model->rowCount(index); i++)
    {

        Model->setData(Model->index(i, 0), QVariant(Qt::Checked), Qt::CheckStateRole);

    }
    ui->tableView->setFocus();
}

void ExPortCID::Pushbutton_noall()
{
    QModelIndex index;
    for (int i = 0; i < Model->rowCount(index); i++)
    {

        Model->setData(Model->index(i, 0), QVariant(Qt::Unchecked), Qt::CheckStateRole);

    }
    ui->tableView->setFocus();
}

void ExPortCID::Pushbutton_export()
{
    File_Map.clear();
    ui->progressBar->setValue(0);
    QString File_Name ,IEDName;
	QStringList FileList;
	int state;
	for (int i = 0; i<IedList.size(); i++)
    {
		state = Model->data(Model->index(i, 0), Qt::CheckStateRole).toInt();
		if (state == Qt::Unchecked)
		{
			continue;
		}
       IEDName = Model->data(Model->index(i, 0), Qt::DisplayRole).toString();
	   File_Name = Model->data(Model->index(i, 4), Qt::DisplayRole).toString();
	   File_Map.insert(IEDName, File_Name);
    }
	FileList = File_Map.keys();
    if(FileList.size()==0)
    {
		QMessageBox::about(this, tr("Export CID"), tr("Please Select IED"));
        return;
    }
    if(SETState==0x04)
    {
    ExportMAP_FILE(File_Map.keys());
    }else if (SETState == 0x02)
    {
    ExportMAP_FILE(File_Map.keys());
    QMessageBox::about(this, tr("Export XLS"), tr("Export XLS Finish"));
    return;
    }
    if(SETState==0x04)
    {
        QMessageBox::about(0, QObject::tr("Notice"), QObject::tr("The config file only the device of keyvia can export!"));
    }
    int value;
    if(FileList.size()<100)
    {
        value= 100/FileList.size();
        ui->progressBar->setMaximum(100);
    }else if((100<FileList.size())&&(FileList.size()<1000))
    {
        value= 1000/FileList.size();
        ui->progressBar->setMaximum(1000);

    }

    ui->progressBar->setToolTip(tr("CID"));
	for (int i = 0; i < FileList.size();i++)
	{
        ui->progressBar->setValue(i*value*10);
		if (SETState==0x04)
		{
			ExportCID_FILE(FileList[i], File_Map.value(FileList[i]));
			ExportConfig_FILE(FileList[i], File_Map.value(FileList[i]));
	
		}
        else if (SETState == 0x01)
		{
			ExportConfig_FILE(FileList[i], File_Map.value(FileList[i]));

		}

	}
    ui->progressBar->setValue(100);
    if (state ==0x01)
    {
        //setWindowTitle(tr("Export XML"));
        QMessageBox::about(this, tr("Export XML"), tr("Export XML Finish"));

    }
//    else 	if (state == 0x02)
//    {
//        //setWindowTitle(tr("Export XLS"));
//        QMessageBox::about(this, tr("Export XLS"), tr("Export XLS success"));

//    }
    else 	if (state == 0x04)
    {
        //setWindowTitle(tr("Export CID"));
        QMessageBox::about(this, tr("Export CID"), tr("Export CID Finish"));

    }
    //QMessageBox::about(this, tr("Export CID"), tr("Export CID success"));

}

void ExPortCID::Pushbutton_Cancel()
{
reject();
}

void ExPortCID::Pushbutton_browse()
{
    QString dir = QFileDialog::getExistingDirectory(this, tr("Open Directory"),
                                                    QDir::currentPath(),
                                                    QFileDialog::ShowDirsOnly
                                                    | QFileDialog::DontResolveSymlinks);
    if (dir.isEmpty())
        return;
	if (dir.at(dir.length() - 1)!= '/')
	{
		FilePath = dir + "/";
	}
	else
	{
		FilePath = dir;
	}

    ui->lineEdit_Path->setText(FilePath);
    ui->pushButton_Apply->setEnabled(true);
}

void ExPortCID::OnDatadoubleClicked(const QModelIndex &index)
{
    if(SETState==0x02||SETState==0x01)
        return;
    QString FILEName = Model->data(Model->index(index.row(), 4), Qt::DisplayRole).toString();

    bool ok;
    QString text = QInputDialog::getText(this, tr("Change FIle name"),
        tr("FIleName:"), QLineEdit::Normal,
		FILEName, &ok);
    int i;
    i = text.indexOf(".");
    if(i ==-1)
    {
        text = text+".CID";
    }else
    {
        text = text.left(i)+".CID";
    }
    if (!text.isEmpty())
    {
        Model->setData(Model->index(index.row(), 4), QVariant(text), Qt::DisplayRole);
        return;
    }
}
void ExPortCID::ExportCID_FILE(QString IEDName, QString strfile)
{
	
    strfile = FilePath+ strfile;
    Point->ExportCID_FILE(IEDName, strfile);
}
void ExPortCID::ExportMAP_FILE(QStringList list)
{
    ui->progressBar->setToolTip(tr("Exprot xls"));
    Point->ExportXLS_FILE(list, FilePath + FileName,ui->progressBar);
}
void ExPortCID::ExportConfig_FILE(QString IEDName, QString FileName)
{
	FileName=FileName.replace(".CID", ".XML", Qt::CaseInsensitive);
	FileName = FilePath+ FileName;
	Point->ExportCONFIG_FILE(IEDName, FileName);
}
