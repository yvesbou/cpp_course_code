#include <iostream>
#include <iterator>
#include <vector>

class Iterator{
public:
    using ValueType = int;
    using PointerType = ValueType*;
    using ReferenceType = ValueType&;
private:
    PointerType ptr;
    int start;
    int ending;

public:
    Iterator(int start, int ending){
        this->start = start;
        this->ending = ending;
    }

    Iterator &operator++(){
        std::cout << "++ used" << std::endl;
        start++;
        return Iterator;
    }

    ReferenceType &operator++(ValueType){
        PointerType temp = &start;
        start++;
        return *temp;
    }

    ReferenceType operator*(){
        return start;
    }

    PointerType operator->(){
        return &start;
    }

    bool operator==(Iterator other){
        return start == other.ending;
    }

    bool operator!=(Iterator other){
        std::cout << "!= used" << std::endl;
        return start != 0;
    }
    PointerType begin(){return &start;}
    PointerType end(){return &ending;}
};


int main()
{
    for (auto i : Iterator(10,10)){
        std::cout << i << std::endl;
    }

}
