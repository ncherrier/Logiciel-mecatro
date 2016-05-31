/* Provisory window to test the communication
* with the industrial camera.
* Can we take a picture ? */



#ifndef TAKEPICTURETEST_H
#define TAKEPICTURETEST_H

#include <QWidget>
#include <QPushButton>
#include "SynchronousGrab.h"

class TakePictureTest : public QWidget
{
	 Q_OBJECT //!\ Build -> run QMAKE before building and running

	public:
		TakePictureTest();
		virtual ~TakePictureTest();

    public slots:
	    void takePicture();

	private:
	  QPushButton *goButton;
	  QLabel *label;
	  QTimer *timer;
	  SynchronousGrab *sync;
	  QImage *image;

};



#endif // TAKEPICTURETEST_H

