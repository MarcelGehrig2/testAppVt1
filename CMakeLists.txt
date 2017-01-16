cmake_minimum_required(VERSION 2.6)
project(testappvt1)

add_executable(testappvt1 main.cpp)

install(TARGETS testappvt1 RUNTIME DESTINATION bin)
