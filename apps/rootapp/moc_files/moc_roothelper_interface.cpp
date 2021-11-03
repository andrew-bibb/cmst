/****************************************************************************
** Meta object code from reading C++ file 'roothelper_interface.h'
**
** Created by: The Qt Meta Object Compiler version 67 (Qt 5.15.2)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include <memory>
#include "../roothelper_interface.h"
#include <QtCore/qbytearray.h>
#include <QtCore/qmetatype.h>
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'roothelper_interface.h' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 67
#error "This file was generated using the moc from 5.15.2. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

QT_BEGIN_MOC_NAMESPACE
QT_WARNING_PUSH
QT_WARNING_DISABLE_DEPRECATED
struct qt_meta_stringdata_OrgCmstRoothelperInterface_t {
    QByteArrayData data[16];
    char stringdata0[236];
};
#define QT_MOC_LITERAL(idx, ofs, len) \
    Q_STATIC_BYTE_ARRAY_DATA_HEADER_INITIALIZER_WITH_OFFSET(len, \
    qptrdiff(offsetof(qt_meta_stringdata_OrgCmstRoothelperInterface_t, stringdata0) + ofs \
        - idx * sizeof(QByteArrayData)) \
    )
static const qt_meta_stringdata_OrgCmstRoothelperInterface_t qt_meta_stringdata_OrgCmstRoothelperInterface = {
    {
QT_MOC_LITERAL(0, 0, 26), // "OrgCmstRoothelperInterface"
QT_MOC_LITERAL(1, 27, 10), // "deleteFile"
QT_MOC_LITERAL(2, 38, 23), // "QDBusPendingReply<bool>"
QT_MOC_LITERAL(3, 62, 0), // ""
QT_MOC_LITERAL(4, 63, 3), // "in0"
QT_MOC_LITERAL(5, 67, 3), // "in1"
QT_MOC_LITERAL(6, 71, 11), // "getFileList"
QT_MOC_LITERAL(7, 83, 30), // "QDBusPendingReply<QStringList>"
QT_MOC_LITERAL(8, 114, 11), // "isConnected"
QT_MOC_LITERAL(9, 126, 8), // "readFile"
QT_MOC_LITERAL(10, 135, 26), // "QDBusPendingReply<QString>"
QT_MOC_LITERAL(11, 162, 8), // "saveFile"
QT_MOC_LITERAL(12, 171, 28), // "QDBusPendingReply<qlonglong>"
QT_MOC_LITERAL(13, 200, 3), // "in2"
QT_MOC_LITERAL(14, 204, 11), // "startHelper"
QT_MOC_LITERAL(15, 216, 19) // "QDBusPendingReply<>"

    },
    "OrgCmstRoothelperInterface\0deleteFile\0"
    "QDBusPendingReply<bool>\0\0in0\0in1\0"
    "getFileList\0QDBusPendingReply<QStringList>\0"
    "isConnected\0readFile\0QDBusPendingReply<QString>\0"
    "saveFile\0QDBusPendingReply<qlonglong>\0"
    "in2\0startHelper\0QDBusPendingReply<>"
};
#undef QT_MOC_LITERAL

static const uint qt_meta_data_OrgCmstRoothelperInterface[] = {

 // content:
       8,       // revision
       0,       // classname
       0,    0, // classinfo
       6,   14, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       0,       // signalCount

 // slots: name, argc, parameters, tag, flags
       1,    2,   44,    3, 0x0a /* Public */,
       6,    1,   49,    3, 0x0a /* Public */,
       8,    0,   52,    3, 0x0a /* Public */,
       9,    2,   53,    3, 0x0a /* Public */,
      11,    3,   58,    3, 0x0a /* Public */,
      14,    0,   65,    3, 0x0a /* Public */,

 // slots: parameters
    0x80000000 | 2, QMetaType::QString, QMetaType::QString,    4,    5,
    0x80000000 | 7, QMetaType::QString,    4,
    0x80000000 | 2,
    0x80000000 | 10, QMetaType::QString, QMetaType::QString,    4,    5,
    0x80000000 | 12, QMetaType::QString, QMetaType::QString, QMetaType::QString,    4,    5,   13,
    0x80000000 | 15,

       0        // eod
};

void OrgCmstRoothelperInterface::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::InvokeMetaMethod) {
        auto *_t = static_cast<OrgCmstRoothelperInterface *>(_o);
        (void)_t;
        switch (_id) {
        case 0: { QDBusPendingReply<bool> _r = _t->deleteFile((*reinterpret_cast< const QString(*)>(_a[1])),(*reinterpret_cast< const QString(*)>(_a[2])));
            if (_a[0]) *reinterpret_cast< QDBusPendingReply<bool>*>(_a[0]) = std::move(_r); }  break;
        case 1: { QDBusPendingReply<QStringList> _r = _t->getFileList((*reinterpret_cast< const QString(*)>(_a[1])));
            if (_a[0]) *reinterpret_cast< QDBusPendingReply<QStringList>*>(_a[0]) = std::move(_r); }  break;
        case 2: { QDBusPendingReply<bool> _r = _t->isConnected();
            if (_a[0]) *reinterpret_cast< QDBusPendingReply<bool>*>(_a[0]) = std::move(_r); }  break;
        case 3: { QDBusPendingReply<QString> _r = _t->readFile((*reinterpret_cast< const QString(*)>(_a[1])),(*reinterpret_cast< const QString(*)>(_a[2])));
            if (_a[0]) *reinterpret_cast< QDBusPendingReply<QString>*>(_a[0]) = std::move(_r); }  break;
        case 4: { QDBusPendingReply<qlonglong> _r = _t->saveFile((*reinterpret_cast< const QString(*)>(_a[1])),(*reinterpret_cast< const QString(*)>(_a[2])),(*reinterpret_cast< const QString(*)>(_a[3])));
            if (_a[0]) *reinterpret_cast< QDBusPendingReply<qlonglong>*>(_a[0]) = std::move(_r); }  break;
        case 5: { QDBusPendingReply<> _r = _t->startHelper();
            if (_a[0]) *reinterpret_cast< QDBusPendingReply<>*>(_a[0]) = std::move(_r); }  break;
        default: ;
        }
    }
}

QT_INIT_METAOBJECT const QMetaObject OrgCmstRoothelperInterface::staticMetaObject = { {
    QMetaObject::SuperData::link<QDBusAbstractInterface::staticMetaObject>(),
    qt_meta_stringdata_OrgCmstRoothelperInterface.data,
    qt_meta_data_OrgCmstRoothelperInterface,
    qt_static_metacall,
    nullptr,
    nullptr
} };


const QMetaObject *OrgCmstRoothelperInterface::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->dynamicMetaObject() : &staticMetaObject;
}

void *OrgCmstRoothelperInterface::qt_metacast(const char *_clname)
{
    if (!_clname) return nullptr;
    if (!strcmp(_clname, qt_meta_stringdata_OrgCmstRoothelperInterface.stringdata0))
        return static_cast<void*>(this);
    return QDBusAbstractInterface::qt_metacast(_clname);
}

int OrgCmstRoothelperInterface::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = QDBusAbstractInterface::qt_metacall(_c, _id, _a);
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
