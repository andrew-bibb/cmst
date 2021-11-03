/****************************************************************************
** Meta object code from reading C++ file 'roothelper.h'
**
** Created by: The Qt Meta Object Compiler version 67 (Qt 5.15.2)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include <memory>
#include "../code/roothelper/roothelper.h"
#include <QtCore/qbytearray.h>
#include <QtCore/qmetatype.h>
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'roothelper.h' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 67
#error "This file was generated using the moc from 5.15.2. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

QT_BEGIN_MOC_NAMESPACE
QT_WARNING_PUSH
QT_WARNING_DISABLE_DEPRECATED
struct qt_meta_stringdata_RootHelper_t {
    QByteArrayData data[10];
    char stringdata0[113];
};
#define QT_MOC_LITERAL(idx, ofs, len) \
    Q_STATIC_BYTE_ARRAY_DATA_HEADER_INITIALIZER_WITH_OFFSET(len, \
    qptrdiff(offsetof(qt_meta_stringdata_RootHelper_t, stringdata0) + ofs \
        - idx * sizeof(QByteArrayData)) \
    )
static const qt_meta_stringdata_RootHelper_t qt_meta_stringdata_RootHelper = {
    {
QT_MOC_LITERAL(0, 0, 10), // "RootHelper"
QT_MOC_LITERAL(1, 11, 15), // "D-Bus Interface"
QT_MOC_LITERAL(2, 27, 19), // "org.cmst.roothelper"
QT_MOC_LITERAL(3, 47, 11), // "startHelper"
QT_MOC_LITERAL(4, 59, 0), // ""
QT_MOC_LITERAL(5, 60, 11), // "getFileList"
QT_MOC_LITERAL(6, 72, 8), // "readFile"
QT_MOC_LITERAL(7, 81, 10), // "deleteFile"
QT_MOC_LITERAL(8, 92, 8), // "saveFile"
QT_MOC_LITERAL(9, 101, 11) // "isConnected"

    },
    "RootHelper\0D-Bus Interface\0"
    "org.cmst.roothelper\0startHelper\0\0"
    "getFileList\0readFile\0deleteFile\0"
    "saveFile\0isConnected"
};
#undef QT_MOC_LITERAL

static const uint qt_meta_data_RootHelper[] = {

 // content:
       8,       // revision
       0,       // classname
       1,   14, // classinfo
       6,   16, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       0,       // signalCount

 // classinfo: key, value
       1,    2,

 // slots: name, argc, parameters, tag, flags
       3,    0,   46,    4, 0x0a /* Public */,
       5,    1,   47,    4, 0x0a /* Public */,
       6,    2,   50,    4, 0x0a /* Public */,
       7,    2,   55,    4, 0x0a /* Public */,
       8,    3,   60,    4, 0x0a /* Public */,
       9,    0,   67,    4, 0x0a /* Public */,

 // slots: parameters
    QMetaType::Void,
    QMetaType::QStringList, QMetaType::QString,    4,
    QMetaType::QString, QMetaType::QString, QMetaType::QString,    4,    4,
    QMetaType::Bool, QMetaType::QString, QMetaType::QString,    4,    4,
    QMetaType::LongLong, QMetaType::QString, QMetaType::QString, QMetaType::QString,    4,    4,    4,
    QMetaType::Bool,

       0        // eod
};

void RootHelper::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::InvokeMetaMethod) {
        auto *_t = static_cast<RootHelper *>(_o);
        (void)_t;
        switch (_id) {
        case 0: _t->startHelper(); break;
        case 1: { QStringList _r = _t->getFileList((*reinterpret_cast< const QString(*)>(_a[1])));
            if (_a[0]) *reinterpret_cast< QStringList*>(_a[0]) = std::move(_r); }  break;
        case 2: { QString _r = _t->readFile((*reinterpret_cast< const QString(*)>(_a[1])),(*reinterpret_cast< const QString(*)>(_a[2])));
            if (_a[0]) *reinterpret_cast< QString*>(_a[0]) = std::move(_r); }  break;
        case 3: { bool _r = _t->deleteFile((*reinterpret_cast< const QString(*)>(_a[1])),(*reinterpret_cast< const QString(*)>(_a[2])));
            if (_a[0]) *reinterpret_cast< bool*>(_a[0]) = std::move(_r); }  break;
        case 4: { qint64 _r = _t->saveFile((*reinterpret_cast< const QString(*)>(_a[1])),(*reinterpret_cast< const QString(*)>(_a[2])),(*reinterpret_cast< const QString(*)>(_a[3])));
            if (_a[0]) *reinterpret_cast< qint64*>(_a[0]) = std::move(_r); }  break;
        case 5: { bool _r = _t->isConnected();
            if (_a[0]) *reinterpret_cast< bool*>(_a[0]) = std::move(_r); }  break;
        default: ;
        }
    }
}

QT_INIT_METAOBJECT const QMetaObject RootHelper::staticMetaObject = { {
    QMetaObject::SuperData::link<QObject::staticMetaObject>(),
    qt_meta_stringdata_RootHelper.data,
    qt_meta_data_RootHelper,
    qt_static_metacall,
    nullptr,
    nullptr
} };


const QMetaObject *RootHelper::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->dynamicMetaObject() : &staticMetaObject;
}

void *RootHelper::qt_metacast(const char *_clname)
{
    if (!_clname) return nullptr;
    if (!strcmp(_clname, qt_meta_stringdata_RootHelper.stringdata0))
        return static_cast<void*>(this);
    if (!strcmp(_clname, "QDBusContext"))
        return static_cast< QDBusContext*>(this);
    return QObject::qt_metacast(_clname);
}

int RootHelper::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = QObject::qt_metacall(_c, _id, _a);
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
