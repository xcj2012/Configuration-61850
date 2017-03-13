#ifndef EXPORTCID_H
#define EXPORTCID_H

#include <QDialog>
#include"userdefinedelegate.h"
#include "datastruct.h"
#include "scdtree.h"
#include <QFileDialog>
#include <QInputDialog>
namespace Ui {
class ExPortCID;
}

class ExPortCID : public QDialog
{
    Q_OBJECT

public:
    explicit ExPortCID(QWidget *parent = 0);
    ~ExPortCID();
    QString FilePath;
	QString FileName;
	int SETState;
    void Init_dlg(int );
    void Display();
	void ExportCID_FILE(QString,QString);
    void ExportMAP_FILE(QStringList);
	void ExportConfig_FILE(QString, QString);
public:
    BatchExport *Model;
    QStringList header;
    QMap<QString,QString> File_Map;
    QVector<IEDstruct> IedList;
    ScdTree *Point;
private slots:
    void Pushbutton_all();
    void Pushbutton_noall();
    void Pushbutton_export();
    void Pushbutton_Cancel();
    void Pushbutton_browse();
    //void OnDataChanged(const QModelIndex & topLeft, const QModelIndex & bottomRight);
    void OnDatadoubleClicked(const QModelIndex &);
private:
    Ui::ExPortCID *ui;
};

#endif // EXPORTCID_H
