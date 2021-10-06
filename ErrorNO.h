#ifndef __HEADERS_H__
#define __HEADERS_H__

const int OK = 0;

namespace input_com_help
{
    const int COMTYPE_ALL = 0;
}


namespace file_io_errorno
{
    const int FERROR_OK = 0;
    const int FERROR_OPENFAIL = -1;  // 打开文件失败
    const int FERROR_GETSECTIONFAIL = -2; //获取节点失败

}

#endif