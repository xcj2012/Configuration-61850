#ifndef IMPORTONEIED_H
#define IMPORTONEIED_H

#include <QDialog>
#include"scdtree.h"
#include<qfiledialog.h>
namespace Ui {
class ImportOneIed;
}

class ImportOneIed : public QDialog
{
    Q_OBJECT

public:
    explicit ImportOneIed(QWidget *parent = 0,ScdTree *point = 0);
    ~ImportOneIed();
	int state;
    void InitDlg();
    int LoadIEDFile(QString fileName);
	void setState(int);
    QString GetIEDName();
    QString GetFileName();

private:
    QString strfilename;
    ScdTree *SCDPoint;
private slots:
    void Action_loadfile();
    void Action_button_ok();
    void Action_button_cancle();
private:
    Ui::ImportOneIed *ui;
};

#endif // IMPORTONEIED_H
