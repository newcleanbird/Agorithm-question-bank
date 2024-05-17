/*
282、求满足条件的最长子串的长度
题目描述：
给定一个字符串，只包含字母和数字，按要求找出字符串中的最长（连续）子串的长度，字符串本身是其最长的子串，子串要求：
1、 只包含1个字母(a~z, A~Z)，其余必须是数字；
2、 字母可以在子串中的任意位置；

如果找不到满足要求的子串，如全是字母或全是数字，则返回-1。
输入描述：
字符串(只包含字母和数字)

输出描述：
子串的长度
补充说明：
示例1
输入：
abC124ACb
输出：
4
说明：
满足条件的最长子串是C124或者124A，长度都是4
示例2
输入：
a5
输出：
2
说明：
字符串自身就是满足条件的子串，长度为2
示例3
输入：
aBB9
输出：
2
说明：
满足条件的子串为B9，长度为2
示例4
输入：
abcdef
输出：
-1
说明：
没有满足要求的子串，返回-1

逻辑：仅有一个字母其余都是数字的子串最长

优化：使用if else

使用：滑动窗口
*/

#include<iostream>
#include<string>
#include<vector>

using namespace std;

int main()
{
	string str;
	getline(cin, str);
	int max = 0;
	string temp;
	bool has_alpha = false;
	bool has_digit = false;
	for (int i = 0; i < str.size(); i++)
	{
		has_alpha = false;	// 标志位，是否有负号
		has_digit = false;	// 标志位，是否有数字
		temp.clear();
		for (int j = i; j < str.size(); j++)
		{
			if (isalpha(str[j]))	// 字母
			{
				if (!has_alpha) // 首次遇到字母
				{
					has_alpha = true;
					temp += str[j];
				}
				else if (has_digit)	// 第二次遇到字母且有数字
				{
					max = max > temp.size() ? max : temp.size();
					break;
				}
				else {	 // 第二次遇到字母但没有数字,即连续遇到两个字母
					break;
				}
			}
			else if (isdigit(str[j]))	// 遇到数字
			{
				if (has_alpha)	// 有数字有字母
				{
					temp += str[j];
					max = max > temp.size() ? max : temp.size();
				}
				else {
					has_digit = true;
					temp += str[j];
				}
			}
		}
	}
	if (max == 0)
	{
		cout << -1;
	}
	else {
		cout << max;
	}
	
}