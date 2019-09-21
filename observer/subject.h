//
// Created by Riton on 2019/9/21.
//

#ifndef DESIGN_PATTERNS_SUBJECT_H
#define DESIGN_PATTERNS_SUBJECT_H

#include <list>
#include "observer.h"


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

Subject::Subject() {
    _observers = new std::list<Observer*>;
}

Subject::~Subject() {
    delete _observers;
}

void Subject::attach(Observer *o) {
    _observers->push_back(o);
}

void Subject::detach(Observer *o) {
    _observers->remove(o);
}

void Subject::notify() {
    for (Observer* observer : *_observers) {
        observer->update(this);
    }
}

#endif //DESIGN_PATTERNS_SUBJECT_H
