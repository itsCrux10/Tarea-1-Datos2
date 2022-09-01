cmake_minimum_required(VERSION 3.23)
project(Tarea_1_Datos2)

set(CMAKE_CXX_STANDARD 14)

include_directories(.)

add_executable(Tarea_1_Datos2
        Algoritmos.h
        Algortimos.cpp
        CreacionListas.cpp
        CreacionListas.h
        main.cpp PagedArray.cpp PagedArray.h)
