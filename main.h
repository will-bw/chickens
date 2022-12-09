#pragma once
#include <graphics.h>
#include "MyChicken.h"
#include "EnemyChicken.h"
#include "Boss.h"
#include "Bullet.h"
#pragma comment(lib,"Winmm.lib")


static int state; //游戏进行状态，while循环结束标志,0为结束，1是开始界面，2是没有boss，3是出现boss,4是结束界面
static bool isover=false;//游戏结束标志
static bool win=false;//游戏结果，false为输
static IMAGE enemy_chicken[2][5]; //敌方小鸡的图片
static IMAGE player[2][4]; //我方小鸡的图片
static IMAGE nums[5];//等级的图片
static IMAGE im_bk;//背景图片
static IMAGE im_boss;//boss图片
static IMAGE im_myBullet;//子弹图片
static IMAGE im_bossBullet;//子弹图片
static IMAGE im_win;//胜利图片
static IMAGE im_lose;//失败图片
static IMAGE im_start;//开始界面
static vector<EnemyChicken> enemys;//敌方小鸡
static MyChicken me;//我方小鸡
static Boss boss;//boss
static vector<Bullet> boss_bullets;//boss子弹
static vector<Bullet> my_bullets;//我方子弹

static int flush_count=0;//用于敌方小鸡的生成

void init();//内容初始化
void draw(EnemyChicken& obj);//绘制小鸡
void draw(MyChicken& obj);//绘制我方小鸡
void draw();//批量绘制敌方小鸡
void enemy_move();//敌方小鸡移动
void update();//更新信息
void crash_check();//碰撞判定
void create_enemy();//敌方小鸡生成
void state_check();//状态检测
void gameover();//结束处理
void text_show();
void bullet_show(MyChicken& me_chicken);
void bullet_show(Boss& boss_bu);
void shoot(MyChicken& mc);
void shoot(Boss& b);
