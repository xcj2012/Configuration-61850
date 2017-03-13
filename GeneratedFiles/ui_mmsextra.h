/********************************************************************************
** Form generated from reading UI file 'mmsextra.ui'
**
** Created by: Qt User Interface Compiler version 5.6.1
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_MMSEXTRA_H
#define UI_MMSEXTRA_H

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
#include <QtWidgets/QTabWidget>
#include <QtWidgets/QTableView>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_MMSExtra
{
public:
    QGridLayout *gridLayout_4;
    QTabWidget *tabWidget;
    QWidget *tab;
    QGridLayout *gridLayout;
    QTableView *tableView_MMS;
    QWidget *tab_2;
    QGridLayout *gridLayout_2;
    QTableView *tableView_GOOSE;
    QWidget *tab_3;
    QGridLayout *gridLayout_3;
    QTableView *tableView_SMV;
    QHBoxLayout *horizontalLayout;
    QSpacerItem *horizontalSpacer;
    QPushButton *pushButton_Apply;
    QSpacerItem *horizontalSpacer_2;
    QPushButton *pushButton_Cancel;
    QSpacerItem *horizontalSpacer_3;

    void setupUi(QDialog *MMSExtra)
    {
        if (MMSExtra->objectName().isEmpty())
            MMSExtra->setObjectName(QStringLiteral("MMSExtra"));
        MMSExtra->resize(494, 272);
        gridLayout_4 = new QGridLayout(MMSExtra);
        gridLayout_4->setObjectName(QStringLiteral("gridLayout_4"));
        tabWidget = new QTabWidget(MMSExtra);
        tabWidget->setObjectName(QStringLiteral("tabWidget"));
        tab = new QWidget();
        tab->setObjectName(QStringLiteral("tab"));
        gridLayout = new QGridLayout(tab);
        gridLayout->setObjectName(QStringLiteral("gridLayout"));
        tableView_MMS = new QTableView(tab);
        tableView_MMS->setObjectName(QStringLiteral("tableView_MMS"));

        gridLayout->addWidget(tableView_MMS, 0, 0, 1, 1);

        tabWidget->addTab(tab, QString());
        tab_2 = new QWidget();
        tab_2->setObjectName(QStringLiteral("tab_2"));
        gridLayout_2 = new QGridLayout(tab_2);
        gridLayout_2->setObjectName(QStringLiteral("gridLayout_2"));
        tableView_GOOSE = new QTableView(tab_2);
        tableView_GOOSE->setObjectName(QStringLiteral("tableView_GOOSE"));

        gridLayout_2->addWidget(tableView_GOOSE, 0, 0, 1, 1);

        tabWidget->addTab(tab_2, QString());
        tab_3 = new QWidget();
        tab_3->setObjectName(QStringLiteral("tab_3"));
        gridLayout_3 = new QGridLayout(tab_3);
        gridLayout_3->setObjectName(QStringLiteral("gridLayout_3"));
        tableView_SMV = new QTableView(tab_3);
        tableView_SMV->setObjectName(QStringLiteral("tableView_SMV"));

        gridLayout_3->addWidget(tableView_SMV, 0, 0, 1, 1);

        tabWidget->addTab(tab_3, QString());

        gridLayout_4->addWidget(tabWidget, 0, 0, 1, 1);

        horizontalLayout = new QHBoxLayout();
        horizontalLayout->setObjectName(QStringLiteral("horizontalLayout"));
        horizontalSpacer = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout->addItem(horizontalSpacer);

        pushButton_Apply = new QPushButton(MMSExtra);
        pushButton_Apply->setObjectName(QStringLiteral("pushButton_Apply"));

        horizontalLayout->addWidget(pushButton_Apply);

        horizontalSpacer_2 = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout->addItem(horizontalSpacer_2);

        pushButton_Cancel = new QPushButton(MMSExtra);
        pushButton_Cancel->setObjectName(QStringLiteral("pushButton_Cancel"));

        horizontalLayout->addWidget(pushButton_Cancel);

        horizontalSpacer_3 = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout->addItem(horizontalSpacer_3);


        gridLayout_4->addLayout(horizontalLayout, 1, 0, 1, 1);


        retranslateUi(MMSExtra);

        tabWidget->setCurrentIndex(2);


        QMetaObject::connectSlotsByName(MMSExtra);
    } // setupUi

    void retranslateUi(QDialog *MMSExtra)
    {
        MMSExtra->setWindowTitle(QApplication::translate("MMSExtra", "Dialog", 0));
        tabWidget->setTabText(tabWidget->indexOf(tab), QApplication::translate("MMSExtra", "MMS", 0));
        tabWidget->setTabText(tabWidget->indexOf(tab_2), QApplication::translate("MMSExtra", "GOOSE", 0));
        tabWidget->setTabText(tabWidget->indexOf(tab_3), QApplication::translate("MMSExtra", "SMV", 0));
        pushButton_Apply->setText(QApplication::translate("MMSExtra", "PushButton", 0));
        pushButton_Cancel->setText(QApplication::translate("MMSExtra", "PushButton", 0));
    } // retranslateUi

};

namespace Ui {
    class MMSExtra: public Ui_MMSExtra {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_MMSEXTRA_H
