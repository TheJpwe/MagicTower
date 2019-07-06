#include "backMap.h"

backMap::backMap()
{
	_id = 0;
}

backMap::backMap(int backmapid)
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

			if (_id == backmapid)
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




backMap::~backMap()
{
}


int backMap::getSubType()
{
	return _subType;
}

int backMap::getAttr()
{
	return _attr;
}