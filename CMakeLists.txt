cmake_minimum_required(VERSION 3.10)
project(design_patterns)

set(CMAKE_CXX_STANDARD 14)

add_executable(design_patterns
    #主程序
        main.cpp

    #单例模式
        creational_pattern/singleton.h

        #观察模式
        behavioral_pattern/observer/subject.h
        behavioral_pattern/observer/observer.h
        behavioral_pattern/observer/concrete_subject.h
        behavioral_pattern/observer/concrete_observer.h

    # 装饰器模式
        structural_pattern/decorator.h

    #代理模式
        structural_pattern/proxy.h

    #抽象工厂
        creational_pattern/abstract_factory.h

    #生成器
        creational_pattern/builder.h

    #工厂方法
        creational_pattern/factory_method.h

    #原型方法
        creational_pattern/prototype.h)

