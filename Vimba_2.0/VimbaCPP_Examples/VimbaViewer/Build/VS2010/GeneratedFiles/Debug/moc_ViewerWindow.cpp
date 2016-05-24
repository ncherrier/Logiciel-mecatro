/****************************************************************************
** Meta object code from reading C++ file 'ViewerWindow.h'
**
** Created by: The Qt Meta Object Compiler version 67 (Qt 5.5.1)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include "../../../../Source/ViewerWindow.h"
#include <QtCore/qbytearray.h>
#include <QtCore/qmetatype.h>
#include <QtCore/QVector>
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'ViewerWindow.h' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 67
#error "This file was generated using the moc from 5.5.1. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

QT_BEGIN_MOC_NAMESPACE
struct qt_meta_stringdata_SaveImageThread_t {
    QByteArrayData data[4];
    char stringdata0[34];
};
#define QT_MOC_LITERAL(idx, ofs, len) \
    Q_STATIC_BYTE_ARRAY_DATA_HEADER_INITIALIZER_WITH_OFFSET(len, \
    qptrdiff(offsetof(qt_meta_stringdata_SaveImageThread_t, stringdata0) + ofs \
        - idx * sizeof(QByteArrayData)) \
    )
static const qt_meta_stringdata_SaveImageThread_t qt_meta_stringdata_SaveImageThread = {
    {
QT_MOC_LITERAL(0, 0, 15), // "SaveImageThread"
QT_MOC_LITERAL(1, 16, 11), // "setPosition"
QT_MOC_LITERAL(2, 28, 0), // ""
QT_MOC_LITERAL(3, 29, 4) // "nPos"

    },
    "SaveImageThread\0setPosition\0\0nPos"
};
#undef QT_MOC_LITERAL

static const uint qt_meta_data_SaveImageThread[] = {

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
       1,    1,   19,    2, 0x06 /* Public */,

 // signals: parameters
    QMetaType::Void, QMetaType::UInt,    3,

       0        // eod
};

void SaveImageThread::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::InvokeMetaMethod) {
        SaveImageThread *_t = static_cast<SaveImageThread *>(_o);
        Q_UNUSED(_t)
        switch (_id) {
        case 0: _t->setPosition((*reinterpret_cast< uint(*)>(_a[1]))); break;
        default: ;
        }
    } else if (_c == QMetaObject::IndexOfMethod) {
        int *result = reinterpret_cast<int *>(_a[0]);
        void **func = reinterpret_cast<void **>(_a[1]);
        {
            typedef void (SaveImageThread::*_t)(unsigned int );
            if (*reinterpret_cast<_t *>(func) == static_cast<_t>(&SaveImageThread::setPosition)) {
                *result = 0;
            }
        }
    }
}

const QMetaObject SaveImageThread::staticMetaObject = {
    { &QThread::staticMetaObject, qt_meta_stringdata_SaveImageThread.data,
      qt_meta_data_SaveImageThread,  qt_static_metacall, Q_NULLPTR, Q_NULLPTR}
};


const QMetaObject *SaveImageThread::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->dynamicMetaObject() : &staticMetaObject;
}

void *SaveImageThread::qt_metacast(const char *_clname)
{
    if (!_clname) return Q_NULLPTR;
    if (!strcmp(_clname, qt_meta_stringdata_SaveImageThread.stringdata0))
        return static_cast<void*>(const_cast< SaveImageThread*>(this));
    return QThread::qt_metacast(_clname);
}

int SaveImageThread::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
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
void SaveImageThread::setPosition(unsigned int _t1)
{
    void *_a[] = { Q_NULLPTR, const_cast<void*>(reinterpret_cast<const void*>(&_t1)) };
    QMetaObject::activate(this, &staticMetaObject, 0, _a);
}
struct qt_meta_stringdata_ViewerWindow_t {
    QByteArrayData data[76];
    char stringdata0[1444];
};
#define QT_MOC_LITERAL(idx, ofs, len) \
    Q_STATIC_BYTE_ARRAY_DATA_HEADER_INITIALIZER_WITH_OFFSET(len, \
    qptrdiff(offsetof(qt_meta_stringdata_ViewerWindow_t, stringdata0) + ofs \
        - idx * sizeof(QByteArrayData)) \
    )
static const qt_meta_stringdata_ViewerWindow_t qt_meta_stringdata_ViewerWindow = {
    {
QT_MOC_LITERAL(0, 0, 12), // "ViewerWindow"
QT_MOC_LITERAL(1, 13, 11), // "closeViewer"
QT_MOC_LITERAL(2, 25, 0), // ""
QT_MOC_LITERAL(3, 26, 3), // "sID"
QT_MOC_LITERAL(4, 30, 26), // "on_ActionFreerun_triggered"
QT_MOC_LITERAL(5, 57, 32), // "on_ActionResetPosition_triggered"
QT_MOC_LITERAL(6, 90, 28), // "on_ActionHistogram_triggered"
QT_MOC_LITERAL(7, 119, 31), // "on_ActionOriginalSize_triggered"
QT_MOC_LITERAL(8, 151, 25), // "on_ActionSaveAs_triggered"
QT_MOC_LITERAL(9, 177, 30), // "on_ActionSaveOptions_triggered"
QT_MOC_LITERAL(10, 208, 29), // "on_ActionSaveImages_triggered"
QT_MOC_LITERAL(11, 238, 27), // "on_ActionRegister_triggered"
QT_MOC_LITERAL(12, 266, 33), // "on_ActionDisplayOptions_trigg..."
QT_MOC_LITERAL(13, 300, 30), // "on_ActionFitToWindow_triggered"
QT_MOC_LITERAL(14, 331, 31), // "on_ActionLeftRotation_triggered"
QT_MOC_LITERAL(15, 363, 32), // "on_ActionRightRotation_triggered"
QT_MOC_LITERAL(16, 396, 26), // "on_ActionZoomOut_triggered"
QT_MOC_LITERAL(17, 423, 25), // "on_ActionZoomIn_triggered"
QT_MOC_LITERAL(18, 449, 37), // "on_ActionLoadCameraSettings_t..."
QT_MOC_LITERAL(19, 487, 37), // "on_ActionSaveCameraSettings_t..."
QT_MOC_LITERAL(20, 525, 41), // "on_ActionLoadCameraSettingsMe..."
QT_MOC_LITERAL(21, 567, 41), // "on_ActionSaveCameraSettingsMe..."
QT_MOC_LITERAL(22, 609, 22), // "onAcquisitionStartStop"
QT_MOC_LITERAL(23, 632, 12), // "sThisFeature"
QT_MOC_LITERAL(24, 645, 21), // "onfloatingDockChanged"
QT_MOC_LITERAL(25, 667, 11), // "bIsFloating"
QT_MOC_LITERAL(26, 679, 19), // "onVisibilityChanged"
QT_MOC_LITERAL(27, 699, 10), // "bIsVisible"
QT_MOC_LITERAL(28, 710, 22), // "displayEveryFrameClick"
QT_MOC_LITERAL(29, 733, 6), // "bValue"
QT_MOC_LITERAL(30, 740, 16), // "onSetDescription"
QT_MOC_LITERAL(31, 757, 5), // "sDesc"
QT_MOC_LITERAL(32, 763, 12), // "onimageReady"
QT_MOC_LITERAL(33, 776, 5), // "image"
QT_MOC_LITERAL(34, 782, 7), // "sFormat"
QT_MOC_LITERAL(35, 790, 7), // "sHeight"
QT_MOC_LITERAL(36, 798, 6), // "sWidth"
QT_MOC_LITERAL(37, 805, 8), // "onSaving"
QT_MOC_LITERAL(38, 814, 4), // "nPos"
QT_MOC_LITERAL(39, 819, 17), // "onSetEventMessage"
QT_MOC_LITERAL(40, 837, 4), // "sMsg"
QT_MOC_LITERAL(41, 842, 15), // "onSetCurrentFPS"
QT_MOC_LITERAL(42, 858, 4), // "sFPS"
QT_MOC_LITERAL(43, 863, 17), // "onSetFrameCounter"
QT_MOC_LITERAL(44, 881, 15), // "nNumberOfFrames"
QT_MOC_LITERAL(45, 897, 12), // "onFeedLogger"
QT_MOC_LITERAL(46, 910, 8), // "sMessage"
QT_MOC_LITERAL(47, 919, 10), // "onResetFPS"
QT_MOC_LITERAL(48, 930, 22), // "getSaveDestinationPath"
QT_MOC_LITERAL(49, 953, 19), // "acceptSaveImagesDlg"
QT_MOC_LITERAL(50, 973, 19), // "rejectSaveImagesDlg"
QT_MOC_LITERAL(51, 993, 17), // "writeRegisterData"
QT_MOC_LITERAL(52, 1011, 16), // "readRegisterData"
QT_MOC_LITERAL(53, 1028, 16), // "endianessChanged"
QT_MOC_LITERAL(54, 1045, 16), // "onPrepareCapture"
QT_MOC_LITERAL(55, 1062, 10), // "VmbError_t"
QT_MOC_LITERAL(56, 1073, 23), // "onSetColorInterpolation"
QT_MOC_LITERAL(57, 1097, 6), // "bState"
QT_MOC_LITERAL(58, 1104, 18), // "onSetHistogramData"
QT_MOC_LITERAL(59, 1123, 26), // "QVector<QVector<quint32> >"
QT_MOC_LITERAL(60, 1150, 8), // "histData"
QT_MOC_LITERAL(61, 1159, 15), // "sHistogramTitle"
QT_MOC_LITERAL(62, 1175, 16), // "nMaxHeight_YAxis"
QT_MOC_LITERAL(63, 1192, 15), // "nMaxWidth_XAxis"
QT_MOC_LITERAL(64, 1208, 20), // "QVector<QStringList>"
QT_MOC_LITERAL(65, 1229, 10), // "statistics"
QT_MOC_LITERAL(66, 1240, 29), // "updateColorInterpolationState"
QT_MOC_LITERAL(67, 1270, 22), // "onTooltipCheckBoxClick"
QT_MOC_LITERAL(68, 1293, 20), // "enableMenuAndToolbar"
QT_MOC_LITERAL(69, 1314, 26), // "directAccessHexTextChanged"
QT_MOC_LITERAL(70, 1341, 5), // "sText"
QT_MOC_LITERAL(71, 1347, 26), // "directAccessDecTextChanged"
QT_MOC_LITERAL(72, 1374, 24), // "optionsFrameCountChanged"
QT_MOC_LITERAL(73, 1399, 15), // "optionsAccepted"
QT_MOC_LITERAL(74, 1415, 17), // "textFilterChanged"
QT_MOC_LITERAL(75, 1433, 10) // "loadPlugin"

    },
    "ViewerWindow\0closeViewer\0\0sID\0"
    "on_ActionFreerun_triggered\0"
    "on_ActionResetPosition_triggered\0"
    "on_ActionHistogram_triggered\0"
    "on_ActionOriginalSize_triggered\0"
    "on_ActionSaveAs_triggered\0"
    "on_ActionSaveOptions_triggered\0"
    "on_ActionSaveImages_triggered\0"
    "on_ActionRegister_triggered\0"
    "on_ActionDisplayOptions_triggered\0"
    "on_ActionFitToWindow_triggered\0"
    "on_ActionLeftRotation_triggered\0"
    "on_ActionRightRotation_triggered\0"
    "on_ActionZoomOut_triggered\0"
    "on_ActionZoomIn_triggered\0"
    "on_ActionLoadCameraSettings_triggered\0"
    "on_ActionSaveCameraSettings_triggered\0"
    "on_ActionLoadCameraSettingsMenu_triggered\0"
    "on_ActionSaveCameraSettingsMenu_triggered\0"
    "onAcquisitionStartStop\0sThisFeature\0"
    "onfloatingDockChanged\0bIsFloating\0"
    "onVisibilityChanged\0bIsVisible\0"
    "displayEveryFrameClick\0bValue\0"
    "onSetDescription\0sDesc\0onimageReady\0"
    "image\0sFormat\0sHeight\0sWidth\0onSaving\0"
    "nPos\0onSetEventMessage\0sMsg\0onSetCurrentFPS\0"
    "sFPS\0onSetFrameCounter\0nNumberOfFrames\0"
    "onFeedLogger\0sMessage\0onResetFPS\0"
    "getSaveDestinationPath\0acceptSaveImagesDlg\0"
    "rejectSaveImagesDlg\0writeRegisterData\0"
    "readRegisterData\0endianessChanged\0"
    "onPrepareCapture\0VmbError_t\0"
    "onSetColorInterpolation\0bState\0"
    "onSetHistogramData\0QVector<QVector<quint32> >\0"
    "histData\0sHistogramTitle\0nMaxHeight_YAxis\0"
    "nMaxWidth_XAxis\0QVector<QStringList>\0"
    "statistics\0updateColorInterpolationState\0"
    "onTooltipCheckBoxClick\0enableMenuAndToolbar\0"
    "directAccessHexTextChanged\0sText\0"
    "directAccessDecTextChanged\0"
    "optionsFrameCountChanged\0optionsAccepted\0"
    "textFilterChanged\0loadPlugin"
};
#undef QT_MOC_LITERAL

static const uint qt_meta_data_ViewerWindow[] = {

 // content:
       7,       // revision
       0,       // classname
       0,    0, // classinfo
      49,   14, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       1,       // signalCount

 // signals: name, argc, parameters, tag, flags
       1,    1,  259,    2, 0x06 /* Public */,

 // slots: name, argc, parameters, tag, flags
       4,    0,  262,    2, 0x08 /* Private */,
       5,    0,  263,    2, 0x08 /* Private */,
       6,    0,  264,    2, 0x08 /* Private */,
       7,    0,  265,    2, 0x08 /* Private */,
       8,    0,  266,    2, 0x08 /* Private */,
       9,    0,  267,    2, 0x08 /* Private */,
      10,    0,  268,    2, 0x08 /* Private */,
      11,    0,  269,    2, 0x08 /* Private */,
      12,    0,  270,    2, 0x08 /* Private */,
      13,    0,  271,    2, 0x08 /* Private */,
      14,    0,  272,    2, 0x08 /* Private */,
      15,    0,  273,    2, 0x08 /* Private */,
      16,    0,  274,    2, 0x08 /* Private */,
      17,    0,  275,    2, 0x08 /* Private */,
      18,    0,  276,    2, 0x08 /* Private */,
      19,    0,  277,    2, 0x08 /* Private */,
      20,    0,  278,    2, 0x08 /* Private */,
      21,    0,  279,    2, 0x08 /* Private */,
      22,    1,  280,    2, 0x08 /* Private */,
      24,    1,  283,    2, 0x08 /* Private */,
      26,    1,  286,    2, 0x08 /* Private */,
      28,    1,  289,    2, 0x08 /* Private */,
      30,    1,  292,    2, 0x08 /* Private */,
      32,    4,  295,    2, 0x08 /* Private */,
      37,    1,  304,    2, 0x08 /* Private */,
      39,    1,  307,    2, 0x08 /* Private */,
      41,    1,  310,    2, 0x08 /* Private */,
      43,    1,  313,    2, 0x08 /* Private */,
      45,    1,  316,    2, 0x08 /* Private */,
      47,    0,  319,    2, 0x08 /* Private */,
      48,    0,  320,    2, 0x08 /* Private */,
      49,    0,  321,    2, 0x08 /* Private */,
      50,    0,  322,    2, 0x08 /* Private */,
      51,    0,  323,    2, 0x08 /* Private */,
      52,    0,  324,    2, 0x08 /* Private */,
      53,    1,  325,    2, 0x08 /* Private */,
      54,    0,  328,    2, 0x08 /* Private */,
      56,    1,  329,    2, 0x08 /* Private */,
      58,    5,  332,    2, 0x08 /* Private */,
      66,    0,  343,    2, 0x08 /* Private */,
      67,    1,  344,    2, 0x08 /* Private */,
      68,    1,  347,    2, 0x08 /* Private */,
      69,    1,  350,    2, 0x08 /* Private */,
      71,    1,  353,    2, 0x08 /* Private */,
      72,    1,  356,    2, 0x08 /* Private */,
      73,    0,  359,    2, 0x08 /* Private */,
      74,    0,  360,    2, 0x08 /* Private */,
      75,    0,  361,    2, 0x08 /* Private */,

 // signals: parameters
    QMetaType::Void, QMetaType::QString,    3,

 // slots: parameters
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void, QMetaType::QString,   23,
    QMetaType::Void, QMetaType::Bool,   25,
    QMetaType::Void, QMetaType::Bool,   27,
    QMetaType::Void, QMetaType::Bool,   29,
    QMetaType::Void, QMetaType::QString,   31,
    QMetaType::Void, QMetaType::QImage, QMetaType::QString, QMetaType::QString, QMetaType::QString,   33,   34,   35,   36,
    QMetaType::Void, QMetaType::UInt,   38,
    QMetaType::Void, QMetaType::QStringList,   40,
    QMetaType::Void, QMetaType::QString,   42,
    QMetaType::Void, QMetaType::UInt,   44,
    QMetaType::Void, QMetaType::QString,   46,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void, QMetaType::Int,    2,
    0x80000000 | 55,
    QMetaType::Void, QMetaType::Bool,   57,
    QMetaType::Void, 0x80000000 | 59, QMetaType::QString, QMetaType::Double, QMetaType::Double, 0x80000000 | 64,   60,   61,   62,   63,   65,
    QMetaType::Void,
    QMetaType::Void, QMetaType::Bool,   29,
    QMetaType::Void, QMetaType::Bool,   29,
    QMetaType::Void, QMetaType::QString,   70,
    QMetaType::Void, QMetaType::QString,   70,
    QMetaType::Void, QMetaType::QString,   70,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Bool,

       0        // eod
};

void ViewerWindow::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::InvokeMetaMethod) {
        ViewerWindow *_t = static_cast<ViewerWindow *>(_o);
        Q_UNUSED(_t)
        switch (_id) {
        case 0: _t->closeViewer((*reinterpret_cast< const QString(*)>(_a[1]))); break;
        case 1: _t->on_ActionFreerun_triggered(); break;
        case 2: _t->on_ActionResetPosition_triggered(); break;
        case 3: _t->on_ActionHistogram_triggered(); break;
        case 4: _t->on_ActionOriginalSize_triggered(); break;
        case 5: _t->on_ActionSaveAs_triggered(); break;
        case 6: _t->on_ActionSaveOptions_triggered(); break;
        case 7: _t->on_ActionSaveImages_triggered(); break;
        case 8: _t->on_ActionRegister_triggered(); break;
        case 9: _t->on_ActionDisplayOptions_triggered(); break;
        case 10: _t->on_ActionFitToWindow_triggered(); break;
        case 11: _t->on_ActionLeftRotation_triggered(); break;
        case 12: _t->on_ActionRightRotation_triggered(); break;
        case 13: _t->on_ActionZoomOut_triggered(); break;
        case 14: _t->on_ActionZoomIn_triggered(); break;
        case 15: _t->on_ActionLoadCameraSettings_triggered(); break;
        case 16: _t->on_ActionSaveCameraSettings_triggered(); break;
        case 17: _t->on_ActionLoadCameraSettingsMenu_triggered(); break;
        case 18: _t->on_ActionSaveCameraSettingsMenu_triggered(); break;
        case 19: _t->onAcquisitionStartStop((*reinterpret_cast< const QString(*)>(_a[1]))); break;
        case 20: _t->onfloatingDockChanged((*reinterpret_cast< bool(*)>(_a[1]))); break;
        case 21: _t->onVisibilityChanged((*reinterpret_cast< bool(*)>(_a[1]))); break;
        case 22: _t->displayEveryFrameClick((*reinterpret_cast< bool(*)>(_a[1]))); break;
        case 23: _t->onSetDescription((*reinterpret_cast< const QString(*)>(_a[1]))); break;
        case 24: _t->onimageReady((*reinterpret_cast< QImage(*)>(_a[1])),(*reinterpret_cast< const QString(*)>(_a[2])),(*reinterpret_cast< const QString(*)>(_a[3])),(*reinterpret_cast< const QString(*)>(_a[4]))); break;
        case 25: _t->onSaving((*reinterpret_cast< uint(*)>(_a[1]))); break;
        case 26: _t->onSetEventMessage((*reinterpret_cast< const QStringList(*)>(_a[1]))); break;
        case 27: _t->onSetCurrentFPS((*reinterpret_cast< const QString(*)>(_a[1]))); break;
        case 28: _t->onSetFrameCounter((*reinterpret_cast< const uint(*)>(_a[1]))); break;
        case 29: _t->onFeedLogger((*reinterpret_cast< const QString(*)>(_a[1]))); break;
        case 30: _t->onResetFPS(); break;
        case 31: _t->getSaveDestinationPath(); break;
        case 32: _t->acceptSaveImagesDlg(); break;
        case 33: _t->rejectSaveImagesDlg(); break;
        case 34: _t->writeRegisterData(); break;
        case 35: _t->readRegisterData(); break;
        case 36: _t->endianessChanged((*reinterpret_cast< int(*)>(_a[1]))); break;
        case 37: { VmbError_t _r = _t->onPrepareCapture();
            if (_a[0]) *reinterpret_cast< VmbError_t*>(_a[0]) = _r; }  break;
        case 38: _t->onSetColorInterpolation((*reinterpret_cast< const bool(*)>(_a[1]))); break;
        case 39: _t->onSetHistogramData((*reinterpret_cast< const QVector<QVector<quint32> >(*)>(_a[1])),(*reinterpret_cast< const QString(*)>(_a[2])),(*reinterpret_cast< const double(*)>(_a[3])),(*reinterpret_cast< const double(*)>(_a[4])),(*reinterpret_cast< const QVector<QStringList>(*)>(_a[5]))); break;
        case 40: _t->updateColorInterpolationState(); break;
        case 41: _t->onTooltipCheckBoxClick((*reinterpret_cast< bool(*)>(_a[1]))); break;
        case 42: _t->enableMenuAndToolbar((*reinterpret_cast< bool(*)>(_a[1]))); break;
        case 43: _t->directAccessHexTextChanged((*reinterpret_cast< const QString(*)>(_a[1]))); break;
        case 44: _t->directAccessDecTextChanged((*reinterpret_cast< const QString(*)>(_a[1]))); break;
        case 45: _t->optionsFrameCountChanged((*reinterpret_cast< const QString(*)>(_a[1]))); break;
        case 46: _t->optionsAccepted(); break;
        case 47: _t->textFilterChanged(); break;
        case 48: { bool _r = _t->loadPlugin();
            if (_a[0]) *reinterpret_cast< bool*>(_a[0]) = _r; }  break;
        default: ;
        }
    } else if (_c == QMetaObject::RegisterMethodArgumentMetaType) {
        switch (_id) {
        default: *reinterpret_cast<int*>(_a[0]) = -1; break;
        case 39:
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
            typedef void (ViewerWindow::*_t)(const QString & );
            if (*reinterpret_cast<_t *>(func) == static_cast<_t>(&ViewerWindow::closeViewer)) {
                *result = 0;
            }
        }
    }
}

const QMetaObject ViewerWindow::staticMetaObject = {
    { &QMainWindow::staticMetaObject, qt_meta_stringdata_ViewerWindow.data,
      qt_meta_data_ViewerWindow,  qt_static_metacall, Q_NULLPTR, Q_NULLPTR}
};


const QMetaObject *ViewerWindow::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->dynamicMetaObject() : &staticMetaObject;
}

void *ViewerWindow::qt_metacast(const char *_clname)
{
    if (!_clname) return Q_NULLPTR;
    if (!strcmp(_clname, qt_meta_stringdata_ViewerWindow.stringdata0))
        return static_cast<void*>(const_cast< ViewerWindow*>(this));
    return QMainWindow::qt_metacast(_clname);
}

int ViewerWindow::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = QMainWindow::qt_metacall(_c, _id, _a);
    if (_id < 0)
        return _id;
    if (_c == QMetaObject::InvokeMetaMethod) {
        if (_id < 49)
            qt_static_metacall(this, _c, _id, _a);
        _id -= 49;
    } else if (_c == QMetaObject::RegisterMethodArgumentMetaType) {
        if (_id < 49)
            qt_static_metacall(this, _c, _id, _a);
        _id -= 49;
    }
    return _id;
}

// SIGNAL 0
void ViewerWindow::closeViewer(const QString & _t1)
{
    void *_a[] = { Q_NULLPTR, const_cast<void*>(reinterpret_cast<const void*>(&_t1)) };
    QMetaObject::activate(this, &staticMetaObject, 0, _a);
}
QT_END_MOC_NAMESPACE
