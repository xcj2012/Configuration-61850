/********************************************************************************
** Form generated from reading UI file 'applyoneied.ui'
**
** Created by: Qt User Interface Compiler version 5.6.1
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_APPLYONEIED_H
#define UI_APPLYONEIED_H

#include <QtCore/QVariant>
#include <QtWidgets/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QButtonGroup>
#include <QtWidgets/QComboBox>
#include <QtWidgets/QDialog>
#include <QtWidgets/QGridLayout>
#include <QtWidgets/QGroupBox>
#include <QtWidgets/QHBoxLayout>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QLabel>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QSpacerItem>
#include <QtWidgets/QVBoxLayout>

QT_BEGIN_NAMESPACE

class Ui_ApplyOneIED
{
public:
    QGridLayout *gridLayout_3;
    QVBoxLayout *verticalLayout_4;
    QVBoxLayout *verticalLayout_3;
    QHBoxLayout *horizontalLayout;
    QLabel *label_name;
    QComboBox *lineEdit_name;
    QHBoxLayout *horizontalLayout_12;
    QLabel *label_type;
    QComboBox *comboBox_type;
    QVBoxLayout *verticalLayout_2;
    QHBoxLayout *horizontalLayout_2;
    QLabel *label_AD1;
    QLineEdit *lineEdit_AD1;
    QHBoxLayout *horizontalLayout_3;
    QLabel *label_AD2;
    QLineEdit *lineEdit_AD2;
    QVBoxLayout *verticalLayout;
    QPushButton *pushButton_Apply;
    QPushButton *pushButton_Cancel;
    QHBoxLayout *horizontalLayout_15;
    QGroupBox *groupBox;
    QGridLayout *gridLayout;
    QHBoxLayout *horizontalLayout_4;
    QLabel *label_Timeserver;
    QComboBox *comboBox_time;
    QHBoxLayout *horizontalLayout_14;
    QLabel *label_ChanMod;
    QComboBox *comboBox_ChanMod;
    QHBoxLayout *horizontalLayout_5;
    QLabel *label_Ctltime;
    QLineEdit *lineEdit_CtlTime;
    QHBoxLayout *horizontalLayout_6;
    QLabel *label_GITime;
    QLineEdit *lineEdit_GITime;
    QHBoxLayout *horizontalLayout_7;
    QLabel *label_RptBuf;
    QLineEdit *lineEdit_RptBuf;
    QHBoxLayout *horizontalLayout_8;
    QLabel *label_RptInt;
    QLineEdit *lineEdit_RptInt;
    QHBoxLayout *horizontalLayout_9;
    QLabel *label_LostTime;
    QLineEdit *lineEdit_LostTime;
    QHBoxLayout *horizontalLayout_10;
    QLabel *label_KeepLive;
    QLineEdit *lineEdit_KeepLive;
    QHBoxLayout *horizontalLayout_13;
    QLabel *label_AuthMod;
    QComboBox *comboBox_pass;
    QHBoxLayout *horizontalLayout_11;
    QLabel *label_AuthCode;
    QLineEdit *lineEdit_AuthCode;
    QGroupBox *groupBox_2;
    QGridLayout *gridLayout_2;
    QHBoxLayout *horizontalLayout_24;
    QLabel *label_AP_Title;
    QLineEdit *lineEdit_AP_Title;
    QHBoxLayout *horizontalLayout_25;
    QLabel *label_AE_Qua;
    QLineEdit *lineEdit_AE_Qua;
    QHBoxLayout *horizontalLayout_26;
    QLabel *label_Psel;
    QLineEdit *lineEdit_Psel;
    QHBoxLayout *horizontalLayout_27;
    QLabel *label_Ssel;
    QLineEdit *lineEdit_Ssel;
    QHBoxLayout *horizontalLayout_28;
    QLabel *label_Tsel;
    QLineEdit *lineEdit_Tsel;
    QSpacerItem *horizontalSpacer_2;
    QSpacerItem *horizontalSpacer_3;
    QSpacerItem *horizontalSpacer_4;
    QSpacerItem *horizontalSpacer_5;
    QSpacerItem *horizontalSpacer_6;

    void setupUi(QDialog *ApplyOneIED)
    {
        if (ApplyOneIED->objectName().isEmpty())
            ApplyOneIED->setObjectName(QStringLiteral("ApplyOneIED"));
        ApplyOneIED->resize(534, 410);
        gridLayout_3 = new QGridLayout(ApplyOneIED);
        gridLayout_3->setObjectName(QStringLiteral("gridLayout_3"));
        verticalLayout_4 = new QVBoxLayout();
        verticalLayout_4->setObjectName(QStringLiteral("verticalLayout_4"));
        verticalLayout_3 = new QVBoxLayout();
        verticalLayout_3->setObjectName(QStringLiteral("verticalLayout_3"));
        horizontalLayout = new QHBoxLayout();
        horizontalLayout->setObjectName(QStringLiteral("horizontalLayout"));
        label_name = new QLabel(ApplyOneIED);
        label_name->setObjectName(QStringLiteral("label_name"));

        horizontalLayout->addWidget(label_name);

        lineEdit_name = new QComboBox(ApplyOneIED);
        lineEdit_name->setObjectName(QStringLiteral("lineEdit_name"));
        lineEdit_name->setEditable(true);

        horizontalLayout->addWidget(lineEdit_name);


        verticalLayout_3->addLayout(horizontalLayout);


        verticalLayout_4->addLayout(verticalLayout_3);

        horizontalLayout_12 = new QHBoxLayout();
        horizontalLayout_12->setObjectName(QStringLiteral("horizontalLayout_12"));
        label_type = new QLabel(ApplyOneIED);
        label_type->setObjectName(QStringLiteral("label_type"));

        horizontalLayout_12->addWidget(label_type);

        comboBox_type = new QComboBox(ApplyOneIED);
        comboBox_type->setObjectName(QStringLiteral("comboBox_type"));

        horizontalLayout_12->addWidget(comboBox_type);


        verticalLayout_4->addLayout(horizontalLayout_12);


        gridLayout_3->addLayout(verticalLayout_4, 0, 0, 1, 1);

        verticalLayout_2 = new QVBoxLayout();
        verticalLayout_2->setObjectName(QStringLiteral("verticalLayout_2"));
        horizontalLayout_2 = new QHBoxLayout();
        horizontalLayout_2->setObjectName(QStringLiteral("horizontalLayout_2"));
        label_AD1 = new QLabel(ApplyOneIED);
        label_AD1->setObjectName(QStringLiteral("label_AD1"));

        horizontalLayout_2->addWidget(label_AD1);

        lineEdit_AD1 = new QLineEdit(ApplyOneIED);
        lineEdit_AD1->setObjectName(QStringLiteral("lineEdit_AD1"));

        horizontalLayout_2->addWidget(lineEdit_AD1);


        verticalLayout_2->addLayout(horizontalLayout_2);

        horizontalLayout_3 = new QHBoxLayout();
        horizontalLayout_3->setObjectName(QStringLiteral("horizontalLayout_3"));
        label_AD2 = new QLabel(ApplyOneIED);
        label_AD2->setObjectName(QStringLiteral("label_AD2"));

        horizontalLayout_3->addWidget(label_AD2);

        lineEdit_AD2 = new QLineEdit(ApplyOneIED);
        lineEdit_AD2->setObjectName(QStringLiteral("lineEdit_AD2"));

        horizontalLayout_3->addWidget(lineEdit_AD2);


        verticalLayout_2->addLayout(horizontalLayout_3);


        gridLayout_3->addLayout(verticalLayout_2, 0, 1, 1, 1);

        verticalLayout = new QVBoxLayout();
        verticalLayout->setObjectName(QStringLiteral("verticalLayout"));
        pushButton_Apply = new QPushButton(ApplyOneIED);
        pushButton_Apply->setObjectName(QStringLiteral("pushButton_Apply"));

        verticalLayout->addWidget(pushButton_Apply);

        pushButton_Cancel = new QPushButton(ApplyOneIED);
        pushButton_Cancel->setObjectName(QStringLiteral("pushButton_Cancel"));

        verticalLayout->addWidget(pushButton_Cancel);


        gridLayout_3->addLayout(verticalLayout, 0, 2, 1, 1);

        horizontalLayout_15 = new QHBoxLayout();
        horizontalLayout_15->setObjectName(QStringLiteral("horizontalLayout_15"));
        groupBox = new QGroupBox(ApplyOneIED);
        groupBox->setObjectName(QStringLiteral("groupBox"));
        gridLayout = new QGridLayout(groupBox);
        gridLayout->setObjectName(QStringLiteral("gridLayout"));
        horizontalLayout_4 = new QHBoxLayout();
        horizontalLayout_4->setObjectName(QStringLiteral("horizontalLayout_4"));
        label_Timeserver = new QLabel(groupBox);
        label_Timeserver->setObjectName(QStringLiteral("label_Timeserver"));

        horizontalLayout_4->addWidget(label_Timeserver);

        comboBox_time = new QComboBox(groupBox);
        comboBox_time->setObjectName(QStringLiteral("comboBox_time"));

        horizontalLayout_4->addWidget(comboBox_time);


        gridLayout->addLayout(horizontalLayout_4, 0, 0, 1, 1);

        horizontalLayout_14 = new QHBoxLayout();
        horizontalLayout_14->setObjectName(QStringLiteral("horizontalLayout_14"));
        label_ChanMod = new QLabel(groupBox);
        label_ChanMod->setObjectName(QStringLiteral("label_ChanMod"));

        horizontalLayout_14->addWidget(label_ChanMod);

        comboBox_ChanMod = new QComboBox(groupBox);
        comboBox_ChanMod->setObjectName(QStringLiteral("comboBox_ChanMod"));

        horizontalLayout_14->addWidget(comboBox_ChanMod);


        gridLayout->addLayout(horizontalLayout_14, 1, 0, 1, 1);

        horizontalLayout_5 = new QHBoxLayout();
        horizontalLayout_5->setObjectName(QStringLiteral("horizontalLayout_5"));
        label_Ctltime = new QLabel(groupBox);
        label_Ctltime->setObjectName(QStringLiteral("label_Ctltime"));

        horizontalLayout_5->addWidget(label_Ctltime);

        lineEdit_CtlTime = new QLineEdit(groupBox);
        lineEdit_CtlTime->setObjectName(QStringLiteral("lineEdit_CtlTime"));

        horizontalLayout_5->addWidget(lineEdit_CtlTime);


        gridLayout->addLayout(horizontalLayout_5, 2, 0, 1, 1);

        horizontalLayout_6 = new QHBoxLayout();
        horizontalLayout_6->setObjectName(QStringLiteral("horizontalLayout_6"));
        label_GITime = new QLabel(groupBox);
        label_GITime->setObjectName(QStringLiteral("label_GITime"));

        horizontalLayout_6->addWidget(label_GITime);

        lineEdit_GITime = new QLineEdit(groupBox);
        lineEdit_GITime->setObjectName(QStringLiteral("lineEdit_GITime"));

        horizontalLayout_6->addWidget(lineEdit_GITime);


        gridLayout->addLayout(horizontalLayout_6, 3, 0, 1, 1);

        horizontalLayout_7 = new QHBoxLayout();
        horizontalLayout_7->setObjectName(QStringLiteral("horizontalLayout_7"));
        label_RptBuf = new QLabel(groupBox);
        label_RptBuf->setObjectName(QStringLiteral("label_RptBuf"));

        horizontalLayout_7->addWidget(label_RptBuf);

        lineEdit_RptBuf = new QLineEdit(groupBox);
        lineEdit_RptBuf->setObjectName(QStringLiteral("lineEdit_RptBuf"));

        horizontalLayout_7->addWidget(lineEdit_RptBuf);


        gridLayout->addLayout(horizontalLayout_7, 4, 0, 1, 1);

        horizontalLayout_8 = new QHBoxLayout();
        horizontalLayout_8->setObjectName(QStringLiteral("horizontalLayout_8"));
        label_RptInt = new QLabel(groupBox);
        label_RptInt->setObjectName(QStringLiteral("label_RptInt"));

        horizontalLayout_8->addWidget(label_RptInt);

        lineEdit_RptInt = new QLineEdit(groupBox);
        lineEdit_RptInt->setObjectName(QStringLiteral("lineEdit_RptInt"));

        horizontalLayout_8->addWidget(lineEdit_RptInt);


        gridLayout->addLayout(horizontalLayout_8, 5, 0, 1, 1);

        horizontalLayout_9 = new QHBoxLayout();
        horizontalLayout_9->setObjectName(QStringLiteral("horizontalLayout_9"));
        label_LostTime = new QLabel(groupBox);
        label_LostTime->setObjectName(QStringLiteral("label_LostTime"));

        horizontalLayout_9->addWidget(label_LostTime);

        lineEdit_LostTime = new QLineEdit(groupBox);
        lineEdit_LostTime->setObjectName(QStringLiteral("lineEdit_LostTime"));

        horizontalLayout_9->addWidget(lineEdit_LostTime);


        gridLayout->addLayout(horizontalLayout_9, 6, 0, 1, 1);

        horizontalLayout_10 = new QHBoxLayout();
        horizontalLayout_10->setObjectName(QStringLiteral("horizontalLayout_10"));
        label_KeepLive = new QLabel(groupBox);
        label_KeepLive->setObjectName(QStringLiteral("label_KeepLive"));

        horizontalLayout_10->addWidget(label_KeepLive);

        lineEdit_KeepLive = new QLineEdit(groupBox);
        lineEdit_KeepLive->setObjectName(QStringLiteral("lineEdit_KeepLive"));

        horizontalLayout_10->addWidget(lineEdit_KeepLive);


        gridLayout->addLayout(horizontalLayout_10, 7, 0, 1, 1);

        horizontalLayout_13 = new QHBoxLayout();
        horizontalLayout_13->setObjectName(QStringLiteral("horizontalLayout_13"));
        label_AuthMod = new QLabel(groupBox);
        label_AuthMod->setObjectName(QStringLiteral("label_AuthMod"));

        horizontalLayout_13->addWidget(label_AuthMod);

        comboBox_pass = new QComboBox(groupBox);
        comboBox_pass->setObjectName(QStringLiteral("comboBox_pass"));

        horizontalLayout_13->addWidget(comboBox_pass);


        gridLayout->addLayout(horizontalLayout_13, 8, 0, 1, 1);

        horizontalLayout_11 = new QHBoxLayout();
        horizontalLayout_11->setObjectName(QStringLiteral("horizontalLayout_11"));
        label_AuthCode = new QLabel(groupBox);
        label_AuthCode->setObjectName(QStringLiteral("label_AuthCode"));

        horizontalLayout_11->addWidget(label_AuthCode);

        lineEdit_AuthCode = new QLineEdit(groupBox);
        lineEdit_AuthCode->setObjectName(QStringLiteral("lineEdit_AuthCode"));

        horizontalLayout_11->addWidget(lineEdit_AuthCode);


        gridLayout->addLayout(horizontalLayout_11, 9, 0, 1, 1);


        horizontalLayout_15->addWidget(groupBox);

        groupBox_2 = new QGroupBox(ApplyOneIED);
        groupBox_2->setObjectName(QStringLiteral("groupBox_2"));
        gridLayout_2 = new QGridLayout(groupBox_2);
        gridLayout_2->setObjectName(QStringLiteral("gridLayout_2"));
        horizontalLayout_24 = new QHBoxLayout();
        horizontalLayout_24->setObjectName(QStringLiteral("horizontalLayout_24"));
        label_AP_Title = new QLabel(groupBox_2);
        label_AP_Title->setObjectName(QStringLiteral("label_AP_Title"));

        horizontalLayout_24->addWidget(label_AP_Title);

        lineEdit_AP_Title = new QLineEdit(groupBox_2);
        lineEdit_AP_Title->setObjectName(QStringLiteral("lineEdit_AP_Title"));

        horizontalLayout_24->addWidget(lineEdit_AP_Title);


        gridLayout_2->addLayout(horizontalLayout_24, 0, 0, 1, 1);

        horizontalLayout_25 = new QHBoxLayout();
        horizontalLayout_25->setObjectName(QStringLiteral("horizontalLayout_25"));
        label_AE_Qua = new QLabel(groupBox_2);
        label_AE_Qua->setObjectName(QStringLiteral("label_AE_Qua"));

        horizontalLayout_25->addWidget(label_AE_Qua);

        lineEdit_AE_Qua = new QLineEdit(groupBox_2);
        lineEdit_AE_Qua->setObjectName(QStringLiteral("lineEdit_AE_Qua"));

        horizontalLayout_25->addWidget(lineEdit_AE_Qua);


        gridLayout_2->addLayout(horizontalLayout_25, 1, 0, 1, 1);

        horizontalLayout_26 = new QHBoxLayout();
        horizontalLayout_26->setObjectName(QStringLiteral("horizontalLayout_26"));
        label_Psel = new QLabel(groupBox_2);
        label_Psel->setObjectName(QStringLiteral("label_Psel"));

        horizontalLayout_26->addWidget(label_Psel);

        lineEdit_Psel = new QLineEdit(groupBox_2);
        lineEdit_Psel->setObjectName(QStringLiteral("lineEdit_Psel"));

        horizontalLayout_26->addWidget(lineEdit_Psel);


        gridLayout_2->addLayout(horizontalLayout_26, 2, 0, 1, 1);

        horizontalLayout_27 = new QHBoxLayout();
        horizontalLayout_27->setObjectName(QStringLiteral("horizontalLayout_27"));
        label_Ssel = new QLabel(groupBox_2);
        label_Ssel->setObjectName(QStringLiteral("label_Ssel"));

        horizontalLayout_27->addWidget(label_Ssel);

        lineEdit_Ssel = new QLineEdit(groupBox_2);
        lineEdit_Ssel->setObjectName(QStringLiteral("lineEdit_Ssel"));

        horizontalLayout_27->addWidget(lineEdit_Ssel);


        gridLayout_2->addLayout(horizontalLayout_27, 3, 0, 1, 1);

        horizontalLayout_28 = new QHBoxLayout();
        horizontalLayout_28->setObjectName(QStringLiteral("horizontalLayout_28"));
        label_Tsel = new QLabel(groupBox_2);
        label_Tsel->setObjectName(QStringLiteral("label_Tsel"));

        horizontalLayout_28->addWidget(label_Tsel);

        lineEdit_Tsel = new QLineEdit(groupBox_2);
        lineEdit_Tsel->setObjectName(QStringLiteral("lineEdit_Tsel"));

        horizontalLayout_28->addWidget(lineEdit_Tsel);


        gridLayout_2->addLayout(horizontalLayout_28, 4, 0, 1, 1);

        horizontalSpacer_2 = new QSpacerItem(222, 17, QSizePolicy::Expanding, QSizePolicy::Minimum);

        gridLayout_2->addItem(horizontalSpacer_2, 5, 0, 1, 1);

        horizontalSpacer_3 = new QSpacerItem(222, 17, QSizePolicy::Expanding, QSizePolicy::Minimum);

        gridLayout_2->addItem(horizontalSpacer_3, 6, 0, 1, 1);

        horizontalSpacer_4 = new QSpacerItem(222, 17, QSizePolicy::Expanding, QSizePolicy::Minimum);

        gridLayout_2->addItem(horizontalSpacer_4, 7, 0, 1, 1);

        horizontalSpacer_5 = new QSpacerItem(222, 17, QSizePolicy::Expanding, QSizePolicy::Minimum);

        gridLayout_2->addItem(horizontalSpacer_5, 8, 0, 1, 1);

        horizontalSpacer_6 = new QSpacerItem(231, 17, QSizePolicy::Expanding, QSizePolicy::Minimum);

        gridLayout_2->addItem(horizontalSpacer_6, 9, 0, 1, 1);


        horizontalLayout_15->addWidget(groupBox_2);

        horizontalLayout_15->setStretch(0, 1);
        horizontalLayout_15->setStretch(1, 1);

        gridLayout_3->addLayout(horizontalLayout_15, 1, 0, 1, 3);


        retranslateUi(ApplyOneIED);

        QMetaObject::connectSlotsByName(ApplyOneIED);
    } // setupUi

    void retranslateUi(QDialog *ApplyOneIED)
    {
        ApplyOneIED->setWindowTitle(QApplication::translate("ApplyOneIED", "Dialog", 0));
        label_name->setText(QApplication::translate("ApplyOneIED", "TextLabel", 0));
        label_type->setText(QApplication::translate("ApplyOneIED", "TextLabel", 0));
        label_AD1->setText(QApplication::translate("ApplyOneIED", "TextLabel", 0));
        label_AD2->setText(QApplication::translate("ApplyOneIED", "TextLabel", 0));
        pushButton_Apply->setText(QApplication::translate("ApplyOneIED", "PushButton", 0));
        pushButton_Cancel->setText(QApplication::translate("ApplyOneIED", "PushButton", 0));
        groupBox->setTitle(QApplication::translate("ApplyOneIED", "IED", 0));
        label_Timeserver->setText(QApplication::translate("ApplyOneIED", "TextLabel", 0));
        label_ChanMod->setText(QApplication::translate("ApplyOneIED", "TextLabel", 0));
        label_Ctltime->setText(QApplication::translate("ApplyOneIED", "TextLabel", 0));
        label_GITime->setText(QApplication::translate("ApplyOneIED", "TextLabel", 0));
        label_RptBuf->setText(QApplication::translate("ApplyOneIED", "TextLabel", 0));
        label_RptInt->setText(QApplication::translate("ApplyOneIED", "TextLabel", 0));
        label_LostTime->setText(QApplication::translate("ApplyOneIED", "TextLabel", 0));
        label_KeepLive->setText(QApplication::translate("ApplyOneIED", "TextLabel", 0));
        label_AuthMod->setText(QApplication::translate("ApplyOneIED", "TextLabel", 0));
        label_AuthCode->setText(QApplication::translate("ApplyOneIED", "TextLabel", 0));
        groupBox_2->setTitle(QApplication::translate("ApplyOneIED", "Address", 0));
        label_AP_Title->setText(QApplication::translate("ApplyOneIED", "TextLabel", 0));
        label_AE_Qua->setText(QApplication::translate("ApplyOneIED", "TextLabel", 0));
        label_Psel->setText(QApplication::translate("ApplyOneIED", "TextLabel", 0));
        label_Ssel->setText(QApplication::translate("ApplyOneIED", "TextLabel", 0));
        label_Tsel->setText(QApplication::translate("ApplyOneIED", "TextLabel", 0));
    } // retranslateUi

};

namespace Ui {
    class ApplyOneIED: public Ui_ApplyOneIED {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_APPLYONEIED_H
