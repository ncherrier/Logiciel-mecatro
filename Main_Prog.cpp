#include <QApplication>
#include <QPushButton>
#include <iostream> // for tests
#include <QtWidgets/QApplication>
#include "cameraSettingsWindow.h"
#include "SettingsWindow.h"
#include "FramingWindow.h"
#include "ProcessWindow.h"
#include "SerialCommunication.h"
#include "TakePictureTest.h" // for tests only
//#include <QWizard>
//#include <QWizardPage>
// For videos
#include <QtMultimedia>
#include <QtMultimediaWidgets>
#include <QVideoWidget>
#include "GPPWizard.h"


using namespace std;


// Algorithm to take a global picture
// will be called by the User Interface
// take subpictures and communicate with Electronics to move the Industrial camera
// returns true if the process was executed normally
//bool startCycle() {
//
//    cout << "call startCycle()" << endl;
	// TODO: change return so that one can know whether everything went good or not (or use exceptions ?)
//
//	return true;
//}

//*****************For tests only*****************
//cout << "hello! in MainProg::MainFunction" << endl;


//************************************************


// First window showed: FramingWindow
//FramingWindow *fra = new FramingWindow();
//fra->show();
//cout << "FramingWindow shown" << endl;

//Permet de detecter la camera // TODO: ameliorer...
QCameraInfo const getWebcamInfo(){
    QList<QCameraInfo> cameras = QCameraInfo::availableCameras();
    QCameraInfo const firstcam = cameras[0];
	return firstcam;
}

/*
QWizardPage *createIntroPage()
{
	QWizardPage *page = new QWizardPage;
	page->setTitle("Bienvenue");

	return page;
}

QWizardPage *createFramingPage()
{
	// Basics
	QWizardPage *page = new QWizardPage;
	page->setTitle("cadrage");
    QLabel *label = new QLabel("Verifiez que le cadrage vous convient, puis passez a l'etape suivante.");
	label->setWordWrap(true);

	// Webcam
    //QCamera camera(getWebcamInfo());
    //QWidget * videoContainer = new QWidget(page);
    //QVideoWidget * videoWidget = new QVideoWidget(videoContainer);
    //videoWidget->resize(200,120);
    //camera.setViewfinder(videoWidget);
    //camera.start();
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

QWizardPage *createSettingsPage()
{
	QWizardPage *page = new QWizardPage;
	page->setTitle("Mise au point et reglages");
	return page;
}

QWizardPage *createInProcessPage()
{
	QWizardPage *page = new QWizardPage;
	page->setTitle("In process...");
	return page;
}
*/
int main(int argc, char *argv[])
{
	cout << "hello! in main" << endl;
	QApplication *app = new QApplication(argc, argv);

    GPPWizard * GPP = new GPPWizard();
    GPP->show();

    //TakePictureTest *tak = new TakePictureTest();
    //tak->show();


    //TEST !!!!
    //Permet de détecter la caméra
    QList<QCameraInfo> cameras = QCameraInfo::availableCameras();
    QCameraInfo const firstCam = cameras[0];
    //QCameraInfo const secondCam = cameras[1];
    QCamera camera(firstCam);
    //

    QWidget w;

    //QWidget videoContainer(&w);
    //w.setCentralWidget(&videoContainer);
    QWidget videoContainer;

    // création d'un QVideoWidget avec videoContainer comme parent
    QVideoWidget videoWidget(&videoContainer);

    videoWidget.resize(600, 360); //Taille de la vidéo

    camera.setViewfinder(&videoWidget); //Intègre la vidéo au videoWidget
    camera.start();

    QGridLayout *layout = new QGridLayout;
    layout->addWidget(&videoContainer);
    w.setLayout(layout);

    w.resize(600, 360); //Taille de la fenêtre
    //w.show();


    w.show();

    //FIN TEST
	return app->exec();
}



