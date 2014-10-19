/****************************************************************************
** Meta object code from reading C++ file 'prov_ed.h'
**
** Created by: The Qt Meta Object Compiler version 67 (Qt 5.3.2)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include "../provisioning/prov_ed.h"
#include <QtCore/qbytearray.h>
#include <QtCore/qmetatype.h>
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'prov_ed.h' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 67
#error "This file was generated using the moc from 5.3.2. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

QT_BEGIN_MOC_NAMESPACE
struct qt_meta_stringdata_ProvisioningEditor_t {
    QByteArrayData data[11];
    char stringdata[129];
};
#define QT_MOC_LITERAL(idx, ofs, len) \
    Q_STATIC_BYTE_ARRAY_DATA_HEADER_INITIALIZER_WITH_OFFSET(len, \
    qptrdiff(offsetof(qt_meta_stringdata_ProvisioningEditor_t, stringdata) + ofs \
        - idx * sizeof(QByteArrayData)) \
    )
static const qt_meta_stringdata_ProvisioningEditor_t qt_meta_stringdata_ProvisioningEditor = {
    {
QT_MOC_LITERAL(0, 0, 18),
QT_MOC_LITERAL(1, 19, 13),
QT_MOC_LITERAL(2, 33, 0),
QT_MOC_LITERAL(3, 34, 9),
QT_MOC_LITERAL(4, 44, 4),
QT_MOC_LITERAL(5, 49, 8),
QT_MOC_LITERAL(6, 58, 18),
QT_MOC_LITERAL(7, 77, 10),
QT_MOC_LITERAL(8, 88, 8),
QT_MOC_LITERAL(9, 97, 15),
QT_MOC_LITERAL(10, 113, 15)
    },
    "ProvisioningEditor\0showWhatsThis\0\0"
    "resetPage\0page\0resetAll\0serviceTypeChanged\0"
    "selectFile\0QAction*\0requestFileList\0"
    "processFileList"
};
#undef QT_MOC_LITERAL

static const uint qt_meta_data_ProvisioningEditor[] = {

 // content:
       7,       // revision
       0,       // classname
       0,    0, // classinfo
       8,   14, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       0,       // signalCount

 // slots: name, argc, parameters, tag, flags
       1,    0,   54,    2, 0x08 /* Private */,
       3,    1,   55,    2, 0x08 /* Private */,
       3,    0,   58,    2, 0x28 /* Private | MethodCloned */,
       5,    0,   59,    2, 0x08 /* Private */,
       6,    1,   60,    2, 0x08 /* Private */,
       7,    1,   63,    2, 0x08 /* Private */,
       9,    0,   66,    2, 0x08 /* Private */,
      10,    1,   67,    2, 0x08 /* Private */,

 // slots: parameters
    QMetaType::Void,
    QMetaType::Void, QMetaType::Int,    4,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void, QMetaType::QString,    2,
    QMetaType::Void, 0x80000000 | 8,    2,
    QMetaType::Void,
    QMetaType::Void, QMetaType::QStringList,    2,

       0        // eod
};

void ProvisioningEditor::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::InvokeMetaMethod) {
        ProvisioningEditor *_t = static_cast<ProvisioningEditor *>(_o);
        switch (_id) {
        case 0: _t->showWhatsThis(); break;
        case 1: _t->resetPage((*reinterpret_cast< int(*)>(_a[1]))); break;
        case 2: _t->resetPage(); break;
        case 3: _t->resetAll(); break;
        case 4: _t->serviceTypeChanged((*reinterpret_cast< const QString(*)>(_a[1]))); break;
        case 5: _t->selectFile((*reinterpret_cast< QAction*(*)>(_a[1]))); break;
        case 6: _t->requestFileList(); break;
        case 7: _t->processFileList((*reinterpret_cast< const QStringList(*)>(_a[1]))); break;
        default: ;
        }
    } else if (_c == QMetaObject::RegisterMethodArgumentMetaType) {
        switch (_id) {
        default: *reinterpret_cast<int*>(_a[0]) = -1; break;
        case 5:
            switch (*reinterpret_cast<int*>(_a[1])) {
            default: *reinterpret_cast<int*>(_a[0]) = -1; break;
            case 0:
                *reinterpret_cast<int*>(_a[0]) = qRegisterMetaType< QAction* >(); break;
            }
            break;
        }
    }
}

const QMetaObject ProvisioningEditor::staticMetaObject = {
    { &QDialog::staticMetaObject, qt_meta_stringdata_ProvisioningEditor.data,
      qt_meta_data_ProvisioningEditor,  qt_static_metacall, 0, 0}
};


const QMetaObject *ProvisioningEditor::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->dynamicMetaObject() : &staticMetaObject;
}

void *ProvisioningEditor::qt_metacast(const char *_clname)
{
    if (!_clname) return 0;
    if (!strcmp(_clname, qt_meta_stringdata_ProvisioningEditor.stringdata))
        return static_cast<void*>(const_cast< ProvisioningEditor*>(this));
    return QDialog::qt_metacast(_clname);
}

int ProvisioningEditor::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = QDialog::qt_metacall(_c, _id, _a);
    if (_id < 0)
        return _id;
    if (_c == QMetaObject::InvokeMetaMethod) {
        if (_id < 8)
            qt_static_metacall(this, _c, _id, _a);
        _id -= 8;
    } else if (_c == QMetaObject::RegisterMethodArgumentMetaType) {
        if (_id < 8)
            qt_static_metacall(this, _c, _id, _a);
        _id -= 8;
    }
    return _id;
}
QT_END_MOC_NAMESPACE
