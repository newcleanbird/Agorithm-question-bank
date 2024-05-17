/*
最长的指定瑕疵度的元音子串

题目描述：
开头和结尾都是元音字母（aeiouAEIOU）的字符串为 元音字符串 ，其中混杂的非元音字母数量为其 瑕疵度 。比如:
·         “a” 、 “aa”是元音字符串，其瑕疵度都为0
·         “aiur”不是元音字符串（结尾不是元音字符）
·         “abira”是元音字符串，其瑕疵度为2
给定一个字符串，请找出指定瑕疵度的最长元音字符子串，并输出其长度，如果找不到满足条件的元音字符子串，输出0。
子串：字符串中任意个连续的字符组成的子序列称为该字符串的子串。

输入描述：
首行输入是一个整数，表示预期的瑕疵度flaw，取值范围[0, 65535]。
接下来一行是一个仅由字符a-z和A-Z组成的字符串，字符串长度(0, 65535]。

输出描述：
输出为一个整数，代表满足条件的元音字符子串的长度。

补充说明：

示例1
输入：
0
asdbuiodevauufgh
输出：
3
说明：
满足条件的最长元音字符子串有两个，分别为uio和auu，长度为3。

示例2
输入：
2
aeueo
输出：
0
说明：
没有满足条件的元音字符子串，输出0

示例3
输入：
1
aabeebuu
输出：
5
说明：
满足条件的最长元音字符子串有两个，分别为aabee和eebuu，长度为5

思路：直接两层for循环暴力解决
*/

#include<iostream>
#include<string>
#include<vector>
#include<algorithm>

using namespace std;

bool is_vowel(char ch)
{
	vector<int> vowel{ 'a','e', 'i', 'o', 'u', 'A', 'E', 'I', 'O', 'U'};
	if (find(vowel.begin(), vowel.end(), ch) != vowel.end())
	{
		return true;
	}
	else {
		return false;
	}
}

int main()
{
	int flaw;	// 混乱度
	string str;	// 输入字符串
	cin >> flaw;
	cin.get();
	getline(cin, str);
	vector<int> vec(str.size());
	for (int i = 0; i < str.size(); i++)
	{
		if (is_vowel(str[i]))
		{
			vec[i] = 0;
		}
		else {
			vec[i] = 1;
		}
	}
	int max = 0;
	int left = 0;
	int right = 0;
	for (int i = 0; i < vec.size(); i++)
	{
		if (vec[i] == 0)
		{
			int count = 0;
			for (int j = i + 1; j < vec.size(); j++)
			{
				if (vec[j] == 1)
				{
					count++;
				}
				if (count == flaw)
				{
					max = max < (j - i + 1) ? (j - i + 1) : max;
				}
			}
		}
	}
	cout << max;
}