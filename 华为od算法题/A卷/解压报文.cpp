/*
题目描述
为了提升数据传输的效率，会对传输的报文进行压缩处理。输入一个压缩后的报文，请返回它解压后的原始报文。
压缩规则：n[str]，表示方括号内部的 str 正好重复 n 次。注意 n 为正整数（0 < n <= 100），str只包含小写英文字母，不考虑异常情况。

输入描述
输入压缩后的报文：

1）不考虑无效的输入，报文没有额外的空格，方括号总是符合格式要求的；
2）原始报文不包含数字，所有的数字只表示重复的次数 n ，例如不会出现像 5b 或 3[8] 的输入；

输出描述
解压后的原始报文

注：
1）原始报文长度不会超过1000，不考虑异常的情况

示例1
输入
3[k]2[mn]
输出
kkkmnmn

示例2
输入
3[m2[c]]
输出
mccmccmcc

示例3
输入
10[k]2[mn3[j2[op]]]
输出
kkkkkkkkkkmnjopopjopopjopopmnjopopjopopjopop


*/

/*
思考：
    格式:数字*[字符]
    遇到],将]之前的数据进行入栈
*/
#include<bits/stdc++.h>

using namespace std;

/*
思考：
    格式:数字*[字符]
    遇到],将]之前的数据进行入栈
*/
// 10[k]2[mn3[j2[op]]]
int main()
{
    string s;
    getline(cin, s); // 输入一行字符串
    string result;
    // 需要处理，数字，字符，左括号[,右括号]
    for(int i = 0; s.find(']') != s.npos; i++)
    {
        // 遇到]
        if(s[i] == ']')
        {
            int j = i; // j为向左搜索的指针
            // 向左搜索，直到搜索到[,此时j的索引为[
            while(s[j] != '[' && j>=0)
            {
                j--;
            }
            cout <<"j:" << endl;
            string tmp = s.substr(j+1, i-j-1); // 获得重复部分的子串，开始点j+1，长度为i-j-1
            cout << "tmp:" << tmp << endl;
            // 开始找数字
            int num;
            int k = j-1;
            while(isdigit(s[k]) && k>=0)
            {
                k--;
                // cout << "k:" << k << " " <<endl;
            }
            // k在数字上一个位置
            string s2 = s.substr(k+1,j-k-1);
            num = stoi(s2);
            cout << "num:" << num << endl; //  查看num
            s.erase(k+1, i-k);
            i = 0;  // i重置
            while(num--)
            {
                s.insert(k+1, tmp);
            }
            cout << "s" << s << endl; // 查看s
        }
    }
    
    cout << s;
    system("pause");

}

/*
    好的版本：
*/
// Online C++ compiler to run C++ program online
#include<iostream>
#include<vector>
#include<stdlib.h>
#include<algorithm>
#include<iomanip>
#include<string.h>
#include<exception> 
#include<map>
#include<cmath>
#include<unordered_map>
#include<set>
#include<climits>
#include<ctype.h>
#include<queue>
#include<stack>
using namespace std;
 
int main() {
    string input_str;
    // 带空格的字符串输入
    getline(cin,input_str);
    
    stack<string> char_stack;
    int i = 0;
    while (i < input_str.size()) {
        // 字母情况
        if(isalpha(input_str[i])){
            int j = i;
            while (j < input_str.size() && isalpha(input_str[j])) {  // 找到第一个不是字母的位置
                j++;
            }
            char_stack.push(input_str.substr(i, j - i));
            i = j; // 更新位置到字母位置
        // 数字情况
        } else if (isdigit(input_str[i])) {
            int j = i;
            while(j < input_str.size() && isdigit(input_str[j])){ // 找到第一个不是数字的位置
                j++;
            }
            char_stack.push(input_str.substr(i, j - i));
            i = j ; // 更新位置到数字位置
        // == ']'
        } else if (input_str[i] == ']') {
            // 遇到第一个]符号，说明到了最深一层的字符，可以弹出栈顶元素进行组合。
            // 此时栈顶必然是一个字符串，且下一个必然是数字
            string currStr = char_stack.top(); char_stack.pop();
            int currCnt = stoi(char_stack.top()); char_stack.pop();
            string tmpStr;
            while (currCnt > 0){
                tmpStr.append(currStr);
                currCnt--;
            }
            if(char_stack.empty()){
                char_stack.push(tmpStr);
            }else{
                char_stack.top() += tmpStr;
            }
            i++; //下一个字符
        // == '['
        } else { 
            i++; //下一个字符
        }
    }
 
 
    string result;
    while (!char_stack.empty()){
        result += char_stack.top(); 
        char_stack.pop();
    }
    cout<< result;
    return 0;
}