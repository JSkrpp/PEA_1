cmake_minimum_required(VERSION 3.27)
project(PEA1)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_EXE_LINKER_FLAGS "-static")

add_executable(PEA1 main.cpp
        Matrix.cpp
        Matrix.h
        Matrix.cpp
        Algorithms.cpp
        Algorithms.h
        Pomiar.cpp
        Pomiar.h
        FileOpener.cpp
        FileOpener.h
)
