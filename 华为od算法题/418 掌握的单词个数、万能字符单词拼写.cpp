///*
//418、掌握的单词个数、万能字符单词拼写
//题目描述：
//有一个字符串数组words和一个字符串chars。
//假如可以用chars中的字母拼写出words中的某个“单词”（字符串），那么我们就认为你掌握了这个单词。
//words的字符仅由 a-z 英文小写字母组成。 例如: abc
//chars 由 a-z 英文小写字母和 “?”组成。其中英文问号“?”表示万能字符，能够在拼写时当做任意一个英文字母。 例如： "?" 可以当做 "a"等字母。
//注意：每次拼写时，chars中的每个字母和万能字符都只能使用一次。
//输出词汇表words中你掌握的所有单词的个数。 没有掌握任何单词，则输出0。
//输入描述：
//第1行输入数组words的个数，记为N。
//从第2行开始到第N+1行依次输入数组words的每个字符串元素。
//第N+2行输入字符串chars。
//输出描述：
//输出一个整数，表示词汇表words中你掌握的单词个数。
//注意：
//1 <= words.length <= 100
//1 <= words[i].length, chars.length <= 100
//所有字符串中都仅包含小写英文字母、英文问号
//
//
//示例1
//输入：
//4
//cat
//bt
//hat
//tree
//atach??
//输出：
//3
//说明：
//可以拼写字符串"cat"、"bt"和"hat"
//
//示例2
//输入：
//3
//hello
//world
//cloud
//welldonehoneyr
//输出：
//2
//说明：
//可以拼写字符串"hello"和"world"
//
//示例3
//输入：
//3
//apple
//car
//window
//welldoneapplec?
//输出：
//2
//说明：
//可以拼写字符串"apple"和"car"
//*/
//#include<iostream>
//#include<string>
//#include<vector>
//#include<algorithm>
//#include<map>
//
//using namespace std;
//
//bool fit_word(string str, map<char, int> mchars, int god_char)
//{
//	for (auto i : str)
//	{
//		mchars[i]--;
//	}
//	int unfit_count = 0;
//	for (auto i : mchars)
//	{
//		if (i.second < 0)
//		{
//			unfit_count += abs(i.second);
//		}
//	}
//	if (god_char >= unfit_count)
//	{
//		return true;
//	}
//	else {
//		return false;
//	}
//}
//
//int main()
//{
//	int n;
//	cin >> n;
//	vector<string> words(n);
//	for (int i = 0; i < n; i++)
//	{
//		cin >> words[i];
//	}
//	string chars;
//	cin >> chars;
//	int god_char = 0;
//	// 统计chars的数据
//	map<char, int> mchars;
//	for (auto i : chars)
//	{
//		if (i == '?')
//		{
//			god_char++;
//			continue;
//		}
//		mchars[i]++;
//	}
//	// 匹配
//	int count = 0;
//	for (auto i : words)
//	{
//		if (fit_word(i, mchars, god_char))
//		{
//			count++;
//		}
//	}
//	cout << count;
//}