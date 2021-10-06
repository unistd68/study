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

int initConfig(const char* file,StSConfig& stSConfig)
{
	Ini ini(file);
	ini.displayConfigs();
	// std::string host = ini.get("epoll_server","host");
	// std::string port = ini.get("epoll_server","port");
	// std::cout<<"host:"<<host<<std::endl;
	// std::cout<<"port:"<<port<<std::endl;
	for(auto& key : stSConfig._vKeyNames)
	{
		std::string strValue = ini.get(stSConfig._strSection.c_str(),(*key).c_str());
		stSConfig._mConfigs.emplace(std::make_pair((*key).c_str(),strValue.c_str()));
	}
	std::cout<<"stConfig._mConfigs size:"<<stSConfig._mConfigs.size()<<std::endl;
	return OK;
}

int initTCPServ(int argc, char *argv[])
{
	StSConfig stConfig;
	stConfig._strSection = CONST_CONFIG_EPOLL;
	stConfig._vKeyNames.emplace_back(CONST_CONFIG_HOST);
	stConfig._vKeyNames.emplace_back(CONST_CONFIG_PORT);
	if(initConfig("serv.ini",stConfig) != OK)
	{
		std::cout<<"initConfig fail" << std::endl;
		return file_io_errorno::FERROR_OPENFAIL;
	}
	unsigned short port = std::atoi((stConfig._mConfigs[CONST_CONFIG_PORT]).c_str());
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
	redis_def::testRedis();

}

int main(int argc, char *argv[])
{
	initTCPServ(argc,argv);
	return 0;
}
