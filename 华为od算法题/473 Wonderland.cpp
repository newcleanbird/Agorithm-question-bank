/*
473、Wonderland
题目描述：
Wonderland是小王居住地一家很受欢迎的游乐园。 Wonderland目前有4种售票方式，分别为一日票（1天）、三日票（3天）、周票（7天）和月票（30天）。
每种售票方式的价格将由一个数组给出，每种票据在票面时限内可以无限制的进行游玩。例如，小王在第10日买了一张三日票，小王可以在第10日、第11日和第12日进行无限制的游玩。
小王计划在接下来一年内多次游玩该游乐园。小王计划的游玩日期将由一个数组给出。 现在，请您根据给出的售票价格数组和小王计划游玩日期数组，返回完成游玩计划所需要的最低消费。

输入描述：
输入为2个数组
售票价格数组为costs，costs.length=4,默认顺序为一日票、三日票、周票和月票。
小王计划游玩日期数组为days，1<=days.length<=365,1<=days[i]<=365,默认顺序为升序。


输出描述：
完成游玩计划的最低消费

根据售票价格数组和游玩日期数组给出的信息，发现每次去玩的时候买一张一日票是最省钱的，所以小王会买8张一日票，每张5元，最低花费是40元。
示例1
输入：
5 14 30 100
1 3 15 20 21 200 202 230
输出：

40
说明：
*/

#include<iostream>
#include<vector>

using namespace std;

int main()
{
	// 输入
	vector<int> costs(4);
	vector<int> days;
	int min_cost = INT_MAX;	// 票面最低价
	for (int i = 0; i < 4; i++)
	{
		cin >> costs[i];
		min_cost = min(min_cost, costs[i]);
	}
	int tmp;
	while (cin >> tmp)
	{
		days.push_back(tmp);
		if (cin.get() == '\n') break;
	}


	// 初始化dp
	int n = days[days.size() - 1];	// 最大游玩日期
	// 一维动态规划
	vector<int> dp(n + 1, 0);
	dp[0] = 0;
	for (int i = 0; i < days.size(); i++)
	{
		int day = days[i];
		dp[day] = min_cost;
	}
	for (int i = 1; i <= n; i++)
	{
		int cur_cost = dp[i - 1] + dp[i];
		dp[i] = cur_cost;	// 初始化当前的价格
		if (i - 1 > 0)	// 一日票
		{
			int cost1 = dp[i-1] + costs[0];
			dp[i] = min(cur_cost, cost1);
		}
		if (i - 3 > 0)
		{
			int cost3 = dp[i - 2] + costs[1];
			dp[i] = min(cur_cost, cost3);
		}
		if (i - 7 > 0)
		{
			int cost7 = dp[i - 6] + costs[2];
			dp[i] = min(cur_cost, cost7);
		}
		if (i - 30 > 0)
		{
			int cost30 = dp[i - 29] + costs[3];
			dp[i] = min(cur_cost, cost30);
		}
	}
	cout << dp[n];

}