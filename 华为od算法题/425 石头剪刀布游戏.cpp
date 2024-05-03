/*
425 石头剪刀布游戏
题目描述：
石头剪刀布游戏有3种出拳形状：石头、剪刀、布。 分别用字母 A,B,C表示。

游戏规则：
1）出拳形状之间的胜负规则如下：A> B；B> C；C> A
“>” 左边一个字母，表示相对优势形状。 右边一个字母，表示相对劣势形状。
2) 当本场次中有且仅有一种出拳形状优于其它出拳形状，则该形状的玩家是胜利者。 否则认为是平局。
例如1 三个玩家出拳分别是 A,B,C。由于出现三方优势循环（即没有任何一方优于其它出拳者），判断为平局。
例如2 三个玩家，出拳分别是 A,B。出拳A的获胜。
例如3   三个玩家，出拳全部是 A。 判为平局
3）当发生平局，没有赢家。有多个胜利者时，同为赢家。
输入描述：
在一场游戏中，每个玩家的信息为一行。玩家数量不超过1000。玩家信息2个字段，用空格隔开：
1）玩家ID：一个仅由英文字母和数字组成的字符串。
2）出拳形状：以英文大写字母表示，A、B、C形状。
3）出拳时间：正整数，越小表示时间越早

例如：
abc1 A
xyz B
解释：玩家abc1 出拳为石头（A）。玩家 xyz 出拳为剪刀（B）
输出描述：
输出为赢家的玩家ID列表（一个或多个），每个ID一行，按字符串升序排列。 如果没有赢家，输出为“NULL”字符串。
例如：
abc1
示例1
输入：
s
s
输出：
abc1
说明：
A比B有优势，abc1 胜出

示例2
输入：
abc1 A
xyz A
输出：
NULL
说明：
没有优胜的出拳形状，平局

示例3
输入：
abc1 A
def A
alic A
xyz B
输出：
abc1
alic
def
说明：
A为优胜方，有三个赢家
*/

#include<iostream>
#include<vector>
#include<string>
#include<unordered_map>
#include<algorithm>

using namespace std;

int main()
{
	// 输入	
	unordered_map<char, vector<string>> player;
	string name;
	char shape;
	while (cin >> name >> shape)
	{
		if (shape < 'A' || shape > 'C') {
			std::cout << "NULL" << std::endl;
			return 0;
		}
		player[shape].push_back(name);
		cin.get();
	}
	// 计算
	vector<string> res;
	if (player.size() == 1 || player.size() == 3)
	{
		std::cout << "NULL" << std::endl;
	}
	else {
		if (player.find('A') == player.end()) // 找不到A，即只有B 和 C，即胜者为B
		{
			res = player['B'];
		}
		else if (player.find('B') == player.end())
		{
			res = player['C'];
		}
		else if (player.find('C') == player.end())
		{
			res = player['A'];
		}
	}
	sort(res.begin(), res.end());
	for (auto i : res)
	{
		cout << i << endl;
	}


}