/*
 * @Author: your name
 * @Date: 2021-10-14 08:44:36
 * @LastEditTime: 2021-10-26 16:31:16
 * @LastEditors: Please set LastEditors
 * @Description: In User Settings Edit
 * @FilePath: \文档c:\Users\msi\Desktop\fresher\vm_shared_data\test\sm4.h
 */
/**   
     * \file sm4.h   
     */
#ifndef _BASE_SM4_H
#define _BASE_SM4_H

#define SM4_ENCRYPT 1
#define SM4_DECRYPT 0

#define SM4_PADDING_PKCS7 1
#define SM4_PADDING_ZERO 0

#include "includes.h"
/**   
     * \brief          SM4 context structure   
     */
typedef struct
{
     int mode;             /*!<  encrypt/decrypt   */
     unsigned long sk[32]; /*!<  SM4 subkeys       */
     int padding_type;     /*!<  none/pkcs7/0   */
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
     int sm4_crypt_ecb_pkcs7(sm4_context *ctx,
                              int mode,
                              int length,
                              unsigned char *input,
                              unsigned char *output);
#ifdef __cplusplus
}
#endif

#endif /* sm4.h */