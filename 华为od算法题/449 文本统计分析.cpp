/*
449 文本统计分析
题目描述：
有一个文件, 包含以一定规则写作的文本, 请统计文件中包含的文本数量
规则如下
1. 文本以";"分隔，最后一条可以没有";"，但空文本不能算语句，比如"COMMAND A; ;"只能算一条语句.
  注意, 无字符/空白字符/制表符都算作"空"文本
2. 文本可以跨行, 比如下面, 是一条文本, 而不是三条
   COMMAND A
      AND
   COMMAND B;
3. 文本支持字符串, 字符串为成对的单引号(')或者成对的双引号("), 字符串可能出现用转义字符(\)处理的单双引号(比如"your input is: \"")和转义字符本身, 比如 COMMAND A "Say \"hello\"";
4. 支持注释, 可以出现在字符串之外的任意位置, 注释以"--"开头, 到换行结束, 比如
   COMMAND A; -- this is comment
  COMMAND -- comment
      A AND COMMAND B;
  注意, 字符串内的"--", 不是注释

输入描述：文本文件
输出描述：包含的文本数量

示例
示例1
输入：
COMMAND TABLE IF EXISTS "UNITED STATE";
COMMAND A GREAT (
ID ADSAB,
download_length INTE-GER, -- test
file_name TEXT,
guid TEXT,
mime_type TEXT
notifica-tionid INTEGER,
original_file_name TEXT,
pause_reason_type INTEGER,
resumable_flag INTEGER,
start_time INTEGER,
state INTEGER,
folder TEXT,
path TEXT,
total_length INTE-GER,
url TEXT
);

输出：2

*/
#include <iostream>
#include <fstream>
#include <string>

#include <regex>
#include <vector>
#include <sstream>

// 解法一：自写逻辑
int count_texts(const std::string& file_path) {
   std::ifstream file(file_path);
   if (!file.is_open()) {
       std::cerr << "Unable to open file!" << std::endl;
       return -1;
   }

   std::string content((std::istreambuf_iterator<char>(file)), std::istreambuf_iterator<char>());
   file.close();

   int count = 0;
   size_t i = 0;
   while (i < content.size()) {
       if (content[i] == '-' && i + 1 < content.size() && content[i + 1] == '-') {
           while (i < content.size() && content[i] != '\n') {
               i += 1;
           }
       }
       else if (content[i] == '\'' || content[i] == '\"') {
           char quote = content[i];
           i += 1;
           while (i < content.size() && (content[i] != quote || content[i - 1] == '\\')) {
               i += 1;
           }
           i += 1;
       }
       else if (content[i] == ';') {
           count += 1;
           i += 1;
       }
       else {
           i += 1;
       }
   }

   return count;
}

// 逻辑二：正则表达式
std::string remove_comments(const std::string& content) {
   // std::regex comment_regex("--.*?$", std::regex::multiline);// 有错误
   std::regex comment_regex("--.*?$");
   return std::regex_replace(content, comment_regex, "");
}

int count_statements(const std::string& file_path) {
   std::ifstream file(file_path);
   if (!file.is_open()) {
       return -1;
   }
   std::stringstream buffer;
   buffer << file.rdbuf();
   std::string content = buffer.str();
   file.close();

   std::string no_comments = remove_comments(content);
   std::istringstream iss(no_comments);
   std::string token;
   int count = 0;
   while (std::getline(iss, token, ';')) {
       if (!token.empty() && token[0] != ' ') {
           count++;
       }
   }
   return count;
}

int main() {
   std::string file_path = "input.txt";
   //int result = count_texts(file_path);// 解法一
   int result = count_statements("input.txt");// 解法二
   std::cout << result << std::endl;
   // std::cout << count_statements("input.txt") << std::endl;
   system("pause");
   return 0;
}
