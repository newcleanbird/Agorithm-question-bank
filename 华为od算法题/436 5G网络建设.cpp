/*
436、5G网络建设
题目描述：
现需要在某城市进行5G网络建设，已经选取N个地点设置5G基站，编号固定为1到N，接下来需要各个基站之间使用光纤进行连接以确保基站能互联互通，不同基站之间架设光纤的成本各不相同，且有些节点之间已经存在光纤相连，请你设计算法，计算出能联通这些基站的最小成本是多少。
注意：基站的联通具有传递性，入基站A与基站B架设了光纤，基站B与基站C也架设了光纤，则基站A与基站C视为可以互相联通
输入描述：
第一行输入表示基站的个数N，其中0<N<=20
第二行输入表示具备光纤直连条件的基站对的数目M，其中0<M<N*(N-1)/2
从第三行开始连续输入M行数据，格式为 X Y Z P，其中X Y表示基站的编号，0<X<=N，0<Y<=N且x不等于y，Z表示在X Y之间架设光纤的成本，其中0<Z<100，P表示是否已存在光纤连接，0表示未连接，1表示已连接
输出描述：
如果给定条件，可以建设成功互联互通的5G网络，则输出最小的建设成本；
如果给定条件，无法建设成功互联互通的5G网络，则输出-1

示例
示例1
输入：
3
3
1 2 3 0
1 3 1 0
2 3 5 0
输出：
4
说明：只需要在1,2以及2,3基站之间铺设光纤，其成本为3+1=4

示例2
输入：
3
1
1 2 5 0
输出：
-1
说明：3基站无法与其他基站连接，输出-1

示例3
输入：
3
3
1 2 3 0
1 3 1 0
2 3 5 1
输出：
1
说明：2,3基站已有光纤相连，只有要再1,3站点之间铺设光纤，其成本为1

找到最小生成树
本题特点：某些路径已经生成，因此需要预处理。

*/
#include<iostream>
#include<vector>
#include<algorithm>

using namespace std;

struct Edge
{
	int x, y, z; // 坐标u，v 权值w
	// Edge(int x, int y, int z) : x(x), y(y), z(z) {}
	bool operator<(const Edge& other) const
	{
		return this->z < other.z;
	}
};

class DisjointSets
{
public:
	DisjointSets(int n) : root(n), rank(n, 0)
	{
		for (int i = 0; i < n; i++)
		{
			root[i] = i;
		}
	}

	int unionFind(int x)	// 查找
	{
		if (x != root[x])
		{
			root[x] = unionFind(root[x]);
		}
		return root[x];
	}

	void unionMerge(int x, int y)	// 合并
	{
		int rX = unionFind(x);
		int rY = unionFind(y);
		if (rX != rY)
		{
			if (rank[rX] < rank[rY])
			{
				swap(rX, rY);
			}
			root[rY] = rX;
			rank[rX]++;
		}
	}

private:
	vector<int> root;
	vector<int> rank;
};


int main()
{
	int n; // 基站的个数N
	int m; // 表示具备光纤直连条件的基站对的数目M
	cin >> n >> m;

	// 初始化并查集
	DisjointSets dset(n+1);
	vector<Edge> Edges;
	// 输入M行数据, X Y Z P，其中X Y表示基站的编号 Z表示在X Y之间架设光纤的成本 P表示是否已存在光纤连接 0表示未连接，1表示已连接
	for (int i = 0; i < m; i++)
	{
		int x, y, z, p;
		cin >> x >> y >> z >> p;
		if (p == 1)
		{
			dset.unionMerge(x, y);
		}
		else {
			Edges.push_back({x, y, z});
		}
	}
	// 按边的权重排序
	sort(Edges.begin(), Edges.end());
	
	int res = 0; // 需要的花费
	// 克鲁斯卡尔算法
	for (auto& edge : Edges)
	{
		int x = edge.x;
		int y = edge.y;
		int set_x = dset.unionFind(x);
		int set_y = dset.unionFind(y);
		if (set_x != set_y)
		{
			dset.unionMerge(x, y);
			res += edge.z;
		}
	}
	
	bool ok = true;
	for (int i = 1; i <= n; i++)
	{
		if (dset.unionFind(1) != dset.unionFind(i))
		{
			ok = false;
		}
	}
	if (ok)
	{
		cout << res;
	}
	else {
		cout << -1;
	}
}
