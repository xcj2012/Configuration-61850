/********************************************************************************
** Form generated from reading UI file 'mergecompare.ui'
**
** Created by: Qt User Interface Compiler version 5.6.1
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_MERGECOMPARE_H
#define UI_MERGECOMPARE_H

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
#include <QtWidgets/QTableView>
#include <QtWidgets/QVBoxLayout>

QT_BEGIN_NAMESPACE

class Ui_MergeCompare
{
public:
    QGridLayout *gridLayout;
    QVBoxLayout *verticalLayout;
    QLabel *label;
    QTableView *tableView;
    QHBoxLayout *horizontalLayout;
    QSpacerItem *horizontalSpacer;
    QPushButton *pushButton_Apply;
    QPushButton *pushButton_Cancel;

    void setupUi(QDialog *MergeCompare)
    {
        if (MergeCompare->objectName().isEmpty())
            MergeCompare->setObjectName(QStringLiteral("MergeCompare"));
        MergeCompare->resize(576, 394);
        gridLayout = new QGridLayout(MergeCompare);
        gridLayout->setSpacing(6);
        gridLayout->setContentsMargins(11, 11, 11, 11);
        gridLayout->setObjectName(QStringLiteral("gridLayout"));
        verticalLayout = new QVBoxLayout();
        verticalLayout->setSpacing(6);
        verticalLayout->setObjectName(QStringLiteral("verticalLayout"));
        label = new QLabel(MergeCompare);
        label->setObjectName(QStringLiteral("label"));

        verticalLayout->addWidget(label);

        tableView = new QTableView(MergeCompare);
        tableView->setObjectName(QStringLiteral("tableView"));

        verticalLayout->addWidget(tableView);

        horizontalLayout = new QHBoxLayout();
        horizontalLayout->setSpacing(6);
        horizontalLayout->setObjectName(QStringLiteral("horizontalLayout"));
        horizontalSpacer = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout->addItem(horizontalSpacer);

        pushButton_Apply = new QPushButton(MergeCompare);
        pushButton_Apply->setObjectName(QStringLiteral("pushButton_Apply"));

        horizontalLayout->addWidget(pushButton_Apply);

        pushButton_Cancel = new QPushButton(MergeCompare);
        pushButton_Cancel->setObjectName(QStringLiteral("pushButton_Cancel"));

        horizontalLayout->addWidget(pushButton_Cancel);


        verticalLayout->addLayout(horizontalLayout);


        gridLayout->addLayout(verticalLayout, 0, 0, 1, 1);


        retranslateUi(MergeCompare);

        QMetaObject::connectSlotsByName(MergeCompare);
    } // setupUi

    void retranslateUi(QDialog *MergeCompare)
    {
        MergeCompare->setWindowTitle(QApplication::translate("MergeCompare", "MergeCompare", 0));
        label->setText(QString());
        pushButton_Apply->setText(QApplication::translate("MergeCompare", "PushButton", 0));
        pushButton_Cancel->setText(QApplication::translate("MergeCompare", "PushButton", 0));
    } // retranslateUi

};

namespace Ui {
    class MergeCompare: public Ui_MergeCompare {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_MERGECOMPARE_H
