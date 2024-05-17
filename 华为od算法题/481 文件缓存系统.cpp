///*
//481 文件缓存系统
//题目描述：
//请设计一个文件缓存系统，该文件缓存系统可以指定缓存的最大值（单位为字节）。
//文件缓存系统有两种操作：存储文件(put)和读取文件(get)
//操作命令为put fileName fileSize或者get fileName
//存储文件是把文件放入文件缓存系统中；读取文件是从文件缓存系统中访问已存在的文件，如果文件不存在，则不作任何操作。
//当缓存空间不足以存放新的文件时，根据规则删除文件，直到剩余空间满足新的文件大小为止，再存放新文件。
//具体的删除规则为：
//文件访问过后，会更新文件的最近访问时间和总的访问次数，当缓存不够时，按照第一优先顺序为访问次数从少到多，第二顺序为时间从老到新的方式来删除文件。
//
//输入描述：
//第一行为缓存最大值m(整数，取值范围为0 < m <= 52428800)；
//第二行为文件操作序列个数n(0 <= n <= 300000
//从第三行起为文件操作序列，每个序列单独一行
//文件操作定义为"op file_namefile_size"
//file_name是文件名，file_size是文件大小
//
//输出描述：
//输出当前文件缓存中的文件名列表，文件名用英文逗号分隔，按字典顺序排序
//如：
//a,c
//如果文件缓存中没有文件，则输出NONE
//补充说明：
//1.  如果新文件的文件名和文件缓存中已有的文件名相同，则不会放在缓存中
//2.  新的文件第一次存入到文件缓存中时，文件的总访问次数不会变化，文件的最近访问时间会更新到最新时间
//3.  每次文件访问后，总访问次数加1，最近访问时间更新到最新时间
//4.  任何两个文件的最近访问时间不会重复
//5.  文件名不会为空，均为小写字母，最大长度为10。
//6.  缓存空间不足时，不能存放新文件
//7.  每个文件大小都是大于0的整数
//
//示例1
//输入：
//50
//6
//put a 10
//put b 20
//get a
//get a
//get b
//put c 30
//输出：
//a,c
//说明：
//
//示例2
//输入：
//50
//1
//get file
//输出：
//NONE
//说明：
//*/
//
//#include <iostream>
//#include <vector>
//#include <string>
//#include <sstream>
//#include <unordered_map>
//#include <chrono>
//#include <algorithm>
//
//using namespace std;
//
//struct file
//{
//public:
//	string fileName;
//	int fileSize;
//	int accessCount;	// 访问次数
//	chrono::time_point<std::chrono::system_clock> lastAccessTime;	// 最近访问时间
//	// 默认构造函数
//	file()
//	{
//
//	}
//	// 构造函数
//	file(string name, int size, int count, chrono::time_point<std::chrono::system_clock> time) : fileName(name), fileSize(size), accessCount(count), lastAccessTime(time)
//	{
//
//	}
//	//// 拷贝构造函数
//	//file(const file& other) : fileName(other.fileName), fileSize(other.fileSize), accessCount(other.accessCount), lastAccessTime(other.lastAccessTime)
//	//{
//
//	//}
//	//// 拷贝运算符
//	//file& operator=(const file& other)
//	//{
//	//	// 防止自我赋值
//	//	if (this != &other) {
//	//		// 深拷贝（或逻辑上的深拷贝，这里假设成员都是可以浅拷贝的）
//	//		fileName = other.fileName;
//	//		fileSize = other.fileSize;
//	//		accessCount = other.accessCount;
//	//		lastAccessTime = other.lastAccessTime;
//	//	}
//	//	return *this; // 返回当前对象的引用，允许链式赋值如 a = b = c;
//	//}
//};
//class compare {
//public:
//	bool operator()(const pair<string, file >& a, const pair<string, file >& b) const
//	{
//		if (a.second.accessCount != b.second.accessCount)
//			return a.second.accessCount > b.second.accessCount;	// 按访问次数排序
//		return b.second.lastAccessTime > b.second.lastAccessTime;     // 按更新时间排序
//	}
//};
//
//class FileCacheSystem
//{
//private:
//	int maxSize;
//	int currentSize = 0;
//	unordered_map<string, file> files;
//
//
//public:
//	FileCacheSystem(int max_file) : maxSize(max_file)
//	{
//
//	}
//
//	void put(string name, int size)
//	{
//		if (files.find(name) != files.end())	// 如果文件已经加入缓存，则跳过
//		{
//			return;
//		}
//
//		if (size > maxSize) return;	// 存储的文件大小超过总缓存,删除其他文件也没有用
//		if(size + currentSize > maxSize)
//		{
//			int nowSize = size + currentSize;
//			evict(nowSize);	// 删除文件直到满足当前所需的缓存大小
//		}
//		// 增加文件
//		std::chrono::time_point<std::chrono::system_clock> current_time  = chrono::system_clock::now();
//		file newfile(name, size, 0, current_time);
//		files.insert({ name, newfile });
//		currentSize += size;
//		//files[name] = newfile;
//	}
//
//	void get(string name)
//	{
//		if (files.find(name) != files.end()) {
//			files[name].accessCount++;
//			files[name].lastAccessTime = chrono::system_clock::now();
//		}
//	}
//
//	void evict(int nowSize)
//	{
//		vector<pair<string, file>> sorted_files(files.begin(), files.end());
//		sort(sorted_files.begin(), sorted_files.end(), compare());
//		size_t pos = sorted_files.size() - 1;
//		while (nowSize > maxSize)
//		{
//			nowSize -= sorted_files[pos].second.fileSize;
//			files.erase(sorted_files[pos].first);
//			pos--;
//		}
//	}
//
//	string listFiles() {
//		if (files.empty()) return "NONE";
//		vector<string> sorted_files;
//		for (auto& [name, _] : files) sorted_files.push_back(name);
//		sort(sorted_files.begin(), sorted_files.end(), less<string>());
//		string result;
//		for (int i = 0; i < sorted_files.size(); i++)
//		{
//			result += sorted_files[i];
//			if (i != sorted_files.size() - 1) result += ',';
//		}
//		return result;
//	}
//
//};
//
//int main()
//{
//	// 输入
//	int m;	// 缓存最大值m
//	cin >> m;
//	int n;
//	cin >> n; // 文件操作序列个数n
//	cin.get(); // 处理掉换行符
//	vector<string> orders(n);
//	string str;
//	for (int i = 0; i < n; i++)
//	{
//		getline(cin, orders[i]);
//	}
//
//	// 解析命令
//	FileCacheSystem fc(m);
//
//	for (auto& i : orders)
//	{
//		istringstream  iss(i);
//		string token;
//		vector<string> order;
//		while (getline(iss, token, ' '))
//		{
//			order.push_back(token);
//		}
//		if (order[0] == "put")
//		{
//			fc.put(order[1], stoi(order[2]));
//		}
//		else if (order[0] == "get")
//		{
//			fc.get(order[1]);
//		}
//	}
//	string res = fc.listFiles();
//	cout << res;
//
//}