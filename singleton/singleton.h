//
// Created by Riton on 2019/9/21.
//

#ifndef DESIGN_PATTERNS_SINGLETON_H
#define DESIGN_PATTERNS_SINGLETON_H

class Singleton {
private:
    static Singleton* _instance;
protected:
    Singleton();
public:
    static Singleton* Instance();
};

#endif //DESIGN_PATTERNS_SINGLETON_H
