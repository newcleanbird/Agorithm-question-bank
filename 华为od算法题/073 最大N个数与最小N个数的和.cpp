/*
最大N个数与最小N个数的和

题目描述：
给定一个数组，编写一个函数来计算它的最大N个数与最小N个数的和。你需要对数组进行去重。

说明：

数组中数字范围[0, 1000]

最大N个数与最小N个数不能有重叠，如有重叠，输入非法返回-1

输入非法返回-1

输入描述:

第一行输入M， M标识数组大小\n第二行输入M个数，标识数组内容

第三行输入N，N表达需要计算的最大、最小N个数

输出描述:

输出最大N个数与最小N个数的和。

示例1

输入输出示例仅供调试，后台判题数据一般不包含示例

输入

5

95 88 83 64 100

2

输出

342

说明

最大2个数[100,95],最小2个数[83,64], 输出为342。

示例2

输入输出示例仅供调试，后台判题数据一般不包含示例

输入

5
3 2 3 4 2
2

输出

-1

说明

最大2个数[4,3],最小2个数[3,2], 有重叠输出为-1。

思路：
		输入：依次输入到vector中，输入的时候进行查重
		对vector进行排序
		然后依次计算和，并判断是否越界
*/
#include<iostream>
#include<vector>
#include<algorithm>

using namespace std;

int main()
{
	int size;
	cin >> size;
	vector<int> vec;
	int tmp;
	while (size--)
	{
		cin >> tmp;
		if (find(vec.begin(), vec.end(), tmp) != vec.end())
		{
			continue;
		}
		vec.push_back(tmp);
	}
	int num;
	cin >> num;
	int min = 0;
	int sum_min = 0;
	int max = 0;
	int sum_max = 0;
	sort(vec.begin(), vec.end());
	for (int i = 0; i < num; i++)
	{
		min = vec[i];
		sum_min += vec[i];
	}
	int vec_size = vec.size();
	for (int i = 0; i < num; i++)
	{
		max = vec[vec_size - i - 1];
		sum_max += vec[vec_size - i - 1];
	}
	if (min >= max)
	{
		cout << -1;
	}
	else {
		cout << sum_min + sum_max;
	}
	
}