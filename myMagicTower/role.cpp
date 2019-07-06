#include "role.h"

//
//int _hp;	//生命
//int _attack;	//角色攻击
//int _defense;	//角色防御
//int _curX;	//角色当前x坐标
//int _curY;	//角色当前y坐标
//std::string _name;	//角色名称
//int _type;	//角色类型id


role::role()
{
	std::ifstream infile("data\\item_proto.txt");
	std::string sTmp;
	if (!infile)
	{
		std::cerr << "打开“item_proto”文件失败" << std::endl;

	}
	else
	{
		
		infile >> _type >> _type >>_type >> _name >> _type >> _hp >> _attack >> _defense >> _attackSpeed;
		
	}

	infile.close();
	infile.clear();

	_curX = 11;
	_curY = 11;
	_tier = 1;
	_yellowKey = 0;
	_blueKey = 0;
	_exp = 0;
	_level = 1;

	infile.open("data\\role_level_up.txt");
	if (!infile)
	{
		std::cerr << "打开“role_level_up”文件失败" << std::endl;

	}
	else
	{
		int tmplevel;
		for (int i = 0; i < MAXLEVEL; i++)
		{
			infile >> tmplevel >> _levelUpInfo[i].needExp >> _levelUpInfo[i].addHp >> _levelUpInfo[i].addAttack >> _levelUpInfo[i].addDefense;
		}
		
	}

	infile.close();

}


role::~role()
{
}

int role::getHp()
{
	return _hp;
}

void role::setHp(int hp)
{
	_hp = hp;
}


int role::getAttack()
{
	return _attack;
}

void role::setAttack(int attack)
{
	_attack = attack;
}

int role::getDefense()
{
	return _defense;
}

void role::setDefense(int defense)
{
	_defense = defense;
}

int role::getCurX()
{
	return _curX;
}

void role::setCurX(int curx)
{
	_curX = curx;
}

int role::getCurY()
{
	return _curY;
}

void role::setCurY(int cury)
{
	_curY = cury;
}

std::string role::getName()
{
	return _name;
}

void role::setName(std::string name)
{
	_name = name;
}


int role::getType()
{
	return _type;
}

void role::setType(int type)
{
	_type = type;
}

int role::getTier()
{
	return _tier;
}

void role::setTier(int tier)
{
	_tier = tier;
}

int role::getYellowKey()
{
	return _yellowKey;
}

void role::setYellowKey(int ykey)
{
	_yellowKey = ykey;
}

int role::getBlueKey()
{
	return _blueKey;
}

void role::setBlueKey(int bkey)
{
	_blueKey = bkey;
}

int role::getAttackSpeed()
{
	return _attackSpeed;
}

void role::setAttackSpeed(int attackspeed)
{
	_attackSpeed = attackspeed;
}

int role::getExp()
{
	return _exp;
}

void role::setExp(int exp)
{
	_exp = exp;
}

int role::getLevel()
{
	return _level;
}

void role::setLevel(int level)
{
	_level = level;
}



//与道具类型的标志物交互函数,返回bool值表示是否能移动到标志物上去。true表示可移动到标志物上
bool role::interaction(item &obj, int &isChangeFloor)
{
	bool result = false;
	int cnt,tmp;
	switch (obj.getSubType())
	{
	case 1:		//向上的楼梯
		//触发进入高一层的函数
		tmp = Role.getTier();
		Role.setTier(++tmp);
		isChangeFloor = 1;
		result = true;
		break;
	case 2:		//向下的楼梯
		//触发进入低一层的函数
		tmp = Role.getTier();
		Role.setTier(--tmp);
		isChangeFloor = -1;
		result = true;
		break;
	case 3:		//门类型
		
		switch (obj.getAttr())
		{
		case 1:		//黄门
			cnt = Role.getYellowKey();
			if (cnt > 0)
			{
				Role.setYellowKey(--cnt);
				result = true;
			}
			else
			{
				result = false;
			}
			std::cout << "当前拥有黄钥匙：" << Role.getYellowKey() << std::endl;
			break;
		case 2:		//蓝门
			cnt = Role.getBlueKey();
			if (cnt > 0)
			{
				Role.setBlueKey(--cnt);
				result = true;
			}
			else
			{
				result = false;
			}
			std::cout << "当前拥有蓝钥匙：" << Role.getBlueKey() << std::endl;
			break;
		default:
			break;
		}
		
		break;
	case 4:		//钥匙
		switch (obj.getAttr())
		{
		case 1:		//黄钥匙
			cnt = Role.getYellowKey();
			Role.setYellowKey(++cnt);
			result = true;

			std::cout << "当前拥有黄钥匙：" << Role.getYellowKey() << std::endl;

			break;
		case 2:		//蓝钥匙
			cnt = Role.getBlueKey();
			Role.setBlueKey(++cnt);
			result = true;

			std::cout << "当前拥有蓝钥匙：" << Role.getBlueKey() << std::endl;
			break;
		default:
			break;
		}

	
		break;
	case 5:		//红药水
		_hp += obj.getAttr();
		std::cout << "--------受到治疗---------" << std::endl;
		std::cout << "当前生命：" << _hp << std::endl;
		result = true;
		break;
	case 6:		//蓝药水
		result = true;
		break;
	case 7:		//红宝石
		_hp += obj.getAttr();
		std::cout << "--------受到治疗---------" << std::endl;
		std::cout << "当前生命：" << _hp << std::endl;
		result = true;
		break;
	case 8:		//蓝宝石
		result = true;
		break;
	case 9:		//幸运金币
		break;
	default:
		result = false;
		break;
	}

	return result;
}

//与背景地图进行交互，返回bool值表示是否可移动到该地图上去，true表示可移动
bool role::interaction(backMap &obj)
{
	bool result = false;
	switch (obj.getSubType())
	{
	case 1:		//如果是墙壁
		result = false;
		break;
	case 2:		//如果是可行走区域
		result = true;
		break;
	default:
		result = false;
		break;
	}

	return result;

}

//与怪物类型的标志物交互，返回bool值表示是否能打败怪物并移动到怪物的位置处，true表示能打赢并可移动到怪物所在的位置
bool role::interaction(monster &obj)
{
	std::cout << "--------PKbegin---------" << std::endl;
	std::cout << "怪物血量：" << obj.getHp() << "\t" << "携带经验：" << obj.getCarryExp() << std::endl;
	std::cout << "角色血量：" << _hp << "\t" << "当前等级：" << _level << "\t" << "当前经验：" << _exp << std::endl;
	bool result = false;
	double t1, damage;
	if (_attack > 1.05 * obj.getDefense())
	{
		t1 = 1.0 * obj.getHp() / (_attack - obj.getDefense()) / _attackSpeed ;
	}
	else
	{
		t1 = 1.0 * obj.getHp() / (_attack * 0.05) / _attackSpeed;
	}
	
	if (obj.getAttack() > 1.1* _defense)
	{
		damage = 1.0 * (obj.getAttack() - _defense) * obj.getAttackSpeed() * t1;
	}
	else
	{
		damage = 0.1 * obj.getAttack();
	}

	if (_hp > damage)
	{
		_hp -= static_cast<int>(damage);
		_exp += obj.getCarryExp();
		result = true;
	}
	else
	{
		//角色阵亡，游戏结束，此处调用游戏结束函数
		_hp = 0;
		//reLoadMapData(0);
		result = false;
		
	}

	std::cout << "-------PKout--------" << std::endl;
	std::cout << "角色血量：" << _hp << std::endl;
	if (!_hp)
	{
		std::cout << "=========GAME OVER==========" << std::endl;
		std::cout << "=                          =" << std::endl;
		std::cout << "=          你挂了          =" << std::endl;
		std::cout << "=                          =" << std::endl;
		std::cout << "============================" << std::endl;
		MessageBox(NULL, _T("游戏结束"), _T("游戏结束"), 1);
		exit(0);
	}

	return result;
}

bool role::checklevelup()
{
	bool result = false;
	if (_level < MAXLEVEL)
	{
		while (_exp >= _levelUpInfo[ _level - 1 ].needExp)
		{
			result = true;
			_exp -= _levelUpInfo[_level - 1].needExp;
			
			_hp += _levelUpInfo[_level - 1].addHp;
			_attack += _levelUpInfo[_level - 1].addAttack;
			_defense += _levelUpInfo[_level - 1].addDefense;

			_level++;
		}
	}

	return result;
	
}