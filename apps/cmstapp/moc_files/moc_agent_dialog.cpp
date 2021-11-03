/****************************************************************************
** Meta object code from reading C++ file 'agent_dialog.h'
**
** Created by: The Qt Meta Object Compiler version 67 (Qt 5.15.2)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include <memory>
#include "../code/agent/agent_dialog.h"
#include <QtCore/qbytearray.h>
#include <QtCore/qmetatype.h>
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'agent_dialog.h' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 67
#error "This file was generated using the moc from 5.15.2. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

QT_BEGIN_MOC_NAMESPACE
QT_WARNING_PUSH
QT_WARNING_DISABLE_DEPRECATED
struct qt_meta_stringdata_AgentDialog_t {
    QByteArrayData data[9];
    char stringdata0[121];
};
#define QT_MOC_LITERAL(idx, ofs, len) \
    Q_STATIC_BYTE_ARRAY_DATA_HEADER_INITIALIZER_WITH_OFFSET(len, \
    qptrdiff(offsetof(qt_meta_stringdata_AgentDialog_t, stringdata0) + ofs \
        - idx * sizeof(QByteArrayData)) \
    )
static const qt_meta_stringdata_AgentDialog_t qt_meta_stringdata_AgentDialog = {
    {
QT_MOC_LITERAL(0, 0, 11), // "AgentDialog"
QT_MOC_LITERAL(1, 12, 14), // "hidePassphrase"
QT_MOC_LITERAL(2, 27, 0), // ""
QT_MOC_LITERAL(3, 28, 16), // "useWPSPushButton"
QT_MOC_LITERAL(4, 45, 13), // "showWhatsThis"
QT_MOC_LITERAL(5, 59, 19), // "updateBrowserChoice"
QT_MOC_LITERAL(6, 79, 11), // "QModelIndex"
QT_MOC_LITERAL(7, 91, 15), // "enteringBrowser"
QT_MOC_LITERAL(8, 107, 13) // "launchBrowser"

    },
    "AgentDialog\0hidePassphrase\0\0"
    "useWPSPushButton\0showWhatsThis\0"
    "updateBrowserChoice\0QModelIndex\0"
    "enteringBrowser\0launchBrowser"
};
#undef QT_MOC_LITERAL

static const uint qt_meta_data_AgentDialog[] = {

 // content:
       8,       // revision
       0,       // classname
       0,    0, // classinfo
       6,   14, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       0,       // signalCount

 // slots: name, argc, parameters, tag, flags
       1,    1,   44,    2, 0x08 /* Private */,
       3,    1,   47,    2, 0x08 /* Private */,
       4,    0,   50,    2, 0x08 /* Private */,
       5,    2,   51,    2, 0x08 /* Private */,
       7,    0,   56,    2, 0x08 /* Private */,
       8,    0,   57,    2, 0x08 /* Private */,

 // slots: parameters
    QMetaType::Void, QMetaType::Bool,    2,
    QMetaType::Void, QMetaType::Bool,    2,
    QMetaType::Void,
    QMetaType::Void, 0x80000000 | 6, 0x80000000 | 6,    2,    2,
    QMetaType::Void,
    QMetaType::Void,

       0        // eod
};

void AgentDialog::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::InvokeMetaMethod) {
        auto *_t = static_cast<AgentDialog *>(_o);
        (void)_t;
        switch (_id) {
        case 0: _t->hidePassphrase((*reinterpret_cast< bool(*)>(_a[1]))); break;
        case 1: _t->useWPSPushButton((*reinterpret_cast< bool(*)>(_a[1]))); break;
        case 2: _t->showWhatsThis(); break;
        case 3: _t->updateBrowserChoice((*reinterpret_cast< const QModelIndex(*)>(_a[1])),(*reinterpret_cast< const QModelIndex(*)>(_a[2]))); break;
        case 4: _t->enteringBrowser(); break;
        case 5: _t->launchBrowser(); break;
        default: ;
        }
    }
}

QT_INIT_METAOBJECT const QMetaObject AgentDialog::staticMetaObject = { {
    QMetaObject::SuperData::link<QDialog::staticMetaObject>(),
    qt_meta_stringdata_AgentDialog.data,
    qt_meta_data_AgentDialog,
    qt_static_metacall,
    nullptr,
    nullptr
} };


const QMetaObject *AgentDialog::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->dynamicMetaObject() : &staticMetaObject;
}

void *AgentDialog::qt_metacast(const char *_clname)
{
    if (!_clname) return nullptr;
    if (!strcmp(_clname, qt_meta_stringdata_AgentDialog.stringdata0))
        return static_cast<void*>(this);
    return QDialog::qt_metacast(_clname);
}

int AgentDialog::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = QDialog::qt_metacall(_c, _id, _a);
    if (_id < 0)
        return _id;
    if (_c == QMetaObject::InvokeMetaMethod) {
        if (_id < 6)
            qt_static_metacall(this, _c, _id, _a);
        _id -= 6;
    } else if (_c == QMetaObject::RegisterMethodArgumentMetaType) {
        if (_id < 6)
            *reinterpret_cast<int*>(_a[0]) = -1;
        _id -= 6;
    }
    return _id;
}
QT_WARNING_POP
QT_END_MOC_NAMESPACE
