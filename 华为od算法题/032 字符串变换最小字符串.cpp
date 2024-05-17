/*
32、字符串变换最小字符串

题目描述：

给定一个字符串s，最多只能进行一次变换，返回变换后能得到的最小字符串（按照字典序进行比较）。变换规则：交换字符串中任意两个不同位置的字符。

输入描述：一串小写字母组成的字符串s

输出描述：按照要求进行变换得到的最小字符串

补充说明：s是都是小写字符组成
                 1<=s.length<=1000

示例

示例1

输入：abcdef

输出：abcdef

说明：abcdef已经是最小字符串，不需要交换

示例2

输入：bcdefa

输出：acdefb

说明：a和b进行位置交换，可以等到最小字符串

示例3：
cdefgba
adefgbc

思路：
// 想想什么情况下的字符串最小呢？
按照字典序，逐位作为哨兵，向后搜索查看有没有和自己相比最小的，如果有则交换之，为最小字符串。
*/

#include<iostream>
#include<string>
#include<algorithm>

using namespace std;

int main()
{
   // 输入
   string str;
   getline(cin, str);

   // 判断
   char min_tmp = 'z'+1;
   int seq = 0;
   bool is_find = false;
   for (int i = 0; i < str.size(); i++)
   {
       for (int j = i+1; j < str.size(); j++)
       {
           if (str[j] < str[i])
           {
               is_find = true;
               if (str[j] < min_tmp)
               {
                   seq = j;
                   min_tmp = str[j];
               }
           }
       }
       if (is_find)
       {
           swap(str[seq], str[i]);
           break;
       }
   }
   cout << str;
}