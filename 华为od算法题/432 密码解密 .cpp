/*
432、 密码解密

题目描述：
给定一段"密文"字符串s,其中字符都是经过"密码本"映射的，现需要将"密文"解密并且输出
   映射的规则 （'a'-'i')分别用('1'-'9')表示；('j'-'z')分别用('10*'-'26*')表示
   约束：映射始终唯一

输入描述：
“密文”字符串

输出描述：
明文字符串

补充说明：
翻译后的文本的长度在100以内

示例1
输入：
20*19*20*
输出：
tst
说明：
*/

#include<iostream>
#include<vector>
#include<string>
#include<queue>

using namespace std;

int main()
{
	string str;
	getline(cin, str);
	string res;
	//// 加密
	//for (auto i : str)
	//{
	//	if (i >= 'a' && i <= 'i')
	//	{
	//		res += to_string((int)(i- 'a' + 1));
	//	}
	//	else {
	//		int tmp = (int)(i - 'a' + 1);
	//		res += to_string(tmp);
	//		res += '*';
	//	}
	//}
	// 解密
	queue<int> que;
	for (auto i : str)
	{
		if (i == '*')
		{
			while (que.size() > 2)
			{
				char tmp = que.front() + 'a' - '1';
				que.pop();
				res += tmp;
			}
			int c1 = que.front() - '0'; que.pop();
			int c2 = que.front() - '0'; que.pop();
			int n = c1 * 10 + c2;
			res += 'a' + n - 1;
		}
		else {
			que.push(i);
		}
	}
	while (que.size() != 0)
	{
		char tmp = que.front() + 'a' - '1' + 1;
		que.pop();
		res += tmp;
	}
	cout << res;
}