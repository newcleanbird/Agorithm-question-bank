/*
440、抢七游戏
题目描述：
a、b两个人玩抢7游戏，游戏规则为a先报一个起始数字x(10<起始数字<10000)，b报下一个数字y(x-y<3),a再报一个数字z(y-z<3)，以此类推，直到其中一个抢到7，抢到7即为胜者；在b赢得比赛的情况下，一共有多少种组合？

输入描述：
起始数字m，如100；10<=m<=10000

输出描述：
b能赢得比赛的组合次数

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

int countwaystowin(int start, bool isaturn) {
    if (start == 7 && !isaturn) return 1;   // 从7开始，b的轮次，此时b有一种赢的组合。
    if (start == 7 && isaturn) return 0;    // 从7开始，a的轮次，此时b不可能赢。
    if (start < 7) return 0;

    auto key = make_pair(start, isaturn);
    if (memo.find(key) != memo.end()) {
        return memo[key];
    }

    int waystowin = 0;
    for (int nextmove = 1; nextmove <= 2; nextmove++) {
        if (isaturn) {
            waystowin += countwaystowin(start - nextmove, false);
        }
        else {
            waystowin += countwaystowin(start - nextmove, true);
        }
    }

    memo[key] = waystowin;
    return waystowin;
}

int main()
{
	int m;  // 起始数字
	cin >> m;
    int res = countwaystowin(m, true);
    cout << res;
}


