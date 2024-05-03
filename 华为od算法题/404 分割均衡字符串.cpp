/*
404、 分割均衡字符串
题目描述：
均衡串定义：字符串只包含两种字符，且两种字符的个数相同。
给定一个均衡字符串，请给出可分割成新的均衡子串的最大个数。
约定字符串中只包含大写的'X'和'Y'两种字符。

输入描述：
均衡串：XXYYXY
字符串的长度[2,10000]。给定的字符串均为均衡串。

输出描述：
可分割为两个子串：
XXYY
XY

补充说明：
分割后的子串，是原字符串的连续子串。

示例1
输入：
XXYYXY
输出：
2
说明：

思路：
	问题：分割后的子串中X和Y的数量一致
	要求分割后的子串不可再分！！！
*/
#include<iostream>
#include<string>

using namespace std;

int main()
{
	string str;
	getline(cin, str);
	int count = 0;
	int res = 0;
	for (int i = 0; i < str.size(); i++)
	{
		if (str[i] == 'X')
		{
			count++;
		}
		if (str[i] == 'Y')
		{
			count--;
		}
		if (count == 0)
		{
			res++;
		}
	}
	cout << res;
}


