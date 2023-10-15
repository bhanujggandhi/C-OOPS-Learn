#include <iostream>

class Account {
   private:
    int balance;  // Instance member variable

    // This variable does not depend on the
    // object, thus known as Class Variable
    static float roi;

   public:
    void setData(int b) {
        balance = b;
    }

    void getData() {
        std::cout << balance << " ---> " << roi << std::endl;
    }

    // Static member function
    static void setROI(float r) {
        roi = r;
    }
};

// Memory to static variable is given only when this
// statement is called
float Account::roi = 4.5f;
// If not this statement, then link error will be given

int main() {
    Account ac;
    ac.setData(2);
    ac.setROI(10.3f);
    Account::setROI(3.4f);
    ac.getData();
    return 0;
}