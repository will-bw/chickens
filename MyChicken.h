#pragma once
#include "chicken.h"
#include "Bullet.h"
class MyChicken :public chicken
{
public:
	MyChicken() = default;

	MyChicken(IMAGE image,int x,int y ,int isright ,int lev):chicken(image,x,y,isright,lev)
	{
		switch (lev)
		{
		case 0:
			width = 30;
			height = 30;
			break;
		case 1:
			width = 50;
			height = 50;
			break;
		case 2:
			width = 70;
			height = 70;
			break;
		case 3:
			width = 90;
			height = 90;
			break;
		default:
			break;
		}
	}
	void move();
	void set_wh();
public:
	int life=MY_LIFE;
	int score = 0;
	int bullet_cnt=0;//还剩的子弹数量
	vector<Bullet> bullets;

};
