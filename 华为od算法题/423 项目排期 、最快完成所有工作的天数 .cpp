/*
423、项目排期 、最快完成所有工作的天数
题目描述：
项目组共有N个开发人员，项目经理接到了M个独立的需求，每个需求的工作量不同，且每个需求只能由一个开发人员独立完成，不能多人合作。假定各个需求直接无任何先后依赖关系，请设计算法帮助项目经理进行工作安排，使整个项目能用最少的时间交付。

输入描述：
第一行输入为M个需求的工作量，单位为天，用逗号隔开。
例如：X1 X2 X3 .... Xm
表示共有M个需求，每个需求的工作量分别为X1天，X2天......Xm天。其中0<M<30；0<Xm<200
第二行输入为项目组人员数量N
例如：
5
表示共有5名员工，其中0<N<10

输出描述：
最快完成所有工作的天数
例如：
25
表示最短需要25天能完成所有工作

示例1
输入：
6 2 7 7 9 3 2 1 3 11 4
2
输出：
28
说明：
共有两位员工，其中一位分配需求 6 2 7 7 3 2 1 共需要28天完成，另一位分配需求 9 3 11 4 共需要27天完成，故完成所有工作至少需要28天。


思路：
解题思路
又是一道描述相当晦涩的题目（很想骂人）

用比较简洁的数学语言来描述就是，将数组X1, X2, X3, ... ,Xm分为N部分（并非子数组，不要求连续），设每一部分的和为sum1, sum2, ..., sumN，要求找到一种分配方式使得max(sum1, sum2, ..., sumN)最小。

用一句简单的话来说，就是最小化各部分求和的最大值。这种设问一定要想到用二分来完成。

将问题转化为，我们需要找到一个阈值k（一个人的最大工作量），并将原数组nums可以被分为N部分（分配给N个人），使得这N部分的各自求和的最大值都不会超过k（每个人各自的工作量不会超过k）。

显然k的选择是一个二段性问题：

当k非常大时，原数组nums无论如何分配都可以完成要求
当k非常小时，原数组nums无论怎么分配都无法完成要求
必然存在一个临界值k，使得存在nums的分配结果恰好完成要求。
我们希望找到这个阈值k，因此需要对k进行二分查找，二分查找的范围为[max(nums), sum(nums)]。当

k = max(nums)时，能够被分为m = len(nums)部分（需要m个人来完成所有工作）
k = sum(nums)时，能够被分为1部分（只由1个人可以完成所有工作）
而上述二分过程的贪心子问题为：当我们选择了阈值k时，数组nums能否被分割不超过N部分？

这个问题就和【贪心】2023B-数据最节约的备份方法几乎完全一致了，其代码为
*/

 抽象为 m 个物品能否放到 N 个盒子中，每个盒子的容纳体积上限为 x
 定义检查函数，判断在x天内是否能完成n个人的m个工作

#include <iostream>
#include <vector>
#include <algorithm>
#include <queue>
#include <numeric>
#include <string>
#include <sstream>

using namespace std;

bool subQuestion(int k, vector<int>& nums, int m, int N) {
    int ans = 0;
    vector<int> check(m, 0);

    for (int i = 0; i < m; i++) {
        if (check[i] == 1) continue;
        ans++;
        int curSum = 0;
        int j = i;
        while (j < m) {
            if (check[j] == 1) {
                j++;
                continue;
            }
            if (nums[j] + curSum > k) {
                j++;
            }
            else {
                curSum += nums[j];
                check[j] = 1;
                j++;
            }
        }
    }
    return ans <= N;
}

void solution_1()
{
    vector<int> nums;
    string input;
    getline(cin, input);
    stringstream ss(input);
    int num;
    while (ss >> num) {
        nums.push_back(num);
    }
    int m = nums.size();
    int N;
    cin >> N;

    sort(nums.begin(), nums.end(), greater<int>());
    int left = nums[0], right = accumulate(nums.begin(), nums.end(), 0) + 1;
    while (left < right) {
        int mid = left + (right - left) / 2;
        if (subQuestion(mid, nums, m, N)) {
            right = mid;
        }
        else {
            left = mid + 1;
        }
    }
    cout << left << endl;
}

void solution_2()
{
     M个需求的工作量
    vector<int> w;
    int tmp;
    while (cin >> tmp)
    {
        w.push_back(tmp);
        if (cin.get() == '\n')
        {
            break;
        }
    }
    int n; // 项目组人员数量N
    cin >> n;
    sort(w.begin(), w.end(), greater<int>());
     计算
    priority_queue<int, vector<int>, greater<int>> pq;
    for (int i = 0; i < n; i++)
    {
        pq.push(0);
    }
    for (int i = 0; i < w.size(); i++)
    {
        int min = pq.top(); pq.pop();
        min += w[i];
        pq.push(min);
    }
    int res = 0;
    while (!pq.empty())
    {
        res = max(res, pq.top());
        pq.pop();
    }
    cout << res;
}

int main() {
    solution_2();
}