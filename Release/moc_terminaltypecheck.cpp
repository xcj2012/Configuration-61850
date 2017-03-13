/****************************************************************************
** Meta object code from reading C++ file 'terminaltypecheck.h'
**
** Created by: The Qt Meta Object Compiler version 67 (Qt 5.6.1)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include "../terminaltypecheck.h"
#include <QtCore/qbytearray.h>
#include <QtCore/qmetatype.h>
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'terminaltypecheck.h' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 67
#error "This file was generated using the moc from 5.6.1. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

QT_BEGIN_MOC_NAMESPACE
struct qt_meta_stringdata_TerminalTypeCheck_t {
    QByteArrayData data[5];
    char stringdata0[68];
};
#define QT_MOC_LITERAL(idx, ofs, len) \
    Q_STATIC_BYTE_ARRAY_DATA_HEADER_INITIALIZER_WITH_OFFSET(len, \
    qptrdiff(offsetof(qt_meta_stringdata_TerminalTypeCheck_t, stringdata0) + ofs \
        - idx * sizeof(QByteArrayData)) \
    )
static const qt_meta_stringdata_TerminalTypeCheck_t qt_meta_stringdata_TerminalTypeCheck = {
    {
QT_MOC_LITERAL(0, 0, 17), // "TerminalTypeCheck"
QT_MOC_LITERAL(1, 18, 14), // "Pushbutton_all"
QT_MOC_LITERAL(2, 33, 0), // ""
QT_MOC_LITERAL(3, 34, 16), // "Pushbutton_noall"
QT_MOC_LITERAL(4, 51, 16) // "Pushbutton_check"

    },
    "TerminalTypeCheck\0Pushbutton_all\0\0"
    "Pushbutton_noall\0Pushbutton_check"
};
#undef QT_MOC_LITERAL

static const uint qt_meta_data_TerminalTypeCheck[] = {

 // content:
       7,       // revision
       0,       // classname
       0,    0, // classinfo
       3,   14, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       0,       // signalCount

 // slots: name, argc, parameters, tag, flags
       1,    0,   29,    2, 0x08 /* Private */,
       3,    0,   30,    2, 0x08 /* Private */,
       4,    0,   31,    2, 0x08 /* Private */,

 // slots: parameters
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,

       0        // eod
};

void TerminalTypeCheck::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::InvokeMetaMethod) {
        TerminalTypeCheck *_t = static_cast<TerminalTypeCheck *>(_o);
        Q_UNUSED(_t)
        switch (_id) {
        case 0: _t->Pushbutton_all(); break;
        case 1: _t->Pushbutton_noall(); break;
        case 2: _t->Pushbutton_check(); break;
        default: ;
        }
    }
    Q_UNUSED(_a);
}

const QMetaObject TerminalTypeCheck::staticMetaObject = {
    { &QDialog::staticMetaObject, qt_meta_stringdata_TerminalTypeCheck.data,
      qt_meta_data_TerminalTypeCheck,  qt_static_metacall, Q_NULLPTR, Q_NULLPTR}
};


const QMetaObject *TerminalTypeCheck::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->dynamicMetaObject() : &staticMetaObject;
}

void *TerminalTypeCheck::qt_metacast(const char *_clname)
{
    if (!_clname) return Q_NULLPTR;
    if (!strcmp(_clname, qt_meta_stringdata_TerminalTypeCheck.stringdata0))
        return static_cast<void*>(const_cast< TerminalTypeCheck*>(this));
    return QDialog::qt_metacast(_clname);
}

int TerminalTypeCheck::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = QDialog::qt_metacall(_c, _id, _a);
    if (_id < 0)
        return _id;
    if (_c == QMetaObject::InvokeMetaMethod) {
        if (_id < 3)
            qt_static_metacall(this, _c, _id, _a);
        _id -= 3;
    } else if (_c == QMetaObject::RegisterMethodArgumentMetaType) {
        if (_id < 3)
            *reinterpret_cast<int*>(_a[0]) = -1;
        _id -= 3;
    }
    return _id;
}
QT_END_MOC_NAMESPACE
