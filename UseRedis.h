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
    enum connection_type
    {
        CONN_TCP,
        CONN_UNIX,
        CONN_FD,
        CONN_SSL
    };

    struct config
    {
        enum connection_type type;

        struct
        {
            const char *host;
            int port;
            struct timeval timeout;
        } tcp;

        struct
        {
            const char *path;
        } unix_sock;

        struct
        {
            const char *host;
            int port;
            const char *ca_cert;
            const char *cert;
            const char *key;
        } ssl;
    };

    int testRedis();

    class RedisManager
    {
    public:
        explicit RedisManager(const char *ip, int port);
        RedisManager();
        RedisManager(redisContext *redis) = delete;
        RedisManager(redisContext &redis) = delete;
        virtual ~RedisManager();

    public:
        int getConnStatus();
        std::string getID();
        std::string sendMsg(std::string msg);

    private:
        redisContext *getRedisInstance();
        int _redisConnect();
        int _redisReConnect();
        int _refreshConnStatus();

    private:
        redisContext *_redis;
        std::string _ip;
        int _port;
        int _conn_status;
        std::string _id;
    }

    class RedisPool
    {

    public:
        RedisPool();
        ~RedisPool();
        int initPool(std::string ip_, int port_, int conn_num_);
        RedisManager *_getConn(int &id);
        void _setConn(int id);
        std::string sendMsg(std::string msg);

    private:
        std::string _ip;
        int _port;
        int _conn_num;

        RedisPool **conn_pool;
        std::vector<RedisManager*> _vpool_manager;
        int *conn_flag;
        int _empty_num;
        int _work_conn;

        std::mutex mtx;
    };
}
#endif