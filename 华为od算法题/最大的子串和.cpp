/*
输入一个整形数组，返回数组中最大的子串和

输入：1 2 3 -5 -5

时间复杂度：
O(n^2)
O(n)
*/

#include<iostream>
#include<vector>

using namespace std;

// 实现一个O(n)时间复杂度的算法

/*
如果区间的和为正，则是正加成，可以选择加入字串

*/
int get_max_count(const vector<int> &nums)
{
	int res = 0;
	int sum = 0;
	for (int i = 0; i < nums.size(); i++)
	{
		if (sum + nums[i] >= 0)
		{
			sum += nums[i];
			res = max(sum, res);
		}
		else {
			sum = 0;
		}
	}
	return res;
}

int main()
{
	// vector<int> nums = { -3, -4, 1, 2, 3, -5, 6, -5 };
	vector<int> nums = {1, 2, 3, -5, 6, -5 };
	cout << get_max_count(nums);

}

