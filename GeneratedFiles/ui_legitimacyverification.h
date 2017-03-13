/********************************************************************************
** Form generated from reading UI file 'legitimacyverification.ui'
**
** Created by: Qt User Interface Compiler version 5.6.1
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_LEGITIMACYVERIFICATION_H
#define UI_LEGITIMACYVERIFICATION_H

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
#include <QtWidgets/QTextBrowser>
#include <QtWidgets/QVBoxLayout>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_LegitimacyVerification
{
public:
    QGridLayout *gridLayout;
    QHBoxLayout *horizontalLayout;
    QCheckBox *checkBox_Comm_IED;
    QCheckBox *checkBox_FCDA;
    QCheckBox *checkBox_Inputs;
    QCheckBox *checkBox_Reference;
    QCheckBox *checkBox_Warnning;
    QPushButton *pushButton_check;
    QSplitter *splitter;
    QWidget *widget;
    QVBoxLayout *verticalLayout_5;
    QHBoxLayout *horizontalLayout_2;
    QLabel *label_comm;
    QSpacerItem *horizontalSpacer;
    QTextBrowser *textBrowser_Comm;
    QWidget *widget1;
    QVBoxLayout *verticalLayout_4;
    QHBoxLayout *horizontalLayout_3;
    QLabel *label_Fcda;
    QSpacerItem *horizontalSpacer_2;
    QTextBrowser *textBrowser_Fcda;
    QWidget *widget2;
    QVBoxLayout *verticalLayout_3;
    QHBoxLayout *horizontalLayout_4;
    QLabel *label_receive;
    QSpacerItem *horizontalSpacer_3;
    QTextBrowser *textBrowser_Receive;
    QWidget *widget3;
    QVBoxLayout *verticalLayout;
    QHBoxLayout *horizontalLayout_5;
    QLabel *label_send;
    QSpacerItem *horizontalSpacer_4;
    QTextBrowser *textBrowser_Send;
    QWidget *widget4;
    QVBoxLayout *verticalLayout_2;
    QHBoxLayout *horizontalLayout_6;
    QLabel *label_Reference;
    QSpacerItem *horizontalSpacer_5;
    QTextBrowser *textBrowser_Reference;
    QTextBrowser *textBrowser_Warning;
    QProgressBar *progressBar;

    void setupUi(QDialog *LegitimacyVerification)
    {
        if (LegitimacyVerification->objectName().isEmpty())
            LegitimacyVerification->setObjectName(QStringLiteral("LegitimacyVerification"));
        LegitimacyVerification->resize(891, 723);
        gridLayout = new QGridLayout(LegitimacyVerification);
        gridLayout->setSpacing(6);
        gridLayout->setContentsMargins(11, 11, 11, 11);
        gridLayout->setObjectName(QStringLiteral("gridLayout"));
        horizontalLayout = new QHBoxLayout();
        horizontalLayout->setSpacing(6);
        horizontalLayout->setObjectName(QStringLiteral("horizontalLayout"));
        checkBox_Comm_IED = new QCheckBox(LegitimacyVerification);
        checkBox_Comm_IED->setObjectName(QStringLiteral("checkBox_Comm_IED"));

        horizontalLayout->addWidget(checkBox_Comm_IED);

        checkBox_FCDA = new QCheckBox(LegitimacyVerification);
        checkBox_FCDA->setObjectName(QStringLiteral("checkBox_FCDA"));

        horizontalLayout->addWidget(checkBox_FCDA);

        checkBox_Inputs = new QCheckBox(LegitimacyVerification);
        checkBox_Inputs->setObjectName(QStringLiteral("checkBox_Inputs"));

        horizontalLayout->addWidget(checkBox_Inputs);

        checkBox_Reference = new QCheckBox(LegitimacyVerification);
        checkBox_Reference->setObjectName(QStringLiteral("checkBox_Reference"));

        horizontalLayout->addWidget(checkBox_Reference);

        checkBox_Warnning = new QCheckBox(LegitimacyVerification);
        checkBox_Warnning->setObjectName(QStringLiteral("checkBox_Warnning"));

        horizontalLayout->addWidget(checkBox_Warnning);

        pushButton_check = new QPushButton(LegitimacyVerification);
        pushButton_check->setObjectName(QStringLiteral("pushButton_check"));

        horizontalLayout->addWidget(pushButton_check);


        gridLayout->addLayout(horizontalLayout, 0, 0, 1, 2);

        splitter = new QSplitter(LegitimacyVerification);
        splitter->setObjectName(QStringLiteral("splitter"));
        splitter->setOrientation(Qt::Vertical);
        widget = new QWidget(splitter);
        widget->setObjectName(QStringLiteral("widget"));
        verticalLayout_5 = new QVBoxLayout(widget);
        verticalLayout_5->setSpacing(6);
        verticalLayout_5->setContentsMargins(11, 11, 11, 11);
        verticalLayout_5->setObjectName(QStringLiteral("verticalLayout_5"));
        verticalLayout_5->setContentsMargins(0, 0, 0, 0);
        horizontalLayout_2 = new QHBoxLayout();
        horizontalLayout_2->setSpacing(6);
        horizontalLayout_2->setObjectName(QStringLiteral("horizontalLayout_2"));
        label_comm = new QLabel(widget);
        label_comm->setObjectName(QStringLiteral("label_comm"));

        horizontalLayout_2->addWidget(label_comm);

        horizontalSpacer = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout_2->addItem(horizontalSpacer);


        verticalLayout_5->addLayout(horizontalLayout_2);

        textBrowser_Comm = new QTextBrowser(widget);
        textBrowser_Comm->setObjectName(QStringLiteral("textBrowser_Comm"));

        verticalLayout_5->addWidget(textBrowser_Comm);

        splitter->addWidget(widget);
        widget1 = new QWidget(splitter);
        widget1->setObjectName(QStringLiteral("widget1"));
        verticalLayout_4 = new QVBoxLayout(widget1);
        verticalLayout_4->setSpacing(6);
        verticalLayout_4->setContentsMargins(11, 11, 11, 11);
        verticalLayout_4->setObjectName(QStringLiteral("verticalLayout_4"));
        verticalLayout_4->setContentsMargins(0, 0, 0, 0);
        horizontalLayout_3 = new QHBoxLayout();
        horizontalLayout_3->setSpacing(6);
        horizontalLayout_3->setObjectName(QStringLiteral("horizontalLayout_3"));
        label_Fcda = new QLabel(widget1);
        label_Fcda->setObjectName(QStringLiteral("label_Fcda"));

        horizontalLayout_3->addWidget(label_Fcda);

        horizontalSpacer_2 = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout_3->addItem(horizontalSpacer_2);


        verticalLayout_4->addLayout(horizontalLayout_3);

        textBrowser_Fcda = new QTextBrowser(widget1);
        textBrowser_Fcda->setObjectName(QStringLiteral("textBrowser_Fcda"));

        verticalLayout_4->addWidget(textBrowser_Fcda);

        splitter->addWidget(widget1);
        widget2 = new QWidget(splitter);
        widget2->setObjectName(QStringLiteral("widget2"));
        verticalLayout_3 = new QVBoxLayout(widget2);
        verticalLayout_3->setSpacing(6);
        verticalLayout_3->setContentsMargins(11, 11, 11, 11);
        verticalLayout_3->setObjectName(QStringLiteral("verticalLayout_3"));
        verticalLayout_3->setContentsMargins(0, 0, 0, 0);
        horizontalLayout_4 = new QHBoxLayout();
        horizontalLayout_4->setSpacing(6);
        horizontalLayout_4->setObjectName(QStringLiteral("horizontalLayout_4"));
        label_receive = new QLabel(widget2);
        label_receive->setObjectName(QStringLiteral("label_receive"));

        horizontalLayout_4->addWidget(label_receive);

        horizontalSpacer_3 = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout_4->addItem(horizontalSpacer_3);


        verticalLayout_3->addLayout(horizontalLayout_4);

        textBrowser_Receive = new QTextBrowser(widget2);
        textBrowser_Receive->setObjectName(QStringLiteral("textBrowser_Receive"));

        verticalLayout_3->addWidget(textBrowser_Receive);

        splitter->addWidget(widget2);
        widget3 = new QWidget(splitter);
        widget3->setObjectName(QStringLiteral("widget3"));
        verticalLayout = new QVBoxLayout(widget3);
        verticalLayout->setSpacing(6);
        verticalLayout->setContentsMargins(11, 11, 11, 11);
        verticalLayout->setObjectName(QStringLiteral("verticalLayout"));
        verticalLayout->setContentsMargins(0, 0, 0, 0);
        horizontalLayout_5 = new QHBoxLayout();
        horizontalLayout_5->setSpacing(6);
        horizontalLayout_5->setObjectName(QStringLiteral("horizontalLayout_5"));
        label_send = new QLabel(widget3);
        label_send->setObjectName(QStringLiteral("label_send"));

        horizontalLayout_5->addWidget(label_send);

        horizontalSpacer_4 = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout_5->addItem(horizontalSpacer_4);


        verticalLayout->addLayout(horizontalLayout_5);

        textBrowser_Send = new QTextBrowser(widget3);
        textBrowser_Send->setObjectName(QStringLiteral("textBrowser_Send"));

        verticalLayout->addWidget(textBrowser_Send);

        splitter->addWidget(widget3);
        widget4 = new QWidget(splitter);
        widget4->setObjectName(QStringLiteral("widget4"));
        verticalLayout_2 = new QVBoxLayout(widget4);
        verticalLayout_2->setSpacing(6);
        verticalLayout_2->setContentsMargins(11, 11, 11, 11);
        verticalLayout_2->setObjectName(QStringLiteral("verticalLayout_2"));
        verticalLayout_2->setContentsMargins(0, 0, 0, 0);
        horizontalLayout_6 = new QHBoxLayout();
        horizontalLayout_6->setSpacing(6);
        horizontalLayout_6->setObjectName(QStringLiteral("horizontalLayout_6"));
        label_Reference = new QLabel(widget4);
        label_Reference->setObjectName(QStringLiteral("label_Reference"));

        horizontalLayout_6->addWidget(label_Reference);

        horizontalSpacer_5 = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout_6->addItem(horizontalSpacer_5);


        verticalLayout_2->addLayout(horizontalLayout_6);

        textBrowser_Reference = new QTextBrowser(widget4);
        textBrowser_Reference->setObjectName(QStringLiteral("textBrowser_Reference"));

        verticalLayout_2->addWidget(textBrowser_Reference);

        splitter->addWidget(widget4);
        textBrowser_Warning = new QTextBrowser(splitter);
        textBrowser_Warning->setObjectName(QStringLiteral("textBrowser_Warning"));
        splitter->addWidget(textBrowser_Warning);

        gridLayout->addWidget(splitter, 1, 0, 2, 2);

        progressBar = new QProgressBar(LegitimacyVerification);
        progressBar->setObjectName(QStringLiteral("progressBar"));
        progressBar->setValue(24);

        gridLayout->addWidget(progressBar, 2, 1, 1, 1);


        retranslateUi(LegitimacyVerification);

        QMetaObject::connectSlotsByName(LegitimacyVerification);
    } // setupUi

    void retranslateUi(QDialog *LegitimacyVerification)
    {
        LegitimacyVerification->setWindowTitle(QApplication::translate("LegitimacyVerification", "LegitimacyVerification", 0));
        checkBox_Comm_IED->setText(QApplication::translate("LegitimacyVerification", "CheckBox", 0));
        checkBox_FCDA->setText(QApplication::translate("LegitimacyVerification", "CheckBox", 0));
        checkBox_Inputs->setText(QApplication::translate("LegitimacyVerification", "CheckBox", 0));
        checkBox_Reference->setText(QApplication::translate("LegitimacyVerification", "CheckBox", 0));
        checkBox_Warnning->setText(QApplication::translate("LegitimacyVerification", "CheckBox", 0));
        pushButton_check->setText(QApplication::translate("LegitimacyVerification", "PushButton", 0));
        label_comm->setText(QApplication::translate("LegitimacyVerification", "TextLabel", 0));
        label_Fcda->setText(QApplication::translate("LegitimacyVerification", "TextLabel", 0));
        label_receive->setText(QApplication::translate("LegitimacyVerification", "TextLabel", 0));
        label_send->setText(QApplication::translate("LegitimacyVerification", "TextLabel", 0));
        label_Reference->setText(QApplication::translate("LegitimacyVerification", "TextLabel", 0));
    } // retranslateUi

};

namespace Ui {
    class LegitimacyVerification: public Ui_LegitimacyVerification {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_LEGITIMACYVERIFICATION_H
