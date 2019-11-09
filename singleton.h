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

    virtual Singleton* CreateSingleton() {
        return new Singleton();
    }
public:
    static Singleton* Instance() {
        if (_instance == nullptr) {
            auto s = Singleton();
            _instance = s.CreateSingleton();
        }
        return _instance;
    }

    virtual void Action() {
        std::cout << "Singleton here" << std::endl;
    }
};

Singleton* Singleton::_instance = nullptr;

class SingletonSuccessor : public Singleton {
protected:
    Singleton* CreateSingleton() override {
        return new SingletonSuccessor();
    }

public:
    void Action() override {
        std::cout << "SingletonSuccessor here" << std::endl;
    }
};

#endif //DESIGN_PATTERNS_SINGLETON_H
