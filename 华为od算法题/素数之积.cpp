/*
https://blog.csdn.net/qq_39132095/article/details/129504608?ops_request_misc=%257B%2522request%255Fid%2522%253A%2522167957936116800186589645%2522%252C%2522scm%2522%253A%252220140713.130102334.pc%255Fall.%2522%257D&request_id=167957936116800186589645&biz_id=0&utm_medium=distribute.pc_search_result.none-task-blog-2~all~first_rank_ecpm_v1~rank_v31_ecpm-2-129504608-null-null.142^v76^control_1,201^v4^add_ask,239^v2^insert_chatgpt&utm_term=%E5%8D%8E%E4%B8%BAOD%E6%9C%BA%E8%AF%95%20-%20%E7%B4%A0%E6%95%B0%E4%B9%8B%E7%A7%AF&spm=1018.2226.3001.4187
https://blog.csdn.net/m0_48914085/article/details/127134402
素数之积
题目
RSA加密算法在网络安全世界中无处不在，它利用了极大整数因数分解的困难度，数据越大，安全系数越高，
给定一个32位正整数，请对其进行因数分解，找出是哪两个素数的乘积。

输入描述:
一个正整数num

0 < num <= 2147483647

输出描述:
如果成功找到，以单个空格分割，从小到大输出两个素数，分解失败，请输出-1 -1

示例1
输入

15

输出

3 5

说明
因数分解后，找到两个素数3和5，使得3*5=15，按从小到大排列后，输出3 5

示例2
输入

27

输出

-1 -1

说明
通过因数分解，找不到任何素数，使得他们的乘积为27，输出-1 -1

*/
#include<bits/stdc++.h>

using namespace std;

bool issushu(int n)
{
    for(int i = 2; i*i <= n; i++)
    {
        if(n%i == 0)
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
    for(int i = 2; i*i < num; i++)
    {
        if(issushu(i)) // 如果i是素数
        {
            if(num %i == 0)
            {
                cout << i << " " << num/i;
                system("pause");
                return 0;
            }
        }
    }
    cout << -1 << " " << -1;
    system("pause");
}