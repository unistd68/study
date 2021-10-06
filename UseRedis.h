/*
 * @Author: your name
 * @Date: 2021-10-05 15:08:18
 * @LastEditTime: 2021-10-05 15:52:50
 * @LastEditors: Please set LastEditors
 * @Description: In User Settings Edit
 * @FilePath: \dubbo-goe:\code\study\UseRedis.h
 */
#ifndef __USEREDIS_H__
#define __USEREDIS_H__

#include "headers.h"

namespace redis_def
{
    enum connection_type {
        CONN_TCP,
        CONN_UNIX,
        CONN_FD,
        CONN_SSL
    };

    struct config {
        enum connection_type type;

        struct {
            const char *host;
            int port;
            struct timeval timeout;
        } tcp; 

        struct {
            const char *path;
        } unix_sock;

        struct {
            const char *host;
            int port;
            const char *ca_cert;
            const char *cert;
            const char *key;
        } ssl; 
    };

    int testRedis() ;


}

#endif