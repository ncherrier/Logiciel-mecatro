/* Provisory window to test the communication
* with the industrial camera.
* Can we take a picture ? */


/*
#ifndef TAKEPICTURETEST_H
#define TAKEPICTURETEST_H

#include <QWidget>
#include <QPushButton>
#include "AsynchronousGrab.h"

class TakePictureTest : public QWidget
{
	 Q_OBJECT //!\ Build -> run QMAKE before building and running

	public:
		TakePictureTest();
		virtual ~TakePictureTest();

    public slots:
		void OnImageReceived(QImage image);

	private:
	  QPushButton *goButton;
	  QLabel *label;
	  QTimer *timer;
	  AsynchronousGrab *sync;
	  QImage *image;

};



#endif // TAKEPICTURETEST_H

*/
