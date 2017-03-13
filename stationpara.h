#ifndef STATIONPARA_H
#define STATIONPARA_H

#include <QDialog>

namespace Ui {
class StationPara;
}

class StationPara : public QDialog
{
    Q_OBJECT

public:
    explicit StationPara(QWidget *parent = 0);
    ~StationPara();
    QString vendor;
    QString Line;
    QString ProjectName;
    QString Version;
    void display(int state);
private slots:
    void pushbutton_ok();
    void pushbutton_cancel();
private:
    Ui::StationPara *ui;
};

#endif // STATIONPARA_H
