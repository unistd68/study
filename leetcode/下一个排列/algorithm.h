/*
 * @Author: your name
 * @Date: 2021-11-17 11:59:47
 * @LastEditTime: 2021-11-17 12:20:26
 * @LastEditors: Please set LastEditors
 * @Description: 打开koroFileHeader查看配置 进行设置: https://github.com/OBKoro1/koro1FileHeader/wiki/%E9%85%8D%E7%BD%AE
 * @FilePath: \dubbo-goe:\other\vshare\test\leetcode\下一个排列\algorithm.h
 */


class Solution {
public:
    void nextPermutation(std::vector<int>& nums) {
        int i=0;
        for (i=nums.size()-2; i >= 0; -- i) { // 从后往前找到第一个相邻升序对
            if (nums[i] < nums[i+1]) break;
        }
        if (i == -1) std::reverse(nums.begin(),nums.end()); // 无相邻升序对，必定为非递减序列
        else {
            for (int j=nums.size()-1; j >= i+1; -- j) { // 从后往前[i+1,end)找第一个大于a[i+1]的值
                if (nums[i] < nums[j]) {
                    std::swap(nums[i],nums[j]); // 交换二者
                    std::reverse(nums.begin()+i+1,nums.end()); // 反转[i+1,end)，变成升序
                    break;
                }
            }
        }
    }
};

void test();