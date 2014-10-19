/****************************************************************************
** Meta object code from reading C++ file 'notify.h'
**
** Created by: The Qt Meta Object Compiler version 67 (Qt 5.3.2)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include "../notify/notify.h"
#include <QtCore/qbytearray.h>
#include <QtCore/qmetatype.h>
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'notify.h' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 67
#error "This file was generated using the moc from 5.3.2. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

QT_BEGIN_MOC_NAMESPACE
struct qt_meta_stringdata_NotifyClient_t {
    QByteArrayData data[6];
    char stringdata[93];
};
#define QT_MOC_LITERAL(idx, ofs, len) \
    Q_STATIC_BYTE_ARRAY_DATA_HEADER_INITIALIZER_WITH_OFFSET(len, \
    qptrdiff(offsetof(qt_meta_stringdata_NotifyClient_t, stringdata) + ofs \
        - idx * sizeof(QByteArrayData)) \
    )
static const qt_meta_stringdata_NotifyClient_t qt_meta_stringdata_NotifyClient = {
    {
QT_MOC_LITERAL(0, 0, 12),
QT_MOC_LITERAL(1, 13, 15),
QT_MOC_LITERAL(2, 29, 29),
QT_MOC_LITERAL(3, 59, 18),
QT_MOC_LITERAL(4, 78, 0),
QT_MOC_LITERAL(5, 79, 13)
    },
    "NotifyClient\0D-Bus Interface\0"
    "org.freedesktop.Notifications\0"
    "notificationClosed\0\0actionInvoked"
};
#undef QT_MOC_LITERAL

static const uint qt_meta_data_NotifyClient[] = {

 // content:
       7,       // revision
       0,       // classname
       1,   14, // classinfo
       2,   16, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       0,       // signalCount

 // classinfo: key, value
       1,    2,

 // slots: name, argc, parameters, tag, flags
       3,    2,   26,    4, 0x08 /* Private */,
       5,    2,   31,    4, 0x08 /* Private */,

 // slots: parameters
    QMetaType::Void, QMetaType::UInt, QMetaType::UInt,    4,    4,
    QMetaType::Void, QMetaType::UInt, QMetaType::QString,    4,    4,

       0        // eod
};

void NotifyClient::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::InvokeMetaMethod) {
        NotifyClient *_t = static_cast<NotifyClient *>(_o);
        switch (_id) {
        case 0: _t->notificationClosed((*reinterpret_cast< quint32(*)>(_a[1])),(*reinterpret_cast< quint32(*)>(_a[2]))); break;
        case 1: _t->actionInvoked((*reinterpret_cast< quint32(*)>(_a[1])),(*reinterpret_cast< QString(*)>(_a[2]))); break;
        default: ;
        }
    }
}

const QMetaObject NotifyClient::staticMetaObject = {
    { &QObject::staticMetaObject, qt_meta_stringdata_NotifyClient.data,
      qt_meta_data_NotifyClient,  qt_static_metacall, 0, 0}
};


const QMetaObject *NotifyClient::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->dynamicMetaObject() : &staticMetaObject;
}

void *NotifyClient::qt_metacast(const char *_clname)
{
    if (!_clname) return 0;
    if (!strcmp(_clname, qt_meta_stringdata_NotifyClient.stringdata))
        return static_cast<void*>(const_cast< NotifyClient*>(this));
    return QObject::qt_metacast(_clname);
}

int NotifyClient::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = QObject::qt_metacall(_c, _id, _a);
    if (_id < 0)
        return _id;
    if (_c == QMetaObject::InvokeMetaMethod) {
        if (_id < 2)
            qt_static_metacall(this, _c, _id, _a);
        _id -= 2;
    } else if (_c == QMetaObject::RegisterMethodArgumentMetaType) {
        if (_id < 2)
            *reinterpret_cast<int*>(_a[0]) = -1;
        _id -= 2;
    }
    return _id;
}
QT_END_MOC_NAMESPACE
