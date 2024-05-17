/*
* 429、货车司机、高效货运
题目描述：
1.老李是货运公司承运人，老李的货车额定载货重量为wt
2.现有两种货物，货物A单件重量为wa，单件运费利润为pa，货物B单件重量为wb，单件运费利润为pb
3.老李每次发车时载货总重量刚好为货车额定载货重量wt，车上必须同时有货物A和货物B，货物A、B不可切割
4.老李单车次满载运输可获得的最高利润是多少

输入描述：
第一列输入为货物A的单件重量wa，0<wa<10000
第二列输入为货物B的单件重量wb，0<wb<10000
第三列输入为货车的额定载重wt，0<wt<100000
第四列输入为货物A的单件运费利润pa，0<pa<1000
第五列输入为货物B的单件运费利润pb，0<pb<1000

输出描述：
单次满载运输的最高利润

示例1
输入：
10 8 36 15 7
输出：
44

示例2
输入：
1 1 2 1 1
输出：
2

思路：枚举
枚举运输 A货物的数量，并计算剩余的车载能运送多少个 B 货物，如果能整除，就用当前这两种货物的价值更新答案。
*/

#include<iostream>
#include<vector>
#include<algorithm>

using namespace std;

int main()
{
	int wa, wb, wt, pa, pb;	// A的单件重量wa, B的单件重量wb, 货车的额定载重wt, A的单件运费利润pa, B的单件运费利润pb
	cin >> wa >> wb >> wt >> pa >> pb;
	int max_profit = 0;
	for (int i = 1; wa * i < wt; i++)
	{
		int j = (wt - wa * i) / wb;
		if (j < 1) continue;
		max_profit = max(max_profit, i * pa + j * pb);
	}
	cout << max_profit;

}