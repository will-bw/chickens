#pragma once
#include<graphics.h>
#include<conio.h>
#include<time.h>
#include<vector>

#define WIN_HEIGHT 800 //窗口高度
#define WIN_WIDTH 1600   //窗口宽度
#define BOSS_LIFE 5	//boss生命值
#define MY_LIFE 10  //我的生命值
#define BULLET_WIDTH 25
#define BULLET_HEIGHT 25

using namespace std;


class object
{
public:
	object() = default;
	object(IMAGE& image, int x, int y)
	{
		this->image = image;
		this->x = x;
		this->y = y;
		this->width=image.getwidth();
		this->height=image.getheight();
	}


	bool intersect(object& object)
	{
		return x <= object.x + object.width && x + width >= object.x && y <= object.y + object.height && y
			+ height >= object.y;
	}

	void move();

public:
	IMAGE image; //贴图
	int x, y; //坐标
	int width, height; //高度宽度
	int level;//等级
	bool isAlive =true;//是否活着
};
