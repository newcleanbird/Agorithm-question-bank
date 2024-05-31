/*
https://blog.csdn.net/qq_39132095/article/details/129504663
求最多可以派出多少支团队
题目
用数组代表每个人的能力，一个比赛活动要求参赛团队的最低能力值为N，每个团队可以由1人或2人组成，且1个人只能参加1个团队，请计算出最多可以派出多少支符合要求的团队？

输入描述:
5
3 1 5 7 9
8

第一行数组代表总人数，范围[1,500000]

第二行数组代表每个人的能力，每个元素的取值范围[1, 500000]，数组的大小范围[1,500000]

第三行数值为团队要求的最低能力值，范围[1, 500000]

输出描述:
3

最多可以派出的团队数量

示例1
输入

5
3 1 5 7 9
8

输出

3


说明
3,5组成一队，1,7组成一队，9自己一个队，故输出3

*/

#include<bits/stdc++.h>

using namespace std;

// vector<vector<int>> result;
// vector<int> path;

// // 每组1人或者2人，元素互异，
// void backtracking(vector<int> power, int target, int sum, int total, int startindex)
// {
//     if(path.size()==2&&total == power.size())
//     {
//         if(sum >= target){
//             result.push_back(path);
//         }
//         return;
//     }
//     for(int i = startindex; i <)
// }

int main()
{
    // 输入
    int n;                      // 总数
    cin >> n;
    vector<int> power(n);       // 能力
    for(int i = 0; i < n; i++)  
    {
        cin >> power[i];
    }
    int target;                 // 能力最低值
    cin >> target;
    int sum = 0; // 符合的数目
    sort(power.begin(), power.end()); // 对power进行排序，升序
    // 使用双指针法进行搜索
    int left = 0;
    int right = power.size() - 1;
    // 把大于等于能力的全部取出去
    while(power[right] >= target)
    {
        sum++;
        right--;
    }
    // 剩下的就是能力小于target的了
    // 本着最强带一个最弱的原则，一个从左搜索，一个从右搜索
    while(left < right) // 相等没意义，因为一个人能力肯定不够
    {
        if(power[left] + power[right] >= target)
        {
            sum++;
            right--;
            left++;
        }
        else{
            left++;
        }
    }
    cout << sum;
    system("pause");

}