#include "GPPWizard.h"

#include <QtMultimedia>
#include <QtMultimediaWidgets>
#include <QVideoWidget>

#include <iostream> // for tests


//Permet de detecter la camera // TODO: ameliorer...
QCameraInfo const getWebcamInfo(){
    QList<QCameraInfo> cameras = QCameraInfo::availableCameras();
    QCameraInfo const firstcam = cameras[0];
    return firstcam;
}

// Wizard creation

// Introduction page
QWizardPage * GPPWizard::createIntroPage()
{
    QWizardPage *page = new QWizardPage;
    page->setTitle("Bienvenue");

    return page;
}



QWizardPage * GPPWizard::createFramingPage()
{
    // Basics
    QWizardPage *page = new QWizardPage;
    page->setTitle("Cadrage");
    QLabel *label = new QLabel("Verifiez que le cadrage vous convient, puis passez a l'etape suivante.");
    label->setWordWrap(true);



    //cout << "Camera started" << endl;

    // Test
    //QPushButton * testButton = new QPushButton("Test");

    // Buttons


    // Layout
    QGridLayout *layout = new QGridLayout;
    layout->addWidget(label, 1, 1);
    //layout->addWidget(videoContainer, 2, 1);
    //layout->addWidget(testButton, 3, 1);

    page->setLayout(layout);

    //videoContainer->show();
    //videoWidget->show();

    return page;
}

QWizardPage * GPPWizard::createSettingsPage()
{
    QWizardPage * page = new SettingsPage();
    return page;
}

ProgressPage * GPPWizard::createProgressPage()
{
    ProgressPage *page = new ProgressPage();
    return page;
}

GPPWizard::GPPWizard() : QWizard()
{
    introPage = createIntroPage();
    framingPage = createFramingPage();
    settingsPage = createSettingsPage();
    progressPage = createProgressPage();
	Log("Pages creees");
    focuswindow = new FocusWindow();
	serialcomm = new SerialCommunication();
	Log("Objets focus et serial crees");
    connect(serialcomm, SIGNAL(MvtFinished()), focuswindow, SLOT(SaveImage())); // TODO: uncomment !!!
    connect(focuswindow, SIGNAL(PictureTaken()), serialcomm, SLOT(moveCameraToNextPosition())); // TODO: uncomment !!!
    connect(focuswindow, SIGNAL(PictureTaken()), progressPage, SLOT(incNbPicturesTaken()));
    connect(progressPage->getStopButton(), SIGNAL(clicked()), serialcomm, SLOT(emergencyStop()));
	Log("Connexions faites");
    addPage(introPage);


    // Framing page

    // Add video
    //QCamera webcam(getWebcamInfo());
    //QWidget * videoContainer = new QWidget();
    //QVideoWidget * videoWidget = new QVideoWidget(videoContainer);
    //videoWidget->resize(200, 120);

    //webcam.setViewfinder(videoWidget);
    //webcam.start();

    //framingPage->layout()->addWidget(videoContainer);

    addPage(framingPage);
    // End framing page

    addPage(createSettingsPage());
    addPage(createProgressPage());

    setWindowTitle("GigaProxyPhoto");
    setFixedSize(700, 600);
	Log("Pages ajoutees");
    // Webcam
	/*
    QList<QCameraInfo> cameras = QCameraInfo::availableCameras();
    QCameraInfo const firstCam = cameras[0];
    //QCameraInfo const secondCam = cameras[1];
    QCamera camera(firstCam);

    // create new window
    //QWidget * windowWithVideo = new QWidget();

    //QWidget * videoContainer = new QWidget(windowWithVideo);
    //QVideoWidget * videoWidget = new QVideoWidget(videoContainer);
    //videoWidget->resize(200,120);
    //camera.setViewfinder(videoWidget);

    //windowWithVideo->resize(400,400);
    //camera.start();
    //windowWithVideo->show();
	*/
    show();

}

// End of wizard creation

void GPPWizard::Log(std::string strMsg)
{
	QString filename = "Data.txt";
	QFile file(filename);
	if (file.open(QIODevice::ReadWrite | QIODevice::Append))
	{
		QTextStream stream(&file);
		stream << QString::fromUtf8(strMsg.c_str()) << endl;
	}
}