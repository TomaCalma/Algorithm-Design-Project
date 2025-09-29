cmake_minimum_required(VERSION 3.21)
project(Proj_DA)

set(CMAKE_CXX_STANDARD 14)

include_directories(codigo)

add_executable(Proj_DA
        codigo/main.cpp
        codigo/package.cpp
        codigo/package.h
        codigo/truck.cpp
        codigo/truck.h
        codigo/optimizer.cpp
        codigo/optimizer.h)
