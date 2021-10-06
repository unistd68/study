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

    int test() 
    {
        redisContext* redis = redisConnect("127.0.0.1", 6379);// 用来连接redis数据库，参数为数据库的ip地址和端口，一般redis数据库的端口为6379。类似的函数有redisContext* redisConnectWithTimeout(const char *ip, int port, timeval tv) 
        if( redis == NULL || redis->err ) //当 redis->err 为真时，redis->errstr 显示具体的错误原因
        {
            std::cout << redis->errstr << '\n';
        }
        const char * command = "set test yes";
        redisReply * reply = (redisReply*)redisCommand(redis, command); // 返回值为void*，强制转换成为redisReply类型
        if(reply == NULL)
        {
            std::cout << "error" << '\n';
            redisFree(redis);
        }
        if(reply->type == REDIS_REPLY_STATUS)// REDIS_REPLY_STATUS 返回状态，可以用 strcasecmp(reply->str,"OK") 判断是否正确执行
        {
            std::cout << "redis reply is : " << reply->str << '\n';
        }
        std::cout << "test finish" << '\n';
        freeReplyObject(reply); // 释放 reply 占用的内存
        redisFree(redis); // 断开连接
        return 0;
    }


}

#endif