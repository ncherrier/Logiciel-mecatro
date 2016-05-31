
#include <iostream> // TODO: remove after tests
#include <QtWidgets/QApplication>
#include <QPushButton>
#include <QGridLayout>
#include "TakePictureTest.h"
#include "SynchronousGrab.h"
//#include <QObject>


using namespace std;

// Slot
void TakePictureTest::takePicture(SynchronousGrab *sync) {
	QImage imagetest;
	std::string res = sync->GetImage(&imagetest);
	label->setPixmap(QPixmap::fromImage(imagetest));
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
//QImage imagetest;
//std::string res = sync.GetImage(&imagetest);

label = new QLabel;
//label->resize(imagetest.size());
label->setFixedWidth(200);
label->setFixedHeight(200);
//label->setPixmap(QPixmap::fromImage(imagetest));
//label->setWindowTitle(QObject::tr("Miracle ?"));
//label->show();
//timer = new QTimer(this);
//timer->setInterval(1000); // toutes les 100ms (10 fois par seconde)
//QImage *image2 = &imagetest;
QObject::connect(goButton, SIGNAL(clicked()), this, SLOT(takePicture(&sync)));
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

