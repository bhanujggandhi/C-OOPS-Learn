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

    Complex operator+(Complex &c) {
        Complex temp(0, 0);
        temp.a = a + c.a;
        temp.b = b + c.b;

        return temp;
    }

    void showData() {
        cout << a << " + i" << b << endl;
    }
};

int main() {
    Complex c1(3, 4), c2(5, 6);

    Complex c3 = c1 + c2;

    c3.showData();

    return 0;
}