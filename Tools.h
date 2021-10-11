/*
 * @Author: your name
 * @Date: 2021-10-05 15:08:18
 * @LastEditTime: 2021-10-05 15:52:50
 * @LastEditors: Please set LastEditors
 * @Description: In User Settings Edit
 * @FilePath: \dubbo-goe:\code\study\UseRedis.h
 */
#ifndef __TOOLS_H__
#define __TOOLS_H__

#include <iostream>
#include <time.h>
#include <chrono>
#include <string>

//c++ 利用chrono函数获取时间戳 毫秒级
static std::string GetTimeStamp()
{
	auto timeNow = chrono::duration_cast<chrono::milliseconds>(chrono::system_clock::now().time_since_epoch());
	long long timestamp = timeNow.count();
	return std::to_string(timestamp);
}

static std::string GetRandStr(int len)  /*参数为字符串的长度*/
{
    /*初始化*/
    string str;                 /*声明用来保存随机字符串的str*/
    char c;                     /*声明字符c，用来保存随机生成的字符*/
    int idx;                    /*用来循环的变量*/
    /*循环向字符串中添加随机生成的字符*/
    for(idx = 0;idx < len;idx ++)
    {
        /*rand()%26是取余，余数为0~25加上'a',就是字母a~z,详见asc码表*/
        c = 'a' + rand()%26;
        str.emplace_back(c);       /*push_back()是string类尾插函数。这里插入随机字符c*/
    }
    return str;                 /*返回生成的随机字符串*/
}

#endif