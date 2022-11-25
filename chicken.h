#pragma once
#include "object.h"

class chicken : public object
{
public:

	chicken(IMAGE& image, int x, int y, int isRight,int level): object(image, x, y)
	{
		this->level = level;
		this->isRight = isRight;
	}
	void move();
public:
	int isRight = 0;//方向是否向右
	bool isAlive;//是否活着
	int level;//等级
};
