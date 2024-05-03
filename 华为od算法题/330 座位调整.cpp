/*
330、座位调整
题目描述：
疫情期间课堂的座位进行了特殊的调整，不能出现两个同学紧挨着，必须隔至少一个空位。
给你一个整数数组 desk 表示当前座位的占座情况，由若干 0 和 1 组成，其中 0 表示没有占位，1 表示占位。在不改变原有座位秩序情况下，还能安排坐几个人？
输入描述：
第一行是个子数组表示作为占座情况，由若干 0 和 1 组成，其中 0 表示没有占位，1 表示占位
输出描述：
输出数值表示还能坐几个人
补充说明：
1 <= desk.length <= 2 * 104
示例1
输入：
1,0,0,0,1
输出：
1
说明：
只有desk[2]的位置可以坐一个人

0,0,0,0,0,0,0,0,0
1,0,1,0,1,0,1,0,1
// 每三个空位可以安排一个人
*/

#include<iostream>
#include<vector>
#include<string>

using namespace std;

int main()
{
	// 输入数据
	char ch;
	vector<int> vec;
	while (cin >> ch)
	{
		if (isdigit(ch)) vec.push_back(ch - '0');
		if (cin.peek() == '\n') break;
	}
	int count = 0; 
	int zero = 0;
	for (int i = 0; i < vec.size() - 1; i++)
	{
		if (vec[i] == 0) {
			if (vec.size() == 1)
			{
				count = 1;
				break;
			}
			else if (i == 0 && vec[i + 1] == 0) {
				vec[i] = 1;
				count++;
			}
			else if (i > 0 && vec[i - 1] == 0 && vec[i + 1] == 0) {
				vec[i] = 1;
				count++;
			}
		}
	}
	if(vec[vec.size() - 2] == 0 && vec[vec.size() - 1] == 0) {
		vec[vec.size() - 1] = 1;
		count++;
	}
	cout << count;
}