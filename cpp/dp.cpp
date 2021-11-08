/*
 * @Author: your name
 * @Date: 2021-11-03 16:47:50
 * @LastEditTime: 2021-11-08 08:59:24
 * @LastEditors: your name
 * @Description: 打开koroFileHeader查看配置 进行设置: https://github.com/OBKoro1/koro1FileHeader/wiki/%E9%85%8D%E7%BD%AE
 * @FilePath: \dubbo-goe:\other\vshare\test\dp.cpp
 */
#include "dp.h"
#include "tools.h"

int maxCakePrice(int n, std::vector<int> priceList)
{
    if (n <= 1)
        return priceList[n];       // 蛋糕重量 <= 1 时直接返回
    std::vector<int> dp(n + 1, 0); // 初始化 dp 列表
    for (int j = 1; j <= n; j++)
    {                               // 按顺序计算 f(1), f(2), ..., f(n)
        for (int i = 0; i < j; i++) // 从 j 种组合种选择最高售价的组合作为 f(j)
            dp[j] = std::max(dp[j], dp[i] + priceList[j - i]);
    }
    show_vector(dp, "dp");
    return dp[n];
}

void testCakePrice(int n)
{
    std::vector<int> priceList = {0, 2, 3, 6, 7, 11, 15};
    show_vector(priceList, "priceList");
    int price = maxCakePrice(n, priceList);
    std::cout << "price:" << price << std::endl;
}

int getMax(const dpArr &arr, int i)
{
    int max = 0;

    for (int row = 0; row < n; row++)
    {
        max = max >= dpArr[row][i] ? max : dpArr[row][i];
    }
    return max;
}

int fillArr(dpArr &arr, const std::vector<int> &priceList, int n)
{
    for (int column = 0; column < n; column++)
    {
        for (int row = 0; row < n; row++)
        {
            if (row == column)
            {
                if (row == 0)
                {
                    arr[row][column] = 0;
                }
                else if (column == 0)
                {
                    arr[row][column] = -1;
                }
                else
                {
                    arr[row][column] = priceList[1] * row;
                }
            }
            else if (row < column)
            {
                if (row == 1)
                {
                    arr[row][column] = priceList[column];
                }
                else
                {
                    arr[row][column] = 0;
                }
            }
            else
            {
                arr[row][column] = -1;
            }
        }
    }

    for (int column = 3; column < n; column++)
    {
        for (int row = 2; row < column; row++)
        {
            int tmp = 0;
            for (int index = 1; index < row; index++)
            {

            }
        }
    }
    return 0;
}
