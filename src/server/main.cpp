/*
 * @Author: your name
 * @Date: 2021-10-03 07:12:11
 * @LastEditTime: 2021-10-03 15:51:11
 * @LastEditors: your name
 * @Description: In User Settings Edit
 * @FilePath: \dubbo-goe:\code\study\main.cpp
 */

// #include "headers.h"
// 
// #include "UseRedis.h"
// #include "ErrorNO.h"
// #include "ConfigParse.h"

#include "HttpServer.hpp"

using namespace std;
using namespace boost;

ReaderWriterQueue<std::string> gQTCP(10000);

void commandHelp()
{
}

int initConfig(const char *file, StSConfig &stSConfig)
{
	Ini ini(file);
	ini.displayConfigs();
	// std::string host = ini.get("epoll_server","host");
	// std::string port = ini.get("epoll_server","port");
	// std::cout<<"host:"<<host<<std::endl;
	// std::cout<<"port:"<<port<<std::endl;
	for (auto &key : stSConfig._vKeyNames)
	{
		std::string strValue = ini.get(stSConfig._strSection.c_str(), (key).c_str());
		stSConfig._mConfigs.emplace(std::make_pair((key).c_str(), strValue.c_str()));
	}
	std::cout << "stConfig._mConfigs size:" << stSConfig._mConfigs.size() << std::endl;
	return OK;
}

int initTCPServ()
{
	StSConfig stConfig;
	stConfig._strSection = CONST_CONFIG_EPOLL;
	stConfig._vKeyNames.emplace_back(CONST_CONFIG_HOST);
	stConfig._vKeyNames.emplace_back(CONST_CONFIG_PORT);
	if (initConfig(CONST_CONFIG_FILE, stConfig) != OK)
	{
		std::cout << "initConfig fail" << std::endl;
		return file_io_errorno::FERROR_OPENFAIL;
	}
	unsigned short port = std::atoi((stConfig._mConfigs[CONST_CONFIG_PORT]).c_str());

	HttpServer *server = new HttpServer();

	if (!server->init_server(port))
	{
		cerr << "Failed in initializing server!" << endl;
		return -3;
	}

	server->start_serving();
	delete server;
	return 0;
}

int initRedisCLi()
{
	StSConfig stConfig;
	stConfig._strSection = CONST_CONFIG_REDIS;
	stConfig._vKeyNames.emplace_back(CONST_CONFIG_HOST);
	stConfig._vKeyNames.emplace_back(CONST_CONFIG_PORT);
	if (initConfig(CONST_CONFIG_FILE, stConfig) != OK)
	{
		std::cout << "initConfig fail" << std::endl;
		return file_io_errorno::FERROR_OPENFAIL;
	}
	std::string host = stConfig._mConfigs[CONST_CONFIG_HOST];
	int port = std::atoi((stConfig._mConfigs[CONST_CONFIG_PORT]).c_str());
	redisContext *redis = redisConnect(host, port); // 用来连接redis数据库，参数为数据库的ip地址和端口，一般redis数据库的端口为6379。类似的函数有redisContext* redisConnectWithTimeout(const char *ip, int port, timeval tv)
	if (redis == NULL || redis->err)				//当 redis->err 为真时，redis->errstr 显示具体的错误原因
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
	redisFree(redis);		// 断开连接
	return 0;
}

void test()
{
	redis_def::testRedis();
}

void testThreadPool()
{
	int main()
	{

		ThreadPool pool(4);
		std::vector<std::future<int>> results;

		for (int i = 0; i < 8; ++i)
		{
			results.emplace_back(
				pool.enqueue([i]
				{
					std::cout << "hello " << i << std::endl;
					std::this_thread::sleep_for(std::chrono::seconds(1));
					std::cout << "world " << i << std::endl;
					return i * i;
				}));
		}

		for (auto &&result : results)
			std::cout << result.get() << ' ';
		std::cout << std::endl;

		return 0;
	}
}

void testQ()
{
	ReaderWriterQueue<int> q(100); // Reserve space for at least 100 elements up front

	q.enqueue(17);						// Will allocate memory if the queue is full
	bool succeeded = q.try_enqueue(18); // Will only succeed if the queue has an empty slot (never allocates)
	assert(succeeded);
	cout << "queue:17,18" << endl;
	int number;
	succeeded = q.try_dequeue(number); // Returns false if the queue was empty

	assert(succeeded && number == 17);
	cout << "dequeue ,number:" << number << endl;
	int *front = q.peek();
	assert(*front == 18);
	cout << "front :" << *front << endl;
	succeeded = q.try_dequeue(number);
	assert(succeeded && number == 18);
	front = q.peek();
	assert(front == nullptr); // Returns nullptr if the queue was empty
	cout << "dequeue , numbner :" << number << endl;
}

int main(int argc, char *argv[])
{
	initRedisCLi();
	testThreadPool();
	initTCPServ();
	
	return 0;
}
