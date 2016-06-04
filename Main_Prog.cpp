#include <QApplication>
#include <QPushButton>

#include "cameraSettingsWindow.h"
#include "SerialCommunication.h"
#include "TakePictureTest.h" // for tests only
#include <iostream> // for tests

// For videos
#include <QtMultimedia>
#include <QtMultimediaWidgets>
#include <QVideoWidget>

#include "GPPWizard.h"


using namespace std;


int main(int argc, char *argv[])
{
    cout << "hello! in main" << endl;
	QApplication *app = new QApplication(argc, argv);


    // WIZARD (fenetre principale)
    GPPWizard * GPP = new GPPWizard();
    GPP->show();
    // FIN WIZARD

    //TakePictureTest *tak = new TakePictureTest();
    //tak->show();

    //WEBCAM !!!!

    //Permet de détecter la webcam
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

    w.show();
    //FIN WEBCAM


    return app->exec();
}



