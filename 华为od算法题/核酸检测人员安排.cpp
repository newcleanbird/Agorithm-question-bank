/*
题目描述：
在系统、网络均正常的情况下组织核酸采样员和志愿者对人群进行核酸检测筛查。每名采样员的效率不同，采样效率为N人/小时。由于外界变化，采样员的效率会以M人/小时为粒度发生变化，M为采样效率浮动粒度，M=N*10%，输入保证N*10%的结果为整数。采样员效率浮动规则：采样员需要一名志愿者协助组织才能发挥正常效率，在此基础上，每增加一名志愿者，效率提升1M，最多提升3M；如果没有志愿者协助组织，效率下降2M。

怎么安排速度最快？求总最快检测效率（总检查效率为各采样人员效率值相加）。


输入描述：
第一行：第一个值，采样员人数，取值范围[1,100]；第二个值，志愿者人数，取值范围[1,500]；

第二行：各采样员基准效率值(单位人/小时)，取值范围[60,600]，保证序列中每项值计算10%为整数

输出描述：
第一行：总最快检测效率(单位人/小时)

补充说明：
输入需要保证采样员基准效率值序列的每个值*10%为整数

 收起
示例1
输入：
2 2
200 200
输出：
400
说明：

*/