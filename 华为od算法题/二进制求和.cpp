//#include<iostream>
//#include<string>
//
//using namespace std;
//
//class Solution {
//public:
//    string addBinary(string a, string b) {
//        // 补齐al 和 bl 为同长
//        int al = a.size();
//        int bl = b.size();
//        while (al < bl)
//        {
//            a = '0' + a;
//            ++al;
//        }
//        while (al > bl)
//        {
//            b = '0' + b;
//            ++bl;
//        }
//
//        int add = 0;
//        for (int i = a.size() - 1; i >= 0; i--)
//        {
//            //a[i] = a[i] - '0' + b[i] + add;
//            char tmp = a[i] - '0' + b[i] + add;
//            add = 0;
//            if (tmp == '3')
//            {
//                a[i] = '1';
//                add = 1;
//            }
//            else if (tmp == '2')
//            {
//                a[i] = '0';
//                add = 1;
//            }
//            else {
//                a[i] = tmp;
//            }
//        }
//        if (add == 1)
//        {
//            a = '1' + a;
//        }
//        return a;
//    }
//};
//
//int main()
//{
//    string str1 = "1010";
//    string str2 = "1011";
//
//    Solution s1;
//    cout << s1.addBinary(str1, str2);
//}