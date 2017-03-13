/********************************************************************************
** Form generated from reading UI file 'terminaltypecheck.ui'
**
** Created by: Qt User Interface Compiler version 5.6.1
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_TERMINALTYPECHECK_H
#define UI_TERMINALTYPECHECK_H

#include <QtCore/QVariant>
#include <QtWidgets/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QButtonGroup>
#include <QtWidgets/QCheckBox>
#include <QtWidgets/QDialog>
#include <QtWidgets/QGridLayout>
#include <QtWidgets/QHBoxLayout>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QLabel>
#include <QtWidgets/QProgressBar>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QSpacerItem>
#include <QtWidgets/QSplitter>
#include <QtWidgets/QTableView>
#include <QtWidgets/QTextBrowser>
#include <QtWidgets/QVBoxLayout>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_TerminalTypeCheck
{
public:
    QGridLayout *gridLayout;
    QSplitter *splitter;
    QWidget *layoutWidget;
    QVBoxLayout *verticalLayout;
    QHBoxLayout *horizontalLayout_2;
    QLabel *label;
    QPushButton *pushButton_All;
    QPushButton *pushButton_NoAll;
    QTableView *tableView;
    QWidget *widget;
    QVBoxLayout *verticalLayout_2;
    QHBoxLayout *horizontalLayout_3;
    QCheckBox *checkBox;
    QSpacerItem *horizontalSpacer_3;
    QTextBrowser *textBrowser;
    QProgressBar *progressBar;
    QHBoxLayout *horizontalLayout;
    QSpacerItem *horizontalSpacer;
    QPushButton *pushButton_Check;
    QSpacerItem *horizontalSpacer_2;

    void setupUi(QDialog *TerminalTypeCheck)
    {
        if (TerminalTypeCheck->objectName().isEmpty())
            TerminalTypeCheck->setObjectName(QStringLiteral("TerminalTypeCheck"));
        TerminalTypeCheck->resize(696, 360);
        gridLayout = new QGridLayout(TerminalTypeCheck);
        gridLayout->setObjectName(QStringLiteral("gridLayout"));
        splitter = new QSplitter(TerminalTypeCheck);
        splitter->setObjectName(QStringLiteral("splitter"));
        splitter->setOrientation(Qt::Horizontal);
        layoutWidget = new QWidget(splitter);
        layoutWidget->setObjectName(QStringLiteral("layoutWidget"));
        verticalLayout = new QVBoxLayout(layoutWidget);
        verticalLayout->setObjectName(QStringLiteral("verticalLayout"));
        verticalLayout->setContentsMargins(0, 0, 0, 0);
        horizontalLayout_2 = new QHBoxLayout();
        horizontalLayout_2->setObjectName(QStringLiteral("horizontalLayout_2"));
        label = new QLabel(layoutWidget);
        label->setObjectName(QStringLiteral("label"));

        horizontalLayout_2->addWidget(label);

        pushButton_All = new QPushButton(layoutWidget);
        pushButton_All->setObjectName(QStringLiteral("pushButton_All"));

        horizontalLayout_2->addWidget(pushButton_All);

        pushButton_NoAll = new QPushButton(layoutWidget);
        pushButton_NoAll->setObjectName(QStringLiteral("pushButton_NoAll"));

        horizontalLayout_2->addWidget(pushButton_NoAll);


        verticalLayout->addLayout(horizontalLayout_2);

        tableView = new QTableView(layoutWidget);
        tableView->setObjectName(QStringLiteral("tableView"));

        verticalLayout->addWidget(tableView);

        splitter->addWidget(layoutWidget);
        widget = new QWidget(splitter);
        widget->setObjectName(QStringLiteral("widget"));
        verticalLayout_2 = new QVBoxLayout(widget);
        verticalLayout_2->setObjectName(QStringLiteral("verticalLayout_2"));
        verticalLayout_2->setContentsMargins(0, 0, 0, 0);
        horizontalLayout_3 = new QHBoxLayout();
        horizontalLayout_3->setObjectName(QStringLiteral("horizontalLayout_3"));
        checkBox = new QCheckBox(widget);
        checkBox->setObjectName(QStringLiteral("checkBox"));

        horizontalLayout_3->addWidget(checkBox);

        horizontalSpacer_3 = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout_3->addItem(horizontalSpacer_3);


        verticalLayout_2->addLayout(horizontalLayout_3);

        textBrowser = new QTextBrowser(widget);
        textBrowser->setObjectName(QStringLiteral("textBrowser"));

        verticalLayout_2->addWidget(textBrowser);

        progressBar = new QProgressBar(widget);
        progressBar->setObjectName(QStringLiteral("progressBar"));
        progressBar->setValue(24);

        verticalLayout_2->addWidget(progressBar);

        horizontalLayout = new QHBoxLayout();
        horizontalLayout->setObjectName(QStringLiteral("horizontalLayout"));
        horizontalSpacer = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout->addItem(horizontalSpacer);

        pushButton_Check = new QPushButton(widget);
        pushButton_Check->setObjectName(QStringLiteral("pushButton_Check"));

        horizontalLayout->addWidget(pushButton_Check);

        horizontalSpacer_2 = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout->addItem(horizontalSpacer_2);


        verticalLayout_2->addLayout(horizontalLayout);

        splitter->addWidget(widget);

        gridLayout->addWidget(splitter, 0, 0, 1, 1);

        splitter->raise();
        progressBar->raise();
        pushButton_Check->raise();

        retranslateUi(TerminalTypeCheck);

        QMetaObject::connectSlotsByName(TerminalTypeCheck);
    } // setupUi

    void retranslateUi(QDialog *TerminalTypeCheck)
    {
        TerminalTypeCheck->setWindowTitle(QApplication::translate("TerminalTypeCheck", "Dialog", 0));
        label->setText(QApplication::translate("TerminalTypeCheck", "TextLabel", 0));
        pushButton_All->setText(QApplication::translate("TerminalTypeCheck", "PushButton", 0));
        pushButton_NoAll->setText(QApplication::translate("TerminalTypeCheck", "PushButton", 0));
        checkBox->setText(QApplication::translate("TerminalTypeCheck", "CheckBox", 0));
        pushButton_Check->setText(QApplication::translate("TerminalTypeCheck", "PushButton", 0));
    } // retranslateUi

};

namespace Ui {
    class TerminalTypeCheck: public Ui_TerminalTypeCheck {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_TERMINALTYPECHECK_H
