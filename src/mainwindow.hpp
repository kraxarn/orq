#pragma once

#include "icons.hpp"
#include "main.hpp"

#include <QMainWindow>
#include <QApplication>
#include <QStyle>
#include <QScreen>
#include <QDockWidget>
#include <QFileDialog>
#include <QStandardPaths>
#include <QMessageBox>
#include <QDesktopServices>
#include <QUrl>

class MainWindow : public QMainWindow
{
	Q_OBJECT

public:
	MainWindow(QWidget *parent = nullptr);
	~MainWindow();

private:
	QDockWidget	*dockValidation;

	void addMenuBar();
};
