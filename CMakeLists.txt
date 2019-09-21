cmake_minimum_required(VERSION 3.10)
project(design_patterns)

set(CMAKE_CXX_STANDARD 14)

add_subdirectory(observer)
add_executable(design_patterns main.cpp singleton.h singleton.cpp observer/subject.h observer/observer.h observer/concrete_subject.h observer/concrete_observer.h decorator.h)

