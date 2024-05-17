/*
443、贪吃的猴子
题目描述：
一只贪吃的猴子，来到一个果园，发现许多串香蕉排成一行，每串香蕉上有若干根香蕉。每串香蕉的根数由数组numbers给出。猴子获取香蕉，每次都只能从行的开头或者末尾获取，并且只能获取N次，求猴子最多能获取多少根香蕉。
输入描述：
第一行为数组numbers的长度
第二行为数组numbers的值每个数字通过空格分开
第三行输入为N，表示获取的次数

输出描述：
按照题目要求能获取的最大数值
补充说明：
1<= numbers.length <= 100000
1<= numbers[i] <= 100
1 <= N <= numbers.length

示例1
输入：
7
1 2 2 7 3 6 1
3
输出：
10
说明：
第一次获取香蕉，无论是从行的开头或者末尾获取，得到的香蕉根数目为1 。但是，从行末尾获取能获取到最优的策略，后面可以直接得到香蕉根数目6和3。因此最终根数为1+6+3 = 10

示例2
输入：
3
1 2 3
3
输出：
6
说明：
全部获取所有的香蕉，因此最终根数为1+2+3 = 6

示例3
输入：
4
4 2 2 3
2
输出：
7
说明：
第一次获取香蕉为行的开头，第二次获取为行的末尾，因此最终根数为4+3 = 7

思路：暴力枚举+前缀和
*/
#include<iostream>
#include<vector>

using namespace std;

int main()
{
	int n;
	cin >> n;
	vector<int> numbers(n+1);
	vector<int> pre(n+1);	// 前缀和
	for (int i = 1; i <= n; i++)
	{
		cin >> numbers[i];
		pre[i] = pre[i - 1] + numbers[i];
	}
	int m = 0;
	cin >> m;	// 总共摘的个数
	// 计算
	int max_sum = 0;
	int sum = 0;
	for (int i = 0; i <= m; i++)
	{
		int r = m - i;	 // 尾部摘的数量
		int res = pre[i] + pre[n] - pre[n - r];
		max_sum = max(res, max_sum);
	}
	cout << max_sum;

}