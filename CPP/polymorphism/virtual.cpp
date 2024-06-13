#include<iostream>
using namespace std;


class Base {
public:
    virtual void show() {
        cout << "Base class show function\n";
    }
};

class Derived : public Base {
public:
    void show() {
	    
        cout << "Derived class show function\n";
    }
};

int main() {
    Base *b;
    Derived d;
    b = &d;  // Pointing base pointer to derived object
    b->show();  // Calls the show function of derived class
    return 0;
}

