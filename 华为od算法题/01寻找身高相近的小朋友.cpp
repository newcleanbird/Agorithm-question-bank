///*
//题目描述：
//
//小明今年升学到小学一年级，来到新班级后发现其他小朋友们身高参差不齐，然后就想基于各小朋友和自己的身高差对他们进行排序，请帮他实现排序。
//
//输入描述：
//
//第一行为正整数H和N，0<H<200，为小明的身高，0<N<50，为新班级其他小朋友个数。
//第二行为N个正整数H1-HN，分别是其他小朋友的身高，取值范围0<Hi<200（1<=i<=N），且N个正整数各不相同。
//
//输出描述：
//
//输出排序结果，各正整数以空格分割。和小明身高差绝对值最小的小朋友排在前面，和小明身高差绝对值最大的小朋友排在最后，如果两个小朋友和小明身高差一样，则个子较小的小朋友排在前面。
//
//补充说明：
//
//收起
//
//示例1
//
//输入：
//
//100 10
//95 96 97 98 99 101 102 103 104 105
//输出：
//
//99 101 98 102 97 103 96 104 95 105
//说明：
//
//小明身高100，班级学生10个，身高分别为95 96 97 98 99 101 102 103 104 105，按身高差排序后结果为：99 101 98 102 97 103 96 104 95 105。
//
//
//思路：改写sort函数，按照排序要求排序。
//*/
//
//#include<iostream>
//#include<vector>
//#include<algorithm>
//
//using namespace std;
//
//bool compare(int h1, int h2, int mingheight)
//{
//	int different1 = abs(h1 - mingheight);
//	int different2 = abs(h2 - mingheight);
//	if (different1 == different2)
//	{
//		return h1 < h2;
//	}
//	return different1 < different2;
//}
//
//int main()
//{
//	// 输入
//	int H, N;
//	cin >> H >> N;
//	vector<int> student(N, 0);
//	for (int i = 0; i < N; i++)
//	{
//		cin >> student[i];
//	}
//
//	sort(student.begin(), student.end(), [&](int h1, int h2) {
//		return compare(h1, h2, H);
//		});
//	// 输出
//	for (auto height : student)
//	{
//		cout << height << " ";
//	}
//}