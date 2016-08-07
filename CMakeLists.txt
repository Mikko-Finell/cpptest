cmake_minimum_required(VERSION 3.0)
project(cpptest)

set(MODULE cpptest)

set(CMAKE_CXX_COMPILER "/usr/bin/clang++")
set(CMAKE_CXX_FLAGS_DEBUG "-Wall -Wextra -Werror -Wfatal-errors -std=c++14 -g")
set(CMAKE_CXX_FLAGS_RELEASE "-Wall -Wextra -Werror -Wfatal-errors -std=c++14 -O3")
set(CMAKE_BUILD_TYPE Release)
#set(CMAKE_BUILD_TYPE Debug)

include_directories(include)
file(GLOB SOURCES "src/*")

add_library(${MODULE} SHARED ${SOURCES})
set_target_properties(${MODULE} PROPERTIES SOVERSION "1.0")
install(TARGETS ${MODULE} DESTINATION /usr/lib)

file(GLOB HEADERS "include/*")
install(FILES ${HEADERS} DESTINATION /usr/include/)
