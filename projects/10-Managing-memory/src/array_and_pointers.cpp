#include <iostream>
#include <algorithm>    // copy
#include <iterator>     // back_inserter
#include <cstddef>      // size_t
#include <vector>
#include "array_and_pointers.hpp"

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
