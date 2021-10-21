/*
 * @Author: your name
 * @Date: 2021-10-21 20:13:17
 * @LastEditTime: 2021-10-21 20:23:09
 * @LastEditors: Please set LastEditors
 * @Description: In User Settings Edit
 * @FilePath: \dubbo-goe:\code\study\libs\unitTest\sm4\test_sm3.cpp
 */

#include "includes.h"
#include "sm3.h"

void test()
{
    unsigned char str[64 * 8 * 8] = {0};
    unsigned char str_sm3[32];
    int len = 5;
    int i = 0;

    /*for(i=0; i<16; i++)
    {
        str[4*i+0] = 0x61;
        str[4*i+1] = 0x62;
        str[4*i+2] = 0x63;
        str[4*i+3] = 0x64;
    }*/

    str[0] = 0x33;
    str[1] = 0x66;
    str[2] = 0x77;
    str[3] = 0x99;

    GetSM3String(str, str_sm3);
}

int main()
{
    test();
    return 0;
}