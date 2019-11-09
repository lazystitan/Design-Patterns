//
// Created by Riton on 2019/11/5.
//

#ifndef DESIGN_PATTERNS_ABSTRACT_FACTORY_H
#define DESIGN_PATTERNS_ABSTRACT_FACTORY_H

#define ARR_SIZE 4

#include <iostream>
#include <vector>


/*
 * 通过抽象类AbstractProduct为所有的product定义接口
 */
class AbstractProduct {
public:
    virtual void action() = 0;
};

/*
 * ConcreteProductA、B、C 分别继承AbstractProduct实现接口
 */
class ConcreteProductA : public AbstractProduct{
private:
    AbstractProduct * _arr[ARR_SIZE];
    int _number;
public:
    explicit ConcreteProductA(int number) : _arr{nullptr} {
        _number = number;
    }

    void set_arr(int index, AbstractProduct * t) {
        _arr[index] = t;
    }

    void action() override {
        std::cout << "ConcreteProductA action" << std::endl;
    }
};

class ConcreteProductB : public AbstractProduct {
public:
    void action() override {
        std::cout << "ConcreteProductB action" << std::endl;
    }
};

class ConcreteProductC : public AbstractProduct {
public:
    void action() override {
        std::cout << "ConcreteProductC action" << std::endl;
    }
};

/*
 * 假设一个新的product EnhancedProductA通过扩展ConcreteProductA实现了
 */
class EnhancedConcreteProductA : public ConcreteProductA {
public:
    explicit EnhancedConcreteProductA(int number) : ConcreteProductA(number) {}

    void action() override {
        std::cout << "EnhancedConcreteProductA action" << std::endl;
    }
};

/*
 * 由Products组合构成的类，其内的products由类型为下定义的AbstractFactory的类生成，整体由下定义的ProductsCreator生成
 */
class Products {
private:
    std::vector<AbstractProduct *> _v;
public:
    void add(AbstractProduct *m) {
        _v.push_back(m);
    }

    void action() {
        for (auto &p : _v)
            p->action();
    }
};

/*
 * AbstractFactory定义需要的接口
 */
class AbstractFactory {
public:
    virtual Products * MakeField() const = 0;
    virtual ConcreteProductA * MakeConcreteProductA(int) const = 0;
    virtual ConcreteProductB * MakeConcreteProductB() const = 0;
    virtual ConcreteProductC * MakeConcreteProductC() const = 0;
};

/*
 * 普通工厂
 */
class ConcreteFactoryA : public AbstractFactory {
public:
    Products * MakeField() const override {
        return new Products();
    }
    ConcreteProductA * MakeConcreteProductA(int number) const override {
        return new ConcreteProductA(number);
    }
    ConcreteProductB * MakeConcreteProductB() const override {
        return new ConcreteProductB();
    }
    ConcreteProductC * MakeConcreteProductC() const override {
        return new ConcreteProductC();
    }
};

/*
 * 使用了EnhancedProductA的工厂
 */
class ConcreteFactoryB : public AbstractFactory {
public:
    Products * MakeField() const override {
        return new Products();
    }
    ConcreteProductA * MakeConcreteProductA(int number) const override {
        return new EnhancedConcreteProductA(number);
    }
    ConcreteProductB * MakeConcreteProductB() const override {
        return new ConcreteProductB();
    }
    ConcreteProductC * MakeConcreteProductC() const override {
        return new ConcreteProductC();
    }
};


/*
 * 生成Products的类，包含一个创建Products的类。
 * 因为该成员函数的参数为一个工厂，根据要求可以创建不同的product，于此同时，它们之间的关系定义可以被复用。
 */
class ProductsCreatorAF{
public:
    static Products * CreateProducts(AbstractFactory * f) {
        auto products = f->MakeField();
        auto pa = f->MakeConcreteProductA(1);
        pa->set_arr(0, f->MakeConcreteProductB());
        pa->set_arr(1, f->MakeConcreteProductC());
        products->add(f->MakeConcreteProductA(0));
        products->add(f->MakeConcreteProductB());
        products->add(f->MakeConcreteProductC());
        return products;
    }
};


/*
 * 使用时，首先获取需要的Factory，之后将其传入ProductsCreator创建Products。
 * 通过获取不同的Factory，创建由不同的Product构成的Products。
 */

#endif //DESIGN_PATTERNS_ABSTRACT_FACTORY_H
