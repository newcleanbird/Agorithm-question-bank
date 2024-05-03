/*
409、传递悄悄话
题目描述：
给定一个二叉树，每个节点上站着一个人，节点数字表示父节点到该节点传递悄悄话需要花费的时间。
初始时，根节点所在位置的人有一个悄悄话想要传递给其他人，求二叉树所有节点上的人都接收到悄悄话花费的时间。

输入描述：

给定二叉树

0 9 20 -1 -1 15 7 -1 -1 -1 -1 3 2

注：-1表示空节点

输出描述：

返回所有节点都接收到悄悄话花费的时间38

补充说明：

示例1

输入：

0 9 20 -1 -1 15 7 -1 -1 -1 -1 3 2
输出：

38
说明：

*/
#include<iostream>
#include<vector>

using namespace std;

int res = 0;

void dfs(vector<int>& btree, int sum, int index)
{
	if (index >= btree.size() || btree[index] == -1)
	{
		return;
	}
	res = max(res, sum + btree[index]);
	dfs(btree, sum + btree[index], index * 2 + 1);	// 左子树
	dfs(btree, sum + btree[index], index * 2 + 2);	// 右子树
}

int main()
{
	// 输入
	vector<int> btree;
	int tmp;
	while (cin >> tmp)
	{
		btree.push_back(tmp);
		if (cin.peek() == '\n') break;
	}
	dfs(btree, 0, 0);
	cout << res;


}