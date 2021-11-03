/****************************************************************************
** Meta object code from reading C++ file 'notify.h'
**
** Created by: The Qt Meta Object Compiler version 67 (Qt 5.15.2)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include <memory>
#include "../code/notify/notify.h"
#include <QtCore/qbytearray.h>
#include <QtCore/qmetatype.h>
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'notify.h' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 67
#error "This file was generated using the moc from 5.15.2. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

QT_BEGIN_MOC_NAMESPACE
QT_WARNING_PUSH
QT_WARNING_DISABLE_DEPRECATED
struct qt_meta_stringdata_NotifyClient_t {
    QByteArrayData data[7];
    char stringdata0[101];
};
#define QT_MOC_LITERAL(idx, ofs, len) \
    Q_STATIC_BYTE_ARRAY_DATA_HEADER_INITIALIZER_WITH_OFFSET(len, \
    qptrdiff(offsetof(qt_meta_stringdata_NotifyClient_t, stringdata0) + ofs \
        - idx * sizeof(QByteArrayData)) \
    )
static const qt_meta_stringdata_NotifyClient_t qt_meta_stringdata_NotifyClient = {
    {
QT_MOC_LITERAL(0, 0, 12), // "NotifyClient"
QT_MOC_LITERAL(1, 13, 15), // "D-Bus Interface"
QT_MOC_LITERAL(2, 29, 29), // "org.freedesktop.Notifications"
QT_MOC_LITERAL(3, 59, 18), // "notificationClosed"
QT_MOC_LITERAL(4, 78, 0), // ""
QT_MOC_LITERAL(5, 79, 13), // "actionInvoked"
QT_MOC_LITERAL(6, 93, 7) // "cleanUp"

    },
    "NotifyClient\0D-Bus Interface\0"
    "org.freedesktop.Notifications\0"
    "notificationClosed\0\0actionInvoked\0"
    "cleanUp"
};
#undef QT_MOC_LITERAL

static const uint qt_meta_data_NotifyClient[] = {

 // content:
       8,       // revision
       0,       // classname
       1,   14, // classinfo
       3,   16, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       0,       // signalCount

 // classinfo: key, value
       1,    2,

 // slots: name, argc, parameters, tag, flags
       3,    2,   31,    4, 0x08 /* Private */,
       5,    2,   36,    4, 0x08 /* Private */,
       6,    0,   41,    4, 0x08 /* Private */,

 // slots: parameters
    QMetaType::Void, QMetaType::UInt, QMetaType::UInt,    4,    4,
    QMetaType::Void, QMetaType::UInt, QMetaType::QString,    4,    4,
    QMetaType::Void,

       0        // eod
};

void NotifyClient::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::InvokeMetaMethod) {
        auto *_t = static_cast<NotifyClient *>(_o);
        (void)_t;
        switch (_id) {
        case 0: _t->notificationClosed((*reinterpret_cast< quint32(*)>(_a[1])),(*reinterpret_cast< quint32(*)>(_a[2]))); break;
        case 1: _t->actionInvoked((*reinterpret_cast< quint32(*)>(_a[1])),(*reinterpret_cast< QString(*)>(_a[2]))); break;
        case 2: _t->cleanUp(); break;
        default: ;
        }
    }
}

QT_INIT_METAOBJECT const QMetaObject NotifyClient::staticMetaObject = { {
    QMetaObject::SuperData::link<QObject::staticMetaObject>(),
    qt_meta_stringdata_NotifyClient.data,
    qt_meta_data_NotifyClient,
    qt_static_metacall,
    nullptr,
    nullptr
} };


const QMetaObject *NotifyClient::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->dynamicMetaObject() : &staticMetaObject;
}

void *NotifyClient::qt_metacast(const char *_clname)
{
    if (!_clname) return nullptr;
    if (!strcmp(_clname, qt_meta_stringdata_NotifyClient.stringdata0))
        return static_cast<void*>(this);
    return QObject::qt_metacast(_clname);
}

int NotifyClient::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = QObject::qt_metacall(_c, _id, _a);
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
QT_WARNING_POP
QT_END_MOC_NAMESPACE
