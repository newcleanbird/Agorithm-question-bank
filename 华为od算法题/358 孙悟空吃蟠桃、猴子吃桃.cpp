/*
358、孙悟空吃蟠桃、猴子吃桃
题目描述：
孙悟空爱吃蟠桃，有一天趁着蟠桃园守卫不在来偷吃。已知蟠桃园有N颗桃树，每颗树上都有桃子，守卫将在H小时后回来。
孙悟空可以决定他吃蟠桃的速度K（个/小时），每个小时选一颗桃树，并从树上吃掉K个，如果树上的桃子少于K个，则全部吃掉，并且这一小时剩余的时间里不再吃桃。
孙悟空喜欢慢慢吃，但又想在守卫回来前吃完桃子。
请返回孙悟空可以在H小时内吃掉所有桃子的最小速度K（K为整数）。如果以任何速度都吃不完所有桃子，则返回0。

输入描述：
第一行输入为N个数字，N表示桃树的数量，这N个数字表示每棵桃树上蟠桃的数量。
第二行输入为一个数字，表示守卫离开的时间H。
其中数字通过空格分割，N、H为正整数，每棵树上都有蟠桃，且0<N<10000，0<H<10000。

输出描述：
吃掉所有蟠桃的最小速度K，无解或输入异常时输出0。

示例1
输入：
2 3 4 5
4
输出：
5
说明：

示例2
输入：
2 3 4 5
3
输出：
0
说明：

示例3
输入：
30 11 23 4 20
6
输出：
23
说明：
*/
#include<iostream>
#include<vector>
#include<algorithm>

using namespace std;

int solution(vector<int>& p, int H)
{
	if (H < p.size()) return 0;
	int speed = 1;
	while(speed++)
	{
		int count = 0;
		for (int i = 0; i < p.size(); i++)
		{
			count += ceil((double)p[i] / speed);
			// cout << "speed" << speed << " " << "p[i]:" << p[i] << " " << ceil((double)p[i] / speed) << endl;
		}
		if (count <= H)
		{
			return speed;
			break;
		}
	}

}


int main()
{
	vector<int> p;		// 桃子
	int tmp;
	while (cin >> tmp)
	{
		p.push_back(tmp);
		if (cin.get() == '\n') break;
 	}
	int H; 
	cin >> H; // 守卫离开的时间
	int res = 0;
	sort(p.begin(), p.end(), less<int>());
	res = solution(p, H);
	cout << res << endl;


	//cout << ceil((double)2 / 3);
}