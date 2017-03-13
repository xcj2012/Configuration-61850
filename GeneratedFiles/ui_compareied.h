/********************************************************************************
** Form generated from reading UI file 'compareied.ui'
**
** Created by: Qt User Interface Compiler version 5.6.1
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_COMPAREIED_H
#define UI_COMPAREIED_H

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
#include <QtWidgets/QSpacerItem>
#include <QtWidgets/QTabWidget>
#include <QtWidgets/QTableView>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_CompareIED
{
public:
    QGridLayout *gridLayout_4;
    QLabel *label;
    QTabWidget *tab;
    QWidget *tab_input;
    QGridLayout *gridLayout;
    QTableView *tableView_input;
    QWidget *tab_data;
    QGridLayout *gridLayout_2;
    QTableView *tableView_data;
    QWidget *tab_cblk;
    QGridLayout *gridLayout_3;
    QTableView *tableView_cblk;
    QHBoxLayout *horizontalLayout;
    QSpacerItem *horizontalSpacer;
    QPushButton *pushButton_Replace_1;
    QPushButton *pushButton_Replace_2;
    QPushButton *pushButton_Ignore;
    QPushButton *pushButton_Cancel;

    void setupUi(QDialog *CompareIED)
    {
        if (CompareIED->objectName().isEmpty())
            CompareIED->setObjectName(QStringLiteral("CompareIED"));
        CompareIED->resize(618, 439);
        gridLayout_4 = new QGridLayout(CompareIED);
        gridLayout_4->setSpacing(6);
        gridLayout_4->setContentsMargins(11, 11, 11, 11);
        gridLayout_4->setObjectName(QStringLiteral("gridLayout_4"));
        label = new QLabel(CompareIED);
        label->setObjectName(QStringLiteral("label"));

        gridLayout_4->addWidget(label, 0, 0, 1, 1);

        tab = new QTabWidget(CompareIED);
        tab->setObjectName(QStringLiteral("tab"));
        tab_input = new QWidget();
        tab_input->setObjectName(QStringLiteral("tab_input"));
        gridLayout = new QGridLayout(tab_input);
        gridLayout->setSpacing(6);
        gridLayout->setContentsMargins(11, 11, 11, 11);
        gridLayout->setObjectName(QStringLiteral("gridLayout"));
        tableView_input = new QTableView(tab_input);
        tableView_input->setObjectName(QStringLiteral("tableView_input"));

        gridLayout->addWidget(tableView_input, 0, 0, 1, 1);

        tab->addTab(tab_input, QString());
        tab_data = new QWidget();
        tab_data->setObjectName(QStringLiteral("tab_data"));
        gridLayout_2 = new QGridLayout(tab_data);
        gridLayout_2->setSpacing(6);
        gridLayout_2->setContentsMargins(11, 11, 11, 11);
        gridLayout_2->setObjectName(QStringLiteral("gridLayout_2"));
        tableView_data = new QTableView(tab_data);
        tableView_data->setObjectName(QStringLiteral("tableView_data"));

        gridLayout_2->addWidget(tableView_data, 0, 0, 1, 1);

        tab->addTab(tab_data, QString());
        tab_cblk = new QWidget();
        tab_cblk->setObjectName(QStringLiteral("tab_cblk"));
        gridLayout_3 = new QGridLayout(tab_cblk);
        gridLayout_3->setSpacing(6);
        gridLayout_3->setContentsMargins(11, 11, 11, 11);
        gridLayout_3->setObjectName(QStringLiteral("gridLayout_3"));
        tableView_cblk = new QTableView(tab_cblk);
        tableView_cblk->setObjectName(QStringLiteral("tableView_cblk"));

        gridLayout_3->addWidget(tableView_cblk, 0, 0, 1, 1);

        tab->addTab(tab_cblk, QString());

        gridLayout_4->addWidget(tab, 1, 0, 1, 1);

        horizontalLayout = new QHBoxLayout();
        horizontalLayout->setSpacing(6);
        horizontalLayout->setObjectName(QStringLiteral("horizontalLayout"));
        horizontalSpacer = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout->addItem(horizontalSpacer);

        pushButton_Replace_1 = new QPushButton(CompareIED);
        pushButton_Replace_1->setObjectName(QStringLiteral("pushButton_Replace_1"));

        horizontalLayout->addWidget(pushButton_Replace_1);

        pushButton_Replace_2 = new QPushButton(CompareIED);
        pushButton_Replace_2->setObjectName(QStringLiteral("pushButton_Replace_2"));

        horizontalLayout->addWidget(pushButton_Replace_2);

        pushButton_Ignore = new QPushButton(CompareIED);
        pushButton_Ignore->setObjectName(QStringLiteral("pushButton_Ignore"));

        horizontalLayout->addWidget(pushButton_Ignore);

        pushButton_Cancel = new QPushButton(CompareIED);
        pushButton_Cancel->setObjectName(QStringLiteral("pushButton_Cancel"));

        horizontalLayout->addWidget(pushButton_Cancel);

        horizontalLayout->setStretch(0, 4);
        horizontalLayout->setStretch(1, 1);
        horizontalLayout->setStretch(2, 1);
        horizontalLayout->setStretch(3, 1);
        horizontalLayout->setStretch(4, 1);

        gridLayout_4->addLayout(horizontalLayout, 2, 0, 1, 1);


        retranslateUi(CompareIED);

        tab->setCurrentIndex(2);


        QMetaObject::connectSlotsByName(CompareIED);
    } // setupUi

    void retranslateUi(QDialog *CompareIED)
    {
        CompareIED->setWindowTitle(QApplication::translate("CompareIED", "CompareIED", 0));
        label->setText(QApplication::translate("CompareIED", "TextLabel", 0));
        tab->setTabText(tab->indexOf(tab_input), QApplication::translate("CompareIED", "Tab 1", 0));
        tab->setTabText(tab->indexOf(tab_data), QApplication::translate("CompareIED", "Tab 2", 0));
        tab->setTabText(tab->indexOf(tab_cblk), QApplication::translate("CompareIED", "Page", 0));
        pushButton_Replace_1->setText(QApplication::translate("CompareIED", "PushButton", 0));
        pushButton_Replace_2->setText(QApplication::translate("CompareIED", "PushButton", 0));
        pushButton_Ignore->setText(QApplication::translate("CompareIED", "PushButton", 0));
        pushButton_Cancel->setText(QApplication::translate("CompareIED", "PushButton", 0));
    } // retranslateUi

};

namespace Ui {
    class CompareIED: public Ui_CompareIED {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_COMPAREIED_H
