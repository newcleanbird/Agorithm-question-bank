///*
//题目描述：
//
//公司用一个字符串来表示员工的出勤信息：
//absent：缺勤
//late：迟到
//leaveearly：早退
//present：正常上班
//现需根据员工出勤信息，判断本次是否能获得出勤奖，能获得出勤奖的条件如下：
//缺勤不超过一次；没有连续的迟到/早退；任意连续7次考勤，缺勤/迟到/早退不超过3次
//输入描述：
//
//用户的考勤数据字符串，记录条数 >= 1；输入字符串长度<10000；不存在非法输入
//如：
//
//2
//present
//present absent present present leaveearly present absent
//
//输出描述：
//根据考勤数据字符串，如果能得到考勤奖，输出"true"；否则输出"false"，对于输入示例的结果应为：
//
//true false
//
//示例1
//
//输入：
//
//2
//present
//present present
//输出：
//
//true true
//说明：
//
//示例2
//
//输入：
//
//2
//present
//present absent present present leaveearly present absent
//输出：
//
//true false
//说明：
//
//*/
//
//#include<iostream>
//#include<sstream>
//#include<string>
//#include<vector>
//
//using namespace std;
//
//bool isPrice(string &str1)
//{
//	
//
//	// 存入vector<string> 里
//	vector<string> vec;
//	istringstream is(str1);
//	string str;
//	while (is >> str)
//	{
//		vec.push_back(str);
//	}
//
//	// 判断
//	int absent = 0;		// 缺勤
//	int present = 0;	// 正常上班
//	string preRecord = "";
//	for (int i = 0; i < vec.size(); i++)
//	{
//		// 当总打卡数大于7时，移动窗口，即对最左边的打卡记录进行处理
//		if (i > 7)
//		{
//			if (vec[i - 7] == "present")
//			{
//				present--;
//			}
//		}
//		// 判断当前的打卡情况
//		if (vec[i] == "absent")
//		{
//			if (++absent > 1) return false;
//		}
//		else if (vec[i] == "late" || vec[i] == "leaveearly")
//		{
//			if (preRecord == "late" || preRecord == "leaveearly")
//			{
//				return false;
//			}
//		}
//		else if (vec[i] == "present")
//		{
//			present++;
//		}
//		// 连续7次打卡超过3次有问题
//		int window_len = min(i + 1, 7);
//		if (window_len - present > 3) return false;
//	}
//	return true;
//}
//
//int main()
//{
//	int count = 0;
//	cin >> count;
//	string str;
//	cin.get();
//
//	vector<bool> res;
//	while (count--)
//	{
//		getline(cin, str);
//		res.push_back(isPrice(str));
//	}
//	for (auto i : res)
//	{
//		if(i == true)cout << "true" << " ";
//		else cout << "false" << " ";
//	}
//
//}