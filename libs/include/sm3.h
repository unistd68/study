/*
 * @Author: your name
 * @Date: 2021-10-21 20:02:36
 * @LastEditTime: 2021-10-21 23:42:34
 * @LastEditors: Please set LastEditors
 * @Description: In User Settings Edit
 * @FilePath: \dubbo-goe:\code\study\libs\include\sm3.h
 */
#pragma once
#ifndef _BASE_SM3_H_
#define _BASE_SM3_H_
#include "includes.h"
/**
 * desc          Output = SM3( input buffer )
 *
 * param input    buffer holding the  data
 * param ilen     length of the input data
 * param output   SM3 checksum result
 */
void sm3_proc(uint8_t *input, int32_t ilen, uint8_t *output);

/**
 * desc          Output = HMAC-SM3( hmac key, input buffer )
 *
 * param key      HMAC secret key
 * param keylen   length of the HMAC key
 * param input    buffer holding the  data
 * param ilen     length of the input data
 * param output   HMAC-SM3 result, 32bytes
 */
void sm3_hmac(uint8_t *key, int32_t keylen, uint8_t *input, int32_t ilen, uint8_t *output);

int ASCII2SM3(unsigned char *in, int len, unsigned char *out);
int HEX2SM3(unsigned char *in, int len, unsigned char *out);

#endif