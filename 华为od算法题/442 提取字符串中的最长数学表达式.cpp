/*
题目描述：
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

输入：
1-2abcd

输出：
-1

-1+2-3+4ab-1+1+1+1+1

思路：
正则表达式
*/

#include<iostream>
#include<string>
#include<vector>
#include<regex>
#include<stack>


using namespace std;

string findexpression(string& s)
{
//	regex expRagex(R"(^[+-]?(\d[+-*])+\d$)");	// 正则表达式的规则
	regex expRagex(R"([+\-]?(\d+[+\-*])+\d+)");
	sregex_iterator beg(s.begin(), s.end(), expRagex);
	sregex_iterator end = sregex_iterator();

	int max_length = 0;
	string longestexpression;
	for (sregex_iterator i = beg; i != end; i++)
	{
		string matchstr = i->str();		// 匹配到的字符串
		if (matchstr.size() > max_length)
		{
			max_length = matchstr.size();
			longestexpression = matchstr;
		} 
	}
	return longestexpression;
}


// 功能：计算简单数学表达式的值
long evaluateExpression(const string& expression) {
    if (expression.empty()) return 0; // 如果表达式为空，直接返回0

    stack<long> values;     // 使用栈来存储中间结果
    long currentNumber = 0; // 当前解析的数字
    char sign = '+';        // 当前数字前的操作符，默认为'+'
    for (int i = 0; i <= expression.size(); ++i) {
        char c = i < expression.size() ? expression[i] : '+'; // 读取字符或在表达式末尾追加'+'
        if (isdigit(c)) { // 如果字符是数字
            currentNumber = currentNumber * 10 + (c - '0'); // 累加形成整数
        }
        else if (c == '+' || c == '-' || c == '*' || i == expression.size()) { // 如果字符是操作符或已达字符串末尾
            if (c != '*' && !values.empty() && values.top() == -1) {
                values.pop(); // 如果栈顶为-1（之前的符号为减号），则弹出
                sign = '-';  // 将符号改为负号
            }
            switch (sign) {
            case '+': values.push(currentNumber); break; // 加法：将当前数字压入栈
            case '-': values.push(-currentNumber); break; // 减法：将当前数字的负值压入栈
            case '*':
                long top = values.top(); // 取出栈顶元素
                values.pop(); // 弹出栈顶元素
                values.push(top * currentNumber); // 执行乘法并将结果压回栈
                break;
            }
            currentNumber = 0; // 重置当前数字
            sign = c; // 更新操作符
        }
    }

    long result = 0; // 初始化结果
    while (!values.empty()) {
        result += values.top(); // 将栈中所有数字累加
        values.pop(); // 弹出栈顶元素
    }
    return result; // 返回计算结果
}

int main()
{
	string str;
	getline(cin, str);
	string longestexpression = findexpression(str);
	int res = evaluateExpression(str);
	cout << res;
}