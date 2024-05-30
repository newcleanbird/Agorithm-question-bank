/*
特异性双端队列
    特异性双端队列
    题目
    有一个特异性的双端队列，该队列可以从头部到尾部添加数据，但是只能从头部移除数据。
    小A一次执行 2n 个指令往队列中添加数据和移除数据，
    其中 n 个指令是添加数据(可能从头部也可以从尾部添加)
    依次添加 1 到 n , n 个指令是移出数据
    现在要求移除数据的顺序为 1 到 n ，
    为了满足最后输出的要求,
    小A可以在任何时候调整队列中的数据的顺序
    请问,小A最少需要调整几次才能满足移除数据的顺序正好是 1 到 n

    输入
    第一行一个整数 n ，表示数据范围
    接下来有 2n 行,其中有 n 行为添加数据:
    指令head add x表示从头部添加数据x
    tail add x表示从尾部添加数据x
    另外 n 行为移除数据指令,指令为remove形式,表示移除一个数据
    1≤n≤3×1 0 5 10^510 
    5
    

    输出描述
    一个整数，表示小A要调整的最小次数


*/


#include<bits/stdc++.h>

using namespace std;

int main()
{
    int n;
    cin >> n; // 指令的条数
    getchar();
    vector<string> s_arr; // 输入
    vector<int> num; // 存放队列
    string temp;
    string num_s; 
    int tmp; // 存放数据
    int index = 1; // 确定输入的整数
    int result = 0; // 记录一共需要变化多少次
    int num_1 = 1; // 记录输出的数字
    for(int i = 0; i < 2*n; i++) // 有n行为输入，有n行为输出，但是可能混合输入
    {
        num_s.clear();      // 重新声明
        getline(cin, temp); // 输入n行
        // cin >> temp;
        if(temp[0] == 'h') // 头部添加
        {
            // for(int j = temp.size()-1; temp[j]!=' '; j--) // 从最后开始遍历，遇到空格停止，插入到头部
            // {
            //     num_s.insert(num_s.begin(), temp[j]);
            // }
            // num.insert(num.begin(), stoi(num_s));
            num.insert(num.begin(), index);
            index++;
        }
        else if(temp[0] == 't') // 尾部添加
        {
            // for(int j = temp.size()-1; temp[j]!=' '; j--) // 从最后开始遍历，遇到空格停止，插入到头部
            // {
            //     num_s.insert(num_s.begin(), temp[j]);
            // }
            // num.push_back(stoi(num_s));
            num.push_back(index);
            index++;
        }
        else    // 开始输出，只能从头部输出，因此设置头部为“左边”
        {
            if(num.size() == 0)
            {
                continue;
            }                   
            else if(num.size() == 1) // 只有一个长度，不用变化，直接输出
            {
                num_1++;
                num.pop_back();// 出队
                continue;
            }
            else if(num[0] == num_1) // result +1 = 应该输出元素
            {
                num.erase(num.begin()); // 移出队首
                num_1++;
                continue;
            }
            else// 不能直接输出，需要调整
            { 
                for(int j = 0; j < num.size(); j++)
                {
                    sort(num.begin(),num.end());
                    result++;
                    num.erase(num.begin());// 移出队首
                    continue;
                    // if(num[j] == num_1){
                    //     swap(num[j], num[0]); // 交换两者
                    //     result++;
                    //     num.erase(num.begin());// 移出队首
                    //     continue;
                    // }
                }
            
            }
        }
    
    }
    cout << result;
    // system("pause");
}