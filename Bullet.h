#pragma once
#include "object.h"
class Bullet
{
public:
	Bullet(double x,double y,double speed_x,double speed_y)
	{
		this->x = x;
		this->y = y;
		this->width=BULLET_WIDTH;
		this->height=BULLET_HEIGHT;
		this->speed_x=speed_x;
		this->speed_y=speed_y;
	}
	void move();
	bool intersect(object& object);
	int width;
	int height;
	double x;
	double y;
	double speed_x;
	double speed_y;
	double g=0.5;
	bool isAlive=true;
};
