#pragma once
#include "common.h"


class backMap
{
	int _id;
	int _mainType;
	int _subType;
	std::string _name;
	int _attr;


public:
	backMap();
	backMap(int backmapid);
	~backMap();

	int getSubType();
	
	int getAttr();



};

