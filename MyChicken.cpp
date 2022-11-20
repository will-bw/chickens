#include "MyChicken.h"

#include "util.h"

void MyChicken::move()
{
	if (_kbhit()) //	If a key is pressed
	{
		//检测玩家按键
		if (GetAsyncKeyState(VK_UP) && y1() > 0) //Up
			set_y(y1() - 8);
		if (GetAsyncKeyState(VK_DOWN) && y1() < WIN_HEIGHT - height1()) //Down
			set_y(y1() + 8);
		if (GetAsyncKeyState(VK_LEFT) && x1() > 0) //Left
			set_x(x1() - 6);
		if (GetAsyncKeyState(VK_RIGHT) && x1() < WIN_WIDTH - width1()) //Right
			set_x(x1() + 6);
	}
}
