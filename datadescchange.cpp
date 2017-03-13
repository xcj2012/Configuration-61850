#include "datadescchange.h"

DataDescChange::DataDescChange(QWidget *parent)
	: QDialog(parent)
{
	ui.setupUi(this);
    ui.label_Desc->setText(tr("Desc"));
    ui.label_DU->setText(tr("dU"));
    ui.pushButton_Apply->setText(tr("Apply"));
    ui.pushButton_Cancel->setText(tr("Cancel"));
    connect(ui.lineEdit_Desc1,SIGNAL(textChanged(QString)),this,SLOT(TextChange1(QString)));
    connect(ui.lineEdit_Desc2,SIGNAL(textChanged(QString)),this,SLOT(TextChange2(QString)));
    connect(ui.pushButton_Apply,SIGNAL(clicked(bool)),this,SLOT(Pushbutton_Apply()));
    connect(ui.pushButton_Cancel,SIGNAL(clicked(bool)),this,SLOT(Pushbutton_Cancel()));
}

DataDescChange::~DataDescChange()
{

}
void DataDescChange::Display(QString Desc1, QString Desc2, QString DU1, QString DU2)
{
    ui.lineEdit_Desc1->setText(Desc1);
	if (Desc2.isEmpty())
    {
        ui.lineEdit_Desc2->hide();
		ui.lineEdit_dU2->hide();
		ui.lineEdit_dU1->setEnabled(false);
		ui.lineEdit_dU1->setText(DU1);

    }else
    {
        ui.lineEdit_Desc2->setText(Desc2);
		ui.lineEdit_dU1->setEnabled(false);
		ui.lineEdit_dU1->setText(DU1);
		ui.lineEdit_dU2->setEnabled(false);
		ui.lineEdit_dU2->setText(DU2);
    }

}

void DataDescChange::Pushbutton_Apply()
{
    strDesc1 = ui.lineEdit_Desc1->text();
    strDesc2 = ui.lineEdit_Desc2->text();
    strDU1 = ui.lineEdit_dU1->text();
	strDU2 = ui.lineEdit_dU2->text();
    accept();
}

void DataDescChange::Pushbutton_Cancel()
{
    reject();
}
void DataDescChange::TextChange1(QString text)
{

    ui.lineEdit_dU1->setText(text);
}
void DataDescChange::TextChange2(QString text)
{

    ui.lineEdit_dU2->setText(text);
}
