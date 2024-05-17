///*
//* 472 攀登者2
//攀登者喜欢寻找各种地图，并且尝试攀登到最高的山峰。
//地图表示为一维数组，数组的索引代表水平位置，数组的元素代表相对海拔高度。其中数组元素0代表地面。
//例如：[0,1,2,4,3,1,0,0,1,2,3,1,2,1,0]，代表如下图所示的地图，地图中有两个山脉位置分别为 1,2,3,4,5 和 8,9,10,11,12,13，最高峰高度分别为 4,3。最高峰位置分别为3,10。
//一个山脉可能有多座山峰(高度大于相邻位置的高度，或在地图边界且高度大于相邻的高度)。
//
//			  4
//			+---+
//			|	|
//			|	|
//			|	| 3						  3
//			|	+---+					+---+
//			|		|					|	|
//			|		|					|	|
//		  2	|		|				  2 |	|	  2
//		+---+		|				+---+	|	+---+
//		|			|				|		|	|	|
//		|			|				|		|	|	|
//	  1	|			| 1			  1 |		| 1	|	| 1
//	+---+			+---+		+---+		+---+	+---+
//	|					|		|						|
//	|					|		|						|
//  0	|					| 0   0 |						| 0
//+---+					+---+---+						+---+
//  0   1   2   3   4   5   6   7   8   9  10  11  12  13  14
//
//1.登山时会消耗登山者的体力(整数)，上山时，消耗相邻高度差两倍的体力，下坡时消耗相邻高度差一倍的体力，平地不消耗体力，登山者体力消耗到零时会有生命危险.
//例如上图所示的山峰， 从索引0，走到索引1，高度差为1，需要消耗2X1=2的体力，从索引2高度2走到高度4索引3需要消耗2X2=4的体力。如果是从索引3走到索引4则消耗1X1=1的体力。
//2.登山者体力上限为999。
//3.登山时的起点和终点可以是地图中任何高度为0的地面例如上图中的0,6,7,14，都可以作为登山的起点和终点
//
//攀登者想要评估一张地图内有多少座山峰可以进行攀登，且可以安全返回到地面，且无生命危险
//例如上图中的数组，有3个不同的山峰，登上位置在3的山可以从位置0或者位置6开始，从位置0登到山顶需要消耗体力1X2+1X2+2X2 = 8，从山顶返回到地面0需要消耗 2X1+1X1 + 1X1 = 4 的体力，按照登山路线0->3->0需要消耗体力12。攀登者至少需要12以上的体力(大于12)才能安全返回。
//
//
//示例1
//输入
//0,1,4,3,1,0,0,1,2,3,1,2,1,0
//13
//输出
//3
//说明
//登山者只能够登上位置10和12的山峰，7->10->7，14->12->14
//
//示例2
//输入
//1,4,3
//999
//输出
//0
//说明
//原题输入输出描述有问题，待修正
//*/
//#include<iostream>
//#include<string>
//#include<vector>
//
//using namespace std;
//
//vector<int> mountain;
//vector<int> cost_m;
//
//void find_mountain(vector<int>& m)
//{
//	// int l = -1, r = m.size(), top;
//	for (int i = 0; i < m.size(); i++)
//	{
//		if (m.size() == 1)	// 只有唯一的值，应该不存在这种情况.只是为了保证 m大于1
//		{
//			mountain.push_back(i);
//		}
//		else if (i == 0)
//		{
//			if (m[i] > m[i + 1])
//			{
//				mountain.push_back(i);
//			}
//			
//		}
//		else if(i == m.size() - 1)
//		{
//			if (m[i] > m[i - 1])
//			{
//				mountain.push_back(i);
//			}
//		}
//		else {
//			if (m[i] > m[i + 1] && m[i] > m[i - 1])
//			{
//				mountain.push_back(i);
//			}
//		}
//	}
//}
//
//int find_left_zero(vector<int>& m, int index)
//{
//	for (int i = index; i >= 0; i--)
//	{
//		if (m[i] == 0)
//		{
//			return i;
//		}
//	}
//	return -1;
//}
//
//int find_right_zero(vector<int>& m, int index)
//{
//	for (int i = index; i < m.size(); i++)
//	{
//		if (m[i] == 0)
//		{
//			return i;
//		}
//	}
//	return -1;
//}
//
//int left_to_right(vector<int>& m, int l, int top)	// 从左向右出发
//{
//	int cost = 0;
//	for (int i = l+1; i <= top; i++)	// 从i - > top
//	{
//		if (m[i] > m[i - 1])	// 向上走
//		{
//			cost += (m[i] - m[i - 1]) * 2;
//		}
//		else {
//			cost += m[i-1] - m[i]; // 往下走
//		}
//	}
//	if (cost == 0)
//	{
//		return 1000;
//	}
//	else {
//		return cost;
//	}
//	
//}
//
//int right_to_left(vector<int>& m, int r, int top) // 从右向左出发
//{
//	int cost = 0;
//	for (int i = r - 1; i >= top; i--)
//	{
//		if (m[i] > m[i + 1])	// 向上走
//		{
//			cost += (m[i] - m[i + 1]) * 2;
//		}
//		else {
//			cost += m[i + 1] - m[i]; // 往下走
//		}
//	}
//	if (cost == 0)
//	{
//		return 1000;
//	}
//	else {
//		return cost;
//	}
//}
//
//void find_min(vector<int>& m)
//{
//	for (auto i : mountain)
//	{
//		int min_up_cost = 1000;
//		int min_down_cost = 1000;
//		int left_zero = find_left_zero(m, i);
//		int right_zero = find_right_zero(m, i);
//		// 上山
//		if (left_zero != -1)
//		{
//			min_up_cost = min(min_up_cost, left_to_right(m, left_zero, i));
//		}
//		if (right_zero != -1)
//		{
//			min_up_cost = min(min_up_cost, right_to_left(m, right_zero, i));
//		}
//		// 下山
//		if (right_zero != -1)
//		{
//			min_down_cost = min(min_down_cost, left_to_right(m, i, right_zero));
//		}
//		if (left_zero != -1)
//		{
//			min_down_cost = min(min_down_cost, right_to_left(m, i, left_zero));
//		}
//		cost_m.push_back(min_up_cost + min_down_cost);
//	}
//}
//
//int main()
//{
//	// 输入
//	vector<int> m;
//	string str;
//	getline(cin, str);
//	string s;
//	for (int i = 0; i < str.size(); i++)
//	{
//		if (str[i] != ',')
//		{
//			s += str[i];
//		}
//		else {
//			m.push_back(stoi(s));
//			s.clear();
//		}
//	}
//	if (!s.empty())
//	{
//		m.push_back(stoi(s));
//	}
//	int power;
//	cin >> power;
//
//	// 先找到所有山峰的山顶和山脚
//	find_mountain(m);
//
//	// 查询每座山的最小体力耗费
//	find_min(m);
//
//	int count = 0;
//	// 能攀爬的数量
//	for (auto i : cost_m)
//	{
//		if (i <= power)
//		{
//			count++;
//		}
//	}
//	cout << count;
//}
//
