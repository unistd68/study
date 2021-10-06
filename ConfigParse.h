
#ifndef __CONFIGPARSE_H__
#define __CONFIGPARSE_H__

#include "headers.h"

class Ini
{
public:
    explict Ini(const string ini_file);
    explict Ini(const char* ini_file);
    ~Ini();
    Ini() = delete;
    Ini(Ini &ini) = delete;
    string get(string path);
    string get(const char *parent,const char* child);
private:
    int _readAll(const char *configfile);
    int _getSection(const string &section,
                    std::vector<std::pair<std::string, std::string>> &results,
                    const char *configfile = nullptr) int errCode();

private:
    int _open(const string ini_file);

private:
    int err_code;
    boost::property_tree::ptree m_pt;
    std::map<std::string, std::map<std::string, std::string>> m_map4AllItems;
};

#endif