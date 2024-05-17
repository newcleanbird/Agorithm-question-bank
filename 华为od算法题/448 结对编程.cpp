///*
//448 结对编程
//题目描述
//某部门计划通过结队编程来进行项目开发，已知该部门有N名员工，每个员工有独一无二的职级，每三个员工形成一个小组进行结队编程，结队分组规则如下：
//从部门中选出序号分别为i、j、k的3名员工，他们的职级分别为level[i],level[j],level[k]结队小组需满足level[i]<level[j]<level[k]或者level[i]>level[j]>level[k]其中0⩽i<j<k<n
//请你按上述条件计算可能组合的小组数量。同一员工可以参加多个小组
//
//输入描述
//第一行输入：员工总数n
//
//第二行输入：按序号依次排列的员工的职级level，中间用空格隔开
//
//限制：
//1⩽n⩽6000
//1⩽level[i]⩽10^5
//
//输出描述
//可能组合的小组数量
//
//样例
//示例1
//输入
//4
//1 2 3 4
//输出
//4
//说明
//可能结队成的组合(1,2,3)、(1,2,4)、 (1,3,4)、(2,3,4)
//
//示例2
//输入
//3
//5 4 7
//输出
//0
//说明
//根据结队条件，我们无法为该部门组建小组
//
//思路：
//1. 三层循环暴力解决：铁超时
//
//2. 前后缀分解+贡献法计数
//我们可以考虑枚举中间位置j ，中间位置j 对答案的贡献其实就是左边比level[j]小的数的个数a和右边比level[j]大的个数b bb的乘积，根据乘法原理可知，对应的贡献就是a*b，我们可以使用两个数组预处理所有位置左边比它小的个数L[i]和右边比它大的个数R[i]，那么对应的贡献值就是L[i]∗R[i]，对于level[i]>level[j]>level[k]的情况，我们可以将数组翻转后，再做一遍上述的计数，即可得到总的答案。
//
//*/
//
//#include<iostream>
//#include<vector>
//#include<algorithm>
//
//using namespace std;
//
//// 暴力，大概率超时
//void solution1(vector<int>& levels, int n)
//{
//	// 开始计算
//	int res = 0;
//	for (int i = 0; i < n; i++)
//	{
//		for (int j = i + 1; j < n; j++)
//		{
//			for (int k = j + 1; k < n; k++)
//			{
//				if ((levels[i] < levels[j] && levels[j] < levels[k]) || (levels[i] > levels[j] && levels[j] > levels[k])) res++;
//			}
//		}
//	}
//	cout << res;
//}
//
//// 2. 前后缀分解+贡献法计数
//void solution2(vector<int>& levels, int n)
//{
//	int res = 0;
//	for (int i = 1; i < n - 1; i++)
//	{
//		int li = levels[i];
//		int count_l_1 = 0, count_r_1 = 0;
//		int count_l_2 = 0, count_r_2 = 0;
//		for (int l = 0; l < i; l++)
//		{
//			if (levels[l] < li) count_l_1++;
//			if (levels[l] > li) count_l_2++;
//		}
//		for (int r = i+1; r < n; r++)
//		{
//			if (li < levels[r] ) count_r_1++;
//			if (li > levels[r]) count_r_2++;
//		}
//		res += count_l_1 * count_r_1 + count_l_2 * count_r_2;
//	}
//	cout << res;
//}
//
//int main()
//{
//	int n; // 员工总数
//	cin >> n;
//	vector<int> levels(n);
//	for(int i = 0; i < n; i++)
//	{
//		cin >> levels[i];
//	}
//	solution2(levels, n);
//	
//}