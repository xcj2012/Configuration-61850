#include "terminaltypecheck.h"
#include "ui_terminaltypecheck.h"

TerminalTypeCheck::TerminalTypeCheck(QWidget *parent) :
QDialog(parent),
ui(new Ui::TerminalTypeCheck)
{
	m_Model = new CheckBoxModel;
	ui->setupUi(this);
	setWindowTitle(tr("The type of terminal matching test"));
	ui->splitter->setStretchFactor(0, 35);
	ui->splitter->setStretchFactor(1, 65);
	ui->progressBar->setValue(0);
	connect(ui->pushButton_Check, SIGNAL(clicked()), this, SLOT(Pushbutton_check()));
	connect(ui->pushButton_All, SIGNAL(clicked()), this, SLOT(Pushbutton_all()));
	connect(ui->pushButton_NoAll, SIGNAL(clicked()), this, SLOT(Pushbutton_noall()));
}

TerminalTypeCheck::~TerminalTypeCheck()
{
	delete ui;
}
void TerminalTypeCheck::init_dlg()
{
	ui->pushButton_Check->setText(tr("Check"));
	ui->pushButton_All->setText(tr("Check All"));
    ui->pushButton_NoAll->setText(tr("ALL NO"));
	ui->checkBox->setEnabled(false);
    ui->checkBox->setChecked(true);
	ui->label->setText(tr("IED List"));
	ui->checkBox->setText(tr("There is no daName in the dataset,the value consider as INT32"));
	headerList.clear();
    headerList << tr("name") << tr("desc");


	ui->tableView->setSelectionMode(QAbstractItemView::SingleSelection);

	m_Model->setcolumncount(headerList.count());
	m_Model->setrowcount(IEDList.size());

	ui->tableView->setModel(m_Model);
	ui->tableView->setColumnWidth(0, 100);
	ui->tableView->setColumnWidth(1, 100);

}
void TerminalTypeCheck::GetIDEList()
{
	IEDList.clear();
	Point->GetIEDList(IEDList);
}
void TerminalTypeCheck::DisplayIED()
{
	for (int i = 0; i < IEDList.size(); i++)
	{

		m_Model->setData(m_Model->index(i, 0), QVariant(IEDList.at(i).s_IEDname), Qt::DisplayRole);
		m_Model->setData(m_Model->index(i, 1), QVariant(IEDList.at(i).s_IEDdesc), Qt::DisplayRole);
	}
}
void TerminalTypeCheck::Pushbutton_all()
{
	for (int i = 0; i < IEDList.size(); i++)
	{

		m_Model->setData(m_Model->index(i, 0), QVariant(Qt::Checked), Qt::CheckStateRole);

	}
	ui->tableView->setFocus();
}
void TerminalTypeCheck::Pushbutton_noall()
{
	for (int i = 0; i < IEDList.size(); i++)
	{

		m_Model->setData(m_Model->index(i, 0), QVariant(Qt::Unchecked), Qt::CheckStateRole);

	}
	ui->tableView->setFocus();
}
void TerminalTypeCheck::Pushbutton_check()
{
	IEDList_Checked.clear();
	for (int i = 0; i < IEDList.size(); i++)
	{
		int state = m_Model->data(m_Model->index(i, 0), Qt::CheckStateRole).toInt();
		if (state == Qt::Checked)
		{
			IEDList_Checked.append(IEDList[i]);
		}
	}
	if (IEDList_Checked.size()==0)
	{
		return;
	}
	CheckMatching();
}
void TerminalTypeCheck::CheckMatching()
{
	errlist.clear();
	ui->textBrowser->clear();
	for (int i = 0; i < IEDList_Checked.size(); i++)
	{
		Point->CheckMatching(IEDList_Checked[i].s_IEDname, errlist);
		ui->progressBar->setValue(i * 100 / IEDList_Checked.size());
	}
	ui->progressBar->setValue(100);
	if (errlist.size()==0)
	{
		ui->textBrowser->append(tr("There is no error"));
	}
	for (int i = 0; i < errlist.size(); i++)
	{
		QString errmes = tr("Err the Virtual terminal of IED=%11 {iedName =%1,daName=%2,doName=%3,ldInst=%4,lnClass=%5,lnInst=%6,prefix=%7,intAddr=%8},the type=%9 of receiver is not match the type=%10 of sender")
			.arg(errlist[i].B_iedName).arg(errlist[i].B_daName).arg(errlist[i].B_doName)
			.arg(errlist[i].B_ldInst).arg(errlist[i].B_lnClass).arg(errlist[i].B_lnInst)
			.arg(errlist[i].B_prefix).arg(errlist[i].B_intAddr).arg(errlist[i].B_IndaType)
			.arg(errlist[i].B_ExdaType).arg(errlist[i].B_InterIED);
		ui->textBrowser->append(errmes);
	}
}
