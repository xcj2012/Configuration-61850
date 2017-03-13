/********************************************************************************
** Form generated from reading UI file 'mergescd.ui'
**
** Created by: Qt User Interface Compiler version 5.6.1
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_MERGESCD_H
#define UI_MERGESCD_H

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
#include <QtWidgets/QVBoxLayout>

QT_BEGIN_NAMESPACE

class Ui_MergeSCD
{
public:
    QGridLayout *gridLayout;
    QVBoxLayout *verticalLayout;
    QLabel *label;
    QHBoxLayout *horizontalLayout;
    QLabel *label_Base;
    QLineEdit *lineEdit_Base;
    QPushButton *pushButton_Base;
    QHBoxLayout *horizontalLayout_2;
    QLabel *label_Merge;
    QLineEdit *lineEdit_Merge;
    QPushButton *pushButton_Merge;
    QHBoxLayout *horizontalLayout_3;
    QLabel *label_New;
    QLineEdit *lineEdit_New;
    QPushButton *pushButton_New;
    QHBoxLayout *horizontalLayout_4;
    QSpacerItem *horizontalSpacer;
    QPushButton *pushButton_Apply;
    QPushButton *pushButton_Cancel;

    void setupUi(QDialog *MergeSCD)
    {
        if (MergeSCD->objectName().isEmpty())
            MergeSCD->setObjectName(QStringLiteral("MergeSCD"));
        MergeSCD->setWindowModality(Qt::WindowModal);
        MergeSCD->resize(400, 190);
        MergeSCD->setMinimumSize(QSize(400, 190));
        MergeSCD->setMaximumSize(QSize(400, 190));
        MergeSCD->setBaseSize(QSize(500, 190));
        gridLayout = new QGridLayout(MergeSCD);
        gridLayout->setSpacing(6);
        gridLayout->setContentsMargins(11, 11, 11, 11);
        gridLayout->setObjectName(QStringLiteral("gridLayout"));
        verticalLayout = new QVBoxLayout();
        verticalLayout->setSpacing(6);
        verticalLayout->setObjectName(QStringLiteral("verticalLayout"));
        label = new QLabel(MergeSCD);
        label->setObjectName(QStringLiteral("label"));

        verticalLayout->addWidget(label);

        horizontalLayout = new QHBoxLayout();
        horizontalLayout->setSpacing(6);
        horizontalLayout->setObjectName(QStringLiteral("horizontalLayout"));
        label_Base = new QLabel(MergeSCD);
        label_Base->setObjectName(QStringLiteral("label_Base"));

        horizontalLayout->addWidget(label_Base);

        lineEdit_Base = new QLineEdit(MergeSCD);
        lineEdit_Base->setObjectName(QStringLiteral("lineEdit_Base"));

        horizontalLayout->addWidget(lineEdit_Base);

        pushButton_Base = new QPushButton(MergeSCD);
        pushButton_Base->setObjectName(QStringLiteral("pushButton_Base"));

        horizontalLayout->addWidget(pushButton_Base);

        horizontalLayout->setStretch(0, 1);
        horizontalLayout->setStretch(1, 4);
        horizontalLayout->setStretch(2, 1);

        verticalLayout->addLayout(horizontalLayout);

        horizontalLayout_2 = new QHBoxLayout();
        horizontalLayout_2->setSpacing(6);
        horizontalLayout_2->setObjectName(QStringLiteral("horizontalLayout_2"));
        label_Merge = new QLabel(MergeSCD);
        label_Merge->setObjectName(QStringLiteral("label_Merge"));

        horizontalLayout_2->addWidget(label_Merge);

        lineEdit_Merge = new QLineEdit(MergeSCD);
        lineEdit_Merge->setObjectName(QStringLiteral("lineEdit_Merge"));

        horizontalLayout_2->addWidget(lineEdit_Merge);

        pushButton_Merge = new QPushButton(MergeSCD);
        pushButton_Merge->setObjectName(QStringLiteral("pushButton_Merge"));

        horizontalLayout_2->addWidget(pushButton_Merge);

        horizontalLayout_2->setStretch(0, 1);
        horizontalLayout_2->setStretch(1, 4);
        horizontalLayout_2->setStretch(2, 1);

        verticalLayout->addLayout(horizontalLayout_2);

        horizontalLayout_3 = new QHBoxLayout();
        horizontalLayout_3->setSpacing(6);
        horizontalLayout_3->setObjectName(QStringLiteral("horizontalLayout_3"));
        label_New = new QLabel(MergeSCD);
        label_New->setObjectName(QStringLiteral("label_New"));

        horizontalLayout_3->addWidget(label_New);

        lineEdit_New = new QLineEdit(MergeSCD);
        lineEdit_New->setObjectName(QStringLiteral("lineEdit_New"));

        horizontalLayout_3->addWidget(lineEdit_New);

        pushButton_New = new QPushButton(MergeSCD);
        pushButton_New->setObjectName(QStringLiteral("pushButton_New"));

        horizontalLayout_3->addWidget(pushButton_New);

        horizontalLayout_3->setStretch(0, 1);
        horizontalLayout_3->setStretch(1, 4);
        horizontalLayout_3->setStretch(2, 1);

        verticalLayout->addLayout(horizontalLayout_3);

        horizontalLayout_4 = new QHBoxLayout();
        horizontalLayout_4->setSpacing(6);
        horizontalLayout_4->setObjectName(QStringLiteral("horizontalLayout_4"));
        horizontalSpacer = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout_4->addItem(horizontalSpacer);

        pushButton_Apply = new QPushButton(MergeSCD);
        pushButton_Apply->setObjectName(QStringLiteral("pushButton_Apply"));

        horizontalLayout_4->addWidget(pushButton_Apply);

        pushButton_Cancel = new QPushButton(MergeSCD);
        pushButton_Cancel->setObjectName(QStringLiteral("pushButton_Cancel"));

        horizontalLayout_4->addWidget(pushButton_Cancel);

        horizontalLayout_4->setStretch(0, 4);
        horizontalLayout_4->setStretch(1, 1);
        horizontalLayout_4->setStretch(2, 1);

        verticalLayout->addLayout(horizontalLayout_4);

        verticalLayout->setStretch(0, 1);
        verticalLayout->setStretch(1, 4);
        verticalLayout->setStretch(2, 4);
        verticalLayout->setStretch(3, 4);
        verticalLayout->setStretch(4, 4);

        gridLayout->addLayout(verticalLayout, 0, 0, 1, 1);


        retranslateUi(MergeSCD);

        QMetaObject::connectSlotsByName(MergeSCD);
    } // setupUi

    void retranslateUi(QDialog *MergeSCD)
    {
        MergeSCD->setWindowTitle(QApplication::translate("MergeSCD", "MergeSCD", 0));
        label->setText(QApplication::translate("MergeSCD", "TextLabel", 0));
        label_Base->setText(QApplication::translate("MergeSCD", "TextLabel", 0));
        pushButton_Base->setText(QApplication::translate("MergeSCD", "PushButton", 0));
        label_Merge->setText(QApplication::translate("MergeSCD", "TextLabel", 0));
        pushButton_Merge->setText(QApplication::translate("MergeSCD", "PushButton", 0));
        label_New->setText(QApplication::translate("MergeSCD", "TextLabel", 0));
        pushButton_New->setText(QApplication::translate("MergeSCD", "PushButton", 0));
        pushButton_Apply->setText(QApplication::translate("MergeSCD", "PushButton", 0));
        pushButton_Cancel->setText(QApplication::translate("MergeSCD", "PushButton", 0));
    } // retranslateUi

};

namespace Ui {
    class MergeSCD: public Ui_MergeSCD {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_MERGESCD_H
