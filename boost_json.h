#pragma once
#include "interfce.h"

class jsonTester_json : public jsonTester_base
{
public:
	std::string read(const char* aFileName) override;
	std::wstring read(const wchar_t* aFileName) override;

};



