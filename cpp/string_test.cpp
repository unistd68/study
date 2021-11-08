/*
 * @Author: your name
 * @Date: 2021-11-01 11:49:23
 * @LastEditTime: 2021-11-01 13:58:42
 * @LastEditors: Please set LastEditors
 * @Description: In User Settings Edit
 * @FilePath: \dubbo-goe:\other\vshare\test\string_test.cpp
 */

#include "includes.h"
#include "string_test.h"

/***************************************************** Basic Function *******************************************************************************/

/**
 * @description: 中心扩展算法，获取最长回文子串的长度
 * @param {char} *in
 * @param {int} left
 * @param {int} right
 * @return {*} max len of Palindrome string
 */
int centerSpread(const char *in, int left, int right)
{
    int len = strlen(in);
    if (left < 0 || left >= len || right < 0 || right >= len || left > right)
    {
        return -1;
    }
    while (left >= 0 && right <= len - 1 && in[left] == in[right])
    {
        left--;
        right++;
    }
    if (left + 1 <= right - 1)
    {
        left++;
        right--;
    }
    else
    {
        // etc. "ac"
        right--;
    }

    len = right - left + 1;
    return len;
}

/**
 * @description: 
 * @param {char} *in
 * @param {char} *divide
 * @param {char} *out
 * @return {*}
 */
int addDivide(const char *in, char *divide, char *out)
{
    int len = strlen(in);
    int new_len = len + (len + 1) + 3;
    char *new_in = (char *)malloc(new_len * sizeof(char));
    if (new_in == NULL)
    {
        return -1;
    }
    memset(new_in, 0, new_len);
    int j = 0;
    strncat(new_in + j++, "^#", 2);
    for (int i = 0; i < len; i++)
    {
        strncat(new_in + j++, in + i, 1);
        strncat(new_in + j++, divide, 1);
    }
    strncat(new_in + j++, "$", 1);
    strncpy(out, new_in, new_len - 1);
    free(new_in);
    new_in = NULL;
    return 0;
}

/***************************************************** Function *******************************************************************************/

/**
 * @description: 使用中心扩展算法获取最长回文字符串
 * @param {char} *in
 * @param {char} *out
 * @return {*} 0:success ,not 0:fail
 */
int longestPalindromeString(const char *in, char *out)
{
    int i = 0;
    int maxLen = 0, begin = 0;
    for (; i < strlen(in); i++)
    {
        int ret1 = 0, ret2 = 0;
        ret1 = centerSpread(in, i, i + 1);
        ret2 = centerSpread(in, i, i);
        if (ret1 >= ret2 && ret1 > maxLen)
        {
            maxLen = ret1;
            begin = i + 1 - ret1 / 2;
        }
        else if (ret2 >= ret1 && ret2 > maxLen)
        {
            maxLen = ret2;
            begin = i - (ret2 - 1) / 2;
        }
    }

    strncat(out, in + begin, maxLen);
    return 0;
}
