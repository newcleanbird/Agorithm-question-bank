/*
408、剩余银饰的重量
题目描述：
有N块二手市场收集的银饰，每块银饰的重量都是正整数，收集到的银饰会被熔化用于打造新的饰品。
每一回合，从中选出三块 最重的 银饰，然后一起熔掉。假设银饰的重量分别为 x 、y和z，且 x <= y <= z。那么熔掉的可能结果如下：
如果 x == y == z，那么三块银饰都会被完全熔掉；
如果 x == y 且 y != z，会剩余重量为 z - y 的银块无法被熔掉；
如果 x != y 且 y == z，会剩余重量为 y - x 的银块无法被熔掉；
如果 x != y 且 y != z，会剩余重量为 z - y 与 y - x 差值 的银块无法被熔掉。
最后，如果剩余两块，返回较大的重量（若两块重量相同，返回任意一块皆可）；如果只剩下一块，返回该块的重量；如果没有剩下，就返回 0。

输入描述：
输入数据为两行
第一行为银饰数组长度n，1 ≤ n ≤ 40，
第二行为n块银饰的重量，重量的取值范围为[1，2000]，重量之间使用空格隔开

输出描述：
如果剩余两块，返回较大的重量（若两块重量相同，返回任意一块皆可）；如果只剩下一块，返回该块的重量；如果没有剩下，就返回 0。

示例1
输入：
3
1 1 1
输出：
0
说明：
选出1 1 1，得到 0，最终数组转换为 []，最后没有剩下银块，返回0

示例2
输入：
3
3 7 10
输出：
1
说明：
选出 3 7 10，需要计算 (7-3) 和 (10-7) 的差值，即(7-3)-(10-7)=1，所以数组转换为 [1]，剩余一块，返回该块重量，返回1


*/
#include<iostream>
#include<vector>
#include<queue>
#include<algorithm>

using namespace std;

int main()
{
	int n;
	cin >> n;
	priority_queue<int, vector<int>, less<int>> silver;	// 优先队列(大根堆)
	int tmp;
	while (n--)
	{
		cin >> tmp;
		silver.push(tmp);
	}
	int x, y, z;
	while (silver.size() > 2)
	{
		z = silver.top();
		silver.pop();
		y = silver.top();
		silver.pop();
		x = silver.top();
		silver.pop();
		if (x == y && y == z)
		{
			// 全部溶解
		}
		else if(x == y && y != z){
			silver.push(z-y);
		}
		else if (x != y && y == z)
		{
			silver.push(y - x);
		}
		else if (x != y && y != z)
		{
			silver.push(abs((y - x) -  (z - y)));
		}
	}
	if (silver.size() == 2)
	{
		cout << silver.top();
	}
	else if(silver.size() == 1){
		cout << silver.top();
	}
	else {
		cout << 0;
	}

}
