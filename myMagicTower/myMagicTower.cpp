#include "myMagicTower.h"

//全局变量定义
//主函数
int SCALE = 32;	//图片原始大小32*32，如果需要放大只能是32的整数倍
int map[13][16];	//地图数据，0表示墙，不可通行，1表示可通行区域
int marker[13][16];		//地图上放置物数据，0表示无放置物
class role Role;	//主角
int curRoleId;	//当前角色id


//用户键盘输入函数
int keyBoard();	//可用↑↓←→输入，也可使用wasd输入


int main()
{
	//判断是否新建角色
	int isNew = 0;

	//获得进入游戏的角色id
	curRoleId = login(&isNew);

	//根据角色id初始化游戏所需数据
	initializeData(isNew);

	HWND hwnd;
	hwnd = initializeMap(isNew);

	//监听键盘输入执行相应操作
	getchar();	//清空输入缓存

	do
	{
		int floor = 0;	//移动后层数是否变化了的标志
		switch (keyBoard())
		{
		case 1:	//向左移动
			floor = move(1);
			if (floor)	//判断是否进入了楼梯切换了层数
			{
				reLoadMapData(floor);
			}
			reDrawMap();
			break;
		case 2:	//向上移动
			floor = move(2);
			if (floor)	//判断是否进入了楼梯切换了层数
			{
				reLoadMapData(floor);
			}
			reDrawMap();
			break;
		case 3:	//向右移动
			floor = move(3);
			if (floor)	//判断是否进入了楼梯切换了层数
			{
				reLoadMapData(floor);
			}
			reDrawMap();
			break;
		case 4:	//向下移动
			floor = move(4);
			if (floor)	//判断是否进入了楼梯切换了层数
			{
				reLoadMapData(floor);
			}
			reDrawMap();
			break;
		case -1:	//esc
			//Role.setYellowKey(5);
			reLoadMapData(0);
			MessageBox(hwnd, _T("保存成功"), _T("保存游戏"), 1);
			exit(0);
			break;
		default:
			
			break;
		}



	} while (true);
	int i;
	closegraph();
	return 0;
}


int keyBoard()
{
	int userkey;
	userkey = _getch();
	//std::cout << userkey << std::endl;
	if (userkey == 224)
	{
		userkey = _getch();
		switch (userkey)
		{
		case 75:	//←
			return 1;
			break;
		case 72:	//↑
			return 2;
			break;
		case 77:	//→
			return 3;
			break;
		case 80:	//↓
			return 4;
			break;
		default:
			return 0;
			break;
		}
	}
	else
	{
		switch (userkey)
		{
		case 97:	//←
			return 1;
			break;
		case 119:	//↑
			return 2;
			break;
		case 100:	//→
			return 3;
			break;
		case 115:	//↓
			return 4;
			break;
		case 27:	//ESC
			return -1;
			break;
		default:
			return 0;
			break;
		}
	}
	


}