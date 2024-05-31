/*
拼接URL
题目
给定一个url前缀和url后缀
通过,分割 需要将其连接为一个完整的url
如果前缀结尾和后缀开头都没有/
需要自动补上/连接符
如果前缀结尾和后缀开头都为/
需要自动去重
约束：
不用考虑前后缀URL不合法情况

输入
url前缀(一个长度小于100的字符串)
url后缀(一个长度小于100的字符串)

输出描述
拼接后的url

示例一
输入
/acm,/bb    两个都合法
输出
/acm/bb

示例二
输入
/abc/,/bcd  前缀后有/后缀也有，去重

输出
/abc/bcd

示例三
输入
/acd,bef    前缀后没有，后缀前也没有，需要加上

输出
/acd/bef   

示例四
输入
,

输出
/

*/

// 前缀：以/开头，可能没有/，则需要补上
// 后缀：以/结尾
#include<bits/stdc++.h>

using namespace std;

int main()
{
    string s1,s2; // 输入两个字符串 s1 s2 以，分割
    getline(cin, s1, ',');
    getline(cin, s2);
    // 前缀保证只有前面有，后缀保证也只有前面有
    if(s1.size() == 0)
    {
        s1 = "/";
    }
    // 将s1后面的\去掉
    if(s1[s1.size()-1] == '/')
    {
        s1.erase(s1.size()-1);
    }
    if(s2[0]!='/')
    {
        s2.insert(s2.begin(),'/');
    }
    cout << s1+s2 << endl;
    
    
    //cout << s1 << " " << s2 << endl;
    system("pause");
}
