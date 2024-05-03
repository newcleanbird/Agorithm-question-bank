/*
465 小朋友来自多少小区
题目描述：
幼儿园组织活动，老师布置了一个任务：每个小朋友去了解与自己同一个小区的小朋友还有几个。我们将这些数量汇总到数组garden中。
请根据这些小朋友给出的信息，计算班级小朋友至少来自几个小区？

输入描述：
输入：
garden[] = {2, 2, 3}
garden数组长度最大为999
每个小区的小朋友数量最多1000人，也就是garden[i]的范围为[0,999]

输出描述：
输出：7

说明：实际输出的是小朋友数量

示例1
输入：
2 2 3
输出：
7

解释：
第一个小朋友反馈有两个小朋友和自己同一小区，即此小区有3个小朋友
第二个小朋友反馈有两个小朋友和自己同一小区，即此小区有3个小朋友。
这两个小朋友，可能是同一小区的，且此小区的小朋友只有3个人。
第三个小区反馈还有3个小朋友与自己同一小区，则这些小朋友只能是另外一个小区的。这个小区有4个小朋友。
*/

#include <iostream>
#include <vector>
#include <map>
#include <unordered_map>

using namespace std;

int main() {
    map<int, int> map;
    int num;
    // 输入一行整数，以空格分隔
    while (cin >> num) {
        map[num+1]++;
        if (cin.get() == '\n') break;
    }

    // 计算
    int res = 0;
    for (auto i : map)
    {
        res += ceil((double)i.second / i.first) * i.first;
    }

    cout << res << endl;

    return 0;
}