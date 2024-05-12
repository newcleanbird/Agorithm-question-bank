/*
455、螺旋数字矩阵
题目描述：
疫情期间，小明隔离在家，百无聊赖，在纸上写数字玩。他发明了一种写法：
给出数字个数n和行数m（0 < n ≤ 999，0 < m ≤ 999），从左上角的1开始，按照顺时针螺旋向内写方式，依次写出2,3...n，最终形成一个m行矩阵。
小明对这个矩阵有些要求：
1.每行数字的个数一样多
2.列的数量尽可能少
3.填充数字时优先填充外部
4.数字不够时，使用单个*号占位

输入描述：
两个整数，空格隔开，依次表示n、m

输出描述：
符合要求的唯一矩阵

示例1
输入：
9 4
输出：
1 2 3
* * 4
9 * 5
8 7 6
说明：
9个数字写成4行，最少需要3列

示例2
输入：
3 5
输出：
1
2
3
*
*
说明：
3个数字写5行，只有一列，数字不够用*号填充

示例3
输入：
120 7
输出：
1 2 3 4 5 6 7 8 9 10 11 12 13 14 15 16 17 18
46 47 48 49 50 51 52 53 54 55 56 57 58 59 60 61 62 19
45 84 85 86 87 88 89 90 91 92 93 94 95 96 97 98 63 20
44 83 114 115 116 117 118 119 120 * * * * * * 99 64 21
43 82 113 112 111 110 109 108 107 106 105 104 103 102 101 100 65 22
42 81 80 79 78 77 76 75 74 73 72 71 70 69 68 67 66 23
41 40 39 38 37 36 35 34 33 32 31 30 29 28 27 26 25 24
*/

#include<iostream>
#include<vector>
#include<string>

using namespace std;

vector<int> dx = { 0,1,0 ,-1 };
vector<int> dy = { 1,0,-1, 0 };

void printMap(vector<vector<string>>& map)
{
	for (auto& i : map)
	{
		for (auto& j : i)
		{
			cout << j << " ";
		}
		cout << endl;
	}
	cout << endl;
}

void solution(vector<vector<string>>& map, int n)
{
	// 开始填充
	int x_max = map.size();
	int y_max = map[0].size();
	int id = 1;
	int dir = 0;
	int x = 0, y = 0;
	while (id <= n)
	{
		map[x][y] = to_string(id);
		if (id == n) break;
		int nx, ny;

		while (1)
		{
			nx = x + dx[dir];
			ny = y + dy[dir];
			if (nx < 0 || nx >= x_max || ny < 0 || ny >= y_max || map[nx][ny] != "*")
				dir = (dir + 1) % 4;
			else
				break; // 找到合法位置，跳出循环
		}
		x = nx;
		y = ny;
		id++;
	}
}

int main()
{
	int n, x;	// 个数n和行数m
	cin >> n >> x;
	int y = ceil((double)n / x);

	vector<vector<string>> map(x, vector<string>(y,"*"));	// map[x][y]
	
	solution(map, n);
	printMap(map);
}