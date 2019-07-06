#include "login.h"

int login(int *isnew)
{
	std::string rolename;

	std::ifstream rolefile("data\\role.txt");

	int cnt = 0;	//记录当前有几个角色记录

	if (!rolefile)
	{
		std::cerr << "打开“role.txt”文件失败" << std::endl;
	}
	else
	{

		while (rolefile >> cnt)
		{
			rolefile >> rolename;
			std::cout << cnt << ":" << rolename << std::endl;
		}
	}

	rolefile.close();
	rolefile.clear();

	std::cout << "-------------------------------------" << std::endl;
	std::cout << "0:创建一个新角色" << std::endl;


	int select;
	std::cout << "请输入序号来选择相应角色进入游戏：" << std::endl;

	std::cin >> select;

	while (select > cnt)
	{
		std::cout << "输入有效的角色序号：" << std::endl;
		std::cin >> select;
	}



	if (!select)
	{
		std::ofstream rolefile("data\\role.txt", std::ios_base::app);

		if (!rolefile)
		{
			std::cerr << "打开“role.txt”文件失败" << std::endl;
		}
		else
		{
			std::cout << "请输入新角色名：" << std::endl;
			std::cin >> rolename;
			Role.setName(rolename);
			rolefile << ++cnt << " " << rolename << std::endl;
		}

		rolefile.close();

		*isnew = 1;

		return cnt;

	}

	return select;
}