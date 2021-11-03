/****************************************************************************
** Meta object code from reading C++ file 'vpnagent_interface.h'
**
** Created by: The Qt Meta Object Compiler version 67 (Qt 5.15.2)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include <memory>
#include "../code/vpn_agent/vpnagent_interface.h"
#include <QtCore/qbytearray.h>
#include <QtCore/qmetatype.h>
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'vpnagent_interface.h' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 67
#error "This file was generated using the moc from 5.15.2. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

QT_BEGIN_MOC_NAMESPACE
QT_WARNING_PUSH
QT_WARNING_DISABLE_DEPRECATED
struct qt_meta_stringdata_NetConnmanVpnAgentInterface_t {
    QByteArrayData data[11];
    char stringdata0[144];
};
#define QT_MOC_LITERAL(idx, ofs, len) \
    Q_STATIC_BYTE_ARRAY_DATA_HEADER_INITIALIZER_WITH_OFFSET(len, \
    qptrdiff(offsetof(qt_meta_stringdata_NetConnmanVpnAgentInterface_t, stringdata0) + ofs \
        - idx * sizeof(QByteArrayData)) \
    )
static const qt_meta_stringdata_NetConnmanVpnAgentInterface_t qt_meta_stringdata_NetConnmanVpnAgentInterface = {
    {
QT_MOC_LITERAL(0, 0, 27), // "NetConnmanVpnAgentInterface"
QT_MOC_LITERAL(1, 28, 6), // "Cancel"
QT_MOC_LITERAL(2, 35, 19), // "QDBusPendingReply<>"
QT_MOC_LITERAL(3, 55, 0), // ""
QT_MOC_LITERAL(4, 56, 7), // "Release"
QT_MOC_LITERAL(5, 64, 11), // "ReportError"
QT_MOC_LITERAL(6, 76, 15), // "QDBusObjectPath"
QT_MOC_LITERAL(7, 92, 3), // "in0"
QT_MOC_LITERAL(8, 96, 3), // "in1"
QT_MOC_LITERAL(9, 100, 12), // "RequestInput"
QT_MOC_LITERAL(10, 113, 30) // "QDBusPendingReply<QVariantMap>"

    },
    "NetConnmanVpnAgentInterface\0Cancel\0"
    "QDBusPendingReply<>\0\0Release\0ReportError\0"
    "QDBusObjectPath\0in0\0in1\0RequestInput\0"
    "QDBusPendingReply<QVariantMap>"
};
#undef QT_MOC_LITERAL

static const uint qt_meta_data_NetConnmanVpnAgentInterface[] = {

 // content:
       8,       // revision
       0,       // classname
       0,    0, // classinfo
       4,   14, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       0,       // signalCount

 // slots: name, argc, parameters, tag, flags
       1,    0,   34,    3, 0x0a /* Public */,
       4,    0,   35,    3, 0x0a /* Public */,
       5,    2,   36,    3, 0x0a /* Public */,
       9,    2,   41,    3, 0x0a /* Public */,

 // slots: parameters
    0x80000000 | 2,
    0x80000000 | 2,
    0x80000000 | 2, 0x80000000 | 6, QMetaType::QString,    7,    8,
    0x80000000 | 10, 0x80000000 | 6, QMetaType::QVariantMap,    7,    8,

       0        // eod
};

void NetConnmanVpnAgentInterface::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::InvokeMetaMethod) {
        auto *_t = static_cast<NetConnmanVpnAgentInterface *>(_o);
        (void)_t;
        switch (_id) {
        case 0: { QDBusPendingReply<> _r = _t->Cancel();
            if (_a[0]) *reinterpret_cast< QDBusPendingReply<>*>(_a[0]) = std::move(_r); }  break;
        case 1: { QDBusPendingReply<> _r = _t->Release();
            if (_a[0]) *reinterpret_cast< QDBusPendingReply<>*>(_a[0]) = std::move(_r); }  break;
        case 2: { QDBusPendingReply<> _r = _t->ReportError((*reinterpret_cast< const QDBusObjectPath(*)>(_a[1])),(*reinterpret_cast< const QString(*)>(_a[2])));
            if (_a[0]) *reinterpret_cast< QDBusPendingReply<>*>(_a[0]) = std::move(_r); }  break;
        case 3: { QDBusPendingReply<QVariantMap> _r = _t->RequestInput((*reinterpret_cast< const QDBusObjectPath(*)>(_a[1])),(*reinterpret_cast< const QVariantMap(*)>(_a[2])));
            if (_a[0]) *reinterpret_cast< QDBusPendingReply<QVariantMap>*>(_a[0]) = std::move(_r); }  break;
        default: ;
        }
    } else if (_c == QMetaObject::RegisterMethodArgumentMetaType) {
        switch (_id) {
        default: *reinterpret_cast<int*>(_a[0]) = -1; break;
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

QT_INIT_METAOBJECT const QMetaObject NetConnmanVpnAgentInterface::staticMetaObject = { {
    QMetaObject::SuperData::link<QDBusAbstractInterface::staticMetaObject>(),
    qt_meta_stringdata_NetConnmanVpnAgentInterface.data,
    qt_meta_data_NetConnmanVpnAgentInterface,
    qt_static_metacall,
    nullptr,
    nullptr
} };


const QMetaObject *NetConnmanVpnAgentInterface::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->dynamicMetaObject() : &staticMetaObject;
}

void *NetConnmanVpnAgentInterface::qt_metacast(const char *_clname)
{
    if (!_clname) return nullptr;
    if (!strcmp(_clname, qt_meta_stringdata_NetConnmanVpnAgentInterface.stringdata0))
        return static_cast<void*>(this);
    return QDBusAbstractInterface::qt_metacast(_clname);
}

int NetConnmanVpnAgentInterface::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = QDBusAbstractInterface::qt_metacall(_c, _id, _a);
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
