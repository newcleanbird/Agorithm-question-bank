/*
363、分月饼
题目描述：
中秋节，公司分月饼，m个员工，买了n个月饼，m<=n，每个员工至少分1个月饼，但可以分多个，单人分到最多月饼的个数是Max1，单人分到第二多月饼个数是Max2，Max1-Max2 <= 3，单人分到第n-1多月饼个数是Max(n-1)，单人分到第n多月饼个数是Max(n)，Max(n-1) – Max(n) <= 3, 问有多少种分月饼的方法？
输入描述：
每一行输入m n，表示m个员工，n个月饼，m<=n
输出描述：
输出有多少种月饼分法
补充说明：
收起

示例1
输入：
2 4
输出：
2
说明：
分法有2种：
4=1+3
4=2+2
注意：1+3和3+1算一种分法

示例2
输入：
3 5
输出：
2
说明：
5=1+1+3
5=1+2+2

示例3
输入：
3 12
输出：
6
说明：
满足要求的有6种分法：
12=1+1+10（Max1=10，Max2=1，不满足要求）
12=1+2+9（Max1=9, Max2=2, 不满足要求）
12=1+3+8（Max1=8, Max2=3, 不满足要求）
12=1+4+7（Max1=7, Max2=4, Max3=1，满足要求）
12=1+5+6（Max1=6, Max2=5, Max3=1，不满足要求）
12=2+2+8（Max1=8, Max2=2, 不满足要求）
12=2+3+7（Max1=7, Max2=3, 不满足要求）
12=2+4+6（Max1=6, Max2=4, Max3=2， 满足要求）
12=2+5+5（Max1=5, Max2=2，满足要求）
12=3+3+6（Max1=6, Max2=3, 满足要求）
12=3+4+5（Max1=5, Max2=4, Max3=3，满足要求）
12=4+4+4（Max1=4, 满足要求）

解题思路    动态规划
用比较严谨的数学语言表达上述问题为：挑选出m非递减的数，要求相邻两个数的差值不超过3，这m个数的和为n，问一共有多少种挑选方式。
由于在挑选完第i个数之后，第i+1个数的取值和第i个数的取值相关，很容易想到用动态规划来解决上述问题。思考动态规划三部曲：

1.dp数组的含义是什么？
我们需要考虑三个因素，选择了第几个数，这个数取了什么数值，当前总和为多少。因此需要构建一个三维的dp数组。
考虑 dp[i][j][k] 表示，第i个数取值为j时，前i个数的总和为k的方法数。
分别考虑i，j，k三个数的取值范围来确定dp数组的大小。
i和k的定义比较明确，范围分别是 [1, m]和[1, n]。
每个数字的取值j的最小为1，最大的情况为m-1个数字都选择最小数1，剩余一个最大数选择n-(m-1) = n-m+1。故j的取值范围是[1, n+m+1]
故构建dp数组是一个大小为 (m+1)*(n-m+2)*(n+1) 的三维数组。

2.动态转移方程是什么？
假设第i个数的取值为j，那么第i+1个数只能在j，j+1，j+2，j+3中进行挑选。
若此时前i个数的总和为k，那么当第i+1个数
    取了j时，前i+1个数的总和为k+j。存在 dp[i+1][j][k+j] += dp[i][j][k]
    取了j+1时，前i+1个数的总和为k+j+1。存在 dp[i+1][j+1][k+j+1] += dp[i][j][k]
    取了j+2时，前i+1个数的总和为k+j+2。存在 dp[i+1][j+2][k+j+2] += dp[i][j][k]
    取了j+3时，前i+1个数的总和为k+j+3。存在 dp[i+1][j+3][k+j+3] += dp[i][j][k]
上述四个式子可以合并为一个式子，即 dp[i+1][j+d][k+j+d] += dp[i][j][k]，其中d的取值为[0,3]
先从小到大遍历i，再从小到大遍历j，再从小到大遍历k，则代码如下
for i in range(1, m):
    for j in range(1, n-m+2):
        for k in range(i, n+1):
            for d in range(4):
                if j+d < n-m+2 and k+j+d < n+1:
                    dp[i+1][j+d][k+j+d] += dp[i][j][k]

3.dp数组如何初始化？
i = 0没有实际意义，不考虑。
考虑i = 1的情况，第1个数字的取值j最小为1，最大为n // m（即所有数字尽可能接近的情况），即此时j的取值为[1, n // m]。
同时，由于只选择了一个数字，因此此时前i个数字的总和k = j
故对于i = 1，做如下初始化

dp = [[[0] * (n+1) for j in range(n-m+2)] for i in range(m+1)]
for j in range(1, n//m+1):
    dp[1][j][j] = 1

4.时间复杂度
时空复杂度
时间复杂度：O(NM(N-M))。三重循环所需时间复杂度。

空间复杂度：O(NM(N-M))。三维dp数组所需空间。
*/

#include<iostream>
#include<string>
#include<vector>

using namespace std;


#include <iostream>
using namespace std;

 思路1：动态规划
int solution(int m, int n)
{
     dp array initialization
    vector<vector<vector<int>>> dp(m + 1, vector<vector<int>>(n - m + 2, vector<int>(n + 1, 0)));   // dp[i][j][k] 第i个员工获得j个月饼当前一共分配了k个月饼
     int dp[m + 1][n - m + 2][n + 1] = { 0 };

     dp初始化，第一个员工最少分配1个月饼
    for (int j = 1; j <= n / m; j++) {
        dp[1][j][j] = 1;
    }

    for (int i = 1; i < m; i++) {   // 员工:[i, m]
        for (int j = 1; j <= n - m + 1; j++) {  // 第i个员工可分配的月饼数：[1, n-m+1]
            for (int k = i; k <= n; k++) {      // 总分配数[i, n]
                for (int d = 0; d < 4; d++) {   // 每次月饼的递增数量[0, 3]
                    if (j + d < n - m + 2 && k + j + d <= n) {  // 
                        dp[i + 1][j + d][k + j + d] += dp[i][j][k];
                    }
                }
            }
        }
    }

    int ans = 0;    // 收集结果，满足m个员工总共分了n个月饼，其中第m个员工拿的情况依次从1到n-m+1。
    for (int j = 1; j <= n - m + 1; j++) {
        ans += dp[m][j][n];
    }
    return ans;
}


int main() {
    int m, n;       // m个员工 n个月饼
    cin >> m >> n;
    int ans = solution(m, n);
    
    cout << ans << endl;

    return 0;
}






int res = 0;
vector<int> cakeMap;
int base = 1;
 
void moonCake(int idx, int m, int n);
 
int main() {
    string input;
    getline(cin, input);
    int pos = input.find(" ");
    int m = stoi(input.substr(0, pos));
    int n = stoi(input.substr(pos + 1));
    
    if (m == 1) {
        cout << 1 << endl;
        return 0;
    }
    
    cakeMap.resize(m);
    int space = 3 * m * (m - 1) / 2;
    
    while (base * m + space < n) {
        base++;
    }
    
    for (int first = base; first <= n / m; first++) {
        cakeMap[0] = first;
        moonCake(1, m, n - first);
        cakeMap[0] = 0;
    }
    
    cout << res << endl;
    
    return 0;
}
 
void moonCake(int idx, int m, int n) {
    if (idx == m - 1) {
        if (n - cakeMap[idx - 1] >= 0 && n - cakeMap[idx - 1] <= 3) {
            res++;
        }
        return;
    }

    int lastCakes = cakeMap[idx - 1];
    int restM = m - idx;

    for (int i = lastCakes; i <= min(lastCakes + 3, n / restM); i++) {
        cakeMap[idx] = i;
        moonCake(idx + 1, m, n - i);
        cakeMap[idx] = 0;
    }
}
