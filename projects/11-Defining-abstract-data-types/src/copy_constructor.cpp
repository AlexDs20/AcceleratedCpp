#include <iostream>

#include "copy_constructor.hpp"

template <class T>
void print(T v){
    std::cout << v << std::endl;
}

template <class T>
void void_func(T in){
    print("void_function");
};

template <class T>
T return_func(const T& value){
    print("return_function");
    return value;
}


template <class T>
class CP{
    public:
        CP(){};
        CP(const CP& v){print("copy constructor");}
};

void copy_constructor(){
    CP<int> v1;
    print("Before calling void function by value");
    void_func(v1);
    print("After calling void function by value");

    print("Before calling return function by const ref");
    return_func(v1);
    print("After calling return function by const ref");

    print("Before calling return function in copy constructor");
    CP<int> v2(return_func(v1));
};
