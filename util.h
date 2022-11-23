#pragma once
#include <graphics.h>

#define WIN_HEIGHT 900 //窗口高度
#define WIN_WIDTH 900   //窗口宽度


static int score; //得分
static bool state; //游戏进行状态
static int myLevel;//我方小鸡的等级
class utils
{
public:
	static IMAGE enemy_chicken[5]; //敌方小鸡的图片
	static IMAGE player[5]; //我方小鸡的图片
	static IMAGE im_bk;
	static void init() //初始化
	{
		TCHAR filename[40];
		for (int i = 0; i < 5; i++)
		{
			_stprintf_s(filename, _T("./images/enemychicken/chicken%d.png"), i);
			loadimage(&enemy_chicken[i], filename);
		}
		for (int i = 0; i < 5; i++)
		{
			_stprintf_s(filename, _T("./images/mychicken/chicken%d.png"), i);
			loadimage(&enemy_chicken[i], filename);
		}
		loadimage(&im_bk,_T("./images/jpg"));
		score=0;
		state=true;
		myLevel=0;
	}
};
