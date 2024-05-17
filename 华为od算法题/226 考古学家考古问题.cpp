///*
//226、考古学家考古问题
//
//题目描述：
//有一个考古学家发现一个石碑，但是很可惜，发现时其已经断成多段，原地发现n个断口整齐的石碑碎片。为了破解石碑内容，考古学家希望有程序能帮忙计算复原后的石碑文字组合数，你能帮忙吗？
//
//输入描述：
//第一行输入n，n表示石碑碎片的个数。
//第二行依次输入石碑碎片上的文字内容s，共有n组。
//
//输出描述：
//输出石碑文字的组合（按照升序排列），行末无多余空格。
//
//补充说明：
//如果存在石碑碎片内容完全相同，则由于碎片间的顺序变换不影响复原后的碑文内容，即相同碎片间的位置变换不影响组合。
//
//示例1
//输入：
//3
//a b c
//输出：
//abc
//acb
//bac
//bca
//cab
//cba
//说明：
//当石碑碎片上的内容为“a”，“b”，“c”时，则组合有“abc”，“acb”，“bac”，“bca”，“cab”，“cba”
//
//示例2
//输入：
//3
//a b a
//输出：
//aab
//aba
//baa
//说明：
//当石碑碎片上的内容为“a”，“b”，“a”时，则可能的组合有“aab”，“aba”，“baa”
//
//示例3
//输入：
//3
//a b ab
//输出：
//aabb
//abab
//abba
//baab
//baba
//说明：
//当石碑碎片上的内容为“a”，“b”，“ab”时，则可能的组合有“aabb”，“abab”，“abba”，“baab”，“baba”
//
//
//// 排列问题
//采用回溯法(dfs)，排列问题每次搜索都从搜索空间起始搜索，当搜索路径长度满足要求时停止。
//*/
//
//#include<iostream>
//#include<string>
//#include<set>
//#include<vector>
//#include<algorithm>
//#include<sstream>
//
//using namespace std;
//
//int length_data;
//vector<string> vec;
//
//void backtrack(vector<bool>& used, set<string>& s_res, vector<string>& path) {
//	if (path.size() == length_data)
//	{
//		string result;
//		for (auto i : path)
//		{
//			result += i;
//		}
//		s_res.insert(result);
//		return;
//	}
//	for (int i = 0; i < vec.size(); i++)
//	{
//		if (used[i]) continue;
//		path.push_back(vec[i]);
//		used[i] = true;
//		backtrack(used, s_res, path);
//		path.pop_back();
//		used[i] = false;
//	}
//}
//
//int main()
//{
//	// 输入数据
//	cin >> length_data;
//	cin.get();
//	string str;
//	getline(cin, str);
//	istringstream ss(str);
//	string temp;
//	while (ss >> temp)
//	{
//		vec.push_back(temp);
//	}
//	// dfs
//	vector<bool> used(vec.size(), false);
//	set<string> s_res;
//	vector<string> path;
//	backtrack(used, s_res, path);
//	for (auto i : s_res)
//	{
//		cout << i << endl;
//	}
//}