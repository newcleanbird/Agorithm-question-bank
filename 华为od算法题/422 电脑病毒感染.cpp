/*
422、电脑病毒感染
题目描述：
一个局域网内有很多台电脑，分别标注为 1 - N 的数字。相连接的电脑距离不一样，所以感染时间不一样，感染时间用t表示。
其中网络内一个电脑被病毒感染，其感染网络内所有的电脑需要最少需要多长时间。如果最后有电脑不会感染，则返回-1
给定一个数组times表示一个电脑把相邻电脑感染所用的时间。
如图：path[i]= {i,j, t} 表示电脑i->j 电脑i上的病毒感染j，需要时间t。

输入描述：
4
3
2 1 1
2 3 1
3 4 1
2
输出描述：
2
补充说明：
第一个参数:局域网内电脑个数N 1<=N<=200;
第二个参数：总共多少条网络连接
第三个 1 2 1 表示1->2时间为1
第七行：表示病毒最开始所在的电脑号1

示例1
输入：
4
3
2 1 1
2 3 1
3 4 1
2
输出：
2
说明：

思路：Dijkstra 单源最短路径
*/
#include<iostream>
#include<vector>
#include<string>
#include<queue>
#include<utility>
#include <climits>

using namespace std;

//设置无穷大常量
int const INF = INT_MAX;

int dijstra(int start, vector<vector<int>>& map) {
    int n = map.size()-1;   // n个节点
    vector<int> dis(n + 1, INT_MAX);    // 当前距离表
    vector<bool> vis(n + 1, false);     // 是否访问表
    dis[start] = 0;                     // 初始化，起点距离为0
    for (int i = 1; i <= n; i++) {
        int minn = INT_MAX;
        int u = -1; 
        for (int j = 1; j <= n; j++) {  // 找最小未被访问的dist[j]
            if (!vis[j] && dis[j] < minn) { // j未被加入最短路径表
                minn = dis[j];
                u = j;  // u存储找到的当前最近的节点
            }
        }
        if (u == -1) break; // 未找到新的表，则算法结束
        vis[u] = true;  // 将找到的节点标记为已访问
        for (int j = 1; j <= n; j++) {  // 更新dist[j]
            if (!vis[j] && map[u][j] != INF && dis[u] + map[u][j] < dis[j])  // 节点j未访问，且
            {
                dis[j] = dis[u] + map[u][j];
                // dis[j] = min(dis[j], dis[u] + map[u][j]);
            }
        }
    }
    int res = 0;
    for (int i = 1; i <= n; i++)
    {
        if (dis[i] == INF)
        {
            return -1;
        }
        else {
            res = max(res, dis[i]);
        }
    }
    return res;
}

int main()
{
	int n;      //电脑个数N
	int size;   //总共多少条网络连接
	cin >> n >> size;
	vector<vector<int>> network(n+1, vector<int>(n+1, INF));    // 节点编号由1~n
	for (int i = 0; i < size; i++)
	{
		int x, y, val;
		cin >> x >> y >> val;
		network[x][y] = val;
	}
	int start;	// 病毒所在的电脑，即Dijkstra算法的起始点
	cin >> start;
	// 计算
	int res = dijstra(start, network);
	cout << res;
}

