/*
192、最多颜色的车辆

题目描述：
在一个狭小的路口，每秒只能通过一辆车，假如车辆的颜色只有3种，找出N秒内经过的最多颜色的车辆数量
三种颜色编号为0,1,2
输入描述：
第一行输入的是通过的车辆颜色信息
[0,1,1,2] 代表4秒钟通过的车辆颜色分别是0,1,1,2
第二行输入的是统计时间窗，整型，单位为秒
输出描述：
输出指定时间窗内经过的最多颜色的车辆数量
补充说明：
 收起
示例1
输入：
0 1 2 1
3
输出：
2
说明：
在[1,2,1]这个3秒时间窗内，1这个颜色出现2次，数量最多
示例2
输入：
0 1 2 1
2
输出：
1
说明：
在2秒时间窗内，每个颜色最多出现1次

示例：
0 1 0 0 1 2 1 2 2 2 2 1 2 0 1 1 1
6

5
思路：
双指针法求解：
*/

#include<iostream>
#include<vector>

using namespace std;

int main()
{
	// 输入
	vector<int> vec;
	int tmp;
	while (cin >> tmp)
	{
		vec.push_back(tmp);
		if (cin.get() == '\n') break;
	}
	int time;
	cin >> time;
	vector<int> res(3);
	// 双指针法搜索
	int imax = 0;
	int left = 0, right = 0;
	for (int right = time - 1; right < vec.size(); right++)
	{
		res.assign(res.size(), 0);// 重置res
		for (int left = right - time + 1; left <= right; left++)
		{
			res[vec[left]]++;
		}
		for (int i : res)
		{
			imax = max(imax, i);
		}
	}
	cout << imax;
}

