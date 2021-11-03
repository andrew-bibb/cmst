/****************************************************************************
** Meta object code from reading C++ file 'counter_interface.h'
**
** Created by: The Qt Meta Object Compiler version 67 (Qt 5.15.2)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include <memory>
#include "../counter_interface.h"
#include <QtCore/qbytearray.h>
#include <QtCore/qmetatype.h>
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'counter_interface.h' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 67
#error "This file was generated using the moc from 5.15.2. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

QT_BEGIN_MOC_NAMESPACE
QT_WARNING_PUSH
QT_WARNING_DISABLE_DEPRECATED
struct qt_meta_stringdata_NetConnmanCounterInterface_t {
    QByteArrayData data[9];
    char stringdata0[90];
};
#define QT_MOC_LITERAL(idx, ofs, len) \
    Q_STATIC_BYTE_ARRAY_DATA_HEADER_INITIALIZER_WITH_OFFSET(len, \
    qptrdiff(offsetof(qt_meta_stringdata_NetConnmanCounterInterface_t, stringdata0) + ofs \
        - idx * sizeof(QByteArrayData)) \
    )
static const qt_meta_stringdata_NetConnmanCounterInterface_t qt_meta_stringdata_NetConnmanCounterInterface = {
    {
QT_MOC_LITERAL(0, 0, 26), // "NetConnmanCounterInterface"
QT_MOC_LITERAL(1, 27, 7), // "Release"
QT_MOC_LITERAL(2, 35, 19), // "QDBusPendingReply<>"
QT_MOC_LITERAL(3, 55, 0), // ""
QT_MOC_LITERAL(4, 56, 5), // "Usage"
QT_MOC_LITERAL(5, 62, 15), // "QDBusObjectPath"
QT_MOC_LITERAL(6, 78, 3), // "in0"
QT_MOC_LITERAL(7, 82, 3), // "in1"
QT_MOC_LITERAL(8, 86, 3) // "in2"

    },
    "NetConnmanCounterInterface\0Release\0"
    "QDBusPendingReply<>\0\0Usage\0QDBusObjectPath\0"
    "in0\0in1\0in2"
};
#undef QT_MOC_LITERAL

static const uint qt_meta_data_NetConnmanCounterInterface[] = {

 // content:
       8,       // revision
       0,       // classname
       0,    0, // classinfo
       2,   14, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       0,       // signalCount

 // slots: name, argc, parameters, tag, flags
       1,    0,   24,    3, 0x0a /* Public */,
       4,    3,   25,    3, 0x0a /* Public */,

 // slots: parameters
    0x80000000 | 2,
    0x80000000 | 2, 0x80000000 | 5, QMetaType::QVariantMap, QMetaType::QVariantMap,    6,    7,    8,

       0        // eod
};

void NetConnmanCounterInterface::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::InvokeMetaMethod) {
        auto *_t = static_cast<NetConnmanCounterInterface *>(_o);
        (void)_t;
        switch (_id) {
        case 0: { QDBusPendingReply<> _r = _t->Release();
            if (_a[0]) *reinterpret_cast< QDBusPendingReply<>*>(_a[0]) = std::move(_r); }  break;
        case 1: { QDBusPendingReply<> _r = _t->Usage((*reinterpret_cast< const QDBusObjectPath(*)>(_a[1])),(*reinterpret_cast< const QVariantMap(*)>(_a[2])),(*reinterpret_cast< const QVariantMap(*)>(_a[3])));
            if (_a[0]) *reinterpret_cast< QDBusPendingReply<>*>(_a[0]) = std::move(_r); }  break;
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
        }
    }
}

QT_INIT_METAOBJECT const QMetaObject NetConnmanCounterInterface::staticMetaObject = { {
    QMetaObject::SuperData::link<QDBusAbstractInterface::staticMetaObject>(),
    qt_meta_stringdata_NetConnmanCounterInterface.data,
    qt_meta_data_NetConnmanCounterInterface,
    qt_static_metacall,
    nullptr,
    nullptr
} };


const QMetaObject *NetConnmanCounterInterface::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->dynamicMetaObject() : &staticMetaObject;
}

void *NetConnmanCounterInterface::qt_metacast(const char *_clname)
{
    if (!_clname) return nullptr;
    if (!strcmp(_clname, qt_meta_stringdata_NetConnmanCounterInterface.stringdata0))
        return static_cast<void*>(this);
    return QDBusAbstractInterface::qt_metacast(_clname);
}

int NetConnmanCounterInterface::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = QDBusAbstractInterface::qt_metacall(_c, _id, _a);
    if (_id < 0)
        return _id;
    if (_c == QMetaObject::InvokeMetaMethod) {
        if (_id < 2)
            qt_static_metacall(this, _c, _id, _a);
        _id -= 2;
    } else if (_c == QMetaObject::RegisterMethodArgumentMetaType) {
        if (_id < 2)
            qt_static_metacall(this, _c, _id, _a);
        _id -= 2;
    }
    return _id;
}
QT_WARNING_POP
QT_END_MOC_NAMESPACE
