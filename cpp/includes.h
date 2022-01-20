/*
 * @Author: your name
 * @Date: 2021-11-01 10:17:18
 * @LastEditTime: 2022-01-19 02:17:58
 * @LastEditors: Ace
 * @Description: In User Settings Edit
 * @FilePath: \dubbo-goe:\other\vshare\test\includes.h
 */
#pragma once

#ifndef _INCLUDES_H_
#define _INCLUDES_H_

#ifdef __cplusplus
extern "C"
{
#endif

#include <unistd.h>
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <stdint.h>
#include <fcntl.h>

#ifdef __cplusplus
}
#endif

#include <iostream>
#include <string>
#include <uuid/uuid.h>
#include <algorithm>
#include <chrono>
#include <sstream>
#include <vector>

#include <mcheck.h>
#include <thread>
#include <memory>
#include <queue>
#include <functional>
#include <future>


enum CallType
{
    NAME,
    AGE,
    GRADE,
};

struct StCallBackMsg
{
	CallType _enCalltype;
	std::string _strSeq;
	std::string _strData;
};

#endif