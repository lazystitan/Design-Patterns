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
 * Scroller、Button、Input 分别继承AbstractProduct实现接口。
 */
class ConcreteProductScroller : public AbstractProduct{
private:
    AbstractProduct * _arr[ARR_SIZE];
    int _number;
public:
    explicit ConcreteProductScroller(int number) : _arr{nullptr} {
        _number = number;
    }

    void set_arr(int index, AbstractProduct * t) {
        _arr[index] = t;
    }

    void action() override {
        std::cout << "ConcreteProductScroller action" << std::endl;
    }
};

class ConcreteProductButton : public AbstractProduct {
public:
    void action() override {
        std::cout << "ConcreteProductButton action" << std::endl;
    }
};

class ConcreteProductInput : public AbstractProduct {
public:
    void action() override {
        std::cout << "ConcreteProductInput action" << std::endl;
    }
};

/*
 * 假设一个新的EnhancedScroller通过扩展ConcreteProductA实现了
 */
class EnhancedConcreteProductScroller : public ConcreteProductScroller {
public:
    explicit EnhancedConcreteProductScroller(int number) : ConcreteProductScroller(number) {}

    void action() override {
        std::cout << "EnhancedConcreteProductScroller action" << std::endl;
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
    virtual ConcreteProductScroller * MakeConcreteProductScroller(int) const = 0;
    virtual ConcreteProductButton * MakeConcreteProductButton() const = 0;
    virtual ConcreteProductInput * MakeConcreteProductInput() const = 0;
};

/*
 * 普通工厂
 */
class ConcreteFactoryA : public AbstractFactory {
public:
    Products * MakeField() const override {
        return new Products();
    }
    ConcreteProductScroller * MakeConcreteProductScroller(int number) const override {
        return new ConcreteProductScroller(number);
    }
    ConcreteProductButton * MakeConcreteProductButton() const override {
        return new ConcreteProductButton();
    }
    ConcreteProductInput * MakeConcreteProductInput() const override {
        return new ConcreteProductInput();
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
    ConcreteProductScroller * MakeConcreteProductScroller(int number) const override {
        return new EnhancedConcreteProductScroller(number);
    }
    ConcreteProductButton * MakeConcreteProductButton() const override {
        return new ConcreteProductButton();
    }
    ConcreteProductInput * MakeConcreteProductInput() const override {
        return new ConcreteProductInput();
    }
};


/*
 * 生成Products的类，包含一个创建Products的方法。
 * 因为该成员函数的参数为一个工厂虚类，可以传入继承了工厂虚类的不同工厂类，创建不同的（但有相同父类的）product。
 */
class ProductsCreatorAF{
public:
    static Products * CreateProducts(AbstractFactory * f) {
        auto products = f->MakeField();
        auto pa = f->MakeConcreteProductScroller(1);
        pa->set_arr(0, f->MakeConcreteProductButton());
        pa->set_arr(1, f->MakeConcreteProductInput());
        products->add(f->MakeConcreteProductScroller(0));
        products->add(f->MakeConcreteProductButton());
        products->add(f->MakeConcreteProductInput());
        return products;
    }
};

/*
 * 使用时，首先获取需要的Factory，之后将其传入ProductsCreator创建Products。
 * 通过获取不同的Factory，创建由不同的Product构成的Products。
 */
void test_abstract_factory() {
    auto factory_a = ConcreteFactoryA();
    auto products_1 = ProductsCreatorAF::CreateProducts(&factory_a);
    products_1->action();

    auto factory_b = ConcreteFactoryB();
    auto products_2 = ProductsCreatorAF::CreateProducts(&factory_b);
    products_2->action();
}


#endif //DESIGN_PATTERNS_ABSTRACT_FACTORY_H
