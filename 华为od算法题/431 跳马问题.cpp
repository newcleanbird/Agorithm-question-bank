///*
//431、跳马问题
//题目描述：
//马是象棋(包括中国象棋和国际象棋)中的棋子，走法是每步直一格再斜一格，即先横着或直着走一格，然后再斜着走一个对角线，可进可退，可越过河界，俗称“马走‘日’字。
//给顶m行n列的棋盘（网格图），棋盘上只有有棋子象棋中的棋子“马”，并且每个棋子有等级之分，等级为k的马可以跳1~k步（走的方式与象棋中“马”的规则一样，不可以超出棋盘位置），问是否能将所有马跳到同一位置，如果存在，输出最少需要的总步数（每匹马的步数相加），不存在则输出-1。
//注：允许不同的马在跳的过程中跳到同一位置，坐标为(x,y)的马跳一次可以跳到到坐标为(x+1, y+2), (x+1, y-2), (x+2, y+1), (x+2, y-1), (x-1, y+2), (x-1, y-2), (x-2, y+1), (x-2, y-1),的格点上，但是不可以超出棋盘范围。
//
//输入描述：
//第一行输入m,n代表m行n列的网格图棋盘(1 ≤ m, n ≤ 25)；
//接下来输入m行n列的网格图棋盘，如果第i行,第j列的元素为”.”代表此格点没有棋子，如果为数字k（1<=k<=9），代表此格点存在等级为k的“马”；
//
//输出描述：
//输出最少需要的总步数（每匹马的步数相加），不存在则输出-1。
//
//补充说明：
//示例1
//输入：
//3 2
//..
//2.
//..
//输出：
//0
//说明：
//只有一匹马，不需要跳动
//
//示例2
//输入：
//3 5
//47.48
//4744.
//7....
//输出：
//17
//说明：
//
//0,0 1,2 2,1 3,3
//*/
//#include<iostream>
//#include<vector>
//#include<string>
//#include<queue>
//
//using namespace std;
//
//vector<int> x_inc = { 1, 2, 2, 1, -1, -2, -2, -1,  };
//vector<int> y_inc = { 2, 1,-1,-2, -2, -1,  1,  2,  };
//
//struct Chess
//{
//	int x;
//	int y;
//	int k;
//	Chess(int x, int y, int k) : x(x), y(y), k(k)
//	{
//
//	}
//};
//
//void bfs(const vector<vector<int>>& map, vector<vector<int>>& vis, Chess start, int n)	// b为当前跳的步数
//{
//	queue<Chess> q;
//	q.push({start.x, start.y, 0});
//	while (!q.empty())
//	{
//		// 出队
//		Chess cur = q.front(); q.pop();
//		// 对该节点进行操作
//		vis[cur.x][cur.y] = cur.k;	// 标记该节点需要几次跳跃次数
//		for (int i = 0; i < 8; i++)
//		{
//			int x = cur.x + x_inc[i];
//			int y = cur.y + y_inc[i];
//			if (x >= 0 && x < map.size() && y >= 0 && y < map[0].size() && vis[x][y] == -1) // 未越界,未访问
//			{
//				if (cur.k + 1 > n) continue;
//				Chess tmp = { x, y, cur.k + 1 };
//				q.push(tmp);
//			}
//		}
//	}
//}
//
//int main()
//{
//	// 输入
//	int m, n; // m行n列的网格图棋盘
//	cin >> m >> n;
//	cin.get();
//	vector<vector<int>> map(m, vector<int>(n));
//	int chess_num = 0; // 记录图中有多少棋子
//	vector<Chess> chesses;
//	for (int i = 0; i < m; i++)
//	{
//		string str;
//		getline(cin, str);
//		int j = 0;
//		for (int j = 0; j < str.size(); j++)
//		{
//			if (str[j] == '.')
//			{
//				map[i][j] = 0;
//			}
//			else {
//				map[i][j] = str[j] - '0';
//				chess_num++;
//				chesses.push_back(Chess(i, j, map[i][j]));
//			}
//		}
//	}
//
//	vector<vector<vector<int>>> vis(chess_num, vector<vector<int>>(m, vector<int>(n, -1)));	// 存储是否可达
//	for (int i = 0; i < chesses.size(); i++)
//	{
//		bfs(map, vis[i], chesses[i], chesses[i].k);
//	}
//	
//	// 统计
//	vector<vector<int>> res(m, vector<int>(n, 0));
//	for (auto& chess : vis)
//	{
//		for (int i = 0; i < m; i++)
//		{
//			for (int j = 0; j < n; j++)
//			{
//				if (res[i][j] == -1)
//				{
//					continue;
//				}
//				if (chess[i][j] == -1)	// 有棋子在该点不可达
//				{
//					res[i][j] = -1;
//				}
//				else {
//					res[i][j] += chess[i][j];
//				}
//			}
//		}
//	}
//	int count = 0;
//	int minn = INT_MAX;
//	for (int i = 0; i < m; i++)
//	{
//		for (int j = 0; j < n; j++)
//		{
//			if (res[i][j] != -1)
//			{
//				count++;
//				minn = min(minn, res[i][j]);
//			}
//
//		}
//	}
//
//	if (count == 0)
//	{
//		cout << -1;
//	}
//	else {
//		cout << minn;
//	}
//
//}