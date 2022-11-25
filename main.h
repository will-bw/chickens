#pragma once
#include <graphics.h>
#include "MyChicken.h"
#include "EnemyChicken.h"

static bool state; //游戏进行状态
static IMAGE enemy_chicken[2][4]; //敌方小鸡的图片
static IMAGE player[2][4]; //我方小鸡的图片
static IMAGE nums[4];
static IMAGE im_bk;

void init();
void draw(object& obj);
void me_update(MyChicken& me);