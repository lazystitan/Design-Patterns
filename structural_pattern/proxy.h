//
// Created by Riton on 2019/9/21.
//

#ifndef DESIGN_PATTERNS_PROXY_H
#define DESIGN_PATTERNS_PROXY_H

#include <iostream>

/*
 * 应用：智能指针、占位、限制访问性
 * virtual proxy for saving resource
 * also have protection proxy and smart reference
 */
class Image {
private:
    int id;
public:
    explicit Image(int _id) {
        id = _id;
        std::cout << "create image " << id << std::endl;
    }
    void draw() {
        std::cout << "drawing" << std::endl;
    }
};

Image* load_an_image_file(int id) {
    std::cout << "loading image " << id << std::endl;
    return new Image(id);
}

class ImagePtr {
private:
    Image *_image;
    const int _image_id;
    Image *load_image() {
        return load_an_image_file(_image_id);
    }

public:
    explicit ImagePtr(const int image_id) :  _image_id(image_id) {
        _image = nullptr;
    }
    virtual ~ImagePtr() {
        delete _image;
        _image = nullptr;
    };
    virtual Image *operator->() {
        return load_image();
    }
    virtual Image &operator*() {
        return *load_image();
    }
};


void test_proxy() {
    ImagePtr imagePtr = ImagePtr(12345);
    imagePtr->draw();
}

#endif //DESIGN_PATTERNS_PROXY_H
