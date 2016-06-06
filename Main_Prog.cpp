#include <QApplication>
#include <QPushButton>

#include "cameraSettingsWindow.h"
#include "SerialCommunication.h"
#include "TakePictureTest.h" // for tests only
#include <iostream> // for tests

// Pour le flux video de la webam
#include <QtMultimedia>
#include <QtMultimediaWidgets>
#include <QVideoWidget>
#include <QPainter>
#include <QLabel>

#include "GPPWizard.h"


using namespace std;

// to debug
void Log(std::string strMsg)
{
	QString filename = "Data.txt";
	QFile file(filename);
	if (file.open(QIODevice::ReadWrite | QIODevice::Append))
	{
		QTextStream stream(&file);
		stream << QString::fromUtf8(strMsg.c_str()) << endl;
	}
}

int main(int argc, char *argv[])
{
    Log("hello! in main");
	QApplication *app = new QApplication(argc, argv);


    // WIZARD (fenetre principale)
    GPPWizard * GPP = new GPPWizard();
    GPP->show();
	Log("GPP Wizard created");
    // FIN WIZARD

    //TakePictureTest *tak = new TakePictureTest();
    //tak->show();

    //WEBCAM !!!!

    //Définition de l'image contenant le rectangle
    QImage image = QImage(800,460,QImage::Format_ARGB32);
    QPainter painter(&image);

    //Permet de détecter la webcam
    QList<QCameraInfo> cameras = QCameraInfo::availableCameras();
	QWidget w;
	QWidget videoContainer;
	QCamera *camera;
	QVideoWidget* videoWidget;
	QLabel *myLabel;
	QGridLayout *layout;
	if (cameras.size() > 0){
		Log("Webcam trouvee");

		QCameraInfo const firstCam = cameras[0];
		//QCameraInfo const secondCam = cameras[1];
		camera = new QCamera(firstCam);
		
		// création d'un QVideoWidget avec videoContainer comme parent
		videoWidget = new QVideoWidget(&videoContainer);

		videoWidget->resize(600, 360); //Taille de la vidéo - A MODIFIER ???
		videoWidget->setAspectRatioMode(Qt::KeepAspectRatio);

		camera->setViewfinder(videoWidget); //Intègre la vidéo au videoWidget
		camera->start();



		// tracer le cadre
		painter.drawRect(0, 0, 700, 400); // A MODIFIER
		myLabel = new QLabel(&videoContainer);
		myLabel->setPixmap(QPixmap::fromImage(image));

		// layout
		layout = new QGridLayout;
		layout->addWidget(&videoContainer);
		w.setLayout(layout);

		w.resize(600, 360); //Taille de la fenêtre

		w.show();
		//FIN WEBCAM
	}
	else{
		Log("Pas de webcam trouvee");
	}

    return app->exec();
}



