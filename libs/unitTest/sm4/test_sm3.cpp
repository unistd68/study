/*
 * @Author: your name
 * @Date: 2021-10-21 20:13:17
 * @LastEditTime: 2021-10-21 21:40:21
 * @LastEditors: Please set LastEditors
 * @Description: In User Settings Edit
 * @FilePath: \dubbo-goe:\code\study\libs\unitTest\sm4\test_sm3.cpp
 */

#include "includes.h"
#include "sm3.h"

void test()
{
    const unsigned char *in = "{\"name\":\"zhangsan\",\"age\":\"18\",\"sex\":\"male\"}";
    unsigned char out[1024] = {0};
    printf("in:%s\n", in);
    printf("len:%d\n", strlen(in));

    ASCII2SM3(in, strlen(in), out);

    unsigned char in2[43] = {0x7B,22,6E,61,6D,65,22,3A,22,7A,68,61,6E,67,73,61,6E,22,2C,22,61,67,65,22,3A,22,31,38,22,2C,22,73,65,78,22,3A,22,6D,61,6C,65,22,7D};
    unsigned char out2[1024] = {0};
    HEX2SM3(in2, 43, out2);
}

int main()
{
    test();
    return 0;
}