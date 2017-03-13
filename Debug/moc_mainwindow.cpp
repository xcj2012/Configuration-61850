/****************************************************************************
** Meta object code from reading C++ file 'mainwindow.h'
**
** Created by: The Qt Meta Object Compiler version 67 (Qt 5.6.1)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include "../mainwindow.h"
#include <QtCore/qbytearray.h>
#include <QtCore/qmetatype.h>
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'mainwindow.h' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 67
#error "This file was generated using the moc from 5.6.1. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

QT_BEGIN_MOC_NAMESPACE
struct qt_meta_stringdata_MainWindow_t {
    QByteArrayData data[90];
    char stringdata0[1524];
};
#define QT_MOC_LITERAL(idx, ofs, len) \
    Q_STATIC_BYTE_ARRAY_DATA_HEADER_INITIALIZER_WITH_OFFSET(len, \
    qptrdiff(offsetof(qt_meta_stringdata_MainWindow_t, stringdata0) + ofs \
        - idx * sizeof(QByteArrayData)) \
    )
static const qt_meta_stringdata_MainWindow_t qt_meta_stringdata_MainWindow = {
    {
QT_MOC_LITERAL(0, 0, 10), // "MainWindow"
QT_MOC_LITERAL(1, 11, 10), // "SendChange"
QT_MOC_LITERAL(2, 22, 0), // ""
QT_MOC_LITERAL(3, 23, 5), // "state"
QT_MOC_LITERAL(4, 29, 10), // "Action_New"
QT_MOC_LITERAL(5, 40, 11), // "Action_Load"
QT_MOC_LITERAL(6, 52, 17), // "Header_DoublClick"
QT_MOC_LITERAL(7, 70, 14), // "Action_Save_As"
QT_MOC_LITERAL(8, 85, 11), // "Action_Save"
QT_MOC_LITERAL(9, 97, 10), // "Action_Add"
QT_MOC_LITERAL(10, 108, 10), // "Action_Del"
QT_MOC_LITERAL(11, 119, 12), // "Action_Extra"
QT_MOC_LITERAL(12, 132, 13), // "Action_Rename"
QT_MOC_LITERAL(13, 146, 13), // "Action_Config"
QT_MOC_LITERAL(14, 160, 17), // "SCLTree_MousEvent"
QT_MOC_LITERAL(15, 178, 3), // "pos"
QT_MOC_LITERAL(16, 182, 19), // "TableView_MousEvent"
QT_MOC_LITERAL(17, 202, 24), // "SubstationTree_MousEvent"
QT_MOC_LITERAL(18, 227, 17), // "IEDTree_MousEvent"
QT_MOC_LITERAL(19, 245, 15), // "openMenuProgram"
QT_MOC_LITERAL(20, 261, 16), // "QTreeWidgetItem*"
QT_MOC_LITERAL(21, 278, 12), // "ImportOneICD"
QT_MOC_LITERAL(22, 291, 12), // "ImportOneCID"
QT_MOC_LITERAL(23, 304, 19), // "OnHeaderDataChanged"
QT_MOC_LITERAL(24, 324, 7), // "topLeft"
QT_MOC_LITERAL(25, 332, 11), // "bottomRight"
QT_MOC_LITERAL(26, 344, 17), // "OnCommDataChanged"
QT_MOC_LITERAL(27, 362, 19), // "OnSubnetDataChanged"
QT_MOC_LITERAL(28, 382, 16), // "OnIEDDataChanged"
QT_MOC_LITERAL(29, 399, 15), // "OnLDDataChanged"
QT_MOC_LITERAL(30, 415, 15), // "OnLNDataChanged"
QT_MOC_LITERAL(31, 431, 17), // "OnDataDataChanged"
QT_MOC_LITERAL(32, 449, 16), // "OnGSEDataChanged"
QT_MOC_LITERAL(33, 466, 16), // "OnSMVDataChanged"
QT_MOC_LITERAL(34, 483, 16), // "OnRptDataChanged"
QT_MOC_LITERAL(35, 500, 16), // "OnLogDataChanged"
QT_MOC_LITERAL(36, 517, 19), // "OnMmsNetDataChanged"
QT_MOC_LITERAL(37, 537, 21), // "OnGooseNetDataChanged"
QT_MOC_LITERAL(38, 559, 19), // "OnSmvNetDataChanged"
QT_MOC_LITERAL(39, 579, 22), // "OnDataSetdoubleClicked"
QT_MOC_LITERAL(40, 602, 5), // "index"
QT_MOC_LITERAL(41, 608, 20), // "OnDataSetDataClicked"
QT_MOC_LITERAL(42, 629, 18), // "OnTableViewClicked"
QT_MOC_LITERAL(43, 648, 25), // "OnHorizontalHeaderClicked"
QT_MOC_LITERAL(44, 674, 24), // "OnTableViewdoubleClicked"
QT_MOC_LITERAL(45, 699, 24), // "PushButton_DataSet_Click"
QT_MOC_LITERAL(46, 724, 20), // "PushButton_GSE_Click"
QT_MOC_LITERAL(47, 745, 22), // "PushButton_Input_Click"
QT_MOC_LITERAL(48, 768, 20), // "PushButton_Log_Click"
QT_MOC_LITERAL(49, 789, 28), // "PushButton_LogicDevice_Click"
QT_MOC_LITERAL(50, 818, 27), // "PushButton_LogiceNode_Click"
QT_MOC_LITERAL(51, 846, 23), // "PushButton_Report_Click"
QT_MOC_LITERAL(52, 870, 20), // "PushButton_SMV_Click"
QT_MOC_LITERAL(53, 891, 16), // "Combox_LD_Active"
QT_MOC_LITERAL(54, 908, 3), // "str"
QT_MOC_LITERAL(55, 912, 16), // "Combox_LN_Active"
QT_MOC_LITERAL(56, 929, 16), // "PushButton_Fresh"
QT_MOC_LITERAL(57, 946, 20), // "IEDTreeDoubleClicked"
QT_MOC_LITERAL(58, 967, 4), // "item"
QT_MOC_LITERAL(59, 972, 6), // "column"
QT_MOC_LITERAL(60, 979, 22), // "Action_Integrity_Check"
QT_MOC_LITERAL(61, 1002, 26), // "Action_Communication_Check"
QT_MOC_LITERAL(62, 1029, 19), // "Action_Schema_Check"
QT_MOC_LITERAL(63, 1049, 29), // "Action_Model_validation_check"
QT_MOC_LITERAL(64, 1079, 26), // "Action_Type_Terminal_check"
QT_MOC_LITERAL(65, 1106, 16), // "Action_IECConfig"
QT_MOC_LITERAL(66, 1123, 15), // "Action_LogicMap"
QT_MOC_LITERAL(67, 1139, 18), // "Action_BatchImport"
QT_MOC_LITERAL(68, 1158, 13), // "Action_Reload"
QT_MOC_LITERAL(69, 1172, 13), // "Action_DelIED"
QT_MOC_LITERAL(70, 1186, 16), // "Action_ExportCID"
QT_MOC_LITERAL(71, 1203, 16), // "Action_ExportXLS"
QT_MOC_LITERAL(72, 1220, 16), // "Action_ExportXML"
QT_MOC_LITERAL(73, 1237, 15), // "Action_Increase"
QT_MOC_LITERAL(74, 1253, 12), // "Action_Batch"
QT_MOC_LITERAL(75, 1266, 21), // "DataSetDate_MousEvent"
QT_MOC_LITERAL(76, 1288, 14), // "Auto_SetMmsNet"
QT_MOC_LITERAL(77, 1303, 16), // "Auto_SetGooseNet"
QT_MOC_LITERAL(78, 1320, 14), // "Auto_SetSmvNet"
QT_MOC_LITERAL(79, 1335, 23), // "Auto_Init_Communication"
QT_MOC_LITERAL(80, 1359, 17), // "Action_ClearInput"
QT_MOC_LITERAL(81, 1377, 13), // "ReceiveChange"
QT_MOC_LITERAL(82, 1391, 20), // "TableView_Row_Select"
QT_MOC_LITERAL(83, 1412, 3), // "row"
QT_MOC_LITERAL(84, 1416, 20), // "Auto_AddControlBlock"
QT_MOC_LITERAL(85, 1437, 16), // "Action_ImportMap"
QT_MOC_LITERAL(86, 1454, 15), // "Action_MergeSCD"
QT_MOC_LITERAL(87, 1470, 21), // "Action_SwitchLanguage"
QT_MOC_LITERAL(88, 1492, 12), // "Action_Close"
QT_MOC_LITERAL(89, 1505, 18) // "Action_CID_Contain"

    },
    "MainWindow\0SendChange\0\0state\0Action_New\0"
    "Action_Load\0Header_DoublClick\0"
    "Action_Save_As\0Action_Save\0Action_Add\0"
    "Action_Del\0Action_Extra\0Action_Rename\0"
    "Action_Config\0SCLTree_MousEvent\0pos\0"
    "TableView_MousEvent\0SubstationTree_MousEvent\0"
    "IEDTree_MousEvent\0openMenuProgram\0"
    "QTreeWidgetItem*\0ImportOneICD\0"
    "ImportOneCID\0OnHeaderDataChanged\0"
    "topLeft\0bottomRight\0OnCommDataChanged\0"
    "OnSubnetDataChanged\0OnIEDDataChanged\0"
    "OnLDDataChanged\0OnLNDataChanged\0"
    "OnDataDataChanged\0OnGSEDataChanged\0"
    "OnSMVDataChanged\0OnRptDataChanged\0"
    "OnLogDataChanged\0OnMmsNetDataChanged\0"
    "OnGooseNetDataChanged\0OnSmvNetDataChanged\0"
    "OnDataSetdoubleClicked\0index\0"
    "OnDataSetDataClicked\0OnTableViewClicked\0"
    "OnHorizontalHeaderClicked\0"
    "OnTableViewdoubleClicked\0"
    "PushButton_DataSet_Click\0PushButton_GSE_Click\0"
    "PushButton_Input_Click\0PushButton_Log_Click\0"
    "PushButton_LogicDevice_Click\0"
    "PushButton_LogiceNode_Click\0"
    "PushButton_Report_Click\0PushButton_SMV_Click\0"
    "Combox_LD_Active\0str\0Combox_LN_Active\0"
    "PushButton_Fresh\0IEDTreeDoubleClicked\0"
    "item\0column\0Action_Integrity_Check\0"
    "Action_Communication_Check\0"
    "Action_Schema_Check\0Action_Model_validation_check\0"
    "Action_Type_Terminal_check\0Action_IECConfig\0"
    "Action_LogicMap\0Action_BatchImport\0"
    "Action_Reload\0Action_DelIED\0"
    "Action_ExportCID\0Action_ExportXLS\0"
    "Action_ExportXML\0Action_Increase\0"
    "Action_Batch\0DataSetDate_MousEvent\0"
    "Auto_SetMmsNet\0Auto_SetGooseNet\0"
    "Auto_SetSmvNet\0Auto_Init_Communication\0"
    "Action_ClearInput\0ReceiveChange\0"
    "TableView_Row_Select\0row\0Auto_AddControlBlock\0"
    "Action_ImportMap\0Action_MergeSCD\0"
    "Action_SwitchLanguage\0Action_Close\0"
    "Action_CID_Contain"
};
#undef QT_MOC_LITERAL

static const uint qt_meta_data_MainWindow[] = {

 // content:
       7,       // revision
       0,       // classname
       0,    0, // classinfo
      78,   14, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       1,       // signalCount

 // signals: name, argc, parameters, tag, flags
       1,    1,  404,    2, 0x06 /* Public */,

 // slots: name, argc, parameters, tag, flags
       4,    0,  407,    2, 0x08 /* Private */,
       5,    0,  408,    2, 0x08 /* Private */,
       6,    1,  409,    2, 0x08 /* Private */,
       7,    0,  412,    2, 0x08 /* Private */,
       8,    0,  413,    2, 0x08 /* Private */,
       9,    0,  414,    2, 0x08 /* Private */,
      10,    0,  415,    2, 0x08 /* Private */,
      11,    0,  416,    2, 0x08 /* Private */,
      12,    0,  417,    2, 0x08 /* Private */,
      13,    0,  418,    2, 0x08 /* Private */,
      14,    1,  419,    2, 0x08 /* Private */,
      16,    1,  422,    2, 0x08 /* Private */,
      17,    1,  425,    2, 0x08 /* Private */,
      18,    1,  428,    2, 0x08 /* Private */,
      19,    2,  431,    2, 0x08 /* Private */,
      21,    0,  436,    2, 0x08 /* Private */,
      22,    0,  437,    2, 0x08 /* Private */,
      23,    2,  438,    2, 0x08 /* Private */,
      26,    2,  443,    2, 0x08 /* Private */,
      27,    2,  448,    2, 0x08 /* Private */,
      28,    2,  453,    2, 0x08 /* Private */,
      29,    2,  458,    2, 0x08 /* Private */,
      30,    2,  463,    2, 0x08 /* Private */,
      31,    2,  468,    2, 0x08 /* Private */,
      32,    2,  473,    2, 0x08 /* Private */,
      33,    2,  478,    2, 0x08 /* Private */,
      34,    2,  483,    2, 0x08 /* Private */,
      35,    2,  488,    2, 0x08 /* Private */,
      36,    2,  493,    2, 0x08 /* Private */,
      37,    2,  498,    2, 0x08 /* Private */,
      38,    2,  503,    2, 0x08 /* Private */,
      39,    1,  508,    2, 0x08 /* Private */,
      41,    1,  511,    2, 0x08 /* Private */,
      42,    1,  514,    2, 0x08 /* Private */,
      43,    1,  517,    2, 0x08 /* Private */,
      44,    1,  520,    2, 0x08 /* Private */,
      45,    0,  523,    2, 0x08 /* Private */,
      46,    0,  524,    2, 0x08 /* Private */,
      47,    0,  525,    2, 0x08 /* Private */,
      48,    0,  526,    2, 0x08 /* Private */,
      49,    0,  527,    2, 0x08 /* Private */,
      50,    0,  528,    2, 0x08 /* Private */,
      51,    0,  529,    2, 0x08 /* Private */,
      52,    0,  530,    2, 0x08 /* Private */,
      53,    1,  531,    2, 0x08 /* Private */,
      55,    1,  534,    2, 0x08 /* Private */,
      56,    0,  537,    2, 0x08 /* Private */,
      57,    2,  538,    2, 0x08 /* Private */,
      60,    0,  543,    2, 0x08 /* Private */,
      61,    0,  544,    2, 0x08 /* Private */,
      62,    0,  545,    2, 0x08 /* Private */,
      63,    0,  546,    2, 0x08 /* Private */,
      64,    0,  547,    2, 0x08 /* Private */,
      65,    0,  548,    2, 0x08 /* Private */,
      66,    0,  549,    2, 0x08 /* Private */,
      67,    0,  550,    2, 0x08 /* Private */,
      68,    0,  551,    2, 0x08 /* Private */,
      69,    0,  552,    2, 0x08 /* Private */,
      70,    0,  553,    2, 0x08 /* Private */,
      71,    0,  554,    2, 0x08 /* Private */,
      72,    0,  555,    2, 0x08 /* Private */,
      73,    0,  556,    2, 0x08 /* Private */,
      74,    0,  557,    2, 0x08 /* Private */,
      75,    1,  558,    2, 0x08 /* Private */,
      76,    0,  561,    2, 0x08 /* Private */,
      77,    0,  562,    2, 0x08 /* Private */,
      78,    0,  563,    2, 0x08 /* Private */,
      79,    0,  564,    2, 0x08 /* Private */,
      80,    0,  565,    2, 0x08 /* Private */,
      81,    1,  566,    2, 0x08 /* Private */,
      82,    1,  569,    2, 0x08 /* Private */,
      84,    0,  572,    2, 0x08 /* Private */,
      85,    0,  573,    2, 0x08 /* Private */,
      86,    0,  574,    2, 0x08 /* Private */,
      87,    0,  575,    2, 0x08 /* Private */,
      88,    0,  576,    2, 0x08 /* Private */,
      89,    0,  577,    2, 0x08 /* Private */,

 // signals: parameters
    QMetaType::Void, QMetaType::Int,    3,

 // slots: parameters
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void, QMetaType::QModelIndex,    2,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void, QMetaType::QPoint,   15,
    QMetaType::Void, QMetaType::QPoint,   15,
    QMetaType::Void, QMetaType::QPoint,   15,
    QMetaType::Void, QMetaType::QPoint,   15,
    QMetaType::Void, 0x80000000 | 20, QMetaType::Int,    2,    2,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void, QMetaType::QModelIndex, QMetaType::QModelIndex,   24,   25,
    QMetaType::Void, QMetaType::QModelIndex, QMetaType::QModelIndex,   24,   25,
    QMetaType::Void, QMetaType::QModelIndex, QMetaType::QModelIndex,   24,   25,
    QMetaType::Void, QMetaType::QModelIndex, QMetaType::QModelIndex,   24,   25,
    QMetaType::Void, QMetaType::QModelIndex, QMetaType::QModelIndex,   24,   25,
    QMetaType::Void, QMetaType::QModelIndex, QMetaType::QModelIndex,   24,   25,
    QMetaType::Void, QMetaType::QModelIndex, QMetaType::QModelIndex,   24,   25,
    QMetaType::Void, QMetaType::QModelIndex, QMetaType::QModelIndex,   24,   25,
    QMetaType::Void, QMetaType::QModelIndex, QMetaType::QModelIndex,   24,   25,
    QMetaType::Void, QMetaType::QModelIndex, QMetaType::QModelIndex,   24,   25,
    QMetaType::Void, QMetaType::QModelIndex, QMetaType::QModelIndex,   24,   25,
    QMetaType::Void, QMetaType::QModelIndex, QMetaType::QModelIndex,   24,   25,
    QMetaType::Void, QMetaType::QModelIndex, QMetaType::QModelIndex,   24,   25,
    QMetaType::Void, QMetaType::QModelIndex, QMetaType::QModelIndex,   24,   25,
    QMetaType::Void, QMetaType::QModelIndex,   40,
    QMetaType::Void, QMetaType::QModelIndex,   40,
    QMetaType::Void, QMetaType::QModelIndex,   40,
    QMetaType::Void, QMetaType::QModelIndex,   40,
    QMetaType::Void, QMetaType::QModelIndex,   40,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void, QMetaType::QString,   54,
    QMetaType::Void, QMetaType::QString,   54,
    QMetaType::Void,
    QMetaType::Void, 0x80000000 | 20, QMetaType::Int,   58,   59,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void, QMetaType::QPoint,   15,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void, QMetaType::Int,    3,
    QMetaType::Void, QMetaType::QModelIndex,   83,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,

       0        // eod
};

void MainWindow::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::InvokeMetaMethod) {
        MainWindow *_t = static_cast<MainWindow *>(_o);
        Q_UNUSED(_t)
        switch (_id) {
        case 0: _t->SendChange((*reinterpret_cast< int(*)>(_a[1]))); break;
        case 1: _t->Action_New(); break;
        case 2: _t->Action_Load(); break;
        case 3: _t->Header_DoublClick((*reinterpret_cast< QModelIndex(*)>(_a[1]))); break;
        case 4: _t->Action_Save_As(); break;
        case 5: _t->Action_Save(); break;
        case 6: _t->Action_Add(); break;
        case 7: _t->Action_Del(); break;
        case 8: _t->Action_Extra(); break;
        case 9: _t->Action_Rename(); break;
        case 10: _t->Action_Config(); break;
        case 11: _t->SCLTree_MousEvent((*reinterpret_cast< const QPoint(*)>(_a[1]))); break;
        case 12: _t->TableView_MousEvent((*reinterpret_cast< const QPoint(*)>(_a[1]))); break;
        case 13: _t->SubstationTree_MousEvent((*reinterpret_cast< const QPoint(*)>(_a[1]))); break;
        case 14: _t->IEDTree_MousEvent((*reinterpret_cast< const QPoint(*)>(_a[1]))); break;
        case 15: _t->openMenuProgram((*reinterpret_cast< QTreeWidgetItem*(*)>(_a[1])),(*reinterpret_cast< int(*)>(_a[2]))); break;
        case 16: _t->ImportOneICD(); break;
        case 17: _t->ImportOneCID(); break;
        case 18: _t->OnHeaderDataChanged((*reinterpret_cast< const QModelIndex(*)>(_a[1])),(*reinterpret_cast< const QModelIndex(*)>(_a[2]))); break;
        case 19: _t->OnCommDataChanged((*reinterpret_cast< const QModelIndex(*)>(_a[1])),(*reinterpret_cast< const QModelIndex(*)>(_a[2]))); break;
        case 20: _t->OnSubnetDataChanged((*reinterpret_cast< const QModelIndex(*)>(_a[1])),(*reinterpret_cast< const QModelIndex(*)>(_a[2]))); break;
        case 21: _t->OnIEDDataChanged((*reinterpret_cast< const QModelIndex(*)>(_a[1])),(*reinterpret_cast< const QModelIndex(*)>(_a[2]))); break;
        case 22: _t->OnLDDataChanged((*reinterpret_cast< const QModelIndex(*)>(_a[1])),(*reinterpret_cast< const QModelIndex(*)>(_a[2]))); break;
        case 23: _t->OnLNDataChanged((*reinterpret_cast< const QModelIndex(*)>(_a[1])),(*reinterpret_cast< const QModelIndex(*)>(_a[2]))); break;
        case 24: _t->OnDataDataChanged((*reinterpret_cast< const QModelIndex(*)>(_a[1])),(*reinterpret_cast< const QModelIndex(*)>(_a[2]))); break;
        case 25: _t->OnGSEDataChanged((*reinterpret_cast< const QModelIndex(*)>(_a[1])),(*reinterpret_cast< const QModelIndex(*)>(_a[2]))); break;
        case 26: _t->OnSMVDataChanged((*reinterpret_cast< const QModelIndex(*)>(_a[1])),(*reinterpret_cast< const QModelIndex(*)>(_a[2]))); break;
        case 27: _t->OnRptDataChanged((*reinterpret_cast< const QModelIndex(*)>(_a[1])),(*reinterpret_cast< const QModelIndex(*)>(_a[2]))); break;
        case 28: _t->OnLogDataChanged((*reinterpret_cast< const QModelIndex(*)>(_a[1])),(*reinterpret_cast< const QModelIndex(*)>(_a[2]))); break;
        case 29: _t->OnMmsNetDataChanged((*reinterpret_cast< const QModelIndex(*)>(_a[1])),(*reinterpret_cast< const QModelIndex(*)>(_a[2]))); break;
        case 30: _t->OnGooseNetDataChanged((*reinterpret_cast< const QModelIndex(*)>(_a[1])),(*reinterpret_cast< const QModelIndex(*)>(_a[2]))); break;
        case 31: _t->OnSmvNetDataChanged((*reinterpret_cast< const QModelIndex(*)>(_a[1])),(*reinterpret_cast< const QModelIndex(*)>(_a[2]))); break;
        case 32: _t->OnDataSetdoubleClicked((*reinterpret_cast< const QModelIndex(*)>(_a[1]))); break;
        case 33: _t->OnDataSetDataClicked((*reinterpret_cast< const QModelIndex(*)>(_a[1]))); break;
        case 34: _t->OnTableViewClicked((*reinterpret_cast< const QModelIndex(*)>(_a[1]))); break;
        case 35: _t->OnHorizontalHeaderClicked((*reinterpret_cast< const QModelIndex(*)>(_a[1]))); break;
        case 36: _t->OnTableViewdoubleClicked((*reinterpret_cast< const QModelIndex(*)>(_a[1]))); break;
        case 37: _t->PushButton_DataSet_Click(); break;
        case 38: _t->PushButton_GSE_Click(); break;
        case 39: _t->PushButton_Input_Click(); break;
        case 40: _t->PushButton_Log_Click(); break;
        case 41: _t->PushButton_LogicDevice_Click(); break;
        case 42: _t->PushButton_LogiceNode_Click(); break;
        case 43: _t->PushButton_Report_Click(); break;
        case 44: _t->PushButton_SMV_Click(); break;
        case 45: _t->Combox_LD_Active((*reinterpret_cast< QString(*)>(_a[1]))); break;
        case 46: _t->Combox_LN_Active((*reinterpret_cast< QString(*)>(_a[1]))); break;
        case 47: _t->PushButton_Fresh(); break;
        case 48: _t->IEDTreeDoubleClicked((*reinterpret_cast< QTreeWidgetItem*(*)>(_a[1])),(*reinterpret_cast< int(*)>(_a[2]))); break;
        case 49: _t->Action_Integrity_Check(); break;
        case 50: _t->Action_Communication_Check(); break;
        case 51: _t->Action_Schema_Check(); break;
        case 52: _t->Action_Model_validation_check(); break;
        case 53: _t->Action_Type_Terminal_check(); break;
        case 54: _t->Action_IECConfig(); break;
        case 55: _t->Action_LogicMap(); break;
        case 56: _t->Action_BatchImport(); break;
        case 57: _t->Action_Reload(); break;
        case 58: _t->Action_DelIED(); break;
        case 59: _t->Action_ExportCID(); break;
        case 60: _t->Action_ExportXLS(); break;
        case 61: _t->Action_ExportXML(); break;
        case 62: _t->Action_Increase(); break;
        case 63: _t->Action_Batch(); break;
        case 64: _t->DataSetDate_MousEvent((*reinterpret_cast< const QPoint(*)>(_a[1]))); break;
        case 65: _t->Auto_SetMmsNet(); break;
        case 66: _t->Auto_SetGooseNet(); break;
        case 67: _t->Auto_SetSmvNet(); break;
        case 68: _t->Auto_Init_Communication(); break;
        case 69: _t->Action_ClearInput(); break;
        case 70: _t->ReceiveChange((*reinterpret_cast< int(*)>(_a[1]))); break;
        case 71: _t->TableView_Row_Select((*reinterpret_cast< QModelIndex(*)>(_a[1]))); break;
        case 72: _t->Auto_AddControlBlock(); break;
        case 73: _t->Action_ImportMap(); break;
        case 74: _t->Action_MergeSCD(); break;
        case 75: _t->Action_SwitchLanguage(); break;
        case 76: _t->Action_Close(); break;
        case 77: _t->Action_CID_Contain(); break;
        default: ;
        }
    } else if (_c == QMetaObject::IndexOfMethod) {
        int *result = reinterpret_cast<int *>(_a[0]);
        void **func = reinterpret_cast<void **>(_a[1]);
        {
            typedef void (MainWindow::*_t)(int );
            if (*reinterpret_cast<_t *>(func) == static_cast<_t>(&MainWindow::SendChange)) {
                *result = 0;
                return;
            }
        }
    }
}

const QMetaObject MainWindow::staticMetaObject = {
    { &QMainWindow::staticMetaObject, qt_meta_stringdata_MainWindow.data,
      qt_meta_data_MainWindow,  qt_static_metacall, Q_NULLPTR, Q_NULLPTR}
};


const QMetaObject *MainWindow::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->dynamicMetaObject() : &staticMetaObject;
}

void *MainWindow::qt_metacast(const char *_clname)
{
    if (!_clname) return Q_NULLPTR;
    if (!strcmp(_clname, qt_meta_stringdata_MainWindow.stringdata0))
        return static_cast<void*>(const_cast< MainWindow*>(this));
    return QMainWindow::qt_metacast(_clname);
}

int MainWindow::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = QMainWindow::qt_metacall(_c, _id, _a);
    if (_id < 0)
        return _id;
    if (_c == QMetaObject::InvokeMetaMethod) {
        if (_id < 78)
            qt_static_metacall(this, _c, _id, _a);
        _id -= 78;
    } else if (_c == QMetaObject::RegisterMethodArgumentMetaType) {
        if (_id < 78)
            *reinterpret_cast<int*>(_a[0]) = -1;
        _id -= 78;
    }
    return _id;
}

// SIGNAL 0
void MainWindow::SendChange(int _t1)
{
    void *_a[] = { Q_NULLPTR, const_cast<void*>(reinterpret_cast<const void*>(&_t1)) };
    QMetaObject::activate(this, &staticMetaObject, 0, _a);
}
QT_END_MOC_NAMESPACE
