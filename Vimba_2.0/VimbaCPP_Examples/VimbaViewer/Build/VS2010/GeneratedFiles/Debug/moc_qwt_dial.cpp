/****************************************************************************
** Meta object code from reading C++ file 'qwt_dial.h'
**
** Created by: The Qt Meta Object Compiler version 67 (Qt 5.5.1)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include "../../../../Source/ExternLib/qwt/qwt_dial.h"
#include <QtCore/qbytearray.h>
#include <QtCore/qmetatype.h>
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'qwt_dial.h' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 67
#error "This file was generated using the moc from 5.5.1. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

QT_BEGIN_MOC_NAMESPACE
struct qt_meta_stringdata_QwtDial_t {
    QByteArrayData data[17];
    char stringdata0[155];
};
#define QT_MOC_LITERAL(idx, ofs, len) \
    Q_STATIC_BYTE_ARRAY_DATA_HEADER_INITIALIZER_WITH_OFFSET(len, \
    qptrdiff(offsetof(qt_meta_stringdata_QwtDial_t, stringdata0) + ofs \
        - idx * sizeof(QByteArrayData)) \
    )
static const qt_meta_stringdata_QwtDial_t qt_meta_stringdata_QwtDial = {
    {
QT_MOC_LITERAL(0, 0, 7), // "QwtDial"
QT_MOC_LITERAL(1, 8, 9), // "lineWidth"
QT_MOC_LITERAL(2, 18, 11), // "frameShadow"
QT_MOC_LITERAL(3, 30, 6), // "Shadow"
QT_MOC_LITERAL(4, 37, 4), // "mode"
QT_MOC_LITERAL(5, 42, 4), // "Mode"
QT_MOC_LITERAL(6, 47, 6), // "origin"
QT_MOC_LITERAL(7, 54, 8), // "wrapping"
QT_MOC_LITERAL(8, 63, 9), // "direction"
QT_MOC_LITERAL(9, 73, 9), // "Direction"
QT_MOC_LITERAL(10, 83, 5), // "Plain"
QT_MOC_LITERAL(11, 89, 6), // "Raised"
QT_MOC_LITERAL(12, 96, 6), // "Sunken"
QT_MOC_LITERAL(13, 103, 12), // "RotateNeedle"
QT_MOC_LITERAL(14, 116, 11), // "RotateScale"
QT_MOC_LITERAL(15, 128, 9), // "Clockwise"
QT_MOC_LITERAL(16, 138, 16) // "CounterClockwise"

    },
    "QwtDial\0lineWidth\0frameShadow\0Shadow\0"
    "mode\0Mode\0origin\0wrapping\0direction\0"
    "Direction\0Plain\0Raised\0Sunken\0"
    "RotateNeedle\0RotateScale\0Clockwise\0"
    "CounterClockwise"
};
#undef QT_MOC_LITERAL

static const uint qt_meta_data_QwtDial[] = {

 // content:
       7,       // revision
       0,       // classname
       0,    0, // classinfo
       0,    0, // methods
       6,   14, // properties
       3,   32, // enums/sets
       0,    0, // constructors
       0,       // flags
       0,       // signalCount

 // properties: name, type, flags
       1, QMetaType::Int, 0x00095103,
       2, 0x80000000 | 3, 0x0009510b,
       4, 0x80000000 | 5, 0x0009510b,
       6, QMetaType::Double, 0x00095103,
       7, QMetaType::Bool, 0x00095103,
       8, 0x80000000 | 9, 0x0009510b,

 // enums: name, flags, count, data
       3, 0x0,    3,   44,
       5, 0x0,    2,   50,
       9, 0x0,    2,   54,

 // enum data: key, value
      10, uint(QwtDial::Plain),
      11, uint(QwtDial::Raised),
      12, uint(QwtDial::Sunken),
      13, uint(QwtDial::RotateNeedle),
      14, uint(QwtDial::RotateScale),
      15, uint(QwtDial::Clockwise),
      16, uint(QwtDial::CounterClockwise),

       0        // eod
};

void QwtDial::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{

#ifndef QT_NO_PROPERTIES
    if (_c == QMetaObject::ReadProperty) {
        QwtDial *_t = static_cast<QwtDial *>(_o);
        Q_UNUSED(_t)
        void *_v = _a[0];
        switch (_id) {
        case 0: *reinterpret_cast< int*>(_v) = _t->lineWidth(); break;
        case 1: *reinterpret_cast< Shadow*>(_v) = _t->frameShadow(); break;
        case 2: *reinterpret_cast< Mode*>(_v) = _t->mode(); break;
        case 3: *reinterpret_cast< double*>(_v) = _t->origin(); break;
        case 4: *reinterpret_cast< bool*>(_v) = _t->wrapping(); break;
        case 5: *reinterpret_cast< Direction*>(_v) = _t->direction(); break;
        default: break;
        }
    } else if (_c == QMetaObject::WriteProperty) {
        QwtDial *_t = static_cast<QwtDial *>(_o);
        Q_UNUSED(_t)
        void *_v = _a[0];
        switch (_id) {
        case 0: _t->setLineWidth(*reinterpret_cast< int*>(_v)); break;
        case 1: _t->setFrameShadow(*reinterpret_cast< Shadow*>(_v)); break;
        case 2: _t->setMode(*reinterpret_cast< Mode*>(_v)); break;
        case 3: _t->setOrigin(*reinterpret_cast< double*>(_v)); break;
        case 4: _t->setWrapping(*reinterpret_cast< bool*>(_v)); break;
        case 5: _t->setDirection(*reinterpret_cast< Direction*>(_v)); break;
        default: break;
        }
    } else if (_c == QMetaObject::ResetProperty) {
    }
#endif // QT_NO_PROPERTIES
    Q_UNUSED(_o);
    Q_UNUSED(_id);
    Q_UNUSED(_c);
    Q_UNUSED(_a);
}

const QMetaObject QwtDial::staticMetaObject = {
    { &QwtAbstractSlider::staticMetaObject, qt_meta_stringdata_QwtDial.data,
      qt_meta_data_QwtDial,  qt_static_metacall, Q_NULLPTR, Q_NULLPTR}
};


const QMetaObject *QwtDial::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->dynamicMetaObject() : &staticMetaObject;
}

void *QwtDial::qt_metacast(const char *_clname)
{
    if (!_clname) return Q_NULLPTR;
    if (!strcmp(_clname, qt_meta_stringdata_QwtDial.stringdata0))
        return static_cast<void*>(const_cast< QwtDial*>(this));
    return QwtAbstractSlider::qt_metacast(_clname);
}

int QwtDial::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = QwtAbstractSlider::qt_metacall(_c, _id, _a);
    if (_id < 0)
        return _id;
    
#ifndef QT_NO_PROPERTIES
   if (_c == QMetaObject::ReadProperty || _c == QMetaObject::WriteProperty
            || _c == QMetaObject::ResetProperty || _c == QMetaObject::RegisterPropertyMetaType) {
        qt_static_metacall(this, _c, _id, _a);
        _id -= 6;
    } else if (_c == QMetaObject::QueryPropertyDesignable) {
        _id -= 6;
    } else if (_c == QMetaObject::QueryPropertyScriptable) {
        _id -= 6;
    } else if (_c == QMetaObject::QueryPropertyStored) {
        _id -= 6;
    } else if (_c == QMetaObject::QueryPropertyEditable) {
        _id -= 6;
    } else if (_c == QMetaObject::QueryPropertyUser) {
        _id -= 6;
    }
#endif // QT_NO_PROPERTIES
    return _id;
}
QT_END_MOC_NAMESPACE
