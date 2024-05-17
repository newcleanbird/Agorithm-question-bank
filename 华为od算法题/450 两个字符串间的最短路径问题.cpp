/*
450、两个字符串间的最短路径问题

题目描述：

给定两个字符串，分别为字符串A与字符串B。例如A字符串为ABCABBA，B字符串为CBABAC可以得到下图m*n的二维数组，定义原点为(0, 0)，终点为(m, n)，水平与垂直的每一条边距离为1，映射成坐标系如下图。

从原点(0, 0)到(0, A)为水平边，距离为1，从(0, A)到(A, C)为垂直边，距离为1；假设两个字符串同一位置的两个字符相同则可以作一个斜边，如(A, C)到(B, B)最短距离为斜边，距离同样为1。

作出所有的斜边如下图，(0, 0)到(B, B)的距离为 1个水平边 + 1个垂直边 + 1个斜边 = 3。
根据定义可知，原点到终点的最短距离路径如下图红线标记，最短距离为9：

输入描述：
空格分割的两个字符串A与字符串B，字符串不为“空串”，字符格式满足正则规则：[A-Z]，字符串长度 < 10000
输出描述：
原点到终点的最短距离

示例1
输入：
ABC ABC
输出：
3
说明：

示例2
输入：
ABCABBA CBABAC
输出：
9
*/

#include<iostream>
#include<string>
#include<vector>

using namespace std;

int main()
{
	string str1, str2;
	cin >> str1 >> str2;
	vector<vector<int>> map(str1.size()+1, vector<int>(str2.size()+1));
	// 初始化
	for (int i = 0; i <= str1.size(); i++)
	{
		map[i][0] = i;
	}
	for (int j = 0; j <= str2.size(); j++)
	{
		map[0][j] = j;
	}
	for (int i = 1; i <= str1.size(); i++)
	{
		for (int j = 1; j <= str2.size(); j++)
		{
			if (str1[i-1] == str2[j-1])
			{
				map[i][j] = min(min(map[i - 1][j], map[i][j - 1]), map[i-1][j-1]) + 1;
			}
			else {
				map[i][j] = min(map[i - 1][j], map[i][j - 1]) + 1;
			}
		}
	}
	/*for (auto i : map)
	{
		for (auto j : i)
		{
			cout << j << " ";
		}
		cout << endl;
	}*/
	cout << map[str1.size()][str2.size()];
}