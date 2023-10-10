#include <bits/stdc++.h>
using namespace std;

class Subject;

class Observer {
   public:
    virtual void update(const Subject &subject) = 0;
};

class Subject {
   private:
    int state = 0;
    set<Observer *> subscribers;

   public:
    void add(Observer *obs) {
        subscribers.insert(obs);
    }

    void remove(Observer *obs) {
        subscribers.erase(obs);
    }

    void notify() {
        for (auto &obs : subscribers) {
            obs->update(*this);
        }
    }

    void setState(int state) {
        this->state = state;
        notify();  // Notify observers when the state changes
    }

    int getState() const {
        return state;
    }
};

class ConcreteObserver1 : public Observer {
   public:
    void update(const Subject &subject) override {
        std::cout << "Observer 1: Subject's state is now " << subject.getState() << std::endl;
    }
};

class ConcreteObserver2 : public Observer {
   public:
    void update(const Subject &subject) override {
        std::cout << "Observer 2: Subject's state is now " << subject.getState() << std::endl;
    }
};

int main() {

    Subject subject;
    ConcreteObserver1 *obs1 = new ConcreteObserver1();
    ConcreteObserver2 *obs2 = new ConcreteObserver2();

    subject.add(obs1);
    subject.add(obs2);

    subject.setState(199);

    subject.remove(obs1);

    subject.setState(19);

    return 0;
}

/*
In this example:

We define an Observer interface with a update method, which concrete observers must implement.

The Subject class represents the object being observed. It maintains a list of observers, allows observers to attach and detach themselves, and notifies all attached observers when its state changes.

ConcreteObserver1 and ConcreteObserver2 are concrete observer classes that implement the update method to react to changes in the subject's state.

In the main function, we create a Subject object and two observers. We attach both observers to the subject, change the subject's state, and observe that both observers are notified of the state change. Then, we detach one observer and change the state again to see that only the remaining observer is notified.

This demonstrates the Observer Pattern, where the subject (in this case, Subject) maintains a list of observers and notifies them when its state changes without needing to know the specific details of each observer's implementation.
*/