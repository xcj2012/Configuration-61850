/********************************************************************************
** Form generated from reading UI file 'mainwindow.ui'
**
** Created by: Qt User Interface Compiler version 5.6.1
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_MAINWINDOW_H
#define UI_MAINWINDOW_H

#include <QtCore/QVariant>
#include <QtWidgets/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QButtonGroup>
#include <QtWidgets/QCheckBox>
#include <QtWidgets/QComboBox>
#include <QtWidgets/QFrame>
#include <QtWidgets/QGridLayout>
#include <QtWidgets/QHBoxLayout>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QLabel>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QMainWindow>
#include <QtWidgets/QMenu>
#include <QtWidgets/QMenuBar>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QSplitter>
#include <QtWidgets/QStatusBar>
#include <QtWidgets/QTableView>
#include <QtWidgets/QTextBrowser>
#include <QtWidgets/QToolBar>
#include <QtWidgets/QTreeWidget>
#include <QtWidgets/QVBoxLayout>
#include <QtWidgets/QWidget>
#include "droptable.h"

QT_BEGIN_NAMESPACE

class Ui_MainWindow
{
public:
    QAction *actionNew;
    QAction *actionOpen;
    QAction *actionSave;
    QAction *actionSave_as;
    QAction *actionExit;
    QAction *actionLoad_DB;
    QAction *actionAuto_Set_MMS;
    QAction *actionAuto_Set_GOOSE;
    QAction *actionAuto_Set_SMV;
    QAction *actionInit_Set_Communication;
    QAction *actionAuto_Add_Control_block;
    QAction *actionDel_All_Virtual_terminal_Map;
    QAction *action_Communication_verification;
    QAction *actionFile_integrity_check;
    QAction *actionModel_validation_check;
    QAction *actionModel_schema2_0_check;
    QAction *actionCID;
    QAction *action_terminals_Type_check;
    QAction *actionThe_virtual_terminal_in_the_interval_contains_the_check;
    QAction *actionImport_CID;
    QAction *actionImport_ICD;
    QAction *actionImport_SSD;
    QAction *actionExprot_CID;
    QAction *actionExport_Virtual_terminal;
    QAction *actionExport_Virtual_terminal_MAp;
    QAction *actionExport_IEC_Conifig;
    QAction *actionExport_MAP;
    QAction *actionHelp;
    QAction *actionAbout;
    QAction *actionConfig;
    QAction *actionImport_Map;
    QAction *actionMerge_SCD;
    QAction *actionSwtich_Chinese;
    QAction *actionSwitch_English;
    QWidget *centralWidget;
    QGridLayout *gridLayout_2;
    QSplitter *splitter_3;
    QSplitter *splitter_2;
    QWidget *layoutWidget;
    QVBoxLayout *verticalLayout;
    QTreeWidget *SCLTree;
    QSplitter *splitter;
    QWidget *layoutWidget1;
    QVBoxLayout *verticalLayout_3;
    QHBoxLayout *horizontalLayout;
    QVBoxLayout *verticalLayout_2;
    QHBoxLayout *horizontalLayout_5;
    QHBoxLayout *horizontalLayout_3;
    QLabel *label_LD;
    QComboBox *comboBox_LD;
    QHBoxLayout *horizontalLayout_4;
    QLabel *label_LN;
    QComboBox *comboBox_LN;
    DropTable *tableView;
    QTreeWidget *SubstationTree;
    QHBoxLayout *horizontalLayout_2;
    QPushButton *pushButton_Addres;
    QPushButton *pushButton_GSE;
    QPushButton *pushButton_SMV;
    QPushButton *Button_LogicDevice;
    QPushButton *Button_LogiceNode;
    QPushButton *Button_DataSet;
    QPushButton *Button_GSE;
    QPushButton *Button_SMV;
    QPushButton *Button_Input;
    QPushButton *Button_Report;
    QPushButton *Button_Log;
    QPushButton *Button_Add;
    QPushButton *Button_Del;
    QTableView *tableView_data;
    QFrame *frame;
    QGridLayout *gridLayout_3;
    QHBoxLayout *horizontalLayout_6;
    QLabel *label_LN_C;
    QLineEdit *lineEdit_LN;
    QCheckBox *checkBox_DA;
    QGridLayout *gridLayout;
    QHBoxLayout *horizontalLayout_7;
    QLabel *label_DA;
    QLineEdit *lineEdit_DA;
    QCheckBox *checkBox_DA_END;
    QHBoxLayout *horizontalLayout_8;
    QLabel *label_AP;
    QComboBox *comboBox_AP;
    QLabel *label_FC;
    QComboBox *comboBox_FC;
    QHBoxLayout *horizontalLayout_9;
    QCheckBox *checkBox_Disp;
    QPushButton *pushButton_fresh;
    QTreeWidget *IEDTree;
    QTextBrowser *textBrowser;
    QLabel *label_Info;
    QMenuBar *menuBar;
    QMenu *menu_File;
    QMenu *menu_Function;
    QMenu *menu_Import;
    QMenu *menu_Export;
    QMenu *menu_Config;
    QMenu *menu_About;
    QMenu *menu_Check;
    QToolBar *mainToolBar;
    QStatusBar *statusBar;

    void setupUi(QMainWindow *MainWindow)
    {
        if (MainWindow->objectName().isEmpty())
            MainWindow->setObjectName(QStringLiteral("MainWindow"));
        MainWindow->resize(1440, 750);
        actionNew = new QAction(MainWindow);
        actionNew->setObjectName(QStringLiteral("actionNew"));
        actionOpen = new QAction(MainWindow);
        actionOpen->setObjectName(QStringLiteral("actionOpen"));
        actionSave = new QAction(MainWindow);
        actionSave->setObjectName(QStringLiteral("actionSave"));
        actionSave_as = new QAction(MainWindow);
        actionSave_as->setObjectName(QStringLiteral("actionSave_as"));
        actionExit = new QAction(MainWindow);
        actionExit->setObjectName(QStringLiteral("actionExit"));
        actionLoad_DB = new QAction(MainWindow);
        actionLoad_DB->setObjectName(QStringLiteral("actionLoad_DB"));
        actionAuto_Set_MMS = new QAction(MainWindow);
        actionAuto_Set_MMS->setObjectName(QStringLiteral("actionAuto_Set_MMS"));
        actionAuto_Set_GOOSE = new QAction(MainWindow);
        actionAuto_Set_GOOSE->setObjectName(QStringLiteral("actionAuto_Set_GOOSE"));
        actionAuto_Set_SMV = new QAction(MainWindow);
        actionAuto_Set_SMV->setObjectName(QStringLiteral("actionAuto_Set_SMV"));
        actionInit_Set_Communication = new QAction(MainWindow);
        actionInit_Set_Communication->setObjectName(QStringLiteral("actionInit_Set_Communication"));
        actionAuto_Add_Control_block = new QAction(MainWindow);
        actionAuto_Add_Control_block->setObjectName(QStringLiteral("actionAuto_Add_Control_block"));
        actionDel_All_Virtual_terminal_Map = new QAction(MainWindow);
        actionDel_All_Virtual_terminal_Map->setObjectName(QStringLiteral("actionDel_All_Virtual_terminal_Map"));
        action_Communication_verification = new QAction(MainWindow);
        action_Communication_verification->setObjectName(QStringLiteral("action_Communication_verification"));
        actionFile_integrity_check = new QAction(MainWindow);
        actionFile_integrity_check->setObjectName(QStringLiteral("actionFile_integrity_check"));
        actionModel_validation_check = new QAction(MainWindow);
        actionModel_validation_check->setObjectName(QStringLiteral("actionModel_validation_check"));
        actionModel_schema2_0_check = new QAction(MainWindow);
        actionModel_schema2_0_check->setObjectName(QStringLiteral("actionModel_schema2_0_check"));
        actionCID = new QAction(MainWindow);
        actionCID->setObjectName(QStringLiteral("actionCID"));
        action_terminals_Type_check = new QAction(MainWindow);
        action_terminals_Type_check->setObjectName(QStringLiteral("action_terminals_Type_check"));
        actionThe_virtual_terminal_in_the_interval_contains_the_check = new QAction(MainWindow);
        actionThe_virtual_terminal_in_the_interval_contains_the_check->setObjectName(QStringLiteral("actionThe_virtual_terminal_in_the_interval_contains_the_check"));
        actionImport_CID = new QAction(MainWindow);
        actionImport_CID->setObjectName(QStringLiteral("actionImport_CID"));
        actionImport_ICD = new QAction(MainWindow);
        actionImport_ICD->setObjectName(QStringLiteral("actionImport_ICD"));
        actionImport_SSD = new QAction(MainWindow);
        actionImport_SSD->setObjectName(QStringLiteral("actionImport_SSD"));
        actionImport_SSD->setEnabled(false);
        actionImport_SSD->setVisible(true);
        actionExprot_CID = new QAction(MainWindow);
        actionExprot_CID->setObjectName(QStringLiteral("actionExprot_CID"));
        actionExport_Virtual_terminal = new QAction(MainWindow);
        actionExport_Virtual_terminal->setObjectName(QStringLiteral("actionExport_Virtual_terminal"));
        actionExport_Virtual_terminal_MAp = new QAction(MainWindow);
        actionExport_Virtual_terminal_MAp->setObjectName(QStringLiteral("actionExport_Virtual_terminal_MAp"));
        actionExport_IEC_Conifig = new QAction(MainWindow);
        actionExport_IEC_Conifig->setObjectName(QStringLiteral("actionExport_IEC_Conifig"));
        actionExport_MAP = new QAction(MainWindow);
        actionExport_MAP->setObjectName(QStringLiteral("actionExport_MAP"));
        actionHelp = new QAction(MainWindow);
        actionHelp->setObjectName(QStringLiteral("actionHelp"));
        actionAbout = new QAction(MainWindow);
        actionAbout->setObjectName(QStringLiteral("actionAbout"));
        actionConfig = new QAction(MainWindow);
        actionConfig->setObjectName(QStringLiteral("actionConfig"));
        actionImport_Map = new QAction(MainWindow);
        actionImport_Map->setObjectName(QStringLiteral("actionImport_Map"));
        actionMerge_SCD = new QAction(MainWindow);
        actionMerge_SCD->setObjectName(QStringLiteral("actionMerge_SCD"));
        actionSwtich_Chinese = new QAction(MainWindow);
        actionSwtich_Chinese->setObjectName(QStringLiteral("actionSwtich_Chinese"));
        actionSwitch_English = new QAction(MainWindow);
        actionSwitch_English->setObjectName(QStringLiteral("actionSwitch_English"));
        centralWidget = new QWidget(MainWindow);
        centralWidget->setObjectName(QStringLiteral("centralWidget"));
        gridLayout_2 = new QGridLayout(centralWidget);
        gridLayout_2->setSpacing(6);
        gridLayout_2->setContentsMargins(11, 11, 11, 11);
        gridLayout_2->setObjectName(QStringLiteral("gridLayout_2"));
        splitter_3 = new QSplitter(centralWidget);
        splitter_3->setObjectName(QStringLiteral("splitter_3"));
        splitter_3->setOrientation(Qt::Vertical);
        splitter_2 = new QSplitter(splitter_3);
        splitter_2->setObjectName(QStringLiteral("splitter_2"));
        splitter_2->setOrientation(Qt::Horizontal);
        layoutWidget = new QWidget(splitter_2);
        layoutWidget->setObjectName(QStringLiteral("layoutWidget"));
        verticalLayout = new QVBoxLayout(layoutWidget);
        verticalLayout->setSpacing(6);
        verticalLayout->setContentsMargins(11, 11, 11, 11);
        verticalLayout->setObjectName(QStringLiteral("verticalLayout"));
        verticalLayout->setContentsMargins(0, 0, 0, 0);
        SCLTree = new QTreeWidget(layoutWidget);
        QTreeWidgetItem *__qtreewidgetitem = new QTreeWidgetItem();
        __qtreewidgetitem->setText(0, QStringLiteral("1"));
        SCLTree->setHeaderItem(__qtreewidgetitem);
        SCLTree->setObjectName(QStringLiteral("SCLTree"));
        SCLTree->setContextMenuPolicy(Qt::CustomContextMenu);

        verticalLayout->addWidget(SCLTree);

        splitter_2->addWidget(layoutWidget);
        splitter = new QSplitter(splitter_2);
        splitter->setObjectName(QStringLiteral("splitter"));
        splitter->setOrientation(Qt::Vertical);
        layoutWidget1 = new QWidget(splitter);
        layoutWidget1->setObjectName(QStringLiteral("layoutWidget1"));
        verticalLayout_3 = new QVBoxLayout(layoutWidget1);
        verticalLayout_3->setSpacing(6);
        verticalLayout_3->setContentsMargins(11, 11, 11, 11);
        verticalLayout_3->setObjectName(QStringLiteral("verticalLayout_3"));
        verticalLayout_3->setContentsMargins(0, 0, 0, 0);
        horizontalLayout = new QHBoxLayout();
        horizontalLayout->setSpacing(6);
        horizontalLayout->setObjectName(QStringLiteral("horizontalLayout"));
        verticalLayout_2 = new QVBoxLayout();
        verticalLayout_2->setSpacing(6);
        verticalLayout_2->setObjectName(QStringLiteral("verticalLayout_2"));
        horizontalLayout_5 = new QHBoxLayout();
        horizontalLayout_5->setSpacing(6);
        horizontalLayout_5->setObjectName(QStringLiteral("horizontalLayout_5"));
        horizontalLayout_3 = new QHBoxLayout();
        horizontalLayout_3->setSpacing(6);
        horizontalLayout_3->setObjectName(QStringLiteral("horizontalLayout_3"));
        label_LD = new QLabel(layoutWidget1);
        label_LD->setObjectName(QStringLiteral("label_LD"));

        horizontalLayout_3->addWidget(label_LD);

        comboBox_LD = new QComboBox(layoutWidget1);
        comboBox_LD->setObjectName(QStringLiteral("comboBox_LD"));

        horizontalLayout_3->addWidget(comboBox_LD);

        horizontalLayout_3->setStretch(0, 1);
        horizontalLayout_3->setStretch(1, 3);

        horizontalLayout_5->addLayout(horizontalLayout_3);

        horizontalLayout_4 = new QHBoxLayout();
        horizontalLayout_4->setSpacing(6);
        horizontalLayout_4->setObjectName(QStringLiteral("horizontalLayout_4"));
        label_LN = new QLabel(layoutWidget1);
        label_LN->setObjectName(QStringLiteral("label_LN"));

        horizontalLayout_4->addWidget(label_LN);

        comboBox_LN = new QComboBox(layoutWidget1);
        comboBox_LN->setObjectName(QStringLiteral("comboBox_LN"));

        horizontalLayout_4->addWidget(comboBox_LN);

        horizontalLayout_4->setStretch(0, 1);
        horizontalLayout_4->setStretch(1, 3);

        horizontalLayout_5->addLayout(horizontalLayout_4);


        verticalLayout_2->addLayout(horizontalLayout_5);

        tableView = new DropTable(layoutWidget1);
        tableView->setObjectName(QStringLiteral("tableView"));
        tableView->setContextMenuPolicy(Qt::CustomContextMenu);

        verticalLayout_2->addWidget(tableView);


        horizontalLayout->addLayout(verticalLayout_2);

        SubstationTree = new QTreeWidget(layoutWidget1);
        QTreeWidgetItem *__qtreewidgetitem1 = new QTreeWidgetItem();
        __qtreewidgetitem1->setText(0, QStringLiteral("1"));
        SubstationTree->setHeaderItem(__qtreewidgetitem1);
        SubstationTree->setObjectName(QStringLiteral("SubstationTree"));
        SubstationTree->setContextMenuPolicy(Qt::CustomContextMenu);

        horizontalLayout->addWidget(SubstationTree);


        verticalLayout_3->addLayout(horizontalLayout);

        horizontalLayout_2 = new QHBoxLayout();
        horizontalLayout_2->setSpacing(6);
        horizontalLayout_2->setObjectName(QStringLiteral("horizontalLayout_2"));
        pushButton_Addres = new QPushButton(layoutWidget1);
        pushButton_Addres->setObjectName(QStringLiteral("pushButton_Addres"));

        horizontalLayout_2->addWidget(pushButton_Addres);

        pushButton_GSE = new QPushButton(layoutWidget1);
        pushButton_GSE->setObjectName(QStringLiteral("pushButton_GSE"));

        horizontalLayout_2->addWidget(pushButton_GSE);

        pushButton_SMV = new QPushButton(layoutWidget1);
        pushButton_SMV->setObjectName(QStringLiteral("pushButton_SMV"));

        horizontalLayout_2->addWidget(pushButton_SMV);

        Button_LogicDevice = new QPushButton(layoutWidget1);
        Button_LogicDevice->setObjectName(QStringLiteral("Button_LogicDevice"));

        horizontalLayout_2->addWidget(Button_LogicDevice);

        Button_LogiceNode = new QPushButton(layoutWidget1);
        Button_LogiceNode->setObjectName(QStringLiteral("Button_LogiceNode"));

        horizontalLayout_2->addWidget(Button_LogiceNode);

        Button_DataSet = new QPushButton(layoutWidget1);
        Button_DataSet->setObjectName(QStringLiteral("Button_DataSet"));

        horizontalLayout_2->addWidget(Button_DataSet);

        Button_GSE = new QPushButton(layoutWidget1);
        Button_GSE->setObjectName(QStringLiteral("Button_GSE"));

        horizontalLayout_2->addWidget(Button_GSE);

        Button_SMV = new QPushButton(layoutWidget1);
        Button_SMV->setObjectName(QStringLiteral("Button_SMV"));

        horizontalLayout_2->addWidget(Button_SMV);

        Button_Input = new QPushButton(layoutWidget1);
        Button_Input->setObjectName(QStringLiteral("Button_Input"));

        horizontalLayout_2->addWidget(Button_Input);

        Button_Report = new QPushButton(layoutWidget1);
        Button_Report->setObjectName(QStringLiteral("Button_Report"));

        horizontalLayout_2->addWidget(Button_Report);

        Button_Log = new QPushButton(layoutWidget1);
        Button_Log->setObjectName(QStringLiteral("Button_Log"));

        horizontalLayout_2->addWidget(Button_Log);

        Button_Add = new QPushButton(layoutWidget1);
        Button_Add->setObjectName(QStringLiteral("Button_Add"));

        horizontalLayout_2->addWidget(Button_Add);

        Button_Del = new QPushButton(layoutWidget1);
        Button_Del->setObjectName(QStringLiteral("Button_Del"));

        horizontalLayout_2->addWidget(Button_Del);


        verticalLayout_3->addLayout(horizontalLayout_2);

        splitter->addWidget(layoutWidget1);
        tableView_data = new QTableView(splitter);
        tableView_data->setObjectName(QStringLiteral("tableView_data"));
        tableView_data->setContextMenuPolicy(Qt::CustomContextMenu);
        splitter->addWidget(tableView_data);
        splitter_2->addWidget(splitter);
        frame = new QFrame(splitter_2);
        frame->setObjectName(QStringLiteral("frame"));
        frame->setFrameShape(QFrame::StyledPanel);
        frame->setFrameShadow(QFrame::Raised);
        gridLayout_3 = new QGridLayout(frame);
        gridLayout_3->setSpacing(6);
        gridLayout_3->setContentsMargins(11, 11, 11, 11);
        gridLayout_3->setObjectName(QStringLiteral("gridLayout_3"));
        horizontalLayout_6 = new QHBoxLayout();
        horizontalLayout_6->setSpacing(6);
        horizontalLayout_6->setObjectName(QStringLiteral("horizontalLayout_6"));
        label_LN_C = new QLabel(frame);
        label_LN_C->setObjectName(QStringLiteral("label_LN_C"));
        label_LN_C->setMinimumSize(QSize(70, 0));
        label_LN_C->setMaximumSize(QSize(70, 16777215));

        horizontalLayout_6->addWidget(label_LN_C);

        lineEdit_LN = new QLineEdit(frame);
        lineEdit_LN->setObjectName(QStringLiteral("lineEdit_LN"));

        horizontalLayout_6->addWidget(lineEdit_LN);

        checkBox_DA = new QCheckBox(frame);
        checkBox_DA->setObjectName(QStringLiteral("checkBox_DA"));

        horizontalLayout_6->addWidget(checkBox_DA);


        gridLayout_3->addLayout(horizontalLayout_6, 0, 0, 1, 1);

        gridLayout = new QGridLayout();
        gridLayout->setSpacing(6);
        gridLayout->setObjectName(QStringLiteral("gridLayout"));
        horizontalLayout_7 = new QHBoxLayout();
        horizontalLayout_7->setSpacing(6);
        horizontalLayout_7->setObjectName(QStringLiteral("horizontalLayout_7"));
        label_DA = new QLabel(frame);
        label_DA->setObjectName(QStringLiteral("label_DA"));
        label_DA->setMinimumSize(QSize(70, 0));
        label_DA->setMaximumSize(QSize(70, 16777215));

        horizontalLayout_7->addWidget(label_DA);

        lineEdit_DA = new QLineEdit(frame);
        lineEdit_DA->setObjectName(QStringLiteral("lineEdit_DA"));

        horizontalLayout_7->addWidget(lineEdit_DA);

        checkBox_DA_END = new QCheckBox(frame);
        checkBox_DA_END->setObjectName(QStringLiteral("checkBox_DA_END"));

        horizontalLayout_7->addWidget(checkBox_DA_END);


        gridLayout->addLayout(horizontalLayout_7, 0, 0, 1, 1);

        horizontalLayout_8 = new QHBoxLayout();
        horizontalLayout_8->setSpacing(6);
        horizontalLayout_8->setObjectName(QStringLiteral("horizontalLayout_8"));
        label_AP = new QLabel(frame);
        label_AP->setObjectName(QStringLiteral("label_AP"));

        horizontalLayout_8->addWidget(label_AP);

        comboBox_AP = new QComboBox(frame);
        comboBox_AP->setObjectName(QStringLiteral("comboBox_AP"));
        comboBox_AP->setFocusPolicy(Qt::NoFocus);

        horizontalLayout_8->addWidget(comboBox_AP);

        label_FC = new QLabel(frame);
        label_FC->setObjectName(QStringLiteral("label_FC"));

        horizontalLayout_8->addWidget(label_FC);

        comboBox_FC = new QComboBox(frame);
        comboBox_FC->setObjectName(QStringLiteral("comboBox_FC"));

        horizontalLayout_8->addWidget(comboBox_FC);


        gridLayout->addLayout(horizontalLayout_8, 1, 0, 1, 1);

        horizontalLayout_9 = new QHBoxLayout();
        horizontalLayout_9->setSpacing(6);
        horizontalLayout_9->setObjectName(QStringLiteral("horizontalLayout_9"));
        checkBox_Disp = new QCheckBox(frame);
        checkBox_Disp->setObjectName(QStringLiteral("checkBox_Disp"));

        horizontalLayout_9->addWidget(checkBox_Disp);

        pushButton_fresh = new QPushButton(frame);
        pushButton_fresh->setObjectName(QStringLiteral("pushButton_fresh"));

        horizontalLayout_9->addWidget(pushButton_fresh);


        gridLayout->addLayout(horizontalLayout_9, 2, 0, 1, 1);

        IEDTree = new QTreeWidget(frame);
        QTreeWidgetItem *__qtreewidgetitem2 = new QTreeWidgetItem();
        __qtreewidgetitem2->setText(0, QStringLiteral("1"));
        IEDTree->setHeaderItem(__qtreewidgetitem2);
        IEDTree->setObjectName(QStringLiteral("IEDTree"));
        IEDTree->setContextMenuPolicy(Qt::CustomContextMenu);

        gridLayout->addWidget(IEDTree, 3, 0, 1, 1);


        gridLayout_3->addLayout(gridLayout, 1, 0, 1, 1);

        splitter_2->addWidget(frame);
        splitter_3->addWidget(splitter_2);
        textBrowser = new QTextBrowser(splitter_3);
        textBrowser->setObjectName(QStringLiteral("textBrowser"));
        textBrowser->setMaximumSize(QSize(16777215, 100));
        textBrowser->setContextMenuPolicy(Qt::CustomContextMenu);
        splitter_3->addWidget(textBrowser);

        gridLayout_2->addWidget(splitter_3, 0, 0, 1, 1);

        label_Info = new QLabel(centralWidget);
        label_Info->setObjectName(QStringLiteral("label_Info"));

        gridLayout_2->addWidget(label_Info, 1, 0, 1, 1);

        MainWindow->setCentralWidget(centralWidget);
        menuBar = new QMenuBar(MainWindow);
        menuBar->setObjectName(QStringLiteral("menuBar"));
        menuBar->setGeometry(QRect(0, 0, 1440, 23));
        menu_File = new QMenu(menuBar);
        menu_File->setObjectName(QStringLiteral("menu_File"));
        menu_Function = new QMenu(menuBar);
        menu_Function->setObjectName(QStringLiteral("menu_Function"));
        menu_Import = new QMenu(menuBar);
        menu_Import->setObjectName(QStringLiteral("menu_Import"));
        menu_Export = new QMenu(menuBar);
        menu_Export->setObjectName(QStringLiteral("menu_Export"));
        menu_Config = new QMenu(menuBar);
        menu_Config->setObjectName(QStringLiteral("menu_Config"));
        menu_About = new QMenu(menuBar);
        menu_About->setObjectName(QStringLiteral("menu_About"));
        menu_Check = new QMenu(menuBar);
        menu_Check->setObjectName(QStringLiteral("menu_Check"));
        MainWindow->setMenuBar(menuBar);
        mainToolBar = new QToolBar(MainWindow);
        mainToolBar->setObjectName(QStringLiteral("mainToolBar"));
        MainWindow->addToolBar(Qt::TopToolBarArea, mainToolBar);
        statusBar = new QStatusBar(MainWindow);
        statusBar->setObjectName(QStringLiteral("statusBar"));
        MainWindow->setStatusBar(statusBar);

        menuBar->addAction(menu_File->menuAction());
        menuBar->addAction(menu_Function->menuAction());
        menuBar->addAction(menu_Check->menuAction());
        menuBar->addAction(menu_Import->menuAction());
        menuBar->addAction(menu_Export->menuAction());
        menuBar->addAction(menu_Config->menuAction());
        menuBar->addAction(menu_About->menuAction());
        menu_File->addAction(actionNew);
        menu_File->addAction(actionOpen);
        menu_File->addAction(actionSave);
        menu_File->addAction(actionSave_as);
        menu_File->addAction(actionExit);
        menu_Function->addAction(actionAuto_Set_MMS);
        menu_Function->addAction(actionAuto_Set_GOOSE);
        menu_Function->addAction(actionAuto_Set_SMV);
        menu_Function->addAction(actionInit_Set_Communication);
        menu_Function->addAction(actionAuto_Add_Control_block);
        menu_Function->addAction(actionDel_All_Virtual_terminal_Map);
        menu_Function->addSeparator();
        menu_Import->addAction(actionImport_CID);
        menu_Import->addAction(actionImport_ICD);
        menu_Import->addAction(actionImport_SSD);
        menu_Import->addAction(actionImport_Map);
        menu_Import->addAction(actionMerge_SCD);
        menu_Export->addAction(actionExprot_CID);
        menu_Export->addAction(actionExport_Virtual_terminal);
        menu_Export->addAction(actionExport_Virtual_terminal_MAp);
        menu_Export->addAction(actionExport_IEC_Conifig);
        menu_Export->addAction(actionExport_MAP);
        menu_Config->addAction(actionConfig);
        menu_Config->addAction(actionSwtich_Chinese);
        menu_Config->addAction(actionSwitch_English);
        menu_About->addAction(actionHelp);
        menu_About->addAction(actionAbout);
        menu_Check->addAction(action_Communication_verification);
        menu_Check->addAction(actionFile_integrity_check);
        menu_Check->addAction(actionModel_validation_check);
        menu_Check->addAction(actionModel_schema2_0_check);
        menu_Check->addAction(actionCID);
        menu_Check->addAction(action_terminals_Type_check);
        menu_Check->addAction(actionThe_virtual_terminal_in_the_interval_contains_the_check);

        retranslateUi(MainWindow);

        QMetaObject::connectSlotsByName(MainWindow);
    } // setupUi

    void retranslateUi(QMainWindow *MainWindow)
    {
        MainWindow->setWindowTitle(QApplication::translate("MainWindow", "MainWindow", 0));
        actionNew->setText(QApplication::translate("MainWindow", "New", 0));
        actionOpen->setText(QApplication::translate("MainWindow", "Open", 0));
        actionSave->setText(QApplication::translate("MainWindow", "Save", 0));
        actionSave_as->setText(QApplication::translate("MainWindow", "Save As", 0));
        actionExit->setText(QApplication::translate("MainWindow", "Exit", 0));
        actionLoad_DB->setText(QApplication::translate("MainWindow", "Load DB", 0));
        actionAuto_Set_MMS->setText(QApplication::translate("MainWindow", "Auto Set MMS NET", 0));
#ifndef QT_NO_TOOLTIP
        actionAuto_Set_MMS->setToolTip(QApplication::translate("MainWindow", "Auto Set MMS net", 0));
#endif // QT_NO_TOOLTIP
        actionAuto_Set_GOOSE->setText(QApplication::translate("MainWindow", "Auto Set GOOSE NET", 0));
#ifndef QT_NO_TOOLTIP
        actionAuto_Set_GOOSE->setToolTip(QApplication::translate("MainWindow", "Auto Set GOOSE net", 0));
#endif // QT_NO_TOOLTIP
        actionAuto_Set_SMV->setText(QApplication::translate("MainWindow", "Auto Set SMV NET", 0));
#ifndef QT_NO_TOOLTIP
        actionAuto_Set_SMV->setToolTip(QApplication::translate("MainWindow", "Auto Set SMV net", 0));
#endif // QT_NO_TOOLTIP
        actionInit_Set_Communication->setText(QApplication::translate("MainWindow", "Init Set Communication", 0));
        actionAuto_Add_Control_block->setText(QApplication::translate("MainWindow", "Auto Add Control block", 0));
        actionDel_All_Virtual_terminal_Map->setText(QApplication::translate("MainWindow", "Del All Virtual terminal Map", 0));
        action_Communication_verification->setText(QApplication::translate("MainWindow", "Communication legitimacy verification", 0));
        actionFile_integrity_check->setText(QApplication::translate("MainWindow", "File integrity check", 0));
        actionModel_validation_check->setText(QApplication::translate("MainWindow", "Model validation check", 0));
        actionModel_schema2_0_check->setText(QApplication::translate("MainWindow", "Model schema2.0 check", 0));
        actionCID->setText(QApplication::translate("MainWindow", "CID File consistency check", 0));
        action_terminals_Type_check->setText(QApplication::translate("MainWindow", "Virtual terminals on both sides of the matching check", 0));
        actionThe_virtual_terminal_in_the_interval_contains_the_check->setText(QApplication::translate("MainWindow", "The virtual terminal in the interval contains the check.", 0));
        actionImport_CID->setText(QApplication::translate("MainWindow", "Import CID", 0));
        actionImport_ICD->setText(QApplication::translate("MainWindow", "Import ICD", 0));
        actionImport_SSD->setText(QApplication::translate("MainWindow", "Import SSD", 0));
        actionExprot_CID->setText(QApplication::translate("MainWindow", "Exprot CID", 0));
        actionExport_Virtual_terminal->setText(QApplication::translate("MainWindow", "Export Virtual terminal", 0));
        actionExport_Virtual_terminal_MAp->setText(QApplication::translate("MainWindow", "Export Virtual terminal MAP", 0));
        actionExport_IEC_Conifig->setText(QApplication::translate("MainWindow", "Export IEC Conifig", 0));
#ifndef QT_NO_TOOLTIP
        actionExport_IEC_Conifig->setToolTip(QApplication::translate("MainWindow", "Export IEC Conifig", 0));
#endif // QT_NO_TOOLTIP
        actionExport_MAP->setText(QApplication::translate("MainWindow", "Export MAP", 0));
        actionHelp->setText(QApplication::translate("MainWindow", "Help", 0));
        actionAbout->setText(QApplication::translate("MainWindow", "About", 0));
        actionConfig->setText(QApplication::translate("MainWindow", "Config", 0));
        actionImport_Map->setText(QApplication::translate("MainWindow", "Import Map", 0));
        actionMerge_SCD->setText(QApplication::translate("MainWindow", "Merge SCD", 0));
        actionSwtich_Chinese->setText(QApplication::translate("MainWindow", "Swtich Chinese", 0));
        actionSwitch_English->setText(QApplication::translate("MainWindow", "Switch English", 0));
        label_LD->setText(QApplication::translate("MainWindow", "TextLabel", 0));
        label_LN->setText(QApplication::translate("MainWindow", "TextLabel", 0));
        pushButton_Addres->setText(QApplication::translate("MainWindow", "PushButton", 0));
        pushButton_GSE->setText(QApplication::translate("MainWindow", "PushButton", 0));
        pushButton_SMV->setText(QApplication::translate("MainWindow", "PushButton", 0));
        Button_LogicDevice->setText(QApplication::translate("MainWindow", "PushButton", 0));
        Button_LogiceNode->setText(QApplication::translate("MainWindow", "PushButton", 0));
        Button_DataSet->setText(QApplication::translate("MainWindow", "PushButton", 0));
        Button_GSE->setText(QApplication::translate("MainWindow", "PushButton", 0));
        Button_SMV->setText(QApplication::translate("MainWindow", "PushButton", 0));
        Button_Input->setText(QApplication::translate("MainWindow", "PushButton", 0));
        Button_Report->setText(QApplication::translate("MainWindow", "PushButton", 0));
        Button_Log->setText(QApplication::translate("MainWindow", "PushButton", 0));
        Button_Add->setText(QApplication::translate("MainWindow", "PushButton", 0));
        Button_Del->setText(QApplication::translate("MainWindow", "PushButton", 0));
        label_LN_C->setText(QApplication::translate("MainWindow", "TextLabel", 0));
        checkBox_DA->setText(QApplication::translate("MainWindow", "CheckBox", 0));
        label_DA->setText(QApplication::translate("MainWindow", "TextLabel", 0));
        checkBox_DA_END->setText(QApplication::translate("MainWindow", "CheckBox", 0));
        label_AP->setText(QApplication::translate("MainWindow", "TextLabel", 0));
        label_FC->setText(QApplication::translate("MainWindow", "TextLabel", 0));
        checkBox_Disp->setText(QApplication::translate("MainWindow", "CheckBox", 0));
        pushButton_fresh->setText(QApplication::translate("MainWindow", "PushButton", 0));
        label_Info->setText(QApplication::translate("MainWindow", "TextLabel", 0));
        menu_File->setTitle(QApplication::translate("MainWindow", "File", 0));
        menu_Function->setTitle(QApplication::translate("MainWindow", "Function", 0));
        menu_Import->setTitle(QApplication::translate("MainWindow", "Import", 0));
        menu_Export->setTitle(QApplication::translate("MainWindow", "Export", 0));
        menu_Config->setTitle(QApplication::translate("MainWindow", "Config", 0));
        menu_About->setTitle(QApplication::translate("MainWindow", "About", 0));
        menu_Check->setTitle(QApplication::translate("MainWindow", "Check", 0));
    } // retranslateUi

};

namespace Ui {
    class MainWindow: public Ui_MainWindow {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_MAINWINDOW_H
