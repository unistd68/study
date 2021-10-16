/*
 * @Author: your name
 * @Date: 2021-10-16 17:30:31
 * @LastEditTime: 2021-10-16 17:41:43
 * @LastEditors: Please set LastEditors
 * @Description: In User Settings Edit
 * @FilePath: \dubbo-goe:\code\study\includes\includes.h
 */

#pragma once
#ifndef _INCLUDES_H_
#define _INCLUDES_H_

#include <iostream>
#include <map>
#include <vector>
#include <string>
#include <queue>
#include <chrono>
#include <mutex>
#include <fstream>

// #ifdef __cplusplus
// extern "C"
// {
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <strings.h>
#include <sys/time.h>
#include <assert.h>
#include <signal.h>
#include <errno.h>
#include <limits.h>
#include <atomicops.h>
#include <time.h>
#include <sys/types.h>
#include <sys/socket.h>
#include <unistd.h>
#include <arpa/inet.h>
#include <fcntl.h>
#include <sys/epoll.h>
// }
// #endif

#include <readerwriterqueue.h>

//boost
#include <boost/foreach.hpp>
#include <boost/property_tree/ptree.hpp>
#include <boost/property_tree/ini_parser.hpp>

#include <atomic>
#include <future>
#include <stdexcept>

// redis
// #ifdef _USE_REDIS_
//#include "hiredis_ssl.h"
#include "hiredis/hiredis.h"
// #endif

#include "../common/ErrorNO.h"
#include "../common/define.h"

//#include "../tools/tools.h"
//#include "ThreadPool.h"

using namespace moodycamel;

#endif