#include "myMagicTower.h"

//ȫ�ֱ�������
//������
int SCALE = 32;	//ͼƬԭʼ��С32*32�������Ҫ�Ŵ�ֻ����32��������
int map[13][16];	//��ͼ���ݣ�0��ʾǽ������ͨ�У�1��ʾ��ͨ������
int marker[13][16];		//��ͼ�Ϸ��������ݣ�0��ʾ�޷�����
class role Role;	//����
int curRoleId;	//��ǰ��ɫid


//�û��������뺯��
int keyBoard();	//���á����������룬Ҳ��ʹ��wasd����


int main()
{
	//�ж��Ƿ��½���ɫ
	int isNew = 0;

	//��ý�����Ϸ�Ľ�ɫid
	curRoleId = login(&isNew);

	//���ݽ�ɫid��ʼ����Ϸ��������
	initializeData(isNew);

	HWND hwnd;
	hwnd = initializeMap(isNew);

	//������������ִ����Ӧ����
	getchar();	//������뻺��

	do
	{
		int floor = 0;	//�ƶ�������Ƿ�仯�˵ı�־
		switch (keyBoard())
		{
		case 1:	//�����ƶ�
			floor = move(1);
			if (floor)	//�ж��Ƿ������¥���л��˲���
			{
				reLoadMapData(floor);
			}
			reDrawMap();
			break;
		case 2:	//�����ƶ�
			floor = move(2);
			if (floor)	//�ж��Ƿ������¥���л��˲���
			{
				reLoadMapData(floor);
			}
			reDrawMap();
			break;
		case 3:	//�����ƶ�
			floor = move(3);
			if (floor)	//�ж��Ƿ������¥���л��˲���
			{
				reLoadMapData(floor);
			}
			reDrawMap();
			break;
		case 4:	//�����ƶ�
			floor = move(4);
			if (floor)	//�ж��Ƿ������¥���л��˲���
			{
				reLoadMapData(floor);
			}
			reDrawMap();
			break;
		case -1:	//esc
			//Role.setYellowKey(5);
			reLoadMapData(0);
			MessageBox(hwnd, _T("����ɹ�"), _T("������Ϸ"), 1);
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
		case 75:	//��
			return 1;
			break;
		case 72:	//��
			return 2;
			break;
		case 77:	//��
			return 3;
			break;
		case 80:	//��
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
		case 97:	//��
			return 1;
			break;
		case 119:	//��
			return 2;
			break;
		case 100:	//��
			return 3;
			break;
		case 115:	//��
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