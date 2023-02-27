#include "boost_json.h"

#include <boost/json.hpp>
#include <boost/json/src.hpp>
#include <fstream>
#include <codecvt>
#include <sstream>
#include <iostream>



#define BOOST_JSON_STACK_BUFFER_SIZE 4096


boost::json::value read_json(std::ifstream& is)
{
    // Detect and skip BOM characters //
    unsigned char a0 = is.get();
    unsigned char a1 = is.get();
    unsigned char a2 = is.get();

    if (!(a0 == 0xEF && a1 == 0xBB && a2 == 0xBF)) is.seekg(0);

    //////

    boost::json::stream_parser p;
    std::stringstream ss;
    ss << is.rdbuf();

    boost::json::error_code ec;
    p.write(ss.str(), ec);
    if (ec.value() != 0)
    {
        throw "json parse error. " + ec.message() + " at: " + ec.location().to_string();
    }

    p.finish();
    return p.release();
}



std::string jsonTester_json::read(const char* aFileName)
{
    std::ifstream fleStream(aFileName, std::ios::binary);

    auto root = read_json(fleStream);

    std::stringstream rez;

    const boost::json::object& robj = root.as_object();
    const boost::json::object& info = robj.at("info").as_object();
    const boost::json::object& printinfo = info.at("printinfo").as_object();
    const boost::json::array& goods = printinfo.at("goods").as_array();

    for (auto ar_it = goods.begin(); ar_it != goods.end(); ar_it++)
    {
        const auto& ar = ar_it->as_object();
        for (auto it = ar.begin(); it != ar.end(); it++)
        {
            const auto& val = it->value();
            std::string valStr;
            switch (val.kind())
            {
            case boost::json::kind::array: valStr = "array []"; break;
            case boost::json::kind::object: valStr = "object {}"; break;
            case boost::json::kind::null: valStr = "null"; break;
            case boost::json::kind::bool_: valStr = val.get_bool() ? "true" : "false"; break;
            case boost::json::kind::double_: valStr = val.get_double(); break;
            case boost::json::kind::int64: valStr = val.get_int64(); break;
            case boost::json::kind::uint64: valStr = val.get_uint64(); break;
            default: valStr = val.get_string().c_str(); break;
            }
            rez << it->key_c_str() << ": " << val << std::endl;
        }
    }
    return rez.str();
}

std::wstring jsonTester_json::read(const wchar_t* aFileName)
{
    std::ifstream fleStream(aFileName, std::ios::binary);

    // Detect and skip BOM characters //
    unsigned char a0 = fleStream.get();
    unsigned char a1 = fleStream.get();
    unsigned char a2 = fleStream.get();

    if (!(a0 == 0xEF && a1 == 0xBB && a2 == 0xBF)) fleStream.seekg(0);

    //////

    std::stringstream ss;
    ss << fleStream.rdbuf();

    auto root = boost::json::parse(ss);

    std::stringstream rez;

    const boost::json::object& robj = root.as_object();
    const boost::json::object& info = robj.at("info").as_object();
    const boost::json::object& printinfo = info.at("printinfo").as_object();
    const boost::json::array& goods = printinfo.at("goods").as_array();
    for (auto ar_it = goods.begin(); ar_it != goods.end(); ar_it++)
    {
        const auto& ar = ar_it->as_object();
        for (auto it = ar.begin(); it != ar.end(); it++)
        {
            const auto& val = it->value();
            std::string valStr;
            switch (val.kind())
            {
            case boost::json::kind::array: valStr = "array []"; break;
            case boost::json::kind::object: valStr = "object {}"; break;
            case boost::json::kind::null: valStr = "null"; break;
            case boost::json::kind::bool_: valStr = val.get_bool() ? "true" : "false"; break;
            case boost::json::kind::double_: valStr = val.get_double(); break;
            case boost::json::kind::int64: valStr = val.get_int64(); break;
            case boost::json::kind::uint64: valStr = val.get_uint64(); break;
            default: valStr = val.get_string().c_str(); break;
            }
            rez << it->key_c_str() << ": " << val << std::endl;
        }
    }

    std::wstring_convert<std::codecvt_utf8_utf16<wchar_t>> converter;
    return converter.from_bytes(rez.str());
}
