//
// Created by Riton on 2019/9/21.
//

#ifndef DESIGN_PATTERNS_SINGLETON_H
#define DESIGN_PATTERNS_SINGLETON_H

#include <iostream>

class Singleton {
private:
    static Singleton* _instance;
protected:
    Singleton() {
        std::cout << "Singleton" << std::endl;
    }
public:
    static Singleton* Instance() {
        if (_instance == nullptr) {
            _instance = new Singleton();
        }
        return _instance;
    }
};

Singleton* Singleton::_instance = nullptr;

#endif //DESIGN_PATTERNS_SINGLETON_H
