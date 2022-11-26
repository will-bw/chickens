#pragma once
#include "chicken.h"
class MyChicken :public chicken
{
public:
	MyChicken(IMAGE image,int x,int y ,int isright ,int lev):chicken(image,x,y,isright,lev)
	{
	}
	void move();
public:
	int life=10;
	int score = 0;
};
