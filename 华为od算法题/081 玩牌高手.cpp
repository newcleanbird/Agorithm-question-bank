/*
玩牌高手

题目描述
给定一个长度为n的整型数组，表示一个选手在n轮内可选择的牌面分数。选手基于规则选牌，

请计算所有轮结束后其可以获得的最高总分数。

选择规则如下：

在每轮里选手可以选择获取该轮牌面，则其总分数加上该轮牌面分数，为其新的总分数。
选手也可不选择本轮牌面直接跳到下一轮，此时将当前总分数还原为3轮前的总分数，若当前轮次小于等于3（即在第1、2、3轮选择跳过轮次），则总分数置为0。
选手的初始总分数为0，且必须依次参加每一轮。

输入描述
第一行为一个小写逗号分割的字符串，表示n轮的牌面分数，1<= n <=20。

分数值为整数，-100 <= 分数值 <= 100。

不考虑格式问题。

输出描述
所有轮结束后选手获得的最高总分数。

用例
输入	1,-5,-6,4,3,6,-2
输出	11
说明	无
*/

#include <iostream>
#include <string>
#include <vector>

using namespace std;

int main()
{
	// 输入
	string str;
	getline(cin, str);
	vector<int> vec;
	int start = 0;
	for (int i = 0; i < str.size(); i++)
	{
		if (str[i] == ',')
		{
			vec.push_back(stoi(str.substr(start, i - start + 1)));
			start = i + 1;
		}
	}
	vec.push_back(stoi(str.substr(start, str.size() - start + 1)));
	
	// 模拟
	int count = 0; // 当前总和
	vector<int> res(vec.size());
	// 单独处理前三轮
	for (int i = 0; i < 3; i++)
	{
		if (count + vec[i] <= 0)
		{
			count = 0;
			res[i] = count;
		}
		else {
			count += vec[i];
			res[i] = count;
		}
	}

	for (int i = 3; i < vec.size(); i++)
	{
		if (res[i - 3] > count + vec[i])
		{
			count = res[i - 3];
			res[i] = count;
		}
		else {
			count += vec[i];
			res[i] = count;
		}
	}
	cout << count;

}
