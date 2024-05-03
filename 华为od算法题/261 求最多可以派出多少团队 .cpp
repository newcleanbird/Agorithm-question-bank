/*
261 求最多可以派出多少团队
题目描述：
用数组代表每个人的能力，一个比赛活动要求参赛团队的最低能力值为N，每个团队可以由1人或2人组成，且1个人只能参加1个团队，请计算出最多可以派出多少支符合要求的团队？

输入描述：
5
3 1 5 7 9
8
第一行数组代表总人数，范围[1,500000]
第二行数组代表每个人的能力，每个元素的取值范围[1, 500000]，数组的大小范围[1,500000]
第三行数值为团队要求的最低能力值，范围[1, 500000]

输出描述：
3
最多可以派出的团队数量

示例1
输入：
5
3 1 5 7 9
8
输出：
3
说明：
3,5组成一队，1,7组成一队，9自己一个队，故输出3
*/
#include<iostream>
#include<vector>
#include<algorithm>

using namespace std;

int main()
{
	int n;	// 总人数
	cin >> n;
	vector<int> powers(n); // 代表每个人的能力
	for (int i = 0; i < n; i++)
	{
		cin >> powers[i];
	}
	int target;	// 团队要求的最低能力值
	cin >> target;

	// 求解
	int res = 0; // 最多可以派出的团队
	sort(powers.begin(), powers.end(), less<int>());
	int l = 0, r = powers.size() - 1;
	while (l < r)
	{
		if (powers[0] >= target)
		{
			res = powers.size();
			break;
		}
		if (powers[r] >= target)
		{
			res++;
			r--;
		}
		else {
			if (powers[l] + powers[r] >= target)
			{
				res++;
				l++;
				r--;
			}
			else {
				l++;
			}
		}
	}
	cout << res;
}
