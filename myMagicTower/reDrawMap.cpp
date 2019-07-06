#include "reDrawMap.h"

void reDrawMap()
{
	//���»���ȫ��ͼ���ݣ�����map���ݺ�marker����
	IMAGE tmpImg;
	std::string src;
	LPCTSTR str;

	for (int i = 0; i < 13; i++)
	{
		for (int j = 0; j < 13; j++)
		{

			
			src = "resources\\" + std::to_string(map[i][j]) + ".png";

			str = src.c_str();

			loadimage(&tmpImg, str, 32 * SCALE / 32, 32 * SCALE / 32);

			putimage(j*SCALE, i*SCALE, &tmpImg);

			if (marker[i][j])
			{
				src = "resources\\" + std::to_string(marker[i][j]) + ".png";

				str = src.c_str();


				loadimage(&tmpImg, str, 32 * SCALE / 32, 32 * SCALE / 32);

				putimage(j*SCALE, i*SCALE, &tmpImg);
			}
			


		}

	}

	setbkmode(OPAQUE);
	setbkcolor(RGB(47, 47, 47));

	RECT r = { 32 * 13, 6, 32 * 16, 38 };
	src = "��" + std::to_string(Role.getTier()) + "��";
	str = src.c_str();
	drawtext(str, &r, DT_CENTER | DT_VCENTER | DT_SINGLELINE);



	r = { 32 * 13, 32 + 6, 32 * 16, 32 * 2 + 6 };
	//str = Role.getName().c_str();
	src = "�ȼ���" + std::to_string(Role.getLevel());
	str = src.c_str();
	drawtext(str, &r, DT_CENTER | DT_VCENTER | DT_SINGLELINE);

	//r = { 32 * 13, 32 * 2 + 6, 32 * 16, 32 * 3 + 6 };
	//drawtext(_T("����"), &r, DT_CENTER | DT_VCENTER | DT_SINGLELINE);


	r = { 32 * 13, 32 * 3 + 6, 32 * 16, 32 * 4 + 6 };
	src = std::to_string(Role.getHp());
	str = src.c_str();
	drawtext(str, &r, DT_CENTER | DT_VCENTER | DT_SINGLELINE);

	//r = { 32 * 13, 32 * 4 + 6, 32 * 16, 32 * 5 + 6 };
	//drawtext(_T("����"), &r, DT_CENTER | DT_VCENTER | DT_SINGLELINE);


	r = { 32 * 13, 32 * 5 + 6, 32 * 16, 32 * 6 + 6 };
	src = std::to_string(Role.getAttack());
	str = src.c_str();
	drawtext(str, &r, DT_CENTER | DT_VCENTER | DT_SINGLELINE);


	//r = { 32 * 13, 32 * 6 + 6, 32 * 16, 32 * 7 + 6 };
	//drawtext(_T("����"), &r, DT_CENTER | DT_VCENTER | DT_SINGLELINE);



	r = { 32 * 13, 32 * 7 + 6, 32 * 16, 32 * 8 + 6 };
	src = std::to_string(Role.getDefense());
	str = src.c_str();
	drawtext(str, &r, DT_CENTER | DT_VCENTER | DT_SINGLELINE);

	//r = { 32 * 13, 32 * 8 + 6, static_cast<int>(32 * 14.5), 32 * 9 + 6 };
	//drawtext(_T("��Կ��"), &r, DT_CENTER | DT_VCENTER | DT_SINGLELINE);


	r = { static_cast<int>(32 * 14.5), 32 * 8 + 6, 32 * 16, 32 * 9 + 6 };
	src = std::to_string(Role.getYellowKey());
	str = src.c_str();
	drawtext(str, &r, DT_CENTER | DT_VCENTER | DT_SINGLELINE);

	//r = { 32 * 13, 32 * 9 + 6, static_cast<int>(32 * 14.5), 32 * 10 + 6 };
	//drawtext(_T("��Կ��"), &r, DT_CENTER | DT_VCENTER | DT_SINGLELINE);


	r = { static_cast<int>(32 * 14.5), 32 * 9 + 6, 32 * 16, 32 * 10 + 6 };
	src = std::to_string(Role.getBlueKey());
	str = src.c_str();
	drawtext(str, &r, DT_CENTER | DT_VCENTER | DT_SINGLELINE);

	//r = { 32 * 13, 32 * 10 + 6, static_cast<int>(32 * 14.5), 32 * 11 + 6 };
	//drawtext(_T("��Կ��"), &r, DT_CENTER | DT_VCENTER | DT_SINGLELINE);


	r = { static_cast<int>(32 * 14.5), 32 * 10 + 6, 32 * 16, 32 * 11 + 6 };
	src = std::to_string(Role.getBlueKey());
	str = src.c_str();
	drawtext(str, &r, DT_CENTER | DT_VCENTER | DT_SINGLELINE);


}