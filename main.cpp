#include <QApplication>
#include <QMainWindow>
#include <QMenu>
#include "MainWindow.h"

int main(int argc, char* argv[])
{
	QApplication a(argc,argv);
	MainWindow dia;
	dia.show();
	return a.exec();
}
