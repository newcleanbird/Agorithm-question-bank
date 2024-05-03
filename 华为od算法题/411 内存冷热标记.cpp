/*
411、内存冷热标记
题目描述：
现代计算机系统中通常存在多级的存储设备，针对海量workload的优化的一种思路是将热点内存页优先放到快速存储层级，这就需要对内存页进行冷热标记。
一种典型的方案是基于内存页的访问频次进行标记，如果统计窗口内访问次数大于等于设定阈值，则认为是热内存页，否则是冷内存页。
对于统计窗口内跟踪到的访存序列和阈值，现在需要实现基于频次的冷热标记。内存页使用页框号作为标识。

输入描述：
第一行为输入为N，表示访存序列的记录条数，0＜N≤10000
第二行为访存序列，空格间隔的N个内存页框号，页框号范围0-65535，同一页框号可能重复出现，出现的次数即为对应页框号的频次。第三行为热内存页的频次阈值T，正整数，范围1≤T≤10000

输出描述：
第一行输出标记为热内存的内存页个数，如果没有被标记为热内存的，则输出0。
如果第一行>0，则接下来按照访问频次降序输出内存页框号，一行一个，频次一样的页框号，页框号小的排前面。

补充说明：
示例1
输入：
10
1 2 1 2 1 2 1 2 1 2
5
输出：
2
1
2
说明：
内存页1和内存页2均被访问了5次，达到了阈值5，因此热内存页有2个。内存页1和内存页2的访问频次相等，页框号小的排前面。

示例2
输入：
5
1 2 3 4 5
3
输出：
0
说明：
访存跟踪里面访问频次没有超过3的，因此热内存页个数为0。
*/

#include<iostream>
#include<vector>
#include<set>
#include<map>
#include<algorithm>

using namespace std;

bool cmp(pair<int, int> p1, pair<int, int> p2)
{
	if (p1.second != p2.second)
	{
		return p1.first < p2.first;
	}
	else {
		return p1.second > p2.second;
	}
}

int main()
{
	int n;
	cin >> n;
	map<int, int> spage;
	int tmp;
	for (int i = 0; i < n; i++)
	{
		cin >> tmp;
		spage[tmp]++;
	}
	int T;
	cin >> T;
	vector<pair<int, int>> pages(spage.begin(), spage.end());
	sort(pages.begin(), pages.end(), cmp);
	int count = 0;
	for (auto i : pages)
	{
		if (i.second >= 5)
		{
			count++;
		}
	}
	cout << count << endl;
	for (int i = 0; i < count; i++)
	{
		cout << pages[i].first << endl;
	}
}