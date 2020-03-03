#pragma once

#include <QByteArray>
#include <QPair>
#include <QtGlobal>

class Item
{
private:
	/**
	 * @brief Row id in database
	 * 
	 */
	qint64 id;
public:
	/**
	 * @brief Create a new item from row id
	 * 					
	 * @param id Row id 
	 */
	Item(qint64 id);

	enum ItemType
	{
		Requirement 				= 0,
		SolutionArgument			= 1,
		DomainKnowledge				= 2,
		ArchitecturalDescription	= 3,
		TestCase 					= 4
	};

	/**
	 * @brief get global unique id :q!:q!
	 * 
	 * @return int 
	 */
	int guid();
	void setGuid(int guid);

	int version();
	
	QByteArray hash();

	bool shown();
	void setShown();
	
	QPair<int, int> pos();
	void setPos(int x, int y); 

	QPair<int, int> size();
	void setSize(int w, int h);

	ItemType type();
	void setType(ItemType type);

	void addChild(Item child);
	void removeChild(Item child);
	QVector<Item> children();

	void addParent(Item parent);
	void removeParent(Item parent);
	QVector<Item> parents();

	bool isPropertyNull(QString columnName);

	QString toString();
};