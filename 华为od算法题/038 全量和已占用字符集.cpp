/*
038 全量和已占用字符集.cpp

题目描述
给定两个字符集合，一个是全量字符集，一个是已占用字符集，已占用字符集中的字符不能再使用。
要求输出剩余可用字符集。

输入描述
输入一个字符串 一定包含@，@前为全量字符集 @后的为已占用字符集
已占用字符集中的字符一定是全量字符集中的字符
字符集中的字符跟字符之间使用英文逗号隔开
每个字符都表示为字符+数字的形式用英文冒号分隔，比如a:1标识一个a字符
字符只考虑英文字母，区分大小写
数字只考虑正整型 不超过100
如果一个字符都没被占用 @标识仍存在，例如 a:3,b:5,c:2@

输出描述
输出可用字符集
不同的输出字符集之间用回车换行
注意 输出的字符顺序要跟输入的一致，如下面用例不能输出b:3,a:2,c:2
如果某个字符已全部占用 则不需要再输出

用例
输入
a:3,b:5,c:2@a:1,b:2

输出
a:2,b:3,c:2

说明
全量字符集为三个a，5个b，2个c
已占用字符集为1个a，2个b
由于已占用字符不能再使用
因此剩余可用字符为2个a，3个b，2个c
因此输出a:2,b:3,c:2

*/



#include<iostream>
#include<string>
#include<vector>
#include<unordered_map>

using namespace std;

int main()
{
	// 输入
	string str;
	getline(cin, str);

	// 分割字符串并依次存入
	int seq = str.find('@');
	string str1 = str.substr(0, seq) + ',';
	string str2 = str.substr(seq+1) + ',';

	unordered_map<string, int> ump;
	string t_str;
	int t_i = 0;
	seq = 0;
	// 输入
	for (int i = 0; i < str1.size(); i++)
	{
		if (str1[i] == ':')
		{
			t_str = str1[i - 1];
			seq = i;
		}
		if (str1[i] == ',')
		{
			//string s = str1.substr(seq, i - seq - 1);
			t_i = stoi(str1.substr(seq+1, i - seq - 1));
			ump.insert(pair<string, int>(t_str, t_i));
		}
	}

	// 删除
	t_i = 0;
	seq = 0;
	for (int i = 0; i < str2.size(); i++)
	{
		if (str2[i] == ':')
		{
			t_str = str2[i - 1];
			seq = i;
		}
		if (str2[i] == ',')
		{
			t_i = stoi(str2.substr(seq+1, i - seq - 1));
			ump[t_str] -= t_i;
		}
	}

	for (auto i : ump)
	{
		cout << i.first << ":" << i.second << ",";
	}
} 