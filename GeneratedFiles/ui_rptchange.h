/********************************************************************************
** Form generated from reading UI file 'rptchange.ui'
**
** Created by: Qt User Interface Compiler version 5.6.1
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_RPTCHANGE_H
#define UI_RPTCHANGE_H

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
#include <QtWidgets/QTableView>

QT_BEGIN_NAMESPACE

class Ui_RptChange
{
public:
    QGridLayout *gridLayout;
    QHBoxLayout *horizontalLayout_2;
    QLabel *label;
    QLineEdit *lineEdit;
    QTableView *tableView;
    QHBoxLayout *horizontalLayout;
    QPushButton *pushButton_ok;
    QSpacerItem *horizontalSpacer;
    QPushButton *pushButton_Cancel;

    void setupUi(QDialog *RptChange)
    {
        if (RptChange->objectName().isEmpty())
            RptChange->setObjectName(QStringLiteral("RptChange"));
        RptChange->resize(384, 264);
        gridLayout = new QGridLayout(RptChange);
        gridLayout->setObjectName(QStringLiteral("gridLayout"));
        horizontalLayout_2 = new QHBoxLayout();
        horizontalLayout_2->setObjectName(QStringLiteral("horizontalLayout_2"));
        label = new QLabel(RptChange);
        label->setObjectName(QStringLiteral("label"));

        horizontalLayout_2->addWidget(label);

        lineEdit = new QLineEdit(RptChange);
        lineEdit->setObjectName(QStringLiteral("lineEdit"));

        horizontalLayout_2->addWidget(lineEdit);


        gridLayout->addLayout(horizontalLayout_2, 0, 0, 1, 1);

        tableView = new QTableView(RptChange);
        tableView->setObjectName(QStringLiteral("tableView"));

        gridLayout->addWidget(tableView, 1, 0, 1, 1);

        horizontalLayout = new QHBoxLayout();
        horizontalLayout->setObjectName(QStringLiteral("horizontalLayout"));
        pushButton_ok = new QPushButton(RptChange);
        pushButton_ok->setObjectName(QStringLiteral("pushButton_ok"));

        horizontalLayout->addWidget(pushButton_ok);

        horizontalSpacer = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout->addItem(horizontalSpacer);

        pushButton_Cancel = new QPushButton(RptChange);
        pushButton_Cancel->setObjectName(QStringLiteral("pushButton_Cancel"));

        horizontalLayout->addWidget(pushButton_Cancel);


        gridLayout->addLayout(horizontalLayout, 2, 0, 1, 1);


        retranslateUi(RptChange);

        QMetaObject::connectSlotsByName(RptChange);
    } // setupUi

    void retranslateUi(QDialog *RptChange)
    {
        RptChange->setWindowTitle(QApplication::translate("RptChange", "Dialog", 0));
        label->setText(QApplication::translate("RptChange", "TextLabel", 0));
        pushButton_ok->setText(QApplication::translate("RptChange", "PushButton", 0));
        pushButton_Cancel->setText(QApplication::translate("RptChange", "PushButton", 0));
    } // retranslateUi

};

namespace Ui {
    class RptChange: public Ui_RptChange {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_RPTCHANGE_H
