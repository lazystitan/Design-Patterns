//
// Created by Riton on 2019/9/21.
//

#ifndef DESIGN_PATTERNS_CONCRETE_SUBJECT_H
#define DESIGN_PATTERNS_CONCRETE_SUBJECT_H


#include "subject.h"

class ConcreteSubject : public Subject {
private:
    int status;
public:
    ConcreteSubject() {
        status = 0;
    }
    void set_status(int s) {
        this->status = s;
        Subject::notify();
    }
    int get_status() {
        return status;
    }

};

#endif //DESIGN_PATTERNS_CONCRETE_SUBJECT_H
