/****************************************************************************
** Meta object code from reading C++ file 'controlbox.h'
**
** Created by: The Qt Meta Object Compiler version 67 (Qt 5.15.2)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include <memory>
#include "../code/control_box/controlbox.h"
#include <QtCore/qbytearray.h>
#include <QtCore/qmetatype.h>
#include <QtCore/QList>
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'controlbox.h' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 67
#error "This file was generated using the moc from 5.15.2. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

QT_BEGIN_MOC_NAMESPACE
QT_WARNING_PUSH
QT_WARNING_DISABLE_DEPRECATED
struct qt_meta_stringdata_idButton_t {
    QByteArrayData data[4];
    char stringdata0[34];
};
#define QT_MOC_LITERAL(idx, ofs, len) \
    Q_STATIC_BYTE_ARRAY_DATA_HEADER_INITIALIZER_WITH_OFFSET(len, \
    qptrdiff(offsetof(qt_meta_stringdata_idButton_t, stringdata0) + ofs \
        - idx * sizeof(QByteArrayData)) \
    )
static const qt_meta_stringdata_idButton_t qt_meta_stringdata_idButton = {
    {
QT_MOC_LITERAL(0, 0, 8), // "idButton"
QT_MOC_LITERAL(1, 9, 9), // "clickedID"
QT_MOC_LITERAL(2, 19, 0), // ""
QT_MOC_LITERAL(3, 20, 13) // "buttonClicked"

    },
    "idButton\0clickedID\0\0buttonClicked"
};
#undef QT_MOC_LITERAL

static const uint qt_meta_data_idButton[] = {

 // content:
       8,       // revision
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
        auto *_t = static_cast<idButton *>(_o);
        (void)_t;
        switch (_id) {
        case 0: _t->clickedID((*reinterpret_cast< QString(*)>(_a[1])),(*reinterpret_cast< bool(*)>(_a[2]))); break;
        case 1: _t->buttonClicked((*reinterpret_cast< bool(*)>(_a[1]))); break;
        default: ;
        }
    } else if (_c == QMetaObject::IndexOfMethod) {
        int *result = reinterpret_cast<int *>(_a[0]);
        {
            using _t = void (idButton::*)(QString , bool );
            if (*reinterpret_cast<_t *>(_a[1]) == static_cast<_t>(&idButton::clickedID)) {
                *result = 0;
                return;
            }
        }
    }
}

QT_INIT_METAOBJECT const QMetaObject idButton::staticMetaObject = { {
    QMetaObject::SuperData::link<QFrame::staticMetaObject>(),
    qt_meta_stringdata_idButton.data,
    qt_meta_data_idButton,
    qt_static_metacall,
    nullptr,
    nullptr
} };


const QMetaObject *idButton::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->dynamicMetaObject() : &staticMetaObject;
}

void *idButton::qt_metacast(const char *_clname)
{
    if (!_clname) return nullptr;
    if (!strcmp(_clname, qt_meta_stringdata_idButton.stringdata0))
        return static_cast<void*>(this);
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
    void *_a[] = { nullptr, const_cast<void*>(reinterpret_cast<const void*>(std::addressof(_t1))), const_cast<void*>(reinterpret_cast<const void*>(std::addressof(_t2))) };
    QMetaObject::activate(this, &staticMetaObject, 0, _a);
}
struct qt_meta_stringdata_ControlBox_t {
    QByteArrayData data[62];
    char stringdata0[1004];
};
#define QT_MOC_LITERAL(idx, ofs, len) \
    Q_STATIC_BYTE_ARRAY_DATA_HEADER_INITIALIZER_WITH_OFFSET(len, \
    qptrdiff(offsetof(qt_meta_stringdata_ControlBox_t, stringdata0) + ofs \
        - idx * sizeof(QByteArrayData)) \
    )
static const qt_meta_stringdata_ControlBox_t qt_meta_stringdata_ControlBox = {
    {
QT_MOC_LITERAL(0, 0, 10), // "ControlBox"
QT_MOC_LITERAL(1, 11, 9), // "aboutCMST"
QT_MOC_LITERAL(2, 21, 0), // ""
QT_MOC_LITERAL(3, 22, 12), // "aboutIconSet"
QT_MOC_LITERAL(4, 35, 13), // "aboutOtherArt"
QT_MOC_LITERAL(5, 49, 11), // "showLicense"
QT_MOC_LITERAL(6, 61, 13), // "showChangeLog"
QT_MOC_LITERAL(7, 75, 20), // "updateDisplayWidgets"
QT_MOC_LITERAL(8, 96, 11), // "moveService"
QT_MOC_LITERAL(9, 108, 8), // "QAction*"
QT_MOC_LITERAL(10, 117, 17), // "moveButtonPressed"
QT_MOC_LITERAL(11, 135, 17), // "enableMoveButtons"
QT_MOC_LITERAL(12, 153, 14), // "counterUpdated"
QT_MOC_LITERAL(13, 168, 15), // "QDBusObjectPath"
QT_MOC_LITERAL(14, 184, 14), // "connectPressed"
QT_MOC_LITERAL(15, 199, 17), // "requestConnection"
QT_MOC_LITERAL(16, 217, 17), // "disconnectPressed"
QT_MOC_LITERAL(17, 235, 13), // "removePressed"
QT_MOC_LITERAL(18, 249, 18), // "dbsPropertyChanged"
QT_MOC_LITERAL(19, 268, 12), // "QDBusVariant"
QT_MOC_LITERAL(20, 281, 18), // "dbsServicesChanged"
QT_MOC_LITERAL(21, 300, 22), // "QList<QDBusObjectPath>"
QT_MOC_LITERAL(22, 323, 12), // "QDBusMessage"
QT_MOC_LITERAL(23, 336, 15), // "dbsPeersChanged"
QT_MOC_LITERAL(24, 352, 25), // "dbsServicePropertyChanged"
QT_MOC_LITERAL(25, 378, 28), // "dbsTechnologyPropertyChanged"
QT_MOC_LITERAL(26, 407, 18), // "dbsTechnologyAdded"
QT_MOC_LITERAL(27, 426, 20), // "dbsTechnologyRemoved"
QT_MOC_LITERAL(28, 447, 8), // "scanWiFi"
QT_MOC_LITERAL(29, 456, 10), // "wifiIDPass"
QT_MOC_LITERAL(30, 467, 8), // "obj_path"
QT_MOC_LITERAL(31, 476, 17), // "toggleOfflineMode"
QT_MOC_LITERAL(32, 494, 14), // "toggleTrayIcon"
QT_MOC_LITERAL(33, 509, 13), // "togglePowered"
QT_MOC_LITERAL(34, 523, 14), // "toggleTethered"
QT_MOC_LITERAL(35, 538, 12), // "minMaxWindow"
QT_MOC_LITERAL(36, 551, 20), // "techSubmenuTriggered"
QT_MOC_LITERAL(37, 572, 20), // "infoSubmenuTriggered"
QT_MOC_LITERAL(38, 593, 20), // "wifiSubmenuTriggered"
QT_MOC_LITERAL(39, 614, 19), // "vpnSubmenuTriggered"
QT_MOC_LITERAL(40, 634, 17), // "getServiceDetails"
QT_MOC_LITERAL(41, 652, 13), // "showWhatsThis"
QT_MOC_LITERAL(42, 666, 17), // "trayNotifications"
QT_MOC_LITERAL(43, 684, 7), // "checked"
QT_MOC_LITERAL(44, 692, 19), // "daemonNotifications"
QT_MOC_LITERAL(45, 712, 26), // "closeSystemTrayTearOffMenu"
QT_MOC_LITERAL(46, 739, 13), // "iconActivated"
QT_MOC_LITERAL(47, 753, 33), // "QSystemTrayIcon::ActivationRe..."
QT_MOC_LITERAL(48, 787, 6), // "reason"
QT_MOC_LITERAL(49, 794, 18), // "enableRunOnStartup"
QT_MOC_LITERAL(50, 813, 7), // "enabled"
QT_MOC_LITERAL(51, 821, 13), // "writeSettings"
QT_MOC_LITERAL(52, 835, 12), // "readSettings"
QT_MOC_LITERAL(53, 848, 20), // "createSystemTrayIcon"
QT_MOC_LITERAL(54, 869, 19), // "connectNotifyClient"
QT_MOC_LITERAL(55, 889, 16), // "configureService"
QT_MOC_LITERAL(56, 906, 16), // "provisionService"
QT_MOC_LITERAL(57, 923, 24), // "socketConnectionDetected"
QT_MOC_LITERAL(58, 948, 7), // "cleanUp"
QT_MOC_LITERAL(59, 956, 15), // "callColorDialog"
QT_MOC_LITERAL(60, 972, 16), // "iconColorChanged"
QT_MOC_LITERAL(61, 989, 14) // "setStateRescan"

    },
    "ControlBox\0aboutCMST\0\0aboutIconSet\0"
    "aboutOtherArt\0showLicense\0showChangeLog\0"
    "updateDisplayWidgets\0moveService\0"
    "QAction*\0moveButtonPressed\0enableMoveButtons\0"
    "counterUpdated\0QDBusObjectPath\0"
    "connectPressed\0requestConnection\0"
    "disconnectPressed\0removePressed\0"
    "dbsPropertyChanged\0QDBusVariant\0"
    "dbsServicesChanged\0QList<QDBusObjectPath>\0"
    "QDBusMessage\0dbsPeersChanged\0"
    "dbsServicePropertyChanged\0"
    "dbsTechnologyPropertyChanged\0"
    "dbsTechnologyAdded\0dbsTechnologyRemoved\0"
    "scanWiFi\0wifiIDPass\0obj_path\0"
    "toggleOfflineMode\0toggleTrayIcon\0"
    "togglePowered\0toggleTethered\0minMaxWindow\0"
    "techSubmenuTriggered\0infoSubmenuTriggered\0"
    "wifiSubmenuTriggered\0vpnSubmenuTriggered\0"
    "getServiceDetails\0showWhatsThis\0"
    "trayNotifications\0checked\0daemonNotifications\0"
    "closeSystemTrayTearOffMenu\0iconActivated\0"
    "QSystemTrayIcon::ActivationReason\0"
    "reason\0enableRunOnStartup\0enabled\0"
    "writeSettings\0readSettings\0"
    "createSystemTrayIcon\0connectNotifyClient\0"
    "configureService\0provisionService\0"
    "socketConnectionDetected\0cleanUp\0"
    "callColorDialog\0iconColorChanged\0"
    "setStateRescan"
};
#undef QT_MOC_LITERAL

static const uint qt_meta_data_ControlBox[] = {

 // content:
       8,       // revision
       0,       // classname
       0,    0, // classinfo
      56,   14, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       0,       // signalCount

 // slots: name, argc, parameters, tag, flags
       1,    0,  294,    2, 0x0a /* Public */,
       3,    0,  295,    2, 0x0a /* Public */,
       4,    0,  296,    2, 0x0a /* Public */,
       5,    0,  297,    2, 0x0a /* Public */,
       6,    0,  298,    2, 0x0a /* Public */,
       7,    0,  299,    2, 0x08 /* Private */,
       8,    1,  300,    2, 0x08 /* Private */,
      10,    1,  303,    2, 0x08 /* Private */,
      11,    2,  306,    2, 0x08 /* Private */,
      12,    3,  311,    2, 0x08 /* Private */,
      14,    0,  318,    2, 0x08 /* Private */,
      15,    0,  319,    2, 0x08 /* Private */,
      16,    0,  320,    2, 0x08 /* Private */,
      17,    0,  321,    2, 0x08 /* Private */,
      18,    2,  322,    2, 0x08 /* Private */,
      20,    3,  327,    2, 0x08 /* Private */,
      23,    3,  334,    2, 0x08 /* Private */,
      24,    3,  341,    2, 0x08 /* Private */,
      25,    3,  348,    2, 0x08 /* Private */,
      26,    2,  355,    2, 0x08 /* Private */,
      27,    1,  360,    2, 0x08 /* Private */,
      28,    0,  363,    2, 0x08 /* Private */,
      29,    1,  364,    2, 0x08 /* Private */,
      29,    0,  367,    2, 0x28 /* Private | MethodCloned */,
      31,    1,  368,    2, 0x08 /* Private */,
      32,    1,  371,    2, 0x08 /* Private */,
      33,    2,  374,    2, 0x08 /* Private */,
      34,    2,  379,    2, 0x08 /* Private */,
      35,    1,  384,    2, 0x08 /* Private */,
      35,    0,  387,    2, 0x28 /* Private | MethodCloned */,
      36,    1,  388,    2, 0x08 /* Private */,
      36,    0,  391,    2, 0x28 /* Private | MethodCloned */,
      37,    1,  392,    2, 0x08 /* Private */,
      37,    0,  395,    2, 0x28 /* Private | MethodCloned */,
      38,    1,  396,    2, 0x08 /* Private */,
      38,    0,  399,    2, 0x28 /* Private | MethodCloned */,
      39,    1,  400,    2, 0x08 /* Private */,
      39,    0,  403,    2, 0x28 /* Private | MethodCloned */,
      40,    1,  404,    2, 0x08 /* Private */,
      41,    0,  407,    2, 0x08 /* Private */,
      42,    1,  408,    2, 0x08 /* Private */,
      44,    1,  411,    2, 0x08 /* Private */,
      45,    0,  414,    2, 0x08 /* Private */,
      46,    1,  415,    2, 0x08 /* Private */,
      49,    1,  418,    2, 0x08 /* Private */,
      51,    0,  421,    2, 0x08 /* Private */,
      52,    0,  422,    2, 0x08 /* Private */,
      53,    0,  423,    2, 0x08 /* Private */,
      54,    0,  424,    2, 0x08 /* Private */,
      55,    0,  425,    2, 0x08 /* Private */,
      56,    0,  426,    2, 0x08 /* Private */,
      57,    0,  427,    2, 0x08 /* Private */,
      58,    0,  428,    2, 0x08 /* Private */,
      59,    0,  429,    2, 0x08 /* Private */,
      60,    1,  430,    2, 0x08 /* Private */,
      61,    1,  433,    2, 0x08 /* Private */,

 // slots: parameters
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void, 0x80000000 | 9,    2,
    QMetaType::Void, 0x80000000 | 9,    2,
    QMetaType::Void, QMetaType::Int, QMetaType::Int,    2,    2,
    QMetaType::Void, 0x80000000 | 13, QMetaType::QString, QMetaType::QString,    2,    2,    2,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void, QMetaType::QString, 0x80000000 | 19,    2,    2,
    QMetaType::Void, QMetaType::QVariantList, 0x80000000 | 21, 0x80000000 | 22,    2,    2,    2,
    QMetaType::Void, QMetaType::QVariantList, 0x80000000 | 21, 0x80000000 | 22,    2,    2,    2,
    QMetaType::Void, QMetaType::QString, 0x80000000 | 19, 0x80000000 | 22,    2,    2,    2,
    QMetaType::Void, QMetaType::QString, 0x80000000 | 19, 0x80000000 | 22,    2,    2,    2,
    QMetaType::Void, 0x80000000 | 13, QMetaType::QVariantMap,    2,    2,
    QMetaType::Void, 0x80000000 | 13,    2,
    QMetaType::Void,
    QMetaType::Void, QMetaType::QString,   30,
    QMetaType::Void,
    QMetaType::Void, QMetaType::Bool,    2,
    QMetaType::Void, QMetaType::Bool,    2,
    QMetaType::Void, QMetaType::QString, QMetaType::Bool,    2,    2,
    QMetaType::Void, QMetaType::QString, QMetaType::Bool,    2,    2,
    QMetaType::Void, 0x80000000 | 9,    2,
    QMetaType::Void,
    QMetaType::Void, 0x80000000 | 9,    2,
    QMetaType::Void,
    QMetaType::Void, 0x80000000 | 9,    2,
    QMetaType::Void,
    QMetaType::Void, 0x80000000 | 9,    2,
    QMetaType::Void,
    QMetaType::Void, 0x80000000 | 9,    2,
    QMetaType::Void,
    QMetaType::Void, QMetaType::Int,    2,
    QMetaType::Void,
    QMetaType::Void, QMetaType::Bool,   43,
    QMetaType::Void, QMetaType::Bool,   43,
    QMetaType::Void,
    QMetaType::Void, 0x80000000 | 47,   48,
    QMetaType::Void, QMetaType::Bool,   50,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void, QMetaType::QString,    2,
    QMetaType::Void, QMetaType::Bool,    2,

       0        // eod
};

void ControlBox::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::InvokeMetaMethod) {
        auto *_t = static_cast<ControlBox *>(_o);
        (void)_t;
        switch (_id) {
        case 0: _t->aboutCMST(); break;
        case 1: _t->aboutIconSet(); break;
        case 2: _t->aboutOtherArt(); break;
        case 3: _t->showLicense(); break;
        case 4: _t->showChangeLog(); break;
        case 5: _t->updateDisplayWidgets(); break;
        case 6: _t->moveService((*reinterpret_cast< QAction*(*)>(_a[1]))); break;
        case 7: _t->moveButtonPressed((*reinterpret_cast< QAction*(*)>(_a[1]))); break;
        case 8: _t->enableMoveButtons((*reinterpret_cast< int(*)>(_a[1])),(*reinterpret_cast< int(*)>(_a[2]))); break;
        case 9: _t->counterUpdated((*reinterpret_cast< const QDBusObjectPath(*)>(_a[1])),(*reinterpret_cast< const QString(*)>(_a[2])),(*reinterpret_cast< const QString(*)>(_a[3]))); break;
        case 10: _t->connectPressed(); break;
        case 11: _t->requestConnection(); break;
        case 12: _t->disconnectPressed(); break;
        case 13: _t->removePressed(); break;
        case 14: _t->dbsPropertyChanged((*reinterpret_cast< QString(*)>(_a[1])),(*reinterpret_cast< QDBusVariant(*)>(_a[2]))); break;
        case 15: _t->dbsServicesChanged((*reinterpret_cast< QList<QVariant>(*)>(_a[1])),(*reinterpret_cast< QList<QDBusObjectPath>(*)>(_a[2])),(*reinterpret_cast< QDBusMessage(*)>(_a[3]))); break;
        case 16: _t->dbsPeersChanged((*reinterpret_cast< QList<QVariant>(*)>(_a[1])),(*reinterpret_cast< QList<QDBusObjectPath>(*)>(_a[2])),(*reinterpret_cast< QDBusMessage(*)>(_a[3]))); break;
        case 17: _t->dbsServicePropertyChanged((*reinterpret_cast< QString(*)>(_a[1])),(*reinterpret_cast< QDBusVariant(*)>(_a[2])),(*reinterpret_cast< QDBusMessage(*)>(_a[3]))); break;
        case 18: _t->dbsTechnologyPropertyChanged((*reinterpret_cast< QString(*)>(_a[1])),(*reinterpret_cast< QDBusVariant(*)>(_a[2])),(*reinterpret_cast< QDBusMessage(*)>(_a[3]))); break;
        case 19: _t->dbsTechnologyAdded((*reinterpret_cast< QDBusObjectPath(*)>(_a[1])),(*reinterpret_cast< QVariantMap(*)>(_a[2]))); break;
        case 20: _t->dbsTechnologyRemoved((*reinterpret_cast< QDBusObjectPath(*)>(_a[1]))); break;
        case 21: _t->scanWiFi(); break;
        case 22: _t->wifiIDPass((*reinterpret_cast< const QString(*)>(_a[1]))); break;
        case 23: _t->wifiIDPass(); break;
        case 24: _t->toggleOfflineMode((*reinterpret_cast< bool(*)>(_a[1]))); break;
        case 25: _t->toggleTrayIcon((*reinterpret_cast< bool(*)>(_a[1]))); break;
        case 26: _t->togglePowered((*reinterpret_cast< QString(*)>(_a[1])),(*reinterpret_cast< bool(*)>(_a[2]))); break;
        case 27: _t->toggleTethered((*reinterpret_cast< QString(*)>(_a[1])),(*reinterpret_cast< bool(*)>(_a[2]))); break;
        case 28: _t->minMaxWindow((*reinterpret_cast< QAction*(*)>(_a[1]))); break;
        case 29: _t->minMaxWindow(); break;
        case 30: _t->techSubmenuTriggered((*reinterpret_cast< QAction*(*)>(_a[1]))); break;
        case 31: _t->techSubmenuTriggered(); break;
        case 32: _t->infoSubmenuTriggered((*reinterpret_cast< QAction*(*)>(_a[1]))); break;
        case 33: _t->infoSubmenuTriggered(); break;
        case 34: _t->wifiSubmenuTriggered((*reinterpret_cast< QAction*(*)>(_a[1]))); break;
        case 35: _t->wifiSubmenuTriggered(); break;
        case 36: _t->vpnSubmenuTriggered((*reinterpret_cast< QAction*(*)>(_a[1]))); break;
        case 37: _t->vpnSubmenuTriggered(); break;
        case 38: _t->getServiceDetails((*reinterpret_cast< int(*)>(_a[1]))); break;
        case 39: _t->showWhatsThis(); break;
        case 40: _t->trayNotifications((*reinterpret_cast< bool(*)>(_a[1]))); break;
        case 41: _t->daemonNotifications((*reinterpret_cast< bool(*)>(_a[1]))); break;
        case 42: _t->closeSystemTrayTearOffMenu(); break;
        case 43: _t->iconActivated((*reinterpret_cast< QSystemTrayIcon::ActivationReason(*)>(_a[1]))); break;
        case 44: _t->enableRunOnStartup((*reinterpret_cast< bool(*)>(_a[1]))); break;
        case 45: _t->writeSettings(); break;
        case 46: _t->readSettings(); break;
        case 47: _t->createSystemTrayIcon(); break;
        case 48: _t->connectNotifyClient(); break;
        case 49: _t->configureService(); break;
        case 50: _t->provisionService(); break;
        case 51: _t->socketConnectionDetected(); break;
        case 52: _t->cleanUp(); break;
        case 53: _t->callColorDialog(); break;
        case 54: _t->iconColorChanged((*reinterpret_cast< const QString(*)>(_a[1]))); break;
        case 55: _t->setStateRescan((*reinterpret_cast< bool(*)>(_a[1]))); break;
        default: ;
        }
    } else if (_c == QMetaObject::RegisterMethodArgumentMetaType) {
        switch (_id) {
        default: *reinterpret_cast<int*>(_a[0]) = -1; break;
        case 6:
            switch (*reinterpret_cast<int*>(_a[1])) {
            default: *reinterpret_cast<int*>(_a[0]) = -1; break;
            case 0:
                *reinterpret_cast<int*>(_a[0]) = qRegisterMetaType< QAction* >(); break;
            }
            break;
        case 7:
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
                *reinterpret_cast<int*>(_a[0]) = qRegisterMetaType< QDBusObjectPath >(); break;
            }
            break;
        case 14:
            switch (*reinterpret_cast<int*>(_a[1])) {
            default: *reinterpret_cast<int*>(_a[0]) = -1; break;
            case 1:
                *reinterpret_cast<int*>(_a[0]) = qRegisterMetaType< QDBusVariant >(); break;
            }
            break;
        case 15:
            switch (*reinterpret_cast<int*>(_a[1])) {
            default: *reinterpret_cast<int*>(_a[0]) = -1; break;
            case 2:
                *reinterpret_cast<int*>(_a[0]) = qRegisterMetaType< QDBusMessage >(); break;
            case 1:
                *reinterpret_cast<int*>(_a[0]) = qRegisterMetaType< QList<QDBusObjectPath> >(); break;
            }
            break;
        case 16:
            switch (*reinterpret_cast<int*>(_a[1])) {
            default: *reinterpret_cast<int*>(_a[0]) = -1; break;
            case 2:
                *reinterpret_cast<int*>(_a[0]) = qRegisterMetaType< QDBusMessage >(); break;
            case 1:
                *reinterpret_cast<int*>(_a[0]) = qRegisterMetaType< QList<QDBusObjectPath> >(); break;
            }
            break;
        case 17:
            switch (*reinterpret_cast<int*>(_a[1])) {
            default: *reinterpret_cast<int*>(_a[0]) = -1; break;
            case 2:
                *reinterpret_cast<int*>(_a[0]) = qRegisterMetaType< QDBusMessage >(); break;
            case 1:
                *reinterpret_cast<int*>(_a[0]) = qRegisterMetaType< QDBusVariant >(); break;
            }
            break;
        case 18:
            switch (*reinterpret_cast<int*>(_a[1])) {
            default: *reinterpret_cast<int*>(_a[0]) = -1; break;
            case 2:
                *reinterpret_cast<int*>(_a[0]) = qRegisterMetaType< QDBusMessage >(); break;
            case 1:
                *reinterpret_cast<int*>(_a[0]) = qRegisterMetaType< QDBusVariant >(); break;
            }
            break;
        case 19:
            switch (*reinterpret_cast<int*>(_a[1])) {
            default: *reinterpret_cast<int*>(_a[0]) = -1; break;
            case 0:
                *reinterpret_cast<int*>(_a[0]) = qRegisterMetaType< QDBusObjectPath >(); break;
            }
            break;
        case 20:
            switch (*reinterpret_cast<int*>(_a[1])) {
            default: *reinterpret_cast<int*>(_a[0]) = -1; break;
            case 0:
                *reinterpret_cast<int*>(_a[0]) = qRegisterMetaType< QDBusObjectPath >(); break;
            }
            break;
        case 28:
            switch (*reinterpret_cast<int*>(_a[1])) {
            default: *reinterpret_cast<int*>(_a[0]) = -1; break;
            case 0:
                *reinterpret_cast<int*>(_a[0]) = qRegisterMetaType< QAction* >(); break;
            }
            break;
        case 30:
            switch (*reinterpret_cast<int*>(_a[1])) {
            default: *reinterpret_cast<int*>(_a[0]) = -1; break;
            case 0:
                *reinterpret_cast<int*>(_a[0]) = qRegisterMetaType< QAction* >(); break;
            }
            break;
        case 32:
            switch (*reinterpret_cast<int*>(_a[1])) {
            default: *reinterpret_cast<int*>(_a[0]) = -1; break;
            case 0:
                *reinterpret_cast<int*>(_a[0]) = qRegisterMetaType< QAction* >(); break;
            }
            break;
        case 34:
            switch (*reinterpret_cast<int*>(_a[1])) {
            default: *reinterpret_cast<int*>(_a[0]) = -1; break;
            case 0:
                *reinterpret_cast<int*>(_a[0]) = qRegisterMetaType< QAction* >(); break;
            }
            break;
        case 36:
            switch (*reinterpret_cast<int*>(_a[1])) {
            default: *reinterpret_cast<int*>(_a[0]) = -1; break;
            case 0:
                *reinterpret_cast<int*>(_a[0]) = qRegisterMetaType< QAction* >(); break;
            }
            break;
        }
    }
}

QT_INIT_METAOBJECT const QMetaObject ControlBox::staticMetaObject = { {
    QMetaObject::SuperData::link<QDialog::staticMetaObject>(),
    qt_meta_stringdata_ControlBox.data,
    qt_meta_data_ControlBox,
    qt_static_metacall,
    nullptr,
    nullptr
} };


const QMetaObject *ControlBox::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->dynamicMetaObject() : &staticMetaObject;
}

void *ControlBox::qt_metacast(const char *_clname)
{
    if (!_clname) return nullptr;
    if (!strcmp(_clname, qt_meta_stringdata_ControlBox.stringdata0))
        return static_cast<void*>(this);
    return QDialog::qt_metacast(_clname);
}

int ControlBox::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = QDialog::qt_metacall(_c, _id, _a);
    if (_id < 0)
        return _id;
    if (_c == QMetaObject::InvokeMetaMethod) {
        if (_id < 56)
            qt_static_metacall(this, _c, _id, _a);
        _id -= 56;
    } else if (_c == QMetaObject::RegisterMethodArgumentMetaType) {
        if (_id < 56)
            qt_static_metacall(this, _c, _id, _a);
        _id -= 56;
    }
    return _id;
}
QT_WARNING_POP
QT_END_MOC_NAMESPACE
