/*
458、堆内存申请
题目描述：
有一个总空间为100字节的堆，现要从中新申请一块内存，内存分配原则为优先紧接着前一块已使用内存分配空间足够且最接近申请大小的空闲内存。

输入描述：
输入：
第1行是1个整数，表示期望申请的内存字节数；
第2到N行是用空格分割的两个整数，表示当前已分配的内存的情况，每一行表示一块已分配的连续内存空间，每行的第1和第2个整数分别表示偏移地址和内存块大小，如：
0 1
3 2
表示0偏移地址开始的1个字节和3偏移地址开始的2个字节已被分配，其余内存空闲。

输出描述：
输出:
若申请成功，输出申请到内存的偏移；若申请失败，输出-1。

补充说明：
1.若输入信息不合法或无效，则申请失败。
2.若没有足够的空间供分配，则申请失败。
3.堆内存信息有区域重叠或有非法值等都是无效输入。

示例1
输入：
1
0 1
3 2
输出：
1
说明：
堆中已使用的两块内存是偏移从0开始1字节和偏移从3开始的2字节，空闲的两块内存是偏移从1开始2个字节和偏移从5开始95字节，根据分配原则，新申请的内存应从1开始分配1个字节，所以输出偏移为1.

题目要求
1. 总堆大小：给定一个总共100字节大小的堆内存。
2. 内存分配原则：
   - 优先选择紧接着前一块已使用内存的空闲内存块。
   - 选择空闲内存块中最小的、足以满足申请需求的块。

解题步骤
1. 读取输入：
   - 读取申请的内存大小，确保它是一个合法的正整数且不超过总堆大小。
   - 读取已分配的内存块信息，包括每个块的起始位置和大小。
2. 验证输入合法性：
   - 确保内存块的起始地址和大小是合法的，并且块不超出堆的界限。
   - 检查是否有重叠的内存块。
3. 计算空闲内存块：
   - 在已分配内存块之间以及最后一个内存块与堆边界之间寻找空闲内存块。计算这些空闲块的大小和起始地址。
4. 选择合适的空闲块：
   - 根据内存分配原则，从空闲内存块中选择最小的、足够大的内存块进行分配。
5. 输出结果：
   - 如果找到合适的空闲内存块，则输出该块的起始地址。否则输出 -1。
边缘情况
- 非法输入：如内存块的起始地址或大小是负数、超出堆大小等。
- 内存块重叠：通过排序和比较检查重叠。
- 空间不足：在所有空闲块都不足以满足申请时返回 -1。
- 没有已分配的内存块：如果没有任何已分配的内存块，整个堆被视为一个大的空闲块。
*/
#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

struct Block {
    int start;
    int size;
};

int main() {
    int requestSize;
    cin >> requestSize; // 读取申请的内存大小
    if (requestSize <= 0 || requestSize > 100) {
        cout << -1 << endl;
        return 0;
    }

    vector<Block> usedBlocks; // 存储已分配的内存块
    int start, size;

    while (cin >> start >> size) {
        if (start < 0 || size <= 0 || start + size > 100) {
            cout << -1 << endl; // 非法值导致申请失败
            return 0;
        }
        usedBlocks.push_back({ start, size });
    }

    // 检查内存块重叠
    sort(usedBlocks.begin(), usedBlocks.end(), [](const Block& a, const Block& b) {
        return a.start < b.start;
        });
    for (int i = 1; i < usedBlocks.size(); ++i) {
        if (usedBlocks[i].start < usedBlocks[i - 1].start + usedBlocks[i - 1].size) {
            cout << -1 << endl; // 内存块重叠
            return 0;
        }
    }

    const int HEAP_SIZE = 100; // 总内存大小
    vector<Block> freeBlocks; // 存储空闲的内存块
    int currentEnd = 0; // 当前已处理到的内存位置

    // 找出所有空闲内存块
    for (const auto& block : usedBlocks) {
        if (block.start > currentEnd) {
            freeBlocks.push_back({ currentEnd, block.start - currentEnd });
        }
        currentEnd = block.start + block.size;
    }
    // 检查最后一个已用块之后是否还有空闲内存
    if (currentEnd < HEAP_SIZE) {
        freeBlocks.push_back({ currentEnd, HEAP_SIZE - currentEnd });
    }

    // 检查每个空闲内存块，找到足够大的最小块
    int bestFitStart = -1;
    int minSizeDiff = HEAP_SIZE + 1;

    for (const auto& block : freeBlocks) {
        if (block.size >= requestSize && block.size - requestSize < minSizeDiff) {
            bestFitStart = block.start;
            minSizeDiff = block.size - requestSize;
        }
    }

    cout << (bestFitStart != -1 ? bestFitStart : -1) << endl; // 输出最佳位置或-1
    return 0;
}