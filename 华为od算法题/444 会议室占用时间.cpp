/*
444、会议室占用时间
题目：
现有若干个会议，所有会议共享一个会议室，用数组表示各个会议的开始时间和结束时间，格式为:
[[会议1开始时间，会议1结束时间]，[会议2开始时间，会议2结束时间]]
请计算会议室占用时间段。

输入描述
[[会议1开始时间，会议1结束时间]，[会议2开始时间，会议2结束时间]]

备注
会议室个数范围: [1,100]
会议室时间段: [1,24]

输出描述
输出格式预输入一致,具体请看用例
[[会议开始时间，会议结束时间]，[会议开始时间，会议结束时间]]

示例1
输入:
[[1,4], [2,5],[7,9], [14,18]]
输出
[[1,5], [7,9],[14,18]]
说明:
时间段[1,4]和[2,5]重叠，合并为[1,5]

示例2
输入:
[[1,4],[4,5]]
输出:
[[1,5]]
本题为leetcode模式，实现给定的函数即可。
int[][] merge(int[][] roomTimes) {

思路：归并Leetcode 56. 合并区间
先对所有段按左端点排序，保证后遍历的段的左端点小于先遍历的左端点，然后只需要判断当前遍历的段的左端点是否比merge好的段中的右端点小即可。
}
*/

#include<iostream>
#include<string>
#include<vector>
#include<queue>
#include<algorithm>

using namespace std;

bool cmp(vector<int>& a, vector<int>& b)
{
	if (a[0] != b[0])
	{
		return a[0] < b[0];
	}
	else {
		return a[1] < b[1];
	}
}

int main()
{
	/*string str;
	getline(cin, str);*/
	vector<vector<int>> rooms = { {1,4},{2,5}, {7,9}, {14,18} };
	/*queue<int> q;
	for (auto i : str)
	{
		if (isdigit(i))
		{
			q.push(i);
		}
	}
	while (!q.empty())
	{
		int a = q.front(); q.pop();
		int b = q.front(); q.pop();
		rooms.push_back(vector<int>{a, b});
	}*/

	// 计算
	sort(rooms.begin(), rooms.end(), cmp);
	vector<vector<int>> merge;
	for (int i = 0; i < rooms.size(); i++)
	{
		int l = rooms[i][0];
		int r = rooms[i][1];
		if (merge.empty() || merge.back()[1] < l)
		{
			merge.push_back({ l, r });
		}
		else {
			merge.back()[1] = max(merge.back()[1], r);
		}
	}
	for (int i = 0; i < merge.size(); i++)
	{
		if (i == 0) cout << "[";
		if (i > 0) cout << ",";
		cout << "[" << merge[i][0] << "," << merge[i][1] << "]"; 
		if (i == merge.size() - 1) cout << "]";
	}

}