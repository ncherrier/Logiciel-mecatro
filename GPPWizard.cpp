#include "GPPWizard.h"
//#include <QPushButton>
#include <QtMultimedia>
#include <QtMultimediaWidgets>
#include <QVideoWidget>
#include "cameraSettingsWindow.h"
#include <iostream> // for tests
//#include <Main_Prog.cpp>

// Slots
/*
void GPPWizard::openCameraSettings() {
    std::cout << "TODO: open cameraSettingsWindow" << std::endl;
    CameraSettingsWindow *cam = new CameraSettingsWindow(this);
    cam->exec();
}

// give instructions to move camera
bool GPPWizard::goUp() {
    return SerialCommunication::goUp();
}

bool GPPWizard::goDown() {
    return SerialCommunication::goDown();
}

bool GPPWizard::goLeft() {
    return SerialCommunication::goLeft();
}

bool GPPWizard::goRight() {
    return SerialCommunication::goRight();
}

QWizardPage * GPPWizard::createIntroPage()
{
    QWizardPage *page = new QWizardPage;
    page->setTitle("Bienvenue");

    return page;
}

//Permet de detecter la camera // TODO: ameliorer...
QCameraInfo const getWebcamInfo(){
	QList<QCameraInfo> cameras = QCameraInfo::availableCameras();
	QCameraInfo const firstcam = cameras[0];
	return firstcam;
}

QWizardPage * GPPWizard::createFramingPage()
{
    // Basics
    QWizardPage *page = new QWizardPage;
    page->setTitle("cadrage");
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
    QWizardPage * page = new QWizardPage;
    page->setTitle("Mise au point et reglages");

    QPushButton * upButton = new QPushButton("^");
    QPushButton * leftButton = new QPushButton("<");
    QPushButton * downButton = new QPushButton("v");
    QPushButton * rightButton = new QPushButton(">");

    QPushButton * cameraSettingsButton = new QPushButton("Indus. camera settings");

    QGridLayout * layout = new QGridLayout(page);



    // connect signals and slots
    QObject::connect(upButton, SIGNAL(clicked()), this, SLOT(goUp()));
    QObject::connect(downButton, SIGNAL(clicked()), this, SLOT(goDown()));
    QObject::connect(leftButton, SIGNAL(clicked()), this, SLOT(goLeft()));
    QObject::connect(rightButton, SIGNAL(clicked()), this, SLOT(goRight()));
    QObject::connect(cameraSettingsButton, SIGNAL(clicked()), this, SLOT(openCameraSettings()));

    layout->addWidget(upButton);
    layout->addWidget(leftButton);
    layout->addWidget(downButton);
    layout->addWidget(rightButton);
    layout->addWidget(cameraSettingsButton);

    page->setLayout(layout);

    return page;
}

QWizardPage * GPPWizard::createInProcessPage()
{
    QWizardPage *page = new QWizardPage;
    page->setTitle("In process...");
    return page;
}

GPPWizard::GPPWizard() : QWizard()
{
    addPage(createIntroPage());

    // Framing page
    QWizardPage * framingPage = createFramingPage();

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
    addPage(createInProcessPage());

    setWindowTitle("GigaProxyPhoto");
    show();

    // Webcam

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



}

*/
