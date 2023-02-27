# boostJsonUsagee c++ 11/14

Sample program demonstrates reading info from a midle of json document with cyrylic symbols using boost library.

NOTE. Edit boost library path in the CmakeList.txt first before compilling. In general case direct setting of CMAKE_INCLUDE_PATH and CMAKE_LIBRARY_PATH to boost location does not nessesary. FIND_PACKAGE(Boost ...) directive does all nessesary work. But in some cases (just my case VS2022 win10) IDE does not finds boost without designation its path.

Boost library provides two different components for json reading.

First one - using boost::json namespace with boost::json::parse() method or boost::json::stream_parser class. According to JSON standart the file must be in UTF-8 encoding or UTF-8 encoding with BOM symbols. Before parsing you have to check if json file begins with BOM symbols and than skip them. stream_parser class is useful when json file is large. It lets read large json document by parts or lines inside a loop. 

Second one - using boost::property_tree namespace with ptree or wptree (unicode) classes. Unlike boost::json it does not neeeds to skip BOM symbols manualy. It is done automatically.

The sample program is designed as two classes jsonTester_json and jsonTester_wptree that realizes jsonTester_base interface with two methods "read" each for bytechars and widechars. It is made for ptree(bytechars) and wptree(widecahrs) diference demonstration. boost::json does not have unicode version. So there were used codecvt conversion to/from widestrings in the sample. 
