#include <iostream>
#include <vector>
#include "singleton.h"
#include "observer/concrete_subject.h"
#include "observer/concrete_observer.h"
#include "decorator.h"
#include "proxy.h"
#include "abstract_factory.h"
#include "builder.h"
#include "factory_method.h"
#include "prototype.h"

void test_singleton() {
    Singleton *s1 = Singleton::Instance();
    Singleton *s2 = Singleton::Instance();

    auto *ss1 = (SingletonSuccessor*) SingletonSuccessor::Instance();
    ss1->Action();
}

void test_observer() {
    ConcreteSubject concreteSubject;
    std::vector<ConcreteObserver*> observers;
    for (int i = 0; i < 5; ++i) {
        auto *observer = new ConcreteObserver();
        concreteSubject.attach(observer);
        observers.push_back(observer);
    }
    concreteSubject.set_status(2);

    concreteSubject.detach(observers[3]);

    concreteSubject.set_status(4);

    for (ConcreteObserver *co : observers) {
        delete co;
    }
}

void test_decorator() {
    std::string str = "12345";
    auto *window = new Window;
    auto *text_view = new TextView(std::move(str));
    auto *vc = new BorderDecorator(new ScrollDecorator(new DropShadowDecorator(text_view, 1), 3, 1), 10);
    window->set_contents(vc);
    delete window;
    delete  text_view;
    delete vc;

}

void test_proxy() {
    ImagePtr imagePtr = ImagePtr(12345);
    imagePtr->draw();
}

void test_abstract_factory() {
    auto factory_a = ConcreteFactoryA();
    auto products_1 = ProductsCreatorAF::CreateProducts(&factory_a);
    products_1->action();

    auto factory_b = ConcreteFactoryB();
    auto products_2 = ProductsCreatorAF::CreateProducts(&factory_b);
    products_2->action();
}

void test_builder() {
    ConcreteBuilder cb;
    Products *p;

    ProductsCreatorB::CreateProducts(cb);
    p = cb.GetProducts();
}

void test_factory_method() {
    ConcreteProductB *p;
    ConcreteCreator c = ConcreteCreator();
//    p = dynamic_cast<ConcreteProductB*>(c.GetProduct());
    p = (ConcreteProductB*) c.GetProduct();
    p->action();

    auto ct = ConcreteTemplateCreator<ConcreteProductC>();
//    auto *pc = dynamic_cast<ConcreteProductC*>(ct.CreateProduct());
    auto *pc = (ConcreteProductC*) ct.CreateProduct();
    pc->action();
}

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

int main() {
    test_singleton();
    test_observer();
    test_proxy();
    test_decorator();
    test_abstract_factory();
    test_builder();
    test_factory_method();
    test_prototype();
    return 0;
}