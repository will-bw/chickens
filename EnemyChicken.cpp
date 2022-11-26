#include "EnemyChicken.h"

void EnemyChicken::move()
{
	if (isRight)
		x+=6;
	else
		x-=6;
}
