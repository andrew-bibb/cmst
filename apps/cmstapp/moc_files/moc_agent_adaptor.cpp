/****************************************************************************
** Meta object code from reading C++ file 'agent_adaptor.h'
**
** Created by: The Qt Meta Object Compiler version 67 (Qt 5.15.2)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include <memory>
#include "../agent_adaptor.h"
#include <QtCore/qbytearray.h>
#include <QtCore/qmetatype.h>
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'agent_adaptor.h' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 67
#error "This file was generated using the moc from 5.15.2. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

QT_BEGIN_MOC_NAMESPACE
QT_WARNING_PUSH
QT_WARNING_DISABLE_DEPRECATED
struct qt_meta_stringdata_AgentAdaptor_t {
    QByteArrayData data[14];
    char stringdata0[903];
};
#define QT_MOC_LITERAL(idx, ofs, len) \
    Q_STATIC_BYTE_ARRAY_DATA_HEADER_INITIALIZER_WITH_OFFSET(len, \
    qptrdiff(offsetof(qt_meta_stringdata_AgentAdaptor_t, stringdata0) + ofs \
        - idx * sizeof(QByteArrayData)) \
    )
static const qt_meta_stringdata_AgentAdaptor_t qt_meta_stringdata_AgentAdaptor = {
    {
QT_MOC_LITERAL(0, 0, 12), // "AgentAdaptor"
QT_MOC_LITERAL(1, 13, 15), // "D-Bus Interface"
QT_MOC_LITERAL(2, 29, 17), // "net.connman.Agent"
QT_MOC_LITERAL(3, 47, 19), // "D-Bus Introspection"
QT_MOC_LITERAL(4, 67, 755), // "  <interface name=\"net.connm..."
QT_MOC_LITERAL(5, 756, 6), // "Cancel"
QT_MOC_LITERAL(6, 763, 0), // ""
QT_MOC_LITERAL(7, 764, 7), // "Release"
QT_MOC_LITERAL(8, 772, 11), // "ReportError"
QT_MOC_LITERAL(9, 784, 15), // "QDBusObjectPath"
QT_MOC_LITERAL(10, 800, 3), // "in0"
QT_MOC_LITERAL(11, 804, 3), // "in1"
QT_MOC_LITERAL(12, 808, 14), // "RequestBrowser"
QT_MOC_LITERAL(13, 823, 12) // "RequestInput"

    },
    "AgentAdaptor\0D-Bus Interface\0"
    "net.connman.Agent\0D-Bus Introspection\0"
    "  <interface name=\"net.connman.Agent\">\n    <method name=\"Release\""
    "/>\n    <method name=\"ReportError\">\n      <arg direction=\"in\" typ"
    "e=\"o\"/>\n      <arg direction=\"in\" type=\"s\"/>\n    </method>\n  "
    "  <method name=\"RequestBrowser\">\n      <arg direction=\"in\" type=\""
    "o\"/>\n      <arg direction=\"in\" type=\"s\"/>\n    </method>\n    <m"
    "ethod name=\"RequestInput\">\n      <arg direction=\"out\" type=\"a{sv"
    "}\"/>\n      <annotation value=\"QVariantMap\" name=\"org.qtproject.Qt"
    "DBus.QtTypeName.Out0\"/>\n      <arg direction=\"in\" type=\"o\"/>\n  "
    "    <arg direction=\"in\" type=\"a{sv}\"/>\n      <annotation value=\""
    "QVariantMap\" name=\"org.qtproject.QtDBus.QtTypeName.In1\"/>\n    </me"
    "thod>\n    <method name=\"Cancel\"/>\n  </interface>\n\0"
    "Cancel\0\0Release\0ReportError\0QDBusObjectPath\0"
    "in0\0in1\0RequestBrowser\0RequestInput"
};
#undef QT_MOC_LITERAL

static const uint qt_meta_data_AgentAdaptor[] = {

 // content:
       8,       // revision
       0,       // classname
       2,   14, // classinfo
       5,   18, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       0,       // signalCount

 // classinfo: key, value
       1,    2,
       3,    4,

 // slots: name, argc, parameters, tag, flags
       5,    0,   43,    6, 0x0a /* Public */,
       7,    0,   44,    6, 0x0a /* Public */,
       8,    2,   45,    6, 0x0a /* Public */,
      12,    2,   50,    6, 0x0a /* Public */,
      13,    2,   55,    6, 0x0a /* Public */,

 // slots: parameters
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void, 0x80000000 | 9, QMetaType::QString,   10,   11,
    QMetaType::Void, 0x80000000 | 9, QMetaType::QString,   10,   11,
    QMetaType::QVariantMap, 0x80000000 | 9, QMetaType::QVariantMap,   10,   11,

       0        // eod
};

void AgentAdaptor::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::InvokeMetaMethod) {
        auto *_t = static_cast<AgentAdaptor *>(_o);
        (void)_t;
        switch (_id) {
        case 0: _t->Cancel(); break;
        case 1: _t->Release(); break;
        case 2: _t->ReportError((*reinterpret_cast< const QDBusObjectPath(*)>(_a[1])),(*reinterpret_cast< const QString(*)>(_a[2]))); break;
        case 3: _t->RequestBrowser((*reinterpret_cast< const QDBusObjectPath(*)>(_a[1])),(*reinterpret_cast< const QString(*)>(_a[2]))); break;
        case 4: { QVariantMap _r = _t->RequestInput((*reinterpret_cast< const QDBusObjectPath(*)>(_a[1])),(*reinterpret_cast< const QVariantMap(*)>(_a[2])));
            if (_a[0]) *reinterpret_cast< QVariantMap*>(_a[0]) = std::move(_r); }  break;
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
        case 4:
            switch (*reinterpret_cast<int*>(_a[1])) {
            default: *reinterpret_cast<int*>(_a[0]) = -1; break;
            case 0:
                *reinterpret_cast<int*>(_a[0]) = qRegisterMetaType< QDBusObjectPath >(); break;
            }
            break;
        }
    }
}

QT_INIT_METAOBJECT const QMetaObject AgentAdaptor::staticMetaObject = { {
    QMetaObject::SuperData::link<QDBusAbstractAdaptor::staticMetaObject>(),
    qt_meta_stringdata_AgentAdaptor.data,
    qt_meta_data_AgentAdaptor,
    qt_static_metacall,
    nullptr,
    nullptr
} };


const QMetaObject *AgentAdaptor::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->dynamicMetaObject() : &staticMetaObject;
}

void *AgentAdaptor::qt_metacast(const char *_clname)
{
    if (!_clname) return nullptr;
    if (!strcmp(_clname, qt_meta_stringdata_AgentAdaptor.stringdata0))
        return static_cast<void*>(this);
    return QDBusAbstractAdaptor::qt_metacast(_clname);
}

int AgentAdaptor::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = QDBusAbstractAdaptor::qt_metacall(_c, _id, _a);
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
