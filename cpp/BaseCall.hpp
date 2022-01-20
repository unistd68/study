/*
 * @Author: your name
 * @Date: 2021-08-17 19:37:59
 * @LastEditTime: 2022-01-19 02:13:09
 * @LastEditors: Ace
 * @Description: In User Settings Edit
 * @FilePath: \dubbo-goe:\code\tmp\BaseCall.hpp
 */
#ifndef _BASECALL_H
#define _BASECALL_H
#include "includes.h"
#include "CallBack.hpp"

class BaseCall
{
public:
    BaseCall();
    ~BaseCall();

public:
    void TestCallBack();

private:
    std::function<void(StCallBackMsg)> m_CallBackMsg; 

};


#endif