//@author A0097195N
//Description: Runs the program and displays an image to the user 
//             signalling the start of the program.

#include "wwgui.h"
#include <QtWidgets/QApplication>
#include <Windows.h>
#include <QSplashScreen>
#include <QTimer>

int main(int argc, char *argv[])
{
	QApplication a(argc, argv);
	WWGUI w;
	//To display the starting image of the program
	QPixmap pixmap(":/WWGUI/Resources/WW.png");
	QSplashScreen splash(pixmap);
	splash.show();
	//start program after 3 seconds
	QTimer::singleShot(3000, &splash, SLOT(close()));
    Sleep(3000);
	w.show();
	return a.exec();
}