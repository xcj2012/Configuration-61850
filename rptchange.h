#ifndef RPTCHANGE_H
#define RPTCHANGE_H

#include <QDialog>
#include"datastruct.h"
#include <QStandardItemModel>
#include"userdefinedelegate.h"
namespace Ui {
class RptChange;
}

class RptChange : public QDialog
{
    Q_OBJECT

public:
    explicit RptChange(QWidget *parent = 0);
    ~RptChange();
    void init_dlg();
    void Displaydata();
    int istate;
    QStringList Interactive;
    QStandardItemModel *m_Model;
    TrgOps_Struct m_Trgops;
    OptFields_Struct m_OptField;
    RptEnabled_Struct m_RptEndabled;
private slots:
    void on_pushbutton_ok_clicked();
    void on_pushbutton_cancel_clicked();
private:
    Ui::RptChange *ui;
};

#endif // RPTCHANGE_H
