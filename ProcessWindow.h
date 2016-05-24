
#ifndef PROCESSWINDOW_H
#define PROCESSWINDOW_H

#include <QPushButton>
#include <QWidget>
#include <QApplication>

class ProcessWindow : public QWidget
{
	Q_OBJECT // To be able to define new slots (interactions with user)
		// /!\ Build -> run QMAKE before building and running

public:
	ProcessWindow();

	public slots:
	void emergencyStop();

private:
	QPushButton *stopButton; // For "emergency" stop

};

#endif // PROCESSWINDOW_H
