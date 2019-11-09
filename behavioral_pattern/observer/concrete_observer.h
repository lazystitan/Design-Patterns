//
// Created by Riton on 2019/9/21.
//

#ifndef DESIGN_PATTERNS_CONCRETE_OBSERVER_H
#define DESIGN_PATTERNS_CONCRETE_OBSERVER_H

#include <iostream>
#include "observer.h"
#include "concrete_subject.h"

class ConcreteObserver : public Observer{
public:
    void update(Subject *the_changed_subject) override {
        auto cs = dynamic_cast<ConcreteSubject *>(the_changed_subject);
        std::cout << "status changed to " << cs->get_status() << std::endl;
    }

};

#endif //DESIGN_PATTERNS_CONCRETE_OBSERVER_H
