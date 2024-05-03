/*
字符串分割
题目描述：
给定非空字符串s，将该字符串分割成一些子串，使每个子串的ASCII码值的和均为水仙花数。
1、若分割不成功，则返回0
2、若分割成功且分割结果不唯一，则返回-1
3、若分割成功且分割结果唯一，则返回分割后子串的数目

输入描述：
1、输入字符串的最大长度为200
输出描述：
根据题目描述中情况，返回相应的结果
补充说明：
“水仙花数”是指一个三位数，每位上数字的立方和等于该数字本身，如371是“水仙花数”，因为：371 = 3^3 + 7^3 + 1^3
收起
示例1
输入：
abc
输出：
0
说明：
分割不成功

示例2
输入：
f3@d5a8
输出：
-1
说明：
分割成功但分割结果不唯一，可以分割为两组，一组"f3"和"@d5a8"，另外一组"f3@d5"和"a8"

示例3
输入：
AXdddF
输出：
2
说明：
成功分割且分割结果唯一，可以分割“AX"(153)和"dddF"(370)成两个子串

思路：
类似n个组合数之和的问题：
	分割次数未知，如何判断回溯结束呢？应该是起始点到达字符串末尾


需要解决的问题：
1. 分割的字符串如何表示分割，是存储分割后的字符串，还是分割点？
	如果存储分割点，那么如何确定分割的字符串？是再加一个变量表示上个分割点？还是用一个数组记录分割点？
2.
*/

#include<iostream>
#include<string>
#include<vector>
#include<set>

using namespace std;

// 第一种做法，传统的分割字符串，依次判断
bool is_narcissistic(string str)
{
	int num = 0; // 记录字符串的字符ASCII的和
	for (auto i : str)
	{
		num += i;
	}
	int sum = 0;
	int ori_num = num;
	while (num > 0)
	{
		sum += pow(num % 10, 3);
		num /= 10;
	}
	if (sum == ori_num) return true;
	else return false;
}

void backtrack(string& str, vector<string>& path, vector<vector<string>>& result, int index)
{
	if (index >= str.size())	// 成功分割至结束
	{
		result.push_back(path);
		return;
	}
	for (int i = index; i < str.size(); i++)
	{
		string tmp = str.substr(index, i - index + 1);	// 当前判断的子串
		if (is_narcissistic(tmp))						// 当前子串是水仙花数字符串
		{
			path.push_back(tmp);
		}
		else {
			continue;	// 不满足，则跳过
		}
		backtrack(str, path, result, i + 1);
		path.pop_back();
	}
}

void sulotion_1()
{
	// 输入
	string str;
	getline(cin, str);
	vector<string> path;	// 保存符合情况的子串
	vector<vector<string>> result; // 保存最后的结果
	backtrack(str, path, result, 0);

	// 输出结果
	if (result.size() == 0)
	{
		cout << 0;
	}
	else if (result.size() == 1)
	{
		cout << result[0].size();
	}
	else if (result.size() == 2)
	{
		cout << -1;
	}
}



// 第二种解法，取巧，将原本的字符串分割判断水仙花数转变为直接计算每位字符的 ASCⅡ码。然后对数组进行分割，寻找水仙花数。
bool is_narcissistic_2(vector<int>& vec, int index, int end)
{
	int num = 0; // 需要判断的水仙花数
	for (int i = index; i <= end; i++)
	{
		num += vec[i];
	}
	int sum = 0; // 水仙花和
	int ori_num = num;
	while (num > 0)
	{
		sum += pow(num % 10, 3);
		num /= 10;
	}
	if (sum == ori_num)
	{
		return true;
	}
	else {
		return false;
	}
}

void backtrack_2(vector<int>& vec, vector<int>& path, vector<vector<int>>& result, int index)	// 每次遍历固定index，然后通过i遍历剩余部分，寻找水仙花数。
{
	if (index >= vec.size())	// 遍历完
	{
		result.push_back(path);
	}
	for (int i = index; i < vec.size(); i++)
	{
		if (is_narcissistic_2(vec, index, i)) // 如果是水仙花数,记录当前的搜索的下标
		{
			path.push_back(i);
		}
		else {
			continue;
		}
		// 搜索 + 回溯
		backtrack_2(vec, path, result, i + 1);
		path.pop_back(); 
	}

}

void solution_2()
{
	// 输入
	string str;
	getline(cin, str);
	// 将字符串中每个字符都转换为 ASCII码，然后存入数组中
	vector<int> vec;
	for (auto i : str)
	{
		vec.push_back(i);
	}
	vector<int> path; // 记录分割的子串的下标
	vector<vector<int>> result;
	backtrack_2(vec, path, result, 0); // 回溯搜索
	if (result.size() == 0)
	{
		cout << 0;
	}
	else if (result.size() == 1)
	{
		cout << result[0].size();
	}
	else if (result.size() == 2)
	{
		cout << -1;
	}

}

// 判断水仙花数的通解
bool is_narcissistic_common(int num, int wide = 3, int power = 3)	// 判断的数字，判断的水仙花数的位数(宽度)，次方数
{
	int max = pow(10, wide);		// 符合数字的上限
	int min = pow(10, wide - 1);	// 符合数字的下限
	if (num < min || num > max)
	{
		return false;
	}
	int tnum = num;	// 需要判断数的拷贝，用于操作
	int sum = 0;	// 总和
	while (tnum > 0)
	{
		sum += pow(tnum % 10, power);
		tnum /= 10;
	}
	if (sum == num)
	{
		return true;
	}
	else {
		return false;
	}
}

int main()
{
	sulotion_1();
	// solution_2();
}