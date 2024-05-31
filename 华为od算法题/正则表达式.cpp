///*
//注意：
//1.C++中，正常书写正则表达式，所有需要有转移字符的地方都需要有两个
//2.可以使用R"(标准正则表达式)"s
//*/
//
//#include<iostream>
//#include<string>
//#include<regex>
//#include<vector>
//
//using namespace std;
//
//int main()
//{
//	//// 匹配
//	//string str = "-1-2-3-4+5*5+99";
//	//string str = "+1";
//	//regex r(R"(^[+\-]?(\d+[+\-*])+\d+$)")
//	//	;
//	//if (regex_match(str, r)) {
//	//	cout << "匹配成功";
//	//}
//	//else {
//	//	cout << "匹配失败";
//	//}
//
//	// 迭代器查找
//	std::string input = "I have 3 cats and 4 dogs.";
//	std::regex pattern("\\d+"); // 匹配一个或多个数字
//
//	// 使用sregex_iterator遍历匹配项
//	for (std::sregex_iterator it(input.begin(), input.end(), pattern); it != std::sregex_iterator(); ++it) {
//		std::cout << "Matched: " << it->str() << std::endl;
//	}
//}