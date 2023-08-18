#include <iostream>

using namespace std;

class SmartPointers {
   private:
    int *ptr;  // actual pointer
   public:
    SmartPointers(int p);
    ~SmartPointers();
    int &operator*();
};

SmartPointers::SmartPointers(int p) {
    this->ptr = new int(p);
}

SmartPointers::~SmartPointers() {
    delete ptr;
}

int &SmartPointers::operator*() {
    return *ptr;
}

int main() {
    SmartPointers ptr(10);
    *ptr = 20;

    cout << *ptr << endl;

    return 0;
}