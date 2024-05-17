/*
跳房子，也叫跳飞机，是—种世界性的儿童游戏，游戏参与者需要分多个回合按顺序跳到第1格直到房子的最后—格。跳房子的过程中，可以向前跳，也可以向后跳。
假设房子的总格数是count，小红每回合可能连续跳的步教都放在数组steps中，请问数组中是否有一种步数的组合，可以让小红两个回合跳到最后—格?如果有，请输出索引和最小的步数组合。
注意:
数组中的步数可以重复，但数组中的元素不能重复使用。提供的数据保证存在满足题目要求的组合，且索引和最小的步数组合是唯一的
输入描述
第一行输入为房子总格数count，它是int整数类型。
第二行输入为每回合可能连续跳的步数，它是int整数数组类型。
输出描述
返回索引和最小的满足要求的步数组合(顺序保持steps中原有顺序）
备注
count ≤ 1000
0 ≤ steps.length ≤ 5000
-100000000 steps ≤ 100000000

示例1:
输入：
7
1,4,5,2,2
输出
5, 2

示例2:
输入
8
-1,2,4,9,6
输出
-1,9
说明
此样例有多种组合满足两回合跳到最后，譬如: [-1,9]，[2,6]，其中[-1,9]的索引和为0+3=3，[2,6]的索和为1+4=5，所以索引和最小的步数组合[-1,9]


// 可以向前跳，可以向后跳。寻找一种组合，使和为所求。
先确定一个值，如果小于目标值，寻找另一个值
如果大于目标值，寻找差值(负值)
*/

#include<iostream>
#include<string>
#include<vector>
#include<algorithm>

using namespace std;

int main()
{
	int count;
	cin >> count;
	cin.get();
	vector<int> steps;
	string str;
	getline(cin, str);
	string tmp;
	for (auto i : str)
	{
		if (i != ',')
		{
			tmp += i;
		}
		else {
			steps.push_back(stoi(tmp));
			tmp.clear();
		}
	}
	steps.push_back(stoi(tmp));
	// 计算
	// sort(steps.begin(), steps.end(), less<int>());	// 先排序
	
	int l = 0, r = steps.size() - 1;
	int dif;
	for (int i = 0; i < steps.size(); i++)
	{
		for (int j = i + 1; j < steps.size(); j++)
		{
			dif = steps[i] + steps[j];
			if (dif == count)
			{
				cout << steps[i] << " " << steps[j];
				break;
			}
			dif = abs(steps[i] - steps[j]);
			if (dif == count)
			{
				cout << steps[i] << " " << steps[j];
				break;
			}
		}
	}
}