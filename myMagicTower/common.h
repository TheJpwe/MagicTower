#pragma once
#include <stdio.h>
#include <stdlib.h>
#include <iostream>
#include <fstream>
#include <graphics.h>
#include <string>
#include <conio.h>

//ȫ�ֱ�������
extern int SCALE;	//ͼƬԭʼ��С32*32�������Ҫ�Ŵ�ֻ����32��������
extern int map[13][16];	//��ͼ���ݣ�0��ʾǽ������ͨ�У�1��ʾ��ͨ������
extern int marker[13][16];		//��ͼ�Ϸ��������ݣ�0��ʾ�޷�����
extern class role Role;	//����
extern int curRoleId;	//��ǰ��ɫid
extern constexpr int MAXLEVEL = 50;		//��ɫ���ȼ�����ʼ�ȼ�Ϊ1��