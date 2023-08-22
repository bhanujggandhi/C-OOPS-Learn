#include <bits/stdc++.h>

using namespace std;

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
};

int main() {
    Bhai bh(20);
    bh.printD();

    Base ba;
    cout << ba.getData() << endl;

    return 0;
}