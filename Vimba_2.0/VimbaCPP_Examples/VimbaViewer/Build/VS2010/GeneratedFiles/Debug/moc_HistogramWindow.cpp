/****************************************************************************
** Meta object code from reading C++ file 'HistogramWindow.h'
**
** Created by: The Qt Meta Object Compiler version 67 (Qt 5.5.1)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include "../../../../Source/UI/Histogram/HistogramWindow.h"
#include <QtCore/qbytearray.h>
#include <QtCore/qmetatype.h>
#include <QtCore/QVector>
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'HistogramWindow.h' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 67
#error "This file was generated using the moc from 5.5.1. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

QT_BEGIN_MOC_NAMESPACE
struct qt_meta_stringdata_HistogramWindow_t {
    QByteArrayData data[12];
    char stringdata0[172];
};
#define QT_MOC_LITERAL(idx, ofs, len) \
    Q_STATIC_BYTE_ARRAY_DATA_HEADER_INITIALIZER_WITH_OFFSET(len, \
    qptrdiff(offsetof(qt_meta_stringdata_HistogramWindow_t, stringdata0) + ofs \
        - idx * sizeof(QByteArrayData)) \
    )
static const qt_meta_stringdata_HistogramWindow_t qt_meta_stringdata_HistogramWindow = {
    {
QT_MOC_LITERAL(0, 0, 15), // "HistogramWindow"
QT_MOC_LITERAL(1, 16, 7), // "onPrint"
QT_MOC_LITERAL(2, 24, 0), // ""
QT_MOC_LITERAL(3, 25, 8), // "onExport"
QT_MOC_LITERAL(4, 34, 15), // "updateHistogram"
QT_MOC_LITERAL(5, 50, 26), // "QVector<QVector<quint32> >"
QT_MOC_LITERAL(6, 77, 13), // "histogramData"
QT_MOC_LITERAL(7, 91, 18), // "sNewHistogramTitle"
QT_MOC_LITERAL(8, 110, 16), // "nMaxHeight_YAxis"
QT_MOC_LITERAL(9, 127, 15), // "nMaxWidth_XAxis"
QT_MOC_LITERAL(10, 143, 21), // "onAutoScaleYAxisClick"
QT_MOC_LITERAL(11, 165, 6) // "bValue"

    },
    "HistogramWindow\0onPrint\0\0onExport\0"
    "updateHistogram\0QVector<QVector<quint32> >\0"
    "histogramData\0sNewHistogramTitle\0"
    "nMaxHeight_YAxis\0nMaxWidth_XAxis\0"
    "onAutoScaleYAxisClick\0bValue"
};
#undef QT_MOC_LITERAL

static const uint qt_meta_data_HistogramWindow[] = {

 // content:
       7,       // revision
       0,       // classname
       0,    0, // classinfo
       4,   14, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       0,       // signalCount

 // slots: name, argc, parameters, tag, flags
       1,    0,   34,    2, 0x08 /* Private */,
       3,    0,   35,    2, 0x08 /* Private */,
       4,    4,   36,    2, 0x0a /* Public */,
      10,    1,   45,    2, 0x0a /* Public */,

 // slots: parameters
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void, 0x80000000 | 5, QMetaType::QString, QMetaType::Double, QMetaType::Double,    6,    7,    8,    9,
    QMetaType::Void, QMetaType::Bool,   11,

       0        // eod
};

void HistogramWindow::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::InvokeMetaMethod) {
        HistogramWindow *_t = static_cast<HistogramWindow *>(_o);
        Q_UNUSED(_t)
        switch (_id) {
        case 0: _t->onPrint(); break;
        case 1: _t->onExport(); break;
        case 2: _t->updateHistogram((*reinterpret_cast< const QVector<QVector<quint32> >(*)>(_a[1])),(*reinterpret_cast< const QString(*)>(_a[2])),(*reinterpret_cast< const double(*)>(_a[3])),(*reinterpret_cast< const double(*)>(_a[4]))); break;
        case 3: _t->onAutoScaleYAxisClick((*reinterpret_cast< bool(*)>(_a[1]))); break;
        default: ;
        }
    } else if (_c == QMetaObject::RegisterMethodArgumentMetaType) {
        switch (_id) {
        default: *reinterpret_cast<int*>(_a[0]) = -1; break;
        case 2:
            switch (*reinterpret_cast<int*>(_a[1])) {
            default: *reinterpret_cast<int*>(_a[0]) = -1; break;
            case 0:
                *reinterpret_cast<int*>(_a[0]) = qRegisterMetaType< QVector<QVector<quint32> > >(); break;
            }
            break;
        }
    }
}

const QMetaObject HistogramWindow::staticMetaObject = {
    { &QWidget::staticMetaObject, qt_meta_stringdata_HistogramWindow.data,
      qt_meta_data_HistogramWindow,  qt_static_metacall, Q_NULLPTR, Q_NULLPTR}
};


const QMetaObject *HistogramWindow::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->dynamicMetaObject() : &staticMetaObject;
}

void *HistogramWindow::qt_metacast(const char *_clname)
{
    if (!_clname) return Q_NULLPTR;
    if (!strcmp(_clname, qt_meta_stringdata_HistogramWindow.stringdata0))
        return static_cast<void*>(const_cast< HistogramWindow*>(this));
    return QWidget::qt_metacast(_clname);
}

int HistogramWindow::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = QWidget::qt_metacall(_c, _id, _a);
    if (_id < 0)
        return _id;
    if (_c == QMetaObject::InvokeMetaMethod) {
        if (_id < 4)
            qt_static_metacall(this, _c, _id, _a);
        _id -= 4;
    } else if (_c == QMetaObject::RegisterMethodArgumentMetaType) {
        if (_id < 4)
            qt_static_metacall(this, _c, _id, _a);
        _id -= 4;
    }
    return _id;
}
QT_END_MOC_NAMESPACE
