/****************************************************************************
** Meta object code from reading C++ file 'mmsextra.h'
**
** Created by: The Qt Meta Object Compiler version 67 (Qt 5.6.1)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include "../mmsextra.h"
#include <QtCore/qbytearray.h>
#include <QtCore/qmetatype.h>
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'mmsextra.h' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 67
#error "This file was generated using the moc from 5.6.1. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

QT_BEGIN_MOC_NAMESPACE
struct qt_meta_stringdata_MMSExtra_t {
    QByteArrayData data[9];
    char stringdata0[122];
};
#define QT_MOC_LITERAL(idx, ofs, len) \
    Q_STATIC_BYTE_ARRAY_DATA_HEADER_INITIALIZER_WITH_OFFSET(len, \
    qptrdiff(offsetof(qt_meta_stringdata_MMSExtra_t, stringdata0) + ofs \
        - idx * sizeof(QByteArrayData)) \
    )
static const qt_meta_stringdata_MMSExtra_t qt_meta_stringdata_MMSExtra = {
    {
QT_MOC_LITERAL(0, 0, 8), // "MMSExtra"
QT_MOC_LITERAL(1, 9, 16), // "OnMMSDataChanged"
QT_MOC_LITERAL(2, 26, 0), // ""
QT_MOC_LITERAL(3, 27, 7), // "topLeft"
QT_MOC_LITERAL(4, 35, 11), // "bottomRight"
QT_MOC_LITERAL(5, 47, 18), // "OnGOOSEDataChanged"
QT_MOC_LITERAL(6, 66, 16), // "OnSMVDataChanged"
QT_MOC_LITERAL(7, 83, 18), // "onpushbutton_apply"
QT_MOC_LITERAL(8, 102, 19) // "onpushbutton_cancel"

    },
    "MMSExtra\0OnMMSDataChanged\0\0topLeft\0"
    "bottomRight\0OnGOOSEDataChanged\0"
    "OnSMVDataChanged\0onpushbutton_apply\0"
    "onpushbutton_cancel"
};
#undef QT_MOC_LITERAL

static const uint qt_meta_data_MMSExtra[] = {

 // content:
       7,       // revision
       0,       // classname
       0,    0, // classinfo
       5,   14, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       0,       // signalCount

 // slots: name, argc, parameters, tag, flags
       1,    2,   39,    2, 0x08 /* Private */,
       5,    2,   44,    2, 0x08 /* Private */,
       6,    2,   49,    2, 0x08 /* Private */,
       7,    0,   54,    2, 0x08 /* Private */,
       8,    0,   55,    2, 0x08 /* Private */,

 // slots: parameters
    QMetaType::Void, QMetaType::QModelIndex, QMetaType::QModelIndex,    3,    4,
    QMetaType::Void, QMetaType::QModelIndex, QMetaType::QModelIndex,    3,    4,
    QMetaType::Void, QMetaType::QModelIndex, QMetaType::QModelIndex,    3,    4,
    QMetaType::Void,
    QMetaType::Void,

       0        // eod
};

void MMSExtra::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::InvokeMetaMethod) {
        MMSExtra *_t = static_cast<MMSExtra *>(_o);
        Q_UNUSED(_t)
        switch (_id) {
        case 0: _t->OnMMSDataChanged((*reinterpret_cast< const QModelIndex(*)>(_a[1])),(*reinterpret_cast< const QModelIndex(*)>(_a[2]))); break;
        case 1: _t->OnGOOSEDataChanged((*reinterpret_cast< const QModelIndex(*)>(_a[1])),(*reinterpret_cast< const QModelIndex(*)>(_a[2]))); break;
        case 2: _t->OnSMVDataChanged((*reinterpret_cast< const QModelIndex(*)>(_a[1])),(*reinterpret_cast< const QModelIndex(*)>(_a[2]))); break;
        case 3: _t->onpushbutton_apply(); break;
        case 4: _t->onpushbutton_cancel(); break;
        default: ;
        }
    }
}

const QMetaObject MMSExtra::staticMetaObject = {
    { &QDialog::staticMetaObject, qt_meta_stringdata_MMSExtra.data,
      qt_meta_data_MMSExtra,  qt_static_metacall, Q_NULLPTR, Q_NULLPTR}
};


const QMetaObject *MMSExtra::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->dynamicMetaObject() : &staticMetaObject;
}

void *MMSExtra::qt_metacast(const char *_clname)
{
    if (!_clname) return Q_NULLPTR;
    if (!strcmp(_clname, qt_meta_stringdata_MMSExtra.stringdata0))
        return static_cast<void*>(const_cast< MMSExtra*>(this));
    return QDialog::qt_metacast(_clname);
}

int MMSExtra::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = QDialog::qt_metacall(_c, _id, _a);
    if (_id < 0)
        return _id;
    if (_c == QMetaObject::InvokeMetaMethod) {
        if (_id < 5)
            qt_static_metacall(this, _c, _id, _a);
        _id -= 5;
    } else if (_c == QMetaObject::RegisterMethodArgumentMetaType) {
        if (_id < 5)
            *reinterpret_cast<int*>(_a[0]) = -1;
        _id -= 5;
    }
    return _id;
}
QT_END_MOC_NAMESPACE
