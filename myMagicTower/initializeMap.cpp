#include "initializeMap.h"

HWND initializeMap(int isnew)
{

	HWND hwnd;
	// »æÍ¼´°¿Ú³õÊ¼»¯
	hwnd = initgraph(SCALE * 16, SCALE * 13, NOCLOSE);
	//initgraph(SCALE * 16, SCALE * 13, SHOWCONSOLE);

	IMAGE tmpImg;
	//loadimage(&baseImg, _T("resources\\magictower.png"), 256 * SCALE / 32, 1216 * SCALE / 32);

	std::string src;
	LPCTSTR str;

	for (int i = 0; i < 13; i++)
	{
		for (int j = 0; j < 16; j++)
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
	src = "µÚ" + std::to_string(Role.getTier()) + "²ã";
	str = src.c_str();
	drawtext(str, &r, DT_CENTER | DT_VCENTER | DT_SINGLELINE);

	r = { 32 * 13, 32 + 6, 32 * 16, 32 * 2 + 6 };
	//str = Role.getName().c_str();
	src = "µÈ¼¶£º" + std::to_string(Role.getLevel());
	str = src.c_str();
	drawtext(str, &r, DT_CENTER | DT_VCENTER | DT_SINGLELINE);

	r = { 32 * 13, 32 * 2 + 6, 32 * 16, 32 * 3 + 6 };
	drawtext(_T("ÉúÃü"), &r, DT_CENTER | DT_VCENTER | DT_SINGLELINE);

	r = { 32 * 13, 32 * 3 + 6, 32 * 16, 32 * 4 + 6 };
	src = std::to_string(Role.getHp());
	str = src.c_str();
	drawtext(str, &r, DT_CENTER | DT_VCENTER | DT_SINGLELINE);

	r = { 32 * 13, 32 * 4 + 6, 32 * 16, 32 * 5 + 6 };
	drawtext(_T("¹¥»÷"), &r, DT_CENTER | DT_VCENTER | DT_SINGLELINE);

	r = { 32 * 13, 32 * 5 + 6, 32 * 16, 32 * 6 + 6 };
	src = std::to_string(Role.getAttack());
	str = src.c_str();
	drawtext(str, &r, DT_CENTER | DT_VCENTER | DT_SINGLELINE);


	r = { 32 * 13, 32 * 6 + 6, 32 * 16, 32 * 7 + 6 };
	drawtext(_T("·ÀÓù"), &r, DT_CENTER | DT_VCENTER | DT_SINGLELINE);

	r = { 32 * 13, 32 * 7 + 6, 32 * 16, 32 * 8 + 6 };
	src = std::to_string(Role.getDefense());
	str = src.c_str();
	drawtext(str, &r, DT_CENTER | DT_VCENTER | DT_SINGLELINE);


	r = { 32 * 13, 32 * 8 + 6, static_cast<int>(32 * 14.5), 32 * 9 + 6 };
	src = "resources\\1001.png";
	str = src.c_str();
	loadimage(&tmpImg, str, 32 * SCALE / 32, 32 * SCALE / 32);
	putimage(32 * 13 + 15, 32 * 8 + 6, &tmpImg);
	//drawtext(_T("»ÆÔ¿³×"), &r, DT_CENTER | DT_VCENTER | DT_SINGLELINE);

	r = { static_cast<int>(32 * 14.5), 32 * 8 + 6, 32 * 16, 32 * 9 + 6 };
	src = std::to_string(Role.getYellowKey());
	str = src.c_str();
	drawtext(str, &r, DT_CENTER | DT_VCENTER | DT_SINGLELINE);

	r = { 32 * 13, 32 * 9 + 6, static_cast<int>(32 * 14.5), 32 * 10 + 6 };
	//drawtext(_T("À¶Ô¿³×"), &r, DT_CENTER | DT_VCENTER | DT_SINGLELINE);
	src = "resources\\1014.png";
	str = src.c_str();
	loadimage(&tmpImg, str, 32 * SCALE / 32, 32 * SCALE / 32);
	putimage(32 * 13 + 15, 32 * 9 + 6, &tmpImg);

	r = { static_cast<int>(32 * 14.5), 32 * 9 + 6, 32 * 16, 32 * 10 + 6 };
	src = std::to_string(Role.getBlueKey());
	str = src.c_str();
	drawtext(str, &r, DT_CENTER | DT_VCENTER | DT_SINGLELINE);

	r = { 32 * 13, 32 * 10 + 6, static_cast<int>(32 * 14.5), 32 * 11 + 6 };
	//drawtext(_T("ºìÔ¿³×"), &r, DT_CENTER | DT_VCENTER | DT_SINGLELINE);
	src = "resources\\1014.png";
	str = src.c_str();
	loadimage(&tmpImg, str, 32 * SCALE / 32, 32 * SCALE / 32);
	putimage(32 * 13 + 15, 32 * 10 + 6, &tmpImg);

	r = { static_cast<int>(32 * 14.5), 32 * 10 + 6, 32 * 16, 32 * 11 + 6 };
	src = std::to_string(Role.getBlueKey());
	str = src.c_str();
	drawtext(str, &r, DT_CENTER | DT_VCENTER | DT_SINGLELINE);

	r = { 32 * 13, 32 * 11 + 16, 32 * 16, 32 * 12 + 16 };
	drawtext(_T("Esc±£´æ²¢ÍË³ö"), &r, DT_CENTER | DT_WORDBREAK);




	return hwnd;
}