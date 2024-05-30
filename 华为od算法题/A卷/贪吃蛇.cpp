/*
https://blog.csdn.net/weixin_40767375/article/details/125612947
标题：贪吃蛇 | 时间限制：1秒 | 内存限制：262144K | 语言限制：不限
贪吃蛇是一个经典游戏，蛇的身体由若干方格连接而成，身体随蛇头移动。蛇头触碰到食物时，蛇的长度会增加一格。
蛇头和身体的任一方格或者游戏版图边界碰撞时，游戏结束。
下面让我们来完成贪吃蛇游戏的模拟。
给定一个N*M的数组arr，代表N*M个方格组成的版图，贪吃蛇每次移动一个方格。
若arr[i][j] == 'H'，表示该方格为贪吃蛇的起始位置；
若arr[i][j] == 'F'，表示该方格为食物，若arr[i][j] == 'E'，表示该方格为空格。

贪吃蛇初始长度为1，初始移动方向为向左。为给定一系列贪吃蛇的移动操作，返回操作后蛇的长度，如果在操作执行完之前已经游戏结束，返回游戏结束时蛇的长度。

贪吃蛇移动、吃食物和碰撞处理的细节见下面图示：



图1：截取了贪吃蛇移动的一个中间状态，H表示蛇头，F表示食物，数字为蛇身体各节的编号，蛇为向左移动，此时蛇头和食物已经相邻
图2：蛇头向左移动一格，蛇头和食物重叠，注意此时食物的格子成为了新的蛇头，第1节身体移动到蛇头位置，第2节身体移动到第1节身体位置，以此类推，最后添加第4节身体到原来第3节身体的位置。
图3：蛇头继续向左移动一格，身体的各节按上述规则移动，此时蛇头已经和边界相邻，但还未碰撞。
图4：蛇头继续向左移动一格，此时蛇头已经超过边界，发生碰撞，游戏结束。
图5和图6给出一个蛇头和身体碰撞的例子，蛇为向上移动。图5时蛇头和第7节身体相邻，但还未碰撞；图6蛇头向上移动一格，此时蛇头和第8节身体都移动到了原来第7节身体的位置，发生碰撞，游戏结束。

输入描述:

输入第一行为空格分隔的字母，代表贪吃蛇的移动操作。字母取值为U、D、L、R和G，U、D、L、R分别表示贪吃蛇往上、下、左、右转向，转向时贪吃蛇不移动，G表示贪吃蛇按当前的方向移动一格。用例保证输入的操作正确。
第二行为空格分隔的两个数，指定N和M，为数组的行和列数。
余下N行每行是空格分隔的M个字母。
字母取值为H、F和E，H表示贪吃蛇的起始位置，F表示食物，E表示该方格为空。
用例保证有且只有一个H，而F和E会有多个。

输出描述:

输出一个数字，为蛇的长度。

示例1
输入

D G G
3 3
F F F
F F H
E F E

输出

1

说明

贪吃蛇一开始就向下转向并且移动两步，此时蛇头已经和边界碰撞，游戏结束，蛇没有吃任何食物，故长度为1

示例2
输入

G G G
3 3
F F F
F F H
E F E

输出

3

说明

贪吃蛇保存最初的向左方向移动三步，此时蛇头已经和边界碰撞，游戏结束，蛇吃了两个食物，故长度为3

*/


#include<bits/stdc++.h>

using namespace std;


void print(vector<vector<char>> &map)
{
    cout << "map:" << endl;
    for(auto i : map)
    {
        for(auto j : i)
        {
            cout << j << " ";
        }
        cout << endl;
    }
    cout << "*****************" << endl;
}
//U、D、L、R分别表示贪吃蛇往上、下、左、右转向
// H表示贪吃蛇的起始位置，F表示食物，E表示该方格为空
bool move(char direction, vector<vector<int>> &snake, vector<vector<char>> &map) // 移动操作
{
    // 判断方向
    int row_offset,col_offset; // 行偏移，列偏移
    if(direction == 'U')    // 向上
    {
        row_offset = -1;
        col_offset = 0;
    }
    if(direction == 'D')    // 向下
    {
        row_offset = 1;
        col_offset = 0;
    }
    if(direction == 'L')    // 向左
    {
        row_offset = 0;
        col_offset = -1;
    }
    if(direction == 'R')    // 向右
    {
        row_offset = 0;
        col_offset = 1;
    }
    int row_new = snake[0][0]+row_offset;
    int col_new = snake[0][1]+col_offset;
    // print(map);  调试用
    if(row_new >= map.size() || row_new < 0 || col_new >= map[0].size() || col_new < 0) // 碰撞
    {
        return false;
    }
    if(map[snake[0][0]+row_offset][snake[0][1]+col_offset] == 'E') // 前方为空格
    {
        // 更新蛇头
        snake.insert(snake.begin(), {snake[0][0]+row_offset, snake[0][1]+col_offset}); // 在蛇表的头部插入移动方向的格子为蛇头
        // 更新地图
        map[snake[0][0]][snake[0][1]] = 'H';    // 把前方格子标记为蛇
        // 地图设置蛇尾为空
        map[snake[snake.size()-1][0]][snake[snake.size()-1][1]] = 'E'; 
        // 删去最后一节
        snake.pop_back(); 
    }
    if(map[snake[0][0]+row_offset][snake[0][1]+col_offset] == 'F') // 前方为食物
    {
        // 更新蛇头
        snake.insert(snake.begin(), {snake[0][0]+row_offset, snake[0][1]+col_offset}); 
        // 更新地图
        map[snake[0][0]][snake[0][1]] = 'H';
    }
    if(map[snake[0][0]+row_offset][snake[0][1]+col_offset] == 'H') // 前方为蛇身
    {
        //游戏结束
        return false;
        // cout << snake.size(); // 输出蛇的长度
    }
    // else{    // 碰撞咯
    //     // 不想写了，就算是0吧
    //     //游戏结束
    //     // cout << snake.size(); // 输出蛇的长度
    //     return false;
    // }
    return true;
    // if(direction == 'U') // 向上
    // {
    //     if(map[snake[0][0]+1][snake[0][1]] == 'E')
    //     // 更新蛇的序列
    //     snake.insert(snake.begin(), {snake[0][0]+1, snake[0][1]}); // 更新蛇头
    //     snake.pop_back(); // 删去最后一节
    // }
    // if(direction == 'D') // 向下
    // {

    // }
}

// void move_space(char direction,  vector<vector<int>> &snake, vector<vector<char>> &map) // 方向处为空格
// {
    
//     snake.insert(snake.begin(), {snake[0][0]+row_offset, snake[0][1]+col_offset}); // 更新蛇头
//     // 更新地图
//     map[snake[0][0]][snake[0][1]] = 'H';
//     // for(int i = 0; i < snake.size()-1; i++) // 尾部
//     // {
//     //     map[snake[i][0]][snake[i][1]] = 'H';
//     // }
//     // 把最后一个格子设置为空
//     // 把尾部去掉，更新地图和蛇
//     map[snake[snake.size()-1][0]][snake[snake.size()-1][1]] = 'E'; // 地图设置蛇尾为空
//     snake.pop_back(); // 删去最后一节
// }


int main()
{
    vector<char> control; // 移动
    char ch; // 临时变量用于输入
    while((ch=cin.get()) != '\n')   // 输入第一行为空格分隔的字母，代表贪吃蛇的移动操作。
    {
        if(ch == ' ') continue;
        control.push_back(ch);
    }
    // for(auto i : control)
    // {
    //     cout << i << endl;
    // }
    int row,col; // 行和列
    cin >> row >> col; // 输入行和列
    vector<vector<char>> map(row, vector<char>(col)); // map地图
    vector<vector<int>> snake(1, vector<int>(2)); // 保存蛇的数据 snake[0]表示蛇头位置，snake[0][0]表示蛇的row坐标，snake[0][1]表示蛇头的col位置
    // 字母取值为H、F和E，H表示贪吃蛇的起始位置，F表示食物，E表示该方格为空。
    // 输入地图和蛇的数据
    for(int i = 0; i < row; i++)
    {
        for(int j = 0; j < col; j++)
        {
            cin >> ch;
            if(ch == 'H') // 存储蛇头   起始长度为1
            {
                snake[0][0] = i;
                snake[0][1] = j;
            }
            map[i][j] = ch;
        }
    }

    // for(auto i : map)
    // {
    //     for(auto j : i)
    //     {
    //         cout << j << " ";
    //     }
    //     cout << endl;
    // }
    // U、D、L、R：上下左右   G:前进一格
    // snake[0][0]表示蛇的row坐标，snake[0][1]表示蛇头的col位置
    char direction = 'L';
    for(int i = 0; i <control.size(); i++) // 遍历操作序列
    {
        if(control[i] != 'G') // 输入的是方向
        {
            direction = control[i]; // 变更方向
        }
        else// 移动
        {   
            if(!move(direction, snake, map))
            {
                break;
            }
        }
    }
    cout << snake.size();
    
    system("pause");
}