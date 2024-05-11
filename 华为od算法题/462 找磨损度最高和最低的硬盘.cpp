/*
462、 找磨损度最高和最低的硬盘
题目描述
存储阵列上使用的一批固态硬盘，根据硬盘磨损值给定一个数组endurances,数组中每个元素表示单块硬盘的磨损度(0到10000之间)。磨损度越大，表示此盘需要更换的概率越高。需要找出磨损度最高三块盘下标和磨损度最低的三块盘下标。
输入描述
一组硬盘磨损度的数组。
说明:
(1) 数组endurances中无重复值
(2) 数组的长度范围:[6,200]
(3) 数组的下标从0开始。
输出描述
第一行:磨损度最高三块盘下标，按下标升序展示
第二行:磨损度最低的三块盘下标，按下标升序展示

输入：
1 50 40 68 72 86 35 14 87 99 63 75
输出：
5 8 9
0 6 7

输入：
23 34 56 12 11 10
输出：
0 1 2
3 4 5

*/

#include<iostream>
#include<vector>
#include<algorithm>

using namespace std;

struct disk
{
	int val;
	int seq;
};

bool cmp(disk& a, disk& b)
{
	if (a.val != b.val)
	{
		return a.val < b.val;
	}
	else {
		return a.seq < b.seq;
	}
}

int main()
{
	vector<disk> endurances;
	int t_value;
	int i = 0;
	while(cin >> t_value)
	{
		endurances.push_back({ t_value, i++ });
		if (cin.peek() == '\n')
		{
			break;
		}
	}
	sort(endurances.begin(), endurances.end(), cmp);
	vector<int> biggest;	// 升序
	vector<int> smallest;	// 升序
	for (int i = endurances.size() - 1; i >= endurances.size() - 3; i--)
	{
		biggest.push_back(endurances[i].seq);
	}
	for (int i = 0; i <= 2; i++)
	{
		smallest.push_back(endurances[i].seq);
	}

	sort(biggest.begin(), biggest.end(), less<int>());	// 升序
	sort(smallest.begin(), smallest.end(), less<int>());

	for (auto i : biggest) cout << i << " ";
	cout << endl;
	for (auto i : smallest) cout << i << " ";
	cout << endl;


}