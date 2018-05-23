cmake_minimum_required(VERSION 2.6)
project(Clientapp)

add_executable(Clientapp main.cpp)

target_link_libraries(Clientapp pthread)
