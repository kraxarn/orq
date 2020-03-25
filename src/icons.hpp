#pragma once

#include <QHash>
#include <QIcon>

class Icons
{
private:
	static QHash<QString, QString> iconNames;
public:
	Icons();
	static QIcon get(const QString &name);
};


