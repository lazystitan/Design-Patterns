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

void test_command() {
    using namespace command;
    auto r = new Receiver();
    auto c = ConcreteCommand(r);
    c.Execute();
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