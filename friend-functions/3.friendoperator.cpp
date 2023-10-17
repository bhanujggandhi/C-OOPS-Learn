#include <bits/stdc++.h>

using namespace std;

class Complex {
   private:
    int a;
    int b;

   public:
    Complex(){};
    Complex(int a, int b) : a(a), b(b){};

    void showData() {
        cout << "Complex Number: " << a << " + " << b << " i" << endl;
    }

    friend Complex operator+(Complex &obj1, Complex &obj2);
    friend Complex operator-(Complex &obj1);
    friend ostream &operator<<(ostream &dout, Complex &obj1);
    friend istream &operator>>(istream &din, Complex &obj1);
};

// Overloading + operator as a friend function
Complex operator+(Complex &obj1, Complex &obj2) {
    Complex temp;
    temp.a = obj1.a + obj2.a;
    temp.b = obj1.b + obj2.b;

    return temp;
}

Complex operator-(Complex &obj1) {
    Complex temp;
    temp.a = -obj1.a;
    temp.b = -obj1.b;
    return temp;
}

ostream &operator<<(ostream &dout, Complex &obj1) {
    cout << "a: " << obj1.a << " + iota " << obj1.b << endl;
    return dout;
}

istream &operator>>(istream &din, Complex &obj1) {
    cin >> obj1.a >> obj1.b;
    return din;
}

int main() {
    Complex c1(10, 12), c2(1, 2);

    // earlier it used to be c1.operator+(c2)
    Complex ans = c1 + c2;  // operator+(c1, c2)
    Complex c3 = -c1;       // operator-(c1)

    // ans.showData();
    // c3.showData();
    cout << c3 << endl;

    Complex c4;
    cin >> c4;
    cout << c4;
    return 0;
}