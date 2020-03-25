#pragma once

#include <QMainWindow>
#include <QApplication>

class MainWindow : public QMainWindow
{
	Q_OBJECT

public:
	MainWindow(QWidget *parent = nullptr);
	~MainWindow();

private: 
	QMenuBar	*menubar;
	QMenu		*fileMenu;
	QAction		*fileNew;
	QAction		*fileOpen;
	QAction		*fileSaveAs;
	QAction		*fileQuit;

	void addMenuBar();
};
