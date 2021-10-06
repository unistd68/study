
#ifndef __CONFIGPARSE_H__
#define __CONFIGPARSE_H__

#include "headers.h"

class Ini
{
public:
    explicit Ini(const string ini_file);
    explicit Ini(const char* ini_file);
    ~Ini();
    Ini() = delete;
    Ini(Ini &ini) = delete;
    std::string get(std::string path);
    std::string get(const char *parent,const char* child);
private:
    int _readAll(const char *configfile);
    int _getSection(const std::string &section,
                    std::vector<std::pair<std::string, std::string>> &results);
    int errCode();

private:
    int _open(const std::string ini_file);

private:
    int err_code;
    boost::property_tree::ptree m_pt;
    std::map<std::string, std::map<std::string, std::string>> m_map4AllItems;
};

#endif