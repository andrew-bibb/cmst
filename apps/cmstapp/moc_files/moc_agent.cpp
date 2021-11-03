/****************************************************************************
** Meta object code from reading C++ file 'agent.h'
**
** Created by: The Qt Meta Object Compiler version 67 (Qt 5.15.2)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include <memory>
#include "../code/agent/agent.h"
#include <QtCore/qbytearray.h>
#include <QtCore/qmetatype.h>
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'agent.h' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 67
#error "This file was generated using the moc from 5.15.2. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

QT_BEGIN_MOC_NAMESPACE
QT_WARNING_PUSH
QT_WARNING_DISABLE_DEPRECATED
struct qt_meta_stringdata_ConnmanAgent_t {
    QByteArrayData data[10];
    char stringdata0[119];
};
#define QT_MOC_LITERAL(idx, ofs, len) \
    Q_STATIC_BYTE_ARRAY_DATA_HEADER_INITIALIZER_WITH_OFFSET(len, \
    qptrdiff(offsetof(qt_meta_stringdata_ConnmanAgent_t, stringdata0) + ofs \
        - idx * sizeof(QByteArrayData)) \
    )
static const qt_meta_stringdata_ConnmanAgent_t qt_meta_stringdata_ConnmanAgent = {
    {
QT_MOC_LITERAL(0, 0, 12), // "ConnmanAgent"
QT_MOC_LITERAL(1, 13, 15), // "D-Bus Interface"
QT_MOC_LITERAL(2, 29, 17), // "net.connman.Agent"
QT_MOC_LITERAL(3, 47, 7), // "Release"
QT_MOC_LITERAL(4, 55, 0), // ""
QT_MOC_LITERAL(5, 56, 11), // "ReportError"
QT_MOC_LITERAL(6, 68, 15), // "QDBusObjectPath"
QT_MOC_LITERAL(7, 84, 14), // "RequestBrowser"
QT_MOC_LITERAL(8, 99, 12), // "RequestInput"
QT_MOC_LITERAL(9, 112, 6) // "Cancel"

    },
    "ConnmanAgent\0D-Bus Interface\0"
    "net.connman.Agent\0Release\0\0ReportError\0"
    "QDBusObjectPath\0RequestBrowser\0"
    "RequestInput\0Cancel"
};
#undef QT_MOC_LITERAL

static const uint qt_meta_data_ConnmanAgent[] = {

 // content:
       8,       // revision
       0,       // classname
       1,   14, // classinfo
       5,   16, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       0,       // signalCount

 // classinfo: key, value
       1,    2,

 // slots: name, argc, parameters, tag, flags
       3,    0,   41,    4, 0x0a /* Public */,
       5,    2,   42,    4, 0x0a /* Public */,
       7,    2,   47,    4, 0x0a /* Public */,
       8,    2,   52,    4, 0x0a /* Public */,
       9,    0,   57,    4, 0x0a /* Public */,

 // slots: parameters
    QMetaType::Void,
    QMetaType::Void, 0x80000000 | 6, QMetaType::QString,    4,    4,
    QMetaType::Void, 0x80000000 | 6, QMetaType::QString,    4,    4,
    QMetaType::QVariantMap, 0x80000000 | 6, QMetaType::QVariantMap,    4,    4,
    QMetaType::Void,

       0        // eod
};

void ConnmanAgent::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::InvokeMetaMethod) {
        auto *_t = static_cast<ConnmanAgent *>(_o);
        (void)_t;
        switch (_id) {
        case 0: _t->Release(); break;
        case 1: _t->ReportError((*reinterpret_cast< QDBusObjectPath(*)>(_a[1])),(*reinterpret_cast< QString(*)>(_a[2]))); break;
        case 2: _t->RequestBrowser((*reinterpret_cast< QDBusObjectPath(*)>(_a[1])),(*reinterpret_cast< QString(*)>(_a[2]))); break;
        case 3: { QVariantMap _r = _t->RequestInput((*reinterpret_cast< QDBusObjectPath(*)>(_a[1])),(*reinterpret_cast< QMap<QString,QVariant>(*)>(_a[2])));
            if (_a[0]) *reinterpret_cast< QVariantMap*>(_a[0]) = std::move(_r); }  break;
        case 4: _t->Cancel(); break;
        default: ;
        }
    } else if (_c == QMetaObject::RegisterMethodArgumentMetaType) {
        switch (_id) {
        default: *reinterpret_cast<int*>(_a[0]) = -1; break;
        case 1:
            switch (*reinterpret_cast<int*>(_a[1])) {
            default: *reinterpret_cast<int*>(_a[0]) = -1; break;
            case 0:
                *reinterpret_cast<int*>(_a[0]) = qRegisterMetaType< QDBusObjectPath >(); break;
            }
            break;
        case 2:
            switch (*reinterpret_cast<int*>(_a[1])) {
            default: *reinterpret_cast<int*>(_a[0]) = -1; break;
            case 0:
                *reinterpret_cast<int*>(_a[0]) = qRegisterMetaType< QDBusObjectPath >(); break;
            }
            break;
        case 3:
            switch (*reinterpret_cast<int*>(_a[1])) {
            default: *reinterpret_cast<int*>(_a[0]) = -1; break;
            case 0:
                *reinterpret_cast<int*>(_a[0]) = qRegisterMetaType< QDBusObjectPath >(); break;
            }
            break;
        }
    }
}

QT_INIT_METAOBJECT const QMetaObject ConnmanAgent::staticMetaObject = { {
    QMetaObject::SuperData::link<QObject::staticMetaObject>(),
    qt_meta_stringdata_ConnmanAgent.data,
    qt_meta_data_ConnmanAgent,
    qt_static_metacall,
    nullptr,
    nullptr
} };


const QMetaObject *ConnmanAgent::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->dynamicMetaObject() : &staticMetaObject;
}

void *ConnmanAgent::qt_metacast(const char *_clname)
{
    if (!_clname) return nullptr;
    if (!strcmp(_clname, qt_meta_stringdata_ConnmanAgent.stringdata0))
        return static_cast<void*>(this);
    if (!strcmp(_clname, "QDBusContext"))
        return static_cast< QDBusContext*>(this);
    return QObject::qt_metacast(_clname);
}

int ConnmanAgent::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = QObject::qt_metacall(_c, _id, _a);
    if (_id < 0)
        return _id;
    if (_c == QMetaObject::InvokeMetaMethod) {
        if (_id < 5)
            qt_static_metacall(this, _c, _id, _a);
        _id -= 5;
    } else if (_c == QMetaObject::RegisterMethodArgumentMetaType) {
        if (_id < 5)
            qt_static_metacall(this, _c, _id, _a);
        _id -= 5;
    }
    return _id;
}
QT_WARNING_POP
QT_END_MOC_NAMESPACE
