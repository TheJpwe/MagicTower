#pragma once
#include "common.h"
#include "myMagicTower.h"


//登录函数
//显示当前有哪些角色，同时玩家也可新创建角色。
//函数返回玩家选择的角色id
//此函数没有角色名查重检查

int login(int *isnew);