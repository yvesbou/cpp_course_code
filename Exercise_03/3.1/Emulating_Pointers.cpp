//
// Created by Yves Boutellier on 25.10.20.
//

#include "Emulating_Pointers.h"



class Object{
public:
    int i;
    explicit Object(int v): i(v){};
    static std::string method1(){
        return "method1 was invoked ";
    }
    static std::string method2(){
        return "method2 was invoked ";
    }
    static std::string method3(){
        return "method3 was invoked ";
    }

    friend std::ostream& operator<< (std::ostream &os, Object o);
};

std::ostream& operator<<(std::ostream &os, Object o){
    os << o.i;
    return os;
};

void print(smartPointer<Object> p){
    std::cout << p.counter() << ": " << *p << std::endl;
}


/* for dumb pointer
int main(){
    int a = 6;
    int* b;
    Object *t = new Object(3);

    dumbPointer<int> q(&a);
    //q = b; //that works
    b = q.p;
    *b = 10;
    int c = *q;
    c = 13;
    std::cout << *q << std::endl;
    std::cout << *b << std::endl;
    std::cout << a << std::endl;

    dumbPointer<Object> z(t);
    std::cout<< z->i; // z-> = (*ptr).i; with -> we can reference and use the members of a class

}
*/

// for smartPointer
int main(){
    Object *o1=new Object(1);
    Object *o2=new Object(2);

    smartPointer<Object> p(o1);
    std::cout << p.counter() << std::endl; // worked


    smartPointer<Object> q(p);
    std::cout << p.counter() << std::endl;
    std::cout << q.counter() << std::endl;


    smartPointer<Object> r(o2);
    std::cout << r.counter() << std::endl;

    q=r;


    std::cout << p.counter() << std::endl;
    std::cout << q.counter() << std::endl;
    std::cout << r.counter() << std::endl;


    print(p);
    print(q);
    print(r);

    std::cout << *r << std::endl;
    std::cout << p->method1() << q->method2() << r->method3() << std::endl;



}
