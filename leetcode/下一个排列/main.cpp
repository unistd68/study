/*
 * @Author: your name
 * @Date: 2021-11-17 11:55:06
 * @LastEditTime: 2021-11-17 12:20:06
 * @LastEditors: Please set LastEditors
 * @Description: 打开koroFileHeader查看配置 进行设置: https://github.com/OBKoro1/koro1FileHeader/wiki/%E9%85%8D%E7%BD%AE
 * @FilePath: \dubbo-goe:\other\vshare\test\leetcode\下一个排列\main.cpp
 */

#include "includes.h"
#include "tools.h"
#include "algorithm.h"

void catTopic()
{

}


void catTestCase()
{

}

void test()
{

}

void show_help()
{
	printf("####################################################\n");
	printf("################### Usage ##########################\n");
	printf("#### 0.  ./test 0 : 退出\n");
	printf("#### 1.  ./test 1 : 查看题目\n");
	printf("#### 2.  ./test 2 : 查看测试用例\n");
	printf("#### 3.  ./test 3 : 开始测试\n");
	printf("####################################################\n");
}

void do_something(int argc, char *argv[])
{
	if (argc == 3 && strcmp(argv[1], "1") == 0)
	{
		printf("################# 获取sm3摘要 开始 ############################ \n");
		test_sm3(argv[2]);
		printf("################# 获取sm3摘要 结束 ############################ \n");
	}
	else if (argc == 4 && strcmp(argv[1], "2") == 0)
	{
		printf("################# SM4算法ECB模式加密 开始 ############################ \n");
		test_SM4ECBEncrypte(argv[2], argv[3]);
		printf("################# SM4算法ECB模式加密 结束 ############################ \n");
	}
	
	else
	{
		show_help();
	}
}



int main(int argc, char *argv[])
{
	do_something(argc, argv);
	return 0;
}

