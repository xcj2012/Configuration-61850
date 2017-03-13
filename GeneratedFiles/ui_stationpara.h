/********************************************************************************
** Form generated from reading UI file 'stationpara.ui'
**
** Created by: Qt User Interface Compiler version 5.6.1
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_STATIONPARA_H
#define UI_STATIONPARA_H

#include <QtCore/QVariant>
#include <QtWidgets/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QButtonGroup>
#include <QtWidgets/QDialog>
#include <QtWidgets/QGridLayout>
#include <QtWidgets/QHBoxLayout>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QLabel>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QSpacerItem>

QT_BEGIN_NAMESPACE

class Ui_StationPara
{
public:
    QGridLayout *gridLayout;
    QHBoxLayout *horizontalLayout;
    QLabel *label_vendor;
    QLineEdit *lineEdit_vendor;
    QSpacerItem *horizontalSpacer_2;
    QHBoxLayout *horizontalLayout_2;
    QLabel *label_Line;
    QLineEdit *lineEdit_Line;
    QSpacerItem *horizontalSpacer;
    QHBoxLayout *horizontalLayout_3;
    QLabel *label_Project;
    QLineEdit *lineEdit_project;
    QSpacerItem *horizontalSpacer_3;
    QHBoxLayout *horizontalLayout_4;
    QLabel *label_ver;
    QLineEdit *lineEdit_ver;
    QSpacerItem *horizontalSpacer_4;
    QHBoxLayout *horizontalLayout_5;
    QSpacerItem *horizontalSpacer_6;
    QPushButton *pushButton_ok;
    QPushButton *pushButton_cancel;
    QSpacerItem *horizontalSpacer_5;

    void setupUi(QDialog *StationPara)
    {
        if (StationPara->objectName().isEmpty())
            StationPara->setObjectName(QStringLiteral("StationPara"));
        StationPara->resize(326, 241);
        gridLayout = new QGridLayout(StationPara);
        gridLayout->setObjectName(QStringLiteral("gridLayout"));
        horizontalLayout = new QHBoxLayout();
        horizontalLayout->setObjectName(QStringLiteral("horizontalLayout"));
        label_vendor = new QLabel(StationPara);
        label_vendor->setObjectName(QStringLiteral("label_vendor"));

        horizontalLayout->addWidget(label_vendor);

        lineEdit_vendor = new QLineEdit(StationPara);
        lineEdit_vendor->setObjectName(QStringLiteral("lineEdit_vendor"));

        horizontalLayout->addWidget(lineEdit_vendor);

        horizontalSpacer_2 = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout->addItem(horizontalSpacer_2);


        gridLayout->addLayout(horizontalLayout, 0, 0, 1, 1);

        horizontalLayout_2 = new QHBoxLayout();
        horizontalLayout_2->setObjectName(QStringLiteral("horizontalLayout_2"));
        label_Line = new QLabel(StationPara);
        label_Line->setObjectName(QStringLiteral("label_Line"));

        horizontalLayout_2->addWidget(label_Line);

        lineEdit_Line = new QLineEdit(StationPara);
        lineEdit_Line->setObjectName(QStringLiteral("lineEdit_Line"));

        horizontalLayout_2->addWidget(lineEdit_Line);

        horizontalSpacer = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout_2->addItem(horizontalSpacer);


        gridLayout->addLayout(horizontalLayout_2, 1, 0, 1, 1);

        horizontalLayout_3 = new QHBoxLayout();
        horizontalLayout_3->setObjectName(QStringLiteral("horizontalLayout_3"));
        label_Project = new QLabel(StationPara);
        label_Project->setObjectName(QStringLiteral("label_Project"));

        horizontalLayout_3->addWidget(label_Project);

        lineEdit_project = new QLineEdit(StationPara);
        lineEdit_project->setObjectName(QStringLiteral("lineEdit_project"));

        horizontalLayout_3->addWidget(lineEdit_project);

        horizontalSpacer_3 = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout_3->addItem(horizontalSpacer_3);


        gridLayout->addLayout(horizontalLayout_3, 2, 0, 1, 1);

        horizontalLayout_4 = new QHBoxLayout();
        horizontalLayout_4->setObjectName(QStringLiteral("horizontalLayout_4"));
        label_ver = new QLabel(StationPara);
        label_ver->setObjectName(QStringLiteral("label_ver"));

        horizontalLayout_4->addWidget(label_ver);

        lineEdit_ver = new QLineEdit(StationPara);
        lineEdit_ver->setObjectName(QStringLiteral("lineEdit_ver"));

        horizontalLayout_4->addWidget(lineEdit_ver);

        horizontalSpacer_4 = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout_4->addItem(horizontalSpacer_4);


        gridLayout->addLayout(horizontalLayout_4, 3, 0, 1, 1);

        horizontalLayout_5 = new QHBoxLayout();
        horizontalLayout_5->setObjectName(QStringLiteral("horizontalLayout_5"));
        horizontalSpacer_6 = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout_5->addItem(horizontalSpacer_6);

        pushButton_ok = new QPushButton(StationPara);
        pushButton_ok->setObjectName(QStringLiteral("pushButton_ok"));

        horizontalLayout_5->addWidget(pushButton_ok);

        pushButton_cancel = new QPushButton(StationPara);
        pushButton_cancel->setObjectName(QStringLiteral("pushButton_cancel"));

        horizontalLayout_5->addWidget(pushButton_cancel);

        horizontalSpacer_5 = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout_5->addItem(horizontalSpacer_5);


        gridLayout->addLayout(horizontalLayout_5, 4, 0, 1, 1);


        retranslateUi(StationPara);

        QMetaObject::connectSlotsByName(StationPara);
    } // setupUi

    void retranslateUi(QDialog *StationPara)
    {
        StationPara->setWindowTitle(QApplication::translate("StationPara", "Dialog", 0));
        label_vendor->setText(QApplication::translate("StationPara", "TextLabel", 0));
        label_Line->setText(QApplication::translate("StationPara", "TextLabel", 0));
        label_Project->setText(QApplication::translate("StationPara", "TextLabel", 0));
        label_ver->setText(QApplication::translate("StationPara", "TextLabel", 0));
        pushButton_ok->setText(QApplication::translate("StationPara", "PushButton", 0));
        pushButton_cancel->setText(QApplication::translate("StationPara", "PushButton", 0));
    } // retranslateUi

};

namespace Ui {
    class StationPara: public Ui_StationPara {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_STATIONPARA_H
