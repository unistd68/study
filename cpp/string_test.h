/*
 * @Author: your name
 * @Date: 2021-11-01 11:49:16
 * @LastEditTime: 2021-11-01 12:23:26
 * @LastEditors: Please set LastEditors
 * @Description: In User Settings Edit
 * @FilePath: \dubbo-goe:\other\vshare\test\string_test.h
 */

#ifndef _STRING_TEST_H_
#define _STRING_TEST_H_

#include "includes.h"

int centerSpread(const char *in, int left, int right);
int longestPalindromeString(const char *in, char *out);

class queue_digit
{
public:
    std::string tmp;
    std::vector<std::string> res;
    std::vector<std::string> board = {"", "", "abc", "def", "ghi", "jkl", "mno", "pqrs", "tuv", "wxyz"};
    void DFS(int pos, std::string digits)
    {
        if (pos == digits.size())
        {
            res.push_back(tmp);
            return;
        }
        int num = digits[pos] - '0';
        for (int i = 0; i < board[num].size(); i++)
        {
            tmp.push_back(board[num][i]);
            DFS(pos + 1, digits);
            tmp.pop_back();
        }
    }
    std::vector<std::string> letterCombinations(std::string digits)
    {
        if (digits.size() == 0)
            return res;
        DFS(0, digits);
        return res;
    }
};

class backtrat_digits
{
public:
    std::vector<std::string> res;

    std::vector<std::string> letterCombinations(std::string digits)
    {
        if (digits == "")
            return {};
        dfs(digits, 0);
        return res;
    }
    void dfs(std::string digits, int index)
    {
        if (index == digits.length())
        {
            res.push_back(digits);
            return;
        }
        switch (digits[index])
        {
        case '2':
            digits[index] = 'a';
            dfs(digits, index + 1);
            digits[index] = 'b';
            dfs(digits, index + 1);
            digits[index] = 'c';
            dfs(digits, index + 1);
            break;
        case '3':
            digits[index] = 'd';
            dfs(digits, index + 1);
            digits[index] = 'e';
            dfs(digits, index + 1);
            digits[index] = 'f';
            dfs(digits, index + 1);
            break;
        case '4':
            digits[index] = 'g';
            dfs(digits, index + 1);
            digits[index] = 'h';
            dfs(digits, index + 1);
            digits[index] = 'i';
            dfs(digits, index + 1);
            break;
        case '5':
            digits[index] = 'j';
            dfs(digits, index + 1);
            digits[index] = 'k';
            dfs(digits, index + 1);
            digits[index] = 'l';
            dfs(digits, index + 1);
            break;
        case '6':
            digits[index] = 'm';
            dfs(digits, index + 1);
            digits[index] = 'n';
            dfs(digits, index + 1);
            digits[index] = 'o';
            dfs(digits, index + 1);
            break;
        case '7':
            digits[index] = 'p';
            dfs(digits, index + 1);
            digits[index] = 'q';
            dfs(digits, index + 1);
            digits[index] = 'r';
            dfs(digits, index + 1);
            digits[index] = 's';
            dfs(digits, index + 1);
            break;
        case '8':
            digits[index] = 't';
            dfs(digits, index + 1);
            digits[index] = 'u';
            dfs(digits, index + 1);
            digits[index] = 'v';
            dfs(digits, index + 1);
            break;
        case '9':
            digits[index] = 'w';
            dfs(digits, index + 1);
            digits[index] = 'x';
            dfs(digits, index + 1);
            digits[index] = 'y';
            dfs(digits, index + 1);
            digits[index] = 'z';
            dfs(digits, index + 1);
            break;
        }
    }
};

class SumOfNums
{
public:
    std::vector<std::vector<int>> fourSum(std::vector<int> &nums, int N, int target)
    {
        std::vector<std::vector<int>> res;
        std::vector<int> cur;
        sort(nums.begin(), nums.end());
        findNsum(nums, target, N, cur, res);
        return res;
    }
    void findNsum(std::vector<int> &nums, int target, int N, std::vector<int> cur, std::vector<std::vector<int>> &res)
    {
        if (N < 2 || nums.size() < N || nums[0] * N > target)
            return;
        if (N == 2)
        {
            int i = 0, j = nums.size() - 1;
            while (i < j)
            {
                if (nums[i] + nums[j] == target)
                {
                    std::vector<int> temp; //注意新建一个数组，不改变cur
                    for (int p = 0; p < cur.size(); p++)
                        temp.push_back(cur[p]);
                    temp.push_back(nums[i]);
                    temp.push_back(nums[j]); //python中list合并’+’的实现
                    res.push_back(temp);
                    while (i < j && nums[i] == nums[i + 1])
                        i++;
                    while (i < j && nums[j] == nums[j - 1])
                        j--;
                    i++;
                    j--;
                }
                else if (nums[i] + nums[j] < target)
                    i++;
                else
                    j--;
            }
        }
        else
        {
            for (int k = 0; k < nums.size() - N + 1; k++)
            {
                if (k == 0 || nums[k] != nums[k - 1])
                {
                    std::vector<int> tempNums, tempCur;
                    for (int t = k + 1; t < nums.size(); t++)
                        tempNums.push_back(nums[t]);
                    for (int z = 0; z < cur.size(); z++) //注意新建一个数组，不改变cur
                        tempCur.push_back(cur[z]);
                    tempCur.push_back(nums[k]);
                    findNsum(tempNums, target - nums[k], N - 1, tempCur, res);
                }
            }
        }
    }
};

#endif