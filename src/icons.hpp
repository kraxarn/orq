#pragma once

#include <QHash>
#include <QIcon>

class Icons
{
private:
	static QHash<QString, QString> iconNames;
public:
	Icons();
	QIcon get(const QString &name);
};


