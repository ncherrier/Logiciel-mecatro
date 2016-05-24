/****************************************************************************
** Meta object code from reading C++ file 'CameraTreeWindow.h'
**
** Created by: The Qt Meta Object Compiler version 67 (Qt 5.5.1)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include "../../../../Source/UI/CameraTreeWindow.h"
#include <QtCore/qbytearray.h>
#include <QtCore/qmetatype.h>
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'CameraTreeWindow.h' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 67
#error "This file was generated using the moc from 5.5.1. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

QT_BEGIN_MOC_NAMESPACE
struct qt_meta_stringdata_CameraTreeWindow_t {
    QByteArrayData data[11];
    char stringdata0[122];
};
#define QT_MOC_LITERAL(idx, ofs, len) \
    Q_STATIC_BYTE_ARRAY_DATA_HEADER_INITIALIZER_WITH_OFFSET(len, \
    qptrdiff(offsetof(qt_meta_stringdata_CameraTreeWindow_t, stringdata0) + ofs \
        - idx * sizeof(QByteArrayData)) \
    )
static const qt_meta_stringdata_CameraTreeWindow_t qt_meta_stringdata_CameraTreeWindow = {
    {
QT_MOC_LITERAL(0, 0, 16), // "CameraTreeWindow"
QT_MOC_LITERAL(1, 17, 13), // "cameraClicked"
QT_MOC_LITERAL(2, 31, 0), // ""
QT_MOC_LITERAL(3, 32, 6), // "sModel"
QT_MOC_LITERAL(4, 39, 10), // "bIsChecked"
QT_MOC_LITERAL(5, 50, 17), // "rightMouseClicked"
QT_MOC_LITERAL(6, 68, 10), // "bIsClicked"
QT_MOC_LITERAL(7, 79, 13), // "clickOnCamera"
QT_MOC_LITERAL(8, 93, 16), // "QTreeWidgetItem*"
QT_MOC_LITERAL(9, 110, 4), // "item"
QT_MOC_LITERAL(10, 115, 6) // "column"

    },
    "CameraTreeWindow\0cameraClicked\0\0sModel\0"
    "bIsChecked\0rightMouseClicked\0bIsClicked\0"
    "clickOnCamera\0QTreeWidgetItem*\0item\0"
    "column"
};
#undef QT_MOC_LITERAL

static const uint qt_meta_data_CameraTreeWindow[] = {

 // content:
       7,       // revision
       0,       // classname
       0,    0, // classinfo
       3,   14, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       2,       // signalCount

 // signals: name, argc, parameters, tag, flags
       1,    2,   29,    2, 0x06 /* Public */,
       5,    1,   34,    2, 0x06 /* Public */,

 // slots: name, argc, parameters, tag, flags
       7,    2,   37,    2, 0x08 /* Private */,

 // signals: parameters
    QMetaType::Void, QMetaType::QString, QMetaType::Bool,    3,    4,
    QMetaType::Void, QMetaType::Bool,    6,

 // slots: parameters
    QMetaType::Void, 0x80000000 | 8, QMetaType::Int,    9,   10,

       0        // eod
};

void CameraTreeWindow::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::InvokeMetaMethod) {
        CameraTreeWindow *_t = static_cast<CameraTreeWindow *>(_o);
        Q_UNUSED(_t)
        switch (_id) {
        case 0: _t->cameraClicked((*reinterpret_cast< const QString(*)>(_a[1])),(*reinterpret_cast< const bool(*)>(_a[2]))); break;
        case 1: _t->rightMouseClicked((*reinterpret_cast< const bool(*)>(_a[1]))); break;
        case 2: _t->clickOnCamera((*reinterpret_cast< QTreeWidgetItem*(*)>(_a[1])),(*reinterpret_cast< int(*)>(_a[2]))); break;
        default: ;
        }
    } else if (_c == QMetaObject::IndexOfMethod) {
        int *result = reinterpret_cast<int *>(_a[0]);
        void **func = reinterpret_cast<void **>(_a[1]);
        {
            typedef void (CameraTreeWindow::*_t)(const QString & , const bool & );
            if (*reinterpret_cast<_t *>(func) == static_cast<_t>(&CameraTreeWindow::cameraClicked)) {
                *result = 0;
            }
        }
        {
            typedef void (CameraTreeWindow::*_t)(const bool & );
            if (*reinterpret_cast<_t *>(func) == static_cast<_t>(&CameraTreeWindow::rightMouseClicked)) {
                *result = 1;
            }
        }
    }
}

const QMetaObject CameraTreeWindow::staticMetaObject = {
    { &QTreeWidget::staticMetaObject, qt_meta_stringdata_CameraTreeWindow.data,
      qt_meta_data_CameraTreeWindow,  qt_static_metacall, Q_NULLPTR, Q_NULLPTR}
};


const QMetaObject *CameraTreeWindow::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->dynamicMetaObject() : &staticMetaObject;
}

void *CameraTreeWindow::qt_metacast(const char *_clname)
{
    if (!_clname) return Q_NULLPTR;
    if (!strcmp(_clname, qt_meta_stringdata_CameraTreeWindow.stringdata0))
        return static_cast<void*>(const_cast< CameraTreeWindow*>(this));
    return QTreeWidget::qt_metacast(_clname);
}

int CameraTreeWindow::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = QTreeWidget::qt_metacall(_c, _id, _a);
    if (_id < 0)
        return _id;
    if (_c == QMetaObject::InvokeMetaMethod) {
        if (_id < 3)
            qt_static_metacall(this, _c, _id, _a);
        _id -= 3;
    } else if (_c == QMetaObject::RegisterMethodArgumentMetaType) {
        if (_id < 3)
            *reinterpret_cast<int*>(_a[0]) = -1;
        _id -= 3;
    }
    return _id;
}

// SIGNAL 0
void CameraTreeWindow::cameraClicked(const QString & _t1, const bool & _t2)
{
    void *_a[] = { Q_NULLPTR, const_cast<void*>(reinterpret_cast<const void*>(&_t1)), const_cast<void*>(reinterpret_cast<const void*>(&_t2)) };
    QMetaObject::activate(this, &staticMetaObject, 0, _a);
}

// SIGNAL 1
void CameraTreeWindow::rightMouseClicked(const bool & _t1)
{
    void *_a[] = { Q_NULLPTR, const_cast<void*>(reinterpret_cast<const void*>(&_t1)) };
    QMetaObject::activate(this, &staticMetaObject, 1, _a);
}
QT_END_MOC_NAMESPACE
