#pragma once

#include "common.h"
#include "role.h"


//层数变化后重新计算地图数据和地图标志数据，floor参数标志是提升了一层，还是下降了一层
void reLoadMapData(int floor);