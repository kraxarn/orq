#pragma once

#include <QGuiApplication>

#include "datacontext.h"

class Project
{
public:
	/// Open a new project
	Project(QString path);

	/// Close project
	~Project();

private:
	/// Project/database has been opened
	bool open;

	/// Data context for data access
	DataContext *data;
};