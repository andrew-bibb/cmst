/****************************************************************************
** Meta object code from reading C++ file 'controlbox.h'
**
** Created by: The Qt Meta Object Compiler version 67 (Qt 5.3.2)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include "../control_box/controlbox.h"
#include <QtCore/qbytearray.h>
#include <QtCore/qmetatype.h>
#include <QtCore/QList>
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'controlbox.h' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 67
#error "This file was generated using the moc from 5.3.2. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

QT_BEGIN_MOC_NAMESPACE
struct qt_meta_stringdata_idButton_t {
    QByteArrayData data[4];
    char stringdata[34];
};
#define QT_MOC_LITERAL(idx, ofs, len) \
    Q_STATIC_BYTE_ARRAY_DATA_HEADER_INITIALIZER_WITH_OFFSET(len, \
    qptrdiff(offsetof(qt_meta_stringdata_idButton_t, stringdata) + ofs \
        - idx * sizeof(QByteArrayData)) \
    )
static const qt_meta_stringdata_idButton_t qt_meta_stringdata_idButton = {
    {
QT_MOC_LITERAL(0, 0, 8),
QT_MOC_LITERAL(1, 9, 9),
QT_MOC_LITERAL(2, 19, 0),
QT_MOC_LITERAL(3, 20, 13)
    },
    "idButton\0clickedID\0\0buttonClicked"
};
#undef QT_MOC_LITERAL

static const uint qt_meta_data_idButton[] = {

 // content:
       7,       // revision
       0,       // classname
       0,    0, // classinfo
       2,   14, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       1,       // signalCount

 // signals: name, argc, parameters, tag, flags
       1,    2,   24,    2, 0x06 /* Public */,

 // slots: name, argc, parameters, tag, flags
       3,    1,   29,    2, 0x08 /* Private */,

 // signals: parameters
    QMetaType::Void, QMetaType::QString, QMetaType::Bool,    2,    2,

 // slots: parameters
    QMetaType::Void, QMetaType::Bool,    2,

       0        // eod
};

void idButton::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::InvokeMetaMethod) {
        idButton *_t = static_cast<idButton *>(_o);
        switch (_id) {
        case 0: _t->clickedID((*reinterpret_cast< QString(*)>(_a[1])),(*reinterpret_cast< bool(*)>(_a[2]))); break;
        case 1: _t->buttonClicked((*reinterpret_cast< bool(*)>(_a[1]))); break;
        default: ;
        }
    } else if (_c == QMetaObject::IndexOfMethod) {
        int *result = reinterpret_cast<int *>(_a[0]);
        void **func = reinterpret_cast<void **>(_a[1]);
        {
            typedef void (idButton::*_t)(QString , bool );
            if (*reinterpret_cast<_t *>(func) == static_cast<_t>(&idButton::clickedID)) {
                *result = 0;
            }
        }
    }
}

const QMetaObject idButton::staticMetaObject = {
    { &QFrame::staticMetaObject, qt_meta_stringdata_idButton.data,
      qt_meta_data_idButton,  qt_static_metacall, 0, 0}
};


const QMetaObject *idButton::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->dynamicMetaObject() : &staticMetaObject;
}

void *idButton::qt_metacast(const char *_clname)
{
    if (!_clname) return 0;
    if (!strcmp(_clname, qt_meta_stringdata_idButton.stringdata))
        return static_cast<void*>(const_cast< idButton*>(this));
    return QFrame::qt_metacast(_clname);
}

int idButton::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = QFrame::qt_metacall(_c, _id, _a);
    if (_id < 0)
        return _id;
    if (_c == QMetaObject::InvokeMetaMethod) {
        if (_id < 2)
            qt_static_metacall(this, _c, _id, _a);
        _id -= 2;
    } else if (_c == QMetaObject::RegisterMethodArgumentMetaType) {
        if (_id < 2)
            *reinterpret_cast<int*>(_a[0]) = -1;
        _id -= 2;
    }
    return _id;
}

// SIGNAL 0
void idButton::clickedID(QString _t1, bool _t2)
{
    void *_a[] = { 0, const_cast<void*>(reinterpret_cast<const void*>(&_t1)), const_cast<void*>(reinterpret_cast<const void*>(&_t2)) };
    QMetaObject::activate(this, &staticMetaObject, 0, _a);
}
struct qt_meta_stringdata_SignalBar_t {
    QByteArrayData data[1];
    char stringdata[10];
};
#define QT_MOC_LITERAL(idx, ofs, len) \
    Q_STATIC_BYTE_ARRAY_DATA_HEADER_INITIALIZER_WITH_OFFSET(len, \
    qptrdiff(offsetof(qt_meta_stringdata_SignalBar_t, stringdata) + ofs \
        - idx * sizeof(QByteArrayData)) \
    )
static const qt_meta_stringdata_SignalBar_t qt_meta_stringdata_SignalBar = {
    {
QT_MOC_LITERAL(0, 0, 9)
    },
    "SignalBar"
};
#undef QT_MOC_LITERAL

static const uint qt_meta_data_SignalBar[] = {

 // content:
       7,       // revision
       0,       // classname
       0,    0, // classinfo
       0,    0, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       0,       // signalCount

       0        // eod
};

void SignalBar::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    Q_UNUSED(_o);
    Q_UNUSED(_id);
    Q_UNUSED(_c);
    Q_UNUSED(_a);
}

const QMetaObject SignalBar::staticMetaObject = {
    { &QFrame::staticMetaObject, qt_meta_stringdata_SignalBar.data,
      qt_meta_data_SignalBar,  qt_static_metacall, 0, 0}
};


const QMetaObject *SignalBar::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->dynamicMetaObject() : &staticMetaObject;
}

void *SignalBar::qt_metacast(const char *_clname)
{
    if (!_clname) return 0;
    if (!strcmp(_clname, qt_meta_stringdata_SignalBar.stringdata))
        return static_cast<void*>(const_cast< SignalBar*>(this));
    return QFrame::qt_metacast(_clname);
}

int SignalBar::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = QFrame::qt_metacall(_c, _id, _a);
    if (_id < 0)
        return _id;
    return _id;
}
struct qt_meta_stringdata_ControlBox_t {
    QByteArrayData data[47];
    char stringdata[778];
};
#define QT_MOC_LITERAL(idx, ofs, len) \
    Q_STATIC_BYTE_ARRAY_DATA_HEADER_INITIALIZER_WITH_OFFSET(len, \
    qptrdiff(offsetof(qt_meta_stringdata_ControlBox_t, stringdata) + ofs \
        - idx * sizeof(QByteArrayData)) \
    )
static const qt_meta_stringdata_ControlBox_t qt_meta_stringdata_ControlBox = {
    {
QT_MOC_LITERAL(0, 0, 10),
QT_MOC_LITERAL(1, 11, 9),
QT_MOC_LITERAL(2, 21, 0),
QT_MOC_LITERAL(3, 22, 12),
QT_MOC_LITERAL(4, 35, 11),
QT_MOC_LITERAL(5, 47, 13),
QT_MOC_LITERAL(6, 61, 20),
QT_MOC_LITERAL(7, 82, 11),
QT_MOC_LITERAL(8, 94, 8),
QT_MOC_LITERAL(9, 103, 17),
QT_MOC_LITERAL(10, 121, 17),
QT_MOC_LITERAL(11, 139, 14),
QT_MOC_LITERAL(12, 154, 15),
QT_MOC_LITERAL(13, 170, 14),
QT_MOC_LITERAL(14, 185, 17),
QT_MOC_LITERAL(15, 203, 13),
QT_MOC_LITERAL(16, 217, 18),
QT_MOC_LITERAL(17, 236, 12),
QT_MOC_LITERAL(18, 249, 18),
QT_MOC_LITERAL(19, 268, 22),
QT_MOC_LITERAL(20, 291, 12),
QT_MOC_LITERAL(21, 304, 15),
QT_MOC_LITERAL(22, 320, 25),
QT_MOC_LITERAL(23, 346, 28),
QT_MOC_LITERAL(24, 375, 18),
QT_MOC_LITERAL(25, 394, 20),
QT_MOC_LITERAL(26, 415, 16),
QT_MOC_LITERAL(27, 432, 17),
QT_MOC_LITERAL(28, 450, 14),
QT_MOC_LITERAL(29, 465, 13),
QT_MOC_LITERAL(30, 479, 12),
QT_MOC_LITERAL(31, 492, 17),
QT_MOC_LITERAL(32, 510, 13),
QT_MOC_LITERAL(33, 524, 24),
QT_MOC_LITERAL(34, 549, 21),
QT_MOC_LITERAL(35, 571, 17),
QT_MOC_LITERAL(36, 589, 7),
QT_MOC_LITERAL(37, 597, 19),
QT_MOC_LITERAL(38, 617, 13),
QT_MOC_LITERAL(39, 631, 33),
QT_MOC_LITERAL(40, 665, 6),
QT_MOC_LITERAL(41, 672, 13),
QT_MOC_LITERAL(42, 686, 12),
QT_MOC_LITERAL(43, 699, 19),
QT_MOC_LITERAL(44, 719, 16),
QT_MOC_LITERAL(45, 736, 16),
QT_MOC_LITERAL(46, 753, 24)
    },
    "ControlBox\0aboutCMST\0\0aboutIconSet\0"
    "showLicense\0showChangeLog\0"
    "updateDisplayWidgets\0moveService\0"
    "QAction*\0moveButtonPressed\0enableMoveButtons\0"
    "counterUpdated\0QDBusObjectPath\0"
    "connectPressed\0disconnectPressed\0"
    "removePressed\0dbsPropertyChanged\0"
    "QDBusVariant\0dbsServicesChanged\0"
    "QList<QDBusObjectPath>\0QDBusMessage\0"
    "dbsPeersChanged\0dbsServicePropertyChanged\0"
    "dbsTechnologyPropertyChanged\0"
    "dbsTechnologyAdded\0dbsTechnologyRemoved\0"
    "scanTechnologies\0toggleOfflineMode\0"
    "toggleTrayIcon\0togglePowered\0minMaxWindow\0"
    "getServiceDetails\0showWhatsThis\0"
    "startSystemTrayMinimized\0startSystemTrayNormal\0"
    "trayNotifications\0checked\0daemonNotifications\0"
    "iconActivated\0QSystemTrayIcon::ActivationReason\0"
    "reason\0writeSettings\0readSettings\0"
    "connectNotifyClient\0configureService\0"
    "provisionService\0socketConnectionDetected"
};
#undef QT_MOC_LITERAL

static const uint qt_meta_data_ControlBox[] = {

 // content:
       7,       // revision
       0,       // classname
       0,    0, // classinfo
      38,   14, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       0,       // signalCount

 // slots: name, argc, parameters, tag, flags
       1,    0,  204,    2, 0x0a /* Public */,
       3,    0,  205,    2, 0x0a /* Public */,
       4,    0,  206,    2, 0x0a /* Public */,
       5,    0,  207,    2, 0x0a /* Public */,
       6,    0,  208,    2, 0x08 /* Private */,
       7,    1,  209,    2, 0x08 /* Private */,
       9,    1,  212,    2, 0x08 /* Private */,
      10,    2,  215,    2, 0x08 /* Private */,
      11,    3,  220,    2, 0x08 /* Private */,
      13,    0,  227,    2, 0x08 /* Private */,
      14,    0,  228,    2, 0x08 /* Private */,
      15,    0,  229,    2, 0x08 /* Private */,
      16,    2,  230,    2, 0x08 /* Private */,
      18,    3,  235,    2, 0x08 /* Private */,
      21,    3,  242,    2, 0x08 /* Private */,
      22,    3,  249,    2, 0x08 /* Private */,
      23,    3,  256,    2, 0x08 /* Private */,
      24,    2,  263,    2, 0x08 /* Private */,
      25,    1,  268,    2, 0x08 /* Private */,
      26,    0,  271,    2, 0x08 /* Private */,
      27,    1,  272,    2, 0x08 /* Private */,
      28,    1,  275,    2, 0x08 /* Private */,
      29,    2,  278,    2, 0x08 /* Private */,
      30,    1,  283,    2, 0x08 /* Private */,
      30,    0,  286,    2, 0x28 /* Private | MethodCloned */,
      31,    1,  287,    2, 0x08 /* Private */,
      32,    0,  290,    2, 0x08 /* Private */,
      33,    0,  291,    2, 0x08 /* Private */,
      34,    0,  292,    2, 0x08 /* Private */,
      35,    1,  293,    2, 0x08 /* Private */,
      37,    1,  296,    2, 0x08 /* Private */,
      38,    1,  299,    2, 0x08 /* Private */,
      41,    0,  302,    2, 0x08 /* Private */,
      42,    0,  303,    2, 0x08 /* Private */,
      43,    0,  304,    2, 0x08 /* Private */,
      44,    0,  305,    2, 0x08 /* Private */,
      45,    0,  306,    2, 0x08 /* Private */,
      46,    0,  307,    2, 0x08 /* Private */,

 // slots: parameters
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void, 0x80000000 | 8,    2,
    QMetaType::Void, 0x80000000 | 8,    2,
    QMetaType::Void, QMetaType::Int, QMetaType::Int,    2,    2,
    QMetaType::Void, 0x80000000 | 12, QMetaType::QString, QMetaType::QString,    2,    2,    2,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void, QMetaType::QString, 0x80000000 | 17,    2,    2,
    QMetaType::Void, QMetaType::QVariantMap, 0x80000000 | 19, 0x80000000 | 20,    2,    2,    2,
    QMetaType::Void, QMetaType::QVariantMap, 0x80000000 | 19, 0x80000000 | 20,    2,    2,    2,
    QMetaType::Void, QMetaType::QString, 0x80000000 | 17, 0x80000000 | 20,    2,    2,    2,
    QMetaType::Void, QMetaType::QString, 0x80000000 | 17, 0x80000000 | 20,    2,    2,    2,
    QMetaType::Void, 0x80000000 | 12, QMetaType::QVariantMap,    2,    2,
    QMetaType::Void, 0x80000000 | 12,    2,
    QMetaType::Void,
    QMetaType::Void, QMetaType::Bool,    2,
    QMetaType::Void, QMetaType::Bool,    2,
    QMetaType::Void, QMetaType::QString, QMetaType::Bool,    2,    2,
    QMetaType::Void, 0x80000000 | 8,    2,
    QMetaType::Void,
    QMetaType::Void, QMetaType::Int,    2,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void, QMetaType::Bool,   36,
    QMetaType::Void, QMetaType::Bool,   36,
    QMetaType::Void, 0x80000000 | 39,   40,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,

       0        // eod
};

void ControlBox::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::InvokeMetaMethod) {
        ControlBox *_t = static_cast<ControlBox *>(_o);
        switch (_id) {
        case 0: _t->aboutCMST(); break;
        case 1: _t->aboutIconSet(); break;
        case 2: _t->showLicense(); break;
        case 3: _t->showChangeLog(); break;
        case 4: _t->updateDisplayWidgets(); break;
        case 5: _t->moveService((*reinterpret_cast< QAction*(*)>(_a[1]))); break;
        case 6: _t->moveButtonPressed((*reinterpret_cast< QAction*(*)>(_a[1]))); break;
        case 7: _t->enableMoveButtons((*reinterpret_cast< int(*)>(_a[1])),(*reinterpret_cast< int(*)>(_a[2]))); break;
        case 8: _t->counterUpdated((*reinterpret_cast< const QDBusObjectPath(*)>(_a[1])),(*reinterpret_cast< const QString(*)>(_a[2])),(*reinterpret_cast< const QString(*)>(_a[3]))); break;
        case 9: _t->connectPressed(); break;
        case 10: _t->disconnectPressed(); break;
        case 11: _t->removePressed(); break;
        case 12: _t->dbsPropertyChanged((*reinterpret_cast< QString(*)>(_a[1])),(*reinterpret_cast< QDBusVariant(*)>(_a[2]))); break;
        case 13: _t->dbsServicesChanged((*reinterpret_cast< QMap<QString,QVariant>(*)>(_a[1])),(*reinterpret_cast< QList<QDBusObjectPath>(*)>(_a[2])),(*reinterpret_cast< QDBusMessage(*)>(_a[3]))); break;
        case 14: _t->dbsPeersChanged((*reinterpret_cast< QMap<QString,QVariant>(*)>(_a[1])),(*reinterpret_cast< QList<QDBusObjectPath>(*)>(_a[2])),(*reinterpret_cast< QDBusMessage(*)>(_a[3]))); break;
        case 15: _t->dbsServicePropertyChanged((*reinterpret_cast< QString(*)>(_a[1])),(*reinterpret_cast< QDBusVariant(*)>(_a[2])),(*reinterpret_cast< QDBusMessage(*)>(_a[3]))); break;
        case 16: _t->dbsTechnologyPropertyChanged((*reinterpret_cast< QString(*)>(_a[1])),(*reinterpret_cast< QDBusVariant(*)>(_a[2])),(*reinterpret_cast< QDBusMessage(*)>(_a[3]))); break;
        case 17: _t->dbsTechnologyAdded((*reinterpret_cast< QDBusObjectPath(*)>(_a[1])),(*reinterpret_cast< QVariantMap(*)>(_a[2]))); break;
        case 18: _t->dbsTechnologyRemoved((*reinterpret_cast< QDBusObjectPath(*)>(_a[1]))); break;
        case 19: _t->scanTechnologies(); break;
        case 20: _t->toggleOfflineMode((*reinterpret_cast< bool(*)>(_a[1]))); break;
        case 21: _t->toggleTrayIcon((*reinterpret_cast< bool(*)>(_a[1]))); break;
        case 22: _t->togglePowered((*reinterpret_cast< QString(*)>(_a[1])),(*reinterpret_cast< bool(*)>(_a[2]))); break;
        case 23: _t->minMaxWindow((*reinterpret_cast< QAction*(*)>(_a[1]))); break;
        case 24: _t->minMaxWindow(); break;
        case 25: _t->getServiceDetails((*reinterpret_cast< int(*)>(_a[1]))); break;
        case 26: _t->showWhatsThis(); break;
        case 27: _t->startSystemTrayMinimized(); break;
        case 28: _t->startSystemTrayNormal(); break;
        case 29: _t->trayNotifications((*reinterpret_cast< bool(*)>(_a[1]))); break;
        case 30: _t->daemonNotifications((*reinterpret_cast< bool(*)>(_a[1]))); break;
        case 31: _t->iconActivated((*reinterpret_cast< QSystemTrayIcon::ActivationReason(*)>(_a[1]))); break;
        case 32: _t->writeSettings(); break;
        case 33: _t->readSettings(); break;
        case 34: _t->connectNotifyClient(); break;
        case 35: _t->configureService(); break;
        case 36: _t->provisionService(); break;
        case 37: _t->socketConnectionDetected(); break;
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
        case 6:
            switch (*reinterpret_cast<int*>(_a[1])) {
            default: *reinterpret_cast<int*>(_a[0]) = -1; break;
            case 0:
                *reinterpret_cast<int*>(_a[0]) = qRegisterMetaType< QAction* >(); break;
            }
            break;
        case 8:
            switch (*reinterpret_cast<int*>(_a[1])) {
            default: *reinterpret_cast<int*>(_a[0]) = -1; break;
            case 0:
                *reinterpret_cast<int*>(_a[0]) = qRegisterMetaType< QDBusObjectPath >(); break;
            }
            break;
        case 12:
            switch (*reinterpret_cast<int*>(_a[1])) {
            default: *reinterpret_cast<int*>(_a[0]) = -1; break;
            case 1:
                *reinterpret_cast<int*>(_a[0]) = qRegisterMetaType< QDBusVariant >(); break;
            }
            break;
        case 13:
            switch (*reinterpret_cast<int*>(_a[1])) {
            default: *reinterpret_cast<int*>(_a[0]) = -1; break;
            case 2:
                *reinterpret_cast<int*>(_a[0]) = qRegisterMetaType< QDBusMessage >(); break;
            case 1:
                *reinterpret_cast<int*>(_a[0]) = qRegisterMetaType< QList<QDBusObjectPath> >(); break;
            }
            break;
        case 14:
            switch (*reinterpret_cast<int*>(_a[1])) {
            default: *reinterpret_cast<int*>(_a[0]) = -1; break;
            case 2:
                *reinterpret_cast<int*>(_a[0]) = qRegisterMetaType< QDBusMessage >(); break;
            case 1:
                *reinterpret_cast<int*>(_a[0]) = qRegisterMetaType< QList<QDBusObjectPath> >(); break;
            }
            break;
        case 15:
            switch (*reinterpret_cast<int*>(_a[1])) {
            default: *reinterpret_cast<int*>(_a[0]) = -1; break;
            case 2:
                *reinterpret_cast<int*>(_a[0]) = qRegisterMetaType< QDBusMessage >(); break;
            case 1:
                *reinterpret_cast<int*>(_a[0]) = qRegisterMetaType< QDBusVariant >(); break;
            }
            break;
        case 16:
            switch (*reinterpret_cast<int*>(_a[1])) {
            default: *reinterpret_cast<int*>(_a[0]) = -1; break;
            case 2:
                *reinterpret_cast<int*>(_a[0]) = qRegisterMetaType< QDBusMessage >(); break;
            case 1:
                *reinterpret_cast<int*>(_a[0]) = qRegisterMetaType< QDBusVariant >(); break;
            }
            break;
        case 17:
            switch (*reinterpret_cast<int*>(_a[1])) {
            default: *reinterpret_cast<int*>(_a[0]) = -1; break;
            case 0:
                *reinterpret_cast<int*>(_a[0]) = qRegisterMetaType< QDBusObjectPath >(); break;
            }
            break;
        case 18:
            switch (*reinterpret_cast<int*>(_a[1])) {
            default: *reinterpret_cast<int*>(_a[0]) = -1; break;
            case 0:
                *reinterpret_cast<int*>(_a[0]) = qRegisterMetaType< QDBusObjectPath >(); break;
            }
            break;
        case 23:
            switch (*reinterpret_cast<int*>(_a[1])) {
            default: *reinterpret_cast<int*>(_a[0]) = -1; break;
            case 0:
                *reinterpret_cast<int*>(_a[0]) = qRegisterMetaType< QAction* >(); break;
            }
            break;
        }
    }
}

const QMetaObject ControlBox::staticMetaObject = {
    { &QDialog::staticMetaObject, qt_meta_stringdata_ControlBox.data,
      qt_meta_data_ControlBox,  qt_static_metacall, 0, 0}
};


const QMetaObject *ControlBox::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->dynamicMetaObject() : &staticMetaObject;
}

void *ControlBox::qt_metacast(const char *_clname)
{
    if (!_clname) return 0;
    if (!strcmp(_clname, qt_meta_stringdata_ControlBox.stringdata))
        return static_cast<void*>(const_cast< ControlBox*>(this));
    return QDialog::qt_metacast(_clname);
}

int ControlBox::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = QDialog::qt_metacall(_c, _id, _a);
    if (_id < 0)
        return _id;
    if (_c == QMetaObject::InvokeMetaMethod) {
        if (_id < 38)
            qt_static_metacall(this, _c, _id, _a);
        _id -= 38;
    } else if (_c == QMetaObject::RegisterMethodArgumentMetaType) {
        if (_id < 38)
            qt_static_metacall(this, _c, _id, _a);
        _id -= 38;
    }
    return _id;
}
QT_END_MOC_NAMESPACE
