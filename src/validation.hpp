#pragma once

#include "item.hpp"

#include <QVector>
#include <QString>
#include <QMap>
#include <QList>
#include <QListWidgetItem>

class Validation
{
	Validation();

	bool containsItem(QMap<Item, int> items, Item target);

	QString getItemName(Item item);
	
	QVector<Item> validateLinks();

	QVector<Item> validateRoots();

	QVector<Item> validateLoops();

	QVector<Item> validateLinkErrors();

	enum class Option
	{
		SameType 	= 0,
		OneRoot 	= 1,
		LinkLoop 	= 2,
		LinkError 	= 3
	};

	const QString ValidateOk 		= "validate-ok";
	const QString ValidateFail 		= "validate-fail";
	const QString ValidateDisabled	= "validate-disabled";
	const QString ValidateNone 		= "validate-none";

	QListWidgetItem *createValidationResult(Option option, QString result);

	QString getDefaultValidationResult(bool enabled);

	QWidget *createValidationEngineLayout();
};