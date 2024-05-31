///*
//公鸡5元，母鸡4元，小鸡1元三只，求100元买100只鸡的解法
//*/
//
//#include <iostream>
//
//using namespace std;
//
//// 暴力解法
//void solution1()
//{
//    // 循环变量，分别代表公鸡、母鸡、小鸡的数量
//    for (int roosters = 0; roosters <= 100; ++roosters) {
//        for (int hens = 0; hens <= 100; ++hens) {
//            for (int chicks = 0; chicks <= 100; ++chicks) {
//                // 检查是否满足总数量为100只
//                if (roosters + hens + chicks == 100) {
//                    // 计算总花费
//                    int totalCost = roosters * 5 + hens * 4 + chicks / 3;
//                    // 检查是否满足总花费为100元
//                    if (totalCost == 100) {
//                        std::cout << "公鸡: " << roosters << ", 母鸡: " << hens << ", 小鸡: " << chicks << " (小鸡按三只为一组计算)" << std::endl;
//                        // 注意：这里的小鸡数量是以“三只为一组”来计数的，实际数量需要乘以3
//                    }
//                }
//            }
//        }
//    }
//}
//
///*
//公式法：
//x + y + z = 100 （总数量）
//5x + 4y + z/3 = 100 （总价值）
//
//避免分数：
//3x + 3y + 3z = 300 （总数量）
//15x + 12y + z = 300 （总价值）
//*/
//void solution2() {
//    // 遍历可能的公鸡和母鸡数量
//    for (int x = 0; x <= 100; ++x) {
//        for (int y = 0; y <= 100; ++y) {
//            // 根据方程3x + 3y + 3z = 300推导出z的可能值，但实际上应考虑小鸡的购买规则
//            int z = 300 - 3 * x - 3 * y;
//            // 检查z是否为非负整数，以及是否满足总价值的方程
//            if (z >= 0 && 15 * x + 12 * y + z == 300) {
//                std::cout << "公鸡: " << x << ", 母鸡: " << y << ", 小鸡(按个计): " << z << std::endl;
//            }
//        }
//    }
//}
//
//
//int main() {
//    solution1();
//
//    cout << "solution2:" << endl;
//    solution2();
//    return 0;
//}