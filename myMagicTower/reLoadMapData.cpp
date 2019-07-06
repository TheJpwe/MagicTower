#include "reLoadMapData.h"


//����ɫ����������߲�ʱ����������map��marker���ݣ���Ҫ���ݽ�ɫ���ڲ������������


void reLoadMapData(int floor)
{
	//��������map����
	std::string src;
	src = "data\\maps\\map_" + std::to_string(Role.getTier()) + ".txt";

	std::ifstream infile(src);

	if (!infile)
	{
		std::cerr << "��'map'�ļ�ʧ��" << std::endl;
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

	//Ȼ�󱣴浱ǰ���marker���ݵ�txt�ļ���ע��Ҫ����¥�����͵ı�־��

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
		std::cerr << "��marker'�ļ�ʧ��" << std::endl;
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
		//�����������������Ҫ������ҵ�ǰ��Ϣ��role_record�����ļ�

		src = "data\\records\\role_record" + std::to_string(curRoleId) + ".txt";

		outfile.open(src, std::ofstream::out);
		if (!outfile)
		{
			std::cerr << "��role_record�ļ�ʧ��" << std::endl;
		}
		else
		{
			std::cout << "~~~~~~~~~~~~~~~~~~~��ʼ�洢����~~~~~~~~~~~~~~~~~" << std::endl;
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



	//��������µ�marker����

	src = "data\\maps\\role" + std::to_string(curRoleId) + "_marker_" + std::to_string(Role.getTier()) + ".txt";

	infile.open(src);

	if (!infile)
	{
		//�����ʧ��˵���ļ������ڣ����ȡĬ�ϵı�־������
		src = "data\\maps\\marker_" + std::to_string(Role.getTier()) + ".txt";
		infile.close();
		infile.clear();

		infile.open(src);

		if (!infile)
		{
			std::cerr << "��marker�ļ�ʧ��" << std::endl;
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