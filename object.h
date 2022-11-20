#pragma once
#include<graphics.h>
#include<conio.h>
#include<time.h>
class object
{
public:
	object(IMAGE image, int x, int y)
	{
		this->image = image;
		this->x = x;
		this->y = y;
		this->width = image.getwidth();
		this->height = image.getheight();
		//对象的宽度和高度由图片尺寸来定
	}

	bool intersect(object* object)
	{
		return x <= object->x1() + object->width1() && x + width >= object->x && y <= object->y1() + object->height1() && y
			+ height >= object->y1();
	}

	void move();

	IMAGE image1() const
	{
		return image;
	}

	int x1() const
	{
		return x;
	}

	int y1() const
	{
		return y;
	}

	int width1() const
	{
		return width;
	}

	int height1() const
	{
		return height;
	}

	void set_image(const IMAGE& image)
	{
		this->image = image;
	}

	void set_x(int x)
	{
		this->x = x;
	}

	void set_y(int y)
	{
		this->y = y;
	}

	void set_width(int width)
	{
		this->width = width;
	}

	void set_height(int height)
	{
		this->height = height;
	}

private:
	IMAGE image; //贴图
	int x, y; //坐标
	int width, height; //高度宽度
};
