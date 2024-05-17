/*
386、山脉的个数
给定一个数组，数组中的每个元素代表该位置的海拔高度。0表示平地，>=1时表示属于某个山峰，山峰的定义为当某个位置的左右海拔均小于自己时，该位置为山峰。数组起始位置计算时可只满足一边的条件。输入描述一个整数数组
输出描述
输出符合条件的山峰的个数
示例1：
输入：
0,1,2,3,2,4
输出：
2
示例2：
输入：
3,0,3,4,1
输出：
2

0,1,4,3,1,0,0,1,2,3,1,2,1,0
3

1
1

1,1
0

1,2
1

*/

#include<iostream>
#include<vector>
#include<string>

using namespace std;

int main()
{
	// 输入
	string str;
	getline(cin, str);
	vector<int> vec;
	string tmp;
	for (int i = 0; i < str.size(); i++)
	{
		if(str[i] == ',')
		{
			vec.push_back(stoi(tmp));
			tmp = "";
		}
		else {
			tmp += str[i];
		}
		if (i == str.size() - 1)
		{
			vec.push_back(stoi(tmp));
		}
	}
	// 计算山峰
	int count = 0;
	for (int i = 0; i < vec.size(); i++)
	{
		if (vec.size() == 1)
		{
			count = 1;
			break;
		}
		if (i == 0)
		{
			if (vec[i] > vec[i + 1]) count++;
		}
		else if ( i== vec.size() - 1)
		{
			if (vec[i] > vec[i-1]) count++;
		}
		else if (vec[i - 1] < vec[i] && vec[i] > vec[i + 1])
		{
			count++;
		}
	}
	cout << count;
}