#include <iostream>
#include <codecvt>
#include <locale>

#include "getCurDir.h"
#include "boost_json.h"
#include "boost_wptree.h"


using namespace std;

int main()
{
	setlocale(LC_ALL, "ru_RU.UTF-8");

	string fleName = getCurrentDir() + "\\" + "cassPay_02122022_121231.json";
	wstring_convert<std::codecvt_utf8_utf16<wchar_t>> converter;
	wstring wfleName = converter.from_bytes(fleName);

	jsonTester_json jsn;

	cout << "boost::json  reading(char*):" << endl << endl;
	string rslt = jsn.read(fleName.c_str());

	cout << rslt << endl;
	cout << endl << endl;

	cout << "boost::json  reading(wchar_t*):" << endl << endl;


	wstring rsltw = jsn.read(wfleName.c_str());

	wcout << rsltw << endl;
	wcout << endl << endl;


	cout << "boost::property_tree::ptree  reading(char*):" << endl << endl;

	jsonTester_wptree jstTree;
	string rsltTree = jstTree.read(fleName.c_str());

	cout << rsltTree << endl;
	cout << endl << endl;

	cout << "boost::property_tree::wptree  reading(wchar_t*):" << endl << endl;

	wstring wrsltTree = jstTree.read(wfleName.c_str());
	wcout << wrsltTree << endl;;


	return 0;
}
