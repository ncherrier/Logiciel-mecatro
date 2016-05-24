﻿/*=============================================================================
  Copyright (C) 2012 - 2016 Allied Vision Technologies.  All Rights Reserved.

  Redistribution of this file, in original or modified form, without
  prior written consent of Allied Vision Technologies is prohibited.

-------------------------------------------------------------------------------

  File:        ViewerWindow.cpp

  Description: The viewer window framework. 
               This contains of dock widgets like camera feature tree, a histogram, a toolbar and MDI window
               

-------------------------------------------------------------------------------

  THIS SOFTWARE IS PROVIDED BY THE AUTHOR "AS IS" AND ANY EXPRESS OR IMPLIED
  WARRANTIES, INCLUDING, BUT NOT LIMITED TO, THE IMPLIED WARRANTIES OF TITLE,
  NON-INFRINGEMENT, MERCHANTABILITY AND FITNESS FOR A PARTICULAR  PURPOSE ARE
  DISCLAIMED.  IN NO EVENT SHALL THE AUTHOR BE LIABLE FOR ANY DIRECT,
  INDIRECT, INCIDENTAL, SPECIAL, EXEMPLARY, OR CONSEQUENTIAL DAMAGES
  (INCLUDING, BUT NOT LIMITED TO, PROCUREMENT OF SUBSTITUTE GOODS OR SERVICES;
  LOSS OF USE, DATA, OR PROFITS; OR BUSINESS INTERRUPTION) HOWEVER CAUSED
  AND ON ANY THEORY OF LIABILITY, WHETHER IN CONTRACT, STRICT LIABILITY, OR
  TORT (INCLUDING NEGLIGENCE OR OTHERWISE) ARISING IN ANY WAY OUT OF THE USE
  OF THIS SOFTWARE, EVEN IF ADVISED OF THE POSSIBILITY OF SUCH DAMAGE.

=============================================================================*/


#include "ViewerWindow.h"
#include "UI/DockWidgetWindow.h"    
#include "UI/ControllerTreeWindow.h"
#include "UI/Viewer.h"
#include "UI/MainInformationWindow.h"
#include "UI/Histogram/HistogramWindow.h"
#include "SplashScreen.h"
#include "VmbImageTransformHelper.hpp"
#include <QtEndian>

using AVT::VmbAPI::Frame;
using AVT::VmbAPI::FramePtr;

#ifndef _WIN32
    #include <unistd.h>
#endif
void ViewerWindow::showSplashScreen(const QString & sID,QWidget* parent)
{
    bool    bIsModelFound = true;
    QPixmap pixmap;
    // We expect ID to be of format: Modelname (DevicePartNumber)-DeviceID(DEV_MAC@) while MAC@ has 12 digits
    if ( sID.contains( "Mako" ))
        pixmap.load( ":/VimbaViewer/Images/mako.png" );
    else if(sID.contains("Manta"))
        pixmap.load( ":/VimbaViewer/Images/manta.png" );
    else if(sID.contains("GT"))
    {
        if (   sID.contains( "4100 " )
            || sID.contains( "4905" )
            || sID.contains( "4907" )
            || sID.contains( "6600" ))
            pixmap.load( ":/VimbaViewer/Images/prosilicagt-large.png" );
        else
            pixmap.load( ":/VimbaViewer/Images/prosilicagt.png" );
    }
    else if(sID.contains("GC"))
        pixmap.load( ":/VimbaViewer/Images/prosilicagc.png" );
    else if(sID.contains("GX"))
        pixmap.load( ":/VimbaViewer/Images/prosilicagx.png" );
    else if(sID.contains("GE"))
        pixmap.load( ":/VimbaViewer/Images/prosilicage.png" );
    else if(sID.contains("Marlin"))
        pixmap.load( ":/VimbaViewer/Images/marlin.png" );
    else if(sID.contains("Guppy"))
    {
        if ( sID.contains( "PRO" ))
            pixmap.load( ":/VimbaViewer/Images/guppy-pro.png" );
        else
            pixmap.load( ":/VimbaViewer/Images/guppy.png" );
    }
    else if(sID.contains("Oscar"))
        pixmap.load( ":/VimbaViewer/Images/oscar.png" );
    else if(sID.contains("Pike"))
        pixmap.load( ":/VimbaViewer/Images/pike.png" );
    else if(sID.contains("Stingray"))
        pixmap.load( ":/VimbaViewer/Images/stingray.png" );
    else if(sID.contains("Bigeye"))
        pixmap.load( ":/VimbaViewer/Images/bigeye.png" );
    else if(sID.contains("Goldeye P"))
        pixmap.load( ":/VimbaViewer/Images/goldeye-p.png" );
    else if(sID.contains("Goldeye G") || sID.contains("Goldeye CL"))
    {
        if ( sID.contains( "Cool" ))
            pixmap.load( ":/VimbaViewer/Images/goldeye-g-cool.png" );
        else
            pixmap.load( ":/VimbaViewer/Images/goldeye-g.png" );
    }
    else
    {
        pixmap.load( ":/VimbaViewer/Images/stripes_256.png" );
        bIsModelFound = false;
    }

    SplashScreen splashScreen(pixmap, parent, Qt::SplashScreen);
    int nW = ((this->width()/2) - splashScreen.width()/2);
    int nH = ((this->height()/2) - splashScreen.height()/2);
    splashScreen.setGeometry(nW,nH, splashScreen.width(),splashScreen.height());
    splashScreen.show();
    if(bIsModelFound)
    {
        splashScreen.showMessage("" , Qt::AlignHCenter | Qt::AlignVCenter, Qt::white);
    }
    else
    {
        splashScreen.showMessage("" , Qt::AlignHCenter | Qt::AlignVCenter, Qt::black);
    }
}
ViewerWindow::ViewerWindow ( QWidget *parent, Qt::WindowFlags flag, QString sID, QString sAccess, bool bAutoAdjustPacketSize, CameraPtr pCam ) 
    : QMainWindow( NULL, flag )
    , m_DockController( NULL )
    , m_DockInformation( NULL )
    , m_Controller( NULL )
    , m_ScreenViewer( NULL )
    , m_InformationWindow( NULL )
    , m_bHasJustStarted ( false )
    , m_bIsFirstStart   ( true )
    , m_bIsCameraRunning ( false )
    , m_bIsCamOpen ( false )
    , m_bIsRedHighlighted ( false )
    , m_bIsViewerWindowClosing ( false )
    , m_bIsDisplayEveryFrame ( false )
    , m_ImageOptionDialog ( NULL )
    , m_saveFileDialog ( NULL )
    , m_getDirDialog ( NULL )
    , m_bIsTriggeredByMultiSaveBtn (false)
    , m_nNumberOfFramesToSave (0)
    , m_FrameBufferCount (BUFFER_COUNT)
{  
    m_pCam = pCam;
    
    showSplashScreen(sID,parent);

    VmbError_t errorType;
    QTime openTimer;
    openTimer.start();

    /* setup information window */
    m_InformationWindow = new MainInformationWindow(m_DockInformation, 0, m_pCam);
    m_InformationWindow->openLoggingWindow();
    
    if( 0 == sAccess.compare(tr("Open FULL ACCESS")))
    {
        errorType = m_pCam->Open(VmbAccessModeFull);
        m_sAccessMode = tr("(FULL ACCESS)");
    }
    else if( 0 == sAccess.compare(tr("Open READ ONLY")))
    {
        errorType = m_pCam->Open(VmbAccessModeRead);
        m_sAccessMode = tr("(READ ONLY)");
        bAutoAdjustPacketSize = false;
    }
    else if( 0 == sAccess.compare(tr("Open CONFIG")))
    {
        errorType = m_pCam->Open(VmbAccessModeConfig);
        m_sAccessMode = tr("(CONFIG MODE)");
        bAutoAdjustPacketSize = false;
    }
    else if( 0 == sAccess.compare(tr("Open LITE")))
    {
        errorType = m_pCam->Open(VmbAccessModeLite);
        m_sAccessMode = tr("(LITE)");
        bAutoAdjustPacketSize = false;
    }
    else
    {
        errorType = VmbErrorInvalidAccess;
        bAutoAdjustPacketSize = false;
    }

    m_OpenError = errorType;

    if( VmbErrorSuccess != errorType )
    {
        openTimer.elapsed();
        return;
    }
    
    m_sCameraID = sID;
    
    /* create ViewerWindow */
    setupUi(this);
    if(!m_sAccessMode.isEmpty())
    {
        sID.append(" ");
        sID.append(m_sAccessMode);
    }
    this->setWindowTitle(sID);

    ActionFreerun->setEnabled(isStreamingAvailable());

    /* add Viewer Widget to ViewerWindow*/
    m_pScene        = QSharedPointer<QGraphicsScene>(new QGraphicsScene());
    m_PixmapItem    = new QGraphicsPixmapItem();
    m_ScreenViewer  = new Viewer(Ui::ViewerWindow::centralWidget);
    m_ScreenViewer->setScene(m_pScene.data());
    m_pScene->addItem(m_PixmapItem);    
    this->setCentralWidget( m_ScreenViewer );
    QPixmap image( ":/VimbaViewer/Images/stripes_256.png" );
    m_PixmapItem->setPixmap(image);
    m_ScreenViewer->show();
    m_bIsCamOpen = true;
    
    /* add DockWidgets: Controller and Information */
    m_DockController   = new DockWidgetWindow(tr("Controller for ")+sID, this);
    m_DockInformation  = new DockWidgetWindow(tr("Information for ")+sID, this);
    m_DockHistogram    = new DockWidgetWindow(tr("Histogram for ")+sID, this);
    m_DockController->setObjectName("Controller");
    m_DockInformation->setObjectName("Information");
    m_DockHistogram->setObjectName("Histogram");

    this->addDockWidget(static_cast<Qt::DockWidgetArea>(2), m_DockController);
    this->addDockWidget(Qt::BottomDockWidgetArea, m_DockInformation);
    this->addDockWidget(static_cast<Qt::DockWidgetArea>(1), m_DockHistogram);
    m_DockHistogram->hide();
        
    /* add Controller Tree */
    
    QWidget     *dockWidgetContents   = new QWidget();
    QVBoxLayout *verticalLayout2      = new QVBoxLayout(dockWidgetContents); 
    QSplitter   *splitter             = new QSplitter(dockWidgetContents);
    QWidget     *verticalLayoutWidget = new QWidget(splitter);
    QVBoxLayout *verticalLayout       = new QVBoxLayout(verticalLayoutWidget); 
    QTabWidget  *tabWidget            = new QTabWidget(verticalLayoutWidget);
    QWidget     *widgetTree           = new QWidget(); 
    QVBoxLayout *verticalLayout3      = new QVBoxLayout(widgetTree);
    
    m_Description = new QTextEdit();
    m_Controller = new ControllerTreeWindow(m_sCameraID, widgetTree, bAutoAdjustPacketSize, m_pCam);

    if (VmbErrorSuccess != m_Controller->getTreeStatus())
    {
        onFeedLogger("ERROR: ControllerTree returned: "+QString::number(m_Controller->getTreeStatus()) + " " +  m_Helper.mapReturnCodeToString(m_Controller->getTreeStatus()));
    }

    m_Description->setLineWrapMode(QTextEdit::NoWrap); 
    m_Description->setReadOnly(true);
    m_Description->setStyleSheet("font: 12px;\n" "font-family: Verdana;\n");
    
    QList<int> listSize;
    listSize << 5000;
    splitter->setChildrenCollapsible(false);
    splitter->setOrientation(Qt::Vertical);
    splitter->addWidget(verticalLayoutWidget);
    splitter->addWidget(m_Description);
    splitter->setSizes(listSize);
    
    /* Filter Pattern */
    QHBoxLayout *pattern_HLayout = new QHBoxLayout();
    m_FilterPatternLineEdit = new LineEditCompleter(this);
    m_FilterPatternLineEdit->setText(tr("Example: Gain|Width"));
    m_FilterPatternLineEdit->setToolTip(tr("To filter multiple features, e.g: Width|Gain|xyz|etc"));
    m_FilterPatternLineEdit->setCompleter(m_Controller->getListCompleter());
    m_FilterPatternLineEdit->setMinimumWidth(200);
    QLabel *filterPatternLabel = new QLabel(tr("Filter pattern:"));
    filterPatternLabel->setStyleSheet("font-weight: bold;");
    QPushButton *patternButton = new QPushButton(tr("Search"));
    
    pattern_HLayout->addWidget(filterPatternLabel);
    pattern_HLayout->addWidget(m_FilterPatternLineEdit);
    pattern_HLayout->addWidget(patternButton);
    verticalLayout3->addLayout(pattern_HLayout);
   
    connect(m_FilterPatternLineEdit, SIGNAL(returnPressed()), this, SLOT(textFilterChanged()));
    connect(patternButton, SIGNAL(clicked(bool)), this, SLOT(textFilterChanged()));

    verticalLayout->setContentsMargins(0, 0, 0, 0);
    verticalLayout->addWidget(tabWidget);
    verticalLayout2->addWidget(splitter);
    verticalLayout3->addWidget(m_Controller);
    
   
    tabWidget->setStyleSheet("color: rgb(0, 0, 0);");

    // closed source injected
    if (loadPlugin())
    {
        for (int i = 0; i < m_TabPluginCount; i++)
        {
            QWidget *plugtabWidget = new QWidget();
            bool check = m_tabExtensionInterface[i]->connectToResetFps(this, SLOT(onResetFPS(void))); 
            m_tabExtensionInterface[i]->get(m_pCam, *plugtabWidget); 
            if (plugtabWidget->accessibleName() != "")
            {
             tabWidget->addTab(plugtabWidget, plugtabWidget->accessibleName());
            }
        }
    }

    tabWidget->addTab(widgetTree, tr("All"));
    m_DockController->setWidget(dockWidgetContents);
    connect(tabWidget, SIGNAL(currentChanged(int)), m_Controller, SLOT(closeControls()));
    
    /* tooltip checkbox */
    m_ToolTipCheckBox     = new QCheckBox();
    m_ToolTipCheckBox->setText(tr("Tooltip ON"));
    m_ToolTipCheckBox->setChecked(true);
    verticalLayout3->addWidget(m_ToolTipCheckBox);
    connect( m_ToolTipCheckBox, SIGNAL(clicked(bool)), this, SLOT(onTooltipCheckBoxClick(bool)) );
    

    connect(m_DockController,  SIGNAL(topLevelChanged  (bool)), this, SLOT(onfloatingDockChanged(bool)));
    connect(m_DockInformation, SIGNAL(topLevelChanged  (bool)), this, SLOT(onfloatingDockChanged(bool)));
    connect(m_DockHistogram,   SIGNAL(topLevelChanged  (bool)), this, SLOT(onfloatingDockChanged(bool)));

    connect(m_DockController,  SIGNAL(visibilityChanged(bool)), this, SLOT(onVisibilityChanged(bool)));
    connect(m_DockInformation, SIGNAL(visibilityChanged(bool)), this, SLOT(onVisibilityChanged(bool)));
    connect(m_DockHistogram,   SIGNAL(visibilityChanged(bool)), this, SLOT(onVisibilityChanged(bool)));

    connect(m_Controller,      SIGNAL(setDescription(const QString &)),  this, SLOT(onSetDescription(const QString &)));
    connect(m_Controller,      SIGNAL(setEventMessage(const QStringList &)), this, SLOT(onSetEventMessage(const QStringList &)), Qt::QueuedConnection);
    connect(m_Controller,      SIGNAL(acquisitionStartStop(const QString &)), this, SLOT(onAcquisitionStartStop(const QString &)));
    connect(m_Controller,      SIGNAL(updateBufferSize(void)), this, SLOT(onPrepareCapture(void)));
    connect(m_Controller,      SIGNAL(resetFPS(void)), this, SLOT(onResetFPS(void)));
    connect(m_Controller,      SIGNAL(logging(const QString &)), this, SLOT(onFeedLogger( const QString &)));
    connect(m_ScreenViewer,    SIGNAL(savingImage(void)), this, SLOT(on_ActionSaveAs_triggered(void)));
    connect(m_ScreenViewer,    SIGNAL(setColorInterpolationState(const bool &)), this, SLOT(onSetColorInterpolation(const bool &)));
    
    /* create FrameObserver to get frames from camera */
    SP_SET( m_pFrameObs, new FrameObserver(m_pCam) );

    connect(SP_ACCESS( m_pFrameObs ), SIGNAL(frameReadyFromObserver (QImage , const QString&, const QString&, const QString&)), 
        this, SLOT(onimageReady(QImage , const QString&, const QString&, const QString&)));

    connect(SP_ACCESS( m_pFrameObs ), SIGNAL(setCurrentFPS (const QString &)), 
        this, SLOT(onSetCurrentFPS(const QString &)));

    connect(SP_ACCESS( m_pFrameObs ), SIGNAL(setFrameCounter (const unsigned int &)), 
        this, SLOT(onSetFrameCounter(const unsigned int &)));

    /* HISTOGRAM: We need to register QVector<QVector <quint32> > because it is not known to Qt's meta-object system */
    qRegisterMetaType< QVector<QVector <quint32> > >("QVector<QVector <quint32> >");
    qRegisterMetaType< QVector <QStringList> >("QVector <QStringList>");

    connect(m_pFrameObs.get(), SIGNAL(histogramDataFromObserver ( const QVector<QVector <quint32> > &, const QString &, const double &, const double &, const QVector <QStringList>& )), 
        this, SLOT(onSetHistogramData( const QVector<QVector <quint32> > &, const QString &, const double &, const double & , const QVector <QStringList>&)));

    m_DockInformation->setWidget(m_InformationWindow);
    int openElapsedTime = openTimer.elapsed();
    if( openElapsedTime <= 2500 )
    {
#ifdef WIN32
        Sleep(2500-openElapsedTime);
#else
        usleep( (2500-openElapsedTime) * 1000 );
#endif
    }
    
    /* use default setting position and geometry */
    QSettings settings("Allied Vision", "Vimba Viewer");
    this->restoreGeometry(settings.value("geometry").toByteArray());
    this->restoreState( settings.value("state").toByteArray(), 0 );
    this->show();

    (!m_DockController->isFloating() && !m_DockInformation->isFloating() && m_DockController->isVisible() && m_DockInformation->isVisible()) ? ActionResetPosition->setEnabled(false) : ActionResetPosition->setEnabled(true);
    
    if( VmbErrorSuccess != m_Controller->getTreeStatus())
    {
        onFeedLogger("ERROR: GetFeatures returned: "+QString::number(m_Controller->getTreeStatus()) + " " +  m_Helper.mapReturnCodeToString(m_Controller->getTreeStatus()));
    }

    /* Histogram */
    m_HistogramWindow = new HistogramWindow(this);
    m_DockHistogram->setWidget(m_HistogramWindow);
    m_HistogramWindow->createGraphWidgets();
    
    m_DockHistogram->isVisible() ? ActionHistogram->setChecked(true) : ActionHistogram->setChecked(false);

    /* Statusbar */
    m_OperatingStatusLabel = new QLabel(" Ready ");
    m_FormatLabel          = new QLabel;
    m_ImageSizeLabel       = new QLabel;
    m_FramesLabel          = new QLabel;
    m_FramerateLabel       = new QLabel;

    statusbar->addWidget(m_OperatingStatusLabel);
    statusbar->addWidget(m_ImageSizeLabel);
    statusbar->addWidget(m_FormatLabel);
    statusbar->addWidget(m_FramesLabel);
    statusbar->addWidget(m_FramerateLabel);

    m_OperatingStatusLabel->setStyleSheet("background-color: rgb(0,0, 0); color: rgb(255,255,255)");

    m_TextItem =  new QGraphicsTextItem;
    QFont serifFont("Arial", 12, QFont::Bold);
    m_TextItem->setFont(serifFont);
    m_TextItem->setDefaultTextColor(Qt::red);

    /*Save Images Option */
    m_ImageOptionDialog = new QDialog(this, windowFlags() & ~Qt::WindowContextHelpButtonHint & ~Qt::WindowMinimizeButtonHint & ~Qt::WindowMaximizeButtonHint);
    m_SaveImageOption.setupUi(m_ImageOptionDialog);
    if(!settings.value(m_sCameraID).toString().isEmpty())
        m_SaveImageOption.ImageDestination_Edit->setText (settings.value(m_sCameraID).toString());
    else
    {
        m_SaveImageOption.ImageDestination_Edit->setText( QString(   
#ifdef WIN32
            "C:\\"
#else
            "/home/"
#endif
            ));
    }

    connect(m_SaveImageOption.ImageDestinationButton, SIGNAL(clicked()),this, SLOT(getSaveDestinationPath()));
    connect(m_ImageOptionDialog, SIGNAL(accepted()),this, SLOT(acceptSaveImagesDlg()));
    connect(m_ImageOptionDialog, SIGNAL(rejected()),this, SLOT(rejectSaveImagesDlg()));

    if(!settings.value(m_sCameraID+"SaveImageName").toString().isEmpty())
        m_SaveImageOption.ImageName_Edit->setText (settings.value(m_sCameraID+"SaveImageName").toString());
    else
        m_SaveImageOption.ImageName_Edit->setText("VimbaImage");
    
    /* Direct Access */
    m_AccessDialog = new QDialog(this, windowFlags() & ~Qt::WindowContextHelpButtonHint & ~Qt::WindowMinimizeButtonHint & ~Qt::WindowMaximizeButtonHint);
    m_DirectAccess.setupUi(m_AccessDialog);    
    m_DirectAccess.RegAdd_Edit->setMaxLength(8);
    m_DirectAccess.RegData_Edit->setMaxLength(8);
    m_DirectAccess.RegAdd_Edit->setText("FFFFFFFC");
    m_DirectAccess.RegData_Edit->setText("00000000");
    m_DirectAccess.RegDataDec_Edit->setText("0");
    VmbInterfaceType InterfaceType = VmbInterfaceUnknown;
    m_DirectAccess.CheckBoxEndianess->setVisible( VmbErrorSuccess == m_pCam->GetInterfaceType(InterfaceType) );
    m_DirectAccess.CheckBoxEndianess->setChecked( VmbInterfaceUsb == InterfaceType );
    m_DirectAccess.CheckBoxEndianess->setToolTip( m_DirectAccess.CheckBoxEndianess->toolTip() + " (your device was detected to be " + (VmbInterfaceUsb == InterfaceType ? "little" : "big") + " endian)");

    m_AccessDialog->setWindowFlags(windowFlags() & ~Qt::WindowContextHelpButtonHint & ~Qt::WindowMinimizeButtonHint);    
    
    QRegExp rxHex("[0-9A-Fa-f]{1,8}");
    m_DirectAccess.RegAdd_Edit->setValidator(new QRegExpValidator(rxHex, m_DirectAccess.RegAdd_Edit)); 
    m_DirectAccess.RegData_Edit->setValidator(new QRegExpValidator(rxHex, m_DirectAccess.RegData_Edit)); 

    QRegExp rxDec("[0-9]{1,10}");
    m_DirectAccess.RegDataDec_Edit->setValidator(new QRegExpValidator(rxDec, m_DirectAccess.RegDataDec_Edit)); 

    connect(m_DirectAccess.RegWrite_Button  , SIGNAL(clicked())                     , this, SLOT(writeRegisterData()));
    connect(m_DirectAccess.RegRead_Button   , SIGNAL(clicked())                     , this, SLOT(readRegisterData()));
    connect(m_DirectAccess.RegData_Edit     , SIGNAL(textChanged(const QString&))   , this, SLOT(directAccessHexTextChanged(const QString&)));
    connect(m_DirectAccess.RegDataDec_Edit  , SIGNAL(textChanged(const QString&))   , this, SLOT(directAccessDecTextChanged(const QString&)));
    connect(m_DirectAccess.CheckBoxEndianess, SIGNAL(stateChanged(int))             , this, SLOT(endianessChanged(int)));

    /*Viewer Option */
    m_ViewerOptionDialog = new QDialog(this, windowFlags() & ~Qt::WindowContextHelpButtonHint & ~Qt::WindowMinimizeButtonHint & ~Qt::WindowMaximizeButtonHint);
    m_ViewerOption.setupUi(m_ViewerOptionDialog);
    m_ViewerOption.lineEdit_FramesCount->setText(QString::number( m_FrameBufferCount ));
    connect( m_ViewerOption.lineEdit_FramesCount, SIGNAL(textChanged(const QString&)),this, SLOT(optionsFrameCountChanged(const QString&)));
    connect( m_ViewerOption.DisplayInterval_CheckBox, SIGNAL(clicked(bool)), this, SLOT(displayEveryFrameClick(bool)));
    connect( m_ViewerOption.buttonBox, SIGNAL(accepted()),this, SLOT(optionsAccepted()));

    //connect(parent, SIGNAL(closeViewer()), this, SLOT(close()));


    if (ActionHistogram->isChecked())
    {
        m_HistogramWindow->initializeStatistic();
        m_pFrameObs->enableHistogram(true);
    }
    else
        m_pFrameObs->enableHistogram(false);

    m_Timer = new QTimer(this);
    connect(m_Timer, SIGNAL(timeout()), this, SLOT(updateColorInterpolationState()));
    
    /* enable/disable menu */
    connect(m_Controller, SIGNAL(enableViewerMenu(bool)), this, SLOT(enableMenuAndToolbar(bool)));

    /* saving images */
    m_SaveImageThread = QSharedPointer<SaveImageThread>(new SaveImageThread());
    connect(m_SaveImageThread.data(), SIGNAL(setPosition(unsigned int)), this, SLOT(onSaving(unsigned int)));
    m_SaveImageThread->m_nImagePosition = 0;

    m_FilterPatternLineEdit->setFocus();
    m_FilterPatternLineEdit->selectAll();

#ifdef WIN32
    m_SelectedExtension = ".bmp";
#else
    m_SelectedExtension = ".png";
#endif
}

ViewerWindow::~ViewerWindow ( void )
{
    /* save setting position and geometry from last session */
    QSettings settings("Allied Vision", "Vimba Viewer");
    settings.setValue("geometry", saveGeometry());
    settings.setValue("state", saveState(0));
    
    /* If cam is open */
    if(!m_sCameraID.isEmpty())
    {
        settings.setValue(m_sCameraID,  m_SaveImageOption.ImageDestination_Edit->text());
        if(!m_SaveName.isEmpty())
            settings.setValue(m_sCameraID +"SaveImageName", m_SaveName+"_"+QString::number(m_SaveImageThread->m_nImagePosition));

        if( NULL != m_saveFileDialog )
        {
            delete m_saveFileDialog;
            m_saveFileDialog = NULL;
        }

        VmbError_t error = releaseBuffer();

        m_pCam->Close();
    }
}

void ViewerWindow::textFilterChanged ( void )
{
    QPixmap pixmap( ":/VimbaViewer/Images/refresh.png" );
    SplashScreen splashScreen(pixmap, m_Controller, Qt::SplashScreen);
    int nW = ((m_Controller->width()/2) - splashScreen.width()/2);
    int nH = ((m_Controller->height()/2) - splashScreen.height()/2);
    splashScreen.setGeometry(nW,nH, splashScreen.width(),splashScreen.height());
    splashScreen.show();
    splashScreen.showMessage("Please wait..." , Qt::AlignHCenter | Qt::AlignVCenter, Qt::red);

    QRegExp::PatternSyntax syntax = QRegExp::PatternSyntax(0);
    Qt::CaseSensitivity caseSensitivity = Qt::CaseInsensitive;
        
    QRegExp regExp(m_FilterPatternLineEdit->text(), caseSensitivity, syntax);
    m_Controller->m_ProxyModel->setFilterRegExp(regExp);
    m_Controller->expandAll();
    //m_Controller->updateUnRegisterFeature();
    m_Controller->updateRegisterFeature();
    m_FilterPatternLineEdit->setFocus();
    m_FilterPatternLineEdit->selectAll();
}

void ViewerWindow::enableMenuAndToolbar ( bool bValue )
{
    menuBarMainWindow->setEnabled(bValue);
    toolBar->setEnabled(bValue);
}

void ViewerWindow::onTooltipCheckBoxClick ( bool bValue )
{
    m_Controller->showTooltip ( bValue );
}

void ViewerWindow::updateColorInterpolationState ( void )
{
    /* update interpolation state after start */
    m_ScreenViewer->updateInterpolationState(m_pFrameObs->getColorInterpolation());
    m_Timer->stop();
}

void ViewerWindow::onSetColorInterpolation ( const bool &bState )
{
    m_pFrameObs->setColorInterpolation(bState);
}

bool ViewerWindow::getCamOpenStatus ( void )
{
    return m_bIsCamOpen;
}

bool  ViewerWindow::getAdjustPacketSizeMessage ( QString &sMessage )
{
    if(m_Controller->isGigE())
    {
        if(VmbErrorSuccess == m_Controller->getTreeStatus())
        {
            sMessage = "Packet Size Adjusted:\t";
        }
        else
        {
            sMessage = "Failed To Adjust Packet Size!";
            sMessage.append(" Reason: " + m_Helper.mapReturnCodeToString(m_Controller->getTreeStatus()));
        }

        return true;
    }

    return false;
}

VmbError_t ViewerWindow::getOpenError ( void )
{
    return m_OpenError;
}

QString ViewerWindow::getCameraID( void ) 
{ 
    return m_sCameraID; 
}

void ViewerWindow::closeEvent ( QCloseEvent *event ) 
{
    if (m_bIsCameraRunning)
    {
        m_bIsViewerWindowClosing = true;
        onAcquisitionStartStop("AcquisitionStopFreerun");
    }
    emit closeViewer( m_sCameraID );
}

void ViewerWindow::displayEveryFrameClick ( bool bValue )
{
    m_ViewerOption.Note_Label->setEnabled(bValue);
    m_bIsDisplayEveryFrame = bValue;    
}

/* Viewer Option */
void ViewerWindow::on_ActionDisplayOptions_triggered( void )
{
    m_ViewerOption.lineEdit_FramesCount->setText(QString::number ( m_FrameBufferCount ));
    m_ViewerOptionDialog->exec();
}

void ViewerWindow::on_ActionResetPosition_triggered ( void )
{
    m_DockController ->setFloating(false);
    m_DockInformation->setFloating(false);
    m_DockHistogram  ->setFloating(false);
    m_DockController ->show();
    m_DockInformation->show();
    m_DockHistogram  ->hide();
    ActionHistogram  ->setChecked(false);    
    ActionResetPosition->setEnabled(false);
}

/* Direct Register Access */
void ViewerWindow::on_ActionRegister_triggered ( void )
{
    m_DirectAccess.RegAccessError_Label->clear();
    m_DirectAccess.RegAccessError_Label->setStyleSheet("");
    m_DirectAccess.RegAdd_Edit->setFocus();
    m_DirectAccess.RegAdd_Edit->selectAll();
    m_AccessDialog->show();
}

void ViewerWindow::optionsFrameCountChanged ( const QString &sText )
{
    bool bOk;
    unsigned int frames = sText.toUInt(&bOk);

    if(!bOk)
    {
        m_ViewerOption.buttonBox->button(QDialogButtonBox::Ok)->setEnabled(false);
        return;
    }
    if(  (0 != QString::number(frames).compare(m_ViewerOption.lineEdit_FramesCount->text()))
       ||(frames < 2))
    {
        m_ViewerOption.buttonBox->button(QDialogButtonBox::Ok)->setEnabled(false);
        return;
    }
    m_ViewerOption.buttonBox->button(QDialogButtonBox::Ok)->setEnabled(true);
}

void ViewerWindow::optionsAccepted ( void )
{
    bool bOk;

    unsigned int frames = m_ViewerOption.lineEdit_FramesCount->text().toUInt(&bOk);

    if (!bOk)
    {
        return;
    }
    m_FrameBufferCount = frames;
}


void ViewerWindow::directAccessHexTextChanged ( const QString &sText )
{
    bool bOk;
    unsigned int sDec = sText.toUInt(&bOk, 16);
    endianessConvert( sDec );
    if(0 == QString::number(sDec).compare(m_DirectAccess.RegDataDec_Edit->text()))
        return;
    else
        m_DirectAccess.RegDataDec_Edit->setText(QString::number(sDec));
}

void ViewerWindow::directAccessDecTextChanged ( const QString &sText )
{
    unsigned int lDecValue = sText.toUInt();
    endianessConvert( lDecValue );
    QString sHex;
    sHex.setNum(lDecValue,16);

    if(0 == sHex.compare(m_DirectAccess.RegData_Edit->text()))
        return;
    else
        m_DirectAccess.RegData_Edit->setText(sHex);
}

void ViewerWindow::writeRegisterData ( void )
{
    bool bOk;
    qlonglong lRegAddress = m_DirectAccess.RegAdd_Edit->text().toLongLong(&bOk, 16);
    qlonglong lRegData    = m_DirectAccess.RegData_Edit->text().toLongLong(&bOk, 16);
    m_DirectAccess.RegAccessError_Label->clear();
    m_DirectAccess.RegAccessError_Label->setStyleSheet("background-color: rgb(240,240,240); color: rgb(0,0,0)");

    m_DirectAccess.RegDataDec_Edit->setFocus();
    m_DirectAccess.RegDataDec_Edit->selectAll();

    std::vector<VmbUint64_t> address;
    address.push_back((VmbUint64_t)lRegAddress);
    std::vector<VmbUint64_t> data;
    data.push_back((VmbUint64_t)lRegData);
    VmbError_t errorType = m_pCam->WriteRegisters(address, data);
    if( VmbErrorSuccess != errorType )
    {
        m_DirectAccess.RegAccessError_Label->setStyleSheet("background-color: rgb(0,0,0); color: rgb(255,0,0)");
        m_DirectAccess.RegAccessError_Label->setText(" "+tr("Write Register Failed!")+" <"+tr("Error")+": " + QString::number(errorType) + ">");
    }
}

void ViewerWindow::readRegisterData ( void )
{
    bool bOk;
    qlonglong lRegAddress = m_DirectAccess.RegAdd_Edit->text().toLongLong(&bOk, 16);

    m_DirectAccess.RegAccessError_Label->clear();
    m_DirectAccess.RegAccessError_Label->setStyleSheet("background-color: rgb(240,240,240); color: rgb(0,0,0)");

    std::vector<VmbUint64_t> address;
    address.push_back((VmbUint64_t)lRegAddress);

    std::vector<VmbUint64_t> data;    
    data.resize(1);
    VmbError_t errorType = m_pCam->ReadRegisters(address, data);    
    if( VmbErrorSuccess != errorType )
    {
        m_DirectAccess.RegAccessError_Label->setStyleSheet("background-color: rgb(0,0,0); color: rgb(255,0,0)");
        m_DirectAccess.RegAccessError_Label->setText(" "+tr("Read Register Failed!")+" <"+tr("Error:")+" " + QString::number(errorType) + ">");
        return;
    }
    QString sData = QString("%1").arg(data[0], 8, 16, QLatin1Char('0'));
    m_DirectAccess.RegData_Edit->setText(sData);
}

void ViewerWindow::endianessChanged(int index)
{
    emit directAccessDecTextChanged( m_DirectAccess.RegDataDec_Edit->text() );
}
template <typename T>
void ViewerWindow::endianessConvert(T &v)
{    
    if( Qt::Checked == m_DirectAccess.CheckBoxEndianess->checkState() )
    {
        v = qFromBigEndian( v );
    }
}
/* Saving an image */
void ViewerWindow::on_ActionSaveAs_triggered ( void )
{
    QImage image = m_PixmapItem->pixmap().toImage();
    QString fileExtension;

    /* Get all inputformats */
    unsigned int nFilterSize = QImageReader::supportedImageFormats().count();
    for (int i = nFilterSize-1; i >= 0; i--) 
    {
        fileExtension += "."; /* Insert wildcard */
        fileExtension += QString(QImageReader::supportedImageFormats().at(i)).toLower(); /* Insert the format */
        if(0 != i)
            fileExtension += ";;"; /* Insert a space */
    }

     if( NULL != m_saveFileDialog )
     {
         delete m_saveFileDialog;
         m_saveFileDialog = NULL;
     }

    m_saveFileDialog = new QFileDialog ( this, tr("Save Image"), m_SaveFileDir, fileExtension );
    m_saveFileDialog->setWindowFlags(windowFlags() & ~Qt::WindowContextHelpButtonHint & ~Qt::WindowMinimizeButtonHint & ~Qt::WindowMaximizeButtonHint); 
    m_saveFileDialog->selectFilter(m_SelectedExtension);
    m_saveFileDialog->setAcceptMode(QFileDialog::AcceptSave);
    
    if(m_saveFileDialog->exec())
    {   //OK
       m_SelectedExtension = m_saveFileDialog->selectedNameFilter();
       m_SaveFileDir = m_saveFileDialog->directory().absolutePath();
       QStringList files = m_saveFileDialog->selectedFiles();

       if(!files.isEmpty())
       {
            QString fileName = files.at(0);
           
            if(!fileName.endsWith(m_SelectedExtension))
            {
                fileName.append(m_SelectedExtension);
            }

            bool saved = false;
            if( true == CanReduceBpp() )
            {
                saved = ReduceBpp( image ).save( fileName );
            }
            else
            {
                saved = image.save( fileName );
            }
            if ( true == saved )
            {
                QMessageBox::information( this, tr( "Vimba Viewer" ), tr( "Image: " ) + fileName + tr( " saved successfully" ));
            }
            else
            {
                QMessageBox::warning( this, tr( "Vimba Viewer" ), tr( "Error saving image" ));
            }
        }
    }
}

/* Saving multiple images */
void ViewerWindow::on_ActionSaveOptions_triggered ( void )
{
    QStringList sListFormat;

    for (int i = 0; i < QImageReader::supportedImageFormats().count(); i++) 
    {
        QString sTemp;
        sTemp.append("."); /* Insert wildcard */
        sTemp.append(QString(QImageReader::supportedImageFormats().at(i)).toLower()); /* Insert the format */
        sListFormat << sTemp;
    }

    sListFormat << ".bin";

    m_SaveImageOption.ImageFormat_ComboBox->clear();
    m_SaveImageOption.ImageFormat_ComboBox->addItems(sListFormat);
    m_ImageOptionDialog->setModal(true);
    m_ImageOptionDialog->show();
}

void ViewerWindow::acceptSaveImagesDlg ( void )
{
    if( !m_SaveImageOption.ImageDestination_Edit->text().isEmpty() && 
        !m_SaveImageOption.ImageName_Edit->text().isEmpty() )
    {            
        m_ImagePath =  m_SaveImageOption.ImageDestination_Edit->text();
    }
    else
    {
        if(m_SaveImageOption.ImageDestination_Edit->text().isEmpty())
            QMessageBox::warning( this, tr("Vimba Viewer"), "<Save Image Options> "+tr("Please choose your destination path!") );
    
        if(m_SaveImageOption.ImageName_Edit->text().isEmpty())
            QMessageBox::warning( this, tr("Vimba Viewer"), "<Save Image Options> "+tr("Please give a name!") );

        m_ImageOptionDialog->setModal(true);
        m_ImageOptionDialog->show();
    }
    
    /* name check existing files */
    QDir destDir( m_SaveImageOption.ImageDestination_Edit->text());
    QStringList filter;
    
    for (int i = 0; i < QImageReader::supportedImageFormats().count(); i++) 
    {
        QString sTemp;
        sTemp.append("*."); /* Insert wildcard */
        sTemp.append(QString(QImageReader::supportedImageFormats().at(i)).toLower()); /* Insert the format */
        filter << sTemp;
    }
    
    destDir.setNameFilters(filter);
    QStringList files = destDir.entryList();
    
    bool bRes = true;
    while(bRes)
    {
        bRes = checkUsedName(files);
    }   

    if(0 < m_SaveImageOption.NumberOfFrames_SpinBox->value())
        ActionSaveImages->setEnabled(true);
    else
        ActionSaveImages->setEnabled(false);
}

void ViewerWindow::rejectSaveImagesDlg ( void )
{
    QString sPathBefore = m_SaveImageOption.ImageDestination_Edit->text();
    m_SaveImageOption.ImageDestination_Edit->setText(sPathBefore);
}

bool ViewerWindow::checkUsedName ( const QStringList &files )
{
    for( int nPos = 0; nPos < files.size(); nPos++ )
    {
        if(0 == files.at(nPos).compare(m_SaveImageOption.ImageName_Edit->text()+"_1"+m_SaveImageOption.ImageFormat_ComboBox->currentText()))
        {
            m_SaveImageOption.ImageName_Edit->setText(m_SaveImageOption.ImageName_Edit->text()+"_New");
            return true;
        }
    }

    return false;
}

bool ViewerWindow::isDestPathWritable  ( void )
{
    /* check permission of destination */
    QString sTmpPath = m_SaveImageOption.ImageDestination_Edit->text().append("/").append("fileTmp.dat");
    QFile fileTmp(sTmpPath);

    if(!fileTmp.open( QIODevice::ReadWrite|QIODevice::Text))
    {
        QMessageBox::warning( this, tr("Vimba Viewer"), "<Save Image Options> "+tr("No permission to write to destination path. Please select another one! ") );
        return false;
    }

    fileTmp.close();
    QFile::remove(sTmpPath);
    return true;
}

/* confirm saving from toolbar */
void ViewerWindow::on_ActionSaveImages_triggered ( void )
{

#ifdef _WIN32 // Do the check always on Windows
    if (!isDestPathWritable())
    {
        ActionSaveImages->setEnabled(false);
        return;
    }
#else
    #ifndef WIN32
        if (!isDestPathWritable())
        {
            ActionSaveImages->setEnabled(false);
            return;
        }
    #endif
#endif

    //overwrite existing name
    if(0 != m_SaveImageOption.ImageName_Edit->text().compare(m_SaveImageName))
    {
        m_SaveImageThread->m_nImagePosition = 0;
        m_SaveImageName = m_SaveImageOption.ImageName_Edit->text();
    }
  
    m_nImageCounter = 0;
    m_nNumberOfFramesToSave = m_SaveImageOption.NumberOfFrames_SpinBox->value();
    m_SaveFormat = m_SaveImageOption.ImageFormat_ComboBox->currentText();
    m_SaveName = m_SaveImageOption.ImageName_Edit->text();

    if( 0 < m_nNumberOfFramesToSave )
    {
        if( 0 == m_SaveImageOption.ImageFormat_ComboBox->currentText().compare(".bin"))
            m_pFrameObs->saveRawData(m_nNumberOfFramesToSave, m_ImagePath, m_SaveName);

        m_bIsTriggeredByMultiSaveBtn = true;
        ActionFreerun->setChecked(isStreamingAvailable());
        on_ActionFreerun_triggered();
        ActionFreerun->setEnabled(false);
    }
}

void ViewerWindow::getSaveDestinationPath ( void )
{
    if( NULL != m_getDirDialog )
    {
        delete m_getDirDialog;
        m_getDirDialog = NULL;
    }

    m_getDirDialog = new QFileDialog ( this, tr("Destination"), m_SaveImageOption.ImageDestination_Edit->text());
    QFileDialog::Options options = QFileDialog::DontResolveSymlinks | QFileDialog::ShowDirsOnly |QFileDialog::DontUseNativeDialog;
    m_getDirDialog->setOptions(options);
    m_getDirDialog->setWindowFlags(windowFlags() & ~Qt::WindowContextHelpButtonHint & ~Qt::WindowMinimizeButtonHint & ~Qt::WindowMaximizeButtonHint); 
    m_getDirDialog->setLabelText(QFileDialog::LookIn, tr("Destination Path"));
    m_getDirDialog->setLabelText(QFileDialog::FileType, tr("Type")); 
    m_getDirDialog->setFileMode( QFileDialog::Directory);
  
    QString sDir;
    if( m_getDirDialog->exec() )
    {   //OK
        sDir = m_getDirDialog->directory().absolutePath();
    }
  
    if(!sDir.isEmpty())
        m_SaveImageOption.ImageDestination_Edit->setText(sDir);
}

void ViewerWindow::on_ActionLeftRotation_triggered ( void )
{
    m_ScreenViewer->rotate(-90);
}

void ViewerWindow::on_ActionRightRotation_triggered ( void )
{
    m_ScreenViewer->rotate(90);
}

void ViewerWindow::on_ActionZoomOut_triggered ( void )
{
    m_ScreenViewer->zoomOut();
}

void ViewerWindow::on_ActionZoomIn_triggered ( void )
{
    m_ScreenViewer->zoomIn();
}

void ViewerWindow::on_ActionOriginalSize_triggered ( void )
{
    m_ScreenViewer->setDefaultSize();
}

void ViewerWindow::on_ActionFitToWindow_triggered ( void )
{
    m_ScreenViewer->setDefaultSize();

    if (ActionFitToWindow->isChecked())
    {
        m_ScreenViewer->setToolTip(tr(""));
        m_ScreenViewer->fitInView(m_pScene->itemsBoundingRect(), Qt::IgnoreAspectRatio);
        m_ScreenViewer->enableFitToWindow(true);
        ActionLeftRotation->setEnabled(false);
        ActionRightRotation->setEnabled(false);
        ActionOriginalSize->setEnabled(false);
        ActionZoomIn->setEnabled(false);
        ActionZoomOut->setEnabled(false);
    }
    else
    {    
        m_ScreenViewer->enableFitToWindow(false);
        ActionLeftRotation->setEnabled(true);
        ActionRightRotation->setEnabled(true);
        ActionOriginalSize->setEnabled(true);
        ActionZoomIn->setEnabled(true);
        ActionZoomOut->setEnabled(true);
    }
}

void ViewerWindow::on_ActionHistogram_triggered ( void )
{
    m_HistogramWindow->deinitializeStatistic();

    if (ActionHistogram->isChecked())
    {
        m_HistogramWindow->initializeStatistic();
        m_DockHistogram->show();
        m_pFrameObs->enableHistogram(true);
    }
    else
    {
        m_DockHistogram->hide();
        m_pFrameObs->enableHistogram(false);
    }
      
    if(!ActionHistogram->isChecked() && m_DockController->isVisible() && m_DockInformation->isVisible())
        ActionResetPosition->setEnabled(false);
}

void ViewerWindow::on_ActionLoadCameraSettings_triggered(void)
{
    VmbErrorType err = VmbErrorSuccess;
    bool proceedLoading = true;

//  create window title
    QString windowTitle = tr( "Load Camera Settings" );

//  setup message boxes
    QMessageBox msgbox;
    msgbox.setWindowTitle( windowTitle );
    QMessageBox msgbox2;
    msgbox2.setStandardButtons( QMessageBox::Yes );
    msgbox2.addButton( QMessageBox::No );
    msgbox2.setDefaultButton( QMessageBox::No );

//  check if camera was opened in 'full access' mode
    if( 0 != m_sAccessMode.compare( tr("(FULL ACCESS)") ) )
    {
        msgbox.setIcon( QMessageBox::Critical );
        msgbox.setText( tr("Camera must be opened in FULL ACCESS mode to use this feature") );
        msgbox.exec();
        return;
    }

//  check if any file dialog was created already
    if( NULL != m_saveFileDialog )
    {
        delete m_saveFileDialog;
        m_saveFileDialog = NULL;
     }

//  create file dialog
    m_saveFileDialog = new QFileDialog( this, windowTitle, QDir::home().absolutePath(), "*.xml" );
    m_saveFileDialog->setWindowFlags( windowFlags() & ~Qt::WindowContextHelpButtonHint & ~Qt::WindowMinimizeButtonHint & ~Qt::WindowMaximizeButtonHint );
    m_saveFileDialog->selectFilter( "*.xml" );
    m_saveFileDialog->setAcceptMode( QFileDialog::AcceptOpen );
    m_saveFileDialog->setFileMode( QFileDialog::ExistingFile );

//  show dialog
    int rval = m_saveFileDialog->exec();
    if( 0 == rval )
    {
        return;
    }

//  get selected file
    m_SaveFileDir = m_saveFileDialog->directory().absolutePath();
    QStringList selectedFiles = m_saveFileDialog->selectedFiles();
    if( true == selectedFiles.isEmpty() )
    {
        msgbox.setIcon( QMessageBox::Critical );
        msgbox.setText( tr("No file selected") );
        msgbox.exec();
        return;
    }

//  delete file dialog
//  (to prevent OCT-1870 bug occured with Qt v4.7.1)
    delete m_saveFileDialog;
    m_saveFileDialog = NULL;

//  get selected file
    QString selectedFile = selectedFiles.at(0);

//  check if xml file is valid
    if( false == selectedFile.endsWith( ".xml" ) )
    {
        msgbox.setIcon( QMessageBox::Critical );
        msgbox.setText( tr("Invalid xml file selected.\nFile must be of type '*.xml'") );
        msgbox.exec();
        return;
    }

//  create and prepare xml parser
//  to check if model name differences between xxml file
//  and connected camera exist
    QXmlStreamReader xml;
    QFile xmlFile( selectedFile );
    QString deviceModel = QString( "" );

//  open xml file stream
    bool check = xmlFile.open( QIODevice::ReadOnly );
    if( false == check )
    {
        msgbox2.setIcon( QMessageBox::Warning );
        msgbox2.setText( tr("Could not validate camera model.\nDo you want to proceed loading settings to selected camera ?") );
        rval = msgbox2.exec();
        if( QMessageBox::No == rval )
        {
            proceedLoading = false;
        }
    }
    else
    {
    //  connect opened file with xml stream object
        xml.setDevice( &xmlFile );
    }

//  proceed loading camera settings only if flag still true
    if( true == proceedLoading )
    {
    //  read xml structure
        while( false == xml.atEnd() )
        {
        //  get current xml token
            xml.readNext();
            QString currentToken = xml.name().toString();

        //  check if token is named 'CameraSettings'
            if( 0 == currentToken.compare( "CameraSettings" ) )
            {
            //  get token attributes and iterate through them
                QXmlStreamAttributes attributes = xml.attributes();
                for( int i=0; i<attributes.count(); ++i )
                {
                //  get current attribute
                    QXmlStreamAttribute currentAttribute = attributes.at(i);

                //  check if current attribute is name 'CameraModel'
                    QString attributeName = currentAttribute.name().toString();
                    if( 0 == attributeName.compare( "CameraModel" ) )
                    {
                        deviceModel = currentAttribute.value().toString();
                        break;
                    }
                }
                break;
            }
        }

    //  close xml file stream
        xmlFile.close();

    //  check if deviceModel was retrieved from xml file
        if( true == deviceModel.isEmpty() )
        {
            msgbox2.setIcon( QMessageBox::Warning );
            msgbox2.setText( tr("Could not validate camera model.\nDo you want to proceed loading settings to selected camera ?") );
            rval = msgbox2.exec();
            if( QMessageBox::No == rval )
            {
                proceedLoading = false;
            }
        }
    }

//  proceed loading camera settings only if flag still true
    std::string modelName;
    if( true == proceedLoading )
    {
    //  get model name from connected camera
        err = m_pCam->GetModel( modelName );
        if( VmbErrorSuccess != err )
        {
            msgbox2.setIcon( QMessageBox::Warning );
            msgbox2.setText( tr("Could not validate camera model.\nDo you want to proceed loading settings to selected camera ?") );
            rval = msgbox2.exec();
            if( QMessageBox::No == rval )
            {
                proceedLoading = false;
            }
        }
    }

//  proceed loading camera settings only if flag still true
    if( true == proceedLoading )
    {
    //  compare mode names from xml file and from 
    //  connected device with each other
        if( 0 != deviceModel.compare( QString(modelName.c_str()) ) )
        {
            QString msgtext = tr( "Selected camera model is different from xml file.\n");
            msgtext.append( tr("[camera: %1]\n").arg( modelName.c_str() ) );
            msgtext.append( tr("[xml: %1]\n\n").arg( deviceModel) );
            msgtext.append( tr("Do you want to proceed loading operation ?" ) );
            msgbox2.setIcon( QMessageBox::Warning );
            msgbox2.setText( msgtext );
            rval = msgbox2.exec();
            if( QMessageBox::No == rval )
            {
                proceedLoading = false;
            }
        }
    }

//  proceed loading camera settings only if flag still true
    if( true == proceedLoading )
    {
    //  setup behaviour for loading and saving camera features
        m_pCam->LoadSaveSettingsSetup( VmbFeaturePersistNoLUT, 5, 4 );

    //  call load method from VimbaCPP
        err = m_pCam->LoadCameraSettings( selectedFile.toStdString() );
        if( VmbErrorSuccess != err )
        {
            QString msgtext = tr( "There have been errors during loading of feature values.\n" );
            msgtext.append( tr("[Error code: %1]\n").arg( err ) );
            msgtext.append( tr("[file: %1]").arg( selectedFile) );
            onFeedLogger( "ERROR: LoadCameraSettings returned: " + QString::number(err) + ". For details activate VimbaC logging and check out VmbCameraSettingsLoad.log" );
            msgbox.setIcon( QMessageBox::Warning );
            msgbox.setText( msgtext );
            msgbox.exec();
            return;
        }
        else
        {
            msgbox.setIcon( QMessageBox::Information );
            QString msgtext = tr( "Successfully loaded device settings\nfrom '%1'" ).arg( selectedFile );
            msgbox.setText( msgtext );
            msgbox.exec();
        }
    }
}

void ViewerWindow::on_ActionSaveCameraSettings_triggered(void)
{
    VmbErrorType err = VmbErrorSuccess;

//  create window title
    QString windowTitle = tr( "Save Camera Settings" );

//  create message box
    QMessageBox msgbox;
    msgbox.setWindowTitle( windowTitle );

//  check if camera was opened in 'full access' mode
    if( 0 != m_sAccessMode.compare( tr("(FULL ACCESS)") ) )
    {
        msgbox.setIcon( QMessageBox::Critical );
        msgbox.setText( tr("Camera must be opened in FULL ACCESS mode to use this feature") );
        msgbox.exec();
        return;
    }

//  check if any file dialog was created already
    if( NULL != m_saveFileDialog )
    {
        delete m_saveFileDialog;
        m_saveFileDialog = NULL;
     }

//  setup file dialog
    m_saveFileDialog = new QFileDialog( this, windowTitle, QDir::home().absolutePath(), "*.xml" );
    m_saveFileDialog->setWindowFlags( windowFlags() & ~Qt::WindowContextHelpButtonHint & ~Qt::WindowMinimizeButtonHint & ~Qt::WindowMaximizeButtonHint );
    m_saveFileDialog->selectFilter( "*.xml" );
    m_saveFileDialog->setAcceptMode( QFileDialog::AcceptSave );

//  show dialog
    int rval = m_saveFileDialog->exec();
    if( 0 == rval )
    {
        return;
    }

//  get selected file
    m_SaveFileDir = m_saveFileDialog->directory().absolutePath();
    QStringList selectedFiles = m_saveFileDialog->selectedFiles();
    if( true == selectedFiles.isEmpty() )
    {
        msgbox.setIcon( QMessageBox::Critical );
        msgbox.setText( tr("No file selected") );
        msgbox.exec();
        return;
    }

//  delete file dialog
//  (to prevent OCT-1870 bug occured with Qt v4.7.1)
    delete m_saveFileDialog;
    m_saveFileDialog = NULL;

//  get selected file
    QString selectedFile = selectedFiles.at(0);
    if( false == selectedFile.endsWith( ".xml" ) )
    {
        selectedFile.append( ".xml" );
    }

//  setup behaviour for loading and saving camera features
    m_pCam->LoadSaveSettingsSetup( VmbFeaturePersistNoLUT, 5, 4 );

//  call VimbaCPP save function
    QString msgtext = QString( "" );
    err = m_pCam->SaveCameraSettings( selectedFile.toStdString() );
    if( VmbErrorSuccess != err )
    {
        msgtext = tr( "There have been errors during saving feature values.\n" );
        msgtext.append( tr("[Error code: %1]\n").arg( err ) );
        msgtext.append( tr("[file: %1]").arg( selectedFile) );
        onFeedLogger( "ERROR: SaveCameraSettings returned: " + QString::number(err) + ". For details activate VimbaC logging and check out VmbCameraSettingsSave.log" );
        msgbox.setIcon( QMessageBox::Warning );
        msgbox.setText( msgtext );
        msgbox.exec();
        return;
    }
    else
    {
        msgtext = tr( "Successfully saved device settings to\n'" );
        msgtext.append( selectedFile );
        msgtext.append( "'" );
        msgbox.setIcon( QMessageBox::Information );
        msgbox.setText( msgtext );
        msgbox.exec();
    }
}

void ViewerWindow::on_ActionLoadCameraSettingsMenu_triggered( void )
{
    on_ActionLoadCameraSettings_triggered();
}

void ViewerWindow::on_ActionSaveCameraSettingsMenu_triggered( void )
{
    on_ActionSaveCameraSettings_triggered();
}

void ViewerWindow::onfloatingDockChanged ( bool bIsFloating )
{
    if( (m_DockController->isFloating()  || (false == m_DockController->isVisible())) ||
        (m_DockInformation->isFloating() || (false == m_DockInformation->isVisible())) )
        ActionResetPosition->setEnabled(true);
    else
        ActionResetPosition->setEnabled(false);

    if(m_DockHistogram->isVisible())
        ActionHistogram->setChecked(true);
}

void ViewerWindow::onVisibilityChanged ( bool bIsVisible )
{
    if( m_DockController->isVisible()  && !m_DockController->isFloating() && 
        m_DockInformation->isVisible() && !m_DockInformation->isFloating() )
    {
        ActionResetPosition->setEnabled(false);
    }
    else
    {
        ActionResetPosition->setEnabled(true);
    }

    if(!m_DockHistogram->isVisible())
    {
        if (ActionHistogram->isChecked() )
        {
            ActionHistogram->setChecked(false);
        }
    }
    else
    {
        ActionHistogram->setChecked(true);
    }
}

void ViewerWindow::onResetFPS ( void )
{
    SP_ACCESS( m_pFrameObs )->resetFrameCounter(false);
}

void ViewerWindow::onSetCurrentFPS( const QString &sFPS )
{
    m_FramerateLabel->setText( QString::fromStdString(" Current FPS: ")+ sFPS + " " );
}

void ViewerWindow::onSetFrameCounter( const unsigned int &nNumberOfFrames )
{
    m_FramesLabel->setText( "Frames: " + QString::number(nNumberOfFrames) + " " );
}

void ViewerWindow::onSetEventMessage ( const QStringList &sMsg )
{
    m_InformationWindow->setEventMessage(sMsg);
}

void ViewerWindow::onSetDescription ( const QString &sDesc )
{
    m_Description->setText(sDesc);
}

void ViewerWindow::onSetHistogramData ( const QVector<QVector <quint32> > &histData, const QString &sHistogramTitle, 
                                        const double &nMaxHeight_YAxis, const double &nMaxWidth_XAxis, const QVector <QStringList> &statistics )
{
    if( ActionHistogram->isChecked() )
    {
        QStringList ColorComponentList;
        QStringList MinimumValueList;
        QStringList MaximumValueList;
        QStringList AverageValueList;
        QString sFormat;

        if(sHistogramTitle.contains("Mono8"))
        {
            sFormat = "Mono8";
            ColorComponentList << statistics.at(0).at(0);
            MinimumValueList << statistics.at(0).at(1);
            MaximumValueList << statistics.at(0).at(2);
            AverageValueList << statistics.at(0).at(3);
            m_HistogramWindow->setStatistic(ColorComponentList, MinimumValueList, MaximumValueList, AverageValueList, sFormat);
        }

        if(sHistogramTitle.contains("RGB8") || sHistogramTitle.contains("BGR8") || sHistogramTitle.contains("YUV") || sHistogramTitle.contains("Bayer"))
        {
            if(sHistogramTitle.contains("RGB8") || sHistogramTitle.contains("BGR8"))
                sFormat = "RGB";
            if(sHistogramTitle.contains("Bayer"))
                sFormat = "Bayer";
            if(sHistogramTitle.contains("YUV"))
                sFormat = "YUV";

            ColorComponentList << statistics.at(0).at(0) << statistics.at(1).at(0) << statistics.at(2).at(0);
            MinimumValueList << statistics.at(0).at(1) << statistics.at(1).at(1) << statistics.at(2).at(1);
            MaximumValueList << statistics.at(0).at(2) << statistics.at(1).at(2) << statistics.at(2).at(2);
            AverageValueList << statistics.at(0).at(3) << statistics.at(1).at(3) << statistics.at(2).at(3);
            m_HistogramWindow->setStatistic(ColorComponentList, MinimumValueList, MaximumValueList, AverageValueList, sFormat);
        }

        m_HistogramWindow->updateHistogram(histData, sHistogramTitle, nMaxHeight_YAxis, nMaxWidth_XAxis);
    }
    else
         m_pFrameObs->enableHistogram(false);
}

/* display frames on viewer */
void ViewerWindow::onimageReady ( QImage image, const QString &sFormat, const QString &sHeight, const QString &sWidth )
{    
    m_FormatLabel->setText("Pixel Format: " + sFormat + " ");
    m_ImageSizeLabel->setText("Size H: " + sHeight + " ,W: "+ sWidth + " ");

    if(m_bHasJustStarted)
    {
        foreach( QGraphicsItem *item, m_pScene->items() )
        {
            if( item->type() == QGraphicsTextItem::Type )
            {
                 m_pScene->removeItem(m_TextItem);
                 m_FormatLabel->setStyleSheet("background-color: rgb(195,195,195); color: rgb(0,0,0)");
                 m_bIsRedHighlighted = false;
                 continue;
            }

            m_pScene->removeItem(m_PixmapItem);
        }

        m_pScene->addItem(m_PixmapItem);    
        m_bHasJustStarted = false;
    }

    if( (sFormat.contains("Convert Error")) && ((sFormat.contains("height") || sFormat.contains("width"))) )
    {
        if( false == m_bIsRedHighlighted )
        {
            m_bIsRedHighlighted = true;
            m_FormatLabel->setStyleSheet("background-color: rgb(196,0, 0); color: rgb(255,255,255)");
            
            m_TextItem->setPlainText("The Resolution you set is not supported by VimbaImageTransform.\n"
                                         "Please change height or width !");
            m_TextItem->setPos(m_pScene->width()/6, m_pScene->height()/2);
            m_pScene->addItem(m_TextItem);        
        }
    }
    else
    {
        if( m_bIsRedHighlighted )
        {
            m_FormatLabel->setStyleSheet("background-color: rgb(195,195,195); color: rgb(0,0,0)");
            m_bIsRedHighlighted = false;

            if (!m_pScene->items().isEmpty())
            {
                m_pScene->removeItem(m_TextItem);
            }
        }
    }

    /* display it at centre whenever changed */
    m_pScene->setSceneRect(0, 0, image.width(), image.height() );
    m_PixmapItem->setPixmap(QPixmap::fromImage(image));
    m_ScreenViewer->show();

    /* saving images */
    if( (0 < m_nNumberOfFramesToSave) && m_bIsTriggeredByMultiSaveBtn )
    {
        ++m_nImageCounter;

        if(m_nImageCounter <= m_nNumberOfFramesToSave)
        {
            static bool bCanReduceBpp;
            // Test only once for every batch to save
            if ( 1 == m_nImageCounter )
            {
                bCanReduceBpp = CanReduceBpp();
            }
            // Save with 8 bpp
            if ( true == bCanReduceBpp )
            {
                m_SaveImageThread->m_Images.append( ReduceBpp( image ) );
            }
            // Save as is
            else
            {
                m_SaveImageThread->m_Images.append( image );
            }
            // Reset at end of batch
            if ( m_nImageCounter == m_nNumberOfFramesToSave )
            {
                bCanReduceBpp = false;
            }
        }

        m_SaveImageThread->m_sImagePath = m_ImagePath;
        m_SaveImageThread->m_sSaveFormat = m_SaveFormat;
        m_SaveImageThread->m_sSaveName = m_SaveName;
        m_SaveImageThread->m_nTImageCounter = m_nImageCounter ;
        m_SaveImageThread->m_nTNumber2Save = m_nNumberOfFramesToSave;

        if(IMAGES_COUNT == m_nImageCounter)
            m_SaveImageThread->start();
        
        if( m_nImageCounter == m_nNumberOfFramesToSave)
        {
            if(!m_SaveImageThread->isRunning() && (!m_SaveImageThread->m_Images.isEmpty()))
               m_SaveImageThread->start();

            return;
        }
    }
}

void SaveImageThread::run ( void )
{
   while(m_nImagePosition != m_nTNumber2Save)
   {
        while (!m_Images.isEmpty())
        {       
            emit setPosition (++m_nImagePosition);
            QString sFullPath = m_sImagePath;
            sFullPath.append("//").append(m_sSaveName);
            sFullPath.append("_"+QString::number(m_nImagePosition)).append(m_sSaveFormat);
            m_Images.first().save(sFullPath);
            m_Images.pop_front();
        }   
   }
 
   exec();
}

void ViewerWindow::onSaving ( unsigned int nPos )
{ 
    if( 1 == nPos )
    {
        //Start Progressbar
        m_SaveImagesDialog = new QDialog(0, Qt::CustomizeWindowHint|Qt::WindowTitleHint);
        m_SaveImagesUIDialog.setupUi(m_SaveImagesDialog);
        m_SaveImagesUIDialog.saveImagesProgress->setMaximum(m_nNumberOfFramesToSave);
        m_SaveImagesUIDialog.saveImagesProgress->setMinimum(1);
        m_SaveImagesDialog->show();
    }

    m_SaveImagesUIDialog.saveImagesProgress->setValue(nPos);

    if (m_nNumberOfFramesToSave == nPos)
    {
        m_FormatLabel->setStyleSheet("background-color: rgb(195,195,195); color: rgb(0,0,0)");
        m_bIsRedHighlighted = false;

        ActionFreerun->setChecked(false);
        on_ActionFreerun_triggered();
        ActionFreerun->setEnabled(isStreamingAvailable());
        
        foreach( QGraphicsItem *item, m_pScene->items() )
        {
            if( item->type() == QGraphicsTextItem::Type )
            {
                m_pScene->removeItem(m_TextItem);
                break;
            }
        }

        m_SaveImagesDialog->hide();
        delete m_SaveImagesDialog;
        m_SaveImagesDialog = NULL;
        m_SaveImageThread->quit();
        m_nImageCounter = 0;
        m_SaveImageThread->m_nImagePosition = 0;
        m_bIsTriggeredByMultiSaveBtn = false;
    }

    QCoreApplication::processEvents();
}

void ViewerWindow::onAcquisitionStartStop ( const QString &sThisFeature )
{
    QIcon icon;

    /* this is intended to stop and start the camera again since PixelFormat, Height and Width have been changed while camera running
    *  ignore this when the changing has been made while camera not running 
    */
    if( ((0 == sThisFeature.compare("AcquisitionStart")) && (m_bIsCameraRunning)) )
    {
        ActionFreerun->setChecked(true);
        on_ActionFreerun_triggered();
    }
    else if( sThisFeature.contains("AcquisitionStartFreerun") )
    {
        SP_ACCESS( m_pFrameObs )->resetFrameCounter(true);
        if(!m_bIsCameraRunning)
        {
            icon.addFile(QString::fromUtf8(":/VimbaViewer/Images/stop.png"), QSize(), QIcon::Normal, QIcon::On);
            ActionFreerun->setIcon(icon);
            checkDisplayInterval();
            releaseBuffer();
            onPrepareCapture();        
         
            ActionFreerun->setChecked(true);
            m_bIsCameraRunning = true;
            m_bHasJustStarted = true;

            if(ActionDisplayOptions->isEnabled())
                ActionDisplayOptions->setEnabled(false);

            if(ActionSaveOptions->isEnabled())
                ActionSaveOptions->setEnabled(false);

            /* if save images settings set, and acquisition starts */
            if( (0 < m_SaveImageOption.NumberOfFrames_SpinBox->value()) && ActionSaveImages->isEnabled() )
            {
                ActionSaveImages->setEnabled(false);
                m_nImageCounter = 0;
                m_nNumberOfFramesToSave = 0;
            }

            m_OperatingStatusLabel->setText( " Running... " );
            m_OperatingStatusLabel->setStyleSheet("background-color: rgb(0,128, 0); color: rgb(255,255,255)");
        }
    }
    else if( sThisFeature.contains("AcquisitionStopFreerun") )
    {
        if(m_bIsCameraRunning)
        {
            icon.addFile(QString::fromUtf8(":/VimbaViewer/Images/play.png"), QSize(), QIcon::Normal, QIcon::Off);
            ActionFreerun->setIcon(icon);
            releaseBuffer();
            ActionFreerun->setChecked(false);
            if (m_bIsViewerWindowClosing)
                on_ActionFreerun_triggered();

            m_bIsCameraRunning = false;

            if(!ActionSaveOptions->isEnabled())
                ActionSaveOptions->setEnabled(true);

            if(!ActionFreerun->isEnabled())
                ActionFreerun->setEnabled(isStreamingAvailable());

            if(!ActionDisplayOptions->isEnabled())
                ActionDisplayOptions->setEnabled(true);

            /* if save images running, and acquisition stops */
            if( (0 < m_SaveImageOption.NumberOfFrames_SpinBox->value()) && !ActionSaveImages->isEnabled() )
            {
                ActionSaveImages->setEnabled(true);
            }

            m_Controller->synchronizeEventFeatures();
        }

        m_OperatingStatusLabel->setText( " Ready " );
        m_OperatingStatusLabel->setStyleSheet("background-color: rgb(0,0, 0); color: rgb(255,255,255)"); 
    }
    else if( ((0 == sThisFeature.compare("AcquisitionStop")) && (m_bIsCameraRunning)) ||
              (sThisFeature.contains("AcquisitionStopWidthHeight")))
    {
        if(m_bIsCameraRunning)
        {
            ActionFreerun->setChecked(false);
            on_ActionFreerun_triggered();
        
            /* use this for GigE, so you can change the W/H "on the fly" */
            if(0 == sThisFeature.compare("AcquisitionStopWidthHeight"))
                m_bIsCameraRunning = true;
        }
    }
}

void ViewerWindow::checkDisplayInterval( void )
{
    FeaturePtr pFeatMode;

    if(VmbErrorSuccess == m_pCam->GetFeatureByName( "AcquisitionMode", pFeatMode ))
    {
        std::string sValue("");
        if( VmbErrorSuccess == pFeatMode->GetValue(sValue) )
        {
            /* display all received frames for SingleFrame and MultiFrame mode or if the user wants to have it */
            if( 0 == sValue.compare("SingleFrame") || 0 == sValue.compare("MultiFrame") || m_bIsDisplayEveryFrame )
                SP_ACCESS( m_pFrameObs )->setDisplayInterval( 0 ); 
            /* display frame in a certain interval to save CPU consumption for continuous mode */
            else
                SP_ACCESS( m_pFrameObs )->setDisplayInterval( 1 ); 
        }
    }
}

void ViewerWindow::on_ActionFreerun_triggered( void )
{
    VmbError_t error;
    FeaturePtr pFeat;
    
    checkDisplayInterval();

     /* update interpolation state after start */
    if( !m_Timer->isActive())
    {
        m_Timer->start(200);
    }

    QIcon icon;
    /* ON */
    if( ActionFreerun->isChecked() )
    {
        icon.addFile(QString::fromUtf8(":/VimbaViewer/Images/stop.png"), QSize(), QIcon::Normal, QIcon::On);
        ActionFreerun->setIcon(icon);
    
        error = onPrepareCapture();
        if( VmbErrorSuccess != error )
        {
            m_bIsCameraRunning = false;
            m_OperatingStatusLabel->setText( " Failed to start! Error: " + QString::number(error)+" "+m_Helper.mapReturnCodeToString(error) );
            m_OperatingStatusLabel->setStyleSheet("background-color: rgb(196,0, 0); color: rgb(255,255,255)"); 
            icon.addFile(QString::fromUtf8(":/VimbaViewer/Images/play.png"), QSize(), QIcon::Normal, QIcon::Off);
            ActionFreerun->setIcon(icon);
            ActionFreerun->setChecked(false);
            return;
        }

        error = m_pCam->GetFeatureByName( "AcquisitionStart", pFeat );
        int nResult = m_sAccessMode.compare(tr("(READ ONLY)")) ;
        if ( (VmbErrorSuccess == error) && ( 0 != nResult ) ) 
        {
            SP_ACCESS( m_pFrameObs )->resetFrameCounter(true);

            // Do some GUI-related preparations before really starting (to avoid timing problems)
            m_OperatingStatusLabel->setText( " Running... " );
            m_OperatingStatusLabel->setStyleSheet("background-color: rgb(0,128, 0); color: rgb(255,255,255)");

            if(ActionDisplayOptions->isEnabled())
                ActionDisplayOptions->setEnabled(false);

            if(ActionSaveOptions->isEnabled())
                ActionSaveOptions->setEnabled(false);

            if( ActionSaveImages->isEnabled() && (0 < m_SaveImageOption.NumberOfFrames_SpinBox->value()) )
                ActionSaveImages->setEnabled(false);

            error = pFeat->RunCommand();
 
            if(VmbErrorSuccess == error)
            {
                if(m_bIsFirstStart)
                {  
                    m_bIsFirstStart = false;
                }

                m_bHasJustStarted = true;
                m_bIsCameraRunning = true;
            }
            else
            {
                m_bIsCameraRunning = false;
                m_OperatingStatusLabel->setText( " Failed to execute AcquisitionStart! Error: " + QString::number(error)+" "+m_Helper.mapReturnCodeToString(error) );
                m_OperatingStatusLabel->setStyleSheet("background-color: rgb(196,0, 0); color: rgb(255,255,255)"); 

                m_InformationWindow->feedLogger("Logging", QString(QTime::currentTime().toString("hh:mm:ss:zzz")+"\t" + 
                                                " RunCommand [AcquisitionStart] Failed! Error: " + QString::number(error)+" "+
                                                m_Helper.mapReturnCodeToString(error)), VimbaViewerLogCategory_ERROR);

                if(ActionDisplayOptions->isEnabled())
                    ActionDisplayOptions->setEnabled(true);

                if(ActionSaveOptions->isEnabled())
                    ActionSaveOptions->setEnabled(true);

                if( ActionSaveImages->isEnabled() && (0 < m_SaveImageOption.NumberOfFrames_SpinBox->value()) )
                    ActionSaveImages->setEnabled(true);

            }
        }
    }
    /* OFF */
    else
    {
        error = m_pCam->GetFeatureByName("AcquisitionStop", pFeat);
        if ( (VmbErrorSuccess == error) )
        {
            if(0 != m_sAccessMode.compare(tr("(READ ONLY)")))
                error = pFeat->RunCommand();
            
            icon.addFile(QString::fromUtf8(":/VimbaViewer/Images/play.png"), QSize(), QIcon::Normal, QIcon::Off);
            ActionFreerun->setIcon(icon);

            if(VmbErrorSuccess == error)
            {  
                m_bIsCameraRunning = false;
                m_OperatingStatusLabel->setText( " Ready " );
                m_OperatingStatusLabel->setStyleSheet("background-color: rgb(0,0, 0); color: rgb(255,255,255)");

                releaseBuffer();
            }
            else
            {
                m_InformationWindow->feedLogger("Logging", QString(QTime::currentTime().toString("hh:mm:ss:zzz")+"\t" + 
                                                " RunCommand [AcquisitionStop] Failed! Error: " + QString::number(error) + " " +
                                                m_Helper.mapReturnCodeToString(error) ), VimbaViewerLogCategory_ERROR);
            }
        }


        if(!ActionDisplayOptions->isEnabled())
            ActionDisplayOptions->setEnabled(true);

        if(!ActionSaveOptions->isEnabled())
            ActionSaveOptions->setEnabled(true);

        if( !ActionSaveImages->isEnabled() && (0 < m_SaveImageOption.NumberOfFrames_SpinBox->value()))
            ActionSaveImages->setEnabled(true);

        m_Controller->synchronizeEventFeatures();
    }
}

VmbError_t ViewerWindow::releaseBuffer ( void )
{
    m_pFrameObs->Stopping();
    VmbError_t error = m_pCam->EndCapture();
    if( VmbErrorSuccess == error )
        error = m_pCam->FlushQueue();
    if( VmbErrorSuccess == error ) 
        error = m_pCam->RevokeAllFrames();
 
    return error;
}

VmbError_t ViewerWindow::onPrepareCapture ( void )
{
    FeaturePtr pFeature;
    VmbInt64_t nPayload = 0;
    QVector <FramePtr> frames;
    VmbError_t error = m_pCam->GetFeatureByName("PayloadSize", pFeature);
    VmbUint32_t nCounter = 0;
    if( VmbErrorSuccess == error )
    {
        error = pFeature->GetValue(nPayload);
        if(VmbErrorSuccess == error)
        {
            frames.resize(m_FrameBufferCount);
        
            bool bIsStreamingAvailable = isStreamingAvailable();

            if (bIsStreamingAvailable)
            {
                for (int i=0; i<frames.size(); i++)
                {
                    try
                    {
                        frames[i] = FramePtr(new Frame(nPayload));
                        nCounter++;
                    }
                    catch(std::bad_alloc& )
                    {
                         frames.resize((VmbInt64_t) (nCounter * 0.7));
                         break;
                    }
                    m_pFrameObs->Starting();
                    error = frames[i]->RegisterObserver(m_pFrameObs);
                    if( VmbErrorSuccess != error )
                    {
                        m_InformationWindow->feedLogger("Logging", 
                                                        QString(QTime::currentTime().toString("hh:mm:ss:zzz")+"\t" + " RegisterObserver frame["+ QString::number(i)+ "] Failed! Error: " + QString::number(error)+" "+ m_Helper.mapReturnCodeToString(error)), 
                                                        VimbaViewerLogCategory_ERROR);
                        return error;
                    }
                }

                for (int i=0; i<frames.size(); i++)
                {
                    error = m_pCam->AnnounceFrame( frames[i] );
                    if( VmbErrorSuccess != error )
                    {
                        m_InformationWindow->feedLogger("Logging", 
                                                        QString(QTime::currentTime().toString("hh:mm:ss:zzz")+"\t" + " AnnounceFrame ["+ QString::number(i)+ "] Failed! Error: " + QString::number(error)+" "+ m_Helper.mapReturnCodeToString(error)), 
                                                        VimbaViewerLogCategory_ERROR);
                        return error;
                    }
                }
            }

            if(VmbErrorSuccess == error)
            {
                error = m_pCam->StartCapture();
                if( VmbErrorSuccess != error )
                {
                    QString sMessage = " StartCapture Failed! Error: ";
                    
                    if(0 != m_sAccessMode.compare(tr("(READ ONLY)")))
                        m_InformationWindow->feedLogger("Logging", 
                                                         QString(QTime::currentTime().toString("hh:mm:ss:zzz")+"\t" + sMessage + QString::number(error)+" "+ m_Helper.mapReturnCodeToString(error)), 
                                                         VimbaViewerLogCategory_ERROR);
                    return error;
                }
            }

            if (bIsStreamingAvailable)
            {
                for (int i=0; i<frames.size(); i++)
                {
                    error = m_pCam->QueueFrame( frames[i] );
                    if( VmbErrorSuccess != error )
                    {
                        m_InformationWindow->feedLogger("Logging", 
                                                        QString(QTime::currentTime().toString("hh:mm:ss:zzz")+"\t" + " QueueFrame ["+ QString::number(i)+ "] Failed! Error: " + QString::number(error)+" "+ m_Helper.mapReturnCodeToString(error)), 
                                                        VimbaViewerLogCategory_ERROR);
                        return error;
                    }
                }
            }
        }
        else
        {
            m_InformationWindow->feedLogger("Logging", 
                                            QString(QTime::currentTime().toString("hh:mm:ss:zzz")+"\t" + " GetValue [PayloadSize] Failed! Error: " + QString::number(error)+" "+ m_Helper.mapReturnCodeToString(error)), 
                                            VimbaViewerLogCategory_ERROR);
            return error;
        }
    }
    else
    {
        m_InformationWindow->feedLogger("Logging", 
                                        QString(QTime::currentTime().toString("hh:mm:ss:zzz")+"\t" + " GetFeatureByName [PayloadSize] Failed! Error: " + QString::number(error)+" "+ m_Helper.mapReturnCodeToString(error)), 
                                        VimbaViewerLogCategory_ERROR);
        return error;
    }

    return error;
}

void ViewerWindow::onFeedLogger    ( const QString &sMessage )
{
    m_InformationWindow->feedLogger("Logging", QString(QTime::currentTime().toString("hh:mm:ss:zzz")+"\t" + sMessage), VimbaViewerLogCategory_ERROR);
}

void ViewerWindow::changeEvent ( QEvent * event )
{
    if( event->type() == QEvent::WindowStateChange )
    {
        if( isMinimized() )
            m_Controller->showControl(false);
        else if( isMaximized() )
            m_Controller->showControl(true);
    }
}

bool ViewerWindow::loadPlugin()
{
    QDir pluginsDir(qApp->applicationDirPath() + "//plugins");

    m_TabPluginCount = 0; 
 
    foreach (QString fileName, pluginsDir.entryList(QDir::Files)) 
    {
        QPluginLoader pluginLoader(pluginsDir.absoluteFilePath(fileName));
        QObject *plugin = pluginLoader.instance();
        if (plugin) 
        {
            TabExtensionInterface *tabInterface = qobject_cast<TabExtensionInterface *>(plugin);
            m_tabExtensionInterface.push_back(tabInterface); 
            if (m_tabExtensionInterface[m_TabPluginCount])
                m_TabPluginCount++;
        }
    }

    return m_TabPluginCount > 0;
}

bool ViewerWindow::CanReduceBpp( void )
{
    bool res = false;

    FeaturePtr pFeature;
    // TODO: Persist pixel format in viewer. Pixel format might be altered in between capture and save. Then color would be transformed to mono.
    // Bug or feature?
    VmbError_t error = m_pCam->GetFeatureByName( "PixelFormat", pFeature );
    if( VmbErrorSuccess == error )
    {
        VmbInt64_t nFormat;
        error = pFeature->GetValue( nFormat );
        if( VmbErrorSuccess == error )
        {
            res = VmbPixelFormatMono8 == nFormat;
        }
    }

    return res;
}

// Reduces bpp to 8
QImage ViewerWindow::ReduceBpp( QImage image )
{
    // Create 8 bit grey scale color table
    if ( 0 == m_ColorTable.size() )
    {
        for ( int i = 0; i < 256; ++i )
        {
            m_ColorTable.push_back( QColor( i, i, i ).rgb() );
        }
    }
    // Convert to 8 bit grey scale
    return image.convertToFormat( QImage::Format_Indexed8, m_ColorTable );
}

// Check if the TL supports streaming
bool ViewerWindow::isStreamingAvailable(void)
{
    AVT::VmbAPI::FeaturePtr pStreamIDFeature;
    m_pCam->GetFeatureByName("StreamID", pStreamIDFeature);
    return (NULL == pStreamIDFeature) ? false : true;
}
