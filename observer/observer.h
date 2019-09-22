//
// Created by Riton on 2019/9/21.
//

#ifndef DESIGN_PATTERNS_OBSERVER_H
#define DESIGN_PATTERNS_OBSERVER_H

#include "subject.h"

class Subject;

class Observer{
protected:
    Observer() = default;

public:
    virtual ~Observer() = default;
    virtual void update(Subject *the_changed_subject) = 0;

};

#endif //DESIGN_PATTERNS_OBSERVER_H
