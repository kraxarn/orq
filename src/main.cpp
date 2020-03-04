#include "mainwindow.hpp"

#include <QApplication>

int main(int argc, char *argv[])
{
	QApplication app(argc, argv);
	MainWindow window = MainWindow(nullptr);
	window.setWindowTitle("orq");
	window.setMinimumSize(960, 540);
	window.resize(1280, 720);
	window.AddMenuBar();
	window.show();
	return app.exec();
}
