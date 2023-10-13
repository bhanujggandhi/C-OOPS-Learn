#include <bits/stdc++.h>
using namespace std;

class Subject {
   public:
    virtual void request() = 0;
};

class RealSubject : public Subject {
   public:
    void request() {
        cout << "RealObject: Handling the request" << endl;
    }
};

class Proxy : public Subject {
   private:
    RealSubject* realSubject;

   public:
    Proxy() {
        realSubject = nullptr;
    }

    void request() {
        // We can implement the proxy logic here, whatever checks we want
        if (realSubject == nullptr) {
            realSubject = new RealSubject();
        }

        realSubject->request();
    }
};

int main() {
    Proxy proxy;

    proxy.request();

    return 0;
}

/*
Subject is the abstract class that declares the interface for the Real Subject and Proxy.

RealSubject is the real object that does the actual work when the client interacts with it.

Proxy is a surrogate for RealSubject. It controls access to the RealSubject and is responsible for creating it when needed. The client interacts with the Proxy, and the Proxy forwards the request to the Real Subject when appropriate.
*/