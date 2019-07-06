#include "initializeData.h"



//根据玩家选择的角色初始化各种数据
void initializeData(int isnew)
{
	//初始化角色数据
	if (!isnew)
	{
		//如果不是新创建的角色
		
		int roleid, hp, attack, defense, xsite, ysite, type, tier, attackspeed, ykey, bkey, curlevel, curexp;
		std::string name, src;

		src = "data\\records\\role_record" + std::to_string(curRoleId) + ".txt";
		std::ifstream infile(src);

		if (!infile)
		{
			std::cerr << "打开“role_record”文件失败" << std::endl;
		}
		else
		{
			while (!infile.eof())
			{
				infile >> roleid;
				
				if (roleid == curRoleId)
				{
					infile >> hp >> attack >> defense >> xsite >> ysite >> name >> type >> tier >> attackspeed >> ykey >> bkey >> curlevel >> curexp;
					Role.setHp(hp);
					Role.setAttack(attack);
					Role.setDefense(defense);
					Role.setCurX(xsite);
					Role.setCurY(ysite);
					Role.setName(name);
					Role.setType(type);
					Role.setTier(tier);
					Role.setAttackSpeed(attackspeed);
					Role.setYellowKey(ykey);
					Role.setBlueKey(bkey);
					Role.setLevel(curlevel);
					Role.setExp(curexp);
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

	}//如果是新创建的角色则由role类的默认构造函数初始化

	std::cout << "当前进入游戏的角色名是：" << Role.getName() << std::endl;


	//初始化地形数据
	std::string src;
	src = "data\\maps\\map_" + std::to_string(Role.getTier()) + ".txt";

	std::ifstream mapfile(src);

	if (!mapfile)
	{
		std::cerr << "打开'map'文件失败" << std::endl;
	}
	else
	{
		int i, j;
		for (i = 0; i < 13; i++)
		{
			for (j = 0; j < 16; j++)
			{
				mapfile >> map[i][j];
			}
		}
	}

	mapfile.close();



	//初始化地图上标志物数据


		//如果不是新创建的角色则读取该角色的标志物数据

		src = "data\\maps\\role" + std::to_string(curRoleId) + "_marker_" + std::to_string(Role.getTier()) + ".txt";

		std::ifstream markerfile(src);

		if (!markerfile)
		{
			//如果打开失败说明文件不存在，则读取默认的标志物数据
			src = "data\\maps\\marker_" + std::to_string(Role.getTier()) + ".txt";
			markerfile.close();
			markerfile.clear();

			markerfile.open(src);

			if (!markerfile)
			{
				std::cerr << "打开marker文件失败" << std::endl;
			}
			else
			{
				int i, j;
				for (i = 0; i < 13; i++)
				{
					for (j = 0; j < 16; j++)
					{
						markerfile >> marker[i][j];
						if (marker[i][j] == 1)
						{
							Role.setCurX(i);
							Role.setCurY(j);
						}
					}
				}
			}
			


		}
		else
		{
			int i, j;
			for (i = 0; i < 13; i++)
			{
				for (j = 0; j < 16; j++)
				{
					markerfile >> marker[i][j];
					if (marker[i][j] == 1)
					{
						Role.setCurX(i);
						Role.setCurY(j);
					}
				}
			}
		}

		markerfile.close();


}