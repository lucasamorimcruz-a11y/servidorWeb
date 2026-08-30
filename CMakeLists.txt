cmake_minimum_required(VERSION 4.3)
project(cpp_projects)

set(CMAKE_CXX_STANDARD 14)

include_directories(include)

add_executable(cpp_projects
        include/server.hpp
        src/server.cpp)
