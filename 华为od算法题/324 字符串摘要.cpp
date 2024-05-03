/*
324 字符串摘要
一、题目描述
给定一个字符串的摘要算法，请输出给定字符串的摘要值：

去除字符串中非字母的符号；
如果出现连续字符（不区分大小写），则输出该字符（小写）+ 连续出现的次数；
如果是非连续的字符（不区分大小写），则输出该字符（小写）+ 该字母之后字符串中出现该字符的次数；
对按照以上方式表示后的字符串进行排序，字母和紧随的数字作为一组进行排序，数字大的在前，数字相同时，按字母进行排序，字母小的在前；

二、输入描述
一行字符串。

三、输出描述
摘要字符串。

四、用例：
输入描述:
行字符串，长度为[1,200]

输出描述:
摘要字符串

示例一：
输入:
aabbcc
输出:
a2b2c2
说明:
第一个b非连续字母，该字母之后字符串中还出现了2次 (最后的两个Bb) ，所以输出b2a连续出现3次，输出a3，c非连续，该字母之后字符串再没有出现过c，输出c0Bb连续2次，输出b2，对b2a3c0b2进行排序，最终输出a3b2b2c0

示例二：
输入：
bAaAcBb
输出：
a3b2b2c0
说明：
bAaAcBb：
第一个 b 非连续字母，该字母之后字符串中还出现了 2 次（最后的两个 Bb），所以输出 b2，
a 连续出现 3 次，输出 a3，
c 非连续，该字母之后字符串再没有出现过 c，输出 c0
Bb 连续 2 次，输出 b2
对 b2a3c0b2 进行排序，最终输出 a3b2b2c0

示例三：
CbAaAcBbA
a3b2b2c1a0c0

五、解题思路
1、核心思路：
如果当前字母和上一个字母相同，该字母连续次数记为+1；
如果当前字母和上一个字母不同；
如果当前字符的连续次数大于1，表示是连续字符，输出即可；
如果只有1个，则要获取后面字符串中该字符的个数；
字母和紧随的数字作为一组进行排序，数字大的在前，数字相同时，按字母进行排序，字母小的在前；
2、具体思路如下：
输入一行字符串，不区分大小写；
定义一个数组c
*/

#include<iostream>
#include<string>
#include<map>
#include<vector>
#include<algorithm>

using namespace std;

bool compare(pair<char, int> p1, pair<char, int> p2)
{
	if (p1.second == p2.second)
	{
		return p1 < p2;
	}
	else
	{
		return p1.second > p2.second;
	}
	
}

int main()
{
	string str;
	getline(cin, str);
	// 去除字符串中的非字母
	string str_1;
	for (int i = 0; i < str.size(); i++)
	{
		if (isalpha(str[i]))
		{
			str_1 += tolower(str[i]);
		}
	}
	map<char, int> char_conut_map;
	vector<pair<char, int>> vec;
	char currentChar = str_1[str_1.size()-1];
	int count = 1;
	for (int i = str_1.size() - 2; i >= 0; i--)
	{
		if (str_1[i] == currentChar)	// 如果和上个字母相同，则增加字母统计
		{
			count++;	// 相同数字，计数+1
		}
		else {
			if (count == 1)	// 当前字符和下个字符不同，且下个字符是单个字符。此时应该将下个字符的结果加入结果集
			{
				count = char_conut_map[currentChar];				// 查询统计数据
				char_conut_map[currentChar] += count + 1;			// 更新统计数据
				vec.push_back(pair<char, int>(currentChar, count));	// 加入结果集
			}
			else {	// 统计连续字母的个数
				char_conut_map[currentChar] += count;
				vec.push_back(pair<char, int>(currentChar, count));	// 将之前的连续字母加入结果集
			}
			// 初始化统计记录
			currentChar = str_1[i];
			count = 1;
		}
		if (i == 0)	// 将最后一次的记录加入结果集
		{
			if (count == 1)	// 非连续字符
			{
				count = char_conut_map[str_1[i]];					// 查询统计数据
			}
			vec.push_back(pair<char, int>(str_1[i], count));	// 加入结果集
		}
	}
	sort(vec.begin(), vec.end(), compare);
	for (auto i : vec)
	{
		cout << i.first << i.second;
	}


}