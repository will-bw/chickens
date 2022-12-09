#pragma once
#include "chicken.h"
#include "Bullet.h"
class Boss:public chicken
{
public:
	Boss() = default;

	Boss(IMAGE& image, int x, int y, int isRight, int level)
		: chicken(image, x, y, isRight, level)
	{
		if(rand()%2)
			speed_x=1+rand()%8;
		else
			speed_x= -1-rand()%8;
		if(rand()%2)
			speed_y=1+rand()%8;
		else
			speed_y= -1-rand()%8;
	}
	void move();
	void shoot();
	int cnt=0;//刷新次数，作为改变速度的依据
	int shoot_cnt=0;//用于发射子弹
	int speed_x;
	int speed_y;
	int life =BOSS_LIFE;
	vector<Bullet> bullets;
};
