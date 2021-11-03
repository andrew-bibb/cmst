/****************************************************************************
** Meta object code from reading C++ file 'gen_conf_ed.h'
**
** Created by: The Qt Meta Object Compiler version 67 (Qt 5.15.2)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include <memory>
#include "../code/gen_conf_ed/gen_conf_ed.h"
#include <QtCore/qbytearray.h>
#include <QtCore/qmetatype.h>
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'gen_conf_ed.h' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 67
#error "This file was generated using the moc from 5.15.2. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

QT_BEGIN_MOC_NAMESPACE
QT_WARNING_PUSH
QT_WARNING_DISABLE_DEPRECATED
struct qt_meta_stringdata_GEN_Editor_t {
    QByteArrayData data[12];
    char stringdata0[147];
};
#define QT_MOC_LITERAL(idx, ofs, len) \
    Q_STATIC_BYTE_ARRAY_DATA_HEADER_INITIALIZER_WITH_OFFSET(len, \
    qptrdiff(offsetof(qt_meta_stringdata_GEN_Editor_t, stringdata0) + ofs \
        - idx * sizeof(QByteArrayData)) \
    )
static const qt_meta_stringdata_GEN_Editor_t qt_meta_stringdata_GEN_Editor = {
    {
QT_MOC_LITERAL(0, 0, 10), // "GEN_Editor"
QT_MOC_LITERAL(1, 11, 13), // "readCompleted"
QT_MOC_LITERAL(2, 25, 0), // ""
QT_MOC_LITERAL(3, 26, 8), // "finished"
QT_MOC_LITERAL(4, 35, 8), // "exitcode"
QT_MOC_LITERAL(5, 44, 13), // "storeContents"
QT_MOC_LITERAL(6, 58, 14), // "executeProcess"
QT_MOC_LITERAL(7, 73, 15), // "processExitCode"
QT_MOC_LITERAL(8, 89, 10), // "editBuffer"
QT_MOC_LITERAL(9, 100, 14), // "writeCompleted"
QT_MOC_LITERAL(10, 115, 20), // "callbackErrorHandler"
QT_MOC_LITERAL(11, 136, 10) // "QDBusError"

    },
    "GEN_Editor\0readCompleted\0\0finished\0"
    "exitcode\0storeContents\0executeProcess\0"
    "processExitCode\0editBuffer\0writeCompleted\0"
    "callbackErrorHandler\0QDBusError"
};
#undef QT_MOC_LITERAL

static const uint qt_meta_data_GEN_Editor[] = {

 // content:
       8,       // revision
       0,       // classname
       0,    0, // classinfo
       9,   14, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       3,       // signalCount

 // signals: name, argc, parameters, tag, flags
       1,    0,   59,    2, 0x06 /* Public */,
       3,    1,   60,    2, 0x06 /* Public */,
       3,    0,   63,    2, 0x26 /* Public | MethodCloned */,

 // slots: name, argc, parameters, tag, flags
       5,    1,   64,    2, 0x08 /* Private */,
       6,    0,   67,    2, 0x08 /* Private */,
       7,    1,   68,    2, 0x08 /* Private */,
       8,    0,   71,    2, 0x08 /* Private */,
       9,    1,   72,    2, 0x08 /* Private */,
      10,    1,   75,    2, 0x08 /* Private */,

 // signals: parameters
    QMetaType::Void,
    QMetaType::Void, QMetaType::Int,    4,
    QMetaType::Void,

 // slots: parameters
    QMetaType::Void, QMetaType::QString,    2,
    QMetaType::Void,
    QMetaType::Void, QMetaType::Int,    2,
    QMetaType::Void,
    QMetaType::Void, QMetaType::LongLong,    2,
    QMetaType::Void, 0x80000000 | 11,    2,

       0        // eod
};

void GEN_Editor::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::InvokeMetaMethod) {
        auto *_t = static_cast<GEN_Editor *>(_o);
        (void)_t;
        switch (_id) {
        case 0: _t->readCompleted(); break;
        case 1: _t->finished((*reinterpret_cast< int(*)>(_a[1]))); break;
        case 2: _t->finished(); break;
        case 3: _t->storeContents((*reinterpret_cast< const QString(*)>(_a[1]))); break;
        case 4: _t->executeProcess(); break;
        case 5: _t->processExitCode((*reinterpret_cast< int(*)>(_a[1]))); break;
        case 6: _t->editBuffer(); break;
        case 7: _t->writeCompleted((*reinterpret_cast< qint64(*)>(_a[1]))); break;
        case 8: _t->callbackErrorHandler((*reinterpret_cast< QDBusError(*)>(_a[1]))); break;
        default: ;
        }
    } else if (_c == QMetaObject::RegisterMethodArgumentMetaType) {
        switch (_id) {
        default: *reinterpret_cast<int*>(_a[0]) = -1; break;
        case 8:
            switch (*reinterpret_cast<int*>(_a[1])) {
            default: *reinterpret_cast<int*>(_a[0]) = -1; break;
            case 0:
                *reinterpret_cast<int*>(_a[0]) = qRegisterMetaType< QDBusError >(); break;
            }
            break;
        }
    } else if (_c == QMetaObject::IndexOfMethod) {
        int *result = reinterpret_cast<int *>(_a[0]);
        {
            using _t = void (GEN_Editor::*)();
            if (*reinterpret_cast<_t *>(_a[1]) == static_cast<_t>(&GEN_Editor::readCompleted)) {
                *result = 0;
                return;
            }
        }
        {
            using _t = void (GEN_Editor::*)(int );
            if (*reinterpret_cast<_t *>(_a[1]) == static_cast<_t>(&GEN_Editor::finished)) {
                *result = 1;
                return;
            }
        }
    }
}

QT_INIT_METAOBJECT const QMetaObject GEN_Editor::staticMetaObject = { {
    QMetaObject::SuperData::link<QWidget::staticMetaObject>(),
    qt_meta_stringdata_GEN_Editor.data,
    qt_meta_data_GEN_Editor,
    qt_static_metacall,
    nullptr,
    nullptr
} };


const QMetaObject *GEN_Editor::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->dynamicMetaObject() : &staticMetaObject;
}

void *GEN_Editor::qt_metacast(const char *_clname)
{
    if (!_clname) return nullptr;
    if (!strcmp(_clname, qt_meta_stringdata_GEN_Editor.stringdata0))
        return static_cast<void*>(this);
    return QWidget::qt_metacast(_clname);
}

int GEN_Editor::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = QWidget::qt_metacall(_c, _id, _a);
    if (_id < 0)
        return _id;
    if (_c == QMetaObject::InvokeMetaMethod) {
        if (_id < 9)
            qt_static_metacall(this, _c, _id, _a);
        _id -= 9;
    } else if (_c == QMetaObject::RegisterMethodArgumentMetaType) {
        if (_id < 9)
            qt_static_metacall(this, _c, _id, _a);
        _id -= 9;
    }
    return _id;
}

// SIGNAL 0
void GEN_Editor::readCompleted()
{
    QMetaObject::activate(this, &staticMetaObject, 0, nullptr);
}

// SIGNAL 1
void GEN_Editor::finished(int _t1)
{
    void *_a[] = { nullptr, const_cast<void*>(reinterpret_cast<const void*>(std::addressof(_t1))) };
    QMetaObject::activate(this, &staticMetaObject, 1, _a);
}
QT_WARNING_POP
QT_END_MOC_NAMESPACE
