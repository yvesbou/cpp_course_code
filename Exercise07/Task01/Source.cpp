//
// Created by Yves Boutellier on 05.12.20.
//

#include <iostream>

// templates schneller, da nicht zweimal fibo(42), bei constexpr werden mehrfache objekte gemacht


// GCD

// with templates

template <int a, int b> struct gcd2{
    static const int res = gcd2<b%a, a>::res;
};

template <int b> struct gcd2<0, b>{
    static const int res = b;
};

template <int a, int b> struct gcd{
    static const int res = gcd2<a, b>::res;
};

// with constexpr

constexpr bool isGCD(int a, int b){
    return a == 0 ? 1 : 0;
}


constexpr int nextGCD(int a, int b){
    return isGCD(b%a, a) ? a : nextGCD(b%a, a);
}


////////////////////////////

// fibonacci

// with templates

template <int n> struct fibo2{
    static const int res = fibo2<n-1>::res + fibo2<n-2>::res;
};

template <> struct fibo2 <0>{
    static const int res = 0;
};

template <> struct fibo2 <1>{
    static const int res = 1;
};


template <int n> struct fibo{
    static const int res = fibo2<n>::res;
};

// with constexpr

constexpr bool isOne(int n){
    return n == 1;
}

constexpr bool isZero(int n){
    return n == 0;
}

constexpr int fibonacci(int n){
    return isZero(n) ? 0 : isOne(n) ? 1 : fibonacci(n-1) + fibonacci(n-2);
};



int main(){
    std::cout << gcd<12,4>::res << std::endl;

    std::cout << nextGCD(16,8) << std::endl;

    std::cout << fibo<6>::res << std::endl;

    std::cout << fibonacci(6) << std::endl;
}
