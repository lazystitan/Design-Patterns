//
// Created by Riton on 2019/11/12.
//

#ifndef DESIGN_PATTERNS_ADAPTER_H
#define DESIGN_PATTERNS_ADAPTER_H

#include <iostream>

namespace ClassAdapter {

    class Target {
    public:
        virtual void setData(int data1, int data2) = 0;
        virtual int getSumData(int data) = 0;
    };

    class Adaptee {
    private:
        int _data = 2;
    public:
        virtual int addData(int data1, int data2) {
            return data1 + data2;
        }
        virtual void modAndSetData(int data) {
            _data =  data % _data;
        }
        virtual int getData() {
            return _data;
        }
    };

    class Adapter : public Target, private Adaptee {
    public:
        void setData(int data1, int data2) override {
            int temp = Adaptee::addData(data1, data2);
            Adaptee::modAndSetData(temp);
        }
        int getSumData(int data) override {
            return Adaptee::getData() + data;
        }
    };

}

namespace ObjectAdapter {

    class Target {
    public:
        virtual void setData(int data1, int data2) = 0;
        virtual int getSumData(int data) = 0;
    };

    class Adaptee {
    private:
        int _data = 2;
    public:
        virtual int addData(int data1, int data2) {
            return data1 + data2;
        }
        virtual void modAndSetData(int data) {
            _data =  data % _data;
        }
        virtual int getData() {
            return _data;
        }
    };

    class Adapter : public Target{
    private:
        Adaptee * _p;
    public:
        explicit Adapter(Adaptee *p) : _p(p) {}

        void setData(int data1, int data2) override {
            int temp = _p->addData(data1, data2);
            _p->modAndSetData(temp);
        }
        int getSumData(int data) override {
            return _p->getData() + data;
        }
    };

}

#endif //DESIGN_PATTERNS_ADAPTER_H
