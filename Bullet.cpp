#include "Bullet.h"

void Bullet::move()
{
	speed_y+=g;//模拟抛物线运动
	y+=speed_y;
	x+=speed_x;
}

bool Bullet::intersect(object& object)
{
	return x <= object.x + object.width && x + width >= object.x && y <= object.y + object.height && y
			+ height >= object.y;
}
