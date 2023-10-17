#include <bits/stdc++.h>

using namespace std;

/*
A friend class in C++ is a class that is granted access to the private and protected members of another class. When a class is declared as a friend of another class, it can access the private and protected members of the friend class as if they were its own members. Friend classes are used to establish tight relationships between classes while maintaining encapsulation.
*/

class Base {
   private:
    int data;

   public:
    Base() : data(19){};

    int getData() {
        return data;
    }

    friend class Bhai;
};

class Bhai {
   private:
    int d;

   public:
    Bhai(int d) : d(d){};
    void printD() {
        Base b;
        cout << "Base ka data " << b.data << endl;
        cout << "Bhai ka d " << this->d << endl;
        return;
    }

    void doSomething(const Base &b) {
        cout << "Doing something, " << b.data << endl;
    }
};

// ====== Private constructor using friend classes ========

class A {
   private:
    int data;
    A() : data(100){};

    friend class B;
};

class B {
   public:
    B() {
        A a1;
        cout << "A ka data: " << a1.data << endl;
    }
};

int main() {
    Bhai bh(20);
    bh.printD();

    Base ba;
    cout << ba.getData() << endl;
    bh.doSomething(ba);

    cout << "==================" << endl;

    B bclass;

    // Cannot directly access A's constructor as it is private but using friend function we can
    // A aclass;

    return 0;
}