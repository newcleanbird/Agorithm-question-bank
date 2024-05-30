/*
找数字
题目
给一个二维数组nums，对于每一个元素num[i]，找出距离最近的且值相等的元素，输出横纵坐标差值的绝对值之和，如果没有等值元素，则输出-1。
例如：
输入数组nums为

0 3 5 4 2
2 5 7 8 3
2 5 4 2 4
对于 num[0][0] = 0，不存在相等的值。
对于 num[0][1] = 3，存在一个相等的值，最近的坐标为num[1][4]，最小距离为4。
对于 num[0][2] = 5，存在两个相等的值，最近的坐标为num[1][1]，故最小距离为2。
…
对于 num[1][1] = 5，存在两个相等的值，最近的坐标为num[2][1]，故最小距离为1。
…
故输出为

-1 4 2 3 3
1 1 -1 -1 4
1 1 2 3 2

输入
输入第一行为二维数组的行
输入第二行为二维数组的列
输入的数字以空格隔开。

输出
数组形式返回所有坐标值。

备注
针对数组num[i][j]，满足 0\u003Ci≤100；0\u003Cj≤100。
对于每个数字，最多存在 100 个与其相等的数字。
示例一
输入
3
5
0 3 5 4 2
2 5 7 8 3
2 5 4 2 4
输出
-1 4 2 3 3
1 1 -1 -1 4
1 1 2 3 2


[[-1, 4, 2, 3, 3], [1, 1, -1, -1, 4], [1, 1, 2, 3, 2]]
*/

#include <bits/stdc++.h>

using namespace std;

int fuction(int a, int b, vector<vector<int> > arr){
    int row = arr.size();
    int col = arr[0].size();
    int min = row+col+1, temp = row+col+1;              // 存储当前最小值 当前相等值的绝对距离 a+b+1是一个比较值
    for(int i = 0; i < row; i++){
        for(int j = 0; j < col ; j++){
            if((i == a) && (j == b)) continue;
            if(arr[a][b] == arr[i][j]){
                temp = abs(i - a) + abs(j - b);
                if(temp < min){
                    min = temp;
                }
            }
        }
    }
    //cout << a << b << min;
    if(min == row+col+1){
        return -1;
    }
    else{
        return min;
    }
}


int main() {
    int row,col;
    cin >> row >> col;
    vector<vector<int> > arr(row, vector<int>(col));
    for(int i = 0; i < row; i++){
        for(int j = 0; j < col; j++){
            cin >> arr[i][j];
        }
    }
    vector<vector<int> > res(row, vector<int>(col));
    for(int i = 0; i < row; i++){
        for(int j = 0; j < col; j++){
            res[i][j] = fuction(i, j, arr);
        }
    }
    for(auto i : res){
        for(auto j : i){
            cout << j << " ";
        }
        cout << endl;
    }
    // cout << fuction(0, 1, arr);// 0 1 出错    


    system("pause");
}