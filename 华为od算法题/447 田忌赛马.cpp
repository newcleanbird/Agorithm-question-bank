/*
447 田忌赛马
题目描述：
给定两个只包含数字的数组a，b，调整数组 a 里面数字的顺序，使得尽可能多的 a[i] > b[i]。数组  a和 b 中的数字各不相同。
输出所有可以达到最优结果的 a 数组的数量

输入描述：
输入的第一行是数组 a 中的数字，其中只包含数字，每两个数字之间相隔一个空格，a 数组大小不超过 10
输入的第二行是数组 b 中的数字，其中只包含数字，每两个数字之间相隔一个空格，b数组大小不超过 10

输出描述：
输出所有可以达到最优结果的 a 数组数量

示例1：
输入：
11 8 20
10 13 7

输出：
说明：
最优结果只有一个， a =[11,20,8]，故输出 1

示例2：
输入：
11 12 20
10 13 7

输出：
说明：有两个 a 数组的排列可以达到最优结果 [12,20,11]和11,20,12] ，故输出 2。

思路：全排列，C++中STL有实际的函数：next_permutation()
*/
#include<iostream>
#include<vector>
#include<algorithm>

using namespace std;

int count_win(vector<int>& a, vector<int>& b)
{
	int count = 0;
	for (int i = 0; i < a.size(); i++)
	{
		if (a[i] > b[i])
		{
			count++;
		}
	}
	return count;
}

int main()
{
	// 输入
	vector<int> a, b;
	int tmp;
	while (cin >> tmp)
	{
		a.push_back(tmp);
		if (cin.get() == '\n') break;
	}
	while (cin >> tmp)
	{
		b.push_back(tmp);
		if (cin.get() == '\n') break;
	}

	// 计算
	int max_count = 0;
	int res = 0;
	sort(a.begin(), a.end());
	do {
		int count = count_win(a, b);
		if (count > max_count)
		{
			max_count = count;
			res = 1;
		}
		else if (count == max_count)
		{
			res++;
		}
	} while (next_permutation(a.begin(), a.end()));

	cout << res;
}