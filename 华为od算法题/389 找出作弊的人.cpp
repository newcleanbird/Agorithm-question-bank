///*
//389、找出作弊的人
//公司组织了一次考试,现在考试结果出来了，想看一下有没人存在作弊行为,但是员工太多了,需要先对员工进行一次过滤,再进一步确定是否存在作弊行为。
//过滤的规则为:找到分差最小的员工ID对(p1,p2)列表,要求p1<p2
//员工个数,取值范国:0<n<100000
//员工ID为整数,取值范围:0<=n<=100000
//考试成绩为整数,取值范围:0<=score<=300
//
//输入描述
//员工的ID及考试分数
//输出描述
//分差最小的员工ID对(p1,p2)列表,要求p1<p2。每一行代表一个集合,每个集合内的员工ID按顺序排列,多行结果也以员工对中p1值大小升序排列(如果p1相同则p2升序)。
//
//示例1：
//输入:
//5
//1 90
//2 91
//3 95
//4 96
//5 100
//输出:
//1 2
//3 4
//说明:
//输入: 第一行为员工个数n，后续的n行第一个数值为员工ID,第二个数值为员工考试分数输出:员工1和员工2的分差为1,员工3和员工4的分差也为1,因此最终结果为
//1 2
//3 4
//
//示例2：
//输入:
//5
//1 90
//2 91
//3 92
//4 85
//5 86
//输出:
//1 2
//2 3
//4 5
//*/
//#include<iostream>
//#include<vector>
//#include<map>
//#include<algorithm>
//
//using namespace std;
//
//bool cmp1(pair<int, int>& p1, pair<int, int>& p2)
//{
//	if (p1.second == p2.second) return p1.first < p2.first;
//	else return p1.second < p2.second;
//}
//
//bool cmp2(pair<int, int>& p1, pair<int, int>& p2)
//{
//	if (p1.first == p2.first) return p1.second < p2.second;
//	else return p1.first < p2.first;
//}
//
//int main()
//{
//	int n;
//	cin >> n;
//	int num;
//	int score;
//	map<int, int> emp;
//	while (n--)
//	{
//		cin >> num >> score;
//		emp.insert(pair<int, int>(num, score));
//	}
//	vector<pair<int, int>> v_emp(emp.begin(), emp.end());
//	sort(v_emp.begin(), v_emp.end(), cmp1);
//	vector< pair<int, int>> res;
//	int min_dif = 300;
//	int dif;
//	for (int i = 1; i < v_emp.size(); i++)
//	{
//		dif = abs(v_emp[i - 1].second - v_emp[i].second);
//		if (dif < min_dif)	// 找到更小的差值
//		{
//			min_dif = dif;
//			res.clear();
//			res.push_back(pair<int, int>(v_emp[i - 1].first, v_emp[i].first));
//		}
//		else if (dif == min_dif)
//		{
//			res.push_back(pair<int, int>(v_emp[i - 1].first, v_emp[i].first));
//		}
//	}
//	sort(res.begin(), res.end(), cmp2);
//	for (auto i : res)
//	{
//		cout << i.first << " " << i.second << endl;
//	}
//}