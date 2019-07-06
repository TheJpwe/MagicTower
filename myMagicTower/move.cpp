#include "move.h"


int move(int direction)
{
	int x, y;
	x = Role.getCurX();
	y = Role.getCurY();

	int result = 0;
	//std::cout << x << " " << y << std::endl;

	switch (direction)
	{
	case 1:		//��

		if (marker[x][y-1])
		{
			//����б�־�������־�ﻥ��
			if (marker[x][y-1]>=1000)
			{
				//˵����־���ǵ�������
				item tmpitem(marker[x][y - 1]);
				if (Role.interaction(tmpitem,result))
				{
					if (!result)	//�������û�б仯
					{
						marker[x][y] = 0;

						y--;

						marker[x][y] = 1;
					}
					
				}
			}
			else if (marker[x][y-1]>=100)
			{
				//˵����־���ǵ�ͼ��������
			}
			else if (marker[x][y-1]>=10)
			{
				//˵����־���ǹ�������
				monster tmpmonster(marker[x][y - 1]);
				if (Role.interaction(tmpmonster))
				{
					marker[x][y] = 0;

					y--;

					marker[x][y] = 1;

					//��ܹ������˾��飬�˴���Ҫ�ж��Ƿ�����
					if (Role.checklevelup())
					{
						std::cout << "==============��ɫ������==============" << std::endl;
						std::cout << "��ɫ����:" << Role.getHp() << "\t" << "��ǰ�ȼ���" << Role.getLevel() << "\t" << "��ǰ���飺" << Role.getExp() << std::endl;
					}

				}
			}
		}
		else
		{
			//���û�б�־�������ͼ�����������ж��Ƿ���ƶ�
			backMap tmpbackmap(map[x][y - 1]);
			if (Role.interaction(tmpbackmap))
			{
				marker[x][y] = 0;

				y--;

				marker[x][y] = 1;

			}
		}

		break;
	case 2:		//��

		if (marker[x-1][y])
		{
			//����б�־�������־�ﻥ��
			if (marker[x-1][y] >= 1000)
			{
				//˵����־���ǵ�������
				item tmpitem(marker[x-1][y]);
				if (Role.interaction(tmpitem, result))
				{
					if (!result)
					{
						marker[x][y] = 0;

						x--;

						marker[x][y] = 1;
					}
					
				}
			}
			else if (marker[x-1][y] >= 100)
			{
				//˵����־���ǵ�ͼ��������
			}
			else if (marker[x-1][y] >= 10)
			{
				//˵����־���ǹ�������
				monster tmpmonster(marker[x-1][y]);
				if (Role.interaction(tmpmonster))
				{
					marker[x][y] = 0;

					x--;

					marker[x][y] = 1;

					//��ܹ������˾��飬�˴���Ҫ�ж��Ƿ�����
					if (Role.checklevelup())
					{
						std::cout << "==============��ɫ������==============" << std::endl;
						std::cout << "��ɫ����:" << Role.getHp() << "\t" << "��ǰ�ȼ���" << Role.getLevel() << "\t" << "��ǰ���飺" << Role.getExp() << std::endl;
					}
				}
			}
		}
		else
		{
			//���û�б�־�������ͼ�����������ж��Ƿ���ƶ�
			backMap tmpbackmap(map[x-1][y]);
			if (Role.interaction(tmpbackmap))
			{
				marker[x][y] = 0;

				x--;

				marker[x][y] = 1;

			}
		}

		break;
	case 3:		//��


		if (marker[x][y + 1])
		{
			//����б�־�������־�ﻥ��
			if (marker[x][y + 1] >= 1000)
			{
				//˵����־���ǵ�������
				item tmpitem(marker[x][y + 1]);
				if (Role.interaction(tmpitem, result))
				{
					if (!result)
					{
						marker[x][y] = 0;

						y++;

						marker[x][y] = 1;
					}
					
				}
			}
			else if (marker[x][y + 1] >= 100)
			{
				//˵����־���ǵ�ͼ��������
			}
			else if (marker[x][y + 1] >= 10)
			{
				//˵����־���ǹ�������
				monster tmpmonster(marker[x][y + 1]);
				if (Role.interaction(tmpmonster))
				{
					marker[x][y] = 0;

					y++;

					marker[x][y] = 1;

					//��ܹ������˾��飬�˴���Ҫ�ж��Ƿ�����
					if (Role.checklevelup())
					{
						std::cout << "==============��ɫ������==============" << std::endl;
						std::cout << "��ɫ����:" << Role.getHp() << "\t" << "��ǰ�ȼ���" << Role.getLevel() << "\t" << "��ǰ���飺" << Role.getExp() << std::endl;
					}
				}
			}
		}
		else
		{
			//���û�б�־�������ͼ�����������ж��Ƿ���ƶ�
			backMap tmpbackmap(map[x][y + 1]);
			if (Role.interaction(tmpbackmap))
			{
				marker[x][y] = 0;

				y++;

				marker[x][y] = 1;

			}
		}

		break;
	case 4:		//��


		if (marker[x+1][y])
		{
			//����б�־�������־�ﻥ��
			if (marker[x+1][y] >= 1000)
			{
				//˵����־���ǵ�������
				item tmpitem(marker[x+1][y]);
				if (Role.interaction(tmpitem, result))
				{
					if (!result)
					{
						marker[x][y] = 0;

						x++;

						marker[x][y] = 1;
					}
					
				}
			}
			else if (marker[x+1][y] >= 100)
			{
				//˵����־���ǵ�ͼ��������
			}
			else if (marker[x+1][y] >= 10)
			{
				//˵����־���ǹ�������
				monster tmpmonster(marker[x+1][y]);
				if (Role.interaction(tmpmonster))
				{
					marker[x][y] = 0;

					x++;

					marker[x][y] = 1;

					//��ܹ������˾��飬�˴���Ҫ�ж��Ƿ�����
					if (Role.checklevelup())
					{
						std::cout << "==============��ɫ������==============" << std::endl;
						std::cout << "��ɫ����:" << Role.getHp() << "\t" << "��ǰ�ȼ���" << Role.getLevel() << "\t" << "��ǰ���飺" << Role.getExp() << std::endl;
					}

				}
			}
		}
		else
		{
			//���û�б�־�������ͼ�����������ж��Ƿ���ƶ�
			backMap tmpbackmap(map[x+1][y]);
			if (Role.interaction(tmpbackmap))
			{
				marker[x][y] = 0;

				x++;

				marker[x][y] = 1;

			}
		}

		break;
	default:
		break;
	}

	Role.setCurX(x);
	Role.setCurY(y);

	return result;


}