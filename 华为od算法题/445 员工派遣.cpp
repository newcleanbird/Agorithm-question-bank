/*
445、员工派遣
题目描述：
某公司部门需要派遣员工去国外做项目。现在，代号为x的国家和代号为y的国家分别需要cntx名和cnty名员工。部门每个员工有一个员工号(1,2,3……)，工号连续，从1开始。
部长派遣员工的规则：
规则1、从[1,k]中选择员工派遣出去
规则2、编号为x的倍数的员工不能去x国，编号为y的倍数的员工不能去y国
问题：
找到最小的k，使得可以将编号在[1,k]中的员工分配给x国和y国，且满足x国和y国的需求

输入描述：
四个整数 x, y, cntx, cnty。(2<=x<y<=30000; x和y一定是质数;1<=cntx,cnty<10^9; cntx+cnty<=10^9）

输出描述：
满足条件的最小的k。

示例1
输入：
2 3 3 1
输出：
5
说明：
输入说明：
2 -表示国家代号2
3 -表示国家代号3
3 -表示国家2需要3个人
1 -表示国家3需要1个人

2 3 3 1
x:3 4
y:2
s:1 5
*/
#include<iostream>
#include<vector>

using namespace std;

int main()
{
	int x, y, cntx, cnty;	// 代号为x的国家和代号为y的国家分别需要cntx名和cnty名员工
	cin >> x >> y >> cntx >> cnty;
	int res;
	for (int i = 1, cx = 0, cy = 0, cs = 0; ; i++)
	{
		int a = i % x;
		int b = i % y;
		if (a != 0 && b != 0)
		{
			cs++;
		}
		else if (a == 0 && b != 0)
		{
			cy++;
		}
		else if (a != 0 && b == 0)
		{
			cx++;
		}
		if (cx + cs >= cntx && cy + cs >= cnty && cx + cy + cs >= cntx + cnty)
		{
			res = i;
			break;
		}
	}
	cout << res;
}