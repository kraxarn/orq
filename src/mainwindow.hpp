#pragma once

#include <QMainWindow>
#include <QApplication>

class MainWindow : public QMainWindow
{
	Q_OBJECT

private: 
	QMenuBar* _menubar;
	QMenu* 	  _fileMenu;
	QAction*  _fileNew;
	QAction*  _fileOpen;
	QAction*  _fileSaveAs;
	QAction*  _fileQuit;

public:
	MainWindow(QWidget *parent = nullptr);
	~MainWindow();

	void AddMenuBar();
	void NewProject();
	void OpenProject();
	void SaveProject();
	void QuitProject();
};
