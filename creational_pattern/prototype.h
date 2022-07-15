//
// Created by Riton on 2019/11/9.
//

#ifndef DESIGN_PATTERNS_PROTOTYPE_H
#define DESIGN_PATTERNS_PROTOTYPE_H

#include <iostream>

//应用：rust中Arc、Rc、RcRef这些共享所有权的指针，每一次clone会增加引用次数，就可以再引用为0后自动释放内存
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

void test_prototype() {
    ConcretePrototypeA p = ConcretePrototypeA();
    p.SetS("123");
    ConcretePrototypeA *p1 = p.Clone();
    const std::string& s = p1->GetS();
    std::cout << "if p : " << p.GetS() << " equals p1 : " << s << " ?" << std::endl;
//    std::cout << &p.GetS() << std::endl;
//    std::cout << &(p1->GetS()) << std::endl;
    std::cout << std::hex << (long unsigned) p.GetAdress() << std::endl;
    std::cout << (long unsigned) p1->GetAdress() << std::endl;

}

#endif //DESIGN_PATTERNS_PROTOTYPE_H
