cmake_minimum_required(VERSION 3.10)
project(design_patterns)

set(CMAKE_CXX_STANDARD 14)

add_executable(design_patterns
    #主程序
        main.cpp

    #单例模式
        singleton.h

        #观察模式
        observer/subject.h
        observer/observer.h
        observer/concrete_subject.h
        observer/concrete_observer.h

    # 装饰器模式
        decorator.h

    #代理模式
        proxy.h

    #抽象工厂
        abstract_factory.h

    #生成器
        builder.h

    #工厂方法
        factory_method.h prototype.h)

