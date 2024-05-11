/*
16 整数对最小和
题目描述：

给定两个整数数组array1、array2，数组元素按升序排列。假设从array1、array2中分别取出一个元素可构成一对元素，现在需要取出k对元素，并对取出的所有元素求和，计算和的最小值
注意：两对元素如果对应于array1、array2中的两个下标均相同，则视为同一对元素。

输入描述：

输入两行数组array1、array2，每行首个数字为数组大小size(0 < size <= 100);
0 < array1[i] <= 1000
0 < array2[i] <= 1000
接下来一行为正整数k
0 < k <= array1.size() * array2.size()

输出描述：

满足要求的最小和

补充说明：

 收起

示例1

输入：

3 1 1 2
3 1 2 3
2
输出：

4
说明：

用例中，需要取2对元素
取第一个数组第0个元素与第二个数组第0个元素组成1对元素[1,1];
取第一个数组第1个元素与第二个数组第0个元素组成1对元素[1,1];
求和为1+1+1+1=4，为满足要求的最小和

思路：直接暴力解决
*/

#include<iostream>
#include<vector>
#include<algorithm>

using namespace std;

int main()
{
    int n1, n2, k;
    cin >> n1;
    vector<int> arr1(n1);
    for (int i = 0; i < n1; i++) cin >> arr1[i];

    cin >> n2;
    vector<int> arr2(n2);
    for (int i = 0; i < n2; i++) cin >> arr2[i];

    cin >> k;

    vector<int> pair;
    for (auto i : arr1)
    {
        for (auto j : arr2)
        {
            pair.push_back(i + j);
        }
    }
    sort(pair.begin(), pair.end());

    int res = 0;
    for(int i = 0; i < k; i++)
    {
        res += pair[i];
    }
    cout << res;

}





