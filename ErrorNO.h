#ifndef __ErrorNO_H__
#define __ErrorNO_H__

#include <iostream>
#include <string>

const int OK = 0;

namespace input_com_help
{
    const int COMTYPE_UNKNOWN = -1;
    const int COMTYPE_DEFAULT = 0;

    const std::string COMTYPE_UNKNOWN_MSG = "#COMMAND# unknown command";
    const std::string COMTYPE_DEFAULT_MSG = "#COMMAND# defaul command";
}

namespace file_io_errorno
{
    const int FERROR_OK = 0;
    const int FERROR_OPENFAIL = -1;       // 打开文件失败
    const int FERROR_GETSECTIONFAIL = -2; //获取节点失败
    const int FERROR_NULLFILE = -3;

    const std::string FERROR_OK_MSG = "#FILEIO# ok";
    const std::string FERROR_OPENFAIL_MSG = "#FILEIO# fail";
    const std::string FERROR_GETSECTIONFAIL_MSG = "#FILEIO# get section fail";
    const std::string FERROR_NULLFILE_MSG = "#FILEIO# empty file";

}

namespace redis_io_errorno
{
    //CONNECT STATUS
    const int REDIS_CONNECT_ONLINE = 0;
    const int REDIS_CONNECT_OFFLINE = -1;

    const std::string REDIS_CONNECT_ONLINE_MSG = "#REDIS# conn online";
    const std::string REDIS_CONNECT_OFFLINE_MSG = "#REDIS# conn offline";


    //RETURN RESULT
    const int REDIS_OK = 0;
    const int REDIS_CONNECT_FAIL = -1;
    const int REDIS_SEND_FAIL = -2;

    const std::string REDIS_OK_MSG = "#REDIS# ok";
    const std::string REDIS_CONNECT_FAIL_MSG = "#REDIS# connect server fail";
    const std::string REDIS_SEND_FAIL_MSG = "#REDIS# send msg fail";

}

#endif