/****************************************************************************
** Meta object code from reading C++ file 'vpnagent.h'
**
** Created by: The Qt Meta Object Compiler version 67 (Qt 5.15.2)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include <memory>
#include "../code/vpn_agent/vpnagent.h"
#include <QtCore/qbytearray.h>
#include <QtCore/qmetatype.h>
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'vpnagent.h' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 67
#error "This file was generated using the moc from 5.15.2. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

QT_BEGIN_MOC_NAMESPACE
QT_WARNING_PUSH
QT_WARNING_DISABLE_DEPRECATED
struct qt_meta_stringdata_ConnmanVPNAgent_t {
    QByteArrayData data[9];
    char stringdata0[111];
};
#define QT_MOC_LITERAL(idx, ofs, len) \
    Q_STATIC_BYTE_ARRAY_DATA_HEADER_INITIALIZER_WITH_OFFSET(len, \
    qptrdiff(offsetof(qt_meta_stringdata_ConnmanVPNAgent_t, stringdata0) + ofs \
        - idx * sizeof(QByteArrayData)) \
    )
static const qt_meta_stringdata_ConnmanVPNAgent_t qt_meta_stringdata_ConnmanVPNAgent = {
    {
QT_MOC_LITERAL(0, 0, 15), // "ConnmanVPNAgent"
QT_MOC_LITERAL(1, 16, 15), // "D-Bus Interface"
QT_MOC_LITERAL(2, 32, 21), // "net.connman.vpn.Agent"
QT_MOC_LITERAL(3, 54, 7), // "Release"
QT_MOC_LITERAL(4, 62, 0), // ""
QT_MOC_LITERAL(5, 63, 11), // "ReportError"
QT_MOC_LITERAL(6, 75, 15), // "QDBusObjectPath"
QT_MOC_LITERAL(7, 91, 12), // "RequestInput"
QT_MOC_LITERAL(8, 104, 6) // "Cancel"

    },
    "ConnmanVPNAgent\0D-Bus Interface\0"
    "net.connman.vpn.Agent\0Release\0\0"
    "ReportError\0QDBusObjectPath\0RequestInput\0"
    "Cancel"
};
#undef QT_MOC_LITERAL

static const uint qt_meta_data_ConnmanVPNAgent[] = {

 // content:
       8,       // revision
       0,       // classname
       1,   14, // classinfo
       4,   16, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       0,       // signalCount

 // classinfo: key, value
       1,    2,

 // slots: name, argc, parameters, tag, flags
       3,    0,   36,    4, 0x0a /* Public */,
       5,    2,   37,    4, 0x0a /* Public */,
       7,    2,   42,    4, 0x0a /* Public */,
       8,    0,   47,    4, 0x0a /* Public */,

 // slots: parameters
    QMetaType::Void,
    QMetaType::Void, 0x80000000 | 6, QMetaType::QString,    4,    4,
    QMetaType::QVariantMap, 0x80000000 | 6, QMetaType::QVariantMap,    4,    4,
    QMetaType::Void,

       0        // eod
};

void ConnmanVPNAgent::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::InvokeMetaMethod) {
        auto *_t = static_cast<ConnmanVPNAgent *>(_o);
        (void)_t;
        switch (_id) {
        case 0: _t->Release(); break;
        case 1: _t->ReportError((*reinterpret_cast< QDBusObjectPath(*)>(_a[1])),(*reinterpret_cast< QString(*)>(_a[2]))); break;
        case 2: { QVariantMap _r = _t->RequestInput((*reinterpret_cast< QDBusObjectPath(*)>(_a[1])),(*reinterpret_cast< QMap<QString,QVariant>(*)>(_a[2])));
            if (_a[0]) *reinterpret_cast< QVariantMap*>(_a[0]) = std::move(_r); }  break;
        case 3: _t->Cancel(); break;
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
        }
    }
}

QT_INIT_METAOBJECT const QMetaObject ConnmanVPNAgent::staticMetaObject = { {
    QMetaObject::SuperData::link<QObject::staticMetaObject>(),
    qt_meta_stringdata_ConnmanVPNAgent.data,
    qt_meta_data_ConnmanVPNAgent,
    qt_static_metacall,
    nullptr,
    nullptr
} };


const QMetaObject *ConnmanVPNAgent::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->dynamicMetaObject() : &staticMetaObject;
}

void *ConnmanVPNAgent::qt_metacast(const char *_clname)
{
    if (!_clname) return nullptr;
    if (!strcmp(_clname, qt_meta_stringdata_ConnmanVPNAgent.stringdata0))
        return static_cast<void*>(this);
    if (!strcmp(_clname, "QDBusContext"))
        return static_cast< QDBusContext*>(this);
    return QObject::qt_metacast(_clname);
}

int ConnmanVPNAgent::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = QObject::qt_metacall(_c, _id, _a);
    if (_id < 0)
        return _id;
    if (_c == QMetaObject::InvokeMetaMethod) {
        if (_id < 4)
            qt_static_metacall(this, _c, _id, _a);
        _id -= 4;
    } else if (_c == QMetaObject::RegisterMethodArgumentMetaType) {
        if (_id < 4)
            qt_static_metacall(this, _c, _id, _a);
        _id -= 4;
    }
    return _id;
}
QT_WARNING_POP
QT_END_MOC_NAMESPACE
