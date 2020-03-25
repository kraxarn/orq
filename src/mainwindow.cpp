#include "mainwindow.hpp"
#include <QMenuBar>
#include <QMenu>
#include <QAction>
#include <QtGlobal>
#include <QtDebug>

MainWindow::MainWindow(QWidget *parent) : QMainWindow(parent)
{
	// Set minimum and initial size
	setMinimumSize(960, 540);
	resize(1280, 720);

	// Center window on screen
	setGeometry(QStyle::alignedRect(
		Qt::LeftToRight,
		Qt::AlignCenter,
		size(),
		QGuiApplication::screens().at(0)->availableGeometry()
	));

	// Set window title
	setWindowTitle("orq");

	// Setup the rest of the stuff
	addMenuBar();
}

MainWindow::~MainWindow()
{
	delete menubar;
	delete dockValidation;
}

void MainWindow::addMenuBar()
{
	// Main menu bar
	menubar = new QMenuBar(this);
	
	// File options
	auto fileMenu = menubar->addMenu("File");
	// New
	auto fileNew = fileMenu->addAction(Icons::get("file-new"), "New...");
	fileNew->setShortcut(QKeySequence::New);
	QAction::connect(fileNew, &QAction::triggered, [this](bool checked) {
		auto fileName = QFileDialog::getSaveFileName(
			this,
			"New Project",
			QStandardPaths::locate(QStandardPaths::DocumentsLocation, ""),
			"orq project(*.orq)"
		);
		if (fileName.length() > 0)
		{
			// TODO: newProject(), reloadProject()
		}
	});
	// Open
	auto fileOpen = fileMenu->addAction(Icons::get("file-open"), "Open...");
	fileOpen->setShortcut(QKeySequence::Open);
	QAction::connect(fileOpen, &QAction::triggered, [this](bool checked) {
		// TODO
	});
	// Save as
	auto fileSaveAs = fileMenu->addAction(Icons::get("file-save-as"), "Save as...");
	fileSaveAs->setShortcut(QKeySequence::SaveAs);
	QAction::connect(fileSaveAs, &QAction::triggered, [this](bool checked) {
		// TODO
	});
	// Quit
	fileMenu->addSeparator();
	auto fileQuit = fileMenu->addAction(Icons::get("file-quit"), "Quit");
	fileQuit->setShortcut(QKeySequence::Quit);
	QAction::connect(fileQuit, &QAction::triggered, [this](bool checked) {
		close();
	});
}