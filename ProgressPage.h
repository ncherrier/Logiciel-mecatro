// Page pour montrer l'avancement (photos prises/photos restantes)

#ifndef PROGRESSPAGE_H
#define PROGRESSPAGE_H

#include <QWizardPage>
#include <QLabel>
#include <QProgressBar>
#include <QGridLayout>
#include <QPushButton>
#include <QWidget>

class ProgressPage :  public QWizardPage
{

    Q_OBJECT

private:
	QPushButton * goButton;
    QProgressBar * bar;
    QPushButton * stopButton;

public slots:
    void incNbPicturesTaken();
    void handleGoButtonClicked();
	void handleStopButtonClicked();

public:
    ProgressPage();
    QPushButton* getStopButton();
	QPushButton* getGoButton();
	// for tests
	void Log(std::string strMsg);

signals:
	void goRequest();
    void stopRequest();

};

#endif // PROGRESSPAGE_H
