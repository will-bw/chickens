#include "MyChicken.h"
#include "EnemyChicken.h"
#include "util.h"

void init();
void draw();

int main()
{
	srand((unsigned int)time(NULL));//随机数种子初始化
	init();
	MyChicken me(utils::player[myLevel],WIN_WIDTH/2,WIN_HEIGHT/2);

	return 0;
}

void init()
{
	utils::init();
}
