/********************************************************************************
** Form generated from reading UI file 'logicmap.ui'
**
** Created by: Qt User Interface Compiler version 5.6.1
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_LOGICMAP_H
#define UI_LOGICMAP_H

#include <QtCore/QVariant>
#include <QtWidgets/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QButtonGroup>
#include <QtWidgets/QComboBox>
#include <QtWidgets/QDialog>
#include <QtWidgets/QGridLayout>
#include <QtWidgets/QHBoxLayout>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QLabel>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QRadioButton>
#include <QtWidgets/QSpacerItem>
#include <QtWidgets/QSplitter>
#include <QtWidgets/QTreeWidget>
#include <QtWidgets/QVBoxLayout>
#include <QtWidgets/QWidget>
#include "droptable.h"

QT_BEGIN_NAMESPACE

class Ui_LogicMap
{
public:
    QGridLayout *gridLayout;
    QVBoxLayout *verticalLayout_3;
    QHBoxLayout *horizontalLayout;
    QLabel *label_MAP;
    QLineEdit *lineEdit_MAP;
    QRadioButton *radioButton_new;
    QRadioButton *radioButton_browse;
    QPushButton *pushButton_browse;
    QPushButton *pushButton_save;
    QHBoxLayout *horizontalLayout_2;
    QLabel *label_DB;
    QLineEdit *lineEdit_DB;
    QSpacerItem *horizontalSpacer_3;
    QPushButton *pushButton_Config;
    QPushButton *pushButton_open;
    QSplitter *splitter;
    QWidget *layoutWidget;
    QVBoxLayout *verticalLayout;
    QHBoxLayout *horizontalLayout_3;
    QLabel *label_dev;
    QComboBox *comboBox_dev;
    QLabel *label_type;
    QComboBox *comboBox_type;
    QLabel *label_IED_Type;
    QComboBox *comboBox_IED_Type;
    QPushButton *pushButton_Clear;
    QPushButton *pushButton_Apply;
    QPushButton *pushButton_Del;
    DropTable *dropTable;
    QWidget *layoutWidget1;
    QVBoxLayout *verticalLayout_2;
    QHBoxLayout *horizontalLayout_4;
    QLabel *label_IED;
    QComboBox *comboBox_ied;
    QLabel *label_ld;
    QComboBox *comboBox_ld;
    QTreeWidget *treeWidget;

    void setupUi(QDialog *LogicMap)
    {
        if (LogicMap->objectName().isEmpty())
            LogicMap->setObjectName(QStringLiteral("LogicMap"));
        LogicMap->resize(1040, 612);
        gridLayout = new QGridLayout(LogicMap);
        gridLayout->setObjectName(QStringLiteral("gridLayout"));
        verticalLayout_3 = new QVBoxLayout();
        verticalLayout_3->setObjectName(QStringLiteral("verticalLayout_3"));
        horizontalLayout = new QHBoxLayout();
        horizontalLayout->setObjectName(QStringLiteral("horizontalLayout"));
        label_MAP = new QLabel(LogicMap);
        label_MAP->setObjectName(QStringLiteral("label_MAP"));

        horizontalLayout->addWidget(label_MAP);

        lineEdit_MAP = new QLineEdit(LogicMap);
        lineEdit_MAP->setObjectName(QStringLiteral("lineEdit_MAP"));

        horizontalLayout->addWidget(lineEdit_MAP);

        radioButton_new = new QRadioButton(LogicMap);
        radioButton_new->setObjectName(QStringLiteral("radioButton_new"));

        horizontalLayout->addWidget(radioButton_new);

        radioButton_browse = new QRadioButton(LogicMap);
        radioButton_browse->setObjectName(QStringLiteral("radioButton_browse"));

        horizontalLayout->addWidget(radioButton_browse);

        pushButton_browse = new QPushButton(LogicMap);
        pushButton_browse->setObjectName(QStringLiteral("pushButton_browse"));

        horizontalLayout->addWidget(pushButton_browse);

        pushButton_save = new QPushButton(LogicMap);
        pushButton_save->setObjectName(QStringLiteral("pushButton_save"));

        horizontalLayout->addWidget(pushButton_save);


        verticalLayout_3->addLayout(horizontalLayout);

        horizontalLayout_2 = new QHBoxLayout();
        horizontalLayout_2->setObjectName(QStringLiteral("horizontalLayout_2"));
        label_DB = new QLabel(LogicMap);
        label_DB->setObjectName(QStringLiteral("label_DB"));

        horizontalLayout_2->addWidget(label_DB);

        lineEdit_DB = new QLineEdit(LogicMap);
        lineEdit_DB->setObjectName(QStringLiteral("lineEdit_DB"));

        horizontalLayout_2->addWidget(lineEdit_DB);

        horizontalSpacer_3 = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout_2->addItem(horizontalSpacer_3);

        pushButton_Config = new QPushButton(LogicMap);
        pushButton_Config->setObjectName(QStringLiteral("pushButton_Config"));

        horizontalLayout_2->addWidget(pushButton_Config);

        pushButton_open = new QPushButton(LogicMap);
        pushButton_open->setObjectName(QStringLiteral("pushButton_open"));

        horizontalLayout_2->addWidget(pushButton_open);


        verticalLayout_3->addLayout(horizontalLayout_2);


        gridLayout->addLayout(verticalLayout_3, 0, 0, 1, 1);

        splitter = new QSplitter(LogicMap);
        splitter->setObjectName(QStringLiteral("splitter"));
        splitter->setOrientation(Qt::Horizontal);
        layoutWidget = new QWidget(splitter);
        layoutWidget->setObjectName(QStringLiteral("layoutWidget"));
        verticalLayout = new QVBoxLayout(layoutWidget);
        verticalLayout->setObjectName(QStringLiteral("verticalLayout"));
        verticalLayout->setContentsMargins(0, 0, 0, 0);
        horizontalLayout_3 = new QHBoxLayout();
        horizontalLayout_3->setObjectName(QStringLiteral("horizontalLayout_3"));
        label_dev = new QLabel(layoutWidget);
        label_dev->setObjectName(QStringLiteral("label_dev"));
        label_dev->setMaximumSize(QSize(80, 16777215));

        horizontalLayout_3->addWidget(label_dev);

        comboBox_dev = new QComboBox(layoutWidget);
        comboBox_dev->setObjectName(QStringLiteral("comboBox_dev"));
        comboBox_dev->setMinimumSize(QSize(150, 0));

        horizontalLayout_3->addWidget(comboBox_dev);

        label_type = new QLabel(layoutWidget);
        label_type->setObjectName(QStringLiteral("label_type"));
        label_type->setMaximumSize(QSize(80, 16777215));

        horizontalLayout_3->addWidget(label_type);

        comboBox_type = new QComboBox(layoutWidget);
        comboBox_type->setObjectName(QStringLiteral("comboBox_type"));

        horizontalLayout_3->addWidget(comboBox_type);

        label_IED_Type = new QLabel(layoutWidget);
        label_IED_Type->setObjectName(QStringLiteral("label_IED_Type"));
        QSizePolicy sizePolicy(QSizePolicy::Maximum, QSizePolicy::Preferred);
        sizePolicy.setHorizontalStretch(0);
        sizePolicy.setVerticalStretch(0);
        sizePolicy.setHeightForWidth(label_IED_Type->sizePolicy().hasHeightForWidth());
        label_IED_Type->setSizePolicy(sizePolicy);
        label_IED_Type->setMaximumSize(QSize(80, 16777215));
        label_IED_Type->setSizeIncrement(QSize(80, 0));

        horizontalLayout_3->addWidget(label_IED_Type);

        comboBox_IED_Type = new QComboBox(layoutWidget);
        comboBox_IED_Type->setObjectName(QStringLiteral("comboBox_IED_Type"));

        horizontalLayout_3->addWidget(comboBox_IED_Type);

        pushButton_Clear = new QPushButton(layoutWidget);
        pushButton_Clear->setObjectName(QStringLiteral("pushButton_Clear"));

        horizontalLayout_3->addWidget(pushButton_Clear);

        pushButton_Apply = new QPushButton(layoutWidget);
        pushButton_Apply->setObjectName(QStringLiteral("pushButton_Apply"));

        horizontalLayout_3->addWidget(pushButton_Apply);

        pushButton_Del = new QPushButton(layoutWidget);
        pushButton_Del->setObjectName(QStringLiteral("pushButton_Del"));

        horizontalLayout_3->addWidget(pushButton_Del);


        verticalLayout->addLayout(horizontalLayout_3);

        dropTable = new DropTable(layoutWidget);
        dropTable->setObjectName(QStringLiteral("dropTable"));

        verticalLayout->addWidget(dropTable);

        splitter->addWidget(layoutWidget);
        layoutWidget1 = new QWidget(splitter);
        layoutWidget1->setObjectName(QStringLiteral("layoutWidget1"));
        verticalLayout_2 = new QVBoxLayout(layoutWidget1);
        verticalLayout_2->setObjectName(QStringLiteral("verticalLayout_2"));
        verticalLayout_2->setContentsMargins(0, 0, 0, 0);
        horizontalLayout_4 = new QHBoxLayout();
        horizontalLayout_4->setObjectName(QStringLiteral("horizontalLayout_4"));
        label_IED = new QLabel(layoutWidget1);
        label_IED->setObjectName(QStringLiteral("label_IED"));
        sizePolicy.setHeightForWidth(label_IED->sizePolicy().hasHeightForWidth());
        label_IED->setSizePolicy(sizePolicy);
        label_IED->setMaximumSize(QSize(80, 16777215));
        label_IED->setSizeIncrement(QSize(80, 0));

        horizontalLayout_4->addWidget(label_IED);

        comboBox_ied = new QComboBox(layoutWidget1);
        comboBox_ied->setObjectName(QStringLiteral("comboBox_ied"));

        horizontalLayout_4->addWidget(comboBox_ied);

        label_ld = new QLabel(layoutWidget1);
        label_ld->setObjectName(QStringLiteral("label_ld"));
        sizePolicy.setHeightForWidth(label_ld->sizePolicy().hasHeightForWidth());
        label_ld->setSizePolicy(sizePolicy);
        label_ld->setMaximumSize(QSize(80, 16777215));
        label_ld->setSizeIncrement(QSize(80, 0));

        horizontalLayout_4->addWidget(label_ld);

        comboBox_ld = new QComboBox(layoutWidget1);
        comboBox_ld->setObjectName(QStringLiteral("comboBox_ld"));

        horizontalLayout_4->addWidget(comboBox_ld);


        verticalLayout_2->addLayout(horizontalLayout_4);

        treeWidget = new QTreeWidget(layoutWidget1);
        QTreeWidgetItem *__qtreewidgetitem = new QTreeWidgetItem();
        __qtreewidgetitem->setText(0, QStringLiteral("1"));
        treeWidget->setHeaderItem(__qtreewidgetitem);
        treeWidget->setObjectName(QStringLiteral("treeWidget"));
        treeWidget->setMinimumSize(QSize(0, 500));

        verticalLayout_2->addWidget(treeWidget);

        splitter->addWidget(layoutWidget1);

        gridLayout->addWidget(splitter, 1, 0, 1, 1);


        retranslateUi(LogicMap);

        QMetaObject::connectSlotsByName(LogicMap);
    } // setupUi

    void retranslateUi(QDialog *LogicMap)
    {
        LogicMap->setWindowTitle(QApplication::translate("LogicMap", "Dialog", 0));
        label_MAP->setText(QApplication::translate("LogicMap", "TextLabel", 0));
        radioButton_new->setText(QApplication::translate("LogicMap", "RadioButton", 0));
        radioButton_browse->setText(QApplication::translate("LogicMap", "RadioButton", 0));
        pushButton_browse->setText(QApplication::translate("LogicMap", "PushButton", 0));
        pushButton_save->setText(QApplication::translate("LogicMap", "PushButton", 0));
        label_DB->setText(QApplication::translate("LogicMap", "TextLabel", 0));
        pushButton_Config->setText(QApplication::translate("LogicMap", "PushButton", 0));
        pushButton_open->setText(QApplication::translate("LogicMap", "PushButton", 0));
        label_dev->setText(QApplication::translate("LogicMap", "TextLabel", 0));
        label_type->setText(QApplication::translate("LogicMap", "TextLabel", 0));
        label_IED_Type->setText(QApplication::translate("LogicMap", "TextLabel", 0));
        pushButton_Clear->setText(QApplication::translate("LogicMap", "PushButton", 0));
        pushButton_Apply->setText(QApplication::translate("LogicMap", "PushButton", 0));
        pushButton_Del->setText(QApplication::translate("LogicMap", "PushButton", 0));
        label_IED->setText(QApplication::translate("LogicMap", "TextLabel", 0));
        label_ld->setText(QApplication::translate("LogicMap", "TextLabel", 0));
    } // retranslateUi

};

namespace Ui {
    class LogicMap: public Ui_LogicMap {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_LOGICMAP_H
