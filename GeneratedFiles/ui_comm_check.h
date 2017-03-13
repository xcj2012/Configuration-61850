/********************************************************************************
** Form generated from reading UI file 'comm_check.ui'
**
** Created by: Qt User Interface Compiler version 5.6.1
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_COMM_CHECK_H
#define UI_COMM_CHECK_H

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
#include <QtWidgets/QTextEdit>

QT_BEGIN_NAMESPACE

class Ui_Comm_check
{
public:
    QGridLayout *gridLayout;
    QHBoxLayout *horizontalLayout;
    QLabel *label;
    QSpacerItem *horizontalSpacer;
    QPushButton *pushButton_Check;
    QTextEdit *textEdit;

    void setupUi(QDialog *Comm_check)
    {
        if (Comm_check->objectName().isEmpty())
            Comm_check->setObjectName(QStringLiteral("Comm_check"));
        Comm_check->resize(593, 406);
        gridLayout = new QGridLayout(Comm_check);
        gridLayout->setObjectName(QStringLiteral("gridLayout"));
        horizontalLayout = new QHBoxLayout();
        horizontalLayout->setObjectName(QStringLiteral("horizontalLayout"));
        label = new QLabel(Comm_check);
        label->setObjectName(QStringLiteral("label"));

        horizontalLayout->addWidget(label);

        horizontalSpacer = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout->addItem(horizontalSpacer);

        pushButton_Check = new QPushButton(Comm_check);
        pushButton_Check->setObjectName(QStringLiteral("pushButton_Check"));

        horizontalLayout->addWidget(pushButton_Check);


        gridLayout->addLayout(horizontalLayout, 0, 0, 1, 1);

        textEdit = new QTextEdit(Comm_check);
        textEdit->setObjectName(QStringLiteral("textEdit"));

        gridLayout->addWidget(textEdit, 1, 0, 1, 1);


        retranslateUi(Comm_check);

        QMetaObject::connectSlotsByName(Comm_check);
    } // setupUi

    void retranslateUi(QDialog *Comm_check)
    {
        Comm_check->setWindowTitle(QApplication::translate("Comm_check", "Dialog", 0));
        label->setText(QApplication::translate("Comm_check", "TextLabel", 0));
        pushButton_Check->setText(QApplication::translate("Comm_check", "PushButton", 0));
    } // retranslateUi

};

namespace Ui {
    class Comm_check: public Ui_Comm_check {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_COMM_CHECK_H
