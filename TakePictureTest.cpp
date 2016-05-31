
#include <iostream> // TODO: remove after tests
#include <QtWidgets/QApplication>
#include <QPushButton>
#include <QGridLayout>
#include "TakePictureTest.h"
#include "AsynchronousGrab.h"
//#include <QObject>


using namespace std;

// Slot
void TakePictureTest::takePicture(QImage image) {
	label->setPixmap(QPixmap::fromImage(image));
}

// Default Constructor
TakePictureTest::TakePictureTest()
{
// Set size and title

setFixedSize(800,400);
setWindowTitle("Test : take picture");

// Button

goButton = new QPushButton("GO !!");

// Layout
sync = new AsynchronousGrab();
QImage *imagetest = new QImage();
label = new QLabel;
label->setFixedWidth(200);
label->setFixedHeight(200);
//label->setPixmap(QPixmap::fromImage(imagetest));
//timer = new QTimer(this);
//timer->setInterval(1000); */ // toutes les 100ms (10 fois par seconde)
//QObject::connect(timer, SIGNAL(timeout()), label, SLOT(setPixmap(QPixmap::fromImage(sync.GetImage()))));

QObject::connect(goButton, SIGNAL(clicked()), sync, SLOT(OnBnClickedButtonStartstop()));
QObject::connect(sync, SIGNAL(ImageReceivedSignal(imagetest)), this, SLOT(takePicture(*imagetest)));
//timer->start();
label->setVisible(true);

QGridLayout *layout = new QGridLayout;
layout->addWidget(goButton, 1, 1);
layout->addWidget(label,0,1);
setLayout(layout);

}

// Default destructor
TakePictureTest::~TakePictureTest() {
// What TODO ?
}

