/*
275、求字符串中所有整数的最小和

题目描述：
输入字符串s，输出s中包含所有整数的最小和
说明
1. 字符串s，只包含 a-z A-Z +- 数字；
2. 合法的整数包括
    1） 正整数 一个或者多个0-9组成，如 0 2 3 002 102
    2）负整数 负号 - 开头，数字部分由一个或者多个0-9组成，如 -0 -012 -23 -00023
输入描述：
包含数字的字符串
输出描述：
所有整数的最小和
示例1
输入：
bb1234aa
输出：
10
说明：
示例2
输入：
bb12-34aa
输出：
-31
说明：
1+2+（-34） = -31

输入3：
a-1c2+1-+1+-2s-c3-2+2

逻辑：遇到字母跳过，遇到数字，若前面不是符号，则直接相加，若有负号，则向后遍历，将最小的负数加和。
*/

#include<iostream>
#include<string>
#include<vector>

using namespace std;

int main()
{
    string str;
    getline(cin, str);
    int sum = 0;
    string temp;
    bool minue= false;
    for (int i = 0; i < str.size(); i++)
    {
        if (isdigit(str[i]))    // 遇到数字
        {
            if (minue)          // 前有负号
            {
                temp += str[i];
            }
            else {  // 没有负号，直接相加
                sum += str[i] - '0';
            }
        }
        else if (str[i] == '-') // 负号
        {
            minue = true;
            temp.clear();
        }
        else  // 字母或其他字符
        {
            if (minue == true)   // 前有负号的字符串，则转换字符串并添加数字
            {
                minue = false;
                if (!temp.empty())
                {
                    sum -= stoi(temp);
                }
                
            }
        }
    }
    if (minue == true)
    {
        minue = false;
        if (!temp.empty())
        {
            sum += stoi(temp);
        }
        
    }
    cout << sum;
}
