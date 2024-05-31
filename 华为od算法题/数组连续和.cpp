/*
题目描述

给定一个含有N个正整数的数组，求出有多少个连续区间（包括单个正整数），它们的和大于等于x。
输入描述
第一行两个整数N x（0 < N <= 100000, 0 <= x <= 10000000)
第二行有N个正整数（每个正整数小于等于100)。

输出描述
输出一个整数，表示所求的个数。

示例1
输入
3 7
3 4 7
输出
4

示例2
10 10000000
1 2 3 4 5 6 7 8 9 10

输出
0

*/

#include<bits/stdc++.h>

using namespace std;

int main()
{
    int N,x; // N 个 整数，和大于等于x
    cin >> N >> x;
    vector<int> arr(N);
    for(int i = 0; i < N; i++)
    {
        cin >> arr[i];
    }
    // 一共有n*(n+1)/2 个区间，可以转化为求连续区间小于x
    int sum = N*(N+1)/2; // 一共的连续区间数
    int sum_1 = 0;
    for(int i = 0; i < arr.size(); i++)
    {
        int temp = 0;
        for(int j = i; j < arr.size(); j++)
        {
            temp += arr[j];
            if(temp < x)
            {
                sum_1++;
            }
            else{
                break;
            }
        }
    }
    cout << sum - sum_1;
    system("pause");
}