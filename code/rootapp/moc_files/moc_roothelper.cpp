/****************************************************************************
** Meta object code from reading C++ file 'roothelper.h'
**
** Created by: The Qt Meta Object Compiler version 67 (Qt 5.3.2)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include "../roothelper/roothelper.h"
#include <QtCore/qbytearray.h>
#include <QtCore/qmetatype.h>
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'roothelper.h' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 67
#error "This file was generated using the moc from 5.3.2. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

QT_BEGIN_MOC_NAMESPACE
struct qt_meta_stringdata_RootHelper_t {
    QByteArrayData data[9];
    char stringdata[107];
};
#define QT_MOC_LITERAL(idx, ofs, len) \
    Q_STATIC_BYTE_ARRAY_DATA_HEADER_INITIALIZER_WITH_OFFSET(len, \
    qptrdiff(offsetof(qt_meta_stringdata_RootHelper_t, stringdata) + ofs \
        - idx * sizeof(QByteArrayData)) \
    )
static const qt_meta_stringdata_RootHelper_t qt_meta_stringdata_RootHelper = {
    {
QT_MOC_LITERAL(0, 0, 10),
QT_MOC_LITERAL(1, 11, 15),
QT_MOC_LITERAL(2, 27, 19),
QT_MOC_LITERAL(3, 47, 13),
QT_MOC_LITERAL(4, 61, 0),
QT_MOC_LITERAL(5, 62, 11),
QT_MOC_LITERAL(6, 74, 11),
QT_MOC_LITERAL(7, 86, 8),
QT_MOC_LITERAL(8, 95, 11)
    },
    "RootHelper\0D-Bus Interface\0"
    "org.cmst.roothelper\0readCompleted\0\0"
    "startHelper\0getFileList\0saveFile\0"
    "isConnected"
};
#undef QT_MOC_LITERAL

static const uint qt_meta_data_RootHelper[] = {

 // content:
       7,       // revision
       0,       // classname
       1,   14, // classinfo
       5,   16, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       1,       // signalCount

 // classinfo: key, value
       1,    2,

 // signals: name, argc, parameters, tag, flags
       3,    1,   41,    4, 0x06 /* Public */,

 // slots: name, argc, parameters, tag, flags
       5,    0,   44,    4, 0x0a /* Public */,
       6,    0,   45,    4, 0x0a /* Public */,
       7,    0,   46,    4, 0x0a /* Public */,
       8,    0,   47,    4, 0x0a /* Public */,

 // signals: parameters
    QMetaType::Void, QMetaType::QStringList,    4,

 // slots: parameters
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Bool,

       0        // eod
};

void RootHelper::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::InvokeMetaMethod) {
        RootHelper *_t = static_cast<RootHelper *>(_o);
        switch (_id) {
        case 0: _t->readCompleted((*reinterpret_cast< const QStringList(*)>(_a[1]))); break;
        case 1: _t->startHelper(); break;
        case 2: _t->getFileList(); break;
        case 3: _t->saveFile(); break;
        case 4: { bool _r = _t->isConnected();
            if (_a[0]) *reinterpret_cast< bool*>(_a[0]) = _r; }  break;
        default: ;
        }
    } else if (_c == QMetaObject::IndexOfMethod) {
        int *result = reinterpret_cast<int *>(_a[0]);
        void **func = reinterpret_cast<void **>(_a[1]);
        {
            typedef void (RootHelper::*_t)(const QStringList & );
            if (*reinterpret_cast<_t *>(func) == static_cast<_t>(&RootHelper::readCompleted)) {
                *result = 0;
            }
        }
    }
}

const QMetaObject RootHelper::staticMetaObject = {
    { &QObject::staticMetaObject, qt_meta_stringdata_RootHelper.data,
      qt_meta_data_RootHelper,  qt_static_metacall, 0, 0}
};


const QMetaObject *RootHelper::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->dynamicMetaObject() : &staticMetaObject;
}

void *RootHelper::qt_metacast(const char *_clname)
{
    if (!_clname) return 0;
    if (!strcmp(_clname, qt_meta_stringdata_RootHelper.stringdata))
        return static_cast<void*>(const_cast< RootHelper*>(this));
    if (!strcmp(_clname, "QDBusContext"))
        return static_cast< QDBusContext*>(const_cast< RootHelper*>(this));
    return QObject::qt_metacast(_clname);
}

int RootHelper::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
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
            *reinterpret_cast<int*>(_a[0]) = -1;
        _id -= 5;
    }
    return _id;
}

// SIGNAL 0
void RootHelper::readCompleted(const QStringList & _t1)
{
    void *_a[] = { 0, const_cast<void*>(reinterpret_cast<const void*>(&_t1)) };
    QMetaObject::activate(this, &staticMetaObject, 0, _a);
}
QT_END_MOC_NAMESPACE
