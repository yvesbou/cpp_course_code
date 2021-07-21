//
// Created by Yves Boutellier on 25.10.20.
//

#ifndef EXERCISE_03_EMULATING_POINTERS_H
#define EXERCISE_03_EMULATING_POINTERS_H

#include <iostream>

template <typename T>
class dumbPointer {

public:
    T* p;
    explicit dumbPointer(T* point): p(point){};

    T& operator*(){return *p;};
    T* operator->(){
        return p;
    };
    T* operator=(T* right){
        p = right;
        return p;
    }
    T* operator&(){
        return &p;
    }
};

class referenceCounter{
private:
    int RefCount{0};
public:
    void increment(){
        ++RefCount;
    }
    int decrement(){
        return --RefCount;
    }
    int getCount() const {
        return RefCount;
    }
};

template <typename T>
class smartPointer{
public:
    T* ptr{nullptr};
    referenceCounter* count{nullptr};

    //constructor
    explicit smartPointer(T* pointer):
    ptr(pointer),
    count(new referenceCounter())
    {
        count->increment();
    };

    //copy constructor
    smartPointer(const smartPointer<T>& other):
    ptr(other.ptr),
    count(other.count)
    {
        count->increment();
    };

    //destructor
    virtual ~smartPointer(){
        std::cout << "the destructor was called" << std::endl;
        if (count){
            int decrementCount = count->decrement();
            if (decrementCount <= 0){
                delete count;
                delete ptr;
            }
        }
    }

    // assignment operator
    smartPointer<T>& operator=(const smartPointer<T>  &other){
        if (this != &other){
            if (count && count->decrement() == 0){
                delete count;
                delete ptr;
            }
            ptr = other.ptr;
            count = other.count;
            count->increment();
        }
        return *this;
    }

    // dereference operator
    T operator*(){
        return *ptr;
    };

    // -> operator (member access operator)
    T* operator->(){
        return ptr;
    };

    int counter(){
        return count->getCount();
    }
};


#endif //EXERCISE_03_EMULATING_POINTERS_H
