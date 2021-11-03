/****************************************************************************
** Meta object code from reading C++ file 'roothelper_adaptor.h'
**
** Created by: The Qt Meta Object Compiler version 67 (Qt 5.15.2)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include <memory>
#include "../roothelper_adaptor.h"
#include <QtCore/qbytearray.h>
#include <QtCore/qmetatype.h>
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'roothelper_adaptor.h' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 67
#error "This file was generated using the moc from 5.15.2. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

QT_BEGIN_MOC_NAMESPACE
QT_WARNING_PUSH
QT_WARNING_DISABLE_DEPRECATED
struct qt_meta_stringdata_RoothelperAdaptor_t {
    QByteArrayData data[15];
    char stringdata0[1044];
};
#define QT_MOC_LITERAL(idx, ofs, len) \
    Q_STATIC_BYTE_ARRAY_DATA_HEADER_INITIALIZER_WITH_OFFSET(len, \
    qptrdiff(offsetof(qt_meta_stringdata_RoothelperAdaptor_t, stringdata0) + ofs \
        - idx * sizeof(QByteArrayData)) \
    )
static const qt_meta_stringdata_RoothelperAdaptor_t qt_meta_stringdata_RoothelperAdaptor = {
    {
QT_MOC_LITERAL(0, 0, 17), // "RoothelperAdaptor"
QT_MOC_LITERAL(1, 18, 15), // "D-Bus Interface"
QT_MOC_LITERAL(2, 34, 19), // "org.cmst.roothelper"
QT_MOC_LITERAL(3, 54, 19), // "D-Bus Introspection"
QT_MOC_LITERAL(4, 74, 891), // "  <interface name=\"org.cmst...."
QT_MOC_LITERAL(5, 874, 10), // "deleteFile"
QT_MOC_LITERAL(6, 885, 0), // ""
QT_MOC_LITERAL(7, 886, 3), // "in0"
QT_MOC_LITERAL(8, 890, 3), // "in1"
QT_MOC_LITERAL(9, 894, 11), // "getFileList"
QT_MOC_LITERAL(10, 906, 11), // "isConnected"
QT_MOC_LITERAL(11, 918, 8), // "readFile"
QT_MOC_LITERAL(12, 927, 8), // "saveFile"
QT_MOC_LITERAL(13, 936, 3), // "in2"
QT_MOC_LITERAL(14, 940, 11) // "startHelper"

    },
    "RoothelperAdaptor\0D-Bus Interface\0"
    "org.cmst.roothelper\0D-Bus Introspection\0"
    "  <interface name=\"org.cmst.roothelper\">\n    <method name=\"startHe"
    "lper\"/>\n    <method name=\"getFileList\">\n      <arg direction=\"ou"
    "t\" type=\"as\"/>\n      <arg direction=\"in\" type=\"s\"/>\n    </met"
    "hod>\n    <method name=\"readFile\">\n      <arg direction=\"out\" typ"
    "e=\"s\"/>\n      <arg direction=\"in\" type=\"s\"/>\n      <arg direct"
    "ion=\"in\" type=\"s\"/>\n    </method>\n    <method name=\"deleteFile\""
    ">\n      <arg direction=\"out\" type=\"b\"/>\n      <arg direction=\"i"
    "n\" type=\"s\"/>\n      <arg direction=\"in\" type=\"s\"/>\n    </meth"
    "od>\n    <method name=\"saveFile\">\n      <arg direction=\"out\" type"
    "=\"x\"/>\n      <arg direction=\"in\" type=\"s\"/>\n      <arg directi"
    "on=\"in\" type=\"s\"/>\n      <arg direction=\"in\" type=\"s\"/>\n    "
    "</method>\n    <method name=\"isConnected\">\n      <arg direction=\"o"
    "ut\" type=\"b\"/>\n    </method>\n  </interface>\n\0"
    "deleteFile\0\0in0\0in1\0getFileList\0"
    "isConnected\0readFile\0saveFile\0in2\0"
    "startHelper"
};
#undef QT_MOC_LITERAL

static const uint qt_meta_data_RoothelperAdaptor[] = {

 // content:
       8,       // revision
       0,       // classname
       2,   14, // classinfo
       6,   18, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       0,       // signalCount

 // classinfo: key, value
       1,    2,
       3,    4,

 // slots: name, argc, parameters, tag, flags
       5,    2,   48,    6, 0x0a /* Public */,
       9,    1,   53,    6, 0x0a /* Public */,
      10,    0,   56,    6, 0x0a /* Public */,
      11,    2,   57,    6, 0x0a /* Public */,
      12,    3,   62,    6, 0x0a /* Public */,
      14,    0,   69,    6, 0x0a /* Public */,

 // slots: parameters
    QMetaType::Bool, QMetaType::QString, QMetaType::QString,    7,    8,
    QMetaType::QStringList, QMetaType::QString,    7,
    QMetaType::Bool,
    QMetaType::QString, QMetaType::QString, QMetaType::QString,    7,    8,
    QMetaType::LongLong, QMetaType::QString, QMetaType::QString, QMetaType::QString,    7,    8,   13,
    QMetaType::Void,

       0        // eod
};

void RoothelperAdaptor::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::InvokeMetaMethod) {
        auto *_t = static_cast<RoothelperAdaptor *>(_o);
        (void)_t;
        switch (_id) {
        case 0: { bool _r = _t->deleteFile((*reinterpret_cast< const QString(*)>(_a[1])),(*reinterpret_cast< const QString(*)>(_a[2])));
            if (_a[0]) *reinterpret_cast< bool*>(_a[0]) = std::move(_r); }  break;
        case 1: { QStringList _r = _t->getFileList((*reinterpret_cast< const QString(*)>(_a[1])));
            if (_a[0]) *reinterpret_cast< QStringList*>(_a[0]) = std::move(_r); }  break;
        case 2: { bool _r = _t->isConnected();
            if (_a[0]) *reinterpret_cast< bool*>(_a[0]) = std::move(_r); }  break;
        case 3: { QString _r = _t->readFile((*reinterpret_cast< const QString(*)>(_a[1])),(*reinterpret_cast< const QString(*)>(_a[2])));
            if (_a[0]) *reinterpret_cast< QString*>(_a[0]) = std::move(_r); }  break;
        case 4: { qlonglong _r = _t->saveFile((*reinterpret_cast< const QString(*)>(_a[1])),(*reinterpret_cast< const QString(*)>(_a[2])),(*reinterpret_cast< const QString(*)>(_a[3])));
            if (_a[0]) *reinterpret_cast< qlonglong*>(_a[0]) = std::move(_r); }  break;
        case 5: _t->startHelper(); break;
        default: ;
        }
    }
}

QT_INIT_METAOBJECT const QMetaObject RoothelperAdaptor::staticMetaObject = { {
    QMetaObject::SuperData::link<QDBusAbstractAdaptor::staticMetaObject>(),
    qt_meta_stringdata_RoothelperAdaptor.data,
    qt_meta_data_RoothelperAdaptor,
    qt_static_metacall,
    nullptr,
    nullptr
} };


const QMetaObject *RoothelperAdaptor::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->dynamicMetaObject() : &staticMetaObject;
}

void *RoothelperAdaptor::qt_metacast(const char *_clname)
{
    if (!_clname) return nullptr;
    if (!strcmp(_clname, qt_meta_stringdata_RoothelperAdaptor.stringdata0))
        return static_cast<void*>(this);
    return QDBusAbstractAdaptor::qt_metacast(_clname);
}

int RoothelperAdaptor::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = QDBusAbstractAdaptor::qt_metacall(_c, _id, _a);
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
