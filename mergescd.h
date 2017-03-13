#ifndef MERGESCD_H
#define MERGESCD_H

#include <QDialog>
#include "ui_mergescd.h"
#include"scdtree.h"
#include<QFileDialog>
#include<QMessageBox>
#include"mergecompare.h"
#include<QMap>
#include"datastruct.h"
#include"tinyxml.h"
#include"tinyxml_global.h"

class MergeSCD : public QDialog
{
	Q_OBJECT

public:
	MergeSCD(QWidget *parent = 0);
	~MergeSCD();
    ScdTree *m_Point_base;
    ScdTree *m_Point_merge;
	bool state_base;
	bool state_merge;
	bool state_new;
    QVector<IEDstruct> List_Base;
    QMap<int,IEDstruct>IED_MAP;
    QVector<IEDstruct> List_Merge;
    void Init_dlg();
private slots:
    void Pushbutton_Apply();
    void Pushbutton_Cancel();
    void Pushbutton_OpenBase();
    void Pushbutton_OpenMerge();
    void Pushbutton_OpenNew();
	
private:
	Ui::MergeSCD ui;
};

#endif // MERGESCD_H
