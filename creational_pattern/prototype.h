//
// Created by Riton on 2019/11/9.
//

#ifndef DESIGN_PATTERNS_PROTOTYPE_H
#define DESIGN_PATTERNS_PROTOTYPE_H

#include <iostream>

class Prototype {
public:
    virtual Prototype* Clone() = 0;
};

class ConcretePrototypeA : public Prototype {
private:
    std::string _s;
public:
    const std::string &GetS() const {
        return _s;
    }

    void SetS(const std::string &s) {
        this->_s = s;
    }

    const char* GetAdress() const {
        return _s.data();
    }

    ConcretePrototypeA* Clone() override {
        auto *p = new ConcretePrototypeA();
        p->SetS(std::string(this->_s));
        return p;
    }
};

#endif //DESIGN_PATTERNS_PROTOTYPE_H
