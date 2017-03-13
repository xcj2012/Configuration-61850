/****************************************************************************
** Meta object code from reading C++ file 'iecconfig.h'
**
** Created by: The Qt Meta Object Compiler version 67 (Qt 5.6.1)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include "../iecconfig.h"
#include <QtCore/qbytearray.h>
#include <QtCore/qmetatype.h>
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'iecconfig.h' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 67
#error "This file was generated using the moc from 5.6.1. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

QT_BEGIN_MOC_NAMESPACE
struct qt_meta_stringdata_IECCONFIG_t {
    QByteArrayData data[13];
    char stringdata0[230];
};
#define QT_MOC_LITERAL(idx, ofs, len) \
    Q_STATIC_BYTE_ARRAY_DATA_HEADER_INITIALIZER_WITH_OFFSET(len, \
    qptrdiff(offsetof(qt_meta_stringdata_IECCONFIG_t, stringdata0) + ofs \
        - idx * sizeof(QByteArrayData)) \
    )
static const qt_meta_stringdata_IECCONFIG_t qt_meta_stringdata_IECCONFIG = {
    {
QT_MOC_LITERAL(0, 0, 9), // "IECCONFIG"
QT_MOC_LITERAL(1, 10, 20), // "pushbutton_New_click"
QT_MOC_LITERAL(2, 31, 0), // ""
QT_MOC_LITERAL(3, 32, 20), // "pushbutton_Add_click"
QT_MOC_LITERAL(4, 53, 20), // "pushbutton_Del_click"
QT_MOC_LITERAL(5, 74, 21), // "pushbutton_Save_click"
QT_MOC_LITERAL(6, 96, 21), // "pushbutton_Time_click"
QT_MOC_LITERAL(7, 118, 24), // "pushbutton_Station_click"
QT_MOC_LITERAL(8, 143, 21), // "RadioButton_new_click"
QT_MOC_LITERAL(9, 165, 24), // "RadioButton_browse_click"
QT_MOC_LITERAL(10, 190, 13), // "OnDataChanged"
QT_MOC_LITERAL(11, 204, 19), // "OnDatadoubleClicked"
QT_MOC_LITERAL(12, 224, 5) // "index"

    },
    "IECCONFIG\0pushbutton_New_click\0\0"
    "pushbutton_Add_click\0pushbutton_Del_click\0"
    "pushbutton_Save_click\0pushbutton_Time_click\0"
    "pushbutton_Station_click\0RadioButton_new_click\0"
    "RadioButton_browse_click\0OnDataChanged\0"
    "OnDatadoubleClicked\0index"
};
#undef QT_MOC_LITERAL

static const uint qt_meta_data_IECCONFIG[] = {

 // content:
       7,       // revision
       0,       // classname
       0,    0, // classinfo
      10,   14, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       0,       // signalCount

 // slots: name, argc, parameters, tag, flags
       1,    0,   64,    2, 0x08 /* Private */,
       3,    0,   65,    2, 0x08 /* Private */,
       4,    0,   66,    2, 0x08 /* Private */,
       5,    0,   67,    2, 0x08 /* Private */,
       6,    0,   68,    2, 0x08 /* Private */,
       7,    0,   69,    2, 0x08 /* Private */,
       8,    0,   70,    2, 0x08 /* Private */,
       9,    0,   71,    2, 0x08 /* Private */,
      10,    2,   72,    2, 0x08 /* Private */,
      11,    1,   77,    2, 0x08 /* Private */,

 // slots: parameters
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void, QMetaType::QModelIndex, QMetaType::QModelIndex,    2,    2,
    QMetaType::Void, QMetaType::QModelIndex,   12,

       0        // eod
};

void IECCONFIG::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::InvokeMetaMethod) {
        IECCONFIG *_t = static_cast<IECCONFIG *>(_o);
        Q_UNUSED(_t)
        switch (_id) {
        case 0: _t->pushbutton_New_click(); break;
        case 1: _t->pushbutton_Add_click(); break;
        case 2: _t->pushbutton_Del_click(); break;
        case 3: _t->pushbutton_Save_click(); break;
        case 4: _t->pushbutton_Time_click(); break;
        case 5: _t->pushbutton_Station_click(); break;
        case 6: _t->RadioButton_new_click(); break;
        case 7: _t->RadioButton_browse_click(); break;
        case 8: _t->OnDataChanged((*reinterpret_cast< const QModelIndex(*)>(_a[1])),(*reinterpret_cast< const QModelIndex(*)>(_a[2]))); break;
        case 9: _t->OnDatadoubleClicked((*reinterpret_cast< const QModelIndex(*)>(_a[1]))); break;
        default: ;
        }
    }
}

const QMetaObject IECCONFIG::staticMetaObject = {
    { &QDialog::staticMetaObject, qt_meta_stringdata_IECCONFIG.data,
      qt_meta_data_IECCONFIG,  qt_static_metacall, Q_NULLPTR, Q_NULLPTR}
};


const QMetaObject *IECCONFIG::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->dynamicMetaObject() : &staticMetaObject;
}

void *IECCONFIG::qt_metacast(const char *_clname)
{
    if (!_clname) return Q_NULLPTR;
    if (!strcmp(_clname, qt_meta_stringdata_IECCONFIG.stringdata0))
        return static_cast<void*>(const_cast< IECCONFIG*>(this));
    return QDialog::qt_metacast(_clname);
}

int IECCONFIG::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = QDialog::qt_metacall(_c, _id, _a);
    if (_id < 0)
        return _id;
    if (_c == QMetaObject::InvokeMetaMethod) {
        if (_id < 10)
            qt_static_metacall(this, _c, _id, _a);
        _id -= 10;
    } else if (_c == QMetaObject::RegisterMethodArgumentMetaType) {
        if (_id < 10)
            *reinterpret_cast<int*>(_a[0]) = -1;
        _id -= 10;
    }
    return _id;
}
QT_END_MOC_NAMESPACE
