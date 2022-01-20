/*
 * @Author: your name
 * @Date: 2021-08-17 19:37:26
 * @LastEditTime: 2021-08-17 20:47:28
 * @LastEditors: Please set LastEditors
 * @Description: In User Settings Edit
 * @FilePath: \dubbo-goe:\code\tmp\CallBack.cpp
 */
#include "CallBack.hpp"
#include "BaseCall.hpp"

CallBack::CallBack()
{
}

CallBack::~CallBack()
{
}

void CallBack::CallBackFunc(StCallBackMsg msg)
{
	
    switch (msg._enCalltype)
    {
    case NAME:
        onPrintName(msg._strData);
        break;
    case AGE:
        onPrintAge(std::stoi(msg._strData));
        break;
    case GRADE:
        onPrintGrade(std::stoi(msg._strData));
        break;
    default:
        break;
    }
}

void CallBack::onPrintName(std::string strName)
{
    printf("姓名： %s\n", strName.c_str());
}

void CallBack::onPrintAge(int nAge)
{
    printf("年龄： %d\n", nAge);
}

void CallBack::onPrintGrade(int nGrade)
{
    printf("班级：%d\n", nGrade);
}