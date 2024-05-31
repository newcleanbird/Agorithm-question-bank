/*
简单的解压缩算法
    题目描述
    现需要实现一种算法，能将一组压缩字符串还原成原始字符串，还原规则如下：

    1、字符后面加数字N，表示重复字符N次。例如：压缩内容为A3，表示原始字符串为AAA。

    2、花括号中的字符串加数字N，表示花括号中的字符重复N次。例如压缩内容为{AB}3，表示原始字符串为ABABAB。

    3、字符加N和花括号后面加N，支持任意的嵌套，包括互相嵌套，例如：压缩内容可以{A3B1{C}3}3

    输入描述
    输入一行压缩后的字符串

    输出描述
    输出压缩前的字符串

    备注
    输入保证，数字不会为0，花括号中的内容不会为空，保证输入的都是合法有效的压缩字符串

    输入输出字符串区分大小写

    输入的字符串长度范围为[1, 10000]

    输出的字符串长度范围为[1, 100000]

    数字N范围为[1, 10000]

用例
输入

{A3B1{C}3}3

输出

AAABCCCAAABCCCAAABCCC

说明

{A3B1{C}3}3代表A字符重复3次，B字符重复1次，花括号中的C字符重复3次，最外层花括号中的AAABCCC重复3次。

*/



#include<bits/stdc++.h>

using namespace std;

int main()
{
    string s; //输入
    cin >> s;
    int index_l; // 数组下标为{
    int index_r;
    int index_i; // 保存数字的下标
    int num_i; // 保存整数数字
    string ch; // 保存字符串
    string num_s; // 保存数字

    
    for(int i = 0; i < s.size(); i++)
        {
            if(s[i] >= '0' && s[i] <= '9' ) // 直接找到数字
            {
                if(s[i-1] == '}') continue; 
                int num_int = s[i] - '0'; // 保存数字
                string ch_1; // 保存字母
                ch_1.clear();
                char ch_2 = s[i-1];
                ch_1 += ch_2;
                s.erase(i-1, 2);
                while(num_int--)
                {
                    s.insert(i-1, ch_1);
                }
                // i = 0;
        }
    }
    while(s.find('}') != s.npos)
    {
            // 先处理正常的A3数字
        
        for(int i = 0; i < s.size(); i++) // 从i开始寻找
        {
            ch.clear();
            num_s.clear(); // 保存数字
            num_i = 0; // 


            if(s[i] == '}') // 找到}
            {
                index_r = i; // 保存}位置
                // cout << "index_r({):" << index_r << endl; // "{"
                // 找到整数
                for(int j = index_r+11; j <= s.size(); j--) // 向右找数字
                {
                    if(s[j] >= '0' && s[j] <= '9')        // isdigit(s[j])
                    {
                        num_s.insert(num_s.begin(), s[j]);
                    }
                    else
                    {
                        num_i = stoi(num_s);
                        index_i = j - 1;
                        break;
                    }
                }
                // cout << "num_s" << num_s << endl; //

                // 找到需要翻译的字符串
                for(int j = i-1; j >= 0; j-- ) // 向左进行搜索字符串
                {
                    if(s[j] == '{') // 找到{
                    {
                        index_l = j;
                        break; // 跳出循环
                    }
                    ch = s[j] + ch; // ch保存的是要多次加入的字符串
                }
                // cout << "index_l({):" << index_l << endl; // "{"

                // // 删除}
                // s.erase(index_r);
                // // 删除{
                // s.erase(index_l);
                // 删除从数字到}的所有字符
                s.erase(index_i, index_i - index_l+1);
                // cout << "s" << s << endl; // s
                // 开始复制
                while(num_i--)
                {
                    s.insert(index_i, ch);
                }
                // cout << "s" << s << endl;
                break;
            }
        }
    }
    for(int i = 0; i < s.size(); i++)
    {
        if(s[i] >= '0' && s[i] <= '9' ) // 直接找到数字
            {
                int num_int = s[i] - '0'; // 保存数字
                string ch_1; // 保存字母
                ch_1.clear();
                char ch_2 = s[i-1];
                ch_1 += ch_2;
                s.erase(i-1, 2);
                while(num_int--)
                {
                    s.insert(i-1, ch_1);
                }
                i = 0;
            }
    }
 

    cout << s;
    system("pause");
}