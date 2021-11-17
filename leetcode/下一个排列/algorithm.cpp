/*
 * @Author: your name
 * @Date: 2021-11-17 12:00:08
 * @LastEditTime: 2021-11-17 12:25:22
 * @LastEditors: Please set LastEditors
 * @Description: 打开koroFileHeader查看配置 进行设置: https://github.com/OBKoro1/koro1FileHeader/wiki/%E9%85%8D%E7%BD%AE
 * @FilePath: \dubbo-goe:\other\vshare\test\leetcode\下一个排列\algorithm.cpp
 */
#include "algorithm.h"
#include "tools.h"

void test()
{
    int n;
    std::vector<int> &nums;
    std::cout << "请输入数组个数：" << std::endl;
    std::cin >> n;
    for (int i = 0; i < n; i++)
    {
        std::cout << "请输入第" << i + 1 << "个数：" << std::endl;
        std::cin >> nums[i];
    }
    nextPermutation(nums);
    show_vector(nums,"下一个排列");
}