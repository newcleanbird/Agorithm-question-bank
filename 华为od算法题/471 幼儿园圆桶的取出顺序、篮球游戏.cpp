///*
//471、幼儿园圆桶的取出顺序、篮球游戏
//题目描述：
//幼儿园里有一个放倒的圆桶，它是一个 线性结构，允许在桶的右边将篮球放入，可以在桶的左边和右边将篮球取出。每个篮球有单独的编号，老师可以连续放入一个或多个篮球，小朋友可以在桶左边或右边将篮球取出，当桶只有一个篮球的情况下，必须从左边取出。
//如老师按顺序放入1、2、3、4、5共有5 个编号的篮球，那么小朋友可以依次取出编号为1、2、3、4、5或者 3、1、2.4、5 编号的篮球，无法取出 5、1、3、2、4 编号的篮球
//其中 3、1、2、4、5 的取出场景为:
//->连续放入1、2、3号
//->从右边取出3号
//->从左边取出1号
//->从左边取出2号
//->放入4号
//->从左边取出4号
//->放入5号
//->从左边取出5号
//简答起见，我们以 L 表示左，R表示右，此时取出篮球的依次取出序列为“RLLLL”。
//
//输入描述：
//每次输入包含一个 测试用例
//1.第一行的数字作为老师依次放入的篮球编号
//2.第二行的数字作为要检查是否能够按照放入的顺序取出给定的篮球的编号，其中篮球的编号用逗号进行分隔.
//其中篮球编号用逗号进行分隔。
//
//输出描述：
//对干每个篮球的取出席列，如果确实可以获取，请打印出其按照左右方向的操作取出顺序，如果无法获取则打印“NO”
//备注
//1＜篮球编号，篮球个数≤200
//篮球上的数字不重复
//输出的结果中 LR 必须为大写
//
//示例1：
//输入：
//4,5,6,7,0,1,2
//6,4,0,1,2,5,7
//
//输出：
//RLRRRLL
//说明：
//篮球的取出顺序依次为\"右、左、右、右、右、左、左\"
//
//示例2：
//输入：
//4,5,6,7,0,1,2
//6,0,5,1,2,4,7
//输出：
//NO
//
//示例3：
//输入：
//1,2,3,4
//1,2,3,5
//
//输出：
//NO
//
//感觉像模拟队列，判断输出次序是否能通过队列生成。
//*/
//#include<iostream>
//#include<vector>
//#include<queue>
//#include<deque>
//#include<sstream>
//
//using namespace std;
//
//int main()
//{
//	vector<int> input;
//	queue<int> output;
//	string str1;
//	string str2;
//	getline(cin, str1);
//	getline(cin, str2);
//	istringstream iss1(str1);
//	istringstream iss2(str2);
//	string token;
//	while (getline(iss1, token, ','))
//	{
//		input.push_back(stoi(token));
//	}
//	while (getline(iss2, token, ','))
//	{
//		output.push(stoi(token));
//	}
//	
//	// 开始计算
//	deque<int> dq;	// 双端队列，将input从队尾输入，从队首或队尾输出
//	vector<char> res;
//
//	for (int i = 0; i < input.size(); i++)
//	{
//		dq.push_back(input[i]);
//		while (output.front() == dq.front() || output.front() == dq.back())
//		{
//			if (output.front() == dq.front())
//			{
//				output.pop();
//				dq.pop_front();
//				res.push_back('L');
//			}
//			else if(output.front() == dq.back()){
//				output.pop();
//				dq.pop_back();
//				res.push_back('R');
//			}
//			if (dq.empty()) break;
//		}
//	}
//	if (res.size() == input.size())
//	{
//		for (int i = 0; i < res.size(); i++)
//		{
//			cout << res[i];
//		}
//	}
//	else {
//		cout << "NO" << endl;
//	}
//
//}