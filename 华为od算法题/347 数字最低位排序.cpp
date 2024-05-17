/*
347、数字最低位排序
题目描述：
给定一个非空数组(列表)起元素数据类型为整型，请按照数组元素十进制最低位从小到大进行排序。
1.十进制最低位相同的元素，相对位置保持不变
2.当数组元素为负值时，十进制最低为等同于去除符号位后对应十进制值最低位
输入描述
给定一个非空数组(列表)
其元素数据类型为32位有符号整数，数组长度为[1,1000]
输出描述
排序后的数组
示例1:
输入
1,2,5,-21,22,11,55,-101,42,8,7,32
输出
1,-21,11,-101,2,22,42,32,5,55,7,8
方法：自定义快速排序，利用STL库中的快排函数sort完成即可
*/

#include<iostream>
#include<vector>
#include<string>
#include<algorithm>

using namespace std;

bool compare(int n1, int n2)
{
	int l1 = abs(n1 % 10);
	int l2 = abs(n2 % 10);
	if (l1 == l2)
	{
		return false;	// 不sort() 等价于 l1 < l2;
	}
	else {
		return l1 < l2;
	}
}

int main()
{
	string str;
	getline(cin, str);
	string tmp;
	vector<int> vec;
	for (int i = 0; i < str.size(); i++)
	{
		if (str[i] == ',')
		{
			vec.push_back(stoi(tmp));
			tmp = "";
		}
		else {
			tmp += str[i];
		}
	}
	vec.push_back(stoi(tmp));

	// sort
	sort(vec.begin(), vec.end(), compare);
	for (int i = 0; i < vec.size(); i++)
	{
		cout << vec[i];
		if (i != vec.size() - 1)
		{
			cout << ",";
		}
	}
}