/*
寻找相似单词
知识点字符串排序 字符比较

时间限制：1s 空间限制：256MB 限定语言：不限

题目描述：
给定一个可存储若干单词的字典，找出指定单词的所有相似单词，并且按照单词名称从小到大排序输出。单词仅包括字母，但可能大小写并存（大写不一定只出现在首字母）。
相似单词说明：给定一个单词X，如果通过任意交换单词中字母的位置得到不同的单词Y，那么定义Y是X的相似单词，如abc、bca即为相似单词（大小写是不同的字母，如a和A算两个不同字母）。
字典序排序： 大写字母\u003C小写字母。同样大小写的字母，遵循26字母顺序大小关系。即A\u003CB\u003CC\u003C...\u003CX\u003CY\u003CZ\u003Ca\u003Cb\u003Cc\u003C...\u003Cx\u003Cy\u003Cz. 如Bac\u003CaBc\u003CacB\u003CcBa.
输入描述：
第一行为给定的单词个数N（N为非负整数）
从第二行到地N+1行是具体的单词（每行一个单词）
最后一行是指定的待检测单词（用于检测上面给定的单词中哪些是与该指定单词是相似单词，该单词可以不是上面给定的单词）

输出描述：
从给定的单词组中，找出指定单词的相似单词，并且按照从小到大字典序排列输出，中间以空格隔开
如果不存在，则输出null（字符串null）

示例1
输入：
4
abc
dasd
tad
bca
abc

输出：
abc bca

说明：
在给定的输入中，与abc是兄弟单词的是abc bca，且输出按照字典序大小排序，输出的所有单词以空格隔开

示例2
输入：
4
abc
dasd
tad
bca
abd

输出：
null

说明：
给定单词组中，没有与给定单词abd是兄弟单词，输出为null（字符串null）
*/

#include <bits/stdc++.h>

using namespace std;

int main() {
    int n;
    cin >> n; // 一共有n个单词
    vector<string> s1(n);
    string ch;
    for(int i = 0; i < n; i++)
    {
        cin >> ch;
        s1[i] = ch;
    }

    multiset<char> str;

    cin >> ch;
    for(auto i : ch){
        str.insert(i);
    }

    multiset<string> res;
    for(int i = 0; i < n; i++){
        multiset<char> str1;
        for(auto j : s1[i])
        {
            str1.insert(j);
        }
        if(str1 == str){
            res.insert(s1[i]);
        }
    }

    if(res.size() == 0) cout << "NULL";
    else{
        for(auto i : res){
            cout << i << endl;
        }        
    }

    system("pause");
}