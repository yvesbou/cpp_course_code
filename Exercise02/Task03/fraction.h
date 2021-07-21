//
// Created by Yves Boutellier on 12.10.20.
//
#include <iostream>
#ifndef EXERCISE02_FRACTION_H
#define EXERCISE02_FRACTION_H
int GCD(int u, int v) {
    while (v != 0) {
        int r = u % v;
        u = v;
        v = r;
    }
    return u;
}

class fraction { // type declaration+definition int c; int d;
public:
    int c; int d;
public:
    //fraction(){};
    fraction(int cntr = 0, int denom = 1) : c(cntr), d(denom) { /*void*/ }

    // fraction(const fraction &f) : c(f.c), d(f.d) { /*void*/ } // this is a copy constructor delete later

    fraction operator*(fraction b) {
        int f1 = GCD(c, b.d), f2 = GCD(b.c, d);
        return fraction((c/f1) * (b.c/f2), (d/f2) * (b.d/f1));
    }

    fraction operator/(fraction b){
        std::swap(b.c, b.d);
        return (*this) * b;
    }

    fraction operator+(fraction b){
        int cf = GCD(d, b.d);
        int f1 = cf/d, f2 = cf/b.d;
        return fraction(f1*c + f2*b.c, cf);
    }

    fraction operator-(fraction b){
        int cf = GCD(d, b.d);
        int f1 = cf/d, f2 = cf/b.d;
        return fraction(f1*c - f2*b.c, cf);
    }

    fraction operator< (fraction f){
        float a = c/d;
        float b = f.c/f.d;
        if (a < b){
            return true;
        }else{
            return false;
        }}

    fraction operator> (fraction f){
        float a = c/d;
        float b = f.c/f.d;
        if (a > b){
            return true;
        }else{
            return false;
        }
    };


/*
    fraction min(const fraction & x, const fraction & y) {
        using std::min;
        double a = x.c/x.d;
        double b = y.c/y.d;
        if (a < b){
            return x;
        }
        else{return y;}
    }*/

    friend std::ostream& operator<< (std::ostream &os, fraction);
    friend std::istream& operator>> (std::istream &is, fraction);
};


std::ostream& operator<<(std::ostream &os, fraction f){
    os << f.c << "/" << f.d;
    return os;
};



std::istringstream& operator>>(std::istringstream &iss, fraction& f){
    std::string s;
    iss >> s;
    int pos = s.find("/");
    std::string cnt = s.substr(0,pos);
    std::string den = s.substr(pos+1);
    int cntr = std::stoi(cnt);
    int denom = std::stoi(den);
    class fraction input(cntr,denom);
    return iss;
}


/*
void get_fraction(){
    std::cout << std::to_string(c) << ":" << std::to_string(d) << std::endl;
}*/
;
#endif //EXERCISE02_FRACTION_H
