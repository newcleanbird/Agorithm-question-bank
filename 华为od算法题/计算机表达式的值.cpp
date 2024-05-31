///*
//-5-5+5-5+5+99*2
//
//
//*/
//
//#include <iostream>
//#include <stack>
//#include <string>
//#include <sstream>
//
//using namespace std;
//
//// 不带括号的表达式计算值
//int calculate(const std::string& expression) {
//    std::stack<int> nums;
//    std::stack<char> ops;
//    int num = 0;
//    char op = '+';
//
//    for (int i = 0; i < expression.size(); ++i) {
//        char c = expression[i];
//        if (isdigit(c)) {
//            num = num * 10 + (c - '0');
//        }
//        if ((!isdigit(c) && c != ' ') || i == expression.size() - 1) {
//            switch (op) {
//            case '+':
//                nums.push(num);
//                break;
//            case '-':
//                nums.push(-num);
//                break;
//            case '*':
//                nums.top() *= num;
//                break;
//            case '/':
//                nums.top() /= num;
//                break;
//            }
//            op = c;
//            num = 0;
//        }
//    }
//
//    int result = 0;
//    while (!nums.empty()) {
//        result += nums.top();
//        nums.pop();
//    }
//    return result;
//}
//
//// 带括号的表达式计算
//int calculate_1(string s) {
//    int n = s.size();
//    int res = 0, num = 0, sign = 1;
//    stack<int> stk;
//    for (int i = 0; i < n; ++i) {
//        char c = s[i];
//        if (isdigit(c)) {
//            num = num * 10 + (c - '0');
//        }
//        else if (c == '+' || c == '-') {
//            res += sign * num;
//            num = 0;
//            sign = (c == '+') ? 1 : -1;
//        }
//        else if (c == '(') {
//            stk.push(res);
//            stk.push(sign);
//            res = 0;
//            sign = 1;
//        }
//        else if (c == ')') {
//            res += sign * num;
//            num = 0;
//            res *= stk.top(); stk.pop();
//            res += stk.top(); stk.pop();
//        }
//    }
//    res += sign * num;
//    return res;
//}
//
//int main() {
//    std::string expression;
//    std::cout << "请输入一个字符串表达式： ";
//    std::getline(std::cin, expression);
//    std::cout << "方法1计算的表达式的值为： " << calculate(expression) << std::endl;
//    std::cout << "方法2计算的表达式的值为： " << calculate_1(expression) << std::endl;
//    return 0;
//}