
#include "includes.h"
#include "tools.h"
#include "string_test.h"
#include "dp.h"

void test_uuid()
{
	char uuid[33] = {0};
	Get32UUIDFormat(uuid);
	printf("uuid:%s\n", uuid);
}

void test_time()
{
	unsigned long long curr_time = get_timestamp();
	char time_str[256] = {0};
	time_t time = (time_t)curr_time;
	timestamp2String(time, (char *)time_str);
	printf("time string: %s\n", time_str);
	printf("time stamp: %d\n", curr_time);
}

void testchar2Upper()
{
	char in[32] = {"## this is A ##"};
	char out[32] = {0};
	char2Upper(in, out);
	printf("in: %s\nout: %s\n", in, out);
}

void testchar2Lower()
{
	char in[32] = {"## THIS IS a ##"};
	char out[32] = {0};
	char2Lower(in, out);
	printf("in: %s\nout: %s\n", in, out);
}

void test_sm3(const char *in)
{
	unsigned char out[2048] = {0};
	ASCII2SM3(in, strlen(in), out);
	printf("sm3 in: %s\n", in);
	printf("sm3 out: %s\n", out);
}
void test_SM4ECBEncrypte(const char *key, const char *in)
{
	char out[4096] = {0};
	int len = SM4ECBEncrypte(key, in, out);
	if (len != strlen(out))
	{
		printf(" ### ERROR ### \n");
		printf("output len: %d,return : %d\n", strlen(out), len);
		printf("out : %s\n", out);
		return;
	}
	printf("key: %s\n", key);
	printf("input: %s\n", in);
	printf("output: %s\n", out);
}
void test_SM4ECBDecrypte(const char *key, const char *in)
{
	char out[4096] = {0};
	int len = SM4ECBDecrypte(key, in, out);
	if (len != strlen(out))
	{
		printf(" ### ERROR ### \n");
		printf("output len: %d,return : %d\n", strlen(out), len);
		printf("out : %s\n", out);
		return;
	}
	printf("key: %s\n", key);
	printf("input: %s\n", in);
	printf("output: %s\n", out);
}
void test_SM4ECBEncryptePadding7(const char *key, const char *in)
{
	char out[4096] = {0};
	int len = SM4ECBEncryptePadding7(key, in, out);
	if (len != strlen(out))
	{
		printf(" ### ERROR ### \n");
		printf("output len: %d,return : %d\n", strlen(out), len);
		printf("out : %s\n", out);
		return;
	}
	printf("key: %s\n", key);
	printf("input: %s\n", in);
	printf("output: %s\n", out);
}
void test_SM4ECBDecryptePadding7(const char *key, const char *in)
{
	char out[4096] = {0};
	int len = SM4ECBDecryptePadding7(key, in, out);
	if (len != strlen(out))
	{
		printf(" ### ERROR ### \n");
		printf("output len: %d,return : %d\n", strlen(out), len);
		printf("out : %s\n", out);
		return;
	}
	printf("key: %s\n", key);
	printf("input: %s\n", in);
	printf("output: %s\n", out);
}

/**
 * @description: 中心扩展法获取最长回文子串
 * @param {int} argc
 * @param {char} *argv
 * @return {*}
 */
void test_strings(int argc, char *argv[])
{
	//printf("argc:%d,argv:%s\n",argc,argv[1]);
	if (argc != 2)
	{
		return;
	}
	const char *in = argv[1];
	char *out = (char *)malloc(1024 * sizeof(char));
	if (out == NULL)
	{
		printf("malloc fail");
		return;
	}
	memset(out, 0, 1024);
	int ret = longestPalindromeString(in, out);
	if (ret == 0)
	{
		printf("in:%s\n", in);
		printf("out:%s\n", out);
	}
	free(out);
	out = NULL;
}

/**
 * @description: 队列、递归获取电话号码的所有字符串组合,主要思想：回溯
 * @param {int} argc
 * @param {char} *argv
 * @return {*}
 */
void test_digits(int argc, char *argv[])
{
	if (argc != 3)
	{
		return;
	}
	const char *in = argv[2];
	int op = atoi(argv[1]);
	std::vector<std::string> res;
	if (op == 1)
	{
		queue_digit qd;
		res = qd.letterCombinations(in);
	}
	else if (op == 2)
	{
		backtrat_digits bd;
		res = bd.letterCombinations(in);
	}
	for (int i = 0; i < res.size(); i++)
	{
		std::cout << " " << res[i];
	}
	std::cout << std::endl;
}

void test_sumofnums(int argc, char *argv[])
{
	// ./test N target
	if (argc != 3)
	{
		return;
	}
	//const char *in = argv[2];
	int N = atoi(argv[1]);
	int target = atoi(argv[2]);
	std::vector<std::vector<int>> res;
	std::vector<int> v = {9, 8, 7, 6, 5, 4, 3, 2, 1, 0, -3, -2, -1};
	SumOfNums son;
	res = son.fourSum(v, N, target);
	for (int i = 0; i < res.size(); i++)
	{
		//std::cout <<"i:" << i << std::endl;
		std::cout << "[";
		for (int j = 0; j < res[i].size(); j++)
		{
			std::cout << " " << res[i][j] << " ";
		}
		std::cout << "] ";
	}
	std::cout << std::endl;
}

void test_dp(char *in)
{
	int N = atoi(in);
	testCakePrice(N);
}

void show_help()
{
	printf("####################################################\n");
	printf("################### Usage ##########################\n");
	printf("#### 0.  ./test 0 : 退出\n");
	printf("#### 1.  ./test 1 abcdefg :获取sm3摘要\n");
	printf("#### 2.  ./test 2 key string :使用sm4的ecb模式,以0填充的加密密文\n");
	printf("#### 3.  ./test 3 key string :使用sm4的ecb模式,以0填充的解密明文\n");
	printf("#### 4.  ./test 4 key string :使用sm4的ecb模式,以pkcs7填充的加密密文\n");
	printf("#### 5.  ./test 5 key string :使用sm4的ecb模式,以pkcs7填充的解密明文\n");
	printf("#### 6.  ./test 6 data : 动态规划测试\n");
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
	else if (argc == 4 && strcmp(argv[1], "3") == 0)
	{
		printf("################# SM4算法ECB模式解密 开始 ############################ \n");
		test_SM4ECBDecrypte(argv[2], argv[3]);
		printf("################# SM4算法ECB模式解密 结束 ############################ \n");
	}
	else if (argc == 4 && strcmp(argv[1], "4") == 0)
	{
		printf("################# SM4算法ECB模式Padding7加密 开始 ############################ \n");
		test_SM4ECBEncryptePadding7(argv[2], argv[3]);
		printf("################# SM4算法ECB模式Padding7加密 结束 ############################ \n");
	}
	else if (argc == 4 && strcmp(argv[1], "5") == 0)
	{
		printf("################# SM4算法ECB模式Padding7解密 开始 ############################ \n");
		test_SM4ECBDecryptePadding7(argv[2], argv[3]);
		printf("################# SM4算法ECB模式Padding7解密 结束 ############################ \n");
	}
	else if (argc == 3 && strcmp(argv[1], "6") == 0)
	{
		printf("################# 动态规划算法测试 开始 ############################ \n");
		test_dp(argv[2]);
		printf("################# 动态规划算法测试 结束 ############################ \n");
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
