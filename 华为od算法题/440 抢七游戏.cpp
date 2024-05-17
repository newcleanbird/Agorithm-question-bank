/*
440、抢七游戏
题目描述：
A、B两个人玩抢7游戏，游戏规则为A先报一个起始数字X(10<起始数字<10000)，B报下一个数字Y(X-Y<3),A再报一个数字Z(Y-Z<3)，以此类推，直到其中一个抢到7，抢到7即为胜者；在B赢得比赛的情况下，一共有多少种组合？

输入描述：
起始数字M，如100；10<=M<=10000

输出描述：
B能赢得比赛的组合次数

补充说明：
示例1
输入：
10
输出：
1

思路：
每次叠加为0~2
*/
#include<iostream>
#include<vector>
#include<map>

using namespace std;

map<pair<int, bool>, int> memo; // map存储开始位置和谁的轮次 以及对应的组合数量信息

int countWaysToWin(int start, bool isATurn) {
   if (start == 7 && !isATurn) return 1;   // 从7开始，B的轮次，此时B有一种赢的组合。
   if (start == 7 && isATurn) return 0;    // 从7开始，A的轮次，此时B不可能赢。
   if (start < 7) return 0;

   auto key = make_pair(start, isATurn);
   if (memo.find(key) != memo.end()) {
       return memo[key];
   }

   int waysToWin = 0;
   for (int nextMove = 1; nextMove <= 2; nextMove++) {
       if (isATurn) {
           waysToWin += countWaysToWin(start - nextMove, false);
       }
       else {
           waysToWin += countWaysToWin(start - nextMove, true);
       }
   }

   memo[key] = waysToWin;
   return waysToWin;
}

int main()
{
	int M;  // 起始数字
	cin >> M;
   int res = countWaysToWin(M, true);
   cout << res;
}


