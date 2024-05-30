/*
标题：绘图机器的绘图问题| 时间限制：1秒 | 内存限制：262144K | 语言限制：不限
所谓的水仙花数是指一个n位的正整数其各位数字的n次方的和等于该数本身，

例如153=1^3+5^3+3^3,153是一个三位数

输入描述：
第一行输入一个整数N，

表示N位的正整数，N在3-7之间包含3,7

第二行输入一个正整数M，

表示需要返回第M个水仙花数

输出描述：
返回长度是N的第M个水仙花数，

个数从0开始编号，

若M大于水仙花数的个数返回最后一个水仙花数和M的乘积，

若输入不合法返回-1
示例1
输入

3
0

输出

153

说明：153是第一个水仙花数

示例2:
输入

9
1

输出

-1


*/
#include <bits/stdc++.h>

using namespace std;

int pow_1(int  x, int n)
{
    int res = 1;
    for(int i = 0; i < n; i++)
    {
        res *=x;
    }
    return res;
}

bool func_shui(int n, int p)
{
    int temp = 0;
    int n_1 = n;
    int sum = 0;
    while(n>0)
    {
        temp = n %10;
        sum += pow_1(temp, p);
        n /=10;
    }
    if(sum == n_1)
    {
        return true;
    }
    return false;
    
}
// 返回长度是n的第m个水仙花数
int main()
{
    int n;  // n为长度
    cin >> n;
    int m;
    cin >> m; // 第m个数
    int num = 1;
    int sum = 0;
    vector<int> result;
    for(int i = 0; i < n - 1; i++)
    {
        num *= 10;
    }
    for(int i = num; i < num*10; i++)
    {
        if(func_shui(i, n))
        {
            result.push_back(i);
        }
    }
    for(auto i : result)
    {
        cout << i << endl;
    }
    system("pause");
}
