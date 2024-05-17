/*
* 转盘寿司
题目描述：
寿司店周年庆，正在举办优惠活动回馈新老客户。寿司转盘上总共有n盘寿司，prices[i]是第i盘寿司的价格，如果客户选择了第i盘寿司，寿司店免费赠送客户距离第i盘寿司最近的下一盘寿司 j，前提是prices[j]< prices[i]，如果没有满足条件的 j，则不赠送寿司。每个价格的寿司都可无限供应

输入描述： 输入的每一个数字代表每盘寿司的价格，每盘寿司的价格之间使用空格分隔，
例如:
3 15 6 14
3 21 9 17

表示第0盘寿司价格prices[0]为3，第1盘寿司价格prices[1]为15，第2盘寿司价格prices[2]为6，第3盘寿司价格prices[3]为14
寿司的盘数n范围为：1 <= n <= 500
每盘寿司的价格price范围为：1 <= price <= 1000
输出描述：输出享受优惠后的一组数据，每个值表示客户选择第i盘寿司时实际得到的寿司的总价格。使用空格进行分隔，例如：3 21 6 17
补充说明：
示例
示例1
输入：3 14 15 6 5
输出：3 20 21 11 8
说明：第0盘寿司价格为3，往后找不到任何比第0盘寿司便宜的寿司，所以客户选择第0盘寿司的话，实际可得到价格还是原价格3
         第1盘寿司价格为14，往后可以找到第4盘寿司价格为6，prices[3] < prices[1]，所以客户选择第1盘寿司的话，实际可得到价格为prices[1] + prices[3] = 20

思路：
   问题：循环数组，找到下一个比自己小的数字
*/

#include<iostream>
#include<vector>

using namespace std;

int main()
{
   vector<int> prices;
   int i;
   while (cin >> i)
   {
       prices.push_back(i);
       if (cin.peek() == '\n') break;
   }

   // 计算
   int length = prices.size();
   vector<int> t_prices(prices);
   for (int i = 0; i < length; i++)
   {
       for (int j = (i + 1) % length; j != i; j = (j + 1) % length)
       {
           if (prices[j] < prices[i])
           {
               t_prices[i] += prices[j];
               break;
           }
       }
   }



   for (auto i : t_prices)
   {
       cout << i << " ";
   }
}