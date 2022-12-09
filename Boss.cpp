#include "Boss.h"

void Boss::move()
{
	if(cnt>=40)//两秒改变一次
	{
		if(rand()%2)
			speed_x=1+rand()%8;
		else
			speed_x= -1-rand()%8;
		if(rand()%2)
			speed_y=1+rand()%8;
		else
			speed_y= -1-rand()%8;

		cnt=0;
	}
	x+=speed_x;
	y+=speed_y;
	if(x<=0||x>=WIN_WIDTH-width)
		speed_x=-speed_x;
	if(y<=0||y>=WIN_HEIGHT-height)
		speed_y=-speed_y;

	cnt++;
}
