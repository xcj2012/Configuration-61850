#include "legitimacyverification.h"
#include"datastruct.h"
LegitimacyVerification::LegitimacyVerification(QWidget *parent)
: QDialog(parent)
{
	ui.setupUi(this);
	Init_dlg();
}

LegitimacyVerification::~LegitimacyVerification()
{}
void LegitimacyVerification::Init_dlg()
{
	ui.checkBox_Comm_IED->setText(tr("The Communication and IED Consistency checking"));
	ui.checkBox_FCDA->setText(tr("Functional constraint Legitimacy check"));
	ui.checkBox_Inputs->setText(tr("Virtual terminal mapping check"));
	ui.checkBox_Reference->setText(tr("Reference template check"));
	ui.checkBox_Warnning->setText(tr("Display warning"));
	ui.pushButton_check->setText(tr("Start Check"));
	ui.label_comm->setText(tr("Communication Verification"));
	ui.label_Fcda->setText(tr("FCDA Verification"));
	ui.label_receive->setText(tr("Virtual terminal mapping receiver Verification"));
	ui.label_send->setText(tr("Virtual terminal mapping sender Verification"));
	ui.label_Reference->setText(tr("Reference template Verification"));
    ui.checkBox_FCDA->setChecked(true);
    ui.checkBox_FCDA->setEnabled(false);
    ui.checkBox_Inputs->setChecked(true);
    ui.checkBox_Inputs->setEnabled(false);
    ui.checkBox_Reference->setChecked(true);
    ui.checkBox_Reference->setEnabled(false);
    ui.checkBox_Warnning->setChecked(true);
    ui.checkBox_Warnning->setEnabled(false);
    ui.progressBar->setValue(0);
	connect(ui.pushButton_check, SIGNAL(clicked()), this, SLOT(Pushbutton_Check_Click()));

}
int  LegitimacyVerification::CheckComm()
{
    m_Point->CommAndIed_Check(comm_errList);

	return DO_OK;
}

int  LegitimacyVerification::CheckFCDA()
{

    ui.textBrowser_Warning->append(tr("Start Check FCDA"));
    ui.progressBar->setValue(0);
	m_Point->FCDA_Check(FCDA_errList, FCDA_warnList, Reference_errList,ui.progressBar);
    ui.progressBar->setValue(100);
    return DO_OK;

}

int  LegitimacyVerification::CheckMapping()
{
	Receiver_errList.clear();
	Receiver_warnList.clear();
    ui.textBrowser_Warning->append(tr("Start Check Mapping"));

    ui.progressBar->setValue(0);
    //Reference_errList.clear();
    m_Point->MappingReceiver_Check(Sender_errList, Receiver_errList, Sender_warnList, Receiver_warnList, Reference_errList,ui.progressBar);
    ui.progressBar->setValue(100);
    return DO_OK;
}

int  LegitimacyVerification::CheckSender()
{
	m_Point->MappingSender_Check(Sender_errList, Sender_warnList, Reference_errList);
	return DO_OK;
}

int  LegitimacyVerification::CheckReference()
{
	return DO_OK;
}

void  LegitimacyVerification::DisCheckComm()
{
    for (int i =0;i<comm_errList.size();i++)
    {
        ui.textBrowser_Comm->append(comm_errList[i]);
    }
    if (comm_errList.size()==0)
    {
		ui.textBrowser_Comm->append(tr("Communication Check Success"));

    }
}

void  LegitimacyVerification::DisCheckFCDA()
{
	for (int i = 0; i < FCDA_warnList.size(); i++)
	{
        ui.textBrowser_Fcda->append(FCDA_warnList[i]);
	}
	for (int i = 0; i < FCDA_errList.size(); i++)
	{
		ui.textBrowser_Fcda->append(FCDA_errList[i]);
	}
    if((FCDA_errList.size()==0)&&(FCDA_warnList.size()==0))
    {
        ui.textBrowser_Fcda->append(tr("FCDA Check Success"));
    }
//    for (int i = 0; i < Reference_errList.size(); i++)
//	{
//		ui.textBrowser_Reference->append(Reference_errList[i]);
//	}
}

void  LegitimacyVerification::DisMapping()
{
//	for (int i = 0; i < Sender_warnList.size(); i++)
//	{
//		ui.textBrowser_Send->append(Sender_warnList[i]);
//	}
//	for (int i = 0; i < Sender_errList.size(); i++)
//	{
//		ui.textBrowser_Send->append(Sender_errList[i]);
//	}
//    if((Sender_errList.size()==0)&&(Sender_warnList.size()==0))
//    {
//        ui.textBrowser_Send->append(tr("Sender Check Success"));
//    }
//	for (int i = 0; i < Reference_errList.size(); i++)
//	{
//		ui.textBrowser_Reference->append(Reference_errList[i]);
//	}
}

void  LegitimacyVerification::DisCheckSender()
{
    for (int i = 0; i < Sender_warnList.size(); i++)
    {
        ui.textBrowser_Send->append(Sender_warnList[i]);
    }
    for (int i = 0; i < Sender_errList.size(); i++)
    {
        ui.textBrowser_Send->append(Sender_errList[i]);
    }
    if((Sender_errList.size()==0)&&(Sender_warnList.size()==0))
    {
        ui.textBrowser_Send->append(tr("Sender Check Success"));
    }
}
void LegitimacyVerification::DisCheckReceiver()
{
    for (int i = 0; i < Receiver_warnList.size(); i++)
    {
        ui.textBrowser_Receive->append(Receiver_warnList[i]);
    }
    for (int i = 0; i < Receiver_errList.size(); i++)
    {
        ui.textBrowser_Receive->append(Receiver_errList[i]);
    }
    if((Receiver_errList.size()==0)&&(Receiver_warnList.size()==0))
    {
        ui.textBrowser_Receive->append(tr("Receiver Check Success"));
    }
}

void  LegitimacyVerification::DisCheckReference()
{
    for (int i = 0; i < Reference_errList.size(); i++)
    {
        ui.textBrowser_Reference->append(Reference_errList[i]);
    }
    if(Reference_errList.size()==0)
    {
		ui.textBrowser_Reference->append(tr("Reference Check Success"));
    }
}

void  LegitimacyVerification::DisWarning()
{
	ui.textBrowser_Warning->clear();
    QString error;
    int ErrNum,WarnNum;
	ErrNum = FCDA_errList.size() + Reference_errList.size() + Sender_errList.size() + Receiver_errList.size() + comm_errList.size();
    WarnNum =FCDA_warnList.size()+Reference_warnList.size()+Sender_warnList.size()+Receiver_warnList.size()+comm_warnList.size();
    error = tr("Check Finish: Err Number %1,Warning Number %2").arg(QString::number(ErrNum,10)).arg(QString::number(WarnNum,10));
    ui.textBrowser_Warning->append(error);
}
//void LegitimacyVerification::DisReference()
//{
//        for (int i = 0; i < Reference_errList.size(); i++)
//        {
//            ui.textBrowser_Reference->append(Reference_errList[i]);
//        }
//}

void LegitimacyVerification::Pushbutton_Check_Click()
{
	 comm_errList.clear();
	 FCDA_errList.clear();
	 Receiver_errList.clear();
	 Sender_errList.clear();
	 Reference_errList.clear();
	 comm_warnList.clear();
	 FCDA_warnList.clear();
	 Receiver_warnList.clear();
	 Sender_warnList.clear();
	 Reference_warnList.clear();
     ui.textBrowser_Comm->clear();
     ui.textBrowser_Fcda->clear();
     ui.textBrowser_Receive->clear();
     ui.textBrowser_Reference->clear();
     ui.textBrowser_Send->clear();
     ui.textBrowser_Warning->clear();
	 ui.textBrowser_Warning->append(tr("Start Check in"));
	//    CheckComm();
	//    DisCheckComm();
//    if(ui.checkBox_FCDA->checkState()==Qt::Checked)
//     Wait_Dlg m_dlg;
//     m_dlg.Set(tr("Checking ,Please wait"));
//     m_dlg.show();
    if(ui.checkBox_Comm_IED->checkState()==Qt::Checked)
    {
            CheckComm();
            DisCheckComm();
    }
    CheckFCDA();
	DisCheckFCDA();
	CheckMapping();
    DisCheckSender();
    DisCheckReceiver();
    DisCheckReference();
    DisWarning();
    //m_dlg.m_Close();
    //if(Reference_errList.size())
	//CheckSender();
	//DisCheckSender();
	//CheckReference();
	//DisCheckReference();
	//DisWarning();
}
