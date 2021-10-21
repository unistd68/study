/*
 * @Author: your name
 * @Date: 2021-10-21 20:13:17
 * @LastEditTime: 2021-10-21 21:27:11
 * @LastEditors: Please set LastEditors
 * @Description: In User Settings Edit
 * @FilePath: \dubbo-goe:\code\study\libs\unitTest\sm4\test_sm3.cpp
 */

#include "includes.h"
#include "sm3.h"

void test()
{
    const unsigned char* in = "{\"name\":\"zhangsan\",\"age\":\"18\",\"sex\":\"male\"}";
    unsigned char out[1024] = {0};
    GetSM3String(in,strlen(in), out);
}

int main()
{
    test();
    return 0;
}