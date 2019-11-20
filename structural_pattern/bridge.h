//
// Created by Riton on 2019/11/19.
//

#ifndef DESIGN_PATTERNS_BRIDGE_H
#define DESIGN_PATTERNS_BRIDGE_H

namespace bridge {

#include <iostream>

    class WindowImp {
    public:
        virtual void DrawText() {
            std::cout << "draw text" << std::endl;
        }

        virtual void DrawLine() {
            std::cout << "draw line" << std::endl;
        }
    };

    class XWindowImp : public WindowImp {
    public:
        void DrawText() override {
            std::cout << "XWindowImp draw text" << std::endl;
        }

        void DrawLine() override {
            std::cout << "XWindowImp draw line" << std::endl;
        }
    };

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
        void DrawBorder() {
            Window::DrawText();
            Window::DrawRect();
        }
    };

    class TransientWindow : public Window {
    public:
        void DrawCloseBox() {
            Window::DrawRect();
        }
    };
}

#endif //DESIGN_PATTERNS_BRIDGE_H
