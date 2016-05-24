/********************************************************************************
** Form generated from reading UI file 'ViewerWindow.ui'
**
** Created by: Qt User Interface Compiler version 5.5.1
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_VIEWERWINDOW_H
#define UI_VIEWERWINDOW_H

#include <QtCore/QVariant>
#include <QtWidgets/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QButtonGroup>
#include <QtWidgets/QGridLayout>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QMainWindow>
#include <QtWidgets/QMenu>
#include <QtWidgets/QMenuBar>
#include <QtWidgets/QStatusBar>
#include <QtWidgets/QToolBar>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_ViewerWindow
{
public:
    QAction *ActionFreerun;
    QAction *ActionResetPosition;
    QAction *ActionSaveAs;
    QAction *ActionOriginalSize;
    QAction *ActionSaveOptions;
    QAction *ActionRegister;
    QAction *ActionSaveImages;
    QAction *ActionDisplayOptions;
    QAction *ActionHistogram;
    QAction *ActionFitToWindow;
    QAction *ActionLeftRotation;
    QAction *ActionRightRotation;
    QAction *ActionZoomIn;
    QAction *ActionZoomOut;
    QAction *ActionSaveCameraSettings;
    QAction *ActionLoadCameraSettings;
    QAction *ActionLoadCameraSettingsMenu;
    QAction *ActionSaveCameraSettingsMenu;
    QWidget *centralWidget;
    QGridLayout *gridLayout;
    QMenuBar *menuBarMainWindow;
    QMenu *fileMenu;
    QMenu *viewMenu;
    QMenu *menuCamera;
    QMenu *menuDirect_Access;
    QStatusBar *statusbar;
    QToolBar *toolBar;

    void setupUi(QMainWindow *ViewerWindow)
    {
        if (ViewerWindow->objectName().isEmpty())
            ViewerWindow->setObjectName(QStringLiteral("ViewerWindow"));
        ViewerWindow->resize(823, 569);
        ActionFreerun = new QAction(ViewerWindow);
        ActionFreerun->setObjectName(QStringLiteral("ActionFreerun"));
        ActionFreerun->setCheckable(true);
        QIcon icon;
        icon.addFile(QStringLiteral(":/VimbaViewer/Images/play.png"), QSize(), QIcon::Normal, QIcon::Off);
        ActionFreerun->setIcon(icon);
        QFont font;
        ActionFreerun->setFont(font);
        ActionResetPosition = new QAction(ViewerWindow);
        ActionResetPosition->setObjectName(QStringLiteral("ActionResetPosition"));
        QIcon icon1;
        icon1.addFile(QStringLiteral(":/VimbaViewer/Images/resetposition.png"), QSize(), QIcon::Normal, QIcon::Off);
        ActionResetPosition->setIcon(icon1);
        ActionSaveAs = new QAction(ViewerWindow);
        ActionSaveAs->setObjectName(QStringLiteral("ActionSaveAs"));
        QIcon icon2;
        icon2.addFile(QStringLiteral(":/VimbaViewer/Images/save.png"), QSize(), QIcon::Normal, QIcon::Off);
        ActionSaveAs->setIcon(icon2);
        ActionOriginalSize = new QAction(ViewerWindow);
        ActionOriginalSize->setObjectName(QStringLiteral("ActionOriginalSize"));
        QIcon icon3;
        icon3.addFile(QStringLiteral(":/VimbaViewer/Images/zoom_default.png"), QSize(), QIcon::Normal, QIcon::Off);
        ActionOriginalSize->setIcon(icon3);
        ActionSaveOptions = new QAction(ViewerWindow);
        ActionSaveOptions->setObjectName(QStringLiteral("ActionSaveOptions"));
        QIcon icon4;
        icon4.addFile(QStringLiteral(":/VimbaViewer/Images/option.png"), QSize(), QIcon::Normal, QIcon::Off);
        ActionSaveOptions->setIcon(icon4);
        ActionRegister = new QAction(ViewerWindow);
        ActionRegister->setObjectName(QStringLiteral("ActionRegister"));
        QIcon icon5;
        icon5.addFile(QStringLiteral(":/VimbaViewer/Images/directaccess.png"), QSize(), QIcon::Normal, QIcon::Off);
        ActionRegister->setIcon(icon5);
        ActionSaveImages = new QAction(ViewerWindow);
        ActionSaveImages->setObjectName(QStringLiteral("ActionSaveImages"));
        ActionSaveImages->setEnabled(false);
        QIcon icon6;
        icon6.addFile(QStringLiteral(":/VimbaViewer/Images/savemultipleimages.png"), QSize(), QIcon::Normal, QIcon::Off);
        ActionSaveImages->setIcon(icon6);
        ActionDisplayOptions = new QAction(ViewerWindow);
        ActionDisplayOptions->setObjectName(QStringLiteral("ActionDisplayOptions"));
        ActionHistogram = new QAction(ViewerWindow);
        ActionHistogram->setObjectName(QStringLiteral("ActionHistogram"));
        ActionHistogram->setCheckable(true);
        QIcon icon7;
        icon7.addFile(QStringLiteral(":/VimbaViewer/Images/histogram.png"), QSize(), QIcon::Normal, QIcon::Off);
        ActionHistogram->setIcon(icon7);
        ActionFitToWindow = new QAction(ViewerWindow);
        ActionFitToWindow->setObjectName(QStringLiteral("ActionFitToWindow"));
        ActionFitToWindow->setCheckable(true);
        QIcon icon8;
        icon8.addFile(QStringLiteral(":/VimbaViewer/Images/fittowin.png"), QSize(), QIcon::Normal, QIcon::Off);
        ActionFitToWindow->setIcon(icon8);
        ActionLeftRotation = new QAction(ViewerWindow);
        ActionLeftRotation->setObjectName(QStringLiteral("ActionLeftRotation"));
        QIcon icon9;
        icon9.addFile(QStringLiteral(":/VimbaViewer/Images/leftrotate.png"), QSize(), QIcon::Normal, QIcon::Off);
        ActionLeftRotation->setIcon(icon9);
        ActionRightRotation = new QAction(ViewerWindow);
        ActionRightRotation->setObjectName(QStringLiteral("ActionRightRotation"));
        QIcon icon10;
        icon10.addFile(QStringLiteral(":/VimbaViewer/Images/rightrotate.png"), QSize(), QIcon::Normal, QIcon::Off);
        ActionRightRotation->setIcon(icon10);
        ActionZoomIn = new QAction(ViewerWindow);
        ActionZoomIn->setObjectName(QStringLiteral("ActionZoomIn"));
        QIcon icon11;
        icon11.addFile(QStringLiteral(":/VimbaViewer/Images/zoom_in.png"), QSize(), QIcon::Normal, QIcon::Off);
        ActionZoomIn->setIcon(icon11);
        ActionZoomOut = new QAction(ViewerWindow);
        ActionZoomOut->setObjectName(QStringLiteral("ActionZoomOut"));
        QIcon icon12;
        icon12.addFile(QStringLiteral(":/VimbaViewer/Images/zoom_out.png"), QSize(), QIcon::Normal, QIcon::Off);
        ActionZoomOut->setIcon(icon12);
        ActionSaveCameraSettings = new QAction(ViewerWindow);
        ActionSaveCameraSettings->setObjectName(QStringLiteral("ActionSaveCameraSettings"));
        QIcon icon13;
        icon13.addFile(QStringLiteral(":/VimbaViewer/Images/saveSettings_32.png"), QSize(), QIcon::Normal, QIcon::Off);
        ActionSaveCameraSettings->setIcon(icon13);
        ActionLoadCameraSettings = new QAction(ViewerWindow);
        ActionLoadCameraSettings->setObjectName(QStringLiteral("ActionLoadCameraSettings"));
        QIcon icon14;
        icon14.addFile(QStringLiteral(":/VimbaViewer/Images/loadSettings_32.png"), QSize(), QIcon::Normal, QIcon::Off);
        ActionLoadCameraSettings->setIcon(icon14);
        ActionLoadCameraSettingsMenu = new QAction(ViewerWindow);
        ActionLoadCameraSettingsMenu->setObjectName(QStringLiteral("ActionLoadCameraSettingsMenu"));
        ActionLoadCameraSettingsMenu->setIcon(icon14);
        ActionSaveCameraSettingsMenu = new QAction(ViewerWindow);
        ActionSaveCameraSettingsMenu->setObjectName(QStringLiteral("ActionSaveCameraSettingsMenu"));
        ActionSaveCameraSettingsMenu->setIcon(icon13);
        centralWidget = new QWidget(ViewerWindow);
        centralWidget->setObjectName(QStringLiteral("centralWidget"));
        gridLayout = new QGridLayout(centralWidget);
        gridLayout->setObjectName(QStringLiteral("gridLayout"));
        ViewerWindow->setCentralWidget(centralWidget);
        menuBarMainWindow = new QMenuBar(ViewerWindow);
        menuBarMainWindow->setObjectName(QStringLiteral("menuBarMainWindow"));
        menuBarMainWindow->setGeometry(QRect(0, 0, 823, 22));
        menuBarMainWindow->setStyleSheet(QStringLiteral("font: 10pt \"Verdana\";"));
        fileMenu = new QMenu(menuBarMainWindow);
        fileMenu->setObjectName(QStringLiteral("fileMenu"));
        viewMenu = new QMenu(menuBarMainWindow);
        viewMenu->setObjectName(QStringLiteral("viewMenu"));
        menuCamera = new QMenu(menuBarMainWindow);
        menuCamera->setObjectName(QStringLiteral("menuCamera"));
        menuDirect_Access = new QMenu(menuCamera);
        menuDirect_Access->setObjectName(QStringLiteral("menuDirect_Access"));
        ViewerWindow->setMenuBar(menuBarMainWindow);
        statusbar = new QStatusBar(ViewerWindow);
        statusbar->setObjectName(QStringLiteral("statusbar"));
        statusbar->setStyleSheet(QLatin1String("background-color: rgb(195, 195, 195);\n"
"font: 10pt \"Verdana\";"));
        ViewerWindow->setStatusBar(statusbar);
        toolBar = new QToolBar(ViewerWindow);
        toolBar->setObjectName(QStringLiteral("toolBar"));
        toolBar->setMinimumSize(QSize(0, 0));
        QPalette palette;
        toolBar->setPalette(palette);
        toolBar->setStyleSheet(QStringLiteral(""));
        toolBar->setToolButtonStyle(Qt::ToolButtonIconOnly);
        ViewerWindow->addToolBar(Qt::TopToolBarArea, toolBar);

        menuBarMainWindow->addAction(fileMenu->menuAction());
        menuBarMainWindow->addAction(viewMenu->menuAction());
        menuBarMainWindow->addAction(menuCamera->menuAction());
        fileMenu->addAction(ActionSaveImages);
        fileMenu->addAction(ActionSaveAs);
        fileMenu->addAction(ActionSaveOptions);
        viewMenu->addAction(ActionFitToWindow);
        viewMenu->addAction(ActionLeftRotation);
        viewMenu->addAction(ActionRightRotation);
        viewMenu->addSeparator();
        viewMenu->addAction(ActionHistogram);
        viewMenu->addSeparator();
        viewMenu->addAction(ActionZoomIn);
        viewMenu->addAction(ActionZoomOut);
        viewMenu->addAction(ActionOriginalSize);
        viewMenu->addAction(ActionResetPosition);
        viewMenu->addSeparator();
        viewMenu->addAction(ActionDisplayOptions);
        menuCamera->addAction(ActionFreerun);
        menuCamera->addSeparator();
        menuCamera->addAction(menuDirect_Access->menuAction());
        menuCamera->addSeparator();
        menuCamera->addAction(ActionLoadCameraSettingsMenu);
        menuCamera->addAction(ActionSaveCameraSettingsMenu);
        menuDirect_Access->addAction(ActionRegister);
        toolBar->addAction(ActionFreerun);
        toolBar->addSeparator();
        toolBar->addAction(ActionSaveImages);
        toolBar->addAction(ActionLoadCameraSettings);
        toolBar->addAction(ActionSaveCameraSettings);
        toolBar->addSeparator();
        toolBar->addAction(ActionHistogram);
        toolBar->addSeparator();
        toolBar->addAction(ActionFitToWindow);
        toolBar->addAction(ActionLeftRotation);
        toolBar->addAction(ActionRightRotation);
        toolBar->addAction(ActionZoomIn);
        toolBar->addAction(ActionOriginalSize);
        toolBar->addAction(ActionZoomOut);
        toolBar->addSeparator();
        toolBar->addAction(ActionResetPosition);

        retranslateUi(ViewerWindow);

        QMetaObject::connectSlotsByName(ViewerWindow);
    } // setupUi

    void retranslateUi(QMainWindow *ViewerWindow)
    {
        ViewerWindow->setWindowTitle(QApplication::translate("ViewerWindow", "MainWindow", 0));
        ActionFreerun->setText(QApplication::translate("ViewerWindow", "Freerun", 0));
        ActionFreerun->setIconText(QApplication::translate("ViewerWindow", "Freerun", 0));
#ifndef QT_NO_TOOLTIP
        ActionFreerun->setToolTip(QApplication::translate("ViewerWindow", "Freerun", 0));
#endif // QT_NO_TOOLTIP
        ActionFreerun->setShortcut(QApplication::translate("ViewerWindow", "Ctrl+F", 0));
        ActionResetPosition->setText(QApplication::translate("ViewerWindow", "Reset Docking Position", 0));
#ifndef QT_NO_TOOLTIP
        ActionResetPosition->setToolTip(QApplication::translate("ViewerWindow", "Reset docking windows position", 0));
#endif // QT_NO_TOOLTIP
        ActionResetPosition->setShortcut(QApplication::translate("ViewerWindow", "Ctrl+R", 0));
        ActionSaveAs->setText(QApplication::translate("ViewerWindow", "Save As...", 0));
        ActionOriginalSize->setText(QApplication::translate("ViewerWindow", "Set Zoom To Default", 0));
        ActionOriginalSize->setIconText(QApplication::translate("ViewerWindow", "Original Size", 0));
#ifndef QT_NO_TOOLTIP
        ActionOriginalSize->setToolTip(QApplication::translate("ViewerWindow", "Set zoom to default (original size)", 0));
#endif // QT_NO_TOOLTIP
        ActionOriginalSize->setShortcut(QApplication::translate("ViewerWindow", "Ctrl+D", 0));
        ActionSaveOptions->setText(QApplication::translate("ViewerWindow", "Save Options...", 0));
        ActionRegister->setText(QApplication::translate("ViewerWindow", "Register", 0));
#ifndef QT_NO_TOOLTIP
        ActionRegister->setToolTip(QApplication::translate("ViewerWindow", "Direct Access Register", 0));
#endif // QT_NO_TOOLTIP
        ActionSaveImages->setText(QApplication::translate("ViewerWindow", "Save Images", 0));
#ifndef QT_NO_TOOLTIP
        ActionSaveImages->setToolTip(QApplication::translate("ViewerWindow", "Save images", 0));
#endif // QT_NO_TOOLTIP
        ActionDisplayOptions->setText(QApplication::translate("ViewerWindow", "Options...", 0));
#ifndef QT_NO_TOOLTIP
        ActionDisplayOptions->setToolTip(QApplication::translate("ViewerWindow", "Display options", 0));
#endif // QT_NO_TOOLTIP
        ActionHistogram->setText(QApplication::translate("ViewerWindow", "Histogram", 0));
#ifndef QT_NO_TOOLTIP
        ActionHistogram->setToolTip(QApplication::translate("ViewerWindow", "Open the histogram window", 0));
#endif // QT_NO_TOOLTIP
        ActionHistogram->setShortcut(QApplication::translate("ViewerWindow", "Ctrl+H", 0));
        ActionFitToWindow->setText(QApplication::translate("ViewerWindow", "Fit to window", 0));
        ActionFitToWindow->setShortcut(QApplication::translate("ViewerWindow", "Ctrl+W", 0));
        ActionLeftRotation->setText(QApplication::translate("ViewerWindow", "Left Rotation 90\302\260", 0));
        ActionRightRotation->setText(QApplication::translate("ViewerWindow", "Right Rotation 90\302\260", 0));
        ActionZoomIn->setText(QApplication::translate("ViewerWindow", "Zoom In", 0));
        ActionZoomIn->setShortcut(QApplication::translate("ViewerWindow", "Ctrl++", 0));
        ActionZoomOut->setText(QApplication::translate("ViewerWindow", "Zoom Out", 0));
        ActionZoomOut->setShortcut(QApplication::translate("ViewerWindow", "Ctrl+-", 0));
        ActionSaveCameraSettings->setText(QApplication::translate("ViewerWindow", "Save camera settings", 0));
#ifndef QT_NO_TOOLTIP
        ActionSaveCameraSettings->setToolTip(QApplication::translate("ViewerWindow", "Save Camera Settings to File.", 0));
#endif // QT_NO_TOOLTIP
        ActionLoadCameraSettings->setText(QApplication::translate("ViewerWindow", "Load camera settings", 0));
#ifndef QT_NO_TOOLTIP
        ActionLoadCameraSettings->setToolTip(QApplication::translate("ViewerWindow", "Load Camera Settings from File.", 0));
#endif // QT_NO_TOOLTIP
        ActionLoadCameraSettingsMenu->setText(QApplication::translate("ViewerWindow", "Load Camera Settings", 0));
        ActionSaveCameraSettingsMenu->setText(QApplication::translate("ViewerWindow", "Save Camera Settings", 0));
        fileMenu->setTitle(QApplication::translate("ViewerWindow", "File", 0));
        viewMenu->setTitle(QApplication::translate("ViewerWindow", "View", 0));
        menuCamera->setTitle(QApplication::translate("ViewerWindow", "Camera", 0));
        menuDirect_Access->setTitle(QApplication::translate("ViewerWindow", "Direct Access", 0));
        toolBar->setWindowTitle(QApplication::translate("ViewerWindow", "Viewer ToolBar ", 0));
    } // retranslateUi

};

namespace Ui {
    class ViewerWindow: public Ui_ViewerWindow {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_VIEWERWINDOW_H
