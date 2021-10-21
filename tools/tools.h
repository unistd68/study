/*
* @Author: your name
* @Date: 2021-10-16 17:29:00
 * @LastEditTime: 2021-10-21 21:25:06
 * @LastEditors: Please set LastEditors
* @Description: In User Settings Edit
* @FilePath: \dubbo-goe:\code\study\tools\com_tools.h
*/
#pragma once
#ifndef _TOOLS_H_
#define _TOOLS_H_
#include "../includes/includes.h"
/**
 * @description: 
 * @param {char} *in
 * @param {unsigned char} *out
 * @return {int} 
 */
int hex2Array(unsigned char *in, unsigned char *out)
{
    unsigned char *p = in;
    char high = 0, low = 0;
    int tmplen = strlen(p), cnt = 0;
    tmplen = strlen(p);
    while (cnt < (tmplen / 2))
    {
        high = ((*p > '9') && ((*p <= 'F') || (*p <= 'f'))) ? *p - 48 - 7 : *p - 48;
        low = (*(++p) > '9' && ((*p <= 'F') || (*p <= 'f'))) ? *(p)-48 - 7 : *(p)-48;
        out[cnt] = ((high & 0x0f) << 4 | (low & 0x0f));
        p++;
        cnt++;
    }
    if (tmplen % 2 != 0)
    {
        out[cnt] = ((*p > '9') && ((*p <= 'F') || (*p <= 'f'))) ? *p - 48 - 7 : *p - 48;
    }
    return tmplen / 2 + tmplen % 2;
}
/*************************************************
Function:       string2HexArray
Description:    ascii字符串转16进制数组
Input:          in:ascII字符串，如abcd1234
                len:ascII字符串的有效字符串长度
                big:hex字符串是否大写字母
Output:         out:输出的hex字符串，如3132334d
Return:         
Sample:         (in)data: 123M,(out):3132334d
*************************************************/
/**
 * @description: 
 * @param {char} *in
 * @param {int} len
 * @param {unsigned char} *out
 * @return {*}
 */
int ascii2HexArray(const char *in, int len, unsigned char *out)
{
    unsigned char tmpOut[1024] = {0};
    int i = 0, j = 0;
    char alTmp[16] = {'0', '1', '2', '3', '4', '5', '6', '7', '8', '9', 'a', 'b', 'c', 'd', 'e', 'f'};
    for (i = 0, j = i; i < len; i++, j += 2)
    {
        tmpOut[j] = alTmp[in[i] / 16];
        tmpOut[j + 1] = alTmp[in[i] % 16];
    }
    // printf("len: %d\n", len);
    // printf("tmpOut: %s", tmpOut);
    // printf("\n");
    char *p = tmpOut;
    char high = 0, low = 0;
    int tmplen = strlen(p), cnt = 0;
    while (cnt < (tmplen / 2))
    {
        high = ((*p > '9') && ((*p <= 'F') || (*p <= 'f'))) ? *p - 48 - 7 : *p - 48;
        low = (*(++p) > '9' && ((*p <= 'F') || (*p <= 'f'))) ? *(p)-48 - 7 : *(p)-48;
        out[cnt] = ((high & 0x0f) << 4 | (low & 0x0f));
        p++;
        cnt++;
    }
    if (tmplen % 2 != 0)
        out[cnt] = ((*p > '9') && ((*p <= 'F') || (*p <= 'f'))) ? *p - 48 - 7 : *p - 48;
    return tmplen / 2 + tmplen % 2;
}
/**
 * @description: 
 * @param {unsigned char} *in
 * @param {unsigned int} len
 * @param {char} *out
 * @return {*}
 */
int hexArr2String(unsigned char *in, int len, char *out)
{
    unsigned char strBuf[1024] = {0};
    char pbuf[32];
    int i, j, index = 0;
    for (i = 0, j = i; i < len; i++, j += 2)
    {
        index++;
        if (in[i] == 0x00)
        {
            index--;
        }
        sprintf(pbuf, "%02X", in[i]);
        strncat(strBuf + j, pbuf, 2);
    }
    strncpy(out, strBuf, index * 2);
    return index * 2;
}
/*c++ 利用chrono函数获取时间戳 毫秒级*/
std::string GetTimeStamp()
{
    auto timeNow = std::chrono::duration_cast<std::chrono::milliseconds>(std::chrono::system_clock::now().time_since_epoch());
    long long timestamp = timeNow.count();
    return std::to_string(timestamp);
}

std::string GetRandStr(int len) /*参数为字符串的长度*/
{
    /*初始化*/
    //std::string str; /*声明用来保存随机字符串的str*/
    std::stringstream str;
    char c;  /*声明字符c，用来保存随机生成的字符*/
    int idx; /*用来循环的变量*/
    /*循环向字符串中添加随机生成的字符*/
    for (idx = 0; idx < len; idx++)
    {
        /*rand()%26是取余，余数为0~25加上'a',就是字母a~z,详见asc码表*/
        c = 'a' + rand() % 26;
        //str.emplace_back(c); /*push_back()是string类尾插函数。这里插入随机字符c*/
        str << c;
    }
    return str.str(); /*返回生成的随机字符串*/
}

/**
 * @description: 获取当前时间的字符串
 * @param {*}
 * @return {*}
 */
static std::string get_format_time_string() //获取格式化时间
{
    time_t now;
    struct tm *tm_now;
    char datetime[128];

    time(&now);
    tm_now = localtime(&now);
    strftime(datetime, 128, "%Y-%m-%d %H:%M:%S", tm_now);

    return datetime;
}

/**
 * @description: 获取时间戳
 * @param {*}
 * @return 秒级时间戳
 */
static int get_timestamp()
{
    time_t timep;
    struct tm *p;
    time(&timep); /*当前time_t类型UTC时间*/
    //printf("time():%d\n",timep);
    p = localtime(&timep); /*转换为本地的tm结构的时间按*/
    timep = mktime(p);
    return timep;


    // time_t myt = time(NULL);
    // time_t t;
    // time(&t);
    // return static_cast<int>(t.time);
}

#endif