cmake_minimum_required(VERSION 3.10)
project(design_patterns)

set(CMAKE_CXX_STANDARD 14)

add_executable(design_patterns
    #主程序
        main.cpp

    #单例模式
        singleton/singleton.h
        singleton/singleton.cpp

    #观察模式
        observer/subject.h
        observer/observer.h
        observer/concrete_subject.h
        observer/concrete_observer.h

    # 装饰器模式
        decorator.h
        )

