cmake_minimum_required(VERSION 3.27)
project(L4)

set(CMAKE_CXX_STANDARD 17)

add_executable(L4 main.cpp
        Fruit.h
        Fruit.cpp
        FruitRepo.h
        FruitRepo.cpp
        FruitController.h
        FruitController.cpp
        FruitUI.h
        FruitUI.cpp)
