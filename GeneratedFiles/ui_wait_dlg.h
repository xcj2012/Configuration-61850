/********************************************************************************
** Form generated from reading UI file 'wait_dlg.ui'
**
** Created by: Qt User Interface Compiler version 5.6.1
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_WAIT_DLG_H
#define UI_WAIT_DLG_H

#include <QtCore/QVariant>
#include <QtWidgets/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QButtonGroup>
#include <QtWidgets/QDialog>
#include <QtWidgets/QGridLayout>
#include <QtWidgets/QHBoxLayout>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QLabel>

QT_BEGIN_NAMESPACE

class Ui_Wait_Dlg
{
public:
    QGridLayout *gridLayout;
    QHBoxLayout *horizontalLayout;
    QLabel *label;
    QLabel *label_2;

    void setupUi(QDialog *Wait_Dlg)
    {
        if (Wait_Dlg->objectName().isEmpty())
            Wait_Dlg->setObjectName(QStringLiteral("Wait_Dlg"));
        Wait_Dlg->resize(250, 45);
        Wait_Dlg->setMaximumSize(QSize(250, 45));
        gridLayout = new QGridLayout(Wait_Dlg);
        gridLayout->setSpacing(6);
        gridLayout->setContentsMargins(11, 11, 11, 11);
        gridLayout->setObjectName(QStringLiteral("gridLayout"));
        horizontalLayout = new QHBoxLayout();
        horizontalLayout->setSpacing(6);
        horizontalLayout->setObjectName(QStringLiteral("horizontalLayout"));
        label = new QLabel(Wait_Dlg);
        label->setObjectName(QStringLiteral("label"));
        label->setMaximumSize(QSize(20, 20));

        horizontalLayout->addWidget(label);

        label_2 = new QLabel(Wait_Dlg);
        label_2->setObjectName(QStringLiteral("label_2"));
        label_2->setMaximumSize(QSize(245, 20));

        horizontalLayout->addWidget(label_2);

        horizontalLayout->setStretch(0, 1);
        horizontalLayout->setStretch(1, 5);

        gridLayout->addLayout(horizontalLayout, 0, 0, 1, 1);


        retranslateUi(Wait_Dlg);

        QMetaObject::connectSlotsByName(Wait_Dlg);
    } // setupUi

    void retranslateUi(QDialog *Wait_Dlg)
    {
        Wait_Dlg->setWindowTitle(QApplication::translate("Wait_Dlg", "Wait_Dlg", 0));
        label->setText(QApplication::translate("Wait_Dlg", "TextLabel", 0));
        label_2->setText(QApplication::translate("Wait_Dlg", "TextLabel", 0));
    } // retranslateUi

};

namespace Ui {
    class Wait_Dlg: public Ui_Wait_Dlg {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_WAIT_DLG_H
