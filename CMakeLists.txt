# CMakeList.txt: проект CMake для boostJsonUsage; включите исходный код и определения,
# укажите здесь логику для конкретного проекта.
#
cmake_minimum_required (VERSION 3.8)

project ("boostJsonUsage")

SET(CMAKE_INCLUDE_PATH ${CMAKE_INCLUDE_PATH} "c:/Program Files/Microsoft Visual Studio/2022/Community/VC_libs/boost_1_81_0/")
SET(CMAKE_LIBRARY_PATH ${CMAKE_LIBRARY_PATH} "c:/Program Files/Microsoft Visual Studio/2022/Community/VC_libs/boost_1_81_0/stage/lib/")

add_definitions( -DBOOST_ALL_NO_LIB )

set(Boost_USE_STATIC_LIBS OFF) 
set(Boost_USE_MULTITHREADED OFF)  
set(Boost_USE_STATIC_RUNTIME OFF) 

FIND_PACKAGE(Boost COMPONENTS json)

INCLUDE_DIRECTORIES(${Boost_INCLUDE_DIR})

# Добавьте источник в исполняемый файл этого проекта.
add_executable (boostJsonUsage "boostJsonUsage.cpp"  "getCurDir.h" "boost_json.cpp" "boost_wptree.cpp")

TARGET_LINK_LIBRARIES( boostJsonUsage ${Boost_LIBRARIES} )

if (CMAKE_VERSION VERSION_GREATER 3.12)
  set_property(TARGET boostJsonUsage PROPERTY CXX_STANDARD 14)
endif()

configure_file(cassPay_02122022_121231.json cassPay_02122022_121231.json COPYONLY)

# TODO: Добавьте тесты и целевые объекты, если это необходимо.
