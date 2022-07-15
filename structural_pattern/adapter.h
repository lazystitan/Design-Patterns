//
// Created by Riton on 2019/11/12.
//

#ifndef DESIGN_PATTERNS_ADAPTER_H
#define DESIGN_PATTERNS_ADAPTER_H

#include <iostream>

namespace ClassAdapter {

    //目标（虚）类（接口）
    class Target {
    public:
        virtual void setData(int data1, int data2) = 0;
        virtual int getSumData(int data) = 0;
    };

    //待转换类
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

    //适配器类
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

//类似于类适配去，却别在于要给Adapter传入一个待转换对象
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

void test_adapter() {
    {
        using namespace ClassAdapter;
        Adapter a;
        a.setData(15,2);
        int rs = a.getSumData(3);
        std::cout << rs << std::endl;
    }
    {
        using namespace ObjectAdapter;
        Adaptee a;
        Adapter at = Adapter(&a);
        at.setData(15,37);
        int rs = at.getSumData(3);
        std::cout << rs << std::endl;
    }
}

#endif //DESIGN_PATTERNS_ADAPTER_H
