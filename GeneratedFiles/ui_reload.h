/********************************************************************************
** Form generated from reading UI file 'reload.ui'
**
** Created by: Qt User Interface Compiler version 5.6.1
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_RELOAD_H
#define UI_RELOAD_H

#include <QtCore/QVariant>
#include <QtWidgets/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QButtonGroup>
#include <QtWidgets/QDialog>
#include <QtWidgets/QGridLayout>
#include <QtWidgets/QHBoxLayout>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QSpacerItem>
#include <QtWidgets/QTableView>

QT_BEGIN_NAMESPACE

class Ui_ReLoad
{
public:
    QGridLayout *gridLayout;
    QTableView *tableView;
    QHBoxLayout *horizontalLayout;
    QSpacerItem *horizontalSpacer;
    QPushButton *pushButton_apply;
    QPushButton *pushButton_cancel;
    QSpacerItem *horizontalSpacer_2;

    void setupUi(QDialog *ReLoad)
    {
        if (ReLoad->objectName().isEmpty())
            ReLoad->setObjectName(QStringLiteral("ReLoad"));
        ReLoad->resize(310, 272);
        gridLayout = new QGridLayout(ReLoad);
        gridLayout->setObjectName(QStringLiteral("gridLayout"));
        tableView = new QTableView(ReLoad);
        tableView->setObjectName(QStringLiteral("tableView"));

        gridLayout->addWidget(tableView, 0, 0, 1, 1);

        horizontalLayout = new QHBoxLayout();
        horizontalLayout->setObjectName(QStringLiteral("horizontalLayout"));
        horizontalSpacer = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout->addItem(horizontalSpacer);

        pushButton_apply = new QPushButton(ReLoad);
        pushButton_apply->setObjectName(QStringLiteral("pushButton_apply"));

        horizontalLayout->addWidget(pushButton_apply);

        pushButton_cancel = new QPushButton(ReLoad);
        pushButton_cancel->setObjectName(QStringLiteral("pushButton_cancel"));

        horizontalLayout->addWidget(pushButton_cancel);

        horizontalSpacer_2 = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout->addItem(horizontalSpacer_2);


        gridLayout->addLayout(horizontalLayout, 1, 0, 1, 1);


        retranslateUi(ReLoad);

        QMetaObject::connectSlotsByName(ReLoad);
    } // setupUi

    void retranslateUi(QDialog *ReLoad)
    {
        ReLoad->setWindowTitle(QApplication::translate("ReLoad", "Dialog", 0));
        pushButton_apply->setText(QApplication::translate("ReLoad", "PushButton", 0));
        pushButton_cancel->setText(QApplication::translate("ReLoad", "PushButton", 0));
    } // retranslateUi

};

namespace Ui {
    class ReLoad: public Ui_ReLoad {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_RELOAD_H
