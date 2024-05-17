///*
//题目描述：
//橱窗里有一排宝石，不同的宝石对应不同的价格，宝石的价格标记为gems[i],0<=i<n, n = gems.length宝石可同时出售0个或多个，如果同时出售多个，则要求出售的宝石编号连续；例如客户最大购买宝石个数为m，购买的宝石编号必须为gems[i],gems[i+1]...gems[i+m-1](0<=i<n,m<=n)假设你当前拥有总面值为value的钱，请问最多能购买到多少个宝石,如无法购买宝石，则返回0.
//
//输入描述：第一行输入n，参数类型为int，取值范围：[0,10 ]，表示橱窗中宝石的总数量。
//之后n行分别表示从第0个到第n-1个宝石的价格，即gems[0]到gems[n-1]的价格，类型为int，取值范围：(0,1000]。
//之后一行输入v，类型为int，取值范围：[0,10 ]表示你拥有的钱。
//输出描述：输出int类型的返回值，表示最大可购买的宝石数量。
//
//示例
//示例1
//输入：
//7
//8
//4
//6
//3
//1
//6
//7
//10
//输出：3
//说明：
//       gems = [8,4,6,3,1,6,7], value = 10
//       最多购买的宝石为gems[2]至gems[4]或者gems[3]至gems[5]
//
//示例2
//输入：
//0
//1
//输出：0
//说明：
//gems = [], value = 1
//因为没有宝石，所以返回0
//
//示例3
//输入：
//9
//6
//1
//3
//1
//8
//9
//3
//2
//4
//15
//输出：4
//说明：gems = [6, 1, 3, 1, 8, 9, 3, 2, 4], value = 15
//最多购买的宝石为gems[0]至gems[3]
//
//示例4
//输入：
//9
//1
//1
//1
//1
//1
//1
//1
//1
//1
//10
//输出：
//9
//说明：
//gems = [1, 1, 1, 1, 1, 1, 1, 1, 1], value = 10
//最多购买的宝石为gems[0]至gems[8]，即全部购买
//
//// 寻找数组中，和最小的最长连续子数组
//*/
//#include<iostream>
//#include<vector>
//#include<algorithm>
//
//using namespace std;
//
//int main()
//{
//    int num;
//    cin >> num;
//    int tmp;
//    vector<int> vec;
//    while (num--)
//    {
//        cin >> tmp;
//        vec.push_back(tmp);
//    }
//    int money = 0;
//    cin >> money;
//    // 寻找和最小的最长连续子数组
//    int count = 0;
//    int sum = 0;
//    int max = 0;
//    for (int i = 0; i < vec.size(); i++)
//    {
//        count = 0;
//        sum = 0;
//        for (int j = i; j < vec.size(); j++)
//        {
//            if (sum + vec[j] <= money)
//            {
//                count++;
//                sum += vec[j];
//            }
//            else {
//                max = max > count ? max : count;
//                break;
//            }
//        }
//        max = max > count ? max : count;
//    }
//    cout << max;
//}
//
