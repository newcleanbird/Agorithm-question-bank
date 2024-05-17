/*
483、中文分词模拟器
题目描述：
给定一个连续不包含空格字符串，该字符串仅包含英文小写字母及英文文标点符号(逗号、分号、句号)，同时给定词库，对该字符串进行精确分词。
说明：
1.精确分词： 字符串分词后，不会出现重叠。即“ilovechina” ，不同词库可分割为 “i，love，china” “ilove，china”，不能分割出现重叠的"i，ilove，china",i重叠出现
2.标点符号不成词，仅用于断句
3.词库：根据外部知识库统计出来的常用词汇例：dictionary=["i","love","china","lovechina","ilove"],
4.分词原则：采用分词顺序优先且最长匹配原则
“ilovechina”，假设分词结果  [ i,ilove,lo,love,ch,china,lovechina ] 则输出 [ilove，china]
错误输出：[i,lovechina],            原因："ilove ">优先于 "lovechina"成词
错误输出：[i,love,china]            原因："ilove" >"i"  遵循最长匹配原则

输入描述：
字符串长度限制：0<length<256
词库长度限制：  1<length<100000
第一行输入待分词语句 "ilovechina"
第二行输入中文词库   "i,love,china,ch,na,ve,lo,this,is,the,word"

输出描述：
按顺序输出分词结果 "i,love,china"

示例1
输入：
ilovechina
i,love,china,ch,na,ve,lo,this,is,the,word

输出：
i,love,china

示例2
输入：
iat
i,love,china,ch,na,ve,lo,this,is,the,word,beauti,tiful,ful
输出：
i,a,t
说明：
单个字母，不在词库中且不成词则直接输出单个字母

示例3
输入：
ilovechina,thewordisbeautiful
i,love,china,ch,na,ve,lo,this,is,the,word,beauti,tiful,ful,beautiful
输出：
i,love,china,the,word,is,beautiful
说明：
标点符号为英文标点符号

解题思路：维护一个红黑树结构作为词库，降低查询的复杂度，然后遍历字符串，按照题目要求的长度优先方式，查询词库中是否含有这类词即可。注意判断标点的情况。
*/


#include<iostream>
#include<vector>
#include<unordered_set>
#include<string>
#include<sstream>

using namespace std;

int main()
{
	string word;	 // 输入待分词的词
	string word_library;	// 分词库
	unordered_set<string> library;

	cin >> word >> word_library;

	int max_word_size = 0;
	istringstream iss(word_library);
	string token;
	while (getline(iss, token, ','))
	{
		max_word_size = max(max_word_size, (int)token.size());
		library.insert(token);
	}

	vector<string> res;
	// 开始分词
	for (int i = 0; i < word.size(); i++)
	{
		// 如果不是字母，则跳过
		if (!isalpha(word[i]))
		{
			continue;
		}
		// 记录开始的位置
		int pos = i;
		string tmp;	// 存储当前匹配的字符
		string find_word;	// 存储找到的字符
		tmp += word[i];
		find_word = tmp;
		for (int j = i + 1; j - i + 1 <= max_word_size && j < word.size(); j++)
		{
			tmp += word[j];
			if (library.find(tmp) != library.end())
			{
				find_word = tmp; // 依次匹配，直到匹配到最长的单词。
				pos = j;	// 当前匹配的单词的最后的位置
			}
		}
		res.push_back(find_word);
		i = pos;
	}

	for (int i = 0; i < res.size(); i++)
	{
		cout << res[i];
		if (i != res.size() - 1)
		{
			cout << ",";
		}
	}
}