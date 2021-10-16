/*
 * @Author: your name
 * @Date: 2021-10-16 17:27:52
 * @LastEditTime: 2021-10-16 17:27:53
 * @LastEditors: Please set LastEditors
 * @Description: In User Settings Edit
 * @FilePath: \dubbo-goe:\code\study\sm4\TestSM4\test_sm4.cpp
 */

#include "sm4.h"

const char* key = "1234567890abcdef";
const char* plain_in = "{\"name\":\"张三\",\"age\":\"18\",\"sex\":\"male\"}";
const char* plain_in_hex = "7b5c226e616d655c223a5c225f4e5c222c5c226167655c223a5c2231385c222c5c227365785c223a5c226d616c655c227d";
const char* encrpto_data = "551EB5F76082DF027FE1F4E977234F0EFEE56A0820792CBE0605005C0A62F9C78B9FFC795CD1A0B6DD55073C2326E8CE1D7D2755550AA81E3CC9CD9DBCE723C4";


void testSM4Encrypto()
{
    // const char *key = "1234567890abcdef";
    // const char *in = "{\"name\":\"张三\",\"age\":\"18\",\"sex\":\"male\"}";
    char out[1024] = {0};
    SM4Encrypto(key, plain_in, out);
    if(strcmp(encrpto_data,out) == 0)
    {
        printf(" ### testSM4Encrypto ### test ok\n");
    }
    else
    {
        printf(" ### testSM4Encrypto ### test fail\n");
    }
}

void testSM4Decrypto()
{
    // const char *key = "1234567890abcdef";
    // const char *in = "551EB5F76082DF027FE1F4E977234F0EFEE56A0820792CBE0605005C0A62F9C78B9FFC795CD1A0B6DD55073C2326E8CE1D7D2755550AA81E3CC9CD9DBCE723C4";
    char out[1024] = {0};
    SM4Decrypto(key, encrpto_data, out);
    if(strcmp(plain_in_hex,out) == 0)
    {
        printf(" ### testSM4Decrypto ### test ok\n");
    }
    else
    {
        printf(" ### testSM4Decrypto ### test fail\n");
    }
}

int main()
{
    testSM4Encrypto();
    testSM4Decrypto();
    return 0;
}