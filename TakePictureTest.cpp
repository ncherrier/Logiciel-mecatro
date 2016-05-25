
#include <iostream> // TODO: remove after tests
#include <QtWidgets/QApplication>
#include <QPushButton>
#include <QGridLayout>
#include "TakePictureTest.h"
#include "SynchronousGrab.h"

using namespace std;

// Slot
void TakePictureTest::takePicture() {
std::cout << "TODO : take picture" << std::endl;
// TODO !!
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
SynchronousGrab sync = SynchronousGrab::SynchronousGrab(this,0);
QImage imagetest = sync.GetImage();
QLabel label;
label.resize(imagetest.size());
label.setPixmap(QPixmap::fromImage(imagetest));
label.setWindowTitle(QObject::tr("Miracle ?"));
label.show();

}

// Default destructor
TakePictureTest::~TakePictureTest() {
// What TODO ?
}
