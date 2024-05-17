///*
//205、最多几个直角三角形
//题目描述：
//有N条线段，长度分别为a[1]-a[N]。现要求你计算这N条线段最多可以组合成几个直角三角形，每条线段只能使用一次，每个三角形包含三条线段。
//
//输入描述：
//第一行输入一个正整数T(1 <= T <= 100)，表示有T组测试数据。
//对于每组测试数据，接下来有T行，每行第一个正整数N，表示线段个数，(3<=N<20)，接着是N个正整数，表示每条线段长度，(0<a[i]<100)。
//
//输出描述：
//对于每组测试数据输出一行，每行包括一个整数，表示最多能组合的直角三角形个数。
//
//示例1
//输入：
//1
//7 3 4 5 6 5 12 13
//输出：
//2
//说明：
//可以组成2个直角三角形（3,4,5）、（5,12,13）
//
//示例2
//输入：
//1
//7 3 4 5 6 6 12 13
//输出：
//1
//说明：
//可以组成1个直角三角形(3,4,5)或(5,12,13)，5只能使用一次，所以只有1个。
//
//示例3：
//输入
//3
//7 3 4 5 6 5 12 13
//7 3 4 5 6 6 12 13
//9 3 4 5 5 12 13 7 24 25
//输出
//1
//2
//3
//
//思路：组合问题，不能重复
//使用回溯/dfs
//
//*/
//
//#include<iostream>
//#include<vector>
//#include<algorithm>
//
//using namespace std;
//
//int max_triangle(const vector<int>& vec, vector<bool>& used, int index)
//{
//	int res = 0;
//	for (int i = index; i < vec.size(); i++)
//	{
//		if (used[i]) continue;
//		for (int j = i + 1; j < vec.size(); j++)
//		{
//			if (used[j]) continue;
//			for (int k = j + 1; k < vec.size(); k++)
//			{
//				if (used[k]) continue;
//				if (vec[i] * vec[i] + vec[j] * vec[j] == vec[k] * vec[k])
//				{
//					used[i] = true;
//					used[j] = true;
//					used[k] = true;
//					res = max(res, max_triangle(vec, used, index + 1) + 1);
//					used[i] = false;
//					used[j] = false;
//					used[k] = false;
//				}
//			}
//		}
//	}
//	return res;
//}
//
//int main()
//{
//	// 输入
//	int total_test;
//	cin >> total_test;
//	vector<vector<int>> vec(total_test);
//	int tmp;
//	vector<int> v_res;
//	for (int i = 0; i < total_test; i++)
//	{
//		int num_size;
//		cin >> num_size;
//		for (int j = 0; j < num_size; j++)
//		{
//			cin >> tmp;
//			vec[i].push_back(tmp);
//		}
//		sort(vec[i].begin(), vec[i].end());			// 排序
//		vector<bool> used(num_size, false);			// 标记使用数组
//		int max = max_triangle(vec[i], used, 0);	// 从0开始搜索
//		v_res.push_back(max);
//	}
//
//	for (auto i : v_res)
//	{
//		cout << i << endl;
//	}
//
//}