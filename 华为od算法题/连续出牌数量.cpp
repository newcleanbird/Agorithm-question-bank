/*
题目描述
有这么一款单人卡牌游戏，牌面由颜色和数字组成，颜色为红、黄、蓝、绿中的一种，数字为0-9中的一个。
游戏开始时玩家从手牌中选取一张卡牌打出，接下来如果玩家手中有和他上一次打出的手牌颜色或者数字相同的手牌，
他可以继续将该手牌打出，直至手牌打光或者没有符合条件可以继续打出的手牌。

现给定一副手牌，请找到最优的出牌策略，使打出的手牌最多。

输入描述

输入为两行，第一行是每张手牌的数字，数字由空格分隔，第二张为对应的每张手牌的颜色，用r y b g这4个字母分别代表4种颜色，字母也由空格分隔。手牌数量不超过10。

输出描述

输出一个数字，即最多能打出的手牌的数量。

示例1
输入
1 4 3 4 5
r y b b r
输出
3

示例2
输入
1 4 3 4 5 3
r y b b r g
输出
4

*/
/*
思考：
    如果颜色和数字一样，就可以继续出。
    回溯：有序搜索
    深度优先搜索：
*/

#include<bits/stdc++.h>

using namespace std;

struct card
{
    int num;
    char color;
};

vector<card> result; // 结果数组
vector<card> path;
static int max_1 = 0; // 存放最大的出牌数

void backtracking(vector<card> cards, int sum, int index, vector<bool> used) // 牌集合，已经打出的牌数，上一张打出的牌的序号，搜索序列
{   
    // // 找到非法点，返回
    // if((!path.empty()) && cards[startindex].color != path.top().color && cards[startindex].num != path.top().num)    // 确定返回条件->如果当前牌颜色和数字都和上一个不同，则返回
    // {
    //     return;
    // }
    if(path.size() == cards.size())// 如果全部搜搜完了，返回
    {
        // cout << "max:" << max_1;
        return; 
    } 
    
    
    // 本轮的搜索
    for(int i = 0; i < cards.size(); i++) // 从0开始遍历所有的卡片
    {
        // 对该节点进行操作：
        if(used[i] == true) continue;   // 如果当前卡已经被使用，则返回
        if((!path.empty()) && (cards[i].color != cards[index].color) && (cards[i].num != cards[index].num))    // 确定返回条件->如果当前牌颜色和数字都和上一个不同，则返回
        {
            continue;
        }
        // 满足要求
        path.push_back(cards[i]); // 将当前牌纳入搜索序列
        sum++;
        used[i] = true; // 设置当前
        // cout << sum << endl;
        if(sum > max_1)
        {
            max_1 = sum;
        }
        backtracking(cards, sum, i, used); // 路径选择列表
        // 回溯
        sum--;
        used[i] = false;
        path.pop_back();
    }
}

int main(){
    vector<card> cards;
    // 输入
    char tmp;
    int i = 0;
    while(1)
    {
        cin.get(tmp);
        if(tmp == ' ') continue;
        if(tmp == '\n')
        {
            break;
        }
        cards.push_back({tmp - '0'});
        i++;
    }
    i = 0;
    while(1)
    {
        cin.get(tmp);
        if(tmp == ' ') continue;
        if(tmp == '\n')
        {
            break;
        }
        cards[i].color = tmp;
        i++;
    }
    // for(auto i : cards)
    // {
    //     cout << i.num << " " << i.color << endl;
    // }
    // 开始找   回溯
    vector<bool> used(cards.size()); // 记录是否被使用  默认全部为false 如果使用过，则取1(true)
    backtracking(cards, 0, 0, used);
    cout << max_1 << endl;
    system("pause");
}