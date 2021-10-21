/*
 * @Author: your name
 * @Date: 2021-10-21 20:02:36
 * @LastEditTime: 2021-10-21 21:36:52
 * @LastEditors: Please set LastEditors
 * @Description: In User Settings Edit
 * @FilePath: \dubbo-goe:\code\study\libs\include\sm3.h
 */
#pragma once
#ifndef _SM3_H_
#define _SM3_H_

#define SHL(x,n) (x<<n)
#define SHR(x,n) (x>>n)
#define ROTL(x,n) ((x<<n)|(x>>(32-n)))
#define ROTR(x,n) ((x>>n)|(x<<(32-n)))

#define P1(a,b,c,d,e) (P2((a)^(b)^ROTL((c),15))^ROTL((d),7)^e)
#define P2(a) ((a)^ROTL((a),15)^ROTL((a),23))
#define P3(a,b) ((a)^(b))
#define P4(a) ((a)^ROTL((a),9)^ROTL((a),17))
#define T1 (0x79cc4519)
#define T2 (0x7a879d8a)
#define FF1(a,b,c) ((a)^(b)^(c))
#define FF2(a,b,c) (((a)&(b))|((a)&(c))|((b)&(c)))
#define GG1(a,b,c) ((a)^(b)^(c))
#define GG2(a,b,c) (((a)&(b))|((~a)&(c)))
#define SS1(a,b,c,d) (ROTL((ROTL((a),12)+b+ROTL((c),(d))),7))
#define SS2(a,b,c,d) (SS1((a),(b),(c),(d))^ROTL((a),12))
#define TT1(e,f,g,a,b,c,d) ((e)+(f)+SS2(a,b,c,d)+(g))
#define TT2(e,f,g,a,b,c,d) ((e)+(f)+SS1(a,b,c,d)+(g))


int ASCII2SM3(unsigned char* in,int len,unsigned char* out);
int HEX2SM3(unsigned char* in,int len,unsigned char* out);


#endif