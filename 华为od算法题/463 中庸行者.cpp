///*
//463 中庸行者
//题目描述
//给定一个m*n的整数矩阵作为地图，短阵数值为地形高度中庸行者选择地图中的任意一点作为起点，尝试往上、下、左、右四个相邻格子移动:移动时有如下约束:
//中庸行者只能上坡或者下坡，不能走到高度相同的点
//不允许连续上坡或者连续下坡，需要交替进行
//每个位置只能经过一次，不能重复行走
//请给出中庸行者在本地图内，能连续移动的最大次数。
//
//输入描述
//一个只包含整数的二维数组
//2 2
//1 2
//4 3
//说明：
//第一行两个数字，分别为行数和每行的列数
//后续数据为矩阵地图内容:
//矩阵边长范围:[1,8]
//地形高度范围:[0,10^6]
//
//输出描述
//一个整数，代表中庸行者在本地图内，能连续移动的最大次数。
//
//样例1
//输入
//2 2
//1 2
//4 3
//输出
//3
//说明：3>4>1>2
//
//样例2
//输入
//3 3
//1 2 4
//3 5 7
//6 8 9
//
//输出
//4
//
//说明：6>3>5>2>4
//*/
//#include<iostream>
//#include<vector>
//
//using namespace std;
//
//int res = 0;
//
//vector<int> dx = { -1, 1, 0, 0 }, dy = {0, 0, -1, 1};
//void dfs(int x, int y, vector<vector<int>>& map, vector<vector<bool>>& b_map, int count, int dir)
//{
//	// 更新结果
//	res = max(res, count);
//
//	b_map[x][y] = true;
//	for (int i = 0; i < 4; i++)
//	{
//		int a = dx[i] + x, b = dy[i] + y;
//		if (a >= 0 && a < map.size() && b >= 0 && b < map[0].size() && b_map[a][b] == false && map[a][b] != map[x][y])
//		{
//			int cur_dir = map[a][b] > map[x][y];
//			if (cur_dir != dir)
//			{
//				dfs(a, b, map, b_map, count+1, cur_dir);
//			}
//		}
//	}
//	// 回溯
//	b_map[x][y] = false;
//}
//
//int main()
//{
//	// 输入
//	int n, m;	// 行数和列数
//	cin >> n >> m;
//	vector<vector<int>> map(n, vector<int>(m));
//	for (int i = 0; i < n; i++)
//	{
//		for (int j = 0; j < m; j++)
//		{
//			cin >> map[i][j];
//		}
//	}
//	
//	for (int i = 0; i < n; i++)
//	{
//		for (int j = 0; j < m; j++)
//		{
//			vector<vector<bool>> b_map(n, vector<bool>(m, false));
//			dfs(i, j, map, b_map, 0, -1);
//		}
//	}
//	cout << res;
//}