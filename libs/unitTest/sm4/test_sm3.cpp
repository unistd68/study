/*
 * @Author: your name
 * @Date: 2021-10-21 20:13:17
 * @LastEditTime: 2021-10-21 23:23:14
 * @LastEditors: Please set LastEditors
 * @Description: In User Settings Edit
 * @FilePath: \dubbo-goe:\code\study\libs\unitTest\sm4\test_sm3.cpp
 */

#include "includes.h"
#include "sm3.h"

void test()
{
    const unsigned char *in = "abc";
    unsigned char out[1024] = {0};
    printf("in:%s\n", in);
    printf("len:%d\n", strlen(in));

    ASCII2SM3(in, strlen(in), out);

    unsigned char in2[43] = {0x7B,0x22,0x6E,0x61,0x6D,0x65,0x22,0x3A,0x22,0x7A,0x68,0x61,0x6E,0x67,0x73,0x61,0x6E,0x22,0x2C,0x22,0x61,0x67,0x65,0x22,0x3A,0x22,0x31,0x38,0x22,0x2C,0x22,0x73,0x65,0x78,0x22,0x3A,0x22,0x6D,0x61,0x6C,0x65,0x22,0x7D};
    unsigned char out2[1024] = {0};
    HEX2SM3(in2, 43, out2);
}

int main()
{
    test();
    return 0;
}