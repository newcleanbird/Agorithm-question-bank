/*
42 GPU算力问题
题目描述
为了充分发挥GPU算力，需要尽可能多的将任务交给GPU执行，现有一个任务数组，数组元素表示在这1s内新增的任务个数，且每秒都有新增任务。假设GPU最多一次执行n个任务，一次执行耗时1s，在保证GPU不空闲的情况下，最少需要多长时间执行完成。

输入描述
第一个参数为GPU最多执行的任务个数，取值范围[1,1 0000]
第二个参数为任务数组的长度，取值范围[1,1 0000]
第三个参数为任务数组，数字范围[1,1 0000]

输出描述
执行完所有任务最少需要多少秒

示例1
输入
3
5
1 2 3 4 5
输出
6

示例2
输入
4
5
5 4 1 1 1
输出
5

思考：
按照每秒给gpu的任务数模拟过程，每秒遍历任务数组，遍历完后计算剩余计算时间。

*/
#include<iostream>
#include<vector>


using namespace std;

int main()
{
	int m_work;	// 每秒gpu最大任务量
	int w_len;	// 任务数组长度
	cin >> m_work >> w_len;
	vector<int> vec(w_len);
	for (auto& i : vec)
	{
		cin >> i;
	}

	int time = 0;	// 总时间
	int remain = 0;	// 剩余的时间
	for (auto i : vec)
	{
		if (remain + i > m_work)
		{
			remain = remain + i - m_work;
		}
		else {
			remain = 0;
		}
		time++;
	}
	// 修正时间
	time += ceil((double)remain / m_work);
	cout << time;

}