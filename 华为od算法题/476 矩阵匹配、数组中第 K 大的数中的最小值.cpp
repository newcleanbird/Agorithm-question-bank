/*
476、矩阵匹配、数组中第 K 大的数中的最小值
题目描述：
从一个N*M（N<=M)的矩阵中选出N个数，任意两个数字不能在同一行或同一列，求选出来的N个数中第K大的数字的最小值是多少。

输入描述：
输入矩阵要求：1<=K<=N<=M<=150

输入格式：
N M K
N*M矩阵

输出描述：
N*M的矩阵中可以选出M!/N!种组合数组，每个组合数组中第K大的数中的最小值。无需考虑重复数字，直接取字典排序结果即可。

补充说明：注意：结果是第K大的数字的最小值
示例1
输入：
3 4 2
1 5 6 6
8 3 4 3
6 8 6 3
输出：3
说明：N*M的矩阵中可以选出M!/N!种组合数组，每个组合数组中第K大的数中的最小值；上述输入中选出的数组组合为1,3,6; 1,3,3; 1,4,8; 1,4,3;......上述输入样例中选出的组合数组有24种，最小数组为1,3,3，则2大的最小值为3

理解：每行选一个数，列不冲突

*/

#include<iostream>
#include<vector>
#include<algorithm>

using namespace std;

int N, M, K;	// N*M矩阵 第K大
vector<int> nums;
int res = INT_MAX;
vector<bool> vis;
vector<vector<int>> vec;

void dfs(int row)
{
	if (nums.size() == N)
	{
		vector<int> sort_nums(nums);
		sort(sort_nums.begin(), sort_nums.end(), greater<int>());
		res = min(res, sort_nums[K-1]);	// 第K大是数组中的第k-1位
		return;
	}
	for (int j = 0; j < M; j++)
	{
		if (vis[j] == true) continue;
		vis[j] == true;
		nums.push_back(vec[row][j]);
		dfs(row + 1);
		vis[j] == false;
		nums.pop_back();
	}
}

int main()
{
	cin >> N >> M >> K;
	vec.resize(N, vector<int>(M, 0));
	vis.resize(M,false); // 用来标记行是否使用
	for (int i = 0; i < N; i++)
	{
		for (int j = 0; j < M; j++)
		{
			cin >> vec[i][j];
		}
	}

	// 计算
	dfs(0);
	cout << res;
}