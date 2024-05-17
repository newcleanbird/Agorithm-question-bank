/*
400 小明找位置
题目描述：

小朋友出操，按学号从小到大排成一列；小明来迟了，请你给小明出个主意，让他尽快找到他应该排的位置。

算法复杂度要求不高于nLog(n)；学号为整数类型，队列规模<=10000；

输入描述：

1、第一行：输入已排成队列的小朋友的学号（正整数），以”,”隔开；
      例如：93 95 97 100 102 123 155
2、第二行：小明学号，如110；

输出描述：

输出一个数字，代表队列位置（从1开始）。

例如：

6

补充说明：

示例1

输入：
93 95 97 100 102 123 155
110
输出：
6

思考：
二分查找，找不到的情况，即找大于目标值的位置。
0 1 2 3   4    5
1 2 3 111 112 113
110
说明：
*/

// 二分查找

#include<iostream>
#include<vector>

using namespace std;

int main()
{
   vector<int> vec;
   int tmp;
   while (cin >> tmp)
   {
       vec.push_back(tmp);
       if (cin.peek() == '\n') break;
   }
   cin.get();
   int target = 0;
   cin >> target;
   // 二分查找
   int mid;
   int left = -1;
   int right = vec.size();
   while (left +1 != right)
   {
       mid = (left + right) / 2;
       if (vec[mid] < target)
       {
           left = mid;
       }
       else {
           right = mid;
       }
   }
   cout << right + 1;
}