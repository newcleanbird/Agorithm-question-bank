/*
猴子爬山
题目
一天一只顽猴想要从山脚爬到山顶，
途中经过一个有n个台阶的阶梯，
但是这个猴子有个习惯，每一次只跳1步或3步
试问？猴子通过这个阶梯有多少种不同的跳跃方式

输入
输入只有一个数n， 0 < n < 50
代表此阶梯有多个台阶

输出描述
有多少种跳跃方式

示例一
输入
50

输出
122106097

示例二
输入
3

输出
2

*/

#include <bits/stdc++.h>

using namespace std;

void backtracking(int target, int sum, int startindex)
{
    if(sum > target) return;
    if(sum == target)
    {
        result.push_back(path);
    }
    for(int i = startindex; i < 2; i++)
    {
        path.push_back(jump[i]);
        sum += jump[i];
        backtracking(target, sum, i);
        path.pop_back();
        sum -= jump[i];
    }
}

vector<int> path;
vector<vector<int>> result;
vector<int> jump = {1,3};

int main()
{
    int n;
    cin >> n;
    // 回溯(每次有两个选择，可以重复)
    // 集合(1,3)
    backtracking(n, 0, 0);
    cout << result.size();
    
    
}