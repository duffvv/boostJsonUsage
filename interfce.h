#pragma once

#include <string>

class jsonTester_base
{
public:
	virtual std::string read(const char* aFileName) = 0;
	virtual std::wstring read(const wchar_t* aFileName) = 0;
};


