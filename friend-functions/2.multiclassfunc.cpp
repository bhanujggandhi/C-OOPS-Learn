#include <bits/stdc++.h>
using namespace std;

class A;
class B;

class A {
   private:
    int a;

   public:
    A(int a) : a(a){};

    void showData() {
        cout << a << endl;
    }

    friend int add(A &a, B &b);
};

class B {
   private:
    int b;

   public:
    B(int a) : b(a){};

    void showData() {
        cout << b << endl;
    }

    friend int add(A &a, B &b);
};

int add(A &obj1, B &obj2) {
    return obj1.a + obj2.b;
}

/*
Friend function can become friend to more than one class.
It is a great usecase of sharing data between objects of different classes
*/

int main() {
    A obj1(5);
    B obj2(1);

    cout << add(obj1, obj2) << endl;
    return 0;
}