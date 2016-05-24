/****************************************************************************
** Meta object code from reading C++ file 'qwt_abstract_slider.h'
**
** Created by: The Qt Meta Object Compiler version 67 (Qt 5.5.1)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include "../../../../Source/ExternLib/qwt/qwt_abstract_slider.h"
#include <QtCore/qbytearray.h>
#include <QtCore/qmetatype.h>
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'qwt_abstract_slider.h' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 67
#error "This file was generated using the moc from 5.5.1. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

QT_BEGIN_MOC_NAMESPACE
struct qt_meta_stringdata_QwtAbstractSlider_t {
    QByteArrayData data[18];
    char stringdata0[176];
};
#define QT_MOC_LITERAL(idx, ofs, len) \
    Q_STATIC_BYTE_ARRAY_DATA_HEADER_INITIALIZER_WITH_OFFSET(len, \
    qptrdiff(offsetof(qt_meta_stringdata_QwtAbstractSlider_t, stringdata0) + ofs \
        - idx * sizeof(QByteArrayData)) \
    )
static const qt_meta_stringdata_QwtAbstractSlider_t qt_meta_stringdata_QwtAbstractSlider = {
    {
QT_MOC_LITERAL(0, 0, 17), // "QwtAbstractSlider"
QT_MOC_LITERAL(1, 18, 12), // "valueChanged"
QT_MOC_LITERAL(2, 31, 0), // ""
QT_MOC_LITERAL(3, 32, 5), // "value"
QT_MOC_LITERAL(4, 38, 13), // "sliderPressed"
QT_MOC_LITERAL(5, 52, 14), // "sliderReleased"
QT_MOC_LITERAL(6, 67, 11), // "sliderMoved"
QT_MOC_LITERAL(7, 79, 8), // "setValue"
QT_MOC_LITERAL(8, 88, 3), // "val"
QT_MOC_LITERAL(9, 92, 8), // "fitValue"
QT_MOC_LITERAL(10, 101, 8), // "incValue"
QT_MOC_LITERAL(11, 110, 5), // "steps"
QT_MOC_LITERAL(12, 116, 11), // "setReadOnly"
QT_MOC_LITERAL(13, 128, 8), // "readOnly"
QT_MOC_LITERAL(14, 137, 5), // "valid"
QT_MOC_LITERAL(15, 143, 4), // "mass"
QT_MOC_LITERAL(16, 148, 11), // "orientation"
QT_MOC_LITERAL(17, 160, 15) // "Qt::Orientation"

    },
    "QwtAbstractSlider\0valueChanged\0\0value\0"
    "sliderPressed\0sliderReleased\0sliderMoved\0"
    "setValue\0val\0fitValue\0incValue\0steps\0"
    "setReadOnly\0readOnly\0valid\0mass\0"
    "orientation\0Qt::Orientation"
};
#undef QT_MOC_LITERAL

static const uint qt_meta_data_QwtAbstractSlider[] = {

 // content:
       7,       // revision
       0,       // classname
       0,    0, // classinfo
       8,   14, // methods
       4,   74, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       4,       // signalCount

 // signals: name, argc, parameters, tag, flags
       1,    1,   54,    2, 0x06 /* Public */,
       4,    0,   57,    2, 0x06 /* Public */,
       5,    0,   58,    2, 0x06 /* Public */,
       6,    1,   59,    2, 0x06 /* Public */,

 // slots: name, argc, parameters, tag, flags
       7,    1,   62,    2, 0x0a /* Public */,
       9,    1,   65,    2, 0x0a /* Public */,
      10,    1,   68,    2, 0x0a /* Public */,
      12,    1,   71,    2, 0x0a /* Public */,

 // signals: parameters
    QMetaType::Void, QMetaType::Double,    3,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void, QMetaType::Double,    3,

 // slots: parameters
    QMetaType::Void, QMetaType::Double,    8,
    QMetaType::Void, QMetaType::Double,    8,
    QMetaType::Void, QMetaType::Int,   11,
    QMetaType::Void, QMetaType::Bool,    2,

 // properties: name, type, flags
      13, QMetaType::Bool, 0x00095103,
      14, QMetaType::Bool, 0x00095103,
      15, QMetaType::Double, 0x00095103,
      16, 0x80000000 | 17, 0x0009510b,

       0        // eod
};

void QwtAbstractSlider::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::InvokeMetaMethod) {
        QwtAbstractSlider *_t = static_cast<QwtAbstractSlider *>(_o);
        Q_UNUSED(_t)
        switch (_id) {
        case 0: _t->valueChanged((*reinterpret_cast< double(*)>(_a[1]))); break;
        case 1: _t->sliderPressed(); break;
        case 2: _t->sliderReleased(); break;
        case 3: _t->sliderMoved((*reinterpret_cast< double(*)>(_a[1]))); break;
        case 4: _t->setValue((*reinterpret_cast< double(*)>(_a[1]))); break;
        case 5: _t->fitValue((*reinterpret_cast< double(*)>(_a[1]))); break;
        case 6: _t->incValue((*reinterpret_cast< int(*)>(_a[1]))); break;
        case 7: _t->setReadOnly((*reinterpret_cast< bool(*)>(_a[1]))); break;
        default: ;
        }
    } else if (_c == QMetaObject::IndexOfMethod) {
        int *result = reinterpret_cast<int *>(_a[0]);
        void **func = reinterpret_cast<void **>(_a[1]);
        {
            typedef void (QwtAbstractSlider::*_t)(double );
            if (*reinterpret_cast<_t *>(func) == static_cast<_t>(&QwtAbstractSlider::valueChanged)) {
                *result = 0;
            }
        }
        {
            typedef void (QwtAbstractSlider::*_t)();
            if (*reinterpret_cast<_t *>(func) == static_cast<_t>(&QwtAbstractSlider::sliderPressed)) {
                *result = 1;
            }
        }
        {
            typedef void (QwtAbstractSlider::*_t)();
            if (*reinterpret_cast<_t *>(func) == static_cast<_t>(&QwtAbstractSlider::sliderReleased)) {
                *result = 2;
            }
        }
        {
            typedef void (QwtAbstractSlider::*_t)(double );
            if (*reinterpret_cast<_t *>(func) == static_cast<_t>(&QwtAbstractSlider::sliderMoved)) {
                *result = 3;
            }
        }
    }
#ifndef QT_NO_PROPERTIES
    else if (_c == QMetaObject::ReadProperty) {
        QwtAbstractSlider *_t = static_cast<QwtAbstractSlider *>(_o);
        Q_UNUSED(_t)
        void *_v = _a[0];
        switch (_id) {
        case 0: *reinterpret_cast< bool*>(_v) = _t->isReadOnly(); break;
        case 1: *reinterpret_cast< bool*>(_v) = _t->isValid(); break;
        case 2: *reinterpret_cast< double*>(_v) = _t->mass(); break;
        case 3: *reinterpret_cast< Qt::Orientation*>(_v) = _t->orientation(); break;
        default: break;
        }
    } else if (_c == QMetaObject::WriteProperty) {
        QwtAbstractSlider *_t = static_cast<QwtAbstractSlider *>(_o);
        Q_UNUSED(_t)
        void *_v = _a[0];
        switch (_id) {
        case 0: _t->setReadOnly(*reinterpret_cast< bool*>(_v)); break;
        case 1: _t->setValid(*reinterpret_cast< bool*>(_v)); break;
        case 2: _t->setMass(*reinterpret_cast< double*>(_v)); break;
        case 3: _t->setOrientation(*reinterpret_cast< Qt::Orientation*>(_v)); break;
        default: break;
        }
    } else if (_c == QMetaObject::ResetProperty) {
    }
#endif // QT_NO_PROPERTIES
}

const QMetaObject QwtAbstractSlider::staticMetaObject = {
    { &QWidget::staticMetaObject, qt_meta_stringdata_QwtAbstractSlider.data,
      qt_meta_data_QwtAbstractSlider,  qt_static_metacall, Q_NULLPTR, Q_NULLPTR}
};


const QMetaObject *QwtAbstractSlider::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->dynamicMetaObject() : &staticMetaObject;
}

void *QwtAbstractSlider::qt_metacast(const char *_clname)
{
    if (!_clname) return Q_NULLPTR;
    if (!strcmp(_clname, qt_meta_stringdata_QwtAbstractSlider.stringdata0))
        return static_cast<void*>(const_cast< QwtAbstractSlider*>(this));
    if (!strcmp(_clname, "QwtDoubleRange"))
        return static_cast< QwtDoubleRange*>(const_cast< QwtAbstractSlider*>(this));
    return QWidget::qt_metacast(_clname);
}

int QwtAbstractSlider::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = QWidget::qt_metacall(_c, _id, _a);
    if (_id < 0)
        return _id;
    if (_c == QMetaObject::InvokeMetaMethod) {
        if (_id < 8)
            qt_static_metacall(this, _c, _id, _a);
        _id -= 8;
    } else if (_c == QMetaObject::RegisterMethodArgumentMetaType) {
        if (_id < 8)
            *reinterpret_cast<int*>(_a[0]) = -1;
        _id -= 8;
    }
#ifndef QT_NO_PROPERTIES
   else if (_c == QMetaObject::ReadProperty || _c == QMetaObject::WriteProperty
            || _c == QMetaObject::ResetProperty || _c == QMetaObject::RegisterPropertyMetaType) {
        qt_static_metacall(this, _c, _id, _a);
        _id -= 4;
    } else if (_c == QMetaObject::QueryPropertyDesignable) {
        _id -= 4;
    } else if (_c == QMetaObject::QueryPropertyScriptable) {
        _id -= 4;
    } else if (_c == QMetaObject::QueryPropertyStored) {
        _id -= 4;
    } else if (_c == QMetaObject::QueryPropertyEditable) {
        _id -= 4;
    } else if (_c == QMetaObject::QueryPropertyUser) {
        _id -= 4;
    }
#endif // QT_NO_PROPERTIES
    return _id;
}

// SIGNAL 0
void QwtAbstractSlider::valueChanged(double _t1)
{
    void *_a[] = { Q_NULLPTR, const_cast<void*>(reinterpret_cast<const void*>(&_t1)) };
    QMetaObject::activate(this, &staticMetaObject, 0, _a);
}

// SIGNAL 1
void QwtAbstractSlider::sliderPressed()
{
    QMetaObject::activate(this, &staticMetaObject, 1, Q_NULLPTR);
}

// SIGNAL 2
void QwtAbstractSlider::sliderReleased()
{
    QMetaObject::activate(this, &staticMetaObject, 2, Q_NULLPTR);
}

// SIGNAL 3
void QwtAbstractSlider::sliderMoved(double _t1)
{
    void *_a[] = { Q_NULLPTR, const_cast<void*>(reinterpret_cast<const void*>(&_t1)) };
    QMetaObject::activate(this, &staticMetaObject, 3, _a);
}
QT_END_MOC_NAMESPACE
