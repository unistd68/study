/*
 * @Author: your name
 * @Date: 2021-10-16 17:27:52
 * @LastEditTime: 2021-10-22 00:03:36
 * @LastEditors: Please set LastEditors
 * @Description: In User Settings Edit
 * @FilePath: \dubbo-goe:\code\study\sm4\TestSM4\test_sm4.cpp
 */

#include "sm4.h"

const char* key = "123456789gabcdef";
const char* plain_in = "{\"name\":\"zhangsan\",\"age\":\"18\",\"sex\":\"male\"}";
const char* plain_in_hex = "7B226E616D65223A227A68616E6773616E222C22616765223A223138222C22736578223A226D616C65227D";
const char* encrpto_data = "C3A6D7F25CD94E43525A8DEFA20B7F5DBCAFF7DFD1AF14E08386116D1300F1CCDB44E374DD6731221BE8B0D5A3A02F85";
//加密前: {"name":"张三","age":"18","sex":"male"}
//加密前: 7B226E616D65223A22E5BCA0E4B889222C22616765223A223138222C22736578223A226D616C65227D
//加密后: 82ADED14217761441B4F1BFE1E26390700FC5D1E4E85D24D5AB44B8FF4AD01FA0900F6E43D08C409ED1CFBCF5283B399

void testSM4Encrypto()
{
    const char *key = "1234567890abcdef";
    //const char *in = "{\"name\":\"张三\",\"age\":\"18\",\"sex\":\"male\"}";
    const char *in = "wqetwdadada";
    char out[1024] = {0};
    SM4Encrypto(key, in, out);
    printf("key: %s\n",key);
    printf("in: %s\n",in);
    printf("out: %s\n",out);
    // if(strcmp(encrpto_data,out) == 0)
    // {
    //     printf(" ### testSM4Encrypto ### test ok\n");
    // }
    // else
    // {
    //     printf(" ### testSM4Encrypto ### test fail\n");
    // }
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

int main(char *argv[],int argc)
{
    testSM4Encrypto();
    //testSM4Decrypto();
    return 0;
}