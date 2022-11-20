#pragma once
#include "object.h"

class chicken:public object
{
public:
	chicken(IMAGE image,int x,int y):object(image,x,y){}
	void move();
private:

};
