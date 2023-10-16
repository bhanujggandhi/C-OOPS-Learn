#include <iostream>
using namespace std;

class Complex {
   private:
    int a, b;

   public:
    Complex() {}
    Complex(int a, int b) {
        this->a = a;
        this->b = b;
    }

    // Binary operator takes an argument
    Complex operator+(Complex &c) {
        Complex temp(0, 0);
        temp.a = a + c.a;
        temp.b = b + c.b;

        return temp;
    }

    // Unary operator does not take any argument
    Complex operator-() {
        Complex temp;
        temp.a = -a;
        temp.b = -b;

        return temp;
    }

    // Pre-increment operator does not take any argument
    Complex operator++() {
        Complex temp;
        temp.a = ++a;
        temp.b = ++b;

        return temp;
    }

    // Post-increment operator
    Complex operator++(int) {
        Complex temp;
        temp.a = a++;
        temp.b = b++;

        return temp;
    }

    /*
    Since post and pre increment have same function prototype
    for compiler to treat them differently, in post increment we
    pass (int) as an argument
    */

    void showData() {
        cout << a << " + i" << b << endl;
    }
};

int main() {
    Complex c1(3, 4), c2(5, 6);

    Complex c3 = c1 + c2;
    Complex c4 = -c3;
    Complex c6 = c1++;
    Complex c5 = ++c1;

    c3.showData();
    c4.showData();
    c6.showData();
    c5.showData();

    return 0;
}