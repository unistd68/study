/*
 * @Author: your name
 * @Date: 2021-08-17 19:38:38
 * @LastEditTime: 2022-01-19 02:13:15
 * @LastEditors: Ace
 * @Description: In User Settings Edit
 * @FilePath: \dubbo-goe:\code\tmp\BaseCall.cpp
 */
#include"BaseCall.hpp"

BaseCall::BaseCall()
{
    m_CallBackMsg = std::bind(CallBack::CallBackFunc, std::placeholders::_1);
}

BaseCall::~BaseCall()
{

}

void BaseCall::TestCallBack()
{
    StCallBackMsg msg1={CallType::NAME,"00000001","My Name is Tom"};
    StCallBackMsg msg2={CallType::AGE,"00000002","200"};
    StCallBackMsg msg3={CallType::GRADE,"00000003","150"};

    m_CallBackMsg(msg1);
    m_CallBackMsg(msg2);
    m_CallBackMsg(msg3);
}


