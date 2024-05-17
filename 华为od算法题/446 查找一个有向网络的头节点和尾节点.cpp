///*
//446、查找一个有向网络的头节点和尾节点
//题目描述：
//给定一个有向图，图中可能包含有环，图使用二维矩阵表示，每一行的第一列表示起始节点，第二列表示终止节点，如[0, 1]表示从0到1的路径。每个节点用正整数表示。求这个数据的首节点与尾节点，题目给的用例会是一个首节点，但可能存在多个尾节点。同时，图中可能含有环。如果图中含有环，返回[-1]。
//
//说明：入度为0是首节点，出度为0是尾节点。
//
//输入描述：
//第一行为后续输入的键值对数量N>=0，第二行为2N个数字。每两个为一个起点，一个终点。如：
//
//输出描述：
//输出一行头节点和尾节点。如果有多个尾节点，按从大到小的顺序输出。
//
//补充说明：
//如果图有环，输出为-1.
//所有输入均合法，不会出现不配对的数据
//
//示例1
//输入：
//4
//0 1 0 2 1 2 2 3
//输出：
//0 3
//说明：
//
//示例2
//输入：
//2
//0 1 0 2
//输出：
//0 1 2
//说明：
//*/
//#include <iostream>
//#include <vector>
//#include <queue>
//#include <algorithm>
//
//using namespace std;
//
//class Graph
//{
//private:
//	vector<vector<int>> m;	// (adjMatrix)邻接矩阵，存储权值
//	int v; // numVertices 顶点数
//	vector<int> topologicalOrder; // 存储拓扑排序次序
//public:
//	Graph(int v) : v(v)
//	{
//		m.resize(v, vector<int>(v, 0));
//	}
//
//	void addEdge(int x, int y)
//	{
//		m[x][y] = 1;
//	}
//
//	void kahn()
//	{
//		// 初始化入度数组:
//		vector<int> in_degree(v, 0);
//		// 计算每个顶点的入度:
//		for (int i = 0; i < v; i++)
//		{
//			for (int j = 0; j < v; j++)
//			{
//				if (m[j][i] != 0)
//				{
//					in_degree[i]++;
//				}
//			}
//		}
//
//		// 将入度为0的顶点加入到q
//		queue<int> q; // 存储所有入度为0的顶点
//		for (int i = 0; i < v; i++)
//		{
//			if (in_degree[i] == 0) q.push(i);
//		}
//
//		// 拓扑排序
//		while (!q.empty())
//		{
//			int cur = q.front(); q.pop();// 弹出队首顶点 cur，并输出，表示顶点 cur 在拓扑排序中的位置。
//			topologicalOrder.push_back(cur);
//
//			// 更新入读表
//			for (int i = 0; i < v; i++)
//			{
//				if (m[cur][i] != 0)	// 找到邻接点
//				{
//					in_degree[i]--;
//					if (in_degree[i] == 0) q.push(i);
//				}
//			}
//		}
//	}
//
//	void print_topologicalOrder()
//	{
//		for (auto i : topologicalOrder)
//		{
//			cout << i << " ";
//		}
//	}
//
//	int size_topologicalOrder()
//	{
//		return topologicalOrder.size();
//	}
//
//	void get_result()
//	{
//		vector<int> res;
//		res.push_back(topologicalOrder[0]);
//
//		// 找到所有出度为0的点
//		vector<int> out_degree(v);
//		for (int i = 0; i < v; i++)
//		{
//			for (int j = 0; j < v; j++)
//			{
//				if (m[i][j] != 0) out_degree[i]++;
//			}
//		}
//		for (int i = 0; i < v; i++)
//		{
//			if (out_degree[i] == 0)
//			{
//				res.push_back(i);
//			}
//		}
//		
//		// 输出结果
//		for (auto i : res)
//		{
//			cout << i << " ";
//		}
//	}
//};
//
//
//int main()
//{
//	int n;// 一共n条数据,其实没有用
//	cin >> n;
//	vector<int> nums;	// 存储所有输入的数据
//	int tmp;
//	while (cin >> tmp)
//	{
//		nums.push_back(tmp);
//		if (cin.get() == '\n') break;
//	}
//	int v = 0;
//	for (auto i : nums) v = max(v, i);
//	v++;	// 实际节点数目是最大序号+1
//	Graph g(v);
//	for (int i = 0; i < nums.size(); i = i + 2)
//	{
//		g.addEdge(nums[i], nums[i + 1]);
//	}
//	g.kahn();
//	if (g.size_topologicalOrder() != v)
//	{
//		cout << -1;
//	}
//	else {
//		g.get_result();
//	}
//}