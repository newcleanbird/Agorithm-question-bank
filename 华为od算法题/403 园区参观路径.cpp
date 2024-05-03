/*
403、园区参观路径
题目描述：园区某部门举办了Family Day，邀请员工及其家属参加；将公司园区视为一个矩形，起始园区设置在左上角，终点园区设置在右下角；家属参观园区时，只能向右和向下园区前进；求从起始园区到终点园区会有多少条不同的参观路径；

输入描述：第一行为园区长和宽；后面每一行表示该园区是否可以参观，0表示可以参观，1表示不能参观
输出描述：输出为不同的路径数量
补充说明：
    1 <= 园区长 <= 100
    1 <= 园区宽 <= 100

示例
示例1
输入：
3 3
0 0 0
0 1 0
0 0 0
输出：2
说明：

示例二
4 4
0 0 0 1 
0 0 0 0 
1 0 0 0 
0 0 0 0  

思路：
经典动态规划
*/
#include<iostream>
#include<vector>

using namespace std;

void print_garden(vector<vector<int>>& garden)
{
    for (auto i : garden)
    {
        for (auto j : i)
        {
            cout << j << " ";
        }
        cout << endl;
    }
    cout << endl;
}

void solution()
{
    int row, col;    // 行(宽) 和 列(长)
    cin >> col >> row;
    vector<vector<int>> garden(row + 1, vector<int>(col + 1, 0)); // garden[row][col];
    int tmp;
    for (int i = 1; i <= row; i++)
    {
        for (int j = 1; j <= col; j++)
        {
            cin >> tmp;
            garden[i][j] = tmp;
        }
    }

    vector<vector<int>> road(row + 1, vector<int>(col + 1, 0));
    // 初始化
    road[1][1] = 1;
    for (int i = 2; i <= row; i++)
    {
        if (garden[i][1] == 1)
        {
            continue;
        }
        else {
            road[i][1] = road[i - 1][1];
        }
    }
    //print_garden(road);
    for (int j = 2; j <= col; j++)
    {
        if (garden[1][j] == 1)
        {
            continue;
        }
        else {
            road[1][j] = road[1][j - 1];
        }
    }
    //print_garden(road);
    for (int i = 2; i <= row; i++)
    {
        for (int j = 2; j <= col; j++)
        {
            if (garden[i][j] == 1)
            {
                road[i][j] = 0;
            }
            else
            {
                road[i][j] = road[i - 1][j] + road[i][j - 1];
            }
            //print_garden(road);
        }
    }
    cout << road[row][col];
}

void solution_1()
{
    int n, m;
    cin >> n >> m;

    vector<vector<int>> grid(n, vector<int>(m));
    vector<vector<int>> dp(n, vector<int>(m, 0));

    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < m; ++j) {
            cin >> grid[i][j];
        }
    }

    for (int i = 0; i < n; ++i) {
        if (grid[i][0] == 1) break;
        dp[i][0] = 1;
    }

    for (int j = 0; j < m; ++j) {
        if (grid[0][j] == 1) break;
        dp[0][j] = 1;
    }

    for (int i = 1; i < n; ++i) {
        for (int j = 1; j < m; ++j) {
            if (grid[i][j] == 1) continue;
            dp[i][j] = dp[i][j - 1] + dp[i - 1][j];
        }
    }

    cout << dp[n - 1][m - 1] << endl;
}

int main()
{
    //solution();
    solution_1();
}