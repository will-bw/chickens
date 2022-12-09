#include "Bullet.h"

void Bullet::move()
{
	speed_y+=g;//模拟抛物线运动
	y+=speed_y;
	x+=speed_x;
}
