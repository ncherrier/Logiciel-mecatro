/****************************************************************************
** Meta object code from reading C++ file 'FeatureObserver.h'
**
** Created by: The Qt Meta Object Compiler version 67 (Qt 5.5.1)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include "../../../../Source/FeatureObserver.h"
#include <QtCore/qbytearray.h>
#include <QtCore/qmetatype.h>
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'FeatureObserver.h' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 67
#error "This file was generated using the moc from 5.5.1. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

QT_BEGIN_MOC_NAMESPACE
struct qt_meta_stringdata_FeatureObserver_t {
    QByteArrayData data[9];
    char stringdata0[96];
};
#define QT_MOC_LITERAL(idx, ofs, len) \
    Q_STATIC_BYTE_ARRAY_DATA_HEADER_INITIALIZER_WITH_OFFSET(len, \
    qptrdiff(offsetof(qt_meta_stringdata_FeatureObserver_t, stringdata0) + ofs \
        - idx * sizeof(QByteArrayData)) \
    )
static const qt_meta_stringdata_FeatureObserver_t qt_meta_stringdata_FeatureObserver = {
    {
QT_MOC_LITERAL(0, 0, 15), // "FeatureObserver"
QT_MOC_LITERAL(1, 16, 17), // "setChangedFeature"
QT_MOC_LITERAL(2, 34, 0), // ""
QT_MOC_LITERAL(3, 35, 5), // "sFeat"
QT_MOC_LITERAL(4, 41, 6), // "sValue"
QT_MOC_LITERAL(5, 48, 11), // "bIsWritable"
QT_MOC_LITERAL(6, 60, 15), // "setEventMessage"
QT_MOC_LITERAL(7, 76, 4), // "sMsg"
QT_MOC_LITERAL(8, 81, 14) // "checkSendEvent"

    },
    "FeatureObserver\0setChangedFeature\0\0"
    "sFeat\0sValue\0bIsWritable\0setEventMessage\0"
    "sMsg\0checkSendEvent"
};
#undef QT_MOC_LITERAL

static const uint qt_meta_data_FeatureObserver[] = {

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
       1,    3,   29,    2, 0x06 /* Public */,
       6,    1,   36,    2, 0x06 /* Public */,

 // slots: name, argc, parameters, tag, flags
       8,    0,   39,    2, 0x08 /* Private */,

 // signals: parameters
    QMetaType::Void, QMetaType::QString, QMetaType::QString, QMetaType::Bool,    3,    4,    5,
    QMetaType::Void, QMetaType::QStringList,    7,

 // slots: parameters
    QMetaType::Void,

       0        // eod
};

void FeatureObserver::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::InvokeMetaMethod) {
        FeatureObserver *_t = static_cast<FeatureObserver *>(_o);
        Q_UNUSED(_t)
        switch (_id) {
        case 0: _t->setChangedFeature((*reinterpret_cast< const QString(*)>(_a[1])),(*reinterpret_cast< const QString(*)>(_a[2])),(*reinterpret_cast< const bool(*)>(_a[3]))); break;
        case 1: _t->setEventMessage((*reinterpret_cast< const QStringList(*)>(_a[1]))); break;
        case 2: _t->checkSendEvent(); break;
        default: ;
        }
    } else if (_c == QMetaObject::IndexOfMethod) {
        int *result = reinterpret_cast<int *>(_a[0]);
        void **func = reinterpret_cast<void **>(_a[1]);
        {
            typedef void (FeatureObserver::*_t)(const QString & , const QString & , const bool & );
            if (*reinterpret_cast<_t *>(func) == static_cast<_t>(&FeatureObserver::setChangedFeature)) {
                *result = 0;
            }
        }
        {
            typedef void (FeatureObserver::*_t)(const QStringList & );
            if (*reinterpret_cast<_t *>(func) == static_cast<_t>(&FeatureObserver::setEventMessage)) {
                *result = 1;
            }
        }
    }
}

const QMetaObject FeatureObserver::staticMetaObject = {
    { &QObject::staticMetaObject, qt_meta_stringdata_FeatureObserver.data,
      qt_meta_data_FeatureObserver,  qt_static_metacall, Q_NULLPTR, Q_NULLPTR}
};


const QMetaObject *FeatureObserver::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->dynamicMetaObject() : &staticMetaObject;
}

void *FeatureObserver::qt_metacast(const char *_clname)
{
    if (!_clname) return Q_NULLPTR;
    if (!strcmp(_clname, qt_meta_stringdata_FeatureObserver.stringdata0))
        return static_cast<void*>(const_cast< FeatureObserver*>(this));
    if (!strcmp(_clname, "AVT::VmbAPI::IFeatureObserver"))
        return static_cast< AVT::VmbAPI::IFeatureObserver*>(const_cast< FeatureObserver*>(this));
    return QObject::qt_metacast(_clname);
}

int FeatureObserver::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = QObject::qt_metacall(_c, _id, _a);
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
void FeatureObserver::setChangedFeature(const QString & _t1, const QString & _t2, const bool & _t3)
{
    void *_a[] = { Q_NULLPTR, const_cast<void*>(reinterpret_cast<const void*>(&_t1)), const_cast<void*>(reinterpret_cast<const void*>(&_t2)), const_cast<void*>(reinterpret_cast<const void*>(&_t3)) };
    QMetaObject::activate(this, &staticMetaObject, 0, _a);
}

// SIGNAL 1
void FeatureObserver::setEventMessage(const QStringList & _t1)
{
    void *_a[] = { Q_NULLPTR, const_cast<void*>(reinterpret_cast<const void*>(&_t1)) };
    QMetaObject::activate(this, &staticMetaObject, 1, _a);
}
QT_END_MOC_NAMESPACE
