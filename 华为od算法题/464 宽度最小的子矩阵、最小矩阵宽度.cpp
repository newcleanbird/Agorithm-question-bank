/*
464、 宽度最小的子矩阵、最小矩阵宽度
题目描述：
给定一个矩阵，包含N*M个整数，和一个包含K个整数的数组。
现在要求在这个矩阵中找一个宽度最小的子矩阵，要求子矩阵包含数组中所有的整数。

输入描述：
第一行输入两个正整数N，M，表示矩阵大小。
接下来N行M列表示矩阵内容。
下一行包含一个正整数K。
下一行包含K个整数，表示所需包含的数组，K个整数可能存在重复数字
所有输入数据小于1000。

输出描述：
输出包含一个整数，表示满足要求子矩阵的最小宽度，若找不到，输出-1.

补充说明：
示例1
输入：
2 5
1 2 2 3 1
2 3 2 3 2
3
1 2 3
输出：
2
说明：
矩阵第0、3列包含了1、2、3，矩阵第3、4列包含了1、2、3

示例2
输入：
2 5
1 2 2 3 1
1 3 2 3 4
3
1 1 4
输出：
5
说明：
矩阵第1、2、3、4、5列包含了1、1、4

思路：宽度最小,并非任意的矩形
*/
#include<iostream>
#include<vector>
#include<map>

using namespace std;

bool check(map<int, int>& cur_map, map<int, int>& target)
{
	for (auto& i : target)
	{
		if (cur_map[i.first] < i.second)	// 如果有项小于目标值
		{
			return false;
		}
	}
	return true;
}

int main()
{
	// 输入
	int n, m;	// N行M列
	cin >> n >> m;
	vector<vector<int>> vec(n, vector<int>(m));
	for (int i = 0; i < n; i++)
	{
		for (int j = 0; j < m; j++)
		{
			cin >> vec[i][j];
		}
	}
	int k;
	cin >> k;
	map<int, int> target;
	for (int i = 0; i < k; i++)
	{
		int tmp;
		cin >> tmp;
		target[tmp]++;
	}
	map<int, int> cur_map;	// 哈希记录当前需要的数据
	for (auto& i : target)
	{
		cur_map[i.first] = 0;
	}

	// 滑动窗口求解
	int min_length = m + 1;
	int l = 0;
	for(int r = 0; r < m; r++)
	{
		// 更新数据
		for (int i = 0; i < n; i++)
		{
			if (target.find(vec[i][r]) != target.end())
			{
				cur_map[vec[i][r]]++;	// 记录数据
			}
		}
		// 判断是否符合需要更新左边界并收集数据
		while (check(cur_map, target))
		{
			// 先更新最小数据
			min_length = min(min_length, r - l + 1);
			cout << "符合条件的l和r:" << l << " " << r << endl;

			// 更新左边界
			for (int i = 0; i < n; i++)
			{
				if (target.find(vec[i][l]) != target.end())
				{
					cur_map[vec[i][l]]--;	// 记录数据
				}
			}
			l++;
		}
	}
	cout << min_length;
}