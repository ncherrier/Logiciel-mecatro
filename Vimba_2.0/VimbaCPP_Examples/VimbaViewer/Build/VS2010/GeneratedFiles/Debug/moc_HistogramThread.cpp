/****************************************************************************
** Meta object code from reading C++ file 'HistogramThread.h'
**
** Created by: The Qt Meta Object Compiler version 67 (Qt 5.5.1)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include "../../../../Source/UI/Histogram/HistogramThread.h"
#include <QtCore/qbytearray.h>
#include <QtCore/qmetatype.h>
#include <QtCore/QVector>
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'HistogramThread.h' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 67
#error "This file was generated using the moc from 5.5.1. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

QT_BEGIN_MOC_NAMESPACE
struct qt_meta_stringdata_HistogramThread_t {
    QByteArrayData data[10];
    char stringdata0[158];
};
#define QT_MOC_LITERAL(idx, ofs, len) \
    Q_STATIC_BYTE_ARRAY_DATA_HEADER_INITIALIZER_WITH_OFFSET(len, \
    qptrdiff(offsetof(qt_meta_stringdata_HistogramThread_t, stringdata0) + ofs \
        - idx * sizeof(QByteArrayData)) \
    )
static const qt_meta_stringdata_HistogramThread_t qt_meta_stringdata_HistogramThread = {
    {
QT_MOC_LITERAL(0, 0, 15), // "HistogramThread"
QT_MOC_LITERAL(1, 16, 23), // "histogramDataFromThread"
QT_MOC_LITERAL(2, 40, 0), // ""
QT_MOC_LITERAL(3, 41, 26), // "QVector<QVector<quint32> >"
QT_MOC_LITERAL(4, 68, 8), // "histData"
QT_MOC_LITERAL(5, 77, 15), // "sHistogramTitle"
QT_MOC_LITERAL(6, 93, 16), // "nMaxHeight_YAxis"
QT_MOC_LITERAL(7, 110, 15), // "nMaxWidth_XAxis"
QT_MOC_LITERAL(8, 126, 20), // "QVector<QStringList>"
QT_MOC_LITERAL(9, 147, 10) // "statistics"

    },
    "HistogramThread\0histogramDataFromThread\0"
    "\0QVector<QVector<quint32> >\0histData\0"
    "sHistogramTitle\0nMaxHeight_YAxis\0"
    "nMaxWidth_XAxis\0QVector<QStringList>\0"
    "statistics"
};
#undef QT_MOC_LITERAL

static const uint qt_meta_data_HistogramThread[] = {

 // content:
       7,       // revision
       0,       // classname
       0,    0, // classinfo
       1,   14, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       1,       // signalCount

 // signals: name, argc, parameters, tag, flags
       1,    5,   19,    2, 0x06 /* Public */,

 // signals: parameters
    QMetaType::Void, 0x80000000 | 3, QMetaType::QString, QMetaType::Double, QMetaType::Double, 0x80000000 | 8,    4,    5,    6,    7,    9,

       0        // eod
};

void HistogramThread::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::InvokeMetaMethod) {
        HistogramThread *_t = static_cast<HistogramThread *>(_o);
        Q_UNUSED(_t)
        switch (_id) {
        case 0: _t->histogramDataFromThread((*reinterpret_cast< const QVector<QVector<quint32> >(*)>(_a[1])),(*reinterpret_cast< const QString(*)>(_a[2])),(*reinterpret_cast< const double(*)>(_a[3])),(*reinterpret_cast< const double(*)>(_a[4])),(*reinterpret_cast< const QVector<QStringList>(*)>(_a[5]))); break;
        default: ;
        }
    } else if (_c == QMetaObject::RegisterMethodArgumentMetaType) {
        switch (_id) {
        default: *reinterpret_cast<int*>(_a[0]) = -1; break;
        case 0:
            switch (*reinterpret_cast<int*>(_a[1])) {
            default: *reinterpret_cast<int*>(_a[0]) = -1; break;
            case 4:
                *reinterpret_cast<int*>(_a[0]) = qRegisterMetaType< QVector<QStringList> >(); break;
            case 0:
                *reinterpret_cast<int*>(_a[0]) = qRegisterMetaType< QVector<QVector<quint32> > >(); break;
            }
            break;
        }
    } else if (_c == QMetaObject::IndexOfMethod) {
        int *result = reinterpret_cast<int *>(_a[0]);
        void **func = reinterpret_cast<void **>(_a[1]);
        {
            typedef void (HistogramThread::*_t)(const QVector<QVector<quint32> > & , const QString & , const double & , const double & , const QVector<QStringList> & );
            if (*reinterpret_cast<_t *>(func) == static_cast<_t>(&HistogramThread::histogramDataFromThread)) {
                *result = 0;
            }
        }
    }
}

const QMetaObject HistogramThread::staticMetaObject = {
    { &QThread::staticMetaObject, qt_meta_stringdata_HistogramThread.data,
      qt_meta_data_HistogramThread,  qt_static_metacall, Q_NULLPTR, Q_NULLPTR}
};


const QMetaObject *HistogramThread::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->dynamicMetaObject() : &staticMetaObject;
}

void *HistogramThread::qt_metacast(const char *_clname)
{
    if (!_clname) return Q_NULLPTR;
    if (!strcmp(_clname, qt_meta_stringdata_HistogramThread.stringdata0))
        return static_cast<void*>(const_cast< HistogramThread*>(this));
    return QThread::qt_metacast(_clname);
}

int HistogramThread::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = QThread::qt_metacall(_c, _id, _a);
    if (_id < 0)
        return _id;
    if (_c == QMetaObject::InvokeMetaMethod) {
        if (_id < 1)
            qt_static_metacall(this, _c, _id, _a);
        _id -= 1;
    } else if (_c == QMetaObject::RegisterMethodArgumentMetaType) {
        if (_id < 1)
            qt_static_metacall(this, _c, _id, _a);
        _id -= 1;
    }
    return _id;
}

// SIGNAL 0
void HistogramThread::histogramDataFromThread(const QVector<QVector<quint32> > & _t1, const QString & _t2, const double & _t3, const double & _t4, const QVector<QStringList> & _t5)
{
    void *_a[] = { Q_NULLPTR, const_cast<void*>(reinterpret_cast<const void*>(&_t1)), const_cast<void*>(reinterpret_cast<const void*>(&_t2)), const_cast<void*>(reinterpret_cast<const void*>(&_t3)), const_cast<void*>(reinterpret_cast<const void*>(&_t4)), const_cast<void*>(reinterpret_cast<const void*>(&_t5)) };
    QMetaObject::activate(this, &staticMetaObject, 0, _a);
}
QT_END_MOC_NAMESPACE
