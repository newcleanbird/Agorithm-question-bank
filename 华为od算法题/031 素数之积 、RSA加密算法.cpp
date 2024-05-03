/*
题目描述：

RSA加密算法在网络安全世界中无处不在，它利用了极大整数因数分解的困难度，数据越大，安全系数越高，给定一个32位正整数，请对其进行因数分解，找出是哪两个素数的乘积。

输入描述：

一个正整数num

0 < num <= 2147483647

输出描述：

如果成功找到，以单个空格分割，从小到大输出两个素数，分解失败，请输出-1 -1

示例1

输入：

15
输出：

3 5
说明：

因数分解后，找到两个素数3和5，使得3*5=15，按从小到大排列后，输出3 5

示例2

输入：

27
输出：

-1 -1
说明：

通过因数分解，找不到任何素数，使得他们的乘积为27，输出-1 -1

思路：
	1. 判断素数：素数的因数小于开方。依次取余，非0不是素数。
	2. 寻找是素数的因数。
*/

#include<iostream>
#include<cmath>

using namespace std;

bool is_prime(int num)
{
	if (num < 2) return false;
	for (int i = 2; i <= sqrt(num); i++)
	{
		if (num % i == 0)
		{
			return false;
		}
	}
	return true;
}

int main()
{
	int num;
	cin >> num;
	int a = -1, b = -1;
	for (int i = 2; i <= sqrt(num); i++)
	{
		if (is_prime(i))
		{
			if ((num % i == 0) && is_prime(num / i))
			{
				a = i;
				b = num / i;
				break;
			}
		}
	}
	cout << a << " " << b;
}