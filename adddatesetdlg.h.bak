#ifndef ADDDATESETDLG_H
#define ADDDATESETDLG_H

#include <QDialog>
#include<QMessageBox>
namespace Ui {
class AddDateSetdlg;
}

class AddDateSetdlg : public QDialog
{
    Q_OBJECT

public:
    explicit AddDateSetdlg(QWidget *parent = 0);
    ~AddDateSetdlg();
    void init_dlg();
    void setstate(int state);
    void SetDataSetName(QString strname);
    void SetDataSetDesc(QString strDesc);
	QString GetDataSetName();
	QString GetDataSetDesc();
    bool CheckDataSetName(QString Name);
    QStringList NameList;
private slots:
   void pushbutton_ok();
   void pushbutton_cancel();
private:
	QString str_DataSetName;
		QString str_DataSetDesc;
        int i_state;
    Ui::AddDateSetdlg *ui;


};

#endif // ADDDATESETDLG_H
