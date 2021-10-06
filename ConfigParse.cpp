#include "ConfigParse.h"


Ini::Ini(string ini_file)
{
    if (access(ini_file.c_str(), 0) == OK)
    {
        this->err_code = file_io_errorno::FERROR_OK;
        _open(ini_file);
    }
    else
    {
        this->err_code = file_io_errorno::FERROR_OPENFAIL;
    }
}


Ini::Ini(const char* ini_file)
{
    if (access(ini_file, 0) == OK)
    {
        this->err_code = file_io_errorno::FERROR_OK;
        this->err_code = _readAll(ini_file);
    }
    else
    {
        this->err_code = file_io_errorno::FERROR_OPENFAIL;
    }
}

Ini::~Ini() {}

int Ini::_open(const string ini_file)
{
    if (ini_file.empty())
    {
        this->err_code = file_io_errorno::FERROR_OPENFAIL;
        return file_io_errorno::FERROR_OPENFAIL;
    }
    try
    {
        boost::property_tree::ini_parser::read_ini(ini_file, this->m_pt);
    }
    catch (std::exception &e)
    {
        this->err_code = file_io_errorno::FERROR_OPENFAIL;
        return file_io_errorno::FERROR_OPENFAIL;
    }

    this->err_code = file_io_errorno::FERROR_OK;
}

Ini::errCode()
{
    return this->err_code;
}

string Ini::get(string path)
{
    if (this->err_code == file_io_errorno::FERROR_OK)
    {
        return this->m_pt.get<string>(path);
    }
    else
    {
        return "";
    }
}

int Ini::_readAll(const char *configfile)
{
    std::vector<std::string> vSectionNameLists;
    foreach (auto &section, m_pt)
    {
        std::string strSectionName = section.first;
        vSectionNameLists.emplace_back(strSectionName);
    }

    std::vector<std::string>::iterator itSectionName = vSectionNameLists.begin();
    for (; itSectionName != vSectionNameLists.end(); itSectionName++)
    {
        std::map<std::string, std::string> mapSection;
        std::vector<std::pair<std::string, std::string>> results;

        if (_getSection(itSectionName, results, configfile) != 0)
        {
            return file_io_errorno::FERROR_GETSECTIONFAIL;
        }

        foreach (auto &key, results)
        {
            mapSection.emplace(key);
        }
        m_map4AllItems.emplace(std::make_pair<std::string, std::map<std::string, std::string>>(*itSectionName, mapSection));
    }

    return file_io_errorno::FERROR_OK;
}

int Ini::_getSection(const string &section,
                     std::vector<std::pair<std::string, std::string>> &results,
                     const char *configfile = nullptr)
{
    if (configfile != nullptr && open(configfile) != 0)
    {
        return file_io_errorno::FERROR_OPENFAIL;
    }

    try
    {
        auto lvbtItems = this->m_pt.get_child(section.c_str());

        foreach (auto &i, lvbtItems)
        {
            results.push_back(std::make_pair(i.first.data(), i.second.data()));
        }
    }
    catch (std::exception &e)
    {
        return file_io_errorno::FERROR_GETSECTIONFAIL;
    }

    return file_io_errorno::FERROR_OK;
}


string Ini::get(const char *parent,const char* child)
{
    if (this->err_code == file_io_errorno::OK)
    {
        auto _retParent = m_map4AllItems.find(parent);
        if(_retParent == m_map4AllItems.end())
        {
            return "";
        }
        std::map<std::string, std::string> mChilds = *_retParent;

        auto _retChild = mChilds.find(child);
        if(_retChild == mChilds.end())
        {
            return "";
        }
        return *_retChild->second;
    }
    else
    {
        return "";
    }
}