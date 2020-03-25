#include "mainwindow.hpp"

#include <QApplication>
#include <QCoreApplication>

int main(int argc, char *argv[])
{
	// Setup application variables
	QCoreApplication::setOrganizationName("orqapp");
	QCoreApplication::setApplicationName("orq");

	// Create main window and app
	QApplication app(argc, argv);
	MainWindow window;

	// Show main window and run main Qt loop
	window.show();
	return app.exec();
}
