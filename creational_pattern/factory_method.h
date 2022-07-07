//
// Created by Riton on 2019/11/9.
//

#ifndef DESIGN_PATTERNS_FACTORY_METHOD_H
#define DESIGN_PATTERNS_FACTORY_METHOD_H

#include "abstract_factory.h"

/*
 * AbstractProduct
 *       |
 *       +-----+-------------------+----------------------+
 *             |                   |                      |
 *      ConcreteProductScroller    ConcreteProductButton      ConcreteProductInput
 *            |
 *  EnhancedConcreteProductScroller
 */

//without template
//use lay initialization

class Creator {
private:
    AbstractProduct *_product{};
protected:
    virtual AbstractProduct* CreateProduct() = 0;

public:
    AbstractProduct* GetProduct() {
        if (!this->_product)
            this->_product = CreateProduct();
        return _product;
    }
};

class ConcreteCreator : public Creator {
protected:
    AbstractProduct* CreateProduct() override {
        return new ConcreteProductButton();
    }
};

//use template
class CreatorT {
public:
    virtual AbstractProduct* CreateProduct() = 0;
};

template <class T>
class ConcreteTemplateCreator : public CreatorT {
public:
    AbstractProduct* CreateProduct() override {
        return new T();
    }
};


void test_factory_method() {
    ConcreteProductButton *p;
    ConcreteCreator c = ConcreteCreator();
//    p = dynamic_cast<ConcreteProductButton*>(c.GetProduct());
    p = (ConcreteProductButton*) c.GetProduct();
    p->action();

    auto ct = ConcreteTemplateCreator<ConcreteProductInput>();
//    auto *pc = dynamic_cast<ConcreteProductInput*>(ct.CreateProduct());
    auto *pc = (ConcreteProductInput*) ct.CreateProduct();
    pc->action();
}

#endif //DESIGN_PATTERNS_FACTORY_METHOD_H
