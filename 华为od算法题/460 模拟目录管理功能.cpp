/*
460、模拟目录管理功能
题目描述：
实现一个模拟目录管理功能的软件，输入一个命令序列，输出最后一条命令运行结果。
支持命令：
1）创建目录命令：mkdir 目录名称，如mkdir abc为在当前目录创建abc目录，如果已存在同名目录则不执行任何操作。此命令无输出。
2）进入目录命令：cd 目录名称, 如cd abc为进入abc目录，特别地，cd ..为返回上级目录，如果目录不存在则不执行任何操作。此命令无输出。
3）查看当前所在路径命令：pwd，输出当前路径字符串。

约束：
 1）目录名称仅支持小写字母；mkdir和cd命令的参数仅支持单个目录，如：mkdir abc和cd abc；不支持嵌套路径和绝对路径，如mkdir abc/efg, cd abc/efg, mkdir /abc/efg, cd /abc/efg是不支持的。
 2）目录符号为/，根目录/作为初始目录。
 3）任何不符合上述定义的无效命令不做任何处理并且无输出。

输入描述：

输入N行字符串，每一行字符串是一条命令。

输出描述：

输出最后一条命令运行结果字符串。

补充说明：

命令行数限制100行以内，目录名称限制10个字符以内。

示例1
输入：
mkdir abc
cd abc
pwd
输出：
abc/
说明：
在根目录创建一个abc的目录并进入abc目录中查看当前目录路径，输出当前路径/abc/。

示例2
输入
mkdir a
mkdir b
cd b
mkdir b1
mkdir b2
pwd  
cd ..
cd a
mkdir a1
cd a1
pwd

解题思路：
1. 设计目录结构
首先需要设计一个用于存储目录结构的数据模型。常见方法是使用一个树状结构，其中每个节点代表一个目录。节点可以有多个子节点，代表其下的子目录。每个节点还应存储一些基本信息，如目录名。
- 节点属性：目录名、指向子节点的引用（列表或哈希表）。

2. 初始化根目录
- 初始化一个根节点作为目录树的起点。这个节点代表文件系统的根目录，标记为 /。

3. 解析命令
- 需要一个循环或逻辑来读取并解析用户的命令输入。命令可以分为三种类型：mkdir、cd、pwd。
- 对于每种命令类型，解析出命令后的参数（如果有的话）。

4. 实现 mkdir 命令
- 查找当前目录：确定当前工作目录。
- 检查目录是否存在：在当前目录的子目录列表中查找是否已存在该目录。
- 创建目录：如果不存在，则在当前目录下创建一个新的子目录节点。

5. 实现 cd 命令
- 解析目录参数：如果是 ..，则需要移动到父目录，但不能超过根目录。
- 更改目录：如果是具体的目录名，检查该目录是否存在于当前目录的子目录中。如果存在，更新当前目录为该子目录。

6. 实现 pwd 命令
- 输出当前路径：从根目录开始，遍历到当前目录的路径。可以通过从当前节点向上遍历至根节点来构建完整的路径字符串。
*/

#include <iostream>
#include <unordered_map>
#include <string>
#include <vector>
#include <sstream>
using namespace std;

class FileSystem {
private:
    struct Directory {
        unordered_map<string, Directory*> children;  // 存储目录的子目录
    };

    Directory* root;   // 根目录指针
    Directory* current;  // 当前目录指针
    string currentPath;  // 当前目录的路径字符串

public:
    FileSystem() {
        root = new Directory();
        current = root;
        currentPath = "/";  // 初始化时设为根目录
    }

    // 创建目录的函数
    void mkdir(const string& name) {
        // 检查当前目录下是否存在同名目录
        if (current->children.find(name) == current->children.end()) {
            current->children[name] = new Directory();  // 不存在则创建新目录
        }
    }

    // 改变当前目录的函数
    void cd(const string& path) {
        if (path == "..") {
            // 如果是返回上一级目录
            if (current != root) { // 确保不是根目录
                size_t pos = currentPath.rfind('/', currentPath.length() - 2);
                currentPath = currentPath.substr(0, pos + 1);
                // 从根目录重新遍历到上一级目录
                current = root; // 重设为根目录
                vector<string> dirs = split(currentPath, '/');
                for (const string& dir : dirs) {
                    if (!dir.empty() && current->children.find(dir) != current->children.end()) {
                        current = current->children[dir];
                    }
                }
            }
        }
        else {
            // 如果是进入一个子目录
            if (current->children.find(path) != current->children.end()) {
                current = current->children[path];
                currentPath += path + "/";
            }
        }
    }

    // 获取当前目录路径的函数
    string pwd() {
        return currentPath;
    }

private:
    // 辅助函数，用于分割字符串
    vector<string> split(const string& s, char delimiter) {
        vector<string> tokens;
        string token;
        istringstream tokenStream(s);
        while (getline(tokenStream, token, delimiter)) {
            tokens.push_back(token);
        }
        return tokens;
    }
};

int main() {
    FileSystem fs;
    string line;
    string lastOutput = "";  // 用于存储最后一次的pwd输出

    while (getline(cin, line)) {
        lastOutput = "";
        if (line.substr(0, 5) == "mkdir") {
            string dirName = line.substr(6);
            fs.mkdir(dirName);  // 执行mkdir命令
        }
        else if (line.substr(0, 2) == "cd") {
            string dirName = line.substr(3);
            fs.cd(dirName);  // 执行cd命令
        }
        else if (line == "pwd") {
            lastOutput = fs.pwd();      // 执行pwd命令，并保存输出
            cout << lastOutput << endl; // 打印最后的pwd输出结果
        }
    }

    //cout << lastOutput << endl;  // 打印最后的pwd输出结果

    return 0;
}
