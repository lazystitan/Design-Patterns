#include <iostream>
#include <vector>
#include "singleton.h"
#include "observer/concrete_subject.h"
#include "observer/concrete_observer.h"
#include "decorator.h"
#include "proxy.h"
#include "abstract_factory.h"
#include "builder.h"

void test_singleton() {
    Singleton *s1 = Singleton::Instance();
    Singleton *s2 = Singleton::Instance();
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

int main() {
    test_singleton();
    test_observer();
    test_proxy();
    test_decorator();
    test_abstract_factory();
    test_builder();
    return 0;
}