/********************************************************************************
** Form generated from reading UI file 'logiciel_mecatro.ui'
**
** Created by: Qt User Interface Compiler version 5.5.1
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_LOGICIEL_MECATRO_H
#define UI_LOGICIEL_MECATRO_H

#include <QtCore/QVariant>
#include <QtWidgets/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QButtonGroup>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QLabel>
#include <QtWidgets/QListWidget>
#include <QtWidgets/QMainWindow>
#include <QtWidgets/QMenuBar>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QStatusBar>
#include <QtWidgets/QToolBar>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_Logiciel_mecatroClass
{
public:
    QMenuBar *menuBar;
    QToolBar *mainToolBar;
    QWidget *centralWidget;
    QStatusBar *statusBar;
    QWidget *centralWidget1;
    QListWidget *m_ListBoxCameras;
    QListWidget *m_ListLog;
    QPushButton *m_ButtonStartStop;
    QLabel *m_LabelStream;

    void setupUi(QMainWindow *Logiciel_mecatroClass)
    {
        if (Logiciel_mecatroClass->objectName().isEmpty())
            Logiciel_mecatroClass->setObjectName(QStringLiteral("Logiciel_mecatroClass"));
        Logiciel_mecatroClass->resize(600, 400);
        menuBar = new QMenuBar(Logiciel_mecatroClass);
        menuBar->setObjectName(QStringLiteral("menuBar"));
        Logiciel_mecatroClass->setMenuBar(menuBar);
        mainToolBar = new QToolBar(Logiciel_mecatroClass);
        mainToolBar->setObjectName(QStringLiteral("mainToolBar"));
        Logiciel_mecatroClass->addToolBar(mainToolBar);
        centralWidget = new QWidget(Logiciel_mecatroClass);
        centralWidget->setObjectName(QStringLiteral("centralWidget"));
        Logiciel_mecatroClass->setCentralWidget(centralWidget);
        statusBar = new QStatusBar(Logiciel_mecatroClass);
        statusBar->setObjectName(QStringLiteral("statusBar"));
        Logiciel_mecatroClass->setStatusBar(statusBar);
        centralWidget1 = new QWidget(Logiciel_mecatroClass);
        centralWidget1->setObjectName(QStringLiteral("centralWidget1"));
        m_ListBoxCameras = new QListWidget(centralWidget1);
        m_ListBoxCameras->setObjectName(QStringLiteral("m_ListBoxCameras"));
        m_ListBoxCameras->setGeometry(QRect(0, 10, 261, 521));
        m_ListLog = new QListWidget(centralWidget1);
        m_ListLog->setObjectName(QStringLiteral("m_ListLog"));
        m_ListLog->setGeometry(QRect(0, 580, 1041, 191));
        m_ButtonStartStop = new QPushButton(centralWidget1);
        m_ButtonStartStop->setObjectName(QStringLiteral("m_ButtonStartStop"));
        m_ButtonStartStop->setGeometry(QRect(0, 540, 261, 31));
        m_LabelStream = new QLabel(centralWidget1);
        m_LabelStream->setObjectName(QStringLiteral("m_LabelStream"));
        m_LabelStream->setGeometry(QRect(270, 10, 771, 561));
        QSizePolicy sizePolicy(QSizePolicy::Fixed, QSizePolicy::Fixed);
        sizePolicy.setHorizontalStretch(0);
        sizePolicy.setVerticalStretch(0);
        sizePolicy.setHeightForWidth(m_LabelStream->sizePolicy().hasHeightForWidth());
        m_LabelStream->setSizePolicy(sizePolicy);
        Logiciel_mecatroClass->setCentralWidget(centralWidget1);

        retranslateUi(Logiciel_mecatroClass);

        QMetaObject::connectSlotsByName(Logiciel_mecatroClass);
    } // setupUi

    void retranslateUi(QMainWindow *Logiciel_mecatroClass)
    {
        Logiciel_mecatroClass->setWindowTitle(QApplication::translate("Logiciel_mecatroClass", "Logiciel_mecatro", 0));
        m_ButtonStartStop->setText(QApplication::translate("Logiciel_mecatroClass", "Acquire Single Image", 0));
        m_LabelStream->setText(QString());
    } // retranslateUi

};

namespace Ui {
    class Logiciel_mecatroClass: public Ui_Logiciel_mecatroClass {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_LOGICIEL_MECATRO_H
