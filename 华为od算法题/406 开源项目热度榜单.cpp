/*
406、开源项目热度榜单
题目描述
某个开源社区希望将最近热度比较高的开源项目出个榜单，推荐给社区里面的开发者。

对于每个开源项目，开发者可以进行关注(watch)，收藏(star)、fork、提交issue、提交合并请求(MR)等

数据库里面统计了每个开源项目关注、收藏、fork、issue、MR的数量，开源项目的热度根据者 5 个维度的加权求和进行排序。
H = W(watch)x #watch + W(star)x #star + W(fork)x #star + W(issue)x #issue + W(mr)x #mr

H 表示热度值
W(watch)、W(star)、W(fork)、W(issue)、W(mr)分别表示 5 55 个统计维度的权重
#watch、#star、#star、#issue、#mr分别表示 5 个统计维度的统计值
榜单按照热度值降序排序，对于热度值相等的，按照项目名字转换为全小写字母后的字典序排序('a','b','c',...,'x','y','z')

输入描述
第一行输入为 N ，表示开源项目的个数，0 < N < 100
第二行输入为权重值列表，一共 5 个整型值，分别对应关注、收藏、fork、issue、MR 的数量，数量的取值 0 < n r ≤ 1000
第三行开始接下来的 N 行为开源项目的统计维度，每一行的格式为
name nr_watch nr_star nr_fork nr_issue nr_mr
其中 name 为开源项目的名字，由英文字母组成，长度 ≤ 50,其余 5 格整型值分别为该开源项目关注、收藏、fork、issue、MR 的数量，数量的取值 0 < nr ≤ 1000。

输出描述
按照热度降序，输出开源项目的名字，由英文字母组成，对于热度值相等的，按照项目名字转换为全小写后的字典排序(‘a’>‘b’>‘c’>…>‘x’>‘y’>‘z’)。

样例
输入
4
8 6 2 8 6
camila 66 70 46 158 80
victoria 94 76 86 189 211
anthony 29 17 83 21 48
emily 53 97 1 19 218

输出
victoria
camila
emily
anthony
*/

#include<iostream>
#include<vector>
#include<algorithm>

using namespace std;

struct project
{
	string name;
	string lower_name;
	int focus;
	int selection;
	int fork;
	int issue;
	int MR;
	int H;
};

bool cmp(project& project1, project& project2)
{
	if (project1.H == project2.H)
	{
		return project1.lower_name < project2.lower_name;
	} 
	else {
		return project1.H > project2.H;
	}
}

int main()
{
	int n;
	cin >> n;
	vector<int> weight(5, 0);
	int tmp;
	for (int i = 0; i < 5; i++)
	{
		cin >> tmp;
		weight[i] = tmp;
	}
	vector<project> projects;
	string name;
	int focus;
	int selection;
	int fork;
	int issue;
	int MR;
	int H;
	while (n--)
	{
		cin >> name >> focus >> selection >> fork >> issue >> MR;
		string lower_name = name;
		transform(lower_name.begin(), lower_name.end(), lower_name.begin(), ::tolower);  // 将节点名称转换为小写形式

		H = focus * weight[0] + selection * weight[1] + fork * weight[2] + issue * weight[3] + MR * weight[4];
		projects.push_back({ name, lower_name, focus, selection, fork, issue, MR, H});
	}
	sort(projects.begin(), projects.end(), cmp);
	for (auto i : projects)
	{
		//cout << i.name << endl;
		cout << "name:" << i.name << " H = " << i.H << endl;
	}
}