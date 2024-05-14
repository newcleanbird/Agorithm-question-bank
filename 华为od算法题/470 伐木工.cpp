/*
470、伐木工
题目描述：
一根X米长的树木，伐木工切割成不同长度的木材后进行交易，交易价格为每根木头长度的乘积。规定切割后的每根木头长度都为正整数；也可以不切割，直接拿整根树木进行交易。请问伐木工如何尽量少的切割，才能使收益最大化？

输入描述：
木材的长度（X<=50）

输出描述：
输出最优收益时的各个树木长度，以空格分割，按升序排列

补充说明：
示例1
输入：
10
输出：
3 3 4
说明：
1. 一根2米长的树木，伐木工不切割，为2 * 1，收益最大为2
2. 一根4米长的树木，伐木工不需要切割为2 * 2，省去切割成本，直接整根树木交易，为4 * 1，收益最大为4
3. 一根5米长的树木，伐木工切割为2 * 3，收益最大为6
4. 一根10米长的树木，伐木工可以切割为方式一：3，4，3，也可以切割为方式二：3，2，2，3，但方式二伐木工多切割了一次，增加切割成本却卖了一样的价格，因此并不是最优收益。
*/


#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

struct Wood
{
	int price;
	vector<int> length;
};

int main()
{
	int n;	// 木材的长度
	cin >> n;
	vector<Wood> vec(n + 1);	// 从长度为0到长度为n

	// 初始化每个长度的木材价值和当前切割后的长度
	for (int i = 0; i <= n; i++)
	{
		vec[i].price = i;
		vec[i].length.push_back(i);
	}

	for (int i = 2; i <= n; i++)
	{
		for (int j = 1; j <= i; j++)
		{
			int price = vec[i - j].price * vec[j].price;
			if (vec[i].price < price || (vec[i].price == price && vec[i].length.size() > vec[i - j].length.size() + vec[j].length.size()))
			{
				vec[i].price = price;	// 更新价格
				// 更新切割方案
				vec[i].length = vec[i - j].length;
				vec[i].length.insert(vec[i].length.end(), vec[j].length.begin(), vec[j].length.end());
			}
		}
	}
	sort(vec[n].length.begin(), vec[n].length.end(), less<int>());
	for (int i = 0; i < vec[n].length.size(); i++)
	{
		cout << vec[n].length[i];
		if (i != vec[n].length.size() - 1)
		{
			cout << " ";
		}
	}
	cout << endl;
	cout << vec[n].price << endl;

}




















//class Wood {
//public:
//    int profit;
//    std::vector<int> slices;
//};
//
//int main() {
//    int x;  // X米长的树木
//    std::cin >> x;
//
//    std::vector<Wood> dp(x + 1);    // 存储每个长度的最大利润和对应的切割方案
//
//    // 初始化dp,dp[i]表示长度为i的木材的最大利润和切割方案。
//    for (int i = 0; i <= x; i++) {
//        dp[i].profit = i;
//        dp[i].slices.push_back(i);
//    }
//
//    for (int i = 2; i <= x; i++) {
//        for (int j = 1; j < i; j++) {
//            int profit = dp[j].profit * dp[i - j].profit;   // 计算将长度为j的木材和长度为i-j的木材切割后的利润
//
//            if (profit > dp[i].profit || (profit == dp[i].profit && dp[i].slices.size() > dp[j].slices.size() + dp[i - j].slices.size())) { // 如果新计算的利润大于当前最大利润，或者利润相等但切割后的段数更少，则更新dp[i]的信息。
//                dp[i].profit = profit;
//                dp[i].slices.clear();// 重置dp[i]的切割方案
//                dp[i].slices.insert(dp[i].slices.end(), dp[j].slices.begin(), dp[j].slices.end());  // 加入长度为j的最大切割方案
//                dp[i].slices.insert(dp[i].slices.end(), dp[i - j].slices.begin(), dp[i - j].slices.end());  // 加入长度为i-j的最大切割方案
//            }
//        }
//    }
//
//    std::sort(dp[x].slices.begin(), dp[x].slices.end());
//
//    std::ostringstream oss;
//    for (int slice : dp[x].slices) {
//        oss << slice << " ";
//    }
//
//    std::cout << oss.str() << std::endl;
//
//    return 0;
//}