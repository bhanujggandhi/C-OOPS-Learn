#include <iostream>
using namespace std;

class Engine {
    int m_power;

   public:
    void setPower(int power) {
        this->m_power = power;
    }

    int getPower() {
        return m_power;
    }
};

class Body {
    int m_body;

   public:
    void setBody(int power) {
        this->m_body = power;
    }

    int getBody() {
        return m_body;
    }
};

class Wheel {
    int m_wheel;

   public:
    void setWheel(int power) {
        this->m_wheel = power;
    }

    int getWheel() {
        return m_wheel;
    }
};

class Car {
   public:
    Engine engine;
    Body body;
    Wheel wheel;
};

class IHyundaiCarBuilder {
   protected:
    unique_ptr<Car> m_car;

   public:
    virtual void BuildEngine() = 0;
    virtual void BuildBody() = 0;
    virtual void BuildWheel() = 0;
    virtual unique_ptr<Car> GetCar() = 0;
};