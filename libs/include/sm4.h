/*
 * @Author: your name
 * @Date: 2021-10-16 17:25:19
 * @LastEditTime: 2021-10-21 20:15:44
 * @LastEditors: Please set LastEditors
 * @Description: In User Settings Edit
 * @FilePath: \dubbo-goe:\code\study\sm4\sm4.h
 */
#pragma once
#ifndef _SM4_H_
#define _SM4_H_

#include "includes.h"


#define SM4_ENCRYPT 1
#define SM4_DECRYPT 0

/**
 * \brief          SM4 context structure
 */
typedef struct
{
    int mode;             /*!<  encrypt/decrypt   */
    unsigned long sk[32]; /*!<  SM4 subkeys       */
} sm4_context;

#ifdef __cplusplus
extern "C"
{
#endif

    /**
 * \brief          SM4 key schedule (128-bit, encryption)
 *
 * \param ctx      SM4 context to be initialized
 * \param key      16-byte secret key
 */
    void sm4_setkey_enc(sm4_context *ctx, unsigned char key[16]);

    /**
 * \brief          SM4 key schedule (128-bit, decryption)
 *
 * \param ctx      SM4 context to be initialized
 * \param key      16-byte secret key
 */
    void sm4_setkey_dec(sm4_context *ctx, unsigned char key[16]);

    /**
 * \brief          SM4-ECB block encryption/decryption
 * \param ctx      SM4 context
 * \param mode     SM4_ENCRYPT or SM4_DECRYPT
 * \param length   length of the input data
 * \param input    input block
 * \param output   output block
 */
    void sm4_crypt_ecb(sm4_context *ctx,
                       int mode,
                       int length,
                       unsigned char *input,
                       unsigned char *output);

    /**
 * \brief          SM4-CBC buffer encryption/decryption
 * \param ctx      SM4 context
 * \param mode     SM4_ENCRYPT or SM4_DECRYPT
 * \param length   length of the input data
 * \param iv       initialization vector (updated after use)
 * \param input    buffer holding the input data
 * \param output   buffer holding the output data
 */
    void sm4_crypt_cbc(sm4_context *ctx,
                       int mode,
                       int length,
                       unsigned char iv[16],
                       unsigned char *input,
                       unsigned char *output);

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

#ifdef __cplusplus
}
#endif

#endif