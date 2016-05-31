
#include <iostream> // TODO: remove after tests
#include <QtWidgets/QApplication>
#include <QPushButton>
#include <QGridLayout>
#include "TakePictureTest.h"
#include "SynchronousGrab.h"
//#include <QObject>


using namespace std;

// Slot
void TakePictureTest::takePicture() {
	QImage imagetest;
	imagetest = sync->GetImage();
	//QImage* imagerecup = sync->GetImageRecup();
	/*if (res) {
		label->setPixmap(QPixmap::fromImage(imagetest));
	}*/

	/*QString fichier = QFileDialog::getOpenFileName(this, QString(), QString(), "*.jpg *.gif *.png");
	//QMessageBox::information(this, "Fichier", "Vous avez sélectionné :\n" + fichier);
	label->setPixmap(fichier);*/
}

// Default Constructor
TakePictureTest::TakePictureTest()
{
// Set size and title

setFixedSize(800,400);
setWindowTitle("Test : take picture");

// Button

goButton = new QPushButton("Take picture");

// Slots

//QObject::connect(goButton, SIGNAL(clicked()), this, SLOT(takePicture()));

// Layout
SynchronousGrab sync = SynchronousGrab::SynchronousGrab();

label = new QLabel;
//label->resize(imagetest.size());
label->setFixedWidth(200);
label->setFixedHeight(200);
//timer = new QTimer(this);
//timer->setInterval(1000); // toutes les 100ms (10 fois par seconde)
//QImage *image2 = &imagetest;
QObject::connect(goButton, SIGNAL(clicked()), this, SLOT(takePicture()));
/*QObject::connect(timer, SIGNAL(timeout()), label, SLOT(setPixmap(QPixmap::fromImage(image2))));
QObject::connect(goButton, SIGNAL(clicked()), &sync, SLOT(GetImage(image2)));
QObject::connect(goButton, SIGNAL(clicked()), label, SLOT(setPixmap(QPixmap::fromImage(image2))));
timer->start();
*/


QGridLayout *layout = new QGridLayout;
layout->addWidget(goButton, 1, 1);
layout->addWidget(label,0,1);
setLayout(layout);

}

// Default destructor
TakePictureTest::~TakePictureTest() {
// What TODO ?
}

