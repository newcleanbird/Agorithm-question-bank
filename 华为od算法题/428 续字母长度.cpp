///*
//428 连续字母长度
//题目描述
//给定一个字符串，只包含大写字母，求在包含同一个字母的子串中，
//长度第k长的子串的长度，相同字母只取最长的那个子串。
//若子串中只包含同一个字母的子串数小于k，则输出-1.
//
//输入描述：
//第一行有一个字符串（1 < 长度 < 100），只包含大写字母
//第二行有一个数字，表示k的值
//
//输出描述：
//输出连续出现次数第k多的字母的次数
//
//示例1：
//输入
//AAAAHHHBBCDHHHH
//3
//输出
//2
//说明
//同一字母连续出现的最多的是A和H，4次；
//第二多的是H，3次，但是H已经存在4个连续的了，故不再考虑；
//下个最长的子串是BB，其长度为2，所以最终答案应该输出2
//
//示例2：
//输入
//AABAAA
//2
//输出
//1
//说明
//同一字母连续出现的最多的是A，3次；
//第二多的还是A，两次，但是A已经出现过了，故不考虑；
//第二个最长子串是B，它的长度是1，所以输出1
//
//示例3：
//输入
//ABC
//4
//输出
//-1
//说明
//只含有3个包含同一个字母的子串，小于k，输出-1
//
//示例4：
//输入
//ABC
//2
//输出
//1
//说明
//三个子串长度均为1，所以此时k=1、k=2、k=3这三种情况均输出1
//
//解题思路
//1.用滑窗法求出连续字母的最大个数，对个数数组降序排序，输出第k个值
//*/
//#include<iostream>
//#include<string>
//#include<vector>
//#include<algorithm>
//#include<map>
//
//using namespace std;
//
////bool cmp(pair<char, int>& a, pair<char, int>& b)
////{
////	return a.second > b.second;
////}
//
//int main()
//{
//	// 输入
//	string str;
//	getline(cin, str);
//	int k;
//	cin >> k;
//	map<char, int> map;
//	char last_char = str[0];
//	int length = 1;
//	for (int i = 1; i < str.size(); i++)
//	{
//		if (str[i] != last_char)
//		{
//			// 收集答案
//			if (map[last_char] == 0)
//			{
//				map[last_char] = length;
//			}
//			else {
//				if (map[last_char] < length)
//				{
//					map[last_char] = length;
//				}
//			}
//			// 初始化
//			last_char = str[i];
//			length = 1;
//		}
//		else {
//			length++;
//		}
//	}
//	vector<int> vec;
//	for (auto i : map)
//	{
//		vec.push_back(i.second);
//	}
//	sort(vec.begin(), vec.end(), greater<int>());
//	// 输出结果
//	if (vec.size() < k)
//	{
//		cout << -1;
//	}
//	else {
//		cout << vec[k - 1];
//	}
//}