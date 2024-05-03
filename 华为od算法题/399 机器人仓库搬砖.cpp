/*
399、机器人仓库搬砖
题目描述：
机器人搬砖，一共有N堆砖存放在N个不同的仓库中，第i堆砖中有bricks[i]块砖头，要求在8小时内搬完。机器人每小时能搬砖的数量取决于有多少能量格，机器人一个小时中只能在一个仓库中搬砖，机器人的能量格每小时补充一次且能量格只在这一个小时有效，为使得机器人损耗最小化尽量减小每次补充的能量格数。
为了保障在8小时内能完成搬砖任务，请计算每小时给机器人充能的最小能量格数。
备注：
1、无需考虑机器人补充能量格的耗时；
2、无需考虑机器人搬砖的耗时；
3、机器人每小时补充能量格只在这一个小时中有效；
输入描述：
程序输入为“30 12 25 8 19”一个整数数组，数组中的每个数字代表第i堆砖的个数，每堆砖的个数不超过100。
输出描述：
输出在8小时内完成搬砖任务，机器人每小时最少需要充多少个能量格；
如果8个小时内无论如何都完成不了任务，则输出“-1”；
补充说明：
示例1
输入：
30 12 25 8 19
输出：
15
说明：
示例2
输入：
10 12 25 8 19 8 6 4 17 19 20 30
输出：
-1
说明：
砖的堆数为12堆存放在12个仓库中，机器人一个小时内只能在一个仓库搬砖，不可能完成任务。

解题思路：
1. 二分法搜索速度
速度的区间是[1, max],使用二分搜索速度
	如果速度可以搜索完，说明速度大了，需要降低速度，缩小最大速度至区间一半，如果不能，则提高最低速度至区间一半


*/
#include<iostream>
#include<vector>
#include<set>
#include<queue>

using namespace std;

bool can_fin(vector<int>& work, int count, int power)
{
	int hour = 0;
	for (auto i : work)
	{
		hour += (int)ceil((double)i / power);
	}
	return hour <= count;
}

// 使用二分搜索
int calculate(vector<int>& work, int count)
{
	if (work.size() > count) return -1;
	int left = 0;
	int right = *max_element(work.begin(), work.end());
	while (left < right)
	{
		int mid = (left + right) / 2;
		if (can_fin(work, count, mid))	// 能完成
		{
			right = mid;
		}
		else {
			left = mid + 1;
		}
	}
	return left;
}

// 使用优先队列二分搜索
int calculate_1(vector<int>& work, int count)
{
	priority_queue<double> mque(work.begin(), work.end());
	int max;
	while (mque.size() <= 8)
	{
		max = mque.top();
		mque.pop();
		mque.push(max/2);
		mque.push(max/2);
	}
	return ceil(mque.top());
}

int main()
{
	// 输入
	vector<int> work;
	int tmp;
	while (cin >> tmp)
	{
		work.push_back(tmp);
		if (cin.peek() == '\n')
			break;
	}
	int count = 8; // 需要8小时
	cout << calculate_1(work, count);
}