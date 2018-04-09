cmake_minimum_required(VERSION 3.9)
project(ds_sql)

include_directories(include)

set(CMAKE_CXX_STANDARD 11)

set(SOURCES
        src/repl.cpp
        src/Type.cpp
        src/Table.cpp
        src/Attribute.cpp
        src/Constraint.cpp
        src/test.cpp
        src/Cursor.cpp)

set(INCLUDES
        include/repl.h
        include/Type.h
        include/Table.h
        include/Attribute.h
        include/Constraint.h
        include/Cursor.h
        include/Insert.h)

add_executable(ds-sql ${SOURCES} ${INCLUDES})

