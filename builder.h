//
// Created by Riton on 2019/11/5.
//

#ifndef DESIGN_PATTERNS_BUILDER_H
#define DESIGN_PATTERNS_BUILDER_H

#include "abstract_factory.h"

/*
 * AbstractProduct
 *       |
 *       +-----+-------------------+----------------------+
 *             |                   |                      |
 *      ConcreteProductA    ConcreteProductB      ConcreteProductC
 *            |
 *  EnhancedConcreteProductA
 */

/*
 * Builder和Abstract的区别？
 */



class AbstractBuilder {
protected:
    AbstractBuilder() = default;

public:
    virtual void BuildProducts() = 0;
    virtual void BuildProductA(int) = 0;
    virtual void BuildProductB() = 0;
    virtual void BuildProductC() = 0;
    virtual void EnhancedBuildProductA(int) = 0;
    virtual Products* GetProducts() = 0;
};

class ConcreteBuilder : public AbstractBuilder {
private:
    Products * _products;
public:
    ConcreteBuilder() {
        this->_products = nullptr;
    }
    void BuildProducts() override {
        this->_products = new Products();
    }

    void BuildProductA(int number) override {
        this->_products->add(new ConcreteProductA(number));
    }

    void BuildProductB() override {
        this->_products->add(new ConcreteProductB());
    }
    void BuildProductC() override {
        this->_products->add(new ConcreteProductC());
    }
    void EnhancedBuildProductA(int number) override {
        this->_products->add(new EnhancedConcreteProductA(number));
    }
    Products* GetProducts() override {
        return this->_products;
    }
};

class ProductsCreatorB {
public:
    static Products* CreateProducts(AbstractBuilder &b) {
        b.BuildProducts();
        b.BuildProductA(0);
        b.EnhancedBuildProductA(1);
        b.BuildProductB();
        b.BuildProductC();

        return b.GetProducts();
    }
};



#endif //DESIGN_PATTERNS_BUILDER_H
