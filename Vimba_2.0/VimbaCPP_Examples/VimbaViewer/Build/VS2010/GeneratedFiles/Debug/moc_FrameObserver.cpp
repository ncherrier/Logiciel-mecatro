/****************************************************************************
** Meta object code from reading C++ file 'FrameObserver.h'
**
** Created by: The Qt Meta Object Compiler version 67 (Qt 5.5.1)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include "../../../../Source/FrameObserver.h"
#include <QtCore/qbytearray.h>
#include <QtCore/qmetatype.h>
#include <QtCore/QVector>
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'FrameObserver.h' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 67
#error "This file was generated using the moc from 5.5.1. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

QT_BEGIN_MOC_NAMESPACE
struct qt_meta_stringdata_HelperThread_t {
    QByteArrayData data[7];
    char stringdata0[64];
};
#define QT_MOC_LITERAL(idx, ofs, len) \
    Q_STATIC_BYTE_ARRAY_DATA_HEADER_INITIALIZER_WITH_OFFSET(len, \
    qptrdiff(offsetof(qt_meta_stringdata_HelperThread_t, stringdata0) + ofs \
        - idx * sizeof(QByteArrayData)) \
    )
static const qt_meta_stringdata_HelperThread_t qt_meta_stringdata_HelperThread = {
    {
QT_MOC_LITERAL(0, 0, 12), // "HelperThread"
QT_MOC_LITERAL(1, 13, 20), // "frameReadyFromThread"
QT_MOC_LITERAL(2, 34, 0), // ""
QT_MOC_LITERAL(3, 35, 5), // "image"
QT_MOC_LITERAL(4, 41, 7), // "sFormat"
QT_MOC_LITERAL(5, 49, 7), // "sHeight"
QT_MOC_LITERAL(6, 57, 6) // "sWidth"

    },
    "HelperThread\0frameReadyFromThread\0\0"
    "image\0sFormat\0sHeight\0sWidth"
};
#undef QT_MOC_LITERAL

static const uint qt_meta_data_HelperThread[] = {

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
       1,    4,   19,    2, 0x06 /* Public */,

 // signals: parameters
    QMetaType::Void, QMetaType::QImage, QMetaType::QString, QMetaType::QString, QMetaType::QString,    3,    4,    5,    6,

       0        // eod
};

void HelperThread::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::InvokeMetaMethod) {
        HelperThread *_t = static_cast<HelperThread *>(_o);
        Q_UNUSED(_t)
        switch (_id) {
        case 0: _t->frameReadyFromThread((*reinterpret_cast< QImage(*)>(_a[1])),(*reinterpret_cast< const QString(*)>(_a[2])),(*reinterpret_cast< const QString(*)>(_a[3])),(*reinterpret_cast< const QString(*)>(_a[4]))); break;
        default: ;
        }
    } else if (_c == QMetaObject::IndexOfMethod) {
        int *result = reinterpret_cast<int *>(_a[0]);
        void **func = reinterpret_cast<void **>(_a[1]);
        {
            typedef void (HelperThread::*_t)(QImage , const QString & , const QString & , const QString & );
            if (*reinterpret_cast<_t *>(func) == static_cast<_t>(&HelperThread::frameReadyFromThread)) {
                *result = 0;
            }
        }
    }
}

const QMetaObject HelperThread::staticMetaObject = {
    { &QThread::staticMetaObject, qt_meta_stringdata_HelperThread.data,
      qt_meta_data_HelperThread,  qt_static_metacall, Q_NULLPTR, Q_NULLPTR}
};


const QMetaObject *HelperThread::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->dynamicMetaObject() : &staticMetaObject;
}

void *HelperThread::qt_metacast(const char *_clname)
{
    if (!_clname) return Q_NULLPTR;
    if (!strcmp(_clname, qt_meta_stringdata_HelperThread.stringdata0))
        return static_cast<void*>(const_cast< HelperThread*>(this));
    return QThread::qt_metacast(_clname);
}

int HelperThread::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
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
            *reinterpret_cast<int*>(_a[0]) = -1;
        _id -= 1;
    }
    return _id;
}

// SIGNAL 0
void HelperThread::frameReadyFromThread(QImage _t1, const QString & _t2, const QString & _t3, const QString & _t4)
{
    void *_a[] = { Q_NULLPTR, const_cast<void*>(reinterpret_cast<const void*>(&_t1)), const_cast<void*>(reinterpret_cast<const void*>(&_t2)), const_cast<void*>(reinterpret_cast<const void*>(&_t3)), const_cast<void*>(reinterpret_cast<const void*>(&_t4)) };
    QMetaObject::activate(this, &staticMetaObject, 0, _a);
}
struct qt_meta_stringdata_FrameObserver_t {
    QByteArrayData data[21];
    char stringdata0[298];
};
#define QT_MOC_LITERAL(idx, ofs, len) \
    Q_STATIC_BYTE_ARRAY_DATA_HEADER_INITIALIZER_WITH_OFFSET(len, \
    qptrdiff(offsetof(qt_meta_stringdata_FrameObserver_t, stringdata0) + ofs \
        - idx * sizeof(QByteArrayData)) \
    )
static const qt_meta_stringdata_FrameObserver_t qt_meta_stringdata_FrameObserver = {
    {
QT_MOC_LITERAL(0, 0, 13), // "FrameObserver"
QT_MOC_LITERAL(1, 14, 22), // "frameReadyFromObserver"
QT_MOC_LITERAL(2, 37, 0), // ""
QT_MOC_LITERAL(3, 38, 5), // "image"
QT_MOC_LITERAL(4, 44, 7), // "sFormat"
QT_MOC_LITERAL(5, 52, 7), // "sHeight"
QT_MOC_LITERAL(6, 60, 6), // "sWidth"
QT_MOC_LITERAL(7, 67, 13), // "setCurrentFPS"
QT_MOC_LITERAL(8, 81, 4), // "sFPS"
QT_MOC_LITERAL(9, 86, 15), // "setFrameCounter"
QT_MOC_LITERAL(10, 102, 6), // "nFrame"
QT_MOC_LITERAL(11, 109, 25), // "histogramDataFromObserver"
QT_MOC_LITERAL(12, 135, 26), // "QVector<QVector<quint32> >"
QT_MOC_LITERAL(13, 162, 8), // "histData"
QT_MOC_LITERAL(14, 171, 15), // "sHistogramTitle"
QT_MOC_LITERAL(15, 187, 16), // "nMaxHeight_YAxis"
QT_MOC_LITERAL(16, 204, 15), // "nMaxWidth_XAxis"
QT_MOC_LITERAL(17, 220, 20), // "QVector<QStringList>"
QT_MOC_LITERAL(18, 241, 10), // "statistics"
QT_MOC_LITERAL(19, 252, 18), // "getFrameFromThread"
QT_MOC_LITERAL(20, 271, 26) // "getHistogramDataFromThread"

    },
    "FrameObserver\0frameReadyFromObserver\0"
    "\0image\0sFormat\0sHeight\0sWidth\0"
    "setCurrentFPS\0sFPS\0setFrameCounter\0"
    "nFrame\0histogramDataFromObserver\0"
    "QVector<QVector<quint32> >\0histData\0"
    "sHistogramTitle\0nMaxHeight_YAxis\0"
    "nMaxWidth_XAxis\0QVector<QStringList>\0"
    "statistics\0getFrameFromThread\0"
    "getHistogramDataFromThread"
};
#undef QT_MOC_LITERAL

static const uint qt_meta_data_FrameObserver[] = {

 // content:
       7,       // revision
       0,       // classname
       0,    0, // classinfo
       6,   14, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       4,       // signalCount

 // signals: name, argc, parameters, tag, flags
       1,    4,   44,    2, 0x06 /* Public */,
       7,    1,   53,    2, 0x06 /* Public */,
       9,    1,   56,    2, 0x06 /* Public */,
      11,    5,   59,    2, 0x06 /* Public */,

 // slots: name, argc, parameters, tag, flags
      19,    4,   70,    2, 0x08 /* Private */,
      20,    5,   79,    2, 0x08 /* Private */,

 // signals: parameters
    QMetaType::Void, QMetaType::QImage, QMetaType::QString, QMetaType::QString, QMetaType::QString,    3,    4,    5,    6,
    QMetaType::Void, QMetaType::QString,    8,
    QMetaType::Void, QMetaType::UInt,   10,
    QMetaType::Void, 0x80000000 | 12, QMetaType::QString, QMetaType::Double, QMetaType::Double, 0x80000000 | 17,   13,   14,   15,   16,   18,

 // slots: parameters
    QMetaType::Void, QMetaType::QImage, QMetaType::QString, QMetaType::QString, QMetaType::QString,    3,    4,    5,    6,
    QMetaType::Void, 0x80000000 | 12, QMetaType::QString, QMetaType::Double, QMetaType::Double, 0x80000000 | 17,   13,   14,   15,   16,   18,

       0        // eod
};

void FrameObserver::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::InvokeMetaMethod) {
        FrameObserver *_t = static_cast<FrameObserver *>(_o);
        Q_UNUSED(_t)
        switch (_id) {
        case 0: _t->frameReadyFromObserver((*reinterpret_cast< QImage(*)>(_a[1])),(*reinterpret_cast< const QString(*)>(_a[2])),(*reinterpret_cast< const QString(*)>(_a[3])),(*reinterpret_cast< const QString(*)>(_a[4]))); break;
        case 1: _t->setCurrentFPS((*reinterpret_cast< const QString(*)>(_a[1]))); break;
        case 2: _t->setFrameCounter((*reinterpret_cast< const uint(*)>(_a[1]))); break;
        case 3: _t->histogramDataFromObserver((*reinterpret_cast< const QVector<QVector<quint32> >(*)>(_a[1])),(*reinterpret_cast< const QString(*)>(_a[2])),(*reinterpret_cast< const double(*)>(_a[3])),(*reinterpret_cast< const double(*)>(_a[4])),(*reinterpret_cast< const QVector<QStringList>(*)>(_a[5]))); break;
        case 4: _t->getFrameFromThread((*reinterpret_cast< QImage(*)>(_a[1])),(*reinterpret_cast< const QString(*)>(_a[2])),(*reinterpret_cast< const QString(*)>(_a[3])),(*reinterpret_cast< const QString(*)>(_a[4]))); break;
        case 5: _t->getHistogramDataFromThread((*reinterpret_cast< const QVector<QVector<quint32> >(*)>(_a[1])),(*reinterpret_cast< const QString(*)>(_a[2])),(*reinterpret_cast< const double(*)>(_a[3])),(*reinterpret_cast< const double(*)>(_a[4])),(*reinterpret_cast< const QVector<QStringList>(*)>(_a[5]))); break;
        default: ;
        }
    } else if (_c == QMetaObject::RegisterMethodArgumentMetaType) {
        switch (_id) {
        default: *reinterpret_cast<int*>(_a[0]) = -1; break;
        case 3:
            switch (*reinterpret_cast<int*>(_a[1])) {
            default: *reinterpret_cast<int*>(_a[0]) = -1; break;
            case 4:
                *reinterpret_cast<int*>(_a[0]) = qRegisterMetaType< QVector<QStringList> >(); break;
            case 0:
                *reinterpret_cast<int*>(_a[0]) = qRegisterMetaType< QVector<QVector<quint32> > >(); break;
            }
            break;
        case 5:
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
            typedef void (FrameObserver::*_t)(QImage , const QString & , const QString & , const QString & );
            if (*reinterpret_cast<_t *>(func) == static_cast<_t>(&FrameObserver::frameReadyFromObserver)) {
                *result = 0;
            }
        }
        {
            typedef void (FrameObserver::*_t)(const QString & );
            if (*reinterpret_cast<_t *>(func) == static_cast<_t>(&FrameObserver::setCurrentFPS)) {
                *result = 1;
            }
        }
        {
            typedef void (FrameObserver::*_t)(const unsigned int & );
            if (*reinterpret_cast<_t *>(func) == static_cast<_t>(&FrameObserver::setFrameCounter)) {
                *result = 2;
            }
        }
        {
            typedef void (FrameObserver::*_t)(const QVector<QVector<quint32> > & , const QString & , const double & , const double & , const QVector<QStringList> & );
            if (*reinterpret_cast<_t *>(func) == static_cast<_t>(&FrameObserver::histogramDataFromObserver)) {
                *result = 3;
            }
        }
    }
}

const QMetaObject FrameObserver::staticMetaObject = {
    { &QObject::staticMetaObject, qt_meta_stringdata_FrameObserver.data,
      qt_meta_data_FrameObserver,  qt_static_metacall, Q_NULLPTR, Q_NULLPTR}
};


const QMetaObject *FrameObserver::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->dynamicMetaObject() : &staticMetaObject;
}

void *FrameObserver::qt_metacast(const char *_clname)
{
    if (!_clname) return Q_NULLPTR;
    if (!strcmp(_clname, qt_meta_stringdata_FrameObserver.stringdata0))
        return static_cast<void*>(const_cast< FrameObserver*>(this));
    if (!strcmp(_clname, "AVT::VmbAPI::IFrameObserver"))
        return static_cast< AVT::VmbAPI::IFrameObserver*>(const_cast< FrameObserver*>(this));
    return QObject::qt_metacast(_clname);
}

int FrameObserver::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = QObject::qt_metacall(_c, _id, _a);
    if (_id < 0)
        return _id;
    if (_c == QMetaObject::InvokeMetaMethod) {
        if (_id < 6)
            qt_static_metacall(this, _c, _id, _a);
        _id -= 6;
    } else if (_c == QMetaObject::RegisterMethodArgumentMetaType) {
        if (_id < 6)
            qt_static_metacall(this, _c, _id, _a);
        _id -= 6;
    }
    return _id;
}

// SIGNAL 0
void FrameObserver::frameReadyFromObserver(QImage _t1, const QString & _t2, const QString & _t3, const QString & _t4)
{
    void *_a[] = { Q_NULLPTR, const_cast<void*>(reinterpret_cast<const void*>(&_t1)), const_cast<void*>(reinterpret_cast<const void*>(&_t2)), const_cast<void*>(reinterpret_cast<const void*>(&_t3)), const_cast<void*>(reinterpret_cast<const void*>(&_t4)) };
    QMetaObject::activate(this, &staticMetaObject, 0, _a);
}

// SIGNAL 1
void FrameObserver::setCurrentFPS(const QString & _t1)
{
    void *_a[] = { Q_NULLPTR, const_cast<void*>(reinterpret_cast<const void*>(&_t1)) };
    QMetaObject::activate(this, &staticMetaObject, 1, _a);
}

// SIGNAL 2
void FrameObserver::setFrameCounter(const unsigned int & _t1)
{
    void *_a[] = { Q_NULLPTR, const_cast<void*>(reinterpret_cast<const void*>(&_t1)) };
    QMetaObject::activate(this, &staticMetaObject, 2, _a);
}

// SIGNAL 3
void FrameObserver::histogramDataFromObserver(const QVector<QVector<quint32> > & _t1, const QString & _t2, const double & _t3, const double & _t4, const QVector<QStringList> & _t5)
{
    void *_a[] = { Q_NULLPTR, const_cast<void*>(reinterpret_cast<const void*>(&_t1)), const_cast<void*>(reinterpret_cast<const void*>(&_t2)), const_cast<void*>(reinterpret_cast<const void*>(&_t3)), const_cast<void*>(reinterpret_cast<const void*>(&_t4)), const_cast<void*>(reinterpret_cast<const void*>(&_t5)) };
    QMetaObject::activate(this, &staticMetaObject, 3, _a);
}
QT_END_MOC_NAMESPACE
