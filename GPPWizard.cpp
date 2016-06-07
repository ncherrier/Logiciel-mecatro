#include "GPPWizard.h"

#include <QtMultimedia>
#include <QtMultimediaWidgets>
#include <QVideoWidget>

#include <iostream> // for tests

int GPPWizard::getWishedXPos(){
	return XPosBox->value();
}

int GPPWizard::getWishedYPos(){
	return YPosBox->value();
}

// to debug
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

// SLOTS

void GPPWizard::moveCamera(){
	// "internal memory" of this page
	realXPos = getWishedXPos();
	realYPos = getWishedYPos();
	// actual movement: communicate with Arduino
	//SerialCommunication::goTo(realXPos, realYPos);
	std::cout << "TODO!" << std::endl;
}

void GPPWizard::restoreToActualValues() {
	XPosBox->setValue(realXPos);
	YPosBox->setValue(realYPos);
}

void GPPWizard::incNbPicturesTaken() {
	bar->setValue(bar->value() + 1);
	Log("in ProgressPage : nbPicturesTaken += 1");
}

//Permet de detecter la camera // TODO: ameliorer...
QCameraInfo const getWebcamInfo(){
    QList<QCameraInfo> cameras = QCameraInfo::availableCameras();
    QCameraInfo const firstcam = cameras[0];
    return firstcam;
}

// Wizard creation
/*
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
*/
GPPWizard::GPPWizard() 
{
    /*introPage = createIntroPage();
    framingPage = createFramingPage();
    settingsPage = createSettingsPage();
    progressPage = createProgressPage();
	Log("Pages creees");*/
    focuswindow = new FocusWindow();
	serialcomm = new SerialCommunication();
	Log("Objets focus et serial crees");

	// Settings

	// Camera position settings (manual)
	XPosBox = new QSpinBox();
	XPosBox->setMinimum(0); // TODO: check values with elec
	XPosBox->setMaximum(100);
	XPosBox->setSingleStep(1);
	XPosBox->setAccelerated(true);
	XPosBox->setSuffix("%");

	YPosBox = new QSpinBox();
	YPosBox->setMinimum(0); // TODO: check values with elec
	YPosBox->setMaximum(100);
	YPosBox->setSingleStep(1);
	YPosBox->setAccelerated(true);
	YPosBox->setSuffix("%");

	moveButton = new QPushButton("Move camera");
	realButton = new QPushButton("Show actual values");

	//cameraSettingsButton = new QPushButton("Indus. camera settings");

	// Progress
	goButton = new QPushButton("Go!");
	stopButton = new QPushButton("Arret d'urgence");
	photoButton = new QPushButton("Prendre une photo");

	// bar de progression
	bar = new QProgressBar();
	bar->setMinimum(0);
	bar->setMaximum(225); //TODO: bonne valeur ???
	bar->setValue(0);

	// Prendre des photos qd le mvt est termine
    connect(serialcomm, SIGNAL(MvtFinished()), focuswindow, SLOT(SaveImage()));
	// Demander a l'elec de bouger la camera qd la photo est prise
    //connect(focuswindow, SIGNAL(PictureTaken()), serialcomm, SLOT(moveCameraToNextPosition()));
	// Pour la barre de progression 
    connect(focuswindow, SIGNAL(PictureTaken()), this, SLOT(incNbPicturesTaken()));
	connect(photoButton, SIGNAL(clicked()), focuswindow, SLOT(SaveImage()));
	// Arret d'urgence
    //connect(progressPage->stopButton, SIGNAL(clicked()), serialcomm, SLOT(emergencyStop()));
	// Debut du cycle !
	//connect(progressPage, SIGNAL(goRequest()), serialcomm, SLOT(startCycle()));
	Log("Connexions faites");

	
	//connect(goButton, SIGNAL(clicked()), serialcomm, SLOT(startCycle()));
	connect(stopButton, SIGNAL(clicked()), serialcomm, SLOT(emergencyStop()));
	
	//QObject::connect(moveButton, SIGNAL(clicked()), this, SLOT(moveCamera()));
	//QObject::connect(realButton, SIGNAL(clicked()), this, SLOT(restoreToActualValues()));

	//test
	//connect(focuswindow, SIGNAL(CameraStarted()), serialcomm, SLOT(startCycle()));

    //addPage(introPage);


    // Framing page

    // Add video
    //QCamera webcam(getWebcamInfo());
    //QWidget * videoContainer = new QWidget();
    //QVideoWidget * videoWidget = new QVideoWidget(videoContainer);
    //videoWidget->resize(200, 120);

    //webcam.setViewfinder(videoWidget);
    //webcam.start();

    //framingPage->layout()->addWidget(videoContainer);
	
	// layout

	QGridLayout * layout = new QGridLayout;
	//layout->addWidget(XPosBox);
	//layout->addWidget(YPosBox);
	//layout->addWidget(realButton);
	//layout->addWidget(moveButton);
	//layout->addWidget(cameraSettingsButton);

	layout->addWidget(photoButton);
	layout->addWidget(goButton);
	layout->addWidget(stopButton);
	layout->addWidget(bar);

	setLayout(layout);


    //addPage(framingPage);
    // End framing page

    //addPage(createSettingsPage());
    //addPage(createProgressPage());

    setWindowTitle("GigaProxyPhoto");
    setFixedSize(700, 600);
	//Log("Pages ajoutees");
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

