#pragma once
#include<graphics.h>
#include<conio.h>
#include<time.h>
#define WIN_HEIGHT 800 //窗口高度
#define WIN_WIDTH 1600   //窗口宽度
class object
{
public:
	object(IMAGE& image, int x, int y)
	{
		this->image = image;
		this->x = x;
		this->y = y;
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
