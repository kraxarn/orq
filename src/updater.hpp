#pragma once

#include "main.hpp"

#include <QNetworkAccessManager>
#include <QNetworkReply>
#include <QCoreApplication>
#include <QJsonDocument>
#include <QJsonArray>
#include <QJsonObject>

class Updater
{
public:
	Updater();
	~Updater();
	bool isLatest();
private:
	QNetworkAccessManager	*network;
};