#include "EnemyChicken.h"

void EnemyChicken::move()
{
	if (isRight)
		set_x(x1() + speed);
	else
		set_x(x1() - speed);
}
