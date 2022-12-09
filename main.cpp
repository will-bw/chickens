#include"main.h"
#include "EasyXPng.h"


void init()
{
	TCHAR filename[50];
	for (int i = 0; i < 5; i++)
	{
		_stprintf_s(filename, _T("./images/enemychicken/left/chicken%d.png"), i);
		loadimage(&enemy_chicken[0][i], filename);
	}
	for (int i = 0; i < 5; i++)
	{
		_stprintf_s(filename, _T("./images/enemychicken/right/chicken%d.png"), i);
		loadimage(&enemy_chicken[1][i], filename);
	}
	for (int i = 0; i < 4; i++)
	{
		_stprintf_s(filename, _T("./images/mychicken/left/chicken%d.png"), i);
		loadimage(&player[0][i], filename);
	}
	for (int i = 0; i < 4; i++)
	{
		_stprintf_s(filename, _T("./images/mychicken/right/chicken%d.png"), i);
		loadimage(&player[1][i], filename);
	}
	for (int i = 0; i < 5; i++)
	{
		_stprintf_s(filename, _T("./images/nums/0%d.png"), i);
		loadimage(&nums[i], filename);
	}
	loadimage(&im_bk, _T("./images/bk2.jpg"));
	loadimage(&im_boss, _T("./images/boss.png"));
	loadimage(&im_myBullet, _T("./images/basketball.png"));
	loadimage(&im_start, _T("./images/start.png"));
	loadimage(&im_win, _T("./images/win.png"));
	loadimage(&im_lose, _T("./images/lose.png"));
	loadimage(&im_bossBullet, _T("./images/egg.png"));
	mciSendString(_T("open ./music/xianjian.mp3 alias xj"), NULL, 0, NULL);
	mciSendString(_T("open ./music/nkg.mp3 alias nkg"), NULL, 0, NULL);
	mciSendString(_T("open ./music/win.mp3 alias win"), NULL, 0, NULL);
	mciSendString(_T("open ./music/lose.mp3 alias lose"), NULL, 0, NULL);
	mciSendString(_T("open ./music/j.mp3 alias j"), NULL, 0, NULL);
	mciSendString(_T("open ./music/a.mp3 alias a"), NULL, 0, NULL);
	//音乐


	state = 1; //游戏开始
	srand((unsigned int)time(NULL)); //随机数种子初始化
	me = MyChicken(player[1][0],WIN_WIDTH / 2, WIN_HEIGHT / 2, 1, 0);
	boss = Boss(im_boss, 20, 20, 1, 5);
	initgraph(WIN_WIDTH, WIN_HEIGHT); //开窗口
}

/*注意这里的贴图坐标判定，我写在类里面的坐标和width和height实际上是原来的小鸡的坐标和宽和高，
不算上剑，是为了提高碰撞判定的精确度，但是贴图的坐标是整张图的坐标，所以要在对象的坐标的基础上进行计算来进行绘图。*/

void draw(EnemyChicken& obj)
{
	putimagePng(obj.x - (obj.image.getwidth() - obj.width) / 2, obj.y, &(obj.image));
	putimagePng(obj.x + obj.width / 2 - nums[obj.level].getwidth() / 2, obj.y - nums[obj.level].getheight(),
	            &nums[obj.level]);
}


void draw(MyChicken& obj)
{
	putimagePng(obj.x - (obj.image.getwidth() - obj.width) / 2, obj.y, &(obj.image));
	putimagePng(obj.x + obj.width / 2 - nums[obj.level].getwidth() / 2, obj.y - nums[obj.level].getheight(),
	            &nums[obj.level + 1]);
}


void draw()
{
	putimage(0, 0, &im_bk); //绘制背景
	draw(me); //绘制我方小鸡
	for (auto it = enemys.begin(); it != enemys.end();) //绘制敌方小鸡
	{
		if (it->isAlive && it->x >= -200 && it->x <= WIN_WIDTH + 200)
		{
			draw(*it);
			it++;
		}
		else
		{
			it = enemys.erase(it);
		}
	}
	// boss.shoot();
	if (state == 3)
	{
		bullet_show(me);
		bullet_show(boss);
		putimagePng(boss.x, boss.y, &boss.image); //绘制boss
		TCHAR s[20]; //血量显示
		_stprintf_s(s, _T("blood:%d"), boss.life);
		settextcolor(RED);
		settextstyle(30, 0, _T("Arial"));
		setbkmode(TRANSPARENT); //设置字体背景透明
		outtextxy(boss.x + 70, boss.y - 30, s);
	}
	text_show();
	gameover();
}

void enemy_move()
{
	for (auto it = enemys.begin(); it != enemys.end(); it++)
	{
		it->move();
	}
}

void crash_check()
{
	for (auto it = enemys.begin(); it != enemys.end(); it++) //我方小鸡和敌方小鸡
	{
		if (me.intersect(*it))
		{
			if (me.level < it->level)
			{
				me.life--;
				it->isAlive = false;
				mciSendString(_T("close a"), NULL, 0, NULL);
				mciSendString(_T("open ./music/a.mp3 alias a"), NULL, 0, NULL);
				mciSendString(_T("play a"), NULL, 0, NULL);
			}
			else
			{
				it->isAlive = false;
				me.score += it->level + 1;
				mciSendString(_T("close j"), NULL, 0, NULL);
				mciSendString(_T("open ./music/j.mp3 alias j"), NULL, 0, NULL);
				mciSendString(_T("play j"), NULL, 0, NULL);
				if (it->level == 3)
					me.bullet_cnt++;
			}
		}
	}
	if (state == 3)
	{
		for (auto it = boss.bullets.begin(); it != boss.bullets.end(); it++) //我方小鸡和敌方子弹
		{
			if (it->intersect(me))
			{
				me.life--;
				it->isAlive = false;
				mciSendString(_T("close a"), NULL, 0, NULL);
				mciSendString(_T("open ./music/a.mp3 alias a"), NULL, 0, NULL);
				mciSendString(_T("play a"), NULL, 0, NULL);
			}
		}
		if (me.intersect(boss)) //我方小鸡和boss
		{
			me.life = 0;
		}
		for (auto it = me.bullets.begin(); it != me.bullets.end(); it++) //boss和我方子弹
		{
			if (it->intersect(boss))
			{
				boss.life--;
				it->isAlive = false;
				mciSendString(_T("close nkg"), NULL, 0, NULL);
				mciSendString(_T("open ./music/nkg.mp3 alias nkg"), NULL, 0, NULL);
				mciSendString(_T("play nkg"), NULL, 0, NULL);
			}
		}
	}
}

void create_enemy()
{
	if (flush_count >= 15)
	{
		flush_count = 0; //半秒生成一个敌方小鸡
		int isright = rand() % 2;
		int lev = rand() % 5;
		int y = (100 * (rand() % 6));
		int x = isright ? 0 - enemy_chicken[isright][lev].getwidth() : WIN_WIDTH;
		enemys.push_back(EnemyChicken(enemy_chicken[isright][lev], x, y, isright, lev));
	}
}

void state_check()
{
	if (me.score >= 2 && me.score < 10)
		me.level = 1;
	else if (me.score >= 10 && me.score <= 20)
		me.level = 2;
	else if (me.score > 20)
	{
		me.level = 3;
		if (state == 1)
			state = 2;
	}

	if (me.score >= 30 && state == 2 && me.level == 3)
		state = 3;

	if (boss.life <= 0) //boss打死为赢
	{
		isover = true;
		win = true;
	}
	if (me.life <= 0)
	{
		isover = true;
		win = false;
	}
}

void gameover()
{
	if (isover)
	{
		state = 4;
		if (win)
		{
			putimagePng(550, 300, &im_win);
			mciSendString(_T("close xj"), NULL, 0, NULL);
			mciSendString(_T("open ./music/win.mp3 alias win"), NULL, 0, NULL);
			mciSendString(_T("play win"), NULL, 0, NULL);
		}
		else
		{
			putimagePng(550, 300, &im_lose);
			mciSendString(_T("close xj"), NULL, 0, NULL);
			mciSendString(_T("open ./music/lose.mp3 alias lose"), NULL, 0, NULL);
			mciSendString(_T("play lose"), NULL, 0, NULL);
		}
		_getch();
	}
}

void text_show()
{
	TCHAR s[20]; //血量显示
	_stprintf_s(s, _T("Lives:%d"), me.life);
	settextcolor(GREEN);
	settextstyle(30, 0, _T("Arial"));
	setbkmode(TRANSPARENT); //设置字体背景透明
	outtextxy(10, 30, s);
	// TCHAR s1[20]; //得分显示
	// settextcolor(WHITE);
	// settextstyle(30, 0, _T("Arial"));
	_stprintf_s(s, _T("Score:%d"), me.score);
	outtextxy(200, 30, s);
	putimagePng(500, 35, &im_myBullet);
	_stprintf_s(s, _T("x %d"), me.bullet_cnt);
	outtextxy(550, 30, s);
}

void bullet_show(MyChicken& me_chicken)
{
	for (auto it = me_chicken.bullets.begin(); it != me_chicken.bullets.end();)
	{
		if (it->isAlive && it->x >= -200 && it->x <= WIN_WIDTH + 200)
		{
			putimagePng(it->x, it->y, &im_myBullet);
			it->move();
			it++;
		}
		else
		{
			it = me_chicken.bullets.erase(it);
		}
	}
}

void bullet_show(Boss& boss_bu)
{
	for (auto it = boss_bu.bullets.begin(); it != boss_bu.bullets.end();)
	{
		if (it->isAlive && it->x >= -200 && it->x <= WIN_WIDTH + 200)
		{
			putimagePng(it->x, it->y, &im_bossBullet);
			it->move();
			it++;
		}
		else
		{
			it = boss_bu.bullets.erase(it);
		}
	}
}

void shoot(MyChicken& mc)
{
	if (_kbhit())
	{
		if (GetAsyncKeyState(32)) //空格
		{
			if (me.bullet_cnt > 0)
			{
				if (mc.isRight)
				{
					Bullet bu(double(mc.x + mc.width - BULLET_WIDTH), double(mc.y + 35), double(8), double(-15));
					mc.bullets.push_back(bu);
				}
				else
				{
					Bullet bu(double(mc.x), double(mc.y + 35), double(-8), double(-15));
					mc.bullets.push_back(bu);
				}
				mc.bullet_cnt--;
			}
		}
	}
}

void shoot(Boss& b)
{
	if (b.shoot_cnt >= 60) //三秒发射一次
	{
		for (int i = 0; i < 4; i++)
		{
			b.bullets.push_back(Bullet(b.x + (b.width / 2) - 12, b.y + (b.height / 2) - 12, 1 + 2 * i, -15 + 1.5 * i));
		}
		for (int i = 0; i < 4; i++)
		{
			b.bullets.push_back(Bullet(b.x + (b.width / 2) - 12, b.y + (b.height / 2) - 12, -1 - 2 * i, -15 + 1.5 * i));
		}
		b.shoot_cnt = 0;
	}
	b.shoot_cnt++;
}

void update()
{
	if (state == 1)
	{
		putimagePng(0, 0, &im_start);
		if (_kbhit())
		{
			if (GetAsyncKeyState(13)) //空格
			{
				state = 2;
				mciSendString(_T("play xj repeat"), NULL, 0, NULL);
			}
		}
	}
	else if (state == 2 || state == 3)
	{
		cleardevice();
		create_enemy(); //开始生成敌方小鸡

		BeginBatchDraw(); //开始绘图
		draw(); //绘制
		EndBatchDraw(); //结束绘图

		me.move(); //我方小鸡移动
		enemy_move(); //敌方小鸡移动
		if (state == 3)
		{
			boss.move(); //boss移动
			shoot(me);
			shoot(boss); //发射子弹开始
		}
		me.image = player[me.isRight][me.level]; //更新我的图片
		crash_check();
		Sleep(50);
		flush_count++;
	}
	if (state == 4)
	{
		if (_kbhit())
		{
			if (GetAsyncKeyState(13)) //回车
			{
				state = 0;
			}
		}
	}
	state_check();
}

int main()
{
	init();
	while (state)
	{
		update();
	}

	_getch();
	return 0;
}
