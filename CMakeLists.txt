cmake_minimum_required(VERSION 3.9)
project(ds_sql)

set(CMAKE_CXX_STANDARD 11)

include_directories(include)

add_executable(repl src/repl.cpp include/repl.h)
