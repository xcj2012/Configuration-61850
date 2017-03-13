#include "adddatesetdlg.h"
#include "ui_adddatesetdlg.h"

AddDateSetdlg::AddDateSetdlg(QWidget *parent) :
QDialog(parent),
ui(new Ui::AddDateSetdlg)
{
	ui->setupUi(this);
	ui->pushButton_ok->setText(tr("Ok"));
	ui->pushButton_cancel->setText(tr("Cancel"));
	ui->label_name->setText(tr("Name"));
	ui->label_desc->setText(tr("Desc"));
    ui->groupBox->setTitle(tr("Naming conventions"));
	connect(ui->pushButton_ok, SIGNAL(clicked()), this, SLOT(pushbutton_ok()));
	connect(ui->pushButton_cancel, SIGNAL(clicked()), this, SLOT(pushbutton_cancel()));
	NameList << "dsAin" << "dsDin" << "dsAlarm" << "dsWarning" << "dsCommState" << "dsParameter"
		<< "dsInterLock" << "dsGOOSE" << "dsTripInfo" << "dsRelayDin" << "dsRelayEna" << "dsRelayRec"
        << "dsRelayAin" << "dsSetting" << "dsSV" << "dsLog";
    QStringList DescList;
    DescList<< "Analog in" << "Digital in" << "Alarm Signal" << "Warning Signal" << "Communication state" << "Set parameter"
            << "Interlocking state" << "GOOSE Signal" << "Trip Info" << "Relay Digital in" << "Relay Ena" << "Relay Rec"
            << "Relay Analog in" << "Setting" << "SV" << "Log";
    ui->textBrowser->append(tr("The format of name is Name+Index"));
	ui->textBrowser->append(tr("Example:One Group Goose named dsGOOSE, more than one ,named dsGOOSE1"));
    for(int i =0;i<NameList.size();i++)
    {
       QString str;
        str =NameList.at(i)+"::"+DescList.at(i);
        ui->textBrowser->append(str);
    }
}
AddDateSetdlg::~AddDateSetdlg()
{
	delete ui;
}
void AddDateSetdlg::pushbutton_ok()
{
	if (ui->lineEdit_name->text().isEmpty())
	{
		QMessageBox::about(0, tr("Alarm"), tr("The name of dataset must be input"));
		return;
	}
	if (ui->lineEdit_desc->text().isEmpty())
	{
		QMessageBox::about(0, tr("Alarm"), tr("The desc of dataset must be input"));
		return;
	}
	str_DataSetName = ui->lineEdit_name->text();
	str_DataSetDesc = ui->lineEdit_desc->text();
	if (CheckDataSetName(str_DataSetName) == false)
	{
		str_DataSetName.clear();
		str_DataSetDesc.clear();
		return;
	}

	accept();
}
void AddDateSetdlg::pushbutton_cancel()
{
	reject();
}
void AddDateSetdlg::init_dlg()
{
	if (i_state == 1)
	{
		setWindowTitle(tr(" Add new DataSet"));
	}
	else if (i_state == 2)
	{
		setWindowTitle(tr("Rename DataSet"));
		ui->lineEdit_name->setText(str_DataSetName);
		ui->lineEdit_desc->setText(QString(str_DataSetDesc));
	}
}
void AddDateSetdlg::setstate(int state)
{
	i_state = state;
}
void AddDateSetdlg::SetDataSetName(QString strname)
{
	str_DataSetName = strname;
}

void AddDateSetdlg::SetDataSetDesc(QString strDesc)
{
	str_DataSetDesc = strDesc;
}

QString AddDateSetdlg::GetDataSetName()
{
	return str_DataSetName;
}

QString AddDateSetdlg::GetDataSetDesc()
{
	return str_DataSetDesc;
}
bool AddDateSetdlg::CheckDataSetName(QString Name)
{
	int k = 0;
	for (int i = 0; i < NameList.size(); i++)
	{
		if (Name.contains(NameList.at(i), Qt::CaseInsensitive))
		{
			k = i + 1;
			break;
		}
	}
	if (k == 0)
	{
		QMessageBox::about(this, tr("Notice"), tr("The format of name is wrong"));
		return false;

	}
	else
	{
		int index; 
		index = Name.indexOf(NameList.at(k - 1));
		if (index != 0)
		{
			QMessageBox::about(this, tr("Notice"), tr("Can not add prefix"));
			return false;
		}
		QString str = Name.remove(NameList.at(k - 1));
		for (int i = 0; i < str.size(); i++)
		{
			if ((str.at(i)<'0') || (str.at(i)>'9'))
			{
				QMessageBox::about(this, tr("Notice"), tr("The Index only can be number"));
				return false;
			}
		}
	}
	return true;

}
