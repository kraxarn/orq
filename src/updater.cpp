#include "updater.hpp"

Updater::Updater()
{
	network = new QNetworkAccessManager();
}

Updater::~Updater()
{
	delete network;
}

bool Updater::isLatest()
{
	auto reply = network->get(QNetworkRequest(
		QUrl("https://gitlab.com/api/v4/projects/17193193/repository/tags")));
	while (!reply->isFinished())
		QCoreApplication::processEvents();
	reply->deleteLater();
	return QJsonDocument::fromJson(reply->readAll()).array()[0].toObject()["name"] == VERSION;
}