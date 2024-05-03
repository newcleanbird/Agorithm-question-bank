/*
478、字符串拼接、构成指定长度字符串的个数
题目描述：
给定M(0<M<=30)个字符（a-z），从中取出任意字符（每个字符只能用一次）拼接成长度为N(0<N<=5)的字符串，要求相同的字符不能相邻，计算出给定的字符列表能拼接出多少种满足条件的字符串，输入非法或者无法拼接出满足条件的字符串则返回0。

输入描述：
给定的字符列表和结果字符串长度，中间使用空格（" "）拼接

输出描述：
满足条件的字符串个数

示例1
输入：
abc 1
输出：
3
说明：
给定的字符为a,b,c，结果字符串长度为1，可以拼接成a,b,c，共3种

示例2
输入：


输出：
2
说明：
给定的字符为dde，结果字符串长度为2，可以拼接成de,ed，共2种
*/

#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;

string s;
int k;
int ans = 0;
int n;
vector<bool> vis;
string v;

// 定义深度优先搜索函数
void dfs(int u) {
    if (u == k) {
        ans++;
        return;
    }
    for (int i = 0; i < n; i++) {
        // 如果当前字符已经被使用过，或者与上一个字符一样（但上一个字符未被使用），则跳过
        if (vis[i] || (i > 0 && s[i] == s[i - 1] && !vis[i - 1])) {
            continue;
        }
        // 如果相邻字符相同，则跳过
        if (!v.empty() && v.back() == s[i]) {
            continue;
        }
        // 将当前字符添加到序列中，更新标记，并进行递归
        v.push_back(s[i]);
        vis[i] = true;
        dfs(u + 1);
        // 回溯操作，将当前字符弹出序列，还原标记
        v.pop_back();
        vis[i] = false;
    }
}

int main() {
    // 读取输入
    cin >> s >> k;
    sort(s.begin(), s.end());  // 将字符串按照字典序排序，方便后续去重操作
    n = s.length();
    vis = vector<bool>(n, false);  // 用于标记当前字符是否被选取

    // 从起始状态开始深度优先搜索
    dfs(0);

    // 输出结果
    cout << ans << endl;

    return 0;
}