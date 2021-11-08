/*
 * @Author: your name
 * @Date: 2021-10-14 08:54:19
 * @LastEditTime: 2021-11-01 11:41:51
 * @LastEditors: Please set LastEditors
 * @Description: In User Settings Edit
 * @FilePath: \文档c:\Users\msi\Desktop\fresher\vm_shared_data\test\tools.h
 */
#pragma once
#ifndef _TOOLS_H_
#define _TOOLS_H_

#include "includes.h"

void Get32UUIDFormat(char *str);
unsigned long long get_timestamp();
void get_currtime_string(char *str_time);
void timestamp2String(time_t t, char *str_time);
void char2Upper(const char *in, char *out);
void char2Lower(const char *in, char *out);
int arrayToStr(unsigned char *in, unsigned int len, unsigned char *out);
int ascii2HexChar(unsigned char *in, int len, unsigned char *out);
int hex2Array(unsigned char *in, int len, unsigned char *out);
int ascii2HexArray(unsigned char *in, int in_len, unsigned char *out);

int SM4ECBEncrypte(const unsigned char *key, const char *in, char *out);
int SM4ECBDecrypte(const unsigned char *key, const char *in, char *out);

int SM4ECBEncryptePadding7(const unsigned char *key, const unsigned char *in, unsigned char *out);
int SM4ECBDecryptePadding7(const unsigned char *key, const unsigned char *in, unsigned char *out);

int ASCII2SM3(unsigned char *in, int len, unsigned char *out);

void show_array(const unsigned char *in, int len, const char *name);

int getStrings(const char *in, std::vector<std::string> &out);

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