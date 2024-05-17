///*
//426 部门人力分配
//题目描述：
//部门在进行需求开发时需要进行人力安排。当前部门需要完成N个需求，需求用requirements[]表示，requirements[i]表示第i个需求的工作量大小，单位：人月。
//这部分需求需要在M个月内完成开发，进行人力安排后每个月的人力是固定的。
//目前要求每个月最多有2个需求开发，并且每个月需要完成的需求不能超过部门人力。请帮部门评估在满足需求开发进度的情况下，每个月需要的最小人力是多少？
//输入描述：输入第一行为M和requirements，M表示需要开发时间要求，requirements表示每个需求工作量大小，N为requirements长度
//1 <= N/2 <= M <= N <= 10^4
//1 <= requirements[i] <= 10^9
//输出描述：对于每组测试数据，输出部门需要人力需求，行末无多余空格
//
//示例1
//输入：
//3
//3 5 3 4
//输出：6
//说明：输入数据两行，第一行输入数据3表示开发时间要求，第二行输入数据表示需求工作量大小，输出数据一行，表示部门人力需求
//
//3
//1 2 3 4
//
//// 思路二：二分+双指针
//*/
//#include<iostream>
//#include<vector>
//#include<algorithm>
//#include<queue>
//using namespace std;
//
//void solution()
//{
//	int m;	// 时间
//	cin >> m;
//	int tmp;
//	priority_queue<int, vector<int>, greater<int>> que;
//	while (cin >> tmp)
//	{
//		que.push(tmp);
//		if (cin.peek() == '\n') break;
//	}
//
//	// 计算
//	int count; // 需要的人力
//	int tmp1, tmp2;
//	while (que.size() > m)
//	{
//		tmp1 = que.top();
//		que.pop();
//		tmp2 = que.top();
//		que.pop();
//		que.push(tmp1 + tmp2);
//	}
//	while (!que.empty())
//	{
//		count = max(count, que.top());
//		que.pop();
//	}
//	cout << count;
//}
//
//void solution_1()
//{
//    int m;
//    std::cin >> m;
//    std::vector<int> w;
//    int x;
//    while (std::cin >> x) {
//        w.push_back(x);
//    }
//
//    std::sort(w.begin(), w.end());
//    int n = w.size();
//    int l = w[n - 1];
//    int r = 1e9;
//
//    while (l < r) {
//        int mid = (l + r) / 2;
//        if (check(w, m, mid)) {
//            r = mid;
//        }
//        else {
//            l = mid + 1;
//        }
//    }
//    std::cout << l << std::endl;
//}
//
//int check(const std::vector<int>& w, int m, int x) {
//    int cnt = 0;
//    int l = 0;
//    int r = w.size() - 1;
//
//    while (l <= r) {
//        if (w[l] + w[r] <= x) {
//            l++;
//            r--;
//        } else {
//            r--;
//        }
//        cnt++;
//    }
//
//    return cnt <= m;
//}
//
//int main()
//{
//	// solution();
//    solution_1();
//
//}