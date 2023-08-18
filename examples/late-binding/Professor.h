#pragma once

#include <iostream>
#include "Department.h"

class Professor : public Department {
   public:
    void getdata() {
        Department::show();
        std::cout << "This is a IIIT Prof" << std::endl;
    }
};