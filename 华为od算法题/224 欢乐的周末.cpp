/*
224、欢乐的周末 200分
题目描述：
小华和小为是很要好的朋友，他们约定周末一起吃饭。通过手机交流，他们在地图上选择了多个聚餐地点（由于自然地形等原因，部分聚餐地点不可达），求小华和小为都能到达的聚餐地点有多少个？

输入描述：
第一行输入m和n，m代表地图的长度，n代表地图的宽度。
第二行开始具体输入地图信息，地图信息包含：
0 为通畅的道路
1 为障碍物（且仅1为障碍物）
2 为小华或者小为，地图中必定有且仅有2个 （非障碍物）
3 为被选中的聚餐地点（非障碍物）

输出描述：
可以被两方都到达的聚餐地点数量，行末无空格。
补充说明：
地图的长宽为m和n，其中：
4 <= m <= 100
4 <= n <= 100
聚餐的地点数量为 k，则
1< k <= 100

示例1
输入：
4 4
2 1 0 3
0 1 2 1
0 3 0 0
0 0 0 0
输出：
2
说明：
第一行输入地图的长宽为3和4。
第二行开始为具体的地图，其中：3代表小华和小明选择的聚餐地点；2代表小华或者小明（确保有2个）；0代表可以通行的位置；1代表不可以通行的位置。
此时两者能都能到达的聚餐位置有2处

示例2
输入：
4 4
2 1 2 3
0 1 0 0
0 1 0 0
0 1 0 0
输出：
0
说明：
第一行输入地图的长宽为4和4。
第二行开始为具体的地图，其中：3代表小华和小明选择的聚餐地点；2代表小华或者小明（确保有2个）；0代表可以通行的位置；1代表不可以通行的位置。
由于图中小华和小为之间有个阻隔，此时，没有两人都能到达的聚餐地址，故而返回0
*/
#include<iostream>
#include<vector>
#include<queue>

using namespace std;

int m, n; // m代表地图的长度，n代表地图的宽度。

// 定义点的坐标
struct point2
{
	int x;
	int y;
};

// 定义四个方向的移动向量
const vector<pair<int, int>> DIRECTIONS = { {-1, 0}, {1, 0}, {0, -1}, {0, 1} };

void if_reach(const vector<vector<int>>& map, vector<vector<bool>>& visited, const point2& start)	// 判断从x1,y2 -> x2,y2是否可达
{
	queue<point2> q;
	// vector<vector<bool>> visited(map.size(), vector<bool>(map[0].size(), false));	// 记录已访问的节点
	// 初始化
	q.push({ start.x, start.y });
	visited[start.x][start.y] = true;

	while (!q.empty())
	{
		point2 current = q.front(); q.pop();	// 从队列出队当前遍历的节点
		for (auto i : DIRECTIONS)
		{
			int newX = current.x + i.first;
			int newY = current.y + i.second;
			if (newX >=0 && newX < n && newY >=0 && newY < m && map[newX][newY] != 1 && visited[newX][newY] == false)	// 搜索的节点可达且未访问
			{
				q.push({ newX, newY });
				visited[newX][newY] = true;
			}
		}
	}
}

int main()
{
	cin >> m >> n;
	vector<vector<int>> map(n, vector<int>(m));			// 总的地图
	vector<point2> restaurant;	// 餐厅
	vector<point2> people;		// 小华和小为的位置
	/*  0 为通畅的道路
		1 为障碍物（且仅1为障碍物）
		2 为小华或者小为，地图中必定有且仅有2个 （非障碍物）
		3 为被选中的聚餐地点（非障碍物）*/
	for (int i = 0; i < n; i++)
	{
		for (int j = 0; j < m; j++)
		{
			cin >> map[i][j];
			if (map[i][j] == 3)
			{
				restaurant.push_back({ i, j });
			}
			if (map[i][j] == 2)
			{
				people.push_back({ i, j });
			}
		}
	}
	//bfs搜索
	vector<vector<bool>> if_reach_1(n, vector<bool>(m, false));
	vector<vector<bool>> if_reach_2(n, vector<bool>(m, false));
	if_reach(map, if_reach_1, people[0]);
	if_reach(map, if_reach_2, people[1]);

	// 判断
	int res = 0;
	for (auto i : restaurant)
	{
		if (if_reach_1[i.x][i.y] && if_reach_2[i.x][i.y]) res++;
	}
	cout << res;





}