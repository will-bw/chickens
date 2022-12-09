#pragma once

#include"chicken.h"

class EnemyChicken : public chicken
{
public:
	EnemyChicken(IMAGE image, int x, int y, int isright, int lev): chicken(image, x, y, isright, lev)
	{
		switch (lev)
		{
		case 0:
			width = 20;
			height = 20;
			break;
		case 1:
			width = 30;
			height = 30;
			break;
		case 2:
			width = 50;
			height = 50;
			break;
		case 3:
			width = 70;
			height = 70;
			break;
		case 4:
			width = 90;
			height = 90;
			break;
		default:
			break;
		}
		speed=4+rand()%5;//获得随机速度
	}

	void move();
	int speed;
};
