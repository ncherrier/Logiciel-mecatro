
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
QImage imagetest = sync.GetImage();

label = new QLabel;
//label->resize(imagetest.size());
label->setFixedWidth(200);
label->setFixedHeight(200);
label->setPixmap(QPixmap::fromImage(imagetest));
//label->setWindowTitle(QObject::tr("Miracle ?"));
//label->show();
timer = new QTimer(this);
timer->setInterval(1000); // toutes les 100ms (10 fois par seconde)
//QObject::connect(timer, SIGNAL(timeout()), label, SLOT(setPixmap(QPixmap::fromImage(sync.GetImage()))));
QObject::connect(goButton, SIGNAL(clicked()), label, SLOT(setText("Essai")));
timer->start();
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

