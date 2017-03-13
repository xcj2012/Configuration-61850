#include "mainwindow.h"
#include "ui_mainwindow.h"
#include <QTextCodec>
MainWindow::MainWindow(QWidget *parent) :
QMainWindow(parent),
ui(new Ui::MainWindow)
{
	ui->setupUi(this);
	Init();
	m_SCDPoint = NULL;
	RPT_STATE = 0;
	Change_Flag = 0;
	Version_Flag = 0;
	Reversion_Flag = 0;
	DataSet_Change = false;
	Language_Type = -1;
}

MainWindow::~MainWindow()
{
	Action_Close();
	delete ui;
}
void MainWindow::Init()
{
	//ui->SCLTable->setText(tr("SCL Tree"));
	//ui->SCLTable->hide();

	//ui->IEDTree->hide();
	Init_Menu();
	Init_Display();
	
	DisableFun();
	m_ModelHeader = new QStandardItemModel;
	m_ModelSubstation = new QStandardItemModel;
	m_ModelCommunication = new QStandardItemModel;
	m_ModelIED = new QStandardItemModel;
	m_ModelIEDNode = new QStandardItemModel;
	m_ModelSubNet = new QStandardItemModel;
	m_ModelIED_LD = new QStandardItemModel;
	m_ModelIED_LN = new QStandardItemModel;
	m_ModelIED_DataSetData = new QStandardItemModel;
	m_ModelIED_GSE = new QStandardItemModel;
	m_ModelIED_Input = new QStandardItemModel;
	m_ModelIED_SMV = new QStandardItemModel;
	m_ModelIED_Log = new QStandardItemModel;
	m_ModelIED_Report = new QStandardItemModel;
	m_ModelIED_DataSet = new QStandardItemModel;
	m_ModelIED_MmsNet = new QStandardItemModel;
	m_ModelIED_GooseNet = new QStandardItemModel;
	m_ModelIED_SmvNet = new QStandardItemModel;
	GOOSE_Flag = 0;
	Version_Flag = 0;
	Reversion_Flag = 0;
	
	// ui->SCLTree->setHeaderLabel("SCL");
	//    QTreeWidgetItem * header = ui->SCLTree->headerItem();
	//    header->setText(0, QString("SCL Tree"));
	//    header->setBackgroundColor(0,QColor(0,0,0));
	//    header->setBackground(0,QBrush(QColor(0,0,0)));
	//    ui->SCLTree->header()->setStyleSheet("QHeaderView::section{rgb(246, 254, 255);}");
	ui->actionInit_Set_Communication->setEnabled(false);
	connect(ui->actionNew, SIGNAL(triggered()), this, SLOT(Action_New()));
	connect(ui->actionSave_as, SIGNAL(triggered()), this, SLOT(Action_Save_As()));
	connect(ui->actionSave, SIGNAL(triggered()), this, SLOT(Action_Save()));
	connect(ui->actionImport_Map, SIGNAL(triggered()), this, SLOT(Action_ImportMap()));

	connect(ui->actionOpen, SIGNAL(triggered()), this, SLOT(Action_Load()));
	connect(ui->SCLTree, SIGNAL(customContextMenuRequested(QPoint)), this, SLOT(SCLTree_MousEvent(QPoint)));
	//connect(ui->SCLTree,SIGNAL(doubleClicked(QModelIndex)),this,SLOT(Header_DoublClick(QModelIndex)));
	connect(ui->SCLTree, SIGNAL(itemDoubleClicked(QTreeWidgetItem *, int)),
		this, SLOT(openMenuProgram(QTreeWidgetItem*, int)));
	connect(ui->SCLTree, SIGNAL(itemClicked(QTreeWidgetItem *, int)),
		this, SLOT(openMenuProgram(QTreeWidgetItem*, int)));
	connect(ui->tableView, SIGNAL(customContextMenuRequested(QPoint)), this, SLOT(TableView_MousEvent(QPoint)));
	connect(ui->tableView_data, SIGNAL(customContextMenuRequested(QPoint)), this, SLOT(DataSetDate_MousEvent(QPoint)));

	connect(actionAdd, SIGNAL(triggered()), this, SLOT(Action_Add()));
	connect(actionDel, SIGNAL(triggered()), this, SLOT(Action_Del()));
	connect(ui->actionImport_CID, SIGNAL(triggered()), this, SLOT(ImportOneCID()));
	connect(ui->actionImport_ICD, SIGNAL(triggered()), this, SLOT(ImportOneICD()));
	connect(ui->Button_LogicDevice, SIGNAL(clicked()), this, SLOT(PushButton_LogicDevice_Click()));
	connect(ui->Button_DataSet, SIGNAL(clicked()), this, SLOT(PushButton_DataSet_Click()));
	connect(ui->Button_GSE, SIGNAL(clicked()), this, SLOT(PushButton_GSE_Click()));
	connect(ui->Button_Input, SIGNAL(clicked()), this, SLOT(PushButton_Input_Click()));
	connect(ui->Button_Log, SIGNAL(clicked()), this, SLOT(PushButton_Log_Click()));
	connect(ui->Button_LogiceNode, SIGNAL(clicked()), this, SLOT(PushButton_LogiceNode_Click()));
	connect(ui->Button_Report, SIGNAL(clicked()), this, SLOT(PushButton_Report_Click()));
	connect(ui->Button_SMV, SIGNAL(clicked()), this, SLOT(PushButton_SMV_Click()));
	connect(ui->pushButton_fresh, SIGNAL(clicked()), this, SLOT(PushButton_Fresh()));
	connect(actionRename, SIGNAL(triggered()), this, SLOT(Action_Rename()));
	connect(ui->tableView, SIGNAL(clicked(QModelIndex)), this, SLOT(OnTableViewClicked(QModelIndex)));
	connect(ui->tableView, SIGNAL(doubleClicked(QModelIndex)), this, SLOT(OnTableViewdoubleClicked(QModelIndex)));
	connect(actionConfig, SIGNAL(triggered()), this, SLOT(Action_Config()));
	connect(ui->actionFile_integrity_check, SIGNAL(triggered()), this, SLOT(Action_Integrity_Check()));
	connect(ui->action_Communication_verification, SIGNAL(triggered()), this, SLOT(Action_Communication_Check()));
	connect(ui->actionModel_schema2_0_check, SIGNAL(triggered()), this, SLOT(Action_Schema_Check()));
	connect(ui->actionModel_validation_check, SIGNAL(triggered()), this, SLOT(Action_Model_validation_check()));
	connect(ui->action_terminals_Type_check, SIGNAL(triggered()), this, SLOT(Action_Type_Terminal_check()));
	connect(ui->actionExport_MAP, SIGNAL(triggered()), this, SLOT(Action_LogicMap()));
	connect(ui->actionExport_IEC_Conifig, SIGNAL(triggered()), this, SLOT(Action_IECConfig()));
	connect(ui->actionAuto_Add_Control_block, SIGNAL(triggered()), this, SLOT(Auto_AddControlBlock()));

	connect(actionBatchImportIED, SIGNAL(triggered()), this, SLOT(Action_BatchImport()));
	connect(actionReLoad, SIGNAL(triggered()), this, SLOT(Action_Reload()));
	connect(actionDelOneIed, SIGNAL(triggered()), this, SLOT(Action_DelIED()));
	connect(actionExtra, SIGNAL(triggered()), this, SLOT(Action_Extra()));
	connect(actionBatch, SIGNAL(triggered()), this, SLOT(Action_Batch()));
	connect(ui->actionExprot_CID, SIGNAL(triggered()), this, SLOT(Action_ExportCID()));
	connect(actionIncrease, SIGNAL(triggered()), this, SLOT(Action_Increase()));
	connect(ui->actionAuto_Set_MMS, SIGNAL(triggered()), this, SLOT(Auto_SetMmsNet()));
	connect(ui->actionAuto_Set_GOOSE, SIGNAL(triggered()), this, SLOT(Auto_SetGooseNet()));
	connect(ui->actionAuto_Set_SMV, SIGNAL(triggered()), this, SLOT(Auto_SetSmvNet()));
	connect(ui->actionInit_Set_Communication, SIGNAL(triggered()), this, SLOT(Auto_Init_Communication()));
	connect(ui->actionDel_All_Virtual_terminal_Map, SIGNAL(triggered()), this, SLOT(Action_ClearInput()));
	connect(ui->actionExport_Virtual_terminal, SIGNAL(triggered()), this, SLOT(Action_ExportXML()));
	connect(ui->actionExport_Virtual_terminal_MAp, SIGNAL(triggered()), this, SLOT(Action_ExportXLS()));
	connect(this, SIGNAL(SendChange(int)), this, SLOT(ReceiveChange(int)));
	connect(ui->tableView, SIGNAL(clicked(QModelIndex)), this, SLOT(TableView_Row_Select(QModelIndex)));
	connect(ui->actionMerge_SCD, SIGNAL(triggered()), this, SLOT(Action_MergeSCD()));
	connect(ui->actionSwitch_English, SIGNAL(triggered()), this, SLOT(Action_SwitchLanguage()));
	connect(ui->actionSwtich_Chinese, SIGNAL(triggered()), this, SLOT(Action_SwitchLanguage()));
	connect(ui->actionExit, SIGNAL(triggered()), this, SLOT(Action_Close()));
	connect(ui->actionCID, SIGNAL(triggered()), this, SLOT(Action_CID_Contain()));

	ui->actionSwitch_English->setProperty("Language", 2);
	ui->actionSwtich_Chinese->setProperty("Language", 1);
	//connect(ui->actionDel_All_Virtual_terminal_Map,SIGNAL(triggered()),this,SLOT(Action_Del_ALLInput()));
}
void MainWindow::Init_Display()
{
	setWindowTitle(tr("KF 6502CFG System Configuration"));
	ui->mainToolBar->hide();
	ui->label_Info->clear();
	ui->label_AP->setText(tr("AP"));
	ui->label_DA->setText(tr("DA"));
	ui->label_LN_C->setText(tr("Logic Node"));
	ui->label_FC->setText(tr("FC"));
	ui->checkBox_DA->setText(tr("Must DA"));
	ui->checkBox_DA_END->setText(tr("End of DA"));
	ui->checkBox_DA_END->hide();
	ui->checkBox_Disp->setText(tr("Not display Common"));
	ui->SCLTree->setHeaderLabel(tr("SCL Tree"));
	ui->Button_DataSet->hide();
	ui->Button_DataSet->setText(tr("DataSet"));
	ui->Button_GSE->hide();
	ui->Button_GSE->setText(tr("GSE"));
	ui->Button_Input->hide();
	ui->Button_Input->setText(tr("Input"));
	ui->Button_Log->hide();
	ui->Button_Log->setText(tr("Log"));
	ui->Button_LogicDevice->hide();
	ui->Button_LogicDevice->setText(tr("LogicDevice"));
	ui->Button_LogiceNode->hide();
	ui->Button_LogiceNode->setText(tr("LogicNode"));
	ui->Button_Report->hide();
	ui->Button_Report->setText(tr("Report"));
	ui->Button_SMV->hide();
	ui->Button_SMV->setText(tr("SMV"));
	ui->Button_Add->hide();
	ui->Button_Add->setText(tr("Add"));
	ui->Button_Del->hide();
	ui->Button_Del->setText(tr("Del"));;
	ui->SubstationTree->hide();
	ui->pushButton_fresh->setText(tr("Fresh"));
	//ui->SCLTree->header()->hide();
	ui->pushButton_Addres->setText(tr("Address"));
	ui->pushButton_Addres->hide();
	ui->pushButton_GSE->setText(tr("GSE"));
	ui->pushButton_GSE->hide();
	ui->pushButton_SMV->setText(tr("SMV"));
	ui->pushButton_SMV->hide();
	ui->label_LD->hide();
	ui->label_LN->hide();
	ui->comboBox_LD->hide();
	ui->comboBox_LN->hide();

	ui->label_LD->setText(tr("Logic Device:"));
	ui->label_LN->setText(tr("Logic Node:"));
	ui->menu_File->setTitle(tr("File"));
	ui->menu_Function->setTitle(tr("Function"));
	ui->menu_Check->setTitle(tr("Check"));
	ui->menu_Import->setTitle(tr("Import"));
	ui->menu_Export->setTitle(tr("Export"));
	ui->menu_Config->setTitle(tr("Config"));
	ui->menu_About->setTitle(tr("About"));
	ui->actionNew->setText(tr("New"));
	ui->actionOpen->setText(tr("Open"));
	ui->actionSave->setText(tr("Save "));
	ui->actionSave_as->setText(tr("Save As"));
	ui->actionExit->setText(tr("Exit"));
	ui->actionAuto_Set_MMS->setText(tr("Auto Set MMS NET"));
	ui->actionAuto_Set_GOOSE->setText(tr("Auto Set GOOSE NET"));
	ui->actionAuto_Set_SMV->setText(tr("Auto Set SMV NET"));
	ui->actionInit_Set_Communication->setText(tr("Init Set Communication"));
	ui->actionAuto_Add_Control_block->setText(tr("Auto Add Control block"));
	ui->actionDel_All_Virtual_terminal_Map->setText(tr("Del All Virtual terminal Map"));
	ui->action_Communication_verification->setText(tr("Communication legitimacy verification"));
	ui->actionFile_integrity_check->setText(tr("File integrity check"));
	ui->actionModel_validation_check->setText(tr("Model validation check"));
	ui->actionModel_schema2_0_check->setText(tr("Model schema2.0 check"));
	ui->actionCID->setText(tr("CID File consistency check"));
	ui->action_terminals_Type_check->setText(tr("Virtual terminals on both sides of the matching check"));
	ui->actionThe_virtual_terminal_in_the_interval_contains_the_check->setText(tr("The virtual terminal in the interval contains the check."));
	ui->actionImport_CID->setText(tr("Import CID"));
	ui->actionImport_ICD->setText(tr("Import ICD"));
	ui->actionImport_SSD->setText(tr("Import SSD"));
	ui->actionImport_Map->setText(tr("Import Map"));
	ui->actionMerge_SCD->setText(tr("Merge SCD"));
	ui->actionExprot_CID->setText(tr("Exprot CID"));
	ui->actionExport_Virtual_terminal->setText(tr("Export Virtual terminal"));
	ui->actionExport_Virtual_terminal_MAp->setText(tr("Export Virtual terminal MAP"));
	ui->actionExport_IEC_Conifig->setText(tr("Export IEC Conifig"));
	ui->actionExport_MAP->setText(tr("Export MAP"));
	ui->actionConfig->setText(tr("Config"));
	ui->actionSwtich_Chinese->setText(tr("Swtich Chinese"));
	ui->actionSwitch_English->setText(tr("Switch English"));
	ui->actionHelp->setText(tr("Help"));
	ui->actionAbout->setText(tr("About"));
	actionAdd->setText(tr("Add"));
	actionDel->setText(tr("Del"));
	actionReLoad->setText(tr("Reload"));
	actionImportOneIed->setText(tr("Import One CID"));
	actionBatchImportIED->setText(tr("Batch Import CID"));
	actionExportIed->setText(tr("Export IED"));
	actionFindIed->setText(tr("Find IED"));
	actionExtra->setText(tr("Extra"));
	actionMovUp->setText(tr("Move Up"));
	actionMovDown->setText(tr("Move Down"));
	actionConfig->setText(tr("Configure"));
	actionRename->setText(tr("Rename"));
	actionDelOneIed->setText(tr("Del One IED"));
	actionIncrease->setText(tr("Increase"));
	actionBatch->setText(tr("Batch"));
	ui->tableView_data->hide();
	ui->frame->hide();
	ui->splitter_2->setStretchFactor(0, 20);
	ui->splitter_2->setStretchFactor(1, 60);
	ui->splitter_2->setStretchFactor(2, 20);
	setAutoFillBackground(true);
}
void MainWindow::DisableFun()
{
	ui->actionAuto_Add_Control_block->setEnabled(false);
	ui->actionSave->setEnabled(false);
	ui->actionSave_as->setEnabled(false);
	ui->actionAuto_Set_MMS->setEnabled(false);
	ui->actionAuto_Set_GOOSE->setEnabled(false);
	ui->actionAuto_Set_SMV->setEnabled(false);
	ui->actionInit_Set_Communication->setEnabled(false);
	ui->actionDel_All_Virtual_terminal_Map->setEnabled(false);
	ui->action_Communication_verification->setEnabled(false);
	ui->actionFile_integrity_check->setEnabled(false);
	ui->actionModel_validation_check->setEnabled(false);
	ui->actionModel_schema2_0_check->setEnabled(false);
	ui->actionCID->setEnabled(false);
	ui->actionImport_Map->setEnabled(false);
	ui->action_terminals_Type_check->setEnabled(false);
	ui->actionThe_virtual_terminal_in_the_interval_contains_the_check->setEnabled(false);
	ui->actionImport_CID->setEnabled(false);
	ui->actionImport_ICD->setEnabled(false);
	ui->actionImport_SSD->setEnabled(false);
	ui->actionExprot_CID->setEnabled(false);
	ui->actionExport_Virtual_terminal->setEnabled(false);
	ui->actionExport_Virtual_terminal_MAp->setEnabled(false);
	ui->actionImport_SSD->setEnabled(false);
	ui->actionExport_MAP->setEnabled(false);
	ui->actionConfig->setEnabled(false);
	//ui->actionInit_Set_Communication->setEnabled(false);
}
void MainWindow::EnableFun()
{
	ui->actionAuto_Add_Control_block->setEnabled(true);
	ui->actionSave->setEnabled(true);
	ui->actionSave_as->setEnabled(true);
	ui->actionAuto_Set_MMS->setEnabled(true);
	ui->actionAuto_Set_GOOSE->setEnabled(true);
	ui->actionAuto_Set_SMV->setEnabled(true);
	ui->actionInit_Set_Communication->setEnabled(false);
	ui->actionDel_All_Virtual_terminal_Map->setEnabled(true);
	ui->action_Communication_verification->setEnabled(true);
	ui->actionFile_integrity_check->setEnabled(true);
	ui->actionModel_validation_check->setEnabled(true);
	ui->actionModel_schema2_0_check->setEnabled(true);
	ui->actionCID->setEnabled(true);
	ui->actionImport_Map->setEnabled(true);
	ui->action_terminals_Type_check->setEnabled(true);
	ui->actionThe_virtual_terminal_in_the_interval_contains_the_check->setEnabled(false);
	ui->actionImport_CID->setEnabled(true);
	ui->actionImport_ICD->setEnabled(true);
	ui->actionImport_SSD->setEnabled(false);
	ui->actionExprot_CID->setEnabled(true);
	ui->actionExport_Virtual_terminal->setEnabled(true);
	ui->actionExport_Virtual_terminal_MAp->setEnabled(true);
	ui->actionImport_SSD->setEnabled(false);
	ui->actionExport_MAP->setEnabled(true);
	ui->actionConfig->setEnabled(true);
}
void MainWindow::Action_New()
{
	if (m_SCDPoint!=NULL)
	{
		delete m_SCDPoint;
		m_SCDPoint = NULL;
	}
	m_SCDPoint = new ScdTree();
	ui->textBrowser->clear();
	SCD_FilePath.clear();
	if (m_SCDPoint->CreatSCD() == DO_OK)
	{
		QStandardItemModel *m_Model = new QStandardItemModel;
		ui->tableView->setModel(m_Model);
		m_Model->setRowCount(0);
		InitSCDtree();
		EnableFun();
		//Init_Header();
	}
	else
	{
		delete m_SCDPoint;
		m_SCDPoint = NULL;
	}
	return;

}

void MainWindow::Action_Load()
{
	ui->textBrowser->clear();
	QString fileName = QFileDialog::getOpenFileName(this,
		tr("Open SCD"), QDir::currentPath(), tr("SCD Files (*.scd)"));

	if (fileName.isEmpty())
	{
		return;
	}
	SCD_FilePath = fileName;
	if (m_SCDPoint!=NULL)
	{
		delete m_SCDPoint;
		m_SCDPoint = NULL;
	}
	m_SCDPoint = new ScdTree();
	ui->label_Info->setText(SCD_FilePath);

	//if (File_Integrity_Check(1)==DO_FAIL)
	//{
	//	delete m_SCDPoint;
	//	return;
	//}
		Wait_Dlg *m_dlg =new Wait_Dlg;
		m_dlg->Set(tr("Loading SCD,Waiting !"));

		m_dlg->show();
        m_dlg->Display();
		bool falg =false;
			QCoreApplication::processEvents(QEventLoop::AllEvents);
			if (m_SCDPoint->LoadSCD(SCD_FilePath) == DO_OK)
			{
				falg = true;
				m_dlg->m_Close();
				QStandardItemModel *m_Model = new QStandardItemModel;
				ui->tableView->setModel(m_Model);
				m_Model->setRowCount(0);
				InitSCDtree();
				EnableFun();

				//Init_Header();
			}
			else
			{
				m_dlg->m_Close();
				ui->SCLTree->clear();
				ui->tableView->selectRow(0);
				ui->tableView_data->selectColumn(0);
				DisableFun();
			}


	



}
void MainWindow::Action_Save_As()
{
	QString fileName = QFileDialog::getSaveFileName(this,
		tr("Open SCD"),
		QDir::currentPath(),
		tr("SCD Files (*.SCD)"));

	if (!fileName.isNull())
	{
		if ((Version_Flag != 0) || (Reversion_Flag != 0))
		{
			AddNewHistoryItem();
			Version_Flag = 0;
			Reversion_Flag = 0;
		}
		m_SCDPoint->SaveSCD(fileName);
		SCD_FilePath = fileName;
		ui->label_Info->setText(SCD_FilePath);
		QMessageBox::information(NULL, tr("Notice"), tr("Save file success "));
	}
	else
	{
		return;
	}
}
void MainWindow::Action_Save()
{

	if (!SCD_FilePath.isNull())
	{
		if ((Version_Flag != 0) || (Reversion_Flag != 0))
		{
			AddNewHistoryItem();
			Version_Flag = 0;
			Reversion_Flag = 0;
		}

		m_SCDPoint->SaveSCD(SCD_FilePath);
		QMessageBox::information(NULL, tr("Notice"), tr("Save file success "));

	}
	else
	{

		Action_Save_As();
	}
}
void MainWindow::DisplayNode(ScdTree *SCDPoint)
{

}


void MainWindow::InitSCDtree()
{



	QTreeWidgetItem *firstClassItem;
	//QTreeWidgetItem *secClassItem;
	ui->SCLTree->clear();
	T_parent = ui->SCLTree->invisibleRootItem();
	T_parent->takeChildren();
	firstClassItem = new QTreeWidgetItem(T_parent);

	firstClassItem->setText(0, tr("Header"));

	firstClassItem = new QTreeWidgetItem(T_parent);

	firstClassItem->setText(0, tr("Substation"));
	firstClassItem = new QTreeWidgetItem(T_parent);

	firstClassItem->setText(0, tr("Communication"));
	firstClassItem = new QTreeWidgetItem(T_parent);
	CurrentNodeType = COMMUNICATION_NODE;
	Get_Node("Communication");
	Get_Communication("Communication");
	Get_CommunicationList("Communication");
	firstClassItem->setText(0, tr("IED"));
	CurrentNodeType = IED_NODE;
	Get_Node("IEDNODE");
	CurrentNodeType = ROOT_NODE;
	Get_IEDList("IED");
	m_SCDPoint->SwitchRoot();

}
void MainWindow::Init_Menu()
{
	m_SubMenu = new QMenu(this);
	m_IEDMenu = new QMenu(this);
	m_HeaderMenu = new QMenu(this);
	m_CommMenu = new QMenu(this);
	m_DataSetMenu = new QMenu(this);
	m_GSEMenu = new QMenu(this);
	m_SMVMenu = new QMenu(this);
	m_InputMenu = new QMenu(this);
	m_DataMenu = new QMenu(this);
	m_IEDMenu->addAction(ui->actionImport_CID);
	actionAdd = new QAction(tr("Add"), this);
	actionDel = new QAction(tr("Del"), this);
	actionReLoad = new QAction(tr("Reload"), this);
	actionImportOneIed = new QAction(tr("Import One CID"), this);
	actionBatchImportIED = new QAction(tr("Batch Import CID"), this);
	actionExportIed = new QAction(tr("Export IED"), this);
	actionFindIed = new QAction(tr("Find IED"), this);
	actionExtra = new QAction(tr("Extra"), this);
	actionMovUp = new QAction(tr("Move Up"), this);
	actionMovDown = new QAction(tr("Move Down"), this);
	actionConfig = new QAction(tr("Configure"), this);
	actionRename = new QAction(tr("Rename"), this);
	actionDelOneIed = new QAction(tr("Del One IED"), this);
	actionIncrease = new QAction(tr("Increase"), this);
	actionBatch = new QAction(tr("Batch"), this);
	m_HeaderMenu->addAction(actionAdd);
	m_HeaderMenu->addAction(actionDel);
	m_CommMenu->addAction(actionAdd);
	m_CommMenu->addAction(actionDel);
	m_IEDMenu->addAction(actionBatchImportIED);
	m_IEDMenu->addAction(actionDelOneIed);
	m_IEDMenu->addAction(actionReLoad);
	// m_IEDMenu->addAction(actionImportOneIed);
	//  m_IEDMenu->addAction(actionExportIed);
	// m_IEDMenu->addAction(actionFindIed);
	//m_SubMenu->addAction(actionExtra);
	m_DataSetMenu->addAction(actionAdd);
	m_DataSetMenu->addAction(actionRename);
	m_DataSetMenu->addAction(actionDel);
	//m_DataMenu->addAction(actionMovUp);
	//m_DataMenu->addAction(actionMovDown);
	m_GSEMenu->addAction(actionAdd);
	m_GSEMenu->addAction(actionDel);
	m_SMVMenu->addAction(actionAdd);
	m_SMVMenu->addAction(actionDel);
	m_InputMenu->addAction(actionConfig);
	//m_InputMenu->addAction(actionDel);
	// m_DataMenu->addAction(actionMovUp);
	//m_DataMenu->addAction(actionMovDown);
	m_DataMenu->addAction(actionDel);
	//m_InputMenu->addAction(actionMovUp);
	//m_InputMenu->addAction(actionMovDown);

}
void MainWindow::SCLTree_MousEvent(const QPoint &pos)
{
	QTreeWidgetItem* curItem = ui->SCLTree->itemAt(pos);
	if (curItem == NULL)return;
	QString title;
	title = curItem->text(0);

	openMenuProgram(curItem, 0);

	if (title == tr("Header"))
	{

	}
	else if (title == tr("Substation"))
	{
		SCLTree_SubStation_RightClick(pos);

		return;
	}
	else if (title == tr("Communication"))
	{

		return;
	}
	else if (title == tr("IED"))
	{
		SCLTree_IED_RightClick(pos);
		return;

	}

}
void MainWindow::TableView_MousEvent(const QPoint &pos)
{
	actionDel->setEnabled(false);
	actionIncrease->setEnabled(true);
	actionDel->setEnabled(false);
	actionRename->setEnabled(false);
	actionDel->setEnabled(false);
	//actionExtra->setEnabled(true);
	if (CurrentNodeType == HEAD_NODE)
	{
		actionDel->setEnabled(false);
		//m_HeaderMenu->exec(QCursor::pos());
	}
	if (CurrentNodeType == COMMUNICATION_NODE)
	{

	}
	if (CurrentNodeType == SUBNET_NODE)
	{
		m_SubMenu->clear();
		if (ChildNodeType == NODE_MMSNET)
		{
			m_ModelSlection = ui->tableView->selectionModel();

			QModelIndexList indexes;
			indexes.clear();
			indexes = m_ModelSlection->selectedIndexes();

			if (indexes.size() == 0)
				return;

			if ((indexes[0].row() == indexes[indexes.size() - 1].row()))
			{
				//actionExtra->setEnabled(false);
				m_SubMenu->addAction(actionExtra);
				QModelIndex index = indexes[0];
				OnMMSClicked(index);
				m_SubMenu->exec(QCursor::pos());
				return;
			}
			else if ((indexes[0].column() == indexes[indexes.size() - 1].column()) && (indexes.size() > 1))
			{
				if (indexes[0].column() > 1)
				{
					if (indexes[0].column() != 2)
					{
						actionIncrease->setEnabled(false);
					}
					m_SubMenu->addAction(actionIncrease);
					m_SubMenu->addAction(actionBatch);
					m_SubMenu->exec(QCursor::pos());
					return;
				}

			}


		}
		if ((ChildNodeType == NODE_GOOSENET) || (ChildNodeType == NODE_SMVNET))
		{
			m_ModelSlection = ui->tableView->selectionModel();

			QModelIndexList indexes;
			indexes.clear();
			indexes = m_ModelSlection->selectedIndexes();

			if (indexes.size() == 0)
				return;
			if ((indexes[0].column() == indexes[indexes.size() - 1].column()) && (indexes.size() > 1))
			{
				if (indexes[0].column() > 3)
				{
					if ((indexes[0].column() != 4) && (indexes[0].column() != 5))
					{
						actionIncrease->setEnabled(false);
					}
					m_SubMenu->addAction(actionIncrease);
					m_SubMenu->addAction(actionBatch);
					m_SubMenu->exec(QCursor::pos());
					return;
				}

			}


		}
	}
	if (CurrentNodeType == NODE_IED)
	{
		QModelIndexList indexes;
		switch (ChildNodeType) {
		case NODE_LD:

			break;
		case NODE_LN:

			break;
		case NODE_DATASET:




			m_ModelSlection = ui->tableView->selectionModel();


			indexes.clear();
			indexes = m_ModelSlection->selectedIndexes();

			if (indexes.size() != 0)
			{
				actionRename->setEnabled(true);
				actionDel->setEnabled(true);

			}
            if(indexes.size()==2)
            {
                QString strname = m_ModelIED_DataSet->data(m_ModelIED_DataSet->index(indexes.at(0).row(), 0)).toString();
                currentDataset =strname;
            }

			m_DataSetMenu->exec(QCursor::pos());
			break;
		case NODE_GSE:

			m_ModelSlection = ui->tableView->selectionModel();


			indexes.clear();
			indexes = m_ModelSlection->selectedIndexes();
			if (indexes.size() != 0)
			{
				actionDel->setEnabled(true);
			}
			m_GSEMenu->exec(QCursor::pos());
			break;
		case NODE_INPUT:
			m_ModelSlection = ui->tableView->selectionModel();


			indexes.clear();
			indexes = m_ModelSlection->selectedIndexes();
			if (indexes.size() == 0)
			{
				actionDel->setEnabled(false);
			}

			m_InputMenu->exec(QCursor::pos());
			break;
		case NODE_SMV:
			m_ModelSlection = ui->tableView->selectionModel();


			indexes.clear();
			indexes = m_ModelSlection->selectedIndexes();
			if (indexes.size() != 0)
			{
				actionDel->setEnabled(true);
			}
			m_SMVMenu->exec(QCursor::pos());
			break;
		case NODE_LOG:

			break;
		case NODE_REPORT:

			break;
		case NODE_DATA:
			ChildNodeType = NODE_DATASET;
			m_ModelIED_DataSetData->setRowCount(0);
			ui->tableView_data->hide();
			if (!currentDataset.isEmpty())
			{
				m_SCDPoint->UpdataBLKConfRev(strIEDname, currentLD, currentDataset, DataSet_Change);
				DataSet_Change = false;
			}
			ui->frame->hide();
			TableView_MousEvent(pos);
			break;
		default:
			break;
		}
	}
}
void MainWindow::SubstationTree_MousEvent(const QPoint &pos)
{
	QTreeWidgetItem* curItem = ui->SubstationTree->itemAt(pos);
	if (curItem == NULL)return;
}
void MainWindow::IEDTree_MousEvent(const QPoint &pos)
{
	QTreeWidgetItem* curItem = ui->IEDTree->itemAt(pos);
	if (curItem == NULL)return;
}
void MainWindow::SCLTree_IED_RightClick(const QPoint &pos)
{
	m_IEDMenu->exec(QCursor::pos());
}
void MainWindow::SCLTree_SubStation_RightClick(const QPoint &pos)
{

}
void MainWindow::Header_DoublClick(QModelIndex index)
{

}
void MainWindow::openMenuProgram(QTreeWidgetItem *Item, int column)
{
	CurrentItem = Item;
	QString title = Item->text(0);
	m_SCDPoint->SwitchRoot();
	if (title == tr("Header"))
	{
		CurrentNodeType = HEAD_NODE;
		CurrentTitle = title;
		ChildNodeType = 0;
		SCLTree_Header_DoubleClick(title);
		return;
	}
	else if (title == tr("Substation"))
	{
		CurrentNodeType = STATION_NODE;
		CurrentTitle = title;
		ChildNodeType = 0;
		SCLTree_SubStation_DoubleClick(title);
		return;
	}
	else if (title == tr("Communication"))
	{
		CurrentNodeType = COMMUNICATION_NODE;
		CurrentTitle = title;
		ChildNodeType = 0;
		SCLTree_Communication_DoubleClick(title);
		return;
	}
	else if (title == tr("IED"))
	{

		CurrentNodeType = IED_NODE;

		if (CurrentTitle != title)
		{

			SCLTree_IEDNODE_DoubleClick("IEDNODE");
		}
		if (CurrentTitle == title)
		{
			Get_Node("IEDNODE");
			DisplayIEDnode("IEDNODE");

		}
		CurrentTitle = title;
		//SCLTree_IEDNODE_DoubleClick("IEDNODE");
		return;
	}
	else
	{

		QString str = Item->parent()->text(0);
		if (str == tr("IED"))
		{
			if (title == CurrentTitle)
				return;
			CurrentTitle = title;
			CurrentNodeType = NODE_IED;
			SCLTree_IED_DoubleClick(title);
			return;
		}
		else if (str == tr("Communication"))
		{
			//CurrentNodeType = COMMUNICATION_NODE;
			//if (title == CurrentTitle)
			//	return;
			CurrentTitle = title;
			CurrentNodeType = SUBNET_NODE;
			SCLTree_SubNet_DoubleClick(CurrentTitle);
			return;
		}
	}
}
void MainWindow::SCLTree_Header_DoubleClick(QString str)
{
	Element_Hide(str);

	Init_Header();
	Get_Node(str);
	DisplayHeader(str);
}

void MainWindow::SCLTree_SubStation_DoubleClick(QString str)
{
	Element_Hide(str);

	Init_Substation();
}

void MainWindow::SCLTree_Communication_DoubleClick(QString str)
{
	Element_Hide(str);

	Init_Communication();
	Get_Node(str);
	//Get_CommunicationList("Communication");

	DisplayCommunication(str);
}

void MainWindow::SCLTree_IED_DoubleClick(QString str)
{

	Element_Hide(str);

	PushButton_LogicDevice_Click();
}

void MainWindow::SCLTree_IEDNODE_DoubleClick(QString str)
{

	Element_Hide(str);
	Init_IED();
	DisplayIEDnode("IEDNODE");


}
void MainWindow::SCLTree_SubNet_DoubleClick(QString str)
{


	
	if (str.contains("GOOSE",Qt::CaseInsensitive))
	{
		CurrentNodeType = SUBNET_NODE;
		ChildNodeType = NODE_GOOSENET;
		Element_Hide("GOOSE-Subnet");
		Init_GOOSENET();
		DisplayGOOSENet(str);
		return;
	}
	else if (str.contains("SMV", Qt::CaseInsensitive) || str.contains("SV", Qt::CaseInsensitive))
	{
		CurrentNodeType = SUBNET_NODE;
		ChildNodeType = NODE_SMVNET;
		Element_Hide("SMV-Subnet");

		Init_SMVNET();
		DisplaySMVNet(str);
		return;
	}else 
	{
		CurrentNodeType = SUBNET_NODE;
		ChildNodeType = NODE_MMSNET;
		Element_Hide("MMS-Subnet");

		Init_MMSNET();
		DisplayMMSNet(str);
		return;
	}
}


void MainWindow::Init_Header()
{
	//设置表头
	//QStringList header;
	headerList.clear();
	headerList << tr("version") << tr("reVersion") << tr("When") << tr("who") << tr("what") << tr("why");

	//设置table的大小
	//ui->tableView->setColumnCount(header.size());
	// ui->tableView->setHorizontalHeaderLabels(header);
	//ui->tableWidget->setColumnCount(wColCount);
	ui->tableView->setSelectionBehavior(QAbstractItemView::SelectItems); //设置选择行为，以行为单位
	ui->tableView->setSelectionMode(QAbstractItemView::SingleSelection); //设置选择模式，选择单行
	m_ModelHeader->clear();

	disconnect(m_ModelHeader, SIGNAL(dataChanged(const QModelIndex &, const QModelIndex &)), this, SLOT(OnHeaderDataChanged(const QModelIndex &, const QModelIndex &)));
	m_ModelHeader->setColumnCount(headerList.count());

	ui->tableView->setModel(m_ModelHeader);

	for (int i = 0; i < headerList.count(); i++)
	{
		m_ModelHeader->setHeaderData(i, Qt::Horizontal, headerList.at(i));
	}
	ui->tableView->setColumnWidth(0, 100);
	ui->tableView->setColumnWidth(1, 100);
	ui->tableView->setColumnWidth(2, 200);
	ui->tableView->setColumnWidth(3, 100);
	ui->tableView->setColumnWidth(4, 300);
	ui->tableView->setColumnWidth(5, 300);

	//ui->tableView->setColumnWidth(6,300);
	//ui->tableView->resizeRowsToContents();
	connect(m_ModelHeader, SIGNAL(dataChanged(const QModelIndex &, const QModelIndex &)), this, SLOT(OnHeaderDataChanged(const QModelIndex &, const QModelIndex &)));

}

void MainWindow::Init_Substation()
{
	headerList.clear();
	headerList << tr("SubNet Name") << tr("SubNet Type") << tr("SubNet Desc");

	ui->tableView->setSelectionBehavior(QAbstractItemView::SelectItems); //设置选择行为，以行为单位
	ui->tableView->setSelectionMode(QAbstractItemView::SingleSelection); //设置选择模式，选择单行
	m_ModelSubNet->clear();
	ClearTableDelegate(headerList.size());
	disconnect(m_ModelSubNet, SIGNAL(dataChanged(const QModelIndex &, const QModelIndex &)), this, SLOT(OnSubnetDataChanged(const QModelIndex &, const QModelIndex &)));
	m_ModelSubNet->setColumnCount(headerList.count());

	ui->tableView->setModel(m_ModelSubNet);

	for (int i = 0; i < headerList.count(); i++)
	{
		m_ModelSubNet->setHeaderData(i, Qt::Horizontal, headerList.at(i));
	}
	ui->tableView->setColumnWidth(0, 200);
	ui->tableView->setColumnWidth(1, 200);
	ui->tableView->setColumnWidth(2, 200);


	connect(m_ModelSubNet, SIGNAL(dataChanged(const QModelIndex &, const QModelIndex &)), this, SLOT(OnSubnetDataChanged(const QModelIndex &, const QModelIndex &)));

}

void MainWindow::Init_Communication()
{
	headerList.clear();
	headerList << tr("SubNet Name") << tr("SubNet Type") << tr("SubNet Desc");


	ui->tableView->setSelectionBehavior(QAbstractItemView::SelectItems); //设置选择行为，以行为单位
	ui->tableView->setSelectionMode(QAbstractItemView::SingleSelection); //设置选择模式，选择单行
	m_ModelCommunication->clear();
	ClearTableDelegate(headerList.size());
	disconnect(m_ModelCommunication, SIGNAL(dataChanged(const QModelIndex &, const QModelIndex &)), this, SLOT(OnCommDataChanged(const QModelIndex &, const QModelIndex &)));
	m_ModelCommunication->setColumnCount(headerList.count());

	ui->tableView->setModel(m_ModelCommunication);
	SubNetTypeCombobox* pSubNetType = new SubNetTypeCombobox(this);

	ui->tableView->setItemDelegateForColumn(1, pSubNetType);

	for (int i = 0; i < headerList.count(); i++)
	{
		m_ModelCommunication->setHeaderData(i, Qt::Horizontal, headerList.at(i));
	}
	ui->tableView->setColumnWidth(0, 200);
	ui->tableView->setColumnWidth(1, 200);
	ui->tableView->setColumnWidth(2, 200);


	//ui->tableView->setColumnWidth(6,300);
	//ui->tableView->resizeRowsToContents();
	connect(m_ModelCommunication, SIGNAL(dataChanged(const QModelIndex &, const QModelIndex &)), this, SLOT(OnCommDataChanged(const QModelIndex &, const QModelIndex &)));

}

void MainWindow::Init_IED()
{
	headerList.clear();
	headerList << tr("IED Name") << tr("IED Type") << tr("IED Vender") << tr("IED Version") << tr("IED Desc");


	ui->tableView->setSelectionBehavior(QAbstractItemView::SelectItems); //设置选择行为，以行为单位
	ui->tableView->setSelectionMode(QAbstractItemView::SingleSelection); //设置选择模式，选择单行
	m_ModelIEDNode->clear();
	ClearTableDelegate(headerList.size());
	disconnect(m_ModelIEDNode, SIGNAL(dataChanged(const QModelIndex &, const QModelIndex &)), this, SLOT(OnIEDDataChanged(const QModelIndex &, const QModelIndex &)));
	m_ModelIEDNode->setColumnCount(headerList.count());
	//int i = m_ModelIEDNode->columnCount();
	ui->tableView->setModel(m_ModelIEDNode);
	for (int i = 0; i < headerList.count(); i++)
	{
		m_ModelIEDNode->setHeaderData(i, Qt::Horizontal, headerList.at(i));
	}
	ui->tableView->setColumnWidth(0, 200);
	ui->tableView->setColumnWidth(1, 200);
	ui->tableView->setColumnWidth(2, 200);

	connect(m_ModelIEDNode, SIGNAL(dataChanged(const QModelIndex &, const QModelIndex &)), this, SLOT(OnIEDDataChanged(const QModelIndex &, const QModelIndex &)));

}

void MainWindow::Init_IEDNODE()
{
	headerList.clear();
	headerList << tr("IED Name") << tr("IED Type") << tr("IED Vender") << tr("IED Version") << tr("IED Desc");


	ui->tableView->setSelectionBehavior(QAbstractItemView::SelectItems); //设置选择行为，以行为单位
	ui->tableView->setSelectionMode(QAbstractItemView::SingleSelection); //设置选择模式，选择单行
	m_ModelIEDNode->clear();
	ClearTableDelegate(headerList.size());
	disconnect(m_ModelIEDNode, SIGNAL(dataChanged(const QModelIndex &, const QModelIndex &)), this, SLOT(OnIEDDataChanged(const QModelIndex &, const QModelIndex &)));
	m_ModelIEDNode->setColumnCount(headerList.count());
	//int i = m_ModelIEDNode->columnCount();
	ui->tableView->setModel(m_ModelIEDNode);
	for (int i = 0; i < headerList.count(); i++)
	{
		m_ModelIEDNode->setHeaderData(i, Qt::Horizontal, headerList.at(i));
	}
	ui->tableView->setColumnWidth(0, 200);
	ui->tableView->setColumnWidth(1, 200);
	ui->tableView->setColumnWidth(2, 200);

	connect(m_ModelIEDNode, SIGNAL(dataChanged(const QModelIndex &, const QModelIndex &)), this, SLOT(OnIEDDataChanged(const QModelIndex &, const QModelIndex &)));

}
void MainWindow::Init_SubNet()
{
	headerList.clear();
	headerList << tr("IED Name") << tr("Access Point") << tr("cb Name") << tr("ldinist") << tr("Mac Address") << tr("APPID") << tr("Desc")
		<< tr("VLAN ID") << tr("VLAN Priority");

	ClearTableDelegate(headerList.size());
	//ui->tableView->setSelectionBehavior(QAbstractItemView::SelectItems); //设置选择行为，以行为单位
	//ui->tableView->setSelectionMode(QAbstractItemView::SingleSelection); //设置选择模式，选择单行
	//m_ModelIEDNode->clear();

	//disconnect(m_ModelIEDNode, SIGNAL(dataChanged(const QModelIndex &, const QModelIndex &)), this, SLOT(OnCommDataChanged(const QModelIndex &, const QModelIndex &)));
	//m_ModelIEDNode->setColumnCount(headerList.count());

	//ui->tableView->setModel(m_ModelIEDNode);
	//for (int i = 0; i<headerList.count(); i++)
	//{
	//	m_ModelIEDNode->setHeaderData(i, Qt::Horizontal, headerList.at(i));
	//}
	//ui->tableView->setColumnWidth(0, 200);
	//ui->tableView->setColumnWidth(1, 200);
	//ui->tableView->setColumnWidth(2, 200);


	////ui->tableView->setColumnWidth(6,300);
	////ui->tableView->resizeRowsToContents();
	//connect(m_ModelIEDNode, SIGNAL(dataChanged(const QModelIndex &, const QModelIndex &)), this, SLOT(OnCommDataChanged(const QModelIndex &, const QModelIndex &)));

}

void MainWindow::Element_Hide(QString str)
{

	ui->frame->hide();
	ui->Button_DataSet->hide();
	ui->Button_GSE->hide();
	ui->Button_Input->hide();
	ui->Button_Log->hide();
	ui->Button_LogicDevice->hide();
	ui->Button_LogiceNode->hide();
	ui->Button_Report->hide();
	ui->Button_SMV->hide();
	ui->Button_Add->hide();
	ui->Button_Del->hide();
	ui->SubstationTree->hide();
	ui->tableView->show();
	ui->label_LD->hide();
	ui->label_LN->hide();
	ui->comboBox_LD->hide();
	ui->comboBox_LN->hide();
	if (!currentDataset.isEmpty())
	{
		m_SCDPoint->UpdataBLKConfRev(strIEDname, currentLD, currentDataset, DataSet_Change);
		DataSet_Change = false;
	}
	ui->tableView_data->hide();
	ui->pushButton_Addres->hide();
	ui->pushButton_GSE->hide();
	ui->pushButton_SMV->hide();
	if (CurrentNodeType == HEAD_NODE)
	{

	}
	else if (CurrentNodeType == STATION_NODE)
	{
		ui->tableView->hide();
		ui->SubstationTree->show();
	}
	else if (CurrentNodeType == COMMUNICATION_NODE)
	{
		ui->IEDTree->clear();
	}
	else if (CurrentNodeType == NODE_IED)
	{
		ui->Button_DataSet->show();
		ui->Button_GSE->show();
		ui->Button_Input->show();
		ui->Button_Log->show();
		ui->Button_LogicDevice->show();
		ui->Button_LogiceNode->show();
		ui->Button_Report->show();
		ui->Button_SMV->show();
		ui->comboBox_LD->show();
		ui->comboBox_LN->show();
		ui->label_LD->show();
		ui->label_LN->show();
	}
	else if (CurrentNodeType == SUBNET_NODE)
	{
		ui->frame->hide();
		ui->label_LN_C->hide();
		ui->lineEdit_LN->hide();
		ui->checkBox_DA->hide();
		ui->label_DA->hide();
		ui->lineEdit_DA->hide();
		ui->label_AP->hide();
		ui->comboBox_AP->hide();
		ui->label_FC->hide();
		ui->comboBox_FC->hide();
		ui->checkBox_Disp->hide();
		ui->checkBox_DA_END->hide();
		ui->pushButton_fresh->hide();
	}

	else if (CurrentNodeType == ROOT_NODE)
	{

	}
}
void MainWindow::Action_Add()
{
	if (CurrentNodeType == HEAD_NODE)
	{

		AddOneHistory();
		return;

	}
	if (CurrentNodeType == COMMUNICATION_NODE)
	{
		//        int numRows=m_ModelCommunication->rowCount();
		//        QModelIndex index;
		//        QModelIndexList indexes;
		//         QString temp;
		//        m_ModelSlection = ui->tableView->selectionModel();
		//        indexes.clear();
		//        indexes = m_ModelSlection->selectedIndexes();

		//        foreach(index, indexes)
		//        {
		//          temp=m_ModelHeader->data(index).toString();
		//        }
		AddOneSubNet();

	}
	if (CurrentNodeType == NODE_IED)
	{
		switch (ChildNodeType)
		{
		case NODE_LD:

			break;
		case NODE_LN:

			break;
		case NODE_DATASET:
			AddOneDatSet();
			break;
		case NODE_GSE:
			AddOneGSECTRL();
			break;
		case NODE_INPUT:

			break;
		case NODE_SMV:
			AddOneSMVCTRL();
			break;
		case NODE_LOG:

			break;
		case NODE_REPORT:

			break;
		default:
			break;
		}
	}


}
void MainWindow::Action_Del()
{
	if (CurrentNodeType == HEAD_NODE)
	{

		//AddOneHistory();
		return;

	}
	if (CurrentNodeType == COMMUNICATION_NODE)
	{

		QModelIndex index;
		QModelIndexList indexes;
		QString str;
		m_ModelSlection = ui->tableView->selectionModel();
		indexes.clear();
		indexes = m_ModelSlection->selectedIndexes();
		if (indexes.size() == 0)
		{
			return;
		}
		foreach(index, indexes)
		{

			str = m_ModelCommunication->data(m_ModelCommunication->index(index.row(), 0)).toString();
			DelOneSubNet(index, str);
		}


	}
	if (CurrentNodeType == NODE_IED)
	{
		switch (ChildNodeType)
		{
		case NODE_LD:

			break;
		case NODE_LN:

			break;
		case NODE_DATASET:
			DelDataSet();
			break;
		case NODE_DATA:
			DelDataSetData();
			break;
		case NODE_GSE:
			DelOneGSECTRL();
			break;
		case NODE_INPUT:

			break;
		case NODE_SMV:
			DelOneSMVCTRL();
			break;
		case NODE_LOG:

			break;
		case NODE_REPORT:

			break;
		default:
			break;
		}
	}

}

void MainWindow::AddOneHistory()
{

	m_SCDPoint->CreatOneHistory();
	Get_Node(CurrentTitle);
	DisplayHeader("Header");

}

void MainWindow::Get_Node(QString str)
{

	if (CurrentNodeType == HEAD_NODE)
	{
		HistoryItemList.clear();
		m_SCDPoint->GetNode(str);
		m_SCDPoint->GetChild("History");
		return;
	}
	if (CurrentNodeType == COMMUNICATION_NODE)
	{
		m_SCDPoint->GetNode(str);
		m_SCDPoint->GetChildList();
		return;
	}
	if (CurrentNodeType == IED_NODE)
	{
		IedList.clear();
		m_SCDPoint->GetIEDList(IedList);
		return;

	}
	if (CurrentNodeType == NODE_IED)
	{

		strIEDname = str;
		m_SCDPoint->GetIEDByname(str);
		//strIEDname = m_SCDPoint->GetAttribute("name");
		//m_SCDPoint->GetChild();
		return;
	}
}

void MainWindow::AddoneItemToTree(QString str1, QString str2)
{
	QTreeWidgetItem *Item = new QTreeWidgetItem;
	QString str3;
	//QString str;
	//QTextCodec *tc = QTextCodec::codecForName("GBK");
	//str = tc->toUnicode(str1);
	Item->setText(0, str1);

	for (int i = 0; i < T_parent->childCount(); i++)
	{
		str3 = T_parent->child(i)->text(0);
		if (str2 == T_parent->child(i)->text(0))
		{
			T_parent->child(i)->addChild(Item);
		}
	}
	//   CurrentItem->addChild(Item);
}
void MainWindow::PushButton_DataSet_Click()
{
	if (!currentDataset.isEmpty())
	{
		m_SCDPoint->UpdataBLKConfRev(strIEDname, currentLD, currentDataset, DataSet_Change);
		DataSet_Change = false;
	}
	ui->tableView_data->hide();
	ui->comboBox_LD->setDisabled(false);
	ui->comboBox_LN->setDisabled(false);


	Get_Node(CurrentItem->text(0));
	ChildNodeType = NODE_DATASET;
	Init_DataSet();
	Init_Combox_LD();

	ui->comboBox_AP->setFocusPolicy(Qt::NoFocus);
	ui->comboBox_LD->activated(ui->comboBox_LD->currentText());

}

void MainWindow::PushButton_GSE_Click()
{
	if (!currentDataset.isEmpty())
	{
		m_SCDPoint->UpdataBLKConfRev(strIEDname, currentLD, currentDataset, DataSet_Change);
		DataSet_Change = false;
	}
	ui->tableView_data->hide();
	ui->comboBox_LD->setEnabled(true);
	ui->comboBox_LN->setEnabled(false);
	ui->frame->hide();
	Get_Node(CurrentItem->text(0));
	ChildNodeType = NODE_GSE;
	Init_GSE();
	Init_Combox_LD();
	ui->comboBox_LD->activated(ui->comboBox_LD->currentText());
	//    DisplayG();
}

void MainWindow::PushButton_Input_Click()
{
	if (!currentDataset.isEmpty())
	{
		m_SCDPoint->UpdataBLKConfRev(strIEDname, currentLD, currentDataset, DataSet_Change);
		DataSet_Change = false;
	}
	ui->tableView_data->hide();
	ui->comboBox_LD->setEnabled(true);
	ui->comboBox_LN->setEnabled(true);
	ui->frame->hide();
	ChildNodeType = NODE_INPUT;
	Get_Node(CurrentItem->text(0));
	Init_Input();
	Init_Combox_LD();
	ui->comboBox_LD->activated(ui->comboBox_LD->currentText());
}

void MainWindow::PushButton_Log_Click()
{
	if (!currentDataset.isEmpty())
	{
		m_SCDPoint->UpdataBLKConfRev(strIEDname, currentLD, currentDataset, DataSet_Change);
		DataSet_Change = false;
	}
	ui->tableView_data->hide();
	ui->comboBox_LD->setEnabled(true);
	ui->comboBox_LN->setEnabled(true);
	ui->frame->hide();
	Get_Node(CurrentItem->text(0));
	ChildNodeType = NODE_LOG;
	Init_Log();
	Init_Combox_LD();
	ui->comboBox_LD->activated(ui->comboBox_LD->currentText());
}

void MainWindow::PushButton_LogicDevice_Click()
{

	if (!currentDataset.isEmpty())
	{
		m_SCDPoint->UpdataBLKConfRev(strIEDname, currentLD, currentDataset, DataSet_Change);
		DataSet_Change = false;
	}
	ui->tableView_data->hide();
	ui->frame->hide();
	Get_Node(CurrentItem->text(0));
	ChildNodeType = NODE_LD;
	RPT_STATE = m_SCDPoint->GetReportSetting(strIEDname);
	GSE_STATE = m_SCDPoint->GetGSESetting(strIEDname);
	Init_LogicDevice();
	//PushButton_LogicDevice_Click();

	DisplayLD();
}

void MainWindow::PushButton_LogiceNode_Click()
{
	if (!currentDataset.isEmpty())
	{
		m_SCDPoint->UpdataBLKConfRev(strIEDname, currentLD, currentDataset, DataSet_Change);
		DataSet_Change = false;
	}
	ui->tableView_data->hide();
	ui->frame->hide();
	Get_Node(CurrentItem->text(0));
	ChildNodeType = NODE_LN;
	Init_Combox_LD();
	Init_LogiceNode();
	ui->comboBox_LD->setDisabled(false);
	ui->comboBox_LN->setDisabled(true);
	ui->comboBox_LD->activated(ui->comboBox_LD->currentText());
	//PushButton_LogicDevice_Click();


}

void MainWindow::Combox_LN_Active(QString str)
{
	disconnect(ui->comboBox_LN, SIGNAL(activated(QString)), this, SLOT(Combox_LN_Active(QString)));

	switch (ChildNodeType)
	{
	case NODE_LD:

		break;
	case NODE_LN:

		break;
	case NODE_DATASET:

		DisplayDataSet();
		if (!currentDataset.isEmpty())
		{
			m_SCDPoint->UpdataBLKConfRev(strIEDname, currentLD, currentDataset, DataSet_Change);
			DataSet_Change = false;
		}
		ui->tableView_data->hide();
		ui->frame->hide();
		break;
	case NODE_DATA:

		DisplayDataSet();
		if (!currentDataset.isEmpty())
		{
			m_SCDPoint->UpdataBLKConfRev(strIEDname, currentLD, currentDataset, DataSet_Change);
			DataSet_Change = false;
		}
		ui->tableView_data->hide();
		ui->frame->hide();
		break;
	case NODE_GSE:
		DisplayGSE();
		break;
	case NODE_INPUT:
		DisplayInput();
		break;
	case NODE_SMV:
		DisplaySMV();
		break;
	case NODE_LOG:
		DisplayLOG();
		break;
	case NODE_REPORT:
		DisplayRPT();
		break;
	default:
		break;
	}
	connect(ui->comboBox_LN, SIGNAL(activated(QString)), this, SLOT(Combox_LN_Active(QString)));

}

void MainWindow::PushButton_Report_Click()
{
	if (!currentDataset.isEmpty())
	{
		m_SCDPoint->UpdataBLKConfRev(strIEDname, currentLD, currentDataset, DataSet_Change);
		DataSet_Change = false;
	}
	ui->tableView_data->hide();
	ui->comboBox_LD->setEnabled(true);
	ui->comboBox_LN->setEnabled(true);
	ui->frame->hide();
	Get_Node(CurrentItem->text(0));
	ChildNodeType = NODE_REPORT;
	Init_Report();
	Init_Combox_LD();
	ui->comboBox_LD->activated(ui->comboBox_LD->currentText());
}

void MainWindow::PushButton_SMV_Click()
{
	if (!currentDataset.isEmpty())
	{
		m_SCDPoint->UpdataBLKConfRev(strIEDname, currentLD, currentDataset, DataSet_Change);
		DataSet_Change = false;
	}
	ui->tableView_data->hide();
	ui->comboBox_LD->setEnabled(true);
	ui->comboBox_LN->setEnabled(false);
	ui->frame->hide();
	Get_Node(CurrentItem->text(0));
	ChildNodeType = NODE_SMV;
	Init_SMV();
	Init_Combox_LD();
	ui->comboBox_LD->activated(ui->comboBox_LD->currentText());
}











void MainWindow::Init_Combox_LD()
{
	disconnect(ui->comboBox_LD, SIGNAL(activated(QString)), this, SLOT(Combox_LD_Active(QString)));
	ui->comboBox_LD->clear();
	if (m_SCDPoint->GetChild("AccessPoint") == DO_OK)
	{
		QString strAp = m_SCDPoint->GetAttribute("name");
		AddLDToCombox(strAp);
	}
	while (m_SCDPoint->GetNextChild() == DO_OK)
	{
		QString strAp = m_SCDPoint->GetAttribute("name");
		AddLDToCombox(strAp);
	}
	m_SCDPoint->SwitchToIED();
	connect(ui->comboBox_LD, SIGNAL(activated(QString)), this, SLOT(Combox_LD_Active(QString)));
}
void MainWindow::AddLDToCombox(QString strAp)
{
	m_SCDPoint->SetRememberEle();
	m_SCDPoint->GetChild("Server");
	QString strvalue;

	if (m_SCDPoint->GetChild("LDevice") == DO_OK)
	{

		strvalue = m_SCDPoint->GetAttribute("inst");
		ui->comboBox_LD->addItem(strAp + ":" + strvalue);
	}
	else
	{

		return;
	}
	while (m_SCDPoint->GetNextChild() == DO_OK)
	{

		strvalue = m_SCDPoint->GetAttribute("inst");
		ui->comboBox_LD->addItem(strAp + ":" + strvalue);
	}

	m_SCDPoint->switchRememberEle();
}
void MainWindow::Combox_LD_Active(QString str)
{
	disconnect(ui->comboBox_LD, SIGNAL(activated(QString)), this, SLOT(Combox_LD_Active(QString)));
	QStringList strlist;
	QString str_LD = ui->comboBox_LD->currentText();
	QStringList slist = str_LD.split(":");
	currentLD = slist.at(1);
	switch (ChildNodeType)
	{
	case NODE_LD:

		break;
	case NODE_LN:
		DisplayLN(str);
		break;
	case NODE_DATASET:
		Init_Combox_LN(str);
		ui->comboBox_AP->clear();
		strlist.clear();
		strlist = str.split(":");
		ui->comboBox_AP->addItem(strlist.at(0));
		LnodeTyepList.clear();
		m_SCDPoint->GetLNodeTypeList(str, LnodeTyepList);
		DataMatrix_Vector_LD.clear();
		for (int i = 0; i < LnodeTyepList.size(); i++)
		{
			m_SCDPoint->CreatDataMatrix(LnodeTyepList.at(i), DataMatrix_Vector_LD);

		}
		DataInstList_LD.clear();
		m_SCDPoint->GetDataInstList(str, DataInstList_LD);
		ui->comboBox_LN->activated(ui->comboBox_LN->currentText());
		if (!currentDataset.isEmpty())
		{
			m_SCDPoint->UpdataBLKConfRev(strIEDname, currentLD, currentDataset, DataSet_Change);
			DataSet_Change = false;
		}
		ui->tableView_data->hide();
		ui->frame->hide();
		break;
	case NODE_DATA:
		Init_Combox_LN(str);
		ui->comboBox_AP->clear();
		strlist.clear();
		strlist = str.split(":");
		ui->comboBox_AP->addItem(strlist.at(0));
		LnodeTyepList.clear();
		m_SCDPoint->GetLNodeTypeList(str, LnodeTyepList);
		DataMatrix_Vector_LD.clear();
		for (int i = 0; i < LnodeTyepList.size(); i++)
		{
			m_SCDPoint->CreatDataMatrix(LnodeTyepList.at(i), DataMatrix_Vector_LD);
		}
		DataInstList_LD.clear();
		m_SCDPoint->GetDataInstList(str, DataInstList_LD);
		ui->comboBox_LN->activated(ui->comboBox_LN->currentText());
		if (!currentDataset.isEmpty())
		{
			m_SCDPoint->UpdataBLKConfRev(strIEDname, currentLD, currentDataset, DataSet_Change);
			DataSet_Change = false;
		}
		ui->tableView_data->hide();
		ui->frame->hide();
		break;
	case NODE_GSE:
		Init_Combox_LN(str);
		ui->comboBox_LN->setEnabled(false);
		ui->comboBox_LN->activated(ui->comboBox_LD->currentText());
		//DisplayGSE();
		break;
	case NODE_INPUT:
		Init_Combox_LN(str);
		ui->comboBox_LN->activated(ui->comboBox_LD->currentText());
		break;
	case NODE_SMV:
		Init_Combox_LN(str);
		ui->comboBox_LN->setEnabled(false);
		DisplaySMV();
		break;
	case NODE_LOG:
		Init_Combox_LN(str);
		ui->comboBox_LN->setEnabled(false);
		ui->comboBox_LN->activated(ui->comboBox_LD->currentText());
		break;
	case NODE_REPORT:
		Init_Combox_LN(str);
		str = ui->comboBox_LN->currentText();
		ui->comboBox_LN->activated(ui->comboBox_LD->currentText());
		break;
	default:
		break;
	}
	connect(ui->comboBox_LD, SIGNAL(activated(QString)), this, SLOT(Combox_LD_Active(QString)));
}
void MainWindow::Init_Combox_LN(QString strLD)
{
	disconnect(ui->comboBox_LN, SIGNAL(activated(QString)), this, SLOT(Combox_LN_Active(QString)));
	ui->comboBox_LN->clear();
	QStringList strlist;


	strlist = strLD.split(":");
	QString strap, strldev;
	strap = strlist[0];

	strldev = strlist[1];
	QStringList LnList;
	int recode = m_SCDPoint->GetLnListFromLD(strIEDname, strldev, LnList);
	ui->comboBox_LN->addItems(LnList);
	ui->comboBox_LN->setCurrentIndex(0);
	m_SCDPoint->SwitchToIED();
	connect(ui->comboBox_LN, SIGNAL(activated(QString)), this, SLOT(Combox_LN_Active(QString)));
}
void MainWindow::AddLNToCombox(QString strAp)
{

	QString strvalue, str;
	str = m_SCDPoint->GetAttribute("prefix");
	if (str != NULL)
	{
		strvalue += str;
	}
	//strvalue+=str;
	str = m_SCDPoint->GetAttribute("lnClass");
	if (str != NULL)
	{
		strvalue += str;
	}
	str = m_SCDPoint->GetAttribute("inst");
	if (str != NULL)
	{
		strvalue += str;
	}
	ui->comboBox_LN->addItem(strvalue);

}
int MainWindow::GetCurrentLD()
{

	QString strap_ld;
	strap_ld = ui->comboBox_LD->currentText();

	QString strap, strld;
	QStringList strlist;
	strlist = strap_ld.split(":"),
		strap = strlist[0];
	strld = strlist[1];
	m_ModelIED_DataSetData->setRowCount(0);
	int recode = m_SCDPoint->GetAccessPoint(strap);
	recode = m_SCDPoint->GetChild("Server");
	if (m_SCDPoint->GetChildByname_value("LDevice", "inst", strld) != DO_OK)
	{
		return DO_FAIL;
	}
	return DO_OK;
}
int MainWindow::GetSpecifytLD(QByteArray strLDname)
{

	QString strap_ld;
	strap_ld = ui->comboBox_LD->currentText();

	QString strap;
	QStringList strlist;
	strlist = strap_ld.split(":"),
		strap = strlist[0];
	m_ModelIED_DataSetData->setRowCount(0);
	int recode = m_SCDPoint->GetAccessPoint(strap);
	recode = m_SCDPoint->GetChild("Server");
	if (m_SCDPoint->GetChildByname_value("LDevice", "inst", strLDname) != DO_OK)
	{
		return DO_FAIL;
	}
	return DO_OK;
}
int MainWindow::GetCurrentLN()
{

	QString ln_prefix, ln_lnclass, ln_inst;
	QString strln = ui->comboBox_LN->currentText();
	QStringList strlist = strln.split("_");
	if (strlist.size() == 3)
	{
		ln_prefix = strlist[0];
		ln_lnclass = strlist[1];
		ln_inst = strlist[2];

		if (m_SCDPoint->GetChildByname_value("LN", "prefix", ln_prefix, "lnClass", ln_lnclass, "inst", ln_inst) == DO_OK)
		{

			return DO_OK;
		}
	}
	else if (strlist.size() == 2)
	{
		ln_lnclass = strlist[0];
		ln_inst = strlist[1];

		if (m_SCDPoint->GetChildByname_value("LN", "prefix", ln_lnclass, "inst", ln_inst, NULL, NULL) == DO_OK)
		{

			return DO_OK;
		}

	}
	else if (strlist.size() == 1)
	{
		ln_lnclass = strlist[0];

		if (m_SCDPoint->GetChildByname_value("LN0", "lnClass", ln_lnclass) == DO_OK)
		{
			//m_SCDPoint->SwitchToIED();
			return DO_OK;
		}
	}

	return DO_FAIL;
}
int MainWindow::GetSpecifytLN(QString strapname, QString strLNname, QString &LDName, QVector<LN_InstStruct>& instList)
{
	QStringList ldnamelist;
	LN_InstStruct Ln_inst;
	int recode = m_SCDPoint->GetAccessPoint(strapname);
	recode = m_SCDPoint->GetChild("Server");
	recode = m_SCDPoint->GetChild("LDevice");
	LDName = m_SCDPoint->GetAttribute("inst");
	if (recode == DO_FAIL)
	{
		return DO_FAIL;
	}
	ldnamelist.append(LDName);
	while (m_SCDPoint->GetNextChild() != DO_FAIL)
	{
		LDName = m_SCDPoint->GetAttribute("inst");
		ldnamelist.append(LDName);
	}
	m_SCDPoint->SwitchToIED();
	for (int i = 0; i < ldnamelist.size(); i++)
	{
		recode = m_SCDPoint->GetAccessPoint(strapname);
		recode = m_SCDPoint->GetChild("Server");
		recode = m_SCDPoint->GetChildByname_value("LDevice", "inst", ldnamelist[i]);
		if (m_SCDPoint->GetChildByname_value("lnClass", strLNname.toLocal8Bit().data()) == DO_OK)
		{
			Ln_inst.B_ldinst = ldnamelist[i];
			Ln_inst.B_inst = m_SCDPoint->GetAttribute("inst");
			Ln_inst.B_lnType = m_SCDPoint->GetAttribute("lnType");
			Ln_inst.B_prefix = m_SCDPoint->GetAttribute("prefix");
			Ln_inst.B_lnClass = m_SCDPoint->GetAttribute("lnClass");
			Ln_inst.B_desc = m_SCDPoint->GetAttribute("desc");
			instList.append(Ln_inst);
			//return DO_OK;
		}
		else
		{
			m_SCDPoint->SwitchToIED();
			continue;
		}
		while (m_SCDPoint->GetNextChild() != DO_FAIL)
		{
			if (m_SCDPoint->GetAttribute("lnClass") == strLNname)
			{
				Ln_inst.B_ldinst = ldnamelist[i];
				Ln_inst.B_inst = m_SCDPoint->GetAttribute("inst");
				Ln_inst.B_lnType = m_SCDPoint->GetAttribute("lnType");
				Ln_inst.B_prefix = m_SCDPoint->GetAttribute("prefix");
				Ln_inst.B_lnClass = m_SCDPoint->GetAttribute("lnClass");
				Ln_inst.B_desc = m_SCDPoint->GetAttribute("desc");
				instList.append(Ln_inst);
			}
		}


	}
	m_SCDPoint->SwitchToIED();
	return DO_OK;
}


void MainWindow::Action_Rename()
{
	disconnect(actionRename, SIGNAL(triggered()), this, SLOT(Action_Rename()));

	QModelIndex index;
	QModelIndexList indexes;
	QString str1, str2;
	switch (ChildNodeType)
	{
	case NODE_LD:

		break;
	case NODE_LN:

		break;
	case NODE_DATASET:

		m_ModelSlection = ui->tableView->selectionModel();
		indexes.clear();
		indexes = m_ModelSlection->selectedIndexes();
		if (indexes.size() == 0)
		{
			return;
		}
		foreach(index, indexes)
		{

			str1 = m_ModelIED_DataSet->data(m_ModelIED_DataSet->index(index.row(), 0)).toString();
			str2 = m_ModelIED_DataSet->data(m_ModelIED_DataSet->index(index.row(), 1)).toString();
			RenameOneDatSet(str1, str2);
			break;
		}
		break;
	case NODE_GSE:

		break;
	case NODE_INPUT:

		break;
	case NODE_SMV:

		break;
	case NODE_LOG:

		break;
	case NODE_REPORT:

		break;
	default:
		break;
	}
	connect(actionRename, SIGNAL(triggered()), this, SLOT(Action_Rename()));

}
void MainWindow::OnTableViewClicked(const QModelIndex &index)
{
	if (CurrentNodeType == HEAD_NODE)
	{


		return;

	}
	if (CurrentNodeType == SUBNET_NODE)
	{
		if (ChildNodeType == NODE_MMSNET)
			OnMMSClicked(index);
		return;
	}
	if (CurrentNodeType == NODE_IED)
	{
		switch (ChildNodeType)
		{
		case NODE_LD:

			break;
		case NODE_LN:

			break;
		case NODE_DATASET:

			break;
		case NODE_GSE:
			OnGSECtrlClicked(index);
			break;
		case NODE_INPUT:

			break;
		case NODE_SMV:
			OnSMVCtrlClicked(index);
			break;
		case NODE_LOG:
			OnLOGCtrlClicked(index);
			break;
		case NODE_REPORT:
			OnRPTCtrlClicked(index);
			break;
		default:
			break;
		}
	}

}
void MainWindow::OnTableViewdoubleClicked(const QModelIndex &index)
{
	if (CurrentNodeType == HEAD_NODE)
	{


		return;

	}
	if (CurrentNodeType == COMMUNICATION_NODE)
	{
		return;
	}
	if (CurrentNodeType == NODE_IED)
	{
		switch (ChildNodeType)
		{
		case NODE_LD:

			break;
		case NODE_LN:

			break;
		case NODE_DATASET:

			break;
		case NODE_GSE:
			//OnGSECtrlClicked(index);
			break;
		case NODE_INPUT:

			break;
		case NODE_SMV:
			//OnSMVCtrlClicked(index);
			break;
		case NODE_LOG:
			OnLOGCtrldoubleClicked(index);
			break;
		case NODE_REPORT:
			OnRPTCtrldoubleClicked(index);
			break;
		default:
			break;
		}
	}

}

void MainWindow::Action_Config()
{
	disconnect(actionConfig, SIGNAL(triggered()), this, SLOT(Action_Config()));
	if (ChildNodeType == NODE_INPUT)
	{
		Change_Flag = 1;
		InputDialog *m_dlg = new InputDialog(this);
		m_dlg->m_scdpoint = m_SCDPoint;
		m_dlg->m_scdpoint->SwitchRoot();
		m_dlg->strcuried = strIEDname;
		m_dlg->Init_dlg();
		m_dlg->exec();
		m_SCDPoint->CleanInvalidInput(strIEDname);
	}
	ui->comboBox_LD->activated(ui->comboBox_LD->currentText());
	connect(actionConfig, SIGNAL(triggered()), this, SLOT(Action_Config()));

}

void MainWindow::ClearTableDelegate(int size)
{
	for (int i = 0; i < size; i++)
	{
		ui->tableView->setItemDelegateForColumn(i, ui->tableView->itemDelegateForColumn(0));
	}
}
void MainWindow::Action_Model_validation_check()
{
	LegitimacyVerification m_check;
	m_check.m_Point = m_SCDPoint;
	m_check.exec();
}
void MainWindow::Action_Type_Terminal_check()
{
	TerminalTypeCheck *m_dlg = new TerminalTypeCheck();
	m_dlg->Point = m_SCDPoint;

	m_dlg->GetIDEList();
	m_dlg->init_dlg();
	m_dlg->DisplayIED();
	m_dlg->exec();
}
void MainWindow::Action_IECConfig()
{
	IECCONFIG m_dlg;
    for(int i=0;i<IedList.size();i++)
    {
       m_dlg.IED_List.append(IedList.at(i).s_IEDname);
    }
	m_dlg.Init_dlg();
	m_dlg.exec();
}
void MainWindow::Action_LogicMap()
{
	LogicMap m_dlg;
	m_dlg.Point_SCD = m_SCDPoint;
	m_dlg.Initcombox_ied();
	m_dlg.exec();
}
void MainWindow::Action_BatchImport()
{
	QStringList filelist;
	QList<QString> keyList;
	QMap <QString, QString>File_Map;
	int irecode;
	filelist = QFileDialog::getOpenFileNames(
		this,
		"Select one or more files to open",
		QDir::currentPath(),
		"CID (*.CID *.cid)");
	if (filelist.size() == 0)
	{
		return;
	}
	BatchImportCID m_dlg;
	m_dlg.fileList = filelist;
	m_dlg.SetPoint(m_SCDPoint);
	m_dlg.Init_dlg();
	m_dlg.Display();
	if (m_dlg.exec() == QDialog::Accepted)
	{
		File_Map = m_dlg.File_Map;
		keyList = File_Map.keys();
		for (int i = 0; i < keyList.size(); i++)
		{
			if (m_SCDPoint->CheckIEDName(keyList[i]) == DO_FAIL)
			{
				QMessageBox::about(0, tr("Alarm"), tr("The IED Name %1 is exist!").arg(keyList[i]));
				continue;
			}
			if (File_Map.value(keyList[i]).contains(".CID", Qt::CaseInsensitive))
			{
				irecode = m_SCDPoint->ImportCID(File_Map.value(keyList[i]), keyList[i]);
				if (irecode != DO_OK)
				{
					Version_Flag = 1;
					Get_Node("IEDNODE");
					CurrentItem->takeChildren();
					Get_IEDList("IED");
					DisplayIEDnode("IEDNODE");
					return;
				}
				continue;
			}
			else if (File_Map.value(keyList[i]).contains(".ICD", Qt::CaseInsensitive))
			{
				irecode = m_SCDPoint->ImportICD(File_Map.value(keyList[i]), keyList[i]);
				if (irecode != DO_OK)
				{
					Version_Flag = 1;
					Get_Node("IEDNODE");
					CurrentItem->takeChildren();
					Get_IEDList("IED");
					DisplayIEDnode("IEDNODE");
					return;
				}
				continue;

			}

		}
		Get_Node("IEDNODE");
		CurrentItem->takeChildren();
		Get_IEDList("IED");
		DisplayIEDnode("IEDNODE");
	}
}
void MainWindow::DataSetDate_MousEvent(const QPoint &pos)
{
	actionDel->setEnabled(true);
	actionMovUp->setEnabled(true);
	actionMovDown->setEnabled(true);
	QModelIndexList indexes;
	if (m_ModelIED_DataSetData->rowCount() == 0)
	{

		actionDel->setEnabled(false);
		actionMovDown->setEnabled(false);
		actionMovUp->setEnabled(false);
	}
	m_ModelSlection = ui->tableView_data->selectionModel();


	indexes.clear();
	indexes = m_ModelSlection->selectedIndexes();

	if (indexes.size() == 0)
	{
		actionDel->setEnabled(false);
		actionMovUp->setEnabled(false);
		actionMovDown->setEnabled(false);
	}

	m_DataMenu->exec(QCursor::pos());
}
void MainWindow::Action_Reload()
{
	QStringList List;
	QString IEDName;
	ReLoad m_dlg;
	for (int i = 0; i < IedList.size(); i++)
	{
		List.append(IedList[i].s_IEDname);
	}
	m_dlg.IEDList = List;
	m_dlg.Init_dlg();
	m_dlg.Display();
	if (m_dlg.exec() == QDialog::Accepted)
	{
		IEDName = m_dlg.IED_select;
		QString fileName = QFileDialog::getOpenFileName(this,
			tr("Open CID"), QDir::currentPath(), tr("CID Files (*.CID *.cid)"));
		if (!fileName.isEmpty())
		{
			int recode = m_SCDPoint->ReLoadIED(IEDName, fileName);
			if (recode == DO_OK)
			{
				Version_Flag = 1;
				QMessageBox msgBox;
				msgBox.setText(tr("Notice"));
				msgBox.setInformativeText(tr("Reload IED success"));
				msgBox.setStandardButtons(QMessageBox::Ok);
				msgBox.setDefaultButton(QMessageBox::Ok);
				int ret = msgBox.exec();

			}
			else if (recode == DO_FAIL)
			{
				QMessageBox msgBox;
				msgBox.setText(tr("Notice"));
				msgBox.setInformativeText(tr("Reload IED fault"));
				msgBox.setStandardButtons(QMessageBox::Ok);
				msgBox.setDefaultButton(QMessageBox::Ok);
				int ret = msgBox.exec();
			}
			else if (recode == DO_OD)
			{
				QMessageBox msgBox;
				msgBox.setText(tr("Notice"));
				msgBox.setInformativeText(tr("Reload IED cancel"));
				msgBox.setStandardButtons(QMessageBox::Ok);
				msgBox.setDefaultButton(QMessageBox::Ok);
				int ret = msgBox.exec();
			}
		}
		Get_Node("IEDNODE");
		CurrentItem->takeChildren();
		Get_IEDList("IED");
		DisplayIEDnode("IEDNODE");
	}
}
void MainWindow::Action_DelIED()
{
	QStringList List;
	int recode;
	QString IEDName;
	ReLoad m_dlg;
	for (int i = 0; i < IedList.size(); i++)
	{
		List.append(IedList[i].s_IEDname);
	}
	m_dlg.IEDList = List;
	m_dlg.Init_dlg();
	m_dlg.Display();
	if (m_dlg.exec() == QDialog::Accepted)
	{
		IEDName = m_dlg.IED_select;
		int recode = m_SCDPoint->DelOneIED(IEDName);
		if (recode == DO_OK)
		{
			Version_Flag = 1;
			QMessageBox msgBox;
			msgBox.setText("Notice");
			msgBox.setInformativeText("Del IED successed");
			msgBox.setStandardButtons(QMessageBox::Ok);
			msgBox.setDefaultButton(QMessageBox::Ok);
			int ret = msgBox.exec();

		}
		Get_Node("IEDNODE");
		CurrentItem->takeChildren();
		Get_IEDList("IED");
		DisplayIEDnode("IEDNODE");
	}
}
void MainWindow::Action_ExportCID()
{
	ExPortCID m_dlg;
	m_dlg.Point = m_SCDPoint;
	m_dlg.IedList = IedList;
	QFileInfo info;
	info.setFile(SCD_FilePath);
	m_dlg.FileName = info.baseName();
	m_dlg.Init_dlg(4);
	m_dlg.Display();
	m_dlg.exec();
}
void MainWindow::Action_ExportXLS()
{
	ExPortCID m_dlg;
	m_dlg.Point = m_SCDPoint;
	m_dlg.IedList = IedList;
	QFileInfo info;
	info.setFile(SCD_FilePath);
	m_dlg.FileName = info.baseName();
	m_dlg.Init_dlg(2);
	m_dlg.Display();
	m_dlg.exec();
}
void MainWindow::Action_ExportXML()
{
	ExPortCID m_dlg;
	m_dlg.Point = m_SCDPoint;
	m_dlg.IedList = IedList;
	m_dlg.Init_dlg(1);
	m_dlg.Display();
	m_dlg.exec();


}
void MainWindow::ReceiveChange(int state)
{

}
void MainWindow::TableView_Row_Select(QModelIndex row)
{
	if (CurrentNodeType == HEAD_NODE)
	{
		CurrentHistoryItem.Clear();
		CurrentHistoryItem.s_Version = m_ModelHeader->data(m_ModelHeader->index(row.row(), 0)).toString();
		CurrentHistoryItem.s_Reversion = m_ModelHeader->data(m_ModelHeader->index(row.row(), 1)).toString();
		CurrentHistoryItem.s_Time = m_ModelHeader->data(m_ModelHeader->index(row.row(), 2)).toString();
		CurrentHistoryItem.s_Who = m_ModelHeader->data(m_ModelHeader->index(row.row(), 3)).toString();
		CurrentHistoryItem.s_What = m_ModelHeader->data(m_ModelHeader->index(row.row(), 4)).toString();
		CurrentHistoryItem.s_Reason = m_ModelHeader->data(m_ModelHeader->index(row.row(), 5)).toString();


	}
}
void MainWindow::AddNewHistoryItem()
{
	if (Version_Flag != 0)
	{
		m_SCDPoint->AddNewHistoryItem(1);
		return;
	}
	if (Reversion_Flag != 0)
	{
		m_SCDPoint->AddNewHistoryItem(2);
		return;
	}
}
void MainWindow::Action_ClearInput()
{
	Reversion_Flag = 1;
	m_SCDPoint->ClearAllInput();
}
void MainWindow::Auto_AddControlBlock()
{
	m_SCDPoint->Auto_AddControlBlock();
}
void MainWindow::Action_ImportMap()
{
	ImportXLS *m_dlg = new ImportXLS;
	m_dlg->Init_dlg();
	m_dlg->Point = m_SCDPoint;

	if (m_dlg->exec() == QDialog::Accepted)
	{
		m_SCDPoint->ImportXLS(m_dlg->File, m_dlg->IED_Map);
	}
}
void MainWindow::Action_MergeSCD()
{
	MergeSCD *m_dlg = new MergeSCD(this);
	m_dlg->Init_dlg();
	m_dlg->exec();
}

void MainWindow::Action_SwitchLanguage()
{
	delete g_appTranslator;
	g_appTranslator = NULL;

	int lan_int = sender()->property("Language").toInt();
	//QString lan_str = sender()->property("Language").toString();
	switch (lan_int)
	{
	case LANGUAGE_CN:
		g_appTranslator = new QTranslator();
		Language_Type = 1;
		if (false == g_appTranslator->load("./Configuration_zh.qm"))
		{
			QMessageBox::warning(this, tr("Warning"), tr("load Configuration_zh.qm failed."));
			return;
		}
		qApp->installTranslator(g_appTranslator);
		Init_Display();
		break;
	case LANGUAGE_EN:


		g_appTranslator = new QTranslator();
		Language_Type = 2;
		if (false == g_appTranslator->load("./Configuration_en.qm"))
		{
			QMessageBox::warning(this, tr("Warning"), tr("load Configuration_en.qm failed."));
			return;
		}
		qApp->installTranslator(g_appTranslator);
		Init_Display();
		break;

	default:
		break;

	}
}
void MainWindow::Action_CID_Contain()
{
	QString filename;
	filename = QFileDialog::getOpenFileName(this, tr("Select CID "),
		QDir::currentPath(), tr("CID Files (*.CID)"));
	if (!filename.isEmpty())
	{
		m_SCDPoint->Compare_CID_Contain(filename);
	}
}

void MainWindow::Action_Close()
{
	if (Version_Flag == 1)
	{
		Reversion_Flag = 0;
		Version_Flag = 0;
		QMessageBox msgBox;
		msgBox.setText(tr("The SCD has been modified"));
		msgBox.setInformativeText(tr("Do you want to save your changes?"));
		msgBox.setStandardButtons(QMessageBox::Save | QMessageBox::No);
		msgBox.setDefaultButton(QMessageBox::Save);
		int ret = msgBox.exec();
		if (ret == QMessageBox::Save)
		{
			Action_Save();
		}
		close();
		return;
	}
	if (Reversion_Flag == 1)
	{
		Reversion_Flag = 0;
		Version_Flag = 0;
		QMessageBox msgBox;
		msgBox.setText("The SCD has been modified");
		msgBox.setInformativeText("Do you want to save your changes?");
		msgBox.setStandardButtons(QMessageBox::Save | QMessageBox::No);
		int ret = msgBox.exec();
		if (ret == QMessageBox::Save)
		{
			Action_Save();
		}
		close();
		return;
	}
	close();
}
