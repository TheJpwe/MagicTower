#include "role.h"

//
//int _hp;	//����
//int _attack;	//��ɫ����
//int _defense;	//��ɫ����
//int _curX;	//��ɫ��ǰx����
//int _curY;	//��ɫ��ǰy����
//std::string _name;	//��ɫ����
//int _type;	//��ɫ����id


role::role()
{
	std::ifstream infile("data\\item_proto.txt");
	std::string sTmp;
	if (!infile)
	{
		std::cerr << "�򿪡�item_proto���ļ�ʧ��" << std::endl;

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
		std::cerr << "�򿪡�role_level_up���ļ�ʧ��" << std::endl;

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



//��������͵ı�־�ｻ������,����boolֵ��ʾ�Ƿ����ƶ�����־����ȥ��true��ʾ���ƶ�����־����
bool role::interaction(item &obj, int &isChangeFloor)
{
	bool result = false;
	int cnt,tmp;
	switch (obj.getSubType())
	{
	case 1:		//���ϵ�¥��
		//���������һ��ĺ���
		tmp = Role.getTier();
		Role.setTier(++tmp);
		isChangeFloor = 1;
		result = true;
		break;
	case 2:		//���µ�¥��
		//���������һ��ĺ���
		tmp = Role.getTier();
		Role.setTier(--tmp);
		isChangeFloor = -1;
		result = true;
		break;
	case 3:		//������
		
		switch (obj.getAttr())
		{
		case 1:		//����
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
			std::cout << "��ǰӵ�л�Կ�ף�" << Role.getYellowKey() << std::endl;
			break;
		case 2:		//����
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
			std::cout << "��ǰӵ����Կ�ף�" << Role.getBlueKey() << std::endl;
			break;
		default:
			break;
		}
		
		break;
	case 4:		//Կ��
		switch (obj.getAttr())
		{
		case 1:		//��Կ��
			cnt = Role.getYellowKey();
			Role.setYellowKey(++cnt);
			result = true;

			std::cout << "��ǰӵ�л�Կ�ף�" << Role.getYellowKey() << std::endl;

			break;
		case 2:		//��Կ��
			cnt = Role.getBlueKey();
			Role.setBlueKey(++cnt);
			result = true;

			std::cout << "��ǰӵ����Կ�ף�" << Role.getBlueKey() << std::endl;
			break;
		default:
			break;
		}

	
		break;
	case 5:		//��ҩˮ
		_hp += obj.getAttr();
		std::cout << "--------�ܵ�����---------" << std::endl;
		std::cout << "��ǰ������" << _hp << std::endl;
		result = true;
		break;
	case 6:		//��ҩˮ
		result = true;
		break;
	case 7:		//�챦ʯ
		_hp += obj.getAttr();
		std::cout << "--------�ܵ�����---------" << std::endl;
		std::cout << "��ǰ������" << _hp << std::endl;
		result = true;
		break;
	case 8:		//����ʯ
		result = true;
		break;
	case 9:		//���˽��
		break;
	default:
		result = false;
		break;
	}

	return result;
}

//�뱳����ͼ���н���������boolֵ��ʾ�Ƿ���ƶ����õ�ͼ��ȥ��true��ʾ���ƶ�
bool role::interaction(backMap &obj)
{
	bool result = false;
	switch (obj.getSubType())
	{
	case 1:		//�����ǽ��
		result = false;
		break;
	case 2:		//����ǿ���������
		result = true;
		break;
	default:
		result = false;
		break;
	}

	return result;

}

//��������͵ı�־�ｻ��������boolֵ��ʾ�Ƿ��ܴ�ܹ��ﲢ�ƶ��������λ�ô���true��ʾ�ܴ�Ӯ�����ƶ����������ڵ�λ��
bool role::interaction(monster &obj)
{
	std::cout << "--------PKbegin---------" << std::endl;
	std::cout << "����Ѫ����" << obj.getHp() << "\t" << "Я�����飺" << obj.getCarryExp() << std::endl;
	std::cout << "��ɫѪ����" << _hp << "\t" << "��ǰ�ȼ���" << _level << "\t" << "��ǰ���飺" << _exp << std::endl;
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
		//��ɫ��������Ϸ�������˴�������Ϸ��������
		_hp = 0;
		//reLoadMapData(0);
		result = false;
		
	}

	std::cout << "-------PKout--------" << std::endl;
	std::cout << "��ɫѪ����" << _hp << std::endl;
	if (!_hp)
	{
		std::cout << "=========GAME OVER==========" << std::endl;
		std::cout << "=                          =" << std::endl;
		std::cout << "=          �����          =" << std::endl;
		std::cout << "=                          =" << std::endl;
		std::cout << "============================" << std::endl;
		MessageBox(NULL, _T("��Ϸ����"), _T("��Ϸ����"), 1);
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