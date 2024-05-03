/*
451、 手机App防沉迷系统
题目描述：
智能手机方便了我们生活的同时，也侵占了我们不少的时间。“手机App防沉迷系统”能够让我们每天合理的规划手机App使用时间，在正确的时间做正确的事。
它的大概原理是这样的：
1、在一天24小时内，可注册每个App的允许使用时段；
2、一个时段只能使用一个App，举例说明：不能同时在09:00-10:00注册App2和App3；
3、App有优先级，数值越高，优先级越高。注册使用时段时，如果高优先级的App时间和低优先级的时段有冲突，则系统会自动注销低优先级的时段；如果App的优先级相同，则后添加的App不能注册。

举例1：
（1）注册App3前：
（2）App3注册时段和App2有冲突：
（3）App3优先级高，系统接受App3的注册，自动注销App2的注册：

举例2：
（1）注册App4：
（2）App4和App2及App3都有冲突，优先级比App2高，但比App3低，这种场景下App4注册不上，最终的注册效果如下：

4、一个App可以在一天内注册多个时段。

请编程实现，根据输入数据注册App，并根据输入的时间点，返回该时间点可用的App名称，如果该时间点没有注册任何App，请返回字符串"NA"。

输入描述：
输入分3部分：第一行表示注册的App数N（N≤100）；第二部分包括N行，每行表示一条App注册数据；最后一行输入一个时间点，程序即返回该时间点的可用App。
2
App1 1 09:00 10:00
App2 2 11:00 11:30
09:30

数据说明如下：
1、N行注册数据以空格分隔，四项数据依次表示：App名称、优先级、起始时间、结束时间
2、优先级1-5，数字值越大，优先级越高
3、时间格式HH:MM，小时和分钟都是两位，不足两位前面补0
4、起始时间需小于结束时间，否则注册不上
5、注册信息中的时间段包含起始时间点，不包含结束时间点

输出描述：
输出一个字符串，表示App名称，或NA表示空闲时间。

补充说明：
1、用例保证时间都介于00:00-24:00之间；
2、用例保证数据格式都是正确的，不用考虑数据输入行数不够、注册信息不完整、字符串非法、优先级超限、时间格式不正确的问题。

示例1
输入：
1
App1 1 09:00 10:00
09:30
输出：
App1
说明：
App1注册在9点到10点间，9点半可用的应用名是App1

示例2
输入：
2
App1 1 09:00 10:00
App2 2 09:10 09:30
09:20
输出：
App2
说明：
App1和App2的时段有冲突，App2的优先级比App1高，注册App2后，系统将App1的注册信息自动注销后，09:20时刻可用应用名是App2.

示例3
输入：
2
App1 1 09:00 10:00
App2 2 09:10 09:30
09:50
输出：
NA
说明：
App1被注销后，09:50时刻没有应用注册，因此输出NA。
*/
#include<iostream>
#include<vector>
#include<string>
#include<algorithm>

using namespace std;

struct apptime
{
	int hour;
	int minute;
	bool operator>=(apptime& b)
	{
		if (this->hour != b.hour)
		{
			return this->hour >= b.hour;
		}
		else {
			return this->minute >= b.minute;
		}
	}
};

struct app
{
	string name;
	int priority;
	apptime begin;
	apptime end;
};

bool cmp(app& a, app& b)
{
	return a.priority > b.priority;
}

int main()
{
	// 输入
	int n;
	cin >> n;
	vector<app> vec(n);
	for (int i = 0; i < n; i++)
	{
		string tbeg, tend;
		cin >> vec[i].name >> vec[i].priority >> tbeg >> tend;
		vec[i].begin.hour = stoi(tbeg.substr(0, 2));
		vec[i].begin.minute = stoi(tbeg.substr(3));
		vec[i].end.hour = stoi(tend.substr(0, 2));
		vec[i].end.minute = stoi(tend.substr(3));
	}
	apptime query_time;
	string stime;
	cin >> stime;
	query_time.hour = stoi(stime.substr(0, 2));
	query_time.minute = stoi(stime.substr(3));


	// 计算
	vector<app> res;	// 记录最终每个时段的结果
	for (int i = 0; i < vec.size(); i++)
	{
		// 获得结果集中所有和app[i]相关的
		vector<int> ids;
		for (int j = 0; j < res.size(); j++)
		{
			if (vec[i].end >= res[j].begin && res[j].end >= vec[i].begin)	// i遍历的和结果集中的j有交集，将j加入需要判断的队列
			{
				ids.push_back(j);
			}
		}
		int priority_max = -1;
		for (int i = 0; i < ids.size(); i++)
		{
			priority_max = max(priority_max, res[ids[i]].priority);
		}
		if (vec[i].priority > priority_max)
		{
			for (int j = ids.size() - 1; j >= 0; j--)
			{
				res.erase(res.begin() + ids[j]);
			}
			res.push_back(vec[i]);
		}
	}
	
	// 查询结果
	string ans = "NA";
	for (auto i : res)
	{
		if (query_time >= i.begin && i.end >= query_time)
		{
			ans = i.name;
		}
	}
	cout << ans;
	

}