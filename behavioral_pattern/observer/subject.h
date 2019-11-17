//
// Created by Riton on 2019/9/21.
//

#ifndef DESIGN_PATTERNS_SUBJECT_H
#define DESIGN_PATTERNS_SUBJECT_H

#include <list>
#include "observer.h"

class Observer;

class Subject {
private:
    std::list<Observer*> *_observers;

protected:
    Subject();

public:
    virtual ~Subject();
    virtual void attach(Observer*);
    virtual void detach(Observer*);
    virtual void notify();
};


#endif //DESIGN_PATTERNS_SUBJECT_H
