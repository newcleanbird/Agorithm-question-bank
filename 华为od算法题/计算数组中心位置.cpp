/*
题目描述
给你一个整数数组nums，请计算数组的中心位置。数组的中心位置是数组的一个下标， 其左侧所有元素相乘的积等于右侧所有元素相乘的积。数组第一个元素的左侧积为1，最后一个元素的右侧积为1。 如果数组有多个中心位置，应该返回最靠近左边的那一个，如果数组不存在中心位置，返回-1。

输入

2 5 3 6 5 6

输出

3

2 2 2 2 2 2 2 2 2 2 2
0 10

题意解读
左侧积：该元素左侧所有元素的乘积；
右侧积：该元素右侧所有元素的乘积；

例如元素3，他的左侧积是 2*5 = 10. 他的右侧积是6*5*6 = 180

数组的中心位置指的是：该元素的 左侧积 等于 右侧积

https://blog.csdn.net/wtswts1232/article/details/135159325
*/

#include<iostream>
#include<vector>

using namespace std;

int find_middle(vector<int>& nums)
{
	int left = 0;
	int right = nums.size() - 1;
	int l_val = nums[left];
	int r_val = nums[right];

	while (!(right - left == 2 && l_val == r_val))
	{
		if (l_val <= r_val)
		{
			left++;
			l_val *= nums[left];
		}
		else if (l_val > r_val)
		{
			right--;
			r_val *= nums[right];
		}
	}


	return left+1;
}

int main()
{
	vector<int> nums;
	int temp;
	while (cin >> temp)
	{
		nums.push_back(temp);
		if (cin.get() == '\n')
			break;
	}
	
	int ans = find_middle(nums);
	cout << ans << endl;
	return 0;
}