/********************************************************************************
** Form generated from reading UI file 'adddatesetdlg.ui'
**
** Created by: Qt User Interface Compiler version 5.6.1
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_ADDDATESETDLG_H
#define UI_ADDDATESETDLG_H

#include <QtCore/QVariant>
#include <QtWidgets/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QButtonGroup>
#include <QtWidgets/QDialog>
#include <QtWidgets/QGridLayout>
#include <QtWidgets/QGroupBox>
#include <QtWidgets/QHBoxLayout>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QLabel>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QSpacerItem>
#include <QtWidgets/QTextBrowser>
#include <QtWidgets/QVBoxLayout>

QT_BEGIN_NAMESPACE

class Ui_AddDateSetdlg
{
public:
    QGridLayout *gridLayout_2;
    QHBoxLayout *horizontalLayout_4;
    QVBoxLayout *verticalLayout;
    QHBoxLayout *horizontalLayout;
    QSpacerItem *horizontalSpacer;
    QLabel *label_name;
    QLineEdit *lineEdit_name;
    QSpacerItem *horizontalSpacer_2;
    QHBoxLayout *horizontalLayout_2;
    QSpacerItem *horizontalSpacer_4;
    QLabel *label_desc;
    QLineEdit *lineEdit_desc;
    QSpacerItem *horizontalSpacer_3;
    QHBoxLayout *horizontalLayout_3;
    QSpacerItem *horizontalSpacer_5;
    QPushButton *pushButton_ok;
    QSpacerItem *horizontalSpacer_6;
    QPushButton *pushButton_cancel;
    QSpacerItem *horizontalSpacer_7;
    QGroupBox *groupBox;
    QGridLayout *gridLayout;
    QTextBrowser *textBrowser;

    void setupUi(QDialog *AddDateSetdlg)
    {
        if (AddDateSetdlg->objectName().isEmpty())
            AddDateSetdlg->setObjectName(QStringLiteral("AddDateSetdlg"));
        AddDateSetdlg->resize(530, 310);
        AddDateSetdlg->setMinimumSize(QSize(530, 0));
        AddDateSetdlg->setMaximumSize(QSize(530, 16777215));
        gridLayout_2 = new QGridLayout(AddDateSetdlg);
        gridLayout_2->setObjectName(QStringLiteral("gridLayout_2"));
        horizontalLayout_4 = new QHBoxLayout();
        horizontalLayout_4->setObjectName(QStringLiteral("horizontalLayout_4"));
        verticalLayout = new QVBoxLayout();
        verticalLayout->setObjectName(QStringLiteral("verticalLayout"));
        horizontalLayout = new QHBoxLayout();
        horizontalLayout->setObjectName(QStringLiteral("horizontalLayout"));
        horizontalSpacer = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout->addItem(horizontalSpacer);

        label_name = new QLabel(AddDateSetdlg);
        label_name->setObjectName(QStringLiteral("label_name"));

        horizontalLayout->addWidget(label_name);

        lineEdit_name = new QLineEdit(AddDateSetdlg);
        lineEdit_name->setObjectName(QStringLiteral("lineEdit_name"));

        horizontalLayout->addWidget(lineEdit_name);

        horizontalSpacer_2 = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout->addItem(horizontalSpacer_2);


        verticalLayout->addLayout(horizontalLayout);

        horizontalLayout_2 = new QHBoxLayout();
        horizontalLayout_2->setObjectName(QStringLiteral("horizontalLayout_2"));
        horizontalSpacer_4 = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout_2->addItem(horizontalSpacer_4);

        label_desc = new QLabel(AddDateSetdlg);
        label_desc->setObjectName(QStringLiteral("label_desc"));

        horizontalLayout_2->addWidget(label_desc);

        lineEdit_desc = new QLineEdit(AddDateSetdlg);
        lineEdit_desc->setObjectName(QStringLiteral("lineEdit_desc"));

        horizontalLayout_2->addWidget(lineEdit_desc);

        horizontalSpacer_3 = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout_2->addItem(horizontalSpacer_3);


        verticalLayout->addLayout(horizontalLayout_2);

        horizontalLayout_3 = new QHBoxLayout();
        horizontalLayout_3->setObjectName(QStringLiteral("horizontalLayout_3"));
        horizontalSpacer_5 = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout_3->addItem(horizontalSpacer_5);

        pushButton_ok = new QPushButton(AddDateSetdlg);
        pushButton_ok->setObjectName(QStringLiteral("pushButton_ok"));

        horizontalLayout_3->addWidget(pushButton_ok);

        horizontalSpacer_6 = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout_3->addItem(horizontalSpacer_6);

        pushButton_cancel = new QPushButton(AddDateSetdlg);
        pushButton_cancel->setObjectName(QStringLiteral("pushButton_cancel"));

        horizontalLayout_3->addWidget(pushButton_cancel);

        horizontalSpacer_7 = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout_3->addItem(horizontalSpacer_7);


        verticalLayout->addLayout(horizontalLayout_3);


        horizontalLayout_4->addLayout(verticalLayout);

        groupBox = new QGroupBox(AddDateSetdlg);
        groupBox->setObjectName(QStringLiteral("groupBox"));
        gridLayout = new QGridLayout(groupBox);
        gridLayout->setObjectName(QStringLiteral("gridLayout"));
        textBrowser = new QTextBrowser(groupBox);
        textBrowser->setObjectName(QStringLiteral("textBrowser"));
        textBrowser->setEnabled(true);

        gridLayout->addWidget(textBrowser, 0, 0, 1, 1);


        horizontalLayout_4->addWidget(groupBox);

        horizontalLayout_4->setStretch(0, 1);
        horizontalLayout_4->setStretch(1, 1);

        gridLayout_2->addLayout(horizontalLayout_4, 0, 0, 1, 1);


        retranslateUi(AddDateSetdlg);

        QMetaObject::connectSlotsByName(AddDateSetdlg);
    } // setupUi

    void retranslateUi(QDialog *AddDateSetdlg)
    {
        AddDateSetdlg->setWindowTitle(QApplication::translate("AddDateSetdlg", "Dialog", 0));
        label_name->setText(QApplication::translate("AddDateSetdlg", "TextLabel", 0));
        label_desc->setText(QApplication::translate("AddDateSetdlg", "TextLabel", 0));
        pushButton_ok->setText(QApplication::translate("AddDateSetdlg", "PushButton", 0));
        pushButton_cancel->setText(QApplication::translate("AddDateSetdlg", "PushButton", 0));
        groupBox->setTitle(QApplication::translate("AddDateSetdlg", "GroupBox", 0));
    } // retranslateUi

};

namespace Ui {
    class AddDateSetdlg: public Ui_AddDateSetdlg {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_ADDDATESETDLG_H
