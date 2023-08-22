#include <bits/stdc++.h>

using namespace std;

/*
A friend function in C++ is a function that is not a member of a class but is allowed to access the private and protected members of that class. It is declared inside the class definition using the friend keyword. Friend functions provide flexibility in terms of granting specific external functions access to class internals without necessarily making those members public.
*/

class Base {
   private:
    int data;
    int d2;

   public:
    // Base() {
    //     data = 100;
    // }

    Base(int d1) : data(d1), d2(d1 * d1 + 7){};

    friend int func(const Base &obj);
};

/*
The friend function definition is outside the class, but it is able to access the private member data
of Base objects because it's declared as a friend.
*/

int func(const Base &obj) {
    return obj.d2;
}

int main() {
    Base b(10);

    cout << func(b) << endl;
    return 0;
}