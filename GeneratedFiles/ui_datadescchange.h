/********************************************************************************
** Form generated from reading UI file 'datadescchange.ui'
**
** Created by: Qt User Interface Compiler version 5.6.1
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_DATADESCCHANGE_H
#define UI_DATADESCCHANGE_H

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

class Ui_DataDescChange
{
public:
    QGridLayout *gridLayout;
    QHBoxLayout *horizontalLayout;
    QLabel *label_Desc;
    QLineEdit *lineEdit_Desc1;
    QLineEdit *lineEdit_Desc2;
    QHBoxLayout *horizontalLayout_2;
    QLabel *label_DU;
    QLineEdit *lineEdit_dU1;
    QLineEdit *lineEdit_dU2;
    QHBoxLayout *horizontalLayout_3;
    QSpacerItem *horizontalSpacer;
    QPushButton *pushButton_Apply;
    QPushButton *pushButton_Cancel;

    void setupUi(QDialog *DataDescChange)
    {
        if (DataDescChange->objectName().isEmpty())
            DataDescChange->setObjectName(QStringLiteral("DataDescChange"));
        DataDescChange->resize(355, 110);
        DataDescChange->setMaximumSize(QSize(355, 110));
        gridLayout = new QGridLayout(DataDescChange);
        gridLayout->setSpacing(6);
        gridLayout->setContentsMargins(11, 11, 11, 11);
        gridLayout->setObjectName(QStringLiteral("gridLayout"));
        horizontalLayout = new QHBoxLayout();
        horizontalLayout->setSpacing(6);
        horizontalLayout->setObjectName(QStringLiteral("horizontalLayout"));
        label_Desc = new QLabel(DataDescChange);
        label_Desc->setObjectName(QStringLiteral("label_Desc"));
        label_Desc->setMinimumSize(QSize(53, 0));
        label_Desc->setMaximumSize(QSize(54, 16777215));

        horizontalLayout->addWidget(label_Desc);

        lineEdit_Desc1 = new QLineEdit(DataDescChange);
        lineEdit_Desc1->setObjectName(QStringLiteral("lineEdit_Desc1"));

        horizontalLayout->addWidget(lineEdit_Desc1);

        lineEdit_Desc2 = new QLineEdit(DataDescChange);
        lineEdit_Desc2->setObjectName(QStringLiteral("lineEdit_Desc2"));

        horizontalLayout->addWidget(lineEdit_Desc2);


        gridLayout->addLayout(horizontalLayout, 0, 0, 1, 1);

        horizontalLayout_2 = new QHBoxLayout();
        horizontalLayout_2->setSpacing(6);
        horizontalLayout_2->setObjectName(QStringLiteral("horizontalLayout_2"));
        label_DU = new QLabel(DataDescChange);
        label_DU->setObjectName(QStringLiteral("label_DU"));
        label_DU->setMinimumSize(QSize(54, 0));
        label_DU->setMaximumSize(QSize(54, 16777215));

        horizontalLayout_2->addWidget(label_DU);

        lineEdit_dU1 = new QLineEdit(DataDescChange);
        lineEdit_dU1->setObjectName(QStringLiteral("lineEdit_dU1"));

        horizontalLayout_2->addWidget(lineEdit_dU1);

        lineEdit_dU2 = new QLineEdit(DataDescChange);
        lineEdit_dU2->setObjectName(QStringLiteral("lineEdit_dU2"));

        horizontalLayout_2->addWidget(lineEdit_dU2);


        gridLayout->addLayout(horizontalLayout_2, 1, 0, 1, 1);

        horizontalLayout_3 = new QHBoxLayout();
        horizontalLayout_3->setSpacing(6);
        horizontalLayout_3->setObjectName(QStringLiteral("horizontalLayout_3"));
        horizontalSpacer = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout_3->addItem(horizontalSpacer);

        pushButton_Apply = new QPushButton(DataDescChange);
        pushButton_Apply->setObjectName(QStringLiteral("pushButton_Apply"));

        horizontalLayout_3->addWidget(pushButton_Apply);

        pushButton_Cancel = new QPushButton(DataDescChange);
        pushButton_Cancel->setObjectName(QStringLiteral("pushButton_Cancel"));

        horizontalLayout_3->addWidget(pushButton_Cancel);

        horizontalLayout_3->setStretch(0, 3);
        horizontalLayout_3->setStretch(1, 1);
        horizontalLayout_3->setStretch(2, 1);

        gridLayout->addLayout(horizontalLayout_3, 2, 0, 1, 1);


        retranslateUi(DataDescChange);

        QMetaObject::connectSlotsByName(DataDescChange);
    } // setupUi

    void retranslateUi(QDialog *DataDescChange)
    {
        DataDescChange->setWindowTitle(QApplication::translate("DataDescChange", "DataDescChange", 0));
        label_Desc->setText(QApplication::translate("DataDescChange", "TextLabel", 0));
        label_DU->setText(QApplication::translate("DataDescChange", "TextLabel", 0));
        pushButton_Apply->setText(QApplication::translate("DataDescChange", "PushButton", 0));
        pushButton_Cancel->setText(QApplication::translate("DataDescChange", "PushButton", 0));
    } // retranslateUi

};

namespace Ui {
    class DataDescChange: public Ui_DataDescChange {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_DATADESCCHANGE_H
