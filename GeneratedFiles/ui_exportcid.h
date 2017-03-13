/********************************************************************************
** Form generated from reading UI file 'exportcid.ui'
**
** Created by: Qt User Interface Compiler version 5.6.1
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_EXPORTCID_H
#define UI_EXPORTCID_H

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
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QProgressBar>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QSpacerItem>
#include <QtWidgets/QTableView>

QT_BEGIN_NAMESPACE

class Ui_ExPortCID
{
public:
    QGridLayout *gridLayout_2;
    QHBoxLayout *horizontalLayout_2;
    QLabel *label_Path;
    QLineEdit *lineEdit_Path;
    QPushButton *pushButton_Browse;
    QGroupBox *groupBox;
    QGridLayout *gridLayout;
    QTableView *tableView;
    QProgressBar *progressBar;
    QHBoxLayout *horizontalLayout;
    QPushButton *pushButton_All;
    QPushButton *pushButton_NoAll;
    QSpacerItem *horizontalSpacer;
    QPushButton *pushButton_Apply;
    QPushButton *pushButton_Cancel;

    void setupUi(QDialog *ExPortCID)
    {
        if (ExPortCID->objectName().isEmpty())
            ExPortCID->setObjectName(QStringLiteral("ExPortCID"));
        ExPortCID->resize(825, 379);
        gridLayout_2 = new QGridLayout(ExPortCID);
        gridLayout_2->setObjectName(QStringLiteral("gridLayout_2"));
        horizontalLayout_2 = new QHBoxLayout();
        horizontalLayout_2->setObjectName(QStringLiteral("horizontalLayout_2"));
        label_Path = new QLabel(ExPortCID);
        label_Path->setObjectName(QStringLiteral("label_Path"));

        horizontalLayout_2->addWidget(label_Path);

        lineEdit_Path = new QLineEdit(ExPortCID);
        lineEdit_Path->setObjectName(QStringLiteral("lineEdit_Path"));

        horizontalLayout_2->addWidget(lineEdit_Path);

        pushButton_Browse = new QPushButton(ExPortCID);
        pushButton_Browse->setObjectName(QStringLiteral("pushButton_Browse"));

        horizontalLayout_2->addWidget(pushButton_Browse);


        gridLayout_2->addLayout(horizontalLayout_2, 0, 0, 1, 1);

        groupBox = new QGroupBox(ExPortCID);
        groupBox->setObjectName(QStringLiteral("groupBox"));
        gridLayout = new QGridLayout(groupBox);
        gridLayout->setObjectName(QStringLiteral("gridLayout"));
        tableView = new QTableView(groupBox);
        tableView->setObjectName(QStringLiteral("tableView"));

        gridLayout->addWidget(tableView, 0, 0, 1, 1);


        gridLayout_2->addWidget(groupBox, 1, 0, 1, 1);

        progressBar = new QProgressBar(ExPortCID);
        progressBar->setObjectName(QStringLiteral("progressBar"));
        progressBar->setValue(24);

        gridLayout_2->addWidget(progressBar, 2, 0, 1, 1);

        horizontalLayout = new QHBoxLayout();
        horizontalLayout->setObjectName(QStringLiteral("horizontalLayout"));
        pushButton_All = new QPushButton(ExPortCID);
        pushButton_All->setObjectName(QStringLiteral("pushButton_All"));

        horizontalLayout->addWidget(pushButton_All);

        pushButton_NoAll = new QPushButton(ExPortCID);
        pushButton_NoAll->setObjectName(QStringLiteral("pushButton_NoAll"));

        horizontalLayout->addWidget(pushButton_NoAll);

        horizontalSpacer = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout->addItem(horizontalSpacer);

        pushButton_Apply = new QPushButton(ExPortCID);
        pushButton_Apply->setObjectName(QStringLiteral("pushButton_Apply"));

        horizontalLayout->addWidget(pushButton_Apply);

        pushButton_Cancel = new QPushButton(ExPortCID);
        pushButton_Cancel->setObjectName(QStringLiteral("pushButton_Cancel"));

        horizontalLayout->addWidget(pushButton_Cancel);


        gridLayout_2->addLayout(horizontalLayout, 3, 0, 1, 1);


        retranslateUi(ExPortCID);

        QMetaObject::connectSlotsByName(ExPortCID);
    } // setupUi

    void retranslateUi(QDialog *ExPortCID)
    {
        ExPortCID->setWindowTitle(QApplication::translate("ExPortCID", "Dialog", 0));
        label_Path->setText(QApplication::translate("ExPortCID", "TextLabel", 0));
        pushButton_Browse->setText(QApplication::translate("ExPortCID", "PushButton", 0));
        groupBox->setTitle(QApplication::translate("ExPortCID", "GroupBox", 0));
        pushButton_All->setText(QApplication::translate("ExPortCID", "PushButton", 0));
        pushButton_NoAll->setText(QApplication::translate("ExPortCID", "PushButton", 0));
        pushButton_Apply->setText(QApplication::translate("ExPortCID", "PushButton", 0));
        pushButton_Cancel->setText(QApplication::translate("ExPortCID", "PushButton", 0));
    } // retranslateUi

};

namespace Ui {
    class ExPortCID: public Ui_ExPortCID {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_EXPORTCID_H
