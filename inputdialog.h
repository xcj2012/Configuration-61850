#ifndef INPUTDIALOG_H
#define INPUTDIALOG_H
#include"scdtree.h"
#include <QDialog>
#include "droptable.h"
#include <QStandardItemModel>
#include<qapplication.h>
#include <QDesktopWidget>
#include <QTreeWidgetItem>
#include <QMimeData>
#include <QMenu>

namespace Ui {
class InputDialog;
}

class InputDialog : public QDialog
{
    Q_OBJECT

public:
    explicit InputDialog(QWidget *parent = 0);
    ~InputDialog();
    void Init_dlg();
    ScdTree* m_scdpoint;
    QStandardItemModel *m_ModelDate;
    QItemSelectionModel *m_ModelSlection;
	QMenu *m_Menu;
	QAction *actionDel;
    QString strcuried;
	void Init_local_AP(QString str);
    void Init_local_LD(QString str);
    void Init_local_LN(QString str);
	void Display_Input_Ln();
    void Init_Ex_IED(QString str);
	void Init_Ex_AP(QString str);
    void Init_Ex_LD(QString str);
    void Init_Ex_LN(QString str);
	void GetInputFromSCD(Input_Struct* data);
	void AddOneInputToTable(int row, Input_Struct &data);
    void ADDListToLocal(LN_InstStruct &Lninst, QVector<Data_instStruct> &Datalist);
	void ADDDatainstListTOTree(QVector<FCDA_Struct>&List);
    void ADDListToEx(LN_InstStruct &Lninst, QVector<Data_instStruct> &Datalist,Input_Struct m_data);
	void ADDListToEx(DataSetStruct &m_data);
	void AddOneNewInput(QTreeWidgetItem *item);
    void SwitchToInput();
	void FreshData(QModelIndex curIndex,int source);
	void FreshInputOfTable(QModelIndex curIndex, QVector<FCDA_Struct> &datalist, int source);
	void FreshInputOfTable(QModelIndex curIndex, QVector<Input_Struct> &datalist, int source);
	int Filter_datainst(FCDA_Struct &);
	QStringList headerlist;
    QVector<Data_instStruct> m_datalist_local;
    QVector<Data_instStruct> m_datalist_ex;
    QVector<Input_Struct> m_newdatalist;
	QVector<Input_Struct> m_olddatalist;
	QVector<DataMatrix_Struct> DataMatrix_Vector_LD_Local;
    QVector<DataMatrix_Struct> DataMatrix_Vector_LN_Local;
	QVector<FCDA_Struct> DataInstList_LD_local;
    QVector<FCDA_Struct> DataInstList_LN_local;
	QVector<FCDA_Struct> DataInstList_Select_local;

	QVector<DataMatrix_Struct> DataMatrix_Vector_LD_ex;
	QVector<FCDA_Struct> DataInstList_LD_ex;
	QVector<FCDA_Struct> DataInstList_Select_ex;
    QVector<DataSetStruct> DataSetVector;
	Input_Struct m_newdata;
	Input_Struct m_olddata;
	int Change_type;
private slots:
    void receivedragEnterEvent(QDropEvent *event);
    void onpushbutton_fresh_Receiver();
    void onpushbutton_fresh_Sender();
    void OnDataChanged(const QModelIndex & topLeft, const QModelIndex & bottomRight);
	void Combox_Local_AP_Active(QString str);
	void Combox_Local_LD_Active(QString str);
    void Combox_Local_LN_Active(QString str);
	void Combox_Ex_AP_Active(QString str);
    void Combox_Ex_LD_Active(QString str);
    void Combox_Ex_LN_Active(QString str);
    void Combox_Ex_IED_Active(QString str);
    void itemDoubleClicked(QTreeWidgetItem *item, int colum);
	void DropTable_MousEvent(const QPoint &pos);
	void OnAction_Del();
private:
    Ui::InputDialog *ui;
};

#endif // INPUTDIALOG_H
