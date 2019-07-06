#pragma once
#include <stdio.h>
#include <stdlib.h>
#include <iostream>
#include <fstream>
#include <graphics.h>
#include <string>
#include <conio.h>

//全局变量声明
extern int SCALE;	//图片原始大小32*32，如果需要放大只能是32的整数倍
extern int map[13][16];	//地图数据，0表示墙，不可通行，1表示可通行区域
extern int marker[13][16];		//地图上放置物数据，0表示无放置物
extern class role Role;	//主角
extern int curRoleId;	//当前角色id
extern constexpr int MAXLEVEL = 50;		//角色最大等级，初始等级为1级