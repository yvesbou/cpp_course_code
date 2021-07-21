//
// Created by Yves Boutellier on 05.11.20.
//

#ifndef EXERCISE04_RANGE_H
#define EXERCISE04_RANGE_H
#include <vector>
class Range{
public:
    int from;
    int to;

    Range(int from, int to){
        this->from = from;
        this->to = to+1;
    }
    class Iterator{
    public:
        int num;

        Iterator(int num){
            this->num = num;
        }

        int operator++(){
            ++num;
            return num;
        }

        int& operator*(){
            return num;
        }

        bool operator !=(Iterator other){
            return this->num != other.num;
        }
    };

    Iterator begin(){return Iterator(from);}
    Iterator end(){return Iterator(to);}
};

#endif //EXERCISE04_RANGE_H
