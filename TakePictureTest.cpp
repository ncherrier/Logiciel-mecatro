
#include <iostream> // TODO: remove after tests
#include <QtWidgets/QApplication>
#include <QPushButton>
#include <QGridLayout>
#include "TakePictureTest.h"
#include "SynchronousGrab.h"
//#include <QObject>

/*
using namespace std;

// Slot
void TakePictureTest::takePicture() {

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

QObject::connect(goButton, SIGNAL(clicked()), this, SLOT(takePicture()));

// Layout

QGridLayout *layout = new QGridLayout;
layout->addWidget(goButton,1,1);
setLayout(layout);

SynchronousGrab sync = SynchronousGrab::SynchronousGrab();
QImage imagetest = sync.GetImage();
QLabel label;
label.resize(imagetest.size());
label.setPixmap(QPixmap::fromImage(imagetest));
label.setWindowTitle(QObject::tr("Miracle ?"));
label.show();

QTimer *timer = new QTimer(this);
QObject::connect(timer, SIGNAL(timeout()), &label, SLOT(setPixmap(QPixmap::fromImage(sync.GetImage()))));
timer->start(100); // toutes les 100ms (10 fois par seconde)

}

// Default destructor
TakePictureTest::~TakePictureTest() {
// What TODO ?
}

*/
