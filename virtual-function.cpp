#include <bits/stdc++.h>

using namespace std;

class Base1 {
   public:
    void show() {
        cout << "I'm from Base1 class" << endl;
    }
};

class Child1 : public Base1 {
   public:
    void show() {
        cout << "I'm from child one" << endl;
    }
};

class Child2 : public Base1 {
   public:
    void show() {
        cout << "I'm from child two" << endl;
    }
};

class Base2 {
   public:
    virtual void show() {
        cout << "I'm from Base2 class" << endl;
    }
};

class Child3 : public Base2 {
   public:
    // not necessary to add `virtual` keyword, as the function of the base is virtual
    void show() {
        cout << "I'm from child three" << endl;
    }
};

class Child4 : public Base2 {
   public:
    void show() {
        cout << "I'm from child four" << endl;
    }
};

int main() {

    Child1 c1;
    Child2 c2;

    c1.show();
    c2.show();

    // This is known as Static/Early Binding. Depends on the type of ptr, not content.
    Base1 *b1 = new Child1();
    b1->show();
    Base1 *b2 = new Child2();
    b2->show();

    Child3 c3;
    c3.show();

    Base2 *b3 = new Child3();
    b3->show();

    return 0;
}

/*
Prepend virtual keyword to the function definition → virtual function.

The rule is that the compiler selects the function based on the contents of ptr, not type. Type is used in non-virtual case.

Here the compiler does not know what class the contents of ptr may contain. It may content address of an object of the Derv1 class or of the Derv2 class. At runtime, this is decided on the basis of content. When it is known what class is pointed to by ptr, the appropriate version is called. This is known as Late Binding.
*/