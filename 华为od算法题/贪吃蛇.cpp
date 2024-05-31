//#include<windows.h>
//#include<conio.h>
//#include<iostream>
//
//using namespace std;
//
//
//// 点
//class Point
//{
//private:
//	COORD pos;	// 控制台上的坐标
//public:
//	Point() { pos.X = 0; pos.Y = 0; }
//
//	Point(UINT x, UINT y)
//	{
//		pos.X = x;
//		pos.Y = y;
//	}
//
//	Point(const Point& p) : pos(p.pos)
//	{
//	}
//
//	void setPos(UINT x, UINT y)
//	{
//		pos.X = x;
//		pos.Y = y;
//	}
//
//	void setPosPoint(const Point& p) { pos = p.pos; }
//
//	void setPosRandom(int isHead = 0)
//		//生成随机位置的点，主要用于蛇的初始化和食物的生成
//		//和食物不同，蛇头具有特殊性，它不能过于靠近地图的边缘，所以这里设计了isHead参数
//		//当isHead不填时默认为零，此时用于生成食物的位置
//		//当isHead传入参数为1时生成蛇头位置
//	{
//		if (isHead == 1)
//		{
//			srand(time(NULL));
//			pos.X = rand() % 18 + 1;
//			pos.Y = rand() % 10 + 7;
//		}
//		else
//		{
//			srand(time(NULL));
//			pos.X = rand() % 18 + 1;
//			pos.Y = rand() % 18 + 1;
//		}
//	}
//
//	void movePoint(int d)
//	{
//		if (d == 1)
//		{
//			pos.Y--;
//		}
//		else if (d == 2)
//		{
//			pos.Y++;
//		}
//		else if (d == 3)
//		{
//			pos.X--;
//		}
//		else if (d == 4)
//		{
//			pos.X++;
//		}
//	}
//
//	COORD getPos(void)
//	{
//		return pos;
//	}
//
//	void printPoint(char c)
//	{
//		HANDLE hOutput = GetStdHandle(STD_OUTPUT_HANDLE);
//		SetConsoleCursorPosition(hOutput, pos);
//		cout << c;
//	}
//};
//
//// 蛇
//class Snake
//{
//private:
//	Point p[400];
//	int dirction;//蛇目前的运动方向 1上2下3左4右
//	int lenth;//蛇的长度
//	friend class Game;
//public:
//	Snake()
//	{
//		lenth = 3;
//		p[0].setPosRandom(1);
//		p[1].setPos(p[0].getPos().X, p[0].getPos().Y + 1);
//		p[2].setPos(p[1].getPos().X, p[1].getPos().Y + 1);
//		dirction = 1;
//	}
//};
//
//// 游戏
//class Game
//{
//private:
//	Snake s;
//	int map[20][20] = { 0 };//0为空地 1为蛇身 2为食物 -1为墙
//	Point food;
//	int score;
//public:
//	Game()
//	{
//		for (int i = 0; i < 20; i++)//这里初始化墙并在控制台打印出来
//		{
//			Point p1(UINT(i), UINT(0));
//			map[i][0] = -1;
//			p1.printPoint('=');
//			Point p2(UINT(i), UINT(19));
//			map[i][19] = -1;
//			p2.printPoint('=');
//			Point p3(UINT(0), UINT(i));
//			map[0][i] = -1;
//			p3.printPoint('=');
//			Point p4(UINT(19), UINT(i));
//			map[19][i] = -1;
//			p4.printPoint('=');
//			Sleep(50);//这里是用来做出一种动画的效果
//		}
//		for (int i = 0; i < s.lenth; i++)//这里在map中标记好蛇
//		{
//			map[s.p[i].getPos().X][s.p[i].getPos().Y] = 1;
//		}
//		for (int i = 0; i < 3; i++)//在控制台打印出蛇
//		{
//			s.p[i].printPoint('O');
//		}
//		score = 0;
//	}
//
//	void creatFood(void)
//	{
//		Point food;
//		while (map[food.getPos().X][food.getPos().Y] != 0)//只有当随机生成的位置在map中为0，也就是为空地时才进行下一步操作
//		{
//			food.setPosRandom();
//		}
//		map[food.getPos().X][food.getPos().Y] = 2;
//		food.printPoint('$');
//	}
//
//	void eatFood(void)
//	{
//		score = score + 100;
//		Point temph(s.p[0]);
//		Point tempt(s.p[s.lenth - 1]);
//		s.p[0].movePoint(s.dirction);
//		map[s.p[0].getPos().X][s.p[0].getPos().Y] = 1;
//		s.p[0].printPoint('O');
//		for (int i = s.lenth - 1; i > 1; i--)
//		{
//			s.p[i].setPosPoint(s.p[i - 1]);
//		}
//		s.p[1].setPosPoint(temph);
//		s.lenth++;
//		s.p[s.lenth - 1].setPosPoint(tempt);
//		Sleep(500);
//	}
//
//	void snakeGo(void)
//	{
//		Point temp(s.p[0]);
//		s.p[0].movePoint(s.dirction);
//		map[s.p[0].getPos().X][s.p[0].getPos().Y] = 1;
//		s.p[0].printPoint('O');
//		map[s.p[s.lenth - 1].getPos().X][s.p[s.lenth - 1].getPos().Y] = 0;
//		s.p[s.lenth - 1].printPoint(' ');
//		for (int i = s.lenth - 1; i > 1; i--)
//		{
//			s.p[i].setPosPoint(s.p[i - 1]);
//		}
//		s.p[1].setPosPoint(temp);
//		Sleep(500);
//	}
//
//	int isEatorEnd(Point q, int dirc)
//		//传入蛇头坐标和此时蛇行进的方向，然后判断蛇下一次运动后是否吃到食物或撞到墙壁或自身，这里利用map进行判断
//	{
//		q.movePoint(dirc);
//		if (map[q.getPos().X][q.getPos().Y] == -1 || map[q.getPos().X][q.getPos().Y] == 1)
//		{
//			return -1;
//		}
//		else if (map[q.getPos().X][q.getPos().Y] == 2)
//		{
//			return 1;
//		}
//		else
//		{
//			return 0;
//		}
//	}
//
//	void setDirection(char d)
//		//注意到蛇在运动过程中不能直接向反方向移动
//		//比如当蛇向上走时只能向左右转而不能直接向后转
//	{
//		if (d == 'w' && s.dirction != 2)
//		{
//			s.dirction = 1;
//		}
//		else if (d == 's' && s.dirction != 1)
//		{
//			s.dirction = 2;
//		}
//		else if (d == 'a' && s.dirction != 4)
//		{
//			s.dirction = 3;
//		}
//		else if (d == 'd' && s.dirction != 3)
//		{
//			s.dirction = 4;
//		}
//		else
//		{
//			return;
//		}
//	}
//
//	Point& getHead(void) { return s.p[0]; }
//
//	int getDirc(void) { return s.dirction; }
//
//	int getPoint(void) { return score; }
//
//	int getLenth(void) { return s.lenth; }
//};
//
//int main()
//{
//	cout << "            您好，欢迎来到贪吃蛇           " << endl;
//	cout << "您可以通过'w''a''s''d'来控制蛇的上下左右移动" << endl;
//	system("pause");
//	system("cls");
//	Game g;
//	g.creatFood();
//	while (1)
//	{
//		while (!_kbhit())
//		{
//			int i = g.isEatorEnd(g.getHead(), g.getDirc());
//			if (i == 1)
//			{
//				g.eatFood();
//				if (g.getLenth() == 361)
//				{
//					goto L;
//				}
//				g.creatFood();
//				continue;
//			}
//			else if (i == -1)
//			{
//				goto L;
//			}
//			g.snakeGo();
//		}
//		char d = _getch();
//		g.setDirection(d);
//	}
//L:system("cls");
//	cout << "游戏结束！您的得分为" << g.getPoint() << endl;
//	return 0;
//}
//
//
//
//
//
//
//
//
//
//
////// 在指定位置打印图形
////// 参数：x坐标 y坐标 需要打印的字符串
////// 无返回值
////void MyPrintf(int iPosX, int iPosY, char* szSymbol)
////{
////	// 设置光标位置 SetConsoleCursorPosition（）
////	// 第一个参数为控制台的句柄 可由 GetStdHandle（）得到  STD_OUTPUT_HANDLE为输出
////	// 第二个参数为坐标结构体
////	COORD pos;											// 创建结构体pos
////	pos.X = iPosX;										// 结构体成员赋值
////	pos.Y = iPosY;
////
////	HANDLE hOutput = GetStdHandle(STD_OUTPUT_HANDLE);	// 得到窗口句柄
////
////	SetConsoleCursorPosition(hOutput, pos);				// 设置光标位置
////	printf(szSymbol);
////}