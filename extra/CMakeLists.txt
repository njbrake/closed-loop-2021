cmake_minimum_required(VERSION 3.9)
project(extra VERSION 1.0.1 DESCRIPTION "extra description")

add_library(${PROJECT_NAME} SHARED
    src/new.cpp
)

target_include_directories(${PROJECT_NAME} PRIVATE src)