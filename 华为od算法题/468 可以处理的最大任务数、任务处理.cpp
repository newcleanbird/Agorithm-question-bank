/*
468、可以处理的最大任务数、任务处理
题目描述：
在某个项目中有多个任务（用 tasks 数组表示）需要您进行处理，其中 tasks[i] = [si, ei]，你可以在 si <= day <= ei 中的任意一天处理该任务。请返回你可以处理的最大任务数。
注：一天可以完成一个任务的处理。

输入描述：
第一行为任务数量 n，1 <= n <= 100000。后面 n 行表示各个任务的开始时间和终止时间，用 si 和 ei 表示，1 <= si <= ei <= 100000。

输出描述：
输出为一个整数，表示可以处理的最大任务数。


示例1
输入：
3
1 1
1 2
1 3
输出：
3
说明：
第一天处理任务 1，第二天处理任务 2，第三天处理任务 3。
*/
#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>

using namespace std;

struct Task
{
    int start;
    int end;
};

bool cmp(Task& a, Task& b)
{
    if (a.end != b.end)
    {
        return a.end < b.end;
    }
    else
    {
        return a.start < b.start;
    }
    
}

int main() {
    // 输入数据
    int n;
    cin >> n; // 输入任务数量
    vector<Task> tasks;
    int max_time = 0;   // 最后的活动结束时间
    for (int i = 0; i < n; i++) {
        int x, y;
        cin >> x >> y;
        tasks.push_back({ x, y });
        max_time = max(max_time, y);
    }
    sort(tasks.begin(), tasks.end(), cmp);

    // 执行
    priority_queue<int, vector<int>, greater<int>> pq;
    int task_loc = 0;
    int res = 0;
    for (int i = 0; i <= max_time; i++)
    {
        // 将符合时间的活动加入队列
        while (task_loc < n && tasks[task_loc].start <= i)
        {
            pq.push(tasks[task_loc].end);
            task_loc++;
        }
        // 去除不符合的活动移除队列
        while (!pq.empty() && pq.top() < i)
        {
            pq.pop();
        }
        // 执行任务
        if (!pq.empty())
        {
            pq.pop();
            res++;
        }
    }
    cout << res;
    return 0;
}