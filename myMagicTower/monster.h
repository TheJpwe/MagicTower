#pragma once
#include "common.h"

class monster
{
	int _id;
	int _mainType;
	int _subType;
	std::string _name;
	int _attr;
	int _hp;
	int _attack;
	int _defense;
	int _attackSpeed;
	int _carryExp;


public:
	monster();
	monster(int monsterid);
	~monster();

	int getId();
	
	int getMainType();
	
	int getSubType();

	std::string getName();

	int getAttr();
	void setAttr(int attr);

	int getHp();
	void setHp(int hp);

	int getAttack();
	void setAttack(int attack);

	int getDefense();
	void setDefense(int defense);

	int getAttackSpeed();

	int getCarryExp();

};

