#include "item.h"



//int _id;
//int _mainType;
//int _subType;
//std::string _name;
//int _attr;

item::item()
{
	_id = 0;


}

item::item(int itemid)
{
	std::ifstream infile("data\\item_proto.txt");
	

	if (!infile)
	{
		std::cerr << "打开item_proto文件失败" << std::endl;
	}
	else
	{
		while (!infile.eof())
		{
			infile >> _id;

			if (_id == itemid)
			{
				infile >> _mainType >> _subType >> _name >> _attr;
			

				break;
			}
			else
			{
				std::string sTmp;
				std::getline(infile, sTmp);
			}
		}
	}

	infile.close();


}


item::~item()
{
}


int item::getId()
{
	return _id;
}

void item::setId(int id)
{
	_id = id;
}

int item::getMainType()
{
	return _mainType;

}

void item::setMainType(int maintype)
{
	_mainType = maintype;
}

int item::getSubType()
{
	return _subType;

}

void item::setSubType(int subtype)
{
	_subType = subtype;
}

std::string item::getName()
{
	return _name;
}

void item::setName(std::string name)
{
	_name = name;
}

int item::getAttr()
{
	return _attr;
}

void item::setAttr(int attr)
{
	_attr = attr;
}