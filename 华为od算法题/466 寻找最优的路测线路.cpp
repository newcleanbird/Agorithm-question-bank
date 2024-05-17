///*
//466、寻找最优的路测线路
//题目描述：
//评估一个网络的信号质量，其中一个做法是将网络划分为栅格，然后对每个栅格的信号质量计算。路测的时候，希望选择一条信号最好的路线（彼此相连的栅格集合）进行演示。现给出R行C列的整数数组Cov，每个单元格的数值S即为该栅格的信号质量（已归一化，无单位，值越大信号越好）。
//要求从[0, 0]到[R-1, C-1]设计一条最优路测路线。返回该路线得分。
//规则：
//1.     路测路线可以上下左右四个方向，不能对角。
//2.     路线的评分是以路线上信号最差的栅格为准的，例如路径8→4→5→9的值为 4，该线路评分为4。线路最优表示该条线路的评分最高。
//
//输入描述：
//第一行表示栅格的行数R
//第二行表示栅格的列数C
//第3行开始，每一行表示栅格地图一行的信号值，如5 4 5
//
//输出描述：
//最优路线的得分
//
//补充说明：
//1.    1<= R, C <= 20
//2.    0<= S <= 65535
//
//示例1
//输入：
//3
//3
//5 4 5
//1 2 6
//7 4 6
//输出：
//4
//说明：
//路线为：5→4→5→6→6
//
//示例2
//输入：
//6
//5
//3 4 6 3 4
//0 2 1 1 7
//8 8 3 2 7
//3 2 4 9 8
//4 1 2 0 0
//4 6 5 4 3
//输出：
//3
//说明：
//路线为：3→4→6→3→4→7→7→8→9→4→3→8→8→3→4→4→6→5→4→3
//
//dist:路由表，维护一个当前已知的源点到其他点的距离
//q:维护一个待选择的未访问节点
//
//思想：只选择当前可达的最大的点即可
//*/
//
//#include<iostream>
//#include<vector>
//#include<queue>
//
//using namespace std;
//
//int R, C;
//
//struct Point
//{
//	int x;
//	int y;
//	int val;
//	Point(int x, int y, int val) : x(x), y(y), val(val) {}
//};
//
//vector<vector<int>> dis;	// 路由表
//vector<vector<Point>> parents;	// 前驱节点表
//vector<vector<int>> map;
//
//vector<int> dx = { 0, 1, 0, -1 };
//vector<int> dy = { 1, 0, -1, 0 };
//
//class compare
//{
//public:
//	bool operator()(const Point p1, const Point p2)
//	{
//		return p1.val < p2.val;
//	}
//};
//
//void Dijkstra()
//{
//	// vector<vector<bool>> vis(R, vector<bool>(C, 0));	// 访问表
//	// 初始化
//	Point start = { 0, 0, map[0][0]};
//	dis[0][0] = map[0][0];
//	parents[0][0] = start;
//	priority_queue<Point, vector<Point>, compare> q;
//	q.push(start);
//	while (!q.empty())
//	{
//		// 操作当前访问的节点
//		Point cur = q.top(); q.pop();
//		int x = cur.x;
//		int y = cur.y;
//		int val = cur.val;
//		if (dis[x][y] == INT_MAX) continue;
//		Point parent = parents[x][y];
//		/*if (parent.x == 0 && parent.y == 0)
//		{
//			dis[x][y] = dis[0][0];
//		}
//		else {
//			dis[x][y] = min(map[x][y], dis[parent.x][parent.y]);
//		}*/
//		dis[x][y] = min(map[x][y], dis[parent.x][parent.y]);
//
//		// 更新dis和q
//		for (int i = 0; i < 4; i++)
//		{
//			int nx = x + dx[i];
//			int ny = y + dy[i];
//			if (nx >= 0 && nx < R && ny >= 0 && ny < C && dis[nx][ny] == INT_MAX)	// 不越界且未访问
//			{
//				if (parents[nx][ny].x == -1 || dis[parents[nx][ny].x][parents[nx][ny].y] < dis[x][y])	// 首次访问 或 之前父节点质量小于当前父节点质量
//				{
//					parents[nx][ny] = cur;
//					dis[nx][ny] = min(map[nx][ny], dis[parents[nx][ny].x][parents[nx][ny].y]);
//					q.push({ nx, ny, map[nx][ny] });
//					
//				}
//			}
//		}
//	}
//}
//
//void printPath(Point& j) // 打印源点到j的路径
//{
//	if (j.x == 0 && j.y == 0) {
//		std::cout << map[0][0];
//		return;
//	}
//	printPath(parents[j.x][j.y]);
//	std::cout <<"->" << j.val;
//}
//
//int main()
//{
//	cin >> R >> C;
//	dis.resize(R, vector<int>(C, INT_MAX));
//	parents.resize(R, vector<Point>(C, {-1, -1, -1}));
//	map.resize(R, vector<int>(C, 0));
//
//
//	for (int i = 0; i < R; i++)
//	{
//		for (int j = 0; j < C; j++)
//		{
//			cin >> map[i][j];
//		}
//	}
//
//	// 探索路线
//	Dijkstra();
//	Point end{ R - 1, C - 1, map[R - 1][C - 1] };
//	cout << dis[R - 1][C - 1] << endl;
//	// printPath(end);
//}