//
// Created by Riton on 2019/9/21.
//

#ifndef DESIGN_PATTERNS_OBSERVER_H
#define DESIGN_PATTERNS_OBSERVER_H

#include "subject.h"

class Subject;

class Observer{
protected:
    Observer();

public:
    virtual ~Observer();
    virtual void update(Subject *the_changed_subject) = 0;

};

Observer::Observer() {}

Observer::~Observer() {}

#endif //DESIGN_PATTERNS_OBSERVER_H
