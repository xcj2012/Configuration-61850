#ifndef TIMESERVER_H
#define TIMESERVER_H

#include <QDialog>

namespace Ui {
class TimeServer;
}

class TimeServer : public QDialog
{
    Q_OBJECT

public:
    explicit TimeServer(QWidget *parent = 0);
    ~TimeServer();

private:
    Ui::TimeServer *ui;
};

#endif // TIMESERVER_H
