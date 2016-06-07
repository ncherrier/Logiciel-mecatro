
#ifndef FOCUSWINDOW_H
#define FOCUSWINDOW_H

#include <QWidget>
#include <QPushButton>
#include <QLabel>
#include "AsynchronousGrab.h"

class FocusWindow : public QWidget
{
	Q_OBJECT 

	public:
		FocusWindow();
        virtual ~FocusWindow();
		void Log(std::string strMsg);

	public slots:
		void OnImageReceived(QImage* image);
		void SaveImage();

	private:
		QLabel * label;
		AsynchronousGrab *sync;
		QString dirpath;
		int nb_photos;
		QImage * m_img;

	signals:
		void PictureTaken();
		//void CameraStarted();

};



#endif // FOCUSWINDOW_H
