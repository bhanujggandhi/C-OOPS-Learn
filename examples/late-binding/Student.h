#pragma once

#include <iostream>
#include "Department.h"

class Student : public Department {
   public:
    void getdata() {
        Department::show();
        std::cout << "This is a IIIT Student" << std::endl;
    }
};