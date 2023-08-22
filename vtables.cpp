#include <bits/stdc++.h>

using namespace std;

class Base {
   public:
    virtual void function1() {
        cout << "Base::F1" << endl;
    };
    virtual void function2() {
        cout << "Base::F2" << endl;
    };
};

class D1 : public Base {
   public:
    virtual void function1() {
        cout << "D1::F1" << endl;
    };
};

class D2 : public Base {
   public:
    virtual void function2() {
        cout << "D2::F2" << endl;
    };
};

int main() {

    D1 b = D1();
    b.function1();

    return 0;
}