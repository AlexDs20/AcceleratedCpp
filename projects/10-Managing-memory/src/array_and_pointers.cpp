#include <iostream>
#include <algorithm>    // copy
#include <iterator>     // back_inserter
#include <cstddef>      // size_t
#include <numeric>      // iota
#include <vector>

#include "array_and_pointers.hpp"


void pointers() {
    std::cout << "POINTERS" << std::endl;
    int *q;
    std::cout << q << std::endl;
    if (q == nullptr)
        std::cout << "q is a nullptr" << std::endl;


    int *p, a;

    p = &a;         // could've written: int* p = &a;
    a = 4;

    std::cout << "int *p, a;" << std::endl;
    std::cout << "p is a pointer " << p << " to an int: " << *p << std::endl;
    std::cout << "a is an int: " << a << " with address " << &a << std::endl;

    // Change the value of a through p
    *p = 5;
    std::cout << "a now has the value: " << a << std::endl;

    std::cout << p << " " << p+1 << std::endl;
    std::cout << "---------------------------------------------------" << std::endl;
}


void function_pointers(){
    std::cout << "FUNCTION POINTERS" << std::endl;

    // A pointer to a function that takes an int and returns an int
    int (*fp)(int);

    // make fp point to function, the 2 are equivallent because we do not call the function -> get address
    fp = &function_int;
    fp = function_int;

    // Can call the function using the pointer, both return 9 because we make a call and do not access address
    std::cout << (*fp)(8) << std::endl;
    std::cout << fp(8) << std::endl;

    int out = function_arg(function_int, 8);
    std::cout << out << std::endl;

    out = function_arg(function_int, 8);
    std::cout << out << std::endl;

    // function returning a pointer to another function
    typedef int (*func_ptr)(int);       // define type: func_ptr that is a pointer to function with int arg and returns int.
    func_ptr get_function_ptr(function_int);
};

int function_int(int i){
    return i+1;
};

int function_arg(int func(int), int i){
    return func(i);
};
int function_arg2(int (*func)(int), int i){
    return func(i);
};
func_ptr get_function_ptr(int func(int)){
    return func;
};

bool is_neg(int n){
    return n<0;
};

void application(){
    std::vector<int> a(10);
    std::iota(a.begin(), a.end(), -2);
    std::reverse(a.begin(), a.end());

    for (auto e: a)
        std::cout << e << ' ';
    std::cout << std::endl;

    std::vector<int>::iterator i = my_find_if(a.begin(), a.end(), is_neg);
    std::cout << *i << std::endl;
};

void array_and_pointers() {
    int a = 5;
    int *b = nullptr;
    std::cout << b << " " << &b << " " << *(&b) << std::endl;
    std::cout << (b==0) << " " << (b==nullptr) << std::endl;
    b = &a;

    std::cout << "a: " << a << std::endl;
    std::cout << "&a: " << &a << std::endl;
    std::cout << "b: " << b << std::endl;
    std::cout << "*b: " << *b << std::endl;
    std::cout << "&b: " << &b << std::endl;
    *b = 4;
    std::cout << "*b=4 -> a =  " << a << std::endl;
    std::cout << "&b: " << &b << std::endl;
    std::cout << "*(&b): " << *(&b) << std::endl;
    std::cout << "&b+1: " << &b+1 << std::endl;
    std::cout << "*(&b+1): " << *(&b+1) << std::endl;
    std::cout << "*(&b-1): " << *(&b-1) << std::endl;
}


void array() {
    // example:
    //  Coordinates in 3d
    const size_t NDim = 3;
    double coords[NDim];
    *coords = 1.5;
    *(coords+1) = 2;
    std::cout << coords << std::endl;
    std::cout << *coords << std::endl;
    std::cout << *coords+1 << std::endl;    // access coords[0] and adds 1
    std::cout << *(coords+1) << std::endl;    // access coords[1]
};

void pointer_arithmetic () {
    const size_t NDim = 3;
    double coords[NDim] = {
        0, 1, 2
    };
    std::cout << *coords << std::endl;      // access coords[0]
    std::cout << coords << std::endl;       // address of coords[0]
    std::cout << coords+1 << std::endl;     // address of coords[1]
    std::cout << coords+2 << std::endl;     // address of coords[2]
    std::cout << *(coords) << std::endl;       // address of coords[0]
    std::cout << *(coords+1) << std::endl;     // address of coords[1]
    std::cout << *(coords+2) << std::endl;     // address of coords[2]

    // Can copy to a vector because coords+3 points to 1 after the last
    std::vector<double> v;
    std::copy(coords, coords+NDim, std::back_inserter(v));
    for (auto e: v)
        std::cout << e << std::endl;

    std::vector<double> w(coords, coords + NDim);
    for (auto e: w)
        std::cout << e << std::endl;


    double *p, *q;
    p = coords;
    q = coords + 2;
    std::cout << p << std::endl;
    std::cout << q << std::endl;
    std::cout << p - q << std::endl;
    std::cout << (p - q) + q << std::endl;

    // type of p-q ? signed int or long -> depends on implementation => exist ptrdiff_t type
    ptrdiff_t diff = p - q;
    std::cout << diff + q << std::endl;

    std::cout << p - 2 << std::endl; // not a valid element
};

void indexing_10_1_5(){
    double array[] = {
        0., 0.5, 1.0
    };

    // point to element 1 of the array
    double *p = array + 1;
    std::cout << *p << std::endl;
    // can access using indices because pointer is like iterator
    std::cout << p[-1] << ", " << p[0] << ", " << p[1] << std::endl;
    std::cout << array[0] << ", " << array[1] << ", " << array[2] << std::endl;
};
