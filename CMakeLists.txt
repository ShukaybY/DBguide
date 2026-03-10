cmake_minimum_required(VERSION 3.15)

project(DBguide)

set(CMAKE_CXX_STANDARD 17)

include_directories(include)

add_executable(database
    src/main.cpp
    src/Database.cpp
    src/Product.cpp
)

file(COPY data DESTINATION ${CMAKE_BINARY_DIR})