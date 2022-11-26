#pragma once
#include <graphics.h>
#include "MyChicken.h"
#include "EnemyChicken.h"
#include<vector>
using namespace std;


static bool state; //游戏进行状态，while循环结束标志
static bool isover=false;//游戏结束标志
static bool win=false;//游戏结果，false为输
static IMAGE enemy_chicken[2][5]; //敌方小鸡的图片
static IMAGE player[2][4]; //我方小鸡的图片
static IMAGE nums[5];//等级的图片
static IMAGE im_bk;//背景图片
static vector<EnemyChicken> enemys;//敌方小鸡

static int flush_count=0;//用于敌方小鸡的生成

void init();//内容初始化
void draw(EnemyChicken& obj);//绘制小鸡
void draw(MyChicken& obj);
void draw();//批量绘制敌方小鸡
void enemy_move();//敌方小鸡移动
void update(MyChicken& me);//更新信息
void crash_check(MyChicken& me);//碰撞判定
void create_enemy();//敌方小鸡生成
void state_check(MyChicken& me);//状态检测
void gameover();//结束处理