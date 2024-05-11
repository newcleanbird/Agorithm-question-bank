/*
469、测试用例执行计划
题目描述：
某个产品当前迭代周期内有N个特性（ F1,F2,.......FN）需要进行覆盖测试，每个特性都被评估了对应的优先级，特性使用其ID作为下标进行标识。
设计了M个测试用例（T1,T2......,TM ），每个用例对应了一个覆盖特性的集合，测试用例使用其ID作为下标进行标识，测试用例的优先级定义为其覆盖的特性的优先级之和。
在开展测试之前，需要制定测试用例的执行顺序，规则为：优先级大的用例先执行，如果存在优先级相同的用例，用例ID小的先执行。

输入描述：
第一行输入为N和M，N表示特性的数量，M表示测试用例的数量， 0＜N≤100,
0＜M≤100 之后N行表示特性ID=1到特性ID=N的优先级。
再接下来M行表示测试用例ID=1到测试用例ID=M关联的特性的ID的列表。

输出描述：
按照执行顺序（优先级从大到小）输出测试用例的ID，每行一个ID。
测试用例覆盖的ID不重复。

示例1
输入：
5 4
1
1
2
3
5
1 2 3
1 4
3 4 5
2 3 4

输出：
3
4
1
2
说明：测试用例的优先级计算如下：

T1=Pf1+Pf2+Pf3=1+1+2=4
T2=Pf1+Pf4=1+3=4
T3=Pf3+Pf4+Pf5=2+3+5=10
T4=Pf2+Pf3+Pf4=1+2+3=6

按照优先级从小到大，以及相同优先级，ID小的先执行的规则，执行顺序为T3,T4,T1,T2

示例2
输入：
3 3
3
1
5
1 2 3
1 2 3
1 2 3

输出：
1
2
3

说明：测试用例的优先级计算如下：
T1=Pf1+Pf2+PF3=3+1+5=9
T2=Pf1+Pf2+PF3=3+1+5=9
T3=Pf1+Pf2+PF3=3+1+5=9
每个优先级一样，按照ID从小到大执行，执行顺序为T1,T2,T3
*/
#include<iostream>
#include<vector>
#include<algorithm>
#include<queue>

using namespace std;

struct task
{
	int prior_level;	// 优先级
	int No;				// 编号
};

bool cmp(task& a, task& b)
{
	if (a.prior_level != b.prior_level)
	{
		return a.prior_level > b.prior_level;
	}
	else {
		return a.No < b.No;
	}
}

int main()
{
	int n, m;	// N表示特性的数量，M表示测试用例的数量
	cin >> n >> m;
	vector<int> prior_level(n+1);	// 特性优先级
	for (int i = 1; i <= n; i++)
	{
		cin >> prior_level[i];
	}
	vector<task> tasks(m);	// 测试用例ID=1到测试用例ID=M关联的特性的ID的列表
	for (int i = 0; i < m; i++)
	{
		int tmp;
		while (cin >> tmp)
		{
			tasks[i].No = i+1;
			tasks[i].prior_level += prior_level[tmp];
			if (cin.get() == '\n') break;
		}
	}

	sort(tasks.begin(), tasks.end(), cmp);
	for (auto i : tasks)
	{
		cout << i.No << endl;
	}







}