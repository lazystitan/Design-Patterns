//
// Created by Riton on 2019/9/21.
//

#ifndef DESIGN_PATTERNS_DECORATOR_H
#define DESIGN_PATTERNS_DECORATOR_H

namespace decorator {

#include <iostream>

    class VisualComponent {
    public:
        VisualComponent() = default;

        virtual void draw() = 0;

        virtual void resize() = 0;
    };

    class TextView : public VisualComponent {
    private:
        std::string text;
    public:
        explicit TextView(std::string &&str) {
            text = str;
        }

        void draw() override {
            std::cout << "text view draw " << text << std::endl;
        }

        void resize() override {
            std::cout << "text view resize " << std::endl;
        }
    };

    class Window {
    public:
        void set_contents(VisualComponent *contents) {
            std::cout << "window set contents" << std::endl;
            contents->draw();
            contents->resize();
        }
    };

    class Decorator : public VisualComponent {
    private:
        VisualComponent *_component;
    public:
        explicit Decorator(VisualComponent *component) {
            _component = component;
        }


        void draw() override {
            _component->draw();
        }

        void resize() override {
            _component->resize();
        }
    };

    class BorderDecorator : public Decorator {
    private:
        int _width;

        void draw_boder() {
            std::cout << "border decorator draw " << _width << " border" << std::endl;
        }

    public:
        BorderDecorator(VisualComponent *visualComponent, int border_width) : Decorator(visualComponent) {
            _width = border_width;
        }

        void draw() override {
            Decorator::draw();
            draw_boder();
        }
    };

    class ScrollDecorator : public Decorator {
    private:
        int _direction;
        int _width;

        void draw_scroll() {
            std::cout << "scroll decorator draw " << _width << " scroll on " << _direction << std::endl;
        }

    public:
        ScrollDecorator(VisualComponent *visualComponent, int width, int direction) : Decorator(visualComponent) {
            _width = width;
            _direction = direction;
        }

        void draw() override {
            Decorator::draw();
            draw_scroll();
        }
    };

    class DropShadowDecorator : public Decorator {
    private:
        int _width;

        void draw_shadow() {
            std::cout << "drop shadow decorator draw " << _width << " shadow" << std::endl;
        }

    public:
        DropShadowDecorator(VisualComponent *visualComponent, int width) : Decorator(visualComponent) {
            _width = width;
        }

        void draw() override {
            Decorator::draw();
            draw_shadow();
        }
    };
}

#endif //DESIGN_PATTERNS_DECORATOR_H
