//
// Created by Riton on 2019/11/24.
//

#ifndef DESIGN_PATTERNS_MEDIATOR_H
#define DESIGN_PATTERNS_MEDIATOR_H

namespace mediator {
    #include <iostream>

    class Colleague;
//    class ColleagueCondition;
//    class ColleagueChange;

    class  Mediator {
    public:
        virtual void ColleagueChanged(Colleague *) = 0;
        virtual void show() {
            std::cout << "show" << std::endl;
        }
    protected:
        virtual void CreateColleagues() = 0;
    };


    class Colleague {
    private:
        Mediator *_m;
    public:
        explicit Colleague(Mediator *m) : _m(m) {}

        virtual void Changed() {
            _m->ColleagueChanged(this);
        }
        virtual void operation(int n) {
            std::cout << "operation " << n << std::endl;
        }
    };

    class ColleagueCondition : public Colleague {
    public:
        explicit ColleagueCondition(Mediator *m) : Colleague(m) {}
        void CreateCondition() {
            Colleague::Changed();
        }
    };

    class ColleagueChange : public Colleague {
    public:
        explicit ColleagueChange(Mediator *m) : Colleague(m) {}
        void Changed() override {
            std::cout << "conditon changed" << std::endl;
            Colleague::Changed();
        }
    };


    class ConcreteMediator : public Mediator {
    private:
        ColleagueCondition *_condition;
        ColleagueChange *_change;
    protected:
        void CreateColleagues() override {
            _condition = new ColleagueCondition(this);
            _change = new ColleagueChange(this);
        }
    public:
        ConcreteMediator() {
            CreateColleagues();
        }
        ~ConcreteMediator() {
            delete _condition;
            delete _change;
        }
        void ColleagueChanged(Colleague *c) override {
            if (c == _condition) {
                _change->Changed();
            }
        }
        ColleagueCondition* GetConditon() {
            return _condition;
        }
        ColleagueChange* GetChange() {
            return _change;
        }
    };
}

void test_mediator() {
    using namespace mediator;
    auto m = ConcreteMediator();
    auto c = m.GetConditon();
    c->Changed();
}

#endif //DESIGN_PATTERNS_MEDIATOR_H
