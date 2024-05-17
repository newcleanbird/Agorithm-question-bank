/*
477、路口最短时间问题
题目描述：
假定街道是棋盘型的，每格距离相等，车辆通过每格街道需要时间均为 timePerRoad;
街道的街口(交叉点)有交通灯，灯的周期T(=lights[row][col])各不相同;
车辆可直行、左转和右转，其中直行和左转需要等相应T时间的交通灯才可通行，右转无需等侍。
现给出 n*m 个街口的交通灯周期，以及起止街口的坐标，计算车辆经过两个街口的最短时间,其中:
1)起点和终点的交通灯不计入时间，且可以任意方向经过街口
2) 不可超出 n*m 个街口，不可跳跃，但边线也是道路(即 lights[0][0] -> lights[0]1] 是有效路径)
入口函数定义:
/**
/* lights: n*m 个街口每个交通灯的周期，值范围[0,120]，n和m的范围为[1,9]
*timePerRoad:相邻两个街口之间街道的通过时间范围为[0,600]
* rowStart: 起点的行号
*colStart: 起点的列号
*rowEnd : 终点的行号
*colEnd : 终点的列号
*return : lights[rowStart][colStart] 与 lights[rowEnd][colEnd] 两个街口之间的最短通行时间
/*
int calcTime(int[] lights,int timePerRoad,int rowStart,int colStart,int rowEnd,int colEnd)

输入描述
第一行输入 n 和 m，以空格分隔
之后 n 行输入 lights矩阵，矩阵每行m个整数，以空格分隔
之后一行输入 timePerRoad
之后一行输入 rowStart colStart，以空格分隔
最后一行输入 rowEnd colEnd，以空格分隔

输出描述
lights[rowStart][colStart] 与 lights[rowEnd][colEnd] 两个街口之间的最短通行时间

示例1
输入:
3 3
1 2 3
4 5 6
7 8 9
60
0 0
2 2
输出:
245

说明:
行走路线为 (0.0) -> (0.1)-> (1,1) -> (1.2) -> 2.2)走了4格路，2个右转，1个左转，共耗时 60+0+60+5+60+0+60=245

// 动态边权的有权图
1. dijkstra: 
因为要涉及汽车的方向，不同的路线到一点后会对到下一个点产生影响，因此当前最短并不一定是全局最短。

2.优先队列bfs

解题思路：
我们需要计算从一个街口（起点）到另一个街口（终点）的最短通行时间，考虑到每个街口处的交通灯周期和道路之间的行驶时间。问题可以用图搜索算法来解决，如Dijkstra算法，因为我们需要找到权重（时间）最小的路径。下面是详细的解题思路：
1. 图搜索问题
  - 节点：街口（交叉点）可以被视为图中的节点。
  - 边：连接相邻街口的道路可以视为图中的边，边的权重是通过该道路的时间（包括等待交通灯的时间）。
2. 定义状态
  - 为了在图中进行搜索，我们定义一个状态State，包含当前位置（街口）、累计的通行时间和当前的行驶方向。
  - 使用四个方向（东、南、西、北）来确定从一个节点到另一个节点的移动。
3. 使用优先队列
  - 使用优先队列（最小堆）来存储和排序所有的状态，以确保总是先处理具有最小通行时间的状态。
  - 优先队列基于当前累计的通行时间排序。
计算通行时间
  - 对于每个节点，需要考虑从四个方向进入该节点的可能性。
  - 计算从一个街口到另一个街口的时间需要基于：
	 - 道路时间：timePerRoad，即直接行驶时间。
	 - 交通灯时间：
	   - 如果是直行或左转，需要考虑交通灯周期，可能需要等待。
	   - 如果是右转，无需等待交通灯。
5. 更新时间和状态
  - 当从一个街口移动到另一个街口时，更新达到该街口的最小时间（如果当前计算的时间小于已记录的最小时间）。
  - 将新状态加入优先队列继续处理。
6. 处理边界条件
  - 确保不越界（即不超过街区的行列范围）。
  - 考虑起点和终点的特殊处理：起点时无需考虑交通灯时间，终点时找到最小时间即可结束。
7. 算法结束条件
  - 当优先队列为空，或者找到到达终点的最短路径时结束算法。


当前：0 1 2 3
左转:减一
指向：不变：
右转：加一：
反向：加2，但取消


之前 0 1 2 3
现在:0 1 2 3

新-旧：若大于则顺时针()，小于则逆时针->取模
新值+4 mod 4，
	0:直走
	1:左转
	2:反向
	3:右转
*/

#include <iostream>
#include <vector>
#include <queue>
#include <climits>

using namespace std;

// 定义一个结构体State来表示每个状态
struct State {
   int row, col, time, dir;  // 当前位置行号、列号，当前累计时间，当前方向
   bool operator<(const State& other) const {
       return time > other.time; // 使优先队列按时间升序排列，最小时间优先
   }
};

// 主函数，计算从起点到终点的最短通行时间
int calcTime(vector<vector<int>>& lights, int timePerRoad, int rowStart, int colStart, int rowEnd, int colEnd) {
   int n = lights.size(), m = lights[0].size(); // 获取灯的行列数
   vector<vector<vector<int>>> minTime(n, vector<vector<int>>(m, vector<int>(4, INT_MAX)));
   priority_queue<State> pq;

   // 初始化起点的所有四个方向时间为0，并推入优先队列
   for (int dir = 0; dir < 4; ++dir) {
       minTime[rowStart][colStart][dir] = 0;
   }
   pq.push({ rowStart, colStart, 0, -1 });
   vector<pair<int, int>> directions = { {0, 1}, {1, 0}, {0, -1}, {-1, 0} };  // 东、南、西、北方向的移动向量

   // 使用优先队列进行Dijkstra算法
   while (!pq.empty()) {
       State cur = pq.top();
       pq.pop();

       // 如果到达终点,继续执行
       if (cur.row == rowEnd && cur.col == colEnd) {
           return cur.time;
       }

       // 尝试所有可能的方向移动
       for (int i = 0; i < 4; ++i) {
           // 新坐标
           int nextRow = cur.row + directions[i].first;
           int nextCol = cur.col + directions[i].second;

           // 非初始状态且转向， 确保不能调头
           if ((cur.dir != -1) && (cur.dir + 2) % 4 == i) continue;
           // 确保不越界
           if (nextRow < 0 || nextRow >= n || nextCol < 0 || nextCol >= m) continue;

           int waitTime = 0;
           // 如果当前移动为右转，则不等待；否则取当前交通灯周期作为等待时间
           if (cur.dir == -1 || i == (cur.dir + 1) % 4) { // 默认状态/右转
               waitTime = 0; // 右转不等待
           }
           else { // 左转或直行
               waitTime = lights[cur.row][cur.col];
           }

           // 计算新的时间
           int nextTime = cur.time + timePerRoad + waitTime;
           // 如果新时间小于已记录的时间，则更新并推入优先队列
           if (nextTime < minTime[nextRow][nextCol][i]) {
               minTime[nextRow][nextCol][i] = nextTime;
               pq.push({ nextRow, nextCol, nextTime, i });
           }
       }
   }

   // 从四个方向找到最短时间并返回
   int ans = INT_MAX;
   for (int dir = 0; dir < 4; ++dir) {
       ans = min(ans, minTime[rowEnd][colEnd][dir]);
   }
   return ans;
}

// 主函数，用于接受输入并计算结果
int main() {
   int n, m; // 行列数
   cin >> n >> m;
   int x;
   vector<vector<int>> lights(n); // 存储每个交通灯周期
   for (int i = 0; i < n; i++)
       for (int j = 0; j < m; j++) {
           cin >> x; // 输入交通灯周期
           lights[i].push_back(x);
       }

   int timePerRoad, rowStart, colStart, rowEnd, colEnd;
   // 输入每格道路的时间，起点和终点坐标
   cin >> timePerRoad >> rowStart >> colStart >> rowEnd >> colEnd;
   // 输出计算的最短通行时间
   cout << calcTime(lights, timePerRoad, rowStart, colStart, rowEnd, colEnd);
   return 0;
}