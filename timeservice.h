#ifndef TIMESERVICE_H
#define TIMESERVICE_H

#include <QDialog>
#include "datastruct.h"
namespace Ui {
class TimeService;
}

class TimeService : public QDialog
{
    Q_OBJECT

public:
    explicit TimeService(QWidget *parent = 0);
	void Init_dlg();
	void Display();
	QStringList headerList;
    ~TimeService();
public:
	TimeServer m_timeserver;
	private slots:
	void pushbutton_apply();
	void pushbutton_cancel();
private:
    Ui::TimeService *ui;
};

#endif // TIMESERVICE_H
