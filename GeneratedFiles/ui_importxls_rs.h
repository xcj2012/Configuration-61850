/********************************************************************************
** Form generated from reading UI file 'importxls_rs.ui'
**
** Created by: Qt User Interface Compiler version 5.6.1
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_IMPORTXLS_RS_H
#define UI_IMPORTXLS_RS_H

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

class Ui_ImportXLS_RS
{
public:
    QGridLayout *gridLayout_2;
    QHBoxLayout *horizontalLayout;
    QSpacerItem *horizontalSpacer;
    QPushButton *pushButton_Apply;
    QPushButton *pushButton_Cancel;
    QTabWidget *tabWidget;
    QWidget *tab;
    QGridLayout *gridLayout;
    QTableView *tableView;
    QLabel *label;

    void setupUi(QDialog *ImportXLS_RS)
    {
        if (ImportXLS_RS->objectName().isEmpty())
            ImportXLS_RS->setObjectName(QStringLiteral("ImportXLS_RS"));
        ImportXLS_RS->resize(692, 531);
        gridLayout_2 = new QGridLayout(ImportXLS_RS);
        gridLayout_2->setSpacing(6);
        gridLayout_2->setContentsMargins(11, 11, 11, 11);
        gridLayout_2->setObjectName(QStringLiteral("gridLayout_2"));
        horizontalLayout = new QHBoxLayout();
        horizontalLayout->setSpacing(6);
        horizontalLayout->setObjectName(QStringLiteral("horizontalLayout"));
        horizontalSpacer = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout->addItem(horizontalSpacer);

        pushButton_Apply = new QPushButton(ImportXLS_RS);
        pushButton_Apply->setObjectName(QStringLiteral("pushButton_Apply"));

        horizontalLayout->addWidget(pushButton_Apply);

        pushButton_Cancel = new QPushButton(ImportXLS_RS);
        pushButton_Cancel->setObjectName(QStringLiteral("pushButton_Cancel"));

        horizontalLayout->addWidget(pushButton_Cancel);

        horizontalLayout->setStretch(0, 6);
        horizontalLayout->setStretch(1, 1);
        horizontalLayout->setStretch(2, 1);

        gridLayout_2->addLayout(horizontalLayout, 2, 0, 1, 1);

        tabWidget = new QTabWidget(ImportXLS_RS);
        tabWidget->setObjectName(QStringLiteral("tabWidget"));
        tab = new QWidget();
        tab->setObjectName(QStringLiteral("tab"));
        gridLayout = new QGridLayout(tab);
        gridLayout->setSpacing(6);
        gridLayout->setContentsMargins(11, 11, 11, 11);
        gridLayout->setObjectName(QStringLiteral("gridLayout"));
        tableView = new QTableView(tab);
        tableView->setObjectName(QStringLiteral("tableView"));

        gridLayout->addWidget(tableView, 0, 0, 1, 1);

        tabWidget->addTab(tab, QString());

        gridLayout_2->addWidget(tabWidget, 1, 0, 1, 1);

        label = new QLabel(ImportXLS_RS);
        label->setObjectName(QStringLiteral("label"));

        gridLayout_2->addWidget(label, 0, 0, 1, 1);


        retranslateUi(ImportXLS_RS);

        tabWidget->setCurrentIndex(0);


        QMetaObject::connectSlotsByName(ImportXLS_RS);
    } // setupUi

    void retranslateUi(QDialog *ImportXLS_RS)
    {
        ImportXLS_RS->setWindowTitle(QApplication::translate("ImportXLS_RS", "ImportXLS_RS", 0));
        pushButton_Apply->setText(QApplication::translate("ImportXLS_RS", "PushButton", 0));
        pushButton_Cancel->setText(QApplication::translate("ImportXLS_RS", "PushButton", 0));
        tabWidget->setTabText(tabWidget->indexOf(tab), QApplication::translate("ImportXLS_RS", "Tab 1", 0));
        label->setText(QString());
    } // retranslateUi

};

namespace Ui {
    class ImportXLS_RS: public Ui_ImportXLS_RS {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_IMPORTXLS_RS_H
