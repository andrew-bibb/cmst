/****************************************************************************
** Meta object code from reading C++ file 'agent_dialog.h'
**
** Created by: The Qt Meta Object Compiler version 67 (Qt 5.3.2)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include "../agent/agent_dialog.h"
#include <QtCore/qbytearray.h>
#include <QtCore/qmetatype.h>
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'agent_dialog.h' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 67
#error "This file was generated using the moc from 5.3.2. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

QT_BEGIN_MOC_NAMESPACE
struct qt_meta_stringdata_AgentDialog_t {
    QByteArrayData data[7];
    char stringdata[89];
};
#define QT_MOC_LITERAL(idx, ofs, len) \
    Q_STATIC_BYTE_ARRAY_DATA_HEADER_INITIALIZER_WITH_OFFSET(len, \
    qptrdiff(offsetof(qt_meta_stringdata_AgentDialog_t, stringdata) + ofs \
        - idx * sizeof(QByteArrayData)) \
    )
static const qt_meta_stringdata_AgentDialog_t qt_meta_stringdata_AgentDialog = {
    {
QT_MOC_LITERAL(0, 0, 11),
QT_MOC_LITERAL(1, 12, 14),
QT_MOC_LITERAL(2, 27, 0),
QT_MOC_LITERAL(3, 28, 16),
QT_MOC_LITERAL(4, 45, 13),
QT_MOC_LITERAL(5, 59, 15),
QT_MOC_LITERAL(6, 75, 13)
    },
    "AgentDialog\0hidePassphrase\0\0"
    "useWPSPushButton\0showWhatsThis\0"
    "useOtherBrowser\0launchBrowser"
};
#undef QT_MOC_LITERAL

static const uint qt_meta_data_AgentDialog[] = {

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
       1,    1,   39,    2, 0x08 /* Private */,
       3,    1,   42,    2, 0x08 /* Private */,
       4,    0,   45,    2, 0x08 /* Private */,
       5,    1,   46,    2, 0x08 /* Private */,
       6,    0,   49,    2, 0x08 /* Private */,

 // slots: parameters
    QMetaType::Void, QMetaType::Bool,    2,
    QMetaType::Void, QMetaType::Bool,    2,
    QMetaType::Void,
    QMetaType::Void, QMetaType::Bool,    2,
    QMetaType::Void,

       0        // eod
};

void AgentDialog::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::InvokeMetaMethod) {
        AgentDialog *_t = static_cast<AgentDialog *>(_o);
        switch (_id) {
        case 0: _t->hidePassphrase((*reinterpret_cast< bool(*)>(_a[1]))); break;
        case 1: _t->useWPSPushButton((*reinterpret_cast< bool(*)>(_a[1]))); break;
        case 2: _t->showWhatsThis(); break;
        case 3: _t->useOtherBrowser((*reinterpret_cast< bool(*)>(_a[1]))); break;
        case 4: _t->launchBrowser(); break;
        default: ;
        }
    }
}

const QMetaObject AgentDialog::staticMetaObject = {
    { &QDialog::staticMetaObject, qt_meta_stringdata_AgentDialog.data,
      qt_meta_data_AgentDialog,  qt_static_metacall, 0, 0}
};


const QMetaObject *AgentDialog::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->dynamicMetaObject() : &staticMetaObject;
}

void *AgentDialog::qt_metacast(const char *_clname)
{
    if (!_clname) return 0;
    if (!strcmp(_clname, qt_meta_stringdata_AgentDialog.stringdata))
        return static_cast<void*>(const_cast< AgentDialog*>(this));
    return QDialog::qt_metacast(_clname);
}

int AgentDialog::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
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
