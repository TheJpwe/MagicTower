#include "initializeData.h"



//�������ѡ��Ľ�ɫ��ʼ����������
void initializeData(int isnew)
{
	//��ʼ����ɫ����
	if (!isnew)
	{
		//��������´����Ľ�ɫ
		
		int roleid, hp, attack, defense, xsite, ysite, type, tier, attackspeed, ykey, bkey, curlevel, curexp;
		std::string name, src;

		src = "data\\records\\role_record" + std::to_string(curRoleId) + ".txt";
		std::ifstream infile(src);

		if (!infile)
		{
			std::cerr << "�򿪡�role_record���ļ�ʧ��" << std::endl;
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

	}//������´����Ľ�ɫ����role���Ĭ�Ϲ��캯����ʼ��

	std::cout << "��ǰ������Ϸ�Ľ�ɫ���ǣ�" << Role.getName() << std::endl;


	//��ʼ����������
	std::string src;
	src = "data\\maps\\map_" + std::to_string(Role.getTier()) + ".txt";

	std::ifstream mapfile(src);

	if (!mapfile)
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
				mapfile >> map[i][j];
			}
		}
	}

	mapfile.close();



	//��ʼ����ͼ�ϱ�־������


		//��������´����Ľ�ɫ���ȡ�ý�ɫ�ı�־������

		src = "data\\maps\\role" + std::to_string(curRoleId) + "_marker_" + std::to_string(Role.getTier()) + ".txt";

		std::ifstream markerfile(src);

		if (!markerfile)
		{
			//�����ʧ��˵���ļ������ڣ����ȡĬ�ϵı�־������
			src = "data\\maps\\marker_" + std::to_string(Role.getTier()) + ".txt";
			markerfile.close();
			markerfile.clear();

			markerfile.open(src);

			if (!markerfile)
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