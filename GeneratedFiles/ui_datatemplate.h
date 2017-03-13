/********************************************************************************
** Form generated from reading UI file 'datatemplate.ui'
**
** Created by: Qt User Interface Compiler version 5.6.1
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_DATATEMPLATE_H
#define UI_DATATEMPLATE_H

#include <QtCore/QVariant>
#include <QtWidgets/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QButtonGroup>
#include <QtWidgets/QDialog>
#include <QtWidgets/QGridLayout>
#include <QtWidgets/QHBoxLayout>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QLabel>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QRadioButton>
#include <QtWidgets/QSpacerItem>

QT_BEGIN_NAMESPACE

class Ui_DataTempLate
{
public:
    QGridLayout *gridLayout;
    QLabel *label;
    QHBoxLayout *horizontalLayout;
    QSpacerItem *horizontalSpacer;
    QRadioButton *radioButton_Add;
    QSpacerItem *horizontalSpacer_4;
    QHBoxLayout *horizontalLayout_2;
    QSpacerItem *horizontalSpacer_2;
    QRadioButton *radioButton_Replace;
    QSpacerItem *horizontalSpacer_5;
    QHBoxLayout *horizontalLayout_3;
    QSpacerItem *horizontalSpacer_3;
    QRadioButton *radioButton_Ignore;
    QSpacerItem *horizontalSpacer_6;
    QHBoxLayout *horizontalLayout_4;
    QPushButton *pushButton_Apply;
    QPushButton *pushButton_Cancel;

    void setupUi(QDialog *DataTempLate)
    {
        if (DataTempLate->objectName().isEmpty())
            DataTempLate->setObjectName(QStringLiteral("DataTempLate"));
        DataTempLate->resize(220, 145);
        DataTempLate->setMaximumSize(QSize(220, 145));
        gridLayout = new QGridLayout(DataTempLate);
        gridLayout->setObjectName(QStringLiteral("gridLayout"));
        label = new QLabel(DataTempLate);
        label->setObjectName(QStringLiteral("label"));

        gridLayout->addWidget(label, 0, 0, 1, 1);

        horizontalLayout = new QHBoxLayout();
        horizontalLayout->setObjectName(QStringLiteral("horizontalLayout"));
        horizontalSpacer = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout->addItem(horizontalSpacer);

        radioButton_Add = new QRadioButton(DataTempLate);
        radioButton_Add->setObjectName(QStringLiteral("radioButton_Add"));
        radioButton_Add->setMinimumSize(QSize(89, 0));
        radioButton_Add->setMaximumSize(QSize(89, 16777215));
        radioButton_Add->setSizeIncrement(QSize(0, 0));

        horizontalLayout->addWidget(radioButton_Add);

        horizontalSpacer_4 = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout->addItem(horizontalSpacer_4);


        gridLayout->addLayout(horizontalLayout, 1, 0, 1, 1);

        horizontalLayout_2 = new QHBoxLayout();
        horizontalLayout_2->setObjectName(QStringLiteral("horizontalLayout_2"));
        horizontalSpacer_2 = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout_2->addItem(horizontalSpacer_2);

        radioButton_Replace = new QRadioButton(DataTempLate);
        radioButton_Replace->setObjectName(QStringLiteral("radioButton_Replace"));
        radioButton_Replace->setMinimumSize(QSize(89, 0));
        radioButton_Replace->setMaximumSize(QSize(89, 16777215));

        horizontalLayout_2->addWidget(radioButton_Replace);

        horizontalSpacer_5 = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout_2->addItem(horizontalSpacer_5);


        gridLayout->addLayout(horizontalLayout_2, 2, 0, 1, 1);

        horizontalLayout_3 = new QHBoxLayout();
        horizontalLayout_3->setObjectName(QStringLiteral("horizontalLayout_3"));
        horizontalSpacer_3 = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout_3->addItem(horizontalSpacer_3);

        radioButton_Ignore = new QRadioButton(DataTempLate);
        radioButton_Ignore->setObjectName(QStringLiteral("radioButton_Ignore"));
        radioButton_Ignore->setMinimumSize(QSize(89, 0));
        radioButton_Ignore->setMaximumSize(QSize(89, 16777215));

        horizontalLayout_3->addWidget(radioButton_Ignore);

        horizontalSpacer_6 = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout_3->addItem(horizontalSpacer_6);


        gridLayout->addLayout(horizontalLayout_3, 3, 0, 1, 1);

        horizontalLayout_4 = new QHBoxLayout();
        horizontalLayout_4->setObjectName(QStringLiteral("horizontalLayout_4"));
        pushButton_Apply = new QPushButton(DataTempLate);
        pushButton_Apply->setObjectName(QStringLiteral("pushButton_Apply"));

        horizontalLayout_4->addWidget(pushButton_Apply);

        pushButton_Cancel = new QPushButton(DataTempLate);
        pushButton_Cancel->setObjectName(QStringLiteral("pushButton_Cancel"));

        horizontalLayout_4->addWidget(pushButton_Cancel);


        gridLayout->addLayout(horizontalLayout_4, 4, 0, 1, 1);

        gridLayout->setRowStretch(0, 1);
        gridLayout->setRowStretch(1, 1);
        gridLayout->setRowStretch(2, 1);
        gridLayout->setRowStretch(3, 1);
        gridLayout->setRowStretch(4, 1);

        retranslateUi(DataTempLate);

        QMetaObject::connectSlotsByName(DataTempLate);
    } // setupUi

    void retranslateUi(QDialog *DataTempLate)
    {
        DataTempLate->setWindowTitle(QApplication::translate("DataTempLate", "Dialog", 0));
        label->setText(QApplication::translate("DataTempLate", "TextLabel", 0));
        radioButton_Add->setText(QApplication::translate("DataTempLate", "RadioButton", 0));
        radioButton_Replace->setText(QApplication::translate("DataTempLate", "RadioButton", 0));
        radioButton_Ignore->setText(QApplication::translate("DataTempLate", "RadioButton", 0));
        pushButton_Apply->setText(QString());
        pushButton_Cancel->setText(QString());
    } // retranslateUi

};

namespace Ui {
    class DataTempLate: public Ui_DataTempLate {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_DATATEMPLATE_H
