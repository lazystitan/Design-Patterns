# 设计模式：C++实现
>使用C++实现《设计模式》出现的所有设计模式

## 目录
-   [背景](#背景)
-   [使用](#使用)
-   [说明](#说明)
-   [相关概念](#相关概念)

## 背景

身为一名计算机科学与技术专业本科生，因大学课程偏向与硬件，外加自己的怠惰，临近毕业依旧不知道设计模式是哪些，内心颇为不甘，遂网购一本设计模式用以学习。

没有实践的学习不仅效率低，对自己技能的提高也是极为不利的。为了巩固和增强自己对于设计模式的理解，于是决定使用C++来实现一遍书中出现的设计模式。

目前进度：
    
-   创建型模式基本实现完毕，有些细节仍需要加以改进，包括
    1.  Factory
    2.  Builder
    3.  Singleton
    4.  AbstractFactory
    5.  Prototype
-   构建型模式，待完成：
    1. Adapter
    2. Bridge
    3. Composite (待实现)
    4. Decorator
    5. Faced (待实现) —— 暂时不打算实现
    6. Flyweight (待实现)
    7. Proxy
-   行为模式，待完成：
    1. Chain of responsibility (待实现)
    2. Command
    3. Interpreter (待实现)
    4. Iterator
    5. Mediator
    6. Memento (待实现)
    7. Observer
    8. State (待实现)
    9. Strategy (待实现)
    10. Template method (待实现)
    11. visitor (待实现)

另外，为了增强可读性，计划为每个模式的代码添加适当的注释，目前已经完成的设计模式中，某些已经有了一定的注释。


## 使用

本项目使用Clion编写，因此包含`CMakeLists.txt`文件，可以通过工具进行直接编译运行。

项目根目录包含三个文件夹和一个`main.cpp`。三个文件夹内分别是设计模式的三个类别：行为模式，结构型模式和创建模式。每个文件加名都是对应的英文，相信你可以理解。他们之内是设计模式的详细代码。

每一个设计模式要么是一个文件夹，要么是一个文件，不会出现多个模式出现在一个文件的情况，并且文件或文件夹名都是对应的英文。

`main.cpp`是对设计模式的简单测试，每一个设计模式的测试被装进一个独立的函数，函数名的格式为`test`+`设计模式英文名`。

## 说明

### 设计模式说明

-   创建型模式
    1. Factory
    2. Builder
    3. Singleton
    4. AbstractFactory
    5. Prototype
    
       ```rust
       //rust代码
       let arc_ptr = Arc::new(1);
       let cloned = Arc::clone(arc_ptr);
       let cloned = arc_ptr.clone();
       ```
    
-   构建型模式
    1. Adapter
    2. Bridge
    3. Composite
    4. Decorator
    5. Faced
    6. Flyweight
    7. Proxy
-   行为模式
    1. Chain of responsibility
    2. Command
    
       - `runner->run([params])`
       - `executor->execute([params])`
    
    4. Interpreter
    5. Iterator
    6. Mediator
    
       将类（对象）之间的交互集中，从类（对象）中抽离出。
    
    7. Memento
    8. Observer
    
       subject中保存observer的引用，subject变化时，调用每一个observer需要执行的方法。
    
    9. State
    
       内部状态的不同会有不同的行为。
    
    10. Strategy
    11. Template method
    12. visitor

### 零零散散

此部分将作为笔记，零零散散的记录一些关于设计模式的细节。待整理完善。

#### Proxy

Proxy模式的使用情况有三种：
1.  为了限制对被代理类的访问权限，使用合适的代理对访问进行限制。
2.  为了减少资源占用，例如，一张图片在非屏幕区域内可以使用代理表示，而不载入内存。当进入屏幕后，由代理将其显示。
3.  实现智能指针，具体可以参考C++标准库中的std::unique_ptr。

#### AbstractFactory和Builder

AbstractFactory和Builder模式看起来有些类似，实际上他们的偏重点不同：
1. AbstratFactory偏重于从一个抽象工厂中获取不同的但属于同系列的对象。
2. Builder偏重于构建一个复杂的对象。

#### Facade

现代编程系统的包（package, module）管理——尤其特指可见性（公开性）管理——是否也是一种Facade设计模式？
OSI模型和TCP/IP模型似乎也符合Facade的理念。

#### Factory

[Dependency Injection vs Factory Pattern](https://stackoverflow.com/questions/557742/dependency-injection-vs-factory-pattern)

#### 封装，抽象，解耦

封装，抽象，解耦可以从两个角度思考其优点和目的：
1. 个人角度

   降低开发者个人的心智压力，可以更高效率的迭代。

2. 工程角度

   1. 降低开发者的能力要求，减少开发成本
   2. 可以并行开发多个分离的子工程（包、类、组件），提高项目开发速度。
   3. 尽力减少新需求导致的工程量，减少开发成本。

## 相关概念

耦合性(coupling)是软件两个部件之间的独立程度；用来描述两个部件之间的联系有多紧密。

耦合性越低，意味着部件之间的独立性越高，也就意味着部件更易于重复使用。因此，在编程中降低耦合性是很重要的内容。

设计模式的目的是在面向对象的程序设计中对代码进行复用，采用的方法就是通过各种模式，降低对象或类之间的耦合性。