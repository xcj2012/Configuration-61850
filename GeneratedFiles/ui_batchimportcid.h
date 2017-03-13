/********************************************************************************
** Form generated from reading UI file 'batchimportcid.ui'
**
** Created by: Qt User Interface Compiler version 5.6.1
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_BATCHIMPORTCID_H
#define UI_BATCHIMPORTCID_H

#include <QtCore/QVariant>
#include <QtWidgets/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QButtonGroup>
#include <QtWidgets/QDialog>
#include <QtWidgets/QGridLayout>
#include <QtWidgets/QGroupBox>
#include <QtWidgets/QHBoxLayout>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QLabel>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QRadioButton>
#include <QtWidgets/QSpacerItem>
#include <QtWidgets/QTableView>

QT_BEGIN_NAMESPACE

class Ui_BatchImportCID
{
public:
    QGridLayout *gridLayout_2;
    QLabel *label_notice;
    QHBoxLayout *horizontalLayout;
    QLabel *label_IED;
    QPushButton *pushButton_checkAll;
    QPushButton *pushButton_NoAll;
    QRadioButton *radioButton_Skip;
    QSpacerItem *horizontalSpacer;
    QPushButton *pushButton_Import;
    QSpacerItem *horizontalSpacer_2;
    QGroupBox *groupBox;
    QGridLayout *gridLayout;
    QTableView *tableView;

    void setupUi(QDialog *BatchImportCID)
    {
        if (BatchImportCID->objectName().isEmpty())
            BatchImportCID->setObjectName(QStringLiteral("BatchImportCID"));
        BatchImportCID->resize(860, 447);
        gridLayout_2 = new QGridLayout(BatchImportCID);
        gridLayout_2->setObjectName(QStringLiteral("gridLayout_2"));
        label_notice = new QLabel(BatchImportCID);
        label_notice->setObjectName(QStringLiteral("label_notice"));

        gridLayout_2->addWidget(label_notice, 0, 0, 1, 1);

        horizontalLayout = new QHBoxLayout();
        horizontalLayout->setObjectName(QStringLiteral("horizontalLayout"));
        label_IED = new QLabel(BatchImportCID);
        label_IED->setObjectName(QStringLiteral("label_IED"));

        horizontalLayout->addWidget(label_IED);

        pushButton_checkAll = new QPushButton(BatchImportCID);
        pushButton_checkAll->setObjectName(QStringLiteral("pushButton_checkAll"));

        horizontalLayout->addWidget(pushButton_checkAll);

        pushButton_NoAll = new QPushButton(BatchImportCID);
        pushButton_NoAll->setObjectName(QStringLiteral("pushButton_NoAll"));

        horizontalLayout->addWidget(pushButton_NoAll);

        radioButton_Skip = new QRadioButton(BatchImportCID);
        radioButton_Skip->setObjectName(QStringLiteral("radioButton_Skip"));
        radioButton_Skip->setEnabled(false);
        radioButton_Skip->setMouseTracking(true);
        radioButton_Skip->setCheckable(true);
        radioButton_Skip->setChecked(true);

        horizontalLayout->addWidget(radioButton_Skip);

        horizontalSpacer = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout->addItem(horizontalSpacer);

        pushButton_Import = new QPushButton(BatchImportCID);
        pushButton_Import->setObjectName(QStringLiteral("pushButton_Import"));

        horizontalLayout->addWidget(pushButton_Import);

        horizontalSpacer_2 = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout->addItem(horizontalSpacer_2);


        gridLayout_2->addLayout(horizontalLayout, 1, 0, 1, 1);

        groupBox = new QGroupBox(BatchImportCID);
        groupBox->setObjectName(QStringLiteral("groupBox"));
        gridLayout = new QGridLayout(groupBox);
        gridLayout->setObjectName(QStringLiteral("gridLayout"));
        tableView = new QTableView(groupBox);
        tableView->setObjectName(QStringLiteral("tableView"));

        gridLayout->addWidget(tableView, 0, 0, 1, 1);


        gridLayout_2->addWidget(groupBox, 2, 0, 1, 1);


        retranslateUi(BatchImportCID);

        QMetaObject::connectSlotsByName(BatchImportCID);
    } // setupUi

    void retranslateUi(QDialog *BatchImportCID)
    {
        BatchImportCID->setWindowTitle(QApplication::translate("BatchImportCID", "Dialog", 0));
        label_notice->setText(QApplication::translate("BatchImportCID", "TextLabel", 0));
        label_IED->setText(QApplication::translate("BatchImportCID", "TextLabel", 0));
        pushButton_checkAll->setText(QApplication::translate("BatchImportCID", "PushButton", 0));
        pushButton_NoAll->setText(QApplication::translate("BatchImportCID", "PushButton", 0));
        radioButton_Skip->setText(QApplication::translate("BatchImportCID", "RadioButton", 0));
        pushButton_Import->setText(QApplication::translate("BatchImportCID", "PushButton", 0));
        groupBox->setTitle(QApplication::translate("BatchImportCID", "GroupBox", 0));
    } // retranslateUi

};

namespace Ui {
    class BatchImportCID: public Ui_BatchImportCID {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_BATCHIMPORTCID_H
