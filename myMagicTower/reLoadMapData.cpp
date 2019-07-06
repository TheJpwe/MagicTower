#include "reLoadMapData.h"


//当角色触发进入更高层时，重新载入map和marker数据，需要根据角色所在层的数据来载入


void reLoadMapData(int floor)
{
	//首先载入map数据
	std::string src;
	src = "data\\maps\\map_" + std::to_string(Role.getTier()) + ".txt";

	std::ifstream infile(src);

	if (!infile)
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
				infile >> map[i][j];
			}
		}
	}

	infile.close();
	infile.clear();

	//然后保存当前层的marker数据到txt文件，注意要保留楼梯类型的标志物

	if (floor==1)
	{
		src = "data\\maps\\role" + std::to_string(curRoleId) + "_marker_" + std::to_string(Role.getTier() - 1) + ".txt";
	}
	else if (floor == -1)
	{
		src = "data\\maps\\role" + std::to_string(curRoleId) + "_marker_" + std::to_string(Role.getTier() + 1) + ".txt";
	}
	else
	{
		src = "data\\maps\\role" + std::to_string(curRoleId) + "_marker_" + std::to_string(Role.getTier()) + ".txt";
	}

	

	std::ofstream outfile(src, std::ofstream::out);

	if (!outfile)
	{
		std::cerr << "打开marker'文件失败" << std::endl;
	}
	else
	{
		int i, j;
		for ( i = 0; i < 13; i++)
		{
			for ( j = 0; j < 16; j++)
			{
				outfile << marker[i][j] << " ";
			}

			outfile << std::endl;

		}
	}

	outfile.close();
	outfile.clear();

	if (!floor)
	{
		//如果是主动保存则需要保存玩家当前信息至role_record数据文件

		src = "data\\records\\role_record" + std::to_string(curRoleId) + ".txt";

		outfile.open(src, std::ofstream::out);
		if (!outfile)
		{
			std::cerr << "打开role_record文件失败" << std::endl;
		}
		else
		{
			std::cout << "~~~~~~~~~~~~~~~~~~~开始存储数据~~~~~~~~~~~~~~~~~" << std::endl;
			std::cout << curRoleId << " " << Role.getHp() << " " << Role.getAttack() << " " << Role.getDefense() << " " << Role.getName() << std::endl;


			outfile << curRoleId << " ";
			outfile << Role.getHp() << " ";
			outfile << Role.getAttack() << " ";
			outfile << Role.getDefense() << " ";
			outfile << Role.getCurX() << " ";
			outfile << Role.getCurY() << " ";
			outfile << Role.getName() << " ";
			outfile << Role.getType() << " ";
			outfile << Role.getTier() << " ";
			outfile << Role.getAttackSpeed() << " ";
			outfile << Role.getYellowKey() << " ";
			outfile << Role.getBlueKey() << " ";
			outfile << Role.getLevel() << " ";
			outfile << Role.getExp() << " ";
			outfile << std::endl;
		}

		outfile.close();
		outfile.clear();
	}



	//最后载入新的marker数据

	src = "data\\maps\\role" + std::to_string(curRoleId) + "_marker_" + std::to_string(Role.getTier()) + ".txt";

	infile.open(src);

	if (!infile)
	{
		//如果打开失败说明文件不存在，则读取默认的标志物数据
		src = "data\\maps\\marker_" + std::to_string(Role.getTier()) + ".txt";
		infile.close();
		infile.clear();

		infile.open(src);

		if (!infile)
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
					infile >> marker[i][j];
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
				infile >> marker[i][j];
				if (marker[i][j] == 1)
				{
					Role.setCurX(i);
					Role.setCurY(j);
				}
			}
		}
	}

	infile.close();





}