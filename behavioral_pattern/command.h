//
// Created by Riton on 2019/11/23.
//

#ifndef DESIGN_PATTERNS_COMMAND_H
#define DESIGN_PATTERNS_COMMAND_H


namespace command {
    #include <iostream>

    class Command {
    public:
        virtual void Execute() = 0;
    };

    class Receiver {
    public:
        void Action() {
            std::cout << "do something" << std::endl;
        }
    };

    class ConcreteCommand : public Command {
    private:
        Receiver * _r;
    public:
        explicit ConcreteCommand(Receiver *r) : _r(r) {}
        void Execute() override {
            _r->Action();
        }
    };
}

#endif //DESIGN_PATTERNS_COMMAND_H
