///*
//题目描述：
//给定长度为n的无序的数字数组，每个数字代表二叉树的叶子节点的权值，数字数组的值均大于等于1。请完成一个函数，根据输入的数字数组，生成哈夫曼树，并将哈夫曼树按照中序遍历输出。
//为了保证输出的二叉树中序遍历结果统一，增加以下限制：二叉树节点中，左节点权值小于等于右节点权值，根节点权值为左右节点权值之和。当左右节点权值相同时，左子树高度高度小于等于右子树。
//注意：所有用例保证有效，并能生成哈夫曼树。
//
//提醒：哈夫曼树又称最优二叉树，是一种带权路径长度最短的二叉树。所谓树的带权路径长度，就是树中所有的叶结点的权值乘上其到根结点的路径长度（若根结点为0层，叶结点到根结点的路径长度为叶结点的层数）。
//例如：
//由叶子节点5 15 40 30 10生成的最优二叉树如下图所示，该树的最短带权路径长度为40*1+30*2+15*3+5*4+10*4=205。
//
//输入描述：
//第一行输入为数组长度，记为N，1<=N<=1000，第二行输入无序数值数组，以空格分割，数值均大于等于1，小于100000
//
//输出描述：
//输出一个哈夫曼树的中序遍历的数组，数值间以空格分割
//
//补充说明：
//示例1
//输入：
//5
//5 15 40 30 10
//输出：
//40 100 30 60 15 30 5 15 10
//说明：
//根据输入，生成哈夫曼树，按照中序遍历返回。所有节点中，左节点权值小于等于右节点权值，根节点权值为左右节点权值之和。当左右节点权值相同时，左子树高度高度小于等于右子树。结果
//*/
//
//#include<iostream>
//#include<vector>
//#include<queue>
//#include<algorithm>
//
//using namespace std;
//
//struct Node
//{
//	// int data;	// data
//	int freq;	// 节点的频率
//	Node* left;	// 左子树
//	Node* right;// 右子树
//
//	Node(int freq) : freq(freq), left(nullptr), right(nullptr)
//	{
//
//	}
//	Node(int freq, Node* left, Node* right) : freq(freq), left(left), right(right)
//	{
//
//	}
//};
//
//int getHeight(Node* root) {
//	if (root == NULL) {
//		return 0;
//	}
//	int leftHeight = getHeight(root->left);
//	int rightHeight = getHeight(root->right);
//	return max(leftHeight, rightHeight) + 1;
//}
//
//struct Compare {
//	bool operator()(Node* l, Node* r) {
//		if (l->freq == r->freq)
//		{
//			return getHeight(l) > getHeight(r);
//		}
//		else {
//			return l->freq > r->freq;
//		}
//	}
//};
//
//class HuffmanTree
//{
//private:
//	Node* root;
//	priority_queue<Node*, vector<Node*>, Compare> q;
//	void buildTree()
//	{
//		while (q.size() != 1)
//		{
//			Node* left = q.top(); q.pop();
//			Node* right = q.top(); q.pop();
//			Node* cur = new Node(left->freq + right->freq, left, right);
//			q.push(cur);
//		}
//		root = q.top();
//	}
//	int treeHeight()
//	{
//
//	}
//	void inOrderTraversal(Node* cur)
//	{
//		if (cur == nullptr) return;
//		inOrderTraversal(cur->left);
//		cout << cur->freq << " ";
//		inOrderTraversal(cur->right);
//	}
//
//public:
//	HuffmanTree(vector<int>& freqs)
//	{
//		for (auto i : freqs)
//		{
//			q.push(new Node(i));
//		}
//		buildTree();
//	}
//	void getInOrderTraversal()
//	{
//		inOrderTraversal(root);
//	}
//};
//
//int main()
//{
//	int n;
//	cin >> n;
//	vector<int> freqs(n);
//	for (int i = 0; i < n; i++)
//	{
//		cin >> freqs[i];
//	}
//	HuffmanTree ht(freqs);
//	ht.getInOrderTraversal();
//
//}