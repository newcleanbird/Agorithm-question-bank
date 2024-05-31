/*
https://blog.csdn.net/qq_34465338/article/details/125884929?ops_request_misc=%257B%2522request%255Fid%2522%253A%2522167957922616800182130274%2522%252C%2522scm%2522%253A%252220140713.130102334.pc%255Fall.%2522%257D&request_id=167957922616800182130274&biz_id=0&utm_medium=distribute.pc_search_result.none-task-blog-2~all~first_rank_ecpm_v1~rank_v31_ecpm-1-125884929-null-null.142^v76^control_1,201^v4^add_ask,239^v2^insert_chatgpt&utm_term=%E6%95%B0%E7%BB%84%E4%BA%8C%E5%8F%89%E6%A0%91%20%E5%8D%8E%E4%B8%BAod&spm=1018.2226.3001.4187
标题：数组二叉树 | 时间限制：1秒 | 内存限制：262144K | 语言限制：不限
二叉树也可以用数组来存储，给定一个数组，树的根节点的值存储在下标1，对于存储在下标N的节点，它的左子节点和右子节点分别存储在下标2*N和2*N+1，并且我们用值-1代表一个节点为空。
给定一个数组存储的二叉树，试求从根节点到最小的叶子节点的路径，路径由节点的值组成。

输入描述:

输入一行为数组的内容，数组的每个元素都是正整数或表示节点为空的-1，元素间用空格分隔。
注意第一个元素即为根节点的值，即数组的第N个元素对应下标N，下标0在树的表示中没有使用，所以我们省略了。输入的树最多为7层。

输出描述:

输出从根节点到最小叶子节点的路径上，各个节点的值，由空格分隔，用例保证最小叶子节点只有一个。

示例1
输入

3 5 7 -1 -1 2 4

输出

3 7 2

说明

数组存储的二叉树如图，故到最小叶子节点的路径为3 7 2

示例2
输入

5 9 8 -1 -1 7 -1 -1 -1 -1 -1 6

输出

5 8 7 6

说明

数组存储的二叉树如图，故到最小叶子节点的路径为10 8 7 6，注意数组仅存储至最后一个非空节点，故不包含节点“7”右子节点的-1


*/

#include<bits/stdc++.h>

using namespace std;

// void traver(vector<int> tree, int cur, vector<int>& path) // 树，当前访问的下标，
// {
//     if(!(cur <= tree.size() && tree[cur] != -1))   // 访问没越界，当前也有值
//     {
//         return;
//     }
//     else{
//         path.push_back(tree[cur]); // 将当前节点加入到path中
//         if(tree[cur] == target);
//         traver(tree, cur*2, path);   // 左
//         traver(tree, cur*2+1, path);   // 右
//     }
    
// }

int main()
{
    // 输入
    vector<int> tree(1);   // 存储树 树从1开始(1为根)
    int tmp;
    int min = INT_MAX;     // 最小的叶子节点下标
    int index = 1;         // 下标从1开始
    while (cin>>tmp)
    {
        if(tmp < min)
        {
            min = index;
        }
        index++;
        tree.push_back(tmp);
        if (getchar() == '\n')
        {
            break;
        }
    }
    vector<int> result;
    // index_min 为下标
    while(min > 0){
        result.push_back(tree[min]);
        min /=2;
    }
    for(int i = result.size() - 1; i >=0; i--)
    {
        cout << result[i] << " ";
    }
    system("pause");
    
}