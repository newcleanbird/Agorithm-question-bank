/*
413 计算三叉搜索树的高度
题目描述：
定义构造三叉搜索树规则如下：
每个节点都存有一个数，当插入一个新的数时，从根节点向下寻找，直到找到一个合适的空节点插入。
   查找的规则是：
       1. 如果数小于节点的数减去500，则将数插入节点的左子树
       2. 如果数大于节点的数加上500，则将数插入节点的右子树
       3. 否则，将数插入节点的中子树
给你一系列数，请按以上规则，按顺序将数插入树中，构建出一棵三叉搜索树，最后输出树的高度。

输入描述：第一行为一个数N，表示有N个数，1<=N<=10000
第二行为N个空格分隔的整数，每个数的范围为[1,10000]

输出描述：输出树的高度(根节点的高度为1)

补充说明：

示例1
输入：
5
5000 2000 5000 8000 1800
输出：
3
说明：
最终构造出的树如下，高度为3：

示例2
输入：
3
5000 4000 3000
输出：
3
说明：
最终构造出的树如下，高度为3：

示例2
输入：
6
500 1500 2500 3500 4500 5500

*/
#include<iostream>
#include<vector>
#include<queue>

using namespace std;

struct Node
{
   int val = 0;
   Node* a = nullptr;
   Node* b = nullptr;
   Node* c = nullptr;

public:
   Node(int n)
   {
       val = n;
   }
};

class TernarySearchTree
{
public:
   Node* head = nullptr;
};

TernarySearchTree tree;

int res = 0;

void insertNode(int n)
{
   int height = 1;
   Node* next = tree.head;
   Node* cur;
   if (next == nullptr)
   {
       tree.head = new Node(n);
   }
   else {
       while (1)
       {
           cur = next;
           if (n < cur->val - 500)
           {
               next = next->a;
               height++;
               if (next == nullptr)
               {
                   cur->a = new Node(n);
                   break;
               }
           }
           else if (n > cur->val + 500)
           {
               next = next->c;
               height++;
               if (next == nullptr)
               {
                   cur->c = new Node(n);
                   break;
               }
           }
           else {
               next = next->b;
               height++;
               if (next == nullptr)
               {
                   cur->b = new Node(n);
                   break;
               }
           }
       }
   }
   res = max(res, height);
}

void print()
{
   Node* cur = tree.head;
   queue<Node*> q;
   if (cur != nullptr)
   {
       q.push(cur);
   }
   while (!q.empty())
   {
       cur = q.front(); q.pop();
       cout << cur->val << " ";
       if (cur->a != nullptr)
       {
           q.push(cur->a);
       }
       if (cur->b != nullptr)
       {
           q.push(cur->b);
       }
       if (cur->c != nullptr)
       {
           q.push(cur->c);
       }
   }
}

int main()
{
   int num;
   cin >> num;
   vector<int> nums(num);
   for (int i = 0; i < num; i++)
   {
       cin >> nums[i];
   }
   // 插入
   for (auto i : nums)
   {
       insertNode(i);
       print();
       cout << endl;
   }
   cout << res;
}