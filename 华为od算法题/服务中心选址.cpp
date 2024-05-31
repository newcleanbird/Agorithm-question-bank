/*
■ 题目描述

【服务中心选址】

一家快递公司希望在一条街道建立新的服务中心。
公司统计了该街道中所有区域在地图上的位置，并希望能够以此为依据为新的服务中心选址：使服务中心到所有区域的距离的总和最小。
给你一个数组 positions，其中 positions []=[left,right ]表示第1个区域在街道上的位置，其中 left 代表区域的左侧的起点， right 表示区域的右侧终点，
设择服务中心的位置为 location,如果第1个区城的右侧起点 right 满足 right < location ，
则第1个区域到服务中心的距离为 location – right ;

如果第 i 个区域的左侧起点 left 满足 left > location ，则第 i 个区城到服务中心的距离为 left – location ;
如果第 i 个区域的两侧 left , right 满足 left <= location <= right ，
则第1个区域到 服务中心的距离为0; 选择最佳的服务中心的位置为 location ，请返回最佳的服务中心位置到所有区域的距离总和的最小值。

输入描述

第一行，一个整数N表示区域个数。
后面N行，每行两个整数，表示区域的左右起点终点。

输出描述

运行结果输出一个整数，表示服务中心位置到所有区域的距离总和的最小值。

示例1 输入输出示例仅供调试，后台判题数据一般不包含示例

输入

3
1 2
3 4
10 20
输出

8
*/
/*
解体思路:二分查找


*/


#include<bits/stdc++.h>

using namespace std;

int main(){
    int N;
    cin >> N; // 区域个数
    vector<vector<int> > positions(N, vector<int>(2));
    for(int i = 0; i < N; i++){
        cin >> positions[i][0] >> positions[i][1];
    }
    // 有N个区域,每个区域有一个范围
    // 暴力解是,遍历所有的范围内的点,输出距离
    int max_l = positions[0][0], max_r = positions[0][1]; // 最左边,最右边
    // 找到最左端,最右端
    for(auto i : positions){
        if(i[0] < max_l){
            max_l = i[0];
        }
        if(i[1] > max_r){
            max_r = i[1];
        }
    }
    // 遍历每个点
    set<int> min_pos; // 存储每个点的值
    for(int pos = max_l; pos <= max_r; pos++) // pos 为当前点
    {
        int sum_p = 0;
        for(int i = 0; i < N; i++){
            if(pos < positions[i][0])
            { // 在范围左边
                sum_p += positions[i][0] - pos;
            }
            else if (pos <= positions[i][1]) // 在范围内
            {
                sum_p += 0;
            }
            else{
                sum_p += pos - positions[i][1];
            }
        }
        min_pos.insert(sum_p);
    }
    cout << *min_pos.begin();
        
    
    






    system("pause");


}
