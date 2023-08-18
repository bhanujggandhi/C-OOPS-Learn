#include <bits/stdc++.h>

using namespace std;

/*
Deleting a derived class object using a pointer of base class type that has a non-virtual destructor results in undefined behavior. To correct this situation, the base class should be defined with a virtual destructor.


Making base class destructor virtual guarantees that the object of derived class is destructed properly, i.e., both base class and derived class destructors are called.

As a guideline, any time you have a virtual function in a class, you should immediately add a virtual destructor (even if it does nothing). This way, you ensure against any surprises later.
*/

class Base {
   private:
    int x;

   public:
    Base() {
        cout << "Base object creating..." << endl;
    }

    // If we don't include virtual here, and the pointer type is base class
    // and object type is child class then only base destructor is called
    // to remove this undetermined behavior, we need to make destructor of
    // base class virtual
    virtual ~Base() {
        cout << "Base object destroying..." << endl;
    }
};

class Child : public Base {
   public:
    Child() {
        cout << "Child object creating..." << endl;
    }

    ~Child() {
        cout << "Child object destroying..." << endl;
    }
};

int main() {

    Base *b = new Child();
    delete b;

    return 0;
}