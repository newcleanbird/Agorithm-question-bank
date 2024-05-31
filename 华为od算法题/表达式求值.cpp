//#include <iostream>
//#include <stack>
//#include <string>
//#include <sstream>
//
//using namespace std;
//
//int getPrecedence(char op) {
//    if (op == '+' || op == '-')
//        return 1;
//    else if (op == '*' || op == '/')
//        return 2;
//    /*else if (op == '^')
//        return 3;*/
//    else
//        return 0;
//}
//
//string infixToPostfix(const string& infix) {
//    stack<char> operators;
//    string postfix;
//    for (size_t i = 0; i < infix.length(); ++i) {
//        if (isdigit(infix[i])) {
//            // 处理多位数的情况
//            while (i + 1 < infix.length() && isdigit(infix[i + 1])) {
//                postfix += infix[i];
//                ++i;
//            }
//            postfix += infix[i]; // 添加最后一个数字
//            postfix += ' '; // 添加空格分隔符
//        }
//        else if (infix[i] == '(') {
//            operators.push(infix[i]);
//        }
//        else if (infix[i] == ')') {
//            while (!operators.empty() && operators.top() != '(') {
//                postfix += operators.top();
//                postfix += ' '; // 添加空格分隔符
//                operators.pop();
//            }
//            operators.pop(); // 弹出左括号
//        }
//        else {
//            while (!operators.empty() && getPrecedence(infix[i]) <= getPrecedence(operators.top())) {
//                postfix += operators.top();
//                postfix += ' '; // 添加空格分隔符
//                operators.pop();
//            }
//            operators.push(infix[i]);
//        }
//    }
//    while (!operators.empty()) {
//        postfix += operators.top();
//        postfix += ' '; // 添加空格分隔符
//        operators.pop();
//    }
//    return postfix;
//}
//
//int calculatePostfixExpression(const std::string& expression) {
//    std::stack<int> numStack;
//    std::istringstream iss(expression);
//    std::string token;
//
//    while (iss >> token) {
//        if (token == "+" || token == "-" || token == "*" || token == "/") {
//            int num2 = numStack.top();
//            numStack.pop();
//            int num1 = numStack.top();
//            numStack.pop();
//
//            if (token == "+") {
//                numStack.push(num1 + num2);
//            }
//            else if (token == "-") {
//                numStack.push(num1 - num2);
//            }
//            else if (token == "*") {
//                numStack.push(num1 * num2);
//            }
//            else if (token == "/") {
//                numStack.push(num1 / num2);
//            }
//        }
//        else {
//            numStack.push(std::stoi(token));
//        }
//    }
//
//    return numStack.top();
//}
//
//int main() {
//    string infixExpression = "3+45*67";
//    string postfixExpression = infixToPostfix(infixExpression);
//    cout << "Infix expression: " << infixExpression << endl;
//    cout << "Postfix expression: " << postfixExpression << endl;
//    cout << "表达式求值：" << calculatePostfixExpression(postfixExpression) << endl;
//    return 0;
//}
