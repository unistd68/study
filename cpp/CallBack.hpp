/*
 * @Author: your name
 * @Date: 2021-08-17 19:36:55
 * @LastEditTime: 2022-01-19 02:08:25
 * @LastEditors: Ace
 * @Description: In User Settings Edit
 * @FilePath: \dubbo-goe:\code\tmp\CallBack.hpp
 */
#ifndef _CALLBACK_H
#define _CALLBACK_H
#include"includes.h"

//using namespace std;

class CallBack
{
public:
    CallBack();
    ~CallBack();

public:
    static void CallBackFunc(StCallBackMsg Msg);


private:
    static void onPrintName(std::string);
    static void onPrintAge(int);
    static void onPrintGrade(int);
};

#endif