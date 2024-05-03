/*
特定大小的停车场，数组cars[]表示，其中1表示有车，0表示没车。
车辆大小不一，小车占一个车位（长度1），货车占两个车位（长度2），卡车占三个车位（长度3）。
统计停车场最少可以停多少辆车，返回具体的数目

输入
整型字符串数组cars[]，其中1表示有车，0表示没车，数组长度小于1000。

输出
整型数字字符串，表示最少停车数目

输入
1,0,1

输出
2

说明:
1个小车占第1个车位，第二个车位空，1个小车占第3个车位，最少有两辆车

输入
1,1,0,0,1,1,1,0,1


输出
3

说明:
1个货车占第1、2个车位，第3、4个车位空，1个卡车占第5、6、7个车位
第8个车位空，1个小车占第9个车位，最少3辆车

思路：
	嵌套if语句解决问题

注意：if的边界条件，注意判断语句中的 == 不要写成 =
*/

#include<iostream>
#include<string>
#include<vector>
#include<algorithm>

using namespace std;

int main()
{
	// 输入
	string input;
	getline(cin, input);
	vector<int> vec;
	int start = 0;
	for (int i = 0; i < input.size(); ++i)
	{
		if (input[i] == ',')
		{
			string str = input.substr(start, i - start);
			int tmp = stoi(str);
			vec.push_back(tmp);
			start = i + 1;
		}
	}
	vec.push_back(stoi(input.substr(start)));


	// 计算最少停下的数量
	int count = 0;
	int i = 0;
	int size = vec.size();
	while(i < size){
		if (vec[i] == 1) {
			if (i + 2 < size && vec[i + 2] == 1 && vec[i + 1] == 1) {
				count++;
				i = i + 3;
			}
			else if (i + 1 < size && vec[i + 1] == 1) {
				count++;
				i = i + 2;
			}
			else {
				count++;
				i = i + 1;
			}
		}
		else {
			i = i + 1;
		}
	}
	cout << count << endl;
}