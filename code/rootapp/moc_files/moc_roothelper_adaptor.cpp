/****************************************************************************
** Meta object code from reading C++ file 'roothelper_adaptor.h'
**
** Created by: The Qt Meta Object Compiler version 67 (Qt 5.3.2)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include "../roothelper_adaptor.h"
#include <QtCore/qbytearray.h>
#include <QtCore/qmetatype.h>
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'roothelper_adaptor.h' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 67
#error "This file was generated using the moc from 5.3.2. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

QT_BEGIN_MOC_NAMESPACE
struct qt_meta_stringdata_RoothelperAdaptor_t {
    QByteArrayData data[12];
    char stringdata[493];
};
#define QT_MOC_LITERAL(idx, ofs, len) \
    Q_STATIC_BYTE_ARRAY_DATA_HEADER_INITIALIZER_WITH_OFFSET(len, \
    qptrdiff(offsetof(qt_meta_stringdata_RoothelperAdaptor_t, stringdata) + ofs \
        - idx * sizeof(QByteArrayData)) \
    )
static const qt_meta_stringdata_RoothelperAdaptor_t qt_meta_stringdata_RoothelperAdaptor = {
    {
QT_MOC_LITERAL(0, 0, 17),
QT_MOC_LITERAL(1, 18, 15),
QT_MOC_LITERAL(2, 34, 19),
QT_MOC_LITERAL(3, 54, 19),
QT_MOC_LITERAL(4, 74, 354),
QT_MOC_LITERAL(5, 398, 13),
QT_MOC_LITERAL(6, 412, 0),
QT_MOC_LITERAL(7, 413, 3),
QT_MOC_LITERAL(8, 417, 11),
QT_MOC_LITERAL(9, 429, 11),
QT_MOC_LITERAL(10, 441, 8),
QT_MOC_LITERAL(11, 450, 11)
    },
    "RoothelperAdaptor\0D-Bus Interface\0"
    "org.cmst.roothelper\0D-Bus Introspection\0"
    "  <interface name=\"org.cmst.roothelper\">\n    <signal name=\"readCom"
    "pleted\">\n      <arg direction=\"out\" type=\"as\"/>\n    </signal>\n"
    "    <method name=\"startHelper\"/>\n    <method name=\"getFileList\"/>"
    "\n    <method name=\"saveFile\"/>\n    <method name=\"isConnected\">\n"
    "      <arg direction=\"out\" type=\"b\"/>\n    </method>\n  </interfac"
    "e>\n\0"
    "readCompleted\0\0in0\0getFileList\0"
    "isConnected\0saveFile\0startHelper"
};
#undef QT_MOC_LITERAL

static const uint qt_meta_data_RoothelperAdaptor[] = {

 // content:
       7,       // revision
       0,       // classname
       2,   14, // classinfo
       5,   18, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       1,       // signalCount

 // classinfo: key, value
       1,    2,
       3,    4,

 // signals: name, argc, parameters, tag, flags
       5,    1,   43,    6, 0x06 /* Public */,

 // slots: name, argc, parameters, tag, flags
       8,    0,   46,    6, 0x0a /* Public */,
       9,    0,   47,    6, 0x0a /* Public */,
      10,    0,   48,    6, 0x0a /* Public */,
      11,    0,   49,    6, 0x0a /* Public */,

 // signals: parameters
    QMetaType::Void, QMetaType::QStringList,    7,

 // slots: parameters
    QMetaType::Void,
    QMetaType::Bool,
    QMetaType::Void,
    QMetaType::Void,

       0        // eod
};

void RoothelperAdaptor::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::InvokeMetaMethod) {
        RoothelperAdaptor *_t = static_cast<RoothelperAdaptor *>(_o);
        switch (_id) {
        case 0: _t->readCompleted((*reinterpret_cast< const QStringList(*)>(_a[1]))); break;
        case 1: _t->getFileList(); break;
        case 2: { bool _r = _t->isConnected();
            if (_a[0]) *reinterpret_cast< bool*>(_a[0]) = _r; }  break;
        case 3: _t->saveFile(); break;
        case 4: _t->startHelper(); break;
        default: ;
        }
    } else if (_c == QMetaObject::IndexOfMethod) {
        int *result = reinterpret_cast<int *>(_a[0]);
        void **func = reinterpret_cast<void **>(_a[1]);
        {
            typedef void (RoothelperAdaptor::*_t)(const QStringList & );
            if (*reinterpret_cast<_t *>(func) == static_cast<_t>(&RoothelperAdaptor::readCompleted)) {
                *result = 0;
            }
        }
    }
}

const QMetaObject RoothelperAdaptor::staticMetaObject = {
    { &QDBusAbstractAdaptor::staticMetaObject, qt_meta_stringdata_RoothelperAdaptor.data,
      qt_meta_data_RoothelperAdaptor,  qt_static_metacall, 0, 0}
};


const QMetaObject *RoothelperAdaptor::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->dynamicMetaObject() : &staticMetaObject;
}

void *RoothelperAdaptor::qt_metacast(const char *_clname)
{
    if (!_clname) return 0;
    if (!strcmp(_clname, qt_meta_stringdata_RoothelperAdaptor.stringdata))
        return static_cast<void*>(const_cast< RoothelperAdaptor*>(this));
    return QDBusAbstractAdaptor::qt_metacast(_clname);
}

int RoothelperAdaptor::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
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
            *reinterpret_cast<int*>(_a[0]) = -1;
        _id -= 5;
    }
    return _id;
}

// SIGNAL 0
void RoothelperAdaptor::readCompleted(const QStringList & _t1)
{
    void *_a[] = { 0, const_cast<void*>(reinterpret_cast<const void*>(&_t1)) };
    QMetaObject::activate(this, &staticMetaObject, 0, _a);
}
QT_END_MOC_NAMESPACE
