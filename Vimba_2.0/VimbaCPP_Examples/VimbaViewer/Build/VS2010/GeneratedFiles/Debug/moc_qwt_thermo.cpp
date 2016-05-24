/****************************************************************************
** Meta object code from reading C++ file 'qwt_thermo.h'
**
** Created by: The Qt Meta Object Compiler version 67 (Qt 5.5.1)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include "../../../../Source/ExternLib/qwt/qwt_thermo.h"
#include <QtCore/qbytearray.h>
#include <QtCore/qmetatype.h>
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'qwt_thermo.h' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 67
#error "This file was generated using the moc from 5.5.1. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

QT_BEGIN_MOC_NAMESPACE
struct qt_meta_stringdata_QwtThermo_t {
    QByteArrayData data[19];
    char stringdata0[175];
};
#define QT_MOC_LITERAL(idx, ofs, len) \
    Q_STATIC_BYTE_ARRAY_DATA_HEADER_INITIALIZER_WITH_OFFSET(len, \
    qptrdiff(offsetof(qt_meta_stringdata_QwtThermo_t, stringdata0) + ofs \
        - idx * sizeof(QByteArrayData)) \
    )
static const qt_meta_stringdata_QwtThermo_t qt_meta_stringdata_QwtThermo = {
    {
QT_MOC_LITERAL(0, 0, 9), // "QwtThermo"
QT_MOC_LITERAL(1, 10, 8), // "setValue"
QT_MOC_LITERAL(2, 19, 0), // ""
QT_MOC_LITERAL(3, 20, 3), // "val"
QT_MOC_LITERAL(4, 24, 12), // "alarmEnabled"
QT_MOC_LITERAL(5, 37, 10), // "alarmLevel"
QT_MOC_LITERAL(6, 48, 13), // "scalePosition"
QT_MOC_LITERAL(7, 62, 8), // "ScalePos"
QT_MOC_LITERAL(8, 71, 7), // "spacing"
QT_MOC_LITERAL(9, 79, 11), // "borderWidth"
QT_MOC_LITERAL(10, 91, 8), // "maxValue"
QT_MOC_LITERAL(11, 100, 8), // "minValue"
QT_MOC_LITERAL(12, 109, 9), // "pipeWidth"
QT_MOC_LITERAL(13, 119, 5), // "value"
QT_MOC_LITERAL(14, 125, 7), // "NoScale"
QT_MOC_LITERAL(15, 133, 9), // "LeftScale"
QT_MOC_LITERAL(16, 143, 10), // "RightScale"
QT_MOC_LITERAL(17, 154, 8), // "TopScale"
QT_MOC_LITERAL(18, 163, 11) // "BottomScale"

    },
    "QwtThermo\0setValue\0\0val\0alarmEnabled\0"
    "alarmLevel\0scalePosition\0ScalePos\0"
    "spacing\0borderWidth\0maxValue\0minValue\0"
    "pipeWidth\0value\0NoScale\0LeftScale\0"
    "RightScale\0TopScale\0BottomScale"
};
#undef QT_MOC_LITERAL

static const uint qt_meta_data_QwtThermo[] = {

 // content:
       7,       // revision
       0,       // classname
       0,    0, // classinfo
       1,   14, // methods
       9,   22, // properties
       1,   49, // enums/sets
       0,    0, // constructors
       0,       // flags
       0,       // signalCount

 // slots: name, argc, parameters, tag, flags
       1,    1,   19,    2, 0x0a /* Public */,

 // slots: parameters
    QMetaType::Void, QMetaType::Double,    3,

 // properties: name, type, flags
       4, QMetaType::Bool, 0x00095103,
       5, QMetaType::Double, 0x00095103,
       6, 0x80000000 | 7, 0x0009510b,
       8, QMetaType::Int, 0x00095103,
       9, QMetaType::Int, 0x00095103,
      10, QMetaType::Double, 0x00095103,
      11, QMetaType::Double, 0x00095103,
      12, QMetaType::Int, 0x00095103,
      13, QMetaType::Double, 0x00095103,

 // enums: name, flags, count, data
       7, 0x0,    5,   53,

 // enum data: key, value
      14, uint(QwtThermo::NoScale),
      15, uint(QwtThermo::LeftScale),
      16, uint(QwtThermo::RightScale),
      17, uint(QwtThermo::TopScale),
      18, uint(QwtThermo::BottomScale),

       0        // eod
};

void QwtThermo::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::InvokeMetaMethod) {
        QwtThermo *_t = static_cast<QwtThermo *>(_o);
        Q_UNUSED(_t)
        switch (_id) {
        case 0: _t->setValue((*reinterpret_cast< double(*)>(_a[1]))); break;
        default: ;
        }
    }
#ifndef QT_NO_PROPERTIES
    else if (_c == QMetaObject::ReadProperty) {
        QwtThermo *_t = static_cast<QwtThermo *>(_o);
        Q_UNUSED(_t)
        void *_v = _a[0];
        switch (_id) {
        case 0: *reinterpret_cast< bool*>(_v) = _t->alarmEnabled(); break;
        case 1: *reinterpret_cast< double*>(_v) = _t->alarmLevel(); break;
        case 2: *reinterpret_cast< ScalePos*>(_v) = _t->scalePosition(); break;
        case 3: *reinterpret_cast< int*>(_v) = _t->spacing(); break;
        case 4: *reinterpret_cast< int*>(_v) = _t->borderWidth(); break;
        case 5: *reinterpret_cast< double*>(_v) = _t->maxValue(); break;
        case 6: *reinterpret_cast< double*>(_v) = _t->minValue(); break;
        case 7: *reinterpret_cast< int*>(_v) = _t->pipeWidth(); break;
        case 8: *reinterpret_cast< double*>(_v) = _t->value(); break;
        default: break;
        }
    } else if (_c == QMetaObject::WriteProperty) {
        QwtThermo *_t = static_cast<QwtThermo *>(_o);
        Q_UNUSED(_t)
        void *_v = _a[0];
        switch (_id) {
        case 0: _t->setAlarmEnabled(*reinterpret_cast< bool*>(_v)); break;
        case 1: _t->setAlarmLevel(*reinterpret_cast< double*>(_v)); break;
        case 2: _t->setScalePosition(*reinterpret_cast< ScalePos*>(_v)); break;
        case 3: _t->setSpacing(*reinterpret_cast< int*>(_v)); break;
        case 4: _t->setBorderWidth(*reinterpret_cast< int*>(_v)); break;
        case 5: _t->setMaxValue(*reinterpret_cast< double*>(_v)); break;
        case 6: _t->setMinValue(*reinterpret_cast< double*>(_v)); break;
        case 7: _t->setPipeWidth(*reinterpret_cast< int*>(_v)); break;
        case 8: _t->setValue(*reinterpret_cast< double*>(_v)); break;
        default: break;
        }
    } else if (_c == QMetaObject::ResetProperty) {
    }
#endif // QT_NO_PROPERTIES
}

const QMetaObject QwtThermo::staticMetaObject = {
    { &QWidget::staticMetaObject, qt_meta_stringdata_QwtThermo.data,
      qt_meta_data_QwtThermo,  qt_static_metacall, Q_NULLPTR, Q_NULLPTR}
};


const QMetaObject *QwtThermo::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->dynamicMetaObject() : &staticMetaObject;
}

void *QwtThermo::qt_metacast(const char *_clname)
{
    if (!_clname) return Q_NULLPTR;
    if (!strcmp(_clname, qt_meta_stringdata_QwtThermo.stringdata0))
        return static_cast<void*>(const_cast< QwtThermo*>(this));
    if (!strcmp(_clname, "QwtAbstractScale"))
        return static_cast< QwtAbstractScale*>(const_cast< QwtThermo*>(this));
    return QWidget::qt_metacast(_clname);
}

int QwtThermo::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = QWidget::qt_metacall(_c, _id, _a);
    if (_id < 0)
        return _id;
    if (_c == QMetaObject::InvokeMetaMethod) {
        if (_id < 1)
            qt_static_metacall(this, _c, _id, _a);
        _id -= 1;
    } else if (_c == QMetaObject::RegisterMethodArgumentMetaType) {
        if (_id < 1)
            *reinterpret_cast<int*>(_a[0]) = -1;
        _id -= 1;
    }
#ifndef QT_NO_PROPERTIES
   else if (_c == QMetaObject::ReadProperty || _c == QMetaObject::WriteProperty
            || _c == QMetaObject::ResetProperty || _c == QMetaObject::RegisterPropertyMetaType) {
        qt_static_metacall(this, _c, _id, _a);
        _id -= 9;
    } else if (_c == QMetaObject::QueryPropertyDesignable) {
        _id -= 9;
    } else if (_c == QMetaObject::QueryPropertyScriptable) {
        _id -= 9;
    } else if (_c == QMetaObject::QueryPropertyStored) {
        _id -= 9;
    } else if (_c == QMetaObject::QueryPropertyEditable) {
        _id -= 9;
    } else if (_c == QMetaObject::QueryPropertyUser) {
        _id -= 9;
    }
#endif // QT_NO_PROPERTIES
    return _id;
}
QT_END_MOC_NAMESPACE
