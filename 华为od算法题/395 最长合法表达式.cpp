/*
395、最长合法表达式 / 提取字符串中的最长数学表达式并计算
提取字符串中的最长合法简单数学表达式，字符串长度最长的，并计算表达式的值。如果没有，则返回0
简单数学表达式只能包含以下内容
0-9数字，符号 +-*
说明：
1. 所有数字，计算结果都不超过long
2. 如果有多个长度一样的，请返回第一个表达式的结果
3. 数学表达式，必须是最长的，合法的
4. 操作符不能连续出现，如 +--+1 是不合法的

输入描述：
字符串

输出描述：
表达式值

补充说明：

示例1
输入：
1-2abcd
输出：
-1
说明：

ab1-2+3-4+ba-1-2-3-4+5*5+99

思路：
使用正则表达式进行匹配

难点：计算字符串表达式的值
1. 使用栈(因为本题没有括号，因此可以直接解)
2. 中缀转后缀，后缀求值。(正常思路)


*/

#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
#include <regex>
#include <stack>

using namespace std;

//vector<char> chars{ '0', '1', '2', '3', '4', '5', '6', '7', '8', '9', '+', '-', '*' };
//
//bool is_exp(string& str, int start, int end)
//{
//	bool is_sign = false;
//	for (int i = start; i <= end; i++)
//	{
//		if (find(chars.begin(), chars.end(), str[i]) != chars.end())	// 负号不存在，不是合法表达式
//		{
//			return false;
//		}
//		else if (isdigit(str[i]) && is_sign)		// 当前字符是数字，上一个是符号
//		{
//			is_sign = false;
//		}
//		else if (!isdigit(str[i]) && is_sign)		// 当前是符号，上一个是数字
//		{
//			is_sign = true;
//		}
//		else if (isdigit(str[i]) && is_sign)
//		{
//			return false;
//		}
//		else if (!isdigit(str[i]) && !is_sign)
//		{
//			return false;
//		}
//	}
//}
// 修建字符串，移除空格
void trim(string& s)
{
    int index = 0;
    if (!s.empty())
    {
        while ((index = s.find(' ', index)) != string::npos)
        {
            s.erase(index, 1);
        }
    }
}

// 计算字符串表达式的值
int calculate(const std::string& expression) {
    std::stack<int> nums;
    std::stack<char> ops;
    int num = 0;
    char op = '+';

    for (int i = 0; i < expression.size(); ++i) {
        char c = expression[i];
        if (isdigit(c)) {
            num = num * 10 + (c - '0');
        }
        if ((!isdigit(c) && c != ' ') || i == expression.size() - 1) {
            switch (op) {
            case '+':
                nums.push(num);
                break;
            case '-':
                nums.push(-num);
                break;
            case '*':
                nums.top() *= num;
                break;
            case '/':
                nums.top() /= num;
                break;
            }
            op = c;
            num = 0;
        }
    }

    int result = 0;
    while (!nums.empty()) {
        result += nums.top();
        nums.pop();
    }
    return result;
}

int main()
{
    //输入
	string s;    // 存储输入的字符串
	getline(cin, s);
    
    // 搜索
    int maxExpLen = 0;
    long ans = 0;
    string maxstr;
    for (int i = 0; i < s.length(); i++) 
    {
        for (int j = i; j < s.length(); j++) 
        {
            string sub = s.substr(i, j - i + 1);
            regex reg(R"(^[+-]?(\d+[+\-*])+\d+$)");    // +- 数字 +-* 数字
            if (regex_match(sub, reg) && sub.length() > maxExpLen) {
                maxExpLen = j - i + 1;
                //ans = calculate(sub);
                maxstr = sub;
            }
        }
    }
    ans = calculate(maxstr);
    cout << "manstr:" << maxstr << " =" << ans << endl;
    cout << "maxExpLen:" << maxExpLen<< endl;

    return 0;



}
