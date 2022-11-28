#include "MyChicken.h"

#include "main.h"

void MyChicken::move()
{
	if (_kbhit()) //	If a key is pressed
	{
		//检测玩家按键
		if (GetAsyncKeyState(VK_UP) && y > 0) //Up
			y-=8;
		if (GetAsyncKeyState(VK_DOWN) && y < WIN_HEIGHT - height) //Down
			y+=8;
		if (GetAsyncKeyState(VK_LEFT) && x > 0) //Left
			{x-=9;isRight=0;}
		if (GetAsyncKeyState(VK_RIGHT) && x < WIN_WIDTH - width) //Right
			{x+=9;isRight=1;}
	}
	width=image.getwidth();
	height=image.getheight();
}

