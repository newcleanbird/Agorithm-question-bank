/*
006 数组去重和排序
给定一个乱序的数组，删除所有的重复元素，使得每个元素只出现一次，并且按照出现的次数从高到低进行排序，相同出现次数按照第一次出现顺序进行先后排序

输入
一个数组

输出
去重排序后的数组


输入
1,3,3,3,2,4,4,4,5

输出
3,4,1,2,5

说明:
数组大小不超过100 数组元素值大小不超过100。
*/


#include <iostream>
#include <string>
#include <vector>
#include <unordered_map>
#include <algorithm>

// 定义一个辅助结构体，用于存储元素的值和出现次数
struct Element {
    int value;
    int count;
};

// 自定义比较函数，按照题目要求进行排序
bool compare(const Element& a, const Element& b) {
    if (a.count == b.count) {
        return a.value < b.value;
    }
    return a.count > b.count;
}

std::vector<int> removeDuplicatesAndSort(std::vector<int>& nums) {
    std::unordered_map<int, int> countMap; // 用于记录每个元素的出现次数
    for (int num : nums) {
        countMap[num]++;
    }

    std::vector<Element> elements; // 用于存储元素及其出现次数的结构体数组
    for (auto& entry : countMap) {
        elements.push_back({ entry.first, entry.second });
    }

    std::sort(elements.begin(), elements.end(), compare); // 按照出现次数和值进行排序

    std::vector<int> result; // 存储最终结果的数组
    for (const Element& element : elements) {
        result.push_back(element.value);
    }

    return result;
}

int main() {
    std::string input;
    std::getline(std::cin, input);

    std::vector<int> nums;
    size_t startPos = 0;
    size_t commaPos = input.find(',');

    while (commaPos != std::string::npos) {
        std::string numStr = input.substr(startPos, commaPos - startPos);
        int num = std::stoi(numStr);
        nums.push_back(num);
        startPos = commaPos + 1;
        commaPos = input.find(',', startPos);
    }

    // 处理最后一个逗号后的数字
    std::string numStr = input.substr(startPos);
    int num = std::stoi(numStr);
    nums.push_back(num);

    std::vector<int> result = removeDuplicatesAndSort(nums);

    for (int i = 0; i < result.size(); i++) {
        std::cout << result[i];
        if (i != result.size() - 1) {
            std::cout << ",";
        }
    }

    return 0;
}


