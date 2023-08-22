#include <bits/stdc++.h>

using namespace std;

class Parent {
   protected:
    int var = 5;
};

class C1 : virtual public Parent {
};

class C2 : virtual public Parent {
};

class GC : public C1, public C2 {
   public:
    int getdata() {
        return var;  // no longer ambiguous
    }
};

int main() {

    GC* gc = new GC();
    cout << gc->getdata() << endl;

    return 0;
}