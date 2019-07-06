#pragma once
#include "common.h"
#include "item.h"
#include "backMap.h"
#include "monster.h"
#include "reLoadMapData.h"


struct levelupReward
{
	int needExp;
	int addHp;
	int addAttack;
	int addDefense;
};
typedef struct levelupReward levelUp;


class role
{
	int _hp;		//����
	int _attack;	//��ɫ����
	int _defense;	//��ɫ����
	int _curX;		//��ɫ��ǰx����
	int _curY;		//��ɫ��ǰy����
	std::string _name;	//��ɫ����
	int _type;			//��ɫ����id
	int _tier;			//��ɫ����һ��
	int _yellowKey;		//��ɫԿ��ӵ������
	int _attackSpeed;	//����
	int _exp;			//��ɫ��ǰ����
	int _level;			//��ɫ��ǰ�ȼ�
	int _blueKey;		//��ɫԿ��ӵ������
	levelUp _levelUpInfo[MAXLEVEL];		//���������辭���Լ�������������

public:
	role();
	//role(int hp, int attack, int defense, int curx, int cury, std::string name, int type);
	~role();

	int getHp();
	void setHp(int hp);

	int getAttack();
	void setAttack(int attack);

	int getDefense();
	void setDefense(int defense);

	int getCurX();
	void setCurX(int curx);

	int getCurY();
	void setCurY(int cury);

	std::string getName();
	void setName(std::string name);

	int getType();
	void setType(int type);

	int getTier();
	void setTier(int tier);

	int getYellowKey();
	void setYellowKey(int ykey);

	int getBlueKey();
	void setBlueKey(int bkey);

	int getAttackSpeed();
	void setAttackSpeed(int attackspeed);

	int getExp();
	void setExp(int exp);

	int getLevel();
	void setLevel(int level);


	//��������͵ı�־�ｻ������,����boolֵ��ʾ�Ƿ����ƶ�����־����ȥ��true��ʾ���ƶ�����־����, ischangefloor������־�Ƿ����˲����仯1��ʾ����һ�㣬-1��ʾ����һ�㣬0��ʾ�ޱ仯
	bool interaction(item &obj, int &isChangeFloor);

	//�뱳����ͼ���н���������boolֵ��ʾ�Ƿ���ƶ����õ�ͼ��ȥ��true��ʾ���ƶ�
	bool interaction(backMap &obj);

	//��������͵ı�־�ｻ��������boolֵ��ʾ�Ƿ��ܴ�ܹ��ﲢ�ƶ��������λ�ô���true��ʾ�ܴ�Ӯ�����ƶ����������ڵ�λ��
	bool interaction(monster &obj);

	//�����Ҿ����Ƿ��㹻����������true��ʾ������������false��ʾ��������
	bool checklevelup();

};

