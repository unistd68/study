/*
 * @Author: AntiFun
 * @Date: 2021-10-05 14:59:20
 * @LastEditTime: 2021-10-05 15:05:44
 * @LastEditors: Please set LastEditors
 * @Description: A headers included manager
 * @FilePath: \dubbo-goe:\code\study\headers.h
 */
#ifndef __HEADERS_H__
#define __HEADERS_H__
#include <iostream>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <strings.h>
#include <sys/time.h>
#include <assert.h>
#include <signal.h>
#include <errno.h>
#include <limits.h>
#include <boost/property_tree/ptree.hpp>
#include <boost/property_tree/ini_parser.hpp>


#include <vector>
#include <map>




// #ifdef _USE_REDIS_
#include "hiredis.h"
#include "hiredis_ssl.h"
#include "hiredis/hiredis.h" 
// #endif


#include "ErrorNO.h"

#include "HttpServer.hpp"
#include "UseRedis.h"
#include "ErrorNO.h"
#include "ConfigParse.h"


#endif