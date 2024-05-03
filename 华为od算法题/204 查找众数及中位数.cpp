/*
题目：
众数是指一组数据中出现次数量多的那个数，众数可以是多个。
中位数是指把一组数据从小到大排列，最中间的那个数，如果这组数据的个数是奇数，那最中间那个就是中位数，如果这组数据的个数为偶数，那就把中间的两个数之和除以2，所得的结果就是中位数。

查找整型数组中元素的众数并组成一个新的数组，求新数组的中位数。
输入描述
输入一个一维整型数组，数组大小取值范围
0＜N＜1000，数组中每个元素取值范围
0＜E＜1000

输出描述
输出众数组成的新数组的中位数

示例1
输入输出示例仅供调试，后台判题数据一般不包含示例
输入
10 11 21 19 21 17 21 16 21 18 15
输出
21

示例2
输入输出示例仅供调试，后台判题数据一般不包含示例
输入
2 1 5 4 3 3 9 2 7 4 6 2 15 4 2 4
输出
3

示例3
输入输出示例仅供调试，后台判题数据一般不包含示例
输入
5 1 5 3 5 2 5 5 7 6 7 3 7 11 7 55 7 9 98 9 17 9 15 9 9 1 39
输出
7
*/

#include<iostream>
#include<vector>
#include<map>
#include<algorithm>
#include <numeric> 

using namespace std;

bool cmp(pair<int, int> p1, pair<int, int> p2)
{
	return p1.second > p2.second;
}

int main()
{
	map<int, int> imap;
	int tmp;
	while (cin >> tmp)
	{
		imap[tmp]++;
		if (cin.get() == '\n') break;
	}
	vector<pair<int, int>> vec(imap.begin(), imap.end());
	sort(vec.begin(), vec.end(), cmp);
	
	vector<int> res;
	int max = (*vec.begin()).second;
	for (auto i : vec)
	{
		if (i.second == max)
		{
			res.push_back(i.first);
		}
	}
	cout << accumulate(res.begin(), res.end(), 0) / res.size();
}