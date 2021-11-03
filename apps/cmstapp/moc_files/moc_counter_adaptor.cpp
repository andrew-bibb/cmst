/****************************************************************************
** Meta object code from reading C++ file 'counter_adaptor.h'
**
** Created by: The Qt Meta Object Compiler version 67 (Qt 5.15.2)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include <memory>
#include "../counter_adaptor.h"
#include <QtCore/qbytearray.h>
#include <QtCore/qmetatype.h>
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'counter_adaptor.h' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 67
#error "This file was generated using the moc from 5.15.2. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

QT_BEGIN_MOC_NAMESPACE
QT_WARNING_PUSH
QT_WARNING_DISABLE_DEPRECATED
struct qt_meta_stringdata_CounterAdaptor_t {
    QByteArrayData data[12];
    char stringdata0[561];
};
#define QT_MOC_LITERAL(idx, ofs, len) \
    Q_STATIC_BYTE_ARRAY_DATA_HEADER_INITIALIZER_WITH_OFFSET(len, \
    qptrdiff(offsetof(qt_meta_stringdata_CounterAdaptor_t, stringdata0) + ofs \
        - idx * sizeof(QByteArrayData)) \
    )
static const qt_meta_stringdata_CounterAdaptor_t qt_meta_stringdata_CounterAdaptor = {
    {
QT_MOC_LITERAL(0, 0, 14), // "CounterAdaptor"
QT_MOC_LITERAL(1, 15, 15), // "D-Bus Interface"
QT_MOC_LITERAL(2, 31, 19), // "net.connman.Counter"
QT_MOC_LITERAL(3, 51, 19), // "D-Bus Introspection"
QT_MOC_LITERAL(4, 71, 446), // "  <interface name=\"net.connm..."
QT_MOC_LITERAL(5, 482, 7), // "Release"
QT_MOC_LITERAL(6, 490, 0), // ""
QT_MOC_LITERAL(7, 491, 5), // "Usage"
QT_MOC_LITERAL(8, 497, 15), // "QDBusObjectPath"
QT_MOC_LITERAL(9, 513, 3), // "in0"
QT_MOC_LITERAL(10, 517, 3), // "in1"
QT_MOC_LITERAL(11, 521, 3) // "in2"

    },
    "CounterAdaptor\0D-Bus Interface\0"
    "net.connman.Counter\0D-Bus Introspection\0"
    "  <interface name=\"net.connman.Counter\">\n    <method name=\"Release"
    "\"/>\n    <method name=\"Usage\">\n      <arg direction=\"in\" type=\""
    "o\"/>\n      <arg direction=\"in\" type=\"a{sv}\"/>\n      <annotation"
    " value=\"QVariantMap\" name=\"org.qtproject.QtDBus.QtTypeName.In1\"/>\n"
    "      <arg direction=\"in\" type=\"a{sv}\"/>\n      <annotation value="
    "\"QVariantMap\" name=\"org.qtproject.QtDBus.QtTypeName.In2\"/>\n    </"
    "method>\n  </interface>\n\0"
    "Release\0\0Usage\0QDBusObjectPath\0in0\0"
    "in1\0in2"
};
#undef QT_MOC_LITERAL

static const uint qt_meta_data_CounterAdaptor[] = {

 // content:
       8,       // revision
       0,       // classname
       2,   14, // classinfo
       2,   18, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       0,       // signalCount

 // classinfo: key, value
       1,    2,
       3,    4,

 // slots: name, argc, parameters, tag, flags
       5,    0,   28,    6, 0x0a /* Public */,
       7,    3,   29,    6, 0x0a /* Public */,

 // slots: parameters
    QMetaType::Void,
    QMetaType::Void, 0x80000000 | 8, QMetaType::QVariantMap, QMetaType::QVariantMap,    9,   10,   11,

       0        // eod
};

void CounterAdaptor::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::InvokeMetaMethod) {
        auto *_t = static_cast<CounterAdaptor *>(_o);
        (void)_t;
        switch (_id) {
        case 0: _t->Release(); break;
        case 1: _t->Usage((*reinterpret_cast< const QDBusObjectPath(*)>(_a[1])),(*reinterpret_cast< const QVariantMap(*)>(_a[2])),(*reinterpret_cast< const QVariantMap(*)>(_a[3]))); break;
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

QT_INIT_METAOBJECT const QMetaObject CounterAdaptor::staticMetaObject = { {
    QMetaObject::SuperData::link<QDBusAbstractAdaptor::staticMetaObject>(),
    qt_meta_stringdata_CounterAdaptor.data,
    qt_meta_data_CounterAdaptor,
    qt_static_metacall,
    nullptr,
    nullptr
} };


const QMetaObject *CounterAdaptor::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->dynamicMetaObject() : &staticMetaObject;
}

void *CounterAdaptor::qt_metacast(const char *_clname)
{
    if (!_clname) return nullptr;
    if (!strcmp(_clname, qt_meta_stringdata_CounterAdaptor.stringdata0))
        return static_cast<void*>(this);
    return QDBusAbstractAdaptor::qt_metacast(_clname);
}

int CounterAdaptor::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = QDBusAbstractAdaptor::qt_metacall(_c, _id, _a);
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
