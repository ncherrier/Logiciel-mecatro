/********************************************************************************
** Form generated from reading UI file 'MainWindow.ui'
**
** Created by: Qt User Interface Compiler version 5.5.1
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_MAINWINDOW_H
#define UI_MAINWINDOW_H

#include <QtCore/QVariant>
#include <QtWidgets/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QButtonGroup>
#include <QtWidgets/QHBoxLayout>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QMainWindow>
#include <QtWidgets/QMenu>
#include <QtWidgets/QMenuBar>
#include <QtWidgets/QToolBar>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_mainWindow
{
public:
    QAction *ActionDiscover;
    QAction *ActionClear;
    QAction *actionAbout;
    QAction *actionAbout_Qt;
    QAction *ActionStartOptions;
    QAction *actionExit;
    QAction *ActionOpenByID;
    QWidget *centralWidget;
    QHBoxLayout *horizontalLayout_2;
    QHBoxLayout *layout_H;
    QMenuBar *menuBar;
    QMenu *menuAction;
    QMenu *menuHelp;
    QMenu *menuSettings;
    QToolBar *mainToolBar;

    void setupUi(QMainWindow *mainWindow)
    {
        if (mainWindow->objectName().isEmpty())
            mainWindow->setObjectName(QStringLiteral("mainWindow"));
        mainWindow->resize(700, 416);
        QSizePolicy sizePolicy(QSizePolicy::Preferred, QSizePolicy::Preferred);
        sizePolicy.setHorizontalStretch(0);
        sizePolicy.setVerticalStretch(0);
        sizePolicy.setHeightForWidth(mainWindow->sizePolicy().hasHeightForWidth());
        mainWindow->setSizePolicy(sizePolicy);
        mainWindow->setMinimumSize(QSize(700, 350));
        mainWindow->setMaximumSize(QSize(16777215, 16777215));
        QIcon icon;
        icon.addFile(QStringLiteral(":/VimbaViewer/Images/stripes_256.png"), QSize(), QIcon::Normal, QIcon::Off);
        mainWindow->setWindowIcon(icon);
        mainWindow->setIconSize(QSize(24, 24));
        ActionDiscover = new QAction(mainWindow);
        ActionDiscover->setObjectName(QStringLiteral("ActionDiscover"));
        QIcon icon1;
        icon1.addFile(QStringLiteral(":/VimbaViewer/Images/refresh.png"), QSize(), QIcon::Normal, QIcon::Off);
        ActionDiscover->setIcon(icon1);
        ActionClear = new QAction(mainWindow);
        ActionClear->setObjectName(QStringLiteral("ActionClear"));
        QIcon icon2;
        icon2.addFile(QStringLiteral(":/VimbaViewer/Images/delete.png"), QSize(), QIcon::Normal, QIcon::Off);
        ActionClear->setIcon(icon2);
        actionAbout = new QAction(mainWindow);
        actionAbout->setObjectName(QStringLiteral("actionAbout"));
        actionAbout_Qt = new QAction(mainWindow);
        actionAbout_Qt->setObjectName(QStringLiteral("actionAbout_Qt"));
        ActionStartOptions = new QAction(mainWindow);
        ActionStartOptions->setObjectName(QStringLiteral("ActionStartOptions"));
        actionExit = new QAction(mainWindow);
        actionExit->setObjectName(QStringLiteral("actionExit"));
        ActionOpenByID = new QAction(mainWindow);
        ActionOpenByID->setObjectName(QStringLiteral("ActionOpenByID"));
        QIcon icon3;
        icon3.addFile(QStringLiteral(":/VimbaViewer/Images/goldeye-g.png"), QSize(), QIcon::Normal, QIcon::Off);
        ActionOpenByID->setIcon(icon3);
        centralWidget = new QWidget(mainWindow);
        centralWidget->setObjectName(QStringLiteral("centralWidget"));
        horizontalLayout_2 = new QHBoxLayout(centralWidget);
        horizontalLayout_2->setSpacing(6);
        horizontalLayout_2->setContentsMargins(11, 11, 11, 11);
        horizontalLayout_2->setObjectName(QStringLiteral("horizontalLayout_2"));
        layout_H = new QHBoxLayout();
        layout_H->setSpacing(6);
        layout_H->setContentsMargins(11, 11, 11, 11);
        layout_H->setObjectName(QStringLiteral("layout_H"));

        horizontalLayout_2->addLayout(layout_H);

        mainWindow->setCentralWidget(centralWidget);
        menuBar = new QMenuBar(mainWindow);
        menuBar->setObjectName(QStringLiteral("menuBar"));
        menuBar->setGeometry(QRect(0, 0, 700, 21));
        menuAction = new QMenu(menuBar);
        menuAction->setObjectName(QStringLiteral("menuAction"));
        menuHelp = new QMenu(menuBar);
        menuHelp->setObjectName(QStringLiteral("menuHelp"));
        menuSettings = new QMenu(menuBar);
        menuSettings->setObjectName(QStringLiteral("menuSettings"));
        mainWindow->setMenuBar(menuBar);
        mainToolBar = new QToolBar(mainWindow);
        mainToolBar->setObjectName(QStringLiteral("mainToolBar"));
        mainToolBar->setStyleSheet(QStringLiteral(""));
        mainWindow->addToolBar(Qt::LeftToolBarArea, mainToolBar);

        menuBar->addAction(menuAction->menuAction());
        menuBar->addAction(menuSettings->menuAction());
        menuBar->addAction(menuHelp->menuAction());
        menuAction->addAction(ActionOpenByID);
        menuAction->addAction(ActionDiscover);
        menuAction->addAction(ActionClear);
        menuAction->addSeparator();
        menuAction->addAction(actionExit);
        menuHelp->addAction(actionAbout);
        menuHelp->addAction(actionAbout_Qt);
        menuSettings->addAction(ActionStartOptions);
        mainToolBar->addAction(ActionOpenByID);
        mainToolBar->addAction(ActionDiscover);
        mainToolBar->addAction(ActionClear);

        retranslateUi(mainWindow);

        QMetaObject::connectSlotsByName(mainWindow);
    } // setupUi

    void retranslateUi(QMainWindow *mainWindow)
    {
        mainWindow->setWindowTitle(QApplication::translate("mainWindow", "Vimba Viewer", 0));
        ActionDiscover->setText(QApplication::translate("mainWindow", "Refresh", 0));
#ifndef QT_NO_TOOLTIP
        ActionDiscover->setToolTip(QApplication::translate("mainWindow", "Refresh camera tree", 0));
#endif // QT_NO_TOOLTIP
        ActionDiscover->setShortcut(QApplication::translate("mainWindow", "Ctrl+R", 0));
        ActionClear->setText(QApplication::translate("mainWindow", "Clear Logger", 0));
#ifndef QT_NO_TOOLTIP
        ActionClear->setToolTip(QApplication::translate("mainWindow", "Clear log window", 0));
#endif // QT_NO_TOOLTIP
        ActionClear->setShortcut(QApplication::translate("mainWindow", "Ctrl+C", 0));
        actionAbout->setText(QApplication::translate("mainWindow", "About", 0));
        actionAbout_Qt->setText(QApplication::translate("mainWindow", "About Qt", 0));
        ActionStartOptions->setText(QApplication::translate("mainWindow", "Start Options...", 0));
        ActionStartOptions->setShortcut(QApplication::translate("mainWindow", "Ctrl+S", 0));
        actionExit->setText(QApplication::translate("mainWindow", "Exit", 0));
        actionExit->setShortcut(QApplication::translate("mainWindow", "Ctrl+F4", 0));
        ActionOpenByID->setText(QApplication::translate("mainWindow", "Open Camera by IP", 0));
#ifndef QT_NO_TOOLTIP
        ActionOpenByID->setToolTip(QApplication::translate("mainWindow", "Open a camera that was not discovered", 0));
#endif // QT_NO_TOOLTIP
        ActionOpenByID->setShortcut(QApplication::translate("mainWindow", "Ctrl+O", 0));
        menuAction->setTitle(QApplication::translate("mainWindow", "Action", 0));
        menuHelp->setTitle(QApplication::translate("mainWindow", "Help", 0));
        menuSettings->setTitle(QApplication::translate("mainWindow", "Settings", 0));
        mainToolBar->setWindowTitle(QApplication::translate("mainWindow", "MainWindow ToolBar", 0));
    } // retranslateUi

};

namespace Ui {
    class mainWindow: public Ui_mainWindow {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_MAINWINDOW_H
