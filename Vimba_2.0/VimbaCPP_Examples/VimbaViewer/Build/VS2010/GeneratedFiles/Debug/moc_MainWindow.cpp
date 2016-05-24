/****************************************************************************
** Meta object code from reading C++ file 'MainWindow.h'
**
** Created by: The Qt Meta Object Compiler version 67 (Qt 5.5.1)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include "../../../../Source/MainWindow.h"
#include <QtCore/qbytearray.h>
#include <QtCore/qmetatype.h>
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'MainWindow.h' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 67
#error "This file was generated using the moc from 5.5.1. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

QT_BEGIN_MOC_NAMESPACE
struct qt_meta_stringdata_MainWindow_t {
    QByteArrayData data[17];
    char stringdata0[288];
};
#define QT_MOC_LITERAL(idx, ofs, len) \
    Q_STATIC_BYTE_ARRAY_DATA_HEADER_INITIALIZER_WITH_OFFSET(len, \
    qptrdiff(offsetof(qt_meta_stringdata_MainWindow_t, stringdata0) + ofs \
        - idx * sizeof(QByteArrayData)) \
    )
static const qt_meta_stringdata_MainWindow_t qt_meta_stringdata_MainWindow = {
    {
QT_MOC_LITERAL(0, 0, 10), // "MainWindow"
QT_MOC_LITERAL(1, 11, 27), // "on_ActionDiscover_triggered"
QT_MOC_LITERAL(2, 39, 0), // ""
QT_MOC_LITERAL(3, 40, 24), // "on_ActionClear_triggered"
QT_MOC_LITERAL(4, 65, 27), // "on_ActionOpenByID_triggered"
QT_MOC_LITERAL(5, 93, 31), // "on_ActionStartOptions_triggered"
QT_MOC_LITERAL(6, 125, 15), // "onCameraClicked"
QT_MOC_LITERAL(7, 141, 6), // "sModel"
QT_MOC_LITERAL(8, 148, 10), // "bIsChecked"
QT_MOC_LITERAL(9, 159, 19), // "onRightMouseClicked"
QT_MOC_LITERAL(10, 179, 10), // "bIsClicked"
QT_MOC_LITERAL(11, 190, 17), // "onCloseFromViewer"
QT_MOC_LITERAL(12, 208, 18), // "onUpdateDeviceList"
QT_MOC_LITERAL(13, 227, 5), // "about"
QT_MOC_LITERAL(14, 233, 20), // "rightMouseOpenCamera"
QT_MOC_LITERAL(15, 254, 15), // "bOpenAccesState"
QT_MOC_LITERAL(16, 270, 17) // "onInitializeVimba"

    },
    "MainWindow\0on_ActionDiscover_triggered\0"
    "\0on_ActionClear_triggered\0"
    "on_ActionOpenByID_triggered\0"
    "on_ActionStartOptions_triggered\0"
    "onCameraClicked\0sModel\0bIsChecked\0"
    "onRightMouseClicked\0bIsClicked\0"
    "onCloseFromViewer\0onUpdateDeviceList\0"
    "about\0rightMouseOpenCamera\0bOpenAccesState\0"
    "onInitializeVimba"
};
#undef QT_MOC_LITERAL

static const uint qt_meta_data_MainWindow[] = {

 // content:
       7,       // revision
       0,       // classname
       0,    0, // classinfo
      11,   14, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       0,       // signalCount

 // slots: name, argc, parameters, tag, flags
       1,    0,   69,    2, 0x08 /* Private */,
       3,    0,   70,    2, 0x08 /* Private */,
       4,    0,   71,    2, 0x08 /* Private */,
       5,    0,   72,    2, 0x08 /* Private */,
       6,    2,   73,    2, 0x08 /* Private */,
       9,    1,   78,    2, 0x08 /* Private */,
      11,    1,   81,    2, 0x08 /* Private */,
      12,    0,   84,    2, 0x08 /* Private */,
      13,    0,   85,    2, 0x08 /* Private */,
      14,    1,   86,    2, 0x08 /* Private */,
      16,    0,   89,    2, 0x08 /* Private */,

 // slots: parameters
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void, QMetaType::QString, QMetaType::Bool,    7,    8,
    QMetaType::Void, QMetaType::Bool,   10,
    QMetaType::Void, QMetaType::QString,    7,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void, QMetaType::Bool,   15,
    QMetaType::Void,

       0        // eod
};

void MainWindow::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::InvokeMetaMethod) {
        MainWindow *_t = static_cast<MainWindow *>(_o);
        Q_UNUSED(_t)
        switch (_id) {
        case 0: _t->on_ActionDiscover_triggered(); break;
        case 1: _t->on_ActionClear_triggered(); break;
        case 2: _t->on_ActionOpenByID_triggered(); break;
        case 3: _t->on_ActionStartOptions_triggered(); break;
        case 4: _t->onCameraClicked((*reinterpret_cast< const QString(*)>(_a[1])),(*reinterpret_cast< const bool(*)>(_a[2]))); break;
        case 5: _t->onRightMouseClicked((*reinterpret_cast< const bool(*)>(_a[1]))); break;
        case 6: _t->onCloseFromViewer((*reinterpret_cast< const QString(*)>(_a[1]))); break;
        case 7: _t->onUpdateDeviceList(); break;
        case 8: _t->about(); break;
        case 9: _t->rightMouseOpenCamera((*reinterpret_cast< bool(*)>(_a[1]))); break;
        case 10: _t->onInitializeVimba(); break;
        default: ;
        }
    }
}

const QMetaObject MainWindow::staticMetaObject = {
    { &QMainWindow::staticMetaObject, qt_meta_stringdata_MainWindow.data,
      qt_meta_data_MainWindow,  qt_static_metacall, Q_NULLPTR, Q_NULLPTR}
};


const QMetaObject *MainWindow::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->dynamicMetaObject() : &staticMetaObject;
}

void *MainWindow::qt_metacast(const char *_clname)
{
    if (!_clname) return Q_NULLPTR;
    if (!strcmp(_clname, qt_meta_stringdata_MainWindow.stringdata0))
        return static_cast<void*>(const_cast< MainWindow*>(this));
    return QMainWindow::qt_metacast(_clname);
}

int MainWindow::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = QMainWindow::qt_metacall(_c, _id, _a);
    if (_id < 0)
        return _id;
    if (_c == QMetaObject::InvokeMetaMethod) {
        if (_id < 11)
            qt_static_metacall(this, _c, _id, _a);
        _id -= 11;
    } else if (_c == QMetaObject::RegisterMethodArgumentMetaType) {
        if (_id < 11)
            *reinterpret_cast<int*>(_a[0]) = -1;
        _id -= 11;
    }
    return _id;
}
QT_END_MOC_NAMESPACE
