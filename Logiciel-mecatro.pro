TARGET=declarative-camera

QT += core gui

QT += widgets # Indispensable pour interface graphique !!!

QT += serialport

QT += quick qml multimedia multimediawidgets # for the webcam

SOURCES += \
    camera.cpp \
    camera_settings.cpp \
    FramingWindow.cpp \
    SettingsWindow.cpp \
    cameraSettingsWindow.cpp \
    ProcessWindow.cpp \
    Main_Prog.cpp \
    TakePictureTest.cpp \
    SerialCommunication.cpp

HEADERS += \
    camera.h \
    FramingWindow.h \
    SettingsWindow.h \
    cameraSettingsWindow.h \
    ProcessWindow.h \
    Main_Prog.h \
    SerialCommunication.h \
    TakePictureTest.h \
    Vimba_2.0/VimbaCPP/Include/AncillaryData.h \
    Vimba_2.0/VimbaCPP/Include/BasicLockable.h \
    Vimba_2.0/VimbaCPP/Include/Camera.h \
    Vimba_2.0/VimbaCPP/Include/Camera.hpp \
    Vimba_2.0/VimbaCPP/Include/EnumEntry.h \
    Vimba_2.0/VimbaCPP/Include/EnumEntry.hpp \
    Vimba_2.0/VimbaCPP/Include/Feature.h \
    Vimba_2.0/VimbaCPP/Include/Feature.hpp \
    Vimba_2.0/VimbaCPP/Include/FeatureContainer.h \
    Vimba_2.0/VimbaCPP/Include/FeatureContainer.hpp \
    Vimba_2.0/VimbaCPP/Include/FileLogger.h \
    Vimba_2.0/VimbaCPP/Include/Frame.h \
    Vimba_2.0/VimbaCPP/Include/ICameraFactory.h \
    Vimba_2.0/VimbaCPP/Include/ICameraListObserver.h \
    Vimba_2.0/VimbaCPP/Include/IFeatureObserver.h \
    Vimba_2.0/VimbaCPP/Include/IFrameObserver.h \
    Vimba_2.0/VimbaCPP/Include/IInterfaceListObserver.h \
    Vimba_2.0/VimbaCPP/Include/Interface.h \
    Vimba_2.0/VimbaCPP/Include/Interface.hpp \
    Vimba_2.0/VimbaCPP/Include/IRegisterDevice.h \
    Vimba_2.0/VimbaCPP/Include/LoggerDefines.h \
    Vimba_2.0/VimbaCPP/Include/Mutex.h \
    Vimba_2.0/VimbaCPP/Include/SharedPointer.h \
    Vimba_2.0/VimbaCPP/Include/SharedPointer_impl.h \
    Vimba_2.0/VimbaCPP/Include/SharedPointerDefines.h \
    Vimba_2.0/VimbaCPP/Include/UserLoggerDefines.h \
    Vimba_2.0/VimbaCPP/Include/UserSharedPointerDefines.h \
    Vimba_2.0/VimbaCPP/Include/VimbaCPP.h \
    Vimba_2.0/VimbaCPP/Include/VimbaCPPCommon.h \
    Vimba_2.0/VimbaCPP/Include/VimbaSystem.h \
    Vimba_2.0/VimbaCPP/Include/VimbaSystem.hpp

win32:CONFIG(release, debug|release): LIBS += -L$$PWD/Vimba_2.0/VimbaC/Lib/Win32 -lVimbaC
#else:win32:CONFIG(debug, debug|release): LIBS += -L$$PWD/Vimba_2.0/VimbaC/Lib/Win32 -lVimbaCd

win32:CONFIG(release, debug|release): LIBS += -L$$PWD/Vimba_2.0/VimbaCPP/Lib/Win32 -lVimbaCPP
#else:win32:CONFIG(debug, debug|release): LIBS += -L$$PWD/Vimba_2.0/VimbaCPP/Lib/Win32 -lVimbaCPPd

INCLUDEPATH += $$PWD/Vimba_2.0/VimbaCPP/Include
DEPENDPATH += $$PWD/Vimba_2.0/VimbaCPP/Include

win32:!win32-g++:CONFIG(release, debug|release): PRE_TARGETDEPS += $$PWD/Vimba_2.0/VimbaCPP/Lib/Win32/VimbaCPP.lib
#else:win32:!win32-g++:CONFIG(debug, debug|release): PRE_TARGETDEPS += $$PWD/Vimba_2.0/VimbaCPP/Lib/Win32/VimbaCPPd.lib

INCLUDEPATH += $$PWD/Vimba_2.0/VimbaC/Include
DEPENDPATH += $$PWD/Vimba_2.0/VimbaC/Include

win32:!win32-g++:CONFIG(release, debug|release): PRE_TARGETDEPS += $$PWD/Vimba_2.0/VimbaC/Lib/Win32/VimbaC.lib
#else:win32:!win32-g++:CONFIG(debug, debug|release): PRE_TARGETDEPS += $$PWD/Vimba_2.0/VimbaC/Lib/Win32/VimbaCd.lib

INCLUDEPATH += $$PWD/Vimba_2.0
DEPENDPATH += $$PWD/Vimba_2.0

target.path = $$[QT_INSTALL_EXAMPLES]/multimedia/declarative-camera
INSTALLS += target

winrt {
    WINRT_MANIFEST.capabilities_device += webcam microphone
}
