/********************************************************************************
** Form generated from reading UI file 'inputdialog.ui'
**
** Created by: Qt User Interface Compiler version 5.6.1
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_INPUTDIALOG_H
#define UI_INPUTDIALOG_H

#include <QtCore/QVariant>
#include <QtWidgets/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QButtonGroup>
#include <QtWidgets/QCheckBox>
#include <QtWidgets/QComboBox>
#include <QtWidgets/QDialog>
#include <QtWidgets/QFrame>
#include <QtWidgets/QGridLayout>
#include <QtWidgets/QHBoxLayout>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QLabel>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QSpacerItem>
#include <QtWidgets/QSplitter>
#include <QtWidgets/QTreeWidget>
#include <QtWidgets/QVBoxLayout>
#include "droptable.h"

QT_BEGIN_NAMESPACE

class Ui_InputDialog
{
public:
    QGridLayout *gridLayout_3;
    QSplitter *splitter_2;
    QSplitter *splitter;
    QFrame *frame;
    QGridLayout *gridLayout_2;
    QSpacerItem *horizontalSpacer_2;
    QVBoxLayout *verticalLayout;
    QHBoxLayout *horizontalLayout;
    QLabel *label_localAP;
    QComboBox *comboBox_localAP;
    QLabel *label_localLD;
    QComboBox *comboBox_localLD;
    QHBoxLayout *horizontalLayout_2;
    QLabel *label_localLN;
    QComboBox *comboBox_localLN;
    QLabel *label_localFC;
    QComboBox *comboBox_localFC;
    QHBoxLayout *horizontalLayout_3;
    QCheckBox *checkBox1_DA;
    QCheckBox *checkBox1_disp;
    QCheckBox *checkBox1_DAEND;
    QHBoxLayout *horizontalLayout_4;
    QLabel *label_localDA;
    QLineEdit *lineEdit_localDA;
    QPushButton *pushButton_fresh;
    QTreeWidget *treeWidget_local;
    QFrame *frame_2;
    QGridLayout *gridLayout;
    QHBoxLayout *horizontalLayout_9;
    QLabel *label_exIED;
    QComboBox *comboBox_exIED;
    QSpacerItem *horizontalSpacer;
    QVBoxLayout *verticalLayout_2;
    QHBoxLayout *horizontalLayout_5;
    QLabel *label_exAP;
    QComboBox *comboBox_exAP;
    QLabel *label_exLD;
    QComboBox *comboBox_exLD;
    QHBoxLayout *horizontalLayout_6;
    QLabel *label_exLN;
    QComboBox *comboBox_exLN;
    QHBoxLayout *horizontalLayout_7;
    QCheckBox *checkBox2_DA;
    QCheckBox *checkBox2_disp;
    QCheckBox *checkBox2_DAEND;
    QHBoxLayout *horizontalLayout_8;
    QLabel *label_exDA;
    QLineEdit *lineEdit_exDA;
    QLabel *label_exFC;
    QComboBox *comboBox_exFC;
    QPushButton *pushButton_fresh_ex;
    QTreeWidget *treeWidget_ex;
    DropTable *dropTable;

    void setupUi(QDialog *InputDialog)
    {
        if (InputDialog->objectName().isEmpty())
            InputDialog->setObjectName(QStringLiteral("InputDialog"));
        InputDialog->setWindowModality(Qt::WindowModal);
        InputDialog->resize(1024, 600);
        gridLayout_3 = new QGridLayout(InputDialog);
        gridLayout_3->setObjectName(QStringLiteral("gridLayout_3"));
        splitter_2 = new QSplitter(InputDialog);
        splitter_2->setObjectName(QStringLiteral("splitter_2"));
        splitter_2->setOrientation(Qt::Vertical);
        splitter = new QSplitter(splitter_2);
        splitter->setObjectName(QStringLiteral("splitter"));
        splitter->setOrientation(Qt::Horizontal);
        frame = new QFrame(splitter);
        frame->setObjectName(QStringLiteral("frame"));
        frame->setFrameShape(QFrame::StyledPanel);
        frame->setFrameShadow(QFrame::Raised);
        gridLayout_2 = new QGridLayout(frame);
        gridLayout_2->setObjectName(QStringLiteral("gridLayout_2"));
        horizontalSpacer_2 = new QSpacerItem(478, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        gridLayout_2->addItem(horizontalSpacer_2, 0, 0, 1, 1);

        verticalLayout = new QVBoxLayout();
        verticalLayout->setObjectName(QStringLiteral("verticalLayout"));
        horizontalLayout = new QHBoxLayout();
        horizontalLayout->setObjectName(QStringLiteral("horizontalLayout"));
        label_localAP = new QLabel(frame);
        label_localAP->setObjectName(QStringLiteral("label_localAP"));

        horizontalLayout->addWidget(label_localAP);

        comboBox_localAP = new QComboBox(frame);
        comboBox_localAP->setObjectName(QStringLiteral("comboBox_localAP"));

        horizontalLayout->addWidget(comboBox_localAP);

        label_localLD = new QLabel(frame);
        label_localLD->setObjectName(QStringLiteral("label_localLD"));

        horizontalLayout->addWidget(label_localLD);

        comboBox_localLD = new QComboBox(frame);
        comboBox_localLD->setObjectName(QStringLiteral("comboBox_localLD"));

        horizontalLayout->addWidget(comboBox_localLD);


        verticalLayout->addLayout(horizontalLayout);

        horizontalLayout_2 = new QHBoxLayout();
        horizontalLayout_2->setObjectName(QStringLiteral("horizontalLayout_2"));
        label_localLN = new QLabel(frame);
        label_localLN->setObjectName(QStringLiteral("label_localLN"));

        horizontalLayout_2->addWidget(label_localLN);

        comboBox_localLN = new QComboBox(frame);
        comboBox_localLN->setObjectName(QStringLiteral("comboBox_localLN"));

        horizontalLayout_2->addWidget(comboBox_localLN);

        label_localFC = new QLabel(frame);
        label_localFC->setObjectName(QStringLiteral("label_localFC"));

        horizontalLayout_2->addWidget(label_localFC);

        comboBox_localFC = new QComboBox(frame);
        comboBox_localFC->setObjectName(QStringLiteral("comboBox_localFC"));

        horizontalLayout_2->addWidget(comboBox_localFC);


        verticalLayout->addLayout(horizontalLayout_2);

        horizontalLayout_3 = new QHBoxLayout();
        horizontalLayout_3->setObjectName(QStringLiteral("horizontalLayout_3"));
        checkBox1_DA = new QCheckBox(frame);
        checkBox1_DA->setObjectName(QStringLiteral("checkBox1_DA"));

        horizontalLayout_3->addWidget(checkBox1_DA);

        checkBox1_disp = new QCheckBox(frame);
        checkBox1_disp->setObjectName(QStringLiteral("checkBox1_disp"));

        horizontalLayout_3->addWidget(checkBox1_disp);

        checkBox1_DAEND = new QCheckBox(frame);
        checkBox1_DAEND->setObjectName(QStringLiteral("checkBox1_DAEND"));

        horizontalLayout_3->addWidget(checkBox1_DAEND);


        verticalLayout->addLayout(horizontalLayout_3);


        gridLayout_2->addLayout(verticalLayout, 1, 0, 1, 1);

        horizontalLayout_4 = new QHBoxLayout();
        horizontalLayout_4->setObjectName(QStringLiteral("horizontalLayout_4"));
        label_localDA = new QLabel(frame);
        label_localDA->setObjectName(QStringLiteral("label_localDA"));

        horizontalLayout_4->addWidget(label_localDA);

        lineEdit_localDA = new QLineEdit(frame);
        lineEdit_localDA->setObjectName(QStringLiteral("lineEdit_localDA"));

        horizontalLayout_4->addWidget(lineEdit_localDA);

        pushButton_fresh = new QPushButton(frame);
        pushButton_fresh->setObjectName(QStringLiteral("pushButton_fresh"));

        horizontalLayout_4->addWidget(pushButton_fresh);


        gridLayout_2->addLayout(horizontalLayout_4, 2, 0, 1, 1);

        treeWidget_local = new QTreeWidget(frame);
        QTreeWidgetItem *__qtreewidgetitem = new QTreeWidgetItem();
        __qtreewidgetitem->setText(0, QStringLiteral("1"));
        treeWidget_local->setHeaderItem(__qtreewidgetitem);
        treeWidget_local->setObjectName(QStringLiteral("treeWidget_local"));

        gridLayout_2->addWidget(treeWidget_local, 3, 0, 1, 1);

        splitter->addWidget(frame);
        frame_2 = new QFrame(splitter);
        frame_2->setObjectName(QStringLiteral("frame_2"));
        frame_2->setFrameShape(QFrame::StyledPanel);
        frame_2->setFrameShadow(QFrame::Raised);
        gridLayout = new QGridLayout(frame_2);
        gridLayout->setObjectName(QStringLiteral("gridLayout"));
        horizontalLayout_9 = new QHBoxLayout();
        horizontalLayout_9->setObjectName(QStringLiteral("horizontalLayout_9"));
        label_exIED = new QLabel(frame_2);
        label_exIED->setObjectName(QStringLiteral("label_exIED"));

        horizontalLayout_9->addWidget(label_exIED);

        comboBox_exIED = new QComboBox(frame_2);
        comboBox_exIED->setObjectName(QStringLiteral("comboBox_exIED"));

        horizontalLayout_9->addWidget(comboBox_exIED);

        horizontalSpacer = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout_9->addItem(horizontalSpacer);


        gridLayout->addLayout(horizontalLayout_9, 0, 0, 1, 1);

        verticalLayout_2 = new QVBoxLayout();
        verticalLayout_2->setObjectName(QStringLiteral("verticalLayout_2"));
        horizontalLayout_5 = new QHBoxLayout();
        horizontalLayout_5->setObjectName(QStringLiteral("horizontalLayout_5"));
        label_exAP = new QLabel(frame_2);
        label_exAP->setObjectName(QStringLiteral("label_exAP"));

        horizontalLayout_5->addWidget(label_exAP);

        comboBox_exAP = new QComboBox(frame_2);
        comboBox_exAP->setObjectName(QStringLiteral("comboBox_exAP"));

        horizontalLayout_5->addWidget(comboBox_exAP);

        label_exLD = new QLabel(frame_2);
        label_exLD->setObjectName(QStringLiteral("label_exLD"));

        horizontalLayout_5->addWidget(label_exLD);

        comboBox_exLD = new QComboBox(frame_2);
        comboBox_exLD->setObjectName(QStringLiteral("comboBox_exLD"));

        horizontalLayout_5->addWidget(comboBox_exLD);


        verticalLayout_2->addLayout(horizontalLayout_5);

        horizontalLayout_6 = new QHBoxLayout();
        horizontalLayout_6->setObjectName(QStringLiteral("horizontalLayout_6"));
        label_exLN = new QLabel(frame_2);
        label_exLN->setObjectName(QStringLiteral("label_exLN"));

        horizontalLayout_6->addWidget(label_exLN);

        comboBox_exLN = new QComboBox(frame_2);
        comboBox_exLN->setObjectName(QStringLiteral("comboBox_exLN"));

        horizontalLayout_6->addWidget(comboBox_exLN);


        verticalLayout_2->addLayout(horizontalLayout_6);

        horizontalLayout_7 = new QHBoxLayout();
        horizontalLayout_7->setObjectName(QStringLiteral("horizontalLayout_7"));
        checkBox2_DA = new QCheckBox(frame_2);
        checkBox2_DA->setObjectName(QStringLiteral("checkBox2_DA"));

        horizontalLayout_7->addWidget(checkBox2_DA);

        checkBox2_disp = new QCheckBox(frame_2);
        checkBox2_disp->setObjectName(QStringLiteral("checkBox2_disp"));

        horizontalLayout_7->addWidget(checkBox2_disp);

        checkBox2_DAEND = new QCheckBox(frame_2);
        checkBox2_DAEND->setObjectName(QStringLiteral("checkBox2_DAEND"));

        horizontalLayout_7->addWidget(checkBox2_DAEND);


        verticalLayout_2->addLayout(horizontalLayout_7);


        gridLayout->addLayout(verticalLayout_2, 1, 0, 1, 1);

        horizontalLayout_8 = new QHBoxLayout();
        horizontalLayout_8->setObjectName(QStringLiteral("horizontalLayout_8"));
        label_exDA = new QLabel(frame_2);
        label_exDA->setObjectName(QStringLiteral("label_exDA"));

        horizontalLayout_8->addWidget(label_exDA);

        lineEdit_exDA = new QLineEdit(frame_2);
        lineEdit_exDA->setObjectName(QStringLiteral("lineEdit_exDA"));

        horizontalLayout_8->addWidget(lineEdit_exDA);

        label_exFC = new QLabel(frame_2);
        label_exFC->setObjectName(QStringLiteral("label_exFC"));

        horizontalLayout_8->addWidget(label_exFC);

        comboBox_exFC = new QComboBox(frame_2);
        comboBox_exFC->setObjectName(QStringLiteral("comboBox_exFC"));

        horizontalLayout_8->addWidget(comboBox_exFC);

        pushButton_fresh_ex = new QPushButton(frame_2);
        pushButton_fresh_ex->setObjectName(QStringLiteral("pushButton_fresh_ex"));

        horizontalLayout_8->addWidget(pushButton_fresh_ex);


        gridLayout->addLayout(horizontalLayout_8, 2, 0, 1, 1);

        treeWidget_ex = new QTreeWidget(frame_2);
        QTreeWidgetItem *__qtreewidgetitem1 = new QTreeWidgetItem();
        __qtreewidgetitem1->setText(0, QStringLiteral("1"));
        treeWidget_ex->setHeaderItem(__qtreewidgetitem1);
        treeWidget_ex->setObjectName(QStringLiteral("treeWidget_ex"));

        gridLayout->addWidget(treeWidget_ex, 3, 0, 1, 1);

        splitter->addWidget(frame_2);
        splitter_2->addWidget(splitter);
        dropTable = new DropTable(splitter_2);
        dropTable->setObjectName(QStringLiteral("dropTable"));
        dropTable->setContextMenuPolicy(Qt::CustomContextMenu);
        splitter_2->addWidget(dropTable);

        gridLayout_3->addWidget(splitter_2, 0, 0, 1, 1);


        retranslateUi(InputDialog);

        QMetaObject::connectSlotsByName(InputDialog);
    } // setupUi

    void retranslateUi(QDialog *InputDialog)
    {
        InputDialog->setWindowTitle(QApplication::translate("InputDialog", "Dialog", 0));
        label_localAP->setText(QApplication::translate("InputDialog", "TextLabel", 0));
        label_localLD->setText(QApplication::translate("InputDialog", "TextLabel", 0));
        label_localLN->setText(QApplication::translate("InputDialog", "TextLabel", 0));
        label_localFC->setText(QApplication::translate("InputDialog", "TextLabel", 0));
        checkBox1_DA->setText(QApplication::translate("InputDialog", "CheckBox", 0));
        checkBox1_disp->setText(QApplication::translate("InputDialog", "CheckBox", 0));
        checkBox1_DAEND->setText(QApplication::translate("InputDialog", "CheckBox", 0));
        label_localDA->setText(QApplication::translate("InputDialog", "TextLabel", 0));
        pushButton_fresh->setText(QApplication::translate("InputDialog", "PushButton", 0));
        label_exIED->setText(QApplication::translate("InputDialog", "TextLabel", 0));
        label_exAP->setText(QApplication::translate("InputDialog", "TextLabel", 0));
        label_exLD->setText(QApplication::translate("InputDialog", "TextLabel", 0));
        label_exLN->setText(QApplication::translate("InputDialog", "TextLabel", 0));
        checkBox2_DA->setText(QApplication::translate("InputDialog", "CheckBox", 0));
        checkBox2_disp->setText(QApplication::translate("InputDialog", "CheckBox", 0));
        checkBox2_DAEND->setText(QApplication::translate("InputDialog", "CheckBox", 0));
        label_exDA->setText(QApplication::translate("InputDialog", "TextLabel", 0));
        label_exFC->setText(QApplication::translate("InputDialog", "TextLabel", 0));
        pushButton_fresh_ex->setText(QApplication::translate("InputDialog", "PushButton", 0));
    } // retranslateUi

};

namespace Ui {
    class InputDialog: public Ui_InputDialog {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_INPUTDIALOG_H
