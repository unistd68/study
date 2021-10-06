
#ifndef __CONFIGPARSE_H__
#define __CONFIGPARSE_H__

#include "headers.h"

const std::string CONST_CONFIG_EPOLL = "epoll_server";
const std::string CONST_CONFIG_HOST = "host";
const std::string CONST_CONFIG_PORT = "port";

typedef struct ST_SECTION_CONFIG
{
    std::string _strSection;
    std::vector<std::string> _vKeyNames;
    std::map<std::string, std::string> _mConfigs;
}StSConfig;

class Ini
{
public:
    explicit Ini(const std::string ini_file);
    explicit Ini(const char* ini_file);
    ~Ini();
    Ini() = delete;
    Ini(Ini &ini) = delete;

public:
    std::string get(std::string path);
    std::string get(const char *parent,const char* child);
    void displayConfigs();
    int errCode();

private:
    int _readAll(const char *configfile);
    int _getSection(const std::string &section,
                    std::vector<std::pair<std::string, std::string>> &results);
    int _open(const std::string ini_file);

private:
    int err_code;
    boost::property_tree::ptree m_pt;
    std::map<std::string, std::map<std::string, std::string>> m_map4AllItems;
};

#endif