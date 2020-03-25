#pragma once

#include "icons.hpp"

#include <QMainWindow>
#include <QApplication>
#include <QStyle>
#include <QScreen>
#include <QDockWidget>
#include <QFileDialog>
#include <QStandardPaths>

class MainWindow : public QMainWindow
{
	Q_OBJECT

public:
	MainWindow(QWidget *parent = nullptr);
	~MainWindow();

private: 
	QMenuBar	*menubar;
	QDockWidget	*dockValidation;

	void addMenuBar();
};
