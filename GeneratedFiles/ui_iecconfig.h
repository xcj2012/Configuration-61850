/********************************************************************************
** Form generated from reading UI file 'iecconfig.ui'
**
** Created by: Qt User Interface Compiler version 5.6.1
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_IECCONFIG_H
#define UI_IECCONFIG_H

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
#include <QtWidgets/QPushButton>
#include <QtWidgets/QRadioButton>
#include <QtWidgets/QSpacerItem>
#include <QtWidgets/QTableView>

QT_BEGIN_NAMESPACE

class Ui_IECCONFIG
{
public:
    QGridLayout *gridLayout_2;
    QHBoxLayout *horizontalLayout;
    QLabel *label;
    QLineEdit *lineEdit;
    QRadioButton *radioButton_new;
    QRadioButton *radioButton_browse;
    QPushButton *pushButton_new;
    QPushButton *pushButton_station;
    QPushButton *pushButton_time;
    QGroupBox *groupBox;
    QGridLayout *gridLayout;
    QTableView *tableView;
    QHBoxLayout *horizontalLayout_2;
    QSpacerItem *horizontalSpacer;
    QPushButton *pushButton_add;
    QPushButton *pushButton_del;
    QPushButton *pushButton_save;

    void setupUi(QDialog *IECCONFIG)
    {
        if (IECCONFIG->objectName().isEmpty())
            IECCONFIG->setObjectName(QStringLiteral("IECCONFIG"));
        IECCONFIG->resize(1043, 600);
        IECCONFIG->setMinimumSize(QSize(800, 600));
        gridLayout_2 = new QGridLayout(IECCONFIG);
        gridLayout_2->setObjectName(QStringLiteral("gridLayout_2"));
        horizontalLayout = new QHBoxLayout();
        horizontalLayout->setObjectName(QStringLiteral("horizontalLayout"));
        label = new QLabel(IECCONFIG);
        label->setObjectName(QStringLiteral("label"));

        horizontalLayout->addWidget(label);

        lineEdit = new QLineEdit(IECCONFIG);
        lineEdit->setObjectName(QStringLiteral("lineEdit"));

        horizontalLayout->addWidget(lineEdit);

        radioButton_new = new QRadioButton(IECCONFIG);
        radioButton_new->setObjectName(QStringLiteral("radioButton_new"));

        horizontalLayout->addWidget(radioButton_new);

        radioButton_browse = new QRadioButton(IECCONFIG);
        radioButton_browse->setObjectName(QStringLiteral("radioButton_browse"));

        horizontalLayout->addWidget(radioButton_browse);

        pushButton_new = new QPushButton(IECCONFIG);
        pushButton_new->setObjectName(QStringLiteral("pushButton_new"));

        horizontalLayout->addWidget(pushButton_new);

        pushButton_station = new QPushButton(IECCONFIG);
        pushButton_station->setObjectName(QStringLiteral("pushButton_station"));
        pushButton_station->setMinimumSize(QSize(0, 0));

        horizontalLayout->addWidget(pushButton_station);

        pushButton_time = new QPushButton(IECCONFIG);
        pushButton_time->setObjectName(QStringLiteral("pushButton_time"));

        horizontalLayout->addWidget(pushButton_time);


        gridLayout_2->addLayout(horizontalLayout, 0, 0, 1, 1);

        groupBox = new QGroupBox(IECCONFIG);
        groupBox->setObjectName(QStringLiteral("groupBox"));
        gridLayout = new QGridLayout(groupBox);
        gridLayout->setObjectName(QStringLiteral("gridLayout"));
        tableView = new QTableView(groupBox);
        tableView->setObjectName(QStringLiteral("tableView"));

        gridLayout->addWidget(tableView, 0, 0, 1, 1);


        gridLayout_2->addWidget(groupBox, 1, 0, 1, 1);

        horizontalLayout_2 = new QHBoxLayout();
        horizontalLayout_2->setObjectName(QStringLiteral("horizontalLayout_2"));
        horizontalSpacer = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout_2->addItem(horizontalSpacer);

        pushButton_add = new QPushButton(IECCONFIG);
        pushButton_add->setObjectName(QStringLiteral("pushButton_add"));

        horizontalLayout_2->addWidget(pushButton_add);

        pushButton_del = new QPushButton(IECCONFIG);
        pushButton_del->setObjectName(QStringLiteral("pushButton_del"));

        horizontalLayout_2->addWidget(pushButton_del);

        pushButton_save = new QPushButton(IECCONFIG);
        pushButton_save->setObjectName(QStringLiteral("pushButton_save"));

        horizontalLayout_2->addWidget(pushButton_save);


        gridLayout_2->addLayout(horizontalLayout_2, 2, 0, 1, 1);


        retranslateUi(IECCONFIG);

        QMetaObject::connectSlotsByName(IECCONFIG);
    } // setupUi

    void retranslateUi(QDialog *IECCONFIG)
    {
        IECCONFIG->setWindowTitle(QApplication::translate("IECCONFIG", "Dialog", 0));
        label->setText(QApplication::translate("IECCONFIG", "TextLabel", 0));
        radioButton_new->setText(QApplication::translate("IECCONFIG", "RadioButton", 0));
        radioButton_browse->setText(QApplication::translate("IECCONFIG", "RadioButton", 0));
        pushButton_new->setText(QApplication::translate("IECCONFIG", "PushButton", 0));
        pushButton_station->setText(QApplication::translate("IECCONFIG", "PushButton", 0));
        pushButton_time->setText(QApplication::translate("IECCONFIG", "PushButton", 0));
        groupBox->setTitle(QApplication::translate("IECCONFIG", "GroupBox", 0));
        pushButton_add->setText(QApplication::translate("IECCONFIG", "PushButton", 0));
        pushButton_del->setText(QApplication::translate("IECCONFIG", "PushButton", 0));
        pushButton_save->setText(QApplication::translate("IECCONFIG", "PushButton", 0));
    } // retranslateUi

};

namespace Ui {
    class IECCONFIG: public Ui_IECCONFIG {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_IECCONFIG_H
