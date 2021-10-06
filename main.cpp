/*
 * @Author: your name
 * @Date: 2021-10-03 07:12:11
 * @LastEditTime: 2021-10-03 15:51:11
 * @LastEditors: your name
 * @Description: In User Settings Edit
 * @FilePath: \dubbo-goe:\code\study\main.cpp
 */
#include "HttpServer.hpp"
#include "UseRedis.h"
#include "headers.h"
#include "ErrorNO.h"
#include "ConfigParse.h"

using namespace std;

void commandHelp()
{

}

int initConfig()
{
	Ini ini("serv.ini");
	string host = ini.get("epoll_server","host");
	string port = ini.get("epoll_server","port");
	cout<<"host:"<<host<<endl;
	cout<<"port:"<<port<<endl;

}

void initServ(int argc, char *argv[])
{
	unsigned short port = 8888;
	if (argc > 3)
	{
		cerr << "At most two arguments." << endl;
		return -1;
	}
	if (argc == 2)
		port = atoi(argv[1]);
	else if (argc == 3)
	{
		if (strcmp(argv[1], "--port") != 0)
		{
			cerr << "Unknown command \"" << argv[1] << "\"" << endl;
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
}

void test(int argc, char *argv[])
{
	redis_def::test();

}

int main(int argc, char *argv[])
{
	//test(argc,**argv);
	initConfig();
	return 0;
}
