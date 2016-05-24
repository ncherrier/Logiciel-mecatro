/****************************************************************************
** Meta object code from reading C++ file 'QHexEdit.h'
**
** Created by: The Qt Meta Object Compiler version 67 (Qt 5.5.1)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include "../../../../Source/UI/HexEditor/QHexEdit.h"
#include <QtCore/qbytearray.h>
#include <QtCore/qmetatype.h>
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'QHexEdit.h' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 67
#error "This file was generated using the moc from 5.5.1. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

QT_BEGIN_MOC_NAMESPACE
struct qt_meta_stringdata_QHexEdit_t {
    QByteArrayData data[28];
    char stringdata0[325];
};
#define QT_MOC_LITERAL(idx, ofs, len) \
    Q_STATIC_BYTE_ARRAY_DATA_HEADER_INITIALIZER_WITH_OFFSET(len, \
    qptrdiff(offsetof(qt_meta_stringdata_QHexEdit_t, stringdata0) + ofs \
        - idx * sizeof(QByteArrayData)) \
    )
static const qt_meta_stringdata_QHexEdit_t qt_meta_stringdata_QHexEdit = {
    {
QT_MOC_LITERAL(0, 0, 8), // "QHexEdit"
QT_MOC_LITERAL(1, 9, 21), // "currentAddressChanged"
QT_MOC_LITERAL(2, 31, 0), // ""
QT_MOC_LITERAL(3, 32, 7), // "address"
QT_MOC_LITERAL(4, 40, 18), // "currentSizeChanged"
QT_MOC_LITERAL(5, 59, 4), // "size"
QT_MOC_LITERAL(6, 64, 11), // "dataChanged"
QT_MOC_LITERAL(7, 76, 20), // "overwriteModeChanged"
QT_MOC_LITERAL(8, 97, 5), // "state"
QT_MOC_LITERAL(9, 103, 4), // "redo"
QT_MOC_LITERAL(10, 108, 15), // "setAddressWidth"
QT_MOC_LITERAL(11, 124, 12), // "addressWidth"
QT_MOC_LITERAL(12, 137, 14), // "setAddressArea"
QT_MOC_LITERAL(13, 152, 11), // "addressArea"
QT_MOC_LITERAL(14, 164, 12), // "setAsciiArea"
QT_MOC_LITERAL(15, 177, 9), // "asciiArea"
QT_MOC_LITERAL(16, 187, 15), // "setHighlighting"
QT_MOC_LITERAL(17, 203, 4), // "mode"
QT_MOC_LITERAL(18, 208, 4), // "undo"
QT_MOC_LITERAL(19, 213, 4), // "data"
QT_MOC_LITERAL(20, 218, 13), // "addressOffset"
QT_MOC_LITERAL(21, 232, 16), // "addressAreaColor"
QT_MOC_LITERAL(22, 249, 14), // "cursorPosition"
QT_MOC_LITERAL(23, 264, 17), // "highlightingColor"
QT_MOC_LITERAL(24, 282, 14), // "selectionColor"
QT_MOC_LITERAL(25, 297, 13), // "overwriteMode"
QT_MOC_LITERAL(26, 311, 8), // "readOnly"
QT_MOC_LITERAL(27, 320, 4) // "font"

    },
    "QHexEdit\0currentAddressChanged\0\0address\0"
    "currentSizeChanged\0size\0dataChanged\0"
    "overwriteModeChanged\0state\0redo\0"
    "setAddressWidth\0addressWidth\0"
    "setAddressArea\0addressArea\0setAsciiArea\0"
    "asciiArea\0setHighlighting\0mode\0undo\0"
    "data\0addressOffset\0addressAreaColor\0"
    "cursorPosition\0highlightingColor\0"
    "selectionColor\0overwriteMode\0readOnly\0"
    "font"
};
#undef QT_MOC_LITERAL

static const uint qt_meta_data_QHexEdit[] = {

 // content:
       7,       // revision
       0,       // classname
       0,    0, // classinfo
      10,   14, // methods
       9,   88, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       4,       // signalCount

 // signals: name, argc, parameters, tag, flags
       1,    1,   64,    2, 0x06 /* Public */,
       4,    1,   67,    2, 0x06 /* Public */,
       6,    0,   70,    2, 0x06 /* Public */,
       7,    1,   71,    2, 0x06 /* Public */,

 // slots: name, argc, parameters, tag, flags
       9,    0,   74,    2, 0x0a /* Public */,
      10,    1,   75,    2, 0x0a /* Public */,
      12,    1,   78,    2, 0x0a /* Public */,
      14,    1,   81,    2, 0x0a /* Public */,
      16,    1,   84,    2, 0x0a /* Public */,
      18,    0,   87,    2, 0x0a /* Public */,

 // signals: parameters
    QMetaType::Void, QMetaType::Int,    3,
    QMetaType::Void, QMetaType::Int,    5,
    QMetaType::Void,
    QMetaType::Void, QMetaType::Bool,    8,

 // slots: parameters
    QMetaType::Void,
    QMetaType::Void, QMetaType::Int,   11,
    QMetaType::Void, QMetaType::Bool,   13,
    QMetaType::Void, QMetaType::Bool,   15,
    QMetaType::Void, QMetaType::Bool,   17,
    QMetaType::Void,

 // properties: name, type, flags
      19, QMetaType::QByteArray, 0x00095103,
      20, QMetaType::Int, 0x00095103,
      21, QMetaType::QColor, 0x00095103,
      22, QMetaType::Int, 0x00095103,
      23, QMetaType::QColor, 0x00095103,
      24, QMetaType::QColor, 0x00095103,
      25, QMetaType::Bool, 0x00095103,
      26, QMetaType::Bool, 0x00095103,
      27, QMetaType::QFont, 0x00095103,

       0        // eod
};

void QHexEdit::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::InvokeMetaMethod) {
        QHexEdit *_t = static_cast<QHexEdit *>(_o);
        Q_UNUSED(_t)
        switch (_id) {
        case 0: _t->currentAddressChanged((*reinterpret_cast< int(*)>(_a[1]))); break;
        case 1: _t->currentSizeChanged((*reinterpret_cast< int(*)>(_a[1]))); break;
        case 2: _t->dataChanged(); break;
        case 3: _t->overwriteModeChanged((*reinterpret_cast< bool(*)>(_a[1]))); break;
        case 4: _t->redo(); break;
        case 5: _t->setAddressWidth((*reinterpret_cast< int(*)>(_a[1]))); break;
        case 6: _t->setAddressArea((*reinterpret_cast< bool(*)>(_a[1]))); break;
        case 7: _t->setAsciiArea((*reinterpret_cast< bool(*)>(_a[1]))); break;
        case 8: _t->setHighlighting((*reinterpret_cast< bool(*)>(_a[1]))); break;
        case 9: _t->undo(); break;
        default: ;
        }
    } else if (_c == QMetaObject::IndexOfMethod) {
        int *result = reinterpret_cast<int *>(_a[0]);
        void **func = reinterpret_cast<void **>(_a[1]);
        {
            typedef void (QHexEdit::*_t)(int );
            if (*reinterpret_cast<_t *>(func) == static_cast<_t>(&QHexEdit::currentAddressChanged)) {
                *result = 0;
            }
        }
        {
            typedef void (QHexEdit::*_t)(int );
            if (*reinterpret_cast<_t *>(func) == static_cast<_t>(&QHexEdit::currentSizeChanged)) {
                *result = 1;
            }
        }
        {
            typedef void (QHexEdit::*_t)();
            if (*reinterpret_cast<_t *>(func) == static_cast<_t>(&QHexEdit::dataChanged)) {
                *result = 2;
            }
        }
        {
            typedef void (QHexEdit::*_t)(bool );
            if (*reinterpret_cast<_t *>(func) == static_cast<_t>(&QHexEdit::overwriteModeChanged)) {
                *result = 3;
            }
        }
    }
#ifndef QT_NO_PROPERTIES
    else if (_c == QMetaObject::ReadProperty) {
        QHexEdit *_t = static_cast<QHexEdit *>(_o);
        Q_UNUSED(_t)
        void *_v = _a[0];
        switch (_id) {
        case 0: *reinterpret_cast< QByteArray*>(_v) = _t->data(); break;
        case 1: *reinterpret_cast< int*>(_v) = _t->addressOffset(); break;
        case 2: *reinterpret_cast< QColor*>(_v) = _t->addressAreaColor(); break;
        case 3: *reinterpret_cast< int*>(_v) = _t->cursorPosition(); break;
        case 4: *reinterpret_cast< QColor*>(_v) = _t->highlightingColor(); break;
        case 5: *reinterpret_cast< QColor*>(_v) = _t->selectionColor(); break;
        case 6: *reinterpret_cast< bool*>(_v) = _t->overwriteMode(); break;
        case 7: *reinterpret_cast< bool*>(_v) = _t->isReadOnly(); break;
        case 8: *reinterpret_cast< QFont*>(_v) = _t->font(); break;
        default: break;
        }
    } else if (_c == QMetaObject::WriteProperty) {
        QHexEdit *_t = static_cast<QHexEdit *>(_o);
        Q_UNUSED(_t)
        void *_v = _a[0];
        switch (_id) {
        case 0: _t->setData(*reinterpret_cast< QByteArray*>(_v)); break;
        case 1: _t->setAddressOffset(*reinterpret_cast< int*>(_v)); break;
        case 2: _t->setAddressAreaColor(*reinterpret_cast< QColor*>(_v)); break;
        case 3: _t->setCursorPosition(*reinterpret_cast< int*>(_v)); break;
        case 4: _t->setHighlightingColor(*reinterpret_cast< QColor*>(_v)); break;
        case 5: _t->setSelectionColor(*reinterpret_cast< QColor*>(_v)); break;
        case 6: _t->setOverwriteMode(*reinterpret_cast< bool*>(_v)); break;
        case 7: _t->setReadOnly(*reinterpret_cast< bool*>(_v)); break;
        case 8: _t->setFont(*reinterpret_cast< QFont*>(_v)); break;
        default: break;
        }
    } else if (_c == QMetaObject::ResetProperty) {
    }
#endif // QT_NO_PROPERTIES
}

const QMetaObject QHexEdit::staticMetaObject = {
    { &QScrollArea::staticMetaObject, qt_meta_stringdata_QHexEdit.data,
      qt_meta_data_QHexEdit,  qt_static_metacall, Q_NULLPTR, Q_NULLPTR}
};


const QMetaObject *QHexEdit::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->dynamicMetaObject() : &staticMetaObject;
}

void *QHexEdit::qt_metacast(const char *_clname)
{
    if (!_clname) return Q_NULLPTR;
    if (!strcmp(_clname, qt_meta_stringdata_QHexEdit.stringdata0))
        return static_cast<void*>(const_cast< QHexEdit*>(this));
    return QScrollArea::qt_metacast(_clname);
}

int QHexEdit::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = QScrollArea::qt_metacall(_c, _id, _a);
    if (_id < 0)
        return _id;
    if (_c == QMetaObject::InvokeMetaMethod) {
        if (_id < 10)
            qt_static_metacall(this, _c, _id, _a);
        _id -= 10;
    } else if (_c == QMetaObject::RegisterMethodArgumentMetaType) {
        if (_id < 10)
            *reinterpret_cast<int*>(_a[0]) = -1;
        _id -= 10;
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

// SIGNAL 0
void QHexEdit::currentAddressChanged(int _t1)
{
    void *_a[] = { Q_NULLPTR, const_cast<void*>(reinterpret_cast<const void*>(&_t1)) };
    QMetaObject::activate(this, &staticMetaObject, 0, _a);
}

// SIGNAL 1
void QHexEdit::currentSizeChanged(int _t1)
{
    void *_a[] = { Q_NULLPTR, const_cast<void*>(reinterpret_cast<const void*>(&_t1)) };
    QMetaObject::activate(this, &staticMetaObject, 1, _a);
}

// SIGNAL 2
void QHexEdit::dataChanged()
{
    QMetaObject::activate(this, &staticMetaObject, 2, Q_NULLPTR);
}

// SIGNAL 3
void QHexEdit::overwriteModeChanged(bool _t1)
{
    void *_a[] = { Q_NULLPTR, const_cast<void*>(reinterpret_cast<const void*>(&_t1)) };
    QMetaObject::activate(this, &staticMetaObject, 3, _a);
}
QT_END_MOC_NAMESPACE
