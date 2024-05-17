///*
//457、根据IP查找城市
//题目描述：
//某业务需要根据终端的IP地址获取该终端归属的城市，可以根据公开的IP地址池信息查询归属城市。地址池格式如下城市名=起始IP,结束IP，起始和结束地址按照英文逗号分隔，多个地址段采用英文分号分隔。
//比如City1=1.1.1.1,1.1.1.2;City1=1.1.1.11,1.1.1.16;City2=3.3.3.3,4.4.4.4;City3=2.2.2.2,6.6.6.6。
//一个城市可以有多个IP段，比如City1有2个IP段。城市间也可能存在包含关系，如City3的IP段范围包含City2的IP段范围。现在要根据输入的IP列表，返回最佳匹配的城市列表。
//注：最佳匹配即包含待查询IP且长度最小的IP段，比如例子中3.4.4.4最佳匹配是City2=3.3.3.3,4.4.4.4，5.5.5.5的最佳匹配是City3=2.2.2.2,6.6.6.6。
//
//输入描述：
//输入共2行。
//第一行为城市的IP段列表，多个IP段采用英文分号';'分隔，IP段列表最大不超过500000。城市名称只包含英文字母、数字和下划线，最多不超过100000个。IP段包含关系可能有多层，但不超过100层。
//第二行为查询的IP列表，多个IP采用英文逗号‘,’分隔，最多不超过10000条。
//
//输出描述：
//最佳匹配的城市名列表，采用英文逗号‘,’分隔，城市列表长度应该跟查询的IP列表长度一致。
//补充说明：
//1）无论是否查到匹配正常都要输出分隔符。举例：假如输入IP列表为IPa,IPb两个IP均未有匹配城市，此时输出为“,”，即只有一个逗号分隔符，两个城市均为空；
//2）可以假定用例中的所有输入均合法，IP地址均为合法的ipv4地址，满足（1~255）.（0~255）.（0~255）.（0~255）的格式，且可以假定用例中不会出现组播和广播地址；
//
//示例1
//输入：
//City1=1.1.1.1,1.1.1.2;City1=1.1.1.11,1.1.1.16;City2=3.3.3.3,4.4.4.4;City3=2.2.2.2,6.6.6.6
//1.1.1.15,3.3.3.5,2.2.2.3
//输出：
//City1,City2,City3
//说明：
//1）City1有2个IP段，City3的IP段包含City2的IP段；
//2）1.1.1.15仅匹配City1=1.1.1.11,1.1.1.16，所以City1就是最佳匹配；2.2.2.3仅匹配City3=2.2.2.2,6.6.6.6，所以City3是最佳匹配；3.3.3.5同时匹配为City2=3.3.3.3,4.4.4.4和City3=2.2.2.2,6.6.6.6，但是City3=2.2.2.2,6.6.6.6的IP段范围更小，所以City3为最佳匹配；
//*/
//#include<iostream>
//#include<vector>
//#include<string>
//#include<sstream>
//#include<limits>
//
//using namespace std;
//
//struct city
//{
//	string name;
//	unsigned long start;
//	unsigned long end;
//
//	city(string name, long start, long end) : name(name), start(start), end(end)
//	{
//
//	}
//};
//
//unsigned long ipToUl(string ip)
//{
//	istringstream iss(ip);
//	unsigned long ulip = 0;
//	string token;
//	while (getline(iss, token, '.'))
//	{
//		ulip += stoul(token);
//	}
//	return ulip;
//}
//
//int main()
//{
//	// 输入
//	string str_city;	// 城市的IP段列表
//	getline(cin, str_city);
//	string str_query;   // 查询的IP列表
//	getline(cin, str_query);
//
//
//	vector<city> cities;
//	vector<unsigned long> quiries;
//
//	// 处理输入数据
//	istringstream iss1(str_city);
//	string s_city;
//	while (getline(iss1, s_city, ';'))
//	{
//		size_t pos1 = s_city.find('=');
//		size_t pos2 = s_city.find(',');
//
//		string name = s_city.substr(0, pos1);
//		string ip1 = s_city.substr(pos1 + 1, pos2 - pos1);
//		string ip2 = s_city.substr(pos2 + 1);
//
//		city c1(name, ipToUl(ip1), ipToUl(ip2));
//		cities.push_back(c1);
//	}
//
//	istringstream iss2(str_query);
//	string s_ip;
//	while(getline(iss2, s_ip, ','))
//	{
//		quiries.push_back(ipToUl(s_ip));
//	}
//
//	// 开始查询
//	vector<string> res;
//	for (auto& i : quiries)
//	{
//		string name;
//		unsigned long gap = numeric_limits<unsigned long>::max();
//		for (auto& j : cities)
//		{
//			if (i >= j.start && i <= j.end)
//			{
//				if (j.end - j.start < gap)
//				{
//					name = j.name;
//					gap = j.end - j.start;
//				}
//			}
//		}
//		res.push_back(name);
//	}
//
//	for (int i = 0; i < res.size(); i++)
//	{
//		cout << res[i];
//		if (i != res.size() - 1)
//		{
//			cout << ',';
//		}
//	}
//}