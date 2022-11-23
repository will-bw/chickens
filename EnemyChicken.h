#pragma once

#include"chicken.h"
#include "util.h"

class EnemyChicken : public chicken
{
public:
	EnemyChicken(IMAGE image, bool isRight): chicken(image, 0, 0)
	{
		int x = isRight ? 0 - width1() : WIN_WIDTH;
		set_x(x);
		int a = WIN_HEIGHT / height1();
		int y = (rand() % a) * height1();
		set_y(y);
	}

	void move();
private:
	bool isRight;
	int speed = 4;
};
