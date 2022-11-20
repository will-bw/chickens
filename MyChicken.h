#pragma once
#include "chicken.h"
class MyChicken :public chicken
{
public:
	MyChicken(IMAGE image,int x,int y):chicken(image,x,y){}
	void move();
private:
	int life=10;
};
