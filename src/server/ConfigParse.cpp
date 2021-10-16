#include "ConfigParse.h"

Ini::Ini(std::string ini_file) : _ini_file(ini_file)
{
    if (access(ini_file.c_str(), 0) == OK)
    {
        this->err_code = file_io_errorno::FERROR_OK;
        this->err_code = _open(_ini_file);
        this->err_code = _readAll(_ini_file);
    }
    else
    {
        this->err_code = file_io_errorno::FERROR_OPENFAIL;
    }
}

Ini::Ini(const char *ini_file) : _ini_file(ini_file)
{
    if (access(_ini_file, 0) == OK)
    {
        this->err_code = file_io_errorno::FERROR_OK;
        this->err_code = _open(_ini_file);
        this->err_code = _readAll(_ini_file);
    }
    else
    {
        this->err_code = file_io_errorno::FERROR_OPENFAIL;
    }
}

Ini::Ini()
{
    if (_ini_file.empty())
    {
        this->err_code = file_io_errorno::FERROR_NULLFILE;
    }
}

Ini::~Ini()
{
}

int Ini::_open()
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
    return file_io_errorno::FERROR_OK;
}

int Ini::_readAll()
{
    std::cout << "configfile:" << configfile << std::endl;
    std::vector<std::string> vSectionNameLists;
    BOOST_FOREACH (auto &section, m_pt)
    {
        std::string strSectionName = section.first;
        vSectionNameLists.emplace_back(strSectionName);
    }

    std::vector<std::string>::iterator itSectionName = vSectionNameLists.begin();
    for (; itSectionName != vSectionNameLists.end(); itSectionName++)
    {
        std::map<std::string, std::string> mapSection;
        std::vector<std::pair<std::string, std::string>> results;
        std::string sectionName = *itSectionName;
        if (_getSection(sectionName, results) != OK)
        {
            std::cout << "_getSection fail" << std::endl;
            return file_io_errorno::FERROR_GETSECTIONFAIL;
        }
        //std::map<std::string, std::map<std::string, std::string>> m_map4AllItems;
        BOOST_FOREACH (auto &key, results)
        {
            mapSection.emplace(key);
        }
        //m_map4AllItems.emplace(std::make_pair<std::string, std::map<std::string, std::string>>(*itSectionName, mapSection));
        //std::string sectionName = *itSectionName;
        m_map4AllItems.emplace(sectionName, mapSection);
    }

    return file_io_errorno::FERROR_OK;
}

int Ini::_getSection(const std::string &section, std::vector<std::pair<std::string, std::string>> &results)
{

    try
    {
        auto lvbtItems = this->m_pt.get_child(section.c_str());

        BOOST_FOREACH (auto &i, lvbtItems)
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

void Ini::displayConfigs()
{
    std::cout << "sections nums:" << this->m_map4AllItems.size() << std::endl;
    auto itSectionName = this->m_map4AllItems.begin();
    for (; itSectionName != this->m_map4AllItems.end(); itSectionName++)
    {
        for (auto &child : itSectionName->second)
        {
            std::cout << "sections name:" << itSectionName->first << ",child key:" << child.first << ",child value:" << child.second << std::endl;
        }
    }
}

int Ini::setFilePath(const char *ini_file)
{
    if (access(ini_file, 0) == OK)
    {
        this->_ini_file = ini_file;
        this->err_code = _open(_ini_file);
        this->err_code = _readAll(_ini_file);
    }
    else
    {
        this->err_code = file_io_errorno::FERROR_OPENFAIL;
    }
    return this->err_code;
}

std::string Ini::get(std::string path)
{
    if (this->err_code == file_io_errorno::FERROR_OK && !path.empty() && !(this->__ini_file.empty()))
    {
        return this->m_pt.get<std::string>(path);
    }
    else
    {
        return "";
    }
}

std::string Ini::get(const char *parent, const char *child)
{
    if (this->err_code == file_io_errorno::FERROR_OK)
    {
        auto _retParent = this->m_map4AllItems.find(parent);
        if (_retParent == this->m_map4AllItems.end())
        {
            std::cout << "find parent fail" << std::endl;
            return "";
        }
        std::map<std::string, std::string> mChilds = _retParent->second;

        auto _retChild = mChilds.find(child);
        if (_retChild == mChilds.end())
        {
            std::cout << "find child fail" << std::endl;
            return "";
        }
        return _retChild->second;
    }
    else
    {
        return "";
    }
}

int Ini::errCode()
{
    return this->err_code;
}
