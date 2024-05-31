/*
贪心的商人
知识点贪心
时间限制：1s 空间限制：256MB 限定语言：不限
题目描述：
商人经营一家店铺，有number种商品，由于仓库限制每件商品的最大持有数量是item[index]，
每种商品的价格在每天是item_price[item_index][day]，通过对商品的买进和卖出获取利润，请给出商人在days天内能获取到的最大的利润；
注： 同一件商品可以反复买进和卖出；
输入描述：
3  // 输入商品的数量 number
3  // 输入商人售货天数 days
4 5 6  // 输入仓库限制每件商品的最大持有数量是item[index]
1 2 3   // 输入第一件商品每天的价格
4 3 2   // 输入第二件商品每天的价格
1 5 3   // 输入第三件商品每天的价格
输出描述：
32 // 输出商人在这段时间内的最大利润
补充说明：
根据输入的信息：
number = 3
days = 3
item[3] = {4，5，6}
item_price[3][4] = {{1，2，3}，{4，3，2}，{1，5，3}}
针对第一件商品，商人在第一天的价格是item_price[0][0] = 1时买入item[0]件，在第三天item_price[0][2] = 3的时候卖出，获利最大是8；
针对第二件商品，不进行交易，获利最大是0；
针对第三件商品，商人在第一天的价格是item_price[2][0] = 1时买入item[2]件，在第二天item_price[2][0] == 5的时候卖出，获利最大是24；
因此这段时间商人能获取的最大利润是8 + 24 = 32；
示例1\n输入：
3
3
4 5 6
1 2 3 
4 3 2
1 5 3
输出：
32
示例2
输入：
1
1
1
1
输出：\n0
*/


#include <bits/stdc++.h>
using namespace std;

// 
int main() {
    int number, days;
    cin >> number >> days; // 商品数 天数
    vector<int> item(number); // 商品的库存限制
    for(int i = 0; i < number; i++){
        cin >> item[i];
    }
    vector<vector<int> > item_price(number, vector<int>(days)); // [商品][该天数下的价格]
    for(int i = 0; i < number; i++){
        for(int j = 0; j < days; j++){
            cin >> item_price[i][j];
        }
    }
    // 解决：从左往右，找到最大的差
    vector<int> cost(number);
    for(int i = 0; i < number; i++){
        int temp = item_price[i][0]; // 设置变量为第i件商品，第一天的价格
        for(int j = 0; j < days; j++){
            if(temp < item_price[i][j]){ // 有钱赚
                cost[i] = cost[i] + item_price[i][j] - temp  ;
                temp = item_price[i][j];
            }
            else{ // 高价 —> 低价
                temp = item_price[i][j];
            }    
        }
    }

    for(auto i : cost) cout << i << endl;



    int sum = 0; // 总花费
    for(int i = 0; i < number; i++)
    {
        sum += cost[i] * item[i];
    }
    cout << sum;


    system("pause");
}