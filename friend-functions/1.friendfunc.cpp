#include <bits/stdc++.h>

using namespace std;

/*
A friend function in C++ is a function that is not a member of a class but is allowed to access the private and protected members of that class. It is declared inside the class definition using the friend keyword. Friend functions provide flexibility in terms of granting specific external functions access to class internals without necessarily making those members public.
*/

class Complex {
   private:
    int a;
    int b;

   public:
    Complex(int a, int b) : a(a), b(b){};

    void showData() {
        cout << "Complex Number: " << a << " + " << b << " i" << endl;
    }

    friend int add(Complex &obj);
};

/*
The friend function definition is outside the class, but it is able to access the private member data
of Base objects because it's declared as a friend.
*/

// Me as a programmer can have my own implementation of add function
int add(Complex &obj) {
    return obj.a + obj.b;
}

int main() {
    Complex c1(10, 12);

    cout << add(c1) << endl;
    return 0;
}