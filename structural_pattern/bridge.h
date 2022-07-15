//
// Created by Riton on 2019/11/19.
//

#ifndef DESIGN_PATTERNS_BRIDGE_H
#define DESIGN_PATTERNS_BRIDGE_H

namespace bridge {

#include <iostream>

    //具体实现的顶层接口
    class WindowImp {
    public:
        virtual void DrawText() {
            std::cout << "draw text" << std::endl;
        }

        virtual void DrawLine() {
            std::cout << "draw line" << std::endl;
        }
    };

    //X平台实现
    class XWindowImp : public WindowImp {
    public:
        void DrawText() override {
            std::cout << "XWindowImp draw text" << std::endl;
        }

        void DrawLine() override {
            std::cout << "XWindowImp draw line" << std::endl;
        }
    };

    //PM平台实现
    class PMWindowImp : public WindowImp {
    public:
        void DrawText() override {
            std::cout << "PMWindowImp draw text" << std::endl;
        }

        void DrawLine() override {
            std::cout << "PMWindowImp draw line" << std::endl;
        }
    };

    enum WindowImpType {
        X, PM
    };

    //脱离平台的类
    //Window和WindowImp的关系被称为bridge
    class Window {
    private:
        WindowImp *_window = nullptr;
    public:
        explicit Window(WindowImpType type) {
            switch (type) {
                case X:
                    _window = new XWindowImp();
                    break;
                case PM:
                    _window = new PMWindowImp();
                    break;
                default:
                    break;
            }
        }

        virtual void DrawText() {
            _window->DrawText();
        }

        virtual void DrawRect() {
            _window->DrawLine();
            _window->DrawLine();
            _window->DrawLine();
            _window->DrawLine();
        }
    };

    class IconWindow : public Window {
    public:
        explicit IconWindow(WindowImpType type) : Window(type) {}

        void DrawBorder() {
            Window::DrawText();
            Window::DrawRect();
        }
    };

    class TransientWindow : public Window {
    public:
        explicit TransientWindow(WindowImpType type) : Window(type) {}

        void DrawCloseBox() {
            Window::DrawRect();
        }
    };
}

void test_bridge() {
    using namespace bridge;
    auto w = Window(WindowImpType::PM);
    w.DrawRect();
    w.DrawText();

    auto w2 = Window(WindowImpType::X);
    w2.DrawRect();
    w2.DrawText();

    auto w3 = IconWindow(WindowImpType::X);
    w3.DrawRect();
    w3.DrawText();
    w3.DrawBorder();

    auto w4 = TransientWindow(WindowImpType::PM);
    w4.DrawRect();
    w4.DrawText();
    w4.DrawCloseBox();
}

#endif //DESIGN_PATTERNS_BRIDGE_H
