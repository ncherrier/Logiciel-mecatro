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
#include <QWizard>
#include <QWizardPage>
// For videos
#include <QtMultimedia>
#include <QtMultimediaWidgets>
#include <QVideoWidget>

using namespace std;


// Algorithm to take a global picture
// will be called by the User Interface
// take subpictures and communcate with Electronics to move the Industrial Camera
// returns true if the process was executed normally
bool startCycle() {

	cout << "call startCycle()" << endl;
	// TODO: change return so that one can know whether everything went good or not (or use exceptions ?)

	return true;
}

//*****************For tests only*****************
//cout << "hello! in MainProg::MainFunction" << endl;

//TakePictureTest *tak = new TakePictureTest();
//tak->show();
//************************************************


// First window showed: FramingWindow
//FramingWindow *fra = new FramingWindow();
//fra->show();
//cout << "FramingWindow shown" << endl;

//Permet de détecter la caméra // TODO: ameliorer...
QCameraInfo const getWebcamInfo(){
	QList<QCameraInfo> cameras = QCameraInfo::availableCameras();
	QCameraInfo const firstCam = cameras[0];
	return firstCam;
}

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
	page->setTitle("Cadrage");
	QLabel *label = new QLabel("Vérifiez que le cadrage vous convient, puis passez à l'étape suivante.");
	label->setWordWrap(true);

	// Webcam
	/*QCamera camera(getWebcamInfo());
	QWidget * videoContainer = new QWidget(page);
	QVideoWidget * videoWidget = new QVideoWidget(videoContainer);
	videoWidget->resize(200,120);
	camera.setViewfinder(videoWidget);
	camera.start();*/
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
	page->setTitle("Mise au point et réglages");
	return page;
}

QWizardPage *createInProcessPage()
{
	QWizardPage *page = new QWizardPage;
	page->setTitle("In process...");
	return page;
}

int main(int argc, char *argv[])
{
	cout << "hello! in main" << endl;
	QApplication *app = new QApplication(argc, argv);

	//*****************QWizard creation****************

	QWizard wizard;

	//Page 0: Intro
	//Page 1: Framing
	//Contains video from webcam
	//Page 2: "Settings": focus, exposure time
	//Contains videos from webcam and industrial camera
	//Page 3: In process
	//Enables user to stop the process

	wizard.addPage(createIntroPage());



	QWizardPage * framingPage = createFramingPage();
	// Add video
	QCamera webcam(getWebcamInfo());
	QWidget * videoContainer = new QWidget();
	QVideoWidget * videoWidget = new QVideoWidget(videoContainer);
	videoWidget->resize(200, 120);

	webcam.setViewfinder(videoWidget);
	webcam.start();

	// Label
	//QLabel *label = new QLabel("Vérifiez que le cadrage vous convient, puis passez à l'étape suivante.");
	//label->setWordWrap(true);

	// Layout
	//QGridLayout *framingPageLayout = new QGridLayout;
	//framingPageLayout->addWidget(label);
	//framingPageLayout->addWidget(videoContainer);
	//framingPage->setLayout(framingPageLayout);
	framingPage->layout()->addWidget(videoContainer);

	wizard.addPage(framingPage);




	wizard.addPage(createSettingsPage());
	wizard.addPage(createInProcessPage());

	wizard.setWindowTitle("GigaProxyPhoto");
	wizard.show();

	return app->exec();
}



