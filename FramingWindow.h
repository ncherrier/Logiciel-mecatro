#ifndef FRAMINGWINDOW_H
#define FRAMINGWINDOW_H

#include <QPushButton>
#include <QWidget>
#include <QApplication>
#include <QtMultimedia>
#include <QtMultimediaWidgets>
#include <QVideoWidget>

class FramingWindow : public QWidget
{
	//Q_OBJECT // To be able to define new slots (interactions with user)
	// /!\ Build -> run QMAKE before building and running

public:
	FramingWindow();
	//virtual ~FramingWindow();
	// No destructor needed (?)

	//public slots:
	// void goToSettingsWindow();

private:
	// video
	// QWidget *videoContainer;
	// QVideoWidget *videoWidget;
	// buttons
	// QPushButton *nextButton;
	// QPushButton *cancelButton;

};

#endif // FRAMINGWINDOW_H

