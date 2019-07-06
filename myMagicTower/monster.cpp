#include "monster.h"



monster::monster()
{
	_id = 0;
}

monster::monster(int monsterid)
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

			if (_id == monsterid)
			{
				infile >> _mainType >> _subType >> _name >> _attr >> _hp >> _attack >> _defense >> _attackSpeed >> _carryExp;
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


monster::~monster()
{

}

int monster::getId()
{
	return _id;
}

int monster::getMainType()
{
	return _mainType;
}

int monster::getSubType()
{
	return _subType;
}

std::string monster::getName()
{
	return _name;
}

int monster::getAttr()
{
	return _attr;
}

void monster::setAttr(int attr)
{
	_attr = attr;
}

int monster::getHp()
{
	return _hp;
}

void monster::setHp(int hp)
{
	_hp = hp;
}

int monster::getAttack()
{
	return _attack;
}

void monster::setAttack(int attack)
{
	_attack = attack;
}

int monster::getDefense()
{
	return _defense;
}

void monster::setDefense(int defense)
{
	_defense = defense;
}

int monster::getAttackSpeed()
{
	return _attackSpeed;
}

int monster::getCarryExp()
{
	return _carryExp;
}