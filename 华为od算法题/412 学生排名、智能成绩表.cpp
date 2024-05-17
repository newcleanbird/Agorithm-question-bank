///*
//412、学生排名、智能成绩表
//题目描述：
//小明来到某学校当老师，需要将学生按考试总分或单科分数进行排名，你能帮帮他吗？
//
//输入描述：
//第1行输入两个整数，学生人数n和科目数量m。0<n<100,0<m<10
//第2行输入m个科目名称，彼此之间用空格隔开。科目名称只由英文字母构成，单个长度不超过10个字符。科目的出现顺序和后续输入的学生成绩一一对应。不会出现重复的科目名称。
//第3行开始的n行，每行包含一个学生的姓名和该生m个科目的成绩（空格隔开），学生不会重名。学生姓名只由英文字母构成，长度不超过10个字符。成绩是0~100的整数，依次对应第2行中输入的科目。
//第n+2行，输入用作排名的科目名称。若科目不存在，则按总分进行排序。
//
//输出描述：
//输出一行，按成绩排序后的学生名字，空格隔开。成绩相同的按照学生姓名字典顺序排序。
//
//示例1
//输入：
//3 2
//yuwen shuxue
//fangfang 95 90
//xiaohua 88 95
//minmin 100 82
//shuxue
//输出：
//xiaohua fangfang minmin
//说明：
//按shuxue成绩排名，依次是xiaohua、fangfang、minmin
//
//示例2
//输入：
//3 2
//yuwen shuxue
//fangfang 95 90
//xiaohua 88 95
//minmin 90 95
//zongfen
//输出：
//fangfang minmin xiaohua
//说明：
//
//排序科目不存在，按总分排序，fangfang和minmin总分相同，按姓名的字典顺序，fangfang排在前面
//*/
//#include<iostream>
//#include<vector>
//#include<algorithm>
//#include<map>
//
//using namespace std;
//
//struct student
//{
//	string name;
//	vector<int> subject;
//	int total_score;
//};
//
//int index = -1; // 排序的下标
//
//bool cmp(student student1, student student2)
//{
//	if (index != -1)
//	{
//		int score1 = student1.subject[index];
//		int score2 = student2.subject[index];
//		if (score1 != score2)
//		{
//			return score1 > score2;
//		}
//		else {
//			return student1.name < student2.name;
//		}
//	}
//	else {
//		return student1.total_score > student2.total_score;
//	}
//}
//
//int main()
//{
//	int n, m; //学生人数n 科目数量m
//	cin >> n >> m;
//	vector<string> subject(m);	// 成绩
//	for (int i = 0; i < m; i++)
//	{
//		cin >> subject[i];
//	}
//	vector<student> students(n);
//	for (int i = 0; i < n; i++)
//	{
//		cin >> students[i].name;
//		int tmp;
//		int score = 0;
//		for (int j = 0; j < m; j++)
//		{
//			cin >> tmp;
//			students[i].subject.push_back(tmp);
//			score += tmp;
//		}
//		students[i].total_score = score;
//	}
//	string cmp_name;
//	cin >> cmp_name;
//	for (int i = 0; i < m; i++)
//	{
//		if (subject[i] == cmp_name)
//		{
//			index = i;
//		}
//	}
//	sort(students.begin(), students.end(), cmp);
//	for (auto i : students)
//	{
//		cout << i.name << " ";
//	}
//}
