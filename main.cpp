#include <iostream>
#include <vector>

#include "creational_pattern/singleton.h"
#include "creational_pattern/abstract_factory.h"
#include "creational_pattern/builder.h"
#include "creational_pattern/factory_method.h"
#include "creational_pattern/prototype.h"

#include "structural_pattern/decorator.h"
#include "structural_pattern/proxy.h"

#include "behavioral_pattern/observer.h"
#include "structural_pattern/adapter.h"
#include "structural_pattern/bridge.h"
#include "behavioral_pattern/command.h"
#include "behavioral_pattern/mediator.h"


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
    using namespace decorator;
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

void test_adapter() {
    {
        using namespace ClassAdapter;
        Adapter a;
        a.setData(15,2);
        int rs = a.getSumData(3);
        std::cout << rs << std::endl;
    }
    {
        using namespace ObjectAdapter;
        Adaptee a;
        Adapter at = Adapter(&a);
        at.setData(15,37);
        int rs = at.getSumData(3);
        std::cout << rs << std::endl;
    }
}

void test_bridge() {
    using namespace bridge;
    auto w = Window(PM);
    w.DrawRect();
    w.DrawText();
}

void test_command() {
    using namespace command;
    auto r = new Receiver();
    auto c = ConcreteCommand(r);
    c.Execute();
}

void test_mediator() {
    using namespace mediator;
    auto m = ConcreteMediator();
    auto c = m.GetConditon();
    c->Changed();
}

int main() {
    test_abstract_factory();
    test_singleton();
    test_observer();
    test_proxy();
    test_decorator();
    test_builder();
    test_factory_method();
    test_prototype();
    test_adapter();
    test_bridge();
    test_command();
    test_mediator();
    return 0;
}