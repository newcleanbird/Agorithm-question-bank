/*
410、小华地图寻宝、小华最多能得到多少克黄金
题目描述：
小华按照地图去寻宝，地图上被划分成 m 行和 n 列的方格，横纵坐标范围分别是 [0, n−1]和[0, m-1]。在横坐标和纵坐标的数位之和不大于k的方格中存在黄金（每个方格中仅存在一克黄金），但横坐标和纵坐标之和大于k的方格存在危险不可进入。小华从入口(0,0)进入，任何时候只能向左，右，上，下四个方向移动一格。请问小华最多能获得多少克黄金？

输入描述：
坐标取值范围如下：
0<=m<=50
0<=n<=50
k的取值范围如下：
0<=k<=100
输入中包含3个字数，分别是m，n，k

输出描述：
最多能获得多少克黄金

示例1
输入：
40 40 18
输出：
1484
说明：
当k为18时，小华能够进入方格（10,10），因为1+0+1+0 = 2。 但是，他不能进入方格（36,38），因为3+6+3+8 = 20

示例2
输入：
4 5 7
输出：
20
说明：
如图每个单元格中的数位之和均不大于7，都是符合要求的，所以可以最多可获得20克黄金

0 1 2 3 4
1 2 3 4 5
2 3 4 5 6
3 4 5 6 7

*/
#include <iostream>
#include <vector>
#include <string>
#include <windows.h>

using namespace std;

int m, n, k;
int res = 0;
vector<vector<int>> vis;

// 计算数位和
int get(int num) {
   int sum = 0;
   string s = to_string(num);
   for (char c : s) {
       sum += c - '0';
   }
   return sum;
}
void show_map()
{
   for (auto i : vis)
   {
       for (auto j : i)
       {
           cout << j << " ";
       }
       cout << endl;
   }
   Sleep(100);
   system("cls");
}
// 深度优先搜索
void dfs(int x, int y) {
   if (x < 0 || x >= n || y < 0 || y >= m || vis[x][y] == 1) {  // 越界和是否遍历过判断
       return;
   }
   vis[x][y] = 1;
   if (get(x) + get(y) > k) {  // 数位和大于k直接结束
       return;
   }
   res++;  // 更新答案
   //show_map();
   dfs(x, y - 1);
   dfs(x, y + 1);
   dfs(x + 1, y);
   dfs(x - 1, y);  // 遍历四个方向
}

int main() {
   // 输入 m, n, k
   cin >> m >> n >> k;

   // 初始化数组
   vis = vector<vector<int>>(n, vector<int>(m, 0));

   // 从（0，0）点开始遍历
   dfs(0, 0);

   // 输出结果
   cout << res << endl;

   return 0;
}