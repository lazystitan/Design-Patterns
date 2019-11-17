//
// Created by Riton on 2019/11/17.
//

#include "subject.h"

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
