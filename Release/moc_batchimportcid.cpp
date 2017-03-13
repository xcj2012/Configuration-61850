/****************************************************************************
** Meta object code from reading C++ file 'batchimportcid.h'
**
** Created by: The Qt Meta Object Compiler version 67 (Qt 5.6.1)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include "../batchimportcid.h"
#include <QtCore/qbytearray.h>
#include <QtCore/qmetatype.h>
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'batchimportcid.h' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 67
#error "This file was generated using the moc from 5.6.1. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

QT_BEGIN_MOC_NAMESPACE
struct qt_meta_stringdata_BatchImportCID_t {
    QByteArrayData data[6];
    char stringdata0[86];
};
#define QT_MOC_LITERAL(idx, ofs, len) \
    Q_STATIC_BYTE_ARRAY_DATA_HEADER_INITIALIZER_WITH_OFFSET(len, \
    qptrdiff(offsetof(qt_meta_stringdata_BatchImportCID_t, stringdata0) + ofs \
        - idx * sizeof(QByteArrayData)) \
    )
static const qt_meta_stringdata_BatchImportCID_t qt_meta_stringdata_BatchImportCID = {
    {
QT_MOC_LITERAL(0, 0, 14), // "BatchImportCID"
QT_MOC_LITERAL(1, 15, 14), // "Pushbutton_all"
QT_MOC_LITERAL(2, 30, 0), // ""
QT_MOC_LITERAL(3, 31, 16), // "Pushbutton_noall"
QT_MOC_LITERAL(4, 48, 17), // "Pushbutton_import"
QT_MOC_LITERAL(5, 66, 19) // "OnDatadoubleClicked"

    },
    "BatchImportCID\0Pushbutton_all\0\0"
    "Pushbutton_noall\0Pushbutton_import\0"
    "OnDatadoubleClicked"
};
#undef QT_MOC_LITERAL

static const uint qt_meta_data_BatchImportCID[] = {

 // content:
       7,       // revision
       0,       // classname
       0,    0, // classinfo
       4,   14, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       0,       // signalCount

 // slots: name, argc, parameters, tag, flags
       1,    0,   34,    2, 0x08 /* Private */,
       3,    0,   35,    2, 0x08 /* Private */,
       4,    0,   36,    2, 0x08 /* Private */,
       5,    1,   37,    2, 0x08 /* Private */,

 // slots: parameters
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void, QMetaType::QModelIndex,    2,

       0        // eod
};

void BatchImportCID::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::InvokeMetaMethod) {
        BatchImportCID *_t = static_cast<BatchImportCID *>(_o);
        Q_UNUSED(_t)
        switch (_id) {
        case 0: _t->Pushbutton_all(); break;
        case 1: _t->Pushbutton_noall(); break;
        case 2: _t->Pushbutton_import(); break;
        case 3: _t->OnDatadoubleClicked((*reinterpret_cast< const QModelIndex(*)>(_a[1]))); break;
        default: ;
        }
    }
}

const QMetaObject BatchImportCID::staticMetaObject = {
    { &QDialog::staticMetaObject, qt_meta_stringdata_BatchImportCID.data,
      qt_meta_data_BatchImportCID,  qt_static_metacall, Q_NULLPTR, Q_NULLPTR}
};


const QMetaObject *BatchImportCID::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->dynamicMetaObject() : &staticMetaObject;
}

void *BatchImportCID::qt_metacast(const char *_clname)
{
    if (!_clname) return Q_NULLPTR;
    if (!strcmp(_clname, qt_meta_stringdata_BatchImportCID.stringdata0))
        return static_cast<void*>(const_cast< BatchImportCID*>(this));
    return QDialog::qt_metacast(_clname);
}

int BatchImportCID::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = QDialog::qt_metacall(_c, _id, _a);
    if (_id < 0)
        return _id;
    if (_c == QMetaObject::InvokeMetaMethod) {
        if (_id < 4)
            qt_static_metacall(this, _c, _id, _a);
        _id -= 4;
    } else if (_c == QMetaObject::RegisterMethodArgumentMetaType) {
        if (_id < 4)
            *reinterpret_cast<int*>(_a[0]) = -1;
        _id -= 4;
    }
    return _id;
}
QT_END_MOC_NAMESPACE
