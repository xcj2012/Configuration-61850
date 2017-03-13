#ifndef SCDTREE_H
#define SCDTREE_H
#include"qstring.h"

#include"datastruct.h"
#include <WinSock2.h>
#include <QDomNode>
#include <QDomDocument>
#include <QFile>
#include "datastruct.h"
#include <QMap>
#include <QAxObject>
#include <QFile>
#include<QList>
#include<QTreeWidget>
#include"datatemplate.h"
#include"compareied.h"
#include<QObject>
#include"CRC32.h"
#include"stdio.h"
#include"datastruct.h"
#ifdef _WIN32
#include <windows.h>
#endif
#include "include_cpp/libxl.h"
#include"importxls_rs.h"
#include<QProgressBar>
#include<QTreeWidgetItem>
using namespace libxl;
WORD extern Crc16(BYTE* pBuf, int nLen);
QString extern IP_Increase(QString IP, int i);
QString extern MAC_Increase(QString MAC, int i);
int Min_Flag(QList<int>&);

class ScdTree
{

public:
    ScdTree();
    int LoadSCD(QString filename);
    int CreatSCD();
    int InitSCDstruct(TiXmlDocument*);
    int SaveSCD(QString filename);
    int GetNode(QString NodeName);
    int GetIEDList(QVector<IEDstruct> &);
    int GetChildNum();
    int GetChild(QString ChildName);
    int GetAccessPoint(QString ApName);
	int GetLDnode(QString Ldname);
	int GetLNnode(QString LNinst);
    int GetOneDOI(QString DOIName);
    TiXmlElement* GetOneDAI(QString DAIName);
    QString GetDOIValue(QString Node,QString Name,QString attriName);
    int GetChild();
	int GetChildList();
	int GetNextChild();
    int GetNextChild(QString strname);
    int GetChildByname_value(QString strName,QString strValue);
	
    int GetChildByname_value(QString NodeName,QString strName,QString strValue);
	int GetChildByname_value(QString NodeName, QString strName1, QString strValue1,
							 QString strName2 , QString strValue2,
							 QString strName3, QString strValue3 );
	int GetChildByname_value( QString strName1, QString strValue1,
		QString strName2, QString strValue2,
		QString strName3, QString strValue3);
    int GetIEDByname(QString strname);
    int RemoveChildByName(TiXmlElement*,QString ChildName);
    int RemoveChildByIndex(int index);
    int SetNode();
    int CreatNode(QString NodeName);
    int CreatOneHistory();
    QString CreatOneSubNet();
    int DeleteOneSubNet(QString strname);
    int AddAttribute(QString Name,QString AttributeName);
    int SetAttribute(QString AttributeName,QByteArray Value);

    //int SetLNAttribute(QString AttributeName,float Value);
    QString GetAttribute(QString AttributeName);
    QString GetAttribute(int index,QString AttributeName);
    QString GetValue();
    //int UpdataAttribute(int index,QString AttributeName,QString AttributeValue);
    //int UpdataAttribute(int index,QString AttributeName,QByteArray AttributeValue);
    //int UpdataAttribute(QString nodename, QString name, QByteArray value);
    // int UpdataAttribute(QString name, QString value);
    //int UpdataLDAttribute(QString Apname, QString inst, QByteArray value);
    //int UpdataLNAttribute( QString inst, QByteArray value);
	int UpdataIEDAttribute(QString IEDname, QString name, QString value);
    int UpdateCommunicationAttribute(QString subnet,QString name, QString Value);
    int SwitchRoot();
	int SwitchToIED();
	int SwitchParent();
	
    int ImportICD(QString filename,QString IEDName);
    int ImportCID(QString filename, QString IEDName);
    //int ImportCID(QString filename, QString IEDName,int state);
   // int ImportICD(QString IEDName,int state);
    int ImportCID(QString IEDName);
	int ImportCID(QString IEDName, TiXmlDocument*);
    int RemoveIED(QString IEDName);
	int CheckDataTempLate(TiXmlDocument*, QMap<QString, TiXmlElement*> &, QMap<QString, TiXmlElement*>&, QMap<QString, TiXmlElement*>&,
										   QMap<QString, TiXmlElement*>&, QMap<QString, TiXmlElement*>&);
    int ADDOneAp(TiXmlNode*, QString IEDName);
    int AddOneIED(TiXmlNode*);
    int AddDateType(TiXmlNode*);
    int AddDateType_AddPrefix(QString IEDName,TiXmlElement* Ext_SCL);
    int AddDateType_AddPrefix(QString IEDName, QMap<QString, TiXmlElement*>&, QMap<QString, TiXmlElement*>&,
                              QMap<QString, TiXmlElement*>&, QMap<QString, TiXmlElement*>&);
    int AddDateType_Ignore(QString IEDName, QMap<QString, TiXmlElement*> &, QMap<QString,
                           TiXmlElement*>&, QMap<QString, TiXmlElement*>&,
                           QMap<QString, TiXmlElement*>&, QMap<QString, TiXmlElement*>&);
    int AddDateType_Merge(QString IEDName, QMap<QString, TiXmlElement*> &,
                          QMap<QString, TiXmlElement*>&, QMap<QString, TiXmlElement*>&,
                          QMap<QString, TiXmlElement*>&, QMap<QString, TiXmlElement*>&);
    int AddDateType_Replace(QString IEDName, QMap<QString, TiXmlElement*> &,
                            QMap<QString, TiXmlElement*>&, QMap<QString, TiXmlElement*>&,
                            QMap<QString, TiXmlElement*>&, QMap<QString, TiXmlElement*>&);
    int CheckIEDName(QString strname);
    int LoadIEDFile(QString filename);
    int LoadIEDFile(QString filename,QString &);
    void SetRememberEle();
    void switchRememberEle();
	void SetRememberElelocal();
	void switchRememberElelocal();
 //   void analyzeDO(QVector<Data_instStruct> &list, QString da_prefix,
                   //QString str_lntype);
    //void analyzeSDI(QVector<Data_instStruct> &list, QString strname,
                    //QString strdainst, TiXmlElement *proot,QString desc);
    QString GetIEDName();
    //QString GetFC_ByoneDAI(QString lntype,QString doname,QString daname);
	int AddOneDataToDataSet(QString datasetname, FCDA_Struct data);
	int AddOneDatSet(QString IED, QString LD, QString LN,QString name, QString desc);
    int UpdataOneDatSet(QString oldname, QString newname, QString desc);
	int UpdataOneDatSet(QString IED, QString LD, QString LN, QString oldname, QString newname, QString desc);
    //int AddOneGSECtrl(QString path,QStringList list);
    //int DelOneGSECtrl(QString name);
    //int UpdataOneGSECtrl(QString name,GSE_InstStruct data);
    //int AddOneSMVCtrl(QString path, QStringList list, SMV_InstStruct&);
    //int DelOneSMVCtrl(QString name);
    //int UpdataOneSMVCtrl(QString name,SMV_InstStruct data);
    //int UpdataOneRPTCtrl(QString name,RPT_CTRLStruct data);
    //int UpdataOneLOGCtrl(QString name,LOG_CTRLStruct data);
	int UpdataOneINPUT(QString name, Input_Struct data,int state);
    //int AddOneINPUT(Input_Struct data);
	int AddOneINPUT(QString ied, QString ap, QString ld, QString ln, Input_Struct data);
	int UpdataOneINPUT(QString ied, QString ld, QString ln, QString name, Input_Struct data, int state);
    //int DelOneINPUT(Input_Struct data);
	int DelOneINPUT(QString ied, QString ld, QString ln, QString intAddr);
    int CreatInputs();
	QString GetSpecifytvalue(QString iedname, QString path, QString value);
    QString GetDescFromSpecifNode(QString iedname, QString LDName, QString LNName, QString DOName);

    //QString GetCurIEDName();
    //int GetSubNet(QString NetName);
	int File_Integrity_Check(QString StrName,int state);
    int Comunication_Check(QStringList &);
    //int GetAccessPoint(QString ApName);
    //int GetNode(QString NodeName)
    int CommAndIed_Check(QStringList &);
    int FCDA_Check(QStringList &, QStringList &, QStringList &,QProgressBar*);
    int MappingReceiver_Check(QStringList &, QStringList &, QStringList &, QStringList &, QStringList &,QProgressBar*Bar);
	int MappingSender_Check(QStringList &, QStringList &, QStringList &);
	int Reference_Check(QStringList &, QStringList &, QStringList &);
	int Check_One_FCDA(TiXmlElement*, TiXmlElement*, TiXmlElement*, QStringList &, QStringList &, QStringList &);
	int Check_One_Receiver(TiXmlElement*, TiXmlElement*, TiXmlElement*, QStringList &, QStringList &, QStringList &);
	int Check_One_Sender(TiXmlElement*,  TiXmlElement*, TiXmlElement*, QStringList &, QStringList &, QStringList &);
	int Check_One_Mapping(TiXmlElement*, TiXmlElement*, TiXmlElement*, QStringList &, QStringList &, QStringList &, QStringList &, QStringList &);
    //int GetLNListfromAP(QString ApName,QVector<DataLN_Struct>&);
	int CreatDataMatrix(QString LNodeType,QVector<DataMatrix_Struct>&);
	int CreatDataMatrix_DO(TiXmlElement*, DataMatrix_Struct data, QString  doName, QVector<DataMatrix_Struct>&);
	int CreatDataMatrix_SDO(TiXmlElement*,  DataMatrix_Struct data,QString doName, QVector<DataMatrix_Struct>&);
	int CreatDataMatrix_BDA(TiXmlElement*, DataMatrix_Struct data, QString  daName, QVector<DataMatrix_Struct>&);
	int GetLNodeTypeList(QString str, QStringList&List);
    int GetLNodeTypeList(QString ied,QString ap,QString ld,QString ln, QStringList&List);
	int GetLNodeTypeList(QString ied, QString ap, QString ld, QStringList lnList, QStringList&List);
	int GetDataInstList(QString AP_LD, QVector<FCDA_Struct>&List);
    int GetDataInstList(QString ied,QString ap,QString ld,QString ln, QVector<FCDA_Struct>&List);
	int GetDataInstList_DAI(TiXmlElement*, FCDA_Struct data, QVector<FCDA_Struct>&List);
	int GetDataInstList_SDI(TiXmlElement*, FCDA_Struct data, QVector<FCDA_Struct>&List);
	int GetDataInstList_DOI(TiXmlElement*, FCDA_Struct data, QVector<FCDA_Struct>&List);
	int PrepareDataForCheck(TiXmlElement*, TiXmlElement*);
    //TiXmlElement* GetLDeviceByName(TiXmlElement*, QString str);
	TiXmlElement* GetLNodeByInst(TiXmlElement*, QString str);
    //TiXmlElement* GetDOByName(TiXmlElement*, QString doName);
    int CheckMatching(QString strName,QVector<Input_Struct>&);
    int PrepareforCheckMatching(QString strName,QVector<Input_Struct>&);
    void GetLDeviceList(QString IEDname,QStringList&);
    void GetDataSetList(QString strIED,QString str,QVector<DataSetStruct>&);
    void GetDataSetList(QString strIED,QString str,QVector<DataSetStruct>&,int state);
    void GetCTRLDataList(QString strIED,QString ld,QVector<DataSetStruct>&);
    void GetSGDataList(QString strIED,QString ld,QVector<DataSetStruct>&);
    //int CheckInputReceiver(Input_Struct&);
	int CheckInputReceiver(QString ied, QString ap, QString ld, QString ln, Input_Struct&);
    //int CheckInputSender(Input_Struct&m_data);
    int ReLoadIED(QString Name,QString File);
    int Compare(TiXmlElement*, TiXmlElement*);
	int DelOneIED(QString Name);
	int AutoReleaseUnuseDate();
	int DelOneConnectAP(QString Name);
    //int ReplaceConnectAP(QString,TiXmlElement*);
	int GetDataSetVector(QVector<DataSetStruct>&);
    int GetDataSetVector(QString IEDName,QVector<DataSetStruct>&);
	int GetFCDAList(QVector<FCDA_Struct>&, QMap<quint16, FCDA_Struct>&);
	int DelOneData(WORD);
    int GetConnectAPList(QString ,QVector<ConnectedAP>&);
    int GetConnectAPList_MMS(TiXmlElement* ,QVector<ConnectedAP>&);
    int GetConnectAPList_GOOSE(TiXmlElement*, QVector<ConnectedAP>&);
    int GetConnectAPList_SMV(TiXmlElement*, QVector<ConnectedAP>&);
	int UpdateConnectAPMMS(QString, ConnectedAP&,int);
	int UpdateConnectAPGOOSE(QString, ConnectedAP&);
	int UpdateConnectAPSMV(QString, ConnectedAP&);
	void AutoSet_MMS();
	void AutoSet_GOOSE();
	void AutoSet_SMV();
	void Filling_OneData(FCDA_Struct &,int);
	void Filling_OneData(QString, FCDA_Struct &, int);
	void Init_LN_MAP(TiXmlElement*, QMap<QString, TiXmlElement* >&);
	void Init_LD_MAP(TiXmlElement*, QMap<QString, TiXmlElement* >&);
    void Init_AP_MAP(TiXmlElement*, QMap<QString, TiXmlElement* >&);
	void Init_IED_MAP(TiXmlElement*, QMap<QString, TiXmlElement* >&);
	void Init_DO_MAP(TiXmlElement*, QMap<QString, TiXmlElement* >&);
    void Init_SDI_MAP(TiXmlElement*, QMap<QString, TiXmlElement* >&);
	void Init_DAI_MAP(TiXmlElement*, QMap<QString, TiXmlElement* >&);
	void Init_ConnectAP_MAP(TiXmlElement*, QMap<QString, TiXmlElement* >&);
	void Init_ConnectAP_MAP(TiXmlElement*, QMap<QString, TiXmlElement* >&,int state);
	void Init_LNtype_MAP(TiXmlElement*, QMap<QString, TiXmlElement* >&);
	void Init_DOType_MAP(TiXmlElement*, QMap<QString, TiXmlElement* >&);
	void Init_DAtype_MAP(TiXmlElement*, QMap<QString, TiXmlElement* >&);
	void Init_EnumType_MAP(TiXmlElement*, QMap<QString, TiXmlElement* >&);
    void Init_DataSet_MAP(TiXmlElement*, QMap<QString, TiXmlElement* >&);
    void Init_DataSet_MAP(TiXmlElement*, QMap<QString, TiXmlElement* >&,int);
    void Init_ControBlock_MAP(TiXmlElement*, QMap<QString, TiXmlElement* >&,int);
	void Init_ControBlock_MAP(TiXmlElement*, QMap<QString, TiXmlElement* >&);
    void Init_Input_MAP(TiXmlElement*, QMap<QString, TiXmlElement* >&,int);
    void Init_Child_Map(TiXmlElement*, QMap<QString, TiXmlElement* >&,QString);
	void Init_GSE_Map(TiXmlElement*Node, QMap<QString, TiXmlElement* >&Map,int state);
	void Init_SMV_Map(TiXmlElement*Node, QMap<QString, TiXmlElement* >&Map, int state);
    //void Init_FCDA_MAP(TiXmlElement*, QMap<QString, TiXmlElement* >&);

	void ExportCID_FILE(QString, QString);
	int ExportCONFIG_FILE(QString, QString);
	bool Fill_Input_config(TiXmlElement*, QVector<INPUT_Config>&, int state);
	
    void ExportXLS_FILE(QString, QString);
    void ExportXLS_FILE(QStringList, QString,QProgressBar*);
	void Init_XLSFFIle(QString, QAxObject*);
	void Init_ConfigFIle(TiXmlDocument*);
    int  Write_DataSet2File(TiXmlElement*,TiXmlElement*, int, QString, QAxObject*);
    int  Write_DataSet2File(TiXmlElement*, Sheet*,Format*);
	void WriteData2Config(QString,TiXmlDocument*, INPUT_Config&, int index, int state);
    int  Build_Struct_XLS(int, QString, QAxObject*);
	void Fill_Input_Mapping(TiXmlElement*, TiXmlElement*,Input_Mapping&);
	void Write_Input_Mapping(int, Input_Mapping&, QAxObject*);
    void Write_Input_Mapping(int, int,Input_Mapping&,Sheet*,Format*);
	void GetLnTypeList(TiXmlElement*, QStringList&);
	void GetDoTypeList(TiXmlElement*, QStringList&);
	void GetDaTypeList(TiXmlElement*, QStringList&, QStringList&, QStringList&);
	void GetEnumTypeList(TiXmlElement*, QStringList&, QStringList&);
	int  SwitchToNode(QString ied, QString ld, QString ln);
    void Init_FCDA_MAP();
	int GetLnListFromLD(QString ied, QString ld,QStringList &list);
	int GetIndexByChild(TiXmlElement*, TiXmlElement*);
	QString GetSaddrByInst(QString, QString,QString &);
	void GetDoInstVector(QString, QString, QString, QVector<FCDA_Struct>&);
    void ClearInputs(TiXmlElement*);
	void ClearAllInput();
    void AddNewHistoryItem(int);
    int UpdataHistoryItem(HistoryItem,HistoryItem);
    int UpdataLDDesc(QString IED,QString LD,QString);
    int UpdataLNDesc(QString IED,QString LD,QString LN,QString);
    int GetDataDesc(QString IED,QString Inst,QString &Desc1,QString &Desc2,QString &dU1,QString &dU2);
    int UpdataDataDesc(QString IED,QString Inst,QString &Desc1,QString &Desc2,QString &dU1,QString &dU2);
    int DelOneDataSet(QString IED,QString LD,QString LN,QString DataSet);
    void Auto_AddControlBlock();
    TiXmlElement* GetAPByLD(TiXmlElement*);
    TiXmlElement* CreatBLKNode(QString IED,QString LD,QString LN,int state,QString Name);
    int GetRPTList(QString IED,QString LD,QString LN,QVector<RPT_CTRLStruct>&);
    int UpdataOneRPTCtrl(QString IED, QString LD, QString LN, RPT_CTRLStruct data,QString oldname);
    void GetDataSetList(QString strIED,QString LD,QString LN,QStringList &list);
    int DelOneGSEBlK(QString IED,QString LD,QString LN,QString BLK_Name);
    int UpdataOneGSEBLK(QString IED, QString LD, QString LN, GSE_InstStruct data,QString oldname);
	int AddOneGSECtrl(QString IED, QString LD, QString LN, QStringList list, GSE_InstStruct&);
    int DelOneSMVBlK(QString IED,QString LD,QString LN,QString BLK_Name);
    int UpdataOneSMVBLK(QString IED, QString LD, QString LN, SMV_InstStruct data,QString oldname);
	int AddOneSMVCtrl(QString IED, QString LD, QString LN, QStringList list, SMV_InstStruct&);
    int GetSMVList(QString IED,QString LD,QString LN,QVector<SMV_InstStruct>&);
    int GetGSEList(QString IED,QString LD,QString LN,QVector<GSE_InstStruct>&);
    int GetLOGList(QString IED,QString LD,QString LN,QVector<LOG_CTRLStruct>&);
    int AddOneLOGCtrl(QString IED, QString LD, QString LN,QStringList list);
    int DelOneLOGBlK(QString IED,QString LD,QString LN,QString BLK_Name);
    int UpdataOneLOGBLK(QString IED, QString LD, QString LN, LOG_CTRLStruct data,QString oldname);
    int Print_Test(TiXmlElement* Node,QString filename);
    int UpdataConnectAPByGOOSE(QString IED,QString AP,QString LD,QString OldName,GSE_InstStruct data);
    int AddConnectAPByGOOSE(QString IED,QString AP,QString LD,GSE_InstStruct data);
    int DelConnectAPByGOOSE(QString IED,QString AP,QString LD,GSE_InstStruct data);
    int UpdataConnectAPBySMV(QString IED,QString AP,QString LD,QString OldName,SMV_InstStruct data);
    int AddConnectAPBySMV(QString IED,QString AP,QString LD,SMV_InstStruct data);
    int DelConnectAPBySMV(QString IED,QString AP,QString LD,SMV_InstStruct data);
    int GetReportSetting(QString IED);
	int GetGSESetting(QString IED);
    int UpdataBLKConfRev(QString IED,QString LD,QString DataSet,bool);
	int SaveCRC();
	TiXmlElement* SaveIEDCRC2File(TiXmlElement* m_IED);
	TiXmlElement* GetConnectAP(QString IED, QString AP, QString LD, QString CB,int state);
	TiXmlElement* Fill_FCDA_GOOSE(TiXmlElement* m_LD, TiXmlElement* m_FCDA);
	TiXmlElement* Fill_FCDA_SMV(TiXmlElement* m_LD, TiXmlElement* m_FCDA);
   // int SaveSCDCRC2File();
    int CheckXLS_IED(QString,QVector<Map_IED>&);
    void ImportXLS(QString File,QVector<Map_IED>);
    void CheckXLS_Input(Input_Mapping,QMap<QString,Input_Mapping>&,QMap<QString,Input_Mapping>&,QMap<QString,Input_Mapping>&,QMap<QString,Input_Mapping>&);
    void ImportXLS_Map(QMap<QString,Input_Mapping>&);
    void GetSender_Struct(Input_Mapping m_data,Input_Struct&m_sender);
    void ExportCID_Node(QString, QString,TiXmlDocument*);
	bool ImportCID_Node(QString, TiXmlDocument*);
    void CleanInvalidInput(QString);
    //void Delete_ALLInput();
    int CreatDataMatrix_By_FC(QString LNodeType,QVector<DataMatrix_Struct>&,QString);
    int CreatDataMatrix_DO_By_FC(TiXmlElement*, DataMatrix_Struct data, QString  doName, QVector<DataMatrix_Struct>&,QString);
    int CreatDataMatrix_SDO_By_FC(TiXmlElement*,  DataMatrix_Struct data,QString doName, QVector<DataMatrix_Struct>&,QString);
    int CreatDataMatrix_BDA_By_FC(TiXmlElement*, DataMatrix_Struct data, QString  daName, QVector<DataMatrix_Struct>&,QString);
	void FillDataSetStruct_By_FCDA(TiXmlElement*, FCDA_Struct m_FCDA, DataSetStruct &m_Data);
    void FillDataSetStruct_By_DO(TiXmlElement*,FCDA_Struct m_FCDA,DataSetStruct &m_Data);
    bool Compare_CID_Contain(QString);
    bool Compare_Node(TiXmlElement*Local,TiXmlElement*Ext);
    void GetConnectAPData(QString IED,QString AP,ConnectedAP& m_AP,QVector<Address_GOOSE>&,QVector<Address_SMV>&);
    void UpdataConnectAPMMS(ConnectedAP& m_AP,QVector<Address_GOOSE>&,QVector<Address_SMV>&);
	void Init_P_Map(TiXmlElement*, QMap<QString, TiXmlElement* >&, int state);
	void Fill_Node_GOOSEPUB(TiXmlElement*Node, QString cbName);
	void GetLDList(QString IED,QVector<AP_LD>&);
    void AddRoot_Node(QTreeWidget*);
    void AddChild_Node(QTreeWidgetItem* item,TiXmlElement* node);
    void Get_Attribute_List(QTreeWidgetItem* item,QList<Item_Node>&);
    void Display_AttributeByNode(QList<Item_Node>,QStandardItemModel* mode);
private:
    TiXmlElement* root;
    TiXmlDocument* doc;
	TiXmlDocument *CIDDocument;
    //TiXmlDeclaration* Declaration;
    TiXmlElement* CurElement;
	TiXmlElement* CurNode;
	TiXmlElement* IEDNode;
    TiXmlElement* DataTypeNode;
    TiXmlElement* RememberElement;
	TiXmlElement* RememberElementlocal;
	char* strtmp;
    int Input_flag;
    //TiXmlNode* CurNode;
    TiXmlNode* ClientNode;
    TiXmlNode* TimeNode;
    TiXmlNode* IEDBaseNode;
    TiXmlNode* NETBaseNode;
    TiXmlNode* NetworkNode;
    //QDomDocument QDocumnet;
    int ChildNum;
    QString strIEDName;
	QVector<DataMatrix_Struct> DataMatrix_Vector;
	QVector<FCDA_Struct> DataInst_Vector;
	QStringList LNondeType_List;
	QMap<quint16, TiXmlElement*> FCDAPoint_Vector;
	QMap<QString, TiXmlElement*> FCDA_MAP;
	QMap<QString, TiXmlElement*> CurConnectAP_MAP;
	QMap<QString, TiXmlElement*> IED_MAP;
	QMap<QString, TiXmlElement*> LNodeType_MAP;
	QMap<QString, TiXmlElement*> DOType_MAP;
	QMap<QString, TiXmlElement*> DO_MAP;
	QMap<QString, TiXmlElement*> DAType_MAP;
	QMap<QString, TiXmlElement*> DA_MAP;
	QMap<QString, TiXmlElement*> EnumType_MAP;
	QMap<QString, TiXmlElement*> EnumVal_MAP;
    CRC32 m_SumCheck;
	//QMap<QString, TiXmlElement*> CurConnectAP_MAP;
};

#endif // SCDTREE_H
