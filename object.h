#pragma once
#include<graphics.h>
#include<conio.h>
#include<time.h>
#define WIN_HEIGHT 900 //窗口高度
#define WIN_WIDTH 900   //窗口宽度
class object
{
public:
	object(IMAGE& image, int x, int y)
	{
		this->image = image;
		this->x = x;
		this->y = y;
		this->width = image.getwidth();
		this->height = image.getheight();
		//对象的宽度和高度由图片尺寸来定
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
};
