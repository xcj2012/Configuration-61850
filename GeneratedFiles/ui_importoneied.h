/********************************************************************************
** Form generated from reading UI file 'importoneied.ui'
**
** Created by: Qt User Interface Compiler version 5.6.1
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_IMPORTONEIED_H
#define UI_IMPORTONEIED_H

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

class Ui_ImportOneIed
{
public:
    QGridLayout *gridLayout;
    QHBoxLayout *horizontalLayout_4;
    QSpacerItem *horizontalSpacer_5;
    QLabel *label_doc;
    QSpacerItem *horizontalSpacer_6;
    QHBoxLayout *horizontalLayout_2;
    QLabel *label_file;
    QLineEdit *lineEdit_file;
    QPushButton *pushButton_open;
    QHBoxLayout *horizontalLayout_3;
    QSpacerItem *horizontalSpacer_2;
    QPushButton *pushButton_ok;
    QSpacerItem *horizontalSpacer_3;
    QPushButton *pushButton_cancel;
    QSpacerItem *horizontalSpacer_4;
    QHBoxLayout *horizontalLayout;
    QLabel *label_name;
    QLineEdit *lineEdit_name;
    QSpacerItem *horizontalSpacer;

    void setupUi(QDialog *ImportOneIed)
    {
        if (ImportOneIed->objectName().isEmpty())
            ImportOneIed->setObjectName(QStringLiteral("ImportOneIed"));
        ImportOneIed->resize(400, 160);
        ImportOneIed->setMaximumSize(QSize(400, 160));
        gridLayout = new QGridLayout(ImportOneIed);
        gridLayout->setObjectName(QStringLiteral("gridLayout"));
        horizontalLayout_4 = new QHBoxLayout();
        horizontalLayout_4->setObjectName(QStringLiteral("horizontalLayout_4"));
        horizontalSpacer_5 = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout_4->addItem(horizontalSpacer_5);

        label_doc = new QLabel(ImportOneIed);
        label_doc->setObjectName(QStringLiteral("label_doc"));

        horizontalLayout_4->addWidget(label_doc);

        horizontalSpacer_6 = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout_4->addItem(horizontalSpacer_6);


        gridLayout->addLayout(horizontalLayout_4, 0, 0, 1, 1);

        horizontalLayout_2 = new QHBoxLayout();
        horizontalLayout_2->setObjectName(QStringLiteral("horizontalLayout_2"));
        label_file = new QLabel(ImportOneIed);
        label_file->setObjectName(QStringLiteral("label_file"));

        horizontalLayout_2->addWidget(label_file);

        lineEdit_file = new QLineEdit(ImportOneIed);
        lineEdit_file->setObjectName(QStringLiteral("lineEdit_file"));

        horizontalLayout_2->addWidget(lineEdit_file);

        pushButton_open = new QPushButton(ImportOneIed);
        pushButton_open->setObjectName(QStringLiteral("pushButton_open"));

        horizontalLayout_2->addWidget(pushButton_open);


        gridLayout->addLayout(horizontalLayout_2, 2, 0, 1, 1);

        horizontalLayout_3 = new QHBoxLayout();
        horizontalLayout_3->setObjectName(QStringLiteral("horizontalLayout_3"));
        horizontalSpacer_2 = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout_3->addItem(horizontalSpacer_2);

        pushButton_ok = new QPushButton(ImportOneIed);
        pushButton_ok->setObjectName(QStringLiteral("pushButton_ok"));

        horizontalLayout_3->addWidget(pushButton_ok);

        horizontalSpacer_3 = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout_3->addItem(horizontalSpacer_3);

        pushButton_cancel = new QPushButton(ImportOneIed);
        pushButton_cancel->setObjectName(QStringLiteral("pushButton_cancel"));

        horizontalLayout_3->addWidget(pushButton_cancel);

        horizontalSpacer_4 = new QSpacerItem(97, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout_3->addItem(horizontalSpacer_4);


        gridLayout->addLayout(horizontalLayout_3, 4, 0, 1, 1);

        horizontalLayout = new QHBoxLayout();
        horizontalLayout->setObjectName(QStringLiteral("horizontalLayout"));
        label_name = new QLabel(ImportOneIed);
        label_name->setObjectName(QStringLiteral("label_name"));

        horizontalLayout->addWidget(label_name);

        lineEdit_name = new QLineEdit(ImportOneIed);
        lineEdit_name->setObjectName(QStringLiteral("lineEdit_name"));

        horizontalLayout->addWidget(lineEdit_name);

        horizontalSpacer = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout->addItem(horizontalSpacer);


        gridLayout->addLayout(horizontalLayout, 3, 0, 1, 1);


        retranslateUi(ImportOneIed);

        QMetaObject::connectSlotsByName(ImportOneIed);
    } // setupUi

    void retranslateUi(QDialog *ImportOneIed)
    {
        ImportOneIed->setWindowTitle(QApplication::translate("ImportOneIed", "Dialog", 0));
        label_doc->setText(QApplication::translate("ImportOneIed", "TextLabel", 0));
        label_file->setText(QApplication::translate("ImportOneIed", "TextLabel", 0));
        pushButton_open->setText(QApplication::translate("ImportOneIed", "PushButton", 0));
        pushButton_ok->setText(QApplication::translate("ImportOneIed", "PushButton", 0));
        pushButton_cancel->setText(QApplication::translate("ImportOneIed", "PushButton", 0));
        label_name->setText(QApplication::translate("ImportOneIed", "TextLabel", 0));
    } // retranslateUi

};

namespace Ui {
    class ImportOneIed: public Ui_ImportOneIed {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_IMPORTONEIED_H
