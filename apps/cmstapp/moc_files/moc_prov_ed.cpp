/****************************************************************************
** Meta object code from reading C++ file 'prov_ed.h'
**
** Created by: The Qt Meta Object Compiler version 67 (Qt 5.15.2)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include <memory>
#include "../code/provisioning/prov_ed.h"
#include <QtCore/qbytearray.h>
#include <QtCore/qmetatype.h>
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'prov_ed.h' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 67
#error "This file was generated using the moc from 5.15.2. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

QT_BEGIN_MOC_NAMESPACE
QT_WARNING_PUSH
QT_WARNING_DISABLE_DEPRECATED
struct qt_meta_stringdata_ProvisioningEditor_t {
    QByteArrayData data[20];
    char stringdata0[279];
};
#define QT_MOC_LITERAL(idx, ofs, len) \
    Q_STATIC_BYTE_ARRAY_DATA_HEADER_INITIALIZER_WITH_OFFSET(len, \
    qptrdiff(offsetof(qt_meta_stringdata_ProvisioningEditor_t, stringdata0) + ofs \
        - idx * sizeof(QByteArrayData)) \
    )
static const qt_meta_stringdata_ProvisioningEditor_t qt_meta_stringdata_ProvisioningEditor = {
    {
QT_MOC_LITERAL(0, 0, 18), // "ProvisioningEditor"
QT_MOC_LITERAL(1, 19, 15), // "inputSelectFile"
QT_MOC_LITERAL(2, 35, 0), // ""
QT_MOC_LITERAL(3, 36, 8), // "QAction*"
QT_MOC_LITERAL(4, 45, 14), // "inputValidated"
QT_MOC_LITERAL(5, 60, 13), // "inputComboBox"
QT_MOC_LITERAL(6, 74, 13), // "inputFreeForm"
QT_MOC_LITERAL(7, 88, 11), // "ipv4Address"
QT_MOC_LITERAL(8, 100, 11), // "ipv6Address"
QT_MOC_LITERAL(9, 112, 17), // "templateTriggered"
QT_MOC_LITERAL(10, 130, 13), // "showWhatsThis"
QT_MOC_LITERAL(11, 144, 9), // "resetPage"
QT_MOC_LITERAL(12, 154, 15), // "requestFileList"
QT_MOC_LITERAL(13, 170, 16), // "QAbstractButton*"
QT_MOC_LITERAL(14, 187, 15), // "processFileList"
QT_MOC_LITERAL(15, 203, 12), // "seedTextEdit"
QT_MOC_LITERAL(16, 216, 15), // "deleteCompleted"
QT_MOC_LITERAL(17, 232, 14), // "writeCompleted"
QT_MOC_LITERAL(18, 247, 20), // "callbackErrorHandler"
QT_MOC_LITERAL(19, 268, 10) // "QDBusError"

    },
    "ProvisioningEditor\0inputSelectFile\0\0"
    "QAction*\0inputValidated\0inputComboBox\0"
    "inputFreeForm\0ipv4Address\0ipv6Address\0"
    "templateTriggered\0showWhatsThis\0"
    "resetPage\0requestFileList\0QAbstractButton*\0"
    "processFileList\0seedTextEdit\0"
    "deleteCompleted\0writeCompleted\0"
    "callbackErrorHandler\0QDBusError"
};
#undef QT_MOC_LITERAL

static const uint qt_meta_data_ProvisioningEditor[] = {

 // content:
       8,       // revision
       0,       // classname
       0,    0, // classinfo
      15,   14, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       0,       // signalCount

 // slots: name, argc, parameters, tag, flags
       1,    1,   89,    2, 0x08 /* Private */,
       4,    1,   92,    2, 0x08 /* Private */,
       5,    1,   95,    2, 0x08 /* Private */,
       6,    1,   98,    2, 0x08 /* Private */,
       7,    0,  101,    2, 0x08 /* Private */,
       8,    0,  102,    2, 0x08 /* Private */,
       9,    1,  103,    2, 0x08 /* Private */,
      10,    0,  106,    2, 0x08 /* Private */,
      11,    0,  107,    2, 0x08 /* Private */,
      12,    1,  108,    2, 0x08 /* Private */,
      14,    1,  111,    2, 0x08 /* Private */,
      15,    1,  114,    2, 0x08 /* Private */,
      16,    1,  117,    2, 0x08 /* Private */,
      17,    1,  120,    2, 0x08 /* Private */,
      18,    1,  123,    2, 0x08 /* Private */,

 // slots: parameters
    QMetaType::Void, 0x80000000 | 3,    2,
    QMetaType::Void, 0x80000000 | 3,    2,
    QMetaType::Void, 0x80000000 | 3,    2,
    QMetaType::Void, 0x80000000 | 3,    2,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void, 0x80000000 | 3,    2,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void, 0x80000000 | 13,    2,
    QMetaType::Void, QMetaType::QStringList,    2,
    QMetaType::Void, QMetaType::QString,    2,
    QMetaType::Void, QMetaType::Bool,    2,
    QMetaType::Void, QMetaType::LongLong,    2,
    QMetaType::Void, 0x80000000 | 19,    2,

       0        // eod
};

void ProvisioningEditor::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::InvokeMetaMethod) {
        auto *_t = static_cast<ProvisioningEditor *>(_o);
        (void)_t;
        switch (_id) {
        case 0: _t->inputSelectFile((*reinterpret_cast< QAction*(*)>(_a[1]))); break;
        case 1: _t->inputValidated((*reinterpret_cast< QAction*(*)>(_a[1]))); break;
        case 2: _t->inputComboBox((*reinterpret_cast< QAction*(*)>(_a[1]))); break;
        case 3: _t->inputFreeForm((*reinterpret_cast< QAction*(*)>(_a[1]))); break;
        case 4: _t->ipv4Address(); break;
        case 5: _t->ipv6Address(); break;
        case 6: _t->templateTriggered((*reinterpret_cast< QAction*(*)>(_a[1]))); break;
        case 7: _t->showWhatsThis(); break;
        case 8: _t->resetPage(); break;
        case 9: _t->requestFileList((*reinterpret_cast< QAbstractButton*(*)>(_a[1]))); break;
        case 10: _t->processFileList((*reinterpret_cast< const QStringList(*)>(_a[1]))); break;
        case 11: _t->seedTextEdit((*reinterpret_cast< const QString(*)>(_a[1]))); break;
        case 12: _t->deleteCompleted((*reinterpret_cast< bool(*)>(_a[1]))); break;
        case 13: _t->writeCompleted((*reinterpret_cast< qint64(*)>(_a[1]))); break;
        case 14: _t->callbackErrorHandler((*reinterpret_cast< QDBusError(*)>(_a[1]))); break;
        default: ;
        }
    } else if (_c == QMetaObject::RegisterMethodArgumentMetaType) {
        switch (_id) {
        default: *reinterpret_cast<int*>(_a[0]) = -1; break;
        case 0:
            switch (*reinterpret_cast<int*>(_a[1])) {
            default: *reinterpret_cast<int*>(_a[0]) = -1; break;
            case 0:
                *reinterpret_cast<int*>(_a[0]) = qRegisterMetaType< QAction* >(); break;
            }
            break;
        case 1:
            switch (*reinterpret_cast<int*>(_a[1])) {
            default: *reinterpret_cast<int*>(_a[0]) = -1; break;
            case 0:
                *reinterpret_cast<int*>(_a[0]) = qRegisterMetaType< QAction* >(); break;
            }
            break;
        case 2:
            switch (*reinterpret_cast<int*>(_a[1])) {
            default: *reinterpret_cast<int*>(_a[0]) = -1; break;
            case 0:
                *reinterpret_cast<int*>(_a[0]) = qRegisterMetaType< QAction* >(); break;
            }
            break;
        case 3:
            switch (*reinterpret_cast<int*>(_a[1])) {
            default: *reinterpret_cast<int*>(_a[0]) = -1; break;
            case 0:
                *reinterpret_cast<int*>(_a[0]) = qRegisterMetaType< QAction* >(); break;
            }
            break;
        case 6:
            switch (*reinterpret_cast<int*>(_a[1])) {
            default: *reinterpret_cast<int*>(_a[0]) = -1; break;
            case 0:
                *reinterpret_cast<int*>(_a[0]) = qRegisterMetaType< QAction* >(); break;
            }
            break;
        case 9:
            switch (*reinterpret_cast<int*>(_a[1])) {
            default: *reinterpret_cast<int*>(_a[0]) = -1; break;
            case 0:
                *reinterpret_cast<int*>(_a[0]) = qRegisterMetaType< QAbstractButton* >(); break;
            }
            break;
        case 14:
            switch (*reinterpret_cast<int*>(_a[1])) {
            default: *reinterpret_cast<int*>(_a[0]) = -1; break;
            case 0:
                *reinterpret_cast<int*>(_a[0]) = qRegisterMetaType< QDBusError >(); break;
            }
            break;
        }
    }
}

QT_INIT_METAOBJECT const QMetaObject ProvisioningEditor::staticMetaObject = { {
    QMetaObject::SuperData::link<QDialog::staticMetaObject>(),
    qt_meta_stringdata_ProvisioningEditor.data,
    qt_meta_data_ProvisioningEditor,
    qt_static_metacall,
    nullptr,
    nullptr
} };


const QMetaObject *ProvisioningEditor::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->dynamicMetaObject() : &staticMetaObject;
}

void *ProvisioningEditor::qt_metacast(const char *_clname)
{
    if (!_clname) return nullptr;
    if (!strcmp(_clname, qt_meta_stringdata_ProvisioningEditor.stringdata0))
        return static_cast<void*>(this);
    return QDialog::qt_metacast(_clname);
}

int ProvisioningEditor::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = QDialog::qt_metacall(_c, _id, _a);
    if (_id < 0)
        return _id;
    if (_c == QMetaObject::InvokeMetaMethod) {
        if (_id < 15)
            qt_static_metacall(this, _c, _id, _a);
        _id -= 15;
    } else if (_c == QMetaObject::RegisterMethodArgumentMetaType) {
        if (_id < 15)
            qt_static_metacall(this, _c, _id, _a);
        _id -= 15;
    }
    return _id;
}
QT_WARNING_POP
QT_END_MOC_NAMESPACE
