#pragma once

#include"chicken.h"

class EnemyChicken : public chicken
{
public:
	EnemyChicken(IMAGE image,int x,int y ,int isright ,int lev):chicken(image,x,y,isright,lev)
	{
	}

	void move();
};
