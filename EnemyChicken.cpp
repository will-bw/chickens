#include "EnemyChicken.h"

void EnemyChicken::move()
{
	if (isRight)
		x+=speed;
	else
		x-=speed;
}
