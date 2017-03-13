#ifndef TERMINALTYPECHECK_H
#define TERMINALTYPECHECK_H

#include <QDialog>
#include"scdtree.h"
#include"userdefinedelegate.h"
#include <QStandardItemModel> 
namespace Ui {
class TerminalTypeCheck;
}

class TerminalTypeCheck : public QDialog
{
    Q_OBJECT
public:
	ScdTree *Point;
	QVector<IEDstruct> IEDList; 
	QVector<IEDstruct> IEDList_Checked;
	void init_dlg();
	void DisplayIED();
	void GetIDEList();
	void CheckMatching();
	CheckBoxModel *m_Model;
	QStringList headerList;
    QVector<Input_Struct> errlist;
public:
    explicit TerminalTypeCheck(QWidget *parent = 0);
    ~TerminalTypeCheck();
	private slots:
	void Pushbutton_all();
	void Pushbutton_noall();
	void Pushbutton_check();
private:
    Ui::TerminalTypeCheck *ui;
};

#endif // TERMINALTYPECHECK_H
