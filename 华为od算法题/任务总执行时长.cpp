/*
任务总执行时长

任务编排服务负责对任务进行组合调度。
参与编排的任务有两种类型，其中一种执行时长为taskA，另一种执行时长为taskB。
任务一旦开始执行不能被打断，且任务可连续执行。
服务每次可以编排num个任务。请编写一个方法，生成每次编排后的任务所有可能的总执行时长。
输入描述
第1行输入分别为第1种任务执行时长taskA，
第2种任务执行时长taskB，
这次要编排的任务个数num，以逗号分隔。
输出描述
数组形式返回所有总执行时时长，需要按从小到大排列。
示例1 输入输出示例仅供调试，后台判题数据一般不包含示例
输入
1,2,3
输出
[3, 4, 5, 6]
*/

#include<bits/stdc++.h>

using namespace std;

int main()
{
    int task1,task2,N;
    cin >> task1 >> task2 >> N;
    set<int> set_time;
    int temp_time;
    for(int i = 0; i <= N; i++){
        int j = N - i;
        temp_time = task1 * i + task2 * (j);
        set_time.insert(temp_time);
        // cout << i << " " << j << " " << temp_time << endl;
    }
    vector<int> arr_time(set_time.begin(), set_time.end());
    for(auto i : arr_time)
    {
        cout << i << " ";
    }
    system("pause");

}