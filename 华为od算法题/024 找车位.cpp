/*
* 024 找车位
停车场有一横排车位，0代表没有停车，1代表有车。至少停了一辆车在车位上，也至少有一个空位没有停车。为了防剐蹭，需为停车人找到一个车位，使得距停车人的车最近的车辆的距离是最大的，返回此时的最大距离。
输入描述
1.一个用半角逗号分割的停车标识字符串，停车标识为0或1，0为空位，1为已停车。
2.停车位最多100个。
输出描述
输出一个整数记录最大距离
示例1:
输入∶
1,0,0,0,0,1,0,0,1,0,1
输出:
2
*/

#include<bits/stdc++.h>
#include<string>

using namespace std;

int main()
{
	// 经典输入
	string str_input;
	getline(cin, str_input);
	int str_size = str_input.size();
	int start = 0;
	vector<int> vec;
	for (int i = 0; i < str_size; i++)
	{
		if (str_input[i] == ',')
		{
			vec.push_back(stoi(str_input.substr(start, i - start)));
			start = i + 1;
		}
	}
	vec.push_back(stoi(str_input.substr(start)));

	// 找到最大的0的长度
	int dist = 0;
	int max_dist = 0;
	int i = 0;
	while(i < vec.size())
	{
		if (vec[i] == 0)
		{
			dist++;
			max_dist = dist > max_dist ? dist : max_dist;
			i++;
		}
		else
		{
			dist = 0;
			i++;
		}
	}
	cout << max_dist / 2;
}
