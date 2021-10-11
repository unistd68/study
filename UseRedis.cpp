/*
 * @Author: your name
 * @Date: 2021-10-05 15:08:39
 * @LastEditTime: 2021-10-05 15:48:24
 * @LastEditors: Please set LastEditors
 * @Description: In User Settings Edit
 * @FilePath: \dubbo-goe:\code\study\UseRedis.cpp
 */
#include "UseRedis.h"

extern "C"
{
#include "hiredis/hiredis.h"
}

/***************************************************** RedisManager : public************************************************************************/

int redis_def::testRedis()
{
    redisContext *redis = redisConnect("127.0.0.1", 6379); // 用来连接redis数据库，参数为数据库的ip地址和端口，一般redis数据库的端口为6379。类似的函数有redisContext* redisConnectWithTimeout(const char *ip, int port, timeval tv)
    if (redis == NULL || redis->err)                       //当 redis->err 为真时，redis->errstr 显示具体的错误原因
    {
        std::cout << redis->errstr << '\n';
    }
    const char *command = "set test yes";
    redisReply *reply = (redisReply *)redisCommand(redis, command); // 返回值为void*，强制转换成为redisReply类型
    if (reply == NULL)
    {
        std::cout << "error" << '\n';
        redisFree(redis);
    }
    if (reply->type == REDIS_REPLY_STATUS) // REDIS_REPLY_STATUS 返回状态，可以用 strcasecmp(reply->str,"OK") 判断是否正确执行
    {
        std::cout << "redis reply is : " << reply->str << '\n';
    }
    std::cout << "test finish" << '\n';
    freeReplyObject(reply); // 释放 reply 占用的内存
    redisFree(redis);       // 断开连接
    return 0;
}

RedisManager::RedisManager(const char *ip, int port) : _ip(ip), _port(port)
{
    redisConnect();
    _genID();
}

RedisManager::RedisManager()
{
    this->_conn_status = redis_io_errorno::REDIS_CONNECT_OFFLINE;
    _genID();
}

RedisManager::~RedisManager()
{
    if (this->_redis != NULL)
    {
        redisFree(this->_redis);
        this->_redis = NULL;
        this->_conn_status = redis_io_errorno::REDIS_CONNECT_OFFLINE;
    }
    // 断开连接
}

redisContext *RedisManager::getRedisInstance()
{
    if (this->_redis == NULL)
    {
        _redisConnect();
    }
    return this->_redis;
}

std::string RedisManager::getID()
{
    return _id;
}

/***************************************************** RedisManager : private ************************************************************************/

int RedisManager::_redisConnect()
{
    if (this->_redis != NULL)
    {
        return redis_io_errorno::REDIS_OK;
    }
    this->_redis = redisConnect(this->_ip, this->_port); // 用来连接redis数据库，参数为数据库的ip地址和端口，一般redis数据库的端口为6379。类似的函数有redisContext* redisConnectWithTimeout(const char *ip, int port, timeval tv)
    if (this->_redis == NULL || this->_redis->err)       //当 redis->err 为真时，redis->errstr 显示具体的错误原因
    {
        std::cout << this->_redis->errstr << '\n';
        return redis_io_errorno::REDIS_CONNECT_FAIL;
    }
    this->_conn_status = redis_io_errorno::REDIS_CONNECT_ONLINE;
    return redis_io_errorno::REDIS_OK;
}

int RedisManager::_redisReConnect()
{
    if (this->_redis != NULL)
    {
        redisFree(this->_redis);
        this->_redis = NULL;
    }
    this->_redis = redisConnect(_ip, _port);       // 用来连接redis数据库，参数为数据库的ip地址和端口，一般redis数据库的端口为6379。类似的函数有redisContext* redisConnectWithTimeout(const char *ip, int port, timeval tv)
    if (this->_redis == NULL || this->_redis->err) //当 redis->err 为真时，redis->errstr 显示具体的错误原因
    {
        std::cout << this->_redis->errstr << '\n';
        return redis_io_errorno::REDIS_CONNECT_FAIL;
    }
    this->_conn_status = redis_io_errorno::REDIS_CONNECT_ONLINE;
    return redis_io_errorno::REDIS_OK;
}

int RedisManager::getConnStatus()
{
    _refreshConnStatus();
    return this->_conn_status;
}

int RedisManager::_refreshConnStatus()
{
    redisReply *reply = (redisReply *)redisCommand(this->_redis, "ping"); // 返回值为void*，强制转换成为redisReply类型
    if (reply == NULL)
    {
        std::cout << "error" << std "" endl;
        redisFree(this->_redis);
    }
    if (reply->type == REDIS_REPLY_STATUS) // REDIS_REPLY_STATUS 返回状态，可以用 strcasecmp(reply->str,"OK") 判断是否正确执行
    {
        //set ,multi set
        std::cout << "#REDIS_REPLY_STATUS# redis reply is : " << reply->str << '\n';
        if (strcasecmp(reply->str, "PONG") == OK)
        {
            // ping ok
            this->_conn_status = redis_io_errorno::REDIS_CONNECT_ONLINE;
            return redis_io_errorno::REDIS_OK;
        }
    }
    this->_conn_status = redis_io_errorno::REDIS_CONNECT_OFFLINE;
    return redis_io_errorno::REDIS_CONNECT_FAIL;
}

int RedisManager::_genID()
{
    std::string _timestamp = GetTimeStamp();
    std::string _rand_str = GetRandStr(5);
    this->_id = CONST_REDIS_PREFIX + _timestamp + _rand_str;
    return redis_io_errorno::REDIS_OK;
}

std::string RedisManager::sendMsg(std::string strSendMsg)
{
    //TODO:发送消息前是否有必要确认连接状态？（默认是不需要）
    redisReply *reply = (redisReply *)redisCommand(this->_redis, strSendMsg.c_str()); // 返回值为void*，强制转换成为redisReply类型
    if (reply == NULL)
    {
        std::cout << "error" << '\n';
        redisFree(this->_redis);
    }
    if (reply->type == REDIS_REPLY_STATUS) // REDIS_REPLY_STATUS 返回状态，可以用 strcasecmp(reply->str,"OK") 判断是否正确执行
    {
        //set ,multi set
        std::cout << "#REDIS_REPLY_STATUS# redis reply is : " << reply->str << '\n';
        if (strcasecmp(reply->str, "OK") == 0)
        {
            // send ok
        }
    }
    else if (reply->type == REDIS_REPLY_INTEGER) //
    {

        std::cout << "#REDIS_REPLY_INTEGER# redis reply is : " << reply->str << '\n';
    }
    else if (reply->type == REDIS_REPLY_DOUBLE) //
    {
        std::cout << "#REDIS_REPLY_DOUBLE# redis reply is : " << reply->str << '\n';
    }
    else if (reply->type == REDIS_REPLY_SET) //
    {
        std::cout << "#REDIS_REPLY_SET# redis reply is : " << reply->str << '\n';
    }
    else if (reply->type == REDIS_REPLY_PUSH) //
    {
        std::cout << "#REDIS_REPLY_PUSH# redis reply is : " << reply->str << '\n';
    }
    else if (reply->type == REDIS_REPLY_ATTR) //
    {
        std::cout << "#REDIS_REPLY_ATTR# redis reply is : " << reply->str << '\n';
    }
    else if (reply->type == REDIS_REPLY_ARRAY) //
    {
        // mget  ,对应multi set
        std::cout << "#REDIS_REPLY_ARRAY#" << std::endl;
        for (int i = 0; i < reply->elements; ++i)
        {
            std::cout << "#reply# element[" << i << "]:" << reply->element[i]->str << std::endl;
        }
    }
    else if (reply->type == REDIS_REPLY_STRING) //
    {
        // get
        std::cout << "#REDIS_REPLY_STRING# redis reply is : " << reply->str << '\n';
    }
    else if (reply->type == REDIS_REPLY_ERROR) //
    {
        std::cout << "#REDIS_REPLY_ERROR# redis reply is : " << reply->str << '\n';
    }
    else if (reply->type == REDIS_REPLY_NIL) // REDIS_REPLY_STATUS 返回状态，可以用 strcasecmp(reply->str,"OK") 判断是否正确执行
    {
        std::cout << "#REDIS_REPLY_NIL# redis reply is : " << reply->str << '\n';
    }
}

/***************************************************** RedisPool : public************************************************************************/

RedisPool::RedisPool() {}

RedisPool::~RedisPool()
{
    for (int i = 0; i < conn_num; ++i)
    {
        if (conn_pool[i] != NULL)
        {
            redisFree(conn_pool[i]);
            conn_pool[i] = NULL;
        }
    }
    delete[] conn_pool;

    if (conn_flag != NULL)
    {
        delete[] conn_flag;
        conn_flag = NULL;
    }
}

int RedisPool::initPool(const char *ip, int port, int num)
{
    this->_ip = ip;
    this->_port = port;
    this->_conn_num = num;

    for (int i = 0; i < num; i++)
    {
        RedisManager *_redisCli = new RedisManager(ip, port);
        this->_vpool_manager.emplace_back(_redisCli);
    }

    this->_empty_num = num;
    this->_work_conn = 0;

    return redis_io_errorno::REDIS_OK;
}

/***************************************************** RedisPool : private ************************************************************************/

RedisManager* RedisPool::_getConn(int &id)
{
    /*
    if (this->_empty_num == 0)
    {
        return NULL;
    }

    mtx.lock();

    while (conn_flag[this->_work_conn] != 0)
    {
        this->_work_conn = (this->_work_conn + 1) % conn_num;
    }

    conn_flag[this->_work_conn] = 1;
    --_empty_num;
    id = this->_work_conn;
    this->_work_conn = (this->_work_conn + 1) % conn_num;

    mtx.unlock();

    return conn_pool[id];
    */
}

void RedisPool::_setConn(int id)
{
    /*
    if (id < conn_num && id >= 0)
    {
        mtx.lock();

        conn_flag[id] = 0;
        ++empty_num;

        mtx.unlock();
    }
    */
    return;
}

std::string RedisPool::sendMsg(std::string msg)
{
    RedisManager* _redisCli = _getConn();
    return _redisCli->sendMsg(msg);
}