cmake_minimum_required(VERSION 3.0)
project(cpptest)

set(MODULE cpptest)
cmake_minimum_required(VERSION 3.0)

include_directories(include)
file(GLOB HEADERS "cpptest.hpp")

add_library(HEADER_ONLY_TARGET STATIC ${HEADERS})
set_target_properties(HEADER_ONLY_TARGET PROPERTIES LINKER_LANGUAGE CXX)

install(FILES ${HEADERS} DESTINATION /usr/include/)
