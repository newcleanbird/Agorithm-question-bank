///*
//441、符号运算
//题目描述：
//给定一个表达式，求其分数计算结果
//表达式的限制如下：
//1. 所有的输入数字皆为正整数(包括0)
//2. 仅支持四则运算(+-* /)和括号
//3. 结果为整数或分数, 分数必须化为最简格式(比如6, 3 / 4, 7 / 8, 90 / 7)
//4. 除数可能为0，如果遇到这种情况，直接输出"ERROR"
//5. 输入和最终计算结果中的数字都不会超出整型范围
//
//用例的输入一定合法, 不会出现括号不匹配的情况
//输入描述：
//字符串格式的表达式，仅支持 + - * / ，数字可能超过两位，可能带有空格，没有负数
//长度小于200个字符
//
//输出描述：
//表达式结果，以最简格式表达
//如果结果为整数，那么直接输出整数
//如果结果为分数，那么分子分母不可再约分，可以为假分数，不可表达为带分数
//结果可能是负数, 负号放在最前面
//
//示例1
//输入：
//1 + 5 * 7 / 8
//输出：
//43 / 8
//说明：
//
//示例2
//输入：
//1 / (0 - 5)
//输出：
//- 1 / 5
//说明：
//负号需要提到最前面
//
//示例3
//输入：
//1 * (3 * 4 / (8 - (7 + 0)))
//输出：
//12
//说明：
//注意括号可以多重嵌套
//
//思路：计算中缀表达式
//1. 利用栈来实现转换
//转换过程需要用到栈，这里使用两个栈：stack 栈用来存放运算符，post 栈用来存放最后的后缀表达式。具体规则如下：
//从左到右扫描中缀表达式：
//若是操作数，直接存入 post 栈；
//若是运算符：
//（1）该运算符是左括号 ( , 则直接存入 stack 栈。
//（2）该运算符是右括号 )，则将 stack 栈中 ( 前的所有运算符出栈，存入 post 栈。
//（3）若该运算符为非括号，则将该运算符和 stack 栈顶运算符作比较：若高于栈顶运算符，则直接存入 stack 栈，否则将栈顶运算符出栈（从栈中弹出元素直到遇到发现更低优先级的元素(或者栈为空)为止），存入 post 栈。
//（4）当扫描完后，stack 栈中还有运算符时，则将所有运算符出栈，存入 post 栈。
//
//*/
//
#include <iostream>
#include <stack>
#include <string>
#include <sstream>

using namespace std;


int getPrecedence(char op) {
   if (op == '+' || op == '-')
       return 1;
   else if (op == '*' || op == '/')
       return 2;
   /*else if (op == '^')
       return 3;*/
   else
       return 0;
}

string infixToPostfix(const string& infix) {
   stack<char> operators;
   string postfix;
   for (size_t i = 0; i < infix.length(); ++i) {
       if (isdigit(infix[i])) {
           // 处理多位数的情况
           while (i + 1 < infix.length() && isdigit(infix[i + 1])) {
               postfix += infix[i];
               ++i;
           }
           postfix += infix[i]; // 添加最后一个数字
           postfix += ' '; // 添加空格分隔符
       }
       else if (infix[i] == '(') {
           operators.push(infix[i]);
       }
       else if (infix[i] == ')') {
           while (!operators.empty() && operators.top() != '(') {
               postfix += operators.top();
               postfix += ' '; // 添加空格分隔符
               operators.pop();
           }
           operators.pop(); // 弹出左括号
       }
       else {
           while (!operators.empty() && getPrecedence(infix[i]) <= getPrecedence(operators.top())) {
               postfix += operators.top();
               postfix += ' '; // 添加空格分隔符
               operators.pop();
           }
           operators.push(infix[i]);
       }
   }
   while (!operators.empty()) {
       postfix += operators.top();
       postfix += ' '; // 添加空格分隔符
       operators.pop();
   }
   return postfix;
}

/*计算后缀表达式，其中后缀表达式的数字可能有多位，数字和符号之间用空格间隔*/
int calculatePostfixExpression(const std::string& expression) {
   std::stack<int> numStack;
   std::istringstream iss(expression);
   std::string token;

   while (iss >> token) {
       if (token == "+" || token == "-" || token == "*" || token == "/") {
           int num2 = numStack.top();
           numStack.pop();
           int num1 = numStack.top();
           numStack.pop();

           if (token == "+") {
               numStack.push(num1 + num2);
           }
           else if (token == "-") {
               numStack.push(num1 - num2);
           }
           else if (token == "*") {
               numStack.push(num1 * num2);
           }
           else if (token == "/") {
               numStack.push(num1 / num2);
           }
       }
       else {
           numStack.push(std::stoi(token));
       }
   }

   return numStack.top();
}

/*计算后缀表达式，其中后缀表达式的数字可能有多位，数字和符号之间用空格间隔，除法结果用最简分数的形式表示*/
int gcd(int a, int b) {
   return b == 0 ? a : gcd(b, a % b);
}

std::pair<int, int> simplifyFraction(int numerator, int denominator) {
   int g = gcd(numerator, denominator);
   return std::make_pair(numerator / g, denominator / g);
}

int calculatePostfixExpression_1(const std::string& expression) {
   std::stack<std::pair<int, int>> numStack;
   std::istringstream iss(expression);
   std::string token;

   while (iss >> token) {
       if (token == "+" || token == "-" || token == "*" || token == "/") {
           int num2 = numStack.top().first;
           int den2 = numStack.top().second;
           numStack.pop();
           int num1 = numStack.top().first;
           int den1 = numStack.top().second;
           numStack.pop();

           if (token == "+") {
               numStack.push(simplifyFraction(num1 * den2 + num2 * den1, den1 * den2));
           }
           else if (token == "-") {
               numStack.push(simplifyFraction(num1 * den2 - num2 * den1, den1 * den2));
           }
           else if (token == "*") {
               numStack.push(simplifyFraction(num1 * num2, den1 * den2));
           }
           else if (token == "/") {
               numStack.push(simplifyFraction(num1 * den2, den1 * num2));
           }
       }
       else {
           std::istringstream issNum(token);
           int numerator, denominator;
           issNum >> numerator;
           issNum.ignore();
           issNum >> denominator;
           numStack.push(std::make_pair(numerator, denominator));
       }
   }

   return numStack.top().first;
}

int main() {
   //string infixExpression = "3+45*67";
   string infixExpression = "1+5*7/8";
   string postfixExpression = infixToPostfix(infixExpression);
   cout << "Infix expression: " << infixExpression << endl;
   cout << "Postfix expression: " << postfixExpression << endl;
   //cout << "表达式求值：" << calculatePostfixExpression(postfixExpression) << endl;
   cout << "表达式求值：" << calculatePostfixExpression_1(postfixExpression) << endl;
   return 0;
}

