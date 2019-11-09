# 设计模式：C++实现
>使用C++实现《设计模式》出现的所有设计模式
## 背景

身为一名计算机科学与技术专业本科生，因大学课程偏向与硬件，外加自己的怠惰，临近毕业依旧不知道设计模式是哪些，内心颇为不甘，遂网购一本设计模式用以学习。

没有实践的学习不仅效率低，对自己技能的提高也是极为不利的。为了巩固和增强自己对于设计模式的理解，于是决定使用C++来实现一遍书中出现的设计模式。

目前进度：
    
-   创建型模式基本实现完毕，有些细节仍需要加以改进，包括
    1.  Factory模式
    2.  Builder模式
    3.  Singleton模式  
    4.  AbstractFactory模式
    5.  Prototype模式
-   构建型模式，待完成，已完成的有
    1.  Decorator模式
    2.  Proxy模式
-   行为模式，待完成，已完成的有
    1.  Observer模式

另外，为了增强可读性，计划为每个模式的代码添加适当的注释，目前已经完成的设计模式中，某些已经有了一定的注释。

## 使用

本项目使用Clion编写，因此包含`CMakeLists.txt`文件，可以通过工具进行直接编译运行。

项目根目录包含三个文件夹和一个`main.cpp`。三个文件夹内分别是设计模式的三个类别：行为模式，结构型模式和创建模式。每个文件加名都是对应的英文，相信你可以理解。他们之内是设计模式的详细代码。

每一个设计模式要么是一个文件夹，要么是一个文件，不会出现多个模式出现在一个文件的情况，并且文件或文件夹名都是对应的英文。

`main.cpp`是对设计模式的简单测试，每一个设计模式的测试被装进一个独立的函数，函数名的格式为`test`+`设计模式英文名`。
