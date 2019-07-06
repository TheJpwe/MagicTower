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
	case 1:		//←

		if (marker[x][y-1])
		{
			//如果有标志物则跟标志物互动
			if (marker[x][y-1]>=1000)
			{
				//说明标志物是道具类型
				item tmpitem(marker[x][y - 1]);
				if (Role.interaction(tmpitem,result))
				{
					if (!result)	//如果层数没有变化
					{
						marker[x][y] = 0;

						y--;

						marker[x][y] = 1;
					}
					
				}
			}
			else if (marker[x][y-1]>=100)
			{
				//说明标志物是地图背景类型
			}
			else if (marker[x][y-1]>=10)
			{
				//说明标志物是怪物类型
				monster tmpmonster(marker[x][y - 1]);
				if (Role.interaction(tmpmonster))
				{
					marker[x][y] = 0;

					y--;

					marker[x][y] = 1;

					//打败怪物获得了经验，此处需要判断是否升级
					if (Role.checklevelup())
					{
						std::cout << "==============角色升级！==============" << std::endl;
						std::cout << "角色生命:" << Role.getHp() << "\t" << "当前等级：" << Role.getLevel() << "\t" << "当前经验：" << Role.getExp() << std::endl;
					}

				}
			}
		}
		else
		{
			//如果没有标志物则与地图背景互动，判断是否可移动
			backMap tmpbackmap(map[x][y - 1]);
			if (Role.interaction(tmpbackmap))
			{
				marker[x][y] = 0;

				y--;

				marker[x][y] = 1;

			}
		}

		break;
	case 2:		//↑

		if (marker[x-1][y])
		{
			//如果有标志物则跟标志物互动
			if (marker[x-1][y] >= 1000)
			{
				//说明标志物是道具类型
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
				//说明标志物是地图背景类型
			}
			else if (marker[x-1][y] >= 10)
			{
				//说明标志物是怪物类型
				monster tmpmonster(marker[x-1][y]);
				if (Role.interaction(tmpmonster))
				{
					marker[x][y] = 0;

					x--;

					marker[x][y] = 1;

					//打败怪物获得了经验，此处需要判断是否升级
					if (Role.checklevelup())
					{
						std::cout << "==============角色升级！==============" << std::endl;
						std::cout << "角色生命:" << Role.getHp() << "\t" << "当前等级：" << Role.getLevel() << "\t" << "当前经验：" << Role.getExp() << std::endl;
					}
				}
			}
		}
		else
		{
			//如果没有标志物则与地图背景互动，判断是否可移动
			backMap tmpbackmap(map[x-1][y]);
			if (Role.interaction(tmpbackmap))
			{
				marker[x][y] = 0;

				x--;

				marker[x][y] = 1;

			}
		}

		break;
	case 3:		//→


		if (marker[x][y + 1])
		{
			//如果有标志物则跟标志物互动
			if (marker[x][y + 1] >= 1000)
			{
				//说明标志物是道具类型
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
				//说明标志物是地图背景类型
			}
			else if (marker[x][y + 1] >= 10)
			{
				//说明标志物是怪物类型
				monster tmpmonster(marker[x][y + 1]);
				if (Role.interaction(tmpmonster))
				{
					marker[x][y] = 0;

					y++;

					marker[x][y] = 1;

					//打败怪物获得了经验，此处需要判断是否升级
					if (Role.checklevelup())
					{
						std::cout << "==============角色升级！==============" << std::endl;
						std::cout << "角色生命:" << Role.getHp() << "\t" << "当前等级：" << Role.getLevel() << "\t" << "当前经验：" << Role.getExp() << std::endl;
					}
				}
			}
		}
		else
		{
			//如果没有标志物则与地图背景互动，判断是否可移动
			backMap tmpbackmap(map[x][y + 1]);
			if (Role.interaction(tmpbackmap))
			{
				marker[x][y] = 0;

				y++;

				marker[x][y] = 1;

			}
		}

		break;
	case 4:		//↓


		if (marker[x+1][y])
		{
			//如果有标志物则跟标志物互动
			if (marker[x+1][y] >= 1000)
			{
				//说明标志物是道具类型
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
				//说明标志物是地图背景类型
			}
			else if (marker[x+1][y] >= 10)
			{
				//说明标志物是怪物类型
				monster tmpmonster(marker[x+1][y]);
				if (Role.interaction(tmpmonster))
				{
					marker[x][y] = 0;

					x++;

					marker[x][y] = 1;

					//打败怪物获得了经验，此处需要判断是否升级
					if (Role.checklevelup())
					{
						std::cout << "==============角色升级！==============" << std::endl;
						std::cout << "角色生命:" << Role.getHp() << "\t" << "当前等级：" << Role.getLevel() << "\t" << "当前经验：" << Role.getExp() << std::endl;
					}

				}
			}
		}
		else
		{
			//如果没有标志物则与地图背景互动，判断是否可移动
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