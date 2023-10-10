#include <bits/stdc++.h>
using namespace std;

class PaymentStrategy {
   public:
    virtual void pay(int amount) = 0;
};

class CreditCardPayment : public PaymentStrategy {
   private:
    string cardNumber;
    string cardHolderName;
    string expirationDate;
    int cardPin;

   public:
    CreditCardPayment(const string cardNumber, const string cardHolderName, const string expirationDate, const int cardPin) {
        this->cardNumber = cardNumber;
        this->cardHolderName = cardHolderName;
        this->expirationDate = expirationDate;
        this->cardPin = cardPin;
    }

    void pay(int amount) {
        cout << "Payment of amount ₹" << amount << " made using card number " << cardNumber << " by " << cardHolderName << endl;
    }
};

class PayPalPayment : public PaymentStrategy {
   private:
    string userId;
    string password;

   public:
    PayPalPayment(const string userId, const string password) {
        this->userId = userId;
        this->password = password;
    }

    void pay(int amount) {
        cout << "Payment of amount ₹" << amount << " made using paypal account " << userId << endl;
    }
};

// We can add similar payment strategies now and make the code reusable

class ShoppingCart {
   private:
    PaymentStrategy* paymentMethod;

   public:
    ShoppingCart(PaymentStrategy* paymentMethod) {
        this->paymentMethod = paymentMethod;
    }

    void checkout(int totalAmount) {
        paymentMethod->pay(totalAmount);
    }
};

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    ShoppingCart sc(new PayPalPayment("gandhibhanuj@gmail.com", "abc"));
    sc.checkout(1002);

    return 0;
}