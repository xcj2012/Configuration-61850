#ifndef WAIT_DLG_H
#define WAIT_DLG_H

#include <QDialog>
#include "ui_wait_dlg.h"
#include <QMovie>

class Wait_Dlg : public QDialog
{
	Q_OBJECT

public:
	Wait_Dlg(QWidget *parent = 0);
	void Set(QString str);
	QMovie *movie;
    void Display();
	~Wait_Dlg();
	void m_Close();
private:
	Ui::Wait_Dlg ui;
};

#endif // WAIT_DLG_H
