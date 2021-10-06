#include "ConfigParse.h"


Ini::Ini(std::string ini_file)
{
    std::cout<<"Ini(std::string ini_file) "<<std::endl;
    if (access(ini_file.c_str(), 0) == OK)
    {
        this->err_code = file_io_errorno::FERROR_OK;
        this->err_code = _open(ini_file);
        std::cout<<"this->err_code: "<<this->err_code<<std::endl;
    }
    else
    {
        this->err_code = file_io_errorno::FERROR_OPENFAIL;
    }
}


Ini::Ini(const char* ini_file)
{
    std::cout<<"Ini(const char* ini_file) "<<std::endl;
    if (access(ini_file, 0) == OK)
    {
        this->err_code = file_io_errorno::FERROR_OK;
        this->err_code = _open(ini_file);
        this->err_code = _readAll(ini_file);
        std::cout<<"this->err_code: "<<this->err_code<<std::endl;
    }
    else
    {
        this->err_code = file_io_errorno::FERROR_OPENFAIL;
    }
}

Ini::~Ini() {}

int Ini::_open(const std::string ini_file)
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

int Ini::errCode()
{
    return this->err_code;
}

std::string Ini::get(std::string path)
{
    if (this->err_code == file_io_errorno::FERROR_OK)
    {
        return this->m_pt.get<std::string>(path);
    }
    else
    {
        return "";
    }
}

int Ini::_readAll(const char *configfile)
{
    std::cout<<"configfile:"<<configfile<<std::endl;
    std::vector<std::string> vSectionNameLists;
    BOOST_FOREACH(auto &section , m_pt)
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
            std::cout<<"_getSection fail"<<std::endl;
            return file_io_errorno::FERROR_GETSECTIONFAIL;
        }
        std::map<std::string, std::map<std::string, std::string>> m_map4AllItems;
        BOOST_FOREACH(auto &key , results)
        {
            std::cout<<"BOOST_FOREACH ,key:"<<key.first<<",value:"<<key.second<<std::endl;
            mapSection.emplace(key);
        }
        //m_map4AllItems.emplace(std::make_pair<std::string, std::map<std::string, std::string>>(*itSectionName, mapSection));
        //std::string sectionName = *itSectionName;
        m_map4AllItems.emplace(sectionName, mapSection);
    }

    return file_io_errorno::FERROR_OK;
}

int Ini::_getSection(const std::string &section,
                     std::vector<std::pair<std::string, std::string>> &results)
{
    
    try
    {
        auto lvbtItems = this->m_pt.get_child(section.c_str());

        BOOST_FOREACH(auto &i , lvbtItems)
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


std::string Ini::get(const char *parent,const char* child)
{
    if (this->err_code == file_io_errorno::FERROR_OK)
    {
        auto _retParent = m_map4AllItems.find(parent);
        if(_retParent == m_map4AllItems.end())
        {
            return "";
        }
        std::map<std::string, std::string> mChilds = _retParent->second;

        auto _retChild = mChilds.find(child);
        if(_retChild == mChilds.end())
        {
            return "";
        }
        return _retChild->second;
    }
    else
    {
        return "";
    }
}