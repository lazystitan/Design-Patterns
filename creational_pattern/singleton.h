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

    virtual void Action() {
        std::cout << "Singleton here" << std::endl;
    }
};

Singleton* Singleton::_instance = nullptr;

void test_singleton() {
    Singleton *s1 = Singleton::Instance();
    Singleton *s2 = Singleton::Instance();
}

//try using template implement singleton
//TODO

#endif //DESIGN_PATTERNS_SINGLETON_H
