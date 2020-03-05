#include "mainwindow.hpp"
#include <QMenuBar>
#include <QMenu>
#include <QAction>
#include <QtGlobal>
#include <QtDebug>

MainWindow::MainWindow(QWidget *parent)
	: QMainWindow(parent)
{
	setWindowTitle("orq");
	setMinimumSize(960, 540);
	resize(1280, 720);
	AddMenuBar();
}

MainWindow::~MainWindow()
{
	delete _fileNew;
	delete _fileOpen;
	delete _fileSaveAs;
	delete _fileQuit;
	delete _fileMenu;
	delete _menubar;
}

void MainWindow::AddMenuBar()
{
	_menubar = new QMenuBar(this);
	
	// File menu
	_fileMenu = new QMenu("File", this);
	// New project
	_fileNew = new QAction("New...", this);
	_fileNew->setShortcut(QKeySequence(Qt::CTRL + Qt::Key_N));
	connect(_fileNew, &QAction::triggered, this, &MainWindow::NewProject);
	_fileMenu->addAction(_fileNew);
	
	// Open project
	_fileOpen = new QAction("Open...", this);
	_fileOpen->setShortcut(QKeySequence(Qt::CTRL + Qt::Key_O));
	connect(_fileOpen, &QAction::triggered, this, &MainWindow::OpenProject);
	_fileMenu->addAction(_fileOpen);

	// Save-as
	_fileSaveAs = new QAction("Save As...", this);
	_fileSaveAs->setShortcut(QKeySequence(Qt::CTRL + Qt::Key_S));
	connect(_fileSaveAs, &QAction::triggered, this, &MainWindow::SaveProject);
	_fileMenu->addAction(_fileSaveAs);

	// Add separator
	_fileMenu->addSeparator();

	// Quit
	_fileQuit = new QAction("Quit", this);
	_fileQuit->setShortcut(QKeySequence(Qt::CTRL + Qt::Key_Q));
	connect(_fileQuit, &QAction::triggered, this, &MainWindow::QuitProject);
	_fileMenu->addAction(_fileQuit);

	// Add file menu to menubar
	_menubar->addMenu(_fileMenu);

	// Edit menu
	// TODO
}

void MainWindow::NewProject()
{
	qDebug() << "New project";
}

void MainWindow::OpenProject()
{
	qDebug() << "Open project";
}

void MainWindow::SaveProject()
{
	qDebug() << "Save project";
}

void MainWindow::QuitProject()
{
	qDebug() << "Quit project";
}
