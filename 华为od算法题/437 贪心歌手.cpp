/*
437、贪心歌手
题目描述：
一个歌手准备从A城去B城参加演出。
1) 按照合同，他必须在T天内赶到。
2) 歌手不能往回走。
3) 每两座城市之间需要的天数都可以提前获知。
4) 歌手在每座城市都可以在路边卖唱赚钱。经过调研，歌手提前获知了每座城市卖唱的收入预期：如果在一座城市第一天卖唱可以赚M，后续每天的收入会减少D（第二天赚的钱是M – D，第三天是M-2D…）。如果收入减到0就不会再少了。
5) 歌手到达后的第二天才能开始卖唱。如果今天卖过唱，第二天才能出发。

贪心的歌手最多可以赚多少钱？

输入描述：
第一行两个数字 T和N，中间用空格隔开。
T代表总天数；
N代表路上经过N座城市；
0 < T < 1000, 0 < N < 100
第二行N+1个数字，中间用空格隔开。
代表每两座城市之间耗费的时间。
其总和<=T。
接下来N行，每行两个数字M和D，中间用空格隔开。
代表每个城市的收入预期。
0 < M < 1000, 0 < D < 100

输出描述：一个数字。代表歌手最多可以赚多少钱。以回车结束。

示例1
输入：
10 2
1 1 2
120 20
90 10

输出：540

说明：
总共10天，路上经过2座城市。
路上共花1+1+2=4天。
剩余6天最好的计划是在第一座城市待3天，在第二座城市待3天。
在第一座城市赚的钱：120+100+80= 300.
在第二座城市赚的钱：90+80+70 =240.
一共300 + 240 = 540。

思路：贪心 or 优先队列
*/
#include<iostream>
#include<vector>
#include<queue>

using namespace std;

struct income
{
	int M;	// 第一天收入
	int D;	// 后续衰减

	bool operator<(const income& b) const
	{
		return this->M == b.M ? this->D > b.D : this->M < b.M;
	}
	bool operator>(const income& b) const
	{
		return this->M == b.M ? this->D > b.D : this->M > b.M;
	}
};

bool cmp(income& a, income& b)
{
	if (a.M != b.M)
	{
		return a.M > b.M;
	}
	else
	{
		return a.D > b.D;
	}
}

int main()
{
	// 输入
	int t, n;	// t:代表总天数 N代表路上经过N座城市；
	cin >> t >> n;
	cin.get();
	vector<int> days(n + 1);	// 每两座城市之间耗费的时间
	int tmp;
	int count_day = 0;
	for (int i = 0; i < n + 1; i++)
	{
		cin >> tmp;
		days[i] = tmp;
		count_day += tmp;
	}
	cin.get();
	int m, d;
	vector<income> vec(n);	// 每个城市的收入
	for (int i = 0; i < n; i++)
	{
		cin >> vec[i].M >> vec[i].D;
	}
	// 计算
	int remain_time = t - count_day;	// 实际可用的时间
	int income_count = 0;	// 总收入
	priority_queue<income, vector<income>,  less<income>> q(vec.begin(), vec.end());
	while (remain_time--)
	{
		income_count += q.top().M;
		income tmp = q.top();	q.pop();
		tmp.M -= tmp.D;
		q.push(tmp);
	}
	cout << income_count;
}
