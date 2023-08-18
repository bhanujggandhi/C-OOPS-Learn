#pragma once
#include <iostream>

class Department {
   public:
    void show() {
        std::cout << "Welcome to IIIT CSE department" << std::endl;
    }
    virtual void getdata() = 0;
};
