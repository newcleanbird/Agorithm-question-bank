/*
402、题目描述：在一棵树中，每个节点代表一个家庭成员，节点的数字表示其个人的财富值，一个节点及其直接相连的子节点被定义为一个小家庭。
现给你一棵树，请计算出最富裕的小家庭的财富和。
输入描述：第一行为一个数N，表示成员总数，成员编号1-N，1<=N<=1000
第二行为N个空格分隔的数，表示编号1-N的成员的财富值。0<=财富值<=1000000
接下来N-1行，每行两个空格分隔的整数(N1,N2)，表示N1是N2的父节点。
输出描述：
最富裕的小家庭的财富和
补充说明：

示例1
输入：
4
100 200 300 500
1 2
1 3
2 4
输出：

700
说明：
成员1,2,3组成的小家庭财富值为600
成员2,4组成的小家庭财富值为700

示例2
输入：
4
100 200 300 500
1 2
1 3
1 4
输出：
1100
说明：
成员1,2,3,4组成的小家庭财富值为1100

思路：
想想应该怎么找家庭：
如果数组一保存钱
数组二保存家庭关系

*/
#include<iostream>
#include<vector>

using namespace std;

// 没用上
struct mem
{
	int num;
	int father;
	int wealth;
};

int main()
{
	int n;
	cin >> n;
	int num = n;
	vector<int> wealth(n+1, 0);
	int tmp;
	for(int i = 1; i <= n; i++)
	{
		cin >> tmp;
		wealth[i] = tmp;
	}
	vector<int> father(n+1, 0);
	int fa, me;
	for(int i = 1; i < n; i++)
	{
		cin >> fa >> me;
		father[me] = fa;
	}
	vector<int> result(n, 0); // 保存以每个人为父亲的家庭的钱
	int max_family_wealth = 0;
	for (int i = 1; i <= n; i++)
	{
		int family_wealth = 0;
		family_wealth += wealth[i];
		for (int j = 1; j <= n; j++)
		{
			if (i == father[j])	// 如果该节点的父亲是i，则说明是同一个家
			{
				family_wealth += wealth[j];
			}
		}
		max_family_wealth = max_family_wealth > family_wealth ? max_family_wealth : family_wealth;
	}
	cout << max_family_wealth;
	
}