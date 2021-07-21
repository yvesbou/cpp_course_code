//
// Created by Yves Boutellier on 04.11.20.
//

#ifndef EXERCISE04_SOURCE_H
#define EXERCISE04_SOURCE_H



template <typename Vector>
class Iterator{
public:
    using ValueType = typename Vector::value_type;
    using PointerType = ValueType*;
    using ReferenceType = ValueType&;
private:
    PointerType ptr;
    PointerType end;

public:
    Iterator(Vector vec){
        ptr = &vec[0];
        end = ptr + vec.size();
    }

    PointerType begin(){
        return ptr;
    }

    PointerType beyond(){
        return end;
    }

    //prefix incrementor
    ReferenceType &operator++(){
        ptr++;
        return *ptr;
    }

    //postfix incrementor
    ReferenceType const &operator++(ValueType){
        PointerType temp = ptr;
        this->ptr++;
        return *temp;
    }

    PointerType operator->(){
        return ptr;
    }

    ReferenceType operator*(){
        return *ptr;
    }

    bool operator==(const Iterator& other)const
    {
        return ptr == other.ptr;
    }
    bool operator!=(const Iterator& other) const
    {
        return ptr != other.ptr;
    }
};




#endif //EXERCISE04_SOURCE_H
