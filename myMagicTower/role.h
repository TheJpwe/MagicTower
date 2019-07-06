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
	int _hp;		//生命
	int _attack;	//角色攻击
	int _defense;	//角色防御
	int _curX;		//角色当前x坐标
	int _curY;		//角色当前y坐标
	std::string _name;	//角色名称
	int _type;			//角色类型id
	int _tier;			//角色在哪一层
	int _yellowKey;		//黄色钥匙拥有数量
	int _attackSpeed;	//攻速
	int _exp;			//角色当前经验
	int _level;			//角色当前等级
	int _blueKey;		//蓝色钥匙拥有数量
	levelUp _levelUpInfo[MAXLEVEL];		//各升级所需经验以及升级奖励属性

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


	//与道具类型的标志物交互函数,返回bool值表示是否能移动到标志物上去。true表示可移动到标志物上, ischangefloor参数标志是否发生了层数变化1表示上了一层，-1表示下了一层，0表示无变化
	bool interaction(item &obj, int &isChangeFloor);

	//与背景地图进行交互，返回bool值表示是否可移动到该地图上去，true表示可移动
	bool interaction(backMap &obj);

	//与怪物类型的标志物交互，返回bool值表示是否能打败怪物并移动到怪物的位置处，true表示能打赢并可移动到怪物所在的位置
	bool interaction(monster &obj);

	//检测玩家经验是否足够升级，返回true表示可升级，返回false表示不可升级
	bool checklevelup();

};

