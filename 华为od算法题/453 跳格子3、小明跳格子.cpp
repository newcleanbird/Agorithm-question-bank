///*
//453 跳格子3、小明跳格子
//题目描述：
//小明和朋友们一起玩跳格子游戏，每个格子上有特定的分数，score[] = [1 -1 -6 7 -17 7]，从起点score[0]开始，每次最大跳的步长为k，请你返回小明跳到终点score[n-1]时，能得到的最大得分。
//注：
//格子的总长度和步长的区间在 [1,  100000]；
//每个格子的分数在[-10000, 10000]区间中；
//
//输入描述：
//6					// 第一行输入总的格子数量
//1 -1 -6 7 -17 7		// 第二行输入每个格子的分数score[]
//2					// 第三行输入最大跳的步长k
//输出描述：
//14					// 输出最大得分数，小明从起点score[0]开始跳，第一次跳score[1], 第二次跳到score[3],第三次跳到score[5]，因此得到的最大的得分是score[0] + score[1] + score[3] + score[5] = 14
//
//示例1
//输入：
//6
//1 -1 -6 7 -17 7
//2
//输出：
//14
//*/
//#include<iostream>
//#include<vector>
//#include<string>
//#include<algorithm>
//
//using namespace std;
//
//int main()
//{
//	int n;	// 总的格子数量
//	cin >> n;
//	vector<int> scores(n+1);
//	for (int i = 1; i <= n; i++)
//	{
//		cin >> scores[i];
//	}
//	int k;	// 最大跳的步长
//	cin >> k;
//
//	// 计算
//	vector<int> dp(n+1);
//	//for (int i = 1; i < k; i++)	// 初始化
//	//{
//	//	dp[i] = scores[i];
//	//}
//	for (int i = 1; i <= n; i++)
//	{
//		int max_dp = -10000;
//		for (int j = i-1; j >= i - k && j>=0; j--)
//		{
//			max_dp = max(max_dp, dp[j]);
//		}
//		dp[i] = max_dp + scores[i];
//	}
//	/*for (auto i : dp)
//	{
//		cout << i << " ";
//	}*/
//	cout << dp[n];
//
//}