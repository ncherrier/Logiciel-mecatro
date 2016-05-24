/* Fenetre pour le cadrage
* (affiche le signal de la webcam ;
* accès aux reglages de la webcam (?)) */

#include "FramingWindow.h"
#include "SettingsWindow.h"
#include <QApplication>
#include <QPushButton>
#include <QGridLayout>
#include <iostream> // TODO: remove after tests

using namespace std;

// Slots

/*void FramingWindow::goToSettingsWindow() {
// SettingsWindow *set = new SettingsWindow();
// set->show();
// this->close();
// ****** TEST!!! ******

}*/

// Constructors and destructors

// Default Constructor
FramingWindow::FramingWindow() : QWidget()
{

	// provisory
	cout << "TODO: inclure le flux video de la webcam" << endl;

	// Detect webcam
	QList<QCameraInfo> cameras = QCameraInfo::availableCameras();
	QCameraInfo const firstCam = cameras[0];
	QCamera camera(firstCam);

	// Flux video...
	QWidget videoContainer(this);
	// setCentralWidget(&videoContainer);
	QVideoWidget videoWidget(&videoContainer);
	videoWidget.resize(800, 480); // video size
	camera.setViewfinder(&videoWidget); //Intègre la vidéo au videoWidget
	camera.start();
	// provisory
	cout << "camera started" << endl;


	// Set size and title

	setFixedSize(800, 480);
	setWindowTitle("Framing");


	// Buttons

	//nextButton = new QPushButton("Next >");
	//cancelButton = new QPushButton("Cancel");


	// Tips

	//QString userTip = "Utiliser la webcam pour le cadrage, puis cliquer sur Next. Au besoin, régler la webcam. (Ces réglages n'interviennent pas dans la photo finale.)";



	// Signals and slots

	// QObject::connect(cancelButton, SIGNAL(clicked()), qApp, SLOT(quit()));
	// QObject::connect(nextButton, SIGNAL(clicked()), this, SLOT(goToSettingsWindow()));



	// Layout

	// QGridLayout *layout = new QGridLayout;

	/*layout->addWidget(&videoWidget, 1, 1);
	layout->addWidget(cancelButton, 2, 1);
	layout->addWidget(nextButton, 2, 2);

	setLayout(layout);*/
}

// Default destructor
//FramingWindow::~FramingWindow(){
// what TODO ??
//}
