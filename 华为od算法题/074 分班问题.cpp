/*
74、 分班问题
题目
幼儿园两个班的小朋友在排队时混在了一起，每位小朋友都知道自己是否与前面一位小朋友同班，请你帮忙把同班的小朋友找出来。
小朋友的编号是整数，与前一位小朋友同班用Y表示，不同班用N表示。
学生序号范围(0,999]，如果输入不合法则打印ERROR。
输入描述：

输入为空格分开的小朋友编号和是否同班标志。
输出描述：

输出为两行，每一行记录一个班小朋友的编号，编号用空格分开，且：
1.编号需按照升序排列。
2.若只有一个班的小朋友，第二行为空行。
示例1 输入输出示例仅供调试，后台判题数据一般不包含示例

输入
1/N 2/Y 3/N 4/Y

输出
1 2
3 4

示例2 输入输出示例仅供调试，后台判题数据一般不包含示例

输入
1/N 2/Y 3/N 4/Y 5/Y

输出
1 2
3 4 5

思路：一共只有两个班，
	每次处理：以 / 为分界线，斜杠前的所有数字为存储序号，斜杠后的字符为判断标志。
*/

#include<iostream>
#include<string>
#include<vector>
#include<algorithm>

using namespace std;

int main()
{
	string str;
	getline(cin, str);
	vector<int> class1;	// 一班
	vector<int> class2;	// 二班
	bool isFiest = false;// 设置标志位
	string seq;
	int num;
	for (int i = 0; i < str.size(); i++)
	{
		if (isdigit(str[i]))
		{
			seq.append(1, str[i]);
		}
		else if (str[i] == '/')
		{
			num = stoi(seq);
			seq.clear();
			i++;
			if (str[i] == 'N')
			{
				isFiest = !isFiest;
			}
			else {
				// 不取反
			}
			if (isFiest == true)
			{
				class1.push_back(num);
			}
			else {
				class2.push_back(num);
			}
		}
	}

	// 输出结果
	for (auto i : class1)
	{
		cout << i << " ";
	}
	cout << endl;
	for (auto i : class2)
	{
		cout << i << " ";
	}
	


}