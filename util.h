#pragma once
#include <graphics.h>

#define WIN_HEIGHT 100 //窗口高度
#define WIN_WIDTH 100   //窗口宽度


static int score = 0; //得分
static bool state = true; //游戏进行状态
class util
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
		loadimage(&im_bk,_T("./images/bk.png"));
	}
};
