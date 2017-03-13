#ifndef DATASTRUCT
#define DATASTRUCT
#include<qstring.h>
#include<QMessageBox>
#include <QItemSelectionModel>
#include "tinyxml.h"
#include"tinyxml.h"
#include"tinystr.h"
#include"tinyxml_global.h"
#include <QVector>
#include <QTranslator >
#include <QtCore>
#define STATE_NEW    1
#define STATE_LOAD   2
#define DO_OK        3
#define DO_FAIL      1
#define DO_OD        2
#define ROOT_NODE	0
#define HEAD_NODE    1
#define STATION_NODE    2
#define COMMUNICATION_NODE    3
#define IED_NODE    4
#define SUBNET_NODE 5
#define NODE_IED	6
#define NODE_LD		7
#define NODE_LN		8
#define NODE_DATASET	9
#define NODE_GSE	10
#define NODE_INPUT	11
#define NODE_SMV	12
#define NODE_LOG	13
#define NODE_REPORT	14
#define NODE_MMSNET	15
#define NODE_GOOSENET	16
#define NODE_SMVNET	17
#define NODE_DATA	18
#define ERROR_MSG  1
#define WARNING_MSG 2
#define RTUMT_NAME_MAXLEN		24
#define RTUMT_DESC_MAXLEN		64
#define MMSNETPARA_WITHOUT	01
#define MMSNETPARA_WITH		02
#define GOOSENTPARA				03
#define SMVNTPARA					04
#define LOCAL_DATA 1
#define EX_DATA 2
#define CBNAME_ENA    0x01
#define DATASET_ENA    0x02
#define RPTID_ENA    0x04
#define APPID_ENA    0x04
#define OPTFIELDS_ENA    0x08
#define BUFTIME_ENA    0x10
#define TRPOPS_ENA    0x20
#define INTGPD_ENA    0x40
#define LANGUAGE_CN    0x01
#define LANGUAGE_EN    0x02
#define SAME_VERSION   0x01
#define SAME_TYPE      0x04
#define DIF_TYPE        0x08
struct HistoryItem
{
    QString s_Version;
    QString s_Reversion;
    QString s_Time;
    QString s_Who;
    QString s_Reason;
    QString s_What;
    HistoryItem()
    {
        s_Version.clear();
        s_Reversion.clear();
        s_Time.clear();
        s_Who.clear();
        s_Reason.clear();
        s_What.clear();
    }
   void Clear()
    {
        s_Version.clear();
        s_Reversion.clear();
        s_Time.clear();
        s_Who.clear();
        s_Reason.clear();
        s_What.clear();
    }
};
struct CommItem
{
    QString s_SubNet_name;
    QString s_SubNet_type;
    QString s_SubNet_desc;
    CommItem()
    {
        s_SubNet_name.clear();
        s_SubNet_type.clear();
        s_SubNet_desc.clear();

    }
};
struct IEDstruct
{
    QString s_IEDname;
	QString s_IEDtype;
	QString s_IEDvendor;
	QString s_IEDversion;
	QString s_IEDdesc;
    IEDstruct()
    {
        s_IEDname.clear();
        s_IEDtype.clear();
        s_IEDvendor.clear();
        s_IEDversion.clear();
        s_IEDdesc.clear();


    }
    bool operator==(const IEDstruct &other) const
    {
        return( s_IEDname == other.s_IEDname &&
            s_IEDtype == other.s_IEDtype &&
            s_IEDvendor == other.s_IEDvendor &&
            s_IEDversion == other.s_IEDversion &&
            s_IEDdesc == other.s_IEDdesc);
    }
};
struct FCDA_Struct
{
    QByteArray B_ldInst;
    QByteArray B_prefix;
    QByteArray B_lnClass;
    QByteArray B_lnInst;
    QByteArray B_doName;
    QByteArray B_daName;
    QByteArray B_fc;
    QByteArray B_DaType;
	QString B_dU;
	QString B_DOdesc;
	QString B_sAddr;
	QString B_LNodeType;
	QString B_IED;

	FCDA_Struct()
    {
        B_ldInst.clear();
        B_prefix.clear();
        B_lnClass.clear();
        B_lnInst.clear();
        B_doName.clear();
        B_daName.clear();
        B_fc.clear();
        B_DaType.clear();
		B_DOdesc.clear();
		B_sAddr.clear();
		B_dU.clear();
		B_LNodeType.clear();
		B_IED.clear();

    }
	void Clear()
	{
		B_ldInst.clear();
		B_prefix.clear();
		B_lnClass.clear();
		B_lnInst.clear();
		B_doName.clear();
		B_daName.clear();
		B_fc.clear();
		B_DaType.clear();
		B_DOdesc.clear();
		B_sAddr.clear();
		B_dU.clear();
		B_LNodeType.clear();
		B_IED.clear();
	}
	bool operator ==(const FCDA_Struct &other) const
	{
		if (B_ldInst != other.B_ldInst)
		{
			return false;
		}
		if (B_prefix != other.B_prefix)
		{
			return false;
		}
		if (B_lnClass != other.B_lnClass)
		{
			return false;
		}
		if (B_lnInst != other.B_lnInst)
		{
			return false;
		}
		if (B_doName != other.B_doName)
		{
			return false;
		}
		if (B_daName != other.B_daName)
		{
			return false;
		}
		if (B_fc != other.B_fc)
		{
			return false;
		}
		if (B_DaType != other.B_DaType)
		{
			return false;
		}
		if (B_DOdesc != other.B_DOdesc)
		{
			return false;
		}
		if (B_sAddr != other.B_sAddr)
		{
			return false;
		}
		if (B_dU != other.B_dU)
		{
			return false;
		}
		if (B_LNodeType != other.B_LNodeType)
		{
			return false;
		}
		if (B_IED != other.B_IED)
		{
			return false;
		}
		return true;
	};
};
struct DataSetStruct
{
	QString DataSetName;
	QString DataSetDesc;
	int		  Goose_state;
	QVector<FCDA_Struct> FCDA_List;
	DataSetStruct()
	{
		DataSetName.clear();
		DataSetDesc.clear();
		FCDA_List.clear();
		Goose_state = 0;
	}
};
struct Data_instStruct
{
//	QString B_IEDname;
	QString B_Datalnst;
	QString B_DA;
	QString B_FC;
	QString B_dU;
	QString B_DOdesc;
	QString B_sAddr;
    Data_instStruct()
    {
        B_Datalnst.clear();
        B_DA.clear();
        B_FC.clear();
        B_dU.clear();
        B_DOdesc.clear();
        B_sAddr.clear();

    }

};
struct LN_InstStruct
{
	QString B_ldinst;
	QString B_lnType;
	QString B_prefix;
	QString B_lnClass;
	QString B_inst;
	QString B_desc;
    LN_InstStruct()
    {
        B_ldinst.clear();
        B_lnType.clear();
        B_prefix.clear();
        B_lnClass.clear();
        B_inst.clear();
        B_desc.clear();

    }

};
struct GSE_InstStruct
{
    QString B_name;
    QString B_datSet;
    QString B_confRev;
    QString B_type;
    QString B_appID;
    QString B_desc;
    GSE_InstStruct()
    {
        B_name.clear();
        B_datSet.clear();
        B_confRev.clear();
        B_type.clear();
        B_appID.clear();
        B_desc.clear();

    }
    void Clear()
    {
        B_name.clear();
        B_datSet.clear();
        B_confRev.clear();
        B_type.clear();
        B_appID.clear();
        B_desc.clear();
    }

};
struct SMV_InstStruct
{
    QString B_name;
    QString B_datSet;
    QString B_confRev;
    QString B_nofASDU;
    QString B_smpRate;
    QString B_multicast;
    QString B_desc;
    QString B_smvID;
    SMV_InstStruct()
    {
        B_name.clear();
        B_datSet.clear();
        B_confRev.clear();
        B_nofASDU.clear();
        B_smpRate.clear();
        B_multicast.clear();
        B_desc.clear();
        B_smvID.clear();
    }
};
struct TrgOps_Struct
{
	QString B_dchg;
	QString B_dupd;
	QString B_period;
	QString B_qchg;
	TrgOps_Struct()
	{
		B_dchg.clear();
		B_dupd.clear();
		B_period.clear();
		B_qchg.clear();
	}
};
struct OptFields_Struct
{
	QString B_seqNum;
	QString B_timeStamp;
	QString B_dataSet;
	QString B_reasonCode;
	QString B_dataRef;
	QString B_entryID;
	QString B_configRef;
	OptFields_Struct()
	{
		B_seqNum.clear();
		B_timeStamp.clear();
		B_dataSet.clear();
		B_reasonCode.clear();
		B_dataRef.clear();
		B_entryID.clear();
		B_configRef.clear();
	}

};
struct RptEnabled_Struct
{
	QString B_max;
	RptEnabled_Struct()
	{
		B_max.clear();
	}

};
struct RPT_CTRLStruct
{
    QString B_name;
    QString B_rptID;
    QString B_datSet;
    QString B_intgPd;
    QString B_confRev;
    QString B_buffered;
    QString B_buftime;
    TrgOps_Struct m_Trgops;
    OptFields_Struct m_OptFields;
    RptEnabled_Struct m_RtpEnabled;
    QString B_desc;
    RPT_CTRLStruct()
    {   TrgOps_Struct();
        OptFields_Struct();
        RptEnabled_Struct();
        B_name.clear();
        B_rptID.clear();
        B_datSet.clear();
        B_intgPd.clear();
        B_confRev.clear();
        B_buffered.clear();
        B_desc.clear();
    }
};
struct LOG_CTRLStruct
{
    QString B_name;

    QString B_datSet;
    QString B_intgPd;
    QString B_logName;
    QString B_logEna;
    QString B_reasonCode;
    TrgOps_Struct m_Trgops;

    QString B_desc;
    LOG_CTRLStruct()
    {   TrgOps_Struct();
        B_name.clear();
        B_logName.clear();
        B_datSet.clear();
        B_intgPd.clear();
        B_logEna.clear();
        B_reasonCode.clear();
        B_desc.clear();
    }
};
struct Input_Struct
{
	QString B_InterIED;
    QString B_iedName;

    QString B_daName;
    QString B_doName;
    QString B_ldInst;
    QString B_lnClass;
    QString B_lnInst;


    QString B_prefix;
    QString B_intAddr;
    QString B_intDesc;
    QString B_exDesc;
    QString B_InType;
	QString B_exType;
    QString B_ExdaType;
	QString B_IndaType;

    Input_Struct()
    {
		B_InterIED.clear();
        B_iedName.clear();
        B_daName.clear();
        B_doName.clear();
        B_ldInst.clear();
        B_lnClass.clear();
        B_lnInst.clear();
        B_prefix.clear();
        B_intAddr.clear();
        B_intDesc.clear();
        B_exDesc.clear();
		B_InType.clear();
		B_exType.clear();
		B_ExdaType.clear();
		B_IndaType.clear();
    }
};
struct CommCheck_Struct
{
    QString B_MacAddr;

    QString B_APPID;
    QString B_VLANID;
    QString B_apName;

    QString B_cbName;
    QString B_ldInst;
    QString B_iedName;
    QString B_Subnetwork;
    QString B_IPAddr;

    CommCheck_Struct()
    {
        B_MacAddr.clear();
        B_APPID.clear();
        B_VLANID.clear();
        B_apName.clear();
        B_cbName.clear();
        B_ldInst.clear();
        B_iedName.clear();
        B_Subnetwork.clear();
        B_IPAddr.clear();

    }
};
struct APCheck_Struct
{
	QString B_APName;

	QString B_IEDName;
	APCheck_Struct()
	{
		B_APName.clear();
		B_IEDName.clear();
    }
	bool operator == (APCheck_Struct m)
	{
		if (B_APName != m.B_IEDName)
		{
			return false;
		}
		if (B_IEDName != m.B_APName)
		{
			return false;
		}
		return true;
    }
};
struct DataLN_Struct
{
	QString B_AP;

	QString B_LD;
	QString B_LN;

	QString B_LnType;
	DataLN_Struct()
	{
		B_AP.clear();
		B_LD.clear();
		B_LN.clear();
		B_LnType.clear();
    }
	bool operator == (DataLN_Struct m)
	{
		if (B_AP != m.B_AP)
		{
			return false;
		}
		if (B_LD != m.B_LD)
		{
			return false;
		}
		if (B_LN != m.B_LN)
		{
			return false;
		}
		if (B_LnType != m.B_LnType)
		{
			return false;
		}
		return true;
    }
};
struct DataMatrix_Struct
{
	QString B_LNodeType;

	QString B_doName;
	QString B_daName;
	QString B_Fc;
	QString B_bType;
	DataMatrix_Struct()
	{
		B_LNodeType.clear();
		B_doName.clear();
		B_daName.clear();
		B_Fc.clear();
		B_bType.clear();
    }
	virtual bool  operator==(const DataMatrix_Struct n)
	{
		if (this->B_LNodeType != n.B_LNodeType)
		{
			return false;
		}
		if (this->B_doName != n.B_doName)
		{
			return false;
		}
		if (this->B_daName != n.B_daName)
		{
			return false;
		}
		if (this->B_Fc != n.B_Fc)
		{
			return false;
		}
		if (this->B_bType != n.B_bType)
		{
			return false;
		}
		return true;
    }
};
struct YX_Struct
{
    QString YX_Name;
    //QString YX_Desc;
	char	YX_Desc[RTUMT_DESC_MAXLEN];
    QString YX_No;
    YX_Struct()
    {
        YX_Name.clear();
		memset(YX_Desc, 0, RTUMT_DESC_MAXLEN);
        YX_No.clear();

    }

};
struct YC_Struct
{
    QString YC_Name;
   // QString YC_Desc;
	char	YC_Desc[RTUMT_DESC_MAXLEN];
    QString YC_No;
    YC_Struct()
    {
        YC_Name.clear();
		memset(YC_Desc, 0, RTUMT_DESC_MAXLEN);
        YC_No.clear();

    }

};
struct KWH_Struct
{
    QString KWH_Name;
	char	KWH_Desc[RTUMT_DESC_MAXLEN];
    QString KWH_No;
    KWH_Struct()
    {
        KWH_Name.clear();
		memset(KWH_Desc, 0, RTUMT_DESC_MAXLEN);
        KWH_No.clear();

    }

};
struct YK_Struct
{
    QString YK_Name;
    //QString YK_Desc;
	char	YK_Desc[RTUMT_DESC_MAXLEN];
    QString YK_No;
    YK_Struct()
    {
        YK_Name.clear();
		memset(YK_Desc, 0, RTUMT_DESC_MAXLEN);
        YK_No.clear();

    }

};
struct SG_Struct
{
	QString SG_Name;
	//QString YK_Desc;
	char	SG_Desc[RTUMT_DESC_MAXLEN];
	QString SG_No;
	SG_Struct()
	{
		SG_Name.clear();
		memset(SG_Desc, 0, RTUMT_DESC_MAXLEN);
		SG_No.clear();

	}

};
struct Model_Struct
{
    QString Model_Name;
    QString Model_No;
    QVector<YX_Struct> YX_List;
     QVector<YC_Struct> YC_List;
      QVector<KWH_Struct> KWH_List;
       QVector<YK_Struct> YK_List;
	   QVector<SG_Struct> SG_List;
    Model_Struct()
    {
        Model_Name.clear();
        Model_No.clear();
        YX_List.clear();
        YC_List.clear();
        KWH_List.clear();
        YK_List.clear();
		SG_List.clear();

    }
	void operator = (const Model_Struct model)
	{
		Model_Name = model.Model_Name;
		Model_No = model.Model_No;
	
		YX_List.clear();
		YC_List.clear();
		KWH_List.clear();
		YK_List.clear();
		YX_List = model.YX_List;
		YC_List = model.YC_List;
		KWH_List = model.KWH_List;
		YK_List = model.YK_List;
		SG_List = model.SG_List;

	}
	void clear ()
	{
		Model_Name.clear();
		Model_No.clear();

		YX_List.clear();
		YC_List.clear();
		KWH_List.clear();
		YK_List.clear();
		SG_List.clear();

	}

};
struct StationPara_struct
{
    QString Vender;
    QString Line;
    QString ProjectName;
    QString Version;
    StationPara_struct()
    {
        Vender.clear();
        Line.clear();
        Version.clear();
        ProjectName.clear();
    }
};
struct BI_struct
{
    QString DataNo;
    QString Name;
    QString stVal;
    QString t;
    QString q;
    QString TrigOsc;
    BI_struct()
    {
        DataNo.clear();
        Name.clear();
        t.clear();
        q.clear();
        TrigOsc.clear();
    }
};
struct AI_struct
{
    QString DataNo;
    QString Name;
    QString stVal;
    QString t;
    QString q;
    QString TrigOsc;
    AI_struct()
    {
        DataNo.clear();
        Name.clear();
        t.clear();
        q.clear();
        TrigOsc.clear();
    }
};
struct CI_struct
{
    QString DataNo;
    QString Name;
    QString stVal;
    QString t;
    QString q;
    QString TrigOsc;
    CI_struct()
    {
        DataNo.clear();
        Name.clear();
        t.clear();
        q.clear();
        TrigOsc.clear();
    }
};
struct BO_struct
{
    QString DataNo;
    QString Name;
    QString ctlModel;

    BO_struct()
    {
        DataNo.clear();
        Name.clear();
        ctlModel.clear();

    }
};
struct SG_struct
{
	QString DataNo;
	QString Name;

	SG_struct()
	{
		DataNo.clear();
		Name.clear();
	}
};
struct Model_XML
{
    QString No;
    QString Name;
    QString Ventor;
    QString Type;
    QString Address;
    QVector<BI_struct> BI_List;
    QVector<AI_struct> AI_List;
    QVector<CI_struct> CI_List;
    QVector<BO_struct> BO_List;
	QVector<SG_struct> SG_List;
    Model_XML()
    {
        No.clear();
        Name.clear();
        Ventor.clear();
        Type.clear();
        Address.clear();
        BI_List.clear();
        CI_List.clear();
		BO_List.clear();
        AI_List.clear();
		SG_List.clear();
    }
};
struct Device_Type
{
	QString Name;
	QString Type;
	Device_Type()
	{
		Name.clear();
		Type.clear();
	}
    bool operator==(const Device_Type &other) const

    //bool operator == (const Address_IP& rhs)
    {
        return (Name == other.Name);
    }
};
struct RemoteAddress_Type
{
	QString Name;
	QString Addr1;
	QString Addr2;
	QString Ap_Title;
	QString AE_Qualifier;
	QString Psel;
	QString Ssel;
	QString Tsel;
	QString NetType;
	RemoteAddress_Type()
	{
		Name.clear();
		Addr1.clear();
		Addr2.clear();
		Ap_Title.clear();

		AE_Qualifier.clear();
		Psel.clear();

		Ssel.clear();
		Tsel.clear();
		NetType.clear();
	}
};
struct IED_IEC
{
	QString Name;
	QString Vendor;
	QString Type;
    QString ChanMod;
	QString ChanName1;
	QString ChanName2;
	QString TimeServMode;
	QString CtlTimeOut;
	QString GITime;
	QString RptBufTime;
	QString RptIntgPd;
	QString LostConTime;
	QString KeepLive;
	QString AuthMod;
	QString AuthCode;
	IED_IEC()
	{
		Name.clear();
		Vendor.clear();
		Type.clear();
        ChanMod.clear();
		ChanName1.clear();
		ChanName2.clear();
		TimeServMode.clear();

		CtlTimeOut.clear();
		GITime.clear();

		RptBufTime.clear();
		RptIntgPd.clear();
		LostConTime.clear();
		KeepLive.clear();
		AuthCode.clear();
		AuthMod.clear();
	}
};
struct TimeServer
{
	QString Name;
	QString PortNo;
	QString GroupNum;
	QString Mode;
	QString GroupIp1;
	QString GroupIp2;
	QString GroupIp3;
	QString Interval;
	QString  TimeMode;
	TimeServer()
	{
		Name.clear();
		PortNo.clear();
		GroupNum.clear();
		Mode.clear();
		GroupIp1.clear();
		GroupIp2.clear();
		GroupIp3.clear();

		Interval.clear();
		TimeMode.clear();

	}
};
struct Address_IP
{
    QString s_AP_Title;
    QString s_AE_Qualifier;
    QString s_PSEL;
    QString s_SSEL;
    QString s_TSEL;
    QString s_IP;
    Address_IP()
    {
        s_AP_Title.clear();
        s_AE_Qualifier.clear();
        s_PSEL.clear();
        s_SSEL.clear();
        s_TSEL.clear();
        s_IP.clear();
    }
    void clear()
    {
        s_AP_Title.clear();
        s_AE_Qualifier.clear();
        s_PSEL.clear();
        s_SSEL.clear();
        s_TSEL.clear();
        s_IP.clear();
    }
    bool operator==(const Address_IP &other) const

	//bool operator == (const Address_IP& rhs)
	{
		return (s_IP == other.s_IP);
	}
};
struct Address_GOOSE
{
    QString s_cbName;
    QString s_ldInst;
    QString s_MAC_addr;
    QString s_VLAN_ID;
    QString s_APPID;
    QString s_VLAN_PRIORITY;
    QString s_MaxTime;
    QString s_MinTime;
    Address_GOOSE()
    {
        s_cbName.clear();
        s_ldInst.clear();
        s_VLAN_ID.clear();
        s_VLAN_ID.clear();
		s_APPID.clear();
        s_VLAN_PRIORITY.clear();
        s_MaxTime.clear();
        s_MinTime.clear();
        s_MAC_addr.clear();

    }
    void clear()
    {
        s_cbName.clear();
        s_ldInst.clear();
        s_VLAN_ID.clear();
        s_VLAN_ID.clear();
        s_APPID.clear();
        s_VLAN_PRIORITY.clear();
        s_MaxTime.clear();
        s_MinTime.clear();
        s_MAC_addr.clear();

    }
    bool operator==(const Address_GOOSE &other) const
	//bool operator == (const Address_GOOSE& rhs)
	{
		return (s_APPID == other.s_APPID &&
			s_MAC_addr == other.s_MAC_addr);
	}
	bool isEmpty() 
		//bool operator == (const Address_GOOSE& rhs)
	{
		if (!s_cbName.isEmpty())
		{
			return false;
		}	
		if (!s_ldInst.isEmpty())
		{
			return false;
		}
		if (!s_VLAN_ID.isEmpty())
		{
			return false;
		}
		if (!s_MAC_addr.isEmpty())
		{
			return false;
		}
		if (!s_APPID.isEmpty())
		{
			return false;
		}
		if (!s_VLAN_PRIORITY.isEmpty())
		{
			return false;
		}
		if (!s_MaxTime.isEmpty())
		{
			return false;
		}
		if (!s_MinTime.isEmpty())
		{
			return false;
		}
		return true;
	}
};
struct Address_SMV
{
    QString s_cbName;
    QString s_ldInst;
     QString s_MAC_addr;
    QString s_VLAN_ID;
    QString s_APPID;
    QString s_VLAN_PRIORITY;
    QString s_MaxTime;
        QString s_MinTime;
    Address_SMV()
    {
        s_cbName.clear();
        s_ldInst.clear();
        s_VLAN_ID.clear();
        s_VLAN_PRIORITY.clear();
        s_MaxTime.clear();
        s_MinTime.clear();
        s_MAC_addr.clear();

    }
    void clear()
    {
        s_cbName.clear();
        s_ldInst.clear();
        s_VLAN_ID.clear();
        s_VLAN_PRIORITY.clear();
        s_MaxTime.clear();
        s_MinTime.clear();
        s_MAC_addr.clear();

    }
    bool operator==(const Address_SMV &other) const
	//bool operator == (const Address_SMV& rhs)
	{
		return (s_APPID == other.s_APPID &&
			s_MAC_addr == other.s_MAC_addr);
	}
	bool isEmpty()
		//bool operator == (const Address_GOOSE& rhs)
	{
		if (!s_cbName.isEmpty())
		{
			return false;
		}
		if (!s_ldInst.isEmpty())
		{
			return false;
		}
		if (!s_VLAN_ID.isEmpty())
		{
			return false;
		}
		if (!s_MAC_addr.isEmpty())
		{
			return false;
		}
		if (!s_APPID.isEmpty())
		{
			return false;
		}
		if (!s_VLAN_PRIORITY.isEmpty())
		{
			return false;
		}
		if (!s_MaxTime.isEmpty())
		{
			return false;
		}
		if (!s_MinTime.isEmpty())
		{
			return false;
		}
		return true;
	}
};
  struct ConnectedAP
  {
    QString iedName;
    QString apName;
    Address_IP iP_addr;
    Address_GOOSE Goose_addr;
    Address_SMV   SMV_addr;
    ConnectedAP()
    {
        iedName.clear();
        apName.clear();

    }
	//inline bool operator ==(const ConnectedAP &left, const ConnectedAP &right) _NOEXCEPT
    bool operator==(const ConnectedAP &other) const
	{
		return( iedName == other.iedName &&
			apName == other.apName &&
			iP_addr == other.iP_addr &&
			SMV_addr == other.SMV_addr &&
			Goose_addr == other.Goose_addr);
	}

  };
  struct Input_Mapping
  {
	  int Index;
	  QString Interior_IED;
	  QString Interior_Reference;
	  QString Interior_ReferenceDesc;
	  QString External_IED;
	  QString External_Reference;
	  QString External_ReferenceDesc;
	  QString   External_DataSet;
	  QString External_Block;
	  QString External_MACAddr;
	  QString   External_APPID;
	  QString   External_Index;
	  QString   SubStrap_Name;
	  Input_Mapping()
	  {
		  Index = -1;
		  Interior_IED.clear();
		  Interior_Reference.clear();
		  Interior_ReferenceDesc.clear();
		  External_IED.clear();
		  External_Reference.clear();
		  External_ReferenceDesc.clear();
		  External_DataSet.clear();
		  External_Block.clear();
		  External_MACAddr.clear();
		  External_APPID.clear();
		  External_Index.clear();
		  SubStrap_Name.clear();
	  }


  };
  struct INPUT_Map
  {
	  int index;
	  TiXmlElement*  EXEefList;
	  INPUT_Map()
	  {
		  index = -1;
		  EXEefList = NULL;
	  }
  };
  struct INPUT_Config
  {
	  QString IEDName;
	  QString DataSetName;
	  TiXmlElement* GSENode;
	  TiXmlElement* SMVNode;

	  QVector<INPUT_Map> EXEefList;
	  INPUT_Config()
	  {
		  IEDName.clear();
		  EXEefList.clear();
		  SMVNode = NULL;
		  GSENode = NULL;
	  }
	  bool operator==(const INPUT_Config &other) const
	  {
		  return((IEDName == other.IEDName) && (DataSetName == other.DataSetName));
	  }

  };
  struct Map_IED
  {
        bool State;
        QString IEDName;
        bool available;
        Map_IED (){
            State=false;
            IEDName.clear();
            available =false;
        }
  };
  struct Attribue_Valuse
  {

        QString Attribue;
        QString Valuse;
        Attribue_Valuse (){

            Attribue.clear();
            Valuse.clear();
        }
  };
  struct AP_LD
  {

	  QString AP;
	  QString LD;
	  QString Dese;
	  AP_LD(){

		  AP.clear();
		  LD.clear();
		  Dese.clear();
	  }
  };
  struct Item_Node
  {

      QString value;
      QString name;
      int index;
      Item_Node(){

          index=-1;
          name.clear();
          value.clear();
      }
  };
  extern QTranslator *g_appTranslator;
#endif // DATASTRUCT

