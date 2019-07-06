#include "login.h"

int login(int *isnew)
{
	std::string rolename;

	std::ifstream rolefile("data\\role.txt");

	int cnt = 0;	//��¼��ǰ�м�����ɫ��¼

	if (!rolefile)
	{
		std::cerr << "�򿪡�role.txt���ļ�ʧ��" << std::endl;
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
	std::cout << "0:����һ���½�ɫ" << std::endl;


	int select;
	std::cout << "�����������ѡ����Ӧ��ɫ������Ϸ��" << std::endl;

	std::cin >> select;

	while (select > cnt)
	{
		std::cout << "������Ч�Ľ�ɫ��ţ�" << std::endl;
		std::cin >> select;
	}



	if (!select)
	{
		std::ofstream rolefile("data\\role.txt", std::ios_base::app);

		if (!rolefile)
		{
			std::cerr << "�򿪡�role.txt���ļ�ʧ��" << std::endl;
		}
		else
		{
			std::cout << "�������½�ɫ����" << std::endl;
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