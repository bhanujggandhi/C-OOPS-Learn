#include <bits/stdc++.h>
using namespace std;

class Vehicle {
   public:
    virtual void startVehicle() = 0;
};

class TwoWheeler : public Vehicle {
   public:
    void startVehicle() {
        cout << "2 wheeler started" << endl;
    }
};

class FourWheeler : public Vehicle {
   public:
    void startVehicle() {
        cout << "4 wheeler started" << endl;
    }
};

class VehicleFactory {
   public:
    Vehicle* getVehicle(int wheels) {
        switch (wheels) {
            case 2:
                return new TwoWheeler();
                break;
            case 4:
                return new FourWheeler();
                break;
            default:
                return NULL;
                break;
        }
    }
};

int main() {
    VehicleFactory* vf = new VehicleFactory();
    Vehicle* veh = vf->getVehicle(4);
    veh->startVehicle();

    return 0;
}