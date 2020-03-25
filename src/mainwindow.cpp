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
	delete dockValidation;
}

void MainWindow::addMenuBar()
{
	// File menu
	auto fileMenu = menuBar()->addMenu("File");
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
	// Save as
	auto fileSaveAs = fileMenu->addAction(Icons::get("file-save-as"), "Save As...");
	fileSaveAs->setShortcut(QKeySequence::SaveAs);
	// Quit
	fileMenu->addSeparator();
	auto fileQuit = fileMenu->addAction(Icons::get("file-quit"), "Quit");
	fileQuit->setShortcut(QKeySequence::Quit);
	QAction::connect(fileQuit, &QAction::triggered, [this](bool checked) {
		close();
	});

	// Edit menu
	auto editMenu = menuBar()->addMenu("Edit");
	// Rename project
	editMenu->addAction(Icons::get("edit-rename"), "Rename Project...");
	// Reload project
	editMenu->addAction(Icons::get("edit-reload"), "Reload Project");

	// View menu
	auto viewMenu = menuBar()->addMenu("View");
	// Validation engine
	auto viewValidate = viewMenu->addAction("Validation Engine");
	viewValidate->setCheckable(true);

	// About menu
	auto aboutMenu = menuBar()->addMenu("About");
	// About app
	auto aboutVersion = aboutMenu->addAction(
		Icons::get("about-app"),
		QString("Version %1").arg(VERSION));
	aboutVersion->setEnabled(false);
	// About Qt
	auto aboutQt = aboutMenu->addAction(Icons::get("about-qt"), "About Qt");
	QAction::connect(aboutQt, &QAction::triggered, [this](bool checked) {
		QMessageBox::aboutQt(this);
	});
	// Third-party licenses
	auto aboutLicenses = aboutMenu->addAction(Icons::get("about-licenses"), "Licenses");
	QAction::connect(aboutLicenses, &QAction::triggered, [this](bool checked) {
		QDesktopServices::openUrl(QUrl("https://gitlab.com/orqapp/orq/blob/master/third_party.md"));
	});
	// Check for updates
	aboutMenu->addAction(Icons::get("about-update"), "Check for Updates");
}