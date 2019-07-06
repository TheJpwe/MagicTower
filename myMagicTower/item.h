#pragma once
#include "common.h"

//道具类，对应item_proto表中的类型4
class item
{
	int _id;
	int _mainType;
	int _subType;
	std::string _name;
	int _attr;
	

public:
	item();
	item(int itemid);
	~item();

	int getId();
	void setId(int id);

	int getMainType();
	void setMainType(int maintype);

	int getSubType();
	void setSubType(int subtype);

	std::string getName();
	void setName(std::string name);

	int getAttr();
	void setAttr(int attr);


};

