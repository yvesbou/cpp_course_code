//
// Created by Yves Boutellier on 18.11.20.
//
#include <iostream>

//Virtual destructor in base class ensures that the destructor of derived class will be called
// when using base pointer to the object.

class ABC{
public:
    //ABC() { std::cout << "ABase Class Constructor is called" << std::endl;}
    virtual ~ABC(void){std::cout << "Abstract Base Class Destructor is called" << std::endl;};
    virtual void foo() = 0;
};

class BC2{
public:
    BC2() { std::cout << "Base Class Constructor is called" << std::endl;}
    // without virtual destructor both base classes would not get destructed
    virtual ~BC2() { std::cout << "Base Class Destructor is called" << std::endl;}

};


class Derived : public BC2, public ABC{
public:
    Derived(){std::cout << "Derived constructor is called" << std::endl;};
    ~Derived(){std::cout << "Derived destructor is called" << std::endl;};
    virtual void foo() override{
        std::cout << "I'm doing foo" << std::endl;
    }
};


int main() {

    ABC* a = new Derived();
    a->foo();
    delete a;

    /*
    std::cout << "Second example" << std::endl;

    BC2* b = new Derived();
    delete b;

    std::cout << "Third example" << std::endl;

    Derived* c = new Derived();
    delete c;*/


}
