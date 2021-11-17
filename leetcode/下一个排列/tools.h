/*
 * @Author: your name
 * @Date: 2021-10-14 08:54:19
 * @LastEditTime: 2021-11-17 12:08:46
 * @LastEditors: Please set LastEditors
 * @Description: In User Settings Edit
 * @FilePath: \文档c:\Users\msi\Desktop\fresher\vm_shared_data\test\tools.h
 */
#pragma once
#ifndef _TOOLS_H_
#define _TOOLS_H_

#include "includes.h"

template <class T>
void show_vector(std::vector<T> v, const char *name)
{
    std::cout << name << ":" << std::endl;
    auto ite = v.begin();
    while (ite != v.end())
    {
        std::cout << *ite++ << " ";
    }
    std::cout << std::endl;
}

#endif