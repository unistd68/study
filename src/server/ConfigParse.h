
#ifndef __CONFIGPARSE_H__
#define __CONFIGPARSE_H__

#include "../../includes/includes.h"



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
    Ini() ;
    Ini(Ini &ini) = delete;
    Ini& operator=(const Ini&) = delete;

public:
    std::string get(std::string path);
    std::string get(const char *parent,const char* child);
    void displayConfigs();
    int errCode();
    int setFilePath(const char* ini_file);

private:
    int _readAll();
    int _getSection(const std::string &section,
                    std::vector<std::pair<std::string, std::string>> &results);
    int _open();

private:
    int err_code;
    boost::property_tree::ptree m_pt;
    std::map<std::string, std::map<std::string, std::string>> m_map4AllItems;
    std::mutex _mtx;
    static Ini *_ini;
    std::string _ini_file;
};

#endif