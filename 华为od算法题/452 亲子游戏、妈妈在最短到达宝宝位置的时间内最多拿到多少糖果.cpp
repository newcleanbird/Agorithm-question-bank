///*
//452 亲子游戏 妈妈在最短到达宝宝位置的时间内最多拿到多少糖果
//题目描述：
//宝宝和妈妈参加亲子游戏，在一个二维矩阵（N*N）的格子地图上，宝宝和妈妈抽签决定各自的位置，地图上每个格子有不同的糖果数量，部分格子有障碍物。
//游戏规则是妈妈必须在最短的时间（每个单位时间只能走一步）到达宝宝的位置，路上的所有糖果都可以拿走，不能走障碍物的格子，只能上下左右走。
//请问妈妈在最短到达宝宝位置的时间内最多拿到多少糖果（优先考虑最短时间到达的情况下尽可能多拿糖果）。
//
//输入描述：
//第一行输入为N，N标识二维矩阵的大小
//之后N行，每行有N个值，表格矩阵每个位置的值
//其中：
//-3：妈妈
//-2：宝宝
//-1：障碍
//>=0：糖果数(0表示没有糖果，但是可以走)
//
//输出描述：
//输出妈妈在最短到达宝宝位置的时间内最多拿到多少糖果，行末无多余空格
//补充说明：
//地图最大50*50
//
//示例1
//输入：
//4
//3 2 1 -3
//1 -1 1 1
//1 1 -1 2
//-2 1 2 3
//输出：
//9
//说明：
//此地图有两条最短路径可到宝宝位置，绿色线和黄色线都是最短路径6步，但黄色拿到的糖果更多，9个
//
//示例2
//输入：
//4
//3 2 1 -3
//-1 -1 1 1
//1 1 -1 2
//-2 1 -1 3
//输出：
//-1
//说明：
//此地图妈妈无法到达宝宝位置
//*/
//
//#include<iostream>
//#include<vector>
//#include<queue>
//
//using namespace std;
//
//struct coord
//{
//	int x;
//	int y;
//};
//
//int dx[] = { -1, 0, 1, 0 };
//int dy[] = { 0, 1, 0, -1 };
//
//int main()
//{
//	int n;
//	cin >> n;
//	vector<vector<int>> map(n, vector<int>(n));
//	coord begin, end;
//	for (int i = 0; i < n; i++)
//	{
//		for (int j = 0; j < n; j++)
//		{
//			cin >> map[i][j];
//			if (map[i][j] == -3)
//			{
//				begin.x = i;
//				begin.y = j;
//			}
//			else if (map[i][j] == -2)
//			{
//				end.x = i;
//				end.y = j;
//			}
//		}
//	}
//
//	// 开始计算
//	queue<coord> q;
//	vector<vector<int>> step(n, vector<int>(n, INT_MAX));	// 存储每格的步数，以及验证是否来过
//	step[begin.x][begin.y] = 0;
//	vector<vector<int>> scores(n, vector<int>(n, 0));		// 得分
//	q.push(begin);
//	while (!q.empty())
//	{
//		coord cur = q.front(); q.pop();
//		if (step[cur.x][cur.y] >= step[end.x][end.y]) continue;	// 当前的步数已经超过终点步数，跳过当前
//		for (int i = 0; i < 4; i++)
//		{
//			int nx = cur.x + dx[i];
//			int ny = cur.y + dy[i];
//			if (nx >= 0 && nx < n && ny >= 0 && ny < n && map[nx][ny] != -1)
//			{
//				if (step[nx][ny] != 0)
//				{
//					q.push({ nx, ny });
//					step[nx][ny] += step[cur.x][cur.y] + 1;
//					scores[nx][ny] = scores[cur.x][cur.y] + map[nx][ny];
//				}
//				else {// 来过
//					if (step[nx][ny] == step[cur.x][cur.y] + 1)	// 同一轮查询
//					{
//						scores[nx][ny] = max(scores[nx][ny], scores[cur.x][cur.y] + map[nx][ny]);
//					}
//				}
//			}
//		}
//	}
//	if (scores[end.x][end.y] == 0)
//	{
//		cout << -1;
//	}
//	else {
//		cout << scores[end.x][end.y] + 2;
//	}
//
//}