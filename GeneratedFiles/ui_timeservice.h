/********************************************************************************
** Form generated from reading UI file 'timeservice.ui'
**
** Created by: Qt User Interface Compiler version 5.6.1
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_TIMESERVICE_H
#define UI_TIMESERVICE_H

#include <QtCore/QVariant>
#include <QtWidgets/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QButtonGroup>
#include <QtWidgets/QComboBox>
#include <QtWidgets/QDialog>
#include <QtWidgets/QGridLayout>
#include <QtWidgets/QHBoxLayout>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QLabel>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QVBoxLayout>

QT_BEGIN_NAMESPACE

class Ui_TimeService
{
public:
    QGridLayout *gridLayout;
    QVBoxLayout *verticalLayout_3;
    QHBoxLayout *horizontalLayout;
    QLabel *label_IP1;
    QLineEdit *lineEdit_IP1;
    QHBoxLayout *horizontalLayout_2;
    QLabel *label_IP2;
    QLineEdit *lineEdit_IP2;
    QHBoxLayout *horizontalLayout_3;
    QLabel *label_IP3;
    QLineEdit *lineEdit_IP3;
    QVBoxLayout *verticalLayout_2;
    QHBoxLayout *horizontalLayout_4;
    QLabel *label_Group;
    QLineEdit *lineEdit_Group;
    QHBoxLayout *horizontalLayout_5;
    QLabel *label_Port;
    QLineEdit *lineEdit_Port;
    QHBoxLayout *horizontalLayout_6;
    QLabel *label_Mod;
    QComboBox *comboBox_Mod;
    QVBoxLayout *verticalLayout;
    QPushButton *pushButton_Apply;
    QPushButton *pushButton_Cancel;
    QHBoxLayout *horizontalLayout_7;
    QLabel *label_TimeMode;
    QComboBox *comboBox_TimeMode;

    void setupUi(QDialog *TimeService)
    {
        if (TimeService->objectName().isEmpty())
            TimeService->setObjectName(QStringLiteral("TimeService"));
        TimeService->resize(543, 106);
        gridLayout = new QGridLayout(TimeService);
        gridLayout->setObjectName(QStringLiteral("gridLayout"));
        verticalLayout_3 = new QVBoxLayout();
        verticalLayout_3->setObjectName(QStringLiteral("verticalLayout_3"));
        horizontalLayout = new QHBoxLayout();
        horizontalLayout->setObjectName(QStringLiteral("horizontalLayout"));
        label_IP1 = new QLabel(TimeService);
        label_IP1->setObjectName(QStringLiteral("label_IP1"));

        horizontalLayout->addWidget(label_IP1);

        lineEdit_IP1 = new QLineEdit(TimeService);
        lineEdit_IP1->setObjectName(QStringLiteral("lineEdit_IP1"));

        horizontalLayout->addWidget(lineEdit_IP1);


        verticalLayout_3->addLayout(horizontalLayout);

        horizontalLayout_2 = new QHBoxLayout();
        horizontalLayout_2->setObjectName(QStringLiteral("horizontalLayout_2"));
        label_IP2 = new QLabel(TimeService);
        label_IP2->setObjectName(QStringLiteral("label_IP2"));

        horizontalLayout_2->addWidget(label_IP2);

        lineEdit_IP2 = new QLineEdit(TimeService);
        lineEdit_IP2->setObjectName(QStringLiteral("lineEdit_IP2"));

        horizontalLayout_2->addWidget(lineEdit_IP2);


        verticalLayout_3->addLayout(horizontalLayout_2);

        horizontalLayout_3 = new QHBoxLayout();
        horizontalLayout_3->setObjectName(QStringLiteral("horizontalLayout_3"));
        label_IP3 = new QLabel(TimeService);
        label_IP3->setObjectName(QStringLiteral("label_IP3"));

        horizontalLayout_3->addWidget(label_IP3);

        lineEdit_IP3 = new QLineEdit(TimeService);
        lineEdit_IP3->setObjectName(QStringLiteral("lineEdit_IP3"));

        horizontalLayout_3->addWidget(lineEdit_IP3);


        verticalLayout_3->addLayout(horizontalLayout_3);


        gridLayout->addLayout(verticalLayout_3, 0, 0, 1, 1);

        verticalLayout_2 = new QVBoxLayout();
        verticalLayout_2->setObjectName(QStringLiteral("verticalLayout_2"));
        horizontalLayout_4 = new QHBoxLayout();
        horizontalLayout_4->setObjectName(QStringLiteral("horizontalLayout_4"));
        label_Group = new QLabel(TimeService);
        label_Group->setObjectName(QStringLiteral("label_Group"));

        horizontalLayout_4->addWidget(label_Group);

        lineEdit_Group = new QLineEdit(TimeService);
        lineEdit_Group->setObjectName(QStringLiteral("lineEdit_Group"));

        horizontalLayout_4->addWidget(lineEdit_Group);


        verticalLayout_2->addLayout(horizontalLayout_4);

        horizontalLayout_5 = new QHBoxLayout();
        horizontalLayout_5->setObjectName(QStringLiteral("horizontalLayout_5"));
        label_Port = new QLabel(TimeService);
        label_Port->setObjectName(QStringLiteral("label_Port"));

        horizontalLayout_5->addWidget(label_Port);

        lineEdit_Port = new QLineEdit(TimeService);
        lineEdit_Port->setObjectName(QStringLiteral("lineEdit_Port"));

        horizontalLayout_5->addWidget(lineEdit_Port);


        verticalLayout_2->addLayout(horizontalLayout_5);

        horizontalLayout_6 = new QHBoxLayout();
        horizontalLayout_6->setObjectName(QStringLiteral("horizontalLayout_6"));
        label_Mod = new QLabel(TimeService);
        label_Mod->setObjectName(QStringLiteral("label_Mod"));

        horizontalLayout_6->addWidget(label_Mod);

        comboBox_Mod = new QComboBox(TimeService);
        comboBox_Mod->setObjectName(QStringLiteral("comboBox_Mod"));

        horizontalLayout_6->addWidget(comboBox_Mod);


        verticalLayout_2->addLayout(horizontalLayout_6);


        gridLayout->addLayout(verticalLayout_2, 0, 1, 1, 1);

        verticalLayout = new QVBoxLayout();
        verticalLayout->setObjectName(QStringLiteral("verticalLayout"));
        pushButton_Apply = new QPushButton(TimeService);
        pushButton_Apply->setObjectName(QStringLiteral("pushButton_Apply"));

        verticalLayout->addWidget(pushButton_Apply);

        pushButton_Cancel = new QPushButton(TimeService);
        pushButton_Cancel->setObjectName(QStringLiteral("pushButton_Cancel"));

        verticalLayout->addWidget(pushButton_Cancel);

        horizontalLayout_7 = new QHBoxLayout();
        horizontalLayout_7->setObjectName(QStringLiteral("horizontalLayout_7"));
        label_TimeMode = new QLabel(TimeService);
        label_TimeMode->setObjectName(QStringLiteral("label_TimeMode"));

        horizontalLayout_7->addWidget(label_TimeMode);

        comboBox_TimeMode = new QComboBox(TimeService);
        comboBox_TimeMode->setObjectName(QStringLiteral("comboBox_TimeMode"));

        horizontalLayout_7->addWidget(comboBox_TimeMode);


        verticalLayout->addLayout(horizontalLayout_7);


        gridLayout->addLayout(verticalLayout, 0, 2, 1, 1);


        retranslateUi(TimeService);

        QMetaObject::connectSlotsByName(TimeService);
    } // setupUi

    void retranslateUi(QDialog *TimeService)
    {
        TimeService->setWindowTitle(QApplication::translate("TimeService", "Dialog", 0));
        label_IP1->setText(QApplication::translate("TimeService", "TextLabel", 0));
        label_IP2->setText(QApplication::translate("TimeService", "TextLabel", 0));
        label_IP3->setText(QApplication::translate("TimeService", "TextLabel", 0));
        label_Group->setText(QApplication::translate("TimeService", "TextLabel", 0));
        label_Port->setText(QApplication::translate("TimeService", "TextLabel", 0));
        label_Mod->setText(QApplication::translate("TimeService", "TextLabel", 0));
        pushButton_Apply->setText(QApplication::translate("TimeService", "PushButton", 0));
        pushButton_Cancel->setText(QApplication::translate("TimeService", "PushButton", 0));
        label_TimeMode->setText(QApplication::translate("TimeService", "TextLabel", 0));
    } // retranslateUi

};

namespace Ui {
    class TimeService: public Ui_TimeService {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_TIMESERVICE_H
