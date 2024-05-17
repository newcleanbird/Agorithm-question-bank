/*
396、数据单元的变量替换 200
题目描述
将一个 csv 格式的数据文件中包含单元格引用的内容替换为对应的单元格内容的实际值。
comma separated values(CSV)逗号分隔值，csv 格式的数据文件使用逗号","作为分隔符将单元的内容进行分隔。

输入描述
1. 输入只有一行数据，用逗号分隔每个单元格，行尾没有引号。最多 26 个单元格，对应编号 A~Z 。
2. 每个单元格的内容包含字母和数字，以及用<>分隔的单元格引用，例如：<A> 表示引用的第一个单元的值。
3. 每个单元格的内容，在替换前和替换后均不超过 100 个字符。
4. 引用单元格的位置不受限制，允许排在后面的单元格被排在前面的单元格引用。
5. 不存在循环引用的情况，一个单元格只能引用一个其他单元格，比如下面这种场景是不存在的：
	A单元格:aCd<B>8u
	B单元格:kAy<A>dzqo
不存在多重’<>'的情况，一个单元格只能引用一个其他单元格，比如下面这种场景是不存在的：
A单元格:aCd8u
B单元格:kAydzqo
C单元格:y<<A><B>>d

输出描述
输出所有单元格展开后的内容，单元格之间用",“分隔，输入内容出现错误时，输出字符串”− 1 -1−1"表示出错

样例1
输入
1,2<A>00
输出
1,2100
说明：第二个单元中有对 A  单元的引用，A  单元格的值为 1 ，替换时，将 A 单元的内容替代 <A> 的位置，并知其他内容合并。

样例2
输入
1<B>2,1
输出
112,1
说明：第一个单元中有对 B 单元的引用，B BB 单元格的值为 1 ，替换时，将第二个数据单元的内容替代 <B>的位置，并与其他内容合并

样例3
输入
<A>
输出
-1

样例4
I<B>!,love<C>,china

*/
#include<iostream>
#include<vector>
#include<string>
#include<unordered_map>
#include<algorithm>

using namespace std;

int check_referce(string& str, unordered_map<char, string>& references)
{
	size_t pos1 = str.find('<');
	size_t pos2 = str.find('>');
	if (pos1 == str.npos)
	{
		return 0;	// 未找到reference
	}
	else if (pos2 - pos1 != 2)
	{
		return -1; // 输入错误
	}
	else if (references[str[pos1 + 1]] == str)
	{
		return -1;
	}
	else {
		return pos2;
	}
}

bool replace_referce(char cur, unordered_map<char, string>& references)
{
	int pos = references[cur].find('<');
	char tar = references[cur][pos+1];
	if (check_referce(references[tar], references) == 0)
	{
		references[cur].replace(references[cur].begin() + pos, references[cur].begin() + pos + 3, references[tar]);
	}
	else if (check_referce(references[tar], references) == -1)
	{
		return false;
	}
	else
	{
		replace_referce(tar, references);
		references[cur].replace(references[cur].begin() + pos, references[cur].begin() + pos + 3, references[tar]);
	}
	return true;
}

int main()
{
	string str;
	getline(cin, str);
	unordered_map<char, string> references;	// 字符对应字符串
	char id = 'A';
	string tmp;
	for (int i = 0; i <= str.size(); i++)
	{
		if (str[i] == ',' || i == str.size())
		{
			references[id] = tmp;
			tmp.clear();
			id++;
		}
		else {
			tmp += str[i];
		}
	}
	bool res = true;
	for (auto& i : references)
	{
		int check = check_referce(i.second, references);
		if (check == -1)
		{
			res = false;
			break;
		}
		else if (check == 0)
		{
			continue;
		}
		else {	// 找到referece，需要替换
			if (!replace_referce(i.first, references))
			{
				res = false;
				break;
			}
		}
	}
	if (res)
	{
		for (auto i : references)
		{
			if (i.first != 'A')
			{
				cout << ",";
			}
			cout << i.second;
		}
	}
	else {
		cout << -1;
	}
}