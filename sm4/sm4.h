/*
 * @Author: your name
 * @Date: 2021-10-16 17:25:19
 * @LastEditTime: 2021-10-16 17:44:16
 * @LastEditors: Please set LastEditors
 * @Description: In User Settings Edit
 * @FilePath: \dubbo-goe:\code\study\sm4\sm4.h
 */
#pragma once
#ifndef _SM4_H_
#define _SM4_H_

#include "../includes/includes.h"
#include "../tools/tools.h"
/**
 * @description: ascii字符串加密为ascii字符串
 * @param {char} *key
 * @param {char} *in
 * @param {char} *out
 * @return {*}
 */
int SM4Decrypto(const char *key, const char *in, char *out);

/**
 * @description: hex字符串解密为ascii字符串
 * @param {char} *key
 * @param {char} *in
 * @param {char} *out
 * @return {*}
 */
int SM4Encrypto(const char *key, const char *in, char *out);

#endif