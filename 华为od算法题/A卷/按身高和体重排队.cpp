/*
AC
按身高和体重排队
题目
某学校举行运动会，学生们按编号(1、2、3…n)进行标识，现需要按照身高由低到高排列，对身高相同的人，按体重由轻到重排列；
对于身高体重都相同的人，维持原有的编号顺序关系。请输出排列后的学生编号。

输入输出描述:
输入描述:
两个序列，每个序列由n个正整数组成（0 < n <= 100）。第一个序列中的数值代表身高，第二个序列中的数值代表体重。

输出描述:
排列结果，每个数值都是原始序列中的学生编号，编号从1开始

示例1：
输入
4
100 100 120 130
40 30 60 50

输出
2 1 3 4

说明
输出的第一个数字2表示此人原始编号为2，即身高为100，体重为30的这个人。由于他和编号为1的人身高一样，但体重更轻，因此要排在1前面。

示例2：
输入
3
90 110 90
45 60 45

输出
1 3 2

说明
1和3的身高体重都相同，需要按照原有位置关系让1排在3前面，而不是3 1 2

*/

#include<bits/stdc++.h>

using namespace std;

struct people
{
    int index;
    int height;
    int weight;
};

// 身高由低到高,体重由轻到重
bool cmp(people &a, people &b)
{
    return a.height < b.height || (a.height==b.height) && (a.weight <b.weight );
}

int main()
{
    int n; // n个学生
    cin >> n;
    vector<people> student(n);
    // 将身高和体重数组输入
    for(int i = 0; i < n; i++)
    {
        cin >> student[i].height;
    }
    for(int i = 0; i < n; i++)
    {
        cin >> student[i].weight;
    }
    for(int i = 0; i < n; i++)
    {
        student[i].index = i+1;
    }
    sort(student.begin(), student.end(), cmp);
    for(auto i : student)
    {
        cout << i.index << " ";
    }
    system("pause");
    
}