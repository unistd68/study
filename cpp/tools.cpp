#include "tools.h"
#include "md5.h"
#include "sm3.h"
#include "sm4.h"
// #include "base64.h"

void Get32UUIDFormat(char *str)
{
	char tmp[64] = {0};
	uuid_t uuid;
	uuid_generate(uuid);
	uuid_unparse(uuid, tmp);
	strcpy(str, tmp);
}

unsigned long long get_timestamp()
{
	time_t t;
	time(&t);
	return (unsigned long long)t;
}

/*c++ 利用chrono函数获取时间戳 毫秒级*/
std::string GetTimeStamp()
{
    auto timeNow = std::chrono::duration_cast<std::chrono::milliseconds>(std::chrono::system_clock::now().time_since_epoch());
    long long timestamp = timeNow.count();
    return std::to_string(timestamp);
}

void get_currtime_string(char *str_time) //获取格式化时间
{
	time_t now;
	struct tm *tm_now;
	char datetime[128];

	time(&now);
	tm_now = localtime(&now);
	strftime(datetime, 128, "%Y-%m-%d %H:%M:%S", tm_now);

	strcpy(str_time, datetime);
}

void timestamp2String(time_t t, char *str_time) //获取格式化时间
{
	char datetime[128];
	struct tm *tm_now;

	tm_now = localtime(&t);
	strftime(datetime, 128, "%Y-%m-%d %H:%M:%S", tm_now);

	strcpy(str_time, datetime);
}

/**
 * @description: 获取时间戳
 * @param {*}
 * @return 秒级时间戳
 */
// static int get_timestamp()
// {
//     time_t timep;
//     struct tm *p;
//     time(&timep); /*当前time_t类型UTC时间*/
//     //printf("time():%d\n",timep);
//     p = localtime(&timep); /*转换为本地的tm结构的时间按*/
//     timep = mktime(p);
//     return timep;

//     // time_t myt = time(NULL);
//     // time_t t;
//     // time(&t);
//     // return static_cast<int>(t.time);
// }

std::string GetRandStr(int len) /*参数为字符串的长度*/
{
    /*初始化*/
    //std::string str; /*声明用来保存随机字符串的str*/
    std::stringstream str;
    char c;  /*声明字符c，用来保存随机生成的字符*/
    int idx; /*用来循环的变量*/
    /*循环向字符串中添加随机生成的字符*/
    for (idx = 0; idx < len; idx++)
    {
        /*rand()%26是取余，余数为0~25加上'a',就是字母a~z,详见asc码表*/
        c = 'a' + rand() % 26;
        //str.emplace_back(c); /*push_back()是string类尾插函数。这里插入随机字符c*/
        str << c;
    }
    return str.str(); /*返回生成的随机字符串*/
}

/**
 * @description: 获取当前时间的字符串
 * @param {*}
 * @return {*}
 */
static std::string get_format_time_string() //获取格式化时间
{
    time_t now;
    struct tm *tm_now;
    char datetime[128];

    time(&now);
    tm_now = localtime(&now);
    strftime(datetime, 128, "%Y-%m-%d %H:%M:%S", tm_now);

    return datetime;
}

void char2Upper(const char *in, char *out)
{
	for (int i = 0; i < strlen(in); i++)
	{
		if (in[i] >= 'a' && in[i] <= 'z')
		{
			out[i] = in[i] - 'a' + 'A';
		}
		else
		{
			out[i] = in[i];
		}
	}
}

void char2Lower(const char *in, char *out)
{
	for (int i = 0; i < strlen(in); i++)
	{
		if (in[i] >= 'A' && in[i] <= 'Z')
		{
			out[i] = in[i] - 'A' + 'a';
		}
		else
		{
			out[i] = in[i];
		}
	}
}

/*************************************************
Function: 		string2hex
Description: 	将十进制转为hex(16进制)
Input: 			buf:十进制数组
        		buflen:数组长度
Output:			out: hex字符串
Return: 		字符串长度
Sample:        (in):{11, 12, 23, 4} (out):0b 0c 17 04
*************************************************/
int arrayToStr(unsigned char *in, unsigned int len, unsigned char *out)
{
	int index = 0;
	unsigned char strBuf[4096] = {0};
	char pbuf[16];
	int i, j;
	for (i = 0, j = i; i < len; i++, j += 2)
	{
		index += 2;
		sprintf(pbuf, "%02X", in[i]);
		strncat(strBuf + j, pbuf, 2);
	}
	strncpy(out, strBuf, len * 2);
	return index;
}

int ascii2HexChar(unsigned char *in, int len, unsigned char *out)
{
	unsigned char tmpOut[1024] = {0};
	int i = 0, j = 0;
	char alTmp[16] = {'0', '1', '2', '3', '4', '5', '6', '7', '8', '9', 'a', 'b', 'c', 'd', 'e', 'f'};

	for (i = 0, j = i; i < len; i++, j += 2)
	{

		tmpOut[j] = alTmp[in[i] / 16];
		tmpOut[j + 1] = alTmp[in[i] % 16];
	}
	len = j * 2;
	memcpy(out, tmpOut, len);
	return len / 2;
}

int hex2Array(unsigned char *in, int len, unsigned char *out)
{
	char *p = in;
	char high = 0, low = 0;
	int tmplen = len, cnt = 0;
	while (cnt < (tmplen / 2))
	{
		high = ((*p > '9') && ((*p <= 'F') || (*p <= 'f'))) ? *p - 48 - 7 : *p - 48;
		low = (*(++p) > '9' && ((*p <= 'F') || (*p <= 'f'))) ? *(p)-48 - 7 : *(p)-48;
		out[cnt] = ((high & 0x0f) << 4 | (low & 0x0f));
		p++;
		cnt++;
	}
	if (tmplen % 2 != 0)
		out[cnt] = ((*p > '9') && ((*p <= 'F') || (*p <= 'f'))) ? *p - 48 - 7 : *p - 48;

	return tmplen / 2 + tmplen % 2;
}

/*************************************************
Function: 		string2HexArray
Description: 	ascii字符串转16进制数组
Input: 			in:ascII字符串，如abcd1234
                len:ascII字符串的有效字符串长度
				big:hex字符串是否大写字母
Output: 		out:输出的hex字符串，如3132334d
Return: 		
Sample:         (in)data: 123M,(out):3132334d
*************************************************/
int ascii2HexArray(unsigned char *in, int in_len, unsigned char *out)
{
	unsigned char tmpOut[2048] = {0};
	int i = 0, j = 0;
	char alTmp[16] = {'0', '1', '2', '3', '4', '5', '6', '7', '8', '9', 'a', 'b', 'c', 'd', 'e', 'f'};

	for (i = 0, j = i; i < in_len; i++, j += 2)
	{

		tmpOut[j] = alTmp[in[i] / 16];
		tmpOut[j + 1] = alTmp[in[i] % 16];
	}

	char *p = tmpOut;
	char high = 0, low = 0;
	//int tmplen = out_len == 0 ? strlen(p) : out_len * 2, cnt = 0;
	int tmplen = in_len * 2, cnt = 0;
	while (cnt < (tmplen / 2)) //80
	{
		high = ((*p > '9') && ((*p <= 'F') || (*p <= 'f'))) ? *p - 48 - 7 : *p - 48;
		low = (*(++p) > '9' && ((*p <= 'F') || (*p <= 'f'))) ? *(p)-48 - 7 : *(p)-48;
		out[cnt] = ((high & 0x0f) << 4 | (low & 0x0f));
		p++;
		cnt++;
	}
	if (tmplen % 2 != 0)
		out[cnt] = ((*p > '9') && ((*p <= 'F') || (*p <= 'f'))) ? *p - 48 - 7 : *p - 48;

	return tmplen / 2 + tmplen % 2;
}

void show_array(const unsigned char *in, int len, const char *name)
{
	printf("%s:\n", name);
	for (int i = 0; i < len; i++)
	{
		printf("%02X ", in[i]);
	}
	printf("\n");
}

void hexArr2Ascii(unsigned char *in, int in_len, unsigned char *out)
{
	int new_len = 2 * in_len + 1;
	unsigned char *new_arr = (unsigned char *)malloc(new_len * sizeof(unsigned char));
	if (new_arr == NULL)
	{
		free(new_arr);
		return;
	}
	strncpy(new_arr, in, in_len);
	new_arr[in_len] = '\0';
	sprintf(out, "%s", new_arr);
	free(new_arr);
}

/*************************************************************************************/

int SM4ECBEncrypte(const unsigned char *key, const char *in, char *out)
{
	unsigned char arrKey[32] = {0};
	unsigned char arrInput[4096] = {0};
	unsigned char arrOnput[4096] = {0};
	sm4_context ctx;
	unsigned long i;
	int key_len = ascii2HexArray(key, strlen(key), arrKey);
	int in_len = ascii2HexArray(in, strlen(in), arrInput);
	sm4_setkey_enc(&ctx, arrKey);
	sm4_crypt_ecb(&ctx, SM4_ENCRYPT, in_len, arrInput, arrOnput);
	int line = in_len % 16 == 0 ? (in_len / 16) : (in_len / 16 + 1);
	int out_len = line * 16;
	in_len = arrayToStr(arrOnput, out_len, out);
	return in_len;
}

int SM4ECBDecrypte(const unsigned char *key, const char *in, char *out)
{
	unsigned char arrKey[32] = {0};
	unsigned char arrInput[4096] = {0};
	unsigned char arrOnput[4096] = {0};
	sm4_context ctx;
	unsigned long i;
	int len = ascii2HexArray(key, strlen(key), arrKey);
	len = hex2Array(in, strlen(in), arrInput);
	sm4_setkey_dec(&ctx, arrKey);
	sm4_crypt_ecb(&ctx, SM4_DECRYPT, len, arrInput, arrOnput);
	sprintf(out, "%s", arrOnput);
	return strlen(out);
}

int SM4ECBEncryptePadding7(const unsigned char *key, const unsigned char *in, unsigned char *out)
{
	unsigned char arrKey[32] = {0};
	unsigned char arrInput[4096] = {0};
	unsigned char arrOnput[4096] = {0};
	sm4_context ctx;
	ctx.padding_type = SM4_PADDING_PKCS7;
	unsigned long i;
	int key_len = ascii2HexArray(key, strlen(key), arrKey);
	int in_len = ascii2HexArray(in, strlen(in), arrInput);
	sm4_setkey_enc(&ctx, arrKey);
	sm4_crypt_ecb_pkcs7(&ctx, SM4_ENCRYPT, in_len, arrInput, arrOnput);
	int line = in_len % 16 == 0 ? (in_len / 16) : (in_len / 16 + 1);
	int out_len = line * 16;
	in_len = arrayToStr(arrOnput, out_len, out);
	return in_len;
}

int SM4ECBDecryptePadding7(const unsigned char *key, const unsigned char *in, unsigned char *out)
{
	unsigned char arrKey[32] = {0};
	unsigned char arrInput[4096] = {0};
	unsigned char arrOnput[4096] = {0};
	sm4_context ctx;
	ctx.padding_type = SM4_PADDING_PKCS7;
	unsigned long i;
	int len = ascii2HexArray(key, strlen(key), arrKey);
	len = hex2Array(in, strlen(in), arrInput);
	sm4_setkey_dec(&ctx, arrKey);
	len = sm4_crypt_ecb_pkcs7(&ctx, SM4_DECRYPT, len, arrInput, arrOnput);
	sprintf(out, "%s", arrOnput);
	return len;
}

int ASCII2SM3(unsigned char *in, int len, unsigned char *out)
{
    //printf("len: %d\n",len);
    unsigned char temp[1024] = {0};
    len = ascii2HexArray(in, len, temp);
    //printf("len: %d\n",len);
    uint8_t buf[1024];

    sm3_proc(temp, len, buf);
    //show_hex("in", temp, len);
    //show_hex("out", buf, 32);
    arrayToStr(buf,32,out);
    return 0;
    
}

int getStrings(const char* in,std::vector<std::string> &out)
{

	return 0;
}