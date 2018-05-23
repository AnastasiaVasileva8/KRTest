cmake_minimum_required(VERSION 2.6)
project(Clcapp)

add_executable(Clcapp main.cpp)

target_link_libraries(Clcapp pthread)
