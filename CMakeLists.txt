cmake_minimum_required(VERSION 3.9)
project(ds_sql)

include_directories(include)

set(CMAKE_CXX_STANDARD 11)

set(SOURCES src/repl.cpp src/Type.cpp)
set(INCLUDES include/repl.h include/Type.h)

add_executable(ds-sql ${SOURCES} ${INCLUDES})

