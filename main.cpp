/*
 * @Author: your name
 * @Date: 2021-10-03 07:12:11
 * @LastEditTime: 2021-10-03 15:51:11
 * @LastEditors: your name
 * @Description: In User Settings Edit
 * @FilePath: \dubbo-goe:\code\study\main.cpp
 */

#include "headers.h"
#include "HttpServer.hpp"
#include "UseRedis.h"
#include "ErrorNO.h"
#include "ConfigParse.h"

using namespace std;
using namespace boost;

void commandHelp()
{

}

int initConfig()
{
	Ini ini("serv.ini");
	std::string host = ini.get("epoll_server","host");
	std::string port = ini.get("epoll_server","port");
	std::cout<<"host:"<<host<<std::endl;
	std::cout<<"port:"<<port<<std::endl;
	return OK;
}

int initServ(int argc, char *argv[])
{
	unsigned short port = 8888;
	if (argc > 3)
	{
		std::cerr << "At most two arguments." << std::endl;
		return -1;
	}
	if (argc == 2)
		port = atoi(argv[1]);
	else if (argc == 3)
	{
		if (std::strcmp(argv[1], "--port") != 0)
		{
			std::cerr << "Unknown command \"" << argv[1] << "\"" << endl;
			return -2;
		}
		port = atoi(argv[2]);
	}
	
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

void test()
{
	redis_def::test();

}

int main()
{
	initConfig();
	return 0;
}
