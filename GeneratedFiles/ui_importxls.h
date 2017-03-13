/********************************************************************************
** Form generated from reading UI file 'importxls.ui'
**
** Created by: Qt User Interface Compiler version 5.6.1
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_IMPORTXLS_H
#define UI_IMPORTXLS_H

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

class Ui_ImportXLS
{
public:
    QGridLayout *gridLayout;
    QHBoxLayout *horizontalLayout;
    QLabel *label_Path;
    QLineEdit *lineEdit_Path;
    QPushButton *pushButton_Browse;
    QTableView *tableView;
    QHBoxLayout *horizontalLayout_2;
    QSpacerItem *horizontalSpacer;
    QPushButton *pushButton_Ok;
    QPushButton *pushButton_Cancel;

    void setupUi(QDialog *ImportXLS)
    {
        if (ImportXLS->objectName().isEmpty())
            ImportXLS->setObjectName(QStringLiteral("ImportXLS"));
        ImportXLS->resize(472, 305);
        gridLayout = new QGridLayout(ImportXLS);
        gridLayout->setSpacing(6);
        gridLayout->setContentsMargins(11, 11, 11, 11);
        gridLayout->setObjectName(QStringLiteral("gridLayout"));
        horizontalLayout = new QHBoxLayout();
        horizontalLayout->setSpacing(6);
        horizontalLayout->setObjectName(QStringLiteral("horizontalLayout"));
        label_Path = new QLabel(ImportXLS);
        label_Path->setObjectName(QStringLiteral("label_Path"));

        horizontalLayout->addWidget(label_Path);

        lineEdit_Path = new QLineEdit(ImportXLS);
        lineEdit_Path->setObjectName(QStringLiteral("lineEdit_Path"));

        horizontalLayout->addWidget(lineEdit_Path);

        pushButton_Browse = new QPushButton(ImportXLS);
        pushButton_Browse->setObjectName(QStringLiteral("pushButton_Browse"));

        horizontalLayout->addWidget(pushButton_Browse);

        horizontalLayout->setStretch(0, 1);
        horizontalLayout->setStretch(1, 5);
        horizontalLayout->setStretch(2, 1);

        gridLayout->addLayout(horizontalLayout, 0, 0, 1, 1);

        tableView = new QTableView(ImportXLS);
        tableView->setObjectName(QStringLiteral("tableView"));

        gridLayout->addWidget(tableView, 1, 0, 1, 1);

        horizontalLayout_2 = new QHBoxLayout();
        horizontalLayout_2->setSpacing(6);
        horizontalLayout_2->setObjectName(QStringLiteral("horizontalLayout_2"));
        horizontalLayout_2->setContentsMargins(-1, -1, -1, 0);
        horizontalSpacer = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout_2->addItem(horizontalSpacer);

        pushButton_Ok = new QPushButton(ImportXLS);
        pushButton_Ok->setObjectName(QStringLiteral("pushButton_Ok"));

        horizontalLayout_2->addWidget(pushButton_Ok);

        pushButton_Cancel = new QPushButton(ImportXLS);
        pushButton_Cancel->setObjectName(QStringLiteral("pushButton_Cancel"));

        horizontalLayout_2->addWidget(pushButton_Cancel);

        horizontalLayout_2->setStretch(0, 5);
        horizontalLayout_2->setStretch(1, 1);
        horizontalLayout_2->setStretch(2, 1);

        gridLayout->addLayout(horizontalLayout_2, 2, 0, 1, 1);


        retranslateUi(ImportXLS);

        QMetaObject::connectSlotsByName(ImportXLS);
    } // setupUi

    void retranslateUi(QDialog *ImportXLS)
    {
        ImportXLS->setWindowTitle(QApplication::translate("ImportXLS", "ImportXLS", 0));
        label_Path->setText(QApplication::translate("ImportXLS", "TextLabel", 0));
        pushButton_Browse->setText(QApplication::translate("ImportXLS", "PushButton", 0));
        pushButton_Ok->setText(QApplication::translate("ImportXLS", "PushButton", 0));
        pushButton_Cancel->setText(QApplication::translate("ImportXLS", "PushButton", 0));
    } // retranslateUi

};

namespace Ui {
    class ImportXLS: public Ui_ImportXLS {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_IMPORTXLS_H
