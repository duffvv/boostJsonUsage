#include "boost_wptree.h"

#include <iostream>
#include <boost/property_tree/ptree.hpp>
#include <boost/property_tree/json_parser.hpp>

#include <codecvt>
#include <locale>


std::string jsonTester_wptree::read(const char* aFileName)
{
    std::ifstream jsnFle(aFileName, std::ios::binary);
    std::stringstream jsnDta;
    jsnDta << jsnFle.rdbuf();
    std::string wstr = jsnDta.str();
    boost::property_tree::ptree rootHive;
    boost::property_tree::read_json(jsnDta, rootHive);


    std::stringstream rez;
    for (const auto& v : rootHive.get_child("info.printinfo.goods"))
    {
        for (auto it3 = v.second.begin(); it3 != v.second.end(); ++it3)
        {
            const std::string& nme = it3->first;
            const std::string& val = it3->second.data();
            rez << nme << ": " << val << std::endl;
        }
    }
    return rez.str();
}

std::wstring jsonTester_wptree::read(const wchar_t* aFileName)
{
    std::wifstream jsnFle(aFileName, std::ios::binary);
    jsnFle.imbue(std::locale(std::locale::empty(), new std::codecvt_utf8<wchar_t>));
    std::wstringstream jsnDta;
    jsnDta << jsnFle.rdbuf();
    std::wstring wstr = jsnDta.str();
    boost::property_tree::wptree rootHive;
    boost::property_tree::read_json(jsnDta, rootHive);
    
    
    std::wstringstream rez;
    for (const auto& v : rootHive.get_child(L"info.printinfo.goods"))
    {
        for (auto it3 = v.second.begin(); it3 != v.second.end(); ++it3)
        {
            const std::wstring& nme = it3->first;
            const std::wstring& val = it3->second.data();  
            rez << nme << ": " << val << std::endl;
        }
    }
    return rez.str();
}
