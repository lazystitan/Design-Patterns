//
// Created by Riton on 2019/9/21.
//

#include <iostream>
#include "singleton.h"

Singleton* Singleton::_instance = nullptr;

Singleton::Singleton() {
    std::cout << "Singleton" << std::endl;
}

Singleton *Singleton::Instance() {
    if (_instance == nullptr) {
        _instance = new Singleton();
    }
    return _instance;
}
