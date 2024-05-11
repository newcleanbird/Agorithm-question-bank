/*
424、虚拟游戏理财 / 最优投资方式
题目描述：
在一款虚拟游戏中生活，你必须进行投资以增强在虚拟游戏中的资产以免被淘汰出局。现有一家Bank，它提供有若干理财产品m，风险及投资回报不同，你有N（元）进行投资，能接受的总风险值为X。
你要在可接受范围内选择最优的投资方式获得最大回报。
说明：
在虚拟游戏中，每项投资风险值相加为总风险值；
在虚拟游戏中，最多只能投资2个理财产品；
在虚拟游戏中，最小单位为整数，不能拆分为小数；
投资额*回报率=投资回报

输入描述：
第一行：产品数(取值范围[1, 20])，总投资额(整数，取值范围[1, 10000])，可接受的总风险(整数，取值范围[1, 200])
第二行：产品投资回报率序列，输入为整数，取值范围[1,60]
第三行：产品风险值序列，输入为整数，取值范围[1,100]
第四行：最大投资额度序列，输入为整数，取值范围[1,10000]

输出描述：
每个产品的投资额序列
补充说明：
在虚拟游戏中，每项投资风险值相加为总风险值；
在虚拟游戏中，最多只能投资2个理财产品；
在虚拟游戏中，最小单位为整数，不能拆分为小数；
投资额*回报率=投资回报

收起
示例1
输入：
5 100 10
10 20 30 40 50
3 4 5 6 10
20 30 20 40 30
输出：
0 30 0 40 0
说明：
投资第二项30个单位，第四项40个单位，总的投资风险为两项相加为4+6=10

约束：
1. 风险总和不超过风险
2. 获得最大投资回报
3. 最多两项

思路：暴力枚举
一开始看题目还以为是一道二维背包DP，但是题目加了一个限制条件：最多只能投资两个理财产品，那么要么就是投资一个，要么就是投资两个，就分别枚举这两种情况，更新最大回报即可。
*/
#include<iostream>
#include<vector>
#include<algorithm>
#include<map>

using namespace std;

int main()
{
	// 输入数据
	int m, n, x; // 产品数 投资额 总风险
	cin >> m >> n >> x;
	vector<int> return_invest(m);	// 产品投资回报率
	vector<int> risk(m);			// 产品风险值
	vector<int> limit_invest(m);	// 最大投资额度
	for (int i = 0; i < m; i++)
	{
		cin >> return_invest[i];
	}
	for (int i = 0; i < m; i++)
	{
		cin >> risk[i];
	}
	for (int i = 0; i < m; i++)
	{
		cin >> limit_invest[i];
	}
	map<int, int> choose; // 最终投资序列和额度
	int max_return = 0; // 最大投资额
	// 计算
	// 投资单个项目
	for (int i = 0; i < m; i++)
	{
		if (risk[i] <= x)
		{
			int investI = min(limit_invest[i], n);	// 投资的额度不超过 投资额 和 最大投资额度
			if (investI * return_invest[i] > max_return)
			{
				max_return = investI * return_invest[i];
				choose = {pair<int, int>(i, investI)};
			}
		}
	}
	// 投资两个项目
	for (int i = 0; i < m; i++)
	{
		for (int j = 0; j < m; j++)
		{
			if (risk[i] + risk[j] <= x) // 满足风险
			{
				int investI, investII;	// i 和 j 的投资额
				if (return_invest[i] > return_invest[j])
				{
					investI = min(limit_invest[i], n);
					investII = min(limit_invest[j], n - investI);
				}
				else {
					investII = min(limit_invest[j], n);
					investI = min(limit_invest[i], n - investII);
				}
				if (investI * return_invest[i] + investII * return_invest[j] > max_return)
				{
					max_return = investI * return_invest[i] + investII * return_invest[j];
					choose = { pair<int, int>(i, investI), pair<int, int>(j, investII) };
				}
			}
		}
	}
	// 输出结果
	for (int i = 0; i < m; i++)
	{
		cout << choose[i] << " ";
	}
}