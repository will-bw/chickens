#pragma once
#include "object.h"

class chicken : public object
{
public:
	chicken() = default;

	chicken(IMAGE& image, int x, int y, int isRight,int level): object(image, x, y)
	{
		this->level = level;
		this->isRight = isRight;
	}
	void move();
public:
	int isRight = 0;//方向是否向右
};
