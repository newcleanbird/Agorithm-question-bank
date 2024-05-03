/*
041 查找接口成功率最优时间段

题目描述：
服务之间交换的接口成功率作为服务调用关键质量特性，某个时间段内的接口失败率使用一个数组表示，数组中每个元素都是单位时间内失败率数值，数组中的数值为0~100的整数，
给定一个数值(minAverageLost)表示某个时间段内平均失败率容忍值，即平均失败率小于等于minAverageLost，找出数组中最长时间段，如果未找到则直接返回NULL。

输入描述：
输入有两行内容，第一行为{minAverageLost}，第二行为{数组}，数组元素通过空格(" ")分隔，minAverageLost及数组中元素取值范围为0~100的整数，数组元素的个数不会超过100个。

输出描述：
找出平均值小于等于minAverageLost的最长时间段，输出数组下标对，格式{beginIndex}-{endIndx}(下标从0开始)，如果同时存在多个最长时间段，则输出多个下标对且下标对之间使用空格(" ")拼接，多个下标对按下标从小到大排序。

补充说明：

收起

示例1

输入：
1
0 1 2 3 4

输出：
0-2

说明：

A、输入解释：minAverageLost=1，数组[0, 1, 2, 3, 4]
B、前3个元素的平均值为1，因此数组第一个至第三个数组下标，即0-2

示例2

输入：
2
0 0 100 2 2 99 0 2
输出：

0-1 3-4 6-7
说明：

A、输入解释：minAverageLost=2，数组[0, 0, 100, 2, 2, 99, 0, 2]
B、通过计算小于等于2的最长时间段为：数组下标为0-1即[0, 0]，数组下标为3-4即[2, 2]，数组下标为6-7即[0, 2]，这三个部分都满足平均值小于等2的要求，因此输出0-1 3-4 6-7

思路：滑动窗口
目的是找到最大的窗口长度：
使用滑动窗口，外循环是右边界。
内循环是左边界。
每次先更新当前窗口内的值，当窗口内的值大于临界值时，不满足要求，因此要求左边界向右移动。
当窗口内的值小于等于临界值时，则满足需求。记录当前的最大值


*/

#include<iostream>
#include<vector>
#include<string>

using namespace std;

int main()
{
	// 输入
	int minAverageLost;
	cin >> minAverageLost;
	int input;
	vector<int> vec;
	while (cin >> input)
	{
		vec.push_back(input);
		if (cin.peek() != ' ') break;
	}

	int left = 0;
	int sum = 0;	// 窗口内的总值
	int avg = 0;	// 窗口内的平均值
	int max_length = 0;
	vector<string> res;	// 存放结果
	for(int right = 0; right < vec.size(); right++)
	{
		sum += vec[right];	// 计算当前的值
		avg = ceil((double)sum / (right - left + 1));	// 计算平均值
		if (avg <= minAverageLost)	// 满足误差率
		{
			if (max_length < right - left + 1)	// 找到更长的窗口
			{
				max_length = right - left + 1;
				res.clear();
				res.push_back(to_string(left) + '-' + to_string(right));
			}
			else if (max_length == right - left + 1)	// 找到同长度的窗口
			{
				res.push_back(to_string(left) + '-' + to_string(right));
			}
		}
		else {
			while (avg > minAverageLost && left < right)	// 只要平均值大于误差率，一直更新左边界
			{
				sum -= vec[left];
				left++;
				avg = ceil((double)sum / (right - left + 1));
			}
		}
	}
	for (auto i : res)
	{
		cout << i << " ";
	}





}

/*
ceil()向上取整有大坑，记得加(double)
*/