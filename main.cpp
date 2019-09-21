#include <iostream>
#include <vector>
#include "singleton.h"
#include "observer/concrete_subject.h"
#include "observer/concrete_observer.h"
#include "decorator.h"

void test1() {
    Singleton *s1 = Singleton::Instance();
    Singleton *s2 = Singleton::Instance();
}

void test2() {
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

void test3() {
    std::string str = "12345";
    auto *window = new Window;
    auto *text_view = new TextView(std::move(str));
    auto *vc = new BorderDecorator(new ScrollDecorator(new DropShadowDecorator(text_view, 1), 3, 1), 10);
    window->set_contents(vc);
    delete window;
    delete  text_view;
    delete vc;

}

int main() {
//    test1();
//    test2();
    test3();
    return 0;
}