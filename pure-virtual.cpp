#include <bits/stdc++.h>

using namespace std;

/*
1. A class is abstract if it has at least one pure virtual function.
2. We can have pointers and references of abstract class type.
3. If we do not override the pure virtual function in the derived class, then the derived class also becomes an abstract class.
4. An abstract class can have constructors.
*/

class Base {
   public:
    Base() {
        cout << "Base constructor" << endl;
    }
    virtual void show() = 0;

    void intro() {
        cout << "Welcome from the base class" << endl;
    }
};

class Child1 : public Base {
   public:
    void show() {
        Base::intro();
        cout << "This is a child class" << endl;
    }
};

int main() {
    // If a class has a pure virtual function, then it is an abstract class
    // We cannot create an object of that abstract class
    // Base b1;

    Child1 c1;
    c1.show();

    Base *ptr = new Child1();
    ptr->show();
    return 0;
}