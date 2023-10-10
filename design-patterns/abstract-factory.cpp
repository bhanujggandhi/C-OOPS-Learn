#include <bits/stdc++.h>
using namespace std;

class AbstractProductA {
   public:
    virtual string getProductInfo() = 0;
};

class ProductA1 : public AbstractProductA {
   public:
    string getProductInfo() {
        return "Product A1";
    }
};

class ProductA2 : public AbstractProductA {
   public:
    string getProductInfo() {
        return "Product A2";
    }
};

class AbstractProductB {
   public:
    virtual std::string getProductBInfo() = 0;
};

class ProductB1 : public AbstractProductB {
   public:
    string getProductBInfo() {
        return "Product B1";
    }
};

class ProductB2 : public AbstractProductB {
   public:
    string getProductBInfo() {
        return "Product B2";
    }
};

class AbstractFactory {
   public:
    virtual AbstractProductA* createProductA() = 0;
    virtual AbstractProductB* createProductB() = 0;
};

// Concrete Factory 1
class ConcreteFactory1 : public AbstractFactory {
   public:
    AbstractProductA* createProductA() override {
        return new ProductA1();
    }

    AbstractProductB* createProductB() override {
        return new ProductB1();
    }
};

// Concrete Factory 2
class ConcreteFactory2 : public AbstractFactory {
   public:
    AbstractProductA* createProductA() override {
        return new ProductA2();
    }

    AbstractProductB* createProductB() override {
        return new ProductB2();
    }
};

int main() {
    // Create a factory (either ConcreteFactory1 or ConcreteFactory2)
    AbstractFactory* factory = new ConcreteFactory2();

    // Create products using the factory
    AbstractProductA* productA = factory->createProductA();
    AbstractProductB* productB = factory->createProductB();

    // Use the products
    std::cout << "Product A: " << productA->getProductInfo() << std::endl;
    std::cout << "Product B: " << productB->getProductBInfo() << std::endl;

    return 0;
}
