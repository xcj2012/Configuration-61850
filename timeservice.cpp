#include "timeservice.h"
#include "ui_timeservice.h"

TimeService::TimeService(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::TimeService)
{
    ui->setupUi(this);
	headerList << "SERVER" << "CLIENT";
	ui->comboBox_Mod->addItems(headerList);
	headerList.clear();
	headerList << "UNICAST" << "BROADCAST";
	ui->comboBox_TimeMode->addItems(headerList);
	Init_dlg();
	connect(ui->pushButton_Apply, SIGNAL(clicked(bool)), this, SLOT(pushbutton_apply()));
	connect(ui->pushButton_Cancel, SIGNAL(clicked(bool)), this, SLOT(pushbutton_cancel()));
}

TimeService::~TimeService()
{
    delete ui;
}
void TimeService::Init_dlg()
{
	ui->label_Group->setText(tr("GroupNum"));
	ui->label_IP1->setText(tr("GroupIp1"));
	ui->label_IP2->setText(tr("GroupIp2"));
	ui->label_IP3->setText(tr("GroupIp3"));
	ui->label_Mod->setText(tr("Mode"));
	ui->label_Port->setText(tr("Port"));
	ui->pushButton_Apply->setText(tr("Apply"));
	ui->pushButton_Cancel->setText(tr("Cancel"));
	ui->label_TimeMode->setText(tr("TimeMode"));
}
void TimeService::Display()
{
	ui->lineEdit_Group->setText(m_timeserver.GroupNum);
	ui->lineEdit_IP1->setText(m_timeserver.GroupIp1);
	ui->lineEdit_IP2->setText(m_timeserver.GroupIp2);
	ui->lineEdit_IP3->setText(m_timeserver.GroupIp3);
	ui->lineEdit_Port->setText(m_timeserver.PortNo);
	ui->comboBox_Mod->setCurrentText(m_timeserver.Mode);
	ui->comboBox_TimeMode->setCurrentText(m_timeserver.TimeMode);
}
void TimeService::pushbutton_apply()
{
	m_timeserver.GroupNum = ui->lineEdit_Group->text();
	m_timeserver.GroupIp1 = ui->lineEdit_IP1->text();
	m_timeserver.GroupIp2 = ui->lineEdit_IP2->text();
	m_timeserver.GroupIp3 = ui->lineEdit_IP3->text();
	m_timeserver.PortNo = ui->lineEdit_Port->text();
	m_timeserver.Mode = ui->comboBox_Mod->currentText();
	m_timeserver.TimeMode = ui->comboBox_TimeMode->currentText();
	accept();
}
void TimeService::pushbutton_cancel()
{
	reject();
}