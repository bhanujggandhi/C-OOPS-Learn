#include <bits/stdc++.h>
using namespace std;

class Coffee {
   public:
    virtual double cost() = 0;
    virtual string description() = 0;
};

class SimpleCoffee : public Coffee {
   public:
    double cost() {
        return 300;
    }

    string description() {
        return "Simple Coffee";
    }
};

class CoffeeDecorator : public Coffee {
   protected:
    Coffee* coffee;

   public:
    CoffeeDecorator(Coffee* coffee) {
        this->coffee = coffee;
    }

    double cost() {
        return coffee->cost();
    }

    string description() {
        return coffee->description();
    }
};

class MilkDecorator : public CoffeeDecorator {
   public:
    MilkDecorator(Coffee* decoratedCoffee) : CoffeeDecorator(decoratedCoffee) {}

    double cost() override {
        return coffee->cost() + 50;  // Additional cost for milk
    }

    std::string description() override {
        return coffee->description() + ", Milk";
    }
};

class SugarDecorator : public CoffeeDecorator {
   public:
    SugarDecorator(Coffee* decoratedCoffee) : CoffeeDecorator(decoratedCoffee) {}

    double cost() override {
        return coffee->cost() + 20;  // Additional cost for sugar
    }

    std::string description() override {
        return coffee->description() + ", Sugar";
    }
};

int main() {
    // Create a simple coffee
    Coffee* simpleCoffee = new SimpleCoffee();
    std::cout << "Cost of " << simpleCoffee->description() << ": ₹" << simpleCoffee->cost() << std::endl;

    // Decorate the simple coffee with milk
    Coffee* coffeeWithMilk = new MilkDecorator(new SimpleCoffee());
    std::cout << "Cost of " << coffeeWithMilk->description() << ": ₹" << coffeeWithMilk->cost() << std::endl;

    // Decorate the coffee with milk with sugar
    Coffee* coffeeWithMilkAndSugar = new SugarDecorator(new MilkDecorator(new SimpleCoffee()));
    std::cout << "Cost of " << coffeeWithMilkAndSugar->description() << ": ₹" << coffeeWithMilkAndSugar->cost() << std::endl;

    return 0;
}