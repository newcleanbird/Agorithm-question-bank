/*
434 围棋的气、围棋气数
题目描述：
围棋棋盘由纵横各19条线垂直相交组成，棋盘上一共19x19=361个交点，对弈双方一方执白棋，一方执黑棋，落子时只能将棋子置于交点上。
“气”是围棋中很重要的一个概念，某个棋子有几口气，是指其上下左右方向四个相邻的交叉点中，有几个交叉点没有棋子，由此可知：
1、在棋盘的边缘上的棋子最多有3口气（黑1），在棋盘角点的棋子最多有2口气（黑2），其它情况最多有4口气（白1）
2、所有同色棋子的气之和叫作该色棋子的气，需要注意的是，同色棋子重合的气点，对于该颜色棋子来说，只能计算一次气，比如下图中，黑棋一共4口气，而不是5口气，因为黑1和黑2中间红色三角标出的气是两个黑棋共有的，对于黑棋整体来说只能算一个气。
3、本题目只计算气，对于眼也按气计算，如果您不清楚“眼”的概念，可忽略，按照前面描述的规则计算即可。
现在，请根据输入的黑棋和白棋的坐标位置，计算黑棋和白起一共各有多少气？

输入描述：
输入包括两行数据，如：
0 5 8 9 9 10
5 0 9 9 9 8
1、每行数据以空格分隔，数据个数是2的整数倍，每两个数是一组，代表棋子在棋盘上的坐标；
2、坐标的原点在棋盘左上角点，第一个值是行号，范围从0到18；第二个值是列号，范围从0到18。
3、举例说明：第一行数据表示三个坐标（0，5）、（8，9）、（9，10）
4、第一行表示黑棋的坐标，第二行表示白棋的坐标。
5、题目保证输入两行数据，无空行且每行按前文要求是偶数个，每个坐标不会超出棋盘范围。

输出描述：
8 7
两个数字以空格分隔，第一个数代表黑棋的气数，第二个数代表白棋的气数。

示例1
输入：
0 5 8 9 9 10
5 0 9 9 9 8
输出：

8 7
说明：
如果将输入数据放到棋盘上，数数黑棋一共8口气：
数数白棋一共7口气：

思路："枚举"
1. 先输入所有的黑棋和白棋
2. 遍历棋盘，枚举四个方向即可
*/

#include<iostream>
#include<map>
#include<set>
#include<vector>
#include<algorithm>

using namespace std;

void count(int i, int j, vector<vector<int>>& map, bool& black, bool& white)
{
	if (i < 0 || j < 0 || i > 18 || j > 18)
	{
		return;
	}
	if (map[i][j] == 1)
	{
		black = true;
	}
	if(map[i][j] == 2){
		white = true;
	}
}

int main()
{
	// 输入
	vector<vector<int>> map(19, vector<int>(19, 0));
	int a, b;
	while (cin >> a >> b)
	{
		map[a][b] = 1;	// 黑棋
		if (cin.peek() == '\n') break;
	}
	cin.get();
	while (cin >> a >> b)
	{
		map[a][b] = 2;	// 白棋
		if (cin.peek() == '\n') break;
	}
	// 计算
	int white = 0, black = 0;
	for (int i = 0; i < 19; i++)
	{
		for (int j = 0; j < 19; j++)
		{
			// 当前节点
			if (map[i][j] == 0)
			{
				bool has_black = false, has_white = false;
				count(i - 1, j, map, has_black, has_white);
				count(i, j - 1, map, has_black, has_white);
				count(i + 1, j, map, has_black, has_white);
				count(i, j + 1, map, has_black, has_white);
				if (has_black == true) black++;
				if (has_white == true) white++;
			}
		}
	}
	cout << black << " " << white;
}