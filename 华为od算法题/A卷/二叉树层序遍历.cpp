/*
https://blog.csdn.net/qq_39132095/article/details/129532585?ops_request_misc=&request_id=&biz_id=102&utm_term=%E4%BA%8C%E5%8F%89%E6%A0%91%E5%B1%82%E5%BA%8F%E9%81%8D%E5%8E%86%20%E5%8D%8E%E4%B8%BAod&utm_medium=distribute.pc_search_result.none-task-blog-2~all~sobaiduweb~default-1-129532585.142^v76^control_1,201^v4^add_ask,239^v2^insert_chatgpt&spm=1018.2226.3001.4187

二叉树层次遍历
题目
有一棵二叉树
每一个节点用一个大写字母标识
最多26个节点
现有两组字母
分别表示后序遍历（左孩子指向右孩子指向父节点）左 右 中
和中序遍历（左孩子指向父节点指向右孩子）左 中 右
请输出层次遍历的结果

输入
输入为两个字符串
分别为二叉树的后序遍历和中序遍历结果

输出
输出二叉树的层次遍历结果

示例一
输入
CBEFDA CBAEDF

输出
ABDCEF

示例二(自编)
输入
HIDJKEBLMFNOGCA
HDIBJEKALFMCNGO

例子：
先序：ABDHIEJKCFLMGNO
中序：HDIBJEKALFMCNGO
后序：HIDJKEBLMFNOGCA
层序：ABCDEFGHIJKLMNO

*/

/*
思路：
    后序:左 右 中   HIDJKEB LMFNOGC A
    中序:左 中 右   HDIBJEK A LFMCNGO
    前序:中 左 右   ABDHIEJKCFLMGNO
    层序：每一层从左向右：ABCDEFGHIJKLMNO


*/

/*
整体思路：
    1.通过后序和中序构建完整二叉树
    {
        1.通过后序序列找到根节点：后序的最后一个是根节点    A
        2.遍历中序序列找到根节点 root_index                           A
        3.使用根节点将中序序列切割为左子树序列和右子树序列(右子树序列首位即为分割点)  HDIBJEK  LFMCNGO  23其实就是找分割点，即根节点的右边第一个元素s_inorder[root_index+1], l:[0, index-1] r:[index+1, s_inorder.size()-1] 
        4.使用刚得到的左子树序列和右子树序列(右子树首位)去切割后序序列，得到后序序列中的左子树序列和右子树序列  HIDJKEB LMFNOGC
        5.对得到的四个新序列即左子树的后序遍历和中序遍历、右子树的后序遍历和中序遍历，再进一步进行递归遍历。

    }
    2.通过层序遍历，找到遍历路径


*/
#include <bits/stdc++.h>

using namespace std;

//CBEFDA CBAEDF
void traversal(string s_post, string s_inorder, string & s_sequence) // 找到根节点 // 后序遍历，先序遍历
{
    // cout << s_post.size() << " " << s_inorder.size() << endl;
    if(s_post.size() == 0) // 如果后序遍历是最后一个元素，则没有节点可搜索
    {
        cout << "final s_seq:" << s_sequence << endl;
        return;
    }
    // 后序遍历最后一个值即为当前树的根节点
    char root = s_post[s_post.size() - 1]; // 根节点
    cout << "root:" << root << endl;
    s_sequence.push_back(root);            // 将根节点加入到层序遍历结果中
    int root_index;                        // root_index->根节点在中序遍历中的下标
    // 在中序序列中找到根节点的下标
    for(int i = 0; i < s_inorder.size(); i++)
    {
        if(s_inorder[i] == root)
        {
            root_index = i;
            break;
        }
    }
    // cout << "root_index:" << root_index << endl; // root_index：中序序列中找到的根节点的下标   
    // 分割中序遍历的左子树和右子树
    string s_inorder_left = s_inorder.substr(0, root_index); // 中序遍历的左子树(中序遍历)  左子树：[0,根节点-1]    根节点的下标，刚好即为根节点前的长度
    string s_inorder_right = s_inorder.substr(root_index+1); // 中序遍历的右子树(中序遍历)  右子树[根节点+1,结尾]
    // 分割后的左右子树，可能有其一不存在。中序的右子树可能为空，此时找不到
    // 使用左子树的长度来切割，不能使用具体的元素，因为可能存在越界，因此会报错。
    
    
    string s_post_left = s_post.substr(0, s_inorder_left.size()); // 后序遍历的左子树(后序遍历序列)
    string s_post_right = s_post.substr(s_inorder_left.size(), s_inorder_right.size());   // 后序遍历的右子树(后序遍历序列)

    // cout << "s_inorder_left.size():" << s_inorder_left.size() << " " << "s_inorder_left:" << s_inorder_left << endl;
    // cout << "s_post_left.size():" << s_post_left.size() << " " <<"s_post_left:" << s_post_left << endl;
    // cout << "s_inorder_right.size():" << s_inorder_right.size() << " " <<"s_inorder_right:" << s_inorder_right << endl;
    // cout << "s_post_right.size():" << s_post_right.size() << " " <<"s_post_right:" << s_post_right << endl;
    traversal(s_post_left, s_inorder_left, s_sequence);     // 先遍历左子树
    traversal(s_post_right, s_inorder_right, s_sequence);   // 再遍历右子树
    return;
}

int main()
{
    string s_post, s_inorder,s_sequence; // 后序，中序，层序
    cin >> s_post >> s_inorder;
    s_sequence.clear();
    // cout << s_sequence;
    traversal(s_post, s_inorder, s_sequence);
    cout << s_sequence;
    system("pause");
}