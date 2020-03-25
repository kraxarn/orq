#include "mainwindow.hpp"
#include <QMenuBar>
#include <QMenu>
#include <QAction>
#include <QtGlobal>
#include <QtDebug>

MainWindow::MainWindow(QWidget *parent) : QMainWindow(parent)
{
	setWindowTitle("orq");
	setMinimumSize(960, 540);
	resize(1280, 720);
	addMenuBar();
}

MainWindow::~MainWindow()
{
	delete fileNew;
	delete fileOpen;
	delete fileSaveAs;
	delete fileQuit;
	delete fileMenu;
	delete menubar;
}

void MainWindow::addMenuBar()
{
	menubar = new QMenuBar(this);
	
	// File menu
	fileMenu = new QMenu("File", this);
	// New project
	fileNew = new QAction("New...", this);
	fileNew->setShortcut(QKeySequence(Qt::CTRL + Qt::Key_N));
	connect(fileNew, &QAction::triggered, this, &MainWindow::newProject);
	fileMenu->addAction(fileNew);
	
	// Open project
	fileOpen = new QAction("Open...", this);
	fileOpen->setShortcut(QKeySequence(Qt::CTRL + Qt::Key_O));
	connect(fileOpen, &QAction::triggered, this, &MainWindow::ppenProject);
	fileMenu->addAction(fileOpen);

	// Save-as
	fileSaveAs = new QAction("Save As...", this);
	fileSaveAs->setShortcut(QKeySequence(Qt::CTRL + Qt::Key_S));
	connect(fileSaveAs, &QAction::triggered, this, &MainWindow::SaveProject);
	fileMenu->addAction(fileSaveAs);

	// Add separator
	fileMenu->addSeparator();

	// Quit
	fileQuit = new QAction("Quit", this);
	fileQuit->setShortcut(QKeySequence(Qt::CTRL + Qt::Key_Q));
	connect(fileQuit, &QAction::triggered, this, &MainWindow::QuitProject);
	fileMenu->addAction(fileQuit);

	// Add file menu to menubar
	menubar->addMenu(fileMenu);

	// Edit menu
	// TODO
}

void MainWindow::newProject()
{
	qDebug() << "New project";
}

void MainWindow::ppenProject()
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
