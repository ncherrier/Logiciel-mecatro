#include "GPPWizard.h"
//#include <QPushButton>
#include <QtMultimedia>
#include <QtMultimediaWidgets>
#include <QVideoWidget>
#include "cameraSettingsWindow.h"
#include <iostream> // for tests
//#include <Main_Prog.cpp>

int GPPWizard::getWishedXPos(){
    return -1; //TODO
}

int GPPWizard::getWishedYPos(){
    return -1; //TODO
}

// Slots

void GPPWizard::openCameraSettings() {
    std::cout << "TODO: open cameraSettingsWindow" << std::endl;
    //CameraSettingsWindow *cam = new CameraSettingsWindow(this);
    //cam->exec();
    // TODO: uncomment - & solve bug
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

QWizardPage * GPPWizard::createInProcessPage()
{
    QWizardPage *page = new QWizardPage;
    page->setTitle("In process...");
    return page;
}

GPPWizard::GPPWizard() : QWizard()
{
    introPage = createIntroPage();
    framingPage = createFramingPage();
    settingsPage = createSettingsPage();
    inProcessPage = createInProcessPage();

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
    addPage(createInProcessPage());

    setWindowTitle("GigaProxyPhoto");
    setFixedSize(700, 600);

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

    show();

}


